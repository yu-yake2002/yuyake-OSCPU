
//--Sun Jiru, Nanjing University--

`include "defines.v"

module ex_stage(
  input wire clk,
  input wire rst,
  
  // pipeline control
  input wire mem_allowin,
  output wire ex_allowin,
  input wire id_ex_valid,
  output wire ex_mem_valid,
  
  input wire [`REG_BUS] pc_in,
  input wire [31  :  0] inst_in,
  output reg [`REG_BUS] pc_out,
  output reg [31  :  0] inst_out,
  
  // forward control
  input wire [`REG_BUS] op1_src,
  input wire [`REG_BUS] op2_src,
  
  // ALU control
  input wire is_word_opt,
  input wire [`ALU_BUS] alu_info_in,
  
  // branch & jump control
  input wire [`BJ_BUS] bj_info_in,
  input wire [`REG_BUS] jmp_imm,

  // pass to mem_stage
  input wire [`LOAD_BUS] load_info_in,
  input wire [`SAVE_BUS] save_info_in,
  input wire mem_wr_ena_in,
  input wire mem_rd_ena_in,
  input wire [`REG_BUS] mem_wr_src_in,
  output reg [`LOAD_BUS] load_info_out,
  output reg [`SAVE_BUS] save_info_out,
  output reg mem_wr_ena_out,
  output reg mem_rd_ena_out,
  output reg [`REG_BUS] mem_wr_src_out,
  
  // pass to wb_stage
  input wire [`REG_CTRL_BUS] reg_wr_ctrl_in,
  input wire csr_wr_ena_in,
  input wire [11 : 0] csr_wr_addr_in,
  input wire rd_ena_in,
  input wire [4 : 0] rd_addr_in,
  output reg [`REG_CTRL_BUS] reg_wr_ctrl_out,
  output reg csr_wr_ena_out,
  output reg [11 : 0] csr_wr_addr_out,
  output reg rd_ena_out,
  output reg [4 : 0] rd_addr_out,

  output reg [`REG_BUS] ex_data,
  output wire [`REG_BUS] new_pc,
  output wire bj_ena
  );

  // pipeline control
  reg ex_valid;
  wire ex_ready_go = 1'b1;
  assign ex_allowin = !ex_valid || ex_ready_go && mem_allowin;
  assign ex_mem_valid = ex_valid && ex_ready_go;
  
  always @(posedge clk) begin
    if (rst ) begin
      ex_valid <= 1'b0;
    end
    else if (ex_allowin) begin
      ex_valid <= id_ex_valid;
    end
  end

  wire [`REG_BUS] alu_output;
  wire [`BJ_BUS] bj_data;

  ex_stage_alu Exe_stage_alu(
    .rst(rst),
    .op1(op1_src),
    .op2(op2_src),
    .alu_info(alu_info_in),
    .is_word_opt(is_word_opt),
    
    .alu_output(alu_output),
    .bj_data(bj_data)
  );
  
  ex_stage_bj Exe_stage_bj(
    .rst(rst),
    .ex_valid(ex_valid),
    .bj_info(bj_info_in),
    .bj_data(bj_data),
    .jmp_imm(jmp_imm),
    .exe_op1(op1_src),
    .now_pc(pc_in),
    
    .bj_ena(bj_ena),
    .new_pc(new_pc)
  );
  
  always @(posedge clk) begin
    if (id_ex_valid && ex_allowin) begin
      pc_out   <= pc_in;
      inst_out <= inst_in;
      load_info_out <= load_info_in;
      save_info_out <= save_info_in;
      mem_wr_ena_out <= mem_wr_ena_in;
      mem_rd_ena_out <= mem_rd_ena_in;

      reg_wr_ctrl_out <= reg_wr_ctrl_in;
      csr_wr_ena_out <= csr_wr_ena_in;
      csr_wr_addr_out <= csr_wr_addr_in;
      rd_ena_out <= rd_ena_in;
      rd_addr_out <= rd_addr_in;

      ex_data <= alu_output;
    end
  end
endmodule
