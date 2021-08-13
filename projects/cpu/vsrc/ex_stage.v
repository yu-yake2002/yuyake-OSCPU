
//--Sun Jiru, Nanjing University--

`include "defines.v"

module ex_stage(
  input wire rst,

  input wire ex_valid,
  input wire [`REG_BUS] ex_op1,
  input wire [`REG_BUS] ex_op2,
  input wire is_word_opt,
  input wire [`ALU_BUS] alu_info,
  input wire [`BJ_BUS] bj_info,
  input wire [`REG_BUS] jmp_imm,
  input wire [`REG_BUS] now_pc,

  output wire [`REG_BUS] rd_data,
  output wire [`REG_BUS] bj_pc,
  output wire bj_ena
  );
  
  // alu -> bj
  wire [`BJ_BUS] bj_data;
  
  ex_stage_alu Exe_stage_alu(
    .rst(rst),
    .op1(ex_op1),
    .op2(ex_op2),
    .alu_info(alu_info),
    .is_word_opt(is_word_opt),
    
    .alu_output(rd_data),
    .bj_data(bj_data)
  );
  
  ex_stage_bj Exe_stage_bj(
    .rst(rst),
    .ex_valid(ex_valid),
    .bj_info(bj_info),
    .bj_data(bj_data),
    .jmp_imm(jmp_imm),
    .exe_op1(ex_op1),
    .now_pc(now_pc),
    
    .bj_ena(bj_ena),
    .new_pc(bj_pc)
  );

endmodule
