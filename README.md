# MASTER_PROJECT_CONTEXT.md — AgentGate-V

> **Document Type:** Immutable project identity & engineering philosophy.  
> **Last Updated:** 2026-07-23  
> **Update Policy:** Rarely changes. Only updated when a fundamental design axiom is revised (with logged reasoning).

---

## 1. Project Identity

| Field | Value |
|-------|-------|
| **Official Title** | Secure Agentic Orchestration using Custom RISC-V Hardware Acceleration |
| **Internal Code Name** | AgentGate-V |
| **Name Etymology** | **Agent** = AI agent orchestrator; **V** = RISC-**V** architecture + hardware **V**ault + **V**erilog design |
| **Team** | Harish M (310623105016), Sathya Narayanan R, Pradeep R — Batch 2, Dept. of EEE |
| **Faculty Guide** | Mrs. D. Chandrakala |
| **Base Paper** | *"EPIC: A Sub-6mW In-Memory Computing-based RISC-V Microcontroller Unit with On-Chip Training Support for TinyML"* (IEEE ESSERC 2025) |
| **Academic Year** | 2026 Final Year Project |

---

## 2. One-Sentence Summary

A custom RISC-V soft-core on an FPGA acts as an air-gapped, hardware-rooted "Brain" that receives remote Telegram commands, classifies intents using a hardware-accelerated TinyML classifier, and securely executes automations on a PC by acting as a physical USB HID Keyboard/Mouse — ensuring zero vulnerable custom software is required on the PC.

---

## 3. Engineering Philosophy

### 3.1 Hardware-First — With Honesty

The project's core identity is **custom digital hardware design**. Every feature should first be evaluated as a hardware opportunity (custom RTL, DSP blocks, BRAM, custom ISA). **However:** a feature only belongs in hardware if it's genuinely buildable by this team in this timeline. Software is the correct choice whenever hardware would be simulated, faked, or unverifiable. Claiming hardware novelty for something not actually built in hardware is worse than not having the feature — it collapses under panel questioning.

### 3.2 Brain vs. Dumb Body Paradigm (The AI Rubber Ducky Pivot)

This is the project's core architectural invariant:

| Entity | Role | Trust Level |
|--------|------|-------------|
| **FPGA (Brain)** | Intent classification, API key storage (Telegram token), orchestration state, security enforcement, USB HID generation | **Fully Trusted** — air-gapped from PC OS, deterministic, tamper-resistant |
| **PC (Dumb Body)** | Executes nothing but standard OS features driven by physical keyboard/mouse input | **Untrusted** — runs NO custom software or listeners |
| **Phone (Remote)** | Natural language input via Telegram Bot | **Authenticated** — user's input device |

The PC never sees API keys. The PC runs no Python listener scripts. The FPGA physically drives the PC OS.

### 3.3 Not a Chatbot / Not an LLM Wrapper (The Strict Boundary)

The TinyML component is a **fixed-vocabulary intent classifier** — it maps tokenized input to one of N predefined C-macros. It does not understand novel requests, does not perform reasoning, and does not generate text. This distinction is non-negotiable and must survive panel questioning.

**The "Secure Reject" Fallback:** If a task requires genuine natural language understanding (e.g. "What is quantum physics?"), the MAC array's confidence scores will all be near 0%. The firmware instantly maps this to `UNKNOWN_INTENT` and triggers the Secure Reject Macro. The FPGA routes a strict error message ("Error: I am a secure hardware actuator...") back to the ESP32 (UART TX), which sends it to Telegram. We actively avoid acting as a Cloud LLM proxy to maximize our hardware edge-AI novelty.

---

## 4. Immutable Design Decisions

These decisions are **locked** unless explicitly revised with logged reasoning.

| # | Decision | Rationale | Locked Date |
|---|----------|-----------|-------------|
| D1 | **FPGA Board: Sipeed Tang Primer 20K** (Gowin GW2A-LV18PG256C8) | 20,736 LUTs, 48 DSP slices (18×18), 828 Kbit BRAM, 128MB DDR3, USB-C, affordable, available | 2026-07-21 |
| D2 | **RISC-V Core: PicoRV32 or VexRiscv** | Mature, well-documented, synthesizable on Gowin FPGAs, MIT licensed | 2026-07-21 |
| D3 | **TinyML Quantization: INT8** | Fits in BRAM/DDR3, compatible with DSP slices (8-bit MAC), proven for edge classifiers | 2026-07-21 |
| D4 | **Model Size: 100k–200k parameters** | Small enough for edge, large enough for fixed-vocabulary intent classification | 2026-07-21 |
| D5 | **Remote Input: Telegram Bot over WiFi** | Phone → Telegram → ESP32 WiFi → FPGA. Allows remote commanding from anywhere (e.g., college to home) without exposing the PC to the internet. | 2026-07-23 (Pivot) |
| D6 | **PC Communication: Pure USB HID** | The FPGA acts as a physical USB Keyboard/Mouse. Removes the need for vulnerable PC-side software. | 2026-07-23 (Pivot) |
| D7 | **Sub-Agents: RISC-V Firmware Macros** | The sub-agents are C-code routines generating keystrokes, completely contained in hardware. | 2026-07-23 (Pivot) |
| D8 | **Project is NOT an AI/ML project** | AI is a supporting subsystem. The project is a custom hardware platform. The MAC array and RISC-V ISA are the novelty, not the model. | 2026-07-21 |

