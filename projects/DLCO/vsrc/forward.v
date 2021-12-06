//--Sun Jiru, Nanjing University--

`include "defines.v"

module forward (
  // forward control
  input wire [4 : 0]                  ex_rs1_addr,
  input wire [4 : 0]                  ex_rs2_addr,
  //input wire [12: 0] csr_addr,
  input wire [`REG_BUS]               ex_rs1_data,
  input wire [`REG_BUS]               ex_rs2_data,
  input wire                          ex_use_rs1,
  input wire                          ex_use_rs2,

  input wire [`MEM_FORWARD_WIDTH-1:0] mem_forward_bus,
  input wire [`WB_FORWARD_WIDTH-1:0]  wb_forward_bus,

  output wire [`REG_BUS]              rs1_forward,
  output wire [`REG_BUS]              rs2_forward,

  output wire                         hazard
);
  
  wire [4:0] mem_reg_wr_addr, wb_reg_wr_addr;
  wire mem_reg_wr_ena, wb_reg_wr_ena;
  wire [`REG_BUS] mem_ex_data, wb_ex_data, wb_mem_data;
  wire [`REG_CTRL_BUS] mem_reg_wr_ctrl, wb_reg_wr_ctrl;

  assign {
    mem_reg_wr_addr, // 72 :68
    mem_reg_wr_ena,  // 67 :67
    mem_ex_data,     // 66 :3
    mem_reg_wr_ctrl  // 2  :0
  } = mem_forward_bus;
  
  assign {
    wb_reg_wr_addr, // 136:132
    wb_reg_wr_ena,  // 131:131
    wb_ex_data,     // 130:67
    wb_mem_data,    // 66 :3
    wb_reg_wr_ctrl  // 2  :0
  } = wb_forward_bus;
  
  wire mem_op1_src_ex = (ex_rs1_addr == mem_reg_wr_addr) 
                        && mem_reg_wr_ena 
                        && (|ex_rs1_addr)
                        && mem_reg_wr_ctrl[`EXE_TO_REG];
  wire wb_op1_src_ex = (ex_rs1_addr == wb_reg_wr_addr) 
                        && wb_reg_wr_ena 
                        && (|ex_rs1_addr)
                        && wb_reg_wr_ctrl[`EXE_TO_REG];
  wire mem_op1_src_mem = (ex_rs1_addr == mem_reg_wr_addr) 
                        && mem_reg_wr_ena 
                        && (|ex_rs1_addr)
                        && mem_reg_wr_ctrl[`MEM_TO_REG];
  wire wb_op1_src_mem = (ex_rs1_addr == wb_reg_wr_addr) 
                        && wb_reg_wr_ena 
                        && (|ex_rs1_addr)
                        && wb_reg_wr_ctrl[`MEM_TO_REG];
  assign rs1_forward = (mem_op1_src_ex) ? mem_ex_data :
                       (wb_op1_src_ex)  ? wb_ex_data  :
                       (wb_op1_src_mem) ? wb_mem_data :
                       ex_rs1_data;

  /* test wires begin */
  wire test_eq     = (ex_rs1_addr == mem_reg_wr_addr);
  wire test_wr_ena = mem_reg_wr_ena;
  wire test_rs1    = (|ex_rs1_addr);
  wire test_wr_src = mem_reg_wr_ctrl[`MEM_TO_REG];
  /* test wires end */

  wire mem_op2_src_ex = (ex_rs2_addr == mem_reg_wr_addr) 
                        && mem_reg_wr_ena 
                        && (|ex_rs2_addr)
                        && mem_reg_wr_ctrl[`EXE_TO_REG];
  wire wb_op2_src_ex = (ex_rs2_addr == wb_reg_wr_addr) 
                        && wb_reg_wr_ena 
                        && (|ex_rs2_addr)
                        && wb_reg_wr_ctrl[`EXE_TO_REG];
  wire mem_op2_src_mem = (ex_rs2_addr == mem_reg_wr_addr) 
                        && mem_reg_wr_ena 
                        && (|ex_rs2_addr)
                        && mem_reg_wr_ctrl[`MEM_TO_REG];
  wire wb_op2_src_mem = (ex_rs2_addr == wb_reg_wr_addr) 
                        && wb_reg_wr_ena 
                        && (|ex_rs2_addr)
                        && wb_reg_wr_ctrl[`MEM_TO_REG];
  assign rs2_forward = (mem_op2_src_ex) ? mem_ex_data :
                       (wb_op2_src_ex)  ? wb_ex_data  :
                       (wb_op2_src_mem) ? wb_mem_data :
                       ex_rs2_data;
  
  assign hazard = mem_op1_src_mem || mem_op2_src_mem;
endmodule