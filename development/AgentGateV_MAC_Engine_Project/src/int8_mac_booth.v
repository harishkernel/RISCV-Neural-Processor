//==============================================================================
// Module: int8_mac
// Project: AGVME - AgentGate-V MAC Engine
//
// Description:
//   A hardcore, gate-level Fully-Pipelined Radix-4 Booth Multiplier.
//   This module completely bypasses the FPGA synthesizer's native DSP/LUT 
//   multipliers, forcing the logic level down to 2 by manually inserting 
//   pipeline registers between every addition step in the reduction tree.
//
//   Latency: 5 clock cycles
//==============================================================================

module int8_mac_booth #(
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
    reg signed [7:0] a_reg1;
    reg signed [7:0] w_reg1;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            a_reg1 <= 8'sd0;
            w_reg1 <= 8'sd0;
        end else if (en) begin
            a_reg1 <= a_in;
            w_reg1 <= w_in;
        end
    end

    //==========================================================================
    // Stage 2: Radix-4 Booth Partial Products Generation
    //==========================================================================
    wire [8:0] B_ext = {w_reg1[7], w_reg1}; // 9-bit extended weight for chunking

    reg signed [15:0] pp0, pp1, pp2, pp3;

    // Helper task to generate a 16-bit partial product from a 3-bit chunk
    function signed [15:0] booth_pp;
        input [2:0] chunk;
        input signed [7:0] A;
        input integer shift;
        reg signed [8:0] A_ext; // 9-bit to hold 2*A without overflow
        begin
            A_ext = A; // default assignment
            case (chunk)
                3'b000, 3'b111: A_ext = 9'sd0;
                3'b001, 3'b010: A_ext = {A[7], A};
                3'b011:         A_ext = {A, 1'b0};
                3'b100:         A_ext = -{A, 1'b0};
                3'b101, 3'b110: A_ext = -{A[7], A};
                default:        A_ext = 9'sd0;
            endcase
            // Sign extend to 16 bits and shift
            booth_pp = ({{7{A_ext[8]}}, A_ext}) <<< shift;
        end
    endfunction

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pp0 <= 16'sd0;
            pp1 <= 16'sd0;
            pp2 <= 16'sd0;
            pp3 <= 16'sd0;
        end else if (en) begin
            pp0 <= booth_pp(B_ext[2:0], a_reg1, 0);
            pp1 <= booth_pp(B_ext[4:2], a_reg1, 2);
            pp2 <= booth_pp(B_ext[6:4], a_reg1, 4);
            pp3 <= booth_pp(B_ext[8:6], a_reg1, 6);
        end
    end

    //==========================================================================
    // Stage 3: Reduction Tree Layer 1
    //==========================================================================
    reg signed [15:0] sum0_1, sum2_3;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            sum0_1 <= 16'sd0;
            sum2_3 <= 16'sd0;
        end else if (en) begin
            sum0_1 <= pp0 + pp1;
            sum2_3 <= pp2 + pp3;
        end
    end

    //==========================================================================
    // Stage 4: Reduction Tree Layer 2 (Final Multiplier Latch)
    //==========================================================================
    reg signed [15:0] mult_reg;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            mult_reg <= 16'sd0;
        end else if (en) begin
            mult_reg <= sum0_1 + sum2_3;
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
                acc_out <= acc_out + mult_reg;
            end
        end
    end

endmodule
