module pe (
    input  wire        clk,
    input  wire        reset,
    input  wire        enable,

    input  wire [7:0]  A_in,
    input  wire [7:0]  B_in,

    output reg  [7:0]  A_out,
    output reg  [7:0]  B_out,

    output wire [31:0] acc_out
);

    // MAC inside the PE
    mac mac_unit (
        .clk(clk),
        .reset(reset),
        .enable(enable),
        .A(A_in),
        .B(B_in),
        .acc_out(acc_out)
    );

    // Forward A and B to the next PE
    always @(posedge clk) begin

        if (reset) begin
            A_out <= 8'b0;
            B_out <= 8'b0;
        end

        else if (enable) begin
            A_out <= A_in;
            B_out <= B_in;
        end

    end

endmodule