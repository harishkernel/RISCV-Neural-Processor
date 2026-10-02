using Microsoft.Win32;
using ProjectAgentGateV.Controls;
using ProjectAgentGateV.Models;
using ProjectAgentGateV.Services;
using ProjectAgentGateV.Views;
using System.Diagnostics;
using System.IO;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace ProjectAgentGateV;

public partial class MainWindow : Window
{
    private readonly CancellationTokenSource _windowLifetime = new();
    private CancellationTokenSource? _benchmarkCancellation;
    private CancellationTokenSource? _datasetValidationCancellation;
    private HardwareSnapshot? _hardware;
    private UserProfile? _user;
    private string? _datasetDirectory;
    private string? _latestReport;
    private bool _isRunning;
    private bool _isValidatingDataset;
    private bool _hasDatasetSelection;
    private double _latestFps;
    private double _runnerX;
    private double _heroX;
    private int _heroDirection = 1;
    private readonly DispatcherTimer _runnerTimer = new() { Interval = TimeSpan.FromMilliseconds(83) };
    private readonly Stopwatch _progressClock = new();
    private readonly Queue<double> _cpuSamples = new();
    private readonly Queue<double> _gpuSamples = new();
    private readonly List<double> _liveLatencySamples = new();
    private int _runnerDirection = 1;
    private double _runnerPhase;

    private const long OperationsPerImage = 233_303_552;

    private static readonly CountryOption[] Countries =
    [
        new("India", "IN"), new("United States", "US"), new("Canada", "CA"),
        new("United Kingdom", "GB"), new("Germany", "DE"), new("France", "FR"),
        new("Japan", "JP"), new("Australia", "AU"), new("Brazil", "BR")
    ];

    public MainWindow()
    {
        InitializeComponent();
        Icon = BitmapFrame.Create(new Uri("pack://application:,,,/Assets/Project-AgentGate-V.ico", UriKind.Absolute));
        CountryCombo.ItemsSource = Countries;
        CountryCombo.SelectedIndex = -1;
        _runnerTimer.Tick += RunnerTimer_Tick;
        Loaded += (_, _) => _runnerTimer.Start();
        Unloaded += (_, _) => _runnerTimer.Stop();
        MascotStage.SizeChanged += (_, _) => SetMascotPosition();
        UpdateSelectedDeviceLabel();
    }

    private async void Window_Loaded(object sender, RoutedEventArgs e)
    {
        ModelStatusText.Text = "The embedded ONNX engine loads into memory when the test starts.";
        DatasetPathText.Text = "No dataset folder selected";
        _hasDatasetSelection = false;
        SetDatasetBadge("Choose an extracted test folder to scan its classes and images.", ready: false);
        UpdateDatasetSelectionVisual();
        OnboardingView.Visibility = Visibility.Collapsed;
        TransitionView.Visibility = Visibility.Visible;
        TransitionTitle.Text = "Checking this PC";
        TransitionDescription.Text = "Detecting processors and graphics adapters before showing available run targets.";
        TransitionStatus.Text = "Reading local Windows hardware details";
        FooterStatus.Text = "Checking available devices…";
        GpuDeviceCheckBox.Visibility = Visibility.Collapsed;
        GpuDeviceCheckBox.IsEnabled = false;
        try
        {
            _hardware = await HardwareProfiler.CaptureAsync(_windowLifetime.Token);
            RenderHardware(_hardware);
            if (_hardware.Gpus.Count > 0)
            {
                GpuDeviceCheckBox.Visibility = Visibility.Visible;
                GpuDeviceCheckBox.IsEnabled = true;
                GpuProviderNote.Text = $"Windows detected {_hardware.Gpus.Count} graphics adapter(s). This runner uses DirectML adapter 0; provider availability is checked when the run starts.";
            }
            else
            {
                GpuDeviceCheckBox.IsChecked = false;
                GpuProviderNote.Text = "No graphics adapter was detected; CPU inference is available.";
            }
            FooterStatus.Text = "Device check complete";
        }
        catch (OperationCanceledException) { return; }
        catch (Exception error)
        {
            _hardware = new HardwareSnapshot();
            GpuDeviceCheckBox.IsChecked = false;
            GpuDeviceCheckBox.Visibility = Visibility.Collapsed;
            GpuProviderNote.Text = "Graphics hardware could not be detected; CPU inference is available.";
            ProfileStatusText.Text = "Some system fields could not be read.";
            HardwareBriefText.Text = error.Message;
            FooterStatus.Text = "Hardware profile is incomplete";
        }
        finally
        {
            TransitionView.Visibility = Visibility.Collapsed;
            OnboardingView.Visibility = Visibility.Visible;
        }
        UpdateCanRun();
    }

