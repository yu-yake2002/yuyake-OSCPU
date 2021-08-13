//--Sun Jiru, Nanjing University

`include "defines.v"

module hazard (
  input wire ex_ram_rd_ena,
  input wire [4 : 0] ex_reg_wr_addr,
  input wire [4 : 0] rs1_addr,
  input wire [4 : 0] rs2_addr,

  output wire id_stall
);
  assign id_stall = ex_ram_rd_ena && (
       (ex_reg_wr_addr == rs1_addr && rs1_addr != 5'b0) 
    || (ex_reg_wr_addr == rs2_addr && rs2_addr != 5'b0)
  );
endmodule