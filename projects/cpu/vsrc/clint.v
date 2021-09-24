
// Sun Jiru, Nanjing University

`include "defines.v"

module clint # (
  parameter RW_DATA_WIDTH     = 64,
  parameter RW_ADDR_WIDTH     = 64,
  parameter AXI_DATA_WIDTH    = 64,
  parameter AXI_ADDR_WIDTH    = 64,
  parameter AXI_ID_WIDTH      = 4,
  parameter AXI_USER_WIDTH    = 1
)(
  input  wire                             clk,
  input  wire                             rst,

  // AXI bus
  output wire                             aw_ready_o,
  input  wire                             aw_valid_i,
  input  wire [AXI_ADDR_WIDTH-1:0]        aw_addr_i,
  input  wire [2:0]                       aw_prot_i,
  input  wire [AXI_ID_WIDTH-1:0]          aw_id_i,
  input  wire [AXI_USER_WIDTH-1:0]        aw_user_i,
  input  wire [7:0]                       aw_len_i,
  input  wire [2:0]                       aw_size_i,
  input  wire [1:0]                       aw_burst_i,
  input  wire                             aw_lock_i,
  input  wire [3:0]                       aw_cache_i,
  input  wire [3:0]                       aw_qos_i,
  
  output wire                             w_ready_o,
  input  wire                             w_valid_i,
  input  wire [AXI_DATA_WIDTH-1:0]        w_data_i,
  input  wire [AXI_DATA_WIDTH/8-1:0]      w_strb_i,
  input  wire                             w_last_i,
  input  wire [AXI_ID_WIDTH-1:0]          w_id_i,
   
  input  wire                             b_ready_i,
  output wire                             b_valid_o,
  output wire [1:0]                       b_resp_o,
  output wire [AXI_ID_WIDTH-1:0]          b_id_o,
  output wire [AXI_USER_WIDTH-1:0]        b_user_o,
  
  output wire                             ar_ready_o,
  input  wire                             ar_valid_i,
  input  wire [AXI_ADDR_WIDTH-1:0]        ar_addr_i,
  input  wire [2:0]                       ar_prot_i,
  input  wire [AXI_ID_WIDTH-1:0]          ar_id_i,
  input  wire [AXI_USER_WIDTH-1:0]        ar_user_i,
  input  wire [7:0]                       ar_len_i,
  input  wire [2:0]                       ar_size_i,
  input  wire [1:0]                       ar_burst_i,
  input  wire                             ar_lock_i,
  input  wire [3:0]                       ar_cache_i,
  input  wire [3:0]                       ar_qos_i,
  
  input  wire                             r_ready_i,
  output wire                             r_valid_o,
  output wire [1:0]                       r_resp_o,
  output wire [AXI_DATA_WIDTH-1:0]        r_data_o,
  output wire                             r_last_o,
  output wire [AXI_ID_WIDTH-1:0]          r_id_o,
  output wire [AXI_USER_WIDTH-1:0]        r_user_o,

  // interupt bus to core
  output wire [`ITRP_BUS]                 clint_interupt_bus
);

  // CLINT CSRs
  reg [31 : 0]   csr_msip;
  reg [`REG_BUS] csr_mtime, csr_mtimecmp;

  wire ar_hs  = ar_valid_i && ar_ready_o;
  wire r_hs   = r_valid_o  && r_ready_i;
  wire aw_hs  = aw_valid_i && aw_ready_o;
  wire w_hs   = w_valid_i  && w_ready_o;
  wire b_hs   = b_valid_o  && b_ready_i;
  
  /* ------Read Bus------ */

  // Read State Machine
  parameter R_STATE_IDLE = 1'b0, R_STATE_READ = 1'b1;
  reg r_state;
  wire r_state_idle = r_state == R_STATE_IDLE;
  wire r_state_read = r_state == R_STATE_READ;

  always @(posedge clk) begin
    if (rst) begin
      r_state <= R_STATE_IDLE;
    end
    else begin
      case (r_state)
        R_STATE_IDLE: if (ar_hs) r_state <= R_STATE_READ;
        R_STATE_READ: if (r_hs)  r_state <= R_STATE_IDLE;
      endcase
    end
  end
  
  // ar bus
  assign ar_ready_o = r_state_idle && ar_valid_i;
  reg [`REG_BUS]           rd_addr_reg;
  reg [AXI_ID_WIDTH-1:0]   rd_id_reg;
  reg [AXI_USER_WIDTH-1:0] rd_user_reg;
  always @(posedge clk) begin
    if (rst) begin
      {rd_addr_reg, rd_id_reg, rd_user_reg} <= `ZERO_WORD;
    end
    else if (ar_hs) begin
      rd_addr_reg <= ar_addr_i;
      rd_id_reg   <= ar_id_i;
      rd_user_reg <= ar_user_i;
    end
  end

  // r bus
  assign r_valid_o = R_STATE_READ;
  assign r_resp_o  = 2'b0;

  wire msip_rd_ena     = (rd_addr_reg == 64'h00000000_02000000);
  wire mtimecmp_rd_ena = (rd_addr_reg == 64'h00000000_02004000);
  wire mtime_rd_ena    = (rd_addr_reg == 64'h00000000_0200BFF8);
  assign r_data_o  = (
      ({64{msip_rd_ena}}     & {{32{csr_msip[31]}}, csr_msip})
    | ({64{mtimecmp_rd_ena}} & csr_mtimecmp)
    | ({64{mtime_rd_ena}}    & csr_mtime)
  );

  assign r_last_o  = R_STATE_READ;
  assign r_id_o    = rd_id_reg;
  assign r_user_o  = rd_user_reg;
  
  /* ------Write Bus------ */

  // Write State Machine
  parameter [1:0] W_STATE_IDLE = 2'b00, W_STATE_WRITE = 2'b01, W_STATE_RESP = 2'b10;
  reg [1 : 0] w_state;
  wire w_state_idle  = w_state == W_STATE_IDLE;
  wire w_state_write = w_state == W_STATE_WRITE;
  wire w_state_resp  = w_state == W_STATE_RESP;
  
  always @(posedge clk) begin
    if (rst) begin
      w_state <= W_STATE_IDLE;
    end
    else begin
      case (w_state)
        W_STATE_IDLE:
          if (aw_hs) 
            w_state <= W_STATE_WRITE;
        W_STATE_WRITE:
          if (w_hs && w_last_i)
            w_state <= W_STATE_RESP;
        W_STATE_RESP:
          if (b_hs)
            w_state <= W_STATE_IDLE;
        default:
          w_state <= W_STATE_IDLE;
      endcase
    end
  end

  // aw bus
  assign aw_ready_o = w_state_idle && aw_valid_i;
  reg [`REG_BUS]           wr_addr_reg;
  reg [AXI_ID_WIDTH-1:0]   wr_id_reg;
  reg [AXI_USER_WIDTH-1:0] wr_user_reg;
  always @(posedge clk) begin
    if (rst) begin
      {wr_addr_reg, wr_id_reg, wr_user_reg} <= `ZERO_WORD;
    end
    else if (aw_hs) begin
      wr_addr_reg <= aw_addr_i;
      wr_id_reg   <= aw_id_i;
      wr_user_reg <= aw_user_i;
    end
  end

  // w bus
  assign w_ready_o = W_STATE_WRITE && w_valid_i;
  
  wire [`REG_BUS] wr_mask = {
    {8{w_strb_i[7]}},
    {8{w_strb_i[6]}},
    {8{w_strb_i[5]}},
    {8{w_strb_i[4]}},
    {8{w_strb_i[3]}},
    {8{w_strb_i[2]}},
    {8{w_strb_i[1]}},
    {8{w_strb_i[0]}}
  };
  wire msip_wr_ena     = (wr_addr_reg == 64'h00000000_02000000);
  wire mtimecmp_wr_ena = (wr_addr_reg == 64'h00000000_02004000);
  wire mtime_wr_ena    = (wr_addr_reg == 64'h00000000_0200BFF8);
  // msip
  always @(posedge clk) begin
    if (rst) begin
      csr_msip <= 32'b0;
    end
    else if (w_hs && msip_wr_ena) begin
      csr_msip <= (~wr_mask[31:0] & csr_msip) | (wr_mask[31:0] & w_data_i[31:0]);
    end
  end
  
  // mtimecmp
  always @(posedge clk) begin
    if (rst) begin
      csr_mtimecmp <= `ZERO_WORD;
    end
    else if (w_hs && mtimecmp_wr_ena) begin
        csr_mtimecmp <= (~wr_mask & csr_mtimecmp) | (wr_mask & w_data_i);
    end
  end

  // mtime
  always @(posedge clk) begin
    if (rst) begin
      csr_mtime <= `ZERO_WORD;
    end
    else if (w_hs && mtime_wr_ena) begin
      csr_mtime <= (~wr_mask & csr_mtime) | (wr_mask & w_data_i);
    end 
    else begin
      csr_mtime <= csr_mtime + 1;
    end
  end
  
  // b bus
  assign b_valid_o = w_state_resp;
  //assign b_valid_o = 1'b0;
 
  assign b_resp_o  = 2'b0;
  assign b_id_o    = wr_id_reg;
  assign b_user_o  = wr_user_reg;
  
  /* ------Generate CLINT------ */
  assign clint_interupt_bus [`SOFT_ITRP]  = csr_msip == 32'b1;
  assign clint_interupt_bus [`TIMER_ITRP] = csr_mtime >= csr_mtimecmp;
endmodule