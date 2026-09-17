`timescale 1ns/1ps

module systolic4x4 (
    input wire clk,
    input wire reset,
    input wire enable,

//    input wire [7:0] A [0:3][0:3],
//    input wire [7:0] B [0:3][0:3],

    input wire [127:0] A,
    input wire [127:0] B,

    output wire [31:0] C00, C01, C02, C03,
    output wire [31:0] C10, C11, C12, C13,
    output wire [31:0] C20, C21, C22, C23,
    output wire [31:0] C30, C31, C32, C33
);

// =========================================================
    // Unpack flattened input buses into matrix elements
    // =========================================================

    wire [7:0] A_matrix [0:3][0:3];
    wire [7:0] B_matrix [0:3][0:3];

    assign A_matrix[0][0] = A[7:0];
    assign A_matrix[0][1] = A[15:8];
    assign A_matrix[0][2] = A[23:16];
    assign A_matrix[0][3] = A[31:24];

    assign A_matrix[1][0] = A[39:32];
    assign A_matrix[1][1] = A[47:40];
    assign A_matrix[1][2] = A[55:48];
    assign A_matrix[1][3] = A[63:56];

    assign A_matrix[2][0] = A[71:64];
    assign A_matrix[2][1] = A[79:72];
    assign A_matrix[2][2] = A[87:80];
    assign A_matrix[2][3] = A[95:88];

    assign A_matrix[3][0] = A[103:96];
    assign A_matrix[3][1] = A[111:104];
    assign A_matrix[3][2] = A[119:112];
    assign A_matrix[3][3] = A[127:120];

    assign B_matrix[0][0] = B[7:0];
    assign B_matrix[0][1] = B[15:8];
    assign B_matrix[0][2] = B[23:16];
    assign B_matrix[0][3] = B[31:24];

    assign B_matrix[1][0] = B[39:32];
    assign B_matrix[1][1] = B[47:40];
    assign B_matrix[1][2] = B[55:48];
    assign B_matrix[1][3] = B[63:56];

    assign B_matrix[2][0] = B[71:64];
    assign B_matrix[2][1] = B[79:72];
    assign B_matrix[2][2] = B[87:80];
    assign B_matrix[2][3] = B[95:88];

    assign B_matrix[3][0] = B[103:96];
    assign B_matrix[3][1] = B[111:104];
    assign B_matrix[3][2] = B[119:112];
    assign B_matrix[3][3] = B[127:120];

    // =========================================================
    // Internal systolic data paths
    //
    // A moves ---> across each row
    // B moves | down each column
    // =========================================================

    wire [7:0] A_wire [0:3][0:4];
    wire [7:0] B_wire [0:4][0:3];

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

    reg [7:0] A_feed [0:3];
    reg [7:0] B_feed [0:3];

    always @* begin

        // Default values
        A_feed[0] = 8'd0;
        A_feed[1] = 8'd0;
        A_feed[2] = 8'd0;
        A_feed[3] = 8'd0;

        B_feed[0] = 8'd0;
        B_feed[1] = 8'd0;
        B_feed[2] = 8'd0;
        B_feed[3] = 8'd0;

        // =====================================================
        // A streams
        // =====================================================

        if (cycle >= 0 && cycle < 4)
            A_feed[0] = A_matrix[0][cycle];

        if (cycle >= 1 && cycle < 5)
            A_feed[1] = A_matrix[1][cycle-1];

        if (cycle >= 2 && cycle < 6)
            A_feed[2] = A_matrix[2][cycle-2];

        if (cycle >= 3 && cycle < 7)
            A_feed[3] = A_matrix[3][cycle-3];

        // =====================================================
        // B streams
        // =====================================================

        if (cycle >= 0 && cycle < 4)
            B_feed[0] = B_matrix[cycle][0];

        if (cycle >= 1 && cycle < 5)
            B_feed[1] = B_matrix[cycle-1][1];

        if (cycle >= 2 && cycle < 6)
            B_feed[2] = B_matrix[cycle-2][2];

        if (cycle >= 3 && cycle < 7)
            B_feed[3] = B_matrix[cycle-3][3];

    end

    // =========================================================
    // Inject A into first column
    // =========================================================

    assign A_wire[0][0] = A_feed[0];
    assign A_wire[1][0] = A_feed[1];
    assign A_wire[2][0] = A_feed[2];
    assign A_wire[3][0] = A_feed[3];

    // =========================================================
    // Inject B into first row
    // =========================================================

    assign B_wire[0][0] = B_feed[0];
    assign B_wire[0][1] = B_feed[1];
    assign B_wire[0][2] = B_feed[2];
    assign B_wire[0][3] = B_feed[3];

    // =========================================================
    // ROW 0
    // =========================================================

    pe pe00 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[0][0]),
        .B_in(B_wire[0][0]),
        .A_out(A_wire[0][1]),
        .B_out(B_wire[1][0]),
        .acc_out(C00)
    );

    pe pe01 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[0][1]),
        .B_in(B_wire[0][1]),
        .A_out(A_wire[0][2]),
        .B_out(B_wire[1][1]),
        .acc_out(C01)
    );

    pe pe02 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[0][2]),
        .B_in(B_wire[0][2]),
        .A_out(A_wire[0][3]),
        .B_out(B_wire[1][2]),
        .acc_out(C02)
    );

    pe pe03 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[0][3]),
        .B_in(B_wire[0][3]),
        .A_out(A_wire[0][4]),
        .B_out(B_wire[1][3]),
        .acc_out(C03)
    );

    // =========================================================
    // ROW 1
    // =========================================================

    pe pe10 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[1][0]),
        .B_in(B_wire[1][0]),
        .A_out(A_wire[1][1]),
        .B_out(B_wire[2][0]),
        .acc_out(C10)
    );

    pe pe11 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[1][1]),
        .B_in(B_wire[1][1]),
        .A_out(A_wire[1][2]),
        .B_out(B_wire[2][1]),
        .acc_out(C11)
    );

    pe pe12 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[1][2]),
        .B_in(B_wire[1][2]),
        .A_out(A_wire[1][3]),
        .B_out(B_wire[2][2]),
        .acc_out(C12)
    );

    pe pe13 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[1][3]),
        .B_in(B_wire[1][3]),
        .A_out(A_wire[1][4]),
        .B_out(B_wire[2][3]),
        .acc_out(C13)
    );

    // =========================================================
    // ROW 2
    // =========================================================

    pe pe20 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[2][0]),
        .B_in(B_wire[2][0]),
        .A_out(A_wire[2][1]),
        .B_out(B_wire[3][0]),
        .acc_out(C20)
    );

    pe pe21 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[2][1]),
        .B_in(B_wire[2][1]),
        .A_out(A_wire[2][2]),
        .B_out(B_wire[3][1]),
        .acc_out(C21)
    );

    pe pe22 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[2][2]),
        .B_in(B_wire[2][2]),
        .A_out(A_wire[2][3]),
        .B_out(B_wire[3][2]),
        .acc_out(C22)
    );

    pe pe23 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[2][3]),
        .B_in(B_wire[2][3]),
        .A_out(A_wire[2][4]),
        .B_out(B_wire[3][3]),
        .acc_out(C23)
    );

    // =========================================================
    // ROW 3
    // =========================================================

    pe pe30 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[3][0]),
        .B_in(B_wire[3][0]),
        .A_out(A_wire[3][1]),
        .B_out(B_wire[4][0]),
        .acc_out(C30)
    );

    pe pe31 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[3][1]),
        .B_in(B_wire[3][1]),
        .A_out(A_wire[3][2]),
        .B_out(B_wire[4][1]),
        .acc_out(C31)
    );

    pe pe32 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[3][2]),
        .B_in(B_wire[3][2]),
        .A_out(A_wire[3][3]),
        .B_out(B_wire[4][2]),
        .acc_out(C32)
    );

    pe pe33 (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_wire[3][3]),
        .B_in(B_wire[3][3]),
        .A_out(A_wire[3][4]),
        .B_out(B_wire[4][3]),
        .acc_out(C33)
    );

endmodule