    private void Continue_Click(object sender, RoutedEventArgs e)
    {
        var username = UsernameBox.Text.Trim();
        if (username.Length == 0)
        {
            UsernameBox.Focus();
            FooterStatus.Text = "Enter a username to continue.";
            return;
        }
        if (CountryCombo.SelectedItem is not CountryOption country)
        {
            FooterStatus.Text = "Choose a country or region.";
            return;
        }

        _user = new UserProfile(username, country.Name);
        OnboardingView.Visibility = Visibility.Collapsed;
        DatasetView.Visibility = Visibility.Visible;
        FooterStatus.Text = "Select a target dataset";
        UpdateCanRun();
    }

    private void DatasetContinue_Click(object sender, RoutedEventArgs e)
    {
        if (_user is null || _hardware is null || _isValidatingDataset || string.IsNullOrWhiteSpace(_datasetDirectory)) return;
        SelectedDatasetSummary.Text = $"Dataset  ·  {_datasetDirectory}";
        WelcomeTitle.Text = $"Benchmark  ·  {_user.Username}";
        DatasetView.Visibility = Visibility.Collapsed;
        DashboardView.Visibility = Visibility.Visible;
        SystemProfileExpander.IsExpanded = false;
        FooterStatus.Text = "Ready to run inference";
        UpdateCanRun();
    }

    private void RenderHardware(HardwareSnapshot profile)
    {
        var baseClock = ReadBaseClock(profile.ProcessorName);
        ProfileStatusText.Text = $"Profiled {DateTime.Now:t} · local machine";
        HardwareBriefText.Text = $"{profile.OperatingSystem} · Windows {profile.WindowsVersion} (build {profile.WindowsBuild}) · {profile.Architecture}{Environment.NewLine}{profile.StorageSummary}";

        var hardwareDetails = new List<HardwareDetailRow>
        {
            new("OPERATING SYSTEM", $"{profile.OperatingSystem} · Windows {profile.WindowsVersion}", $"Build {profile.WindowsBuild} · {profile.Architecture}"),
            new("PROCESSOR", profile.ProcessorName, $"{profile.CpuCoreDisplay} · base {baseClock} · max {profile.CpuClockDisplay} · current {profile.CurrentClockMHz?.ToString() ?? "not reported"} MHz"),
            new("PHYSICAL MEMORY", profile.TotalMemoryDisplay, $"{profile.AvailableMemoryDisplay} available · {profile.RamSpeed} · {profile.RamType}"),
            new("GRAPHICS", profile.GpuSummary, GpuMemoryDescription(profile.Gpus.FirstOrDefault())),
            new("STORAGE", profile.StorageSummary, "Fixed volumes · available capacity")
        };
        hardwareDetails.AddRange(profile.Gpus.Skip(1).Select(g => new HardwareDetailRow("ADDITIONAL GRAPHICS", g.Name, $"{GpuMemoryDescription(g)} · driver {g.DriverVersion}")));
        HardwareDetailsList.ItemsSource = hardwareDetails;
    }

    private static string ReadBaseClock(string processorName)
    {
        var match = Regex.Match(processorName, @"@\s*(\d+(?:\.\d+)?)\s*GHz", RegexOptions.IgnoreCase);
        return match.Success ? $"{match.Groups[1].Value} GHz" : "Not reported";
    }

    private static string GpuMemoryDescription(GpuInfo? gpu)
    {
        if (gpu is null) return "Memory not reported by WMI";
        if (gpu.Classification.StartsWith("Integrated", StringComparison.OrdinalIgnoreCase))
            return $"Shared system memory · {gpu.DedicatedVideoMemoryDisplay} reported by WMI";
        return $"Dedicated memory · {gpu.DedicatedVideoMemoryDisplay}";
    }

