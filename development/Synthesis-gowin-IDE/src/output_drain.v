//==============================================================================
// Module: output_drain
// Project: AGVME - AgentGate-V MAC Engine
//
// Description:
//   Re-architected for True Systolic Shift-Out.
//   Drives shift_en to the systolic array for 64 cycles to pump the 
//   accumulators out in a daisy-chain, completely eliminating the old 
//   64-to-1 global multiplexer bottleneck.
//==============================================================================

module output_drain #(
    parameter N      = 8,
    parameter ACC_W  = 32
)(
    input  wire                          clk,
    input  wire                          rst_n,
    
    // Control
    input  wire                          start,
    output wire                          done,
    
    // Data and Control from/to Systolic Array
    input  wire [ACC_W-1:0]              acc_in_serial,
    output reg                           shift_en,
    
    // Serialized Output to Post-Processor
    output reg                           valid_out,
    output reg signed [ACC_W-1:0]        data_out
);

    localparam TOTAL_MACS = N * N;

    reg [6:0] count;
    reg       draining;

    assign done = (count == TOTAL_MACS);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            count     <= 7'd0;
            draining  <= 1'b0;
            shift_en  <= 1'b0;
            valid_out <= 1'b0;
            data_out  <= {ACC_W{1'b0}};
        end else begin
            
            valid_out <= 1'b0;
            shift_en  <= 1'b0;

            if (start) begin
                draining <= 1'b1;
                count    <= 7'd0;
            end 
            
            if (draining || start) begin
                if (count < TOTAL_MACS) begin
                    shift_en  <= 1'b1;
                    valid_out <= 1'b1;
                    data_out  <= acc_in_serial; // Latch the current daisy-chain output
                    count     <= count + 1'b1;
                end else begin
                    draining  <= 1'b0;
                end
            end

        end
    end
endmodule