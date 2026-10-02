"""Development-only exporter for the app's bundled ONNX model.

Requires PyTorch plus the temporary `onnx` package used only at export time.
The WPF app itself has no Python runtime dependency.
"""

from pathlib import Path
import sys
import argparse

ROOT = Path(__file__).resolve().parents[1]

import onnx
import torch
from torch import nn


class FpgaNet(nn.Module):
    def __init__(self) -> None:
        super().__init__()
        self.conv1 = nn.Conv2d(1, 64, 3, 1, 1, bias=False)
        self.relu1 = nn.ReLU()
        self.pool1 = nn.MaxPool2d(2, 2)
        self.conv2 = nn.Conv2d(64, 128, 3, 1, 1, bias=False)
        self.relu2 = nn.ReLU()
        self.conv3 = nn.Conv2d(128, 128, 3, 1, 1, bias=False)
        self.relu3 = nn.ReLU()
        self.pool2 = nn.MaxPool2d(2, 2)
        self.conv4 = nn.Conv2d(128, 256, 3, 1, 1, bias=False)
        self.relu4 = nn.ReLU()
        self.conv5 = nn.Conv2d(256, 256, 3, 1, 1, bias=False)
        self.relu5 = nn.ReLU()
        self.conv6 = nn.Conv2d(256, 256, 3, 1, 1, bias=False)
        self.relu6 = nn.ReLU()
        self.pool3 = nn.MaxPool2d(2, 2)
        self.fc1 = nn.Linear(256 * 3 * 3, 256, bias=False)
        self.relu7 = nn.ReLU()
        self.fc2 = nn.Linear(256, 19, bias=False)

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        x = self.pool1(self.relu1(self.conv1(x)))
        x = self.relu2(self.conv2(x))
        x = self.pool2(self.relu3(self.conv3(x)))
        x = self.relu4(self.conv4(x))
        x = self.relu5(self.conv5(x))
        x = self.pool3(self.relu6(self.conv6(x)))
        x = torch.flatten(x, 1)
        x = self.relu7(self.fc1(x))
        return self.fc2(x)


def main() -> None:
    parser = argparse.ArgumentParser(description="Export a trained Project-AgentGate-V checkpoint to ONNX.")
    parser.add_argument(
        "--checkpoint",
        type=Path,
        default=ROOT.parent / "model_training" / "artifacts" / "fpga_net_fp32.pt",
        help="Path to the trained PyTorch state dict.",
    )
    parser.add_argument(
        "--output",
        type=Path,
        default=ROOT / "src" / "ProjectAgentGateV" / "Assets" / "fpga_net.onnx",
        help="Destination ONNX file.",
    )
    args = parser.parse_args()
    checkpoint = args.checkpoint.resolve()
    destination = args.output.resolve()
    if not checkpoint.is_file():
        raise FileNotFoundError(f"Trained checkpoint not found: {checkpoint}")
    destination.parent.mkdir(parents=True, exist_ok=True)

    model = FpgaNet().cpu().eval()
    weights = torch.load(checkpoint, map_location="cpu", weights_only=True)
    model.load_state_dict(weights, strict=True)
    sample = torch.zeros((1, 1, 28, 28), dtype=torch.float32)
    torch.onnx.export(
        model,
        sample,
        destination,
        input_names=["input"],
        output_names=["logits"],
        opset_version=17,
        do_constant_folding=True,
        dynamo=False,
    )
    onnx.checker.check_model(str(destination))
    graph = onnx.load(str(destination))
    output_dimensions = [d.dim_value for d in graph.graph.output[0].type.tensor_type.shape.dim]
    if output_dimensions != [1, 19]:
        raise ValueError(f"Unexpected model output shape: {output_dimensions}")
    print(f"Exported {destination} ({destination.stat().st_size:,} bytes), output [1, 19]")


if __name__ == "__main__":
    main()
