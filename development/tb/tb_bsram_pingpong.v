//==============================================================================
// Testbench: tb_bsram_pingpong
//==============================================================================
`timescale 1ns / 1ps

module tb_bsram_pingpong;

    reg clk;
    reg bank_sel;
    
    reg wr_en;
    reg [8:0] wr_addr;
    reg [63:0] wr_data;
    
    reg rd_en;
    reg [8:0] rd_addr;
    wire [63:0] rd_data;

    bsram_pingpong #(
        .DATA_W(64),
        .ADDR_W(9)
    ) u_dut (
        .clk(clk),
        .bank_sel(bank_sel),
        .wr_en(wr_en),
        .wr_addr(wr_addr),
        .wr_data(wr_data),
        .rd_en(rd_en),
        .rd_addr(rd_addr),
        .rd_data(rd_data)
    );

    initial clk = 0;
    always #5 clk = ~clk;

    initial begin
        $dumpfile("tb_bsram_pingpong.vcd");
        $dumpvars(0, tb_bsram_pingpong);

        wr_en = 0; wr_addr = 0; wr_data = 0;
        rd_en = 0; rd_addr = 0;
        bank_sel = 0; // Host -> Ping(0), Accel -> Pong(1)
        
        #20;
        
        // Host writes to Ping
        @(posedge clk); #1;
        wr_en = 1; wr_addr = 5; wr_data = 64'hAABBCCDDEEFF0011;
        @(posedge clk); #1;
        wr_en = 0;
        
        // Accel reads from Pong (should be X or 0, let's write to Pong first)
        bank_sel = 1; // Host -> Pong(1), Accel -> Ping(0)
        
        @(posedge clk); #1;
        rd_en = 1; rd_addr = 5;
        @(posedge clk); #1;
        rd_en = 0;
        
        // Data should be available now
        if (rd_data === 64'hAABBCCDDEEFF0011)
            $display("[PASS] Read Ping bank successfully.");
        else
            $display("[FAIL] Expected AABBCCDDEEFF0011, got %h", rd_data);
            
        #20;
        $finish;
    end

endmodule
