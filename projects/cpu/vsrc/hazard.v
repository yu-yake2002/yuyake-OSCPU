//--Sun Jiru, Nanjing University

`include "defines.v"

module hazard (
  input wire [`REG_CTRL_BUS] id_ex_reg_wr_ctrl,
  input wire [4 : 0] id_ex_rd_addr,
  input wire [4 : 0] rs1_addr,
  input wire [4 : 0] rs2_addr,

  output wire id_stall
);
  wire mem_to_reg = id_ex_reg_wr_ctrl[`MEM_TO_REG];
  assign id_stall = mem_to_reg && (
    (id_ex_rd_addr == rs1_addr) || (id_ex_rd_addr == rs2_addr)
  );
endmodule