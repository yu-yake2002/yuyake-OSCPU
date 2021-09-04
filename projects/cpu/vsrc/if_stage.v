
/* verilator lint_off UNUSED */
//--Sun Jiru, Nanjing University--

`include "defines.v"

module if_stage(
  input wire                          clk,
  input wire                          rst,
  input wire                          refresh,
  
  // pipeline control
  output wire                         if_to_id_valid,
  output wire [`IF_TO_ID_WIDTH-1:0]   if_to_id_bus,
  input wire                          id_allowin,
  
  // branch and jump control
  input wire [`BJ_CTRL_WIDTH-1:0]     bj_ctrl_bus,
  input wire                          excp_jmp_ena,
  input wire [`REG_BUS]               excp_pc,

  // AXI4
  output wire                         if_axi_valid, // master is valid
  input wire                          if_axi_ready, // slave is ready
  input wire [`REG_BUS]               if_axi_data_read,
  output reg [`REG_BUS]               if_axi_addr,
  output wire [1:0]                   if_axi_size,
  input wire [1:0]                    if_axi_resp
  );
  
  wire [`REG_BUS] bj_pc;
  wire            bj_ena, bj_stall;
  assign {
    bj_pc,    // 65:2
    bj_ena,   // 1 :1
    bj_stall  // 0 :0
  } = bj_ctrl_bus;

  // pre-IF stage
  wire pre_valid = 1'b1;
  wire pre_ready_go = if_state == RETN;
  wire pre_to_if_valid = pre_valid && pre_ready_go;
  wire [`REG_BUS] next_pc = excp_jmp_ena ? excp_pc :
                            bj_ena       ? bj_pc   :
                            (if_pc + 4);
  
  // fetch an instruction
  assign if_axi_valid = if_state == ADDR;
  wire   if_handshake = if_axi_valid & if_axi_ready;
  
  assign if_axi_addr = next_pc;
  assign if_axi_size = `SIZE_W;

  // State Machine
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
        if_next_state = bj_stall ? IDLE : ADDR;
      ADDR:
        if_next_state = if_handshake ? RETN : ADDR;
      RETN:
        if_next_state = bj_stall ? RETN : ADDR;
      default:
        if_next_state = IDLE;
    endcase
  end
  
  // IF stage
  
  // pipeline control
  reg if_valid;
  wire if_ready_go;
  wire if_allowin;
  
  assign if_ready_go    = if_finish;
  assign if_allowin     = !if_valid || if_ready_go && id_allowin;
  assign if_to_id_valid = if_valid && if_ready_go;
  
  always @(posedge clk) begin
    if (rst) begin
      if_valid <= 1'b0;
    end
    else if (if_allowin) begin
      if_valid <= pre_to_if_valid;
    end
  end
  
  reg [`REG_BUS] if_pc;
  reg [31 : 0]   if_inst;
  
  always @(posedge clk) begin
    if (rst) begin
      if_pc <= 64'h7ffffffc;
    end
    else if (pre_to_if_valid && if_allowin) begin
      if_pc <= next_pc;
      if_inst <= if_axi_data_read[31 : 0]; // this inst
    end
  end
  
  wire if_finish = (if_state == RETN) && ~refresh;

  assign if_to_id_bus = {
    if_inst,
    if_pc
  };
endmodule
