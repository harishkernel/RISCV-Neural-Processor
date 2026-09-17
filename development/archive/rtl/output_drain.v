//==============================================================================
// Module:  output_drain
// Project: AGVME — AgentGate-V MAC Engine
// Target:  Gowin GW5A-LV25MG121
//
// Description:
//   An external FSM-based output drain for the 8x8 systolic array.
//   It takes the 2,048-bit flat accumulator bus (64 × 32-bit) and sequentially
//   muxes it to a single 32-bit output port.
//
//   Dataflow:
//     - On `start`, output C[0][0].
//     - Over 64 output cycles, serialize C[0][0] to C[7][7].
//     - `valid` is asserted during these 64 output cycles.
//==============================================================================

module output_drain #(
    parameter N = 8,
    parameter ACC_W = 32
)(
    input  wire                     clk,
    input  wire                     rst_n,

    // Control interface
    input  wire                     start,
    output reg                      busy,
    output reg                      valid,
    output reg                      done,

    // Input from Systolic Array
    input  wire [(N*N*ACC_W)-1:0]   acc_in,

    // Serialized Output
    output reg [ACC_W-1:0]          data_out
);

    // Number of elements to drain
    localparam TOTAL_ELEMENTS = N * N;

    // Counter for indexing
    // Counts from 0 to TOTAL_ELEMENTS.
    reg [6:0] count;

    // State machine
    localparam IDLE  = 1'b0;
    localparam DRAIN = 1'b1;
    reg state;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state    <= IDLE;
            busy     <= 1'b0;
            valid    <= 1'b0;
            done     <= 1'b0;
            count    <= 7'd0;
            data_out <= 'd0;
        end else begin
            // Default: done is a one-cycle pulse
            done <= 1'b0;

            case (state)

                // ------------------------------------------------------------
                // IDLE
                // ------------------------------------------------------------
                IDLE: begin
                    valid <= 1'b0;

                    if (start) begin
                        state    <= DRAIN;
                        busy     <= 1'b1;

                        // Output C[0][0] on the start cycle
                        data_out <= acc_in[0 +: ACC_W];

                        // Next element will be C[0][1]
                        count <= 7'd1;

                        valid <= 1'b1;
                    end else begin
                        busy <= 1'b0;
                    end
                end

                // ------------------------------------------------------------
                // DRAIN
                // ------------------------------------------------------------
                DRAIN: begin
                    if (count < TOTAL_ELEMENTS) begin
                        // Output next accumulator element
                        data_out <= acc_in[count * ACC_W +: ACC_W];

                        count <= count + 1'b1;
                        valid <= 1'b1;
                        busy  <= 1'b1;
                    end else begin
                        // All 64 elements have been emitted
                        state <= IDLE;
                        busy  <= 1'b0;
                        valid <= 1'b0;
                        done  <= 1'b1;
                    end
                end

                default: begin
                    state    <= IDLE;
                    busy     <= 1'b0;
                    valid    <= 1'b0;
                    done     <= 1'b0;
                    count    <= 7'd0;
                    data_out <= 'd0;
                end

            endcase
        end
    end
endmodule