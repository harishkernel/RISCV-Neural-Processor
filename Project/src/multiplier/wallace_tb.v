module wallace_tb;

reg [3:0] A, B;
wire [7:0] P;

wallace uut (
    .A(A),
    .B(B),
    .P(P)
);

integer i, j;
initial begin
    $dumpfile("wallace.vcd");
    $dumpvars(0, wallace_tb);
    for (i = 0; i < 16; i = i + 1) begin
        for(j = 0; j < 16; j = j + 1) begin

            A = i;
            B = j;
            
            #1;
            if (P != i*j) begin
                $display("ERROR!");
                $display("A        = %d", i);
                $display("B        = %d", j);
                $display("P        = %d", P);
                $display("Expected = %d", i * j);
                $finish;
            end
        end
    end
    $display("All 256 combinations passed!");
    $finish;
end

endmodule