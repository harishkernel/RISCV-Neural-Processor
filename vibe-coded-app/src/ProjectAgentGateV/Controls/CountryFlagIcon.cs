using System.Windows;
using System.Windows.Media;

namespace ProjectAgentGateV.Controls;

public sealed class CountryFlagIcon : FrameworkElement
{
    public static readonly DependencyProperty FlagCodeProperty = DependencyProperty.Register(
        nameof(FlagCode), typeof(string), typeof(CountryFlagIcon), new FrameworkPropertyMetadata("IN", FrameworkPropertyMetadataOptions.AffectsRender));

    public string FlagCode { get => (string)GetValue(FlagCodeProperty); set => SetValue(FlagCodeProperty, value); }
    protected override Size MeasureOverride(Size availableSize) => new(28, 18);
    protected override void OnRender(DrawingContext dc)
    {
        const double w = 28, h = 18;
        var rect = new Rect(0, 0, w, h);
        var clip = new RectangleGeometry(rect, 2, 2);
        dc.PushClip(clip);
        var white = Brushes.White;
        var red = new SolidColorBrush(Color.FromRgb(0xD8, 0x2E, 0x3A));
        switch (FlagCode.ToUpperInvariant())
        {
            case "IN":
                dc.DrawRectangle(new SolidColorBrush(Color.FromRgb(0xFF, 0x99, 0x33)), null, new Rect(0, 0, w, 6));
                dc.DrawRectangle(white, null, new Rect(0, 6, w, 6));
                dc.DrawRectangle(new SolidColorBrush(Color.FromRgb(0x13, 0x88, 0x08)), null, new Rect(0, 12, w, 6));
                dc.DrawEllipse(null, new Pen(new SolidColorBrush(Color.FromRgb(0x1A, 0x3C, 0x8B)), 0.9), new Point(14, 9), 2.1, 2.1);
                for (int i = 0; i < 12; i++) { double a = i * Math.PI / 6; dc.DrawLine(new Pen(new SolidColorBrush(Color.FromRgb(0x1A, 0x3C, 0x8B)), 0.45), new Point(14 + Math.Cos(a), 9 + Math.Sin(a)), new Point(14 + Math.Cos(a) * 1.8, 9 + Math.Sin(a) * 1.8)); }
                break;
            case "US":
                for (int i = 0; i < 7; i++) dc.DrawRectangle(i % 2 == 0 ? red : white, null, new Rect(0, i * (h / 7), w, h / 7 + 0.2));
                dc.DrawRectangle(new SolidColorBrush(Color.FromRgb(0x22, 0x3A, 0x70)), null, new Rect(0, 0, 12, 9.5));
                for (int r = 0; r < 3; r++) for (int c = 0; c < 3; c++) dc.DrawEllipse(white, null, new Point(2 + c * 4, 2 + r * 3), 0.45, 0.45);
                break;
            case "DE":
                dc.DrawRectangle(Brushes.Black, null, new Rect(0, 0, w, 6));
                dc.DrawRectangle(new SolidColorBrush(Color.FromRgb(0xD0, 0x0C, 0x27)), null, new Rect(0, 6, w, 6));
                dc.DrawRectangle(new SolidColorBrush(Color.FromRgb(0xFF, 0xCE, 0x00)), null, new Rect(0, 12, w, 6));
                break;
            case "FR":
                dc.DrawRectangle(new SolidColorBrush(Color.FromRgb(0x00, 0x55, 0xA4)), null, new Rect(0, 0, w / 3, h));
                dc.DrawRectangle(white, null, new Rect(w / 3, 0, w / 3, h));
                dc.DrawRectangle(new SolidColorBrush(Color.FromRgb(0xEF, 0x41, 0x43)), null, new Rect(w * 2 / 3, 0, w / 3, h));
                break;
            case "JP":
                dc.DrawRectangle(white, null, rect);
                dc.DrawEllipse(new SolidColorBrush(Color.FromRgb(0xBC, 0x00, 0x2D)), null, new Point(14, 9), 5, 5);
                break;
            case "GB":
                dc.DrawRectangle(new SolidColorBrush(Color.FromRgb(0x1C, 0x35, 0x8A)), null, rect);
                dc.DrawLine(new Pen(white, 4), new Point(-1, 0), new Point(29, 18)); dc.DrawLine(new Pen(white, 4), new Point(29, 0), new Point(-1, 18));
                dc.DrawLine(new Pen(red, 1.6), new Point(-1, 0), new Point(29, 18)); dc.DrawLine(new Pen(red, 1.6), new Point(29, 0), new Point(-1, 18));
                dc.DrawRectangle(white, null, new Rect(11, 0, 6, h)); dc.DrawRectangle(white, null, new Rect(0, 6, w, 6));
                dc.DrawRectangle(red, null, new Rect(12.3, 0, 3.4, h)); dc.DrawRectangle(red, null, new Rect(0, 7.3, w, 3.4));
                break;
            case "CA":
                dc.DrawRectangle(white, null, rect); dc.DrawRectangle(red, null, new Rect(0, 0, 6.5, h)); dc.DrawRectangle(red, null, new Rect(21.5, 0, 6.5, h));
                var maple = Geometry.Parse("M14,3 L15.2,6.2 18.2,5.2 17,8 20,8.8 16.4,10.4 17.2,14.2 14,12.5 10.8,14.2 11.6,10.4 8,8.8 11,8 9.8,5.2 12.8,6.2 Z");
                dc.DrawGeometry(red, null, maple);
                break;
            case "AU":
                dc.DrawRectangle(new SolidColorBrush(Color.FromRgb(0x00, 0x2A, 0x67)), null, rect);
                dc.DrawLine(new Pen(white, 2.5), new Point(0, 0), new Point(11, 9)); dc.DrawLine(new Pen(white, 2.5), new Point(11, 0), new Point(0, 9));
                dc.DrawLine(new Pen(red, 1), new Point(0, 0), new Point(11, 9)); dc.DrawLine(new Pen(red, 1), new Point(11, 0), new Point(0, 9));
                dc.DrawRectangle(white, null, new Rect(4.2, 0, 2.5, 9)); dc.DrawRectangle(white, null, new Rect(0, 3.2, 11, 2.5));
                dc.DrawRectangle(red, null, new Rect(4.9, 0, 1.1, 9)); dc.DrawRectangle(red, null, new Rect(0, 3.9, 11, 1.1));
                foreach (var p in new[] { new Point(19, 4), new Point(23, 8), new Point(17, 12), new Point(24, 14) }) dc.DrawEllipse(white, null, p, 0.7, 0.7);
                break;
            case "BR":
                dc.DrawRectangle(new SolidColorBrush(Color.FromRgb(0x00, 0x9B, 0x3A)), null, rect);
                var diamond = Geometry.Parse("M14,2 L25,9 14,16 3,9 Z");
                dc.DrawGeometry(new SolidColorBrush(Color.FromRgb(0xFF, 0xDF, 0x00)), null, diamond);
                dc.DrawEllipse(new SolidColorBrush(Color.FromRgb(0x00, 0x39, 0x8A)), null, new Point(14, 9), 3.7, 3.7);
                break;
            default:
                dc.DrawRectangle(white, null, rect);
                dc.DrawRectangle(new SolidColorBrush(Color.FromRgb(0x8D, 0x9A, 0xB1)), new Pen(new SolidColorBrush(Color.FromRgb(0xD8, 0xDE, 0xE9)), .5), rect);
                dc.DrawRectangle(red, null, new Rect(0, 0, 6, h));
                break;
        }
        dc.Pop();
        dc.DrawRoundedRectangle(null, new Pen(new SolidColorBrush(Color.FromArgb(42, 25, 35, 55)), .7), rect, 2, 2);
    }
}
