
/* verilator lint_off UNUSED */
//--Sun Jiru, Nanjing University--

`timescale 1ns / 1ps

`include "defines.v"

module cpu(
  input wire            clock,
  input wire            reset,
  
  // Custom interface
  output                if_rw_valid,
  input                 if_rw_ready,
  input  [`REG_BUS]     if_r_data,
  output [`REG_BUS]     if_rw_addr,
  output [1 : 0]        if_rw_size,
  input  [1 : 0]        if_rw_resp,

  output                mem_rw_valid,
  input                 mem_rw_ready,
  output                mem_rw_req,
  input  [`REG_BUS]     mem_r_data,
  output [`REG_BUS]     mem_w_data,
  output [`REG_BUS]     mem_rw_addr,
  output [1 : 0]        mem_rw_size,
  input  [1 : 0]        mem_rw_resp
);
  
  // pipeline control
  wire if_valid;
  wire if_ready_go;
  wire if_to_id_valid;
  reg if_stage_refresh;
  assign if_to_id_valid = if_valid && if_ready_go;
  // IF stage
  wire [`EXCP_BUS] if_excp;
  wire [`REG_BUS] bj_pc, excp_pc, if_pc;
  wire [31 : 0] if_inst;
  wire bj_ena;
  if_stage If_stage(
    .clk(clock),
    .rst(reset),
    .refresh(if_stage_refresh),
    
    // branch and jump control
    .bj_ena(bj_ena),
    .bj_pc(bj_pc),
    .excp_jmp_ena(excp_jmp_ena),
    .excp_pc(excp_pc),
    
    // output to pipeline
    .if_pc(if_pc),
    .if_inst(if_inst),
    
    // Custom Interface
    .if_axi_valid(if_rw_valid),
    .if_axi_ready(if_rw_ready),
    .if_axi_data_read(if_r_data),
    .if_axi_addr(if_rw_addr),
    .if_axi_size(if_rw_size),
    .if_axi_resp(if_rw_resp),

    .if_finish(if_valid)
  );
  
  // IF/ID reg
  reg [`REG_BUS] id_pc;
  reg [31  :  0] id_inst;
  wire flush = bj_ena;
  
  // pipeline control
  reg id_valid;
  wire id_allowin;
  wire id_ready_go;
  wire id_to_ex_valid;
  
  assign id_ready_go = ~stall;
  assign id_allowin = !id_valid || id_ready_go && ex_allowin;
  assign id_to_ex_valid = id_valid && id_ready_go;
  
  always @(posedge clock) begin
    if (reset) begin
      if_stage_refresh = 1'b1;
    end
    else if (if_to_id_valid && id_allowin) begin
      if_stage_refresh = 1'b1;
    end
    else begin
      if_stage_refresh = 1'b0;
    end
  end
  
  always @(posedge clock) begin
    if (reset) begin
      id_valid <= 1'b0;
    end
    else if (id_allowin) begin
      id_valid <= if_to_id_valid;
    end
    
    if (if_to_id_valid && id_allowin) begin
      id_pc <= if_pc;
      id_inst <= if_inst;
    end
  end

  hazard Hazard(
    .ex_ram_rd_ena(ex_ram_rd_ena),
    .ex_reg_wr_addr(ex_reg_wr_addr),
    .rs1_addr(rs1_r_addr),
    .rs2_addr(rs2_r_addr),

    .stall(stall)
  );
  wire stall;
  
  // exception
  wire [`EXCP_BUS] id_excp;

  // ID stage
  id_stage Id_stage(
    .clk(clock),
    .rst(reset),

    .inst(id_inst),
    .pc_id(id_pc),
  
    // data from regfile and CSRs
    .r_data1(r_data1),
    .r_data2(r_data2),
    .csr_data(id_csr_data),
    
    // control reg
    .rs1_r_ena(rs1_r_ena),
    .rs1_addr(rs1_r_addr),
    .rs2_r_ena(rs2_r_ena),
    .rs2_addr(rs2_r_addr),
    
    // control csr
    .csr_rd_ena(csr_rd_ena),
    .csr_rd_addr(csr_rd_addr),
    
    // -> ex
    .id_op1(id_op1),
    .id_op2(id_op2),
    .use_rs1(id_use_rs1),
    .use_rs2(id_use_rs2),
    .id_rs1_data(id_rs1_data),
    .id_rs2_data(id_rs2_data),
    
    .is_word_opt(id_is_word_opt),
    .alu_info(id_alu_info),
    .bj_info(id_bj_info),
    .load_info(id_load_info),
    .save_info(id_save_info),
    .jmp_imm(id_jmp_imm),
    
    // -> mem
    .mem_rd_ena(id_ram_rd_ena),
    .mem_wr_ena(id_ram_wr_ena),
    
    // -> wb
    .reg_wr_ctrl(id_reg_wr_ctrl),
    .reg_wr_addr(id_reg_wr_addr),
    .reg_wr_ena(id_reg_wr_ena),
    .csr_wr_ena(id_csr_wr_ena),
    .csr_wr_addr(id_csr_wr_addr)
  );
  wire id_is_word_opt;
  wire [`ALU_BUS] id_alu_info;
  wire [`BJ_BUS] id_bj_info;
  wire [`LOAD_BUS] id_load_info;
  wire [`SAVE_BUS] id_save_info;
  wire [`REG_BUS] id_jmp_imm;
  wire [`REG_BUS] id_op1, id_op2;
  wire id_use_rs1, id_use_rs2;
  wire [`REG_BUS] id_rs1_data, id_rs2_data;
  wire [`REG_BUS] id_csr_data;

  wire id_ram_wr_ena, id_ram_rd_ena;
  
  wire [`REG_CTRL_BUS] id_reg_wr_ctrl;
  wire [4 : 0] id_reg_wr_addr;
  wire id_reg_wr_ena;
  wire [11: 0] id_csr_wr_addr;
  wire id_csr_wr_ena;

  // ID/EX reg
  reg [`REG_BUS] ex_pc;
  reg [31  :  0] ex_inst;
  reg ex_is_word_opt;
  reg [`ALU_BUS] ex_alu_info;
  reg [`BJ_BUS] ex_bj_info;
  reg [`REG_BUS] ex_jmp_imm;
  reg [`REG_BUS] ex_now_op1, ex_now_op2;
  reg ex_use_rs1, ex_use_rs2;
  reg [`REG_BUS] ex_rs1_data, ex_rs2_data;
  reg [4 : 0] ex_rs1_addr, ex_rs2_addr;
  reg [`REG_BUS] ex_csr_data;

  // -> mem
  reg ex_ram_wr_ena_r, ex_ram_rd_ena_r;
  wire ex_ram_wr_ena = ex_ram_wr_ena_r & ex_valid;
  wire ex_ram_rd_ena = ex_ram_rd_ena_r & ex_valid;
  reg [`LOAD_BUS] ex_load_info;
  reg [`SAVE_BUS] ex_save_info;

  // -> wb
  reg [`REG_CTRL_BUS] ex_reg_wr_ctrl;
  reg [4 : 0] ex_reg_wr_addr;
  reg ex_reg_wr_ena_r;
  wire ex_reg_wr_ena = ex_reg_wr_ena_r & ex_valid;
  reg [11 : 0] ex_csr_wr_addr;
  reg ex_csr_wr_ena_r;
  wire ex_csr_wr_ena = ex_csr_wr_ena_r & ex_valid;
  
  // pipeline control
  reg ex_valid;
  wire ex_allowin;
  wire ex_ready_go;
  wire ex_to_mem_valid;
  
  assign ex_ready_go = 1'b1;
  assign ex_allowin = !ex_valid || ex_ready_go && mem_allowin;
  assign ex_to_mem_valid = ex_valid && ex_ready_go;
  
  always @(posedge clock) begin
    if (reset || flush) begin
      ex_valid <= 1'b0;
    end
    else if (ex_allowin) begin
      ex_valid <= id_to_ex_valid;
    end
  end

  always @(posedge clock) begin
    if (id_to_ex_valid && ex_allowin) begin
      ex_pc <= id_pc;
      ex_inst <= id_inst;
      ex_is_word_opt <= id_is_word_opt;
      ex_alu_info <= id_alu_info;
      ex_bj_info <= id_bj_info;
      ex_jmp_imm <= id_jmp_imm;
      ex_now_op1 <= id_op1;
      ex_now_op2 <= id_op2;
      ex_use_rs1 <= id_use_rs1;
      ex_use_rs2 <= id_use_rs2;
      ex_rs1_data <= id_rs1_data;
      ex_rs2_data <= id_rs2_data;
      ex_rs1_addr <= rs1_r_addr;
      ex_rs2_addr <= rs2_r_addr;
      
      // -> mem
      ex_ram_wr_ena_r <= id_ram_wr_ena;
      ex_ram_rd_ena_r <= id_ram_rd_ena;
      ex_load_info <= id_load_info;
      ex_save_info <= id_save_info;

      // -> wb
      ex_csr_data <= id_csr_data;
      ex_reg_wr_ctrl <= id_reg_wr_ctrl & {3{id_valid}};
      ex_reg_wr_addr <= id_reg_wr_addr;
      ex_reg_wr_ena_r <= id_reg_wr_ena;
      ex_csr_wr_addr <= id_csr_wr_addr;
      ex_csr_wr_ena_r <= id_csr_wr_ena;
    end
  end

  forward Forward(
    .rs1_addr(ex_rs1_addr),
    .rs2_addr(ex_rs2_addr),
    .mem_reg_wr_addr(mem_reg_wr_addr),
    .mem_reg_wr_ena(mem_reg_wr_ena),
    .wb_reg_wr_addr(wb_reg_wr_addr),
    .wb_reg_wr_ena(wb_reg_wr_ena),
    .mem_ex_data(mem_ex_data),
    .wb_ex_data(wb_ex_data),
    .wb_mem_data(wb_ram_data),
    .mem_reg_wr_ctrl(mem_reg_wr_ctrl),
    .wb_reg_wr_ctrl(wb_reg_wr_ctrl),
    .rs1_now(ex_rs1_data),
    .rs2_now(ex_rs2_data),

    .rs1_forward(rs1_forward),
    .rs2_forward(rs2_forward)
  );
  
  // forward rs1, rs2
  wire [`REG_BUS] rs1_forward, rs2_forward;

  // True operands, considering "forwards"
  wire [`REG_BUS] true_op1, true_op2;
  
  assign true_op1 = ex_use_rs1 ? rs1_forward : ex_now_op1;
  assign true_op2 = ex_use_rs2 ? rs2_forward : ex_now_op2;
  
  ex_stage Ex_stage(
    .rst(reset),
    
    .ex_valid(ex_valid),
    .ex_op1(true_op1),
    .ex_op2(true_op2),
    .rs1_forward(rs1_forward),
    .rs2_forward(rs2_forward),
    .is_word_opt(ex_is_word_opt),
    .alu_info(ex_alu_info),
    .bj_info(ex_bj_info),
    .jmp_imm(ex_jmp_imm),
    .now_pc(ex_pc),

    .rd_data(ex_data),
    .bj_pc(bj_pc),
    .bj_ena(bj_ena)
  );
  
  wire [`REG_BUS] ex_data;
  
  
  // EX_MEM reg
  reg [`REG_BUS] mem_pc;
  reg [31  :  0] mem_inst;
  reg [`LOAD_BUS] mem_load_info;
  reg [`SAVE_BUS] mem_save_info;
  reg [`REG_BUS] mem_ram_wr_src;
  reg [`REG_BUS] mem_ex_data, mem_csr_data;
  reg mem_ram_wr_ena, mem_ram_rd_ena;
  
  reg [`REG_CTRL_BUS] mem_reg_wr_ctrl;
  reg [4 : 0] mem_reg_wr_addr;
  reg mem_reg_wr_ena;
  reg [11: 0] mem_csr_wr_addr;
  reg mem_csr_wr_ena;
  
  // pipeline control
  reg mem_stage_refresh; // the first beat of mem_stage
  reg mem_valid;
  wire mem_allowin;
  wire mem_ready_go;
  wire mem_to_wb_valid;
  wire mem_finish;
  
  assign mem_ready_go = (
      (~mem_ram_rd_ena && ~mem_ram_wr_ena)
    | mem_finish
  );
  assign mem_allowin = !mem_valid || mem_ready_go && wb_allowin;
  assign mem_to_wb_valid = mem_valid && mem_ready_go;
  
  always @(posedge clock) begin
    if (reset) begin
      mem_valid <= 1'b0;
    end
    else if (mem_allowin) begin
      mem_valid <= ex_to_mem_valid;
    end
  end

  always @(posedge clock) begin
    if (ex_to_mem_valid && mem_allowin) begin
      mem_pc <= ex_pc;
      mem_inst <= ex_inst;
      mem_load_info <= ex_load_info;
      mem_save_info <= ex_save_info;
      mem_ram_wr_src <= rs2_forward;
      mem_ex_data <= ex_data;
      mem_csr_data <= ex_csr_data;
      mem_ram_wr_ena <= ex_ram_wr_ena & ex_valid;
      mem_ram_rd_ena <= ex_ram_rd_ena & ex_valid;

      // -> wb
      mem_reg_wr_ctrl <= ex_reg_wr_ctrl & {3{ex_valid}};
      mem_reg_wr_addr <= ex_reg_wr_addr;
      mem_reg_wr_ena <= ex_reg_wr_ena & ex_valid;
      mem_csr_wr_ena <= ex_csr_wr_ena & ex_valid;
    end
  end

  always @(posedge clock) begin
    if (reset) begin
      mem_stage_refresh <= 1'b0;
    end
    else if (ex_to_mem_valid && mem_allowin) begin
      mem_stage_refresh <= 1'b1;
    end
    else begin
      mem_stage_refresh <= 1'b0;
    end
  end

  // mem_stage -> excp_handler
  wire [`EXCP_BUS] mem_excp;
  
  // MEM_STAGE
  mem_stage Mem_stage(
    .clk(clock),
    .rst(reset),
    .refresh(mem_stage_refresh),
  
    .ram_wr_src(mem_ram_wr_src),
    .load_info(mem_load_info),
    .save_info(mem_save_info),
    .mem_addr(mem_ex_data),
    .ram_rd_ena(mem_ram_rd_ena),
    .ram_wr_ena(mem_ram_wr_ena),
    
    // to wb_stage
    .mem_data(mem_ram_data),

    // to exception
    .mem_excp(mem_excp),
    
    // Custom interface
    .mem_rw_valid(mem_rw_valid),
    .mem_rw_ready(mem_rw_ready),
    .mem_rw_req(mem_rw_req),
    .mem_r_data(mem_r_data),
    .mem_w_data(mem_w_data),
    .mem_rw_addr(mem_rw_addr),
    .mem_rw_size(mem_rw_size),
    .mem_rw_resp(mem_rw_resp),
    
    .mem_finish(mem_finish)
  );

  wire [`REG_BUS] mem_ram_data;

  // MEM/WB reg
  reg [`REG_BUS] wb_pc;
  reg [31  :  0] wb_inst;
  reg [`REG_CTRL_BUS] wb_reg_wr_ctrl;
  reg [`REG_BUS] wb_ex_data, wb_ram_data, wb_csr_data;
  reg [4 : 0] wb_reg_wr_addr;
  reg wb_reg_wr_ena;
  reg [11: 0] wb_csr_wr_addr;
  reg wb_csr_wr_ena;

  // pipeline control
  reg wb_valid;
  wire wb_allowin = 1'b1;
  
  always @(posedge clock) begin
    if (reset) begin
      wb_valid <= 1'b0;
    end
    else if (wb_allowin) begin
      wb_valid <= mem_to_wb_valid;
    end
  end

  always @(posedge clock) begin
    if (mem_to_wb_valid && wb_allowin) begin
      wb_pc <= mem_pc;
      wb_inst <= mem_inst;
      wb_reg_wr_ctrl <= mem_reg_wr_ctrl & {3{mem_valid}};
      wb_ex_data <= mem_ex_data;
      wb_ram_data <= mem_ram_data;
      wb_csr_data <= mem_csr_data;
      wb_reg_wr_addr <= mem_reg_wr_addr;
      wb_reg_wr_ena <= mem_reg_wr_ena & mem_valid;
      wb_csr_wr_addr <= mem_csr_wr_addr;
      wb_csr_wr_ena <= mem_csr_wr_ena & mem_valid;
    end
  end
  
  // WB_STAGE
  wb_stage Wb_stage(
    .rst(reset),
    
    .reg_wr_ctrl(wb_reg_wr_ctrl),
    .exe_data(wb_ex_data),
    .mem_data(wb_ram_data),
    .csr_data(wb_csr_data),
    
    .reg_wr_data(wb_reg_wr_data)
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
  wire [`REG_BUS] wb_reg_wr_data;
  
  // difftest
  wire [`REG_BUS] regs[0 : 31];

  regfile Regfile(
    .clk(clock),
    .rst(reset),
    .w_addr(wb_reg_wr_addr),
    .w_data(wb_reg_wr_data),
    .w_ena(wb_reg_wr_ena),
  
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
  wire excp_jmp_ena;
  wire [`REG_BUS] excp_pc;
  excp_handler Excp_handler(
    .if_excp(if_excp),
    .id_excp(id_excp),
    .mem_excp(mem_excp),
    .itrp_info(0),
    .now_pc(mem_pc),
    .now_inst(mem_inst),
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
  
  .csr_wr_ena(wb_csr_wr_ena),
  .csr_wr_addr(wb_csr_wr_addr),
  .csr_rd_ena(csr_rd_ena),
  .csr_rd_addr(csr_rd_addr),
  .csr_wr_data(wb_ex_data),
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
    cmt_wen <= wb_reg_wr_ena;
    cmt_wdest <= {3'd0, wb_reg_wr_addr};
    cmt_wdata <= wb_reg_wr_data;
    cmt_pc <= wb_pc;
    cmt_inst <= wb_inst;
    vaild <= wb_valid;

    // Skip comparison of the first instruction
    // Because the result required to commit cannot be calculated in time before first InstrCommit during verilator simulation
    // Maybe you can avoid it in pipeline
    skip <= (if_pc == `PC_START);
    
    cycleCnt <= cycleCnt + 1;
    instrCnt <= instrCnt + wb_valid;
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
  .valid              (wb_inst[6:0] == 7'h6b),
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
