
/* verilator lint_off UNUSED */
//--Sun Jiru, Nanjing University--

`include "defines.v"

module if_stage(
  input wire clk,
  input wire rst,
  
  // branch and jump control
  input wire bj_ena,
  input wire [`REG_BUS] bj_pc,
  input wire excp_jmp_ena,
  input wire [`REG_BUS] excp_pc,
  
  // output to pipeline
  output reg [`REG_BUS] if_pc,
  output reg [31  :  0] if_inst,

  // AXI4
  output wire           if_axi_valid, // master is valid
  input wire            if_axi_ready, // slave is ready
  input wire [`REG_BUS] if_axi_data_read,
  output reg [`REG_BUS] if_axi_addr,
  output wire [1:0]     if_axi_size,
  input wire [1:0]      if_axi_resp,

  output reg fetched
  );

  // fetch an instruction
  assign if_axi_valid = 1'b1;
  assign if_axi_size = `SIZE_W;

  wire if_handshake = if_axi_valid & if_axi_ready;

  always @(posedge clk) begin
    if (rst) begin
      if_pc <= `PC_START;
      if_axi_addr <= `PC_START;
      fetched <= 1'b0;
    end
    else if (if_handshake) begin
      if_pc <= if_axi_addr; // this pc
      if_axi_addr <= excp_jmp_ena ? excp_pc :
                     bj_ena       ? bj_pc   :
                     (if_axi_addr + 4) ; // next pc
      fetched <= 1'b1;
      if_inst <= if_axi_data_read[31 : 0]; // this inst
    end
    else begin
      fetched <= 1'b0;
    end
  end
endmodule
