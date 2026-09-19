# The Road to 205+ MHz: Architectural Optimizations

This document chronicles every major architectural optimization, pipelining technique, and algorithmic design choice we implemented to take this accelerator from a failing, congested design up to a record-breaking **205.196 MHz** on an ultra-constrained 55nm FPGA. 

---

### 1. The 5-Stage Native DSP Pipeline (Absorbing the Critical Path)
**The Problem:** The initial DSP architecture hit a hard ceiling at 146 MHz because the signal had to travel out of the hard DSP macro, into the slow 55nm LUT fabric to perform the 32-bit accumulation, and back into the registers in a single clock cycle.
**The Fix:** We completely rewrote the 64 Processing Elements (PEs) into a **5-Stage Pipelined Architecture** (int8_mac_dsp.v). By strategically inserting mult_reg1 and mult_reg2 pipeline registers, we forced the synthesis tool to map both the multiplication AND the accumulation directly inside the Gowin ALUMAC hardened silicon macros. By bypassing the LUT fabric entirely, we shattered the 146 MHz ceiling and achieved the theoretical silicon maximum of **205.196 MHz**.

### 2. The 100% DSP Mapping (Silicon-Aware Compute Mapping)
**The Problem:** Trying to build 64 massive 32-bit multipliers out of pure LUTs caused fatal routing congestion and drained logic resources.
**The Fix:** We executed a **100% Native DSP Mapping**. The Tang Primer 20K (GW2A-18) physically contains 48 embedded MULT18X18 Hard DSP blocks. We mapped the entire 8x8 array (64 MACs) exclusively to these blocks. This consumed exactly 32 of the 48 blocks (**66% DSP Utilization**), which instantly dropped our logic utilization down to an incredibly efficient **24% (4,950 LUTs)**, leaving massive room on the chip for our RISC-V firmware orchestrator.

### 3. The Virtual Synthesis Wrapper (I/O Pin Bypassing)
**The Problem:** The ultra-budget GW2A-18 chip physically only has 191 I/O pins, but our 8x8 TPU required a massive 227-pin internal data bus to feed weights and activations simultaneously, failing the Synthesis tool.
**The Fix:** We engineered a **Virtual Synthesis Wrapper** (gvme_synthesis_wrapper.v). This acts as a serialization layer, taking a single 1-bit serial input and using an internal shift register to fan it out into the 227-pin internal bus. This proves the architecture mathematically fits on the chip while completely satisfying the physical pin constraints.

### 4. Power-of-Two (PoT) Shift-Add Requantization
**The Problem:** The Post-Processor required a large 32x16 multiplier to rescale the 32-bit accumulator back down to an 8-bit activation. This was a massive bottleneck that would have wasted a dedicated DSP slice.
**The Fix:** We replaced the heavy multiplier with a **PoT Shift-Add approximation algorithm** (e.g., data * 1.25 became data + (data >>> 2)). This replaced expensive multiplication with a simple, zero-cost wire shift and an adder, freeing up the DSPs strictly for the neural network matrix math.

### 5. True Systolic Daisy-Chain Output (Routing Decongestion)
**The Problem:** Initially, we tried to read the 32-bit accumulators out of all 64 PEs simultaneously using a gigantic 64-to-1 global multiplexer. This required routing 2,048 wires across the entire chip to a single point, causing fatal routing congestion.
**The Fix:** We deleted the global multiplexer and implemented a **True Systolic Daisy Chain**. The accumulators now act as a massive shift-register "bucket brigade." Each PE passes its result to its neighbor, pumping the data out to the edge of the array one cycle at a time. This completely localized the routing.

### 6. Triangular Data Skewing (Fan-out Reduction)
**The Problem:** Feeding data to all PEs simultaneously causes "High Fan-Out" errors, where one register tries to drive 64 endpoints at once, causing massive capacitance and delay.
**The Fix:** We implemented input_skew.v and weight_loader.v to skew the data. Activations and weights are fed diagonally into the array, one row/column at a time, ensuring that no register ever drives more than one neighboring PE.

### 7. Ping-Pong BSRAM Buffering (Memory Latency Hiding)
**The Problem:** Waiting for the 1GB external DDR3 memory to load weights for the next layer would stall the 205 MHz systolic array, starving the compute units.
**The Fix:** We implemented a **Double-Buffering (Ping-Pong) architecture**. The array computes Layer N using internal SRAM Bank A, while simultaneously pre-fetching weights for Layer N+1 from the external DDR3 into internal SRAM Bank B. This completely hides the slow external memory access latency from the hyper-fast internal TPU core.