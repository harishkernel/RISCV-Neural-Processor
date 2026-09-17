//==============================================================================
// Module:  input_skew
// Project: AGVME — AgentGate-V MAC Engine
// Target:  Gowin GW5A-LV25MG121 (Sipeed Tang Primer 25K)
//
// Description:
//   Applies staggered delays to N parallel data channels so that a
//   systolic array receives time-aligned data.
//
//     Channel 0 : 0 cycles delay  (pass-through)
//     Channel 1 : 1 cycle  delay
//     Channel 2 : 2 cycles delay
//     …
//     Channel N-1 : N-1 cycles delay
//
//   Used twice in the GEMM datapath:
//     1. Row-skew for activations   (before left edge of array)
//     2. Column-skew for weights    (before top  edge of array)
//
//   Total delay registers = 0+1+2+…+(N-1) = N·(N-1)/2
//     For N=8 → 28 shift-register stages × DATA_W bits each.
//==============================================================================

module input_skew #(
    parameter N      = 8,   // number of channels
    parameter CH_W   = 8    // data width per channel
)(
    input  wire                   clk,
    input  wire                   rst_n,
    input  wire                   en,

    input  wire [N*CH_W-1:0]      data_in,   // parallel input  (channel i at [CH_W*i +: CH_W])
    output wire [N*CH_W-1:0]      data_out   // skewed   output (same packing)
);

    // ----------------------------------------------------------------
    // Channel 0 — zero delay (combinational pass-through)
    // ----------------------------------------------------------------
    assign data_out[CH_W-1:0] = data_in[CH_W-1:0];

    // ----------------------------------------------------------------
    // Channels 1..N-1 — shift-register chains of increasing depth
    // ----------------------------------------------------------------
    genvar gi;
    generate
        for (gi = 1; gi < N; gi = gi + 1) begin : gen_delay
            
            // Exactly 'gi' synchronous cycles of delay
            reg [CH_W-1:0] sr [1:gi];
            integer k;

            always @(posedge clk or negedge rst_n) begin
                if (!rst_n) begin
                    for (k = 1; k <= gi; k = k + 1)
                        sr[k] <= {CH_W{1'b0}};
                end else if (en) begin
                    // 1st cycle of delay captures input
                    sr[1] <= data_in[CH_W*gi +: CH_W];
                    // Subsequent cycles shift data down the pipeline
                    for (k = 2; k <= gi; k = k + 1)
                        sr[k] <= sr[k-1];
                end
            end

            // Output from the final stage 'gi'
            assign data_out[CH_W*gi +: CH_W] = sr[gi];

        end
    endgenerate

endmodule