    private async Task ShowDatasetPickerAsync()
    {
        var picker = new OpenFolderDialog
        {
            Title = "Choose the test dataset root folder",
            InitialDirectory = Directory.Exists(_datasetDirectory) ? _datasetDirectory : Environment.GetFolderPath(Environment.SpecialFolder.MyPictures),
            Multiselect = false
        };
        if (picker.ShowDialog(this) != true) return;
        await SelectDatasetRootAsync(picker.FolderName);
    }

    private async void DatasetDropZone_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
    {
        if (e.ChangedButton != MouseButton.Left || e.Handled) return;
        e.Handled = true;
        await ShowDatasetPickerAsync();
    }

    private async void DatasetDropZone_KeyDown(object sender, KeyEventArgs e)
    {
        if (e.Key is not (Key.Enter or Key.Space)) return;
        e.Handled = true;
        await ShowDatasetPickerAsync();
    }

    private void DatasetDropZone_DragEnter(object sender, DragEventArgs e) => DatasetDropZone_DragOver(sender, e);

    private void DatasetDropZone_DragOver(object sender, DragEventArgs e)
    {
        bool valid = e.Data.GetDataPresent(DataFormats.FileDrop)
            && e.Data.GetData(DataFormats.FileDrop) is string[] { Length: 1 } paths
            && Directory.Exists(paths[0]);
        e.Effects = valid ? DragDropEffects.Copy : DragDropEffects.None;
        DatasetDropZone.Background = valid ? new SolidColorBrush(Color.FromRgb(242, 241, 239)) : new SolidColorBrush(Color.FromRgb(250, 249, 247));
        DatasetDropZone.BorderBrush = valid ? new SolidColorBrush(Color.FromRgb(112, 110, 105)) : new SolidColorBrush(Color.FromRgb(220, 218, 214));
        e.Handled = true;
    }

    private void DatasetDropZone_DragLeave(object sender, DragEventArgs e) => ResetDropZoneStyle();

    private async void DatasetDropZone_Drop(object sender, DragEventArgs e)
    {
        ResetDropZoneStyle();
        if (e.Data.GetData(DataFormats.FileDrop) is not string[] { Length: 1 } paths || !Directory.Exists(paths[0]))
        {
            SetDatasetBadge("Drop one extracted dataset folder. Do not drop individual images or a ZIP file.", ready: false);
            return;
        }
        await SelectDatasetRootAsync(paths[0]);
    }

    private void ResetDropZoneStyle()
    {
        UpdateDatasetSelectionVisual();
    }

    private async Task SelectDatasetRootAsync(string selectedRoot)
    {
        _datasetValidationCancellation?.Cancel();
        _datasetValidationCancellation?.Dispose();
        _datasetValidationCancellation = CancellationTokenSource.CreateLinkedTokenSource(_windowLifetime.Token);
        var token = _datasetValidationCancellation.Token;
        _datasetDirectory = null;
        _hasDatasetSelection = true;
        _isValidatingDataset = true;
        DatasetPathText.Text = selectedRoot;
        DatasetPathText.ToolTip = selectedRoot;
        UpdateDatasetSelectionVisual(scanning: true);
        SetDatasetBadge("Scanning all 19 required class folders and supported images…", ready: false, scanning: true);
        FooterStatus.Text = "Scanning target dataset…";
        UpdateCanRun();
        try
        {
            var validation = await Task.Run(() => DatasetService.InspectRoot(selectedRoot, token), token);
            if (validation.IsReady)
            {
                _datasetDirectory = validation.RootDirectory;
                SetDatasetBadge(validation.Summary, ready: true);
                UpdateDatasetSelectionVisual(ready: true);
                FooterStatus.Text = $"Dataset ready · {validation.ImageCount:N0} images";
            }
            else
            {
                var detail = validation.MissingOrEmptyClasses.Count == 0 ? "" : $" Missing or empty: {string.Join(", ", validation.MissingOrEmptyClasses)}.";
                SetDatasetBadge(validation.Summary + detail, ready: false);
                UpdateDatasetSelectionVisual();
                FooterStatus.Text = "Target dataset is incomplete";
            }
        }
        catch (OperationCanceledException) { }
        catch (Exception error)
        {
            SetDatasetBadge($"Could not scan this folder: {error.Message}", ready: false);
            UpdateDatasetSelectionVisual();
            FooterStatus.Text = "Dataset folder not ready";
        }
        finally
        {
            if (_datasetValidationCancellation?.Token == token) _isValidatingDataset = false;
        }
        UpdateCanRun();
    }

