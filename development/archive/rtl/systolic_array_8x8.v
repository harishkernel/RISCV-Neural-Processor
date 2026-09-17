//==============================================================================
// Module:  systolic_array_8x8
// Project: AGVME — AgentGate-V MAC Engine
// Target:  Gowin GW5A-LV25MG121 (Sipeed Tang Primer 25K)
//
// Description:
//   Parameterised N×N output-stationary systolic array (default N=8).
//
//   Topology:
//     - N rows × N columns of Processing Elements (PEs).
//     - Activations enter from the LEFT  edge (one value per row).
//     - Weights   enter from the TOP   edge (one value per column).
//     - Both inputs must be PRE-SKEWED externally (use `input_skew`).
//     - Each PE[i][j] accumulates C[i][j] = Σ_k A[i][k]·B[k][j].
//
//   Wiring:
//     PE[i][j].a_out  → PE[i][j+1].a_in   (left→right, 1-cycle delay)
//     PE[i][j].w_out  → PE[i+1][j].w_in   (top→bottom, 1-cycle delay)
//     Right-edge a_out and bottom-edge w_out are left unconnected (dangling).
//
//   I/O packing (flat vectors, Verilog-2001 friendly):
//     a_in   :  a_in[8*i +: 8]                = activation for row i
//     w_in   :  w_in[8*j +: 8]                = weight for column j
//     acc_out:  acc_out[32*(N*i+j) +: 32]      = PE[i][j] accumulator
//
//   Resource note (N=8, GW5A-25A):
//     64 PEs → 64 multipliers.  Actual utilisation to be measured post-synthesis.
//==============================================================================

module systolic_array_8x8 #(
    parameter N = 8       // array dimension (rows = columns = N)
)(
    input  wire                  clk,
    input  wire                  rst_n,
    input  wire                  en,       // global compute enable
    input  wire                  clr_acc,  // clear all accumulators

    // Activation inputs — pre-skewed, one per row
    input  wire [N*8-1:0]        a_in,

    // Weight inputs — pre-skewed, one per column
    input  wire [N*8-1:0]        w_in,

    // Accumulated outputs — one 32-bit value per PE
    output wire [N*N*32-1:0]     acc_out
);

    // ----------------------------------------------------------------
    // Internal interconnect arrays  (1-D, indexed with flat arithmetic)
    //
    //  Activation horizontal bus:
    //    a_h[ i*(N+1) + p ]   row i, position p
    //       p = 0        → external input  (left edge)
    //       p = 1..N     → output of PE[i][p-1]
    //
    //  Weight vertical bus:
    //    w_v[ j*(N+1) + q ]   column j, position q
    //       q = 0        → external input  (top edge)
    //       q = 1..N     → output of PE[q-1][j]
    // ----------------------------------------------------------------
    wire [7:0] a_h [0 : N*(N+1)-1];
    wire [7:0] w_v [0 : N*(N+1)-1];

    // ----------------------------------------------------------------
    // Connect external inputs to left edge and top edge
    // ----------------------------------------------------------------
    genvar gi, gj;

    generate
        for (gi = 0; gi < N; gi = gi + 1) begin : gen_ext_in
            assign a_h[gi*(N+1) + 0] = a_in[8*gi +: 8];   // row gi ← external activation
            assign w_v[gi*(N+1) + 0] = w_in[8*gi +: 8];   // col gi ← external weight
        end
    endgenerate

    // ----------------------------------------------------------------
    // Instantiate N × N PE grid
    // ----------------------------------------------------------------
    generate
        for (gi = 0; gi < N; gi = gi + 1) begin : gen_row
            for (gj = 0; gj < N; gj = gj + 1) begin : gen_col

                wire signed [31:0] pe_acc_wire;

                pe u_pe (
                    .clk     (clk),
                    .rst_n   (rst_n),
                    .en      (en),
                    .clr_acc (clr_acc),

                    // Activation: left → right
                    .a_in    (a_h[ gi*(N+1) + gj     ]),
                    .w_in    (w_v[ gj*(N+1) + gi     ]),

                    .a_out   (a_h[ gi*(N+1) + gj + 1 ]),
                    .w_out   (w_v[ gj*(N+1) + gi + 1 ]),

                    .acc     (pe_acc_wire)
                );

                // Pack accumulator into flat output bus
                assign acc_out[32*(N*gi + gj) +: 32] = pe_acc_wire;

            end
        end
    endgenerate

endmodule
