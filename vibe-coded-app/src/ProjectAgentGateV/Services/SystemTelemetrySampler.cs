using System.Diagnostics;
using System.Management;
using System.Runtime.InteropServices;

namespace ProjectAgentGateV.Services;

public sealed record SystemTelemetrySample(double? CpuUtilizationPercent, double? GpuUtilizationPercent, long ProcessWorkingSetBytes, long TotalPhysicalMemoryBytes);

/// <summary>Samples host CPU and application memory every 100 ms; Windows GPU 3D counters are best effort.</summary>
public sealed class SystemTelemetrySampler : IAsyncDisposable
{
    private const int PollMilliseconds = 100;
    private CancellationTokenSource? _cancellation;
    private Task? _loop;

    public void Start(long totalPhysicalMemoryBytes, Action<SystemTelemetrySample> onSample, CancellationToken cancellationToken)
    {
        if (_loop is not null) throw new InvalidOperationException("Telemetry sampling has already started.");
        _cancellation = CancellationTokenSource.CreateLinkedTokenSource(cancellationToken);
        _loop = Task.Run(() => SampleLoopAsync(totalPhysicalMemoryBytes, onSample, _cancellation.Token));
    }

    private static async Task SampleLoopAsync(long knownMemoryBytes, Action<SystemTelemetrySample> onSample, CancellationToken cancellationToken)
    {
        using var process = Process.GetCurrentProcess();
        ulong? previousIdle = null, previousKernel = null, previousUser = null;
        long totalMemory = knownMemoryBytes;
        double? gpuUsage = null;

        while (!cancellationToken.IsCancellationRequested)
        {
            var started = Stopwatch.GetTimestamp();
            double? cpuUsage = ReadCpuUsage(ref previousIdle, ref previousKernel, ref previousUser);
            gpuUsage = ReadGpu3DUtilization();
            if (totalMemory <= 0) totalMemory = ReadTotalPhysicalMemory();

            long workingSet;
            try { process.Refresh(); workingSet = process.WorkingSet64; }
            catch (InvalidOperationException) { workingSet = 0; }

            onSample(new SystemTelemetrySample(cpuUsage, gpuUsage, workingSet, totalMemory));
            var elapsed = Stopwatch.GetElapsedTime(started);
            var delay = TimeSpan.FromMilliseconds(PollMilliseconds) - elapsed;
            if (delay <= TimeSpan.Zero) delay = TimeSpan.FromMilliseconds(1);
            await Task.Delay(delay, cancellationToken).ConfigureAwait(false);
        }
    }

    private static double? ReadCpuUsage(ref ulong? previousIdle, ref ulong? previousKernel, ref ulong? previousUser)
    {
        if (!GetSystemTimes(out var idleTime, out var kernelTime, out var userTime)) return null;
        ulong idle = ToUInt64(idleTime), kernel = ToUInt64(kernelTime), user = ToUInt64(userTime);
        if (previousIdle is null || previousKernel is null || previousUser is null)
        {
            previousIdle = idle; previousKernel = kernel; previousUser = user;
            return null;
        }

        ulong deltaIdle = idle - previousIdle.Value;
        ulong deltaKernel = kernel - previousKernel.Value;
        ulong deltaUser = user - previousUser.Value;
        previousIdle = idle; previousKernel = kernel; previousUser = user;
        ulong total = deltaKernel + deltaUser;
        if (total == 0) return 0;
        // Windows kernel time includes idle time.
        return Math.Clamp((total - Math.Min(total, deltaIdle)) * 100d / total, 0d, 100d);
    }

    private static double? ReadGpu3DUtilization()
    {
        try
        {
            using var searcher = new ManagementObjectSearcher(
                "SELECT Name, UtilizationPercentage FROM Win32_PerfFormattedData_GPUPerformanceCounters_GPUEngine");
            using var rows = searcher.Get();
            var engineUsage = new Dictionary<(string Adapter, string Engine), double>();
            foreach (ManagementObject row in rows)
            {
                using (row)
                {
                    var name = row["Name"]?.ToString() ?? "";
                    if (!name.Contains("engtype_3D", StringComparison.OrdinalIgnoreCase)) continue;
                    var value = Convert.ToDouble(row["UtilizationPercentage"] ?? 0);
                    var match = System.Text.RegularExpressions.Regex.Match(name, @"phys_(?<adapter>\d+)_eng_(?<engine>\d+)", System.Text.RegularExpressions.RegexOptions.IgnoreCase);
                    var key = match.Success
                        ? (match.Groups["adapter"].Value, match.Groups["engine"].Value)
                        : ("0", name);
                    engineUsage[key] = engineUsage.GetValueOrDefault(key) + Math.Clamp(value, 0, 100);
                }
            }
            return engineUsage.Count == 0
                ? null
                : engineUsage.GroupBy(item => item.Key.Adapter)
                    .Select(adapter => adapter.Max(item => Math.Clamp(item.Value, 0, 100)))
                    .DefaultIfEmpty()
                    .Max();
        }
        catch (Exception) { return null; }
    }

    private static long ReadTotalPhysicalMemory()
    {
        var status = new MemoryStatusEx { Length = (uint)Marshal.SizeOf<MemoryStatusEx>() };
        return GlobalMemoryStatusEx(ref status) ? (long)Math.Min(status.TotalPhys, (ulong)long.MaxValue) : 0;
    }

    private static ulong ToUInt64(FileTime value) => ((ulong)value.High << 32) | value.Low;

    public async ValueTask DisposeAsync()
    {
        if (_cancellation is null) return;
        _cancellation.Cancel();
        if (_loop is not null)
        {
            try { await _loop.ConfigureAwait(false); }
            catch (OperationCanceledException) { }
        }
        _cancellation.Dispose();
        _cancellation = null;
        _loop = null;
    }

    [DllImport("kernel32.dll", SetLastError = true)]
    [return: MarshalAs(UnmanagedType.Bool)]
    private static extern bool GetSystemTimes(out FileTime idleTime, out FileTime kernelTime, out FileTime userTime);

    [DllImport("kernel32.dll", CharSet = CharSet.Auto, SetLastError = true)]
    [return: MarshalAs(UnmanagedType.Bool)]
    private static extern bool GlobalMemoryStatusEx(ref MemoryStatusEx buffer);

    [StructLayout(LayoutKind.Sequential)]
    private struct FileTime
    {
        public uint Low;
        public uint High;
    }

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Auto)]
    private struct MemoryStatusEx
    {
        public uint Length;
        public uint MemoryLoad;
        public ulong TotalPhys;
        public ulong AvailPhys;
        public ulong TotalPageFile;
        public ulong AvailPageFile;
        public ulong TotalVirtual;
        public ulong AvailVirtual;
        public ulong AvailExtendedVirtual;
    }
}
