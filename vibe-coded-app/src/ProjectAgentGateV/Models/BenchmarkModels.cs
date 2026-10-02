namespace ProjectAgentGateV.Models;

public sealed record UserProfile(string Username, string Country);

public enum BenchmarkDevice
{
    Cpu,
    DirectMlGpu
}

public sealed record DeviceComparison(
    string Device,
    double ThroughputFps,
    double AccuracyPercent,
    double InferenceDurationSeconds,
    string? Error = null,
    IReadOnlyList<double>? FrameLatencySamplesMilliseconds = null,
    LatencyStatistics? FrameLatency = null,
    LatencyStatistics? ModelCallLatency = null)
{
    public string ThroughputDisplay => Error is null ? $"{ThroughputFps:0.00}" : "Failed";
    public string AccuracyDisplay => Error is null ? $"{AccuracyPercent:0.00}%" : "—";
    public string DurationDisplay => Error is null ? $"{InferenceDurationSeconds:0.000} s" : "—";
    public string P99LatencyDisplay => Error is null ? $"{FrameLatency?.P99Milliseconds:0.000} ms" : "—";
    public string MaxLatencyDisplay => Error is null ? $"{FrameLatency?.MaximumMilliseconds:0.000} ms" : "—";
}

public sealed record LatencyStatistics(
    int SampleCount,
    double MeanMilliseconds,
    double MedianMilliseconds,
    double P95Milliseconds,
    double P99Milliseconds,
    double MinimumMilliseconds,
    double MaximumMilliseconds,
    double MaximumDeviationFromMedianMilliseconds,
    double StandardDeviationMilliseconds)
{
    public static LatencyStatistics From(IReadOnlyList<double> samples)
    {
        if (samples.Count == 0) return new LatencyStatistics(0, 0, 0, 0, 0, 0, 0, 0, 0);

        var ordered = samples.ToArray();
        Array.Sort(ordered);
        double mean = ordered.Average();
        double median = Percentile(ordered, 0.50);
        double variance = ordered.Sum(value => (value - mean) * (value - mean)) / ordered.Length;
        return new LatencyStatistics(
            ordered.Length,
            mean,
            median,
            Percentile(ordered, 0.95),
            Percentile(ordered, 0.99),
            ordered[0],
            ordered[^1],
            ordered.Max(value => Math.Abs(value - median)),
            Math.Sqrt(variance));
    }

    private static double Percentile(double[] ordered, double percentile)
    {
        int index = Math.Clamp((int)Math.Ceiling(percentile * ordered.Length) - 1, 0, ordered.Length - 1);
        return ordered[index];
    }
}

public sealed record CountryOption(string Name, string Code);

public sealed record HardwareDetailRow(string Label, string Value, string Detail);

public sealed class StorageDeviceInfo
{
    public string Name { get; init; } = "";
    public string Type { get; init; } = "Unknown";
    public long TotalBytes { get; init; }
    public long FreeBytes { get; init; }
    public string TotalDisplay => FormatBytes(TotalBytes);
    public string FreeDisplay => FormatBytes(FreeBytes);

    internal static string FormatBytes(long value)
    {
        string[] units = ["B", "KB", "MB", "GB", "TB"];
        double size = Math.Max(0, value);
        var index = 0;
        while (size >= 1024 && index < units.Length - 1) { size /= 1024; index++; }
        return $"{size:0.#} {units[index]}";
    }
}

public sealed class GpuInfo
{
    public string Name { get; init; } = "Unknown";
    public string Vendor { get; init; } = "Unknown";
    public string VideoProcessor { get; init; } = "Not reported";
    public string DriverVersion { get; init; } = "Not reported";
    public string Classification { get; init; } = "Integrated or unclassified";
    public ulong? DedicatedVideoMemoryBytes { get; init; }
    public string DedicatedVideoMemoryDisplay => DedicatedVideoMemoryBytes is > 0
        ? StorageDeviceInfo.FormatBytes((long)Math.Min(DedicatedVideoMemoryBytes.Value, (ulong)long.MaxValue))
        : "Not reported by WMI";
}

public sealed class HardwareSnapshot
{
    public string CapturedAtUtc { get; init; } = DateTimeOffset.UtcNow.ToString("O");
    public string OperatingSystem { get; init; } = "Unknown";
    public string WindowsVersion { get; init; } = "Unknown";
    public string WindowsBuild { get; init; } = "Unknown";
    public string Architecture { get; init; } = "Unknown";
    public long TotalMemoryBytes { get; init; }
    public long AvailableMemoryBytes { get; init; }
    public string RamSpeed { get; init; } = "Not reported";
    public string RamType { get; init; } = "Not reported";
    public string ProcessorName { get; init; } = "Unknown";
    public int PhysicalCores { get; init; }
    public int LogicalCores { get; init; }
    public int? MaxClockMHz { get; init; }
    public int? CurrentClockMHz { get; init; }
    public string DirectXVersion { get; init; } = "Not reported";
    public string CudaHardwareIndicator { get; init; } = "No NVIDIA adapter detected";
    public string CudaRuntimeAvailability { get; init; } = "Not verified by WMI";
    public IReadOnlyList<GpuInfo> Gpus { get; init; } = [];
    public IReadOnlyList<StorageDeviceInfo> Storage { get; init; } = [];

