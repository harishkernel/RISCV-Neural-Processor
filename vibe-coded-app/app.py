"""Project-AgentGate-V desktop inference benchmark."""
from __future__ import annotations

import sys
from pathlib import Path

from PySide6.QtWidgets import QApplication

from agentgate.ui import MainWindow


def app_root() -> Path:
    if getattr(sys, "frozen", False):
        return Path(sys.executable).resolve().parent
    return Path(__file__).resolve().parent


def main() -> int:
    app = QApplication(sys.argv)
    app.setApplicationName("Project-AgentGate-V")
    app.setOrganizationName("AgentGate")
    window = MainWindow(app_root())
    window.show()
    return app.exec()


if __name__ == "__main__":
    raise SystemExit(main())
