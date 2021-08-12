//--Sun Jiru, Nanjing University

`include "defines.v"

module hazard (
  input wire id_ex_mem_rd_ena,
  input wire [4 : 0] id_ex_rd_addr,
  input wire [4 : 0] rs1_addr,
  input wire [4 : 0] rs2_addr,

  output wire id_stall
);
  assign id_stall = id_ex_mem_rd_ena && (
       (id_ex_rd_addr == rs1_addr && rs1_addr != 5'b0) 
    || (id_ex_rd_addr == rs2_addr && rs2_addr != 5'b0)
  );
endmodule