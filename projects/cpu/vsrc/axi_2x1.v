
//--Sun Jiru, Nanjing University--

`include "defines.v"

// Burst types
`define AXI_BURST_TYPE_FIXED                                2'b00
`define AXI_BURST_TYPE_INCR                                 2'b01
`define AXI_BURST_TYPE_WRAP                                 2'b10
// Access permissions
`define AXI_PROT_UNPRIVILEGED_ACCESS                        3'b000
`define AXI_PROT_PRIVILEGED_ACCESS                          3'b001
`define AXI_PROT_SECURE_ACCESS                              3'b000
`define AXI_PROT_NON_SECURE_ACCESS                          3'b010
`define AXI_PROT_DATA_ACCESS                                3'b000
`define AXI_PROT_INSTRUCTION_ACCESS                         3'b100
// Memory types (AR)
`define AXI_ARCACHE_DEVICE_NON_BUFFERABLE                   4'b0000
`define AXI_ARCACHE_DEVICE_BUFFERABLE                       4'b0001
`define AXI_ARCACHE_NORMAL_NON_CACHEABLE_NON_BUFFERABLE     4'b0010
`define AXI_ARCACHE_NORMAL_NON_CACHEABLE_BUFFERABLE         4'b0011
`define AXI_ARCACHE_WRITE_THROUGH_NO_ALLOCATE               4'b1010
`define AXI_ARCACHE_WRITE_THROUGH_READ_ALLOCATE             4'b1110
`define AXI_ARCACHE_WRITE_THROUGH_WRITE_ALLOCATE            4'b1010
`define AXI_ARCACHE_WRITE_THROUGH_READ_AND_WRITE_ALLOCATE   4'b1110
`define AXI_ARCACHE_WRITE_BACK_NO_ALLOCATE                  4'b1011
`define AXI_ARCACHE_WRITE_BACK_READ_ALLOCATE                4'b1111
`define AXI_ARCACHE_WRITE_BACK_WRITE_ALLOCATE               4'b1011
`define AXI_ARCACHE_WRITE_BACK_READ_AND_WRITE_ALLOCATE      4'b1111
// Memory types (AW)
`define AXI_AWCACHE_DEVICE_NON_BUFFERABLE                   4'b0000
`define AXI_AWCACHE_DEVICE_BUFFERABLE                       4'b0001
`define AXI_AWCACHE_NORMAL_NON_CACHEABLE_NON_BUFFERABLE     4'b0010
`define AXI_AWCACHE_NORMAL_NON_CACHEABLE_BUFFERABLE         4'b0011
`define AXI_AWCACHE_WRITE_THROUGH_NO_ALLOCATE               4'b0110
`define AXI_AWCACHE_WRITE_THROUGH_READ_ALLOCATE             4'b0110
`define AXI_AWCACHE_WRITE_THROUGH_WRITE_ALLOCATE            4'b1110
`define AXI_AWCACHE_WRITE_THROUGH_READ_AND_WRITE_ALLOCATE   4'b1110
`define AXI_AWCACHE_WRITE_BACK_NO_ALLOCATE                  4'b0111
`define AXI_AWCACHE_WRITE_BACK_READ_ALLOCATE                4'b0111
`define AXI_AWCACHE_WRITE_BACK_WRITE_ALLOCATE               4'b1111
`define AXI_AWCACHE_WRITE_BACK_READ_AND_WRITE_ALLOCATE      4'b1111

`define AXI_SIZE_BYTES_1                                    3'b000
`define AXI_SIZE_BYTES_2                                    3'b001
`define AXI_SIZE_BYTES_4                                    3'b010
`define AXI_SIZE_BYTES_8                                    3'b011
`define AXI_SIZE_BYTES_16                                   3'b100
`define AXI_SIZE_BYTES_32                                   3'b101
`define AXI_SIZE_BYTES_64                                   3'b110
`define AXI_SIZE_BYTES_128                                  3'b111

