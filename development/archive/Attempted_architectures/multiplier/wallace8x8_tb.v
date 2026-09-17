// wallace8x8_tb.v
//
// Self-checking testbench for the standalone wallace8x8 module.
// Compares DUT output against plain A*B multiplication automatically.
// Compile together with: full_adder.v, wallace8x8.v

`timescale 1ns/1ps

module wallace8x8_tb;
    reg  [7:0]  A, B;
    wire [15:0] P;
    integer     errors = 0;
    integer     i;

    wallace8x8 uut (.A(A), .B(B), .P(P));

    task check;
        begin
            #10;
            if (P !== (A * B)) begin
                errors = errors + 1;
                $display("FAIL: A=%0d B=%0d  got=%0d  expected=%0d", A, B, P, A*B);
            end else begin
                $display("pass: A=%0d B=%0d  P=%0d", A, B, P);
            end
        end
    endtask

    initial begin
        $dumpfile("multiplier/wallace8x8.vcd");
        $dumpvars(0, wallace8x8_tb);
        
        // edge cases
        A = 0;   B = 0;   check;
        A = 255; B = 255; check;
        A = 1;   B = 255; check;
        A = 255; B = 1;   check;
        A = 128; B = 128; check;
        A = 200; B = 200; check;
        A = 15;  B = 15;  check;
        A = 16;  B = 16;  check;

        // sweep some pseudo-random combinations
        for (i = 0; i < 20; i = i + 1) begin
            A = ($random) & 8'hFF;
            B = ($random) & 8'hFF;
            check;
        end

        if (errors == 0)
            $display("ALL TESTS PASSED");
        else
            $display("%0d TEST(S) FAILED", errors);

        $finish;
    end
endmodule