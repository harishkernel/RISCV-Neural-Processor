using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;

namespace ProjectAgentGateV.Controls;

/// <summary>Draws a 32x32 transparent AND-gate sprite at pixel-art scaling.</summary>
public sealed class AndGateMascot : FrameworkElement
{
    private const int FrameSize = 32;
    private const int FrameCount = 12;
    // Short clips are deliberately composed from the supplied sprite sheet so
    // the character can greet, look around, hop, travel and celebrate without
    // replacing its pixel art with a static vector or a stretched full sheet.
    private static readonly int[][] IdleSequences =
    [
        [0, 0, 1, 0, 2, 0, 0, 3, 4, 3, 0, 5, 6, 5, 0, 0, 1, 2, 1, 0, 0, 3, 4, 0],
        [0, 1, 2, 2, 1, 0, 5, 6, 5, 0, 0, 3, 4, 3, 0, 1, 0, 2, 0, 0, 5, 6, 0, 0],
        [0, 2, 1, 0, 0, 5, 6, 5, 0, 0, 2, 0, 1, 0, 3, 4, 3, 0, 0, 5, 6, 5, 0, 0],
        [0, 0, 0, 3, 4, 3, 0, 0, 1, 0, 2, 0, 0, 5, 6, 5, 0, 0, 3, 4, 3, 0, 0, 1],
        [0, 2, 0, 1, 0, 0, 3, 4, 3, 0, 5, 6, 5, 0, 0, 1, 2, 1, 0, 0, 3, 4, 0, 0]
    ];
    private static readonly int[][] WorkSequences =
    [
        [7, 8, 7, 8, 9, 9, 10, 10, 9, 10, 11, 0, 7, 8, 7, 8, 9, 10, 9, 10, 11, 0, 7, 8],
        [9, 10, 9, 10, 7, 8, 7, 8, 11, 7, 8, 9, 10, 9, 10, 11, 7, 8, 7, 8, 9, 10, 0, 7],
        [7, 8, 7, 8, 11, 9, 10, 9, 10, 10, 0, 7, 8, 9, 10, 9, 10, 11, 7, 8, 7, 8, 0, 9],
        [9, 9, 10, 9, 10, 11, 7, 8, 7, 8, 0, 9, 10, 9, 10, 7, 8, 7, 8, 11, 0, 9, 10, 7],
        [7, 8, 7, 8, 9, 10, 9, 10, 11, 11, 0, 0, 9, 10, 9, 10, 7, 8, 7, 8, 11, 0, 9, 10]
    ];
    private static readonly int[] ResultSequence = [0, 5, 6, 5, 0, 1, 2, 1, 0, 3, 4, 3, 0, 5, 6, 5, 0, 0, 1, 2, 1, 0, 0, 0];
    private static readonly BitmapSource[] Frames = LoadFrames();
    private readonly DispatcherTimer _timer = new() { Interval = TimeSpan.FromMilliseconds(84) };
    private int _frameIndex;
    private int _sequenceIndex;
    private int[] _currentSequence = IdleSequences[0];
    private bool _isAnimationPaused;
    private bool _isWorking;
    private bool _isFacingLeft;
    private int _animationStep;
    private bool _isCelebrating;

    public int FrameIndex => _frameIndex;

    public bool IsAnimationPaused
    {
        get => _isAnimationPaused;
        set
        {
            if (_isAnimationPaused == value) return;
            _isAnimationPaused = value;
            if (value) _timer.Stop();
            else StartIfVisible();
        }
    }

    public event EventHandler? FrameAdvanced;

    public bool IsWorking
    {
        get => _isWorking;
        set
        {
            if (_isWorking == value) return;
            _isWorking = value;
            _isCelebrating = false;
            _sequenceIndex = 0;
            _currentSequence = ChooseSequence();
            InvalidateVisual();
        }
    }

