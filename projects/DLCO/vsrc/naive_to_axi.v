`include "defines.v"

module naive_to_axi # (
  parameter RW_DATA_WIDTH     = 32,
  parameter RW_ADDR_WIDTH     = 32,
  parameter AXI_DATA_WIDTH    = 32,
  parameter AXI_ADDR_WIDTH    = 32,
  parameter AXI_ID_WIDTH      = 4,
  parameter AXI_USER_WIDTH    = 1
)(
  input                               clk,
  input                               rst,

  // naive bus
  output [RW_ADDR_WIDTH-1:0]          memaddr,     //dmem的地址
	input  [RW_DATA_WIDTH-1:0]          memdataout,  //dmem读取到的数据
	output [RW_DATA_WIDTH-1:0]          memdatain,   //需要写入dmem的数据
  output [2:0]                        memop,       //3'b000:sb 3'b001:sh 3'b010://sw
	output	                            memwe,       //dmem写有效
  
  // AXI4
  output                              axi_aw_ready,
  input                               axi_aw_valid,
  input [AXI_ADDR_WIDTH-1:0]          axi_aw_addr,
  input [2:0]                         axi_aw_prot,
  input [AXI_ID_WIDTH-1:0]            axi_aw_id,
  input [AXI_USER_WIDTH-1:0]          axi_aw_user,
  input [7:0]                         axi_aw_len,
  input [2:0]                         axi_aw_size,
  input [1:0]                         axi_aw_burst,
  input                               axi_aw_lock,
  input [3:0]                         axi_aw_cache,
  input [3:0]                         axi_aw_qos,

  output                              axi_w_ready,
  input                               axi_w_valid,
  input [AXI_DATA_WIDTH-1:0]          axi_w_data,
  input [AXI_DATA_WIDTH/8-1:0]        axi_w_strb,
  input                               axi_w_last,
  input [AXI_ID_WIDTH-1:0]            axi_w_id,
  
  input                               axi_b_ready,
  output                              axi_b_valid,
  output  [1:0]                       axi_b_resp,
  output  [AXI_ID_WIDTH-1:0]          axi_b_id,
  output  [AXI_USER_WIDTH-1:0]        axi_b_user,

  output                              axi_ar_ready,
  input                               axi_ar_valid,
  input [AXI_ADDR_WIDTH-1:0]          axi_ar_addr,
  input [2:0]                         axi_ar_prot,
  input [AXI_ID_WIDTH-1:0]            axi_ar_id,
  input [AXI_USER_WIDTH-1:0]          axi_ar_user,
  input [7:0]                         axi_ar_len,
  input [2:0]                         axi_ar_size,
  input [1:0]                         axi_ar_burst,
  input                               axi_ar_lock,
  input [3:0]                         axi_ar_cache,
  input [3:0]                         axi_ar_qos,
    
  input                               axi_r_ready,
  output                              axi_r_valid,
  output  [1:0]                       axi_r_resp,
  output  [AXI_DATA_WIDTH-1:0]        axi_r_data,
  output                              axi_r_last,
  output  [AXI_ID_WIDTH-1:0]          axi_r_id,
  output  [AXI_USER_WIDTH-1:0]        axi_r_user
);
  
  localparam [1:0] IDLE = 2'b00;
  localparam [1:0] READ_TRANS = 2'b01;
  localparam [1:0] WRITE_TRANS = 2'b10;
  localparam [1:0] WRITE_RESP = 2'b11;
  // a READ operation happens between IDLE and READ_TRANS
  // a WRITE operation happens between WRITE_TRANS and WRITE_RESP

  reg [1:0] state;
  reg [1:0] next_state;

  always @(posedge clk) begin
    state <= ~{2{rst}} & next_state;
  end

  always @(*) begin
    case (state)
      IDLE, READ_TRANS: begin
        if (axi_aw_valid) begin
          next_state = WRITE_TRANS;
        end
        else if (axi_ar_valid) begin
          next_state = READ_TRANS;
        end
        else next_state = IDLE;
      end
      WRITE_TRANS: begin
        next_state = WRITE_RESP;
      end
      WRITE_RESP: begin
        if (axi_aw_valid) begin
          next_state = WRITE_TRANS;
        end
        else if (axi_ar_valid) begin
          next_state = READ_TRANS;
        end
        else next_state = IDLE;
      end
    endcase
  end

  wire [1:0] w_offset;
  assign w_offset = (
      ({2{axi_w_strb == 4'b0001}} & 2'b00)
    | ({2{axi_w_strb == 4'b0010}} & 2'b01)
    | ({2{axi_w_strb == 4'b0100}} & 2'b10)
    | ({2{axi_w_strb == 4'b1000}} & 2'b11)
    | ({2{axi_w_strb == 4'b0011}} & 2'b00)
    | ({2{axi_w_strb == 4'b1100}} & 2'b10)
    | ({2{axi_w_strb == 4'b1111}} & 2'b00)
  );
  
  wire ar_hs = axi_ar_valid && axi_ar_ready;
  wire aw_hs = axi_aw_valid && axi_aw_ready;

  // generate addr
  reg [31:0] naive_wr_addr;
  wire [31:0] naive_rd_addr = axi_ar_addr;

  // naive_wr_addr should keep available until finish writing
  always @(posedge clk) begin
    if (aw_hs)
      naive_wr_addr <= axi_aw_addr;
    else
      naive_wr_addr <= naive_wr_addr;
  end
  
  assign memaddr = axi_aw_valid ? (naive_wr_addr | {30'b0, w_offset}) : naive_rd_addr;

  assign memdatain = (
      ({32{axi_w_strb == 4'b0001}} & {24'b0, axi_w_data[7:0]})
    | ({32{axi_w_strb == 4'b0010}} & {24'b0, axi_w_data[15:8]})
    | ({32{axi_w_strb == 4'b0100}} & {24'b0, axi_w_data[23:16]})
    | ({32{axi_w_strb == 4'b1000}} & {24'b0, axi_w_data[31:24]})
    | ({32{axi_w_strb == 4'b0011}} & {16'b0, axi_w_data[15:0]})
    | ({32{axi_w_strb == 4'b1100}} & {16'b0, axi_w_data[31:16]})
    | ({32{axi_w_strb == 4'b1111}} & {axi_w_data[31:0]})
  );

  assign memwe = axi_w_ready;

  assign axi_aw_ready = next_state == WRITE_TRANS;

  assign axi_w_ready = state == WRITE_TRANS;

  assign axi_b_valid = state == WRITE_RESP;
  assign axi_b_resp = {1'b0, axi_b_valid};
  assign axi_b_id = 0;
  assign axi_b_user = 0;

  assign axi_ar_ready = next_state == READ_TRANS;
  
  assign axi_r_valid = state == READ_TRANS;
  assign axi_r_resp = {1'b0, axi_r_valid};
  assign axi_r_data = memdataout;
  assign axi_r_last = axi_r_valid;
  assign axi_r_id = 0;
  assign axi_r_user = 0;
endmodule