    private void SetDatasetBadge(string text, bool ready, bool scanning = false)
    {
        DatasetCountText.Text = text;
        DatasetStatusBadge.Background = new SolidColorBrush(ready ? Color.FromRgb(239, 244, 237) : scanning ? Color.FromRgb(244, 243, 241) : Color.FromRgb(248, 242, 239));
        DatasetCountText.Foreground = new SolidColorBrush(ready ? Color.FromRgb(55, 84, 52) : Color.FromRgb(93, 81, 75));
    }

    private void UpdateDatasetSelectionVisual(bool ready = false, bool scanning = false)
    {
        if (DatasetDropZone is null) return;
        DatasetDropZone.Background = new SolidColorBrush(_hasDatasetSelection ? Color.FromRgb(244, 243, 240) : Color.FromRgb(250, 249, 247));
        DatasetDropZone.BorderBrush = new SolidColorBrush(ready ? Color.FromRgb(102, 126, 94) : _hasDatasetSelection ? Color.FromRgb(139, 135, 127) : Color.FromRgb(214, 211, 205));
        DatasetDropZone.BorderThickness = new Thickness(_hasDatasetSelection ? 1.5 : 1);
        DatasetPathPanel.Background = new SolidColorBrush(_hasDatasetSelection ? Color.FromRgb(244, 243, 240) : Color.FromRgb(247, 246, 244));
        DatasetPathPanel.BorderBrush = new SolidColorBrush(_hasDatasetSelection ? Color.FromRgb(211, 208, 202) : Color.FromRgb(232, 231, 229));
        DatasetPathText.Foreground = new SolidColorBrush(_hasDatasetSelection ? Color.FromRgb(55, 54, 51) : Color.FromRgb(120, 118, 113));
        DatasetDropHeadline.Text = scanning ? "Checking the selected folder…"
            : ready ? "Dataset selected and ready"
            : _hasDatasetSelection ? "Folder selected · validation needed"
            : "Choose a test folder";
        DatasetDropHint.Text = _hasDatasetSelection
            ? "Click anywhere here to choose a different folder, or drag a replacement onto this panel."
            : "Click anywhere here to open File Explorer, or drag a folder onto this panel.";
        DatasetZoneIcon.Fill = new SolidColorBrush(ready ? Color.FromRgb(70, 100, 63) : Color.FromRgb(104, 101, 96));
        DatasetDropZone.ToolTip = _hasDatasetSelection ? "Choose a different dataset folder" : "Open File Explorer to choose the test dataset folder";
    }

