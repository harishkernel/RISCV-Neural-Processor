`timescale 1ns/1ps

module pe_tb;

    reg        clk;
    reg        reset;
    reg        enable;

    reg  [7:0] A_in;
    reg  [7:0] B_in;

    wire [7:0] A_out;
    wire [7:0] B_out;

    wire [31:0] acc_out;

    integer errors = 0;

    pe uut (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A_in(A_in),
        .B_in(B_in),
        .A_out(A_out),
        .B_out(B_out),
        .acc_out(acc_out)
    );

    // 10 ns clock
    always #5 clk = ~clk;


    task check;
        input [31:0] expected_acc;
        input [7:0]  expected_A;
        input [7:0]  expected_B;

        begin
            #1;

            if (acc_out !== expected_acc) begin
                $display(
                    "FAIL ACC: A=%0d B=%0d | Got=%0d | Expected=%0d",
                    A_in, B_in, acc_out, expected_acc
                );
                errors = errors + 1;
            end
            else if (A_out !== expected_A || B_out !== expected_B) begin
                $display(
                    "FAIL FORWARD: A_out=%0d B_out=%0d | Expected A=%0d B=%0d",
                    A_out, B_out, expected_A, expected_B
                );
                errors = errors + 1;
            end
            else begin
                $display(
                    "PASS: A=%0d B=%0d | ACC=%0d | A_out=%0d B_out=%0d",
                    A_in, B_in, acc_out, A_out, B_out
                );
            end
        end
    endtask


    initial begin

        $dumpfile("arithmetic/pe.vcd");
        $dumpvars(0, pe_tb);

        clk = 0;
        reset = 1;
        enable = 0;
        A_in = 0;
        B_in = 0;

        // Reset
        @(posedge clk);
        #1;

        if (acc_out !== 0 || A_out !== 0 || B_out !== 0) begin
            $display("FAIL: Reset");
            errors = errors + 1;
        end
        else
            $display("PASS: Reset");


        // 2 × 3 = 6
        reset = 0;
        enable = 1;
        A_in = 2;
        B_in = 3;

        @(posedge clk);
        check(32'd6, 8'd2, 8'd3);


        // 4 × 5 = 20
        // ACC = 6 + 20 = 26
        A_in = 4;
        B_in = 5;

        @(posedge clk);
        check(32'd26, 8'd4, 8'd5);


        // Disable
        // ACC must remain 26
        enable = 0;
        A_in = 100;
        B_in = 100;

        @(posedge clk);
        check(32'd26, 8'd4, 8'd5);


        if (errors == 0)
            $display("ALL PE TESTS PASSED");
        else
            $display("%0d PE TEST(S) FAILED", errors);

        $finish;

    end

endmodule