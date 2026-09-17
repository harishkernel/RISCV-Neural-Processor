module mac (
    input wire clk,
    input wire reset,
    input wire enable,
    input wire [7:0] A,
    input wire [7:0] B,
    output reg [31:0] acc_out
);

    // 8-bit × 8-bit multiplication.
    // Gowin synthesis can map this to the FPGA's
    // dedicated hard multiplier/DSP resource.
    wire [15:0] product;
    wire [31:0] product_ext;

    assign product = A * B;

    assign product_ext = {16'b0, product};

    always @(posedge clk) begin
        if (reset)
            acc_out <= 32'b0;
        else if (enable)
            acc_out <= acc_out + product_ext;
    end

endmodule