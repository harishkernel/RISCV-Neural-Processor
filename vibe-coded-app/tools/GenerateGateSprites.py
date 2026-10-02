from pathlib import Path

from PIL import Image, ImageDraw


ROOT = Path(__file__).resolve().parents[1]
ASSET_DIR = ROOT / "src" / "ProjectAgentGateV" / "Assets"
FRAME = 32
POSES = [
    {"shift": 0, "hop": 0, "eyes": "open", "step": 0, "mouth": "smile", "action": "idle"},
    {"shift": 0, "hop": 0, "eyes": "blink", "step": 0, "mouth": "smile", "action": "idle"},
    {"shift": 0, "hop": 0, "eyes": "look", "step": 0, "mouth": "smile", "action": "idle"},
    {"shift": 0, "hop": -1, "eyes": "wide", "step": 0, "mouth": "open", "action": "wave", "wave": 0},
    {"shift": 0, "hop": 0, "eyes": "open", "step": 0, "mouth": "smile", "action": "wave", "wave": 2},
    {"shift": 0, "hop": 0, "eyes": "open", "step": 1, "mouth": "smile", "action": "idle"},
    {"shift": 0, "hop": 0, "eyes": "blink", "step": 0, "mouth": "smile", "action": "idle"},
    {"shift": 0, "hop": -1, "eyes": "open", "step": 0, "mouth": "smile", "action": "walk"},
    {"shift": 0, "hop": 0, "eyes": "look", "step": 1, "mouth": "smile", "action": "walk"},
    {"shift": 0, "hop": 0, "eyes": "look", "step": 0, "mouth": "smile", "action": "chip", "chip": 0},
    {"shift": 0, "hop": -1, "eyes": "wide", "step": 0, "mouth": "open", "action": "chip", "chip": 1},
    {"shift": 0, "hop": -2, "eyes": "wide", "step": 1, "mouth": "open", "action": "cheer"},
]

INK = (48, 51, 48, 255)
BODY = (238, 234, 222, 255)
SHADE = (201, 197, 181, 255)
ACCENT = (177, 190, 151, 255)
WHITE = (255, 255, 250, 255)


def make_frame(pose: dict[str, int | str]) -> Image.Image:
    image = Image.new("RGBA", (FRAME, FRAME), (0, 0, 0, 0))
    draw = ImageDraw.Draw(image)
    shift = int(pose["shift"])
    hop = int(pose["hop"])
    step = int(pose["step"])
    left, top = 7 + shift, 4 + hop

    # Input leads and output lead create the recognizable AND-gate silhouette.
    for y in (11 + hop, 20 + hop):
        draw.rectangle((0, y, left + 1, y + 1), fill=INK)
        draw.rectangle((1, y, left, y), fill=ACCENT)
    draw.rectangle((25 + shift, 15 + hop, 31, 17 + hop), fill=INK)
    draw.rectangle((26 + shift, 16 + hop, 30, 16 + hop), fill=ACCENT)

    # Little feet stay inside the 32 px cell and alternate during a walk.
    foot_y = 28 + hop
    draw.rectangle((10 + shift, foot_y, 14 + shift, min(31, foot_y + (1 if step == 0 else 2))), fill=INK)
    draw.rectangle((11 + shift, foot_y, 13 + shift, min(30, foot_y + (1 if step == 0 else 2))), fill=SHADE)
    other_y = foot_y if step == 0 else max(27, foot_y - 1)
    draw.rectangle((20 + shift, other_y, 24 + shift, min(31, other_y + (2 if step == 0 else 1))), fill=INK)
    draw.rectangle((21 + shift, other_y, 23 + shift, min(30, other_y + (2 if step == 0 else 1))), fill=SHADE)

    body = [
        (left, top), (left + 8, top), (left + 12, top + 1), (left + 15, top + 3),
        (left + 17, top + 6), (left + 18, top + 10), (left + 18, top + 14),
        (left + 17, top + 18), (left + 15, top + 21), (left + 12, top + 23),
        (left + 8, top + 24), (left, top + 24),
    ]
    draw.polygon(body, fill=BODY, outline=INK)
    draw.line((left + 2, top + 2, left + 8, top + 2), fill=ACCENT, width=1)
    draw.line((left + 1, top + 5, left + 1, top + 21), fill=SHADE, width=1)

    action = str(pose.get("action", "idle"))
    if action in ("wave", "cheer"):
        hand_y = top + 2 + int(pose.get("wave", 0))
        draw.line((left + 14, top + 10, left + 18, hand_y + 2), fill=INK, width=2)
        draw.rectangle((left + 18, hand_y, left + 20, hand_y + 2), fill=INK)
        draw.point((left + 19, hand_y), fill=ACCENT)
        if action == "cheer":
            draw.point((left + 22, top - 1), fill=ACCENT)
            draw.point((left + 25, top + 2), fill=SHADE)
    elif action == "chip":
        chip_x, chip_y = 26, 21 + hop
        draw.line((left + 14, top + 16, chip_x, chip_y + 1), fill=INK, width=2)
        draw.rectangle((chip_x, chip_y, min(FRAME - 1, chip_x + 4), min(FRAME - 1, chip_y + 4)), fill=INK)
        draw.rectangle((chip_x + 1, chip_y + 1, chip_x + 3, chip_y + 3), fill=ACCENT)
        draw.point((chip_x + 2, chip_y + 2), fill=WHITE)
        for pin in (chip_x + 1, chip_x + 3):
            draw.point((pin, chip_y - 1), fill=INK)
            draw.point((pin, min(FRAME - 1, chip_y + 5)), fill=INK)

    eye_y = top + 11
    eyes = str(pose["eyes"])
    if eyes == "blink":
        draw.line((left + 5, eye_y + 1, left + 7, eye_y + 1), fill=INK, width=1)
        draw.line((left + 12, eye_y + 1, left + 14, eye_y + 1), fill=INK, width=1)
    else:
        offset = 1 if eyes == "look" else 0
        draw.rectangle((left + 5 + offset, eye_y, left + 6 + offset, eye_y + 3), fill=INK)
        draw.rectangle((left + 12 + offset, eye_y, left + 13 + offset, eye_y + 3), fill=INK)
        draw.point((left + 5 + offset, eye_y), fill=WHITE)
        draw.point((left + 12 + offset, eye_y), fill=WHITE)

    if pose["mouth"] == "open":
        draw.rectangle((left + 9, top + 17, left + 10, top + 19), fill=INK)
        draw.point((left + 9, top + 17), fill=ACCENT)
    else:
        draw.point((left + 9, top + 18), fill=INK)
        draw.point((left + 10, top + 19), fill=INK)
    return image


sheet = Image.new("RGBA", (FRAME * len(POSES), FRAME), (0, 0, 0, 0))
for index, pose in enumerate(POSES):
    sheet.alpha_composite(make_frame(pose), (index * FRAME, 0))

ASSET_DIR.mkdir(parents=True, exist_ok=True)
sheet.save(ASSET_DIR / "and-gate-spritesheet.png", optimize=True)
