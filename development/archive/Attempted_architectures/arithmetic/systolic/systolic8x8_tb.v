`timescale 1ns/1ps

module systolic8x8_tb;

    reg clk;
    reg reset;
    reg enable;

    // =========================================================
    // Flattened 8x8 matrix inputs
    //
    // 64 elements × 8 bits = 512 bits
    // =========================================================

    reg [511:0] A;
    reg [511:0] B;

    wire [31:0] C00, C01, C02, C03, C04, C05, C06, C07;
    wire [31:0] C10, C11, C12, C13, C14, C15, C16, C17;
    wire [31:0] C20, C21, C22, C23, C24, C25, C26, C27;
    wire [31:0] C30, C31, C32, C33, C34, C35, C36, C37;
    wire [31:0] C40, C41, C42, C43, C44, C45, C46, C47;
    wire [31:0] C50, C51, C52, C53, C54, C55, C56, C57;
    wire [31:0] C60, C61, C62, C63, C64, C65, C66, C67;
    wire [31:0] C70, C71, C72, C73, C74, C75, C76, C77;

    integer errors = 0;

    // =========================================================
    // DUT
    // =========================================================

    systolic8x8 uut (
        .clk(clk),
        .reset(reset),
        .enable(enable),

        .A(A),
        .B(B),

        .C00(C00), .C01(C01), .C02(C02), .C03(C03),
        .C04(C04), .C05(C05), .C06(C06), .C07(C07),
        .C10(C10), .C11(C11), .C12(C12), .C13(C13),
        .C14(C14), .C15(C15), .C16(C16), .C17(C17),
        .C20(C20), .C21(C21), .C22(C22), .C23(C23),
        .C24(C24), .C25(C25), .C26(C26), .C27(C27),
        .C30(C30), .C31(C31), .C32(C32), .C33(C33),
        .C34(C34), .C35(C35), .C36(C36), .C37(C37),
        .C40(C40), .C41(C41), .C42(C42), .C43(C43),
        .C44(C44), .C45(C45), .C46(C46), .C47(C47),
        .C50(C50), .C51(C51), .C52(C52), .C53(C53),
        .C54(C54), .C55(C55), .C56(C56), .C57(C57),
        .C60(C60), .C61(C61), .C62(C62), .C63(C63),
        .C64(C64), .C65(C65), .C66(C66), .C67(C67),
        .C70(C70), .C71(C71), .C72(C72), .C73(C73),
        .C74(C74), .C75(C75), .C76(C76), .C77(C77)
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
        $dumpfile("arithmetic/systolic/systolic8x8.vcd");
        $dumpvars(0, systolic8x8_tb);

        clk = 0;
        reset = 1;
        enable = 0;

        // =====================================================
        // MATRIX A
        //
        // A =
        //
        //  1   2   3   4   5   6   7   8
        //  9  10  11  12  13  14  15  16
        // 17  18  19  20  21  22  23  24
        // 25  26  27  28  29  30  31  32
        // 33  34  35  36  37  38  39  40
        // 41  42  43  44  45  46  47  48
        // 49  50  51  52  53  54  55  56
        // 57  58  59  60  61  62  63  64
        //
        // Packed as:
        //
        // A[7:0]       = A00
        // A[15:8]      = A01
        // ...
        // A[511:504]   = A77
        // =====================================================

        A = {
            8'd64, 8'd63, 8'd62, 8'd61, 8'd60, 8'd59, 8'd58, 8'd57,
            8'd56, 8'd55, 8'd54, 8'd53, 8'd52, 8'd51, 8'd50, 8'd49,
            8'd48, 8'd47, 8'd46, 8'd45, 8'd44, 8'd43, 8'd42, 8'd41,
            8'd40, 8'd39, 8'd38, 8'd37, 8'd36, 8'd35, 8'd34, 8'd33,
            8'd32, 8'd31, 8'd30, 8'd29, 8'd28, 8'd27, 8'd26, 8'd25,
            8'd24, 8'd23, 8'd22, 8'd21, 8'd20, 8'd19, 8'd18, 8'd17,
            8'd16, 8'd15, 8'd14, 8'd13, 8'd12, 8'd11, 8'd10, 8'd9,
            8'd8,  8'd7,  8'd6,  8'd5,  8'd4,  8'd3,  8'd2,  8'd1
        };

        // =====================================================
        // MATRIX B
        //
        // B =
        //
        //  1   2   3   4   5   6   7   8
        //  2   3   4   5   6   7   8   9
        //  3   4   5   6   7   8   9  10
        //  4   5   6   7   8   9  10  11
        //  5   6   7   8   9  10  11  12
        //  6   7   8   9  10  11  12  13
        //  7   8   9  10  11  12  13  14
        //  8   9  10  11  12  13  14  15
        // =====================================================

        B = {
            8'd15, 8'd14, 8'd13, 8'd12, 8'd11, 8'd10, 8'd9,  8'd8,
            8'd14, 8'd13, 8'd12, 8'd11, 8'd10, 8'd9,  8'd8,  8'd7,
            8'd13, 8'd12, 8'd11, 8'd10, 8'd9,  8'd8,  8'd7,  8'd6,
            8'd12, 8'd11, 8'd10, 8'd9,  8'd8,  8'd7,  8'd6,  8'd5,
            8'd11, 8'd10, 8'd9,  8'd8,  8'd7,  8'd6,  8'd5,  8'd4,
            8'd10, 8'd9,  8'd8,  8'd7,  8'd6,  8'd5,  8'd4,  8'd3,
            8'd9,  8'd8,  8'd7,  8'd6,  8'd5,  8'd4,  8'd3,  8'd2,
            8'd8,  8'd7,  8'd6,  8'd5,  8'd4,  8'd3,  8'd2,  8'd1
        };

        // =====================================================
        // Reset
        // =====================================================

        repeat(2) @(posedge clk);

        reset = 0;
        enable = 1;

        // =====================================================
        // Allow systolic computation to run
        //
        // 8x8 needs 8 + (8-1) = 15 cycles for all data to
        // propagate. Using 17 for margin.
        // =====================================================

        repeat(23) @(posedge clk);

        #1;

        // =====================================================
        // CHECK RESULT
        //
        // Expected C = A * B
        // =====================================================

        // ----- ROW 0 -----

        if (C00 !== 32'd204) begin
            $display("FAIL C00: got %0d, expected 204", C00);
            errors = errors + 1;
        end
        else
            $display("PASS C00 = %0d", C00);

        if (C01 !== 32'd240) begin
            $display("FAIL C01: got %0d, expected 240", C01);
            errors = errors + 1;
        end
        else
            $display("PASS C01 = %0d", C01);

        if (C02 !== 32'd276) begin
            $display("FAIL C02: got %0d, expected 276", C02);
            errors = errors + 1;
        end
        else
            $display("PASS C02 = %0d", C02);

        if (C03 !== 32'd312) begin
            $display("FAIL C03: got %0d, expected 312", C03);
            errors = errors + 1;
        end
        else
            $display("PASS C03 = %0d", C03);

        if (C04 !== 32'd348) begin
            $display("FAIL C04: got %0d, expected 348", C04);
            errors = errors + 1;
        end
        else
            $display("PASS C04 = %0d", C04);

        if (C05 !== 32'd384) begin
            $display("FAIL C05: got %0d, expected 384", C05);
            errors = errors + 1;
        end
        else
            $display("PASS C05 = %0d", C05);

        if (C06 !== 32'd420) begin
            $display("FAIL C06: got %0d, expected 420", C06);
            errors = errors + 1;
        end
        else
            $display("PASS C06 = %0d", C06);

        if (C07 !== 32'd456) begin
            $display("FAIL C07: got %0d, expected 456", C07);
            errors = errors + 1;
        end
        else
            $display("PASS C07 = %0d", C07);

        // ----- ROW 1 -----

        if (C10 !== 32'd492) begin
            $display("FAIL C10: got %0d, expected 492", C10);
            errors = errors + 1;
        end
        else
            $display("PASS C10 = %0d", C10);

        if (C11 !== 32'd592) begin
            $display("FAIL C11: got %0d, expected 592", C11);
            errors = errors + 1;
        end
        else
            $display("PASS C11 = %0d", C11);

        if (C12 !== 32'd692) begin
            $display("FAIL C12: got %0d, expected 692", C12);
            errors = errors + 1;
        end
        else
            $display("PASS C12 = %0d", C12);

        if (C13 !== 32'd792) begin
            $display("FAIL C13: got %0d, expected 792", C13);
            errors = errors + 1;
        end
        else
            $display("PASS C13 = %0d", C13);

        if (C14 !== 32'd892) begin
            $display("FAIL C14: got %0d, expected 892", C14);
            errors = errors + 1;
        end
        else
            $display("PASS C14 = %0d", C14);

        if (C15 !== 32'd992) begin
            $display("FAIL C15: got %0d, expected 992", C15);
            errors = errors + 1;
        end
        else
            $display("PASS C15 = %0d", C15);

        if (C16 !== 32'd1092) begin
            $display("FAIL C16: got %0d, expected 1092", C16);
            errors = errors + 1;
        end
        else
            $display("PASS C16 = %0d", C16);

        if (C17 !== 32'd1192) begin
            $display("FAIL C17: got %0d, expected 1192", C17);
            errors = errors + 1;
        end
        else
            $display("PASS C17 = %0d", C17);

        // ----- ROW 2 -----

        if (C20 !== 32'd780) begin
            $display("FAIL C20: got %0d, expected 780", C20);
            errors = errors + 1;
        end
        else
            $display("PASS C20 = %0d", C20);

        if (C21 !== 32'd944) begin
            $display("FAIL C21: got %0d, expected 944", C21);
            errors = errors + 1;
        end
        else
            $display("PASS C21 = %0d", C21);

        if (C22 !== 32'd1108) begin
            $display("FAIL C22: got %0d, expected 1108", C22);
            errors = errors + 1;
        end
        else
            $display("PASS C22 = %0d", C22);

        if (C23 !== 32'd1272) begin
            $display("FAIL C23: got %0d, expected 1272", C23);
            errors = errors + 1;
        end
        else
            $display("PASS C23 = %0d", C23);

        if (C24 !== 32'd1436) begin
            $display("FAIL C24: got %0d, expected 1436", C24);
            errors = errors + 1;
        end
        else
            $display("PASS C24 = %0d", C24);

        if (C25 !== 32'd1600) begin
            $display("FAIL C25: got %0d, expected 1600", C25);
            errors = errors + 1;
        end
        else
            $display("PASS C25 = %0d", C25);

        if (C26 !== 32'd1764) begin
            $display("FAIL C26: got %0d, expected 1764", C26);
            errors = errors + 1;
        end
        else
            $display("PASS C26 = %0d", C26);

        if (C27 !== 32'd1928) begin
            $display("FAIL C27: got %0d, expected 1928", C27);
            errors = errors + 1;
        end
        else
            $display("PASS C27 = %0d", C27);

        // ----- ROW 3 -----

        if (C30 !== 32'd1068) begin
            $display("FAIL C30: got %0d, expected 1068", C30);
            errors = errors + 1;
        end
        else
            $display("PASS C30 = %0d", C30);

        if (C31 !== 32'd1296) begin
            $display("FAIL C31: got %0d, expected 1296", C31);
            errors = errors + 1;
        end
        else
            $display("PASS C31 = %0d", C31);

        if (C32 !== 32'd1524) begin
            $display("FAIL C32: got %0d, expected 1524", C32);
            errors = errors + 1;
        end
        else
            $display("PASS C32 = %0d", C32);

        if (C33 !== 32'd1752) begin
            $display("FAIL C33: got %0d, expected 1752", C33);
            errors = errors + 1;
        end
        else
            $display("PASS C33 = %0d", C33);

        if (C34 !== 32'd1980) begin
            $display("FAIL C34: got %0d, expected 1980", C34);
            errors = errors + 1;
        end
        else
            $display("PASS C34 = %0d", C34);

        if (C35 !== 32'd2208) begin
            $display("FAIL C35: got %0d, expected 2208", C35);
            errors = errors + 1;
        end
        else
            $display("PASS C35 = %0d", C35);

        if (C36 !== 32'd2436) begin
            $display("FAIL C36: got %0d, expected 2436", C36);
            errors = errors + 1;
        end
        else
            $display("PASS C36 = %0d", C36);

        if (C37 !== 32'd2664) begin
            $display("FAIL C37: got %0d, expected 2664", C37);
            errors = errors + 1;
        end
        else
            $display("PASS C37 = %0d", C37);

        // ----- ROW 4 -----

        if (C40 !== 32'd1356) begin
            $display("FAIL C40: got %0d, expected 1356", C40);
            errors = errors + 1;
        end
        else
            $display("PASS C40 = %0d", C40);

        if (C41 !== 32'd1648) begin
            $display("FAIL C41: got %0d, expected 1648", C41);
            errors = errors + 1;
        end
        else
            $display("PASS C41 = %0d", C41);

        if (C42 !== 32'd1940) begin
            $display("FAIL C42: got %0d, expected 1940", C42);
            errors = errors + 1;
        end
        else
            $display("PASS C42 = %0d", C42);

        if (C43 !== 32'd2232) begin
            $display("FAIL C43: got %0d, expected 2232", C43);
            errors = errors + 1;
        end
        else
            $display("PASS C43 = %0d", C43);

        if (C44 !== 32'd2524) begin
            $display("FAIL C44: got %0d, expected 2524", C44);
            errors = errors + 1;
        end
        else
            $display("PASS C44 = %0d", C44);

        if (C45 !== 32'd2816) begin
            $display("FAIL C45: got %0d, expected 2816", C45);
            errors = errors + 1;
        end
        else
            $display("PASS C45 = %0d", C45);

        if (C46 !== 32'd3108) begin
            $display("FAIL C46: got %0d, expected 3108", C46);
            errors = errors + 1;
        end
        else
            $display("PASS C46 = %0d", C46);

        if (C47 !== 32'd3400) begin
            $display("FAIL C47: got %0d, expected 3400", C47);
            errors = errors + 1;
        end
        else
            $display("PASS C47 = %0d", C47);

        // ----- ROW 5 -----

        if (C50 !== 32'd1644) begin
            $display("FAIL C50: got %0d, expected 1644", C50);
            errors = errors + 1;
        end
        else
            $display("PASS C50 = %0d", C50);

        if (C51 !== 32'd2000) begin
            $display("FAIL C51: got %0d, expected 2000", C51);
            errors = errors + 1;
        end
        else
            $display("PASS C51 = %0d", C51);

        if (C52 !== 32'd2356) begin
            $display("FAIL C52: got %0d, expected 2356", C52);
            errors = errors + 1;
        end
        else
            $display("PASS C52 = %0d", C52);

        if (C53 !== 32'd2712) begin
            $display("FAIL C53: got %0d, expected 2712", C53);
            errors = errors + 1;
        end
        else
            $display("PASS C53 = %0d", C53);

        if (C54 !== 32'd3068) begin
            $display("FAIL C54: got %0d, expected 3068", C54);
            errors = errors + 1;
        end
        else
            $display("PASS C54 = %0d", C54);

        if (C55 !== 32'd3424) begin
            $display("FAIL C55: got %0d, expected 3424", C55);
            errors = errors + 1;
        end
        else
            $display("PASS C55 = %0d", C55);

        if (C56 !== 32'd3780) begin
            $display("FAIL C56: got %0d, expected 3780", C56);
            errors = errors + 1;
        end
        else
            $display("PASS C56 = %0d", C56);

        if (C57 !== 32'd4136) begin
            $display("FAIL C57: got %0d, expected 4136", C57);
            errors = errors + 1;
        end
        else
            $display("PASS C57 = %0d", C57);

        // ----- ROW 6 -----

        if (C60 !== 32'd1932) begin
            $display("FAIL C60: got %0d, expected 1932", C60);
            errors = errors + 1;
        end
        else
            $display("PASS C60 = %0d", C60);

        if (C61 !== 32'd2352) begin
            $display("FAIL C61: got %0d, expected 2352", C61);
            errors = errors + 1;
        end
        else
            $display("PASS C61 = %0d", C61);

        if (C62 !== 32'd2772) begin
            $display("FAIL C62: got %0d, expected 2772", C62);
            errors = errors + 1;
        end
        else
            $display("PASS C62 = %0d", C62);

        if (C63 !== 32'd3192) begin
            $display("FAIL C63: got %0d, expected 3192", C63);
            errors = errors + 1;
        end
        else
            $display("PASS C63 = %0d", C63);

        if (C64 !== 32'd3612) begin
            $display("FAIL C64: got %0d, expected 3612", C64);
            errors = errors + 1;
        end
        else
            $display("PASS C64 = %0d", C64);

        if (C65 !== 32'd4032) begin
            $display("FAIL C65: got %0d, expected 4032", C65);
            errors = errors + 1;
        end
        else
            $display("PASS C65 = %0d", C65);

        if (C66 !== 32'd4452) begin
            $display("FAIL C66: got %0d, expected 4452", C66);
            errors = errors + 1;
        end
        else
            $display("PASS C66 = %0d", C66);

        if (C67 !== 32'd4872) begin
            $display("FAIL C67: got %0d, expected 4872", C67);
            errors = errors + 1;
        end
        else
            $display("PASS C67 = %0d", C67);

        // ----- ROW 7 -----

        if (C70 !== 32'd2220) begin
            $display("FAIL C70: got %0d, expected 2220", C70);
            errors = errors + 1;
        end
        else
            $display("PASS C70 = %0d", C70);

        if (C71 !== 32'd2704) begin
            $display("FAIL C71: got %0d, expected 2704", C71);
            errors = errors + 1;
        end
        else
            $display("PASS C71 = %0d", C71);

        if (C72 !== 32'd3188) begin
            $display("FAIL C72: got %0d, expected 3188", C72);
            errors = errors + 1;
        end
        else
            $display("PASS C72 = %0d", C72);

        if (C73 !== 32'd3672) begin
            $display("FAIL C73: got %0d, expected 3672", C73);
            errors = errors + 1;
        end
        else
            $display("PASS C73 = %0d", C73);

        if (C74 !== 32'd4156) begin
            $display("FAIL C74: got %0d, expected 4156", C74);
            errors = errors + 1;
        end
        else
            $display("PASS C74 = %0d", C74);

        if (C75 !== 32'd4640) begin
            $display("FAIL C75: got %0d, expected 4640", C75);
            errors = errors + 1;
        end
        else
            $display("PASS C75 = %0d", C75);

        if (C76 !== 32'd5124) begin
            $display("FAIL C76: got %0d, expected 5124", C76);
            errors = errors + 1;
        end
        else
            $display("PASS C76 = %0d", C76);

        if (C77 !== 32'd5608) begin
            $display("FAIL C77: got %0d, expected 5608", C77);
            errors = errors + 1;
        end
        else
            $display("PASS C77 = %0d", C77);


        // =====================================================
        // FINAL RESULT
        // =====================================================

        if (errors == 0) begin
            $display("================================");
            $display("ALL SYSTOLIC 8x8 TESTS PASSED");
            $display("================================");
        end
        else begin
            $display("%0d TESTS FAILED", errors);
        end

        $finish;

    end

endmodule