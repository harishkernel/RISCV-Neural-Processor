`timescale 1ns/1ps

// ============================================================
// Controller Testbench
//
// Test matrices:
//   A[i][j] = i + j + 1
//   B[i][j] = i + j + 1
//
// These are the same style of deterministic matrices used for
// validating the 8x8 systolic array.
//
// The expected matrix below is the mathematically correct result
// of C = A x B.
//
// The controller is expected to provide 23 enabled compute clocks,
// matching the verified current systolic8x8 implementation.
// ============================================================

module controller_tb;

    reg clk;
    reg rst_n;
    reg start;

    reg [511:0] A_flat;
    reg [511:0] B_flat;

    wire done;
    wire busy;
    wire [31:0] cycle_count;

    wire [31:0] C00, C01, C02, C03, C04, C05, C06, C07;
    wire [31:0] C10, C11, C12, C13, C14, C15, C16, C17;
    wire [31:0] C20, C21, C22, C23, C24, C25, C26, C27;
    wire [31:0] C30, C31, C32, C33, C34, C35, C36, C37;
    wire [31:0] C40, C41, C42, C43, C44, C45, C46, C47;
    wire [31:0] C50, C51, C52, C53, C54, C55, C56, C57;
    wire [31:0] C60, C61, C62, C63, C64, C65, C66, C67;
    wire [31:0] C70, C71, C72, C73, C74, C75, C76, C77;

    // =========================================================
    // DUT
    // =========================================================
    controller uut (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .done(done),
        .busy(busy),

        .A_flat(A_flat),
        .B_flat(B_flat),

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
        .C74(C74), .C75(C75), .C76(C76), .C77(C77),

        .cycle_count(cycle_count)
    );

    // =========================================================
    // 10 ns period = 100 MHz simulation clock.
    //
    // This is ONLY the simulation clock. It does not change the
    // FPGA's 50 MHz synthesis target.
    // =========================================================
    initial clk = 1'b0;
    always #5 clk = ~clk;

    // =========================================================
    // Expected C = A x B
    //
    // A[i][j] = B[i][j] = i + j + 1
    // =========================================================
    reg [31:0] expected [0:7][0:7];

    initial begin
        // Row 0
        expected[0][0] = 32'd204;
        expected[0][1] = 32'd240;
        expected[0][2] = 32'd276;
        expected[0][3] = 32'd312;
        expected[0][4] = 32'd348;
        expected[0][5] = 32'd384;
        expected[0][6] = 32'd420;
        expected[0][7] = 32'd456;

        // Row 1
        expected[1][0] = 32'd240;
        expected[1][1] = 32'd284;
        expected[1][2] = 32'd328;
        expected[1][3] = 32'd372;
        expected[1][4] = 32'd416;
        expected[1][5] = 32'd460;
        expected[1][6] = 32'd504;
        expected[1][7] = 32'd548;

        // Row 2
        expected[2][0] = 32'd276;
        expected[2][1] = 32'd328;
        expected[2][2] = 32'd380;
        expected[2][3] = 32'd432;
        expected[2][4] = 32'd484;
        expected[2][5] = 32'd536;
        expected[2][6] = 32'd588;
        expected[2][7] = 32'd640;

        // Row 3
        expected[3][0] = 32'd312;
        expected[3][1] = 32'd372;
        expected[3][2] = 32'd432;
        expected[3][3] = 32'd492;
        expected[3][4] = 32'd552;
        expected[3][5] = 32'd612;
        expected[3][6] = 32'd672;
        expected[3][7] = 32'd732;

        // Row 4
        expected[4][0] = 32'd348;
        expected[4][1] = 32'd416;
        expected[4][2] = 32'd484;
        expected[4][3] = 32'd552;
        expected[4][4] = 32'd620;
        expected[4][5] = 32'd688;
        expected[4][6] = 32'd756;
        expected[4][7] = 32'd824;

        // Row 5
        expected[5][0] = 32'd384;
        expected[5][1] = 32'd460;
        expected[5][2] = 32'd536;
        expected[5][3] = 32'd612;
        expected[5][4] = 32'd688;
        expected[5][5] = 32'd764;
        expected[5][6] = 32'd840;
        expected[5][7] = 32'd916;

        // Row 6
        expected[6][0] = 32'd420;
        expected[6][1] = 32'd504;
        expected[6][2] = 32'd588;
        expected[6][3] = 32'd672;
        expected[6][4] = 32'd756;
        expected[6][5] = 32'd840;
        expected[6][6] = 32'd924;
        expected[6][7] = 32'd1008;

        // Row 7
        expected[7][0] = 32'd456;
        expected[7][1] = 32'd548;
        expected[7][2] = 32'd640;
        expected[7][3] = 32'd732;
        expected[7][4] = 32'd824;
        expected[7][5] = 32'd916;
        expected[7][6] = 32'd1008;
        expected[7][7] = 32'd1100;
    end

    // =========================================================
    // Map flat output ports to a 2-D array for checking.
    // =========================================================
    wire [31:0] actual [0:7][0:7];

    assign actual[0][0] = C00; assign actual[0][1] = C01;
    assign actual[0][2] = C02; assign actual[0][3] = C03;
    assign actual[0][4] = C04; assign actual[0][5] = C05;
    assign actual[0][6] = C06; assign actual[0][7] = C07;

    assign actual[1][0] = C10; assign actual[1][1] = C11;
    assign actual[1][2] = C12; assign actual[1][3] = C13;
    assign actual[1][4] = C14; assign actual[1][5] = C15;
    assign actual[1][6] = C16; assign actual[1][7] = C17;

    assign actual[2][0] = C20; assign actual[2][1] = C21;
    assign actual[2][2] = C22; assign actual[2][3] = C23;
    assign actual[2][4] = C24; assign actual[2][5] = C25;
    assign actual[2][6] = C26; assign actual[2][7] = C27;

    assign actual[3][0] = C30; assign actual[3][1] = C31;
    assign actual[3][2] = C32; assign actual[3][3] = C33;
    assign actual[3][4] = C34; assign actual[3][5] = C35;
    assign actual[3][6] = C36; assign actual[3][7] = C37;

    assign actual[4][0] = C40; assign actual[4][1] = C41;
    assign actual[4][2] = C42; assign actual[4][3] = C43;
    assign actual[4][4] = C44; assign actual[4][5] = C45;
    assign actual[4][6] = C46; assign actual[4][7] = C47;

    assign actual[5][0] = C50; assign actual[5][1] = C51;
    assign actual[5][2] = C52; assign actual[5][3] = C53;
    assign actual[5][4] = C54; assign actual[5][5] = C55;
    assign actual[5][6] = C56; assign actual[5][7] = C57;

    assign actual[6][0] = C60; assign actual[6][1] = C61;
    assign actual[6][2] = C62; assign actual[6][3] = C63;
    assign actual[6][4] = C64; assign actual[6][5] = C65;
    assign actual[6][6] = C66; assign actual[6][7] = C67;

    assign actual[7][0] = C70; assign actual[7][1] = C71;
    assign actual[7][2] = C72; assign actual[7][3] = C73;
    assign actual[7][4] = C74; assign actual[7][5] = C75;
    assign actual[7][6] = C76; assign actual[7][7] = C77;

    integer i;
    integer j;
    integer errors;

    // =========================================================
    // Test procedure
    // =========================================================
    initial begin

        $dumpfile("controller.vcd");
        $dumpvars(0, controller_tb);

        errors = 0;

        // -----------------------------------------------------
        // Initialize matrices.
        //
        // systolic8x8 expects:
        // A[7:0]       = A[0][0]
        // A[15:8]      = A[0][1]
        // ...
        // A[511:504]   = A[7][7]
        // -----------------------------------------------------
        A_flat = 512'd0;
        B_flat = 512'd0;

        for (i = 0; i < 8; i = i + 1) begin
            for (j = 0; j < 8; j = j + 1) begin
                A_flat[(i*8+j)*8 +: 8] = 8'(i + j + 1);
                B_flat[(i*8+j)*8 +: 8] = 8'(i + j + 1);
            end
        end

        // -----------------------------------------------------
        // External reset
        // -----------------------------------------------------
        rst_n = 1'b0;
        start = 1'b0;

        #20;
        rst_n = 1'b1;
        #10;

        // =====================================================
        // TEST 1
        // =====================================================
        $display("");
        $display("==============================================");
        $display("TEST 1: Controller 8x8 Matrix Multiplication");
        $display("==============================================");

        // Start for exactly one clock.
        @(posedge clk);
        start = 1'b1;

        @(posedge clk);
        start = 1'b0;

        // Allow NBA updates to settle before checking busy.
        #1;
        if (!busy) begin
            $display("FAIL: busy did not go high");
            errors = errors + 1;
        end
        else begin
            $display("PASS: busy asserted");
        end

        // Wait until controller announces completion.
        wait (done == 1'b1);
        #1;

        $display("Controller compute cycles = %0d", cycle_count);

        if (cycle_count != 32'd23) begin
            $display("FAIL: cycle_count = %0d, expected 23", cycle_count);
            errors = errors + 1;
        end
        else begin
            $display("PASS: cycle_count = 23");
        end

        // Check all 64 outputs.
        for (i = 0; i < 8; i = i + 1) begin
            for (j = 0; j < 8; j = j + 1) begin

                if (actual[i][j] !== expected[i][j]) begin
                    $display(
                        "FAIL C[%0d][%0d]: got %0d, expected %0d",
                        i, j, actual[i][j], expected[i][j]
                    );
                    errors = errors + 1;
                end
                else begin
                    $display(
                        "PASS C[%0d][%0d] = %0d",
                        i, j, actual[i][j]
                    );
                end

            end
        end

        // =====================================================
        // TEST 2: Run the controller again.
        // This checks that the array accumulators are reset.
        // =====================================================
        $display("");
        $display("==============================================");
        $display("TEST 2: Re-run Same 8x8 Matrix");
        $display("==============================================");

        // Wait until the done pulse has cleared and controller
        // is back in IDLE.
        @(posedge clk);
        #1;

        @(posedge clk);
        start = 1'b1;

        @(posedge clk);
        start = 1'b0;

        wait (done == 1'b1);
        #1;

        $display("Second compute cycles = %0d", cycle_count);

        if (cycle_count != 32'd23) begin
            $display("FAIL: second cycle_count = %0d, expected 23",
                     cycle_count);
            errors = errors + 1;
        end
        else begin
            $display("PASS: second cycle_count = 23");
        end

        if (C00 !== 32'd204) begin
            $display("FAIL C00 (second run): got %0d, expected 204", C00);
            errors = errors + 1;
        end
        else begin
            $display("PASS C00 (second run) = %0d", C00);
        end

        if (C77 !== 32'd1100) begin
            $display("FAIL C77 (second run): got %0d, expected 1100", C77);
            errors = errors + 1;
        end
        else begin
            $display("PASS C77 (second run) = %0d", C77);
        end

        // =====================================================
        // FINAL RESULT
        // =====================================================
        $display("");

        if (errors == 0) begin
            $display("==============================================");
            $display("ALL CONTROLLER TESTS PASSED");
            $display("==============================================");
        end
        else begin
            $display("==============================================");
            $display("%0d TEST(S) FAILED", errors);
            $display("==============================================");
        end

        $finish;
    end

endmodule
