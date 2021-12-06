
`include "defines.v"
`define AXI_TOP_INTERFACE(name) io_memAXI_0_``name

module SimTop # (
  parameter RW_DATA_WIDTH     = 64,
  parameter RW_ADDR_WIDTH     = 64,
  parameter AXI_DATA_WIDTH    = 64,
  parameter AXI_ADDR_WIDTH    = 64,
  parameter AXI_ID_WIDTH      = 4,
  parameter AXI_USER_WIDTH    = 1
)(
  input                               clock,
  input                               reset,

  input  [63:0]                       io_logCtrl_log_begin,
  input  [63:0]                       io_logCtrl_log_end,
  input  [63:0]                       io_logCtrl_log_level,
  input                               io_perfInfo_clean,
  input                               io_perfInfo_dump,
  
  output                              io_uart_out_valid,
  output [7:0]                        io_uart_out_ch,
  output                              io_uart_in_valid,
  input  [7:0]                        io_uart_in_ch,

  input                               `AXI_TOP_INTERFACE(aw_ready),
  output                              `AXI_TOP_INTERFACE(aw_valid),
  output [`AXI_ADDR_WIDTH-1:0]        `AXI_TOP_INTERFACE(aw_bits_addr),
  output [2:0]                        `AXI_TOP_INTERFACE(aw_bits_prot),
  output [`AXI_ID_WIDTH-1:0]          `AXI_TOP_INTERFACE(aw_bits_id),
  output [`AXI_USER_WIDTH-1:0]        `AXI_TOP_INTERFACE(aw_bits_user),
  output [7:0]                        `AXI_TOP_INTERFACE(aw_bits_len),
  output [2:0]                        `AXI_TOP_INTERFACE(aw_bits_size),
  output [1:0]                        `AXI_TOP_INTERFACE(aw_bits_burst),
  output                              `AXI_TOP_INTERFACE(aw_bits_lock),
  output [3:0]                        `AXI_TOP_INTERFACE(aw_bits_cache),
  output [3:0]                        `AXI_TOP_INTERFACE(aw_bits_qos),

  input                               `AXI_TOP_INTERFACE(w_ready),
  output                              `AXI_TOP_INTERFACE(w_valid),
  output [`AXI_DATA_WIDTH-1:0]        `AXI_TOP_INTERFACE(w_bits_data)         [3:0],
  output [`AXI_DATA_WIDTH/8-1:0]      `AXI_TOP_INTERFACE(w_bits_strb),
  output                              `AXI_TOP_INTERFACE(w_bits_last),
  output [`AXI_ID_WIDTH-1:0]          `AXI_TOP_INTERFACE(w_bits_id),
  
  output                              `AXI_TOP_INTERFACE(b_ready),
  input                               `AXI_TOP_INTERFACE(b_valid),
  input  [1:0]                        `AXI_TOP_INTERFACE(b_bits_resp),
  input  [`AXI_ID_WIDTH-1:0]          `AXI_TOP_INTERFACE(b_bits_id),
  input  [`AXI_USER_WIDTH-1:0]        `AXI_TOP_INTERFACE(b_bits_user),

  input                               `AXI_TOP_INTERFACE(ar_ready),
  output                              `AXI_TOP_INTERFACE(ar_valid),
  output [`AXI_ADDR_WIDTH-1:0]        `AXI_TOP_INTERFACE(ar_bits_addr),
  output [2:0]                        `AXI_TOP_INTERFACE(ar_bits_prot),
  output [`AXI_ID_WIDTH-1:0]          `AXI_TOP_INTERFACE(ar_bits_id),
  output [`AXI_USER_WIDTH-1:0]        `AXI_TOP_INTERFACE(ar_bits_user),
  output [7:0]                        `AXI_TOP_INTERFACE(ar_bits_len),
  output [2:0]                        `AXI_TOP_INTERFACE(ar_bits_size),
  output [1:0]                        `AXI_TOP_INTERFACE(ar_bits_burst),
  output                              `AXI_TOP_INTERFACE(ar_bits_lock),
  output [3:0]                        `AXI_TOP_INTERFACE(ar_bits_cache),
  output [3:0]                        `AXI_TOP_INTERFACE(ar_bits_qos),
    
  output                              `AXI_TOP_INTERFACE(r_ready),
  input                               `AXI_TOP_INTERFACE(r_valid),
  input  [1:0]                        `AXI_TOP_INTERFACE(r_bits_resp),
  input  [`AXI_DATA_WIDTH-1:0]        `AXI_TOP_INTERFACE(r_bits_data)         [3:0],
  input                               `AXI_TOP_INTERFACE(r_bits_last),
  input  [`AXI_ID_WIDTH-1:0]          `AXI_TOP_INTERFACE(r_bits_id),
  input  [`AXI_USER_WIDTH-1:0]        `AXI_TOP_INTERFACE(r_bits_user)
);

  axi_2x2 axi_2x2(
    .clock                          (clock),
    .reset                          (reset),
    
    // MEM
    .aw_ready_o_0                   (mem_axi_aw_ready),
    .aw_valid_i_0                   (mem_axi_aw_valid),
    .aw_addr_i_0                    (mem_axi_aw_addr),
    .aw_prot_i_0                    (mem_axi_aw_prot),
    .aw_id_i_0                      (mem_axi_aw_id),
    .aw_user_i_0                    (mem_axi_aw_user),
    .aw_len_i_0                     (mem_axi_aw_len),
    .aw_size_i_0                    (mem_axi_aw_size),
    .aw_burst_i_0                   (mem_axi_aw_burst),
    .aw_lock_i_0                    (mem_axi_aw_lock),
    .aw_cache_i_0                   (mem_axi_aw_cache),
    .aw_qos_i_0                     (mem_axi_aw_qos),

    .w_ready_o_0                    (mem_axi_w_ready),
    .w_valid_i_0                    (mem_axi_w_valid),
    .w_data_i_0                     (mem_axi_w_data),
    .w_strb_i_0                     (mem_axi_w_strb),
    .w_last_i_0                     (mem_axi_w_last),
    .w_id_i_0                       (mem_axi_w_id),

    .b_ready_i_0                    (mem_axi_b_ready),
    .b_valid_o_0                    (mem_axi_b_valid),
    .b_resp_o_0                     (mem_axi_b_resp),
    .b_id_o_0                       (mem_axi_b_id),
    .b_user_o_0                     (mem_axi_b_user),

    .ar_ready_o_0                   (mem_axi_ar_ready),
    .ar_valid_i_0                   (mem_axi_ar_valid),
    .ar_addr_i_0                    (mem_axi_ar_addr),
    .ar_prot_i_0                    (mem_axi_ar_prot),
    .ar_id_i_0                      (mem_axi_ar_id),
    .ar_user_i_0                    (mem_axi_ar_user),
    .ar_len_i_0                     (mem_axi_ar_len),
    .ar_size_i_0                    (mem_axi_ar_size),
    .ar_burst_i_0                   (mem_axi_ar_burst),
    .ar_lock_i_0                    (mem_axi_ar_lock),
    .ar_cache_i_0                   (mem_axi_ar_cache),
    .ar_qos_i_0                     (mem_axi_ar_qos),

    .r_ready_i_0                    (mem_axi_r_ready),
    .r_valid_o_0                    (mem_axi_r_valid),
    .r_resp_o_0                     (mem_axi_r_resp),
    .r_data_o_0                     (mem_axi_r_data),
    .r_last_o_0                     (mem_axi_r_last),
    .r_id_o_0                       (mem_axi_r_id),
    .r_user_o_0                     (mem_axi_r_user),

    // IF
    .aw_ready_o_1                   (if_axi_aw_ready),
    .aw_valid_i_1                   (if_axi_aw_valid),
    .aw_addr_i_1                    (if_axi_aw_addr),
    .aw_prot_i_1                    (if_axi_aw_prot),
    .aw_id_i_1                      (if_axi_aw_id),
    .aw_user_i_1                    (if_axi_aw_user),
    .aw_len_i_1                     (if_axi_aw_len),
    .aw_size_i_1                    (if_axi_aw_size),
    .aw_burst_i_1                   (if_axi_aw_burst),
    .aw_lock_i_1                    (if_axi_aw_lock),
    .aw_cache_i_1                   (if_axi_aw_cache),
    .aw_qos_i_1                     (if_axi_aw_qos),

    .w_ready_o_1                    (if_axi_w_ready),
    .w_valid_i_1                    (if_axi_w_valid),
    .w_data_i_1                     (if_axi_w_data),
    .w_strb_i_1                     (if_axi_w_strb),
    .w_last_i_1                     (if_axi_w_last),
    .w_id_i_1                       (if_axi_w_id),

    .b_ready_i_1                    (if_axi_b_ready),
    .b_valid_o_1                    (if_axi_b_valid),
    .b_resp_o_1                     (if_axi_b_resp),
    .b_id_o_1                       (if_axi_b_id),
    .b_user_o_1                     (if_axi_b_user),

    .ar_ready_o_1                   (if_axi_ar_ready),
    .ar_valid_i_1                   (if_axi_ar_valid),
    .ar_addr_i_1                    (if_axi_ar_addr),
    .ar_prot_i_1                    (if_axi_ar_prot),
    .ar_id_i_1                      (if_axi_ar_id),
    .ar_user_i_1                    (if_axi_ar_user),
    .ar_len_i_1                     (if_axi_ar_len),
    .ar_size_i_1                    (if_axi_ar_size),
    .ar_burst_i_1                   (if_axi_ar_burst),
    .ar_lock_i_1                    (if_axi_ar_lock),
    .ar_cache_i_1                   (if_axi_ar_cache),
    .ar_qos_i_1                     (if_axi_ar_qos),

    .r_ready_i_1                    (if_axi_r_ready),
    .r_valid_o_1                    (if_axi_r_valid),
    .r_resp_o_1                     (if_axi_r_resp),
    .r_data_o_1                     (if_axi_r_data),
    .r_last_o_1                     (if_axi_r_last),
    .r_id_o_1                       (if_axi_r_id),
    .r_user_o_1                     (if_axi_r_user),
    
    // TOP INTERFACE
    .ram_aw_ready_i                 (`AXI_TOP_INTERFACE(aw_ready)),
    .ram_aw_valid_o                 (`AXI_TOP_INTERFACE(aw_valid)),
    .ram_aw_addr_o                  (`AXI_TOP_INTERFACE(aw_bits_addr)),
    .ram_aw_prot_o                  (`AXI_TOP_INTERFACE(aw_bits_prot)),
    .ram_aw_id_o                    (`AXI_TOP_INTERFACE(aw_bits_id)),
    .ram_aw_user_o                  (`AXI_TOP_INTERFACE(aw_bits_user)),
    .ram_aw_len_o                   (`AXI_TOP_INTERFACE(aw_bits_len)),
    .ram_aw_size_o                  (`AXI_TOP_INTERFACE(aw_bits_size)),
    .ram_aw_burst_o                 (`AXI_TOP_INTERFACE(aw_bits_burst)),
    .ram_aw_lock_o                  (`AXI_TOP_INTERFACE(aw_bits_lock)),
    .ram_aw_cache_o                 (`AXI_TOP_INTERFACE(aw_bits_cache)),
    .ram_aw_qos_o                   (`AXI_TOP_INTERFACE(aw_bits_qos)),

    .ram_w_ready_i                  (`AXI_TOP_INTERFACE(w_ready)),
    .ram_w_valid_o                  (`AXI_TOP_INTERFACE(w_valid)),
    .ram_w_data_o                   (`AXI_TOP_INTERFACE(w_bits_data)[0]),
    .ram_w_strb_o                   (`AXI_TOP_INTERFACE(w_bits_strb)),
    .ram_w_last_o                   (`AXI_TOP_INTERFACE(w_bits_last)),
    .ram_w_id_o                     (`AXI_TOP_INTERFACE(w_bits_id)),
  
    .ram_b_ready_o                  (`AXI_TOP_INTERFACE(b_ready)),
    .ram_b_valid_i                  (`AXI_TOP_INTERFACE(b_valid)),
    .ram_b_resp_i                   (`AXI_TOP_INTERFACE(b_bits_resp)),
    .ram_b_id_i                     (`AXI_TOP_INTERFACE(b_bits_id)),
    .ram_b_user_i                   (`AXI_TOP_INTERFACE(b_bits_user)),
  
    .ram_ar_ready_i                 (`AXI_TOP_INTERFACE(ar_ready)),
    .ram_ar_valid_o                 (`AXI_TOP_INTERFACE(ar_valid)),
    .ram_ar_addr_o                  (`AXI_TOP_INTERFACE(ar_bits_addr)),
    .ram_ar_prot_o                  (`AXI_TOP_INTERFACE(ar_bits_prot)),
    .ram_ar_id_o                    (`AXI_TOP_INTERFACE(ar_bits_id)),
    .ram_ar_user_o                  (`AXI_TOP_INTERFACE(ar_bits_user)),
    .ram_ar_len_o                   (`AXI_TOP_INTERFACE(ar_bits_len)),
    .ram_ar_size_o                  (`AXI_TOP_INTERFACE(ar_bits_size)),
    .ram_ar_burst_o                 (`AXI_TOP_INTERFACE(ar_bits_burst)),
    .ram_ar_lock_o                  (`AXI_TOP_INTERFACE(ar_bits_lock)),
    .ram_ar_cache_o                 (`AXI_TOP_INTERFACE(ar_bits_cache)),
    .ram_ar_qos_o                   (`AXI_TOP_INTERFACE(ar_bits_qos)),
  
    .ram_r_ready_o                  (`AXI_TOP_INTERFACE(r_ready)),
    .ram_r_valid_i                  (`AXI_TOP_INTERFACE(r_valid)),
    .ram_r_resp_i                   (`AXI_TOP_INTERFACE(r_bits_resp)),
    .ram_r_data_i                   (`AXI_TOP_INTERFACE(r_bits_data)[0]),
    .ram_r_last_i                   (`AXI_TOP_INTERFACE(r_bits_last)),
    .ram_r_id_i                     (`AXI_TOP_INTERFACE(r_bits_id)),
    .ram_r_user_i                   (`AXI_TOP_INTERFACE(r_bits_user)),

    // CLINT
    .cli_aw_ready_i                 (cli_aw_ready),
    .cli_aw_valid_o                 (cli_aw_valid),
    .cli_aw_addr_o                  (cli_aw_addr),
    .cli_aw_prot_o                  (cli_aw_prot),
    .cli_aw_id_o                    (cli_aw_id),
    .cli_aw_user_o                  (cli_aw_user),
    .cli_aw_len_o                   (cli_aw_len),
    .cli_aw_size_o                  (cli_aw_size),
    .cli_aw_burst_o                 (cli_aw_burst),
    .cli_aw_lock_o                  (cli_aw_lock),
    .cli_aw_cache_o                 (cli_aw_cache),
    .cli_aw_qos_o                   (cli_aw_qos),

    .cli_w_ready_i                  (cli_w_ready),
    .cli_w_valid_o                  (cli_w_valid),
    .cli_w_data_o                   (cli_w_data),
    .cli_w_strb_o                   (cli_w_strb),
    .cli_w_last_o                   (cli_w_last),
    .cli_w_id_o                     (cli_w_id),
  
    .cli_b_ready_o                  (cli_b_ready),
    .cli_b_valid_i                  (cli_b_valid),
    .cli_b_resp_i                   (cli_b_resp),
    .cli_b_id_i                     (cli_b_id),
    .cli_b_user_i                   (cli_b_user),
  
    .cli_ar_ready_i                 (cli_ar_ready),
    .cli_ar_valid_o                 (cli_ar_valid),
    .cli_ar_addr_o                  (cli_ar_addr),
    .cli_ar_prot_o                  (cli_ar_prot),
    .cli_ar_id_o                    (cli_ar_id),
    .cli_ar_user_o                  (cli_ar_user),
    .cli_ar_len_o                   (cli_ar_len),
    .cli_ar_size_o                  (cli_ar_size),
    .cli_ar_burst_o                 (cli_aw_burst),
    .cli_ar_lock_o                  (cli_ar_lock),
    .cli_ar_cache_o                 (cli_ar_cache),
    .cli_ar_qos_o                   (cli_ar_qos),
  
    .cli_r_ready_o                  (cli_r_ready),
    .cli_r_valid_i                  (cli_r_valid),
    .cli_r_resp_i                   (cli_r_resp),
    .cli_r_data_i                   (cli_r_data),
    .cli_r_last_i                   (cli_r_last),
    .cli_r_id_i                     (cli_r_id),
    .cli_r_user_i                   (cli_r_user)
  );
  
  wire                        mem_axi_aw_ready, if_axi_aw_ready, cli_aw_ready;
  wire                        mem_axi_aw_valid, if_axi_aw_valid, cli_aw_valid;
  wire [AXI_ADDR_WIDTH-1:0]   mem_axi_aw_addr,  if_axi_aw_addr,  cli_aw_addr;
  wire [2:0]                  mem_axi_aw_prot,  if_axi_aw_prot,  cli_aw_prot;
  wire [AXI_ID_WIDTH-1:0]     mem_axi_aw_id,    if_axi_aw_id,    cli_aw_id;
  wire [AXI_USER_WIDTH-1:0]   mem_axi_aw_user,  if_axi_aw_user,  cli_aw_user;
  wire [7:0]                  mem_axi_aw_len,   if_axi_aw_len,   cli_aw_len;
  wire [2:0]                  mem_axi_aw_size,  if_axi_aw_size,  cli_aw_size;
  wire [1:0]                  mem_axi_aw_burst, if_axi_aw_burst, cli_aw_burst;
  wire                        mem_axi_aw_lock,  if_axi_aw_lock,  cli_aw_lock;
  wire [3:0]                  mem_axi_aw_cache, if_axi_aw_cache, cli_aw_cache;
  wire [3:0]                  mem_axi_aw_qos,   if_axi_aw_qos,   cli_aw_qos;
  
  wire                        mem_axi_w_ready,  if_axi_w_ready,  cli_w_ready;
  wire                        mem_axi_w_valid,  if_axi_w_valid,  cli_w_valid;
  wire [AXI_DATA_WIDTH-1:0]   mem_axi_w_data,   if_axi_w_data,   cli_w_data;
  wire [AXI_DATA_WIDTH/8-1:0] mem_axi_w_strb,   if_axi_w_strb,   cli_w_strb;
  wire                        mem_axi_w_last,   if_axi_w_last,   cli_w_last;
  wire                        mem_axi_w_id,     if_axi_w_id,     cli_w_id;

  wire                        mem_axi_b_ready,  if_axi_b_ready,  cli_b_ready;
  wire                        mem_axi_b_valid,  if_axi_b_valid,  cli_b_valid;
  wire [1:0]                  mem_axi_b_resp,   if_axi_b_resp,   cli_b_resp;
  wire [AXI_ID_WIDTH-1:0]     mem_axi_b_id,     if_axi_b_id,     cli_b_id;
  wire [AXI_USER_WIDTH-1:0]   mem_axi_b_user,   if_axi_b_user,   cli_b_user;

  wire                        mem_axi_ar_ready, if_axi_ar_ready, cli_ar_ready;
  wire                        mem_axi_ar_valid, if_axi_ar_valid, cli_ar_valid;
  wire [AXI_ADDR_WIDTH-1:0]   mem_axi_ar_addr,  if_axi_ar_addr,  cli_ar_addr;
  wire [2:0]                  mem_axi_ar_prot,  if_axi_ar_prot,  cli_ar_prot;
  wire [AXI_ID_WIDTH-1:0]     mem_axi_ar_id,    if_axi_ar_id,    cli_ar_id;
  wire [AXI_USER_WIDTH-1:0]   mem_axi_ar_user,  if_axi_ar_user,  cli_ar_user;
  wire [7:0]                  mem_axi_ar_len,   if_axi_ar_len,   cli_ar_len;
  wire [2:0]                  mem_axi_ar_size,  if_axi_ar_size,  cli_ar_size;
  wire [1:0]                  mem_axi_ar_burst, if_axi_ar_burst, cli_ar_burst;
  wire                        mem_axi_ar_lock,  if_axi_ar_lock,  cli_ar_lock;
  wire [3:0]                  mem_axi_ar_cache, if_axi_ar_cache, cli_ar_cache;
  wire [3:0]                  mem_axi_ar_qos,   if_axi_ar_qos,   cli_ar_qos;

  wire                        mem_axi_r_ready,  if_axi_r_ready,  cli_r_ready;
  wire                        mem_axi_r_valid,  if_axi_r_valid,  cli_r_valid;
  wire [1:0]                  mem_axi_r_resp,   if_axi_r_resp,   cli_r_resp;
  wire [AXI_DATA_WIDTH-1:0]   mem_axi_r_data,   if_axi_r_data,   cli_r_data;
  wire                        mem_axi_r_last,   if_axi_r_last,   cli_r_last;
  wire [AXI_ID_WIDTH-1:0]     mem_axi_r_id,     if_axi_r_id,     cli_r_id;
  wire [AXI_USER_WIDTH-1:0]   mem_axi_r_user,   if_axi_r_user,   cli_r_user;

  axi_rw mem_axi_rw (
    .clock                          (clock),
    .reset                          (reset),
    .device_id                      (4'b0001),
    
    .rw_valid_i                     (mem_rw_valid),
    .rw_ready_o                     (mem_rw_ready),
    .rw_req_i                       (mem_rw_req),
    .data_read_o                    (mem_r_data),
    .data_write_i                   (mem_w_data),
    .rw_addr_i                      (mem_rw_addr),
    .rw_size_i                      (mem_rw_size),
    .rw_resp_o                      (mem_rw_resp),
    
    .axi_aw_ready_i                 (mem_axi_aw_ready),
    .axi_aw_valid_o                 (mem_axi_aw_valid),
    .axi_aw_addr_o                  (mem_axi_aw_addr),
    .axi_aw_prot_o                  (mem_axi_aw_prot),
    .axi_aw_id_o                    (mem_axi_aw_id),
    .axi_aw_user_o                  (mem_axi_aw_user),
    .axi_aw_len_o                   (mem_axi_aw_len),
    .axi_aw_size_o                  (mem_axi_aw_size),
    .axi_aw_burst_o                 (mem_axi_aw_burst),
    .axi_aw_lock_o                  (mem_axi_aw_lock),
    .axi_aw_cache_o                 (mem_axi_aw_cache),
    .axi_aw_qos_o                   (mem_axi_aw_qos),
    
    .axi_w_ready_i                  (mem_axi_w_ready),
    .axi_w_valid_o                  (mem_axi_w_valid),
    .axi_w_data_o                   (mem_axi_w_data),
    .axi_w_strb_o                   (mem_axi_w_strb),
    .axi_w_last_o                   (mem_axi_w_last),
    .axi_w_id_o                     (mem_axi_w_id),
        
    .axi_b_ready_o                  (mem_axi_b_ready),
    .axi_b_valid_i                  (mem_axi_b_valid),
    .axi_b_resp_i                   (mem_axi_b_resp),
    .axi_b_id_i                     (mem_axi_b_id),
    .axi_b_user_i                   (mem_axi_b_user),

    .axi_ar_ready_i                 (mem_axi_ar_ready),
    .axi_ar_valid_o                 (mem_axi_ar_valid),
    .axi_ar_addr_o                  (mem_axi_ar_addr),
    .axi_ar_prot_o                  (mem_axi_ar_prot),
    .axi_ar_id_o                    (mem_axi_ar_id),
    .axi_ar_user_o                  (mem_axi_ar_user),
    .axi_ar_len_o                   (mem_axi_ar_len),
    .axi_ar_size_o                  (mem_axi_ar_size),
    .axi_ar_burst_o                 (mem_axi_ar_burst),
    .axi_ar_lock_o                  (mem_axi_ar_lock),
    .axi_ar_cache_o                 (mem_axi_ar_cache),
    .axi_ar_qos_o                   (mem_axi_ar_qos),
        
    .axi_r_ready_o                  (mem_axi_r_ready),
    .axi_r_valid_i                  (mem_axi_r_valid),
    .axi_r_resp_i                   (mem_axi_r_resp),
    .axi_r_data_i                   (mem_axi_r_data),
    .axi_r_last_i                   (mem_axi_r_last),
    .axi_r_id_i                     (mem_axi_r_id),
    .axi_r_user_i                   (mem_axi_r_user)
  );

  axi_rw if_axi_rw (
    .clock                          (clock),
    .reset                          (reset),
    .device_id                      (4'b0000),
    
    .rw_valid_i                     (if_rw_valid),
    .rw_ready_o                     (if_rw_ready),
    .rw_req_i                       (if_rw_req),
    .data_read_o                    (if_r_data),
    .data_write_i                   (if_w_data),
    .rw_addr_i                      (if_rw_addr),
    .rw_size_i                      (if_rw_size),
    .rw_resp_o                      (if_rw_resp),
    
    .axi_aw_ready_i                 (if_axi_aw_ready),
    .axi_aw_valid_o                 (if_axi_aw_valid),
    .axi_aw_addr_o                  (if_axi_aw_addr),
    .axi_aw_prot_o                  (if_axi_aw_prot),
    .axi_aw_id_o                    (if_axi_aw_id),
    .axi_aw_user_o                  (if_axi_aw_user),
    .axi_aw_len_o                   (if_axi_aw_len),
    .axi_aw_size_o                  (if_axi_aw_size),
    .axi_aw_burst_o                 (if_axi_aw_burst),
    .axi_aw_lock_o                  (if_axi_aw_lock),
    .axi_aw_cache_o                 (if_axi_aw_cache),
    .axi_aw_qos_o                   (if_axi_aw_qos),
    
    .axi_w_ready_i                  (if_axi_w_ready),
    .axi_w_valid_o                  (if_axi_w_valid),
    .axi_w_data_o                   (if_axi_w_data),
    .axi_w_strb_o                   (if_axi_w_strb),
    .axi_w_last_o                   (if_axi_w_last),
    .axi_w_id_o                     (if_axi_w_id),
        
    .axi_b_ready_o                  (if_axi_b_ready),
    .axi_b_valid_i                  (if_axi_b_valid),
    .axi_b_resp_i                   (if_axi_b_resp),
    .axi_b_id_i                     (if_axi_b_id),
    .axi_b_user_i                   (if_axi_b_user),

    .axi_ar_ready_i                 (if_axi_ar_ready),
    .axi_ar_valid_o                 (if_axi_ar_valid),
    .axi_ar_addr_o                  (if_axi_ar_addr),
    .axi_ar_prot_o                  (if_axi_ar_prot),
    .axi_ar_id_o                    (if_axi_ar_id),
    .axi_ar_user_o                  (if_axi_ar_user),
    .axi_ar_len_o                   (if_axi_ar_len),
    .axi_ar_size_o                  (if_axi_ar_size),
    .axi_ar_burst_o                 (if_axi_ar_burst),
    .axi_ar_lock_o                  (if_axi_ar_lock),
    .axi_ar_cache_o                 (if_axi_ar_cache),
    .axi_ar_qos_o                   (if_axi_ar_qos),
        
    .axi_r_ready_o                  (if_axi_r_ready),
    .axi_r_valid_i                  (if_axi_r_valid),
    .axi_r_resp_i                   (if_axi_r_resp),
    .axi_r_data_i                   (if_axi_r_data),
    .axi_r_last_i                   (if_axi_r_last),
    .axi_r_id_i                     (if_axi_r_id),
    .axi_r_user_i                   (if_axi_r_user)
  );

  wire if_rw_valid;
  wire if_rw_ready;
  wire if_rw_req = `REQ_READ;
  wire [`REG_BUS] if_r_data;
  wire [`REG_BUS] if_w_data = `ZERO_WORD;
  wire [`REG_BUS] if_rw_addr;
  wire [1:0] if_rw_size;
  wire [1:0] if_rw_resp;
  
  wire mem_rw_valid;
  wire mem_rw_ready;
  wire mem_rw_req;
  wire [`REG_BUS] mem_r_data;
  wire [`REG_BUS] mem_w_data;
  wire [`REG_BUS] mem_rw_addr;
  wire [1:0] mem_rw_size;
  wire [1:0] mem_rw_resp;

  wire [`ITRP_BUS] clint_interupt_bus;

  cpu u_cpu(
    .clock                          (clock),
    .reset                          (reset),
    
    // if stage
    .if_rw_valid                   (if_rw_valid),
    .if_rw_ready                   (if_rw_ready),
    .if_r_data                     (if_r_data),
    .if_rw_addr                    (if_rw_addr),
    .if_rw_size                    (if_rw_size),
    .if_rw_resp                    (if_rw_resp),
    
    // mem stage
    .mem_rw_valid                  (mem_rw_valid),
    .mem_rw_ready                  (mem_rw_ready),
    .mem_rw_req                    (mem_rw_req),
    .mem_r_data                    (mem_r_data),
    .mem_w_data                    (mem_w_data),
    .mem_rw_addr                   (mem_rw_addr),
    .mem_rw_size                   (mem_rw_size),
    .mem_rw_resp                   (mem_rw_resp),

    // serial port output
    .uart_out_valid                (io_uart_out_valid),
    .uart_out_char                 (io_uart_out_ch),

    .clint_interupt_bus            (clint_interupt_bus)
  );
  
  clint Clint(
    .clk                           (clock),
    .rst                           (reset),

    .aw_ready_o                    (cli_aw_ready),
    .aw_valid_i                    (cli_aw_valid),
    .aw_addr_i                     (cli_aw_addr),
    .aw_prot_i                     (cli_aw_prot),
    .aw_id_i                       (cli_aw_id),
    .aw_user_i                     (cli_aw_user),
    .aw_len_i                      (cli_aw_len),
    .aw_size_i                     (cli_aw_size),
    .aw_burst_i                    (cli_aw_burst),
    .aw_lock_i                     (cli_aw_lock),
    .aw_cache_i                    (cli_aw_cache),
    .aw_qos_i                      (cli_aw_qos),
    
    .w_ready_o                     (cli_w_ready),
    .w_valid_i                     (cli_w_valid),
    .w_data_i                      (cli_w_data),
    .w_strb_i                      (cli_w_strb),
    .w_last_i                      (cli_w_last),
    .w_id_i                        (cli_w_id),
        
    .b_ready_i                     (cli_b_ready),
    .b_valid_o                     (cli_b_valid),
    .b_resp_o                      (cli_b_resp),
    .b_id_o                        (cli_b_id),
    .b_user_o                      (cli_b_user),

    .ar_ready_o                    (cli_ar_ready),
    .ar_valid_i                    (cli_ar_valid),
    .ar_addr_i                     (cli_ar_addr),
    .ar_prot_i                     (cli_ar_prot),
    .ar_id_i                       (cli_ar_id),
    .ar_user_i                     (cli_ar_user),
    .ar_len_i                      (cli_ar_len),
    .ar_size_i                     (cli_ar_size),
    .ar_burst_i                    (cli_ar_burst),
    .ar_lock_i                     (cli_ar_lock),
    .ar_cache_i                    (cli_ar_cache),
    .ar_qos_i                      (cli_ar_qos),
        
    .r_ready_i                     (cli_r_ready),
    .r_valid_o                     (cli_r_valid),
    .r_resp_o                      (cli_r_resp),
    .r_data_o                      (cli_r_data),
    .r_last_o                      (cli_r_last),
    .r_id_o                        (cli_r_id),
    .r_user_o                      (cli_r_user),

    .clint_interupt_bus            (clint_interupt_bus)
  );
endmodule