//==============================================================================
// Module: systolic_array_8x8
// Project: AGVME - AgentGate-V MAC Engine
//
// Description:
//   An 8x8 2D Systolic Array.
//   100% Pure Soft-Core TPU implementation. Bypasses all hardware DSPs to 
//   avoid physical routing bottlenecks. Uses the Radix-4 Booth Multiplier 
//   for all 64 MACs.
//==============================================================================

module systolic_array_8x8 #(
    parameter N      = 8,
    parameter CH_W   = 8,
    parameter ACC_W  = 32
)(
    input  wire                          clk,
    input  wire                          rst_n,

    // Control
    input  wire                          en,
    input  wire                          clr,
    input  wire                          shift_en,

    // Data Inputs (Skewed)
    input  wire [N*CH_W-1:0]             a_in_skewed,
    input  wire [N*CH_W-1:0]             w_in_skewed,

    // Serial Data Output (Daisy Chain)
    output wire [ACC_W-1:0]              acc_chain_out
);

    // Internal interconnect wires
    wire [CH_W-1:0] a_wire [0:N-1][0:N];
    wire [CH_W-1:0] w_wire [0:N][0:N-1];
    
    // Daisy chain interconnect for the accumulators
    wire [ACC_W-1:0] acc_chain [0:N*N];
    
    assign acc_chain[0] = {ACC_W{1'b0}};
    assign acc_chain_out = acc_chain[N*N];

    // Assign skewed inputs to the boundaries of the array
    genvar i;
    generate
        for (i = 0; i < N; i = i + 1) begin : gen_inputs
            assign a_wire[i][0] = a_in_skewed[CH_W*i +: CH_W];
            assign w_wire[0][i] = w_in_skewed[CH_W*i +: CH_W];
        end
    endgenerate

    // Generate the N x N Array (100% Booth PEs)
    genvar row, col;
    generate
        for (row = 0; row < N; row = row + 1) begin : gen_row
            for (col = 0; col < N; col = col + 1) begin : gen_col
                
                pe_booth #(
                    .CH_W(CH_W)
                ) u_pe (
                    .clk       (clk),
                    .rst_n     (rst_n),
                    .en        (en),
                    .clr       (clr),
                    .shift_en  (shift_en),
                    .shift_in  (acc_chain[row*N + col]),

                    .a_in      (a_wire[row][col]),
                    .w_in      (w_wire[row][col]),

                    .a_out     (a_wire[row][col+1]),
                    .w_out     (w_wire[row+1][col]),

                    .acc_out   (acc_chain[row*N + col + 1])
                );

            end
        end
    endgenerate

endmodule