using Microsoft.Win32;
using ProjectAgentGateV.Models;
using System.IO;
using System.Management;
using System.Runtime.InteropServices;

namespace ProjectAgentGateV.Services;

public static class HardwareProfiler
{
    public static Task<HardwareSnapshot> CaptureAsync(CancellationToken cancellationToken = default) =>
        Task.Run(() => Capture(cancellationToken), cancellationToken);

    public static HardwareSnapshot Capture(CancellationToken cancellationToken = default)
    {
        cancellationToken.ThrowIfCancellationRequested();
        string osCaption = Environment.OSVersion.ToString();
        string version = Environment.OSVersion.Version.ToString();
        string build = Environment.OSVersion.Version.Build.ToString();
        long totalMemory = 0, freeMemory = 0;

        try
        {
            using var searcher = new ManagementObjectSearcher("SELECT Caption, Version, BuildNumber, TotalVisibleMemorySize, FreePhysicalMemory FROM Win32_OperatingSystem");
            using var rows = searcher.Get();
            foreach (ManagementObject row in rows)
            {
                using (row)
                {
                    osCaption = ReadString(row, "Caption", osCaption).Trim();
                    version = ReadString(row, "Version", version);
                    build = ReadString(row, "BuildNumber", build);
                    totalMemory = ReadInt64(row, "TotalVisibleMemorySize") * 1024;
                    freeMemory = ReadInt64(row, "FreePhysicalMemory") * 1024;
                }
                break;
            }
        }
        catch { /* WMI can be disabled by policy; report the fields still available from .NET. */ }

        cancellationToken.ThrowIfCancellationRequested();
        string processor = "Unknown processor";
        int physicalCores = 0, logicalCores = 0;
        int? maxClock = null, currentClock = null;
        try
        {
            using var searcher = new ManagementObjectSearcher("SELECT Name, NumberOfCores, NumberOfLogicalProcessors, MaxClockSpeed, CurrentClockSpeed FROM Win32_Processor");
            using var rows = searcher.Get();
            var currentSum = 0;
            var currentCount = 0;
            foreach (ManagementObject row in rows)
            {
                using (row)
                {
                    processor = ReadString(row, "Name", processor).Trim();
                    physicalCores += (int)ReadInt64(row, "NumberOfCores");
                    logicalCores += (int)ReadInt64(row, "NumberOfLogicalProcessors");
                    int max = (int)ReadInt64(row, "MaxClockSpeed");
                    int current = (int)ReadInt64(row, "CurrentClockSpeed");
                    if (max > 0) maxClock = Math.Max(maxClock ?? 0, max);
                    if (current > 0) { currentSum += current; currentCount++; }
                }
            }
            if (currentCount > 0) currentClock = currentSum / currentCount;
        }
        catch { }

        cancellationToken.ThrowIfCancellationRequested();
        string ramSpeed = "Not reported";
        string ramType = "Not reported";
        try
        {
            using var searcher = new ManagementObjectSearcher("SELECT Capacity, Speed, ConfiguredClockSpeed, SMBIOSMemoryType FROM Win32_PhysicalMemory");
            using var rows = searcher.Get();
            var speeds = new List<long>();
            var types = new List<int>();
            long moduleTotal = 0;
            foreach (ManagementObject row in rows)
            {
                using (row)
                {
                    moduleTotal += ReadInt64(row, "Capacity");
                    var speed = ReadInt64(row, "ConfiguredClockSpeed");
                    if (speed <= 0) speed = ReadInt64(row, "Speed");
                    if (speed > 0) speeds.Add(speed);
                    var type = (int)ReadInt64(row, "SMBIOSMemoryType");
                    if (type > 0) types.Add(type);
                }
            }
            if (totalMemory <= 0) totalMemory = moduleTotal;
            if (speeds.Count > 0) ramSpeed = $"{string.Join(", ", speeds.Distinct())} MT/s";
            if (types.Count > 0) ramType = string.Join(", ", types.Distinct().Select(MapMemoryType));
        }
        catch { }

        cancellationToken.ThrowIfCancellationRequested();
        var gpus = ReadGpus();
        var nvidiaPresent = gpus.Any(g => g.Vendor.Contains("NVIDIA", StringComparison.OrdinalIgnoreCase)
                                         || g.Name.Contains("NVIDIA", StringComparison.OrdinalIgnoreCase));
        var storage = ReadFixedDrives();
        return new HardwareSnapshot
        {
            OperatingSystem = osCaption,
            WindowsVersion = version,
            WindowsBuild = build,
            Architecture = RuntimeInformation.OSArchitecture.ToString(),
            TotalMemoryBytes = totalMemory,
            AvailableMemoryBytes = freeMemory,
            RamSpeed = ramSpeed,
            RamType = ramType,
            ProcessorName = processor,
            PhysicalCores = physicalCores,
            LogicalCores = logicalCores,
            MaxClockMHz = maxClock,
            CurrentClockMHz = currentClock,
            DirectXVersion = ReadDirectXVersion(),
            CudaHardwareIndicator = nvidiaPresent ? "NVIDIA adapter detected (CUDA-capable hardware indicator)" : "No NVIDIA adapter detected",
            CudaRuntimeAvailability = "Not verified: WMI does not report CUDA runtime availability",
            Gpus = gpus,
            Storage = storage
        };
    }

