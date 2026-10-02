"""Fine-tune the FPGA CNN with class-balanced sampling and mild image variation.

This is a development-time training utility. The published WPF application still
loads only its embedded ONNX model and has no Python runtime dependency.
"""

from __future__ import annotations

import argparse
from pathlib import Path

import numpy as np
import torch
from PIL import Image
from torch import nn
from torch.nn import functional as F
from torch.utils.data import DataLoader, TensorDataset


ROOT = Path(__file__).resolve().parents[1]
CLASSES = [
    "(", ")", "+", "-", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
    "=", "X", "forward_slash", "times", "y",
]
NUM_CLASSES = len(CLASSES)


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
        self.flatten = nn.Flatten()
        self.fc1 = nn.Linear(256 * 3 * 3, 256, bias=False)
        self.relu7 = nn.ReLU()
        self.fc2 = nn.Linear(256, NUM_CLASSES, bias=False)

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        x = self.pool1(self.relu1(self.conv1(x)))
        x = self.relu2(self.conv2(x))
        x = self.pool2(self.relu3(self.conv3(x)))
        x = self.relu4(self.conv4(x))
        x = self.relu5(self.conv5(x))
        x = self.pool3(self.relu6(self.conv6(x)))
        x = self.flatten(x)
        return self.fc2(self.relu7(self.fc1(x)))


def stratified_split(labels: np.ndarray, validation_fraction: float, seed: int):
    rng = np.random.default_rng(seed)
    train, validation = [], []
    for label in range(NUM_CLASSES):
        indices = np.flatnonzero(labels == label)
        rng.shuffle(indices)
        count = max(1, int(round(len(indices) * validation_fraction)))
        validation.extend(indices[:count].tolist())
        train.extend(indices[count:].tolist())
    rng.shuffle(train)
    rng.shuffle(validation)
    return np.asarray(train), np.asarray(validation)


def transform_batch(images: torch.Tensor, rng: torch.Generator) -> torch.Tensor:
    """Small translation/scale/rotation and occasional stroke-width jitter."""
    count = images.shape[0]
    device = images.device
    angle = (torch.rand(count, generator=rng) * 24.0 - 12.0) * (np.pi / 180.0)
    scale = torch.rand(count, generator=rng) * 0.30 + 0.85
    tx = torch.rand(count, generator=rng) * 0.24 - 0.12
    ty = torch.rand(count, generator=rng) * 0.24 - 0.12
    cosine, sine = torch.cos(angle) * scale, torch.sin(angle) * scale
    theta = torch.zeros((count, 2, 3), dtype=images.dtype)
    theta[:, 0, 0], theta[:, 0, 1], theta[:, 0, 2] = cosine, -sine, tx
    theta[:, 1, 0], theta[:, 1, 1], theta[:, 1, 2] = sine, cosine, ty
    theta = theta.to(device)
    grid = F.affine_grid(theta, images.shape, align_corners=False)
    varied = F.grid_sample(images, grid, mode="bilinear", padding_mode="border", align_corners=False)

    # Inputs are white (1) with dark strokes (0). Min/max pooling changes stroke
    # thickness by one pixel; only a small subset is altered each batch.
    choose = torch.rand(count, generator=rng).to(device)
    darken = choose < 0.10
    lighten = (choose >= 0.10) & (choose < 0.20)
    if darken.any():
        varied[darken] = 1.0 - F.max_pool2d(1.0 - varied[darken], 3, 1, 1)
    if lighten.any():
        varied[lighten] = F.max_pool2d(varied[lighten], 3, 1, 1)
    return varied.clamp_(0.0, 1.0)


@torch.inference_mode()
def evaluate(model: nn.Module, x: torch.Tensor, y: torch.Tensor, batch_size: int = 64):
    model.eval()
    class_total = np.zeros(NUM_CLASSES, dtype=np.int64)
    class_correct = np.zeros(NUM_CLASSES, dtype=np.int64)
    total, correct = 0, 0
    for start in range(0, len(y), batch_size):
        xb = x[start:start + batch_size]
        yb = y[start:start + batch_size]
        predictions = model(xb).argmax(1)
        total += len(yb)
        correct += int((predictions == yb).sum())
        for label in range(NUM_CLASSES):
            mask = yb == label
            class_total[label] += int(mask.sum())
            class_correct[label] += int(((predictions == yb) & mask).sum())
    per_class = np.divide(class_correct, class_total, out=np.zeros(NUM_CLASSES, dtype=float), where=class_total != 0)
    present = class_total > 0
    return correct / max(total, 1), float(per_class[present].mean()), per_class, class_total


