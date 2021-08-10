
//--Sun Jiru, Nanjing University--

`include "defines.v"

module wb_stage (
  input wire clk,
  input wire rst,

  // pipeline control
  input wire mem_wb_valid,
  output wire wb_allowin,
  output reg wb_valid,
  
  input wire [`REG_BUS] pc_in,
  input wire [31  :  0] inst_in,
  output reg [`REG_BUS] pc_out,
  output reg [31  :  0] inst_out,

  input wire [`REG_CTRL_BUS] reg_wr_ctrl,
  input wire [`REG_BUS] exe_data,
  input wire [`REG_BUS] mem_data,
  input wire [`REG_BUS] csr_data,
  
  output wire [`REG_BUS] w_data
  );

  // pipeline control
  assign wb_allowin = 1'b1;
  always @(posedge clk) begin
    if (rst) begin
      wb_valid <= 1'b0;
    end
    else if (wb_allowin) begin
      wb_valid <= mem_wb_valid;
    end
  end  

  wire mem_to_reg = reg_wr_ctrl[`MEM_TO_REG];
  wire exe_to_reg = reg_wr_ctrl[`EXE_TO_REG];
  wire csr_to_reg = reg_wr_ctrl[`CSR_TO_REG];

  assign w_data = {64{~rst}} & (
      ({64{mem_to_reg}} & mem_data)
    | ({64{exe_to_reg}} & exe_data)
    | ({64{csr_to_reg}} & csr_data)
  );

endmodule