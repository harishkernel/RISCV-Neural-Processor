//==============================================================================
// Module: weight_loader.v
// Project: AGVME - AgentGate-V MAC Engine
//
// Description:
//   Reads words from external BSRAM with 2-cycle read latency.
//==============================================================================

module weight_loader #(
    parameter ADDR_W = 9,
    parameter DATA_W = 64
)(
    input wire                 clk,
    input wire                 rst_n,

    input wire                 start,
    input wire [ADDR_W-1:0]    K_dim,

    output reg                 done,

    output reg                 bsram_rd_en,
    output reg [ADDR_W-1:0]    bsram_addr,
    input wire [DATA_W-1:0]    bsram_data,

    output reg                 valid_out,
    output wire [DATA_W-1:0]   data_out
);

    localparam IDLE = 2'd0;
    localparam READ = 2'd1;
    localparam WAIT = 2'd2;

    reg [1:0] state;
    reg [ADDR_W-1:0] count;
    reg bsram_rd_en_pipe;

    assign data_out = bsram_data;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state       <= IDLE;
            count       <= {ADDR_W{1'b0}};
            done        <= 1'b0;
            bsram_rd_en <= 1'b0;
            bsram_rd_en_pipe <= 1'b0;
            bsram_addr  <= {ADDR_W{1'b0}};
            valid_out   <= 1'b0;
        end else begin
            done      <= 1'b0;
            
            // 2-cycle read latency tracking
            bsram_rd_en_pipe <= bsram_rd_en;
            valid_out        <= bsram_rd_en_pipe;

            case (state)
                IDLE: begin
                    bsram_rd_en <= 1'b0;
                    bsram_addr  <= {ADDR_W{1'b0}};
                    if (start && (K_dim != 0)) begin
                        bsram_rd_en <= 1'b1;
                        bsram_addr  <= {ADDR_W{1'b0}};
                        count <= {{(ADDR_W-1){1'b0}}, 1'b1};
                        state <= READ;
                    end
                end
                READ: begin
                    if (count < K_dim) begin
                        bsram_rd_en <= 1'b1;
                        bsram_addr  <= count;
                        count <= count + 1'b1;
                    end else begin
                        bsram_rd_en <= 1'b0;
                        state <= WAIT;
                    end
                end
                WAIT: begin
                    bsram_rd_en <= 1'b0;
                    done <= 1'b1;
                    state <= IDLE;
                end
                default: begin
                    state <= IDLE;
                    count <= {ADDR_W{1'b0}};
                    bsram_rd_en <= 1'b0;
                    bsram_addr  <= {ADDR_W{1'b0}};
                    done <= 1'b0;
                end
            endcase
        end
    end
endmodule