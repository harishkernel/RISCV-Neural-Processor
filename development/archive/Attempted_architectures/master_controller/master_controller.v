`timescale 1ns/1ps

// =============================================================
// ping_pong_top.v
//
// Integration:
//     ping_pong_buffer + controller + systolic8x8
//
// Responsibilities:
//
//   ping_pong_buffer
//       - Owns PING/PONG storage
//       - Manages LOAD/READY/COMPUTING/FREE states
//       - Selects the bank used for computation
//       - Provides A_out/B_out
//
//   controller
//       - Controls systolic8x8
//       - Resets the array before each operation
//       - Runs the verified 23 compute cycles
//       - Generates compute_done
//
// IMPORTANT:
//   compute_start is accepted only when:
//       1. A buffer is READY
//       2. Controller is idle
//
//   This prevents a spurious compute_start from starting the
//   controller when both PING and PONG are FREE.
// =============================================================

module master_controller (
    input  wire       clk,
    input  wire       rst_n,

    // ---------------------------------------------------------
    // Load interface
    // ---------------------------------------------------------
    input  wire       wr_en,
    input  wire [6:0] wr_addr,
    input  wire [7:0] wr_data,
    input  wire       load_done,

    output wire       load_ready,
    output wire       load_buf_id,

    // ---------------------------------------------------------
    // Compute interface
    // ---------------------------------------------------------
    input  wire       compute_start,

    output wire       compute_valid,
    output wire       compute_busy,
    output wire       compute_done,

    // ---------------------------------------------------------
    // Results
    // ---------------------------------------------------------
    output wire [31:0] C00, C01, C02, C03,
    output wire [31:0] C04, C05, C06, C07,

    output wire [31:0] C10, C11, C12, C13,
    output wire [31:0] C14, C15, C16, C17,

    output wire [31:0] C20, C21, C22, C23,
    output wire [31:0] C24, C25, C26, C27,

    output wire [31:0] C30, C31, C32, C33,
    output wire [31:0] C34, C35, C36, C37,

    output wire [31:0] C40, C41, C42, C43,
    output wire [31:0] C44, C45, C46, C47,

    output wire [31:0] C50, C51, C52, C53,
    output wire [31:0] C54, C55, C56, C57,

    output wire [31:0] C60, C61, C62, C63,
    output wire [31:0] C64, C65, C66, C67,

    output wire [31:0] C70, C71, C72, C73,
    output wire [31:0] C74, C75, C76, C77,

    // ---------------------------------------------------------
    // Debug / monitoring
    // ---------------------------------------------------------
    output wire [1:0] ping_state,
    output wire [1:0] pong_state,
    output wire [31:0] cycle_count
);

    // =========================================================
    // Reset conversion
    //
    // External:
    //     rst_n = active-low
    //
    // ping_pong_buffer:
    //     reset = active-high
    // =========================================================

    wire reset_pp = ~rst_n;

    // =========================================================
    // Internal connections
    // =========================================================

    wire [511:0] A_buf;
    wire [511:0] B_buf;

    wire buf_compute_valid;

    wire ctrl_done;
    wire ctrl_busy;

    // =========================================================
    // Compute-start qualification
    //
    // A compute request is accepted ONLY if:
    //
    //   - a READY buffer exists
    //   - controller is not already busy
    //
    // This is the critical integration guard.
    // =========================================================

    wire safe_compute_start =
        compute_start &&
        buf_compute_valid &&
        !ctrl_busy;

    // =========================================================
    // PING-PONG BUFFER
    // =========================================================

    ping_pong_buffer #(
        .DATA_WIDTH(8),
        .DEPTH(128)
    ) ppb (
        .clk           (clk),
        .reset         (reset_pp),

        // Load
        .wr_en         (wr_en),
        .wr_addr       (wr_addr),
        .wr_data       (wr_data),
        .load_done     (load_done),

        .load_ready    (load_ready),
        .load_buf_id   (load_buf_id),

        // Compute
        .compute_start (safe_compute_start),
        .compute_done  (ctrl_done),

        .A_out         (A_buf),
        .B_out         (B_buf),
        .compute_valid (buf_compute_valid),

        // Debug
        .ping_state    (ping_state),
        .pong_state    (pong_state)
    );

    // =========================================================
    // External compute status
    // =========================================================

    assign compute_valid = buf_compute_valid;
    assign compute_busy  = ctrl_busy;
    assign compute_done  = ctrl_done;

    // =========================================================
    // COMPUTE CONTROLLER
    //
    // A_buf/B_buf come directly from the bank selected by
    // ping_pong_buffer's compute_sel register.
    //
    // The controller itself does NOT decide PING/PONG.
    // =========================================================

    controller ctrl (
        .clk        (clk),
        .rst_n      (rst_n),
        .start      (safe_compute_start),
        .done       (ctrl_done),
        .busy       (ctrl_busy),
        .A_flat     (A_buf),
        .B_flat     (B_buf),

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

        .cycle_count(cycle_count)
    );
endmodule