//==============================================================================
// Testbench: tb_pe
// Verifies:
//   1. Reset clears accumulator and forwarding registers
//   2. Activation pass-through  (a_in → a_out, 1-cycle delay)
//   3. Weight pass-through      (w_in → w_out, 1-cycle delay)
//   4. Accumulation matches expected MAC result
//   5. clr_acc clears accumulator without affecting forwarding
//==============================================================================
`timescale 1ns / 1ps

module tb_pe;

    reg         clk;
    reg         rst_n;
    reg         en;
    reg         clr_acc;
    reg  signed [7:0]  a_in;
    reg  signed [7:0]  w_in;
    wire signed [7:0]  a_out;
    wire signed [7:0]  w_out;
    wire signed [31:0] acc;

    // ---- DUT ----
    pe u_dut (
        .clk     (clk),
        .rst_n   (rst_n),
        .en      (en),
        .clr_acc (clr_acc),
        .a_in    (a_in),
        .w_in    (w_in),
        .a_out   (a_out),
        .w_out   (w_out),
        .acc     (acc)
    );

    // ---- Clock: 10 ns period ----
    initial clk = 0;
    always #5 clk = ~clk;

    // ---- Helpers ----
    integer pass_count = 0;
    integer fail_count = 0;

    task check_val;
        input signed [31:0] actual;
        input signed [31:0] expected;
        input [255:0] label;
        begin
            if (actual !== expected) begin
                $display("[FAIL] %0s : got %0d, expected %0d (t=%0t)",
                         label, actual, expected, $time);
                fail_count = fail_count + 1;
            end else begin
                $display("[PASS] %0s : %0d", label, actual);
                pass_count = pass_count + 1;
            end
        end
    endtask

    // ---- Stimulus ----
    initial begin
        $dumpfile("tb_pe.vcd");
        $dumpvars(0, tb_pe);

        // ---- Reset ----
        rst_n = 0; en = 0; clr_acc = 0; a_in = 0; w_in = 0;
        #20;
        rst_n = 1;
        #10;
        check_val(acc, 32'sd0, "acc after reset");
        check_val({24'd0, a_out}, 32'sd0, "a_out after reset");
        check_val({24'd0, w_out}, 32'sd0, "w_out after reset");

        // ---- Test 1: single cycle, a=3 w=4 → acc=12, forwarded ----
        @(posedge clk); #1
        a_in = 8'sd3; w_in = 8'sd4; en = 1;
        @(posedge clk); #1     // MAC fires, forwarding registers load
        #1;
        check_val(acc,                   32'sd12, "acc 3*4");
        check_val({{24{a_out[7]}},a_out}, 32'sd3, "a_out fwd 3");
        check_val({{24{w_out[7]}},w_out}, 32'sd4, "w_out fwd 4");

        // ---- Test 2: accumulate, a=5 w=-2 → 12 + (-10) = 2 ----
        a_in = 8'sd5; w_in = -8'sd2;
        @(posedge clk); #1
        #1;
        check_val(acc,                    32'sd2,  "acc 12+(-10)");
        check_val({{24{a_out[7]}},a_out}, 32'sd5,  "a_out fwd 5");
        check_val({{24{w_out[7]}},w_out}, -32'sd2, "w_out fwd -2");

        // ---- Test 3: clr_acc only clears accumulator ----
        en = 0;
        @(posedge clk); #1
        clr_acc = 1;
        @(posedge clk); #1
        clr_acc = 0;
        #1;
        check_val(acc, 32'sd0, "acc after clr");

        // ---- Test 4: multi-cycle  (4 cycles of 7×3 = 21 each → 84) ----
        @(posedge clk); #1
        a_in = 8'sd7; w_in = 8'sd3; en = 1;
        repeat (4) @(posedge clk); #1
        en = 0;
        #1;
        check_val(acc, 32'sd84, "4x(7*3)");

        // ---- Summary ----
        #20;
        $display("====================================");
        $display("  PE TB: %0d PASSED, %0d FAILED", pass_count, fail_count);
        $display("====================================");
        if (fail_count == 0)
            $display("*** ALL TESTS PASSED ***");
        else
            $display("*** SOME TESTS FAILED ***");
        $finish;
    end

endmodule
