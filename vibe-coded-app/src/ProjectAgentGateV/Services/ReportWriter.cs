using ProjectAgentGateV.Models;
using System.IO;
using System.Net;
using System.Text;
using System.Globalization;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace ProjectAgentGateV.Services;

public static class ReportWriter
{
    public static async Task<(string Html, string Json)> WriteAsync(BenchmarkResult result, string baseDirectory, CancellationToken cancellationToken = default)
    {
        var reportDirectory = Path.Combine(baseDirectory, "benchmark_reports");
        Directory.CreateDirectory(reportDirectory);
        var stamp = DateTimeOffset.Now.ToString("yyyyMMdd_HHmmss_fff");
        var htmlPath = Path.Combine(reportDirectory, $"benchmark_{stamp}.html");
        var jsonPath = Path.Combine(reportDirectory, $"benchmark_{stamp}.json");
        result.HtmlReportPath = htmlPath;
        result.JsonSummaryPath = jsonPath;

        await File.WriteAllTextAsync(htmlPath, BuildHtml(result), new UTF8Encoding(false), cancellationToken);
        var options = new JsonSerializerOptions { WriteIndented = true, DefaultIgnoreCondition = JsonIgnoreCondition.WhenWritingNull };
        await File.WriteAllTextAsync(jsonPath, JsonSerializer.Serialize(result, options), new UTF8Encoding(false), cancellationToken);
        return (htmlPath, jsonPath);
    }

