//==============================================================================
// Module: int8_mac_dsp
// Project: AGVME - AgentGate-V MAC Engine
//
// Description:
//   A deep-pipelined INT8 Multiply-Accumulate unit explicitly targeting 
//   hardware DSP slices. It uses 5 pipeline stages to perfectly match 
//   the latency of the int8_mac_booth module.
//
//   Latency: 5 clock cycles
//==============================================================================

module int8_mac_dsp #(
    parameter ACC_W = 32
)(
    input  wire                 clk,
    input  wire                 rst_n,
    input  wire                 clr,
    input  wire                 en,
    input  wire                 shift_en,
    input  wire signed [ACC_W-1:0] shift_in,

    input  wire signed [7:0]    a_in,
    input  wire signed [7:0]    w_in,
    
    output reg signed [ACC_W-1:0] acc_out
);

    //==========================================================================
    // Stage 1: Input Latch
    //==========================================================================
    reg signed [7:0] a_reg;
    reg signed [7:0] w_reg;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            a_reg <= 8'sd0;
            w_reg <= 8'sd0;
        end else if (en) begin
            a_reg <= a_in;
            w_reg <= w_in;
        end
    end

    //==========================================================================
    // Stage 2: Hardware DSP Multiplier
    //==========================================================================
    (* syn_dsp = "yes" *) reg signed [15:0] mult_p;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            mult_p <= 16'sd0;
        end else if (en) begin
            mult_p <= a_reg * w_reg;
        end
    end

    //==========================================================================
    // Stage 3 & 4: Pipeline balancing (to match Booth MAC's 5 stages)
    //==========================================================================
    reg signed [15:0] mult_reg1;
    reg signed [15:0] mult_reg2;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            mult_reg1 <= 16'sd0;
            mult_reg2 <= 16'sd0;
        end else if (en) begin
            mult_reg1 <= mult_p;
            mult_reg2 <= mult_reg1;
        end
    end

    //==========================================================================
    // Stage 5: Accumulator & Daisy Chain
    //==========================================================================
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            acc_out <= {ACC_W{1'b0}};
        end else begin
            if (shift_en) begin
                acc_out <= shift_in;
            end else if (clr) begin
                acc_out <= {ACC_W{1'b0}};
            end else if (en) begin
                acc_out <= acc_out + mult_reg2;
            end
        end
    end

endmodule