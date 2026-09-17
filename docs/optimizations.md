# The Road to 217 MHz: Architectural Optimizations

This document chronicles every major architectural optimization, pipelining technique, and algorithmic design choice we implemented to take this accelerator from a failing, congested design up to a record-breaking **217.45 MHz**. 

You can copy-paste these directly into your final report's "Methodology" or "Implementation" chapters.

---

### 1. Radix-4 Booth Encoding (Multiplier Optimization)
**The Problem:** Standard Verilog `*` operators were generating massive, slow ripple-carry multiplier trees in the FPGA's soft logic when DSPs ran out.
**The Fix:** We implemented a custom logic-gate-level **Radix-4 Booth Multiplier**. By encoding the multiplier into Radix-4, we halved the number of partial products required, massively reducing the size of the adder tree and accelerating the compute speed.

### 2. 5-Stage Deep MAC Pipelining (Logic Depth Reduction)
**The Problem:** Even with Booth encoding, trying to multiply and accumulate in a single clock cycle resulted in >15 logic levels, restricting the clock to under 100 MHz.
**The Fix:** We hyper-pipelined the MAC unit into 5 distinct clock stages:
- Stage 1: Input Latching
- Stage 2: Partial Product Generation
- Stage 3: First Adder Tree
- Stage 4: Second Adder Tree
- Stage 5: Accumulation
This bounded the critical path to a maximum of 5 logic levels between registers.

### 3. True Systolic Daisy-Chain Output (Routing Decongestion)
**The Problem:** Initially, we tried to read the 32-bit accumulators out of all 64 PEs simultaneously using a gigantic 64-to-1 global multiplexer. This required routing 2,048 wires across the entire chip to a single point, causing fatal routing congestion.
**The Fix:** We deleted the global multiplexer and implemented a **True Systolic Daisy Chain**. The accumulators now act as a massive shift-register "bucket brigade." Each PE passes its result to its neighbor, pumping the data out to the edge of the array one cycle at a time. This completely localized the routing.

### 4. 100% DSP-Less Soft-Core Architecture (Physical Layout Optimization)
**The Problem:** The FPGA has 56 hard DSP slices. When we tried to use them, the FPGA was forced to stretch long 32-bit wires from our tightly packed LUT logic across the chip to wherever the DSPs were physically manufactured. This physical transit time killed our Fmax (dropping it to 144 MHz).
**The Fix:** We intentionally bypassed every single DSP slice. By forcing all 64 MACs into LUT logic, the synthesizer was able to pack the entire neural network accelerator into one tight, microscopic clump of silicon, drastically reducing wire delays and unlocking 217 MHz.

### 5. Power-of-Two (PoT) Shift-Add Requantization
**The Problem:** The Post-Processor required a large 32x16 multiplier to rescale the 32-bit accumulator back down to an 8-bit activation. This was the final bottleneck consuming a DSP slice.
**The Fix:** We replaced the heavy multiplier with a **PoT Shift-Add approximation algorithm** (e.g., `data * 1.25` became `data + (data >>> 2)`). This replaced expensive multiplication with a simple, zero-cost wire shift and an adder, completely eliminating the final DSP dependency.

### 6. Triangular Data Skewing (Fan-out Reduction)
**The Problem:** Feeding data to all PEs simultaneously causes "High Fan-Out" errors, where one register tries to drive 64 endpoints at once, causing massive capacitance and delay.
**The Fix:** We implemented `input_skew.v` and `weight_loader.v` to skew the data. Activations and weights are fed diagonally into the array, one row/column at a time, ensuring that no register ever drives more than one neighboring PE.

### 7. Ping-Pong BSRAM Buffering (Memory Latency Hiding)
**The Problem:** Waiting for the memory to load weights for the next layer would stall the systolic array, starving the compute units.
**The Fix:** We implemented a **Double-Buffering (Ping-Pong) architecture**. The array computes Layer N using SRAM Bank A, while simultaneously pre-fetching weights for Layer N+1 into SRAM Bank B. This completely hides the memory access latency.

### 8. Distributed FSM Control (Control Path Optimization)
**The Problem:** A single centralized state machine trying to control 64 PEs creates a massive control bottleneck.
**The Fix:** We separated the control logic into a highly pipelined `main_controller.v`. The FSM manages high-level states (`LOAD_WEIGHTS` -> `COMPUTE` -> `DRAIN`), while local counters manage the deep pipeline flushes (accounting for our 5-cycle MAC delay) without bottlenecking the data path.
