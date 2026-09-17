//==============================================================================
// Module:  pe
// Project: AGVME — AgentGate-V MAC Engine
// Target:  Gowin GW5A-LV25MG121 (Sipeed Tang Primer 25K)
//
// Description:
//   Output-stationary Processing Element for a 2-D systolic array.
//
//   Dataflow (per clock cycle, when en=1):
//     1. Multiply  : product = a_in × w_in
//     2. Accumulate: acc    += product
//     3. Forward    : a_out <= a_in  (→ right neighbour, 1-cycle delay)
//                     w_out <= w_in  (→ bottom neighbour, 1-cycle delay)
//
//   The PE holds its own accumulated partial sum (output-stationary).
//   Over K cycles it computes  C[i][j] = Σ_k A[i][k] · B[k][j]
//   where activations A flow left→right and weights B flow top→bottom.
//
//   Control:
//     clr_acc — synchronous clear of the accumulator only
//     en      — enables MAC and data forwarding
//     rst_n   — asynchronous active-low reset of all registers
//==============================================================================

module pe (
    input  wire        clk,
    input  wire        rst_n,
    input  wire        en,        // compute / forward enable
    input  wire        clr_acc,   // clear accumulator (sync)

    // ---- Systolic data ports ----
    input  wire signed [7:0]  a_in,   // activation from left neighbour
    input  wire signed [7:0]  w_in,   // weight from top neighbour

    output reg  signed [7:0]  a_out,  // activation to right neighbour
    output reg  signed [7:0]  w_out,  // weight to bottom neighbour

    // ---- Result ----
    output wire signed [31:0] acc     // accumulated partial sum
);

    // ---- MAC unit (multiply + accumulate) ----
    int8_mac u_mac (
        .clk   (clk),
        .rst_n (rst_n),
        .en    (en),
        .clr   (clr_acc),
        .a     (a_in),
        .b     (w_in),
        .acc   (acc)
    );

    // ---- Systolic forwarding registers ----
    // 1-cycle delay so data arrives at the next PE on the following clock edge.
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            a_out <= 8'sd0;
            w_out <= 8'sd0;
        end else if (en) begin
            a_out <= a_in;
            w_out <= w_in;
        end
    end

endmodule
