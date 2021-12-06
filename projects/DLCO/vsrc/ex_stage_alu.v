
//--Sun Jiru, Nanjing University--

`include "defines.v"

module ex_stage_alu(
  input wire rst,
  input wire [`REG_BUS] op1,
  input wire [`REG_BUS] op2,
  input wire [`ALU_BUS] alu_info,

  output wire [`REG_BUS] alu_output,
  output wire [`BJ_BUS] bj_data
  );
  
  wire op_add  = alu_info[`ALU_ADD];
  wire op_sub  = alu_info[`ALU_SUB];
  wire op_slt  = alu_info[`ALU_SLT];
  wire op_sltu = alu_info[`ALU_SLTU];
  wire op_xor  = alu_info[`ALU_XOR];
  wire op_or   = alu_info[`ALU_OR];
  wire op_and  = alu_info[`ALU_AND];
  wire op_sll  = alu_info[`ALU_SLL];
  wire op_srl  = alu_info[`ALU_SRL];
  wire op_sra  = alu_info[`ALU_SRA];
  wire op_andn = alu_info[`ALU_ANDN];
  wire op_wri  = alu_info[`ALU_WRI];

  // left-shifter and right-shifter
  wire op_shift = op_sll | op_srl | op_sra;
  wire [`REG_BUS] shifter_op1 = op1;
  wire [`REG_BUS] shifter_in1 = {32{op_shift}} &
          //   In order to save area and just use one left-shifter, we
          //   convert the right-shift op into left-shift operation
          (
               (op_srl || op_sra) ? 
                 {
    op1[00], op1[01], op1[02], op1[03],
    op1[04], op1[05], op1[06], op1[07],
    op1[08], op1[09], op1[10], op1[11],
    op1[12], op1[13], op1[14], op1[15],
    op1[16], op1[17], op1[18], op1[19],
    op1[20], op1[21], op1[22], op1[23],
    op1[24], op1[25], op1[26], op1[27],
    op1[28], op1[29], op1[30], op1[31]
                 } : shifter_op1
          );
  wire [4 : 0] shifter_in2 = {5{op_shift}} & op2[4 : 0];

  wire [`REG_BUS] shifter_res = (shifter_in1 << shifter_in2);

  wire [`REG_BUS] sll_res = shifter_res;
  wire [`REG_BUS] srl_res =  
                 {
    shifter_res[00],shifter_res[01],shifter_res[02],shifter_res[03],
    shifter_res[04],shifter_res[05],shifter_res[06],shifter_res[07],
    shifter_res[08],shifter_res[09],shifter_res[10],shifter_res[11],
    shifter_res[12],shifter_res[13],shifter_res[14],shifter_res[15],
    shifter_res[16],shifter_res[17],shifter_res[18],shifter_res[19],
    shifter_res[20],shifter_res[21],shifter_res[22],shifter_res[23],
    shifter_res[24],shifter_res[25],shifter_res[26],shifter_res[27],
    shifter_res[28],shifter_res[29],shifter_res[30],shifter_res[31]
                 };
  wire [`REG_BUS] eff_mask = (~(32'b0)) >> shifter_in2;
  wire [`REG_BUS] sra_res =
               (srl_res & eff_mask) | ({32{shifter_op1[31]}} & (~eff_mask));

  // add & sub operation
  wire temp_add = op_add;
  wire temp_sub = op_sub | op_slt | op_sltu;
  wire op_addsub = temp_add | temp_sub;
  wire op_unsigned = op_sltu;
  wire [32 : 0] adder_op1 = {~op_unsigned & op1[31], op1};
  wire [32 : 0] adder_op2 = {~op_unsigned & op2[31], op2};
  wire [32 : 0] adder_in1 = {33{op_addsub}} & adder_op1;
  wire [32 : 0] adder_in2 = {33{op_addsub}} & (temp_sub ? (~adder_op2) : (adder_op2));
  wire [32 : 0] adder_cin = temp_sub ? 33'b1 : 33'b0;
  wire [32 : 0] add_res   = adder_in1 + adder_in2 + adder_cin;
  wire [`REG_BUS] slt_res   = {{31{1'b0}}, (op_slt | op_sltu) & add_res[32]};
  wire [`REG_BUS] sltu_res  = slt_res;

  // logic operation
  wire [`REG_BUS] xor_res = op1 ^ op2;
  wire [`REG_BUS] or_res  = op1 | op2;
  wire [`REG_BUS] and_res = op1 & op2;
  wire [`REG_BUS] andn_res = ~op1 & op2;
  wire [`REG_BUS] wri_res = op1;

  wire [`REG_BUS] temp_output = {32{~rst}} & ( 
                      ({32{op_sll}}    & sll_res)
                    | ({32{op_srl}}    & srl_res)
                    | ({32{op_sra}}    & sra_res)
                    | ({32{op_slt}}    & slt_res)
                    | ({32{op_sltu}}   & sltu_res)
                    | ({32{op_add | op_sub}} & add_res[31 : 0])
                    | ({32{op_xor}}    & xor_res)
                    | ({32{op_or}}     & or_res)
                    | ({32{op_and}}    & and_res)
                    | ({32{op_andn}}   & andn_res)
                    | ({32{op_wri}}    & wri_res)
                      );
  assign alu_output = temp_output;
  
  wire eq_res = ~(|xor_res);
  assign bj_data[`BJ_BEQ]  = eq_res;
  assign bj_data[`BJ_BNE]  = ~eq_res;
  assign bj_data[`BJ_BLT]  = slt_res[0];
  assign bj_data[`BJ_BGE]  = ~slt_res[0];
  assign bj_data[`BJ_BLTU] = sltu_res[0];
  assign bj_data[`BJ_BGEU] = ~sltu_res[0];
  assign bj_data[`BJ_JALR] = 1'b1;
  assign bj_data[`BJ_JAL]  = 1'b1;
  assign bj_data[`BJ_HALT] = 1'b1;
endmodule