`timescale 1ns/1ps

module systolic8x8 (
    input wire clk,
    input wire reset,
    input wire enable,

    input wire [511:0] A,
    input wire [511:0] B,

    output wire [31:0] C00, C01, C02, C03, C04, C05, C06, C07,
    output wire [31:0] C10, C11, C12, C13, C14, C15, C16, C17,
    output wire [31:0] C20, C21, C22, C23, C24, C25, C26, C27,
    output wire [31:0] C30, C31, C32, C33, C34, C35, C36, C37,
    output wire [31:0] C40, C41, C42, C43, C44, C45, C46, C47,
    output wire [31:0] C50, C51, C52, C53, C54, C55, C56, C57,
    output wire [31:0] C60, C61, C62, C63, C64, C65, C66, C67,
    output wire [31:0] C70, C71, C72, C73, C74, C75, C76, C77
);

    // =========================================================
    // Unpack flattened input buses into matrix elements
    // =========================================================

    wire [7:0] A_matrix [0:7][0:7];
    wire [7:0] B_matrix [0:7][0:7];

    // Row 0
    assign A_matrix[0][0] = A[7:0];
    assign A_matrix[0][1] = A[15:8];
    assign A_matrix[0][2] = A[23:16];
    assign A_matrix[0][3] = A[31:24];
    assign A_matrix[0][4] = A[39:32];
    assign A_matrix[0][5] = A[47:40];
    assign A_matrix[0][6] = A[55:48];
    assign A_matrix[0][7] = A[63:56];

    // Row 1
    assign A_matrix[1][0] = A[71:64];
    assign A_matrix[1][1] = A[79:72];
    assign A_matrix[1][2] = A[87:80];
    assign A_matrix[1][3] = A[95:88];
    assign A_matrix[1][4] = A[103:96];
    assign A_matrix[1][5] = A[111:104];
    assign A_matrix[1][6] = A[119:112];
    assign A_matrix[1][7] = A[127:120];

    // Row 2
    assign A_matrix[2][0] = A[135:128];
    assign A_matrix[2][1] = A[143:136];
    assign A_matrix[2][2] = A[151:144];
    assign A_matrix[2][3] = A[159:152];
    assign A_matrix[2][4] = A[167:160];
    assign A_matrix[2][5] = A[175:168];
    assign A_matrix[2][6] = A[183:176];
    assign A_matrix[2][7] = A[191:184];

    // Row 3
    assign A_matrix[3][0] = A[199:192];
    assign A_matrix[3][1] = A[207:200];
    assign A_matrix[3][2] = A[215:208];
    assign A_matrix[3][3] = A[223:216];
    assign A_matrix[3][4] = A[231:224];
    assign A_matrix[3][5] = A[239:232];
    assign A_matrix[3][6] = A[247:240];
    assign A_matrix[3][7] = A[255:248];

    // Row 4
    assign A_matrix[4][0] = A[263:256];
    assign A_matrix[4][1] = A[271:264];
    assign A_matrix[4][2] = A[279:272];
    assign A_matrix[4][3] = A[287:280];
    assign A_matrix[4][4] = A[295:288];
    assign A_matrix[4][5] = A[303:296];
    assign A_matrix[4][6] = A[311:304];
    assign A_matrix[4][7] = A[319:312];

    // Row 5
    assign A_matrix[5][0] = A[327:320];
    assign A_matrix[5][1] = A[335:328];
    assign A_matrix[5][2] = A[343:336];
    assign A_matrix[5][3] = A[351:344];
    assign A_matrix[5][4] = A[359:352];
    assign A_matrix[5][5] = A[367:360];
    assign A_matrix[5][6] = A[375:368];
    assign A_matrix[5][7] = A[383:376];

    // Row 6
    assign A_matrix[6][0] = A[391:384];
    assign A_matrix[6][1] = A[399:392];
    assign A_matrix[6][2] = A[407:400];
    assign A_matrix[6][3] = A[415:408];
    assign A_matrix[6][4] = A[423:416];
    assign A_matrix[6][5] = A[431:424];
    assign A_matrix[6][6] = A[439:432];
    assign A_matrix[6][7] = A[447:440];

    // Row 7
    assign A_matrix[7][0] = A[455:448];
    assign A_matrix[7][1] = A[463:456];
    assign A_matrix[7][2] = A[471:464];
    assign A_matrix[7][3] = A[479:472];
    assign A_matrix[7][4] = A[487:480];
    assign A_matrix[7][5] = A[495:488];
    assign A_matrix[7][6] = A[503:496];
    assign A_matrix[7][7] = A[511:504];

    // B matrix unpacking
    // Row 0
    assign B_matrix[0][0] = B[7:0];
    assign B_matrix[0][1] = B[15:8];
    assign B_matrix[0][2] = B[23:16];
    assign B_matrix[0][3] = B[31:24];
    assign B_matrix[0][4] = B[39:32];
    assign B_matrix[0][5] = B[47:40];
    assign B_matrix[0][6] = B[55:48];
    assign B_matrix[0][7] = B[63:56];

    // Row 1
    assign B_matrix[1][0] = B[71:64];
    assign B_matrix[1][1] = B[79:72];
    assign B_matrix[1][2] = B[87:80];
    assign B_matrix[1][3] = B[95:88];
    assign B_matrix[1][4] = B[103:96];
    assign B_matrix[1][5] = B[111:104];
    assign B_matrix[1][6] = B[119:112];
    assign B_matrix[1][7] = B[127:120];

    // Row 2
    assign B_matrix[2][0] = B[135:128];
    assign B_matrix[2][1] = B[143:136];
    assign B_matrix[2][2] = B[151:144];
    assign B_matrix[2][3] = B[159:152];
    assign B_matrix[2][4] = B[167:160];
    assign B_matrix[2][5] = B[175:168];
    assign B_matrix[2][6] = B[183:176];
    assign B_matrix[2][7] = B[191:184];

    // Row 3
    assign B_matrix[3][0] = B[199:192];
    assign B_matrix[3][1] = B[207:200];
    assign B_matrix[3][2] = B[215:208];
    assign B_matrix[3][3] = B[223:216];
    assign B_matrix[3][4] = B[231:224];
    assign B_matrix[3][5] = B[239:232];
    assign B_matrix[3][6] = B[247:240];
    assign B_matrix[3][7] = B[255:248];

    // Row 4
    assign B_matrix[4][0] = B[263:256];
    assign B_matrix[4][1] = B[271:264];
    assign B_matrix[4][2] = B[279:272];
    assign B_matrix[4][3] = B[287:280];
    assign B_matrix[4][4] = B[295:288];
    assign B_matrix[4][5] = B[303:296];
    assign B_matrix[4][6] = B[311:304];
    assign B_matrix[4][7] = B[319:312];

    // Row 5
    assign B_matrix[5][0] = B[327:320];
    assign B_matrix[5][1] = B[335:328];
    assign B_matrix[5][2] = B[343:336];
    assign B_matrix[5][3] = B[351:344];
    assign B_matrix[5][4] = B[359:352];
    assign B_matrix[5][5] = B[367:360];
    assign B_matrix[5][6] = B[375:368];
    assign B_matrix[5][7] = B[383:376];

    // Row 6
    assign B_matrix[6][0] = B[391:384];
    assign B_matrix[6][1] = B[399:392];
    assign B_matrix[6][2] = B[407:400];
    assign B_matrix[6][3] = B[415:408];
    assign B_matrix[6][4] = B[423:416];
    assign B_matrix[6][5] = B[431:424];
    assign B_matrix[6][6] = B[439:432];
    assign B_matrix[6][7] = B[447:440];

    // Row 7
    assign B_matrix[7][0] = B[455:448];
    assign B_matrix[7][1] = B[463:456];
    assign B_matrix[7][2] = B[471:464];
    assign B_matrix[7][3] = B[479:472];
    assign B_matrix[7][4] = B[487:480];
    assign B_matrix[7][5] = B[495:488];
    assign B_matrix[7][6] = B[503:496];
    assign B_matrix[7][7] = B[511:504];

    // =========================================================
    // Internal systolic data paths
    //
    // A moves ---> across each row
    // B moves | down each column
    // =========================================================

    wire [7:0] A_wire [0:7][0:8];
    wire [7:0] B_wire [0:8][0:7];

    // =========================================================
    // Cycle counter
    //
    // The inputs are skewed so that:
    //
    // A[i][k] and B[k][j]
    //
    // meet at PE(i,j) at the same cycle.
    // =========================================================

    integer cycle;

    always @(posedge clk) begin
        if (reset)
            cycle <= 0;
        else if (enable)
            cycle <= cycle + 1;
    end

    // =========================================================
    // Input feed registers
    // =========================================================

    reg [7:0] A_feed [0:7];
    reg [7:0] B_feed [0:7];

    always @* begin

        // Default values
        A_feed[0] = 8'd0;
        A_feed[1] = 8'd0;
        A_feed[2] = 8'd0;
        A_feed[3] = 8'd0;
        A_feed[4] = 8'd0;
        A_feed[5] = 8'd0;
        A_feed[6] = 8'd0;
        A_feed[7] = 8'd0;

        B_feed[0] = 8'd0;
        B_feed[1] = 8'd0;
        B_feed[2] = 8'd0;
        B_feed[3] = 8'd0;
        B_feed[4] = 8'd0;
        B_feed[5] = 8'd0;
        B_feed[6] = 8'd0;
        B_feed[7] = 8'd0;

        // =====================================================
        // A streams (skewed by row index)
        // =====================================================

        if (cycle >= 0 && cycle < 8)
            A_feed[0] = A_matrix[0][cycle];

        if (cycle >= 1 && cycle < 9)
            A_feed[1] = A_matrix[1][cycle-1];

        if (cycle >= 2 && cycle < 10)
            A_feed[2] = A_matrix[2][cycle-2];

        if (cycle >= 3 && cycle < 11)
            A_feed[3] = A_matrix[3][cycle-3];

        if (cycle >= 4 && cycle < 12)
            A_feed[4] = A_matrix[4][cycle-4];

        if (cycle >= 5 && cycle < 13)
            A_feed[5] = A_matrix[5][cycle-5];

        if (cycle >= 6 && cycle < 14)
            A_feed[6] = A_matrix[6][cycle-6];

        if (cycle >= 7 && cycle < 15)
            A_feed[7] = A_matrix[7][cycle-7];

        // =====================================================
        // B streams (skewed by column index)
        // =====================================================

        if (cycle >= 0 && cycle < 8)
            B_feed[0] = B_matrix[cycle][0];

        if (cycle >= 1 && cycle < 9)
            B_feed[1] = B_matrix[cycle-1][1];

        if (cycle >= 2 && cycle < 10)
            B_feed[2] = B_matrix[cycle-2][2];

        if (cycle >= 3 && cycle < 11)
            B_feed[3] = B_matrix[cycle-3][3];

        if (cycle >= 4 && cycle < 12)
            B_feed[4] = B_matrix[cycle-4][4];

        if (cycle >= 5 && cycle < 13)
            B_feed[5] = B_matrix[cycle-5][5];

        if (cycle >= 6 && cycle < 14)
            B_feed[6] = B_matrix[cycle-6][6];

        if (cycle >= 7 && cycle < 15)
            B_feed[7] = B_matrix[cycle-7][7];

    end

    // =========================================================
    // Inject A into first column
    // =========================================================

    assign A_wire[0][0] = A_feed[0];
    assign A_wire[1][0] = A_feed[1];
    assign A_wire[2][0] = A_feed[2];
    assign A_wire[3][0] = A_feed[3];
    assign A_wire[4][0] = A_feed[4];
    assign A_wire[5][0] = A_feed[5];
    assign A_wire[6][0] = A_feed[6];
    assign A_wire[7][0] = A_feed[7];

    // =========================================================
    // Inject B into first row
    // =========================================================

    assign B_wire[0][0] = B_feed[0];
    assign B_wire[0][1] = B_feed[1];
    assign B_wire[0][2] = B_feed[2];
    assign B_wire[0][3] = B_feed[3];
    assign B_wire[0][4] = B_feed[4];
    assign B_wire[0][5] = B_feed[5];
    assign B_wire[0][6] = B_feed[6];
    assign B_wire[0][7] = B_feed[7];

    // =========================================================
    // ROW 0
    // =========================================================

    pe pe00 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[0][0]), .B_in(B_wire[0][0]),
        .A_out(A_wire[0][1]), .B_out(B_wire[1][0]),
        .acc_out(C00)
    );

    pe pe01 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[0][1]), .B_in(B_wire[0][1]),
        .A_out(A_wire[0][2]), .B_out(B_wire[1][1]),
        .acc_out(C01)
    );

    pe pe02 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[0][2]), .B_in(B_wire[0][2]),
        .A_out(A_wire[0][3]), .B_out(B_wire[1][2]),
        .acc_out(C02)
    );

    pe pe03 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[0][3]), .B_in(B_wire[0][3]),
        .A_out(A_wire[0][4]), .B_out(B_wire[1][3]),
        .acc_out(C03)
    );

    pe pe04 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[0][4]), .B_in(B_wire[0][4]),
        .A_out(A_wire[0][5]), .B_out(B_wire[1][4]),
        .acc_out(C04)
    );

    pe pe05 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[0][5]), .B_in(B_wire[0][5]),
        .A_out(A_wire[0][6]), .B_out(B_wire[1][5]),
        .acc_out(C05)
    );

    pe pe06 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[0][6]), .B_in(B_wire[0][6]),
        .A_out(A_wire[0][7]), .B_out(B_wire[1][6]),
        .acc_out(C06)
    );

    pe pe07 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[0][7]), .B_in(B_wire[0][7]),
        .A_out(A_wire[0][8]), .B_out(B_wire[1][7]),
        .acc_out(C07)
    );

    // =========================================================
    // ROW 1
    // =========================================================

    pe pe10 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[1][0]), .B_in(B_wire[1][0]),
        .A_out(A_wire[1][1]), .B_out(B_wire[2][0]),
        .acc_out(C10)
    );

    pe pe11 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[1][1]), .B_in(B_wire[1][1]),
        .A_out(A_wire[1][2]), .B_out(B_wire[2][1]),
        .acc_out(C11)
    );

    pe pe12 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[1][2]), .B_in(B_wire[1][2]),
        .A_out(A_wire[1][3]), .B_out(B_wire[2][2]),
        .acc_out(C12)
    );

    pe pe13 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[1][3]), .B_in(B_wire[1][3]),
        .A_out(A_wire[1][4]), .B_out(B_wire[2][3]),
        .acc_out(C13)
    );

    pe pe14 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[1][4]), .B_in(B_wire[1][4]),
        .A_out(A_wire[1][5]), .B_out(B_wire[2][4]),
        .acc_out(C14)
    );

    pe pe15 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[1][5]), .B_in(B_wire[1][5]),
        .A_out(A_wire[1][6]), .B_out(B_wire[2][5]),
        .acc_out(C15)
    );

    pe pe16 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[1][6]), .B_in(B_wire[1][6]),
        .A_out(A_wire[1][7]), .B_out(B_wire[2][6]),
        .acc_out(C16)
    );

    pe pe17 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[1][7]), .B_in(B_wire[1][7]),
        .A_out(A_wire[1][8]), .B_out(B_wire[2][7]),
        .acc_out(C17)
    );

    // =========================================================
    // ROW 2
    // =========================================================

    pe pe20 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[2][0]), .B_in(B_wire[2][0]),
        .A_out(A_wire[2][1]), .B_out(B_wire[3][0]),
        .acc_out(C20)
    );

    pe pe21 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[2][1]), .B_in(B_wire[2][1]),
        .A_out(A_wire[2][2]), .B_out(B_wire[3][1]),
        .acc_out(C21)
    );

    pe pe22 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[2][2]), .B_in(B_wire[2][2]),
        .A_out(A_wire[2][3]), .B_out(B_wire[3][2]),
        .acc_out(C22)
    );

    pe pe23 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[2][3]), .B_in(B_wire[2][3]),
        .A_out(A_wire[2][4]), .B_out(B_wire[3][3]),
        .acc_out(C23)
    );

    pe pe24 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[2][4]), .B_in(B_wire[2][4]),
        .A_out(A_wire[2][5]), .B_out(B_wire[3][4]),
        .acc_out(C24)
    );

    pe pe25 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[2][5]), .B_in(B_wire[2][5]),
        .A_out(A_wire[2][6]), .B_out(B_wire[3][5]),
        .acc_out(C25)
    );

    pe pe26 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[2][6]), .B_in(B_wire[2][6]),
        .A_out(A_wire[2][7]), .B_out(B_wire[3][6]),
        .acc_out(C26)
    );

    pe pe27 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[2][7]), .B_in(B_wire[2][7]),
        .A_out(A_wire[2][8]), .B_out(B_wire[3][7]),
        .acc_out(C27)
    );

    // =========================================================
    // ROW 3
    // =========================================================

    pe pe30 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[3][0]), .B_in(B_wire[3][0]),
        .A_out(A_wire[3][1]), .B_out(B_wire[4][0]),
        .acc_out(C30)
    );

    pe pe31 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[3][1]), .B_in(B_wire[3][1]),
        .A_out(A_wire[3][2]), .B_out(B_wire[4][1]),
        .acc_out(C31)
    );

    pe pe32 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[3][2]), .B_in(B_wire[3][2]),
        .A_out(A_wire[3][3]), .B_out(B_wire[4][2]),
        .acc_out(C32)
    );

    pe pe33 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[3][3]), .B_in(B_wire[3][3]),
        .A_out(A_wire[3][4]), .B_out(B_wire[4][3]),
        .acc_out(C33)
    );

    pe pe34 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[3][4]), .B_in(B_wire[3][4]),
        .A_out(A_wire[3][5]), .B_out(B_wire[4][4]),
        .acc_out(C34)
    );

    pe pe35 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[3][5]), .B_in(B_wire[3][5]),
        .A_out(A_wire[3][6]), .B_out(B_wire[4][5]),
        .acc_out(C35)
    );

    pe pe36 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[3][6]), .B_in(B_wire[3][6]),
        .A_out(A_wire[3][7]), .B_out(B_wire[4][6]),
        .acc_out(C36)
    );

    pe pe37 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[3][7]), .B_in(B_wire[3][7]),
        .A_out(A_wire[3][8]), .B_out(B_wire[4][7]),
        .acc_out(C37)
    );

    // =========================================================
    // ROW 4
    // =========================================================

    pe pe40 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[4][0]), .B_in(B_wire[4][0]),
        .A_out(A_wire[4][1]), .B_out(B_wire[5][0]),
        .acc_out(C40)
    );

    pe pe41 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[4][1]), .B_in(B_wire[4][1]),
        .A_out(A_wire[4][2]), .B_out(B_wire[5][1]),
        .acc_out(C41)
    );

    pe pe42 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[4][2]), .B_in(B_wire[4][2]),
        .A_out(A_wire[4][3]), .B_out(B_wire[5][2]),
        .acc_out(C42)
    );

    pe pe43 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[4][3]), .B_in(B_wire[4][3]),
        .A_out(A_wire[4][4]), .B_out(B_wire[5][3]),
        .acc_out(C43)
    );

    pe pe44 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[4][4]), .B_in(B_wire[4][4]),
        .A_out(A_wire[4][5]), .B_out(B_wire[5][4]),
        .acc_out(C44)
    );

    pe pe45 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[4][5]), .B_in(B_wire[4][5]),
        .A_out(A_wire[4][6]), .B_out(B_wire[5][5]),
        .acc_out(C45)
    );

    pe pe46 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[4][6]), .B_in(B_wire[4][6]),
        .A_out(A_wire[4][7]), .B_out(B_wire[5][6]),
        .acc_out(C46)
    );

    pe pe47 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[4][7]), .B_in(B_wire[4][7]),
        .A_out(A_wire[4][8]), .B_out(B_wire[5][7]),
        .acc_out(C47)
    );

    // =========================================================
    // ROW 5
    // =========================================================

    pe pe50 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[5][0]), .B_in(B_wire[5][0]),
        .A_out(A_wire[5][1]), .B_out(B_wire[6][0]),
        .acc_out(C50)
    );

    pe pe51 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[5][1]), .B_in(B_wire[5][1]),
        .A_out(A_wire[5][2]), .B_out(B_wire[6][1]),
        .acc_out(C51)
    );

    pe pe52 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[5][2]), .B_in(B_wire[5][2]),
        .A_out(A_wire[5][3]), .B_out(B_wire[6][2]),
        .acc_out(C52)
    );

    pe pe53 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[5][3]), .B_in(B_wire[5][3]),
        .A_out(A_wire[5][4]), .B_out(B_wire[6][3]),
        .acc_out(C53)
    );

    pe pe54 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[5][4]), .B_in(B_wire[5][4]),
        .A_out(A_wire[5][5]), .B_out(B_wire[6][4]),
        .acc_out(C54)
    );

    pe pe55 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[5][5]), .B_in(B_wire[5][5]),
        .A_out(A_wire[5][6]), .B_out(B_wire[6][5]),
        .acc_out(C55)
    );

    pe pe56 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[5][6]), .B_in(B_wire[5][6]),
        .A_out(A_wire[5][7]), .B_out(B_wire[6][6]),
        .acc_out(C56)
    );

    pe pe57 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[5][7]), .B_in(B_wire[5][7]),
        .A_out(A_wire[5][8]), .B_out(B_wire[6][7]),
        .acc_out(C57)
    );

    // =========================================================
    // ROW 6
    // =========================================================

    pe pe60 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[6][0]), .B_in(B_wire[6][0]),
        .A_out(A_wire[6][1]), .B_out(B_wire[7][0]),
        .acc_out(C60)
    );

    pe pe61 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[6][1]), .B_in(B_wire[6][1]),
        .A_out(A_wire[6][2]), .B_out(B_wire[7][1]),
        .acc_out(C61)
    );

    pe pe62 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[6][2]), .B_in(B_wire[6][2]),
        .A_out(A_wire[6][3]), .B_out(B_wire[7][2]),
        .acc_out(C62)
    );

    pe pe63 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[6][3]), .B_in(B_wire[6][3]),
        .A_out(A_wire[6][4]), .B_out(B_wire[7][3]),
        .acc_out(C63)
    );

    pe pe64 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[6][4]), .B_in(B_wire[6][4]),
        .A_out(A_wire[6][5]), .B_out(B_wire[7][4]),
        .acc_out(C64)
    );

    pe pe65 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[6][5]), .B_in(B_wire[6][5]),
        .A_out(A_wire[6][6]), .B_out(B_wire[7][5]),
        .acc_out(C65)
    );

    pe pe66 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[6][6]), .B_in(B_wire[6][6]),
        .A_out(A_wire[6][7]), .B_out(B_wire[7][6]),
        .acc_out(C66)
    );

    pe pe67 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[6][7]), .B_in(B_wire[6][7]),
        .A_out(A_wire[6][8]), .B_out(B_wire[7][7]),
        .acc_out(C67)
    );

    // =========================================================
    // ROW 7
    // =========================================================

    pe pe70 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[7][0]), .B_in(B_wire[7][0]),
        .A_out(A_wire[7][1]), .B_out(B_wire[8][0]),
        .acc_out(C70)
    );

    pe pe71 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[7][1]), .B_in(B_wire[7][1]),
        .A_out(A_wire[7][2]), .B_out(B_wire[8][1]),
        .acc_out(C71)
    );

    pe pe72 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[7][2]), .B_in(B_wire[7][2]),
        .A_out(A_wire[7][3]), .B_out(B_wire[8][2]),
        .acc_out(C72)
    );

    pe pe73 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[7][3]), .B_in(B_wire[7][3]),
        .A_out(A_wire[7][4]), .B_out(B_wire[8][3]),
        .acc_out(C73)
    );

    pe pe74 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[7][4]), .B_in(B_wire[7][4]),
        .A_out(A_wire[7][5]), .B_out(B_wire[8][4]),
        .acc_out(C74)
    );

    pe pe75 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[7][5]), .B_in(B_wire[7][5]),
        .A_out(A_wire[7][6]), .B_out(B_wire[8][5]),
        .acc_out(C75)
    );

    pe pe76 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[7][6]), .B_in(B_wire[7][6]),
        .A_out(A_wire[7][7]), .B_out(B_wire[8][6]),
        .acc_out(C76)
    );

    pe pe77 (
        .clk(clk), .reset(reset), .enable(enable),
        .A_in(A_wire[7][7]), .B_in(B_wire[7][7]),
        .A_out(A_wire[7][8]), .B_out(B_wire[8][7]),
        .acc_out(C77)
    );

endmodule