//==============================================================================
// Module:  bsram_pingpong
// Project: AGVME — AgentGate-V MAC Engine
// Target:  Gowin GW5A-LV25MG121 (Sipeed Tang Primer 25K)
//
// Description:
//   A parameterised ping-pong buffer inferred as Gowin BSRAM.
//   It provides double-buffering so the host can write to one bank (e.g. Ping)
//   while the accelerator reads from the other bank (e.g. Pong).
//
//   Memory Organization:
//     - The memory has depth = 2 * (1 << ADDR_W).
//     - The MSB of the internal address selects the bank (0 = Ping, 1 = Pong).
//     - The `bank_sel` input swaps the banks:
//         bank_sel = 0: Host writes Ping, Accel reads Pong
//         bank_sel = 1: Host writes Pong, Accel reads Ping
//
//   Ports:
//     - Port A (Write): Host DMA/CSR write interface
//     - Port B (Read) : Accelerator read interface
//==============================================================================

module bsram_pingpong #(
    parameter DATA_W = 64, // Width of data word (e.g. 8x8 = 64 bits for one row)
    parameter ADDR_W = 9   // Depth per bank (e.g. 2^9 = 512 words per bank)
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
    output reg  [DATA_W-1:0]    rd_data
);

    // Total memory is 2 banks, so addr width is ADDR_W + 1
    localparam TOTAL_DEPTH = 1 << (ADDR_W + 1);

    // Inferred RAM array
    // Gowin Synthesis supports inferring BSRAM from this template.
    reg [DATA_W-1:0] mem [0:TOTAL_DEPTH-1];

    // Compute internal addresses based on bank_sel
    wire [ADDR_W:0] internal_wr_addr;
    wire [ADDR_W:0] internal_rd_addr;

    // bank_sel=0 => Host writes bank 0 (Ping), reads bank 1 (Pong)
    // bank_sel=1 => Host writes bank 1 (Pong), reads bank 0 (Ping)
    assign internal_wr_addr = {bank_sel, wr_addr};
    assign internal_rd_addr = {~bank_sel, rd_addr};

    // Port A: Write
    always @(posedge clk) begin
        if (wr_en) begin
            mem[internal_wr_addr] <= wr_data;
        end
    end

    // Port B: Read (Synchronous Read)
    always @(posedge clk) begin
        if (rd_en) begin
            rd_data <= mem[internal_rd_addr];
        end
    end

endmodule
