module mac (
    input  wire        clk,
    input  wire        reset,
    input  wire        enable,

    input  wire [7:0]  A,
    input  wire [7:0]  B,

    output reg  [31:0] acc_out
);

    wire [15:0] product;
    wire [31:0] product_ext;

    // 8x8 Wallace multiplier
    wallace8x8 multiplier (
        .A(A),
        .B(B),
        .P(product)
    );

    // Explicitly extend 16-bit product to 32 bits
    assign product_ext = {16'b0, product};

    // Accumulator
    always @(posedge clk) begin

        if (reset)
            acc_out <= 32'b0;

        else if (enable)
            acc_out <= acc_out + product_ext;

    end

endmodule