//==============================================================================
// Module:  post_processor
// Project: AGVME - AgentGate-V MAC Engine
//
// Description:
//   Applies Bias, ReLU, and Requantization to the serialized 32-bit INT32 
//   accumulator stream from the output drain. 
//   Outputs a stream of 8-bit INT8 activations suitable for the next layer.
//
//   Uses Power-of-Two (PoT) Shift-Add Quantization to completely bypass 
//   hardware DSP slices, allowing 100% LUT routing for maximum Fmax.
//==============================================================================

module post_processor (
    input  wire                 clk,
    input  wire                 rst_n,

    // Inputs from output_drain
    input  wire                 valid_in,
    input  wire signed [31:0]   data_in,
    
    // Parameters
    input  wire signed [31:0]   bias,
    input  wire signed [15:0]   scale_mult,  // (Ignored in PoT approximation)
    input  wire [4:0]           scale_shift, // Right shift amount (0-31)
    input  wire                 en_relu,     // 1 to enable ReLU

    // Output stream
    output reg                  valid_out,
    output reg  signed [7:0]    data_out
);

    // Pipeline valid signals
    reg vld_s1, vld_s2, vld_s3, vld_s4, vld_s5;

    // Stage 1: Bias Addition
    reg signed [31:0] data_s1;

    // Stage 2: ReLU Mux
    reg signed [31:0] data_s2;

    // Stage 3 & 4: PoT Shift-Add Requantization
    reg signed [31:0] data_s3;
    reg signed [31:0] data_s4;

    // Stage 5: Barrel Shifter
    reg signed [31:0] data_s5;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            vld_s1 <= 0; vld_s2 <= 0; vld_s3 <= 0; vld_s4 <= 0; vld_s5 <= 0;
            valid_out <= 0;
            data_s1 <= 0; data_s2 <= 0; data_s3 <= 0; data_s4 <= 0; data_s5 <= 0;
            data_out <= 0;
        end else begin
            
            //------------------------------------------------------------------
            // Stage 1: Add Bias
            //------------------------------------------------------------------
            vld_s1 <= valid_in;
            data_s1 <= data_in + bias;

            //------------------------------------------------------------------
            // Stage 2: ReLU (Check MSB)
            //------------------------------------------------------------------
            vld_s2 <= vld_s1;
            if (en_relu && data_s1 < 0) begin
                data_s2 <= 32'sd0;
            end else begin
                data_s2 <= data_s1;
            end

            //------------------------------------------------------------------
            // Stage 3: PoT Requantization (x 1.25 approximation)
            // data * 1.25 = data + (data >>> 2)
            //------------------------------------------------------------------
            vld_s3 <= vld_s2;
            data_s3 <= data_s2 + (data_s2 >>> 2);

            //------------------------------------------------------------------
            // Stage 4: Retiming for routing delay
            //------------------------------------------------------------------
            vld_s4 <= vld_s3;
            data_s4 <= data_s3;

            //------------------------------------------------------------------
            // Stage 5: Arithmetic Right Shift
            //------------------------------------------------------------------
            vld_s5 <= vld_s4;
            data_s5 <= data_s4 >>> scale_shift;

            //------------------------------------------------------------------
            // Stage 6: Saturation to INT8
            //------------------------------------------------------------------
            valid_out <= vld_s5;
            if (data_s5 > 127) begin
                data_out <= 8'sd127;
            end else if (data_s5 < -128) begin
                data_out <= -8'sd128;
            end else begin
                data_out <= data_s5[7:0];
            end

        end
    end

endmodule