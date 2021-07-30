
/* verilator lint_off UNUSED */
//--Sun Jiru, Nanjing University--

`timescale 1ns / 1ps

`include "defines.v"


module SimTop(
  input wire            clock,
  input wire            reset,
  
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


// if_stage
wire [31 : 0]  inst;
wire [63 : 0]  pc; 
wire           inst_ena;

// id_stage
// id_stage -> regfile
wire rs1_r_ena;
wire [4 : 0]rs1_r_addr;
wire rs2_r_ena;
wire [4 : 0]rs2_r_addr;
wire rd_w_ena;
wire [4 : 0]rd_w_addr;

// id_stage -> exe/mem_stage
wire [`REG_BUS] exe_op1;
wire [`REG_BUS] exe_op2;
wire [`OP_BUS] op_info;
wire [`ALU_BUS] alu_info;
wire [`BJ_BUS]  bj_info;
wire [`LOAD_BUS] load_info;
wire [`SAVE_BUS] save_info;
wire is_word_opt;

// id stage -> mem_stage
wire mem_wr_ena;
wire mem_rd_ena;

// id_stage -> if_stage
wire [`REG_BUS] jmp_imm;

// regfile -> id_stage
wire [`REG_BUS] r_data1;
wire [`REG_BUS] r_data2;
// regfile ->difftest
wire [`REG_BUS] regs[0 : 31];

// exe_stage -> mem/wb_stage
wire [`REG_BUS] exe_data;
wire [`REG_BUS] mem_addr = exe_data;
// exe_stage -> if_stage
wire bj_ena;

// mem_helper -> mem_stage
wire mem_rd_data;

// mem_stage -> wb_stage
wire [`REG_BUS] mem_data;
// mem_stage -> mem_helper
wire [7 : 0] byte_enable;
wire [`REG_BUS] mem_wr_data;

// wb_stage -> regfile
wire [`REG_BUS] rd_data;

// Access memory
RAM_1W2R RAM_1W2R(
  .clk(clock),
  
  .inst_addr(pc),
  .inst_ena(1),
  .inst(inst),

  .mem_wr_ena(mem_wr_ena),
  .mem_rd_ena(mem_rd_ena),
  .byte_enable(byte_enable),
  .mem_addr(mem_addr),
  .mem_wr_data(mem_wr_data),
  .mem_rd_data(mem_rd_data)
);

if_stage If_stage(
  .clk(clock),
  .rst(reset),
  .bj_ena(bj_ena),
  .jmp_imm(jmp_imm),
  
  .pc_o(pc)
);

id_stage Id_stage(
  .rst(reset),
  .inst(inst),
  .r_data1(r_data1),
  .r_data2(r_data2),
  .inst_addr(pc),

  .rs1_r_ena(rs1_r_ena),
  .rs1_r_addr(rs1_r_addr),
  .rs2_r_ena(rs2_r_ena),
  .rs2_r_addr(rs2_r_addr),
  .rd_w_ena(rd_w_ena),
  .rd_w_addr(rd_w_addr),

  .is_word_opt(is_word_opt),
  .exe_op1(exe_op1),
  .exe_op2(exe_op2),
  
  .mem_rd_ena(mem_rd_ena),
  .mem_wr_ena(mem_wr_ena),

  .op_info(op_info),
  .alu_info(alu_info),
  .bj_info(bj_info),
  .load_info(load_info),
  .save_info(save_info),
  .jmp_imm(jmp_imm)
);

exe_stage Exe_stage(
  .rst(reset),
  .exe_op1(exe_op1),
  .exe_op2(exe_op2),
  .is_word_opt(is_word_opt),
  .op_info(op_info),
  .alu_info(alu_info),
  .bj_info(bj_info),
  
  .rd_data(exe_data),
  .bj_ena(bj_ena)
);

mem_stage Mem_stage(
  .rst(reset),
  .r_data2(r_data2),
  .load_info(load_info),
  .save_info(save_info),
  .mem_addr(mem_addr),
  .mem_rd_data(mem_rd_data),

  .mem_data(mem_data),
  .mem_wr_data(mem_wr_data),
  .byte_enable(byte_enable)
);

wb_stage Wb_stage(
  .rst(reset),
  .mem_to_reg(mem_rd_ena),
  .exe_data(exe_data),
  .mem_data(mem_data),

  .w_data(rd_data)
);

regfile Regfile(
  .clk(clock),
  .rst(reset),
  .w_addr(rd_w_addr),
  .w_data(rd_data),
  .w_ena(rd_w_ena),
  
  .r_addr1(rs1_r_addr),
  .r_data1(r_data1),
  .r_ena1(rs1_r_ena),
  .r_addr2(rs2_r_addr),
  .r_data2(r_data2),
  .r_ena2(rs2_r_ena),

  .regs_o(regs)
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
    {cmt_wen, cmt_wdest, cmt_wdata, cmt_pc, cmt_inst, vaild, cycleCnt, instrCnt} = 0;
  end
  else begin
    cmt_wen = rd_w_ena;
    cmt_wdest = {3'd0, rd_w_addr};
    cmt_wdata = rd_data;
    cmt_pc = pc;
    cmt_inst = inst;
    vaild = 1'd1;

    // Skip comparison of the first instruction
    // Because the result required to commit cannot be calculated in time before first InstrCommit during verilator simulation
    // Maybe you can avoid it in pipeline
    skip = pc == `PC_START;
    
    cycleCnt += 1;
    instrCnt += 1;
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
  .valid              (inst[6:0] == 7'h6b),
  .code               (regs[10][7:0]),
  .pc                 (cmt_pc),
  .cycleCnt           (cycleCnt),
  .instrCnt           (instrCnt)
);

DifftestCSRState DifftestCSRState(
  .clock              (clock),
  .coreid             (0),
  .priviledgeMode     (0),
  .mstatus            (0),
  .sstatus            (0),
  .mepc               (0),
  .sepc               (0),
  .mtval              (0),
  .stval              (0),
  .mtvec              (0),
  .stvec              (0),
  .mcause             (0),
  .scause             (0),
  .satp               (0),
  .mip                (0),
  .mie                (0),
  .mscratch           (0),
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