//==============================================================================
// Module: agvme_core
// Project: AGVME - AgentGate-V MAC Engine
//
// Description:
//   Top-level wrapper for the systolic array core. Instantiates the array, 
//   the input skew buffers, the output drain, and the main controller.
//==============================================================================

module agvme_core #(
    parameter N      = 8,
    parameter CH_W   = 8,
    parameter ADDR_W = 9
)(
    input  wire                 clk,
    input  wire                 rst_n,

    // Execution control
    input  wire                 start,
    input  wire [ADDR_W-1:0]    K_dim,
    output wire                 busy,
    output wire                 done,

    // Stream control to/from loaders
    output wire                 start_loaders,
    input  wire                 loaders_done,

    // Flat data streams from Loaders
    input  wire [N*CH_W-1:0]    a_stream_in,
    input  wire                 a_stream_valid,
    input  wire [N*CH_W-1:0]    w_stream_in,
    input  wire                 w_stream_valid,

    // Result stream out to Post-Processor
    output wire                 out_valid,
    output wire [31:0]          out_data
);

    // Controller <-> Array signals
    wire array_en;
    wire array_clr;
    
    // Controller <-> Drain signals
    wire start_drain;
    wire drain_done;

    // Internal data routing
    wire [N*CH_W-1:0] a_skewed;
    wire [N*CH_W-1:0] w_skewed;
    
    // Daisy Chain signals
    wire        shift_en;
    wire [31:0] acc_chain_out;

    //--------------------------------------------------------------------------
    // Main FSM Controller
    //--------------------------------------------------------------------------
    main_controller #(
        .N(N),
        .ADDR_W(ADDR_W)
    ) u_ctrl (
        .clk           (clk),
        .rst_n         (rst_n),
        .start         (start),
        .K_dim         (K_dim),
        .busy          (busy),
        .done          (done),
        .start_loaders (start_loaders),
        .loaders_done  (loaders_done),
        .start_drain   (start_drain),
        .drain_done    (drain_done),
        .array_en      (array_en),
        .array_clr     (array_clr)
    );

    //--------------------------------------------------------------------------
    // Data Gating (Zero-out invalid data)
    //--------------------------------------------------------------------------
    wire [N*CH_W-1:0] a_gated = a_stream_valid ? a_stream_in : {(N*CH_W){1'b0}};
    wire [N*CH_W-1:0] w_gated = w_stream_valid ? w_stream_in : {(N*CH_W){1'b0}};

    //--------------------------------------------------------------------------
    // Input Skew Buffers
    //--------------------------------------------------------------------------
    input_skew #(
        .N(N),
        .CH_W(CH_W)
    ) u_skew_a (
        .clk      (clk),
        .rst_n    (rst_n),
        .en       (array_en),
        .data_in  (a_gated),
        .data_out (a_skewed)
    );

    input_skew #(
        .N(N),
        .CH_W(CH_W)
    ) u_skew_w (
        .clk      (clk),
        .rst_n    (rst_n),
        .en       (array_en),
        .data_in  (w_gated),
        .data_out (w_skewed)
    );

    //--------------------------------------------------------------------------
    // 8x8 Systolic Array
    //--------------------------------------------------------------------------
    systolic_array_8x8 #(
        .N(N),
        .CH_W(CH_W),
        .ACC_W(32)
    ) u_array (
        .clk           (clk),
        .rst_n         (rst_n),
        .en            (array_en),
        .clr           (array_clr),
        .shift_en      (shift_en),
        .a_in_skewed   (a_skewed),
        .w_in_skewed   (w_skewed),
        .acc_chain_out (acc_chain_out)
    );

    //--------------------------------------------------------------------------
    // Output Drain (Daisy Chain Pumper)
    //--------------------------------------------------------------------------
    output_drain #(
        .N(N),
        .ACC_W(32)
    ) u_drain (
        .clk           (clk),
        .rst_n         (rst_n),
        .start         (start_drain),
        .done          (drain_done),
        .acc_in_serial (acc_chain_out),
        .shift_en      (shift_en),
        .valid_out     (out_valid),
        .data_out      (out_data)
    );

endmodule