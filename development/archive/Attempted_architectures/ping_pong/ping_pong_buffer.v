`timescale 1ns/1ps

// =============================================================
// ping_pong_buffer.v
//
// Two-bank ping-pong tile buffer.
//
// Each bank stores 128 bytes:
//   address 0..63   = A matrix
//   address 64..127 = B matrix
//
// Bank states:
//   FREE       : available for loading
//   LOADING    : currently receiving a tile
//   READY      : tile completely loaded and available for compute
//   COMPUTING  : currently being processed
//
// load_sel:
//   0 = PING
//   1 = PONG
//
// compute_sel:
//   0 = PING
//   1 = PONG
//
// Reset:
//   synchronous, active-high
// =============================================================

module ping_pong_buffer #(
    parameter DATA_WIDTH = 8,
    parameter DEPTH      = 128
)(
    input  wire                   clk,
    input  wire                   reset,

    // ---------------------------------------------------------
    // Load interface
    // ---------------------------------------------------------
    input  wire                   wr_en,
    input  wire [6:0]             wr_addr,
    input  wire [DATA_WIDTH-1:0]  wr_data,
    input  wire                   load_done,

    output wire                   load_ready,
    output wire                   load_buf_id,

    // ---------------------------------------------------------
    // Compute interface
    // ---------------------------------------------------------
    input  wire                   compute_start,
    input  wire                   compute_done,

    output wire [511:0]           A_out,
    output wire [511:0]           B_out,
    output wire                   compute_valid,

    // ---------------------------------------------------------
    // Debug
    // ---------------------------------------------------------
    output wire [1:0]             ping_state,
    output wire [1:0]             pong_state
);

    // ---------------------------------------------------------
    // State encoding
    // ---------------------------------------------------------
    localparam [1:0] ST_FREE      = 2'b00;
    localparam [1:0] ST_LOADING   = 2'b01;
    localparam [1:0] ST_READY     = 2'b10;
    localparam [1:0] ST_COMPUTING = 2'b11;

    // ---------------------------------------------------------
    // Memory
    // ---------------------------------------------------------
    reg [DATA_WIDTH-1:0] ping_mem [0:DEPTH-1];
    reg [DATA_WIDTH-1:0] pong_mem [0:DEPTH-1];

    // ---------------------------------------------------------
    // State registers
    // ---------------------------------------------------------
    reg [1:0] ping_st;
    reg [1:0] pong_st;

    // ---------------------------------------------------------
    // Selection registers
    // ---------------------------------------------------------
    reg load_sel;
    reg compute_sel;

    // Records a PING tile completed after the preceding compute boundary.
    // This is the only history needed to disambiguate the required
    // PING -> PONG -> PING scheduling sequence when both banks are FREE.
    reg ping_loaded_since_compute_done;

    // ---------------------------------------------------------
    // Select READY bank for computation.
    //
    // If both banks are READY, PING has priority.
    // ---------------------------------------------------------
    wire compute_sel_next;

    assign compute_sel_next =
        (ping_st == ST_READY) ? 1'b0 :
        (pong_st == ST_READY) ? 1'b1 :
                                compute_sel;

    // ---------------------------------------------------------
    // Status outputs
    // ---------------------------------------------------------
    assign load_ready =
        (ping_st == ST_FREE) ||
        (pong_st == ST_FREE);

    assign load_buf_id = load_sel;

    assign compute_valid =
        (ping_st == ST_READY) ||
        (pong_st == ST_READY);

    assign ping_state = ping_st;
    assign pong_state = pong_st;

    // ---------------------------------------------------------
    // Write protection
    //
    // Only FREE or LOADING bank may be written.
    //
    // READY and COMPUTING banks are protected.
    // ---------------------------------------------------------
    wire ping_wr_ok =
        (load_sel == 1'b0) &&
        ((ping_st == ST_FREE) ||
         (ping_st == ST_LOADING));

    wire pong_wr_ok =
        (load_sel == 1'b1) &&
        ((pong_st == ST_FREE) ||
         (pong_st == ST_LOADING));

    // ---------------------------------------------------------
    // Memory writes
    // ---------------------------------------------------------
    always @(posedge clk) begin

        if (wr_en && ping_wr_ok)
            ping_mem[wr_addr] <= wr_data;

        if (wr_en && pong_wr_ok)
            pong_mem[wr_addr] <= wr_data;

    end

    // ---------------------------------------------------------
    // Combinational readout
    //
    // A = bytes 0..63
    // B = bytes 64..127
    // ---------------------------------------------------------
    genvar k;

    generate

        for (k = 0; k < 64; k = k + 1) begin : rd_bus

            assign A_out[k*8 +: 8] =
                (compute_sel == 1'b0) ?
                    ping_mem[k] :
                    pong_mem[k];

            assign B_out[k*8 +: 8] =
                (compute_sel == 1'b0) ?
                    ping_mem[k + 64] :
                    pong_mem[k + 64];

        end

    endgenerate

    // ---------------------------------------------------------
    // State machines
    // ---------------------------------------------------------
    always @(posedge clk) begin

        if (reset) begin

            ping_st     <= ST_FREE;
            pong_st     <= ST_FREE;

            // First tile loads into PING.
            load_sel    <= 1'b0;

            compute_sel <= 1'b0;
            ping_loaded_since_compute_done <= 1'b0;

        end else begin

            // A completion establishes a scheduling boundary.  The old
            // value is deliberately used by the selector logic below on
            // this edge; nonblocking assignment then clears it for the
            // next interval.  A completed PING load sets it later.
            if (compute_done)
                ping_loaded_since_compute_done <= 1'b0;
            else if (load_done && (load_sel == 1'b0))
                ping_loaded_since_compute_done <= 1'b1;

            // =================================================
            // PING STATE
            // =================================================
            case (ping_st)

                ST_FREE: begin

                    if ((load_sel == 1'b0) && wr_en)
                        ping_st <= ST_LOADING;

                end

                ST_LOADING: begin

                    if (load_done)
                        ping_st <= ST_READY;

                end

                ST_READY: begin

                    if (compute_start &&
                        compute_valid &&
                        (compute_sel_next == 1'b0))
                        ping_st <= ST_COMPUTING;

                end

                ST_COMPUTING: begin

                    if (compute_done)
                        ping_st <= ST_FREE;

                end

                default: begin
                    ping_st <= ST_FREE;
                end

            endcase

            // =================================================
            // PONG STATE
            // =================================================
            case (pong_st)

                ST_FREE: begin

                    if ((load_sel == 1'b1) && wr_en)
                        pong_st <= ST_LOADING;

                end

                ST_LOADING: begin

                    if (load_done)
                        pong_st <= ST_READY;

                end

                ST_READY: begin

                    if (compute_start &&
                        compute_valid &&
                        (compute_sel_next == 1'b1))
                        pong_st <= ST_COMPUTING;

                end

                ST_COMPUTING: begin

                    if (compute_done)
                        pong_st <= ST_FREE;

                end

                default: begin
                    pong_st <= ST_FREE;
                end

            endcase

            // =================================================
            // COMPUTE SELECTION
            //
            // Capture the READY bank exactly when computation
            // starts.
            // =================================================
            if (compute_start && compute_valid)
                compute_sel <= compute_sel_next;

            // =================================================
            // LOAD SELECTION
            //
            // The ordering below is intentional.
            //
            // -------------------------------------------------
            // CASE 1:
            // A LOAD FINISHES
            // -------------------------------------------------
            // The bank that was loading becomes READY.
            //
            // Prefer the opposite bank if it is FREE.
            // -------------------------------------------------
            if (load_done) begin

                if (load_sel == 1'b0) begin

                    // PING became READY.
                    if (pong_st == ST_FREE)
                        load_sel <= 1'b1;

                end else begin

                    // PONG became READY.
                    if (ping_st == ST_FREE)
                        load_sel <= 1'b0;

                end

            end

            // =================================================
            // CASE 2:
            // COMPUTATION STARTS
            // =================================================
            //
            // If the opposite bank is FREE, select it for
            // loading immediately.
            //
            // This enables:
            //
            //   PING COMPUTING + PONG LOADING
            //
            // or:
            //
            //   PONG COMPUTING + PING LOADING
            // =================================================
            else if (compute_start && compute_valid) begin

                if (compute_sel_next == 1'b0) begin

                    // PING is computing.
                    // PONG is the candidate load bank.
                    if (pong_st == ST_FREE)
                        load_sel <= 1'b1;
                end else begin

                    // PONG is computing.
                    // PING is the candidate load bank.
                    if (ping_st == ST_FREE)
                        load_sel <= 1'b0;
                end
            end

            // =================================================
            // CASE 3:
            // COMPUTATION FINISHES
            // =================================================
            //
            // The computing bank becomes FREE.
            //
            // If the other bank is not already being loaded,
            // select the newly freed bank.
            // =================================================
            else if (compute_done) begin

                if (compute_sel == 1'b0) begin

                    // PING becomes FREE.
                    // Redirect load_sel to PING ONLY if the current load
                    // target (PONG) is unavailable (READY or COMPUTING).
                    // If PONG is FREE or LOADING it is still usable; keep it.

                    if ((ping_loaded_since_compute_done) &&
                        (load_sel == 1'b1) && (pong_st == ST_FREE))
                        load_sel <= 1'b0;
                    else if ((load_sel == 1'b1) &&
                             (pong_st != ST_FREE) &&
                             (pong_st != ST_LOADING))
                        load_sel <= 1'b0;

                end else begin

                    // PONG becomes FREE.
                    // Redirect load_sel to PONG ONLY if the current load
                    // target (PING) is unavailable (READY or COMPUTING).
                    // If PING is FREE or LOADING it is still usable; keep it.
                    if ((load_sel == 1'b0) &&
                             (ping_st != ST_FREE) &&
                             (ping_st != ST_LOADING))
                        load_sel <= 1'b1;

                end
            end
        end
    end
endmodule