    private static string BuildHtml(BenchmarkResult result)
    {
        static string E(string? value) => WebUtility.HtmlEncode(value ?? "");
        static string BaseClock(HardwareSnapshot hardware)
        {
            var match = System.Text.RegularExpressions.Regex.Match(hardware.ProcessorName, @"@\s*(\d+(?:\.\d+)?)\s*GHz", System.Text.RegularExpressions.RegexOptions.IgnoreCase);
            return match.Success ? $"{match.Groups[1].Value} GHz" : "Not reported";
        }
        static string GpuMemory(HardwareSnapshot hardware)
        {
            var gpu = hardware.Gpus.FirstOrDefault();
            if (gpu is null) return "Memory not reported";
            return gpu.Classification.StartsWith("Integrated", StringComparison.OrdinalIgnoreCase)
                ? $"Shared system memory · {gpu.DedicatedVideoMemoryDisplay} reported by WMI"
                : $"Dedicated memory · {gpu.DedicatedVideoMemoryDisplay}";
        }
        var rows = new StringBuilder();
        foreach (var item in result.PerClassAccuracy)
            rows.Append("<tr><td>").Append(E(item.Label)).Append("</td><td>").Append(item.Images)
                .Append("</td><td>").Append(item.Correct).Append("</td><td>").Append(item.AccuracyPercent.ToString("0.00"))
                .Append("%</td></tr>");

        var deviceRows = new StringBuilder();
        foreach (var item in result.DeviceComparisons)
        {
            deviceRows.Append("<tr><td>").Append(E(item.Device)).Append("</td><td>");
            if (item.Error is null)
                deviceRows.Append(item.ThroughputFps.ToString("0.00")).Append(" FPS</td><td>")
                    .Append(item.AccuracyPercent.ToString("0.00")).Append("%</td><td>")
                    .Append(item.InferenceDurationSeconds.ToString("0.000")).Append(" s</td><td>")
                    .Append(E(item.P99LatencyDisplay)).Append("</td><td>")
                    .Append(E(item.MaxLatencyDisplay)).Append("</td><td>Completed</td></tr>");
            else
                deviceRows.Append("—</td><td>—</td><td>—</td><td>—</td><td>—</td><td>").Append(E(item.Error)).Append("</td></tr>");
        }
        string latencyChart = BuildLatencyChart(result.DeviceComparisons);
        string fpgaReference = "FPGA reference omitted: the checked-in RTL provides an 8×8 MAC engine but no complete CNN cycle count or per-image board trace. A flat FPGA line would be an unverified estimate, not a measured result.";

        return $$$"""
<!doctype html>
<html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>AgentGate V benchmark · {{{E(result.StartedAtUtc)}}}</title>
<style>
:root{color-scheme:light;--ink:#252525;--muted:#737373;--line:#e6e5e3;--accent:#383838}*{box-sizing:border-box}body{margin:0;background:#f5f5f3;color:var(--ink);font:15px/1.55 "Segoe UI",Arial,sans-serif}.page{max-width:1040px;margin:44px auto;padding:0 24px}.hero,.card{background:#fff;border:1px solid var(--line);border-radius:20px;box-shadow:0 12px 36px #2020200b}.hero{padding:34px 38px;background:linear-gradient(120deg,#fff 25%,#f5f4f2)}.eyebrow{color:var(--accent);font-weight:700;text-transform:uppercase;letter-spacing:.12em;font-size:12px}.hero h1{font-size:32px;letter-spacing:-.04em;margin:8px 0}.muted{color:var(--muted)}.grid{display:grid;grid-template-columns:repeat(4,1fr);gap:14px;margin:18px 0}.metric{padding:20px}.metric span{display:block;color:var(--muted);font-size:12px}.metric strong{display:block;font-size:24px;margin-top:6px}.card{padding:26px;margin:16px 0}.card h2{margin:0 0 16px;font-size:18px}.details{display:grid;grid-template-columns:1fr 1fr;gap:10px 28px}.details div{padding:11px 0;border-bottom:1px solid var(--line)}.details b{display:block;font-size:12px;color:var(--muted);font-weight:500}.details span{overflow-wrap:anywhere}.chart{width:100%;height:auto;display:block}.legend{display:flex;gap:20px;flex-wrap:wrap;font-size:12px;margin-top:10px}.legend i{display:inline-block;width:18px;height:3px;margin:0 7px 3px 0;vertical-align:middle}table{width:100%;border-collapse:collapse}th,td{text-align:left;padding:11px;border-bottom:1px solid var(--line)}th{font-size:12px;color:var(--muted);font-weight:600}footer{color:var(--muted);font-size:12px;padding:16px 0 36px;overflow-wrap:anywhere}@media(max-width:760px){.grid{grid-template-columns:1fr 1fr}.details{grid-template-columns:1fr}.page{margin:18px auto}}
</style></head><body><main class="page">
<section class="hero"><div class="eyebrow">Project-AgentGate-V · Inference report</div><h1>Benchmark complete</h1><div class="muted">{{{E(result.StartedAtUtc)}}} · Batch size {{{result.BatchSize}}}</div></section>
<section class="grid"><article class="card metric"><span>Images</span><strong>{{{result.TotalImages:N0}}}</strong></article><article class="card metric"><span>Accuracy</span><strong>{{{result.AccuracyPercent:0.00}}}%</strong></article><article class="card metric"><span>Throughput</span><strong>{{{result.ThroughputFps:0.00}}} FPS</strong></article><article class="card metric"><span>Compute estimate</span><strong>{{{result.Gops:0.00}}} GOPS</strong></article></section>
<section class="card"><h2>Device comparison</h2><table><thead><tr><th>Device</th><th>Throughput</th><th>Accuracy</th><th>Inference time</th><th>P99 frame</th><th>Worst frame</th><th>Status</th></tr></thead><tbody>{{{deviceRows}}}</tbody></table><p class="muted">Every request is batch size 1. Device passes use the same dataset sequentially; DirectML targets the default Windows graphics adapter.</p></section>
<section class="card"><h2>Per-frame latency · batch size 1</h2><p class="muted">Each plotted point is one image request, including file decode, resize/preprocessing, ONNX inference, and prediction. The selected device lines show measured samples in dataset order.</p>{{{latencyChart}}}<p class="muted">{{{E(fpgaReference)}}}</p></section>
<section class="card"><h2>Tail latency</h2><div class="details"><div><b>Frame requests · median / p95 / p99 / worst</b><span>{{{result.FrameLatency.MedianMilliseconds:0.000}}} / {{{result.FrameLatency.P95Milliseconds:0.000}}} / {{{result.FrameLatency.P99Milliseconds:0.000}}} / {{{result.FrameLatency.MaximumMilliseconds:0.000}}} ms</span></div><div><b>Worst deviation from median · frame / ONNX call</b><span>{{{result.FrameLatency.MaximumDeviationFromMedianMilliseconds:0.000}}} / {{{result.ModelCallLatency.MaximumDeviationFromMedianMilliseconds:0.000}}} ms</span></div><div><b>ONNX call · median / p95 / p99 / worst</b><span>{{{result.ModelCallLatency.MedianMilliseconds:0.000}}} / {{{result.ModelCallLatency.P95Milliseconds:0.000}}} / {{{result.ModelCallLatency.P99Milliseconds:0.000}}} / {{{result.ModelCallLatency.MaximumMilliseconds:0.000}}} ms</span></div><div><b>Mean frame request / model call</b><span>{{{result.FrameLatency.MeanMilliseconds:0.000}}} / {{{result.ModelCallLatency.MeanMilliseconds:0.000}}} ms</span></div><div><b>Frame request throughput</b><span>{{{result.EndToEndThroughputFps:0.00}}} FPS · total {{{result.EndToEndDurationSeconds:0.000}}} s</span></div><div><b>Warm-up</b><span>{{{result.WarmupCalls}}} model calls per device, excluded from the measured samples</span></div><div><b>Samples</b><span>{{{result.FrameLatency.SampleCount:N0}}} per-frame observations</span></div><div><b>Primary device</b><span>{{{E(result.PrimaryDevice)}}}</span></div><div><b>Operations per image</b><span>{{{result.OperationsPerImage:N0}}} estimated floating-point operations (MAC counted as two operations)</span></div><div><b>Sprite animation</b><span>{{{E(result.SpriteAnimationDuringRun)}}}</span></div><div><b>User / country</b><span>{{{E(result.User.Username)}}} · {{{E(result.User.Country)}}}</span></div><div><b>Operating system</b><span>{{{E(result.Hardware.OperatingSystem)}}}, build {{{E(result.Hardware.WindowsBuild)}}} · {{{E(result.Hardware.Architecture)}}}</span></div><div><b>Processor</b><span>{{{E(result.Hardware.ProcessorName)}}}, {{{E(result.Hardware.CpuCoreDisplay)}}} · base {{{E(BaseClock(result.Hardware))}}} · max {{{E(result.Hardware.CpuClockDisplay)}}}, current {{{result.Hardware.CurrentClockMHz?.ToString() ?? "Not reported"}}} MHz</span></div><div><b>Memory</b><span>{{{E(result.Hardware.TotalMemoryDisplay)}}} total · {{{E(result.Hardware.AvailableMemoryDisplay)}}} available · {{{E(result.Hardware.RamSpeed)}}} · {{{E(result.Hardware.RamType)}}}</span></div><div><b>Graphics</b><span>{{{E(result.Hardware.GpuSummary)}}} · {{{E(result.Hardware.Gpus.FirstOrDefault()?.Classification)}}} · {{{E(GpuMemory(result.Hardware))}}}</span></div><div><b>Storage</b><span>{{{E(result.Hardware.StorageSummary)}}}</span></div><div><b>Dataset</b><span>{{{E(result.DatasetDirectory)}}}</span></div><div><b>Model</b><span>{{{E(result.ModelFile)}}}</span></div></div></section>
<section class="card"><h2>Per-class accuracy</h2><table><thead><tr><th>Class</th><th>Images</th><th>Correct</th><th>Accuracy</th></tr></thead><tbody>{{{rows}}}</tbody></table></section>
<footer>Model-call latency includes synchronous ONNX Run, output access, ArgMax, and disposal. End-to-end frame latency additionally includes reading and preprocessing the selected image. Dataset scanning, session creation, 10 warm-up calls, and report generation are excluded. All inference uses batch size one and one request at a time. The plotted PC/device lines are measured samples; OS scheduling and shared machine load can affect them. The app's 100 ms telemetry polling and animated UI remain active during the run and can affect tail latency, especially with WMI GPU sampling; compare repeated runs under the same settings. GOPS is estimated from the CNN operation count, not measured hardware instructions. Base clock is read from the processor name when available; maximum and current speeds are shown separately. WMI shared/dedicated memory values depend on what the installed driver reports.</footer>
</main></body></html>
""";
    }

