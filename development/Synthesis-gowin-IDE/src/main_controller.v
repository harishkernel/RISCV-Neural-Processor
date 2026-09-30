//==============================================================================
// Module: main_controller
// Project: AGVME AgentGate-V MAC Engine
//==============================================================================

module main_controller #(
    parameter N      = 8,
    parameter ADDR_W = 9
)(
    input wire                 clk,
    input wire                 rst_n,

    // Execution control
    input wire                 start,
    input wire [ADDR_W-1:0]    K_dim,

    output reg                 busy,
    output reg                 done,

    // Loader control
    output reg                 start_loaders,
    input wire                 loaders_done,

    // Output drain control
    output reg                 start_drain,
    input wire                 drain_done,

    // Systolic array control
    output wire                array_en,
    output reg                 array_clr
);

    localparam IDLE     = 3'd0;
    localparam CLR      = 3'd1;
    localparam LOAD     = 3'd2;
    localparam COMPUTE  = 3'd3;
    localparam DRAIN    = 3'd4;
    localparam WAIT_OUT = 3'd5;
    localparam DONE_ST  = 3'd6;

    reg [2:0] state;

    // Flush array + 1 cycle for new BSRAM latency
    localparam FLUSH_CYCLES = (N-1) + (N-1) + 1 + 3 + 1; // 5-stage pure DSP latency
    reg [4:0] flush_count;

    // Post-processor pipeline latency = 6 cycles
    localparam POST_LATENCY = 6;
    reg [3:0] post_count;

    assign array_en = (state == LOAD) || (state == COMPUTE);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state         <= IDLE;
            busy          <= 1'b0;
            done          <= 1'b0;
            start_loaders <= 1'b0;
            start_drain   <= 1'b0;
            array_clr     <= 1'b0;
            flush_count   <= 5'd0;
            post_count    <= 4'd0;
        end else begin
            start_loaders <= 1'b0;
            start_drain   <= 1'b0;
            done          <= 1'b0;

            case (state)
                IDLE: begin
                    busy      <= 1'b0;
                    array_clr <= 1'b0;
                    if (start) begin
                        busy      <= 1'b1;
                        array_clr <= 1'b1;
                        state     <= CLR;
                    end
                end

                CLR: begin
                    array_clr     <= 1'b0;
                    start_loaders <= 1'b1;
                    state         <= LOAD;
                end

                LOAD: begin
                    if (loaders_done) begin
                        flush_count <= FLUSH_CYCLES;
                        state       <= COMPUTE;
                    end
                end

                COMPUTE: begin
                    if (flush_count > 0) begin
                        flush_count <= flush_count - 1'b1;
                    end else begin
                        start_drain <= 1'b1;
                        state       <= DRAIN;
                    end
                end

                DRAIN: begin
                    if (drain_done) begin
                        post_count <= POST_LATENCY;
                        state      <= WAIT_OUT;
                    end
                end

                WAIT_OUT: begin
                    if (post_count > 0) begin
                        post_count <= post_count - 1'b1;
                    end else begin
                        state <= DONE_ST;
                    end
                end

                DONE_ST: begin
                    done  <= 1'b1;
                    busy  <= 1'b0;
                    state <= IDLE;
                end

                default: begin
                    state         <= IDLE;
                    busy          <= 1'b0;
                    done          <= 1'b0;
                    start_loaders <= 1'b0;
                    start_drain   <= 1'b0;
                    array_clr     <= 1'b0;
                    flush_count   <= 5'd0;
                    post_count    <= 4'd0;
                end
            endcase
        end
    end
endmodule
