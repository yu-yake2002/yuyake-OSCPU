`include "defines.v"

module mem_stage(
  input  wire             clk,
  input  wire             rst,
  input  wire             refresh, // the first beat of mem_stage
  
  input  wire [`REG_BUS]  ram_wr_src,
  input  wire [`LOAD_BUS] load_info,
  input  wire [`SAVE_BUS] save_info,
  input  wire [`REG_BUS]  mem_addr,
  input  wire             ram_rd_ena,
  input  wire             ram_wr_ena,
  
  output reg [`REG_BUS]   mem_data,
  output [`EXCP_BUS]      mem_excp,
  
  output wire             mem_rw_valid,
  input  wire             mem_rw_ready,
  output wire             mem_rw_req,
  input  wire [`REG_BUS]  mem_r_data,
  output wire [`REG_BUS]  mem_w_data,
  output wire [`REG_BUS]  mem_rw_addr,
  output wire [1 : 0]     mem_rw_size,
  input  wire [1 : 0]     mem_rw_resp,
  
  output wire             mem_finish
  );

  wire mem_handshake = mem_rw_valid && mem_rw_ready;

  wire op_sb = save_info[`SAVE_SB];
  wire op_sh = save_info[`SAVE_SH];
  wire op_sw = save_info[`SAVE_SW];
  wire op_sd = save_info[`SAVE_SD];

  wire op_lb  = load_info[`LOAD_LB];
  wire op_lh  = load_info[`LOAD_LH];
  wire op_lw  = load_info[`LOAD_LW];
  wire op_ld  = load_info[`LOAD_LD];
  wire op_lbu = load_info[`LOAD_LBU];
  wire op_lhu = load_info[`LOAD_LHU];
  wire op_lwu = load_info[`LOAD_LWU];
  
  parameter IDLE = 2'b00, ADDR = 2'b01, RETN = 2'b10;
  reg mem_state;
  reg mem_next_state;
  
  always @(posedge clk) begin
    if (rst) begin
      mem_state <= IDLE;
    end
    else begin
      mem_state <= mem_next_state;
    end
  end

  always @(*) begin
    case (mem_state)
      IDLE:
        if (refresh && (ram_rd_ena || ram_wr_ena)) begin
          mem_next_state = ADDR;
        end
      ADDR:
        if (mem_handshake) begin
          mem_next_state = RETN;
        end
      RETN:
        if (refresh) begin
          if (ram_rd_ena || ram_wr_ena) begin
            mem_next_state = ADDR;
          end
          else begin
            mem_next_state = IDLE;
          end
        end
      default:
        mem_next_state = IDLE;
    endcase
  end

  assign mem_rw_valid = mem_state == ADDR;
  assign mem_rw_req = ram_wr_ena;
  assign mem_w_data = ram_wr_src & (
      ({64{op_sb}} & 64'hff)
    | ({64{op_sh}} & 64'hffff)
    | ({64{op_sw}} & 64'hffffffff)
    | ({64{op_sd}} & 64'hffffffffffffffff)
  );
  assign mem_rw_addr = mem_addr;
  assign mem_rw_size = (
      ({2{op_sb || op_lb || op_lbu}} & `SIZE_B)
    | ({2{op_sh || op_lh || op_lhu}} & `SIZE_H)
    | ({2{op_sw || op_lw || op_lwu}} & `SIZE_W)
    | ({2{op_sd || op_ld          }} & `SIZE_D)
  );

  always @(posedge clk) begin
    if (mem_handshake) begin
      mem_data <= (
          ({64{op_lb}} & {{56{mem_r_data[7 ]}}, mem_r_data[7  : 0]})
        | ({64{op_lh}} & {{48{mem_r_data[15]}}, mem_r_data[15 : 0]})
        | ({64{op_lw}} & {{32{mem_r_data[31]}}, mem_r_data[31 : 0]})
        | ({64{op_ld}} & mem_r_data)
        | ({64{op_lbu}} & {56'b0, mem_r_data[7  : 0]})
        | ({64{op_lhu}} & {48'b0, mem_r_data[15 : 0]})
        | ({64{op_lwu}} & {32'b0, mem_r_data[31 : 0]})
      );
    end
  end

  assign mem_finish = mem_state == RETN;
  
endmodule