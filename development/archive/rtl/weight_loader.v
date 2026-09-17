//==============================================================================
// Module:  weight_loader
// Project: AGVME — AgentGate-V MAC Engine
// Target:  Gowin GW5A-LV25MG121
//
// Description:
//   Streams weight data (matrix B) from the Weight Ping-Pong BSRAM to the
//   top edge of the systolic array.
//   For an 8x8 array computing C = A * B, it reads K rows of B.
//   Each row of B is 8 elements (64 bits), which feeds the 8 columns.
//
//   Dataflow:
//     - On `start`, it reads addresses 0 to K-1.
//     - BSRAM read latency is 1 cycle.
//     - `data_out` and `valid_out` are aligned with the read data.
//==============================================================================

module weight_loader #(
    parameter ADDR_W = 9,
    parameter DATA_W = 64
)(
    input  wire                 clk,
    input  wire                 rst_n,

    // Control
    input  wire                 start,
    input  wire [ADDR_W-1:0]    K_dim, // Inner dimension (number of words to read)
    output reg                  done,

    // BSRAM Read Interface
    output reg                  bsram_rd_en,
    output reg  [ADDR_W-1:0]    bsram_addr,
    input  wire [DATA_W-1:0]    bsram_data,

    // Output to Systolic Array (via skew)
    output reg                  valid_out,
    output wire [DATA_W-1:0]    data_out
);

    // State Machine
    localparam IDLE = 2'd0;
    localparam READ = 2'd1;
    localparam WAIT = 2'd2;

    reg [1:0] state;
    reg [ADDR_W-1:0] count;
    reg rd_en_d1; // delayed rd_en to align with valid_out

    assign data_out = bsram_data;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE;
            bsram_rd_en <= 0;
            bsram_addr <= 0;
            count <= 0;
            done <= 0;
        end else begin
            done <= 0;
            case (state)
                IDLE: begin
                    if (start && K_dim > 0) begin
                        state <= READ;
                        bsram_rd_en <= 1;
                        bsram_addr <= 0;
                        count <= 1;
                    end
                end

                READ: begin
                    if (count < K_dim) begin
                        bsram_addr <= count;
                        count <= count + 1;
                        bsram_rd_en <= 1;
                    end else begin
                        bsram_rd_en <= 0;
                        state <= WAIT;
                    end
                end

                WAIT: begin
                    // One cycle wait for the last BSRAM read to complete
                    state <= IDLE;
                    done <= 1;
                end
                
                default: state <= IDLE;
            endcase
        end
    end

    // Valid signal is rd_en delayed by 1 cycle (matching BSRAM read latency)
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rd_en_d1 <= 0;
            valid_out <= 0;
        end else begin
            rd_en_d1 <= bsram_rd_en;
            valid_out <= rd_en_d1; // wait, bsram_rd_en is a register.
            // When bsram_rd_en is set to 1 on clk edge 1.
            // During cycle 1, bsram_rd_en is 1.
            // On clk edge 2, BSRAM registers the read. 
            // rd_en_d1 becomes 1.
            // During cycle 2, BSRAM is reading.
            // On clk edge 3, BSRAM data is available. 
            // valid_out becomes 1.
            // This is a 2-cycle delay from setting bsram_rd_en! 
            // Wait, Gowin BSRAM is synchronous read.
            // If rd_en is 1 at cycle T, data appears at cycle T+1 (after next posedge).
            // Let's trace carefully:
            // T0: state=IDLE, start=1 -> bsram_rd_en <= 1
            // T1: bsram_rd_en is 1. BSRAM samples rd_en and addr.
            // T2: BSRAM outputs data.
            // So data is valid at T2.
            // We want valid_out to be 1 at T2.
            // At T0: bsram_rd_en <= 1
            // At T1: rd_en_d1 <= bsram_rd_en (which is 1)
            // At T2: valid_out <= rd_en_d1 (which is 1)
            // So valid_out is 1 at T2. Perfect.
        end
    end

endmodule
