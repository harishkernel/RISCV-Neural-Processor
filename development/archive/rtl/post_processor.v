//==============================================================================
// Module:  post_processor
// Project: AGVME — AgentGate-V MAC Engine
// Target:  Gowin GW5A-LV25MG121
//
// Description:
//   Applies Bias, ReLU, and Requantization to the serialized 32-bit INT32 
//   accumulator stream from the output drain. 
//   Outputs a stream of 8-bit INT8 activations suitable for the next layer.
//
//   Dataflow (Pipelined):
//     Stage 1: Add bias (32-bit + 32-bit) and apply ReLU
//     Stage 2: Multiply by requantization multiplier (32-bit x 16-bit -> 48-bit)
//     Stage 3: Arithmetic Right Shift (up to 31 bits) and Saturate to INT8.
//==============================================================================

module post_processor (
    input  wire                 clk,
    input  wire                 rst_n,

    // Inputs from output_drain
    input  wire                 valid_in,
    input  wire signed [31:0]   data_in,
    
    // Per-layer / Per-channel parameters (from CSR)
    // For simplicity in this iteration, these are broadcast parameters.
    input  wire signed [31:0]   bias,
    input  wire signed [15:0]   scale_mult,  // Fixed-point multiplier
    input  wire [4:0]           scale_shift, // Right shift amount (0-31)
    input  wire                 en_relu,     // 1 to enable ReLU

    // Output stream
    output reg                  valid_out,
    output reg  signed [7:0]    data_out
);

    // ---- Stage 1: Bias and ReLU ----
    reg signed [32:0] s1_data;
    reg               s1_valid;
    
    // Use 33-bit intermediate to prevent overflow before ReLU
    wire signed [32:0] bias_sum = $signed({data_in[31], data_in}) + $signed({bias[31], bias});

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s1_data <= 0;
            s1_valid <= 0;
        end else begin
            s1_valid <= valid_in;
            if (valid_in) begin
                if (en_relu && (bias_sum < 0)) begin
                    s1_data <= 0;
                end else begin
                    // Pass full 33-bit sum to the next stage multiplier
                    s1_data <= bias_sum;
                end
            end
        end
    end

    // ---- Stage 2: Scale Multiplier ----
    // 33-bit x 16-bit = 49-bit signed product
    reg signed [48:0] s2_data;
    reg               s2_valid;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s2_data <= 0;
            s2_valid <= 0;
        end else begin
            s2_valid <= s1_valid;
            if (s1_valid) begin
                s2_data <= s1_data * scale_mult;
            end
        end
    end

    // ---- Stage 3: Shift and Saturate ----
    wire signed [48:0] shifted_data = s2_data >>> scale_shift;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            data_out <= 0;
            valid_out <= 0;
        end else begin
            valid_out <= s2_valid;
            if (s2_valid) begin
                // Saturate to INT8 (-128 to 127)
                if (shifted_data > 127) begin
                    data_out <= 8'sd127;
                end else if (shifted_data < -128) begin
                    data_out <= -8'sd128;
                end else begin
                    data_out <= shifted_data[7:0];
                end
            end
        end
    end

endmodule
