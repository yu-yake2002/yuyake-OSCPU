`include "defines.v"

module mem_stage(
  input wire clk,
  input wire rst,

  // pipeline control
  input wire wb_allowin,
  output wire mem_allowin,
  input wire ex_mem_valid,
  output wire mem_wb_valid,
  
  input wire [`REG_BUS] pc_in,
  input wire [31  :  0] inst_in,
  output reg [`REG_BUS] pc_out,
  output reg [31  :  0] inst_out,
  
  input wire [`REG_BUS] reg_src,
  input wire [`LOAD_BUS] load_info,
  input wire [`SAVE_BUS] save_info,
  input wire mem_rd_ena,
  input wire mem_wr_ena,
  input wire [`REG_BUS] mem_addr,
  
  // mem_stage -> memhelper
  output wire [7 : 0] byte_enable,
  
  output wire [`REG_BUS] memhpr_wr_data,
  output wire [`REG_BUS] memhpr_rd_data,
  
  // mem_stage -> wb_stage
  output reg [`REG_BUS] mem_data,

  // pass to wb_stage
  input wire [`REG_CTRL_BUS] reg_wr_ctrl_in,
  input wire csr_wr_ena_in,
  input wire [11 : 0] csr_wr_addr_in,
  input wire rd_w_ena_in,
  input wire [4 : 0] rd_w_addr_in,
  input wire [`REG_BUS] ex_data_in,
  output reg [`REG_CTRL_BUS] reg_wr_ctrl_out,
  output reg csr_wr_ena_out,
  output reg [11 : 0] csr_wr_addr_out,
  output reg rd_w_ena_out,
  output reg [4 : 0] rd_w_addr_out,
  output reg [`REG_BUS] ex_data_out,

  // mem_stage -> exception handler
  output wire [`EXCP_BUS] mem_excp
  );

  // pipeline control
  reg mem_valid;
  wire mem_ready_go = 1'b1;
  assign mem_allowin = !mem_valid || mem_ready_go && wb_allowin;
  assign mem_wb_valid = mem_valid && mem_ready_go;
  always @(posedge clk) begin
    if (rst) begin
      mem_valid <= 1'b0;
    end
    else if (mem_allowin) begin
      mem_valid <= ex_mem_valid;
    end
  end

  always @(posedge clk) begin
    if (ex_mem_valid && mem_allowin) begin
      pc_out   <= pc_in;
      inst_out <= inst_in;
      mem_data <= {64{~rst}} & (
          ({64{op_lb}} & {{56{mem_part[7 ]}}, mem_part[7  : 0]})
        | ({64{op_lh}} & {{48{mem_part[15]}}, mem_part[15 : 0]})
        | ({64{op_lw}} & {{32{mem_part[31]}}, mem_part[31 : 0]})
        | ({64{op_ld}} & mem_part)
        | ({64{op_lbu}} & {56'b0, mem_part[7  : 0]})
        | ({64{op_lhu}} & {48'b0, mem_part[15 : 0]})
        | ({64{op_lwu}} & {32'b0, mem_part[31 : 0]})
      );

      reg_wr_ctrl_out <= reg_wr_ctrl_in;
      csr_wr_ena_out <= csr_wr_ena_in;
      csr_wr_addr_out <= csr_wr_addr_in;
      rd_w_ena_out <= rd_w_ena_in;
      rd_w_addr_out <= rd_w_addr_in;
    end
  end

  wire addr_0 = (mem_addr[2 : 0] == 3'h0);
  wire addr_1 = (mem_addr[2 : 0] == 3'h1);
  wire addr_2 = (mem_addr[2 : 0] == 3'h2);
  wire addr_3 = (mem_addr[2 : 0] == 3'h3);
  wire addr_4 = (mem_addr[2 : 0] == 3'h4);
  wire addr_5 = (mem_addr[2 : 0] == 3'h5);
  wire addr_6 = (mem_addr[2 : 0] == 3'h6);
  wire addr_7 = (mem_addr[2 : 0] == 3'h7);

  // load
  wire op_lb  = load_info[`LOAD_LB];
  wire op_lh  = load_info[`LOAD_LH];
  wire op_lw  = load_info[`LOAD_LW];
  wire op_ld  = load_info[`LOAD_LD];
  wire op_lbu = load_info[`LOAD_LBU];
  wire op_lhu = load_info[`LOAD_LHU];
  wire op_lwu = load_info[`LOAD_LWU];
  
  wire [`REG_BUS] mem_part = memhpr_rd_data >> ({mem_addr[2 : 0], 3'b0});  

  // save
  wire op_sb = save_info[`SAVE_SB];
  wire op_sh = save_info[`SAVE_SH];
  wire op_sw = save_info[`SAVE_SW];
  wire op_sd = save_info[`SAVE_SD];

  assign byte_enable[0] = (op_sb & addr_0) | (op_sh & addr_0) | (op_sw & addr_0) | (op_sd & addr_0);
  assign byte_enable[1] = (op_sb & addr_1) | (op_sh & addr_0) | (op_sw & addr_0) | (op_sd & addr_0);
  assign byte_enable[2] = (op_sb & addr_2) | (op_sh & addr_2) | (op_sw & addr_0) | (op_sd & addr_0);
  assign byte_enable[3] = (op_sb & addr_3) | (op_sh & addr_2) | (op_sw & addr_0) | (op_sd & addr_0);
  assign byte_enable[4] = (op_sb & addr_4) | (op_sh & addr_4) | (op_sw & addr_4) | (op_sd & addr_0);
  assign byte_enable[5] = (op_sb & addr_5) | (op_sh & addr_4) | (op_sw & addr_4) | (op_sd & addr_0);
  assign byte_enable[6] = (op_sb & addr_6) | (op_sh & addr_6) | (op_sw & addr_4) | (op_sd & addr_0);
  assign byte_enable[7] = (op_sb & addr_7) | (op_sh & addr_6) | (op_sw & addr_4) | (op_sd & addr_0);
  
  assign memhpr_wr_data = reg_src << ({mem_addr[2 : 0], 3'b0});

endmodule