    private async void RunBenchmark_Click(object sender, RoutedEventArgs e)
    {
        if (_user is null || _hardware is null || _isValidatingDataset || string.IsNullOrWhiteSpace(_datasetDirectory)) return;
        var devices = new List<BenchmarkDevice>();
        if (CpuDeviceCheckBox.IsChecked == true) devices.Add(BenchmarkDevice.Cpu);
        if (GpuDeviceCheckBox.IsChecked == true) devices.Add(BenchmarkDevice.DirectMlGpu);
        if (devices.Count == 0)
        {
            FooterStatus.Text = "Select at least one compute engine.";
            return;
        }
        string datasetRoot = _datasetDirectory!;
        UserProfile user = _user!;
        HardwareSnapshot hardware = _hardware!;
        _benchmarkCancellation = new CancellationTokenSource();
        var token = _benchmarkCancellation.Token;
        SetRunning(true);
        TransitionView.Visibility = Visibility.Collapsed;
        BenchmarkProgressBar.Value = 0;
        BenchmarkProgressBar.Visibility = Visibility.Visible;
        ProgressTelemetryPanel.Visibility = Visibility.Visible;
        BenchmarkStatusText.Text = "Starting the selected inference device(s)…";
        ResultsCard.Visibility = Visibility.Collapsed;
        ReportReadyPanel.Visibility = Visibility.Collapsed;
        ComparisonTable.Visibility = Visibility.Collapsed;
        _cpuSamples.Clear();
        _gpuSamples.Clear();
        _liveLatencySamples.Clear();
        LatencyChart.SetSeries([]);
        LatencyP50Text.Text = "—";
        LatencyP95Text.Text = "—";
        LatencyP99Text.Text = "—";
        LatencyMaxText.Text = "—";
        CpuUsageText.Text = "Sampling…";
        GpuUsageText.Text = "Sampling…";
        ActiveMemoryText.Text = "Sampling…";
        RunnerFpsText.Text = "0.0 FPS";
        GopsText.Text = "0.00 GOPS";
        FooterStatus.Text = "Preparing benchmark";

        try
        {
            BenchmarkStatusText.Text = "Loading the embedded inference engine into memory…";
            FooterStatus.Text = "Loading embedded engine";
            var modelBytes = await Task.Run(EmbeddedOnnxModel.Load, token);

            await using var telemetry = new SystemTelemetrySampler();
            telemetry.Start(hardware.TotalMemoryBytes, sample => Dispatcher.BeginInvoke(new Action(() => RenderTelemetry(sample)), DispatcherPriority.Background), token);
            var comparisons = new List<DeviceComparison>();
            BenchmarkResult? primaryResult = null;
            for (int deviceIndex = 0; deviceIndex < devices.Count; deviceIndex++)
            {
                var device = devices[deviceIndex];
                var deviceName = device == BenchmarkDevice.Cpu ? "CPU · ONNX Runtime" : "GPU · DirectML";
                DeviceActiveText.Text = deviceName;
                BenchmarkProgressBar.Value = 0;
                BenchmarkStatusText.Text = devices.Count == 1
                    ? $"Starting {deviceName} · preprocessing is excluded from timed inference."
                    : $"Run {deviceIndex + 1} of {devices.Count} · starting {deviceName}.";
                FooterStatus.Text = $"Running {deviceName}";

                try
                {
                    using var inference = await Task.Run(() => new OnnxBenchmarkService(modelBytes, device), token);
                    var progress = new Progress<BenchmarkProgress>(p =>
                    {
                        BenchmarkProgressBar.Value = p.Percent;
                        BenchmarkStatusText.Text = $"{deviceName} · {p.Completed:N0} / {p.Total:N0} images · {p.CurrentLabel} · {p.LastFrameLatencyMilliseconds:0.00} ms/frame";
                        _latestFps = p.InferenceSeconds <= 0 ? 0 : p.Completed / p.InferenceSeconds;
                        RunnerFpsText.Text = $"{_latestFps:0.0} FPS";
                        GopsText.Text = $"{OperationsPerImage * _latestFps / 1_000_000_000d:0.00} GOPS";
                        _liveLatencySamples.Add(p.LastFrameLatencyMilliseconds);
                        if (_liveLatencySamples.Count > 1400) _liveLatencySamples.RemoveAt(0);
                        var traceColor = device == BenchmarkDevice.Cpu
                            ? Color.FromRgb(43, 43, 43)
                            : Color.FromRgb(139, 108, 78);
                        LatencyChart.SetSeries([new LatencyChartSeries(deviceName, _liveLatencySamples.ToArray(), traceColor)]);
                    });
                    _progressClock.Restart();
                    var deviceResult = await Task.Run(() => inference.Run(datasetRoot, user, hardware, progress, token), token);
                    _progressClock.Stop();
                    comparisons.Add(new DeviceComparison(
                        deviceName,
                        deviceResult.ThroughputFps,
                        deviceResult.AccuracyPercent,
                        deviceResult.InferenceDurationSeconds,
                        FrameLatencySamplesMilliseconds: deviceResult.FrameLatencySamplesMilliseconds,
                        FrameLatency: deviceResult.FrameLatency,
                        ModelCallLatency: deviceResult.ModelCallLatency));
                    primaryResult ??= deviceResult;
                    RunnerFpsText.Text = $"{deviceResult.ThroughputFps:0.00} FPS";
                    GopsText.Text = $"{deviceResult.Gops:0.00} GOPS";
                }
                catch (OperationCanceledException) { throw; }
                catch (Exception error)
                {
                    comparisons.Add(new DeviceComparison(deviceName, 0, 0, 0, error.Message));
                    if (devices.Count == 1) throw new InvalidOperationException($"{deviceName} could not run: {error.Message}", error);
                }
            }

            await telemetry.DisposeAsync();
            _progressClock.Stop();
            if (primaryResult is null)
            {
                var failures = string.Join(Environment.NewLine, comparisons.Select(item => $"{item.Device}: {item.Error}"));
                throw new InvalidOperationException($"No selected inference device completed successfully.{Environment.NewLine}{failures}");
            }

            var result = primaryResult;
            result.DeviceComparisons = comparisons;
            result.SpriteAnimationDuringRun = "Enabled";
            AccuracyResultText.Text = $"{result.AccuracyPercent:0.00}%";
            ThroughputResultText.Text = $"{result.ThroughputFps:0.00} FPS";
            ResultDetailText.Text = $"{result.TotalImages:N0} images · batch 1 · model p99 {result.ModelCallLatency.P99Milliseconds:0.000} ms · frame p99 {result.FrameLatency.P99Milliseconds:0.000} ms · frame max {result.FrameLatency.MaximumMilliseconds:0.000} ms · {result.PrimaryDevice}";
            LatencyP50Text.Text = $"{result.FrameLatency.MedianMilliseconds:0.000} ms";
            LatencyP95Text.Text = $"{result.FrameLatency.P95Milliseconds:0.000} ms";
            LatencyP99Text.Text = $"{result.FrameLatency.P99Milliseconds:0.000} ms";
            LatencyMaxText.Text = $"{result.FrameLatency.MaximumMilliseconds:0.000} ms";
            _latestFps = result.ThroughputFps;
            DeviceActiveText.Text = devices.Count == 1
                ? $"{result.PrimaryDevice} · complete"
                : "CPU + DirectML · comparison complete";
            RunnerFpsText.Text = $"{result.ThroughputFps:0.00} FPS";
            GopsText.Text = $"{result.Gops:0.00} GOPS";
            ComparisonRunsList.ItemsSource = comparisons;
            ComparisonTable.Visibility = comparisons.Count > 1 ? Visibility.Visible : Visibility.Collapsed;
            ResultsCard.Visibility = Visibility.Visible;
            BenchmarkProgressBar.Value = 100;
            LatencyChart.SetSeries(comparisons
                .Where(item => item.Error is null && item.FrameLatencySamplesMilliseconds is { Count: > 0 })
                .Select((item, index) => new LatencyChartSeries(
                    item.Device,
                    item.FrameLatencySamplesMilliseconds!,
                    item.Device.Contains("DirectML", StringComparison.OrdinalIgnoreCase)
                        ? Color.FromRgb(139, 108, 78)
                        : index == 0 ? Color.FromRgb(43, 43, 43) : Color.FromRgb(95, 114, 131))));

            try
            {
                var paths = await ReportWriter.WriteAsync(result, App.BaseDirectory, token);
                _latestReport = paths.Html;
                ReportPathText.Text = $"HTML  {paths.Html}{Environment.NewLine}JSON  {paths.Json}";
                OpenReportButton.IsEnabled = true;
                ReportReadyCaption.Text = "Benchmark complete — report generated.";
                ReportReadyPanel.Visibility = Visibility.Visible;
                ReportMascot.PlayResultAnimation();
                BenchmarkStatusText.Text = "Benchmark and timestamped HTML / JSON reports completed.";
                FooterStatus.Text = "Benchmark complete";
            }
            catch (Exception reportError) when (reportError is not OperationCanceledException)
            {
                BenchmarkStatusText.Text = "Inference completed, but the report files could not be written.";
                FooterStatus.Text = "Report generation failed";
                new NoticeDialog("Report could not be saved", $"The inference metrics were collected, but the report could not be written to benchmark_reports next to the executable.\n\n{reportError.Message}") { Owner = this }.ShowDialog();
            }
        }
        catch (OperationCanceledException)
        {
            BenchmarkStatusText.Text = "Benchmark canceled before completion.";
            FooterStatus.Text = "Benchmark canceled";
        }
        catch (Exception error)
        {
            BenchmarkStatusText.Text = "The benchmark could not be completed.";
            FooterStatus.Text = "Benchmark error";
            new NoticeDialog("Benchmark could not start", error.Message) { Owner = this }.ShowDialog();
        }
        finally
        {
            _progressClock.Stop();
            RunnerSprite.IsWorking = false;
            _benchmarkCancellation?.Dispose();
            _benchmarkCancellation = null;
            BenchmarkProgressBar.Visibility = Visibility.Collapsed;
            SetRunning(false);
        }
    }