module axi_2x1 # (
  parameter RW_DATA_WIDTH     = 64,
  parameter RW_ADDR_WIDTH     = 64,
  parameter AXI_DATA_WIDTH    = 64,
  parameter AXI_ADDR_WIDTH    = 64,
  parameter AXI_ID_WIDTH      = 4,
  parameter AXI_USER_WIDTH    = 1
)(
  input                 clock,
  input                 reset,

  // Advanced eXtensible Interface
  // mem stage (master) -> 2x1 interconnect (slave)
  // id: 0001
  output                              aw_ready_o_0,
  input                               aw_valid_i_0,
  input [AXI_ADDR_WIDTH-1:0]          aw_addr_i_0,
  input [2:0]                         aw_prot_i_0,
  input [AXI_ID_WIDTH-1:0]            aw_id_i_0,
  input [AXI_USER_WIDTH-1:0]          aw_user_i_0,
  input [7:0]                         aw_len_i_0,
  input [2:0]                         aw_size_i_0,
  input [1:0]                         aw_burst_i_0,
  input                               aw_lock_i_0,
  input [3:0]                         aw_cache_i_0,
  input [3:0]                         aw_qos_i_0,
  
  output                              w_ready_o_0,
  input                               w_valid_i_0,
  input [AXI_DATA_WIDTH-1:0]          w_data_i_0,
  input [AXI_DATA_WIDTH/8-1:0]        w_strb_i_0,
  input                               w_last_i_0,
  input [AXI_ID_WIDTH-1:0]            w_id_i_0,
   
  input                               b_ready_i_0,
  output                              b_valid_o_0,
  output  [1:0]                       b_resp_o_0,
  output  [AXI_ID_WIDTH-1:0]          b_id_o_0,
  output  [AXI_USER_WIDTH-1:0]        b_user_o_0,
  
  output                              ar_ready_o_0,
  input                               ar_valid_i_0,
  input [AXI_ADDR_WIDTH-1:0]          ar_addr_i_0,
  input [2:0]                         ar_prot_i_0,
  input [AXI_ID_WIDTH-1:0]            ar_id_i_0,
  input [AXI_USER_WIDTH-1:0]          ar_user_i_0,
  input [7:0]                         ar_len_i_0,
  input [2:0]                         ar_size_i_0,
  input [1:0]                         ar_burst_i_0,
  input                               ar_lock_i_0,
  input [3:0]                         ar_cache_i_0,
  input [3:0]                         ar_qos_i_0,
  
  input                               r_ready_i_0,
  output                              r_valid_o_0,
  output  [1:0]                       r_resp_o_0,
  output  [AXI_DATA_WIDTH-1:0]        r_data_o_0,
  output                              r_last_o_0,
  output  [AXI_ID_WIDTH-1:0]          r_id_o_0,
  output  [AXI_USER_WIDTH-1:0]        r_user_o_0,

  // Advanced eXtensible Interface
  // if stage (master) -> 2x1 interconnect (slave)
  // id: 0000
  output                              aw_ready_o_1,
  input                               aw_valid_i_1,
  input [AXI_ADDR_WIDTH-1:0]          aw_addr_i_1,
  input [2:0]                         aw_prot_i_1,
  input [AXI_ID_WIDTH-1:0]            aw_id_i_1,
  input [AXI_USER_WIDTH-1:0]          aw_user_i_1,
  input [7:0]                         aw_len_i_1,
  input [2:0]                         aw_size_i_1,
  input [1:0]                         aw_burst_i_1,
  input                               aw_lock_i_1,
  input [3:0]                         aw_cache_i_1,
  input [3:0]                         aw_qos_i_1,
  
  output                              w_ready_o_1,
  input                               w_valid_i_1,
  input [AXI_DATA_WIDTH-1:0]          w_data_i_1,
  input [AXI_DATA_WIDTH/8-1:0]        w_strb_i_1,
  input                               w_last_i_1,
  input [AXI_ID_WIDTH-1:0]            w_id_i_1,
  
  input                               b_ready_i_1,
  output                              b_valid_o_1,
  output  [1:0]                       b_resp_o_1,
  output  [AXI_ID_WIDTH-1:0]          b_id_o_1,
  output  [AXI_USER_WIDTH-1:0]        b_user_o_1,
  
  output                              ar_ready_o_1,
  input                               ar_valid_i_1,
  input [AXI_ADDR_WIDTH-1:0]          ar_addr_i_1,
  input [2:0]                         ar_prot_i_1,
  input [AXI_ID_WIDTH-1:0]            ar_id_i_1,
  input [AXI_USER_WIDTH-1:0]          ar_user_i_1,
  input [7:0]                         ar_len_i_1,
  input [2:0]                         ar_size_i_1,
  input [1:0]                         ar_burst_i_1,
  input                               ar_lock_i_1,
  input [3:0]                         ar_cache_i_1,
  input [3:0]                         ar_qos_i_1,
  
  input                               r_ready_i_1,
  output                              r_valid_o_1,
  output  [1:0]                       r_resp_o_1,
  output  [AXI_DATA_WIDTH-1:0]        r_data_o_1,
  output                              r_last_o_1,
  output  [AXI_ID_WIDTH-1:0]          r_id_o_1,
  output  [AXI_USER_WIDTH-1:0]        r_user_o_1,
  
  // Advanced eXtensible Interface
  // 2x1 interconnect -> RAM
  input                               top_aw_ready_i,
  output                              top_aw_valid_o,
  output [AXI_ADDR_WIDTH-1:0]         top_aw_addr_o,
  output [2:0]                        top_aw_prot_o,
  output [AXI_ID_WIDTH-1:0]           top_aw_id_o,
  output [AXI_USER_WIDTH-1:0]         top_aw_user_o,
  output [7:0]                        top_aw_len_o,
  output [2:0]                        top_aw_size_o,
  output [1:0]                        top_aw_burst_o,
  output                              top_aw_lock_o,
  output [3:0]                        top_aw_cache_o,
  output [3:0]                        top_aw_qos_o,

  input                               top_w_ready_i,
  output                              top_w_valid_o,
  output [AXI_DATA_WIDTH-1:0]         top_w_data_o,
  output [AXI_DATA_WIDTH/8-1:0]       top_w_strb_o,
  output                              top_w_last_o,
  output [AXI_ID_WIDTH-1:0]           top_w_id_o,
  
  output                              top_b_ready_o,
  input                               top_b_valid_i,
  input  [1:0]                        top_b_resp_i,
  input  [AXI_ID_WIDTH-1:0]           top_b_id_i,
  input  [AXI_USER_WIDTH-1:0]         top_b_user_i,
  
  input                               top_ar_ready_i,
  output                              top_ar_valid_o,
  output [AXI_ADDR_WIDTH-1:0]         top_ar_addr_o,
  output [2:0]                        top_ar_prot_o,
  output [AXI_ID_WIDTH-1:0]           top_ar_id_o,
  output [AXI_USER_WIDTH-1:0]         top_ar_user_o,
  output [7:0]                        top_ar_len_o,
  output [2:0]                        top_ar_size_o,
  output [1:0]                        top_ar_burst_o,
  output                              top_ar_lock_o,
  output [3:0]                        top_ar_cache_o,
  output [3:0]                        top_ar_qos_o,
  
  output                              top_r_ready_o,
  input                               top_r_valid_i,
  input  [1:0]                        top_r_resp_i,
  input  [AXI_DATA_WIDTH-1:0]         top_r_data_i,
  input                               top_r_last_i,
  input  [AXI_ID_WIDTH-1:0]           top_r_id_i,
  input  [AXI_USER_WIDTH-1:0]         top_r_user_i
);
  
  wire r_finish_0 = top_r_valid_i && top_r_last_i && r_ready_i_0 && r_state_0;
  wire r_finish_1 = top_r_valid_i && top_r_last_i && r_ready_i_1 && r_state_1;
  wire w_finish_0 = top_b_valid_i && b_ready_i_0;
  wire w_finish_1 = top_b_valid_i && b_ready_i_1;
  
  // ------------------State Machine------------------
  parameter [1:0] STATE_IDLE  = 2'b00, STATE_0 = 2'b01, STATE_1 = 2'b10;
  
  // Write State Machine
  reg [1:0] w_state;
  
  // Current Stage
  always @(posedge clock) begin
    if (reset) begin
      w_state <= STATE_IDLE;
    end
    else begin
      w_state <= w_next_state;
    end
  end
  
  // Next Stage
  reg [1:0] w_next_state;
  always @(*) begin
    case (w_state)
      STATE_IDLE: begin
        if (aw_valid_i_0) begin
          w_next_state = STATE_0;
        end
        else if (aw_valid_i_1) begin
          w_next_state = STATE_1;
        end
        else begin
          w_next_state = STATE_IDLE;
        end
      end
      STATE_0: begin
        if (w_finish_0) begin
          w_next_state = STATE_IDLE;
        end
        else begin
          w_next_state = STATE_0;
        end
      end
      STATE_1: begin
        if (w_finish_0) begin
          w_next_state = STATE_IDLE;
        end
        else begin
          w_next_state = STATE_1;
        end
      end
      default: begin
        w_next_state = STATE_IDLE;
      end
    endcase
  end
  
  // Output of State Machine
  wire w_state_0 = w_state == STATE_0;
  wire w_state_1 = w_state == STATE_1;
  
  // to IF
  assign aw_ready_o_0  = w_state_0                   & top_aw_ready_i;
  assign w_ready_o_0   = w_state_0                   & top_w_ready_i;
  assign b_valid_o_0   = w_state_0                   & top_b_valid_i;
  assign b_resp_o_0    = {2{w_state_0}}              & top_b_resp_i;
  assign b_id_o_0      = {AXI_ID_WIDTH{w_state_0}}   & top_b_id_i;
  assign b_user_o_0    = {AXI_USER_WIDTH{w_state_0}} & top_b_user_i;
  
  // to MEM
  assign aw_ready_o_1  = w_state_1                   & top_aw_ready_i;
  assign w_ready_o_1   = w_state_1                   & top_w_ready_i;
  assign b_valid_o_1   = w_state_1                   & top_b_valid_i;
  assign b_resp_o_1    = {2{w_state_1}}              & top_b_resp_i;
  assign b_id_o_1      = {AXI_ID_WIDTH{w_state_1}}   & top_b_id_i;
  assign b_user_o_1    = {AXI_USER_WIDTH{w_state_1}} & top_b_user_i;
  
  // to RAM
  assign top_aw_valid_o = (
      (w_state_0 & aw_valid_i_0) 
    | (w_state_1 & aw_valid_i_1)
  );
  assign top_aw_addr_o = (
      ({AXI_ADDR_WIDTH{w_state_0}} & aw_addr_i_0) 
    | ({AXI_ADDR_WIDTH{w_state_1}} & aw_addr_i_1)
  );
  assign top_aw_prot_o = (
      ({3{w_state_0}} & aw_prot_i_0) 
    | ({3{w_state_1}} & aw_prot_i_1)
  );
  assign top_aw_id_o = (
      ({AXI_ID_WIDTH{w_state_0}} & aw_id_i_0) 
    | ({AXI_ID_WIDTH{w_state_1}} & aw_id_i_1)
  );
  assign top_aw_user_o = (
      ({AXI_USER_WIDTH{w_state_0}} & aw_user_i_0) 
    | ({AXI_USER_WIDTH{w_state_1}} & aw_user_i_1)
  );
  assign top_aw_len_o = (
      ({8{w_state_0}} & aw_len_i_0) 
    | ({8{w_state_1}} & aw_len_i_1)
  );
  assign top_aw_size_o = (
      ({3{w_state_0}} & aw_size_i_0) 
    | ({3{w_state_1}} & aw_size_i_1)
  );
  assign top_aw_burst_o = (
      ({2{w_state_0}} & aw_burst_i_0) 
    | ({2{w_state_1}} & aw_burst_i_1)
  );
  assign top_aw_lock_o = (
      (w_state_0 & aw_lock_i_0) 
    | (w_state_1 & aw_lock_i_1)
  );
  assign top_aw_cache_o = (
      ({4{w_state_0}} & aw_cache_i_0) 
    | ({4{w_state_1}} & aw_cache_i_1)
  );
  assign top_aw_qos_o = (
      ({4{w_state_0}} & aw_qos_i_0) 
    | ({4{w_state_1}} & aw_qos_i_1)
  );

  assign top_w_valid_o = (
      (w_state_0 & w_valid_i_0) 
    | (w_state_1 & w_valid_i_1)
  );
  assign top_w_data_o =(
      ({AXI_DATA_WIDTH{w_state_0}} & w_data_i_0) 
    | ({AXI_DATA_WIDTH{w_state_1}} & w_data_i_1)
  );
  assign top_w_strb_o = (
      ({8{w_state_0}} & w_strb_i_0) 
    | ({8{w_state_1}} & w_strb_i_1)
  );
  assign top_w_last_o = (
      (w_state_0 & w_last_i_0) 
    | (w_state_1 & w_last_i_1)
  );
  assign top_w_id_o = (
      ({AXI_ID_WIDTH{w_state_0}} & w_id_i_0) 
    | ({AXI_ID_WIDTH{w_state_1}} & w_id_i_1)
  );
  
  assign top_b_ready_o = (
      (w_state_0 & b_ready_i_0) 
    | (w_state_1 & b_ready_i_1)
  );

  // Read State Machine
  reg [1:0] r_state;
  
  // Current Stage
  always @(posedge clock) begin
    if (reset) begin
      r_state <= STATE_IDLE;
    end
    else begin
      r_state <= r_next_state;
    end
  end
  
  // Next Stage
  reg [1:0] r_next_state;
  always @(*) begin
    case (r_state)
      STATE_IDLE: begin
        if (ar_valid_i_0) begin
          r_next_state = STATE_0;
        end
        else if (ar_valid_i_1) begin
          r_next_state = STATE_1;
        end
        else begin
          r_next_state = STATE_IDLE;
        end
      end
      STATE_0: begin
        if (r_finish_0) begin
          r_next_state = STATE_IDLE;
        end
        else begin
          r_next_state = STATE_0;
        end
      end
      STATE_1: begin
        if (r_finish_1) begin
          r_next_state = STATE_IDLE;
        end
        else begin
          r_next_state = STATE_1;
        end
      end
      default: begin
        r_next_state = STATE_IDLE;
      end
    endcase
  end

  // Output of State Machine

  wire r_state_0 = r_state == STATE_0;
  wire r_state_1 = r_state == STATE_1;
  
  // to IF
  assign ar_ready_o_0  = r_state_0                    & top_ar_ready_i;
  assign r_valid_o_0   = r_state_0                    & top_r_valid_i;
  assign r_resp_o_0    = {2{r_state_0}}               & top_r_resp_i;
  assign r_data_o_0    = {AXI_DATA_WIDTH{r_state_0}}  & top_r_resp_i;
  assign r_last_o_0    = r_state_0                    & top_r_last_i;
  assign r_id_o_0      = {AXI_ID_WIDTH{r_state_0}}    & top_r_id_i;
  assign r_user_o_0    = {AXI_USER_WIDTH{r_state_0}}  & top_r_user_i;
  
  // to MEM
  assign ar_ready_o_1 = r_state_1                   & top_ar_ready_i;
  assign r_valid_o_1  = r_state_1                   & top_r_valid_i;
  assign r_resp_o_1   = {2{r_state_1}}              & top_r_resp_i;
  assign r_data_o_1   = {AXI_DATA_WIDTH{r_state_1}} & top_r_resp_i;
  assign r_last_o_1   = r_state_1                   & top_r_last_i;
  assign r_id_o_1     = {AXI_ID_WIDTH{r_state_1}}   & top_r_id_i;
  assign r_user_o_1   = {AXI_USER_WIDTH{r_state_1}} & top_r_user_i;
  
  // to RAM
  assign top_ar_valid_o = (
      (r_state_0 & ar_valid_i_0) 
    | (r_state_1 & ar_valid_i_1)
  );
  assign top_ar_addr_o = (
      ({AXI_ADDR_WIDTH{r_state_0}} & ar_addr_i_0) 
    | ({AXI_ADDR_WIDTH{r_state_1}} & ar_addr_i_1)
  );
  assign top_ar_prot_o = (
      ({3{r_state_0}} & ar_prot_i_0) 
    | ({3{r_state_1}} & ar_prot_i_1)
  );
  assign top_ar_id_o = (
      ({AXI_ID_WIDTH{r_state_0}} & ar_id_i_0) 
    | ({AXI_ID_WIDTH{r_state_1}} & ar_id_i_1)
  );
  assign top_ar_user_o = (
      ({AXI_USER_WIDTH{r_state_0}} & ar_user_i_0) 
    | ({AXI_USER_WIDTH{r_state_1}} & ar_user_i_1)
  );
  assign top_ar_len_o = (
      ({8{r_state_0}} & ar_len_i_0) 
    | ({8{r_state_1}} & ar_len_i_1)
  );
  assign top_ar_size_o = (
      ({3{r_state_0}} & ar_size_i_0) 
    | ({3{r_state_1}} & ar_size_i_1)
  );
  assign top_ar_burst_o = (
      ({2{r_state_0}} & ar_burst_i_0) 
    | ({2{r_state_1}} & ar_burst_i_1)
  );
  assign top_ar_lock_o = (
      (r_state_0 & ar_addr_i_0) 
    | (r_state_1 & ar_addr_i_1)
  );
  assign top_ar_cache_o = (
      ({4{r_state_0}} & ar_addr_i_0) 
    | ({4{r_state_1}} & ar_addr_i_1)
  );
  assign top_ar_qos_o = (
      ({4{r_state_0}} & ar_qos_i_0) 
    | ({4{r_state_1}} & ar_qos_i_1)
  );
    
  assign top_r_ready_o = (
      (r_state_0 & ar_user_i_0) 
    | (r_state_1 & ar_user_i_1)
  );
  
endmodule