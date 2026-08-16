module csa_tb;

reg [31:0] A, B, C;
wire [31:0] sum;
wire [32:0] carry;

csa uut (
    .A(A),
    .B(B),
    .C(C),
    .sum(sum),
    .carry(carry)
);

integer i, j, k;
reg [32:0] expected;
reg [32:0] actual;

initial begin
    $dumpfile("csa.vcd");
    $dumpvars(0, csa_tb);

    for(i = 0; i < 16; i = i + 1) begin
        for(j = 0; j < 16; j = j + 1) begin
            for(k = 0; k < 16; k = k + 1) begin

                A = i;
                B = j;
                C = k;
                #1;

                expected = A+B+C;
                actual = sum + carry;

                if (actual != expected) begin
                    $display("ERROR!");
                    $display("A        = %d", A);
                    $display("B        = %d", B);
                    $display("C        = %d", C);
                    $display("SUM      = %d", sum);
                    $display("CARRY    = %d", carry);
                    $display("ACTUAL   = %d", actual);
                    $display("EXPECTED = %d", expected);
                    $finish;
                end
            end
        end
    end
    $display("All CSA tests passed!");
    $finish;
end
endmodule