using System.Globalization;
using System.Windows;
using System.Windows.Media;
using ProjectAgentGateV.Models;

namespace ProjectAgentGateV.Controls;

/// <summary>Small dependency-free latency plot for live samples and completed runs.</summary>
public sealed class LatencyChartControl : FrameworkElement
{
    private static readonly Typeface AxisTypeface = new("Segoe UI");
    private static readonly Brush LabelBrush = Freeze(new SolidColorBrush(Color.FromRgb(117, 115, 110)));
    private static readonly Pen GridPen = Freeze(new Pen(new SolidColorBrush(Color.FromRgb(232, 231, 228)), 1));
    private static readonly Pen AxisPen = Freeze(new Pen(new SolidColorBrush(Color.FromRgb(205, 203, 198)), 1));
    private IReadOnlyList<LatencyChartSeries> _series = [];

    public LatencyChartControl()
    {
        SnapsToDevicePixels = true;
        UseLayoutRounding = true;
        ClipToBounds = true;
    }

    public void SetSeries(IEnumerable<LatencyChartSeries> series)
    {
        _series = series.Where(item => item.Samples.Count > 0).ToArray();
        InvalidateVisual();
    }

    protected override Size MeasureOverride(Size availableSize) => new(
        Math.Max(360, double.IsInfinity(availableSize.Width) ? 520 : availableSize.Width),
        Math.Max(300, double.IsInfinity(availableSize.Height) ? 360 : availableSize.Height));

    protected override void OnRender(DrawingContext dc)
    {
        base.OnRender(dc);
        var width = ActualWidth;
        var height = ActualHeight;
        if (width < 100 || height < 100) return;

        const double left = 52;
        const double right = 16;
        const double top = 30;
        const double bottom = 38;
        var plotWidth = Math.Max(1, width - left - right);
        var plotHeight = Math.Max(1, height - top - bottom);
        var allSamples = _series.SelectMany(line => line.Samples).Where(double.IsFinite).ToArray();
        if (allSamples.Length == 0)
        {
            DrawText(dc, "Measured per-image latency will appear here", left + 12, top + plotHeight / 2 - 10, 12, LabelBrush);
            DrawText(dc, "One sample is collected for each image · batch size 1", left + 12, top + plotHeight / 2 + 12, 10, LabelBrush);
            DrawGrid(dc, left, top, plotWidth, plotHeight, 1);
            return;
        }

        var maxValue = Math.Max(0.01, allSamples.Max());
        var axisMaximum = NiceMaximum(maxValue * 1.08);
        DrawText(dc, "ms / frame", 2, 4, 10, LabelBrush);
        for (var tick = 0; tick <= 4; tick++)
        {
            var fraction = tick / 4d;
            var y = top + plotHeight * (1 - fraction);
            dc.DrawLine(GridPen, new Point(left, y), new Point(left + plotWidth, y));
            DrawText(dc, (axisMaximum * fraction).ToString("0.##", CultureInfo.CurrentCulture), 2, y - 8, 10, LabelBrush);
        }
        dc.DrawLine(AxisPen, new Point(left, top), new Point(left, top + plotHeight));
        dc.DrawLine(AxisPen, new Point(left, top + plotHeight), new Point(left + plotWidth, top + plotHeight));

        foreach (var line in _series)
            DrawSeries(dc, line, left, top, plotWidth, plotHeight, axisMaximum);

        DrawText(dc, "Image samples", left + plotWidth / 2 - 34, top + plotHeight + 15, 10, LabelBrush);
        DrawText(dc, "1", left, top + plotHeight + 4, 9, LabelBrush);
        DrawText(dc, allSamples.Length.ToString("N0", CultureInfo.CurrentCulture), left + plotWidth - 35, top + plotHeight + 4, 9, LabelBrush);
        DrawLegend(dc, width);
    }

    private void DrawGrid(DrawingContext dc, double left, double top, double width, double height, double axisMaximum)
    {
        for (var tick = 0; tick <= 4; tick++)
        {
            var y = top + height * (1 - tick / 4d);
            dc.DrawLine(GridPen, new Point(left, y), new Point(left + width, y));
            DrawText(dc, (axisMaximum * tick / 4d).ToString("0.##", CultureInfo.CurrentCulture), 2, y - 8, 10, LabelBrush);
        }
        dc.DrawLine(AxisPen, new Point(left, top), new Point(left, top + height));
        dc.DrawLine(AxisPen, new Point(left, top + height), new Point(left + width, top + height));
    }

    private static void DrawSeries(DrawingContext dc, LatencyChartSeries series, double left, double top, double width, double height, double axisMaximum)
    {
        var color = series.Color;
        var pen = new Pen(new SolidColorBrush(color), 1.8);
        pen.Freeze();
        var samples = series.Samples;
        var count = Math.Min(samples.Count, 1400);
        if (count == 0) return;
        var geometry = new StreamGeometry();
        using (var ctx = geometry.Open())
        {
            for (var i = 0; i < count; i++)
            {
                var sourceIndex = count == 1 ? 0 : (int)Math.Round(i * (samples.Count - 1d) / (count - 1));
                var value = Math.Clamp(samples[sourceIndex], 0, axisMaximum);
                var point = new Point(left + (count == 1 ? 0 : i * width / (count - 1)), top + height * (1 - value / axisMaximum));
                if (i == 0) ctx.BeginFigure(point, false, false);
                else ctx.LineTo(point, true, false);
            }
        }
        geometry.Freeze();
        dc.DrawGeometry(null, pen, geometry);
    }

    private void DrawLegend(DrawingContext dc, double width)
    {
        var x = 12d;
        foreach (var line in _series)
        {
            var pen = new Pen(new SolidColorBrush(line.Color), 2);
            pen.Freeze();
            dc.DrawLine(pen, new Point(x, 13), new Point(x + 17, 13));
            DrawText(dc, line.Name, x + 22, 6, 10, LabelBrush);
            var labelWidth = new FormattedText(line.Name, CultureInfo.CurrentCulture, FlowDirection.LeftToRight, AxisTypeface, 10, LabelBrush, VisualTreeHelper.GetDpi(this).PixelsPerDip).Width;
            x += 22 + labelWidth + 18;
            if (x > width - 90) break;
        }
    }

    private void DrawText(DrawingContext dc, string value, double x, double y, double fontSize, Brush brush)
    {
        var text = new FormattedText(value, CultureInfo.CurrentCulture, FlowDirection.LeftToRight, AxisTypeface, fontSize, brush, VisualTreeHelper.GetDpi(this).PixelsPerDip);
        dc.DrawText(text, new Point(x, y));
    }

    private static double NiceMaximum(double value)
    {
        if (!double.IsFinite(value) || value <= 0) return 1;
        var power = Math.Pow(10, Math.Floor(Math.Log10(value)));
        var normalized = value / power;
        var rounded = normalized <= 1 ? 1 : normalized <= 2 ? 2 : normalized <= 5 ? 5 : 10;
        return rounded * power;
    }

    private static Brush Freeze(SolidColorBrush brush)
    {
        brush.Freeze();
        return brush;
    }

    private static Pen Freeze(Pen pen)
    {
        pen.Freeze();
        return pen;
    }
}

public sealed record LatencyChartSeries(string Name, IReadOnlyList<double> Samples, Color Color);
