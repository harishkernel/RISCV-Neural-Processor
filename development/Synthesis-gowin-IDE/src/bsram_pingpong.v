//==============================================================================
// Module:  bsram_pingpong
// Project: AGVME - AgentGate-V MAC Engine
// Target:  Gowin GW5A-LV25MG121 (Sipeed Tang Primer 25K)
//
// Description:
//   A parameterised ping-pong buffer inferred as Gowin BSRAM.
//   Includes an explicit output register stage to absorb routing delays
//   and maximize Fmax across the FPGA fabric.
//==============================================================================

module bsram_pingpong #(
    parameter DATA_W = 64,
    parameter ADDR_W = 9
)(
    input  wire                 clk,

    // Bank Selection (0 = Host->Ping, 1 = Host->Pong)
    input  wire                 bank_sel,

    // Port A: Host Write Interface
    input  wire                 wr_en,
    input  wire [ADDR_W-1:0]    wr_addr,
    input  wire [DATA_W-1:0]    wr_data,

    // Port B: Accelerator Read Interface
    input  wire                 rd_en,
    input  wire [ADDR_W-1:0]    rd_addr,
    output wire [DATA_W-1:0]    rd_data
);

    localparam TOTAL_DEPTH = 1 << (ADDR_W + 1);

    (* syn_ramstyle = "block_ram" *)
    reg [DATA_W-1:0] mem [0:TOTAL_DEPTH-1];

    wire [ADDR_W:0] internal_wr_addr = {bank_sel, wr_addr};
    wire [ADDR_W:0] internal_rd_addr = {~bank_sel, rd_addr};

    // Internal read data from RAM macro
    reg [DATA_W-1:0] rd_data_internal;
    
    // Output pipeline register (Absorbs routing delay / mapped to BSRAM output reg)
    reg [DATA_W-1:0] rd_data_pipe;

    // Port A: Write
    always @(posedge clk) begin
        if (wr_en) begin
            mem[internal_wr_addr] <= wr_data;
        end
    end

    // Port B: Read & Pipeline
    always @(posedge clk) begin
        if (rd_en) begin
            // Stage 1: Read from memory macro
            rd_data_internal <= mem[internal_rd_addr];
        end
               rd_data_pipe <= rd_data_internal;
    end
    
    assign rd_data = rd_data_pipe;

endmodule