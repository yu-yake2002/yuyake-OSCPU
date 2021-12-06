
/* verilator lint_off UNDRIVEN */
/* verilator lint_off UNUSED */
//--Sun Jiru, Nanjing University--

`include "defines.v"

module id_stage(
  input wire                             rst,
  input wire                             clk,

  // pipeline control
  input wire                             if_to_id_valid,
  input wire [`REG_BUS]                  if_to_id_pc,
  input wire [`INST_BUS]                 if_to_id_inst,
  output wire                            id_allowin,

  output wire                            id_to_ex_valid,
  output wire [`REG_BUS]                 id_to_ex_pc,
  output wire [`INST_BUS]                id_to_ex_inst,
  output wire [`ID_TO_EX_WIDTH-1:0]      id_to_ex_bus,
  input wire                             ex_allowin,

  input wire [`REG_BUS]                  csr_data,

  // control csr
  output wire                            csr_rd_ena,
  output wire [11: 0]                    csr_rd_addr,

  input wire [`BJ_CTRL_WIDTH-1:0]        bj_ctrl_bus,

  output wire [`ID_TO_EX_DIFF_WIDTH-1:0] id_to_ex_diffbus
);

  wire                       rs1_r_ena;
  wire [4 : 0]               rs1_addr;
  wire                       rs2_r_ena;
  wire [4 : 0]               rs2_addr;

  wire [`REG_BUS] bj_pc;
  wire            bj_ena, bj_valid;
  assign {
    bj_pc,    // 33:2
    bj_ena,   // 1 :1
    bj_valid  // 0 :0
  } = bj_ctrl_bus;

  // pipeline control
  reg id_valid;
  wire id_ready_go;
  wire id_flush = bj_ena && bj_valid;
  reg [`REG_BUS] if_to_id_pc_r;
  reg [`INST_BUS] if_to_id_inst_r;

  assign id_ready_go = 1'b1;
  assign id_allowin = !id_valid || id_ready_go && ex_allowin;
  assign id_to_ex_valid = id_valid && id_ready_go && ~id_flush;

  always @(posedge clk) begin
    if (rst) begin
      id_valid <= 1'b0;
    end
    else if (id_allowin) begin
      id_valid <= if_to_id_valid;
    end
    else if (id_flush) begin // not allowin, and flush happen
      id_valid <= 1'b0;
    end
    
    if (if_to_id_valid && id_allowin) begin
      if_to_id_pc_r <= if_to_id_pc;
      if_to_id_inst_r <= if_to_id_inst;
    end
  end
  
  
  wire [`REG_BUS]  id_pc   = if_to_id_pc_r;
  wire [`INST_BUS] id_inst = if_to_id_inst_r;
  
  // decode
  wire [6  : 0] opcode = id_inst[6 : 0];
  wire [2  : 0] func3  = id_inst[14 : 12];
  wire [5  : 0] func6  = id_inst[31 : 26];
  wire [6  : 0] func7  = id_inst[31 : 25];
  wire [4  : 0] zimm = id_inst[19 : 15];
  
  assign rs1_addr = inst_putch ? 5'b01010 : {5{rs1_r_ena}} & id_inst[19 : 15];
  assign rs2_addr = {5{rs2_r_ena}} & id_inst[24 : 20];
  wire [11 : 0] id_csr_addr = id_inst[31 : 20];
  assign csr_rd_addr = id_csr_addr;
  wire [4  : 0] rd_addr = id_inst[11 : 7];
  
  wire [11 : 0] immI = id_csr_addr;
  wire [11 : 0] immS = {func7, id_inst[11 :  7]};
  wire [12 : 0] immB = {id_inst[31], id_inst[7], id_inst[30 : 25], id_inst[11 : 8], 1'b0};
  wire [19 : 0] immU = id_inst[31 : 12];
  wire [20 : 0] immJ = {id_inst[31], id_inst[19 : 12], id_inst[20], id_inst[30 : 21], 1'b0};
  
  // decode func3
  wire func3_0 = (func3 == 3'h0);
  wire func3_1 = (func3 == 3'h1);
  wire func3_2 = (func3 == 3'h2);
  wire func3_3 = (func3 == 3'h3);
  wire func3_4 = (func3 == 3'h4);
  wire func3_5 = (func3 == 3'h5);
  wire func3_6 = (func3 == 3'h6);
  wire func3_7 = (func3 == 3'h7);
  
  // decode func6
  wire func6_00 = (func6 == 6'h00);
  wire func6_10 = (func6 == 6'h10);
  
  // decode func7
  wire func7_00 = (func7 == 7'h00);
  wire func7_20 = (func7 == 7'h20);
  
  // decode imm12
  wire imm12_000 = (immI == 12'h000);
  wire imm12_001 = (immI == 12'h001);
  wire imm12_302 = (immI == 12'h302);
  
  // decode type
  wire inst_i_load        = (opcode == 7'h03);
  wire inst_i_fence       = (opcode == 7'h0f);
  wire inst_i_arith_dword = (opcode == 7'h13);
  wire inst_u_auipc       = (opcode == 7'h17);
  wire inst_s             = (opcode == 7'h23);
  wire inst_r_dword       = (opcode == 7'h33);
  wire inst_u_lui         = (opcode == 7'h37);
  wire inst_b             = (opcode == 7'h63);
  wire inst_i_jalr        = (opcode == 7'h67);
  wire inst_j             = (opcode == 7'h6f);
  wire inst_i_sys         = (opcode == 7'h73);
  wire inst_i_excp        = inst_i_sys & func3_0;
  wire inst_i_csr_imm     = inst_i_sys & (func3[2] == 1) & ~func3_0;
  wire inst_i_csr_reg     = inst_i_sys & (func3[2] == 0) & ~func3_0;
  //wire inst_t             = (opcode == 7'h6b); // signal of termination
  wire inst_putch         = (opcode == 7'h7b); //signal of putch

  // decode arithmetic
  // load
  wire inst_lb      = inst_i_load & func3_0;
  wire inst_lh      = inst_i_load & func3_1;
  wire inst_lw      = inst_i_load & func3_2;
  wire inst_lbu     = inst_i_load & func3_4;
  wire inst_lhu     = inst_i_load & func3_5;
  wire load_vld     = inst_lb | inst_lh | inst_lw | inst_lbu | inst_lhu;
  
  // fence
  wire inst_fence   = inst_i_fence & func3_0;
  wire inst_fence_i = inst_i_fence & func3_1;
  wire fence_vld    = inst_fence | inst_fence_i;
  
  // arith-i-dword
  wire inst_addi    = inst_i_arith_dword & func3_0;
  wire inst_slli    = inst_i_arith_dword & func3_1 & func6_00;
  wire inst_slti    = inst_i_arith_dword & func3_2;
  wire inst_sltiu   = inst_i_arith_dword & func3_3;
  wire inst_xori    = inst_i_arith_dword & func3_4;
  wire inst_srli    = inst_i_arith_dword & func3_5 & func6_00;
  wire inst_srai    = inst_i_arith_dword & func3_5 & func6_10;
  wire inst_ori     = inst_i_arith_dword & func3_6;
  wire inst_andi    = inst_i_arith_dword & func3_7;
  wire arith_id_vld = inst_addi | inst_slli | inst_slti | inst_sltiu 
                    | inst_xori | inst_srli | inst_srai | inst_ori
                    | inst_andi;
  
  // auipc
  wire inst_auipc   = inst_u_auipc;
  wire auipc_vld    = inst_auipc;
  
  // store
  wire inst_sb      = inst_s & func3_0;
  wire inst_sh      = inst_s & func3_1;
  wire inst_sw      = inst_s & func3_2;
  wire store_vld    = inst_sb | inst_sh | inst_sw;
  
  // arith-r-dword
  wire inst_add     = inst_r_dword & func3_0 & func7_00;
  wire inst_sub     = inst_r_dword & func3_0 & func7_20;
  wire inst_sll     = inst_r_dword & func3_1;
  wire inst_slt     = inst_r_dword & func3_2;
  wire inst_sltu    = inst_r_dword & func3_3;
  wire inst_xor     = inst_r_dword & func3_4;
  wire inst_srl     = inst_r_dword & func3_5 & func7_00;
  wire inst_sra     = inst_r_dword & func3_5 & func7_20;
  wire inst_or      = inst_r_dword & func3_6;
  wire inst_and     = inst_r_dword & func3_7;
  wire arith_rd_vld = inst_add  | inst_sub | inst_sll | inst_slt 
                    | inst_sltu | inst_xor | inst_srl | inst_sra
                    | inst_or   | inst_and;
  
  // lui
  wire inst_lui     = inst_u_lui;
  wire lui_vld      = inst_lui;

  // branch
  wire inst_beq     = inst_b & func3_0;
  wire inst_bne     = inst_b & func3_1;
  wire inst_blt     = inst_b & func3_4;
  wire inst_bge     = inst_b & func3_5;
  wire inst_bltu    = inst_b & func3_6;
  wire inst_bgeu    = inst_b & func3_7;
  wire branch_vld   = inst_beq | inst_bne  | inst_blt 
                    | inst_bge | inst_bltu | inst_bgeu;
  
  // jump
  wire inst_jalr    = inst_i_jalr;
  wire inst_jal     = inst_j;
  wire jump_vld     = inst_jalr | inst_jal;
  
  // exception
  wire inst_ecall   = inst_i_excp    & imm12_000;
  wire inst_ebreak  = inst_i_excp    & imm12_001;
  wire inst_mret    = inst_i_excp    & imm12_302;
  wire excp_vld     = inst_ecall | inst_ebreak | inst_mret;
  
  // csr
  wire inst_csrrw   = inst_i_csr_reg & func3_1;
  wire inst_csrrs   = inst_i_csr_reg & func3_2;
  wire inst_csrrc   = inst_i_csr_reg & func3_3;
  wire inst_csrrwi  = inst_i_csr_imm & func3_5;
  wire inst_csrrsi  = inst_i_csr_imm & func3_6;
  wire inst_csrrci  = inst_i_csr_imm & func3_7;
  wire csr_vld      = inst_csrrw  | inst_csrrs  | inst_csrrc
                    | inst_csrrwi | inst_csrrsi | inst_csrrci;
  
  // halt
  wire inst_halt    = id_inst == 32'hdead10cc;

  wire inst_vld     = load_vld | fence_vld | arith_id_vld | auipc_vld
                    | store_vld | arith_rd_vld | lui_vld
                    | branch_vld | jump_vld | excp_vld
                    | csr_vld | inst_halt;

  wire [`ALU_BUS] id_alu_info;
  assign id_alu_info[`ALU_ADD]  = inst_add   | inst_addi 
                             | inst_auipc | inst_lui    | inst_i_load | inst_s 
                             | inst_jal   | inst_jalr;
  assign id_alu_info[`ALU_SUB]  = inst_sub   | inst_b;
  assign id_alu_info[`ALU_SLT]  = inst_slt   | inst_slti   | inst_blt   | inst_bge;
  assign id_alu_info[`ALU_SLTU] = inst_sltu  | inst_sltiu  | inst_bltu  | inst_bgeu;
  assign id_alu_info[`ALU_XOR]  = inst_xor   | inst_xori   | inst_beq   | inst_bne;
  assign id_alu_info[`ALU_OR]   = inst_or    | inst_ori    | inst_csrrs | inst_csrrsi;
  assign id_alu_info[`ALU_AND]  = inst_and   | inst_andi;
  assign id_alu_info[`ALU_SLL]  = inst_sll   | inst_slli;
  assign id_alu_info[`ALU_SRL]  = inst_srl   | inst_srli;
  assign id_alu_info[`ALU_SRA]  = inst_sra   | inst_srai;
  assign id_alu_info[`ALU_ANDN] = inst_csrrc | inst_csrrci;
  assign id_alu_info[`ALU_WRI]  = inst_csrrw | inst_csrrwi;
  
  wire [`BJ_BUS] id_bj_info;
  assign id_bj_info[`BJ_BEQ]  = inst_beq;
  assign id_bj_info[`BJ_BNE]  = inst_bne;
  assign id_bj_info[`BJ_BLT]  = inst_blt;
  assign id_bj_info[`BJ_BGE]  = inst_bge;
  assign id_bj_info[`BJ_BLTU] = inst_bltu;
  assign id_bj_info[`BJ_BGEU] = inst_bgeu;
  assign id_bj_info[`BJ_JALR] = inst_jalr;
  assign id_bj_info[`BJ_JAL]  = inst_jal;
  assign id_bj_info[`BJ_HALT] = inst_halt;
  
  wire [`LOAD_BUS] id_load_info = {
    inst_lhu, inst_lbu, inst_lw, inst_lh, inst_lb
  };
  
  wire [`SAVE_BUS] id_save_info = {
    inst_sw, inst_sh, inst_sb
  };
  
  assign rs1_r_ena  = ~rst & (inst_i_load | inst_i_fence | inst_i_arith_dword 
                            | inst_s | inst_r_dword 
                            | inst_b | inst_i_jalr | inst_i_csr_reg
                            | inst_putch);
  assign rs2_r_ena  = ~rst & (inst_r_dword | inst_s | inst_b);
  assign csr_rd_ena = csr_vld;
  
  wire [4 : 0] reg_wr_addr = (reg_wr_ena == 1'b1) ? rd_addr : 0;
  
  wire mem_wr_ena = ~rst & inst_s;
  wire mem_rd_ena = ~rst & inst_i_load;
  
  wire [`REG_BUS] id_op1 = {32{~rst}} & (
                  ({32{inst_u_auipc}}       & id_pc)
                | ({32{inst_u_lui}}         & 32'b0)
                | ({32{inst_i_jalr}}        & id_pc)
                | ({32{inst_jal}}           & id_pc)
                | ({32{inst_i_csr_imm}}     & {27'b0, zimm})
               );
  wire id_use_rs1 = inst_i_load | inst_i_fence | inst_i_arith_dword
                  | inst_s | inst_r_dword
                  | inst_b | inst_i_csr_reg;
  
  wire [`REG_BUS] id_op2 = {32{~rst}} & (
                  ({32{inst_i_load}}        & {{20{immI[11]}}, immI})
                | ({32{inst_i_fence}}       & {{20{immI[11]}}, immI})
                | ({32{inst_i_arith_dword}} & {{20{immI[11]}}, immI})
                | ({32{inst_u_auipc}}       & {immU, 12'b0})
                | ({32{inst_s}}             & {{20{immS[11]}}, immS})
                | ({32{inst_u_lui}}         & {immU, 12'b0})
                | ({32{inst_i_jalr}}        & 32'h4)
                | ({32{inst_jal}}           & 32'h4)
                | ({32{inst_i_csr_imm}}     & csr_data)
                | ({32{inst_i_csr_reg}}     & csr_data)
               );
  wire id_use_rs2 = inst_r_dword | inst_b;
  wire id_use_csr = inst_i_csr_imm | inst_i_csr_reg;
  
  wire [`REG_BUS] id_jmp_imm = ({32{inst_b}}      & {{19{immB[12]}}, immB})
                 | ({32{inst_j}}       & {{11{immJ[20]}}, immJ})
                 | ({32{inst_i_jalr}}  & {{20{immI[11]}}, immI});
  
  // data to wb_stage
  wire csr_to_reg = ~rst & (inst_i_csr_imm | inst_i_csr_reg);
  wire mem_to_reg = ~rst & inst_i_load;
  wire exe_to_reg = ~rst & (
      inst_i_fence | inst_i_arith_dword | inst_u_auipc 
    | inst_r_dword | inst_u_lui
    | inst_jal | inst_i_jalr
  );
  wire [`REG_CTRL_BUS] reg_wr_ctrl = {
    csr_to_reg,
    mem_to_reg,
    exe_to_reg
  };
  
  wire reg_wr_ena  = ~rst & (
      inst_i_load | inst_i_fence | inst_i_arith_dword
    | inst_u_auipc | inst_r_dword
    | inst_u_lui | inst_i_jalr | inst_j
    | inst_i_csr_imm | inst_i_csr_reg
  );
  
  wire csr_wr_ena  = ~rst & (inst_i_csr_imm | inst_i_csr_reg);
  wire [11: 0] csr_wr_addr = id_inst[31 : 20];
  
  wire [`EXCP_BUS] id_excp_bus;
  wire id_excp_exit = inst_mret;
  assign id_excp_bus[`EXCP_BRK_PT]  = inst_ebreak;
  assign id_excp_bus[`EXCP_ECALL_M] = inst_ecall;
  
  wire id_uart_out_valid = inst_putch;
 
  assign id_to_ex_pc = id_pc;
  assign id_to_ex_inst = id_inst;
  assign id_to_ex_bus = {
    // exception
    id_excp_exit,      // 208:208
    id_excp_bus,       // 207:192

    // -> ex
    rs1_addr,          // 191:187
    rs2_addr,          // 186:182
    id_op1,            // 181:150
    id_op2,            // 149:118
    id_use_rs1,        // 117:117
    id_use_rs2,        // 116:116
    id_alu_info,       // 115:104
    id_bj_info,        // 103:95
    id_jmp_imm,        // 94 :63
    
    // -> mem
    id_load_info,      // 62 :58
    id_save_info,      // 57 :55
    mem_rd_ena,        // 54 :54
    mem_wr_ena,        // 53 :53
    
    // -> wb
    reg_wr_ctrl,       // 52: 50
    reg_wr_ena,        // 49: 49
    reg_wr_addr,       // 48 :45
    csr_wr_ena,        // 44 :44
    csr_wr_addr,       // 43 :32
    csr_data           // 31 :0
  };
  
  wire id_skip_instr = inst_putch || (csr_vld && (csr_rd_addr == 12'hB00 || csr_rd_addr == 12'h344));
  assign id_to_ex_diffbus = (
    id_skip_instr
  );
endmodule
