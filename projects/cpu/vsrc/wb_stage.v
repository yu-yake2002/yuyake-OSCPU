
//--Sun Jiru, Nanjing University--

`include "defines.v"

module wb_stage (
  input wire                              clk,
  input wire                              rst,
  
  // pipeline control
  input wire                              mem_to_wb_valid,
  input wire [`MEM_TO_WB_WIDTH-1:0]       mem_to_wb_bus,
  output wire                             wb_allowin,
  
  output wire [`WB_FORWARD_WIDTH-1:0]     wb_forward_bus,
  
  // regfile control
  output wire                             reg_wr_ena,
  output wire [4 : 0]                     reg_wr_addr,
  output wire [`REG_BUS]                  reg_wr_data,

  // difftest
  input wire [`MEM_TO_WB_DIFF_WIDTH-1:0]  mem_to_wb_diffbus,
  output wire [`WB_DIFFTEST_WIDTH-1:0]    difftest_bus,
  
  // serial port output
  output wire                             wb_uart_out_valid,
  output wire [7 : 0]                     wb_uart_out_char
  );
  
  // pipeline control
  reg wb_valid;
  reg [`MEM_TO_WB_WIDTH-1:0] mem_to_wb_bus_r;
  reg [`MEM_TO_WB_DIFF_WIDTH-1:0] mem_to_wb_diffbus_r;
  assign wb_allowin = 1'b1;
  
  always @(posedge clk) begin
    if (rst) begin
      wb_valid <= 1'b0;
    end
    else if (wb_allowin) begin
      wb_valid <= mem_to_wb_valid;
    end

    if (mem_to_wb_valid && wb_allowin) begin
      mem_to_wb_bus_r <= mem_to_wb_bus;
      mem_to_wb_diffbus_r <= mem_to_wb_diffbus;
    end
  end
  
  wire [`REG_BUS] wb_pc;
  wire [31 : 0]   wb_inst;
  wire            wb_wen;
  wire [4  : 0]   wb_wdest;
  
  assign {
    // serial port output
    wb_uart_out_valid, // 305:305
    wb_uart_out_char,  // 304:297
    
    wb_pc,          // 296:233
    wb_inst,        // 232:201
    wb_wen,         // 200:200
    wb_wdest,       // 199:195
    wb_reg_wr_ctrl, // 194:192
    wb_ex_data,     // 191:0
    wb_mem_rd_data,    // 127:0
    wb_csr_rd_data     // 63 :0
  } = mem_to_wb_bus_r & {`MEM_TO_WB_WIDTH{wb_valid}};

  // write in
  assign reg_wr_ena = wb_wen && wb_valid;
  assign reg_wr_addr = wb_wdest;
  wire [`REG_CTRL_BUS] wb_reg_wr_ctrl;
  wire [`REG_BUS] wb_ex_data, wb_mem_rd_data, wb_csr_rd_data;

  wire mem_to_reg = wb_reg_wr_ctrl[`MEM_TO_REG];
  wire ex_to_reg  = wb_reg_wr_ctrl[`EXE_TO_REG];
  wire csr_to_reg = wb_reg_wr_ctrl[`CSR_TO_REG];
  
  wire [`EXCP_BUS] wb_excp_bus;
  assign reg_wr_data = {64{~rst}} & (
      ({64{mem_to_reg}} & wb_mem_rd_data)
    | ({64{ex_to_reg}}  & wb_ex_data)
    | ({64{csr_to_reg}} & wb_csr_rd_data)
  );
  
  wire wb_commit = wb_valid;
  assign difftest_bus = {
    mem_to_wb_diffbus_r,
    wb_pc,       // 96 :33
    wb_inst,     // 32 :1
    wb_commit    // 0  :0
  };

  assign wb_forward_bus = {
    reg_wr_addr,       // 136:132
    reg_wr_ena,        // 131:131
    wb_ex_data,        // 130:67
    wb_mem_rd_data,    // 66 :3
    wb_reg_wr_ctrl     // 2  :0
  };
endmodule