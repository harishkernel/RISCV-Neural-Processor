using Microsoft.ML.OnnxRuntime;
using Microsoft.ML.OnnxRuntime.Tensors;
using ProjectAgentGateV.Models;
using System.Diagnostics;
using System.IO;

namespace ProjectAgentGateV.Services;

public sealed class OnnxBenchmarkService : IDisposable
{
    private const int WarmupCalls = 10;
    private readonly InferenceSession _session;
    private readonly string _inputName;
    private readonly BenchmarkDevice _device;

    public OnnxBenchmarkService(byte[] modelBytes, BenchmarkDevice device)
    {
        ArgumentNullException.ThrowIfNull(modelBytes);
        if (modelBytes.Length == 0) throw new InvalidDataException("The embedded ONNX model is empty.");
        _device = device;
        using var sessionOptions = new SessionOptions();
        if (device == BenchmarkDevice.DirectMlGpu)
        {
            sessionOptions.ExecutionMode = ExecutionMode.ORT_SEQUENTIAL;
            sessionOptions.EnableMemoryPattern = false;
            sessionOptions.AppendExecutionProvider_DML(0);
        }
        _session = new InferenceSession(modelBytes, sessionOptions);
        var input = _session.InputMetadata.FirstOrDefault();
        if (string.IsNullOrWhiteSpace(input.Key))
        {
            _session.Dispose();
            throw new InvalidDataException("The ONNX model does not expose an input tensor.");
        }
        _inputName = input.Key;
        var shape = input.Value.Dimensions;
        if (shape.Length != 4 || (shape[0] > 0 && shape[0] != 1) || (shape[1] > 0 && shape[1] != 1)
            || (shape[2] > 0 && shape[2] != 28) || (shape[3] > 0 && shape[3] != 28))
        {
            _session.Dispose();
            throw new InvalidDataException($"Expected a float NCHW grayscale input shaped [1, 1, 28, 28]. Model input '{_inputName}' is [{string.Join(", ", shape)}].");
        }
        if (input.Value.ElementType != typeof(float))
        {
            _session.Dispose();
            throw new InvalidDataException($"Expected a float model input; '{_inputName}' is {input.Value.ElementType.Name}.");
        }
    }

