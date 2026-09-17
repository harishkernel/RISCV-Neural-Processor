`timescale 1ns/1ps

module mac_tb;

    reg        clk;
    reg        reset;
    reg        enable;

    reg  [7:0] A;
    reg  [7:0] B;

    wire [31:0] acc_out;

    integer errors = 0;

    mac uut (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A(A),
        .B(B),
        .acc_out(acc_out)
    );

    // Clock: 10 ns period
    always #5 clk = ~clk;


    task check;
        input [31:0] expected;
        begin
            #1;

            if (acc_out !== expected) begin
                $display(
                    "FAIL: A=%0d B=%0d enable=%b | Got=%0d | Expected=%0d",
                    A, B, enable, acc_out, expected
                );
                errors = errors + 1;
            end
            else begin
                $display(
                    "PASS: A=%0d B=%0d enable=%b | ACC=%0d",
                    A, B, enable, acc_out
                );
            end
        end
    endtask


    initial begin

        $dumpfile("arithmetic/mac.vcd");
        $dumpvars(0, mac_tb);

        clk = 0;
        reset = 1;
        enable = 0;
        A = 0;
        B = 0;

        // Reset
        @(posedge clk);
        #1;

        if (acc_out !== 32'd0) begin
            $display("FAIL: Reset did not clear accumulator");
            errors = errors + 1;
        end
        else
            $display("PASS: Reset | ACC=0");


        // 2 × 3 = 6
        reset = 0;
        enable = 1;
        A = 2;
        B = 3;

        @(posedge clk);
        check(32'd6);


        // 4 × 5 = 20
        // ACC = 6 + 20 = 26
        A = 4;
        B = 5;

        @(posedge clk);
        check(32'd26);


        // 10 × 2 = 20
        // ACC = 26 + 20 = 46
        A = 10;
        B = 2;

        @(posedge clk);
        check(32'd46);


        // Test enable = 0
        // ACC should remain 46
        enable = 0;
        A = 100;
        B = 100;

        @(posedge clk);
        check(32'd46);


        // Enable again
        // ACC = 46 + (7 × 8) = 102
        enable = 1;
        A = 7;
        B = 8;

        @(posedge clk);
        check(32'd102);


        // Larger multiplication
        // 200 × 200 = 40000
        // ACC = 102 + 40000 = 40102
        A = 200;
        B = 200;

        @(posedge clk);
        check(32'd40102);


        if (errors == 0)
            $display("ALL MAC TESTS PASSED");
        else
            $display("%0d MAC TEST(S) FAILED", errors);

        $finish;

    end

endmodule