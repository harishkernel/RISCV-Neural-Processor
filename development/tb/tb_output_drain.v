//==============================================================================
// Testbench: tb_output_drain
//==============================================================================
`timescale 1ns / 1ps

module tb_output_drain;

    parameter N = 8;
    parameter ACC_W = 32;
    localparam TOTAL_BITS = N * N * ACC_W;

    reg clk;
    reg rst_n;
    reg start;
    
    wire busy;
    wire valid;
    wire done;
    
    reg  [TOTAL_BITS-1:0] acc_in;
    wire [ACC_W-1:0]      data_out;

    output_drain #(
        .N(N),
        .ACC_W(ACC_W)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .busy(busy),
        .valid(valid),
        .done(done),
        .acc_in(acc_in),
        .data_out(data_out)
    );

    initial clk = 0;
    always #5 clk = ~clk;

    integer i;
    initial begin
        $dumpfile("tb_output_drain.vcd");
        $dumpvars(0, tb_output_drain);

        rst_n = 0;
        start = 0;
        acc_in = 0;
        
        // Fill the 2048-bit bus with index data (C[i][j] = i*8 + j)
        for (i = 0; i < 64; i = i + 1) begin
            acc_in[i*32 +: 32] = i;
        end
        
        #20;
        rst_n = 1;
        #10;
        
        @(posedge clk); #1;
        start = 1;
        @(posedge clk); #1;
        start = 0;
        
        // Wait for drain to complete
        wait (done == 1);
        @(posedge clk);
        
        $display("[PASS] Drain completed.");
        $finish;
    end
    
    // Monitor the output
    integer out_count = 0;
    always @(posedge clk) begin
        if (valid) begin
            if (data_out !== out_count) begin
                $display("[FAIL] Expected %d, got %d", out_count, data_out);
            end else begin
                // $display("[PASS] Output %d correct.", out_count);
            end
            out_count = out_count + 1;
        end
    end

endmodule