    public BenchmarkResult Run(
        string datasetRoot,
        UserProfile user,
        HardwareSnapshot hardware,
        IProgress<BenchmarkProgress>? progress,
        CancellationToken cancellationToken)
    {
        var images = DatasetService.Enumerate(datasetRoot, cancellationToken);
        int[] classCounts = new int[DatasetService.ClassNames.Length];
        int[] classCorrect = new int[DatasetService.ClassNames.Length];

        // Prime the session, provider, graph kernels, and allocations before collecting
        // per-frame samples. These calls are excluded from all reported timings.
        float[] firstPixels = DatasetService.Preprocess(images[0].FullPath);
        for (int warmup = 0; warmup < WarmupCalls; warmup++)
        {
            cancellationToken.ThrowIfCancellationRequested();
            _ = Predict(firstPixels);
        }
        var benchmarkStartedAt = DateTimeOffset.UtcNow;

        double inferenceSeconds = 0;
        double endToEndSeconds = 0;
        var modelCallLatencies = new List<double>(images.Count);
        var frameLatencies = new List<double>(images.Count);
        int correct = 0;
        var reportStride = Math.Max(1, images.Count / 100);
        for (var index = 0; index < images.Count; index++)
        {
            cancellationToken.ThrowIfCancellationRequested();
            var sample = images[index];
            var frameTimer = Stopwatch.StartNew();
            var pixels = DatasetService.Preprocess(sample.FullPath);
            var tensor = new DenseTensor<float>(pixels, new[] { 1, 1, 28, 28 });
            var input = NamedOnnxValue.CreateFromTensor(_inputName, tensor);

            // Batch size stays at one. The runtime-call sample includes Run, output
            // materialization, ArgMax, and disposal to observe provider synchronization.
            var callTimer = Stopwatch.StartNew();
            int predicted;
            using (var outputs = _session.Run(new[] { input }))
            {
                var output = outputs.FirstOrDefault()?.AsTensor<float>()
                    ?? throw new InvalidDataException("The ONNX model returned no float output tensor.");
                predicted = ArgMax(output);
            }
            callTimer.Stop();
            inferenceSeconds += callTimer.Elapsed.TotalSeconds;
            modelCallLatencies.Add(callTimer.Elapsed.TotalMilliseconds);
            if ((uint)predicted >= DatasetService.ClassNames.Length)
                throw new InvalidDataException($"The ONNX model returned class index {predicted}; expected 0–{DatasetService.ClassNames.Length - 1}.");

            frameTimer.Stop();
            endToEndSeconds += frameTimer.Elapsed.TotalSeconds;
            frameLatencies.Add(frameTimer.Elapsed.TotalMilliseconds);
            classCounts[sample.ExpectedClassIndex]++;
            if (predicted == sample.ExpectedClassIndex)
            {
                correct++;
                classCorrect[predicted]++;
            }
            if ((index + 1) % reportStride == 0 || index == images.Count - 1)
                progress?.Report(new BenchmarkProgress(
                    index + 1,
                    images.Count,
                    DatasetService.ClassNames[sample.ExpectedClassIndex],
                    inferenceSeconds,
                    callTimer.Elapsed.TotalMilliseconds,
                    frameTimer.Elapsed.TotalMilliseconds));
        }

        var modelCallSamples = modelCallLatencies.ToArray();
        var frameSamples = frameLatencies.ToArray();

        return new BenchmarkResult
        {
            StartedAtUtc = benchmarkStartedAt.ToString("O"),
            TotalImages = images.Count,
            CorrectImages = correct,
            InferenceDurationSeconds = inferenceSeconds,
            ThroughputFps = inferenceSeconds <= 0 ? 0 : images.Count / inferenceSeconds,
            EndToEndDurationSeconds = endToEndSeconds,
            EndToEndThroughputFps = endToEndSeconds <= 0 ? 0 : images.Count / endToEndSeconds,
            AverageModelCallLatencyMilliseconds = modelCallSamples.Length == 0 ? 0 : modelCallSamples.Average(),
            ModelCallLatency = LatencyStatistics.From(modelCallSamples),
            FrameLatency = LatencyStatistics.From(frameSamples),
            WarmupCalls = WarmupCalls,
            ModelCallLatencySamplesMilliseconds = modelCallSamples,
            FrameLatencySamplesMilliseconds = frameSamples,
            BatchSize = 1,
            DatasetDirectory = Path.GetFullPath(datasetRoot),
            ModelFile = EmbeddedOnnxModel.ReportDescription,
            PrimaryDevice = _device == BenchmarkDevice.Cpu ? "CPU · ONNX Runtime" : "GPU · DirectML",
            User = user,
            Hardware = hardware,
            PerClassAccuracy = DatasetService.ClassNames.Select((label, i) => new ClassAccuracy(label, classCounts[i], classCorrect[i])).ToArray()
        };
    }

    private int Predict(float[] pixels)
    {
        var tensor = new DenseTensor<float>(pixels, new[] { 1, 1, 28, 28 });
        var input = NamedOnnxValue.CreateFromTensor(_inputName, tensor);
        using var outputs = _session.Run(new[] { input });
        var output = outputs.FirstOrDefault()?.AsTensor<float>()
            ?? throw new InvalidDataException("The ONNX model returned no float output tensor.");
        return ArgMax(output);
    }

    private static int ArgMax(Tensor<float> output)
    {
        int bestIndex = -1;
        float bestValue = float.NegativeInfinity;
        int index = 0;
        foreach (float value in output)
        {
            if (value > bestValue) { bestValue = value; bestIndex = index; }
            index++;
        }
        if (index != DatasetService.ClassNames.Length)
            throw new InvalidDataException($"The ONNX model returned {index} scores; expected exactly {DatasetService.ClassNames.Length} class scores.");
        return bestIndex;
    }

    public void Dispose() => _session.Dispose();
}
