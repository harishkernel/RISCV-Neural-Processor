`timescale 1ns/1ps

module systolic4x4_tb;

    reg clk;
    reg reset;
    reg enable;

    // =========================================================
    // Flattened 4x4 matrix inputs
    //
    // 16 elements × 8 bits = 128 bits
    // =========================================================

    reg [127:0] A;
    reg [127:0] B;

    wire [31:0] C00, C01, C02, C03;
    wire [31:0] C10, C11, C12, C13;
    wire [31:0] C20, C21, C22, C23;
    wire [31:0] C30, C31, C32, C33;

    integer errors = 0;

    // =========================================================
    // DUT
    // =========================================================

    systolic4x4 uut (
        .clk(clk),
        .reset(reset),
        .enable(enable),

        .A(A),
        .B(B),

        .C00(C00), .C01(C01), .C02(C02), .C03(C03),
        .C10(C10), .C11(C11), .C12(C12), .C13(C13),
        .C20(C20), .C21(C21), .C22(C22), .C23(C23),
        .C30(C30), .C31(C31), .C32(C32), .C33(C33)
    );

    // =========================================================
    // Clock
    // =========================================================

    always #5 clk = ~clk;

    // =========================================================
    // Test
    // =========================================================

    initial begin

        // VCD output
        $dumpfile("arithmetic/systolic/systolic4x4.vcd");
        $dumpvars(0, systolic4x4_tb);

        clk = 0;
        reset = 1;
        enable = 0;

        // =====================================================
        // MATRIX A
        //
        // A =
        //
        //  1   2   3   4
        //  5   6   7   8
        //  9  10  11  12
        // 13  14  15  16
        //
        // Packed as:
        //
        // A[7:0]       = A00
        // A[15:8]      = A01
        // ...
        // A[127:120]   = A33
        // =====================================================

        A = {
            8'd16, 8'd15, 8'd14, 8'd13,
            8'd12, 8'd11, 8'd10, 8'd9,
            8'd8,  8'd7,  8'd6,  8'd5,
            8'd4,  8'd3,  8'd2,  8'd1
        };

        // =====================================================
        // MATRIX B
        //
        // B =
        //
        //  1   2   3   4
        //  2   3   4   5
        //  3   4   5   6
        //  4   5   6   7
        // =====================================================

        B = {
            8'd7, 8'd6, 8'd5, 8'd4,
            8'd6, 8'd5, 8'd4, 8'd3,
            8'd5, 8'd4, 8'd3, 8'd2,
            8'd4, 8'd3, 8'd2, 8'd1
        };

        // =====================================================
        // Reset
        // =====================================================

        repeat(2) @(posedge clk);

        reset = 0;
        enable = 1;

        // =====================================================
        // Allow systolic computation to run
        // =====================================================

        repeat(9) @(posedge clk);

        #1;

        // =====================================================
        // CHECK RESULT
        // =====================================================

        if (C00 !== 32'd30) begin
            $display("FAIL C00");
            errors = errors + 1;
        end
        else
            $display("PASS C00 = %0d", C00);

        if (C01 !== 32'd40) begin
            $display("FAIL C01");
            errors = errors + 1;
        end
        else
            $display("PASS C01 = %0d", C01);

        if (C02 !== 32'd50) begin
            $display("FAIL C02");
            errors = errors + 1;
        end
        else
            $display("PASS C02 = %0d", C02);

        if (C03 !== 32'd60) begin
            $display("FAIL C03");
            errors = errors + 1;
        end
        else
            $display("PASS C03 = %0d", C03);


        if (C10 !== 32'd70) begin
            $display("FAIL C10");
            errors = errors + 1;
        end
        else
            $display("PASS C10 = %0d", C10);

        if (C11 !== 32'd96) begin
            $display("FAIL C11");
            errors = errors + 1;
        end
        else
            $display("PASS C11 = %0d", C11);

        if (C12 !== 32'd122) begin
            $display("FAIL C12");
            errors = errors + 1;
        end
        else
            $display("PASS C12 = %0d", C12);

        if (C13 !== 32'd148) begin
            $display("FAIL C13");
            errors = errors + 1;
        end
        else
            $display("PASS C13 = %0d", C13);


        if (C20 !== 32'd110) begin
            $display("FAIL C20");
            errors = errors + 1;
        end
        else
            $display("PASS C20 = %0d", C20);

        if (C21 !== 32'd152) begin
            $display("FAIL C21");
            errors = errors + 1;
        end
        else
            $display("PASS C21 = %0d", C21);

        if (C22 !== 32'd194) begin
            $display("FAIL C22");
            errors = errors + 1;
        end
        else
            $display("PASS C22 = %0d", C22);

        if (C23 !== 32'd236) begin
            $display("FAIL C23");
            errors = errors + 1;
        end
        else
            $display("PASS C23 = %0d", C23);


        if (C30 !== 32'd150) begin
            $display("FAIL C30");
            errors = errors + 1;
        end
        else
            $display("PASS C30 = %0d", C30);

        if (C31 !== 32'd208) begin
            $display("FAIL C31");
            errors = errors + 1;
        end
        else
            $display("PASS C31 = %0d", C31);

        if (C32 !== 32'd266) begin
            $display("FAIL C32");
            errors = errors + 1;
        end
        else
            $display("PASS C32 = %0d", C32);

        if (C33 !== 32'd324) begin
            $display("FAIL C33");
            errors = errors + 1;
        end
        else
            $display("PASS C33 = %0d", C33);


        // =====================================================
        // FINAL RESULT
        // =====================================================

        if (errors == 0) begin
            $display("================================");
            $display("ALL SYSTOLIC 4x4 TESTS PASSED");
            $display("================================");
        end
        else begin
            $display("%0d TESTS FAILED", errors);
        end

        $finish;

    end

endmodule