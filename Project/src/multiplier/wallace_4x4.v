module   wallace   ( 
    input wire [3:0] A,
    input wire [3:0] B,
    output wire [7:0] P // packed vectors so they are treated together as a bits of a number
);

/* Stage 1 */
assign P[0] = A[0] & B[0];
wire S2, C2;
full_adder FA_C2_1 (
    .a(A[2] & B[0]),
    .b(A[1] & B[1]),
    .cin(A[0] & B[2]),
    .sum(S2),
    .cout(C2)
);

wire S3, C3;
full_adder FA_C3_1 (
    .a(A[3] & B[0]),
    .b(A[2] & B[1]),
    .cin(A[1] & B[2]),
    .sum(S3),
    .cout(C3)
);

wire S4, C4;
full_adder FA_C4_1 (
    .a(A[3] & B[1]),
    .b(A[2] & B[2]),
    .cin(A[1] & B[3]),
    .sum(S4),
    .cout(C4)
);

/* Stage 2 */
wire S5, C5;
full_adder FA_C3_2 (
    .a(C2),
    .b(S3),
    .cin(A[0] & B[3]),
    .sum(S5),
    .cout(C5)
);

wire S6, C6;
full_adder FA_C5_2 (
    .a(C4),
    .b(A[3] & B[2]),
    .cin(A[2] & B[3]),
    .sum(S6),
    .cout(C6)
);

/* Stage 3 */
wire S7, C7;
full_adder FA_C4_3 (
    .a(C5),
    .b(C3),
    .cin(S4),
    .sum(S7),
    .cout(C7)
);

/* FINAL */
wire carry1, carry2, carry3, carry4, carry5;

/* C1 */
half_adder HA_final_C1 (
    .a(A[1] & B[0]),
    .b(A[0] & B[1]),
    .sum(P[1]),
    .carry(carry1)
);

/* C2 */
half_adder HA_final_C2 (
    .a(S2),
    .b(carry1),
    .sum(P[2]),
    .carry(carry2)
);

/* C3 */
half_adder HA_final_C3 (
    .a(S5),
    .b(carry2),
    .sum(P[3]),
    .carry(carry3)
);

/* C4 */
half_adder HA_final_C4 (
    .a(S7),
    .b(carry3),
    .sum(P[4]),
    .carry(carry4)
);

/* C5 */
full_adder FA_final_C5 (
    .a(S6),
    .b(C7),
    .cin(carry4),
    .sum(P[5]),
    .cout(carry5)
);

/* C6 */
full_adder FA_final_C6 (
    .a(A[3] & B[3]),
    .b(C6),
    .cin(carry5),
    .sum(P[6]),
    .cout(P[7])
);

endmodule