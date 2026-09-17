// wallace8x8.v
//
// Standalone 8-bit x 8-bit Wallace tree multiplier. Fully flat: does NOT
// depend on the 4x4 wallace module. Depends only on full_adder.v
// (module full_adder: a, b, cin -> sum, cout), same interface as your
// existing wallace4x4.v uses.
//
// Schedule generated and numerically verified before being emitted as
// Verilog: 7 reduction layers, 42 full adders, 0 half adders.
// Half adders were tried and empirically made the schedule WORSE (9 layers
// instead of 7), since each one creates a new carry that can re-trigger an
// already-settled column -- so this simpler FA-only schedule is used.
//
// Final merge: the two remaining rows are combined with a plain add here
// for clarity -- swap in a real adder (e.g. cla4x4/cla32x32) later if you
// want that stage gate-level too.

module wallace8x8 (
    input  wire [7:0]  A,
    input  wire [7:0]  B,
    output wire [15:0] P
);

    // ---- AND array: 64 partial product bits ----
    wire pp_0_0 = A[0] & B[0];
    wire pp_0_1 = A[0] & B[1];
    wire pp_0_2 = A[0] & B[2];
    wire pp_0_3 = A[0] & B[3];
    wire pp_0_4 = A[0] & B[4];
    wire pp_0_5 = A[0] & B[5];
    wire pp_0_6 = A[0] & B[6];
    wire pp_0_7 = A[0] & B[7];
    wire pp_1_0 = A[1] & B[0];
    wire pp_1_1 = A[1] & B[1];
    wire pp_1_2 = A[1] & B[2];
    wire pp_1_3 = A[1] & B[3];
    wire pp_1_4 = A[1] & B[4];
    wire pp_1_5 = A[1] & B[5];
    wire pp_1_6 = A[1] & B[6];
    wire pp_1_7 = A[1] & B[7];
    wire pp_2_0 = A[2] & B[0];
    wire pp_2_1 = A[2] & B[1];
    wire pp_2_2 = A[2] & B[2];
    wire pp_2_3 = A[2] & B[3];
    wire pp_2_4 = A[2] & B[4];
    wire pp_2_5 = A[2] & B[5];
    wire pp_2_6 = A[2] & B[6];
    wire pp_2_7 = A[2] & B[7];
    wire pp_3_0 = A[3] & B[0];
    wire pp_3_1 = A[3] & B[1];
    wire pp_3_2 = A[3] & B[2];
    wire pp_3_3 = A[3] & B[3];
    wire pp_3_4 = A[3] & B[4];
    wire pp_3_5 = A[3] & B[5];
    wire pp_3_6 = A[3] & B[6];
    wire pp_3_7 = A[3] & B[7];
    wire pp_4_0 = A[4] & B[0];
    wire pp_4_1 = A[4] & B[1];
    wire pp_4_2 = A[4] & B[2];
    wire pp_4_3 = A[4] & B[3];
    wire pp_4_4 = A[4] & B[4];
    wire pp_4_5 = A[4] & B[5];
    wire pp_4_6 = A[4] & B[6];
    wire pp_4_7 = A[4] & B[7];
    wire pp_5_0 = A[5] & B[0];
    wire pp_5_1 = A[5] & B[1];
    wire pp_5_2 = A[5] & B[2];
    wire pp_5_3 = A[5] & B[3];
    wire pp_5_4 = A[5] & B[4];
    wire pp_5_5 = A[5] & B[5];
    wire pp_5_6 = A[5] & B[6];
    wire pp_5_7 = A[5] & B[7];
    wire pp_6_0 = A[6] & B[0];
    wire pp_6_1 = A[6] & B[1];
    wire pp_6_2 = A[6] & B[2];
    wire pp_6_3 = A[6] & B[3];
    wire pp_6_4 = A[6] & B[4];
    wire pp_6_5 = A[6] & B[5];
    wire pp_6_6 = A[6] & B[6];
    wire pp_6_7 = A[6] & B[7];
    wire pp_7_0 = A[7] & B[0];
    wire pp_7_1 = A[7] & B[1];
    wire pp_7_2 = A[7] & B[2];
    wire pp_7_3 = A[7] & B[3];
    wire pp_7_4 = A[7] & B[4];
    wire pp_7_5 = A[7] & B[5];
    wire pp_7_6 = A[7] & B[6];
    wire pp_7_7 = A[7] & B[7];

    // ---- Wallace reduction tree: 7 layers, 42 full adders ----
    // Layer 1
    wire s_L1_c2_0, c_L1_c2_0;
    full_adder FA_s_L1_c2_0 (.a(pp_0_2), .b(pp_1_1), .cin(pp_2_0), .sum(s_L1_c2_0), .cout(c_L1_c2_0));
    wire s_L1_c3_0, c_L1_c3_0;
    full_adder FA_s_L1_c3_0 (.a(pp_0_3), .b(pp_1_2), .cin(pp_2_1), .sum(s_L1_c3_0), .cout(c_L1_c3_0));
    wire s_L1_c4_0, c_L1_c4_0;
    full_adder FA_s_L1_c4_0 (.a(pp_0_4), .b(pp_1_3), .cin(pp_2_2), .sum(s_L1_c4_0), .cout(c_L1_c4_0));
    wire s_L1_c5_0, c_L1_c5_0;
    full_adder FA_s_L1_c5_0 (.a(pp_0_5), .b(pp_1_4), .cin(pp_2_3), .sum(s_L1_c5_0), .cout(c_L1_c5_0));
    wire s_L1_c5_1, c_L1_c5_1;
    full_adder FA_s_L1_c5_1 (.a(pp_3_2), .b(pp_4_1), .cin(pp_5_0), .sum(s_L1_c5_1), .cout(c_L1_c5_1));
    wire s_L1_c6_0, c_L1_c6_0;
    full_adder FA_s_L1_c6_0 (.a(pp_0_6), .b(pp_1_5), .cin(pp_2_4), .sum(s_L1_c6_0), .cout(c_L1_c6_0));
    wire s_L1_c6_1, c_L1_c6_1;
    full_adder FA_s_L1_c6_1 (.a(pp_3_3), .b(pp_4_2), .cin(pp_5_1), .sum(s_L1_c6_1), .cout(c_L1_c6_1));
    wire s_L1_c7_0, c_L1_c7_0;
    full_adder FA_s_L1_c7_0 (.a(pp_0_7), .b(pp_1_6), .cin(pp_2_5), .sum(s_L1_c7_0), .cout(c_L1_c7_0));
    wire s_L1_c7_1, c_L1_c7_1;
    full_adder FA_s_L1_c7_1 (.a(pp_3_4), .b(pp_4_3), .cin(pp_5_2), .sum(s_L1_c7_1), .cout(c_L1_c7_1));
    wire s_L1_c8_0, c_L1_c8_0;
    full_adder FA_s_L1_c8_0 (.a(pp_1_7), .b(pp_2_6), .cin(pp_3_5), .sum(s_L1_c8_0), .cout(c_L1_c8_0));
    wire s_L1_c8_1, c_L1_c8_1;
    full_adder FA_s_L1_c8_1 (.a(pp_4_4), .b(pp_5_3), .cin(pp_6_2), .sum(s_L1_c8_1), .cout(c_L1_c8_1));
    wire s_L1_c9_0, c_L1_c9_0;
    full_adder FA_s_L1_c9_0 (.a(pp_2_7), .b(pp_3_6), .cin(pp_4_5), .sum(s_L1_c9_0), .cout(c_L1_c9_0));
    wire s_L1_c9_1, c_L1_c9_1;
    full_adder FA_s_L1_c9_1 (.a(pp_5_4), .b(pp_6_3), .cin(pp_7_2), .sum(s_L1_c9_1), .cout(c_L1_c9_1));
    wire s_L1_c10_0, c_L1_c10_0;
    full_adder FA_s_L1_c10_0 (.a(pp_3_7), .b(pp_4_6), .cin(pp_5_5), .sum(s_L1_c10_0), .cout(c_L1_c10_0));
    wire s_L1_c11_0, c_L1_c11_0;
    full_adder FA_s_L1_c11_0 (.a(pp_4_7), .b(pp_5_6), .cin(pp_6_5), .sum(s_L1_c11_0), .cout(c_L1_c11_0));
    wire s_L1_c12_0, c_L1_c12_0;
    full_adder FA_s_L1_c12_0 (.a(pp_5_7), .b(pp_6_6), .cin(pp_7_5), .sum(s_L1_c12_0), .cout(c_L1_c12_0));
    // Layer 2
    wire s_L2_c3_0, c_L2_c3_0;
    full_adder FA_s_L2_c3_0 (.a(c_L1_c2_0), .b(s_L1_c3_0), .cin(pp_3_0), .sum(s_L2_c3_0), .cout(c_L2_c3_0));
    wire s_L2_c4_0, c_L2_c4_0;
    full_adder FA_s_L2_c4_0 (.a(c_L1_c3_0), .b(s_L1_c4_0), .cin(pp_3_1), .sum(s_L2_c4_0), .cout(c_L2_c4_0));
    wire s_L2_c5_0, c_L2_c5_0;
    full_adder FA_s_L2_c5_0 (.a(c_L1_c4_0), .b(s_L1_c5_0), .cin(s_L1_c5_1), .sum(s_L2_c5_0), .cout(c_L2_c5_0));
    wire s_L2_c6_0, c_L2_c6_0;
    full_adder FA_s_L2_c6_0 (.a(c_L1_c5_0), .b(c_L1_c5_1), .cin(s_L1_c6_0), .sum(s_L2_c6_0), .cout(c_L2_c6_0));
    wire s_L2_c7_0, c_L2_c7_0;
    full_adder FA_s_L2_c7_0 (.a(c_L1_c6_0), .b(c_L1_c6_1), .cin(s_L1_c7_0), .sum(s_L2_c7_0), .cout(c_L2_c7_0));
    wire s_L2_c7_1, c_L2_c7_1;
    full_adder FA_s_L2_c7_1 (.a(s_L1_c7_1), .b(pp_6_1), .cin(pp_7_0), .sum(s_L2_c7_1), .cout(c_L2_c7_1));
    wire s_L2_c8_0, c_L2_c8_0;
    full_adder FA_s_L2_c8_0 (.a(c_L1_c7_0), .b(c_L1_c7_1), .cin(s_L1_c8_0), .sum(s_L2_c8_0), .cout(c_L2_c8_0));
    wire s_L2_c9_0, c_L2_c9_0;
    full_adder FA_s_L2_c9_0 (.a(c_L1_c8_0), .b(c_L1_c8_1), .cin(s_L1_c9_0), .sum(s_L2_c9_0), .cout(c_L2_c9_0));
    wire s_L2_c10_0, c_L2_c10_0;
    full_adder FA_s_L2_c10_0 (.a(c_L1_c9_0), .b(c_L1_c9_1), .cin(s_L1_c10_0), .sum(s_L2_c10_0), .cout(c_L2_c10_0));
    wire s_L2_c11_0, c_L2_c11_0;
    full_adder FA_s_L2_c11_0 (.a(c_L1_c10_0), .b(s_L1_c11_0), .cin(pp_7_4), .sum(s_L2_c11_0), .cout(c_L2_c11_0));
    wire s_L2_c13_0, c_L2_c13_0;
    full_adder FA_s_L2_c13_0 (.a(c_L1_c12_0), .b(pp_6_7), .cin(pp_7_6), .sum(s_L2_c13_0), .cout(c_L2_c13_0));
    // Layer 3
    wire s_L3_c4_0, c_L3_c4_0;
    full_adder FA_s_L3_c4_0 (.a(c_L2_c3_0), .b(s_L2_c4_0), .cin(pp_4_0), .sum(s_L3_c4_0), .cout(c_L3_c4_0));
    wire s_L3_c6_0, c_L3_c6_0;
    full_adder FA_s_L3_c6_0 (.a(c_L2_c5_0), .b(s_L2_c6_0), .cin(s_L1_c6_1), .sum(s_L3_c6_0), .cout(c_L3_c6_0));
    wire s_L3_c7_0, c_L3_c7_0;
    full_adder FA_s_L3_c7_0 (.a(c_L2_c6_0), .b(s_L2_c7_0), .cin(s_L2_c7_1), .sum(s_L3_c7_0), .cout(c_L3_c7_0));
    wire s_L3_c8_0, c_L3_c8_0;
    full_adder FA_s_L3_c8_0 (.a(c_L2_c7_0), .b(c_L2_c7_1), .cin(s_L2_c8_0), .sum(s_L3_c8_0), .cout(c_L3_c8_0));
    wire s_L3_c9_0, c_L3_c9_0;
    full_adder FA_s_L3_c9_0 (.a(c_L2_c8_0), .b(s_L2_c9_0), .cin(s_L1_c9_1), .sum(s_L3_c9_0), .cout(c_L3_c9_0));
    wire s_L3_c10_0, c_L3_c10_0;
    full_adder FA_s_L3_c10_0 (.a(c_L2_c9_0), .b(s_L2_c10_0), .cin(pp_6_4), .sum(s_L3_c10_0), .cout(c_L3_c10_0));
    wire s_L3_c12_0, c_L3_c12_0;
    full_adder FA_s_L3_c12_0 (.a(c_L2_c11_0), .b(c_L1_c11_0), .cin(s_L1_c12_0), .sum(s_L3_c12_0), .cout(c_L3_c12_0));
    // Layer 4
    wire s_L4_c5_0, c_L4_c5_0;
    full_adder FA_s_L4_c5_0 (.a(c_L3_c4_0), .b(c_L2_c4_0), .cin(s_L2_c5_0), .sum(s_L4_c5_0), .cout(c_L4_c5_0));
    wire s_L4_c8_0, c_L4_c8_0;
    full_adder FA_s_L4_c8_0 (.a(c_L3_c7_0), .b(s_L3_c8_0), .cin(s_L1_c8_1), .sum(s_L4_c8_0), .cout(c_L4_c8_0));
    wire s_L4_c10_0, c_L4_c10_0;
    full_adder FA_s_L4_c10_0 (.a(c_L3_c9_0), .b(s_L3_c10_0), .cin(pp_7_3), .sum(s_L4_c10_0), .cout(c_L4_c10_0));
    wire s_L4_c11_0, c_L4_c11_0;
    full_adder FA_s_L4_c11_0 (.a(c_L3_c10_0), .b(c_L2_c10_0), .cin(s_L2_c11_0), .sum(s_L4_c11_0), .cout(c_L4_c11_0));
    // Layer 5
    wire s_L5_c6_0, c_L5_c6_0;
    full_adder FA_s_L5_c6_0 (.a(c_L4_c5_0), .b(s_L3_c6_0), .cin(pp_6_0), .sum(s_L5_c6_0), .cout(c_L5_c6_0));
    wire s_L5_c9_0, c_L5_c9_0;
    full_adder FA_s_L5_c9_0 (.a(c_L4_c8_0), .b(c_L3_c8_0), .cin(s_L3_c9_0), .sum(s_L5_c9_0), .cout(c_L5_c9_0));
    // Layer 6
    wire s_L6_c7_0, c_L6_c7_0;
    full_adder FA_s_L6_c7_0 (.a(c_L5_c6_0), .b(c_L3_c6_0), .cin(s_L3_c7_0), .sum(s_L6_c7_0), .cout(c_L6_c7_0));
    // Layer 7
    wire s_L7_c8_0, c_L7_c8_0;
    full_adder FA_s_L7_c8_0 (.a(c_L6_c7_0), .b(s_L4_c8_0), .cin(pp_7_1), .sum(s_L7_c8_0), .cout(c_L7_c8_0));

    // ---- Final two rows (each column now height <= 2) ----
    wire [14:0] row0 = {c_L2_c13_0, c_L3_c12_0, c_L4_c11_0, c_L4_c10_0, c_L5_c9_0, c_L7_c8_0, s_L7_c8_0, s_L6_c7_0, s_L5_c6_0, s_L4_c5_0, s_L3_c4_0, s_L2_c3_0, s_L1_c2_0, pp_0_1, pp_0_0};
    wire [14:0] row1 = {pp_7_7, s_L2_c13_0, s_L3_c12_0, s_L4_c11_0, s_L4_c10_0, s_L5_c9_0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, pp_1_0, 1'b0};

    // ---- Final merge (plain add; see note above) ----
    assign P = {{1{1'b0}}, row0} + {{1{1'b0}}, row1};

endmodule