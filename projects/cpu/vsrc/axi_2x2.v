
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

module axi_2x2 # (
  parameter RW_DATA_WIDTH     = 64,
  parameter RW_ADDR_WIDTH     = 64,
  parameter AXI_DATA_WIDTH    = 64,
  parameter AXI_ADDR_WIDTH    = 64,
  parameter AXI_ID_WIDTH      = 4,
  parameter AXI_USER_WIDTH    = 1
)(
  input  wire               clock,
  input  wire               reset,

  // Advanced eXtensible Interface
  // mem stage (master) -> 2x2 interconnect (slave)
  // id: 0001
  output wire                             aw_ready_o_0,
  input  wire                             aw_valid_i_0,
  input  wire [AXI_ADDR_WIDTH-1:0]        aw_addr_i_0,
  input  wire [2:0]                       aw_prot_i_0,
  input  wire [AXI_ID_WIDTH-1:0]          aw_id_i_0,
  input  wire [AXI_USER_WIDTH-1:0]        aw_user_i_0,
  input  wire [7:0]                       aw_len_i_0,
  input  wire [2:0]                       aw_size_i_0,
  input  wire [1:0]                       aw_burst_i_0,
  input  wire                             aw_lock_i_0,
  input  wire [3:0]                       aw_cache_i_0,
  input  wire [3:0]                       aw_qos_i_0,
  
  output wire                             w_ready_o_0,
  input  wire                             w_valid_i_0,
  input  wire [AXI_DATA_WIDTH-1:0]        w_data_i_0,
  input  wire [AXI_DATA_WIDTH/8-1:0]      w_strb_i_0,
  input  wire                             w_last_i_0,
  input  wire [AXI_ID_WIDTH-1:0]          w_id_i_0,
   
  input  wire                             b_ready_i_0,
  output wire                             b_valid_o_0,
  output wire [1:0]                       b_resp_o_0,
  output wire [AXI_ID_WIDTH-1:0]          b_id_o_0,
  output wire [AXI_USER_WIDTH-1:0]        b_user_o_0,
  
  output wire                             ar_ready_o_0,
  input  wire                             ar_valid_i_0,
  input  wire [AXI_ADDR_WIDTH-1:0]        ar_addr_i_0,
  input  wire [2:0]                       ar_prot_i_0,
  input  wire [AXI_ID_WIDTH-1:0]          ar_id_i_0,
  input  wire [AXI_USER_WIDTH-1:0]        ar_user_i_0,
  input  wire [7:0]                       ar_len_i_0,
  input  wire [2:0]                       ar_size_i_0,
  input  wire [1:0]                       ar_burst_i_0,
  input  wire                             ar_lock_i_0,
  input  wire [3:0]                       ar_cache_i_0,
  input  wire [3:0]                       ar_qos_i_0,
  
  input  wire                             r_ready_i_0,
  output wire                             r_valid_o_0,
  output wire [1:0]                       r_resp_o_0,
  output wire [AXI_DATA_WIDTH-1:0]        r_data_o_0,
  output wire                             r_last_o_0,
  output wire [AXI_ID_WIDTH-1:0]          r_id_o_0,
  output wire [AXI_USER_WIDTH-1:0]        r_user_o_0,

  // Advanced eXtensible Interface
  // if stage (master) -> 2x2 interconnect (slave)
  // id: 0000
  output wire                             aw_ready_o_1,
  input  wire                             aw_valid_i_1,
  input  wire [AXI_ADDR_WIDTH-1:0]        aw_addr_i_1,
  input  wire [2:0]                       aw_prot_i_1,
  input  wire [AXI_ID_WIDTH-1:0]          aw_id_i_1,
  input  wire [AXI_USER_WIDTH-1:0]        aw_user_i_1,
  input  wire [7:0]                       aw_len_i_1,
  input  wire [2:0]                       aw_size_i_1,
  input  wire [1:0]                       aw_burst_i_1,
  input  wire                             aw_lock_i_1,
  input  wire [3:0]                       aw_cache_i_1,
  input  wire [3:0]                       aw_qos_i_1,
  
  output wire                             w_ready_o_1,
  input  wire                             w_valid_i_1,
  input  wire [AXI_DATA_WIDTH-1:0]        w_data_i_1,
  input  wire [AXI_DATA_WIDTH/8-1:0]      w_strb_i_1,
  input  wire                             w_last_i_1,
  input  wire [AXI_ID_WIDTH-1:0]          w_id_i_1,
  
  input  wire                             b_ready_i_1,
  output wire                             b_valid_o_1,
  output wire [1:0]                       b_resp_o_1,
  output wire [AXI_ID_WIDTH-1:0]          b_id_o_1,
  output wire [AXI_USER_WIDTH-1:0]        b_user_o_1,
  
  output wire                             ar_ready_o_1,
  input  wire                             ar_valid_i_1,
  input  wire [AXI_ADDR_WIDTH-1:0]        ar_addr_i_1,
  input  wire [2:0]                       ar_prot_i_1,
  input  wire [AXI_ID_WIDTH-1:0]          ar_id_i_1,
  input  wire [AXI_USER_WIDTH-1:0]        ar_user_i_1,
  input  wire [7:0]                       ar_len_i_1,
  input  wire [2:0]                       ar_size_i_1,
  input  wire [1:0]                       ar_burst_i_1,
  input  wire                             ar_lock_i_1,
  input  wire [3:0]                       ar_cache_i_1,
  input  wire [3:0]                       ar_qos_i_1,
  
  input  wire                             r_ready_i_1,
  output wire                             r_valid_o_1,
  output wire [1:0]                       r_resp_o_1,
  output wire [AXI_DATA_WIDTH-1:0]        r_data_o_1,
  output wire                             r_last_o_1,
  output wire [AXI_ID_WIDTH-1:0]          r_id_o_1,
  output wire [AXI_USER_WIDTH-1:0]        r_user_o_1,
  
  // Advanced eXtensible Interface
  // 2x2 interconnect -> RAM
  input  wire                             ram_aw_ready_i,
  output wire                             ram_aw_valid_o,
  output wire [AXI_ADDR_WIDTH-1:0]        ram_aw_addr_o,
  output wire [2:0]                       ram_aw_prot_o,
  output wire [AXI_ID_WIDTH-1:0]          ram_aw_id_o,
  output wire [AXI_USER_WIDTH-1:0]        ram_aw_user_o,
  output wire [7:0]                       ram_aw_len_o,
  output wire [2:0]                       ram_aw_size_o,
  output wire [1:0]                       ram_aw_burst_o,
  output wire                             ram_aw_lock_o,
  output wire [3:0]                       ram_aw_cache_o,
  output wire [3:0]                       ram_aw_qos_o,
  
  input  wire                             ram_w_ready_i,
  output wire                             ram_w_valid_o,
  output wire [AXI_DATA_WIDTH-1:0]        ram_w_data_o,
  output wire [AXI_DATA_WIDTH/8-1:0]      ram_w_strb_o,
  output wire                             ram_w_last_o,
  output wire [AXI_ID_WIDTH-1:0]          ram_w_id_o,
  
  output wire                             ram_b_ready_o,
  input  wire                             ram_b_valid_i,
  input  wire [1:0]                       ram_b_resp_i,
  input  wire [AXI_ID_WIDTH-1:0]          ram_b_id_i,
  input  wire [AXI_USER_WIDTH-1:0]        ram_b_user_i,
  
  input  wire                             ram_ar_ready_i,
  output wire                             ram_ar_valid_o,
  output wire [AXI_ADDR_WIDTH-1:0]        ram_ar_addr_o,
  output wire [2:0]                       ram_ar_prot_o,
  output wire [AXI_ID_WIDTH-1:0]          ram_ar_id_o,
  output wire [AXI_USER_WIDTH-1:0]        ram_ar_user_o,
  output wire [7:0]                       ram_ar_len_o,
  output wire [2:0]                       ram_ar_size_o,
  output wire [1:0]                       ram_ar_burst_o,
  output wire                             ram_ar_lock_o,
  output wire [3:0]                       ram_ar_cache_o,
  output wire [3:0]                       ram_ar_qos_o,
  
  output wire                             ram_r_ready_o,
  input  wire                             ram_r_valid_i,
  input  wire [1:0]                       ram_r_resp_i,
  input  wire [AXI_DATA_WIDTH-1:0]        ram_r_data_i,
  input  wire                             ram_r_last_i,
  input  wire [AXI_ID_WIDTH-1:0]          ram_r_id_i,
  input  wire [AXI_USER_WIDTH-1:0]        ram_r_user_i,
  
  // 2x2 interconnect -> CLINT
  input  wire                             cli_aw_ready_i,
  output wire                             cli_aw_valid_o,
  output wire [AXI_ADDR_WIDTH-1:0]        cli_aw_addr_o,
  output wire [2:0]                       cli_aw_prot_o,
  output wire [AXI_ID_WIDTH-1:0]          cli_aw_id_o,
  output wire [AXI_USER_WIDTH-1:0]        cli_aw_user_o,
  output wire [7:0]                       cli_aw_len_o,
  output wire [2:0]                       cli_aw_size_o,
  output wire [1:0]                       cli_aw_burst_o,
  output wire                             cli_aw_lock_o,
  output wire [3:0]                       cli_aw_cache_o,
  output wire [3:0]                       cli_aw_qos_o,
  
  input  wire                             cli_w_ready_i,
  output wire                             cli_w_valid_o,
  output wire [AXI_DATA_WIDTH-1:0]        cli_w_data_o,
  output wire [AXI_DATA_WIDTH/8-1:0]      cli_w_strb_o,
  output wire                             cli_w_last_o,
  output wire [AXI_ID_WIDTH-1:0]          cli_w_id_o,
  
  output wire                             cli_b_ready_o,
  input  wire                             cli_b_valid_i,
  input  wire [1:0]                       cli_b_resp_i,
  input  wire [AXI_ID_WIDTH-1:0]          cli_b_id_i,
  input  wire [AXI_USER_WIDTH-1:0]        cli_b_user_i,
  
  input  wire                             cli_ar_ready_i,
  output wire                             cli_ar_valid_o,
  output wire [AXI_ADDR_WIDTH-1:0]        cli_ar_addr_o,
  output wire [2:0]                       cli_ar_prot_o,
  output wire [AXI_ID_WIDTH-1:0]          cli_ar_id_o,
  output wire [AXI_USER_WIDTH-1:0]        cli_ar_user_o,
  output wire [7:0]                       cli_ar_len_o,
  output wire [2:0]                       cli_ar_size_o,
  output wire [1:0]                       cli_ar_burst_o,
  output wire                             cli_ar_lock_o,
  output wire [3:0]                       cli_ar_cache_o,
  output wire [3:0]                       cli_ar_qos_o,
  
  output wire                             cli_r_ready_o,
  input  wire                             cli_r_valid_i,
  input  wire [1:0]                       cli_r_resp_i,
  input  wire [AXI_DATA_WIDTH-1:0]        cli_r_data_i,
  input  wire                             cli_r_last_i,
  input  wire [AXI_ID_WIDTH-1:0]          cli_r_id_i,
  input  wire [AXI_USER_WIDTH-1:0]        cli_r_user_i
);

  // bridge between master and slave
  wire                             mid_aw_ready;
  wire                             mid_aw_valid;
  wire [AXI_ADDR_WIDTH-1:0]        mid_aw_addr;
  wire [2:0]                       mid_aw_prot;
  wire [AXI_ID_WIDTH-1:0]          mid_aw_id;
  wire [AXI_USER_WIDTH-1:0]        mid_aw_user;
  wire [7:0]                       mid_aw_len;
  wire [2:0]                       mid_aw_size;
  wire [1:0]                       mid_aw_burst;
  wire                             mid_aw_lock;
  wire [3:0]                       mid_aw_cache;
  wire [3:0]                       mid_aw_qos;
  
  wire                             mid_w_ready;
  wire                             mid_w_valid;
  wire [AXI_DATA_WIDTH-1:0]        mid_w_data;
  wire [AXI_DATA_WIDTH/8-1:0]      mid_w_strb;
  wire                             mid_w_last;
  wire [AXI_ID_WIDTH-1:0]          mid_w_id;
  
  wire                             mid_b_ready;
  wire                             mid_b_valid;
  wire [1:0]                       mid_b_resp;
  wire [AXI_ID_WIDTH-1:0]          mid_b_id;
  wire [AXI_USER_WIDTH-1:0]        mid_b_user;
  
  wire                             mid_ar_ready;
  wire                             mid_ar_valid;
  wire [AXI_ADDR_WIDTH-1:0]        mid_ar_addr;
  wire [2:0]                       mid_ar_prot;
  wire [AXI_ID_WIDTH-1:0]          mid_ar_id;
  wire [AXI_USER_WIDTH-1:0]        mid_ar_user;
  wire [7:0]                       mid_ar_len;
  wire [2:0]                       mid_ar_size;
  wire [1:0]                       mid_ar_burst;
  wire                             mid_ar_lock;
  wire [3:0]                       mid_ar_cache;
  wire [3:0]                       mid_ar_qos;
  
  wire                             mid_r_ready;
  wire                             mid_r_valid;
  wire [1:0]                       mid_r_resp;
  wire [AXI_DATA_WIDTH-1:0]        mid_r_data;
  wire                             mid_r_last;
  wire [AXI_ID_WIDTH-1:0]          mid_r_id;
  wire [AXI_USER_WIDTH-1:0]        mid_r_user;

  wire r_finish_0 = mid_r_valid && r_ready_i_0 && mid_r_last && r_state_0;
  wire r_finish_1 = mid_r_valid && r_ready_i_1 && mid_r_last && r_state_1;
  wire r_finish_cli = mid_r_ready && cli_r_valid_i && cli_r_last_i && r_state_cli;
  wire r_finish_ram = mid_r_ready && ram_r_valid_i && ram_r_last_i && r_state_ram;
  wire w_finish_0 = mid_b_valid && b_ready_i_0 && w_state_0;
  wire w_finish_1 = mid_b_valid && b_ready_i_1 && w_state_1;
  wire w_finish_cli = mid_b_ready && cli_b_valid_i && w_state_cli;
  wire w_finish_ram = mid_b_ready && ram_b_valid_i && w_state_ram;

  // ------------------State Machine------------------
  parameter [1:0] STATE_IDLE  = 2'b00;
  // master state
  parameter [1:0] STATE_0 = 2'b01, STATE_1 = 2'b10;
  // slave state
  parameter [1:0] STATE_CLINT = 2'b01, STATE_RAM = 2'b10;
  
  // Write State Machine
  // Master
  reg [1:0] master_w_state, slave_w_state;
  wire w_0_to_cli = ~w_0_to_ram;
  wire w_0_to_ram = aw_addr_i_0[63:16] != 48'h00000000_0200;
  wire w_1_to_cli = ~w_1_to_ram;
  wire w_1_to_ram = aw_addr_i_1[63:16] != 48'h00000000_0200;
  
  // Current Stage
  always @(posedge clock) begin
    if (reset) begin
      master_w_state <= STATE_IDLE;
      slave_w_state <= STATE_IDLE;
    end
    else begin
      master_w_state <= master_w_next_state;
      slave_w_state <= slave_w_next_state;
    end
  end
  
  // Next Stage
  reg [1:0] master_w_next_state, slave_w_next_state;
  always @(*) begin
    // master side
    case (master_w_state)
      STATE_IDLE: begin
        if (aw_valid_i_0) begin
          master_w_next_state = STATE_0;
        end
        else if (aw_valid_i_1) begin
          master_w_next_state = STATE_1;
        end
        else begin
          master_w_next_state = STATE_IDLE;
        end
      end
      STATE_0: begin
        if (w_finish_0) begin
          master_w_next_state = STATE_IDLE;
        end
        else begin
          master_w_next_state = STATE_0;
        end
      end
      STATE_1: begin
        if (w_finish_1) begin
          master_w_next_state = STATE_IDLE;
        end
        else begin
          master_w_next_state = STATE_1;
        end
      end
      default: begin
        master_w_next_state = STATE_IDLE;
      end
    endcase

    // slave side
    case (slave_w_state)
      STATE_IDLE: begin
        if (master_w_next_state == STATE_0) begin
          slave_w_next_state = w_0_to_ram ? STATE_RAM : STATE_CLINT;
        end
        else if (master_w_next_state == STATE_1) begin
          slave_w_next_state = w_1_to_ram ? STATE_RAM : STATE_CLINT;
        end
        else begin
          slave_w_next_state = STATE_IDLE;
        end
      end
      STATE_CLINT: begin
        if (w_finish_cli) begin
          slave_w_next_state = STATE_IDLE;
        end
        else begin
          slave_w_next_state = STATE_CLINT;
        end
      end
      STATE_RAM: begin
        if (w_finish_ram) begin
          slave_w_next_state = STATE_IDLE;
        end
        else begin
          slave_w_next_state = STATE_RAM;
        end
      end
      default: begin
        slave_w_next_state = STATE_IDLE;
      end
    endcase
  end
  
  // Read State Machine
  reg [1:0] master_r_state, slave_r_state;
  wire r_0_to_cli = ~r_0_to_ram;
  wire r_0_to_ram = ar_addr_i_0[63:16] != 48'h00000000_0200;
  wire r_1_to_cli = ~r_1_to_ram;
  wire r_1_to_ram = ar_addr_i_1[63:16] != 48'h00000000_0200;

  // Current Stage
  always @(posedge clock) begin
    if (reset) begin
      master_r_state <= STATE_IDLE;
      slave_r_state <= STATE_IDLE;
    end
    else begin
      master_r_state <= master_r_next_state;
      slave_r_state <= slave_r_next_state;
    end
  end
  
  // Next Stage
  reg [1:0] master_r_next_state, slave_r_next_state;
  always @(*) begin
    // master side
    case (master_r_state)
      STATE_IDLE: begin
        if (ar_valid_i_0) begin
          master_r_next_state = STATE_0;
        end
        else if (ar_valid_i_1) begin
          master_r_next_state = STATE_1;
        end
        else begin
          master_r_next_state = STATE_IDLE;
        end
      end
      STATE_0: begin
        if (r_finish_0) begin
          master_r_next_state = STATE_IDLE;
        end
        else begin
          master_r_next_state = STATE_0;
        end
      end
      STATE_1: begin
        if (r_finish_1) begin
          master_r_next_state = STATE_IDLE;
        end
        else begin
          master_r_next_state = STATE_1;
        end
      end
      default: begin
        master_r_next_state = STATE_IDLE;
      end
    endcase

    // slave side
    case (slave_r_state)
      STATE_IDLE: begin
        if (master_r_next_state == STATE_0) begin
          slave_r_next_state = r_0_to_ram ? STATE_RAM : STATE_CLINT;
        end
        else if (master_r_next_state == STATE_1) begin
          slave_r_next_state = r_1_to_ram ? STATE_RAM : STATE_CLINT;
        end
        else begin
          slave_r_next_state = STATE_IDLE;
        end
      end
      STATE_CLINT: begin
        if (r_finish_cli) begin
          slave_r_next_state = STATE_IDLE;
        end
        else begin
          slave_r_next_state = STATE_CLINT;
        end
      end
      STATE_RAM: begin
        if (r_finish_ram) begin
          slave_r_next_state = STATE_IDLE;
        end
        else begin
          slave_r_next_state = STATE_RAM;
        end
      end
      default: begin
        slave_r_next_state = STATE_IDLE;
      end
    endcase
  end
  
  // Write Output
  wire w_state_0 = (master_w_state == STATE_0);
  wire w_state_1 = (master_w_state == STATE_1);
  wire w_state_cli = (slave_w_state == STATE_CLINT);
  wire w_state_ram = (slave_w_state == STATE_RAM);
  
  // master side
  // to MEM
  assign aw_ready_o_0  = w_state_0                   & mid_aw_ready;
  assign w_ready_o_0   = w_state_0                   & mid_w_ready;
  assign b_valid_o_0   = w_state_0                   & mid_b_valid;
  assign b_resp_o_0    = {2{w_state_0}}              & mid_b_resp;
  assign b_id_o_0      = {AXI_ID_WIDTH{w_state_0}}   & mid_b_id;
  assign b_user_o_0    = {AXI_USER_WIDTH{w_state_0}} & mid_b_user;
  
  // to IF
  assign aw_ready_o_1  = w_state_1                   & mid_aw_ready;
  assign w_ready_o_1   = w_state_1                   & mid_w_ready;
  assign b_valid_o_1   = w_state_1                   & mid_b_valid;
  assign b_resp_o_1    = {2{w_state_1}}              & mid_b_resp;
  assign b_id_o_1      = {AXI_ID_WIDTH{w_state_1}}   & mid_b_id;
  assign b_user_o_1    = {AXI_USER_WIDTH{w_state_1}} & mid_b_user;

  // bridge side
  assign mid_aw_ready = (
      (w_state_cli & cli_aw_ready_i)
    | (w_state_ram & ram_aw_ready_i)
  );
  assign mid_aw_valid = (
      (w_state_0 & aw_valid_i_0) 
    | (w_state_1 & aw_valid_i_1)
  );
  assign mid_aw_addr = (
      ({AXI_ADDR_WIDTH{w_state_0}} & aw_addr_i_0) 
    | ({AXI_ADDR_WIDTH{w_state_1}} & aw_addr_i_1)
  );
  assign mid_aw_prot = (
      ({3{w_state_0}} & aw_prot_i_0) 
    | ({3{w_state_1}} & aw_prot_i_1)
  );
  assign mid_aw_id = (
      ({AXI_ID_WIDTH{w_state_0}} & aw_id_i_0) 
    | ({AXI_ID_WIDTH{w_state_1}} & aw_id_i_1)
  );
  assign mid_aw_user = (
      ({AXI_USER_WIDTH{w_state_0}} & aw_user_i_0) 
    | ({AXI_USER_WIDTH{w_state_1}} & aw_user_i_1)
  );
  assign mid_aw_len = (
      ({8{w_state_0}} & aw_len_i_0) 
    | ({8{w_state_1}} & aw_len_i_1)
  );
  assign mid_aw_size = (
      ({3{w_state_0}} & aw_size_i_0) 
    | ({3{w_state_1}} & aw_size_i_1)
  );
  assign mid_aw_burst = (
      ({2{w_state_0}} & aw_burst_i_0) 
    | ({2{w_state_1}} & aw_burst_i_1)
  );
  assign mid_aw_lock = (
      (w_state_0 & aw_lock_i_0) 
    | (w_state_1 & aw_lock_i_1)
  );
  assign mid_aw_cache = (
      ({4{w_state_0}} & aw_cache_i_0) 
    | ({4{w_state_1}} & aw_cache_i_1)
  );
  assign mid_aw_qos = (
      ({4{w_state_0}} & aw_qos_i_0) 
    | ({4{w_state_1}} & aw_qos_i_1)
  );
  
  assign mid_w_ready = (
      (w_state_cli & cli_w_ready_i)
    | (w_state_ram & ram_w_ready_i)
  );
  assign mid_w_valid = (
      (w_state_0 & w_valid_i_0) 
    | (w_state_1 & w_valid_i_1)
  );
  assign mid_w_data =(
      ({AXI_DATA_WIDTH{w_state_0}} & w_data_i_0) 
    | ({AXI_DATA_WIDTH{w_state_1}} & w_data_i_1)
  );
  assign mid_w_strb = (
      ({8{w_state_0}} & w_strb_i_0) 
    | ({8{w_state_1}} & w_strb_i_1)
  );
  assign mid_w_last = (
      (w_state_0 & w_last_i_0) 
    | (w_state_1 & w_last_i_1)
  );
  assign mid_w_id = (
      ({AXI_ID_WIDTH{w_state_0}} & w_id_i_0) 
    | ({AXI_ID_WIDTH{w_state_1}} & w_id_i_1)
  );
  
  assign mid_b_ready = (
      (w_state_0 & b_ready_i_0) 
    | (w_state_1 & b_ready_i_1)
  );
  assign mid_b_valid = (
      (w_state_cli & cli_b_valid_i)
    | (w_state_ram & ram_b_valid_i)
  );
  assign mid_b_resp = (
      ({2{w_state_cli}} & cli_b_resp_i)
    | ({2{w_state_ram}} & ram_b_resp_i)
  );
  assign mid_b_id = (
      ({AXI_ID_WIDTH{w_state_cli}} & cli_b_id_i)
    | ({AXI_ID_WIDTH{w_state_ram}} & ram_b_id_i)
  );
  assign mid_b_user = (
      ({AXI_USER_WIDTH{w_state_cli}} & cli_b_user_i)
    | ({AXI_USER_WIDTH{w_state_ram}} & ram_b_user_i)
  );
  
  // slave side
  assign ram_aw_valid_o = w_state_ram & mid_aw_valid;
  assign ram_aw_addr_o = {AXI_ADDR_WIDTH{w_state_ram}} & mid_aw_addr;
  assign ram_aw_prot_o = {3{w_state_ram}} & mid_aw_prot;
  assign ram_aw_id_o = {AXI_ID_WIDTH{w_state_ram}} & mid_aw_id;
  assign ram_aw_user_o = {AXI_USER_WIDTH{w_state_ram}} & mid_aw_user;
  assign ram_aw_len_o = {8{w_state_ram}} & mid_aw_len;
  assign ram_aw_size_o = {3{w_state_ram}} & mid_aw_size;
  assign ram_aw_burst_o = {2{w_state_ram}} & mid_aw_burst;
  assign ram_aw_lock_o = w_state_ram & mid_aw_lock;
  assign ram_aw_cache_o = {4{w_state_ram}} & mid_aw_cache;
  assign ram_aw_qos_o = {4{w_state_ram}} & mid_aw_qos;
  
  assign ram_w_valid_o = w_state_ram & mid_w_valid;
  assign ram_w_data_o = {AXI_DATA_WIDTH{w_state_ram}} & mid_w_data;
  assign ram_w_strb_o = {AXI_DATA_WIDTH/8{w_state_ram}} & mid_w_strb;
  assign ram_w_last_o = w_state_ram & mid_w_last;
  assign ram_w_id_o = {AXI_ID_WIDTH{w_state_ram}} & mid_w_id;
  
  assign ram_b_ready_o = w_state_ram & mid_b_ready;

  assign cli_aw_valid_o = w_state_cli & mid_aw_valid;
  assign cli_aw_addr_o = {AXI_ADDR_WIDTH{w_state_cli}} & mid_aw_addr;
  assign cli_aw_prot_o = {3{w_state_cli}} & mid_aw_prot;
  assign cli_aw_id_o = {AXI_ID_WIDTH{w_state_cli}} & mid_aw_id;
  assign cli_aw_user_o = {AXI_USER_WIDTH{w_state_cli}} & mid_aw_user;
  assign cli_aw_len_o = {8{w_state_cli}} & mid_aw_len;
  assign cli_aw_size_o = {3{w_state_cli}} & mid_aw_size;
  assign cli_aw_burst_o = {2{w_state_cli}} & mid_aw_burst;
  assign cli_aw_lock_o = w_state_cli & mid_aw_lock;
  assign cli_aw_cache_o = {4{w_state_cli}} & mid_aw_cache;
  assign cli_aw_qos_o = {4{w_state_cli}} & mid_aw_qos;
  
  assign cli_w_valid_o = w_state_cli & mid_w_valid;
  assign cli_w_data_o = {AXI_DATA_WIDTH{w_state_cli}} & mid_w_data;
  assign cli_w_strb_o = {AXI_DATA_WIDTH/8{w_state_cli}} & mid_w_strb;
  assign cli_w_last_o = w_state_cli & mid_w_last;
  assign cli_w_id_o = {AXI_ID_WIDTH{w_state_cli}} & mid_w_id;
  
  assign cli_b_ready_o = r_state_cli & mid_b_ready;

  // Read Output
  wire r_state_0 = (master_r_state == STATE_0);
  wire r_state_1 = (master_r_state == STATE_1);
  wire r_state_cli = (slave_r_state == STATE_CLINT);
  wire r_state_ram = (slave_r_state == STATE_RAM);
  
  // master side
  // to MEM
  assign ar_ready_o_0  = r_state_0                    & mid_ar_ready;
  assign r_valid_o_0   = r_state_0                    & mid_r_valid;
  assign r_resp_o_0    = {2{r_state_0}}               & mid_r_resp;
  assign r_data_o_0    = {AXI_DATA_WIDTH{r_state_0}}  & mid_r_data;
  assign r_last_o_0    = r_state_0                    & mid_r_last;
  assign r_id_o_0      = {AXI_ID_WIDTH{r_state_0}}    & mid_r_id;
  assign r_user_o_0    = {AXI_USER_WIDTH{r_state_0}}  & mid_r_user;
  
  // to IF
  assign ar_ready_o_1  = r_state_1                    & mid_ar_ready;
  assign r_valid_o_1   = r_state_1                    & mid_r_valid;
  assign r_resp_o_1    = {2{r_state_1}}               & mid_r_resp;
  assign r_data_o_1    = {AXI_DATA_WIDTH{r_state_1}}  & mid_r_data;
  assign r_last_o_1    = r_state_1                    & mid_r_last;
  assign r_id_o_1      = {AXI_ID_WIDTH{r_state_1}}    & mid_r_id;
  assign r_user_o_1    = {AXI_USER_WIDTH{r_state_1}}  & mid_r_user;
  
  // bridge side
  assign mid_ar_ready = (
      (r_state_cli & cli_ar_ready_i)
    | (r_state_ram & ram_ar_ready_i)
  );
  assign mid_ar_valid = (
      (r_state_0 & ar_valid_i_0) 
    | (r_state_1 & ar_valid_i_1)
  );
  assign mid_ar_addr = (
      ({AXI_ADDR_WIDTH{r_state_0}} & ar_addr_i_0) 
    | ({AXI_ADDR_WIDTH{r_state_1}} & ar_addr_i_1)
  );
  assign mid_ar_prot = (
      ({3{r_state_0}} & ar_prot_i_0) 
    | ({3{r_state_1}} & ar_prot_i_1)
  );
  assign mid_ar_id = (
      ({AXI_ID_WIDTH{r_state_0}} & ar_id_i_0) 
    | ({AXI_ID_WIDTH{r_state_1}} & ar_id_i_1)
  );
  assign mid_ar_user = (
      ({AXI_USER_WIDTH{r_state_0}} & ar_user_i_0) 
    | ({AXI_USER_WIDTH{r_state_1}} & ar_user_i_1)
  );
  assign mid_ar_len = (
      ({8{r_state_0}} & ar_len_i_0) 
    | ({8{r_state_1}} & ar_len_i_1)
  );
  assign mid_ar_size = (
      ({3{r_state_0}} & ar_size_i_0) 
    | ({3{r_state_1}} & ar_size_i_1)
  );
  assign mid_ar_burst = (
      ({2{r_state_0}} & ar_burst_i_0) 
    | ({2{r_state_1}} & ar_burst_i_1)
  );
  assign mid_ar_lock = (
      (r_state_0 & ar_lock_i_0) 
    | (r_state_1 & ar_lock_i_1)
  );
  assign mid_ar_cache = (
      ({4{r_state_0}} & ar_cache_i_0) 
    | ({4{r_state_1}} & ar_cache_i_1)
  );
  assign mid_ar_qos = (
      ({4{r_state_0}} & ar_qos_i_0) 
    | ({4{r_state_1}} & ar_qos_i_1)
  );
    
  assign mid_r_ready = (
      (r_state_0 & r_ready_i_0) 
    | (r_state_1 & r_ready_i_1)
  );
  assign mid_r_valid = (
      (r_state_cli & cli_r_valid_i)
    | (r_state_ram & ram_r_valid_i)
  );
  assign mid_r_resp = (
      ({2{r_state_cli}} & cli_r_resp_i)
    | ({2{r_state_ram}} & ram_r_resp_i)
  );
  assign mid_r_data = (
      ({AXI_DATA_WIDTH{r_state_cli}} & cli_r_data_i)
    | ({AXI_DATA_WIDTH{r_state_ram}} & ram_r_data_i)
  );
  assign mid_r_last = (
      (r_state_cli & cli_r_last_i)
    | (r_state_ram & ram_r_last_i)
  );
  assign mid_r_id = (
      ({AXI_ID_WIDTH{r_state_cli}} & cli_r_id_i)
    | ({AXI_ID_WIDTH{r_state_ram}} & ram_r_id_i)
  );
  assign mid_r_user = (
      ({AXI_USER_WIDTH{r_state_cli}} & cli_r_user_i)
    | ({AXI_USER_WIDTH{r_state_ram}} & ram_r_user_i)
  );
  
  // slave side
  assign ram_ar_valid_o = r_state_ram & mid_ar_valid;
  assign ram_ar_addr_o = {AXI_ADDR_WIDTH{r_state_ram}} & mid_ar_addr;
  assign ram_ar_prot_o = {3{r_state_ram}} & mid_ar_prot;
  assign ram_ar_id_o = {AXI_ID_WIDTH{r_state_ram}} & mid_ar_id;
  assign ram_ar_user_o = {AXI_USER_WIDTH{r_state_ram}} & mid_ar_user;
  assign ram_ar_len_o = {8{r_state_ram}} & mid_ar_len;
  assign ram_ar_size_o = {3{r_state_ram}} & mid_ar_size;
  assign ram_ar_burst_o = {2{r_state_ram}} & mid_ar_burst;
  assign ram_ar_lock_o = r_state_ram & mid_ar_lock;
  assign ram_ar_cache_o = {4{r_state_ram}} & mid_ar_cache;
  assign ram_ar_qos_o = {4{r_state_ram}} & mid_ar_qos;
  
  assign ram_r_ready_o = r_state_ram & mid_r_ready;

  assign cli_ar_valid_o = r_state_cli & mid_ar_valid;
  assign cli_ar_addr_o = {AXI_ADDR_WIDTH{r_state_cli}} & mid_ar_addr;
  assign cli_ar_prot_o = {3{r_state_cli}} & mid_ar_prot;
  assign cli_ar_id_o = {AXI_ID_WIDTH{r_state_cli}} & mid_ar_id;
  assign cli_ar_user_o = {AXI_USER_WIDTH{r_state_cli}} & mid_ar_user;
  assign cli_ar_len_o = {8{r_state_cli}} & mid_ar_len;
  assign cli_ar_size_o = {3{r_state_cli}} & mid_ar_size;
  assign cli_ar_burst_o = {2{r_state_cli}} & mid_ar_burst;
  assign cli_ar_lock_o = r_state_cli & mid_ar_lock;
  assign cli_ar_cache_o = {4{r_state_cli}} & mid_ar_cache;
  assign cli_ar_qos_o = {4{r_state_cli}} & mid_ar_qos;
  
  assign cli_r_ready_o = r_state_cli & mid_r_ready;
endmodule