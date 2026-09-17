//==============================================================================
// Testbench: tb_systolic_array_8x8
// Verifies:
//   1. 8x8 GEMM computation with skew modules
//   2. Expected results using a random signed matrix
//==============================================================================
`timescale 1ns / 1ps

module tb_systolic_array_8x8;

    parameter N = 8;
    parameter DATA_W = 8;

    reg clk;
    reg rst_n;
    reg en;
    reg clr_acc;

    // Flat data for input to skew modules
    reg [N*DATA_W-1:0] a_raw;
    reg [N*DATA_W-1:0] w_raw;

    // Skewed data fed to systolic array
    wire [N*DATA_W-1:0] a_skewed;
    wire [N*DATA_W-1:0] w_skewed;

    // Output accumulators
    wire [N*N*32-1:0] acc_out;

    // ---- Instantiate Skew Modules ----
    input_skew #(
        .N(N),
        .DATA_W(DATA_W)
    ) u_skew_a (
        .clk(clk),
        .rst_n(rst_n),
        .en(en),
        .data_in(a_raw),
        .data_out(a_skewed)
    );

    input_skew #(
        .N(N),
        .DATA_W(DATA_W)
    ) u_skew_w (
        .clk(clk),
        .rst_n(rst_n),
        .en(en),
        .data_in(w_raw),
        .data_out(w_skewed)
    );

    // ---- Instantiate Systolic Array ----
    systolic_array_8x8 #(
        .N(N)
    ) u_array (
        .clk(clk),
        .rst_n(rst_n),
        .en(en),
        .clr_acc(clr_acc),
        .a_in(a_skewed),
        .w_in(w_skewed),
        .acc_out(acc_out)
    );

    // ---- Clock Generation ----
    initial clk = 0;
    always #5 clk = ~clk;

    integer pass_count = 0;
    integer fail_count = 0;

    task check_acc;
        input integer row;
        input integer col;
        input signed [31:0] expected;
        reg signed [31:0] actual;
        begin
            actual = acc_out[32*(N*row + col) +: 32];
            if (actual !== expected) begin
                $display("[FAIL] C[%0d][%0d] = %0d, expected %0d", row, col, actual, expected);
                fail_count = fail_count + 1;
            end else begin
                pass_count = pass_count + 1;
            end
        end
    endtask

    // ---- Test Stimulus ----
    // Matrices for Golden Model
    reg signed [7:0] A_mat [0:63];
    reg signed [7:0] B_mat [0:63];
    reg signed [31:0] C_golden [0:63];

    integer r, c, k;

    initial begin
        $dumpfile("tb_systolic_array_8x8.vcd");
        $dumpvars(0, tb_systolic_array_8x8);

        // 1. Generate Random Signed Matrices
        // Range: -128 to 127
        for (r=0; r<8; r=r+1) begin
            for (c=0; c<8; c=c+1) begin
                A_mat[r*8 + c] = $random % 128; // Signed random [-127 : 127]
                B_mat[r*8 + c] = $random % 128;
                C_golden[r*8 + c] = 0;
            end
        end
        
        // Compute Golden C = A * B
        for (r=0; r<8; r=r+1) begin
            for (c=0; c<8; c=c+1) begin
                for (k=0; k<8; k=k+1) begin
                    C_golden[r*8 + c] = C_golden[r*8 + c] + ($signed(A_mat[r*8 + k]) * $signed(B_mat[k*8 + c])); 
                end
            end
        end

        // 2. Initialise and Reset
        rst_n = 0;
        en = 0;
        clr_acc = 0;
        a_raw = 0;
        w_raw = 0;

        #20;
        rst_n = 1;
        #10;
        
        // 3. Clear accumulators
        clr_acc = 1;
        @(posedge clk); #1;
        clr_acc = 0;
        
        // 4. Feed Data
        en = 1;
        for (k=0; k<8; k=k+1) begin
            // a_raw = {A[7][k], A[6][k], ..., A[0][k]}
            // w_raw = {B[k][7], B[k][6], ..., B[k][0]}
            a_raw = {A_mat[7*8 + k], A_mat[6*8 + k], A_mat[5*8 + k], A_mat[4*8 + k], 
                     A_mat[3*8 + k], A_mat[2*8 + k], A_mat[1*8 + k], A_mat[0*8 + k]};
            
            w_raw = {B_mat[k*8 + 7], B_mat[k*8 + 6], B_mat[k*8 + 5], B_mat[k*8 + 4], 
                     B_mat[k*8 + 3], B_mat[k*8 + 2], B_mat[k*8 + 1], B_mat[k*8 + 0]};
                     
            @(posedge clk); #1;
        end
        
        // 5. Feed zeros and wait for pipeline to flush
        a_raw = 0;
        w_raw = 0;
        
        repeat (20) @(posedge clk); #1;
        
        en = 0;
        
        // 6. Check results
        $display("Checking C matrix against randomized golden model...");
        begin : check_loop
            for (r=0; r<8; r=r+1) begin
                for (c=0; c<8; c=c+1) begin
                    check_acc(r, c, C_golden[r*8 + c]);
                end
            end
        end
        
        $display("====================================");
        $display("  SYSTOLIC ARRAY TB: %0d PASSED, %0d FAILED", pass_count, fail_count);
        $display("====================================");
        if (fail_count == 0)
            $display("*** ALL RANDOMIZED TESTS PASSED ***");
        else
            $display("*** SOME TESTS FAILED ***");
            
        $finish;
    end

endmodule
