# Project-AgentGate-V

Project-AgentGate-V is a standalone Windows inference benchmark built with C#, WPF, .NET 8, and ONNX Runtime. It profiles the local PC, runs the 19-class CNN, and writes timestamped HTML and JSON reports under `benchmark_reports/` beside the application.

## Requirements and build

- Windows 10 or 11 (x64 by default; ARM64 publish is also available)
- .NET 8 SDK and NuGet access on the build machine
- No Python or separate runtime installation is needed on a PC receiving the published folder

From `vibe-coded-app`, run:

```powershell
./build.ps1
```

Or, from `D:\final-yr-project`, run `./vibe-coded-app/build.ps1`.

The self-contained, non-trimmed single-file publish goes to `dist/Project-AgentGate-V/win-x64/`. The ONNX model is embedded as an assembly resource and bundled inside `Project-AgentGate-V.exe`; it is not copied beside the executable. The app does not bundle or preselect a dataset. Choose your test dataset folder when the app is running. Use `-RuntimeIdentifier win-arm64` for Windows ARM64.

## Model and dataset

The app checks the PC's hardware profile at startup. It shows a GPU target only when Windows reports at least one graphics adapter; that WMI inventory is a hardware-presence check, while DirectML provider initialization is validated when the GPU benchmark is actually started. The app loads its embedded `fpga_net.onnx` resource into memory when **Run benchmark** is clicked. The published executable does not read models from `artifacts/`. ONNX Runtime expects a float NCHW grayscale input shaped `[1, 1, 28, 28]` and 19 output scores in the same ordinal order as the dataset class folders below. The trained checkpoint is maintained at `../model_training/artifacts/fpga_net_fp32.pt`; the development-only exporter writes the ONNX file to `src/ProjectAgentGateV/Assets/fpga_net.onnx` before it is embedded.

Choose an extracted test dataset folder from the **Target Dataset** panel by clicking anywhere in the drop zone to open File Explorer or by dragging a folder onto it. Do not choose individual images, an archive, or a class subfolder. The dataset root must directly contain all 19 class folders, and each class folder needs at least one supported image. The validator counts classes and supported images before enabling Run. Subfolders inside class folders are allowed.

```text
dataset/
  (/  )/  +/  -/  0/  1/  ...  9/
  =/  X/  forward_slash/  times/  y/
```

Supported extensions are `.png`, `.jpg`, `.jpeg`, `.bmp`, `.gif`, `.tif`, and `.tiff`. For example, if the dataset is `D:\Downloads\test_dataset`, select `test_dataset` itself.

Images are flattened onto white, resized to 28×28 with high-quality bicubic interpolation, converted to grayscale, normalized to `[0,1]`, and inverted when mean intensity is below `0.5`.

## Compute devices and telemetry

The CPU option is selected by default and uses ONNX Runtime's native CPU execution provider (AVX2 where available). The optional GPU path uses ONNX Runtime DirectML on adapter index 0; CUDA and vendor-specific runtime installs are not required. Select both CPU and GPU to run two sequential passes on the same data and get a comparison table in the app and report. On multi-GPU PCs, verify that DirectML adapter 0 is the intended adapter before interpreting the result. This DirectML run is a broad Windows baseline, not an optimized CUDA/TensorRT RTX baseline.

CPU use and app working-set memory are sampled every 100 ms. GPU 3D utilization is read from Windows GPU-engine performance data when the installed driver exposes it; otherwise the UI reports the metric as unavailable. The AND-gate mascot uses only the supplied transparent sprite sheet, with longer varied idle/work loops and a brief report-ready sequence. Animation stays enabled during timed inference and the report records that state.

The live GOPS figure is an estimate based on 233,303,552 operations per image for the CNN, counting each multiply-accumulate as two operations. This estimates model math rate, not measured hardware instructions.

## Measurements and reports

The large live graph plots sampled per-image frame time and shows p50, p95, p99, and worst-frame latency. `Stopwatch` intervals around the model call include output materialization and argmax; separate frame timing includes image decoding/preprocessing plus inference. Dataset enumeration, model load, warmup, UI updates and report writes are excluded from model-call timing. Throughput is images divided by summed inference-call time; batch size is one.

Each completed run writes matching timestamped files:

```text
benchmark_reports/benchmark_yyyyMMdd_HHmmss_fff.html
benchmark_reports/benchmark_yyyyMMdd_HHmmss_fff.json
```

Reports include overall metrics, per-class accuracy, hardware profile, selected-device comparison, and animation state.

## Project structure

```text
Project-AgentGate-V.sln
src/ProjectAgentGateV/
  App.xaml                    Light theme and Octicons vector geometry
  MainWindow.xaml             Profile, dataset-selection, and benchmark pages
  Controls/                   Country flags, pixel-art mascot, and latency chart
  Assets/                     Embedded model, mascot sheet and app icon
  Models/                     Hardware, dataset, profile and benchmark types
  Services/                   Hardware/live telemetry, preprocessing, ONNX inference and reports
  Views/                      Styled notices
build.ps1                     Self-contained Windows publish
tools/GenerateAppIcon.ps1     Rebuild the Windows app icon
tools/GenerateGateSprites.py  Rebuild the original 32×32 mascot sheet
tools/ExportModelOnnx.py      Export the model checkpoint to ONNX
```
