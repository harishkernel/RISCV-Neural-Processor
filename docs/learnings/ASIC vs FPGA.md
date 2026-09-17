# ASIC

- ASIC (Application-Specific Integrated Circuit)
- manufactured and hardwired for specific task
- 6 - 7 folds the cost of FPGA

# FPGA

- FPGA (Field-Programmable Gate Array)
- At run-time, HDL is used to re-wire the logic (with existing SRAM `(Static RAM)` bit-streaming)

## LUTs (Look Up Tables)

- LUTs have the gates `(N=4, => 16:1 MUX)`
- There are registers and muxes infront of each LUT
- since MUXes are used for selection of lines via reg.
- No. of. functions: $2^{(2^N)}$
