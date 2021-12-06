`include "defines.v"

module mem_stage(
  input  wire                              clk,
  input  wire                              rst,
  
  // pipeline control
  input wire                               ex_to_mem_valid,
  input wire [`REG_BUS]                    ex_to_mem_pc,
  input wire [`INST_BUS]                   ex_to_mem_inst,
  input wire [`EX_TO_MEM_WIDTH-1:0]        ex_to_mem_bus,
  output wire                              mem_allowin,
  output wire                              ex_to_mem_handshake,

  output wire                              mem_to_wb_valid,
  output wire [`REG_BUS]                   mem_to_wb_pc,
  output wire [`INST_BUS]                  mem_to_wb_inst,
  output wire [`MEM_TO_WB_WIDTH-1:0]       mem_to_wb_bus,
  input wire                               wb_allowin,
  
  // pipeline forward control
  output wire [`MEM_FORWARD_WIDTH-1:0]     mem_forward_bus,
  
  // difftest bus
  input wire [`EX_TO_MEM_DIFF_WIDTH-1:0]   ex_to_mem_diffbus,
  output wire [`MEM_TO_WB_DIFF_WIDTH-1:0]  mem_to_wb_diffbus,

  // custom interface
  output wire                              mem_rw_valid,
  input  wire                              mem_rw_ready,
  output wire                              mem_rw_req,
  input  wire [`REG_BUS]                   mem_r_data,
  output wire [`REG_BUS]                   mem_w_data,
  output wire [`REG_BUS]                   mem_rw_addr,
  output wire [1 : 0]                      mem_rw_size,
  input  wire [1 : 0]                      mem_rw_resp
  );

  // pipeline control
  reg mem_valid;
  wire mem_ready_go;
  reg [`REG_BUS] ex_to_mem_pc_r;
  reg [`INST_BUS] ex_to_mem_inst_r;
  reg [`EX_TO_MEM_WIDTH-1:0] ex_to_mem_bus_r;
  reg [`EX_TO_MEM_DIFF_WIDTH-1:0] ex_to_mem_diffbus_r;
  
  assign mem_ready_go = mem_finish || (~mem_ram_rd_ena && ~mem_ram_wr_ena);
  assign mem_allowin = !mem_valid || mem_ready_go && wb_allowin;
  assign mem_to_wb_valid = mem_valid && mem_ready_go;
  assign ex_to_mem_handshake = ex_to_mem_valid && mem_allowin;

  always @(posedge clk) begin
    if (rst) begin
      mem_valid <= 1'b0;
    end
    else if (mem_allowin) begin
      mem_valid <= ex_to_mem_valid;
    end

    if (ex_to_mem_valid && mem_allowin) begin
      ex_to_mem_pc_r <= ex_to_mem_pc;
      ex_to_mem_inst_r <= ex_to_mem_inst;
      ex_to_mem_bus_r <= ex_to_mem_bus;
      ex_to_mem_diffbus_r <= ex_to_mem_diffbus;
    end
  end

  // serial port output
  wire             mem_uart_out_valid;
  wire [7 : 0]     mem_uart_out_char;
  
  wire [`REG_BUS]  mem_pc;
  wire [31 : 0]    mem_inst;
  
  // ram control
  wire [`LOAD_BUS] mem_load_info;
  wire [`SAVE_BUS] mem_save_info;
  wire [`REG_BUS]  mem_ram_wr_src;
  wire [`REG_BUS]  mem_addr, mem_csr_rd_data;
  wire             mem_ram_rd_ena;
  wire             mem_ram_wr_ena;
  
  // wb stage
  wire [2  : 0]    mem_reg_wr_ctrl;
  wire [4  : 0]    mem_reg_wr_addr;
  wire             mem_reg_wr_ena;
  
  assign mem_pc = ex_to_mem_pc_r;
  assign mem_inst = ex_to_mem_inst_r;
  assign {
    mem_uart_out_valid, // 123:123
    mem_uart_out_char,  // 122:115

    // mem
    mem_load_info,   // 114:110
    mem_save_info,   // 109:107
    mem_ram_wr_src,  // 106:75
    mem_addr,        // 74 :43
    mem_csr_rd_data, // 42 :11
    mem_ram_rd_ena,  // 10 :10
    mem_ram_wr_ena,  // 9  :9
    
    // wb
    mem_reg_wr_ctrl, // 8  :6
    mem_reg_wr_addr, // 5  :1
    mem_reg_wr_ena   // 0  :0
  } = ex_to_mem_bus_r & {`EX_TO_MEM_WIDTH{mem_valid}};
  wire ex_ram_rd_ena = ex_to_mem_bus[10];
  wire ex_ram_wr_ena = ex_to_mem_bus[9];
  wire refresh = ex_to_mem_valid && mem_allowin;
  wire mem_handshake = mem_rw_valid && mem_rw_ready;

  wire op_sb = mem_save_info[`SAVE_SB];
  wire op_sh = mem_save_info[`SAVE_SH];
  wire op_sw = mem_save_info[`SAVE_SW];

  wire op_lb  = mem_load_info[`LOAD_LB];
  wire op_lh  = mem_load_info[`LOAD_LH];
  wire op_lw  = mem_load_info[`LOAD_LW];
  wire op_lbu = mem_load_info[`LOAD_LBU];
  wire op_lhu = mem_load_info[`LOAD_LHU];
  
  parameter IDLE = 2'b00, ADDR = 2'b01, RETN = 2'b10;
  reg [1:0] mem_state;
  reg [1:0] mem_next_state;
  
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
        else begin
          mem_next_state = mem_state;
        end
      ADDR:
        if (mem_handshake) begin
          mem_next_state = RETN;
        end
        else begin
          mem_next_state = mem_state;
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
        else begin
          mem_next_state = RETN;
        end
      default:
        mem_next_state = IDLE;
    endcase
  end

  assign mem_rw_valid = mem_state == ADDR;
  assign mem_rw_req = mem_ram_wr_ena;
  assign mem_w_data = mem_ram_wr_src & (
      ({32{op_sb}} & 32'hff)
    | ({32{op_sh}} & 32'hffff)
    | ({32{op_sw}} & 32'hffffffff)
  );
  assign mem_rw_addr = mem_addr;
  assign mem_rw_size = (
      ({2{op_sb || op_lb || op_lbu}} & `SIZE_B)
    | ({2{op_sh || op_lh || op_lhu}} & `SIZE_H)
    | ({2{op_sw || op_lw          }} & `SIZE_W)
  );
  

  reg[`REG_BUS] mem_data;
  always @(posedge clk) begin
    if (mem_handshake) begin
      mem_data <= (
          ({32{op_lb}} & {{24{mem_r_data[7 ]}}, mem_r_data[7  : 0]})
        | ({32{op_lh}} & {{16{mem_r_data[15]}}, mem_r_data[15 : 0]})
        | ({32{op_lw}} & mem_r_data[31 : 0])
        | ({32{op_lbu}} & {24'b0, mem_r_data[7  : 0]})
        | ({32{op_lhu}} & {16'b0, mem_r_data[15 : 0]})
      );
    end
  end

  wire mem_finish = mem_state == RETN;
  wire [`REG_BUS] mem_ex_data = mem_addr;
  
  // difftest
  wire size_b = mem_rw_size == `SIZE_B;
  wire size_h = mem_rw_size == `SIZE_H;
  wire size_w = mem_rw_size == `SIZE_W;
  wire addr0 = mem_rw_addr[1:0] == 2'b00;
  wire addr1 = mem_rw_addr[1:0] == 2'b01;
  wire addr2 = mem_rw_addr[1:0] == 2'b10;
  wire addr3 = mem_rw_addr[1:0] == 2'b11;
  wire            difftest_s_valid = |mem_save_info;
  wire            difftest_l_valid = |mem_load_info;
  wire [`REG_BUS] difftest_addr = {mem_addr[31:2], 2'b0};
  wire [`REG_BUS] difftest_data = (
      ({32{size_b}} & {4{mem_w_data[7 :0]}})
    | ({32{size_h}} & {2{mem_w_data[15:0]}})
    | ({32{size_w}} & {1{mem_w_data[31:0]}})
  ) & (
      ({32{addr0 && size_w}} & 32'hffffffff)
    | ({32{addr0 && size_h}} & 32'h0000ffff)
    | ({32{addr0 && size_b}} & 32'h000000ff)
    | ({32{addr1 && size_b}} & 32'h0000ff00)
    | ({32{addr2 && size_h}} & 32'hffff0000)
    | ({32{addr2 && size_b}} & 32'h00ff0000)
    | ({32{addr3 && size_b}} & 32'hff000000)
  );
  wire [3:0] difftest_mask = (
      ({4{size_b}} & 4'b0001)
    | ({4{size_h}} & 4'b0011)
    | ({4{size_w}} & 4'b1111)
  ) << mem_addr[2:0];
  assign mem_to_wb_diffbus = {
    ex_to_mem_diffbus_r,

    difftest_addr,      // 69 :38
    difftest_data,      // 37 :6
    difftest_mask,      // 5  :2
    difftest_s_valid,   // 1  :1
    difftest_l_valid    // 0  :0
  };

  assign mem_to_wb_pc = mem_pc;
  assign mem_to_wb_inst = mem_inst;
  assign mem_to_wb_bus = {
    // serial port output
    mem_uart_out_valid, // 113:113
    mem_uart_out_char,  // 112:105

    // wb stage
    mem_reg_wr_ena,  // 104:104
    mem_reg_wr_addr, // 103:99
    mem_reg_wr_ctrl, // 98 :96
    mem_ex_data,     // 95 :64
    mem_data,        // 63 :32
    mem_csr_rd_data  // 31 :0
  };

  assign mem_forward_bus = {
    mem_reg_wr_addr, // 40 :35
    mem_reg_wr_ena,  // 35 :35
    mem_ex_data,     // 34 :3
    mem_reg_wr_ctrl  // 2  :0
  };
endmodule