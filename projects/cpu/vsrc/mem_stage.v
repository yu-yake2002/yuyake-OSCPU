`include "defines.v"

module mem_stage(
  input  wire             clk,
  input  wire             rst,
  
  // pipeline control
  input wire ex_to_mem_valid,
  input wire [`EX_TO_MEM_WIDTH-1:0] ex_to_mem_bus,
  output wire mem_allowin,

  output wire mem_to_wb_valid,
  output wire [`MEM_TO_WB_WIDTH-1:0] mem_to_wb_bus,
  input wire wb_allowin,

  output wire [`MEM_FORWARD_WIDTH-1:0] mem_forward_bus,
  
  output wire             mem_rw_valid,
  input  wire             mem_rw_ready,
  output wire             mem_rw_req,
  input  wire [`REG_BUS]  mem_r_data,
  output wire [`REG_BUS]  mem_w_data,
  output wire [`REG_BUS]  mem_rw_addr,
  output wire [1 : 0]     mem_rw_size,
  input  wire [1 : 0]     mem_rw_resp
  );
  
  // pipeline control
  reg mem_valid;
  wire mem_ready_go;
  reg [`EX_TO_MEM_WIDTH-1:0] ex_to_mem_bus_r;
  
  assign mem_ready_go = mem_finish || (~mem_ram_rd_ena && ~mem_ram_wr_ena);
  assign mem_allowin = !mem_valid || mem_ready_go && wb_allowin;
  assign mem_to_wb_valid = mem_valid && mem_ready_go;

  always @(posedge clk) begin
    if (rst) begin
      mem_valid <= 1'b0;
    end
    else if (mem_allowin) begin
      mem_valid <= ex_to_mem_valid;
    end

    if (ex_to_mem_valid && mem_allowin) begin
      ex_to_mem_bus_r <= ex_to_mem_bus;

    end
  end
  
  wire [`REG_BUS]  mem_pc;
  wire [31 : 0]    mem_inst;
  
  wire [`LOAD_BUS] mem_load_info;
  wire [`SAVE_BUS] mem_save_info;
  wire [`REG_BUS]  mem_ram_wr_src;
  wire [`REG_BUS]  mem_addr, mem_csr_data;
  wire             mem_ram_rd_ena;
  wire             mem_ram_wr_ena;

  wire [2  : 0]    mem_reg_wr_ctrl;
  wire [4  : 0]    mem_reg_wr_addr;
  wire             mem_reg_wr_ena, mem_csr_wr_ena;

  assign {
    mem_pc,          // 310:247
    mem_inst,        // 246:215

    // mem
    mem_load_info,   // 214:208
    mem_save_info,   // 207:204
    mem_ram_wr_src,  // 203:140
    mem_addr,        // 139:76
    mem_csr_data,    // 75 :12
    mem_ram_rd_ena,  // 11 :11
    mem_ram_wr_ena,  // 10 :10
    
    // wb
    mem_reg_wr_ctrl, // 9  :7
    mem_reg_wr_addr, // 6  :2
    mem_reg_wr_ena,  // 1  :1
    mem_csr_wr_ena   // 0  :0
  } = ex_to_mem_bus_r & {`EX_TO_MEM_WIDTH{mem_valid}};
  wire ex_ram_rd_ena = ex_to_mem_bus[11];
  wire ex_ram_wr_ena = ex_to_mem_bus[10];
  wire refresh = ex_to_mem_valid && mem_allowin;
  wire mem_handshake = mem_rw_valid && mem_rw_ready;

  wire op_sb = mem_save_info[`SAVE_SB];
  wire op_sh = mem_save_info[`SAVE_SH];
  wire op_sw = mem_save_info[`SAVE_SW];
  wire op_sd = mem_save_info[`SAVE_SD];

  wire op_lb  = mem_load_info[`LOAD_LB];
  wire op_lh  = mem_load_info[`LOAD_LH];
  wire op_lw  = mem_load_info[`LOAD_LW];
  wire op_ld  = mem_load_info[`LOAD_LD];
  wire op_lbu = mem_load_info[`LOAD_LBU];
  wire op_lhu = mem_load_info[`LOAD_LHU];
  wire op_lwu = mem_load_info[`LOAD_LWU];
  
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
        if (refresh && (ex_ram_rd_ena || ex_ram_wr_ena)) begin
          mem_next_state = ADDR;
        end
      ADDR:
        if (mem_handshake) begin
          mem_next_state = RETN;
        end
      RETN:
        if (refresh) begin
          if (ex_ram_rd_ena || ex_ram_wr_ena) begin
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
  assign mem_rw_req = mem_ram_wr_ena;
  assign mem_w_data = mem_ram_wr_src & (
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
  

  reg[`REG_BUS] mem_data;
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

  wire mem_finish = mem_state == RETN;
  wire [`REG_BUS] mem_ex_data = mem_addr;
  assign mem_to_wb_bus = {
    mem_pc,          // 296:233
    mem_inst,        // 232:201
    mem_reg_wr_ena,  // 200:200
    mem_reg_wr_addr, // 199:195
    mem_reg_wr_ctrl, // 194:192
    mem_ex_data,     // 191:0
    mem_data,        // 127:0
    mem_csr_data     // 63 :0
  };
endmodule