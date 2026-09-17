//==============================================================================
// Module:  int8_mac
// Project: AGVME — AgentGate-V MAC Engine
// Target:  Gowin GW5A-LV25MG121 (Sipeed Tang Primer 25K)
//
// Description:
//   INT8 signed Multiply-Accumulate unit.
//   Computes:  acc += a * b   (when en=1)
//   - a, b : signed 8-bit operands (activation, weight)
//   - acc  : signed 32-bit accumulator
//
//   The multiply produces a 16-bit signed product which is sign-extended
//   and added to the 32-bit accumulator. The accumulator can be cleared
//   synchronously via the 'clr' signal.
//
//   Gowin notes:
//   - The 8x8 signed multiply maps to a GW5A DSP slice.
//     If DSP slices are exhausted the synthesizer will fall back to LUTs.
//     synthesiser will infer LUT-based logic (~50–65 LUT4s per multiply).
//   - Async active-low reset matches Gowin GSR convention.
//==============================================================================

module int8_mac (
    input  wire        clk,     // system clock
    input  wire        rst_n,   // active-low asynchronous reset
    input  wire        en,      // compute enable
    input  wire        clr,     // synchronous accumulator clear
    input  wire signed [7:0]  a,   // operand A (activation)
    input  wire signed [7:0]  b,   // operand B (weight)
    output reg  signed [31:0] acc  // accumulated result
);

    // ---- Multiply stage ----
    // 8-bit signed × 8-bit signed → 16-bit signed product
    wire signed [15:0] product;
    assign product = a * b;

    // ---- Accumulate stage ----
    // Sign-extension from 16→32 bits is implicit (both operands are 'signed')
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            acc <= 32'sd0;
        else if (clr)
            acc <= 32'sd0;
        else if (en)
            acc <= acc + product;
    end

endmodule
