
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
  wire if_to_id_valid, id_to_ex_valid, ex_to_mem_valid, mem_to_wb_valid;
  wire id_allowin, ex_allowin, mem_allowin, wb_allowin;
  wire [`IF_TO_ID_WIDTH-1:0]     if_to_id_bus;
  wire [`ID_TO_EX_WIDTH-1:0]     id_to_ex_bus;
  wire [`EX_TO_MEM_WIDTH-1:0]    ex_to_mem_bus;
  wire [`MEM_TO_WB_WIDTH-1:0]    mem_to_wb_bus;

  // difftest bus
  wire [`CSR_TO_EX_DIFF_WIDTH-1:0] csr_to_ex_diffbus;
  wire [`EX_TO_MEM_DIFF_WIDTH-1:0] ex_to_mem_diffbus;
  wire [`MEM_TO_WB_DIFF_WIDTH-1:0] mem_to_wb_diffbus;
  wire [`WB_DIFFTEST_WIDTH-1:0]    difftest_bus;
  
  // branch and jump bus
  wire [`BJ_CTRL_WIDTH-1:0]      bj_ctrl_bus;

  // pipeline forward control bus
  wire [`MEM_FORWARD_WIDTH-1:0]  mem_forward_bus;
  wire [`WB_FORWARD_WIDTH-1:0]   wb_forward_bus;
  
  wire if_bj_ready;
  // IF stage
  if_stage If_stage(
    .clk                       (clock),
    .rst                       (reset),
    
    // pipeline control
    .if_to_id_valid            (if_to_id_valid),
    .if_to_id_bus              (if_to_id_bus),
    .id_allowin                (id_allowin),
    
    // branch and jump control
    .if_bj_ready               (if_bj_ready),
    .bj_ctrl_bus               (bj_ctrl_bus),
    //.excp_jmp_ena(excp_jmp_ena),
    //.excp_pc(excp_pc),
    
    // Custom Interface
    .if_axi_valid              (if_rw_valid),
    .if_axi_ready              (if_rw_ready),
    .if_axi_data_read          (if_r_data),
    .if_axi_addr               (if_rw_addr),
    .if_axi_size               (if_rw_size),
    .if_axi_resp               (if_rw_resp)
  );

  // ID stage
  id_stage Id_stage(
    .clk                       (clock),
    .rst                       (reset),
  
    // pipeline control
    .if_to_id_valid            (if_to_id_valid),
    .if_to_id_bus              (if_to_id_bus),
    .id_allowin                (id_allowin),
    .id_to_ex_valid            (id_to_ex_valid),
    .id_to_ex_bus              (id_to_ex_bus),
    .ex_allowin                (ex_allowin),

    // data from regfile and CSRs
    //.r_data1                   (r_data1),
    //.r_data2                   (r_data2),
    .csr_data                  (csr_rd_data),
    
    // control reg
    //.rs1_r_ena                 (rs1_r_ena),
    //.rs1_addr                  (rs1_r_addr),
    //.rs2_r_ena                 (rs2_r_ena),
    //.rs2_addr                  (rs2_r_addr),
    
    // control csr
    .csr_rd_ena                (csr_rd_ena),
    .csr_rd_addr               (csr_rd_addr),

    .bj_ctrl_bus               (bj_ctrl_bus)
  );
  
  ex_stage Ex_stage(
    .clk(clock),
    .rst(reset),
    
    // pipeline control
    .id_to_ex_valid            (id_to_ex_valid),
    .id_to_ex_bus              (id_to_ex_bus),
    .ex_allowin                (ex_allowin),

    .ex_to_mem_valid           (ex_to_mem_valid),
    .ex_to_mem_bus             (ex_to_mem_bus),
    .mem_allowin               (mem_allowin),
    
    // pipeline forward control
    .mem_forward_bus           (mem_forward_bus),
    .wb_forward_bus            (wb_forward_bus),
    
    // branch and jump control
    .if_bj_ready               (if_bj_ready),
    .bj_ctrl_bus               (bj_ctrl_bus),
    
    // csr control
    .csr_wr_ena                (csr_wr_ena),
    .csr_wr_addr               (csr_wr_addr),
    .csr_wr_data               (csr_wr_data),

    // exception
    .excp_enter                (excp_enter),
    .excp_exit                 (excp_exit),
    .csr_excp_rd_bus           (csr_excp_rd_bus),
    .csr_excp_wr_bus           (csr_excp_wr_bus),

    .rs1_r_ena                 (rs1_r_ena),
    .rs1_addr                  (rs1_r_addr),
    .rs2_r_ena                 (rs2_r_ena),
    .rs2_addr                  (rs2_r_addr),
    .rs1_data                  (r_data1),
    .rs2_data                  (r_data2),

    .csr_to_ex_diffbus         (csr_to_ex_diffbus),
    .ex_to_mem_diffbus         (ex_to_mem_diffbus)
  );

  // CSRs
  // id stage <-> csrfile
  wire            csr_rd_ena;
  wire [11 : 0]   csr_rd_addr;
  wire [`REG_BUS] csr_rd_data;
  // ex stage <=> csrfile
  wire            csr_wr_ena;
  wire [11 : 0]   csr_wr_addr;
  wire [`REG_BUS] csr_wr_data;
  // excption control
  wire                      excp_enter, excp_exit;
  wire [`EXCP_RD_WIDTH-1:0] csr_excp_rd_bus;
  wire [`EXCP_WR_WIDTH-1:0] csr_excp_wr_bus;

  // direct read and write
  wire [`CSR_TO_EX_DIFF_WIDTH-1:0] csr_to_ex_diffbus;

  csrfile CSRfile(
    .clk                       (clock),
    .rst                       (reset),
    
    // read: id stage
    .csr_rd_ena                (csr_rd_ena),
    .csr_rd_addr               (csr_rd_addr),
    .csr_rd_data               (csr_rd_data),
    
    // write: ex stages
    .csr_wr_ena                (csr_wr_ena),
    .csr_wr_addr               (csr_wr_addr),
    .csr_wr_data               (csr_wr_data),
    
    // exception
    .csr_excp_rd_bus           (csr_excp_rd_bus),
    .csr_excp_wr_bus           (csr_excp_wr_bus),

    .excp_enter                (excp_enter),
    .excp_exit                 (excp_exit),

    .csr_to_ex_diffbus         (csr_to_ex_diffbus)
  );
  
  // MEM_STAGE
  mem_stage Mem_stage(
    .clk                       (clock),
    .rst                       (reset),
  
    // pipeline control
    .ex_to_mem_valid           (ex_to_mem_valid),
    .ex_to_mem_bus             (ex_to_mem_bus),
    .mem_allowin               (mem_allowin),

    .mem_to_wb_valid           (mem_to_wb_valid),
    .mem_to_wb_bus             (mem_to_wb_bus),
    .wb_allowin                (wb_allowin),
    
    // pipeline forward control
    .mem_forward_bus           (mem_forward_bus),

    // difftest bus
    .ex_to_mem_diffbus         (ex_to_mem_diffbus),
    .mem_to_wb_diffbus         (mem_to_wb_diffbus),

    // Custom interface
    .mem_rw_valid              (mem_rw_valid),
    .mem_rw_ready              (mem_rw_ready),
    .mem_rw_req                (mem_rw_req),
    .mem_r_data                (mem_r_data),
    .mem_w_data                (mem_w_data),
    .mem_rw_addr               (mem_rw_addr),
    .mem_rw_size               (mem_rw_size),
    .mem_rw_resp               (mem_rw_resp)
  );
  
  // WB_STAGE
  wb_stage Wb_stage(
    .clk                       (clock),
    .rst                       (reset),
    
    // pipeline control
    .mem_to_wb_valid           (mem_to_wb_valid),
    .mem_to_wb_bus             (mem_to_wb_bus),
    .wb_allowin                (wb_allowin),

    .wb_forward_bus            (wb_forward_bus),

    // regfile control
    .reg_wr_ena                (reg_wr_ena),
    .reg_wr_addr               (reg_wr_addr),
    .reg_wr_data               (reg_wr_data),
    
    .mem_to_wb_diffbus         (mem_to_wb_diffbus),
    .difftest_bus              (difftest_bus)
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
  wire reg_wr_ena;
  wire [4 : 0] reg_wr_addr;
  wire [`REG_BUS] reg_wr_data;
  
  // difftest
  wire [`REG_BUS] regs[0 : 31];

  regfile Regfile(
    .clk                       (clock),
    .rst                       (reset),
    .w_addr                    (reg_wr_addr),
    .w_data                    (reg_wr_data),
    .w_ena                     (reg_wr_ena),
  
    .r_addr1                   (rs1_r_addr),
    .r_data1                   (r_data1),
    .r_ena1                    (rs1_r_ena),
    .r_addr2                   (rs2_r_addr),
    .r_data2                   (r_data2),
    .r_ena2                    (rs2_r_ena),
  
    .regs_o                    (regs)
  );
  
  // Difftest
  reg              cmt_wen;
  reg [7:0]        cmt_wdest;
  reg [`REG_BUS]   cmt_wdata;
  reg [`REG_BUS]   cmt_pc;
  reg [`INST_BUS]  cmt_inst;
  reg              cmt_valid, cmt_skip;
  reg [`REG_BUS]   cycleCnt, instrCnt;
  
  wire [`REG_BUS]  wb_pc, wb_rw_addr, wb_w_data;
  wire [`INST_BUS] wb_inst;
  wire             wb_commit, wb_w_ena, wb_r_ena;
  wire [7 : 0]     wb_w_mask;
  wire [`CSR_TO_EX_DIFF_WIDTH-1:0] wb_csr_diff;
  assign {
    // ex stage
    wb_csr_diff,
    
    // mem stage
    wb_rw_addr,
    wb_w_data,
    wb_w_mask,
    wb_w_ena,
    wb_r_ena,

    // wb stage 
    wb_pc,       // 96 :33
    wb_inst,     // 32 :1
    wb_commit    // 0  :0
  } = difftest_bus;

  always @(posedge clock) begin
    if (reset) begin
      {cmt_wen, cmt_wdest, cmt_wdata, cmt_pc, cmt_inst, cmt_valid, cmt_skip, cycleCnt, instrCnt} <= 0;
    end
    else begin
      cmt_wen <= reg_wr_ena;
      cmt_wdest <= {3'd0, reg_wr_addr};
      cmt_wdata <= reg_wr_data;
      cmt_pc <= wb_pc;
      cmt_inst <= wb_inst;
      cmt_valid <= wb_commit;
  
      // Skip comparison of the first instruction
      // Because the result required to commit cannot be calculated in time before first InstrCommit during verilator simulation
      // Maybe you can avoid it in pipeline
      cmt_skip <= wb_inst[6 : 0] == 7'h7b;
      
      cycleCnt <= cycleCnt + 1;
      instrCnt <= instrCnt + wb_commit;
    end
  end
  
  DifftestInstrCommit DifftestInstrCommit(
    .clock              (clock),
    .coreid             (0),
    .index              (0),
    .valid              (cmt_valid),
    .pc                 (cmt_pc),
    .instr              (cmt_inst),
    .skip               (cmt_skip),
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
    .valid              (cmt_inst[6:0] == 7'h6b),
    .code               (regs[10][7:0]),
    .pc                 (cmt_pc),
    .cycleCnt           (cycleCnt),
    .instrCnt           (instrCnt)
  );
  
  wire [`REG_BUS] wb_mstatus, wb_mepc, wb_mtval, wb_mtvec,
                  wb_mcause, wb_mip, wb_mie, wb_mscratch;
  assign {
    wb_mstatus,
    wb_mepc,
    wb_mtval,
    wb_mtvec,
    wb_mcause,
    wb_mip,
    wb_mie,
    wb_mscratch
  } = wb_csr_diff;

  reg [`REG_BUS] cmt_mstatus, cmt_mepc, cmt_mtval, cmt_mtvec, 
                 cmt_mcause, cmt_mip, cmt_mie, cmt_mscratch;
  always @(posedge clock) begin
    if (reset) begin
      {cmt_mstatus, cmt_mepc, cmt_mtval, cmt_mtvec, cmt_mcause, cmt_mip, cmt_mie, cmt_mscratch} <= 0;
    end
    else begin
      cmt_mstatus   <= wb_mstatus;
      cmt_mepc      <= wb_mepc;
      cmt_mtval     <= wb_mtval;
      cmt_mtvec     <= wb_mtvec;
      cmt_mcause    <= wb_mcause;
      cmt_mip       <= wb_mip;
      cmt_mie       <= wb_mie;
      cmt_mscratch  <= wb_mscratch; 
    end
  end

  DifftestCSRState DifftestCSRState(
    .clock              (clock),
    .coreid             (0),
    .priviledgeMode     (`RISCV_PRIV_MODE_M),
    .mstatus            (cmt_mstatus),
    .sstatus            (0),
    .mepc               (cmt_mepc),
    .sepc               (0),
    .mtval              (cmt_mtval),
    .stval              (0),
    .mtvec              (cmt_mtvec),
    .stvec              (0),
    .mcause             (cmt_mcause),
    .scause             (0),
    .satp               (0),
    .mip                (cmt_mip),
    .mie                (cmt_mie),
    .mscratch           (cmt_mscratch),
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
  
  
  reg [`REG_BUS] cmt_rw_addr, cmt_w_data, buf_rw_addr, buf_w_data;
  reg [7 : 0]    cmt_w_mask, buf_w_mask;
  reg            cmt_w_ena, cmt_r_ena, buf_w_ena, buf_r_ena;
  always @(posedge clock) begin
    if (reset) begin
      {cmt_rw_addr, cmt_w_data, cmt_w_mask, cmt_w_ena, cmt_r_ena} <= 0; 
    end
    else begin
      buf_rw_addr <= wb_rw_addr;
      buf_w_data  <= wb_w_data;
      buf_w_mask  <= wb_w_mask;
      buf_w_ena   <= wb_w_ena & wb_commit;
      buf_r_ena   <= wb_r_ena & wb_commit;

      cmt_rw_addr <= buf_rw_addr;
      cmt_w_data  <= buf_w_data;
      cmt_w_mask  <= buf_w_mask;
      cmt_w_ena   <= buf_w_ena;
      cmt_r_ena   <= buf_r_ena;
    end
  end
  
  DifftestStoreEvent DifftestStoreEvent(
    .clock              (clock),
    .coreid             (0),
    .index              (0),
    .valid              (cmt_w_ena),
    .storeAddr          (cmt_rw_addr),
    .storeData          (cmt_w_data),
    .storeMask          (cmt_w_mask)
  );
  
endmodule
