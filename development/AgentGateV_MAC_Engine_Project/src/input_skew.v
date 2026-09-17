//==============================================================================
// Module: input_skew
// Project: AGVME — AgentGate-V MAC Engine
//
// Description:
//   Applies triangular skew to the input streams (activations or weights)
//   to align them temporally for the systolic array.
//   Channel 0: delayed by 0 cycles
//   Channel 1: delayed by 1 cycle
//   ...
//   Channel i: delayed by i cycles
//==============================================================================

module input_skew #(
    parameter N    = 8,
    parameter CH_W = 8
)(
    input  wire                  clk,
    input  wire                  rst_n,
    input  wire                  en,
    input  wire [N*CH_W-1:0]     data_in,
    output wire [N*CH_W-1:0]     data_out
);

    // Channel 0 passes through without delay
    assign data_out[CH_W-1:0] = data_in[CH_W-1:0];

    // Channels 1..N-1 — shift-register chains of increasing depth
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
                    sr[1] <= data_in[CH_W*gi +: CH_W];
                    for (k = 2; k <= gi; k = k + 1)
                        sr[k] <= sr[k-1];
                end
            end

            assign data_out[CH_W*gi +: CH_W] = sr[gi];

        end
    endgenerate

endmodule
