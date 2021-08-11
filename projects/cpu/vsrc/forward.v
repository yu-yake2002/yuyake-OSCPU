//--Sun Jiru, Nanjing University--

`include "defines.v"

module forward (
  // forward control
  input wire [4 : 0] rs1_addr,
  input wire [4 : 0] rs2_addr,
  //input wire [12: 0] csr_addr,
  input wire [4 : 0] ex_mem_rd_addr,
  input wire ex_mem_rd_ena,
  input wire [4 : 0] mem_wb_rd_addr,
  input wire mem_wb_rd_ena,
  input wire [`REG_BUS] ex_mem_ex_data,
  input wire [`REG_BUS] mem_wb_ex_data,
  input wire [`REG_BUS] mem_wb_mem_data,
  input wire [`REG_CTRL_BUS] ex_mem_reg_wr_ctrl,
  input wire [`REG_CTRL_BUS] mem_wb_reg_wr_ctrl,
  input wire [`REG_BUS] id_op1,
  input wire [`REG_BUS] id_op2,

  output wire [`REG_BUS] op1_src,
  output wire [`REG_BUS] op2_src
  // 0: id/ex
  // 1: ex/mem
  // 2: mem/wb
  );
  
  wire ex_mem_op1_src_ex = (rs1_addr == ex_mem_rd_addr) 
                        && ex_mem_rd_ena 
                        && (|rs1_addr)
                        && ex_mem_reg_wr_ctrl[`EXE_TO_REG];
  wire mem_wb_op1_src_ex = (rs1_addr == mem_wb_rd_addr) 
                        && mem_wb_rd_ena 
                        && (|rs1_addr)
                        && mem_wb_reg_wr_ctrl[`EXE_TO_REG];
  wire ex_mem_op1_src_mem = (rs1_addr == ex_mem_rd_addr) 
                        && ex_mem_rd_ena 
                        && (|rs1_addr)
                        && ex_mem_reg_wr_ctrl[`MEM_TO_REG];
  wire mem_wb_op1_src_mem = (rs1_addr == mem_wb_rd_addr) 
                        && mem_wb_rd_ena 
                        && (|rs1_addr)
                        && mem_wb_reg_wr_ctrl[`MEM_TO_REG];
  assign op1_src = (ex_mem_op1_src_ex)  ? ex_mem_ex_data  :
                   (mem_wb_op1_src_ex)  ? mem_wb_ex_data  :
                   (mem_wb_op1_src_mem) ? mem_wb_mem_data :
                   id_op1;

  wire ex_mem_op2_src_ex = (rs2_addr == ex_mem_rd_addr) 
                        && ex_mem_rd_ena 
                        && (|rs2_addr)
                        && ex_mem_reg_wr_ctrl[`EXE_TO_REG];
  wire mem_wb_op2_src_ex = (rs2_addr == mem_wb_rd_addr) 
                        && mem_wb_rd_ena 
                        && (|rs2_addr)
                        && ex_mem_reg_wr_ctrl[`EXE_TO_REG];
  wire ex_mem_op2_src_mem = (rs2_addr == ex_mem_rd_addr) 
                        && ex_mem_rd_ena 
                        && (|rs2_addr)
                        && ex_mem_reg_wr_ctrl[`MEM_TO_REG];
  wire mem_wb_op2_src_mem = (rs2_addr == mem_wb_rd_addr) 
                        && mem_wb_rd_ena 
                        && (|rs2_addr)
                        && ex_mem_reg_wr_ctrl[`MEM_TO_REG];
  assign op2_src = (ex_mem_op2_src_ex)  ? ex_mem_ex_data  :
                   (mem_wb_op2_src_ex)  ? mem_wb_ex_data  :
                   (mem_wb_op2_src_mem) ? mem_wb_mem_data :
                   id_op2;
  
endmodule