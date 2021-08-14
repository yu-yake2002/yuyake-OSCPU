//--Sun Jiru, Nanjing University--

`include "defines.v"

module forward (
  // forward control
  input wire [4 : 0] rs1_addr,
  input wire [4 : 0] rs2_addr,
  //input wire [12: 0] csr_addr,
  input wire [4 : 0] mem_reg_wr_addr,
  input wire mem_reg_wr_ena,
  input wire [4 : 0] wb_reg_wr_addr,
  input wire wb_reg_wr_ena,
  input wire [`REG_BUS] mem_ex_data,
  input wire [`REG_BUS] wb_ex_data,
  input wire [`REG_BUS] wb_mem_data,
  input wire [`REG_CTRL_BUS] mem_reg_wr_ctrl,
  input wire [`REG_CTRL_BUS] wb_reg_wr_ctrl,
  input wire [`REG_BUS] rs1_now,
  input wire [`REG_BUS] rs2_now,

  output wire [`REG_BUS] rs1_forward,
  output wire [`REG_BUS] rs2_forward
);
  
  wire mem_op1_src_ex = (rs1_addr == mem_reg_wr_addr) 
                        && mem_reg_wr_ena 
                        && (|rs1_addr)
                        && mem_reg_wr_ctrl[`EXE_TO_REG];
  wire wb_op1_src_ex = (rs1_addr == wb_reg_wr_addr) 
                        && wb_reg_wr_ena 
                        && (|rs1_addr)
                        && wb_reg_wr_ctrl[`EXE_TO_REG];
  wire mem_op1_src_mem = (rs1_addr == mem_reg_wr_addr) 
                        && mem_reg_wr_ena 
                        && (|rs1_addr)
                        && mem_reg_wr_ctrl[`MEM_TO_REG];
  wire wb_op1_src_mem = (rs1_addr == wb_reg_wr_addr) 
                        && wb_reg_wr_ena 
                        && (|rs1_addr)
                        && wb_reg_wr_ctrl[`MEM_TO_REG];
  assign rs1_forward = (mem_op1_src_ex) ? mem_ex_data :
                       (wb_op1_src_ex)  ? wb_ex_data  :
                       (wb_op1_src_mem) ? wb_mem_data :
                       rs1_now;

  wire mem_op2_src_ex = (rs2_addr == mem_reg_wr_addr) 
                        && mem_reg_wr_ena 
                        && (|rs2_addr)
                        && mem_reg_wr_ctrl[`EXE_TO_REG];
  wire wb_op2_src_ex = (rs2_addr == wb_reg_wr_addr) 
                        && wb_reg_wr_ena 
                        && (|rs2_addr)
                        && wb_reg_wr_ctrl[`EXE_TO_REG];
  wire mem_op2_src_mem = (rs2_addr == mem_reg_wr_addr) 
                        && mem_reg_wr_ena 
                        && (|rs2_addr)
                        && mem_reg_wr_ctrl[`MEM_TO_REG];
  wire wb_op2_src_mem = (rs2_addr == wb_reg_wr_addr) 
                        && wb_reg_wr_ena 
                        && (|rs2_addr)
                        && wb_reg_wr_ctrl[`MEM_TO_REG];
  assign rs2_forward = (mem_op2_src_ex) ? mem_ex_data :
                       (wb_op2_src_ex)  ? wb_ex_data  :
                       (wb_op2_src_mem) ? wb_mem_data :
                       rs2_now;
  
endmodule