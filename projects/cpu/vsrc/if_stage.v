
/* verilator lint_off UNUSED */
//--Sun Jiru, Nanjing University--

`include "defines.v"

module if_stage(
  input wire clk,
  input wire rst,
  
  input wire pc_now,
  input wire bj_ena,
  input wire [`REG_BUS] bj_pc,
  input wire excp_jmp_ena,
  input wire [`REG_BUS] excp_pc,

  output wire [`REG_BUS] pc
  );

  // fetch an instruction
  assign pc = excp_jmp_ena ? excp_pc :
              bj_ena       ? bj_pc  :
              (pc_now + 4) ;

endmodule
