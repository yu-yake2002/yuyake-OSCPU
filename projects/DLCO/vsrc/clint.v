
// Sun Jiru, Nanjing University

`include "defines.v"

module clint # (
  parameter RW_DATA_WIDTH     = 32,
  parameter RW_ADDR_WIDTH     = 32,
  parameter AXI_DATA_WIDTH    = 32,
  parameter AXI_ADDR_WIDTH    = 32,
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

  wire debug_wr = msip_wr_ena || mtime_wr_ena || mtimecmp_wr_ena;
  wire debug_rd = msip_rd_ena || mtime_rd_ena || mtimecmp_rd_ena;

  // CLINT CSRs
  reg [31 : 0]   csr_msip;
  reg [63 : 0] csr_mtime, csr_mtimecmp;

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
  reg [2:0]                rd_size_reg;
  always @(posedge clk) begin
    if (rst) begin
      {rd_addr_reg, rd_id_reg, rd_user_reg, rd_size_reg} <= 0; 
    end
    else if (ar_hs) begin
      rd_addr_reg <= ar_addr_i;
      rd_id_reg   <= ar_id_i;
      rd_user_reg <= ar_user_i;
      rd_size_reg <= ar_size_i;
    end
    else if (r_hs) begin
      rd_addr_reg <= 0;
    end
  end
  
  wire rd_size_b = rd_size_reg == 3'b000;
  wire rd_size_h = rd_size_reg == 3'b001;
  wire rd_size_w = rd_size_reg == 3'b010;

  // r bus
  assign r_valid_o = r_state_read;
  assign r_resp_o  = 2'b0;
  
  wire msip_rd_ena     = (rd_addr_reg[31:2] == 30'h800000);
  wire mtimecmp_rd_ena = (rd_addr_reg[31:3] == 29'h400800);
  wire mtime_rd_ena    = (rd_addr_reg[31:3] == 29'h4017FF);
  wire [63:0] clint_val = (
      ({64{msip_rd_ena}}     & {{32{csr_msip[31]}}, csr_msip})
    | ({64{mtimecmp_rd_ena}} & csr_mtimecmp)
    | ({64{mtime_rd_ena}}    & csr_mtime)
  ) >> rd_addr_reg[2:0];
  assign r_data_o  = (
      ({32{rd_size_b}} & {4{clint_val[7:0]}})
    | ({32{rd_size_h}} & {2{clint_val[15:0]}})
    | ({32{rd_size_w}} & {1{clint_val[31:0]}})
  );

  assign r_last_o  = r_state_read;
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
  reg [2:0]                wr_size_reg;
  always @(posedge clk) begin
    if (rst) begin
      {wr_addr_reg, wr_id_reg, wr_user_reg} <= 0;
      wr_size_reg <= 3'b0;
    end
    else if (aw_hs) begin
      wr_addr_reg <= aw_addr_i;
      wr_id_reg   <= aw_id_i;
      wr_user_reg <= aw_user_i;
      wr_size_reg <= aw_size_i;
    end
    else if (w_hs) begin
      wr_addr_reg <= 0;
    end
  end

  wire wr_size_b = wr_size_reg == 3'b000;
  wire wr_size_h = wr_size_reg == 3'b001;
  wire wr_size_w = wr_size_reg == 3'b010;
  // w bus
  assign w_ready_o = w_state_write && w_valid_i;
  wire [7:0] mask_size  = (
      ({8{wr_size_b}} & 8'b0001)
    | ({8{wr_size_h}} & 8'b0011)
    | ({8{wr_size_w}} & 8'b1111)
  ) << wr_addr_reg[2:0];
  wire [7:0] mask_8bits = ({4'b0, w_strb_i} << wr_addr_reg[2:0]) & mask_size;
  wire [63:0] wr_mask = {
    {8{mask_8bits[7]}},
    {8{mask_8bits[6]}},
    {8{mask_8bits[5]}},
    {8{mask_8bits[4]}},
    {8{mask_8bits[3]}},
    {8{mask_8bits[2]}},
    {8{mask_8bits[1]}},
    {8{mask_8bits[0]}}
  };
  wire msip_wr_ena     = (wr_addr_reg[31:2] == 30'h800000);
  wire mtimecmp_wr_ena = (wr_addr_reg[31:3] == 29'h400800);
  wire mtime_wr_ena    = (wr_addr_reg[31:3] == 29'h4017FF);
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
      csr_mtimecmp <= 64'b0;
    end
    else if (w_hs && mtimecmp_wr_ena) begin
        csr_mtimecmp <= (~wr_mask & csr_mtimecmp) | (wr_mask & (wr_addr_reg[2] ? {w_data_i, 32'b0} : {32'b0, w_data_i}));
    end
  end
  /*
  // decelerate
  reg [3:0] decelerate_reg;
  always @(posedge clk) begin
    if (rst) begin
      decelerate_reg <= 0;
    end
    else begin
      decelerate_reg <= decelerate_reg + 1;
    end
  end
  wire add_ctime = (&decelerate_reg);
  */
  // mtime
  always @(posedge clk) begin
    if (rst) begin
      csr_mtime <= 64'b0;
    end
    else if (w_hs && mtime_wr_ena) begin
      csr_mtime <= (~wr_mask & csr_mtime) | (wr_mask & (wr_addr_reg[2] ? {w_data_i, 32'b0} : {32'b0, w_data_i}));
    end 
    else begin
      //csr_mtime <= csr_mtime + add_ctime;
      csr_mtime <= csr_mtime + 1;
    end
  end
  
  // b bus
  assign b_valid_o = w_state_resp; 
  assign b_resp_o  = 2'b0;
  assign b_id_o    = wr_id_reg;
  assign b_user_o  = wr_user_reg;
  
  /* ------Generate CLINT------ */
  assign clint_interupt_bus [`SOFT_ITRP]  = csr_msip == 32'b1;
  assign clint_interupt_bus [`TIMER_ITRP] = csr_mtime >= csr_mtimecmp;
endmodule