def load_external(root: Path):
    xs, ys = [], []
    for label, name in enumerate(CLASSES):
        folder = root / name
        for path in folder.rglob("*"):
            if not path.is_file() or path.suffix.lower() not in {".png", ".jpg", ".jpeg", ".bmp", ".gif", ".tif", ".tiff"}:
                continue
            try:
                image = Image.open(path).convert("L").resize((28, 28), Image.Resampling.BICUBIC)
                pixels = np.asarray(image, dtype=np.float32) / 255.0
                if pixels.mean() < 0.5:
                    pixels = 1.0 - pixels
                xs.append(pixels)
                ys.append(label)
            except Exception as exc:
                print(f"Skipping unreadable image {path}: {exc}")
    if not xs:
        return None
    return torch.from_numpy(np.asarray(xs)[:, None]), torch.tensor(ys, dtype=torch.long)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--dataset", type=Path, default=ROOT.parent / "model_training" / "dataset" / "dataset_cache.npz")
    parser.add_argument("--checkpoint", type=Path, default=ROOT.parent / "model_training" / "artifacts" / "fpga_net_fp32.pt")
    parser.add_argument("--output", type=Path, default=ROOT / "artifacts" / "fpga_net_balanced_candidate.pt")
    parser.add_argument("--external-validation", type=Path, default=None)
    parser.add_argument("--epochs", type=int, default=3)
    parser.add_argument("--samples-per-class", type=int, default=600)
    parser.add_argument("--batch-size", type=int, default=64)
    parser.add_argument("--learning-rate", type=float, default=2e-5)
    args = parser.parse_args()

    torch.manual_seed(20261002)
    np.random.seed(20261002)
    torch.set_num_threads(min(4, torch.get_num_threads()))
    if not args.dataset.is_file() or not args.checkpoint.is_file():
        raise FileNotFoundError(f"Dataset or checkpoint missing: {args.dataset} | {args.checkpoint}")

    archive = np.load(args.dataset)
    raw_x = np.asarray(archive["x"], dtype=np.uint8).reshape(-1, 1, 28, 28)
    labels = np.asarray(archive["y"], dtype=np.int64)
    if len(raw_x) != len(labels) or labels.min() != 0 or labels.max() != NUM_CLASSES - 1:
        raise ValueError("Training cache must contain aligned x/y arrays with class IDs 0–18.")
    counts = np.bincount(labels, minlength=NUM_CLASSES)
    print("Training images per class:")
    for name, count in zip(CLASSES, counts):
        print(f"  {name:>14}: {count:>7,}")
    print(f"Class-count ratio (largest/smallest): {counts.max() / counts.min():.1f}x")

    train_indices, validation_indices = stratified_split(labels, 0.10, 20261002)
    images = torch.from_numpy(raw_x.astype(np.float32) / 255.0)
    targets = torch.from_numpy(labels.astype(np.int64))
    x_train, y_train = images[train_indices], targets[train_indices]
    x_val, y_val = images[validation_indices], targets[validation_indices]
    model = FpgaNet().cpu()
    model.load_state_dict(torch.load(args.checkpoint, map_location="cpu", weights_only=True), strict=True)
    before = evaluate(model, x_val, y_val)
    print(f"Held-out training validation before: micro={before[0] * 100:.2f}% macro={before[1] * 100:.2f}%")

    # Draw the same number of training examples per class each epoch. Sampling is
    # only from the training split; neither validation set contributes gradients.
    by_class = [np.flatnonzero(y_train.numpy() == i) for i in range(NUM_CLASSES)]
    optimizer = torch.optim.Adam(model.parameters(), lr=args.learning_rate)
    rng = torch.Generator().manual_seed(20261002)
    for epoch in range(1, args.epochs + 1):
        model.train()
        picked = np.concatenate([
            np.random.choice(indices, size=args.samples_per_class, replace=len(indices) < args.samples_per_class)
            for indices in by_class
        ])
        np.random.shuffle(picked)
        loader = DataLoader(TensorDataset(x_train[picked], y_train[picked]), batch_size=args.batch_size, shuffle=True)
        loss_sum, seen = 0.0, 0
        for xb, yb in loader:
            xb = transform_batch(xb, rng)
            optimizer.zero_grad(set_to_none=True)
            logits = model(xb)
            loss = F.cross_entropy(logits, yb)
            loss.backward()
            optimizer.step()
            loss_sum += float(loss.detach()) * len(yb)
            seen += len(yb)
        score = evaluate(model, x_val, y_val)
        print(f"Epoch {epoch}/{args.epochs}: balanced train loss={loss_sum / seen:.4f} | holdout micro={score[0] * 100:.2f}% macro={score[1] * 100:.2f}%")

    # Save a provisional checkpoint before the potentially lengthy external
    # evaluation so an interruption never discards the finished fine-tune.
    args.output.parent.mkdir(parents=True, exist_ok=True)
    torch.save(model.state_dict(), args.output)
    after = evaluate(model, x_val, y_val)
    external = (
        load_external(args.external_validation)
        if args.external_validation is not None and args.external_validation.is_dir()
        else None
    )
    external_score = None
    base_score = None
    if external:
        external_score = evaluate(model, *external, batch_size=args.batch_size)
        baseline = FpgaNet().cpu()
        baseline.load_state_dict(torch.load(args.checkpoint, map_location="cpu", weights_only=True), strict=True)
        base_score = evaluate(baseline, *external, batch_size=args.batch_size)
        print(f"External held-out baseline: micro={base_score[0] * 100:.2f}% macro={base_score[1] * 100:.2f}%")
        print(f"External held-out candidate: micro={external_score[0] * 100:.2f}% macro={external_score[1] * 100:.2f}%")
        for label, name in enumerate(CLASSES):
            print(f"  {name:>14}: {base_score[2][label] * 100:6.2f}% -> {external_score[2][label] * 100:6.2f}% ({external_score[3][label]:,} images)")

    # Accept a small micro-accuracy tradeoff only when class-balanced holdout
    # performance is retained and the separate, user-selected dataset improves.
    holdout_macro_ok = after[1] + 0.01 >= before[1]
    external_micro_improved = external_score is not None and base_score is not None and external_score[0] > base_score[0]
    if not holdout_macro_ok or (external_score is not None and not external_micro_improved):
        raise RuntimeError("Candidate failed the holdout/external acceptance criteria; it was not saved.")
    print(f"Saved candidate checkpoint: {args.output}")


if __name__ == "__main__":
    main()
