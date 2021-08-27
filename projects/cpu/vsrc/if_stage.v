
/* verilator lint_off UNUSED */
//--Sun Jiru, Nanjing University--

`include "defines.v"

module if_stage(
  input wire            clk,
  input wire            rst,
  input wire            refresh,
  
  // branch and jump control
  input wire            bj_ena,
  input wire [`REG_BUS] bj_pc,
  input wire            excp_jmp_ena,
  input wire [`REG_BUS] excp_pc,
  
  // output to pipeline
  output reg [`REG_BUS] if_pc,
  output reg [31  :  0] if_inst,

  // AXI4
  output wire           if_axi_valid, // master is valid
  input wire            if_axi_ready, // slave is ready
  input wire [`REG_BUS] if_axi_data_read,
  output reg [`REG_BUS] if_axi_addr,
  output wire [1:0]     if_axi_size,
  input wire [1:0]      if_axi_resp,

  output wire           if_finish
  );
  
  parameter IDLE = 2'b00, ADDR = 2'b01, RETN = 2'b10;
  reg [1:0] if_state;
  reg [1:0] if_next_state;

  always @(posedge clk) begin
    if (rst) begin
      if_state <= IDLE;
    end
    else begin
      if_state <= if_next_state;
    end
  end

  always @(*) begin
    case (if_state)
      IDLE:
        if_next_state = refresh ? ADDR : IDLE;
      ADDR:
        if_next_state = if_handshake ? RETN : ADDR;
      RETN:
        if_next_state = refresh ? ADDR : RETN;
      default:
        if_next_state = IDLE;
    endcase
  end

  // fetch an instruction
  assign if_axi_valid = if_state == ADDR;
  assign if_axi_size = `SIZE_W;

  wire if_handshake = if_axi_valid & if_axi_ready;

  always @(posedge clk) begin
    if (rst) begin
      if_pc <= `PC_START;
      if_axi_addr <= `PC_START;
    end
    else if (if_handshake) begin
      if_pc <= if_axi_addr; // this pc
      if_axi_addr <= excp_jmp_ena ? excp_pc :
                     bj_ena       ? bj_pc   :
                     (if_axi_addr + 4) ; // next pc
      if_inst <= if_axi_data_read[31 : 0]; // this inst
    end
  end

  assign if_finish = if_state == RETN && ~refresh;
endmodule