    private static IReadOnlyList<GpuInfo> ReadGpus()
    {
        var result = new List<GpuInfo>();
        try
        {
            using var searcher = new ManagementObjectSearcher("SELECT Name, AdapterCompatibility, AdapterRAM, VideoProcessor, DriverVersion FROM Win32_VideoController");
            using var rows = searcher.Get();
            foreach (ManagementObject row in rows)
            {
                using (row)
                {
                    ulong memory = 0;
                    try { memory = Convert.ToUInt64(row["AdapterRAM"] ?? 0); } catch { }
                    var name = ReadString(row, "Name", "Unknown display adapter").Trim();
                    var vendor = ReadString(row, "AdapterCompatibility", "Unknown").Trim();
                    result.Add(new GpuInfo
                    {
                        Name = name,
                        Vendor = vendor,
                        DedicatedVideoMemoryBytes = memory == 0 ? null : memory,
                        VideoProcessor = ReadString(row, "VideoProcessor", "Not reported").Trim(),
                        DriverVersion = ReadString(row, "DriverVersion", "Not reported").Trim(),
                        Classification = IsLikelyDedicatedAdapter(name, vendor) ? "Dedicated GPU likely (WMI name/vendor heuristic)" : "Integrated or unclassified by WMI"
                    });
                }
            }
        }
        catch { }
        return result;
    }

    private static bool IsLikelyDedicatedAdapter(string name, string vendor)
    {
        string label = $"{name} {vendor}";
        string[] discreteMarkers = ["GeForce", "Quadro", "Tesla", "RTX", "Radeon RX", "Radeon Pro", "FirePro", "Arc A"];
        return discreteMarkers.Any(marker => label.Contains(marker, StringComparison.OrdinalIgnoreCase));
    }

    private static IReadOnlyList<StorageDeviceInfo> ReadFixedDrives()
    {
        var drives = new List<StorageDeviceInfo>();
        var mediaByDisk = ReadPhysicalDiskTypes();
        foreach (var drive in DriveInfo.GetDrives())
        {
            try
            {
                if (!drive.IsReady || drive.DriveType != DriveType.Fixed) continue;
                var type = "Fixed drive (physical type unavailable)";
                var diskIndex = FindDiskIndexForVolume(drive.Name.TrimEnd('\\', '/'));
                if (diskIndex.HasValue && mediaByDisk.TryGetValue(diskIndex.Value, out var mediaType)) type = mediaType;
                drives.Add(new StorageDeviceInfo { Name = drive.Name, Type = type, TotalBytes = drive.TotalSize, FreeBytes = drive.AvailableFreeSpace });
            }
            catch { }
        }
        return drives;
    }

    private static Dictionary<int, string> ReadPhysicalDiskTypes()
    {
        var result = new Dictionary<int, string>();
        try
        {
            var scope = new ManagementScope(@"\\.\root\Microsoft\Windows\Storage");
            scope.Connect();
            using var searcher = new ManagementObjectSearcher(scope, new ObjectQuery("SELECT DeviceId, MediaType FROM MSFT_PhysicalDisk"));
            using var rows = searcher.Get();
            foreach (ManagementObject row in rows)
            {
                using (row)
                {
                    int id = (int)Convert.ToInt64(row["DeviceId"] ?? -1);
                    int type = (int)Convert.ToInt64(row["MediaType"] ?? 0);
                    var label = type switch { 3 => "HDD", 4 => "SSD", 5 => "Storage Class Memory", _ => "Fixed drive (physical type unavailable)" };
                    if (id >= 0) result[id] = label;
                }
            }
        }
        catch { }
        return result;
    }

    private static int? FindDiskIndexForVolume(string volume)
    {
        try
        {
            string escapedVolume = volume.Replace("'", "\\'");
            string logicalPath = $"Win32_LogicalDisk.DeviceID='{escapedVolume}'";
            using var partitionSearcher = new ManagementObjectSearcher($"ASSOCIATORS OF {{{logicalPath}}} WHERE AssocClass = Win32_LogicalDiskToPartition");
            using var partitions = partitionSearcher.Get();
            foreach (ManagementObject partition in partitions)
            {
                using (partition)
                {
                    var partitionId = partition["DeviceID"]?.ToString();
                    if (string.IsNullOrWhiteSpace(partitionId)) continue;
                    string escapedPartition = partitionId.Replace("'", "\\'");
                    using var diskSearcher = new ManagementObjectSearcher($"ASSOCIATORS OF {{Win32_DiskPartition.DeviceID='{escapedPartition}'}} WHERE AssocClass = Win32_DiskDriveToDiskPartition");
                    using var disks = diskSearcher.Get();
                    foreach (ManagementObject disk in disks)
                    {
                        using (disk) return (int)Convert.ToInt64(disk["Index"] ?? -1);
                    }
                }
            }
        }
        catch { }
        return null;
    }

    private static string ReadDirectXVersion()
    {
        try
        {
            using var key = Registry.LocalMachine.OpenSubKey(@"SOFTWARE\Microsoft\DirectX");
            var value = key?.GetValue("Version")?.ToString();
            return string.IsNullOrWhiteSpace(value) ? "Registry version unavailable" : value;
        }
        catch { return "Registry version unavailable"; }
    }

    private static string ReadString(ManagementBaseObject row, string property, string fallback) =>
        row[property]?.ToString() is { Length: > 0 } value ? value : fallback;

    private static long ReadInt64(ManagementBaseObject row, string property)
    {
        try { return Convert.ToInt64(row[property] ?? 0); } catch { return 0; }
    }

    private static string MapMemoryType(int type) => type switch
    {
        20 => "DDR", 21 => "DDR2", 24 => "DDR3", 26 => "DDR4", 34 => "DDR5", _ => $"SMBIOS type {type}"
    };
}
