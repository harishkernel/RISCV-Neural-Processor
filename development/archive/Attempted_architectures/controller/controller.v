`timescale 1ns/1ps

// ============================================================
// 8x8 Systolic Array Controller
//
// Interface:
//   start       : pulse high for 1 clock cycle
//   busy        : high while an operation is running
//   done        : high for 1 clock cycle when result is ready
//   cycle_count : number of clock cycles for the systolic
//                 computation itself
//
// Operation:
//   IDLE -> RESET_ARRAY -> COMPUTE -> DONE
//
// IMPORTANT:
// The verified systolic8x8 core requires 23 enabled clock cycles
// for the current implementation to produce all 64 outputs
// correctly. This was established by the existing 8x8 testbench:
// 17 cycles was insufficient, while 23 cycles passed 64/64.
// ============================================================

module controller (
    input  wire         clk,
    input  wire         rst_n,       // active-low external reset

    // Handshake
    input  wire         start,
    output reg          done,
    output reg          busy,

    // 8x8 matrices, 64 unsigned 8-bit values each
    input  wire [511:0] A_flat,
    input  wire [511:0] B_flat,

    // 8x8 result, 64 unsigned 32-bit values
    output wire [31:0] C00, C01, C02, C03, C04, C05, C06, C07,
    output wire [31:0] C10, C11, C12, C13, C14, C15, C16, C17,
    output wire [31:0] C20, C21, C22, C23, C24, C25, C26, C27,
    output wire [31:0] C30, C31, C32, C33, C34, C35, C36, C37,
    output wire [31:0] C40, C41, C42, C43, C44, C45, C46, C47,
    output wire [31:0] C50, C51, C52, C53, C54, C55, C56, C57,
    output wire [31:0] C60, C61, C62, C63, C64, C65, C66, C67,
    output wire [31:0] C70, C71, C72, C73, C74, C75, C76, C77,

    // Number of enabled compute clocks used by the array
    output reg [31:0] cycle_count
);

    // =========================================================
    // FSM states
    // =========================================================
    localparam S_IDLE        = 2'd0;
    localparam S_RESET_ARRAY = 2'd1;
    localparam S_COMPUTE     = 2'd2;
    localparam S_DONE        = 2'd3;

    reg [1:0] state;

    // 5 bits are enough for 0..22
    reg [4:0] compute_counter;

    // The verified current 8x8 systolic implementation needs
    // 23 enabled clock cycles.
    localparam [4:0] COMPUTE_CYCLES = 5'd23;

    // Systolic-array controls
    reg sys_reset;
    reg sys_enable;

    // =========================================================
    // Systolic array
    // =========================================================
    systolic8x8 array (
        .clk(clk),
        .reset(sys_reset),
        .enable(sys_enable),

        .A(A_flat),
        .B(B_flat),

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
        .C74(C74), .C75(C75), .C76(C76), .C77(C77)
    );

    // =========================================================
    // Controller FSM
    // =========================================================
    always @(posedge clk or negedge rst_n) begin

        if (!rst_n) begin
            state           <= S_IDLE;
            sys_reset       <= 1'b1;
            sys_enable      <= 1'b0;
            done            <= 1'b0;
            busy            <= 1'b0;
            compute_counter <= 5'd0;
            cycle_count     <= 32'd0;
        end

        else begin

            case (state)

                // ------------------------------------------------
                // IDLE
                // ------------------------------------------------
                S_IDLE: begin
                    done       <= 1'b0;
                    sys_reset  <= 1'b0;
                    sys_enable <= 1'b0;

                    if (start) begin
                        busy            <= 1'b1;
                        sys_reset       <= 1'b1;
                        sys_enable      <= 1'b0;
                        compute_counter <= 5'd0;
                        cycle_count     <= 32'd0;
                        state           <= S_RESET_ARRAY;
                    end
                end

                // ------------------------------------------------
                // RESET_ARRAY
                //
                // sys_reset is held high for this complete clock
                // period. At the next clock edge the array is
                // reset, after which reset is released and compute
                // begins.
                // ------------------------------------------------
                S_RESET_ARRAY: begin
                    sys_reset       <= 1'b0;
                    sys_enable      <= 1'b1;
                    compute_counter <= 5'd0;
                    cycle_count     <= 32'd0;
                    state           <= S_COMPUTE;
                end

                // ------------------------------------------------
                // COMPUTE
                //
                // 23 enabled clock edges are provided to the
                // verified systolic8x8 implementation.
                // ------------------------------------------------
                S_COMPUTE: begin
                    cycle_count <= cycle_count + 32'd1;

                    if (compute_counter == COMPUTE_CYCLES - 1) begin
                        sys_enable <= 1'b0;
                        state      <= S_DONE;
                    end
                    else begin
                        compute_counter <= compute_counter + 5'd1;
                    end
                end

                // ------------------------------------------------
                // DONE
                //
                // Results are now stable on C00..C77.
                // done is a one-clock completion pulse.
                // ------------------------------------------------
                S_DONE: begin
                    done       <= 1'b1;
                    busy       <= 1'b0;
                    sys_reset  <= 1'b0;
                    sys_enable <= 1'b0;
                    state      <= S_IDLE;
                end

                default: begin
                    state           <= S_IDLE;
                    sys_reset       <= 1'b1;
                    sys_enable      <= 1'b0;
                    done            <= 1'b0;
                    busy            <= 1'b0;
                    compute_counter <= 5'd0;
                    cycle_count     <= 32'd0;
                end

            endcase
        end
    end

endmodule