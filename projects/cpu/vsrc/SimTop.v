
/* verilator lint_off UNUSED */
//--Sun Jiru, Nanjing University--

`timescale 1ns / 1ps

`include "defines.v"

module SimTop(
  input wire    clock,
  input wire    reset,
  
  input  [63:0] io_logCtrl_log_begin,
  input  [63:0] io_logCtrl_log_end,
  input  [63:0] io_logCtrl_log_level,
  input         io_perfInfo_clean,
  input         io_perfInfo_dump,

  output        io_uart_out_valid,
  output [7:0]  io_uart_out_ch,
  output        io_uart_in_valid,
  input  [7:0]  io_uart_in_ch
  );

  // IF_STAGE
  wire [31  :  0] if_id_inst;
  wire [`REG_BUS] if_id_pc;
  wire           inst_ena;
  // if -> exception
  wire [`EXCP_BUS] if_excp;
  // pipeline control
  wire if_id_valid;
  // instruction jump & exception jump
  wire bj_ena;
  wire [`REG_BUS] new_pc;
  wire excp_jmp_ena;
  wire [`REG_BUS] excp_pc;
  
  if_stage If_stage(
    .clk(clock),
    .rst(reset),
    
    .id_allowin(id_allowin),
    .if_id_valid(if_id_valid),
    
    .bj_ena(bj_ena),
    .new_pc(if_id_pc),
    
    .excp_jmp_ena(excp_jmp_ena),
    .excp_pc(excp_pc),
    
    .pc(if_id_pc),
    .if_excp(if_excp)
  );

  // ID_STAGE
  // pipeline control
  wire id_allowin;
  wire id_ex_valid;
  // -> ex_stage
  wire [`REG_BUS] id_ex_pc;
  wire [31  :  0] id_ex_inst;
  wire [`ALU_BUS] id_ex_alu_info;
  wire [`BJ_BUS]  id_ex_bj_info;
  wire is_word_opt;
  wire [`REG_BUS] jmp_imm;
  // -> exception
  wire [`EXCP_BUS] id_excp;
  // -> mem_stage
  wire [`REG_BUS] id_ex_mem_wr_src;
  wire [`LOAD_BUS] id_ex_load_info;
  wire [`SAVE_BUS] id_ex_save_info;
  wire id_ex_mem_wr_ena;
  wire id_ex_mem_rd_ena;
  // -> wb_stage
  wire [`REG_CTRL_BUS] id_ex_reg_wr_ctrl;
  wire id_ex_csr_wr_ena;
  wire [11 : 0] id_ex_csr_wr_addr;
  wire id_ex_rd_w_ena;
  wire [4 : 0] id_ex_rd_w_addr;

  id_stage Id_stage(
    .rst(reset),
    .clk(clock),
    
    .ex_allowin(ex_allowin),
    .id_allowin(id_allowin),
    .if_id_valid(if_id_valid),
    .id_ex_valid(id_ex_valid),
    
    .pc_in(if_id_pc),
    .inst_in(if_id_inst),
    .pc_out(id_ex_pc),
    .inst_out(id_ex_inst),
    
    .r_data1(r_data1),
    .r_data2(r_data2),
    .csr_data(csr_rd_data),
    
    .rs1_r_ena(rs1_r_ena),
    .rs1_r_addr(rs1_r_addr),
    .rs2_r_ena(rs2_r_ena),
    .rs2_r_addr(rs2_r_addr),
    .csr_rd_ena(csr_rd_ena),
    .csr_rd_addr(csr_rd_addr),
    
    .ex_op1(ex_op1),
    .ex_op2(ex_op2),
    .is_word_opt(is_word_opt),
    .alu_info(id_ex_alu_info),
    .bj_info(id_ex_bj_info),

    .rs2_data(id_ex_mem_wr_src),
    .load_info(id_ex_load_info),
    .save_info(id_ex_save_info),
    .mem_rd_ena(id_ex_mem_rd_ena),
    .mem_wr_ena(id_ex_mem_wr_ena),

    .reg_wr_ctrl(id_ex_reg_wr_ctrl),
    .csr_wr_ena(id_ex_csr_wr_ena),
    .csr_wr_addr(id_ex_csr_wr_addr),
    .rd_w_ena(id_ex_rd_w_ena),
    .rd_w_addr(id_ex_rd_w_addr),
    
    .jmp_imm(jmp_imm),
    
    .id_excp(id_excp),
    .excp_exit(excp_exit)
  );
    
    
  // EX_STAGE
  // pipeline control
  wire ex_allowin;
  wire ex_mem_valid;
  // operand
  wire [`REG_BUS] ex_op1;
  wire [`REG_BUS] ex_op2;
  // -> mem_stage
  wire [`REG_BUS] ex_mem_pc;
  wire [31  :  0] ex_mem_inst;
  wire [`LOAD_BUS] ex_mem_load_info;
  wire [`SAVE_BUS] ex_mem_save_info; 
  wire ex_mem_wr_ena;
  wire ex_mem_rd_ena;
  wire [`REG_BUS] ex_mem_mem_wr_src;
  // -> wb_stage
  wire [`REG_CTRL_BUS] ex_mem_reg_wr_ctrl;
  wire ex_mem_csr_wr_ena;
  wire [11 : 0] ex_mem_csr_wr_addr;
  wire ex_mem_rd_w_ena;
  wire [4 : 0] ex_mem_rd_w_addr;
  wire [`REG_BUS] ex_mem_ex_data;
  ex_stage Ex_stage(
    .clk(clock),
    .rst(reset),
  
    .mem_allowin(mem_allowin),
    .ex_allowin(ex_allowin),
    .id_ex_valid(id_ex_valid),
    .ex_mem_valid(ex_mem_valid),
    
    .pc_in(id_ex_pc),
    .inst_in(id_ex_inst),
    .pc_out(ex_mem_pc),
    .inst_out(ex_mem_inst),
    
    .exe_op1(ex_op1),
    .exe_op2(ex_op2),
    .is_word_opt(is_word_opt),
    .alu_info_in(id_ex_alu_info),
    .bj_info_in(id_ex_bj_info),
    .jmp_imm(jmp_imm),
    
    // pass to mem_stage
    .load_info_in(id_ex_load_info),
    .save_info_in(id_ex_save_info),
    .mem_rd_ena_in(id_ex_mem_rd_ena),
    .mem_wr_ena_in(id_ex_mem_wr_ena),
    .mem_wr_src_in(id_ex_mem_wr_src),
    .load_info_out(ex_mem_load_info),
    .save_info_out(ex_mem_save_info),
    .mem_wr_ena_out(ex_mem_mem_wr_ena),
    .mem_rd_ena_out(ex_mem_mem_rd_ena),
    .mem_wr_src_out(ex_mem_mem_wr_src),
    
    // pass to wb_stage
    .reg_wr_ctrl_in(id_ex_reg_wr_ctrl),
    .csr_wr_ena_in(id_ex_csr_wr_ena),
    .csr_wr_addr_in(id_ex_csr_wr_addr),
    .rd_w_ena_in(id_ex_rd_w_ena),
    .rd_w_addr_in(id_ex_rd_w_addr),
    .reg_wr_ctrl_out(ex_mem_reg_wr_ctrl),
    .csr_wr_ena_out(ex_mem_csr_wr_ena),
    .csr_wr_addr_out(ex_mem_csr_wr_addr),
    .rd_w_ena_out(ex_mem_rd_w_ena),
    .rd_w_addr_out(ex_mem_rd_w_addr),

    .ex_data(ex_mem_ex_data),
    .new_pc(new_pc),
    .bj_ena(bj_ena)
  );

  // MEM_STAGE
  // pipeline control
  wire mem_allowin;
  wire mem_wb_valid;
  wire [`REG_BUS] mem_wb_pc;
  wire [31  :  0] mem_wb_inst;
  // mem_stage -> excp_handler
  wire [`EXCP_BUS] mem_excp;
  // mem control
  wire ex_mem_mem_wr_ena;
  wire ex_mem_mem_rd_ena;
  // -> wb_stage
  wire [`REG_CTRL_BUS] mem_wb_reg_wr_ctrl;
  wire mem_wb_csr_wr_ena;
  wire [11 : 0] mem_wb_csr_wr_addr;
  wire mem_wb_rd_w_ena;
  wire [4 : 0] mem_wb_rd_w_addr;
  wire [`REG_BUS] mem_wb_ex_data;
  mem_stage Mem_stage(
    .clk(clock),
    .rst(reset),
    
    .wb_allowin(wb_allowin),
    .mem_allowin(mem_allowin),
    .ex_mem_valid(ex_mem_valid),
    .mem_wb_valid(mem_wb_valid),
    
    .pc_in(ex_mem_pc),
    .inst_in(ex_mem_inst),
    .pc_out(mem_wb_pc),
    .inst_out(mem_wb_inst),
    
    .reg_src(r_data2),
    .load_info(ex_mem_load_info),
    .save_info(ex_mem_save_info),
    .mem_rd_ena(ex_mem_mem_rd_ena),
    .mem_wr_ena(ex_mem_mem_wr_ena),
    .mem_addr(ex_data),
    
    .memhpr_wr_data(mem_wr_data),
    .memhpr_rd_data(mem_rd_data),
    .byte_enable(byte_enable),
    
    // -> wb_stage
    .mem_data(mem_data),
    .reg_wr_ctrl_in(ex_mem_reg_wr_ctrl),
    .csr_wr_ena_in(ex_mem_csr_wr_ena),
    .csr_wr_addr_in(ex_mem_csr_wr_addr),
    .rd_w_ena_in(ex_mem_rd_w_ena),
    .rd_w_addr_in(ex_mem_rd_w_addr),
    .ex_data_in(ex_mem_ex_data),

    .reg_wr_ctrl_out(mem_wb_reg_wr_ctrl),
    .csr_wr_ena_out(mem_wb_csr_wr_ena),
    .csr_wr_addr_out(mem_wb_csr_wr_addr),
    .rd_w_ena_out(mem_wb_rd_w_ena),
    .rd_w_addr_out(mem_wb_rd_w_addr),
    .ex_data_out(mem_wb_ex_data),

    // mem_stage -> exception handler
    .mem_excp(mem_excp)
  );
  
  // Access memory
  // mem_stage <-> mem_helper
  wire [`REG_BUS] mem_addr = ex_data;
  wire [7 : 0] byte_enable; // write mask
  wire [`REG_BUS] mem_wr_data;
  wire [`REG_BUS] mem_rd_data;
  RAM_1W2R RAM_1W2R(
    .clk(clock),
    
    .inst_addr(if_id_pc),
    .inst_ena(1),
    .inst(if_id_inst),
    
    .mem_wr_ena(ex_mem_mem_wr_ena),
    .mem_rd_ena(ex_mem_mem_rd_ena),
    .byte_enable(byte_enable),
    .mem_addr(mem_addr),
    .mem_wr_data(mem_wr_data),
    .mem_rd_data(mem_rd_data)
  );
  
  // WB_STAGE
  // pipeline control
  wire wb_allowin;
  // datapath
  wire [`REG_BUS] ex_data;
  wire [`REG_BUS] mem_data;
  // wb_stage -> difftest
  wire [`REG_BUS] diff_pc;
  wire [31  :  0] diff_inst;
  wire wb_valid;

  wb_stage Wb_stage(
    .clk(clock),
    .rst(reset),
    
    .mem_wb_valid(mem_wb_valid),
    .wb_allowin(wb_allowin),
    .wb_valid(wb_valid),
    
    .pc_in(mem_wb_pc),
    .inst_in(mem_wb_inst),
    .pc_out(diff_pc),
    .inst_out(diff_inst),

    .reg_wr_ctrl(mem_wb_reg_wr_ctrl),
    .exe_data(mem_wb_ex_data),
    .mem_data(mem_data),
    .csr_data(csr_rd_data),
    
    .w_data(rd_data)
  );
  
  // General Purpose Registers
  // id_stage <-> regfile
  wire rs1_r_ena;
  wire [4 : 0]rs1_r_addr;
  wire [`REG_BUS] r_data1;
  wire rs2_r_ena;
  wire [4 : 0]rs2_r_addr;
  wire [`REG_BUS] r_data2;
  // wb_stage <-> regfile
  wire rd_w_ena;
  wire [`REG_BUS] rd_data;
  
  // difftest
  wire [`REG_BUS] regs[0 : 31];

  regfile Regfile(
    .clk(clock),
    .rst(reset),
    .w_addr(mem_wb_rd_w_addr),
    .w_data(rd_data),
    .w_ena(mem_wb_rd_w_ena),
  
    .r_addr1(rs1_r_addr),
    .r_data1(r_data1),
    .r_ena1(rs1_r_ena),
    .r_addr2(rs2_r_addr),
    .r_data2(r_data2),
    .r_ena2(rs2_r_ena),
  
    .regs_o(regs)
  );

  // exception
  wire excp_enter, excp_exit;
  
  excp_handler Excp_handler(
    .if_excp(if_excp),
    .id_excp(id_excp),
    .mem_excp(mem_excp),
    .itrp_info(0),
    .now_pc(mem_wb_pc),
    .now_inst(mem_wb_inst),
    .mem_acc_addr(0),
    .excp_exit(excp_exit),

    .excp_enter(excp_enter),
    .mcause_wr_data(mcause_wr_data),
    .mepc_wr_data(mepc_wr_data),
    .mtval_wr_data(mtval_wr_data),
    .mstatus_wr_data(mstatus_wr_data),
  
    .mstatus_rd_data(mstatus_rd_data),
    .mtvec_rd_data(mtvec_rd_data),
    .mepc_rd_data(mepc_rd_data),

    .excp_jmp_ena(excp_jmp_ena),
    .excp_pc(excp_pc)
  );

  // CSRs
  // id_stage <-> csrfile
  wire csr_rd_ena;
  wire [11 : 0] csr_rd_addr;
  wire csr_wr_ena;
  wire [11 : 0] csr_wr_addr;
  // csrfile <-> id_stage
  wire [`REG_BUS] csr_rd_data;
  // direct read and write
  wire [`REG_BUS] mstatus_wr_data;
  wire [`REG_BUS] mstatus_rd_data;
  wire [`REG_BUS] mie_rd_data;
  wire [`REG_BUS] mtvec_rd_data;
  wire [`REG_BUS] mscratch_rd_data;
  wire [`REG_BUS] mepc_wr_data;
  wire [`REG_BUS] mepc_rd_data;
  wire [`REG_BUS] mcause_wr_data;
  wire [`REG_BUS] mcause_rd_data;
  wire [`REG_BUS] mtval_rd_data;
  wire [`REG_BUS] mtval_wr_data;
  wire [`REG_BUS] mip_rd_data;

  csrfile CSRfile(
  .clk(clock),
  .rst(reset),

  .csr_rd_ena(csr_rd_ena),
  .csr_rd_addr(csr_rd_addr),
  .csr_wr_ena(csr_wr_ena),
  .csr_wr_addr(csr_wr_addr),
  .csr_wr_data(ex_data),
  .csr_rd_data(csr_rd_data),
  
  .excp_enter(excp_enter),
  .excp_exit(excp_exit),
  .mstatus_wr_data(mstatus_wr_data),
  .mstatus_rd_data(mstatus_rd_data),
  .mie_rd_data(mie_rd_data),
  .mtvec_rd_data(mtvec_rd_data),
  .mscratch_rd_data(mscratch_rd_data),
  .mepc_wr_data(mepc_wr_data),
  .mepc_rd_data(mepc_rd_data),
  .mcause_wr_data(mcause_wr_data),
  .mcause_rd_data(mcause_rd_data),
  .mtval_wr_data(mtval_wr_data),
  .mtval_rd_data(mtval_rd_data),
  .mip_rd_data(mip_rd_data)
);