    private void SetRunning(bool running)
    {
        _isRunning = running;
        RunnerSprite.IsWorking = running;
        RunButton.Visibility = running ? Visibility.Collapsed : Visibility.Visible;
        CancelButton.Visibility = running ? Visibility.Visible : Visibility.Collapsed;
        CancelButton.IsEnabled = running;
        UpdateCanRun();
    }

    private void UpdateCanRun()
    {
        var datasetReady = !_isValidatingDataset && !string.IsNullOrWhiteSpace(_datasetDirectory);
        if (DatasetContinueButton is not null) DatasetContinueButton.IsEnabled = datasetReady && _user is not null;
        if (RunButton is not null)
            RunButton.IsEnabled = !_isRunning && datasetReady && _hardware is not null && _user is not null
                && (CpuDeviceCheckBox.IsChecked == true || (GpuDeviceCheckBox.Visibility == Visibility.Visible && GpuDeviceCheckBox.IsChecked == true));
    }

    private void CancelBenchmark_Click(object sender, RoutedEventArgs e)
    {
        CancelButton.IsEnabled = false;
        TransitionCancelButton.IsEnabled = false;
        _benchmarkCancellation?.Cancel();
        BenchmarkStatusText.Text = "Canceling after the current inference call…";
    }

    private void OpenReport_Click(object sender, RoutedEventArgs e)
    {
        var reportPath = _latestReport;
        if (string.IsNullOrWhiteSpace(reportPath) || !File.Exists(reportPath)) return;
        Process.Start(new ProcessStartInfo(reportPath) { UseShellExecute = true });
    }

