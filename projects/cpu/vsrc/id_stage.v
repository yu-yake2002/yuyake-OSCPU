
/* verilator lint_off UNDRIVEN */
/* verilator lint_off UNUSED */
//--Sun Jiru, Nanjing University--

`include "defines.v"

module id_stage(
  input wire rst,
  input wire clk,
  
  // pipeline control
  input wire ex_allowin,
  output wire id_allowin,
  input wire if_id_valid,
  output wire id_ex_valid,

  // data from if_stage
  input wire [`REG_BUS] pc_in,
  input wire [31  :  0] inst_in,
  output reg [`REG_BUS] pc_out,
  output reg [31  :  0] inst_out,

  // data from reg and csr
  input wire [`REG_BUS] r_data1,
  input wire [`REG_BUS] r_data2,
  input wire [`REG_BUS] csr_data,
  
  // read reg & csr
  output wire rs1_ena,
  output wire [4 : 0] rs1_addr,
  output wire rs2_ena,
  output wire [4 : 0] rs2_addr,
  output wire csr_rd_ena,
  output wire [11 : 0] csr_rd_addr,

  // to ex_stage
  output reg [4 : 0] rs1_addr_out,
  output reg [4 : 0] rs2_addr_out,
  output reg [`REG_BUS] ex_op1,
  output reg [`REG_BUS] ex_op2,
  output reg is_word_opt,
  // output reg [`OP_BUS]  op_info, // useless
  output reg [`ALU_BUS]  alu_info,
  output reg [`BJ_BUS]   bj_info,

  // to mem_stage
  output reg [`REG_BUS] rs2_data,
  output reg [`LOAD_BUS] load_info,
  output reg [`SAVE_BUS] save_info,
  output reg mem_rd_ena,
  output reg mem_wr_ena,

  // to wb_stage
  output reg [`REG_CTRL_BUS] reg_wr_ctrl,
  output reg csr_wr_ena,
  output reg [11 : 0] csr_wr_addr,
  output reg rd_ena,
  output reg [4 : 0] rd_addr,
  
  // to if_stage
  output reg [`REG_BUS] jmp_imm,

  // to excp_handler
  output wire [`EXCP_BUS] id_excp,
  output wire excp_exit
  );


  // pipeline control
  reg id_valid;
  wire id_ready_go = 1'b1;
  assign id_allowin = !id_valid || id_ready_go && ex_allowin;
  assign id_ex_valid = id_valid && id_ready_go;
  
  always @(posedge clk) begin
    if (rst) begin
      id_valid <= 1'b0;
    end
    else if (id_allowin) begin
      id_valid <= if_id_valid;
    end
  end
  
  // decode
  wire [6  : 0] opcode = inst_in[6 : 0];
  wire [2  : 0] func3 = inst_in[14 : 12];
  wire [5  : 0] func6 = inst_in[31 : 26];
  wire [6  : 0] func7 = inst_in[31 : 25];
  
  wire [4  : 0] rd = inst_in[11 :  7];
  wire [4  : 0] rs1 = inst_in[19 : 15];
  wire [4  : 0] rs2 = inst_in[24 : 20];
  
  wire [11 : 0] immI = inst_in[31 : 20];
  wire [4  : 0] zimm = rs1;
  wire [11 : 0] immS = {inst_in[31 : 25], inst_in[11 : 7]};
  wire [12 : 0] immB = {inst_in[31], inst_in[7], inst_in[30 : 25], inst_in[11 : 8], 1'b0};
  wire [19 : 0] immU = inst_in[31 : 12];
  wire [20 : 0] immJ = {inst_in[31], inst_in[19 : 12], inst_in[20], inst_in[30 : 21], 1'b0};
  
  
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
  wire imm12_102 = (immI == 12'h102);
  
  // decode type
  wire inst_i_load        = (opcode == 7'h03);
  wire inst_i_fence       = (opcode == 7'h0f);
  wire inst_i_arith_dword = (opcode == 7'h13);
  wire inst_u_auipc       = (opcode == 7'h17);
  wire inst_i_arith_word  = (opcode == 7'h1b);
  wire inst_s             = (opcode == 7'h23);
  wire inst_r_dword       = (opcode == 7'h33);
  wire inst_u_lui         = (opcode == 7'h37);
  wire inst_r_word        = (opcode == 7'h3b);
  wire inst_b             = (opcode == 7'h63);
  wire inst_i_jalr        = (opcode == 7'h67);
  wire inst_j             = (opcode == 7'h6f);
  wire inst_i_sys         = (opcode == 7'h73);
  wire inst_i_excp        = inst_i_sys & func3_0;
  wire inst_i_csr_imm     = inst_i_sys & (func3[2] == 1) & ~func3_0;
  wire inst_i_csr_reg     = inst_i_sys & (func3[2] == 0) & ~func3_0;
  //wire inst_t             = (opcode == 7'h6b); // signal of termination
  wire inst_putch         = (opcode == 7'h7b); //signal of putch
  /*
  assign op_info = {inst_putch, inst_i_csr_reg, inst_i_csr_imm, inst_i_excp, inst_j, 
                    inst_i_jalr, inst_b, inst_r_word, inst_u_lui, inst_r_dword, inst_s, 
                    inst_i_arith_word, inst_u_auipc, inst_i_arith_dword, inst_i_fence, 
                    inst_i_load};
  */

  // load
  wire inst_lb      = inst_i_load & func3_0;
  wire inst_lh      = inst_i_load & func3_1;
  wire inst_lw      = inst_i_load & func3_2;
  wire inst_ld      = inst_i_load & func3_3;
  wire inst_lbu     = inst_i_load & func3_4;
  wire inst_lhu     = inst_i_load & func3_5;
  wire inst_lwu     = inst_i_load & func3_6;
  wire load_vld     = inst_lb | inst_lh | inst_lw | inst_ld 
                    | inst_lbu | inst_lhu | inst_lwu;

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
  
  // arith-i-word
  wire inst_addiw   = inst_i_arith_word & func3_0;
  wire inst_slliw   = inst_i_arith_word & func3_1;
  wire inst_srliw   = inst_i_arith_word & func3_5 & func6_00;
  wire inst_sraiw   = inst_i_arith_word & func3_5 & func6_10;
  wire arith_iw_vld = inst_addiw | inst_slliw | inst_srliw | inst_sraiw;
  
  // store
  wire inst_sb      = inst_s & func3_0;
  wire inst_sh      = inst_s & func3_1;
  wire inst_sw      = inst_s & func3_2;
  wire inst_sd      = inst_s & func3_3;
  wire store_vld    = inst_sb | inst_sh | inst_sw | inst_sd;
  
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
  
  // arith-r-word
  wire inst_addw    = inst_r_word & func3_0 & func7_00;
  wire inst_subw    = inst_r_word & func3_0 & func7_20;
  wire inst_sllw    = inst_r_word & func3_1;
  wire inst_srlw    = inst_r_word & func3_5 & func7_00;
  wire inst_sraw    = inst_r_word & func3_5 & func7_20;
  wire arith_rw_vld = inst_addw | inst_subw | inst_sllw 
                    | inst_srlw | inst_sraw;
  
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
  wire inst_mret    = inst_i_excp    & imm12_102;
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

  wire inst_vld     = load_vld | fence_vld | arith_id_vld | auipc_vld
                    | arith_iw_vld | store_vld | arith_rd_vld | lui_vld
                    | arith_rw_vld | branch_vld | jump_vld | excp_vld
                    | csr_vld;
  
  // get operands from registers
  assign rs1_ena  = ~rst & (inst_i_load | inst_i_fence | inst_i_arith_dword 
                          | inst_i_arith_word | inst_s | inst_r_dword 
                          | inst_r_word | inst_b | inst_i_jalr | inst_i_csr_reg
                          | inst_putch);
  assign rs1_addr = rs1_ena ? rs1 : 0;
  assign rs2_ena  = ~rst & (inst_r_dword | inst_r_word | inst_s | inst_b);
  assign rs2_addr = rs2_ena ? rs2 : 0;
  // get operands from CSRs
  assign csr_rd_ena = ~rst & (inst_i_csr_imm | inst_i_csr_reg);
  assign csr_rd_addr = immI;

  wire csr_to_reg = ~rst & (inst_i_csr_imm | inst_i_csr_reg);
  wire mem_to_reg = ~rst & inst_i_load;
  wire exe_to_reg = ~rst & (
      inst_i_fence | inst_i_arith_dword | inst_u_auipc 
    | inst_i_arith_word | inst_r_dword | inst_u_lui
    | inst_r_word | inst_i_jalr | inst_j
  );
  
  assign rd_addr = rd_ena ? rd : 0;

  always @(posedge clk) begin
    if (if_id_valid && id_allowin) begin
      // id_stage -> exe_stage
      pc_out   <= pc_in;
      inst_out <= inst_in;
      
      rs1_addr_out <= rs1_addr;
      rs2_addr_out <= rs2_addr;

      is_word_opt <= inst_r_word | inst_i_arith_word;

      alu_info[`ALU_ADD]  <= inst_add   | inst_addi   | inst_addw  | inst_addiw 
                          | inst_auipc | inst_lui    | inst_i_load | inst_s 
                          | inst_jal   | inst_jalr;
      alu_info[`ALU_SUB]  <= inst_sub   | inst_subw   | inst_b;
      alu_info[`ALU_SLT]  <= inst_slt   | inst_slti   | inst_blt   | inst_bge;
      alu_info[`ALU_SLTU] <= inst_sltu  | inst_sltiu  | inst_bltu  | inst_bgeu;
      alu_info[`ALU_XOR]  <= inst_xor   | inst_xori   | inst_beq   | inst_bne;
      alu_info[`ALU_OR]   <= inst_or    | inst_ori    | inst_csrrs | inst_csrrsi;
      alu_info[`ALU_AND]  <= inst_and   | inst_andi;
      alu_info[`ALU_SLL]  <= inst_sll   | inst_slli   | inst_sllw  | inst_slliw;
      alu_info[`ALU_SRL]  <= inst_srl   | inst_srli   | inst_srlw  | inst_srliw;
      alu_info[`ALU_SRA]  <= inst_sra   | inst_srai   | inst_sraw  | inst_sraiw;
      alu_info[`ALU_ANDN] <= inst_csrrc | inst_csrrci;
      alu_info[`ALU_WRI]  <= inst_csrrw | inst_csrrwi;
      
      bj_info[`BJ_BEQ]  <= inst_beq;
      bj_info[`BJ_BNE]  <= inst_bne;
      bj_info[`BJ_BLT]  <= inst_blt;
      bj_info[`BJ_BGE]  <= inst_bge;
      bj_info[`BJ_BLTU] <= inst_bltu;
      bj_info[`BJ_BGEU] <= inst_bgeu;
      bj_info[`BJ_JALR] <= inst_jalr;
      bj_info[`BJ_JAL]  <= inst_jal;
      
      ex_op1 <= {64{~rst}} & (
          ({64{inst_i_load}}        & r_data1)
        | ({64{inst_i_fence}}       & r_data1)
        | ({64{inst_i_arith_dword}} & r_data1)
        | ({64{inst_u_auipc}}       & pc_in)
        | ({64{inst_i_arith_word}}  & r_data1 & 64'hffffffff)
        | ({64{inst_s}}             & r_data1)
        | ({64{inst_r_dword}}       & r_data1)
        | ({64{inst_u_lui}}         & 64'b0)
        | ({64{inst_r_word}}        & r_data1 & 64'hffffffff)
        | ({64{inst_b}}             & r_data1)
        | ({64{inst_i_jalr}}        & pc_in)
        | ({64{inst_j}}             & pc_in)
        | ({64{inst_i_csr_imm}}     & csr_data)
        | ({64{inst_i_csr_reg}}     & csr_data)
      );

      ex_op2 <= {64{~rst}} & (
          ({64{inst_i_load}}        & {{52{immI[11]}}, immI})
        | ({64{inst_i_fence}}       & {{52{immI[11]}}, immI})
        | ({64{inst_i_arith_dword}} & {{52{immI[11]}}, immI})
        | ({64{inst_u_auipc}}       & {{32{immU[19]}}, immU, 12'b0})
        | ({64{inst_i_arith_word}}  & {{52{immI[11]}}, immI})
        | ({64{inst_s}}             & {{52{immS[11]}}, immS})
        | ({64{inst_r_dword}}       & r_data2)
        | ({64{inst_u_lui}}         & {{32{immU[19]}}, immU, 12'b0})
        | ({64{inst_r_word}}        & r_data2 & 64'hffffffff)
        | ({64{inst_b}}             & r_data2)
        | ({64{inst_i_jalr}}        & 64'h4)
        | ({64{inst_j}}             & 64'h4)
        | ({64{inst_i_csr_imm}}     & {59'b0, zimm})
        | ({64{inst_i_csr_reg}}     & r_data1)
      );
      
      jmp_imm <= ({64{inst_b}}      & {{51{immB[12]}}, immB})
                | ({64{inst_j}}       & {{43{immJ[20]}}, immJ})
                | ({64{inst_i_jalr}}  & {{52{immI[11]}}, immI});

      // id -> mem_stage
      mem_rd_ena <= ~rst & inst_i_load;
      mem_wr_ena <= ~rst & inst_s;

      load_info[`LOAD_LB]  <= inst_lb;
      load_info[`LOAD_LH]  <= inst_lh;
      load_info[`LOAD_LW]  <= inst_lw;
      load_info[`LOAD_LD]  <= inst_ld;
      load_info[`LOAD_LBU] <= inst_lbu;
      load_info[`LOAD_LHU] <= inst_lhu;
      load_info[`LOAD_LWU] <= inst_lwu;
      
      save_info[`SAVE_SB] <= inst_sb;
      save_info[`SAVE_SH] <= inst_sh;
      save_info[`SAVE_SW] <= inst_sw;
      save_info[`SAVE_SD] <= inst_sd;
      
      // id -> wb_stage
      reg_wr_ctrl <= {csr_to_reg, mem_to_reg, exe_to_reg};
      rd_ena    <= ~rst & (inst_i_load | inst_i_fence | inst_i_arith_dword
                            | inst_u_auipc | inst_i_arith_word | inst_r_dword
                            | inst_u_lui | inst_r_word | inst_i_jalr | inst_j
                            | inst_i_csr_imm | inst_i_csr_reg);
      
      csr_wr_addr <= immI;
      csr_wr_ena  <= ~rst & (inst_i_csr_imm | inst_i_csr_reg);
    end
  end
  /*
  //assign id_excp[`EXCP_ILG_INST] = ~inst_vld & ~rst; // it may cause error
  assign id_excp[`EXCP_BRK_PT]   = inst_ebreak;
  assign id_excp[`EXCP_ECALL_M]  = inst_ecall;
  assign excp_exit = inst_mret;
  */
endmodule
