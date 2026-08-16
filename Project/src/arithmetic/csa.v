module csa (
    input wire [31:0] A,
    input wire [31:0] B,
    input wire [31:0] C,
    output wire [31:0] sum,
    output wire [32:0] carry
);

genvar i;
generate
    for(i = 0; i < 32; i = i+1) begin : FA_GEN
        full_adder FA (
            .a(A[i]),
            .b(B[i]),
            .cin(C[i]),
            .sum(sum[i]),
            .cout(carry[i+1])
        );
    end
endgenerate

assign carry[0] = 1'b0;

endmodule