    private void BackToSetup_Click(object sender, RoutedEventArgs e)
    {
        if (_isRunning) return;
        DatasetView.Visibility = Visibility.Collapsed;
        DashboardView.Visibility = Visibility.Collapsed;
        OnboardingView.Visibility = Visibility.Visible;
        FooterStatus.Text = "Benchmark setup";
    }

    private void BackToDataset_Click(object sender, RoutedEventArgs e)
    {
        if (_isRunning) return;
        DashboardView.Visibility = Visibility.Collapsed;
        DatasetView.Visibility = Visibility.Visible;
        FooterStatus.Text = "Review target dataset";
    }

    private void CountryCombo_SelectionChanged(object sender, System.Windows.Controls.SelectionChangedEventArgs e)
    {
        if (CountryPlaceholder is not null) CountryPlaceholder.Visibility = CountryCombo.SelectedItem is null ? Visibility.Visible : Visibility.Collapsed;
    }
    private void DeviceSelection_Changed(object sender, RoutedEventArgs e)
    {
        if (CpuDeviceCheckBox is null || GpuDeviceCheckBox is null || RunButton is null) return;
        UpdateSelectedDeviceLabel();
        UpdateCanRun();
    }

    private void UpdateSelectedDeviceLabel()
    {
        if (SelectedDevicesText is null) return;
        var cpu = CpuDeviceCheckBox.IsChecked == true;
        var gpu = GpuDeviceCheckBox.IsChecked == true;
        SelectedDevicesText.Text = cpu && gpu ? "CPU + DirectML" : gpu ? "DirectML GPU" : cpu ? "CPU · ONNX Runtime" : "Select a device";
    }