    private static string BuildLatencyChart(IReadOnlyList<DeviceComparison> comparisons)
    {
        var series = comparisons
            .Where(device => device.Error is null && device.FrameLatencySamplesMilliseconds is { Count: > 0 })
            .ToArray();
        if (series.Length == 0)
            return "<p class=\"muted\">No completed device contains per-frame latency samples.</p>";

        const double width = 980;
        const double height = 340;
        const double left = 68;
        const double right = 18;
        const double top = 18;
        const double bottom = 44;
        double plotWidth = width - left - right;
        double plotHeight = height - top - bottom;
        double maxLatency = series.SelectMany(device => device.FrameLatencySamplesMilliseconds!).Max();
        if (maxLatency <= 0) maxLatency = 1;
        string F(double value) => value.ToString("0.##", CultureInfo.InvariantCulture);
        string[] colors = ["#353535", "#9a6041", "#77766f", "#4f6861"];

        var chart = new StringBuilder();
        chart.Append("<svg class=\"chart\" viewBox=\"0 0 980 340\" role=\"img\" aria-label=\"Measured per-frame latency by selected device\"><title>Batch size one measured frame latency by device</title>");
        for (int tick = 0; tick <= 4; tick++)
        {
            double fraction = tick / 4d;
            double y = top + plotHeight - fraction * plotHeight;
            chart.Append("<line x1=\"").Append(F(left)).Append("\" y1=\"").Append(F(y))
                .Append("\" x2=\"").Append(F(width - right)).Append("\" y2=\"").Append(F(y))
                .Append("\" stroke=\"#ecebe9\" stroke-width=\"1\"/><text x=\"8\" y=\"")
                .Append(F(y + 4)).Append("\" fill=\"#77766f\" font-size=\"11\">")
                .Append(F(maxLatency * fraction)).Append(" ms</text>");
        }

        for (int seriesIndex = 0; seriesIndex < series.Length; seriesIndex++)
        {
            var samples = series[seriesIndex].FrameLatencySamplesMilliseconds!;
            var path = new StringBuilder();
            for (int sampleIndex = 0; sampleIndex < samples.Count; sampleIndex++)
            {
                double x = left + (samples.Count <= 1 ? 0 : plotWidth * sampleIndex / (samples.Count - 1));
                double y = top + plotHeight - Math.Clamp(samples[sampleIndex] / maxLatency, 0, 1) * plotHeight;
                path.Append(sampleIndex == 0 ? "M " : " L ").Append(F(x)).Append(' ').Append(F(y));
            }
            chart.Append("<path d=\"").Append(path).Append("\" fill=\"none\" stroke=\"")
                .Append(colors[seriesIndex % colors.Length]).Append("\" stroke-width=\"1.5\" stroke-linejoin=\"round\" stroke-linecap=\"round\"/>");
        }
        chart.Append("<text x=\"").Append(F(left + plotWidth / 2)).Append("\" y=\"328\" fill=\"#77766f\" font-size=\"11\" text-anchor=\"middle\">Image request in dataset order</text></svg><div class=\"legend\">");
        for (int seriesIndex = 0; seriesIndex < series.Length; seriesIndex++)
        {
            chart.Append("<span><i style=\"background:").Append(colors[seriesIndex % colors.Length])
                .Append("\"></i>").Append(WebUtility.HtmlEncode(series[seriesIndex].Device)).Append(" · end-to-end frame</span>");
        }
        chart.Append("</div>");
        return chart.ToString();
    }
}



