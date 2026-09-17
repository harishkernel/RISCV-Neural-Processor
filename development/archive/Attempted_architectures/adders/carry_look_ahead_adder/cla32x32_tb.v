`timescale 1ns/1ps

module cla32x32_tb;

    reg  [31:0] A;
    reg  [31:0] B;
    reg         Cin;

    wire [31:0] Sum;
    wire        Cout;

    reg [32:0] expected;
    integer i;
    integer errors;

    cla32x32 uut (
        .A(A),
        .B(B),
        .Cin(Cin),
        .Sum(Sum),
        .Cout(Cout)
    );

    initial begin

        $dumpfile("cla32x32.vcd");
        $dumpvars(0, cla32x32_tb);

        errors = 0;

        // -------------------------
        // Edge cases
        // -------------------------

        A = 32'h00000000;
        B = 32'h00000000;
        Cin = 0;
        #10;
        check_result;

        A = 32'hFFFFFFFF;
        B = 32'h00000000;
        Cin = 0;
        #10;
        check_result;

        A = 32'hFFFFFFFF;
        B = 32'h00000001;
        Cin = 0;
        #10;
        check_result;

        A = 32'hFFFFFFFF;
        B = 32'hFFFFFFFF;
        Cin = 0;
        #10;
        check_result;

        A = 32'hFFFFFFFF;
        B = 32'hFFFFFFFF;
        Cin = 1;
        #10;
        check_result;

        // -------------------------
        // Random tests
        // -------------------------

        for(i = 0; i < 1000; i = i+1) begin
            A = $random;
            B = $random;
            Cin = $random & 1;

            #10;
            check_result;
        end

        if (errors == 0)
            $display("PASS: All tests passed.");
        else
            $display("FAIL: %0d errors found.", errors);
        $finish;

    end

    task check_result;
        begin
            expected = A+B+Cin;
            if ({Cout, Sum} !== expected) begin
                $display(
                    "ERROR: A=%h B=%h Cin=%b | Expected=%h | Got=%h",
                    A, B, Cin, expected, {Cout, Sum}
                );
                errors = errors+1;
            end
        end
    endtask

endmodule