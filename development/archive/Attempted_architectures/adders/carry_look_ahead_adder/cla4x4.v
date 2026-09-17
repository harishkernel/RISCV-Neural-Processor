module cla4x4 (
    input wire [3:0]A,
    input wire [3:0]B,
    input wire Cin,
    output wire [3:0] Sum,
    output wire Cout
);

wire [3:0]G;   // Generate
wire [3:0]P;   // Propagate
wire [3:0]C;   // Carries

assign G = A & B;
assign P = A ^ B;


assign C[0] = Cin;

assign C[1] = G[0] |
                  (P[0] & C[0]);

assign C[2] = G[1] |
                 (P[1] & G[0]) |
                 (P[1] & P[0] & C[0]);

assign C[3] = G[2] |
                 (P[2] & G[1]) |
                 (P[2] & P[1] & G[0]) |
                 (P[2] & P[1] & P[0] & C[0]);

assign Sum = P ^ C;
assign Cout =  G[3] |
                 (P[3] & G[2]) |
                 (P[3] & P[2] & G[1]) |
                 (P[3] & P[2] & P[1] & G[0]) |
                 (P[3] & P[2] & P[1] & P[0] & C[0]);

endmodule