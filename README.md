# AgentGate-V MAC Engine (AGVME)
**A High-Speed Native DSP Neural Network TPU for Ultra-Low-Cost 55nm FPGAs**

![Fmax](https://img.shields.io/badge/Fmax-205.2%20MHz-success) ![DSP Usage](https://img.shields.io/badge/DSP%20Usage-66%25-blue) ![Logic Utilization](https://img.shields.io/badge/Logic-24%25-orange) ![Target](https://img.shields.io/badge/Board-Tang%20Primer%2020K-purple)

## Overview

![AgentGate-V Architecture](docs/block-diagram.png)

The AgentGate-V MAC Engine (AGVME) is a highly optimized, 8x8 INT8 Systolic Array TPU designed to solve the Performance vs. Cost dilemma of Edge AI. 

Implemented on an ultra-constrained **₹10,000 (budget friendly) Gowin GW2A-18 FPGA (Tang Primer 20K)**, this accelerator gives you access to **1GB of DDR3 RAM** for massive Neural Network model storage, while pushing the physical silicon to its theoretical limits. 

## The Architecture: The Native DSP Array
To balance hardware constraints on an older 55nm budget FPGA, this project employs extreme architectural planning and logic-gate-level optimizations:

* **The 5-Stage Native DSP Pipeline:** The critical path was entirely absorbed into the Gowin ALUMAC hard macros. By introducing specialized routing isolation registers, the multiplier and accumulator logic are perfectly mapped to physical silicon, bypassing slow FPGA LUT fabric to hit an unprecedented **205.196 MHz**.
* **100% DSP Mapping (66% Utilization):** The entire 8x8 systolic array (64 MACs) is mapped exclusively to the Tang Primer's physical DSP blocks (using 32 of the 48 available blocks). This drops standard logic utilization to a mere 24%, leaving massive room for softcore RISC-V orchestration.
* **Virtual Synthesis Wrapper:** To prove the architecture scales without violating physical I/O pin constraints (the GW2A-18 only has 191 pins), a 4-pin shift-register Virtual Wrapper was implemented to feed the massive 227-pin internal TPU bus.
* **Power-of-Two (PoT) Requantization:** The massive 32x16 hardware multiplier in the post-processor was destroyed and replaced with a zero-cost Shift-Add approximation network (e.g., data * 1.25 is computed as data + (data >>> 2)).
* **True Systolic Daisy-Chain Output:** A massive 64-to-1 global multiplexer was replaced with a sequential shift-register "bucket brigade," decongesting thousands of global routing wires.

## The Benchmark:
This project shatters standard Edge AI literature baselines on a ₹10,000 chip:

### Synthesis Results
![Synthesis Report Summary](docs/synthesis_resource_utilization.png)
![Fmax Timing Report](docs/synthesis_timing_report.png)

| Parameters | Standard Edge AI Baselines | **AGVME (This Project)** | Advantages |
| :--- | :--- | :--- | :--- |
| **Hardware Platform** | Xilinx Zynq / UltraScale+ | **Tang Primer 20K (GW2A-18)** | High-performance AI on ultra-budget 55nm silicon. |
| **Hardware Cost** | ₹130,000 - ₹1,000,000+ | **₹10,000** | **10x Cost Reduction** for deployment. |
| **External Memory** | Usually tightly bound | **1GB DDR3 On-Board** | Capable of storing massive CNN/LLM parameters. |
| **Clock Frequency (Fmax)**| 100 MHz - 150 MHz | **205.196 MHz** | Absolute maximum performance on 55nm LUTs. |
| **Logic Utilization** | 80%+ | **24% (4,950 LUTs)** | Extremely efficient routing and logic mapping. |

## Getting Started
1. Install [Gowin EDA](https://www.gowinsemi.com/en/support/download_eda/).
2. Open the project located at development/AgentGateV_MAC_Engine_Project/AGVME_Synthesis.gprj
3. Hit **Run Synthesis** to verify the 205 MHz Native DSP Fmax!

## Primary Base References
1. *Balancing Performance and Cost: FPGA-Based CNN Accelerators for Edge Computing* (The overarching motivation for cost-effective edge acceleration).
2. *Multiplication-Free Lookup-Based CNN Accelerator Using Residual Vector Quantization and Its FPGA Implementation* (The foundation for extreme optimization).