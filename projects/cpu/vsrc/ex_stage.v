
//--Sun Jiru, Nanjing University--

`include "defines.v"

module ex_stage(
  input wire                              clk,
  input wire                              rst,
  
  // pipeline control
  input wire                              id_to_ex_valid,
  input wire [`REG_BUS]                   id_to_ex_pc,
  input wire [`INST_BUS]                  id_to_ex_inst,
  input wire [`ID_TO_EX_WIDTH-1:0]        id_to_ex_bus,
  output wire                             ex_allowin,

  output wire                             ex_to_mem_valid,
  output wire [`REG_BUS]                  ex_to_mem_pc,
  output wire [`INST_BUS]                 ex_to_mem_inst,
  output wire [`EX_TO_MEM_WIDTH-1:0]      ex_to_mem_bus,
  input wire                              mem_allowin,
  
  input wire [`MEM_FORWARD_WIDTH-1:0]     mem_forward_bus,
  input wire [`WB_FORWARD_WIDTH-1:0]      wb_forward_bus,
  
  input wire                              if_bj_ready,
  output wire [`BJ_CTRL_WIDTH-1:0]        bj_ctrl_bus,

  // csr control
  output wire                             csr_wr_ena,
  output wire [11 : 0]                    csr_wr_addr,
  output wire [`REG_BUS]                  csr_wr_data,

  // exception
  output wire                             excp_enter,
  output wire                             excp_exit,
  input wire [`EXCP_RD_WIDTH-1:0]         csr_excp_rd_bus,
  output wire [`EXCP_WR_WIDTH-1:0]        csr_excp_wr_bus,
  input wire [`ITRP_BUS]                  clint_interupt_bus,

  output wire                             ex_rs1_r_ena,
  output wire [4 : 0]                     ex_rs1_addr,
  output wire                             ex_rs2_r_ena,
  output wire [4 : 0]                     ex_rs2_addr,
  input wire [`REG_BUS]                   rs1_data,
  input wire [`REG_BUS]                   rs2_data,

  // difftest bus
  input wire [`ID_TO_EX_DIFF_WIDTH-1:0]   id_to_ex_diffbus,
  input wire [`CSR_TO_EX_DIFF_WIDTH-1:0]  csr_to_ex_diffbus,
  output wire [`EX_TO_MEM_DIFF_WIDTH-1:0] ex_to_mem_diffbus
  );

  // read GPRs
  assign ex_rs1_r_ena = 1'b1;
  assign ex_rs2_r_ena = 1'b1;
  
  // pipeline control
  reg ex_valid;
  wire ex_ready_go;

  reg [`REG_BUS] id_to_ex_pc_r;
  reg [`INST_BUS] id_to_ex_inst_r;
  reg [`ID_TO_EX_WIDTH-1:0] id_to_ex_bus_r;
  reg [`ID_TO_EX_DIFF_WIDTH-1:0] id_to_ex_diffbus_r;
  
  wire itrp_valid;
  wire ex_done = ~hazard;
  wire bj_handshake = ex_bj_valid && if_bj_ready;
  assign ex_ready_go = ((~(|ex_bj_info) && ~excp_jmp_ena)|| bj_handshake) && ex_done;
  assign ex_allowin = !ex_valid || ex_ready_go && mem_allowin;
  //assign ex_to_mem_valid = ex_valid && ex_ready_go && ~ex_flush;
  assign ex_to_mem_valid = (ex_valid || itrp_valid) && ex_ready_go;


  always @(posedge clk) begin
    if (rst) begin
      ex_valid <= 1'b0;
    end
    else if (ex_allowin) begin
      ex_valid <= id_to_ex_valid;
    end

    if (id_to_ex_valid && ex_allowin) begin
      id_to_ex_pc_r <= id_to_ex_pc;
      id_to_ex_inst_r <= id_to_ex_inst;
      id_to_ex_bus_r <= id_to_ex_bus;
      id_to_ex_diffbus_r <= id_to_ex_diffbus;
      ex_itrp_bus <= clint_interupt_bus & {12{itrp_allowin}};
    end
  end
  
  assign ex_pc = id_to_ex_pc_r;
  assign ex_inst = id_to_ex_inst_r;
  assign {
    // serial port output
    ex_uart_out_valid, // 575:575
    
    // exception
    ex_excp_exit,   // 566:566
    ex_excp_bus,    // 565:550

    // -> ex
    ex_rs1_addr,    // 451:447
    ex_rs2_addr,    // 446:442
    ex_op1,         // 441:378
    ex_op2,         // 377:314
    ex_use_rs1,     // 313:313
    ex_use_rs2,     // 312:312
    ex_rs1_data,    // 311:248
    ex_rs2_data,    // 247:184
    ex_is_word_opt, // 183:183
    ex_alu_info,    // 182:171
    ex_bj_info,     // 170:163
    ex_jmp_imm,     // 162:99
    
    // -> mem
    ex_load_info,   // 98 :92
    ex_save_info,   // 91 :88
    ex_ram_rd_ena,  // 87 :87
    ex_ram_wr_ena,  // 86 :86
    
    // -> reg
    ex_reg_wr_ctrl, // 85: 83
    ex_reg_wr_ena,  // 82: 82
    ex_reg_wr_addr, // 81 :77

    // -> csr
    ex_csr_wr_ena,  // 76 :76
    ex_csr_wr_addr, // 75 :64
    ex_csr_rd_data  // 64 :0
  } = id_to_ex_bus_r & {`ID_TO_EX_WIDTH{ex_valid & ~itrp_valid}};
  
  wire                   ex_uart_out_valid;
  wire [7 : 0]           ex_uart_out_char = rs1_forward[7 : 0];
  wire [`INST_BUS]       ex_inst;
  wire [`REG_BUS]        ex_pc;
  wire [`REG_BUS]        ex_op1, ex_op2;
  wire                   ex_use_rs1, ex_use_rs2;
  wire [`REG_BUS]        ex_rs1_data, ex_rs2_data;
  wire                   ex_is_word_opt;
  wire [`ALU_BUS]        ex_alu_info;
  wire [`BJ_BUS]         ex_bj_info;
  wire [`REG_BUS]        ex_jmp_imm;

  wire [`LOAD_BUS]       ex_load_info;
  wire [`SAVE_BUS]       ex_save_info;
  wire                   ex_ram_rd_ena, ex_ram_wr_ena;
  
  wire [`REG_CTRL_BUS]   ex_reg_wr_ctrl;
  wire                   ex_reg_wr_ena, ex_csr_wr_ena;
  wire [4 : 0]           ex_reg_wr_addr;
  wire [11: 0]           ex_csr_wr_addr;
  wire [`REG_BUS]        ex_csr_rd_data;
  
  wire hazard;
  forward Forward(
    .ex_rs1_addr         (ex_rs1_addr),
    .ex_rs2_addr         (ex_rs2_addr),
    //.ex_rs1_data         (ex_rs1_data),
    //.ex_rs2_data         (ex_rs2_data),
    .ex_rs1_data         (rs1_data),
    .ex_rs2_data         (rs2_data),
    .ex_use_rs1          (ex_use_rs1),
    .ex_use_rs2          (ex_use_rs2),

    .mem_forward_bus     (mem_forward_bus),
    .wb_forward_bus      (wb_forward_bus),

    .rs1_forward         (rs1_forward),
    .rs2_forward         (rs2_forward),

    .hazard              (hazard)
  );
  
  assign                 excp_exit = ex_excp_exit;
  assign                 excp_enter = ex_excp_enter;

  wire [`EXCP_BUS]       ex_excp_bus;
  reg  [`ITRP_BUS]       ex_itrp_bus;
  wire                   itrp_allowin;
  wire                   ex_excp_exit, ex_excp_enter;
  
  excp_handler Excp_handler(
    .excp_info           (ex_excp_bus),
    .itrp_info           (ex_itrp_bus),
    .now_pc              (ex_pc),
    .now_inst            (ex_inst),
    .mem_addr            (ex_data),
    .excp_exit           (ex_excp_exit),
    .excp_enter          (ex_excp_enter),
    .itrp_allowin        (itrp_allowin),
    
    // to CSRs
    .csr_excp_rd_bus     (csr_excp_rd_bus),
    .csr_excp_wr_bus     (csr_excp_wr_bus),
    
    // to if stage
    .excp_jmp_ena        (excp_jmp_ena),
    .excp_jmp_pc         (excp_jmp_pc),
    
    // to ex stage
    .itrp_valid          (itrp_valid),
    
    // to difftest
    .itrp_NO             (itrp_NO),
    .excp_NO             (excp_NO)
  );
  
  wire [`REG_BUS] rs1_forward, rs2_forward, true_op1, true_op2;
  assign true_op1 = ex_use_rs1 ? rs1_forward : ex_op1;
  assign true_op2 = ex_use_rs2 ? rs2_forward : ex_op2;
  wire [`REG_BUS] op1 = {{32{~ex_is_word_opt}} & true_op1[63 : 32], true_op1[31 : 0]};
  wire [`REG_BUS] op2 = {{32{~ex_is_word_opt}} & true_op2[63 : 32], true_op2[31 : 0]};
  
  // alu -> bj
  wire [`BJ_BUS] ex_bj_data;
  
  ex_stage_alu Exe_stage_alu(
    .rst                 (rst),
    .op1                 (op1),
    .op2                 (op2),
    .alu_info            (ex_alu_info),
    .is_word_opt         (ex_is_word_opt),
    
    .alu_output          (ex_data),
    .bj_data             (ex_bj_data)
  );
  
  ex_stage_bj Exe_stage_bj(
    .rst                 (rst),
    .ex_valid            (ex_valid),
    .bj_info             (ex_bj_info),
    .bj_data             (ex_bj_data),
    .jmp_imm             (ex_jmp_imm),
    .rs1_data            (rs1_forward),
    .ex_pc               (ex_pc),
    
    .bj_ena              (ex_bj_ena),
    .new_pc              (ex_bj_pc)
  );
  
  wire [`REG_BUS] ex_ram_wr_src = rs2_forward;
  wire [`REG_BUS] ex_data;
  assign ex_to_mem_pc = ex_pc;
  assign ex_to_mem_inst = ex_inst;
  assign ex_to_mem_bus = {
    // serial port output
    ex_uart_out_valid, // 319:319
    ex_uart_out_char,  // 318:311

    // mem
    ex_load_info,   // 214:208
    ex_save_info,   // 207:204
    ex_ram_wr_src,  // 203:140
    ex_data,        // 139:76
    ex_csr_rd_data, // 75 :12
    ex_ram_rd_ena,  // 11 :11
    ex_ram_wr_ena,  // 10 :10
    
    // wb
    ex_reg_wr_ctrl, // 9  :7
    ex_reg_wr_addr, // 6  :2
    ex_reg_wr_ena,  // 1  :1
    ex_csr_wr_ena   // 0  :0
  };

  wire [`REG_BUS]    ex_bj_pc, excp_jmp_pc;
  wire               ex_bj_ena, excp_jmp_ena;
  wire               ex_bj_valid; // 1: not finish the computation of branch
  
  assign ex_bj_valid = ~(|ex_bj_info) || ex_done;
  assign bj_ctrl_bus = {
    excp_jmp_ena ? excp_jmp_pc : ex_bj_pc,
    ex_bj_ena | excp_jmp_ena,
    ex_bj_valid
  };
  
  assign csr_wr_ena  = ex_csr_wr_ena;
  assign csr_wr_addr = ex_csr_wr_addr;
  assign csr_wr_data = ex_data;
  
  wire [`INST_BUS] itrp_NO, excp_NO;
  assign ex_to_mem_diffbus = {
    id_to_ex_diffbus_r || itrp_valid,

    csr_to_ex_diffbus,
    itrp_NO,
    excp_NO
  };

endmodule
