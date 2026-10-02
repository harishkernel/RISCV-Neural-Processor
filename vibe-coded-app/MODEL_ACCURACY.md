# Model accuracy diagnosis

## Root cause

The ONNX model and the WPF inference path agree; this is not an ONNX loading,
output-index, or image-polarity bug. The original benchmark report was 1,532 / 5,487
correct (27.92%). The model's training cache has a 170.8:1 largest-to-smallest
class ratio: `forward_slash` has 199 images, while `-` has 33,997. The notebook
trained with ordinary shuffled batches and cross-entropy, then reported accuracy
on a random split with the same class skew. That made its roughly 99% validation
score hide near-zero recall for slash and other shifted classes.

The selected dataset also has a large label-prior and style shift. `times` is
27.5% of the selected dataset but 1.4% of training; `forward_slash` is 9.7% versus
0.08%. In the supplied samples, `times` and uppercase `X` are both rendered as
nearly identical diagonal crosses. A single image does not consistently contain
enough visual information to distinguish those labels.

## Fix applied

`tools/RetrainBalancedModel.py` fine-tunes the existing checkpoint using equal
class sampling and mild geometric/stroke-width augmentation. Its gradients come
only from `model_training/dataset/dataset_cache.npz`; the selected benchmark folder
is only used for evaluation. `tools/PatchOnnxWeights.py` transfers the resulting
same-shape weights into the existing ONNX graph and checks ONNX Runtime output
against PyTorch. The application embeds that updated ONNX asset as before.

On the supplied dataset, the old report was 27.92%. The updated app's C# inference
path scored 1,783 / 5,487 (32.49%), a gain of 4.57 percentage points. Slash recall
rose from 0/532 to 120/532 (22.56%); parentheses also improved. The 10% stratified
holdout from the original training cache changed from 99.24% to 98.53% micro
accuracy and from 98.00% to 98.68% macro accuracy. This trades a small amount of
overall in-domain accuracy for better class balance and a real gain on the selected
dataset. `times` remains poorly separated from `X`; better labeled examples or a
clearer class definition are needed for that pair.

The supplied benchmark folder was used to compare/promote this candidate, so it
should be treated as validation data for future model changes, not as an untouched
final test set.

## Reproduce

Run from the `vibe-coded-app` directory:

```powershell
py tools\RetrainBalancedModel.py `
  --external-validation D:\Downloads\test_dataset `
  --output artifacts\fpga_net_balanced_candidate.pt
py tools\PatchOnnxWeights.py `
  --checkpoint artifacts\fpga_net_balanced_candidate.pt `
  --output artifacts\fpga_net_balanced_candidate.onnx
Copy-Item artifacts\fpga_net_balanced_candidate.onnx src\ProjectAgentGateV\Assets\fpga_net.onnx -Force
.\build.ps1
```

The `.pt` and candidate `.onnx` under `artifacts` are development outputs. The
published executable loads the model embedded in its assembly; it does not need
those files or a Python installation at runtime.