---

## 5. Tech Stack

### Hardware
- **FPGA:** Sipeed Tang Primer 20K (Gowin GW2A-LV18PG256C8)
- **EDA Toolchain:** Gowin IDE / Gowin EDA (synthesis, place-and-route, bitstream)
- **HDL:** Verilog / SystemVerilog
- **RISC-V Core:** PicoRV32 or VexRiscv (soft-core, open source)
- **Custom Instructions:** R-type custom opcode for MAC array trigger
- **MAC Array:** 4–8 parallel 8-bit MAC units utilizing 48 built-in DSP slices
- **Memory:** BRAM (828 Kbit) for activation buffers; DDR3 (128MB) for model weight streaming
- **Display:** I2C OLED (SSD1306 or similar) for status/metrics
- **C2 Module:** ESP32 (WiFi) bridged via UART to FPGA for Telegram Bot polling

### Software
- **TinyML Training:** Python (TensorFlow Lite Micro / custom quantization pipeline)
- **Weight Conversion:** Python script to export INT8 weights → binary blobs for FPGA memory
- **Sub-Agents:** C-code macros compiled into the RISC-V firmware (no PC software required)

### Communication Protocols
- **Phone → ESP32:** Telegram Bot API (HTTPS over WiFi)
- **ESP32 → FPGA:** UART
- **FPGA → PC:** USB HID (Keyboard/Mouse)
- **FPGA → OLED:** I2C

---

## 6. Constraints

| Constraint | Impact |
|-----------|--------|
| **3-week timeline** (Jul 23 → ~Aug 12) | Limits scope to Core features only. No luxury for exploration. |
| **3-member EEE team** | Limited parallelism. One person on RTL, one on firmware/TinyML, one on PC/software is the max split. |
| **Student-level Verilog experience** | Custom RTL must stay within achievable complexity. No multi-stage pipelines or complex FSMs unless team demonstrates capability. |
| **Single FPGA board** | No redundancy. Bricking the board = project stop. Use simulation heavily before synthesis. |
| **No custom silicon** | All "custom hardware" = FPGA logic. This is a strength (reconfigurable) but must be stated honestly — it's not ASIC fabrication. |

---

## 7. Security Guardrails (Non-Negotiable)

1. **Never store or transmit real user credentials** (passwords, login details) in any form.
2. **"Trust" features must use proper crypto** — challenge-response, key pairing, hardware hash verification. Never raw credential capture.
3. **API keys live on FPGA only** — The Telegram Bot Token must only be stored in hardware (or ESP32 flash).
4. **Any feature reintroducing a rejected security anti-pattern must be flagged**, even if relabeled.

---

## 8. Terminology Glossary

| Term | Definition |
|------|-----------|
| **AgentGate-V** | The project name. A hardware-rooted secure gateway for AI agent orchestration. |
| **Brain** | The FPGA — sole authority for intent classification, security, and orchestration state. |
| **Dumb Body** | The PC — an completely unmodified actuator that executes standard OS commands typed by the Brain. |
| **Master TinyML Classifier** | The local AI model on the FPGA that maps raw text to a specific HID sub-agent macro. |
| **MAC Array** | Custom parallel Multiply-Accumulate units in Verilog, triggered by a RISC-V custom instruction. |
| **API Vault** | FPGA-resident storage for API keys (e.g., Telegram Token) — physically air-gapped from the PC. |
| **HID Sub-Agent** | A C-code macro running in the RISC-V firmware that generates specific USB keystrokes/mouse movements. |
| **AI Rubber Ducky** | The conceptual architecture where the FPGA acts as a smart, AI-driven keystroke injection tool. |

---

## 9. Base Paper & Academic Justification

**Base Paper:** *"EPIC: A Sub-6mW In-Memory Computing-based RISC-V Microcontroller Unit with On-Chip Training Support for TinyML"* (IEEE ESSERC 2025).

**How we match:** EPIC pairs a RISC-V core with dedicated MAC hardware macros to accelerate TinyML inference. AgentGate-V directly adapts this architecture — RISC-V + custom MAC array for TinyML intent classification.

**Our Novelty:** EPIC uses custom-fabricated 28nm silicon. We adapt the MAC-acceleration concept for affordable, reconfigurable FPGA hardware using RISC-V custom instructions, applied to a novel use-case: Secure Agentic Orchestration via USB HID.

**Supporting Reference Papers (in `Base_papers/`):**
1. EPIC (primary base paper)
2. A Scalable Security Approach in IoT Networks — Hardware Accelerators
3. 16 nJ-Classification FPGA-Based Wired-Logic DNN Accelerator
4. Edge-Compatible Convolutional Autoencoder on FPGA for Anomaly Detection
5. HLS-Based FPGA for PCA-SVM Real-Time Processing
6. Low-Power Hyperspectral Anomaly Detector on FPGA
7. MAD-Flow: Anomaly Detection on FPGA-SoCs
8. TrustGuard: FPGA-Based Security Monitoring

---

*This document defines what AgentGate-V IS. For what's been done and what's next, see PROJECT_STATE.md. For every idea ever discussed, see IDEA_BANK.md.*
