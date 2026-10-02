"""Patch same-shape PyTorch weights into the existing exported ONNX graph.

This avoids re-exporting an unchanged architecture and needs no `onnx` package.
The output is validated by ONNX Runtime against the PyTorch model before it is
accepted. This is a development utility, not part of the Windows app runtime.
"""

from __future__ import annotations

import argparse
from pathlib import Path

import numpy as np
import onnxruntime as ort
import torch

from RetrainBalancedModel import FpgaNet


ROOT = Path(__file__).resolve().parents[1]
ONNX_INITIALIZER_TO_WEIGHT = {
    **{f"conv{i}.weight": f"conv{i}.weight" for i in range(1, 7)},
    "onnx::MatMul_30": "fc1.weight.T",
    "onnx::MatMul_31": "fc2.weight.T",
}


def read_varint(data: bytes | bytearray, offset: int) -> tuple[int, int]:
    value = shift = 0
    while True:
        byte = data[offset]
        offset += 1
        value |= (byte & 0x7F) << shift
        if byte < 0x80:
            return value, offset
        shift += 7
        if shift > 70:
            raise ValueError("Invalid protobuf varint.")


def protobuf_fields(data: bytes | bytearray):
    """Yield (field number, wire type, value, payload start, payload end)."""
    offset = 0
    while offset < len(data):
        key, offset = read_varint(data, offset)
        number, wire_type = key >> 3, key & 7
        if wire_type == 0:
            value, offset = read_varint(data, offset)
            yield number, wire_type, value, offset, offset
        elif wire_type == 1:
            start = offset
            offset += 8
            yield number, wire_type, data[start:offset], start, offset
        elif wire_type == 2:
            length, offset = read_varint(data, offset)
            start = offset
            offset += length
            if offset > len(data):
                raise ValueError("Truncated protobuf length-delimited field.")
            yield number, wire_type, data[start:offset], start, offset
        elif wire_type == 5:
            start = offset
            offset += 4
            yield number, wire_type, data[start:offset], start, offset
        else:
            raise ValueError(f"Unsupported protobuf wire type {wire_type}.")


def scalar(data: bytes | bytearray, number: int, default: int = 0) -> int:
    return next((value for field, wire, value, _, _ in protobuf_fields(data) if field == number and wire == 0), default)


def packed_ints(data: bytes | bytearray) -> list[int]:
    values, offset = [], 0
    while offset < len(data):
        value, offset = read_varint(data, offset)
        values.append(value)
    return values


def patch_graph(model_bytes: bytes, weights: dict[str, torch.Tensor]) -> tuple[bytes, set[str]]:
    model_graph = next(
        (start, end) for field, wire, _, start, end in protobuf_fields(model_bytes)
        if field == 7 and wire == 2
    )
    graph_start, graph_end = model_graph
    graph = bytearray(model_bytes[graph_start:graph_end])
    found: set[str] = set()

    for field, wire, tensor_proto, tensor_start, tensor_end in list(protobuf_fields(graph)):
        if field != 5 or wire != 2:
            continue
        tensor_fields = list(protobuf_fields(tensor_proto))
        name = next((value.decode("utf-8") for number, wt, value, _, _ in tensor_fields if number == 8 and wt == 2), None)
        if name not in ONNX_INITIALIZER_TO_WEIGHT:
            continue

        weight_name = ONNX_INITIALIZER_TO_WEIGHT[name]
        parameter_name, transpose_marker, _ = weight_name.partition(".T")
        tensor = weights[parameter_name].detach().cpu()
        if transpose_marker:
            tensor = tensor.t().contiguous()
        array = tensor.numpy().astype("<f4", copy=False)
        expected_shape: list[int] = []
        for number, wt, value, _, _ in tensor_fields:
            if number == 1 and wt == 0:
                expected_shape.append(value)
            elif number == 1 and wt == 2:
                expected_shape.extend(packed_ints(value))
        data_type = scalar(tensor_proto, 2)
        if data_type != 1:
            raise ValueError(f"Initializer '{name}' is not ONNX FLOAT tensor (data_type={data_type}).")
        if list(array.shape) != expected_shape:
            raise ValueError(f"Shape mismatch for '{name}': ONNX={expected_shape}, checkpoint={list(array.shape)}.")
        raw_field = next(((start, end) for number, wt, value, start, end in tensor_fields if number == 9 and wt == 2), None)
        if raw_field is None:
            raise ValueError(f"Initializer '{name}' has no raw_data field.")
        raw_start, raw_end = raw_field
        blob = array.tobytes(order="C")
        if len(blob) != raw_end - raw_start:
            raise ValueError(f"Byte length mismatch for '{name}': ONNX={raw_end - raw_start}, checkpoint={len(blob)}.")
        graph[tensor_start + raw_start:tensor_start + raw_end] = blob
        found.add(name)

    missing = set(ONNX_INITIALIZER_TO_WEIGHT) - found
    if missing:
        raise ValueError(f"ONNX model is missing expected initializers: {sorted(missing)}")
    patched = bytearray(model_bytes)
    patched[graph_start:graph_end] = graph
    return bytes(patched), found


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--model", type=Path, default=ROOT / "src" / "ProjectAgentGateV" / "Assets" / "fpga_net.onnx")
    parser.add_argument("--checkpoint", type=Path, default=ROOT / "artifacts" / "fpga_net_balanced_candidate.pt")
    parser.add_argument("--output", type=Path, default=ROOT / "artifacts" / "fpga_net_balanced_candidate.onnx")
    args = parser.parse_args()

    model = FpgaNet().cpu().eval()
    state = torch.load(args.checkpoint, map_location="cpu", weights_only=True)
    model.load_state_dict(state, strict=True)
    patched, initializers = patch_graph(args.model.read_bytes(), state)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(patched)

    session = ort.InferenceSession(str(args.output), providers=["CPUExecutionProvider"])
    input_meta = session.get_inputs()[0]
    sample = torch.zeros((1, 1, 28, 28), dtype=torch.float32)
    with torch.inference_mode():
        expected = model(sample).numpy()
    actual = session.run(None, {input_meta.name: sample.numpy()})[0]
    if actual.shape != (1, 19) or not np.allclose(actual, expected, rtol=1e-4, atol=1e-4):
        args.output.unlink(missing_ok=True)
        raise ValueError(f"ONNX/PyTorch verification failed (shape={actual.shape}, max abs diff={np.max(np.abs(actual - expected))}).")
    print(f"Patched {len(initializers)} weight tensors: {', '.join(sorted(initializers))}")
    print(f"Verified ONNX Runtime parity; wrote {args.output} ({args.output.stat().st_size:,} bytes).")


if __name__ == "__main__":
    main()
