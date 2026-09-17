`timescale 1ns/1ps

// =============================================================
// ping_pong_top_tb.v
//
// Integration test:
//
//   1. Negative compute-start test
//   2. Load TILE-1 into PING
//   3. Compute PING
//   4. Load TILE-2 into PONG while controller is active
//   5. Verify PONG becomes READY
//   6. Verify PING result
//   7. Compute PONG
//   8. Verify PONG result
//
// The standalone ping_pong_buffer_tb proves true simultaneous:
//
//       PING = LOADING
//       PONG = COMPUTING
//
// The real controller completes much faster than the 128-byte
// serial load, therefore the integration TB does not require
// PING to remain COMPUTING until the end of PONG loading.
// =============================================================

module master_controller_tb;

    // ---------------------------------------------------------
    // DUT signals
    // ---------------------------------------------------------
    reg clk;
    reg rst_n;

    reg        wr_en;
    reg [6:0]  wr_addr;
    reg [7:0]  wr_data;
    reg        load_done_in;

    reg compute_start;

    wire load_ready;
    wire load_buf_id;

    wire compute_valid;
    wire compute_busy;
    wire compute_done;

    wire [31:0] C00, C01, C02, C03, C04, C05, C06, C07;
    wire [31:0] C10, C11, C12, C13, C14, C15, C16, C17;
    wire [31:0] C20, C21, C22, C23, C24, C25, C26, C27;
    wire [31:0] C30, C31, C32, C33, C34, C35, C36, C37;
    wire [31:0] C40, C41, C42, C43, C44, C45, C46, C47;
    wire [31:0] C50, C51, C52, C53, C54, C55, C56, C57;
    wire [31:0] C60, C61, C62, C63, C64, C65, C66, C67;
    wire [31:0] C70, C71, C72, C73, C74, C75, C76, C77;

    wire [1:0] ping_state;
    wire [1:0] pong_state;

    wire [31:0] cycle_count;

    localparam [1:0] ST_FREE      = 2'b00;
    localparam [1:0] ST_LOADING   = 2'b01;
    localparam [1:0] ST_READY     = 2'b10;
    localparam [1:0] ST_COMPUTING = 2'b11;

    integer errors;

    // ---------------------------------------------------------
    // DUT
    // ---------------------------------------------------------
    master_controller dut (

        .clk          (clk),
        .rst_n        (rst_n),

        .wr_en        (wr_en),
        .wr_addr      (wr_addr),
        .wr_data      (wr_data),
        .load_done    (load_done_in),

        .load_ready   (load_ready),
        .load_buf_id  (load_buf_id),

        .compute_start(compute_start),
        .compute_valid(compute_valid),
        .compute_busy (compute_busy),
        .compute_done (compute_done),

        .C00(C00), .C01(C01), .C02(C02), .C03(C03),
        .C04(C04), .C05(C05), .C06(C06), .C07(C07),

        .C10(C10), .C11(C11), .C12(C12), .C13(C13),
        .C14(C14), .C15(C15), .C16(C16), .C17(C17),

        .C20(C20), .C21(C21), .C22(C22), .C23(C23),
        .C24(C24), .C25(C25), .C26(C26), .C27(C27),

        .C30(C30), .C31(C31), .C32(C32), .C33(C33),
        .C34(C34), .C35(C35), .C36(C36), .C37(C37),

        .C40(C40), .C41(C41), .C42(C42), .C43(C43),
        .C44(C44), .C45(C45), .C46(C46), .C47(C47),

        .C50(C50), .C51(C51), .C52(C52), .C53(C53),
        .C54(C54), .C55(C55), .C56(C56), .C57(C57),

        .C60(C60), .C61(C61), .C62(C62), .C63(C63),
        .C64(C64), .C65(C65), .C66(C66), .C67(C67),

        .C70(C70), .C71(C71), .C72(C72), .C73(C73),
        .C74(C74), .C75(C75), .C76(C76), .C77(C77),

        .ping_state  (ping_state),
        .pong_state  (pong_state),
        .cycle_count (cycle_count)
    );

    // ---------------------------------------------------------
    // Clock
    // ---------------------------------------------------------
    initial clk = 1'b0;
    always #5 clk = ~clk;

    // ---------------------------------------------------------
    // Expected matrix
    // ---------------------------------------------------------
    reg [31:0] expected [0:7][0:7];

    initial begin

        expected[0][0]=32'd204;  expected[0][1]=32'd240;
        expected[0][2]=32'd276;  expected[0][3]=32'd312;
        expected[0][4]=32'd348;  expected[0][5]=32'd384;
        expected[0][6]=32'd420;  expected[0][7]=32'd456;

        expected[1][0]=32'd240;  expected[1][1]=32'd284;
        expected[1][2]=32'd328;  expected[1][3]=32'd372;
        expected[1][4]=32'd416;  expected[1][5]=32'd460;
        expected[1][6]=32'd504;  expected[1][7]=32'd548;

        expected[2][0]=32'd276;  expected[2][1]=32'd328;
        expected[2][2]=32'd380;  expected[2][3]=32'd432;
        expected[2][4]=32'd484;  expected[2][5]=32'd536;
        expected[2][6]=32'd588;  expected[2][7]=32'd640;

        expected[3][0]=32'd312;  expected[3][1]=32'd372;
        expected[3][2]=32'd432;  expected[3][3]=32'd492;
        expected[3][4]=32'd552;  expected[3][5]=32'd612;
        expected[3][6]=32'd672;  expected[3][7]=32'd732;

        expected[4][0]=32'd348;  expected[4][1]=32'd416;
        expected[4][2]=32'd484;  expected[4][3]=32'd552;
        expected[4][4]=32'd620;  expected[4][5]=32'd688;
        expected[4][6]=32'd756;  expected[4][7]=32'd824;

        expected[5][0]=32'd384;  expected[5][1]=32'd460;
        expected[5][2]=32'd536;  expected[5][3]=32'd612;
        expected[5][4]=32'd688;  expected[5][5]=32'd764;
        expected[5][6]=32'd840;  expected[5][7]=32'd916;

        expected[6][0]=32'd420;  expected[6][1]=32'd504;
        expected[6][2]=32'd588;  expected[6][3]=32'd672;
        expected[6][4]=32'd756;  expected[6][5]=32'd840;
        expected[6][6]=32'd924;  expected[6][7]=32'd1008;

        expected[7][0]=32'd456;  expected[7][1]=32'd548;
        expected[7][2]=32'd640;  expected[7][3]=32'd732;
        expected[7][4]=32'd824;  expected[7][5]=32'd916;
        expected[7][6]=32'd1008; expected[7][7]=32'd1100;

    end

    // ---------------------------------------------------------
    // Convert result ports into 2D array.
    // ---------------------------------------------------------
    wire [31:0] C [0:7][0:7];

    assign C[0][0]=C00; assign C[0][1]=C01;
    assign C[0][2]=C02; assign C[0][3]=C03;
    assign C[0][4]=C04; assign C[0][5]=C05;
    assign C[0][6]=C06; assign C[0][7]=C07;

    assign C[1][0]=C10; assign C[1][1]=C11;
    assign C[1][2]=C12; assign C[1][3]=C13;
    assign C[1][4]=C14; assign C[1][5]=C15;
    assign C[1][6]=C16; assign C[1][7]=C17;

    assign C[2][0]=C20; assign C[2][1]=C21;
    assign C[2][2]=C22; assign C[2][3]=C23;
    assign C[2][4]=C24; assign C[2][5]=C25;
    assign C[2][6]=C26; assign C[2][7]=C27;

    assign C[3][0]=C30; assign C[3][1]=C31;
    assign C[3][2]=C32; assign C[3][3]=C33;
    assign C[3][4]=C34; assign C[3][5]=C35;
    assign C[3][6]=C36; assign C[3][7]=C37;

    assign C[4][0]=C40; assign C[4][1]=C41;
    assign C[4][2]=C42; assign C[4][3]=C43;
    assign C[4][4]=C44; assign C[4][5]=C45;
    assign C[4][6]=C46; assign C[4][7]=C47;

    assign C[5][0]=C50; assign C[5][1]=C51;
    assign C[5][2]=C52; assign C[5][3]=C53;
    assign C[5][4]=C54; assign C[5][5]=C55;
    assign C[5][6]=C56; assign C[5][7]=C57;

    assign C[6][0]=C60; assign C[6][1]=C61;
    assign C[6][2]=C62; assign C[6][3]=C63;
    assign C[6][4]=C64; assign C[6][5]=C65;
    assign C[6][6]=C66; assign C[6][7]=C67;

    assign C[7][0]=C70; assign C[7][1]=C71;
    assign C[7][2]=C72; assign C[7][3]=C73;
    assign C[7][4]=C74; assign C[7][5]=C75;
    assign C[7][6]=C76; assign C[7][7]=C77;

    integer r;
    integer c;

    // ---------------------------------------------------------
    // Load one complete tile.
    // ---------------------------------------------------------
    task load_tile;
        integer n;
        integer idx;
        begin

            for (n = 0; n < 128; n = n + 1) begin

                @(posedge clk);
                #1;

                wr_en   = 1'b1;
                wr_addr = n[6:0];

                if (n < 64) begin

                    idx = n;
                    wr_data = (idx / 8) + (idx % 8) + 1;

                end else begin

                    idx = n - 64;
                    wr_data = (idx / 8) + (idx % 8) + 1;

                end

            end

            @(posedge clk);
            #1;

            wr_en       = 1'b0;
            load_done_in = 1'b1;

            @(posedge clk);
            #1;

            load_done_in = 1'b0;

        end
    endtask

    // ---------------------------------------------------------
    // Start compute.
    // ---------------------------------------------------------
    task start_compute_task;
        begin

            @(posedge clk);
            #1;

            compute_start = 1'b1;

            @(posedge clk);
            #1;

            compute_start = 1'b0;

        end
    endtask

    // ---------------------------------------------------------
    // Verify all 64 outputs.
    // ---------------------------------------------------------
    task verify_results;
        input [127:0] tag;
        integer local_errors;

        begin

            local_errors = 0;

            for (r = 0; r < 8; r = r + 1) begin

                for (c = 0; c < 8; c = c + 1) begin

                    if (C[r][c] !== expected[r][c]) begin

                        $display(
                            "FAIL %s C[%0d][%0d]: got %0d expected %0d",
                            tag,
                            r,
                            c,
                            C[r][c],
                            expected[r][c]
                        );

                        local_errors = local_errors + 1;
                        errors = errors + 1;

                    end

                end

            end

            if (local_errors == 0)
                $display("PASS %s: all 64 results correct", tag);

        end
    endtask

    // ---------------------------------------------------------
    // MAIN
    // ---------------------------------------------------------
    initial begin

        $dumpfile("master_controller.vcd");
        $dumpvars(0, master_controller_tb);

        errors        = 0;

        rst_n         = 1'b0;

        wr_en         = 1'b0;
        wr_addr       = 7'd0;
        wr_data       = 8'd0;
        load_done_in  = 1'b0;

        compute_start = 1'b0;

        // =====================================================
        // RESET
        // =====================================================
        repeat (3) @(posedge clk);

        #1;
        rst_n = 1'b1;

        @(posedge clk);
        #1;

        $display("");
        $display("=========================================");
        $display("Integration Test: master_controller");
        $display("=========================================");

        // =====================================================
        // T9-INT — compute before READY
        // =====================================================
        $display("");
        $display("--- T9-INT: Reject compute without READY buffer ---");

        if (compute_valid !== 1'b0) begin

            $display(
                "FAIL T9-INT pre: compute_valid=%b expected 0",
                compute_valid
            );

            errors = errors + 1;

        end

        @(posedge clk);
        #1;

        compute_start = 1'b1;

        @(posedge clk);
        #1;

        compute_start = 1'b0;

        repeat (5) @(posedge clk);
        #1;

        if (compute_busy !== 1'b0) begin

            $display(
                "FAIL T9-INT: compute_busy=%b expected 0",
                compute_busy
            );

            errors = errors + 1;

        end else begin

            $display("PASS T9-INT: controller did not start");

        end

        if (compute_done !== 1'b0) begin

            $display("FAIL T9-INT: unexpected compute_done");

            errors = errors + 1;

        end else begin

            $display("PASS T9-INT: no compute_done pulse");

        end

        if (ping_state !== ST_FREE ||
            pong_state !== ST_FREE) begin

            $display(
                "FAIL T9-INT: ping=%b pong=%b expected FREE/FREE",
                ping_state,
                pong_state
            );

            errors = errors + 1;

        end else begin

            $display("PASS T9-INT: both buffers remain FREE");

        end

        // =====================================================
        // STEP 1 — Load PING
        // =====================================================
        $display("");
        $display("--- Step 1: Load TILE-1 into PING ---");

        if (load_buf_id !== 1'b0) begin

            $display(
                "FAIL Step1: load_buf_id=%b expected PING(0)",
                load_buf_id
            );

            errors = errors + 1;

        end

        load_tile;

        // =====================================================
        // STEP 2 — PING READY
        // =====================================================
        $display("");
        $display("--- Step 2: Confirm PING READY ---");

        if (ping_state !== ST_READY) begin

            $display(
                "FAIL Step2: ping_state=%b expected READY",
                ping_state
            );

            errors = errors + 1;

        end else begin

            $display("PASS Step2: PING READY");

        end

        if (compute_valid !== 1'b1) begin

            $display("FAIL Step2: compute_valid=0");

            errors = errors + 1;

        end else begin

            $display("PASS Step2: compute_valid=1");

        end

        // =====================================================
        // STEP 3 — Start PING compute
        // =====================================================
        $display("");
        $display("--- Step 3: Start PING compute ---");

        start_compute_task;

        @(posedge clk);
        #1;

        if (ping_state !== ST_COMPUTING) begin

            $display(
                "FAIL Step3: PING=%b expected COMPUTING",
                ping_state
            );

            errors = errors + 1;

        end else begin

            $display("PASS Step3: PING COMPUTING");

        end

        if (compute_busy !== 1'b1) begin

            $display("FAIL Step3: compute_busy=0");

            errors = errors + 1;

        end else begin

            $display("PASS Step3: compute_busy=1");

        end

        // =====================================================
        // STEP 4 — Load PONG while PING computation is active
        // =====================================================
        $display("");
        $display("--- Step 4: Load TILE-2 into PONG ---");

        if (load_buf_id !== 1'b1) begin

            $display(
                "FAIL Step4: load_buf_id=%b expected PONG(1)",
                load_buf_id
            );

            errors = errors + 1;

        end else begin

            $display("PASS Step4 pre: PONG selected for loading");

        end

        // Start PONG load.
        load_tile;

        // =====================================================
        // STEP 5 — PONG READY
        // =====================================================
        $display("");
        $display("--- Step 5: Confirm PONG READY ---");

        if (pong_state !== ST_READY) begin

            $display(
                "FAIL Step5: PONG=%b expected READY",
                pong_state
            );

            errors = errors + 1;

        end else begin

            $display("PASS Step5: PONG READY");

        end

        // PING may already have completed because the real
        // controller is much faster than the serial load.
        if (ping_state == ST_COMPUTING)
            $display("INFO Step5: PING still COMPUTING");
        else if (ping_state == ST_FREE)
            $display("INFO Step5: PING already completed and is FREE");
        else
            $display(
                "FAIL Step5: unexpected PING state=%b",
                ping_state
            );

        // =====================================================
        // STEP 6 — Wait for PING compute completion
        // =====================================================
        $display("");
        $display("--- Step 6: Confirm PING completion ---");

        if (compute_busy) begin

            wait (compute_done == 1'b1);
            @(posedge clk);
            #1;

            $display("PASS Step6: PING compute_done received");

        end else begin

            $display(
                "PASS Step6: PING computation already completed"
            );

        end

        // =====================================================
        // STEP 7 — Verify PING results
        // =====================================================
        $display("");
        $display("--- Step 7: Verify PING results ---");

        $display(
            "cycle_count=%0d",
            cycle_count
        );

        verify_results("PING");

        // =====================================================
        // STEP 8 — Start PONG
        // =====================================================
        $display("");
        $display("--- Step 8: Start PONG compute ---");

        if (compute_valid !== 1'b1) begin

            $display(
                "FAIL Step8: compute_valid=0 expected 1"
            );

            errors = errors + 1;

        end else begin

            $display("PASS Step8 pre: READY buffer exists");

        end

        start_compute_task;

        @(posedge clk);
        #1;

        if (pong_state !== ST_COMPUTING) begin

            $display(
                "FAIL Step8: PONG=%b expected COMPUTING",
                pong_state
            );

            errors = errors + 1;

        end else begin

            $display("PASS Step8: PONG COMPUTING");

        end

        // =====================================================
        // STEP 9 — Wait for PONG compute_done
        // =====================================================
        $display("");
        $display("--- Step 9: Wait for PONG compute_done ---");

        wait (compute_done == 1'b1);

        @(posedge clk);
        #1;

        $display(
            "PASS Step9: PONG compute_done received, cycle_count=%0d",
            cycle_count
        );

        // =====================================================
        // STEP 10 — Verify PONG results
        // =====================================================
        $display("");
        $display("--- Step 10: Verify PONG results ---");

        verify_results("PONG");

        // =====================================================
        // FINAL
        // =====================================================
        $display("");
        $display("=========================================");

        if (errors == 0)
            $display("ALL INTEGRATION TESTS PASSED");
        else
            $display("%0d ERROR(S) DETECTED", errors);

        $display("=========================================");

        $finish;

    end

endmodule