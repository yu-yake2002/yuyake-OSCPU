
//--Sun Jiru, Nanjing University--

`include "defines.v"

module wb_stage (
  input wire rst,

  input wire [`REG_CTRL_BUS] reg_wr_ctrl,
  input wire [`REG_BUS] exe_data,
  input wire [`REG_BUS] mem_data,
  input wire [`REG_BUS] csr_data,
  
  output wire [`REG_BUS] reg_wr_data
  );

  wire mem_to_reg = reg_wr_ctrl[`MEM_TO_REG];
  wire exe_to_reg = reg_wr_ctrl[`EXE_TO_REG];
  wire csr_to_reg = reg_wr_ctrl[`CSR_TO_REG];

  assign reg_wr_data = {64{~rst}} & (
      ({64{mem_to_reg}} & mem_data)
    | ({64{exe_to_reg}} & exe_data)
    | ({64{csr_to_reg}} & csr_data)
  );
endmodule