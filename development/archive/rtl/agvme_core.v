//==============================================================================
// Module:  agvme_core
// Project: AGVME — AgentGate-V MAC Engine
// Target:  Gowin GW5A-LV25MG121
//
// Description:
//   Top-level wrapper for the accelerator core (without host CSR/DMA).
//   Integrates:
//     - 8x8 Systolic Array
//     - Input Skews
//     - Weight and Activation Loaders
//     - Main Controller FSM
//     - Output Drain
//     - Post Processor (Bias, ReLU, Requantize)
//
//   Note: Ping-Pong BSRAMs are instantiated outside this core, or fed 
//   directly via ports for now, to keep memory separate from compute logic.
//==============================================================================

module agvme_core #(
    parameter N = 8,
    parameter ADDR_W = 9,
    parameter DATA_W = 64
)(
    input  wire                 clk,
    input  wire                 rst_n,

    // Execution Control (from CSR)
    input  wire                 start,
    input  wire [ADDR_W-1:0]    K_dim,
    output wire                 busy,
    output wire                 done,

    // Post-Processing Params (from CSR)
    input  wire signed [31:0]   bias,
    input  wire signed [15:0]   scale_mult,
    input  wire [4:0]           scale_shift,
    input  wire                 en_relu,

    // BSRAM Read Interfaces (To Memory Subsystem)
    // Activation BSRAM
    output wire                 act_rd_en,
    output wire [ADDR_W-1:0]    act_addr,
    input  wire [DATA_W-1:0]    act_data,
    
    // Weight BSRAM
    output wire                 wt_rd_en,
    output wire [ADDR_W-1:0]    wt_addr,
    input  wire [DATA_W-1:0]    wt_data,

    // Streamed Output (To Host / Next Layer)
    output wire                 out_valid,
    output wire signed [7:0]    out_data
);

    // ---- Internal Signals ----
    wire start_loaders;
    wire start_drain;
    wire loaders_done;
    wire drain_done;
    wire array_en;
    wire array_clr;
    
    wire act_valid;
    wire [DATA_W-1:0] act_raw;
    wire [DATA_W-1:0] act_skewed;

    wire wt_valid;
    wire [DATA_W-1:0] wt_raw;
    wire [DATA_W-1:0] wt_skewed;

    wire [(N*N*32)-1:0] acc_out_flat;
    
    wire drain_valid;
    wire signed [31:0] drain_data;
    
    wire act_loader_done;
    wire wt_loader_done;
    
    wire pipeline_valid = act_valid & wt_valid;
    wire force_zeros;

    // ---- Main Controller ----
    main_controller #(
        .N(N),
        .ADDR_W(ADDR_W)
    ) u_ctrl (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .K_dim(K_dim),
        .pipeline_valid(pipeline_valid),
        .busy(busy),
        .done(done),
        .start_loaders(start_loaders),
        // Assume loaders finish at the same time since K_dim is shared
        .loaders_done(wt_loader_done & act_loader_done), 
        .start_drain(start_drain),
        .drain_done(drain_done),
        .array_en(array_en),
        .force_zeros(force_zeros),
        .array_clr(array_clr)
    );

    // ---- Activation Loader & Skew ----
    activation_feeder #(
        .ADDR_W(ADDR_W),
        .DATA_W(DATA_W)
    ) u_act_feeder (
        .clk(clk),
        .rst_n(rst_n),
        .start(start_loaders),
        .K_dim(K_dim),
        .done(act_loader_done),
        .bsram_rd_en(act_rd_en),
        .bsram_addr(act_addr),
        .bsram_data(act_data),
        .valid_out(act_valid),
        .data_out(act_raw)
    );

    wire [DATA_W-1:0] act_skew_in = force_zeros ? {DATA_W{1'b0}} : act_raw;

    input_skew #(
        .N(N),
        .CH_W(DATA_W / N)
    ) u_skew_a (
        .clk(clk),
        .rst_n(rst_n),
        .en(array_en),
        .data_in(act_skew_in),
        .data_out(act_skewed)
    );

    // ---- Weight Loader & Skew ----
    weight_loader #(
        .ADDR_W(ADDR_W),
        .DATA_W(DATA_W)
    ) u_wt_loader (
        .clk(clk),
        .rst_n(rst_n),
        .start(start_loaders),
        .K_dim(K_dim),
        .done(wt_loader_done),
        .bsram_rd_en(wt_rd_en),
        .bsram_addr(wt_addr),
        .bsram_data(wt_data),
        .valid_out(wt_valid),
        .data_out(wt_raw)
    );

    wire [DATA_W-1:0] wt_skew_in = force_zeros ? {DATA_W{1'b0}} : wt_raw;

    input_skew #(
        .N(N),
        .CH_W(DATA_W / N)
    ) u_skew_w (
        .clk(clk),
        .rst_n(rst_n),
        .en(array_en),
        .data_in(wt_skew_in),
        .data_out(wt_skewed)
    );

    // ---- 8x8 Systolic Array ----
    systolic_array_8x8 #(
        .N(N)
    ) u_array (
        .clk(clk),
        .rst_n(rst_n),
        .en(array_en),
        .clr_acc(array_clr),
        .a_in(act_skewed),
        .w_in(wt_skewed),
        .acc_out(acc_out_flat)
    );

    // ---- Output Drain ----
    output_drain #(
        .N(N),
        .ACC_W(32)
    ) u_drain (
        .clk(clk),
        .rst_n(rst_n),
        .start(start_drain),
        .busy(),
        .valid(drain_valid),
        .done(drain_done),
        .acc_in(acc_out_flat),
        .data_out(drain_data)
    );

    // ---- Post Processor ----
    post_processor u_post (
        .clk(clk),
        .rst_n(rst_n),
        .valid_in(drain_valid),
        .data_in(drain_data),
        .bias(bias),
        .scale_mult(scale_mult),
        .scale_shift(scale_shift),
        .en_relu(en_relu),
        .valid_out(out_valid),
        .data_out(out_data)
    );

endmodule
