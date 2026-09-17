module cla32x32 (
    input wire [31:0]A,
    input wire [31:0]B,
    input wire Cin,
    output wire [31:0]Sum,
    output wire Cout
);

wire [8:0] c;          // c[0] = overall Cin, c[8] = overall Cout, c[1..7] = between blocks
assign c[0] = Cin;

genvar i;
generate
    for(i = 0; i < 8; i = i+1) begin: cla
        cla4x4 u_cla4x4(
            .A(A[4*i +: 4]),
            .B(B[4*i +: 4]),
            .Cin(c[i]),
            .Sum(Sum[4*i +: 4]),
            .Cout(c[i+1])
        );        
    end
endgenerate

assign Cout = c[8];

endmodule