// Difftest
reg cmt_wen;
reg [7:0]cmt_wdest;
reg [`REG_BUS] cmt_wdata;
reg [`REG_BUS] cmt_pc;
reg [31:0]cmt_inst;
reg vaild;
reg skip;
reg [63:0] cycleCnt;
reg [63:0] instrCnt;

always @(posedge clock) begin
  if (reset) begin
    {cmt_wen, cmt_wdest, cmt_wdata, cmt_pc, cmt_inst, vaild, cycleCnt, instrCnt} <= 0;
  end
  else begin
    cmt_wen <= rd_w_ena;
    cmt_wdest <= {3'd0, mem_wb_rd_w_addr};
    cmt_wdata <= rd_data;
    cmt_pc <= mem_wb_pc;
    cmt_inst <= mem_wb_inst;
    vaild <= 1'd1;

    // Skip comparison of the first instruction
    // Because the result required to commit cannot be calculated in time before first InstrCommit during verilator simulation
    // Maybe you can avoid it in pipeline
    skip <= (!wb_valid || mem_wb_pc == `PC_START);
    
    cycleCnt <= cycleCnt + 1;
    instrCnt <= instrCnt + 1;
  end
end

DifftestInstrCommit DifftestInstrCommit(
  .clock              (clock),
  .coreid             (0),
  .index              (0),
  .valid              (vaild),
  .pc                 (cmt_pc),
  .instr              (cmt_inst),
  .skip               (skip),
  .isRVC              (0),
  .scFailed           (0),
  .wen                (cmt_wen),
  .wdest              (cmt_wdest),
  .wdata              (cmt_wdata)
);

DifftestArchIntRegState DifftestArchIntRegState (
  .clock              (clock),
  .coreid             (0),
  .gpr_0              (regs[0]),
  .gpr_1              (regs[1]),
  .gpr_2              (regs[2]),
  .gpr_3              (regs[3]),
  .gpr_4              (regs[4]),
  .gpr_5              (regs[5]),
  .gpr_6              (regs[6]),
  .gpr_7              (regs[7]),
  .gpr_8              (regs[8]),
  .gpr_9              (regs[9]),
  .gpr_10             (regs[10]),
  .gpr_11             (regs[11]),
  .gpr_12             (regs[12]),
  .gpr_13             (regs[13]),
  .gpr_14             (regs[14]),
  .gpr_15             (regs[15]),
  .gpr_16             (regs[16]),
  .gpr_17             (regs[17]),
  .gpr_18             (regs[18]),
  .gpr_19             (regs[19]),
  .gpr_20             (regs[20]),
  .gpr_21             (regs[21]),
  .gpr_22             (regs[22]),
  .gpr_23             (regs[23]),
  .gpr_24             (regs[24]),
  .gpr_25             (regs[25]),
  .gpr_26             (regs[26]),
  .gpr_27             (regs[27]),
  .gpr_28             (regs[28]),
  .gpr_29             (regs[29]),
  .gpr_30             (regs[30]),
  .gpr_31             (regs[31])
);

DifftestTrapEvent DifftestTrapEvent(
  .clock              (clock),
  .coreid             (0),
  .valid              (mem_wb_inst[6:0] == 7'h6b),
  .code               (regs[10][7:0]),
  .pc                 (cmt_pc),
  .cycleCnt           (cycleCnt),
  .instrCnt           (instrCnt)
);

DifftestCSRState DifftestCSRState(
  .clock              (clock),
  .coreid             (0),
  .priviledgeMode     (0),
  .mstatus            (mstatus_rd_data),
  .sstatus            (0),
  .mepc               (mepc_rd_data),
  .sepc               (0),
  .mtval              (mtval_rd_data),
  .stval              (0),
  .mtvec              (mtvec_rd_data),
  .stvec              (0),
  .mcause             (mcause_rd_data),
  .scause             (0),
  .satp               (0),
  .mip                (mip_rd_data),
  .mie                (0),
  .mscratch           (mscratch_rd_data),
  .sscratch           (0),
  .mideleg            (0),
  .medeleg            (0)
);

DifftestArchFpRegState DifftestArchFpRegState(
  .clock              (clock),
  .coreid             (0),
  .fpr_0              (0),
  .fpr_1              (0),
  .fpr_2              (0),
  .fpr_3              (0),
  .fpr_4              (0),
  .fpr_5              (0),
  .fpr_6              (0),
  .fpr_7              (0),
  .fpr_8              (0),
  .fpr_9              (0),
  .fpr_10             (0),
  .fpr_11             (0),
  .fpr_12             (0),
  .fpr_13             (0),
  .fpr_14             (0),
  .fpr_15             (0),
  .fpr_16             (0),
  .fpr_17             (0),
  .fpr_18             (0),
  .fpr_19             (0),
  .fpr_20             (0),
  .fpr_21             (0),
  .fpr_22             (0),
  .fpr_23             (0),
  .fpr_24             (0),
  .fpr_25             (0),
  .fpr_26             (0),
  .fpr_27             (0),
  .fpr_28             (0),
  .fpr_29             (0),
  .fpr_30             (0),
  .fpr_31             (0)
);

endmodule
