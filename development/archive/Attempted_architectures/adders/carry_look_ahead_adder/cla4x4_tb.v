module cla4x4_tb;
reg  [3:0] A;
reg  [3:0] B;
reg        Cin;
wire [3:0] Sum;
wire       Cout;
reg [4:0] expected;

integer i;
integer errors;
cla4x4 uut (
    .A(A),
    .B(B),
    .Cin(Cin),
    .Sum(Sum),
    .Cout(Cout)
);
initial begin
    $dumpfile("cla4x4.vcd");
    $dumpvars(0, cla4x4_tb);
    errors = 0;
    for(i = 0; i < 512; i = i+1) begin
        A   = i[8:5];
        B   = i[4:1];
        Cin = i[0];
        #10;
        expected = A + B + Cin;
        if ({Cout, Sum} !== expected) begin
            $display("ERROR: A=%b B=%b Cin=%b | Expected=%b | Got=%b",
                     A, B, Cin, expected, {Cout, Sum});
            errors = errors+1;
        end
    end
    if(errors == 0)
        $display("PASS: All 512 combinations tested successfully.");
    else
        $display("FAIL: %0d errors found.", errors);
    $finish;
end

endmodule