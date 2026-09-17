//==============================================================================
// Module:  activation_feeder
// Project: AGVME — AgentGate-V MAC Engine
// Target:  Gowin GW5A-LV25MG121
//
// Description:
//   Streams activation data (matrix A) from the Activation Ping-Pong BSRAM to 
//   the left edge of the systolic array.
//   Identical in structure to the weight loader, as both stream 64-bit rows
//   (8 elements) per cycle for K_dim cycles.
//==============================================================================

module activation_feeder #(
    parameter ADDR_W = 9,
    parameter DATA_W = 64
)(
    input  wire                 clk,
    input  wire                 rst_n,

    // Control
    input  wire                 start,
    input  wire [ADDR_W-1:0]    K_dim,
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
    reg rd_en_d1;

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
                    state <= IDLE;
                    done <= 1;
                end
                
                default: state <= IDLE;
            endcase
        end
    end

    // Valid signal pipeline matching BSRAM 1-cycle read latency
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rd_en_d1 <= 0;
            valid_out <= 0;
        end else begin
            rd_en_d1 <= bsram_rd_en;
            valid_out <= rd_en_d1; 
        end
    end

endmodule