    public bool IsFacingLeft
    {
        get => _isFacingLeft;
        set
        {
            if (_isFacingLeft == value) return;
            _isFacingLeft = value;
            InvalidateVisual();
        }
    }

    /// <summary>Plays one longer result celebration, then returns to a varied idle loop.</summary>
    public void PlayResultAnimation()
    {
        _isWorking = false;
        _isCelebrating = true;
        _sequenceIndex = 0;
        _currentSequence = ResultSequence;
        StartIfVisible();
        InvalidateVisual();
    }

    public AndGateMascot()
    {
        SnapsToDevicePixels = true;
        RenderOptions.SetBitmapScalingMode(this, BitmapScalingMode.NearestNeighbor);
        _timer.Tick += (_, _) =>
        {
            if (_isAnimationPaused) return;
            if (_sequenceIndex >= _currentSequence.Length)
            {
                _sequenceIndex = 0;
                if (_isCelebrating) _isCelebrating = false;
                _currentSequence = ChooseSequence();
            }
            _frameIndex = _currentSequence[_sequenceIndex++];
            _animationStep++;
            InvalidateVisual();
            FrameAdvanced?.Invoke(this, EventArgs.Empty);
        };
        Loaded += (_, _) => StartIfVisible();
        Unloaded += (_, _) => _timer.Stop();
        IsVisibleChanged += (_, _) =>
        {
            if (IsVisible) StartIfVisible();
            else _timer.Stop();
        };
    }

    protected override Size MeasureOverride(Size availableSize) => new(64, 64);

    private static BitmapSource[] LoadFrames()
    {
        var sheet = new BitmapImage();
        sheet.BeginInit();
        sheet.UriSource = new Uri("pack://application:,,,/Assets/and-gate-spritesheet.png", UriKind.Absolute);
        sheet.CacheOption = BitmapCacheOption.OnLoad;
        sheet.EndInit();
        sheet.Freeze();

        var frames = new BitmapSource[FrameCount];
        for (var index = 0; index < FrameCount; index++)
        {
            var frame = new CroppedBitmap(sheet, new Int32Rect(index * FrameSize, 0, FrameSize, FrameSize));
            frame.Freeze();
            frames[index] = frame;
        }
        return frames;
    }

    private void StartIfVisible()
    {
        if (IsVisible && !_isAnimationPaused && !_timer.IsEnabled) _timer.Start();
    }

    private int[] ChooseSequence()
    {
        var choices = _isWorking ? WorkSequences : IdleSequences;
        return choices[Random.Shared.Next(choices.Length)];
    }

    protected override void OnRender(DrawingContext drawingContext)
    {
        if (ActualWidth <= 0 || ActualHeight <= 0) return;
        var hop = _isCelebrating
            ? (_frameIndex is 5 or 6 ? -7.0 : Math.Sin(_animationStep * 0.42) * 1.4)
            : _isWorking
                ? (_frameIndex is 8 or 11 ? -3.0 : Math.Sin(_animationStep * 0.42) * 1.4)
                : (_frameIndex is 5 or 6 ? -3.5 : Math.Sin(_animationStep * 0.16) * 0.8);
        var tilt = _frameIndex == 3 ? -7.0 : _frameIndex == 4 ? 7.0
            : _isWorking && _frameIndex == 8 ? -4.0
            : _isWorking && _frameIndex == 7 ? 4.0 : 0.0;

        drawingContext.PushTransform(new TranslateTransform(0, hop));
        drawingContext.PushTransform(new RotateTransform(tilt, ActualWidth / 2, ActualHeight / 2));
        if (_isFacingLeft)
            drawingContext.PushTransform(new ScaleTransform(-1, 1, ActualWidth / 2, ActualHeight / 2));
        drawingContext.DrawImage(Frames[_frameIndex], new Rect(0, 0, ActualWidth, ActualHeight));
        if (_isFacingLeft) drawingContext.Pop();
        drawingContext.Pop();
        drawingContext.Pop();

    }
}