    private void RunnerTimer_Tick(object? sender, EventArgs e)
    {
        var heroWidth = HeroMascotStage.ActualWidth;
        var heroDistance = Math.Max(0, heroWidth - GateMascot.ActualWidth);
        if (heroDistance > 0)
        {
            _heroX += _heroDirection * 24 * _runnerTimer.Interval.TotalSeconds;
            if (_heroX >= heroDistance) { _heroX = heroDistance; _heroDirection = -1; }
            else if (_heroX <= 0) { _heroX = 0; _heroDirection = 1; }
            GateMascot.IsFacingLeft = _heroDirection < 0;
            Canvas.SetLeft(GateMascot, _heroX);
            Canvas.SetTop(GateMascot, 110 + Math.Sin(_runnerPhase * 0.55) * 3);
        }

        var width = MascotStage.ActualWidth > 0 ? MascotStage.ActualWidth : MascotStage.Width;
        var distance = Math.Max(0, width - RunnerSprite.ActualWidth);
        if (distance <= 0) return;
        var speed = (_isRunning ? 34 : 18) + Math.Min(300, _latestFps) * 0.32;
        _runnerX += _runnerDirection * speed * _runnerTimer.Interval.TotalSeconds;
        if (_runnerX >= distance) { _runnerX = distance; _runnerDirection = -1; }
        else if (_runnerX <= 0) { _runnerX = 0; _runnerDirection = 1; }
        _runnerPhase += _runnerTimer.Interval.TotalSeconds * (_isRunning ? 8 : 3.8);
        RunnerSprite.IsFacingLeft = _runnerDirection < 0;
        Canvas.SetLeft(RunnerSprite, _runnerX);
        Canvas.SetTop(RunnerSprite, 3 + Math.Sin(_runnerPhase) * (_isRunning ? 4 : 2));
    }

    private void SetMascotPosition()
    {
        var distance = Math.Max(0, MascotStage.ActualWidth - RunnerSprite.ActualWidth);
        _runnerX = Math.Clamp(_runnerX, 0, distance);
        Canvas.SetLeft(RunnerSprite, _runnerX);
    }

    private void RenderTelemetry(SystemTelemetrySample sample)
    {
        if (sample.CpuUtilizationPercent is double cpu)
        {
            CpuUsageText.Text = $"{cpu:0}%";
            AddSparkSample(_cpuSamples, cpu);
            RenderSparkline(CpuSparkline, _cpuSamples);
        }
        else CpuUsageText.Text = "—";

        if (sample.GpuUtilizationPercent is double gpu)
        {
            GpuUsageText.Text = $"{gpu:0}%";
            GpuUsageText.ToolTip = "Windows GPU 3D engine utilization";
            AddSparkSample(_gpuSamples, gpu);
            RenderSparkline(GpuSparkline, _gpuSamples);
        }
        else
        {
            GpuUsageText.Text = "—";
            GpuUsageText.ToolTip = "Windows GPU 3D utilization counters are not available on this system.";
        }

        var totalGb = sample.TotalPhysicalMemoryBytes / (1024d * 1024 * 1024);
        var appGb = sample.ProcessWorkingSetBytes / (1024d * 1024 * 1024);
        ActiveMemoryText.Text = totalGb > 0 ? $"{appGb:0.0} GB / {totalGb:0.0} GB" : $"{appGb:0.0} GB";
    }

    private static void AddSparkSample(Queue<double> samples, double value)
    {
        samples.Enqueue(Math.Clamp(value, 0, 100));
        while (samples.Count > 30) samples.Dequeue();
    }

    private static void RenderSparkline(Polyline line, Queue<double> samples)
    {
        if (line.ActualWidth <= 0 || line.ActualHeight <= 0 || samples.Count < 2) return;
        var points = new PointCollection();
        var values = samples.ToArray();
        for (var i = 0; i < values.Length; i++)
        {
            var x = i * line.ActualWidth / (values.Length - 1);
            var y = line.ActualHeight - values[i] * line.ActualHeight / 100d;
            points.Add(new Point(x, y));
        }
        line.Points = points;
    }
    private void ProfileCombo_PreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
    {
        if (sender is not System.Windows.Controls.ComboBox combo) return;
        combo.Focus();
        if (!combo.IsDropDownOpen)
        {
            combo.IsDropDownOpen = true;
            e.Handled = true;
        }
    }
    protected override void OnClosed(EventArgs e)
    {
        _windowLifetime.Cancel();
        _datasetValidationCancellation?.Cancel();
        _datasetValidationCancellation?.Dispose();
        _benchmarkCancellation?.Cancel();
        _benchmarkCancellation?.Dispose();
        _windowLifetime.Dispose();
        base.OnClosed(e);
    }
}

