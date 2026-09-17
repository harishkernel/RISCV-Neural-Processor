`timescale 1ns/1ps

module tb_agvme_core;

    parameter N      = 8;
    parameter ADDR_W = 9;
    parameter DATA_W = 64;

    reg clk;
    reg rst_n;

    reg start;
    reg [ADDR_W-1:0] K_dim;

    reg signed [31:0] bias;
    reg signed [15:0] scale_mult;
    reg [4:0] scale_shift;
    reg en_relu;

    wire busy;
    wire done;

    wire act_rd_en;
    wire [ADDR_W-1:0] act_addr;
    reg  [DATA_W-1:0] act_data;

    wire wt_rd_en;
    wire [ADDR_W-1:0] wt_addr;
    reg  [DATA_W-1:0] wt_data;

    wire out_valid;
    wire signed [7:0] out_data;

    //======================================================================
    // Behavioral synchronous BSRAM models
    //======================================================================

    reg [DATA_W-1:0] act_mem [0:511];
    reg [DATA_W-1:0] wt_mem  [0:511];

    always @(posedge clk) begin
        if (act_rd_en)
            act_data <= act_mem[act_addr];

        if (wt_rd_en)
            wt_data <= wt_mem[wt_addr];
    end

    //======================================================================
    // DUT
    //======================================================================

    agvme_core #(
        .N(N),
        .ADDR_W(ADDR_W),
        .DATA_W(DATA_W)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),

        .start(start),
        .K_dim(K_dim),

        .busy(busy),
        .done(done),

        .bias(bias),
        .scale_mult(scale_mult),
        .scale_shift(scale_shift),
        .en_relu(en_relu),

        .act_rd_en(act_rd_en),
        .act_addr(act_addr),
        .act_data(act_data),

        .wt_rd_en(wt_rd_en),
        .wt_addr(wt_addr),
        .wt_data(wt_data),

        .out_valid(out_valid),
        .out_data(out_data)
    );

    //======================================================================
    // Clock: 100 MHz
    //======================================================================

    initial begin
        clk = 1'b0;
        forever #5 clk = ~clk;
    end

    //======================================================================
    // Test matrices / golden results
    //======================================================================

    reg signed [7:0] A [0:7][0:7];
    reg signed [7:0] B [0:7][0:7];

    integer golden [0:7][0:7];
    integer observed [0:63];

    integer current_K;
    integer output_count;
    integer errors;
    integer total_errors;
    integer case_number;

    integer i;
    integer j;
    integer k;
    integer acc;

    //======================================================================
    // Utility: clear memories
    //======================================================================

    task clear_memories;
        integer m;
        begin
            for (m = 0; m < 512; m = m + 1) begin
                act_mem[m] = 64'd0;
                wt_mem[m]  = 64'd0;
            end
        end
    endtask

    //======================================================================
    // Utility: calculate golden matrix multiplication
    //
    // golden[i][j] = sum A[i][k] * B[k][j]
    //======================================================================

    task calculate_golden;
        integer r;
        integer c;
        integer x;

        begin
            for (r = 0; r < 8; r = r + 1) begin
                for (c = 0; c < 8; c = c + 1) begin

                    acc = 0;

                    for (x = 0; x < 8; x = x + 1) begin
                        if (x < current_K)
                            acc = acc + A[r][x] * B[x][c];
                    end

                    golden[r][c] = acc;

                end
            end
        end
    endtask

    //======================================================================
    // Pack matrices into the exact loader format
    //
    // act_mem[k]:
    //   [7:0]    = A[0][k]
    //   [15:8]   = A[1][k]
    //   ...
    //   [63:56]  = A[7][k]
    //
    // wt_mem[k]:
    //   [7:0]    = B[k][0]
    //   [15:8]   = B[k][1]
    //   ...
    //   [63:56]  = B[k][7]
    //======================================================================

    task pack_matrices;
        integer x;
        integer r;
        integer c;

        begin
            clear_memories;

            for (x = 0; x < current_K; x = x + 1) begin

                act_mem[x] = 64'd0;
                wt_mem[x]  = 64'd0;

                for (r = 0; r < 8; r = r + 1)
                    act_mem[x][8*r +: 8] = A[r][x];

                for (c = 0; c < 8; c = c + 1)
                    wt_mem[x][8*c +: 8] = B[x][c];

            end
        end
    endtask

    //======================================================================
    // Generate random matrices
    //
    // Range: -8 ... +8
    // Keeps the first randomized tests comfortably inside INT8 output
    // range while still exercising signed arithmetic.
    //======================================================================

    task generate_random_matrices;
        integer r;
        integer c;

        begin

            for (r = 0; r < 8; r = r + 1) begin
                for (c = 0; c < 8; c = c + 1) begin
                    A[r][c] = ($random % 17) - 8;
                    B[r][c] = ($random % 17) - 8;
                end
            end

        end
    endtask

    //======================================================================
    // Start one accelerator operation
    //======================================================================

    task start_operation;

        begin

            @(posedge clk);
            start <= 1'b1;

            @(posedge clk);
            start <= 1'b0;

        end

    endtask

    //======================================================================
    // Check one completed test case
    //======================================================================

    task check_case;

        integer r;
        integer c;
        integer expected_value;
        integer index;

        begin

            errors = 0;

            // -------------------------------------------------------------
            // Wait until ALL 64 outputs have actually appeared.
            // Do not use done for this because post_processor has latency.
            // -------------------------------------------------------------

            wait(output_count == 64);

            #1;

            for (r = 0; r < 8; r = r + 1) begin
                for (c = 0; c < 8; c = c + 1) begin

                    index = r * 8 + c;

                    expected_value = golden[r][c];

                    // -----------------------------------------------------
                    // Post-processor saturation model
                    // -----------------------------------------------------

                    if (expected_value > 127)
                        expected_value = 127;

                    if (expected_value < -128)
                        expected_value = -128;

                    if (observed[index] != expected_value) begin

                        $display(
                            "FAIL case %0d K=%0d C[%0d][%0d]: expected %0d, got %0d",
                            case_number,
                            current_K,
                            r,
                            c,
                            expected_value,
                            observed[index]
                        );

                        errors = errors + 1;

                    end

                end
            end

            if (errors == 0) begin
                $display(
                    "PASS case %0d: K=%0d, all 64 outputs correct",
                    case_number,
                    current_K
                );
            end
            else begin
                $display(
                    "FAIL case %0d: K=%0d, %0d errors",
                    case_number,
                    current_K,
                    errors
                );

                total_errors = total_errors + errors;
            end

            // Make sure controller eventually reaches done.
            wait(done);

            // Give post-processing/controller a little settling time.
            repeat (3) @(posedge clk);

        end
    endtask

    //======================================================================
    // Run one random case
    //======================================================================

    task run_random_case;
        input integer test_K;

        integer r;
        integer c;

        begin

            current_K = test_K;
            K_dim = test_K;

            generate_random_matrices;
            calculate_golden;
            pack_matrices;

            output_count = 0;

            start_operation;

            check_case;

        end
    endtask

    //======================================================================
    // Explicit extreme-value test
    //
    // K=1
    //
    // A = diagonal-like values containing -128 and +127
    // B = values containing -128 and +127
    //
    // This specifically checks signed INT8 interpretation.
    //======================================================================

    task run_extreme_case;

        integer r;
        integer c;

        begin

            current_K = 1;
            K_dim = 1;

            // Clear everything first.
            clear_memories;

            // All A/B values initially zero.
            for (r = 0; r < 8; r = r + 1) begin
                for (c = 0; c < 8; c = c + 1) begin
                    A[r][c] = 0;
                    B[r][c] = 0;
                end
            end

            // A[*][0]
            A[0][0] = -128;
            A[1][0] = 127;
            A[2][0] = -1;
            A[3][0] = 1;
            A[4][0] = -128;
            A[5][0] = 127;
            A[6][0] = -2;
            A[7][0] = 2;

            // B[0][*]
            B[0][0] = 127;
            B[0][1] = -128;
            B[0][2] = -128;
            B[0][3] = 127;
            B[0][4] = 2;
            B[0][5] = -2;
            B[0][6] = 127;
            B[0][7] = -128;

            calculate_golden;
            pack_matrices;

            output_count = 0;

            start_operation;

            check_case;

        end
    endtask

    //======================================================================
    // Capture post-processed output stream
    //======================================================================

    always @(posedge clk) begin

        if (out_valid) begin

            if (output_count < 64) begin

                observed[output_count] = out_data;

                output_count = output_count + 1;

            end
            else begin

                $display("ERROR: More than 64 output values received!");
                total_errors = total_errors + 1;
            end

        end

    end

    //======================================================================
    // Main test sequence
    //======================================================================

    initial begin

        start       = 1'b0;
        rst_n       = 1'b0;

        K_dim       = 8;

        bias        = 32'sd0;
        scale_mult  = 16'sd1;
        scale_shift = 5'd0;
        en_relu     = 1'b0;

        act_data = 64'd0;
        wt_data  = 64'd0;

        output_count = 0;
        errors       = 0;
        total_errors = 0;
        case_number  = 0;

        clear_memories;

        // -------------------------------------------------------------
        // Reset
        // -------------------------------------------------------------

        repeat (3) @(posedge clk);

        rst_n = 1'b1;

        repeat (2) @(posedge clk);

        $display("");
        $display("==============================================");
        $display("     AGVME RANDOMIZED INTEGRATION TEST");
        $display("==============================================");
        $display("");

        // -------------------------------------------------------------
        // K = 1
        // -------------------------------------------------------------

        case_number = case_number + 1;
        run_random_case(1);

        case_number = case_number + 1;
        run_random_case(1);

        // -------------------------------------------------------------
        // K = 2
        // -------------------------------------------------------------

        case_number = case_number + 1;
        run_random_case(2);

        case_number = case_number + 1;
        run_random_case(2);

        // -------------------------------------------------------------
        // K = 4
        // -------------------------------------------------------------

        case_number = case_number + 1;
        run_random_case(4);

        case_number = case_number + 1;
        run_random_case(4);

        // -------------------------------------------------------------
        // K = 8
        // -------------------------------------------------------------

        case_number = case_number + 1;
        run_random_case(8);

        case_number = case_number + 1;
        run_random_case(8);

        // -------------------------------------------------------------
        // Explicit signed INT8 extreme-value test
        // -------------------------------------------------------------

        case_number = case_number + 1;
        run_extreme_case;

        // -------------------------------------------------------------
        // Final result
        // -------------------------------------------------------------

        $display("");
        $display("==============================================");
        $display("             FINAL TEST RESULT");
        $display("==============================================");

        if (total_errors == 0) begin
            $display("ALL RANDOMIZED TESTS PASSED");
            $display("Cases tested : %0d", case_number);
            $display("Total errors : 0");
        end
        else begin
            $display("TEST FAILED");
            $display("Cases tested : %0d", case_number);
            $display("Total errors : %0d", total_errors);
        end

        $display("==============================================");
        $display("");

        #20;
        $finish;

    end

endmodule