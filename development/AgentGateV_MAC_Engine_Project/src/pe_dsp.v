//==============================================================================
// Module: pe_dsp (Processing Element)
// Project: AGVME - AgentGate-V MAC Engine
//==============================================================================

module pe_dsp #(
    parameter CH_W = 8
)(
    input  wire                 clk,
    input  wire                 rst_n,

    // Array Control
    input  wire                 en,
    input  wire                 clr,
    
    // Daisy Chain Output Drain
    input  wire                 shift_en,
    input  wire [31:0]          shift_in,

    // Data Inputs (from West and North)
    input  wire [CH_W-1:0]      a_in,
    input  wire [CH_W-1:0]      w_in,

    // Data Outputs (to East and South)
    output reg  [CH_W-1:0]      a_out,
    output reg  [CH_W-1:0]      w_out,

    // Accumulator Output / Shift Out
    output wire [31:0]          acc_out
);

    // Forwarding Registers
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            a_out <= {CH_W{1'b0}};
            w_out <= {CH_W{1'b0}};
        end else if (en) begin
            a_out <= a_in;
            w_out <= w_in;
        end
    end

    // MAC Unit (Hardware DSP variant)
    int8_mac_dsp u_mac (
        .clk      (clk),
        .rst_n    (rst_n),
        .en       (en),
        .clr      (clr),
        .shift_en (shift_en),
        .shift_in (shift_in),
        .a_in     (a_in),
        .w_in     (w_in),
        .acc_out  (acc_out)
    );
endmodule