    public string TotalMemoryDisplay => StorageDeviceInfo.FormatBytes(TotalMemoryBytes);
    public string AvailableMemoryDisplay => StorageDeviceInfo.FormatBytes(AvailableMemoryBytes);
    public string CpuCoreDisplay => PhysicalCores > 0 && LogicalCores > 0
        ? $"{PhysicalCores} cores · {LogicalCores} threads"
        : "Core count unavailable";
    public string CpuClockDisplay => MaxClockMHz.HasValue
        ? $"{MaxClockMHz.Value / 1000d:0.00} GHz max"
        : "Clock unavailable";
    public string BaseClockDisplay => "Not reported separately by Win32_Processor WMI";
    public string GpuSummary => Gpus.Count == 0 ? "No WMI display adapter found" : (Gpus.FirstOrDefault(g => g.Classification.StartsWith("Dedicated", StringComparison.OrdinalIgnoreCase)) ?? Gpus[0]).Name;
    public string StorageSummary => Storage.Count == 0 ? "No fixed drives found" : string.Join("  ·  ", Storage.Select(d => $"{d.Name} {d.Type} · {d.FreeDisplay} free of {d.TotalDisplay}"));
}

public sealed record ClassAccuracy(string Label, int Images, int Correct)
{
    public double AccuracyPercent => Images == 0 ? 0 : Correct * 100d / Images;
}

public sealed class BenchmarkResult
{
    public string StartedAtUtc { get; init; } = DateTimeOffset.UtcNow.ToString("O");
    public int TotalImages { get; init; }
    public int CorrectImages { get; init; }
    public double AccuracyPercent => TotalImages == 0 ? 0 : CorrectImages * 100d / TotalImages;
    public double InferenceDurationSeconds { get; init; }
    public double ThroughputFps { get; init; }
    public double EndToEndDurationSeconds { get; init; }
    public double EndToEndThroughputFps { get; init; }
    public double AverageModelCallLatencyMilliseconds { get; init; }
    public LatencyStatistics ModelCallLatency { get; init; } = new(0, 0, 0, 0, 0, 0, 0, 0, 0);
    public LatencyStatistics FrameLatency { get; init; } = new(0, 0, 0, 0, 0, 0, 0, 0, 0);
    public int WarmupCalls { get; init; }
    public IReadOnlyList<double> ModelCallLatencySamplesMilliseconds { get; init; } = [];
    public IReadOnlyList<double> FrameLatencySamplesMilliseconds { get; init; } = [];
    public string SpriteAnimationDuringRun { get; set; } = "Enabled";
    public string PrimaryDevice { get; init; } = "CPU · ONNX Runtime";
    public IReadOnlyList<DeviceComparison> DeviceComparisons { get; set; } = [];
    public long OperationsPerImage { get; init; } = 233_303_552;
    public double Gops => OperationsPerImage * ThroughputFps / 1_000_000_000d;
    public int BatchSize { get; init; } = 1;
    public string DatasetDirectory { get; init; } = "";
    public string ModelFile { get; init; } = "";
    public UserProfile User { get; init; } = new("", "");
    public HardwareSnapshot Hardware { get; init; } = new();
    public IReadOnlyList<ClassAccuracy> PerClassAccuracy { get; init; } = [];
    public string? HtmlReportPath { get; set; }
    public string? JsonSummaryPath { get; set; }
}

public sealed record DatasetImage(string FullPath, int ExpectedClassIndex);

public sealed record DatasetValidation(string RootDirectory, int FoundClasses, int RequiredClasses, int ImageCount, IReadOnlyList<string> MissingOrEmptyClasses)
{
    public bool IsReady => FoundClasses == RequiredClasses && ImageCount > 0 && MissingOrEmptyClasses.Count == 0;
    public string Summary => IsReady
        ? $"Ready: {FoundClasses}/{RequiredClasses} classes found ({ImageCount:N0} images detected)"
        : $"Not ready: {FoundClasses}/{RequiredClasses} classes with images · {ImageCount:N0} images detected";
}

public sealed record BenchmarkProgress(
    int Completed,
    int Total,
    string CurrentLabel,
    double InferenceSeconds,
    double LastModelCallLatencyMilliseconds,
    double LastFrameLatencyMilliseconds)
{
    public double Percent => Total == 0 ? 0 : Completed * 100d / Total;
}
