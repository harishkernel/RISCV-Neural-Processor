module full_adder (
    input wire a,
    input wire b,
    input wire cin,
    output wire sum,
    output wire cout
);
    // dont use XOR(), AND() as their arguments follow output, input1, input2,....

    assign sum = a ^ b ^ cin;
    
    assign cout = (b & cin) | (a & cin) | (a & b);

endmodule