//==============================================================================
// Testbench: tb_int8_mac
// Verifies:
//   1. Reset clears accumulator
//   2. Single MAC cycle:  a × b → acc
//   3. Multi-cycle accumulation
//   4. Synchronous clear
//   5. Signed (negative) operands
//   6. Boundary values (-128 × 127)
//==============================================================================
`timescale 1ns / 1ps

module tb_int8_mac;

    reg         clk;
    reg         rst_n;
    reg         en;
    reg         clr;
    reg  signed [7:0]  a;
    reg  signed [7:0]  b;
    wire signed [31:0] acc;

    // ---- DUT ----
    int8_mac u_dut (
        .clk   (clk),
        .rst_n (rst_n),
        .en    (en),
        .clr   (clr),
        .a     (a),
        .b     (b),
        .acc   (acc)
    );

    // ---- Clock: 10 ns period (100 MHz) ----
    initial clk = 0;
    always #5 clk = ~clk;

    // ---- Helpers ----
    integer pass_count = 0;
    integer fail_count = 0;

    task check;
        input signed [31:0] expected;
        input [255:0] label;            // up to 32 chars
        begin
            if (acc !== expected) begin
                $display("[FAIL] %0s : acc = %0d, expected %0d (t=%0t)",
                         label, acc, expected, $time);
                fail_count = fail_count + 1;
            end else begin
                $display("[PASS] %0s : acc = %0d", label, acc);
                pass_count = pass_count + 1;
            end
        end
    endtask

    // ---- Stimulus ----
    initial begin
        $dumpfile("tb_int8_mac.vcd");
        $dumpvars(0, tb_int8_mac);

        // ---- Reset ----
        rst_n = 0; en = 0; clr = 0; a = 0; b = 0;
        #20;
        rst_n = 1;
        #10;
        check(32'sd0, "After reset");

        // ---- Test 1: single MAC  3 × 4 = 12 ----
        @(posedge clk); #1
        a = 8'sd3; b = 8'sd4; en = 1;
        @(posedge clk); #1
        en = 0; a = 0; b = 0;
        #1;
        check(32'sd12, "3 x 4");

        // ---- Test 2: accumulate  += 5 × 6 = 30  → total 42 ----
        @(posedge clk); #1
        a = 8'sd5; b = 8'sd6; en = 1;
        @(posedge clk); #1
        en = 0; a = 0; b = 0;
        #1;
        check(32'sd42, "accum 5x6");

        // ---- Test 3: synchronous clear ----
        @(posedge clk); #1
        clr = 1;
        @(posedge clk); #1
        clr = 0;
        #1;
        check(32'sd0, "After clear");

        // ---- Test 4: negative operands  (-5) × 3 = -15 ----
        @(posedge clk); #1
        a = -8'sd5; b = 8'sd3; en = 1;
        @(posedge clk); #1
        en = 0; a = 0; b = 0;
        #1;
        check(-32'sd15, "(-5) x 3");

        // ---- Test 5: both negative  (-7) × (-8) = 56  → total -15+56 = 41 ----
        @(posedge clk); #1
        a = -8'sd7; b = -8'sd8; en = 1;
        @(posedge clk); #1
        en = 0; a = 0; b = 0;
        #1;
        check(32'sd41, "(-7)x(-8) accum");

        // ---- Test 6: clear & boundary  -128 × 127 = -16256 ----
        @(posedge clk); #1 clr = 1;
        @(posedge clk); #1 clr = 0;
        @(posedge clk); #1
        a = -8'sd128; b = 8'sd127; en = 1;
        @(posedge clk); #1
        en = 0; a = 0; b = 0;
        #1;
        check(-32'sd16256, "-128 x 127");

        // ---- Test 7: multi-cycle accumulation (8 cycles of 10×10=100 → 800) ----
        @(posedge clk); #1 clr = 1;
        @(posedge clk); #1 clr = 0;
        a = 8'sd10; b = 8'sd10; en = 1;
        repeat (8) @(posedge clk); #1
        en = 0; a = 0; b = 0;
        #1;
        check(32'sd800, "8x(10x10)");

        // ---- Summary ----
        #20;
        $display("====================================");
        $display("  INT8_MAC TB: %0d PASSED, %0d FAILED", pass_count, fail_count);
        $display("====================================");
        if (fail_count == 0)
            $display("*** ALL TESTS PASSED ***");
        else
            $display("*** SOME TESTS FAILED ***");
        $finish;
    end

endmodule
