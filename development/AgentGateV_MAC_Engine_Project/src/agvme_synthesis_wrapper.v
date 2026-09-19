//==============================================================================
// Module:  agvme_synthesis_wrapper
// Project: AGVME - AgentGate-V MAC Engine
//
// Description:
//   A "Virtual Wrapper" designed strictly to bypass the Gowin (PA2024) error.
//   The Tang Primer 20K only has 191 physical I/O pins, but agvme_top requires 227.
//   This wrapper takes a single serial input pin and a single serial output pin,
//   and uses an internal shift register to unpack/pack the data for the TPU.
//==============================================================================

module agvme_synthesis_wrapper (
    input  wire clk,
    input  wire rst_n,
    input  wire serial_in,
    output reg  serial_out
);

    // =========================================================================
    // 1. Deserializer (Shift Register for Inputs)
    // =========================================================================
    reg [213:0] shift_in_reg;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            shift_in_reg <= 214'd0;
        end else begin
            shift_in_reg <= {shift_in_reg[212:0], serial_in};
        end
    end

    // =========================================================================
    // 2. Unpack the shift register into the agvme_top ports
    // =========================================================================
    wire        start             = shift_in_reg[0];
    wire [8:0]  K_dim             = shift_in_reg[9:1];
    wire [31:0] bias              = shift_in_reg[41:10];
    wire [15:0] scale_mult        = shift_in_reg[57:42];
    wire [4:0]  scale_shift       = shift_in_reg[62:58];
    wire        en_relu           = shift_in_reg[63];
    
    wire        host_act_bank_sel = shift_in_reg[64];
    wire        host_act_wr_en    = shift_in_reg[65];
    wire [8:0]  host_act_wr_addr  = shift_in_reg[74:66];
    wire [63:0] host_act_wr_data  = shift_in_reg[138:75];
    
    wire        host_wt_bank_sel  = shift_in_reg[139];
    wire        host_wt_wr_en     = shift_in_reg[140];
    wire [8:0]  host_wt_wr_addr   = shift_in_reg[149:141];
    wire [63:0] host_wt_wr_data   = shift_in_reg[213:150];

    // =========================================================================
    // 3. Instantiate the actual TPU Core
    // =========================================================================
    wire        busy;
    wire        done;
    wire        out_valid;
    wire [7:0]  out_data;

    agvme_top #(
        .N(8),
        .ADDR_W(9),
        .DATA_W(64)
    ) u_agvme_top (
        .clk                (clk),
        .rst_n              (rst_n),
        .start              (start),
        .K_dim              (K_dim),
        .busy               (busy),
        .done               (done),
        .bias               (bias),
        .scale_mult         (scale_mult),
        .scale_shift        (scale_shift),
        .en_relu            (en_relu),
        .host_act_bank_sel  (host_act_bank_sel),
        .host_act_wr_en     (host_act_wr_en),
        .host_act_wr_addr   (host_act_wr_addr),
        .host_act_wr_data   (host_act_wr_data),
        .host_wt_bank_sel   (host_wt_bank_sel),
        .host_wt_wr_en      (host_wt_wr_en),
        .host_wt_wr_addr    (host_wt_wr_addr),
        .host_wt_wr_data    (host_wt_wr_data),
        .out_valid          (out_valid),
        .out_data           (out_data)
    );

    // =========================================================================
    // 4. Serializer (Shift Register for Outputs)
    // =========================================================================
    wire [10:0] packed_outputs = {busy, done, out_valid, out_data};
    reg [10:0] shift_out_reg;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            shift_out_reg <= 11'd0;
            serial_out    <= 1'b0;
        end else begin
            shift_out_reg <= {shift_out_reg[9:0], 1'b0} ^ packed_outputs;
            serial_out    <= shift_out_reg[10];
        end
    end

endmodule