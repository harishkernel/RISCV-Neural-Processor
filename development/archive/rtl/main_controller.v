//==============================================================================
// Module:  main_controller
// Project: AGVME — AgentGate-V MAC Engine
// Target:  Gowin GW5A-LV25MG121
//
// Description:
//   The central FSM that orchestrates a complete 8x8 tile GEMM operation.
//
//   Sequence of Operations:
//   1. IDLE   : Wait for `start` from Host/CSR.
//   2. LOAD   : Trigger activation and weight feeders for `K_dim` cycles.
//   3. COMPUTE: Wait for the systolic array pipeline to flush.
//               (Loaders finish in K_dim cycles, but the array needs
//                (N-1) + (N-1) cycles for the last wavefront to reach PE[7][7]).
//   4. DRAIN  : Trigger `output_drain` to serialize the 64 accumulators.
//   5. DONE   : Assert `done` back to Host/CSR and return to IDLE.
//==============================================================================

module main_controller #(
    parameter N = 8,
    parameter ADDR_W = 9
)(
    input  wire                 clk,
    input  wire                 rst_n,

    // Interface with Host/CSR
    input  wire                 start,
    input  wire [ADDR_W-1:0]    K_dim,
    output reg                  busy,
    output reg                  done,

    // Control to memory loaders
    output reg                  start_loaders,
    input  wire                 loaders_done, // ANDed from both loaders

    // Control to output drain
    output reg                  start_drain,
    input  wire                 drain_done,
    
    // Control to systolic array
    input  wire                 pipeline_valid,
    output wire                 array_en,
    output wire                 force_zeros,
    output reg                  array_clr
);

    // States
    localparam IDLE    = 3'd0;
    localparam CLR     = 3'd1;
    localparam LOAD    = 3'd2;
    localparam COMPUTE = 3'd3;
    localparam DRAIN   = 3'd4;
    localparam DONE_ST = 3'd5;

    reg [2:0] state;

    // Pipeline flush counter. Max pipeline depth is (N-1) for row skew + (N-1) for col skew 
    // + (N-1) internal PE row hops + (N-1) internal PE col hops
    // Actually, as computed earlier, for PE[7][7], delay is 7 (skew A) + 7 (skew W) 
    // Wait, PE[i][j] delay is skew(i) + hops(j) + skew(j) + hops(i) ? 
    // Skew A delays row i by i cycles. Hops take j cycles to reach column j. Total = i+j.
    // Skew W delays col j by j cycles. Hops take i cycles to reach row i. Total = i+j.
    // So both operands arrive at cycle i+j exactly.
    // For PE[7][7], it receives its first operand at cycle 7+7 = 14.
    // It receives its last operand at cycle 14 + K_dim.
    // The MAC requires 1 cycle. So data is ready at cycle 14 + K_dim + 1.
    // The loaders signal `done` at cycle K_dim + 1.
    // So we need to wait 14 cycles AFTER the loaders are done.
    localparam FLUSH_CYCLES = (N - 1) + (N - 1); // 14 cycles for N=8

    reg [4:0] flush_count;

    assign array_en = (state == LOAD) ? pipeline_valid : (state == COMPUTE);
    assign force_zeros = (state == COMPUTE);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE;
            busy <= 0;
            done <= 0;
            start_loaders <= 0;
            start_drain <= 0;
            array_clr <= 0;
            flush_count <= 0;
        end else begin
            // Defaults
            start_loaders <= 0;
            start_drain <= 0;
            done <= 0;

            case (state)
                IDLE: begin
                    array_clr <= 0;
                    if (start) begin
                        state <= CLR;
                        busy <= 1;
                        array_clr <= 1; // Clear accumulators
                    end else begin
                        busy <= 0;
                    end
                end
                
                CLR: begin
                    array_clr <= 0;
                    state <= LOAD;
                    start_loaders <= 1;
                end

                LOAD: begin
                    // Wait for both loaders to finish pumping data
                    if (loaders_done) begin
                        state <= COMPUTE;
                        flush_count <= FLUSH_CYCLES;
                    end
                end

                COMPUTE: begin
                    if (flush_count > 0) begin
                        flush_count <= flush_count - 1;
                    end else begin
                        state <= DRAIN;
                        start_drain <= 1;
                    end
                end

                DRAIN: begin
                    if (drain_done) begin
                        state <= DONE_ST;
                    end
                end

                DONE_ST: begin
                    done <= 1;
                    state <= IDLE;
                end
                
                default: state <= IDLE;
            endcase
        end
    end

endmodule
