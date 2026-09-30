//==============================================================================
// Module:  agvme_top
// Project: AGVME - AgentGate-V MAC Engine
//
// Description:
//   Top-level wrapper that instantiates the entire Neural Network system:
//   1. BSRAM Ping-Pong Buffers
//   2. Loaders (Activation Feeder, Weight Loader)
//   3. Compute Core (Systolic Array)
//   4. Post-Processor (Bias, ReLU, Requantization)
//==============================================================================

module agvme_top #(
    parameter N = 8,
    parameter ADDR_W = 9,
    parameter DATA_W = 64
)(
    input  wire                 clk,
    input  wire                 rst_n,

    // Execution Control
    input  wire                 start,
    input  wire [ADDR_W-1:0]    K_dim,
    output wire                 busy,
    output wire                 done,

    // Post-Processing Params
    input  wire signed [31:0]   bias,
    input  wire signed [15:0]   scale_mult,
    input  wire [4:0]           scale_shift,
    input  wire                 en_relu,

    // Host DMA Write Interface - Activations (Ping-Pong)
    input  wire                 host_act_bank_sel,
    input  wire                 host_act_wr_en,
    input  wire [ADDR_W-1:0]    host_act_wr_addr,
    input  wire [DATA_W-1:0]    host_act_wr_data,

    // Host DMA Write Interface - Weights (Ping-Pong)
    input  wire                 host_wt_bank_sel,
    input  wire                 host_wt_wr_en,
    input  wire [ADDR_W-1:0]    host_wt_wr_addr,
    input  wire [DATA_W-1:0]    host_wt_wr_data,

    // Streamed Output (To Host / Next Layer)
    output wire                 out_valid,
    output wire signed [7:0]    out_data
);

    // =========================================================================
    // Internal Wiring
    // =========================================================================
    
    // Core <-> Loaders
    wire start_loaders;
    wire act_loader_done;
    wire wt_loader_done;
    wire loaders_done = act_loader_done & wt_loader_done;
    
    // BSRAM <-> Loaders
    wire              act_rd_en;
    wire [ADDR_W-1:0] act_addr;
    wire [DATA_W-1:0] act_data;

    wire              wt_rd_en;
    wire [ADDR_W-1:0] wt_addr;
    wire [DATA_W-1:0] wt_data;
    
    // Loaders <-> Core Data Streams
    wire              a_stream_valid;
    wire [DATA_W-1:0] a_stream_in;
    
    wire              w_stream_valid;
    wire [DATA_W-1:0] w_stream_in;
    
    // Core <-> Post-Processor
    wire              core_out_valid;
    wire [31:0]       core_out_data;

    // =========================================================================
    // BSRAM Memory Buffers
    // =========================================================================

    bsram_pingpong #(
        .DATA_W(DATA_W),
        .ADDR_W(ADDR_W)
    ) u_bsram_act (
        .clk      (clk),
        .bank_sel (host_act_bank_sel),
        .wr_en    (host_act_wr_en),
        .wr_addr  (host_act_wr_addr),
        .wr_data  (host_act_wr_data),
        .rd_en    (act_rd_en),
        .rd_addr  (act_addr),
        .rd_data  (act_data)
    );

    bsram_pingpong #(
        .DATA_W(DATA_W),
        .ADDR_W(ADDR_W)
    ) u_bsram_wt (
        .clk      (clk),
        .bank_sel (host_wt_bank_sel),
        .wr_en    (host_wt_wr_en),
        .wr_addr  (host_wt_wr_addr),
        .wr_data  (host_wt_wr_data),
        .rd_en    (wt_rd_en),
        .rd_addr  (wt_addr),
        .rd_data  (wt_data)
    );

    // =========================================================================
    // Data Loaders
    // =========================================================================

    activation_feeder #(
        .ADDR_W(ADDR_W),
        .DATA_W(DATA_W)
    ) u_act_feeder (
        .clk         (clk),
        .rst_n       (rst_n),
        .start       (start_loaders),
        .K_dim       (K_dim),
        .done        (act_loader_done),
        .bsram_rd_en (act_rd_en),
        .bsram_addr  (act_addr),
        .bsram_data  (act_data),
        .valid_out   (a_stream_valid),
        .data_out    (a_stream_in)
    );

    weight_loader #(
        .ADDR_W(ADDR_W),
        .DATA_W(DATA_W)
    ) u_wt_loader (
        .clk         (clk),
        .rst_n       (rst_n),
        .start       (start_loaders),
        .K_dim       (K_dim),
        .done        (wt_loader_done),
        .bsram_rd_en (wt_rd_en),
        .bsram_addr  (wt_addr),
        .bsram_data  (wt_data),
        .valid_out   (w_stream_valid),
        .data_out    (w_stream_in)
    );

    // =========================================================================
    // Math Core (Systolic Array)
    // =========================================================================

    agvme_core #(
        .N(N),
        .CH_W(8),
        .ADDR_W(ADDR_W)
    ) u_core (
        .clk            (clk),
        .rst_n          (rst_n),
        .start          (start),
        .K_dim          (K_dim),
        .busy           (busy),
        .done           (done),
        .start_loaders  (start_loaders),
        .loaders_done   (loaders_done),
        .a_stream_in    (a_stream_in),
        .a_stream_valid (a_stream_valid),
        .w_stream_in    (w_stream_in),
        .w_stream_valid (w_stream_valid),
        .out_valid      (core_out_valid),
        .out_data       (core_out_data)
    );

    // =========================================================================
    // Post-Processor (Bias, ReLU, Requantization)
    // =========================================================================

    post_processor u_post (
        .clk         (clk),
        .rst_n       (rst_n),
        .valid_in    (core_out_valid),
        .data_in     (core_out_data),
        .bias        (bias),
        .scale_mult  (scale_mult),
        .scale_shift (scale_shift),
        .en_relu     (en_relu),
        .valid_out   (out_valid),
        .data_out    (out_data)
    );

endmodule