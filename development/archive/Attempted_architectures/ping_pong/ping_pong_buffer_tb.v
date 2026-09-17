`timescale 1ns/1ps

// =============================================================
// ping_pong_buffer_tb.v
//
// Standalone verification of ping_pong_buffer.
//
// Tests:
//   T1  Reset
//   T2  Load PING
//   T3  Load PONG
//   T4  PING COMPUTING while PONG READY
//   T5  PONG COMPUTING while PING LOADING
//   T6  Compute completion frees bank / load selection changes
//   T7  Consecutive PING/PONG/PING operations
//   T8  Illegal write attempt to COMPUTING bank
//   T9  compute_start with no READY bank
//   T10 Data integrity
// =============================================================

module ping_pong_buffer_tb;

    // ---------------------------------------------------------
    // DUT signals
    // ---------------------------------------------------------
    reg         clk;
    reg         reset;

    reg         wr_en;
    reg  [6:0]  wr_addr;
    reg  [7:0]  wr_data;
    reg         load_done;

    reg         compute_start;
    reg         compute_done;

    wire [511:0] A_out;
    wire [511:0] B_out;

    wire         load_ready;
    wire         load_buf_id;
    wire         compute_valid;

    wire [1:0]   ping_state;
    wire [1:0]   pong_state;

    localparam [1:0] ST_FREE      = 2'b00;
    localparam [1:0] ST_LOADING   = 2'b01;
    localparam [1:0] ST_READY     = 2'b10;
    localparam [1:0] ST_COMPUTING = 2'b11;

    integer errors;
    integer i;

    // ---------------------------------------------------------
    // DUT
    // ---------------------------------------------------------
    ping_pong_buffer dut (
        .clk           (clk),
        .reset         (reset),

        .wr_en         (wr_en),
        .wr_addr       (wr_addr),
        .wr_data       (wr_data),
        .load_done     (load_done),

        .load_ready    (load_ready),
        .load_buf_id   (load_buf_id),

        .compute_start (compute_start),
        .compute_done  (compute_done),

        .A_out         (A_out),
        .B_out         (B_out),
        .compute_valid (compute_valid),

        .ping_state    (ping_state),
        .pong_state    (pong_state)
    );

    // ---------------------------------------------------------
    // 10 ns clock
    // ---------------------------------------------------------
    initial clk = 1'b0;
    always #5 clk = ~clk;

    // ---------------------------------------------------------
    // Load a known 8x8 tile.
    //
    // A addresses 0..63
    // B addresses 64..127
    //
    // A[i][j] = i+j+1
    // B[i][j] = i+j+1
    // ---------------------------------------------------------
    task load_tile;
        integer n;
        integer row;
        integer col;

        begin

            for (n = 0; n < 128; n = n + 1) begin

                @(posedge clk);
                #1;

                row = n % 64;
                col = row % 8;

                wr_en   = 1'b1;
                wr_addr = n[6:0];

                if (n < 64)
                    wr_data = (row / 8) + col + 1;
                else
                    wr_data = ((row - 0) / 8) + col + 1;

            end

            @(posedge clk);
            #1;

            wr_en     = 1'b0;
            load_done = 1'b1;

            @(posedge clk);
            #1;

            load_done = 1'b0;

        end
    endtask

    // ---------------------------------------------------------
    // Start compute
    // ---------------------------------------------------------
    task start_compute;
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
    // Finish manually controlled compute
    // ---------------------------------------------------------
    task finish_compute;
        input integer delay_cycles;
        integer d;

        begin

            for (d = 0; d < delay_cycles; d = d + 1)
                @(posedge clk);

            #1;

            compute_done = 1'b1;

            @(posedge clk);
            #1;

            compute_done = 1'b0;

        end
    endtask

    // ---------------------------------------------------------
    // MAIN TEST
    // ---------------------------------------------------------
    initial begin

        $dumpfile("ping_pong_buffer.vcd");
        $dumpvars(0, ping_pong_buffer_tb);

        errors        = 0;
        reset         = 1'b1;

        wr_en         = 1'b0;
        wr_addr       = 7'd0;
        wr_data       = 8'd0;
        load_done     = 1'b0;

        compute_start = 1'b0;
        compute_done  = 1'b0;

        // =====================================================
        // T1 — RESET
        // =====================================================
        $display("");
        $display("--- T1: Reset ---");

        repeat (2) @(posedge clk);
        #1;

        reset = 1'b0;

        if (ping_state !== ST_FREE ||
            pong_state !== ST_FREE) begin

            $display("FAIL T1: ping=%b pong=%b",
                     ping_state, pong_state);

            errors = errors + 1;

        end else begin

            $display("PASS T1: both banks FREE");

        end

        // =====================================================
        // T2 — LOAD PING
        // =====================================================
        $display("");
        $display("--- T2: Load PING ---");

        if (load_buf_id !== 1'b0) begin

            $display("FAIL T2: expected PING load_buf_id=0");
            errors = errors + 1;

        end

        load_tile;

        if (ping_state !== ST_READY) begin

            $display("FAIL T2: PING=%b expected READY",
                     ping_state);

            errors = errors + 1;

        end else begin

            $display("PASS T2: PING READY");

        end

        // =====================================================
        // T3 — LOAD PONG
        // =====================================================
        $display("");
        $display("--- T3: Load PONG ---");

        if (load_buf_id !== 1'b1) begin

            $display("FAIL T3: expected PONG load_buf_id=1");
            errors = errors + 1;

        end

        load_tile;

        if (pong_state !== ST_READY) begin

            $display("FAIL T3: PONG=%b expected READY",
                     pong_state);

            errors = errors + 1;

        end else begin

            $display("PASS T3: PONG READY");

        end

        // =====================================================
        // T4 — PING COMPUTING, PONG READY
        // =====================================================
        $display("");
        $display("--- T4: PING COMPUTING, PONG READY ---");

        start_compute;

        if (ping_state !== ST_COMPUTING) begin

            $display("FAIL T4: PING=%b expected COMPUTING",
                     ping_state);

            errors = errors + 1;

        end else begin

            $display("PASS T4: PING COMPUTING");

        end

        if (pong_state !== ST_READY) begin

            $display("FAIL T4: PONG=%b expected READY",
                     pong_state);

            errors = errors + 1;

        end else begin

            $display("PASS T4: PONG READY");

        end

        // =====================================================
        // Finish PING so that PING becomes FREE.
        // Then start PONG.
        //
        // This prepares the genuine overlap condition:
        //
        //   PING = FREE
        //   PONG = COMPUTING
        // =====================================================
        finish_compute(3);

        if (ping_state !== ST_FREE) begin

            $display("FAIL T4b: PING=%b expected FREE",
                     ping_state);

            errors = errors + 1;

        end

        // =====================================================
        // T5 — PONG COMPUTING WHILE PING LOADING
        // =====================================================
        $display("");
        $display("--- T5: PONG COMPUTING + PING LOADING ---");

        if (load_buf_id !== 1'b0) begin

            $display("FAIL T5 pre: expected PING load_buf_id=0, got %b",
                     load_buf_id);

            errors = errors + 1;

        end

        start_compute;

        if (pong_state !== ST_COMPUTING) begin

            $display("FAIL T5 pre: PONG=%b expected COMPUTING",
                     pong_state);

            errors = errors + 1;

        end else begin

            $display("PASS T5 pre: PONG COMPUTING");

        end

        // Begin loading PING.
        @(posedge clk);
        #1;

        wr_en   = 1'b1;
        wr_addr = 7'd0;
        wr_data = 8'd1;

        @(posedge clk);
        #1;

        // PING must now be LOADING while PONG is COMPUTING.
        if (ping_state !== ST_LOADING) begin

            $display("FAIL T5: PING=%b expected LOADING",
                     ping_state);

            errors = errors + 1;

        end else begin

            $display("PASS T5: PING LOADING");

        end

        if (pong_state !== ST_COMPUTING) begin

            $display("FAIL T5: PONG=%b expected COMPUTING",
                     pong_state);

            errors = errors + 1;

        end else begin

            $display("PASS T5: PONG COMPUTING");

        end

        // Complete remaining PING bytes.
        for (i = 1; i < 128; i = i + 1) begin

            @(posedge clk);
            #1;

            wr_en   = 1'b1;
            wr_addr = i[6:0];

            if (i < 64)
                wr_data = (i / 8) + (i % 8) + 1;
            else
                wr_data = ((i - 64) / 8) + ((i - 64) % 8) + 1;

        end

        @(posedge clk);
        #1;

        wr_en     = 1'b0;
        load_done = 1'b1;

        @(posedge clk);
        #1;

        load_done = 1'b0;

        if (ping_state !== ST_READY) begin

            $display("FAIL T5b: PING=%b expected READY",
                     ping_state);

            errors = errors + 1;

        end else begin

            $display("PASS T5b: PING READY");

        end

        // PONG is still manually COMPUTING.
        if (pong_state !== ST_COMPUTING) begin

            $display("FAIL T5b: PONG=%b expected COMPUTING",
                     pong_state);

            errors = errors + 1;

        end else begin

            $display("PASS T5b: PONG still COMPUTING");

        end

        // =====================================================
        // T6 — FINISH PONG
        // =====================================================
        $display("");
        $display("--- T6: Finish PONG ---");

        finish_compute(3);

        if (pong_state !== ST_FREE) begin

            $display("FAIL T6: PONG=%b expected FREE",
                     pong_state);

            errors = errors + 1;

        end else begin

            $display("PASS T6: PONG FREE");

        end

        if (load_buf_id !== 1'b1) begin

            $display("FAIL T6: load_buf_id=%b expected PONG(1)",
                     load_buf_id);

            errors = errors + 1;

        end else begin

            $display("PASS T6: load selection switched to PONG");

        end

        // =====================================================
        // T7 — THREE CONSECUTIVE OPERATIONS
        //
        // PING -> PONG -> PING
        // =====================================================
        $display("");
        $display("--- T7: Consecutive PING/PONG/PING ---");

        // -----------------------------------------------------
        // Operation 1: PING
        // -----------------------------------------------------
        // Current PING is READY.
        start_compute;

        if (ping_state !== ST_COMPUTING) begin

            $display("FAIL T7.1: PING not COMPUTING");
            errors = errors + 1;

        end else begin

            $display("PASS T7.1: PING COMPUTING");

        end

        finish_compute(2);

        if (ping_state !== ST_FREE) begin

            $display("FAIL T7.1: PING not FREE after compute");
            errors = errors + 1;

        end

        // -----------------------------------------------------
        // Operation 2: load PONG, then compute PONG
        // -----------------------------------------------------
        if (load_buf_id !== 1'b1) begin

            $display("FAIL T7.2 pre: expected PONG load");
            errors = errors + 1;

        end

        load_tile;

        if (pong_state !== ST_READY) begin

            $display("FAIL T7.2: PONG not READY");
            errors = errors + 1;

        end

        start_compute;

        if (pong_state !== ST_COMPUTING) begin

            $display("FAIL T7.2: PONG not COMPUTING");
            errors = errors + 1;

        end else begin

            $display("PASS T7.2: PONG COMPUTING");

        end

        finish_compute(2);

        if (pong_state !== ST_FREE) begin

            $display("FAIL T7.2: PONG not FREE after compute");
            errors = errors + 1;

        end

        // -----------------------------------------------------
        // Operation 3: load PING, then compute PING
        // -----------------------------------------------------
        if (load_buf_id !== 1'b0) begin

            $display("FAIL T7.3 pre: expected PING load");
            errors = errors + 1;

        end

        load_tile;

        if (ping_state !== ST_READY) begin

            $display("FAIL T7.3: PING not READY");
            errors = errors + 1;

        end

        start_compute;

        if (ping_state !== ST_COMPUTING) begin

            $display("FAIL T7.3: PING not COMPUTING");
            errors = errors + 1;

        end else begin

            $display("PASS T7.3: PING COMPUTING");

        end

        finish_compute(2);

        if (ping_state !== ST_FREE) begin

            $display("FAIL T7.3: PING not FREE after compute");
            errors = errors + 1;

        end

        // =====================================================
        // T8 — ILLEGAL WRITE TO COMPUTING BANK
        //
        // Construct:
        //   PING = COMPUTING
        //   PONG = READY
        //   load_buf_id = PING
        //
        // Then attempt to overwrite PING.
        // =====================================================
        $display("");
        $display("--- T8: Illegal write to COMPUTING bank ---");

        // Load PING first.
        if (load_buf_id !== 1'b0) begin

            $display("FAIL T8 pre1: expected PING load");
            errors = errors + 1;

        end

        load_tile;

        // PING READY.
        // PONG is FREE.

        // Load PONG as well so both banks are occupied.
        if (load_buf_id !== 1'b1) begin

            $display("FAIL T8 pre2: expected PONG load");
            errors = errors + 1;

        end

        load_tile;

        // Both READY. Start PING.
        start_compute;

        if (ping_state !== ST_COMPUTING ||
            pong_state !== ST_READY) begin

            $display("FAIL T8 setup: ping=%b pong=%b",
                     ping_state, pong_state);

            errors = errors + 1;

        end

        // At this point load_sel remains PONG.
        // Finish PING so PING becomes FREE.
        finish_compute(2);

        // load_sel should now become PING.
        if (load_buf_id !== 1'b0) begin

            $display("FAIL T8 setup2: expected load_buf_id=PING, got %b",
                     load_buf_id);

            errors = errors + 1;

        end

        // PING is FREE, PONG READY.
        // Load PING again.
        load_tile;

        // Both READY. Start PING.
        start_compute;

        if (ping_state !== ST_COMPUTING ||
            pong_state !== ST_READY) begin

            $display("FAIL T8 setup3: ping=%b pong=%b",
                     ping_state, pong_state);

            errors = errors + 1;

        end

        // load_sel must still point to PING.
        if (load_buf_id !== 1'b0) begin

            $display("FAIL T8 setup4: load_buf_id=%b expected PING",
                     load_buf_id);

            errors = errors + 1;

        end

        // -----------------------------------------------------
        // Save current A[0].
        // -----------------------------------------------------
        @(posedge clk);
        #1;

        if (A_out[7:0] !== 8'd1) begin

            $display("FAIL T8 pre: A[0]=%0d expected 1",
                     A_out[7:0]);

            errors = errors + 1;

        end

        // -----------------------------------------------------
        // Attempt illegal write to PING while COMPUTING.
        // -----------------------------------------------------
        wr_en   = 1'b1;
        wr_addr = 7'd0;
        wr_data = 8'hFF;

        @(posedge clk);
        #1;

        wr_en = 1'b0;

        // -----------------------------------------------------
        // Verify corruption did NOT occur.
        // -----------------------------------------------------
        if (A_out[7:0] !== 8'd1) begin

            $display("FAIL T8: COMPUTING bank CORRUPTED! A[0]=%0d",
                     A_out[7:0]);

            errors = errors + 1;

        end else begin

            $display("PASS T8: illegal write rejected; COMPUTING bank protected");

        end

        // Finish the compute.
        finish_compute(2);

        // =====================================================
        // T9 — compute_start WITHOUT READY BANK
        // =====================================================
        $display("");
        $display("--- T9: compute_start with no READY bank ---");

        // Current state should be:
        // PING FREE
        // PONG READY
        //
        // First finish/use PONG so both become FREE.
        start_compute;

        finish_compute(2);

        if (ping_state !== ST_FREE ||
            pong_state !== ST_FREE) begin

            $display("FAIL T9 pre: ping=%b pong=%b",
                     ping_state, pong_state);

            errors = errors + 1;

        end

        if (compute_valid !== 1'b0) begin

            $display("FAIL T9 pre: compute_valid=%b expected 0",
                     compute_valid);

            errors = errors + 1;

        end

        // Attempt compute with no READY buffer.
        start_compute;

        if (ping_state !== ST_FREE ||
            pong_state !== ST_FREE) begin

            $display("FAIL T9: state changed unexpectedly");

            errors = errors + 1;

        end else begin

            $display("PASS T9: compute_start rejected with no READY bank");

        end

        // =====================================================
        // T10 — DATA INTEGRITY
        // =====================================================
        $display("");
        $display("--- T10: Data integrity ---");

        // Load PING.
        if (load_buf_id !== 1'b0) begin

            $display("FAIL T10 pre: expected PING load");
            errors = errors + 1;

        end

        load_tile;

        // Verify selected PING bytes.
        // compute_sel still points to PING from previous compute.
        if (A_out[7:0] !== 8'd1) begin

            $display("FAIL T10 A00: got %0d expected 1",
                     A_out[7:0]);

            errors = errors + 1;

        end

        if (A_out[15:8] !== 8'd2) begin

            $display("FAIL T10 A01: got %0d expected 2",
                     A_out[15:8]);

            errors = errors + 1;

        end

        if (A_out[63:56] !== 8'd8) begin

            $display("FAIL T10 A07: got %0d expected 8",
                     A_out[63:56]);

            errors = errors + 1;

        end

        if (B_out[7:0] !== 8'd1) begin

            $display("FAIL T10 B00: got %0d expected 1",
                     B_out[7:0]);

            errors = errors + 1;

        end

        if (B_out[15:8] !== 8'd2) begin

            $display("FAIL T10 B01: got %0d expected 2",
                     B_out[15:8]);

            errors = errors + 1;

        end

        if (errors == 0)
            $display("PASS T10: data integrity verified");

        // =====================================================
        // FINAL
        // =====================================================
        $display("");
        $display("=========================================");

        if (errors == 0)
            $display("ALL PING-PONG BUFFER TESTS PASSED");
        else
            $display("%0d ERROR(S) DETECTED", errors);

        $display("=========================================");

        $finish;

    end

endmodule
