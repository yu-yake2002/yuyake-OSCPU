
//--Sun Jiru, Nanjing University--

`timescale 1ns / 1ps

`define RISCV_PRIV_MODE_U   0
`define RISCV_PRIV_MODE_S   1
`define RISCV_PRIV_MODE_M   3

`define ZERO_WORD  64'h00000000_00000000
`define PC_START   64'h00000000_80000000
`define REG_BUS    63 : 0
`define INST_BUS   31 : 0

`define ID_TO_EX_WIDTH        472
`define EX_TO_MEM_WIDTH       224
`define MEM_TO_WB_WIDTH       210

`define BJ_CTRL_WIDTH         66
`define MEM_FORWARD_WIDTH     73
`define WB_FORWARD_WIDTH      137

`define ID_TO_EX_DIFF_WIDTH   1
`define CSR_TO_EX_DIFF_WIDTH  512
`define EX_TO_MEM_DIFF_WIDTH  64+`CSR_TO_EX_DIFF_WIDTH+`ID_TO_EX_DIFF_WIDTH
`define MEM_TO_WB_DIFF_WIDTH  138+`EX_TO_MEM_DIFF_WIDTH
`define WB_DIFFTEST_WIDTH     97+`MEM_TO_WB_DIFF_WIDTH


`define EXCP_RD_WIDTH       320
`define EXCP_WR_WIDTH       320

`define AXI_ADDR_WIDTH      64
`define AXI_DATA_WIDTH      64
`define AXI_ID_WIDTH        4
`define AXI_USER_WIDTH      1

`define SIZE_B              2'b00
`define SIZE_H              2'b01
`define SIZE_W              2'b10
`define SIZE_D              2'b11

`define REQ_READ            1'b0
`define REQ_WRITE           1'b1

`define ALU_ADD    0
`define ALU_SUB    1
`define ALU_SLT    2
`define ALU_SLTU   3
`define ALU_XOR    4
`define ALU_OR     5
`define ALU_AND    6
`define ALU_SLL    7
`define ALU_SRL    8
`define ALU_SRA    9
`define ALU_ANDN   10
`define ALU_WRI    11
`define ALU_BUS    11 : 0

`define BJ_BEQ  0
`define BJ_BNE  1
`define BJ_BLT  2
`define BJ_BGE  3
`define BJ_BLTU 4
`define BJ_BGEU 5
`define BJ_JALR 6
`define BJ_JAL  7
`define BJ_BUS  7 : 0

`define LOAD_LB  0
`define LOAD_LH  1
`define LOAD_LW  2
`define LOAD_LD  3
`define LOAD_LBU 4
`define LOAD_LHU 5
`define LOAD_LWU 6
`define LOAD_BUS 6 : 0

`define SAVE_SB  0
`define SAVE_SH  1
`define SAVE_SW  2
`define SAVE_SD  3
`define SAVE_BUS 3 : 0

`define INST_I_LOAD        0
`define INST_I_FENCE       1
`define INST_I_ARITH_DWORD 2
`define INST_U_AUIPC       3
`define INST_I_ARITH_WORD  4
`define INST_S             5
`define INST_R_DWORD       6
`define INST_U_LUI         7
`define INST_R_WORD        8
`define INST_B             9
`define INST_I_JALR        10
`define INST_J             11
`define INST_I_EXP         12
`define INST_I_CSR_IMM     13
`define INST_I_CSR_REG     14
`define INST_PUTCH         15
`define OP_BUS             15 : 0

`define CSR_MISA       0
`define CSR_MCYCLE     1
`define CSR_MVENDORID  2
`define CSR_MARCHID    3
`define CSR_MIMPID     4
`define CSR_MHARTID    5
`define CSR_BUS        5 : 0

`define EXE_TO_REG   0
`define MEM_TO_REG   1
`define CSR_TO_REG   2
`define REG_CTRL_BUS 2 : 0

`define SOFT_ITRP  3
`define TIMER_ITRP 7
`define EXTER_ITRP 11
`define ITRP_BUS   11 : 0

`define EXCP_INST_MISAL 0
`define EXCP_INST_ACC   1
`define EXCP_ILG_INST   2
`define EXCP_BRK_PT     3
`define EXCP_LOAD_MISAL 4
`define EXCP_LOAD_ACC   5
`define EXCP_STOR_MISAL 6
`define EXCP_STOR_ACC   7
`define EXCP_ECALL_M    11
`define EXCP_INST_PAGE  12
`define EXCP_LOAD_PAGE  13
`define EXCP_STOR_PAGE  15
`define EXCP_BUS        15 : 0

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
  wire debug_oc_r = ram_ar_addr_o[63:4] == 56'h00000000_801cc68;
  wire debug_oc_w = ram_aw_addr_o[63:4] == 56'h00000000_801cc68;

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
  wire w_finish_0 = b_valid_o_0 && b_ready_i_0 && w_state_0;
  wire w_finish_1 = b_valid_o_1 && b_ready_i_1 && w_state_1;
  wire w_finish_cli = cli_b_ready_o && cli_b_valid_i && w_state_cli;
  wire w_finish_ram = ram_b_ready_o && ram_b_valid_i && w_state_ram;

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
        if ((master_w_next_state == STATE_0) && aw_valid_i_0) begin
          slave_w_next_state = w_0_to_ram ? STATE_RAM : STATE_CLINT;
        end
        else if ((master_w_next_state == STATE_1) && aw_valid_i_1) begin
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
        if ((master_r_next_state == STATE_0) && ar_valid_i_0) begin
          slave_r_next_state = r_0_to_ram ? STATE_RAM : STATE_CLINT;
        end
        else if ((master_r_next_state == STATE_1) && ar_valid_i_1) begin
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
  
  assign cli_b_ready_o = w_state_cli & mid_b_ready;

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


module axi_rw # (
  parameter RW_DATA_WIDTH     = 64,
  parameter RW_ADDR_WIDTH     = 64,
  parameter AXI_DATA_WIDTH    = 64,
  parameter AXI_ADDR_WIDTH    = 64,
  parameter AXI_ID_WIDTH      = 4,
  parameter AXI_USER_WIDTH    = 1
)(
  input  wire                              clock,
  input  wire                              reset,
  input  wire [AXI_ID_WIDTH-1:0]           device_id,
  
  input  wire                              rw_valid_i,
  output wire                              rw_ready_o,
  input  wire                              rw_req_i,
  output reg [RW_DATA_WIDTH-1:0]           data_read_o,
  input  wire [RW_DATA_WIDTH-1:0]          data_write_i,
  input  wire [AXI_DATA_WIDTH-1:0]         rw_addr_i,
  input  wire [1:0]                        rw_size_i,
  output wire [1:0]                        rw_resp_o,
  
  // Advanced eXtensible Interface
  input  wire                              axi_aw_ready_i,
  output wire                              axi_aw_valid_o,
  output wire [AXI_ADDR_WIDTH-1:0]         axi_aw_addr_o,
  output wire [2:0]                        axi_aw_prot_o,
  output wire [AXI_ID_WIDTH-1:0]           axi_aw_id_o,
  output wire [AXI_USER_WIDTH-1:0]         axi_aw_user_o,
  output wire [7:0]                        axi_aw_len_o,
  output wire [2:0]                        axi_aw_size_o,
  output wire [1:0]                        axi_aw_burst_o,
  output wire                              axi_aw_lock_o,
  output wire [3:0]                        axi_aw_cache_o,
  output wire [3:0]                        axi_aw_qos_o,
  
  input  wire                              axi_w_ready_i,
  output wire                              axi_w_valid_o,
  output wire [AXI_DATA_WIDTH-1:0]         axi_w_data_o,
  output wire [AXI_DATA_WIDTH/8-1:0]       axi_w_strb_o,
  output wire                              axi_w_last_o,
  output wire [AXI_ID_WIDTH-1:0]           axi_w_id_o,
  
  output wire                              axi_b_ready_o,
  input  wire                              axi_b_valid_i,
  input  wire [1:0]                        axi_b_resp_i,
  input  wire [AXI_ID_WIDTH-1:0]           axi_b_id_i,
  input  wire [AXI_USER_WIDTH-1:0]         axi_b_user_i,
  
  input  wire                              axi_ar_ready_i,
  output wire                              axi_ar_valid_o,
  output wire [AXI_ADDR_WIDTH-1:0]         axi_ar_addr_o,
  output wire [2:0]                        axi_ar_prot_o,
  output wire [AXI_ID_WIDTH-1:0]           axi_ar_id_o,
  output wire [AXI_USER_WIDTH-1:0]         axi_ar_user_o,
  output wire [7:0]                        axi_ar_len_o,
  output wire [2:0]                        axi_ar_size_o,
  output wire [1:0]                        axi_ar_burst_o,
  output wire                              axi_ar_lock_o,
  output wire [3:0]                        axi_ar_cache_o,
  output wire [3:0]                        axi_ar_qos_o,
  
  output wire                              axi_r_ready_o,
  input  wire                              axi_r_valid_i,
  input  wire [1:0]                        axi_r_resp_i,
  input  wire [AXI_DATA_WIDTH-1:0]         axi_r_data_i,
  input  wire                              axi_r_last_i,
  input  wire [AXI_ID_WIDTH-1:0]           axi_r_id_i,
  input  wire [AXI_USER_WIDTH-1:0]         axi_r_user_i
);
  
  wire w_trans    = rw_req_i == `REQ_WRITE;
  wire r_trans    = rw_req_i == `REQ_READ;
  wire w_valid    = rw_valid_i & w_trans;
  wire r_valid    = rw_valid_i & r_trans;
  
  // handshake
  wire aw_hs      = axi_aw_ready_i & axi_aw_valid_o;
  wire w_hs       = axi_w_ready_i  & axi_w_valid_o;
  wire b_hs       = axi_b_ready_o  & axi_b_valid_i;
  wire ar_hs      = axi_ar_ready_i & axi_ar_valid_o;
  wire r_hs       = axi_r_ready_o  & axi_r_valid_i;
  
  wire w_done     = w_hs & axi_w_last_o;
  wire r_done     = r_hs & axi_r_last_i;
  wire trans_done = w_trans ? b_hs : r_done;
  
  
  // ------------------State Machine------------------
  parameter [2:0] W_STATE_IDLE = 3'b000, W_STATE_ADDR = 3'b001, W_STATE_WRITE = 3'b010, W_STATE_RESP = 3'b011, W_STATE_RETN = 3'b100;
  parameter [2:0] R_STATE_IDLE = 3'b000, R_STATE_ADDR = 3'b001, R_STATE_READ  = 3'b010, R_STATE_RETN = 3'b011;
  reg [2:0] w_state, r_state;
  wire w_state_idle = w_state == W_STATE_IDLE, w_state_addr = w_state == W_STATE_ADDR, w_state_write = w_state == W_STATE_WRITE, w_state_resp = w_state == W_STATE_RESP;
  wire r_state_idle = r_state == R_STATE_IDLE, r_state_addr = r_state == R_STATE_ADDR, r_state_read  = r_state == R_STATE_READ;
  
  // Wirte State Machine
  always @(posedge clock) begin
    if (reset) begin
      w_state <= R_STATE_IDLE;
    end
    else begin
      if (w_valid) begin
        case (w_state)
          W_STATE_IDLE:               w_state <= W_STATE_ADDR;
          W_STATE_ADDR:  if (aw_hs)   w_state <= W_STATE_WRITE;
          W_STATE_WRITE: if (w_done)  w_state <= W_STATE_RESP;
          W_STATE_RESP:  if (b_hs)    w_state <= W_STATE_RETN;
          W_STATE_RETN:               w_state <= W_STATE_IDLE;
          default:                    w_state <= W_STATE_IDLE;
        endcase
       end
    end
  end
  
  // Read State Machine
  always @(posedge clock) begin
    if (reset) begin
      r_state <= R_STATE_IDLE;
    end
    else begin
      if (r_valid) begin
        case (r_state)
          R_STATE_IDLE:               r_state <= R_STATE_ADDR;
          R_STATE_ADDR: if (ar_hs)    r_state <= R_STATE_READ;
          R_STATE_READ: if (r_done)   r_state <= R_STATE_RETN;
          R_STATE_RETN:               r_state <= R_STATE_IDLE;
          default:                    r_state <= R_STATE_IDLE;
        endcase
      end
    end
  end
  
  // ------------------Number of transmission------------------
  reg [7:0] len;
  wire len_reset      = reset | (w_trans & w_state_idle) | (r_trans & r_state_idle);
  wire len_incr_en    = (len != axi_len) & (w_hs | r_hs);
  always @(posedge clock) begin
    if (len_reset) begin
      len <= 0;
    end
    else if (len_incr_en) begin
      len <= len + 1;
    end
  end
  
  
  // ------------------Process Data------------------
  parameter ALIGNED_WIDTH = $clog2(AXI_DATA_WIDTH / 8);
  parameter OFFSET_WIDTH  = $clog2(AXI_DATA_WIDTH);
  parameter AXI_SIZE      = $clog2(AXI_DATA_WIDTH / 8);
  parameter MASK_WIDTH    = AXI_DATA_WIDTH * 2;
  parameter TRANS_LEN     = RW_DATA_WIDTH / AXI_DATA_WIDTH;
  
  wire aligned            = TRANS_LEN != 1 | rw_addr_i[ALIGNED_WIDTH-1:0] == 0;
  wire size_b             = rw_size_i == `SIZE_B;
  wire size_h             = rw_size_i == `SIZE_H;
  wire size_w             = rw_size_i == `SIZE_W;
  wire size_d             = rw_size_i == `SIZE_D;
  wire [3:0] addr_op1     = {{4-ALIGNED_WIDTH{1'b0}}, rw_addr_i[ALIGNED_WIDTH-1:0]};
  wire [3:0] addr_op2     = ({4{size_b}} & {4'b0})
                          | ({4{size_h}} & {4'b1})
                          | ({4{size_w}} & {4'b11})
                          | ({4{size_d}} & {4'b111})
                            ;
  wire [3:0] addr_end     = addr_op1 + addr_op2;
  wire overstep           = addr_end[3:ALIGNED_WIDTH] != 0;
  
  wire [7:0] axi_len      = aligned ? TRANS_LEN - 1 : {{7{1'b0}}, overstep};
  wire [2:0] axi_size     = AXI_SIZE[2:0];
  //wire [2:0] axi_size     = 3'b011;
  wire [AXI_ADDR_WIDTH-1:0] axi_addr    = {rw_addr_i[AXI_ADDR_WIDTH-1:ALIGNED_WIDTH], {ALIGNED_WIDTH{1'b0}}};
  wire [OFFSET_WIDTH-1:0] aligned_offset_l    = {{OFFSET_WIDTH-ALIGNED_WIDTH{1'b0}}, {rw_addr_i[ALIGNED_WIDTH-1:0]}} << 3;
  wire [OFFSET_WIDTH-1:0] aligned_offset_h    = AXI_DATA_WIDTH - aligned_offset_l;
  wire [MASK_WIDTH-1:0] mask                  = (({MASK_WIDTH{size_b}} & {{MASK_WIDTH-8{1'b0}}, 8'hff})
                                              | ({MASK_WIDTH{size_h}} & {{MASK_WIDTH-16{1'b0}}, 16'hffff})
                                              | ({MASK_WIDTH{size_w}} & {{MASK_WIDTH-32{1'b0}}, 32'hffffffff})
                                              | ({MASK_WIDTH{size_d}} & {{MASK_WIDTH-64{1'b0}}, 64'hffffffff_ffffffff})
                                                ) << aligned_offset_l;
  wire [AXI_DATA_WIDTH-1:0] mask_l      = mask[AXI_DATA_WIDTH-1:0];
  wire [AXI_DATA_WIDTH-1:0] mask_h      = mask[MASK_WIDTH-1:AXI_DATA_WIDTH];
  
  wire [AXI_ID_WIDTH-1:0] axi_id        = device_id;
  wire [AXI_USER_WIDTH-1:0] axi_user    = {AXI_USER_WIDTH{1'b0}};
  
  reg rw_ready;
  wire rw_ready_nxt = trans_done;
  wire rw_ready_en      = trans_done | rw_ready;
  always @(posedge clock) begin
    if (reset) begin
      rw_ready <= 0;
    end
    else if (rw_ready_en) begin
      rw_ready <= rw_ready_nxt;
    end
  end
  assign rw_ready_o     = rw_ready;
  
  reg [1:0] rw_resp;
  wire rw_resp_nxt = w_trans ? axi_b_resp_i : axi_r_resp_i;
  wire resp_en = trans_done;
  always @(posedge clock) begin
    if (reset) begin
      rw_resp <= 0;
    end
    else if (resp_en) begin
      rw_resp <= rw_resp_nxt;
    end
  end
  assign rw_resp_o      = rw_resp;
  
  
  // ------------------Write Transaction------------------
  
  // Write address channel signals
  assign axi_aw_valid_o   = w_state_addr;
  //assign axi_aw_addr_o    = {AXI_DATA_WIDTH{w_state_addr}} & axi_addr;
  assign axi_aw_addr_o    = axi_addr;

  assign axi_aw_prot_o    = `AXI_PROT_UNPRIVILEGED_ACCESS | `AXI_PROT_SECURE_ACCESS | `AXI_PROT_DATA_ACCESS;
  assign axi_aw_id_o      = {AXI_ID_WIDTH{w_state_addr}} & axi_id;
  assign axi_aw_user_o    = {AXI_USER_WIDTH{w_state_addr}} & axi_user;
  assign axi_aw_len_o     = {8{w_state_addr}} & axi_len;
  assign axi_aw_size_o    = {3{w_state_addr}} & axi_size;
  assign axi_aw_burst_o   = `AXI_BURST_TYPE_INCR;
  assign axi_aw_lock_o    = 1'b0;
  assign axi_aw_cache_o   = `AXI_ARCACHE_NORMAL_NON_CACHEABLE_NON_BUFFERABLE;
  assign axi_aw_qos_o     = 4'h0;
  
  // Write data channel signals
  assign axi_w_valid_o    = w_state_write;
  always @(posedge clock) begin
    if (reset) begin
      axi_w_data_o <= `ZERO_WORD;
      axi_w_strb_o <= 8'b0;
    end
    else if (aw_hs) begin
      axi_w_data_o <= (
          ({64{size_b}} & {8{data_write_i[7 :0]}})
        | ({64{size_h}} & {4{data_write_i[15:0]}})
        | ({64{size_w}} & {2{data_write_i[31:0]}})
        | ({64{size_d}} & {1{data_write_i[63:0]}})
      );
      axi_w_strb_o <= (
          ({8{size_b}} & 8'b00000001)
        | ({8{size_h}} & 8'b00000011)
        | ({8{size_w}} & 8'b00001111)
        | ({8{size_d}} & 8'b11111111)
      ) << rw_addr_i[2:0];
    end
  end
  assign axi_w_last_o     = axi_w_valid_o;
  assign axi_w_id_o       = axi_id;
  
  // Write response channel signals
  assign axi_b_ready_o    = w_state_resp;
  
  // ------------------Read Transaction------------------
  
  // Read address channel signals
  assign axi_ar_valid_o   = r_state_addr;
  //assign axi_ar_addr_o    = {AXI_DATA_WIDTH{r_state_addr}} & axi_addr;
  assign axi_ar_addr_o    = axi_addr;

  assign axi_ar_prot_o    = `AXI_PROT_UNPRIVILEGED_ACCESS | `AXI_PROT_SECURE_ACCESS | `AXI_PROT_DATA_ACCESS;
  assign axi_ar_id_o      = {AXI_ID_WIDTH{r_state_addr}} & axi_id;
  assign axi_ar_user_o    = {AXI_USER_WIDTH{r_state_addr}} & axi_user;
  assign axi_ar_len_o     = {8{r_state_addr}} & axi_len;
  assign axi_ar_size_o    = {3{r_state_addr}} & axi_size;
  assign axi_ar_burst_o   = `AXI_BURST_TYPE_INCR;
  assign axi_ar_lock_o    = 1'b0;
  assign axi_ar_cache_o   = `AXI_ARCACHE_NORMAL_NON_CACHEABLE_NON_BUFFERABLE;
  assign axi_ar_qos_o     = 4'h0;
  
  // Read data channel signals
  assign axi_r_ready_o    = r_state_read;
  
  wire [AXI_DATA_WIDTH-1:0] axi_r_data_l  = (axi_r_data_i & mask_l) >> aligned_offset_l;
  wire [AXI_DATA_WIDTH-1:0] axi_r_data_h  = (axi_r_data_i & mask_h) << aligned_offset_h;
  
  generate
    for (genvar i = 0; i < TRANS_LEN; i += 1) begin
      always @(posedge clock) begin
        if (reset) begin
          data_read_o[i*AXI_DATA_WIDTH+:AXI_DATA_WIDTH] <= 0;
        end
        else if (r_hs) begin
          if (~aligned & overstep) begin
            if (len[0]) begin
              data_read_o[AXI_DATA_WIDTH-1:0] <= data_read_o[AXI_DATA_WIDTH-1:0] | axi_r_data_h;
            end
            else begin
              data_read_o[AXI_DATA_WIDTH-1:0] <= axi_r_data_l;
            end
          end
          else if (len == i) begin
            data_read_o[i*AXI_DATA_WIDTH+:AXI_DATA_WIDTH] <= axi_r_data_l;
          end
        end
      end
    end
  endgenerate

endmodule

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

  wire debug_wr = msip_wr_ena || mtime_wr_ena || mtimecmp_wr_ena;
  wire debug_rd = msip_rd_ena || mtime_rd_ena || mtimecmp_rd_ena;

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
    else if (r_hs) begin
      rd_addr_reg <= 0;
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
    else if (w_hs) begin
      wr_addr_reg <= 0;
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
      csr_mtime <= `ZERO_WORD;
    end
    else if (w_hs && mtime_wr_ena) begin
      csr_mtime <= (~wr_mask & csr_mtime) | (wr_mask & w_data_i);
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
/* verilator lint_off UNUSED */
//--Sun Jiru, Nanjing University--

`timescale 1ns / 1ps

`include "defines.v"

module cpu(
  input wire                 clock,
  input wire                 reset,
  
  // Custom interface

  // if stage
  output wire                if_rw_valid,
  input wire                 if_rw_ready,
  input wire [`REG_BUS]      if_r_data,
  output wire [`REG_BUS]     if_rw_addr,
  output wire [1 : 0]        if_rw_size,
  input wire [1 : 0]         if_rw_resp,
  
  // mem stage
  output wire                mem_rw_valid,
  input wire                 mem_rw_ready,
  output wire                mem_rw_req,
  input wire [`REG_BUS]      mem_r_data,
  output wire [`REG_BUS]     mem_w_data,
  output wire [`REG_BUS]     mem_rw_addr,
  output wire [1 : 0]        mem_rw_size,
  input wire [1 : 0]         mem_rw_resp,

  // UART serial port
  output wire                uart_out_valid,
  output wire [7 : 0]        uart_out_char,

  input wire [`ITRP_BUS]     clint_interupt_bus
);

  // pipeline control
  wire if_to_id_valid, id_to_ex_valid, ex_to_mem_valid, mem_to_wb_valid;
  wire id_allowin, ex_allowin, mem_allowin, wb_allowin;
  wire ex_to_mem_handshake;
  wire [`REG_BUS] if_to_id_pc, id_to_ex_pc, ex_to_mem_pc, mem_to_wb_pc;
  wire [`INST_BUS] if_to_id_inst, id_to_ex_inst, ex_to_mem_inst, mem_to_wb_inst;
  wire [`ID_TO_EX_WIDTH-1:0]     id_to_ex_bus;
  wire [`EX_TO_MEM_WIDTH-1:0]    ex_to_mem_bus;
  wire [`MEM_TO_WB_WIDTH-1:0]    mem_to_wb_bus;

  // difftest bus
  wire [`CSR_TO_EX_DIFF_WIDTH-1:0] csr_to_ex_diffbus;
  wire [`ID_TO_EX_DIFF_WIDTH-1:0]  id_to_ex_diffbus;
  wire [`EX_TO_MEM_DIFF_WIDTH-1:0] ex_to_mem_diffbus;
  wire [`MEM_TO_WB_DIFF_WIDTH-1:0] mem_to_wb_diffbus;
  wire [`WB_DIFFTEST_WIDTH-1:0]    difftest_bus;
  
  // branch and jump bus
  wire [`BJ_CTRL_WIDTH-1:0]      bj_ctrl_bus;

  // pipeline forward control bus
  wire [`MEM_FORWARD_WIDTH-1:0]  mem_forward_bus;
  wire [`WB_FORWARD_WIDTH-1:0]   wb_forward_bus;
  
  wire if_bj_ready;
  // IF stage
  if_stage If_stage(
    .clk                       (clock),
    .rst                       (reset),
    
    // pipeline control
    .if_to_id_valid            (if_to_id_valid),
    .if_to_id_pc               (if_to_id_pc),
    .if_to_id_inst             (if_to_id_inst),
    .id_allowin                (id_allowin),
    
    // branch and jump control
    .if_bj_ready               (if_bj_ready),
    .bj_ctrl_bus               (bj_ctrl_bus),
    //.excp_jmp_ena(excp_jmp_ena),
    //.excp_pc(excp_pc),
    
    // Custom Interface
    .if_axi_valid              (if_rw_valid),
    .if_axi_ready              (if_rw_ready),
    .if_axi_data_read          (if_r_data),
    .if_axi_addr               (if_rw_addr),
    .if_axi_size               (if_rw_size),
    .if_axi_resp               (if_rw_resp)
  );

  // ID stage
  id_stage Id_stage(
    .clk                       (clock),
    .rst                       (reset),
  
    // pipeline control
    .if_to_id_valid            (if_to_id_valid),
    .if_to_id_pc               (if_to_id_pc),
    .if_to_id_inst             (if_to_id_inst),
    .id_allowin                (id_allowin),

    .id_to_ex_valid            (id_to_ex_valid),
    .id_to_ex_pc               (id_to_ex_pc),
    .id_to_ex_inst             (id_to_ex_inst),
    .id_to_ex_bus              (id_to_ex_bus),
    .ex_allowin                (ex_allowin),

    // data from regfile and CSRs
    //.r_data1                   (r_data1),
    //.r_data2                   (r_data2),
    .csr_data                  (csr_rd_data),
    
    // control reg
    //.rs1_r_ena                 (rs1_r_ena),
    //.rs1_addr                  (rs1_r_addr),
    //.rs2_r_ena                 (rs2_r_ena),
    //.rs2_addr                  (rs2_r_addr),
    
    // control csr
    .csr_rd_ena                (csr_rd_ena),
    .csr_rd_addr               (csr_rd_addr),

    .bj_ctrl_bus               (bj_ctrl_bus),

    .id_to_ex_diffbus          (id_to_ex_diffbus)
  );
  
  ex_stage Ex_stage(
    .clk(clock),
    .rst(reset),
    
    // pipeline control
    .id_to_ex_valid            (id_to_ex_valid),
    .id_to_ex_pc               (id_to_ex_pc),
    .id_to_ex_inst             (id_to_ex_inst),
    .id_to_ex_bus              (id_to_ex_bus),
    .ex_allowin                (ex_allowin),

    .ex_to_mem_valid           (ex_to_mem_valid),
    .ex_to_mem_pc              (ex_to_mem_pc),
    .ex_to_mem_inst            (ex_to_mem_inst),
    .ex_to_mem_bus             (ex_to_mem_bus),
    .mem_allowin               (mem_allowin),
    
    // pipeline forward control
    .mem_forward_bus           (mem_forward_bus),
    .wb_forward_bus            (wb_forward_bus),
    
    // branch and jump control
    .if_bj_ready               (if_bj_ready),
    .bj_ctrl_bus               (bj_ctrl_bus),
    
    // csr control
    .csr_wr_clk                (ex_to_mem_handshake),
    .csr_wr_ena                (csr_wr_ena),
    .csr_wr_addr               (csr_wr_addr),
    .csr_wr_data               (csr_wr_data),
    
    // exception
    .excp_enter                (excp_enter),
    .excp_exit                 (excp_exit),
    .csr_excp_rd_bus           (csr_excp_rd_bus),
    .csr_excp_wr_bus           (csr_excp_wr_bus),
    .clint_interupt_bus        (clint_interupt_bus),

    .ex_rs1_r_ena              (rs1_r_ena),
    .ex_rs1_addr               (rs1_r_addr),
    .ex_rs2_r_ena              (rs2_r_ena),
    .ex_rs2_addr               (rs2_r_addr),
    .rs1_data                  (r_data1),
    .rs2_data                  (r_data2),
    
    .id_to_ex_diffbus          (id_to_ex_diffbus),
    .csr_to_ex_diffbus         (csr_to_ex_diffbus),
    .ex_to_mem_diffbus         (ex_to_mem_diffbus)
  );

  // CSRs
  // id stage <-> csrfile
  wire            csr_rd_ena;
  wire [11 : 0]   csr_rd_addr;
  wire [`REG_BUS] csr_rd_data;
  // ex stage <=> csrfile
  wire            csr_wr_ena;
  wire [11 : 0]   csr_wr_addr;
  wire [`REG_BUS] csr_wr_data;
  // excption control
  wire                      excp_enter, excp_exit;
  wire [`EXCP_RD_WIDTH-1:0] csr_excp_rd_bus;
  wire [`EXCP_WR_WIDTH-1:0] csr_excp_wr_bus;

  // direct read and write
  wire [`CSR_TO_EX_DIFF_WIDTH-1:0] csr_to_ex_diffbus;

  csrfile CSRfile(
    .clk                       (clock),
    .rst                       (reset),
    
    .csr_wr_clk                (ex_to_mem_handshake),

    // read: id stage
    .csr_rd_ena                (csr_rd_ena),
    .csr_rd_addr               (csr_rd_addr),
    .csr_rd_data               (csr_rd_data),
    
    // write: ex stages
    .csr_wr_ena                (csr_wr_ena),
    .csr_wr_addr               (csr_wr_addr),
    .csr_wr_data               (csr_wr_data),
    
    // exception
    .csr_excp_rd_bus           (csr_excp_rd_bus),
    .csr_excp_wr_bus           (csr_excp_wr_bus),

    .excp_enter                (excp_enter),
    .excp_exit                 (excp_exit),

    .csr_to_ex_diffbus         (csr_to_ex_diffbus)
  );
  
  // MEM_STAGE
  mem_stage Mem_stage(
    .clk                       (clock),
    .rst                       (reset),
  
    // pipeline control
    .ex_to_mem_valid           (ex_to_mem_valid),
    .ex_to_mem_pc              (ex_to_mem_pc),
    .ex_to_mem_inst            (ex_to_mem_inst),
    .ex_to_mem_bus             (ex_to_mem_bus),
    .mem_allowin               (mem_allowin),
    .ex_to_mem_handshake       (ex_to_mem_handshake),

    .mem_to_wb_valid           (mem_to_wb_valid),
    .mem_to_wb_pc              (mem_to_wb_pc),
    .mem_to_wb_inst            (mem_to_wb_inst),
    .mem_to_wb_bus             (mem_to_wb_bus),
    .wb_allowin                (wb_allowin),
    
    // pipeline forward control
    .mem_forward_bus           (mem_forward_bus),

    // difftest bus
    .ex_to_mem_diffbus         (ex_to_mem_diffbus),
    .mem_to_wb_diffbus         (mem_to_wb_diffbus),

    // Custom interface
    .mem_rw_valid              (mem_rw_valid),
    .mem_rw_ready              (mem_rw_ready),
    .mem_rw_req                (mem_rw_req),
    .mem_r_data                (mem_r_data),
    .mem_w_data                (mem_w_data),
    .mem_rw_addr               (mem_rw_addr),
    .mem_rw_size               (mem_rw_size),
    .mem_rw_resp               (mem_rw_resp)
  );
  
  // WB_STAGE
  wb_stage Wb_stage(
    .clk                       (clock),
    .rst                       (reset),
    
    // pipeline control
    .mem_to_wb_valid           (mem_to_wb_valid),
    .mem_to_wb_pc              (mem_to_wb_pc),
    .mem_to_wb_inst            (mem_to_wb_inst),
    .mem_to_wb_bus             (mem_to_wb_bus),
    .wb_allowin                (wb_allowin),

    .wb_forward_bus            (wb_forward_bus),

    // regfile control
    .reg_wr_ena                (reg_wr_ena),
    .reg_wr_addr               (reg_wr_addr),
    .reg_wr_data               (reg_wr_data),
    
    // difftest bus
    .mem_to_wb_diffbus         (mem_to_wb_diffbus),
    .difftest_bus              (difftest_bus),
    
    // serial port output
    .wb_uart_out_valid         (uart_out_valid),
    .wb_uart_out_char          (uart_out_char)
  );
  
  // General Purpose Registers
  // id_stage <-> regfile
  wire rs1_r_ena;
  wire [4 : 0]rs1_r_addr;
  wire [`REG_BUS] r_data1;
  wire rs2_r_ena;
  wire [4 : 0]rs2_r_addr;
  wire [`REG_BUS] r_data2;
  // wb_stage <-> regfile
  wire reg_wr_ena;
  wire [4 : 0] reg_wr_addr;
  wire [`REG_BUS] reg_wr_data;
  
  // difftest
  wire [`REG_BUS] regs[0 : 31];

  regfile Regfile(
    .clk                       (clock),
    .rst                       (reset),
    .w_addr                    (reg_wr_addr),
    .w_data                    (reg_wr_data),
    .w_ena                     (reg_wr_ena),
  
    .r_addr1                   (rs1_r_addr),
    .r_data1                   (r_data1),
    .r_ena1                    (rs1_r_ena),
    .r_addr2                   (rs2_r_addr),
    .r_data2                   (r_data2),
    .r_ena2                    (rs2_r_ena),
  
    .regs_o                    (regs)
  );
  
  // Difftest
  reg              cmt_wen;
  reg [7:0]        cmt_wdest;
  reg [`REG_BUS]   cmt_wdata;
  reg [`REG_BUS]   cmt_pc;
  reg [`INST_BUS]  cmt_inst;
  reg              cmt_valid, cmt_skip;
  reg [`INST_BUS]  cmt_itrp_NO, cmt_excp_NO;
  reg [`REG_BUS]   cycleCnt, instrCnt;
  
  wire [`REG_BUS]  wb_pc, wb_rw_addr, wb_w_data;
  wire [`INST_BUS] wb_inst;
  wire             wb_commit, wb_w_ena, wb_r_ena, wb_skip;
  wire [7 : 0]     wb_w_mask;
  wire [`INST_BUS] wb_itrp_NO, wb_excp_NO;
  wire [`CSR_TO_EX_DIFF_WIDTH-1:0] wb_csr_diff;
  assign {
    wb_skip,

    // ex stage
    wb_csr_diff,
    wb_itrp_NO,
    wb_excp_NO,
    
    // mem stage
    wb_rw_addr,
    wb_w_data,
    wb_w_mask,
    wb_w_ena,
    wb_r_ena,

    // wb stage 
    wb_pc,       // 96 :33
    wb_inst,     // 32 :1
    wb_commit    // 0  :0
  } = difftest_bus;

  always @(posedge clock) begin
    if (reset) begin
      {cmt_wen, cmt_wdest, cmt_wdata, cmt_pc, cmt_inst, cmt_valid, cmt_skip, cycleCnt, instrCnt, cmt_itrp_NO, cmt_excp_NO} <= 0;
    end
    else begin
      cmt_wen <= reg_wr_ena;
      cmt_wdest <= {3'd0, reg_wr_addr};
      cmt_wdata <= reg_wr_data;
      cmt_pc <= wb_pc;
      cmt_inst <= wb_inst;
      cmt_valid <= wb_commit && ~(|wb_itrp_NO);
  
      // Skip comparison of the first instruction
      // Because the result required to commit cannot be calculated in time before first InstrCommit during verilator simulation
      // Maybe you can avoid it in pipeline
      cmt_skip <= wb_skip || (wb_rw_addr[63:16] == 48'h00000000_0200);
      cmt_itrp_NO <= wb_itrp_NO & {32{wb_commit}};
      cmt_excp_NO <= wb_excp_NO;
      
      cycleCnt <= cycleCnt + 1;
      instrCnt <= instrCnt + (wb_commit && ~(|wb_itrp_NO));
    end
  end
  
  DifftestInstrCommit DifftestInstrCommit(
    .clock              (clock),
    .coreid             (0),
    .index              (0),
    .valid              (cmt_valid && ~(|cmt_excp_NO) && ~(|cmt_itrp_NO)),
    .pc                 (cmt_pc),
    .instr              (cmt_inst),
    .skip               (cmt_skip),
    .isRVC              (0),
    .scFailed           (0),
    .wen                (cmt_wen),
    .wdest              (cmt_wdest),
    .wdata              (cmt_wdata)
  );
  
  
  DifftestArchEvent DifftestArchEvent(
    .clock              (clock),
    .coreid             (0),
    .intrNO             (cmt_itrp_NO),
    .cause              (cmt_excp_NO & {32{cmt_valid}}),
    .exceptionPC        (cmt_pc),
    .exceptionInst      (cmt_inst)
  );

  DifftestArchIntRegState DifftestArchIntRegState (
    .clock              (clock),
    .coreid             (0),
    .gpr_0              (regs[0]),
    .gpr_1              (regs[1]),
    .gpr_2              (regs[2]),
    .gpr_3              (regs[3]),
    .gpr_4              (regs[4]),
    .gpr_5              (regs[5]),
    .gpr_6              (regs[6]),
    .gpr_7              (regs[7]),
    .gpr_8              (regs[8]),
    .gpr_9              (regs[9]),
    .gpr_10             (regs[10]),
    .gpr_11             (regs[11]),
    .gpr_12             (regs[12]),
    .gpr_13             (regs[13]),
    .gpr_14             (regs[14]),
    .gpr_15             (regs[15]),
    .gpr_16             (regs[16]),
    .gpr_17             (regs[17]),
    .gpr_18             (regs[18]),
    .gpr_19             (regs[19]),
    .gpr_20             (regs[20]),
    .gpr_21             (regs[21]),
    .gpr_22             (regs[22]),
    .gpr_23             (regs[23]),
    .gpr_24             (regs[24]),
    .gpr_25             (regs[25]),
    .gpr_26             (regs[26]),
    .gpr_27             (regs[27]),
    .gpr_28             (regs[28]),
    .gpr_29             (regs[29]),
    .gpr_30             (regs[30]),
    .gpr_31             (regs[31])
  );
  
  DifftestTrapEvent DifftestTrapEvent(
    .clock              (clock),
    .coreid             (0),
    .valid              (cmt_inst[6:0] == 7'h6b),
    .code               (regs[10][7:0]),
    .pc                 (cmt_pc),
    .cycleCnt           (cycleCnt),
    .instrCnt           (instrCnt)
  );
  
  wire [`REG_BUS] wb_mstatus, wb_mepc, wb_mtval, wb_mtvec,
                  wb_mcause, wb_mip, wb_mie, wb_mscratch;
  assign {
    wb_mstatus,
    wb_mepc,
    wb_mtval,
    wb_mtvec,
    wb_mcause,
    wb_mip,
    wb_mie,
    wb_mscratch
  } = wb_csr_diff;

  reg [`REG_BUS] cmt_mstatus, cmt_mepc, cmt_mtval, cmt_mtvec, 
                 cmt_mcause, cmt_mip, cmt_mie, cmt_mscratch;
  always @(posedge clock) begin
    if (reset) begin
      {cmt_mstatus, cmt_mepc, cmt_mtval, cmt_mtvec, cmt_mcause, cmt_mip, cmt_mie, cmt_mscratch} <= 0;
    end
    else begin
      cmt_mstatus   <= wb_mstatus;
      cmt_mepc      <= wb_mepc;
      cmt_mtval     <= wb_mtval;
      cmt_mtvec     <= wb_mtvec;
      cmt_mcause    <= wb_mcause;
      cmt_mip       <= wb_mip;
      cmt_mie       <= wb_mie;
      cmt_mscratch  <= wb_mscratch; 
    end
  end

  DifftestCSRState DifftestCSRState(
    .clock              (clock),
    .coreid             (0),
    .priviledgeMode     (`RISCV_PRIV_MODE_M),
    .mstatus            (cmt_mstatus),
    .sstatus            (cmt_mstatus & 64'h80000003000de122),
    .mepc               (cmt_mepc),
    .sepc               (0),
    .mtval              (cmt_mtval),
    .stval              (0),
    .mtvec              (cmt_mtvec),
    .stvec              (0),
    .mcause             (cmt_mcause),
    .scause             (0),
    .satp               (0),
    .mip                (0),
    .mie                (cmt_mie),
    .mscratch           (cmt_mscratch),
    .sscratch           (0),
    .mideleg            (0),
    .medeleg            (0)
  );
  
  DifftestArchFpRegState DifftestArchFpRegState(
    .clock              (clock),
    .coreid             (0),
    .fpr_0              (0),
    .fpr_1              (0),
    .fpr_2              (0),
    .fpr_3              (0),
    .fpr_4              (0),
    .fpr_5              (0),
    .fpr_6              (0),
    .fpr_7              (0),
    .fpr_8              (0),
    .fpr_9              (0),
    .fpr_10             (0),
    .fpr_11             (0),
    .fpr_12             (0),
    .fpr_13             (0),
    .fpr_14             (0),
    .fpr_15             (0),
    .fpr_16             (0),
    .fpr_17             (0),
    .fpr_18             (0),
    .fpr_19             (0),
    .fpr_20             (0),
    .fpr_21             (0),
    .fpr_22             (0),
    .fpr_23             (0),
    .fpr_24             (0),
    .fpr_25             (0),
    .fpr_26             (0),
    .fpr_27             (0),
    .fpr_28             (0),
    .fpr_29             (0),
    .fpr_30             (0),
    .fpr_31             (0)
  );
  
  
  reg [`REG_BUS] cmt_rw_addr, cmt_w_data, buf_rw_addr, buf_w_data;
  reg [7 : 0]    cmt_w_mask, buf_w_mask;
  reg            cmt_w_ena, cmt_r_ena, buf_w_ena, buf_r_ena;
  always @(posedge clock) begin
    if (reset) begin
      {cmt_rw_addr, cmt_w_data, cmt_w_mask, cmt_w_ena, cmt_r_ena} <= 0; 
    end
    else begin
      buf_rw_addr <= wb_rw_addr;
      buf_w_data  <= wb_w_data;
      buf_w_mask  <= wb_w_mask;
      buf_w_ena   <= wb_w_ena & wb_commit;
      buf_r_ena   <= wb_r_ena & wb_commit;

      cmt_rw_addr <= buf_rw_addr;
      cmt_w_data  <= buf_w_data;
      cmt_w_mask  <= buf_w_mask;
      cmt_w_ena   <= buf_w_ena;
      cmt_r_ena   <= buf_r_ena;
    end
  end
  
  DifftestStoreEvent DifftestStoreEvent(
    .clock              (clock),
    .coreid             (0),
    .index              (0),
    .valid              (cmt_w_ena && ~(wb_rw_addr[63:16] == 48'h00000000_0200)),
    .storeAddr          (cmt_rw_addr),
    .storeData          (cmt_w_data),
    .storeMask          (cmt_w_mask)
  );
endmodule

//--Sun Jiru, Nanjing Univeristy--

`include "defines.v"

module csrfile(
  input wire                              clk,
  input wire                              rst,
  
  input wire                              csr_wr_clk,
  
  // id stage
  input wire                              csr_rd_ena,
  input wire [11 : 0]                     csr_rd_addr,
  output wire [`REG_BUS]                  csr_rd_data,
  
  // wb stage
  input wire                              csr_wr_ena,
  input wire [11 : 0]                     csr_wr_addr,
  input wire [`REG_BUS]                   csr_wr_data,
  
  // exception
  output wire [`EXCP_RD_WIDTH-1:0]        csr_excp_rd_bus,
  input wire [`EXCP_WR_WIDTH-1:0]         csr_excp_wr_bus,
  
  // exception read and write
  input wire                              excp_enter,
  input wire                              excp_exit,
  
  // difftest bus
  output wire [`CSR_TO_EX_DIFF_WIDTH-1:0] csr_to_ex_diffbus
  );
  
  wire [`REG_BUS] mip_wr_data, mstatus_wr_data, mepc_wr_data,
                  mcause_wr_data, mtval_wr_data;
  assign {
    mip_wr_data,
    mcause_wr_data,
    mepc_wr_data,
    mtval_wr_data,
    mstatus_wr_data
  } = csr_excp_wr_bus;

  assign csr_excp_rd_bus = {
    csr_mstatus,
    csr_mtvec,
    csr_mepc,
    csr_mip,
    csr_mie
  };
  
  wire excp_enter_wr = excp_enter && csr_wr_clk;
  wire excp_exit_wr  = excp_exit  && csr_wr_clk;
  wire excp_wr = (excp_enter || excp_exit) && csr_wr_clk;

  // 0x300 Machine Status Register
  wire sel_rd_mstatus = (csr_rd_addr == 12'h300);
  wire sel_wr_mstatus = (csr_wr_addr == 12'h300);
  wire mstatus_rd_ena = sel_rd_mstatus && csr_rd_ena;
  wire mstatus_wr_ena = sel_wr_mstatus && csr_wr_ena && csr_wr_clk;
  wire [`REG_BUS] mstatus_wr_data_full = {
    (mstatus_wr_data[14:13] == 2'b11) || (mstatus_wr_data[16:15] == 2'b11),
    mstatus_wr_data[62:0]
  };
  wire [`REG_BUS] csr_wr_data_full = {
    (csr_wr_data[14:13] == 2'b11) || (csr_wr_data[16:15] == 2'b11),
    csr_wr_data[62:0]
  };

  reg [`REG_BUS] csr_mstatus;

  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mstatus <= 64'h1880;
    end
    else if (excp_wr) begin
      csr_mstatus <= 64'h80000000_0001F888 & mstatus_wr_data_full;
    end
    else if (mstatus_wr_ena) begin
      csr_mstatus <= 64'h80000000_0001F888 & csr_wr_data_full;
    end
  end

  wire [`REG_BUS] mstatus_rd_data = (
    excp_wr        ? mstatus_wr_data_full :
    mstatus_wr_ena ? csr_wr_data_full :
                     csr_mstatus
  );
  
  // 0x301 Machine ISA Register
  wire sel_misa = (csr_rd_addr == 12'h301);
  wire misa_rd_ena = sel_misa & csr_rd_ena;
  wire [`REG_BUS] csr_misa = {
    2'b10
    ,4'b0 //WIRI
    ,1'b0 //              25 Z Reserved
    ,1'b0 //              24 Y Reserved
    ,1'b0 //              23 X Non-standard extensions present
    ,1'b0 //              22 W Reserved
    ,1'b0 //              21 V Tentatively reserved for Vector extension 20 U User mode implemented
    ,1'b0 //              20 U User mode implemented
    ,1'b0 //              19 T Tentatively reserved for Transactional Memory extension
    ,1'b0 //              18 S Supervisor mode implemented
    ,1'b0 //              17 R Reserved
    ,1'b0 //              16 Q Quad-precision floating-point extension
    ,1'b0 //              15 P Tentatively reserved for Packed-SIMD extension
    ,1'b0 //              14 O Reserved
    ,1'b0 //              13 N User-level interrupts supported
    ,1'b0 //              12 M Integer Multiply/Divide extension
    ,1'b0 //              11 L Tentatively reserved for Decimal Floating-Point extension
    ,1'b0 //              10 K Reserved
    ,1'b0 //              9 J Reserved
    ,1'b1 //              8 I RV32I/64I/128I base ISA
    ,1'b0 //              7 H Hypervisor mode implemented
    ,1'b0 //              6 G Additional standard extensions present
    ,1'b0 //              5 F Single-precision floating-point extension
    ,1'b0 //              4 E RV32E base ISA
    ,1'b0 //              3 D Double-precision floating-point extension
    ,1'b0 //              2 C Compressed extension
    ,1'b0 //              1 B Tentatively reserved for Bit operations extension
    ,1'b0 //              0 A Atomic extension
  };

  wire [`REG_BUS] misa_rd_data = csr_misa;

  // 0x304 Machine Interrupt Enable Register
  wire sel_rd_mie = csr_rd_addr == 12'h304;
  wire sel_wr_mie = csr_wr_addr == 12'h304;
  wire mie_rd_ena = csr_rd_ena && sel_rd_mie;
  wire mie_wr_ena = csr_wr_ena && sel_wr_mie && csr_wr_clk;
  reg [`REG_BUS] csr_mie;

  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mie <= 64'h888;  // only for machine mode
    end
    else if (mie_wr_ena) begin
      csr_mie <= csr_wr_data;
    end
  end

  wire [`REG_BUS] mie_rd_data = mie_wr_ena ? csr_wr_data : csr_mie;

  // 0x305 Machine Trap-Vector Base-Address Register
  wire sel_rd_mtvec = (csr_rd_addr == 12'h305);
  wire sel_wr_mtvec = (csr_wr_addr == 12'h305);
  wire mtvec_rd_ena = csr_rd_ena && sel_rd_mtvec;
  wire mtvec_wr_ena = csr_wr_ena && sel_wr_mtvec && csr_wr_clk;
  reg [`REG_BUS] csr_mtvec;

  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mtvec <= `ZERO_WORD;
    end
    else if (mtvec_wr_ena) begin
      csr_mtvec <= csr_wr_data;
    end
  end

  wire [`REG_BUS] mtvec_rd_data = mtvec_wr_ena ? csr_wr_data : csr_mtvec;
  
  // 0x340 Machine Scratch Register
  wire sel_rd_mscratch = (csr_rd_addr == 12'h340);
  wire sel_wr_mscratch = (csr_wr_addr == 12'h340);
  wire mscratch_rd_ena = csr_rd_ena && sel_rd_mscratch;
  wire mscratch_wr_ena = csr_wr_ena && sel_wr_mscratch && csr_wr_clk;
  reg [`REG_BUS] csr_mscratch;

  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mscratch <= `ZERO_WORD;
    end
    else if (mscratch_wr_ena) begin
      csr_mscratch <= csr_wr_data;
    end
  end

  wire [`REG_BUS] mscratch_rd_data = mscratch_wr_ena ? csr_wr_data : csr_mscratch;

  // 0x341 Machine Exception Program Counter
  wire sel_rd_mepc = (csr_rd_addr == 12'h341);
  wire sel_wr_mepc = (csr_wr_addr == 12'h341);
  wire mepc_rd_ena = csr_rd_ena && sel_rd_mepc;
  wire mepc_wr_ena = csr_wr_ena && sel_wr_mepc && csr_wr_clk;
  reg [`REG_BUS] csr_mepc;

  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mepc <= `ZERO_WORD;
    end
    else if (excp_enter_wr) begin
      csr_mepc <=  mepc_wr_data;
    end
    else if (mepc_wr_ena) begin
      csr_mepc <= csr_wr_data;
    end
  end
  
  wire [`REG_BUS] mepc_rd_data = (
    excp_enter  ? mepc_wr_data :
    mepc_wr_ena ? csr_wr_data :
                  csr_mepc
  );

  // 0x342 Machine Cause Register
  wire sel_rd_mcause = (csr_rd_addr == 12'h342);
  wire sel_wr_mcause = (csr_wr_addr == 12'h342);
  wire mcause_rd_ena = csr_rd_ena && sel_rd_mcause;
  wire mcause_wr_ena = csr_wr_ena && sel_wr_mcause && csr_wr_clk;
  reg [`REG_BUS] csr_mcause;

  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mcause <= `ZERO_WORD;
    end
    else if (excp_enter_wr) begin
      csr_mcause <=  mcause_wr_data;
    end
    else if (mcause_wr_ena) begin
      csr_mcause <= csr_wr_data;
    end
  end
  
  wire [`REG_BUS] mcause_rd_data = (
    excp_enter    ? mcause_wr_data :
    mcause_wr_ena ? csr_wr_data :
                    csr_mcause
  );
  
  // 0x343 Machine Trap Value Register
  wire sel_rd_mtval = (csr_rd_addr == 12'h343);
  wire sel_wr_mtval = (csr_wr_addr == 12'h343);
  wire mtval_rd_ena = csr_rd_ena && sel_rd_mtval;
  wire mtval_wr_ena = csr_wr_ena && sel_wr_mtval && csr_wr_clk;
  reg [`REG_BUS] csr_mtval;
  
  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mtval <= 64'b0;
    end
    else if (excp_enter_wr) begin
      csr_mtval <= mtval_wr_data;
    end
    else if (mtval_wr_ena) begin
      csr_mtval <= csr_wr_data;
    end
  end

  wire [`REG_BUS] mtval_rd_data = (
    excp_enter   ? mtval_wr_data :
    mtval_wr_ena ? csr_wr_data :
                   csr_mtval
  );

  // 0x344 Machine Interrupt Pending Register
  wire sel_rd_mip = (csr_rd_addr == 12'h344);
  wire sel_wr_mip = (csr_wr_addr == 12'h344);
  wire mip_rd_ena = csr_rd_ena && sel_rd_mip;
  wire mip_wr_ena = csr_wr_ena && sel_wr_mip && csr_wr_clk;
  reg [`REG_BUS] csr_mip;
  /*
  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mip <= 64'h80;
    end
    else if (mip_wr_ena) begin
      csr_mip <= csr_wr_data;
    end
    // TODO: when interruption pending, mip should flip corresponding bit
  end
  */
  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mip <= 64'h80;
    end
    else begin
      csr_mip <= mip_wr_data;
    end
  end

  wire [`REG_BUS] mip_rd_data = mip_wr_data;

  // 0xB00 Cycle Counter
  wire sel_rd_mcycle = (csr_rd_addr == 12'hb00);
  wire sel_wr_mcycle = (csr_wr_addr == 12'hb00);
  wire mcycle_rd_ena = csr_rd_ena && sel_rd_mcycle;
  wire mcycle_wr_ena = csr_wr_ena && sel_wr_mcycle && csr_wr_clk;
  reg [`REG_BUS] csr_mcycle;

  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mcycle <= `ZERO_WORD;
    end
    else if (mcycle_wr_ena) begin
      csr_mcycle <= csr_wr_data;
    end
    else begin
      csr_mcycle <= csr_mcycle + 64'b1;
    end
  end

  wire [`REG_BUS] mcycle_rd_data = mcycle_wr_ena ? csr_wr_data : (csr_mcycle + 64'b1);

  // 0xF11 Machine Vendor ID Register
  wire sel_mvendorid = (csr_rd_addr == 12'hf11);
  wire mvendorid_rd_ena = (csr_rd_ena & sel_mvendorid);
  wire [`REG_BUS] csr_mvendorid = `ZERO_WORD;
  wire [`REG_BUS] mvendorid_rd_data = csr_mvendorid;
  
  // 0xF12 Machine Architecture ID Register
  wire sel_marchid= (csr_rd_addr == 12'hf12);
  wire marchid_rd_ena = (csr_rd_ena & sel_marchid);
  wire [`REG_BUS] csr_marchid = `ZERO_WORD;
  wire [`REG_BUS] marchid_rd_data = csr_marchid;
  
  // 0xF13 Machine Implementation ID Register
  wire sel_mimpid= (csr_rd_addr == 12'hf13);
  wire mimpid_rd_ena = (csr_rd_ena & sel_mimpid);
  wire [`REG_BUS] csr_mimpid = `ZERO_WORD;
  wire [`REG_BUS] mimpid_rd_data = csr_mimpid;

  // 0xF14 Hart ID Register
  wire sel_mhartid= (csr_rd_addr == 12'hf14);
  wire mhartid_rd_ena = (csr_rd_ena & sel_mhartid);
  wire [`REG_BUS] csr_mhartid = `ZERO_WORD;
  wire [`REG_BUS] mhartid_rd_data = csr_mhartid;

  assign csr_rd_data = {64{~rst}} & (
      ({64{mstatus_rd_ena}}   & mstatus_rd_data)
    | ({64{misa_rd_ena}}      & misa_rd_data)
    | ({64{mie_rd_ena}}       & mie_rd_data)
    | ({64{mtvec_rd_ena}}     & mtvec_rd_data)
    | ({64{mscratch_rd_ena}}  & mscratch_rd_data)
    | ({64{mepc_rd_ena}}      & mepc_rd_data)
    | ({64{mcause_rd_ena}}    & mcause_rd_data)
    | ({64{mtval_rd_ena}}     & mtval_rd_data)
    | ({64{mip_rd_ena}}       & mip_rd_data)
    | ({64{mcycle_rd_ena}}    & mcycle_rd_data)
    | ({64{mvendorid_rd_ena}} & mvendorid_rd_data)
    | ({64{marchid_rd_ena}}   & marchid_rd_data)
    | ({64{mimpid_rd_ena}}    & mimpid_rd_data)
    | ({64{mhartid_rd_ena}}   & mhartid_rd_data)
  );

  assign csr_to_ex_diffbus = {
    mstatus_rd_data, mepc_rd_data, mtval_rd_data, mtvec_rd_data,
    mcause_rd_data, mip_rd_data, mie_rd_data, mscratch_rd_data
  };

endmodule
//--Sun Jiru, Nanjing University--

`include "defines.v"

module ex_stage_alu(
  input wire rst,
  input wire [`REG_BUS] op1,
  input wire [`REG_BUS] op2,
  input wire [`ALU_BUS] alu_info,
  input wire is_word_opt,

  output wire [`REG_BUS] alu_output,
  output wire [`BJ_BUS] bj_data
  );
  
  wire op_add  = alu_info[`ALU_ADD];
  wire op_sub  = alu_info[`ALU_SUB];
  wire op_slt  = alu_info[`ALU_SLT];
  wire op_sltu = alu_info[`ALU_SLTU];
  wire op_xor  = alu_info[`ALU_XOR];
  wire op_or   = alu_info[`ALU_OR];
  wire op_and  = alu_info[`ALU_AND];
  wire op_sll  = alu_info[`ALU_SLL];
  wire op_srl  = alu_info[`ALU_SRL];
  wire op_sra  = alu_info[`ALU_SRA];
  wire op_andn = alu_info[`ALU_ANDN];
  wire op_wri  = alu_info[`ALU_WRI];

  // left-shifter and right-shifter
  wire op_shift = op_sll | op_srl | op_sra;
  wire [`REG_BUS] shifter_op1 = op1;
  wire [`REG_BUS] shifter_in1 = {64{op_shift}} &
          //   In order to save area and just use one left-shifter, we
          //   convert the right-shift op into left-shift operation
          (
               (op_srl || op_sra) ? 
                 {
    op1[00], op1[01], op1[02], op1[03],
    op1[04], op1[05], op1[06], op1[07],
    op1[08], op1[09], op1[10], op1[11],
    op1[12], op1[13], op1[14], op1[15],
    op1[16], op1[17], op1[18], op1[19],
    op1[20], op1[21], op1[22], op1[23],
    op1[24], op1[25], op1[26], op1[27],
    op1[28], op1[29], op1[30], op1[31],
    op1[32], op1[33], op1[34], op1[35],
    op1[36], op1[37], op1[38], op1[39],
    op1[40], op1[41], op1[42], op1[43],
    op1[44], op1[45], op1[46], op1[47],
    op1[48], op1[49], op1[50], op1[51],
    op1[52], op1[53], op1[54], op1[55],
    op1[56], op1[57], op1[58], op1[59],
    op1[60], op1[61], op1[62],shifter_op1[63]
                 } : shifter_op1
          );
  wire [5 : 0] shifter_in2 = {6{op_shift}} & (is_word_opt ? {1'b0, op2[4 : 0]} : op2[5 : 0]);

  wire [`REG_BUS] shifter_res = (shifter_in1 << shifter_in2);

  wire [`REG_BUS] sll_res = shifter_res;
  wire [`REG_BUS] srl_res =  
                 {
    shifter_res[00],shifter_res[01],shifter_res[02],shifter_res[03],
    shifter_res[04],shifter_res[05],shifter_res[06],shifter_res[07],
    shifter_res[08],shifter_res[09],shifter_res[10],shifter_res[11],
    shifter_res[12],shifter_res[13],shifter_res[14],shifter_res[15],
    shifter_res[16],shifter_res[17],shifter_res[18],shifter_res[19],
    shifter_res[20],shifter_res[21],shifter_res[22],shifter_res[23],
    shifter_res[24],shifter_res[25],shifter_res[26],shifter_res[27],
    shifter_res[28],shifter_res[29],shifter_res[30],shifter_res[31],
    shifter_res[32],shifter_res[33],shifter_res[34],shifter_res[35],
    shifter_res[36],shifter_res[37],shifter_res[38],shifter_res[39],
    shifter_res[40],shifter_res[41],shifter_res[42],shifter_res[43],
    shifter_res[44],shifter_res[45],shifter_res[46],shifter_res[47],
    shifter_res[48],shifter_res[49],shifter_res[50],shifter_res[51],
    shifter_res[52],shifter_res[53],shifter_res[54],shifter_res[55],
    shifter_res[56],shifter_res[57],shifter_res[58],shifter_res[59],
    shifter_res[60],shifter_res[61],shifter_res[62],shifter_res[63]
                 };
  wire [`REG_BUS] eff_mask = (is_word_opt ? 64'hffffffff : ~(64'b0)) >> shifter_in2;
  wire [`REG_BUS] sra_res = (srl_res & eff_mask) | (
    ((is_word_opt ? {32'b0, {32{op1[31]}}} : {64{op1[63]}}) & (~eff_mask))
  );

  // add & sub operation
  wire temp_add = op_add;
  wire temp_sub = op_sub | op_slt | op_sltu;
  wire op_addsub = temp_add | temp_sub;
  wire op_unsigned = op_sltu;
  wire [64 : 0] adder_op1 = {~op_unsigned & op1[63], op1};
  wire [64 : 0] adder_op2 = {~op_unsigned & op2[63], op2};
  wire [64 : 0] adder_in1 = {65{op_addsub}} & adder_op1;
  wire [64 : 0] adder_in2 = {65{op_addsub}} & (temp_sub ? (~adder_op2) : (adder_op2));
  wire [64 : 0] adder_cin = temp_sub ? 65'b1 : 65'b0;
  wire [64 : 0] add_res   = adder_in1 + adder_in2 + adder_cin;
  wire [`REG_BUS] slt_res   = {{63{1'b0}}, (op_slt | op_sltu) & add_res[64]};
  wire [`REG_BUS] sltu_res  = slt_res;

  // logic operation
  wire [`REG_BUS] xor_res = op1 ^ op2;
  wire [`REG_BUS] or_res  = op1 | op2;
  wire [`REG_BUS] and_res = op1 & op2;
  wire [`REG_BUS] andn_res = ~op1 & op2;
  wire [`REG_BUS] wri_res = op1;

  wire [`REG_BUS] temp_output = {64{~rst}} & ( 
                      ({64{op_sll}}    & sll_res)
                    | ({64{op_srl}}    & srl_res)
                    | ({64{op_sra}}    & sra_res)
                    | ({64{op_slt}}    & slt_res)
                    | ({64{op_sltu}}   & sltu_res)
                    | ({64{op_add | op_sub}} & add_res[63 : 0])
                    | ({64{op_xor}}    & xor_res)
                    | ({64{op_or}}     & or_res)
                    | ({64{op_and}}    & and_res)
                    | ({64{op_andn}}  & andn_res)
                    | ({64{op_wri}}   & wri_res)
                      );
  assign alu_output = {is_word_opt ? {32{temp_output[31]}} : temp_output[63 : 32], temp_output[31 : 0]};
  
  wire eq_res = ~(|xor_res);
  assign bj_data[`BJ_BEQ]  = eq_res;
  assign bj_data[`BJ_BNE]  = ~eq_res;
  assign bj_data[`BJ_BLT]  = slt_res[0];
  assign bj_data[`BJ_BGE]  = ~slt_res[0];
  assign bj_data[`BJ_BLTU] = sltu_res[0];
  assign bj_data[`BJ_BGEU] = ~sltu_res[0];
  assign bj_data[`BJ_JALR] = 1'b1;
  assign bj_data[`BJ_JAL]  = 1'b1;
endmodule//branch and jump
//--Sun Jiru, Nanjing University--

`include "defines.v"

module ex_stage_bj (
  input wire rst,
  input wire ex_valid,
  input wire [`BJ_BUS] bj_info,
  input wire [`BJ_BUS] bj_data,
  input wire [`REG_BUS] jmp_imm,
  input wire [`REG_BUS] rs1_data,
  input wire [`REG_BUS] ex_pc,
  
  output wire bj_ena,
  output wire [`REG_BUS] new_pc
  );
  
  assign new_pc = jmp_imm + (bj_info[`BJ_JALR] ? rs1_data : ex_pc);
  assign bj_ena = ~rst & ex_valid & (|(bj_info & bj_data));
endmodule
//--Sun Jiru, Nanjing University--

`include "defines.v"

module ex_stage(
  input wire                              clk,
  input wire                              rst,
  
  // pipeline control
  input wire                              id_to_ex_valid,
  input wire [`REG_BUS]                   id_to_ex_pc,
  input wire [`INST_BUS]                  id_to_ex_inst,
  input wire [`ID_TO_EX_WIDTH-1:0]        id_to_ex_bus,
  output wire                             ex_allowin,

  output wire                             ex_to_mem_valid,
  output wire [`REG_BUS]                  ex_to_mem_pc,
  output wire [`INST_BUS]                 ex_to_mem_inst,
  output wire [`EX_TO_MEM_WIDTH-1:0]      ex_to_mem_bus,
  input wire                              mem_allowin,
  
  input wire [`MEM_FORWARD_WIDTH-1:0]     mem_forward_bus,
  input wire [`WB_FORWARD_WIDTH-1:0]      wb_forward_bus,
  
  input wire                              if_bj_ready,
  output wire [`BJ_CTRL_WIDTH-1:0]        bj_ctrl_bus,

  // csr control
  input wire                              csr_wr_clk,
  output wire                             csr_wr_ena,
  output wire [11 : 0]                    csr_wr_addr,
  output wire [`REG_BUS]                  csr_wr_data,

  // exception
  output wire                             excp_enter,
  output wire                             excp_exit,
  input wire [`EXCP_RD_WIDTH-1:0]         csr_excp_rd_bus,
  output wire [`EXCP_WR_WIDTH-1:0]        csr_excp_wr_bus,
  input wire [`ITRP_BUS]                  clint_interupt_bus,

  output wire                             ex_rs1_r_ena,
  output wire [4 : 0]                     ex_rs1_addr,
  output wire                             ex_rs2_r_ena,
  output wire [4 : 0]                     ex_rs2_addr,
  input wire [`REG_BUS]                   rs1_data,
  input wire [`REG_BUS]                   rs2_data,

  // difftest bus
  input wire [`ID_TO_EX_DIFF_WIDTH-1:0]   id_to_ex_diffbus,
  input wire [`CSR_TO_EX_DIFF_WIDTH-1:0]  csr_to_ex_diffbus,
  output wire [`EX_TO_MEM_DIFF_WIDTH-1:0] ex_to_mem_diffbus
  );

  // read GPRs
  assign ex_rs1_r_ena = 1'b1;
  assign ex_rs2_r_ena = 1'b1;
  
  // pipeline control
  reg ex_valid;
  wire ex_ready_go;

  reg [`REG_BUS] id_to_ex_pc_r;
  reg [`INST_BUS] id_to_ex_inst_r;
  reg [`ID_TO_EX_WIDTH-1:0] id_to_ex_bus_r;
  reg [`ID_TO_EX_DIFF_WIDTH-1:0] id_to_ex_diffbus_r;
  
  reg itrp_valid;
  wire ex_done = ~hazard;
  wire bj_handshake = ex_bj_valid && if_bj_ready;
  assign ex_ready_go = ((~(|ex_bj_info) && ~excp_jmp_ena)|| bj_handshake) && ex_done;
  assign ex_allowin = !ex_valid || ex_ready_go && mem_allowin;
  //assign ex_to_mem_valid = ex_valid && ex_ready_go && ~ex_flush;
  assign ex_to_mem_valid = (ex_valid || itrp_valid) && ex_ready_go;


  always @(posedge clk) begin
    if (rst) begin
      ex_valid <= 1'b0;
    end
    else if (ex_allowin) begin
      ex_valid <= id_to_ex_valid;
    end

    if (id_to_ex_valid && ex_allowin) begin
      id_to_ex_pc_r <= id_to_ex_pc;
      id_to_ex_inst_r <= id_to_ex_inst;
      id_to_ex_bus_r <= id_to_ex_bus;
      id_to_ex_diffbus_r <= id_to_ex_diffbus;
    end
  end
  
  always @(posedge clk) begin
    if (rst) begin
      itrp_valid <= 1'b0;
    end
    else begin
      if (itrp_valid && csr_wr_clk) begin
        itrp_valid <= 1'b0;
      end
      else if (id_to_ex_valid && ex_allowin) begin
        itrp_valid <= itrp_allowin;
      end
    end
  end

  assign ex_pc = id_to_ex_pc_r;
  assign ex_inst = id_to_ex_inst_r;
  assign {
    // serial port output
    ex_uart_out_valid, // 575:575
    
    // exception
    ex_excp_exit,   // 566:566
    ex_excp_bus,    // 565:550

    // -> ex
    ex_rs1_addr,    // 451:447
    ex_rs2_addr,    // 446:442
    ex_op1,         // 441:378
    ex_op2,         // 377:314
    ex_use_rs1,     // 313:313
    ex_use_rs2,     // 312:312
    ex_rs1_data,    // 311:248
    ex_rs2_data,    // 247:184
    ex_is_word_opt, // 183:183
    ex_alu_info,    // 182:171
    ex_bj_info,     // 170:163
    ex_jmp_imm,     // 162:99
    
    // -> mem
    ex_load_info,   // 98 :92
    ex_save_info,   // 91 :88
    ex_ram_rd_ena,  // 87 :87
    ex_ram_wr_ena,  // 86 :86
    
    // -> reg
    ex_reg_wr_ctrl, // 85: 83
    ex_reg_wr_ena,  // 82: 82
    ex_reg_wr_addr, // 81 :77

    // -> csr
    ex_csr_wr_ena,  // 76 :76
    ex_csr_wr_addr, // 75 :64
    ex_csr_rd_data  // 64 :0
  } = id_to_ex_bus_r & {`ID_TO_EX_WIDTH{ex_valid & ~itrp_valid}};
  
  wire                   ex_uart_out_valid;
  wire [7 : 0]           ex_uart_out_char = rs1_forward[7 : 0];
  wire [`INST_BUS]       ex_inst;
  wire [`REG_BUS]        ex_pc;
  wire [`REG_BUS]        ex_op1, ex_op2;
  wire                   ex_use_rs1, ex_use_rs2;
  wire [`REG_BUS]        ex_rs1_data, ex_rs2_data;
  wire                   ex_is_word_opt;
  wire [`ALU_BUS]        ex_alu_info;
  wire [`BJ_BUS]         ex_bj_info;
  wire [`REG_BUS]        ex_jmp_imm;

  wire [`LOAD_BUS]       ex_load_info;
  wire [`SAVE_BUS]       ex_save_info;
  wire                   ex_ram_rd_ena, ex_ram_wr_ena;
  
  wire [`REG_CTRL_BUS]   ex_reg_wr_ctrl;
  wire                   ex_reg_wr_ena, ex_csr_wr_ena;
  wire [4 : 0]           ex_reg_wr_addr;
  wire [11: 0]           ex_csr_wr_addr;
  wire [`REG_BUS]        ex_csr_rd_data;
  
  wire hazard;
  forward Forward(
    .ex_rs1_addr         (ex_rs1_addr),
    .ex_rs2_addr         (ex_rs2_addr),
    //.ex_rs1_data         (ex_rs1_data),
    //.ex_rs2_data         (ex_rs2_data),
    .ex_rs1_data         (rs1_data),
    .ex_rs2_data         (rs2_data),
    .ex_use_rs1          (ex_use_rs1),
    .ex_use_rs2          (ex_use_rs2),

    .mem_forward_bus     (mem_forward_bus),
    .wb_forward_bus      (wb_forward_bus),

    .rs1_forward         (rs1_forward),
    .rs2_forward         (rs2_forward),

    .hazard              (hazard)
  );
  
  assign                 excp_exit = ex_excp_exit;
  assign                 excp_enter = ex_excp_enter;

  wire [`EXCP_BUS]       ex_excp_bus;
  wire                   itrp_allowin;
  wire                   ex_excp_exit, ex_excp_enter;
  
  excp_handler Excp_handler(
    .excp_info           (ex_excp_bus),
    .itrp_info           (clint_interupt_bus),
    .now_pc              (ex_pc),
    .now_inst            (ex_inst),
    .mem_addr            (ex_data),
    .excp_exit           (ex_excp_exit),
    .excp_enter          (ex_excp_enter),
    .itrp_allowin        (itrp_allowin),
    
    // to CSRs
    .csr_excp_rd_bus     (csr_excp_rd_bus),
    .csr_excp_wr_bus     (csr_excp_wr_bus),
    
    // to if stage
    .excp_jmp_ena        (excp_jmp_ena),
    .excp_jmp_pc         (excp_jmp_pc),
    
    // to ex stage
    .itrp_valid          (itrp_valid),
    
    // to difftest
    .itrp_NO             (itrp_NO),
    .excp_NO             (excp_NO)
  );
  
  wire [`REG_BUS] rs1_forward, rs2_forward, true_op1, true_op2;
  assign true_op1 = ex_use_rs1 ? rs1_forward : ex_op1;
  assign true_op2 = ex_use_rs2 ? rs2_forward : ex_op2;
  wire [`REG_BUS] op1 = {{32{~ex_is_word_opt}} & true_op1[63 : 32], true_op1[31 : 0]};
  wire [`REG_BUS] op2 = {{32{~ex_is_word_opt}} & true_op2[63 : 32], true_op2[31 : 0]};
  
  // alu -> bj
  wire [`BJ_BUS] ex_bj_data;
  
  ex_stage_alu Exe_stage_alu(
    .rst                 (rst),
    .op1                 (op1),
    .op2                 (op2),
    .alu_info            (ex_alu_info),
    .is_word_opt         (ex_is_word_opt),
    
    .alu_output          (ex_data),
    .bj_data             (ex_bj_data)
  );
  
  ex_stage_bj Exe_stage_bj(
    .rst                 (rst),
    .ex_valid            (ex_valid),
    .bj_info             (ex_bj_info),
    .bj_data             (ex_bj_data),
    .jmp_imm             (ex_jmp_imm),
    .rs1_data            (rs1_forward),
    .ex_pc               (ex_pc),
    
    .bj_ena              (ex_bj_ena),
    .new_pc              (ex_bj_pc)
  );
  
  wire [`REG_BUS] ex_ram_wr_src = rs2_forward;
  wire [`REG_BUS] ex_data;
  assign ex_to_mem_pc = ex_pc;
  assign ex_to_mem_inst = ex_inst;
  assign ex_to_mem_bus = {
    // serial port output
    ex_uart_out_valid, // 319:319
    ex_uart_out_char,  // 318:311

    // mem
    ex_load_info,   // 214:208
    ex_save_info,   // 207:204
    ex_ram_wr_src,  // 203:140
    ex_data,        // 139:76
    ex_csr_rd_data, // 75 :12
    ex_ram_rd_ena,  // 11 :11
    ex_ram_wr_ena,  // 10 :10
    
    // wb
    ex_reg_wr_ctrl, // 9  :7
    ex_reg_wr_addr, // 6  :2
    ex_reg_wr_ena,  // 1  :1
    ex_csr_wr_ena   // 0  :0
  };

  wire [`REG_BUS]    ex_bj_pc, excp_jmp_pc;
  wire               ex_bj_ena, excp_jmp_ena;
  wire               ex_bj_valid; // 1: not finish the computation of branch
  
  assign ex_bj_valid = ~(|ex_bj_info) || ex_done;
  assign bj_ctrl_bus = {
    excp_jmp_ena ? excp_jmp_pc : ex_bj_pc,
    ex_bj_ena | excp_jmp_ena,
    ex_bj_valid
  };
  
  assign csr_wr_ena  = ex_csr_wr_ena;
  assign csr_wr_addr = ex_csr_wr_addr;
  assign csr_wr_data = ex_data;
  
  wire [`INST_BUS] itrp_NO, excp_NO;
  assign ex_to_mem_diffbus = {
    id_to_ex_diffbus_r || itrp_valid,

    csr_to_ex_diffbus,
    itrp_NO,
    excp_NO
  };

endmodule
//--Sun Jiru, Nanjing Uniersity--

`include "defines.v"

module excp_handler (
  input wire [`EXCP_BUS]             excp_info,
  input wire [`ITRP_BUS]             itrp_info,
  input wire [`REG_BUS]              now_pc,
  input wire [31 : 0]                now_inst,
  input wire [`REG_BUS]              mem_addr,
  input wire                         excp_exit,
  output wire                        excp_enter,
  output wire                        itrp_allowin,
  
  // to CSRs
  input wire [`EXCP_RD_WIDTH-1:0]    csr_excp_rd_bus,
  output wire [`EXCP_WR_WIDTH-1:0]   csr_excp_wr_bus,
  
  // to if_stage
  output wire                        excp_jmp_ena,
  output wire [`REG_BUS]             excp_jmp_pc,

  // to ex_stage
  input wire                         itrp_valid,

  // to difftest
  output wire [`INST_BUS]            itrp_NO,
  output wire [`INST_BUS]            excp_NO
  );
  
  // to CSRs
  wire [`REG_BUS] mip_wr_data, mcause_wr_data, mepc_wr_data,
                  mtval_wr_data, mstatus_wr_data;
  assign csr_excp_wr_bus = {
    mip_wr_data,      // 319:256
    mcause_wr_data,   // 255:192
    mepc_wr_data,     // 191:128
    mtval_wr_data,    // 127:64
    mstatus_wr_data   // 63 :0
  };

  // from CSRs
  wire [`REG_BUS] mstatus_rd_data, mtvec_rd_data, mepc_rd_data, mie_rd_data, mip_rd_data;
  assign {
    mstatus_rd_data,
    mtvec_rd_data,
    mepc_rd_data,
    mip_rd_data,
    mie_rd_data
  } = csr_excp_rd_bus;

  // generate excp_ena
  wire sp_excp_ena = |excp_info;
  wire sp_itrp_ena = itrp_valid;
  
  wire msie_allowin = mstatus_rd_data[3] && mie_rd_data[3]  && mip_rd_data[3];
  wire mtie_allowin = mstatus_rd_data[3] && mie_rd_data[7]  && mip_rd_data[7];
  wire meie_allowin = mstatus_rd_data[3] && mie_rd_data[11] && mip_rd_data[11];
  assign itrp_allowin = meie_allowin || mtie_allowin || msie_allowin;
  
  assign excp_enter = sp_excp_ena | sp_itrp_ena;
  
  /* ----------- Decode ----------- */
  // decode machine interruption
  wire soft_itrp  = msie_allowin && itrp_valid;
  wire timer_itrp = mtie_allowin && itrp_valid;
  wire exter_itrp = meie_allowin && itrp_valid;
  wire [62 : 0] itrp_idx = (
      ({63{soft_itrp}}       & 63'd3)
    | ({63{timer_itrp}}      & 63'd7)
    | ({63{exter_itrp}}      & 63'd11)
  );
  // decode exception
  wire excp_inst_misal = excp_info[`EXCP_INST_MISAL];
  wire excp_inst_acc = excp_info[`EXCP_INST_ACC];
  wire excp_ilg_inst = excp_info[`EXCP_ILG_INST];
  wire excp_brk_pt = excp_info[`EXCP_BRK_PT];
  wire excp_load_misal = excp_info[`EXCP_LOAD_MISAL];
  wire excp_load_acc = excp_info[`EXCP_LOAD_ACC];
  wire excp_stor_misal = excp_info[`EXCP_STOR_MISAL];
  wire excp_stor_acc = excp_info[`EXCP_STOR_ACC];
  wire excp_ecall_m = excp_info[`EXCP_ECALL_M];
  wire excp_inst_page = excp_info[`EXCP_INST_PAGE];
  wire excp_load_page = excp_info[`EXCP_LOAD_PAGE];
  wire excp_stor_page = excp_info[`EXCP_STOR_PAGE];
  wire [62 : 0] excp_idx = (
      ({63{excp_inst_misal}} & 63'd0)
    | ({63{excp_inst_acc}}   & 63'd1)
    | ({63{excp_ilg_inst}}   & 63'd2)
    | ({63{excp_brk_pt}}     & 63'd3)
    | ({63{excp_load_misal}} & 63'd4)
    | ({63{excp_load_acc}}   & 63'd5)
    | ({63{excp_stor_misal}} & 63'd6)
    | ({63{excp_stor_acc}}   & 63'd7)
    | ({63{excp_ecall_m}}    & 63'd11)
    | ({63{excp_inst_page}}  & 63'd12)
    | ({63{excp_load_page}}  & 63'd13)
    | ({63{excp_stor_page}}  & 63'd15)
  );
  wire inst_acc_fault = excp_inst_misal | excp_inst_acc | excp_inst_page ;
  wire mem_acc_fault = excp_load_misal | excp_load_acc | excp_stor_misal 
                     | excp_stor_acc | excp_load_page | excp_stor_page;
  
  assign mip_wr_data = {64{itrp_info[`TIMER_ITRP]}} & 64'h80;

  /* -----------Write CSRs----------- */
  // write mcause
  assign mcause_wr_data = { sp_itrp_ena ? 1'b1 : 1'b0,
    sp_itrp_ena ? itrp_idx : excp_idx
  };
  
  // write mepc
  assign mepc_wr_data = now_pc;
  
  // write mtval
  assign mtval_wr_data = (
      ({64{inst_acc_fault}} & now_pc)
    | ({64{excp_ilg_inst}}  & {32'b0, now_inst})
    | ({64{mem_acc_fault}}  & mem_addr)
  );
  
  // write mstatus
  wire [63 : 8] mstatus_p1 = mstatus_rd_data[63 : 8];
  wire mstatus_mpie = mstatus_rd_data[7];  // MPIE
  wire [6 : 4] mstatus_p2 = mstatus_rd_data[6 : 4];
  wire mstatus_mie = mstatus_rd_data[3];   // MIE
  wire [2 : 0] mstatus_p3 = mstatus_rd_data[2 : 0];
  wire [`REG_BUS] mstatus_excp_enter = {mstatus_p1, mstatus_mie, mstatus_p2, 1'b0, mstatus_p3};
  wire [`REG_BUS] mstatus_excp_exit = {mstatus_p1, 1'b1, mstatus_p2, mstatus_mpie, mstatus_p3};
  assign mstatus_wr_data = (
      ({64{excp_enter}} & mstatus_excp_enter)
    | ({64{excp_exit}} & mstatus_excp_exit)
  );

  /* -----------Jump control----------- */
  // load mtvec
  wire [1  : 0] mtvec_mode = mtvec_rd_data[1  : 0];
  wire mtvec_mode0 = (mtvec_mode == 2'b0);
  wire mtvec_mode1 = (mtvec_mode == 2'b1);
  wire [61 : 0] mtvec_base = mtvec_rd_data[63 : 2];
  wire [`REG_BUS] excp_enter_pc = 
      ({64{mtvec_mode0}} & {mtvec_base, 2'b0}) // mode0, jump to base
    | ({64{mtvec_mode1}} & { // mode1
           ({60{sp_excp_ena}} & mtvec_base) // when exception, jump to base
         | ({60{sp_itrp_ena}} & (mtvec_base + itrp_idx)) // when interruption, jump to base + code
        , 2'b0
      });
  wire [`REG_BUS] excp_exit_pc = mepc_rd_data;
  assign excp_jmp_ena = excp_enter | excp_exit;
  assign excp_jmp_pc = ({64{excp_enter}} & excp_enter_pc) | ({64{excp_exit}} & excp_exit_pc);
  
  /* -----------Difftest Control-----------*/
  assign itrp_NO = {32{sp_itrp_ena}} & itrp_idx [31:0];
  assign excp_NO = {32{sp_excp_ena}} & excp_idx [31:0];
endmodule//--Sun Jiru, Nanjing University--

`include "defines.v"

module forward (
  // forward control
  input wire [4 : 0]                  ex_rs1_addr,
  input wire [4 : 0]                  ex_rs2_addr,
  //input wire [12: 0] csr_addr,
  input wire [`REG_BUS]               ex_rs1_data,
  input wire [`REG_BUS]               ex_rs2_data,
  input wire                          ex_use_rs1,
  input wire                          ex_use_rs2,

  input wire [`MEM_FORWARD_WIDTH-1:0] mem_forward_bus,
  input wire [`WB_FORWARD_WIDTH-1:0]  wb_forward_bus,

  output wire [`REG_BUS]              rs1_forward,
  output wire [`REG_BUS]              rs2_forward,

  output wire                         hazard
);
  
  wire [4:0] mem_reg_wr_addr, wb_reg_wr_addr;
  wire mem_reg_wr_ena, wb_reg_wr_ena;
  wire [`REG_BUS] mem_ex_data, wb_ex_data, wb_mem_data;
  wire [`REG_CTRL_BUS] mem_reg_wr_ctrl, wb_reg_wr_ctrl;

  assign {
    mem_reg_wr_addr, // 72 :68
    mem_reg_wr_ena,  // 67 :67
    mem_ex_data,     // 66 :3
    mem_reg_wr_ctrl  // 2  :0
  } = mem_forward_bus;
  
  assign {
    wb_reg_wr_addr, // 136:132
    wb_reg_wr_ena,  // 131:131
    wb_ex_data,     // 130:67
    wb_mem_data,    // 66 :3
    wb_reg_wr_ctrl  // 2  :0
  } = wb_forward_bus;
  
  wire mem_op1_src_ex = (ex_rs1_addr == mem_reg_wr_addr) 
                        && mem_reg_wr_ena 
                        && (|ex_rs1_addr)
                        && mem_reg_wr_ctrl[`EXE_TO_REG];
  wire wb_op1_src_ex = (ex_rs1_addr == wb_reg_wr_addr) 
                        && wb_reg_wr_ena 
                        && (|ex_rs1_addr)
                        && wb_reg_wr_ctrl[`EXE_TO_REG];
  wire mem_op1_src_mem = (ex_rs1_addr == mem_reg_wr_addr) 
                        && mem_reg_wr_ena 
                        && (|ex_rs1_addr)
                        && mem_reg_wr_ctrl[`MEM_TO_REG];
  wire wb_op1_src_mem = (ex_rs1_addr == wb_reg_wr_addr) 
                        && wb_reg_wr_ena 
                        && (|ex_rs1_addr)
                        && wb_reg_wr_ctrl[`MEM_TO_REG];
  assign rs1_forward = (mem_op1_src_ex) ? mem_ex_data :
                       (wb_op1_src_ex)  ? wb_ex_data  :
                       (wb_op1_src_mem) ? wb_mem_data :
                       ex_rs1_data;

  /* test wires begin */
  wire test_eq     = (ex_rs1_addr == mem_reg_wr_addr);
  wire test_wr_ena = mem_reg_wr_ena;
  wire test_rs1    = (|ex_rs1_addr);
  wire test_wr_src = mem_reg_wr_ctrl[`MEM_TO_REG];
  /* test wires end */

  wire mem_op2_src_ex = (ex_rs2_addr == mem_reg_wr_addr) 
                        && mem_reg_wr_ena 
                        && (|ex_rs2_addr)
                        && mem_reg_wr_ctrl[`EXE_TO_REG];
  wire wb_op2_src_ex = (ex_rs2_addr == wb_reg_wr_addr) 
                        && wb_reg_wr_ena 
                        && (|ex_rs2_addr)
                        && wb_reg_wr_ctrl[`EXE_TO_REG];
  wire mem_op2_src_mem = (ex_rs2_addr == mem_reg_wr_addr) 
                        && mem_reg_wr_ena 
                        && (|ex_rs2_addr)
                        && mem_reg_wr_ctrl[`MEM_TO_REG];
  wire wb_op2_src_mem = (ex_rs2_addr == wb_reg_wr_addr) 
                        && wb_reg_wr_ena 
                        && (|ex_rs2_addr)
                        && wb_reg_wr_ctrl[`MEM_TO_REG];
  assign rs2_forward = (mem_op2_src_ex) ? mem_ex_data :
                       (wb_op2_src_ex)  ? wb_ex_data  :
                       (wb_op2_src_mem) ? wb_mem_data :
                       ex_rs2_data;
  
  assign hazard = mem_op1_src_mem || mem_op2_src_mem;
endmodule
/* verilator lint_off UNDRIVEN */
/* verilator lint_off UNUSED */
//--Sun Jiru, Nanjing University--

`include "defines.v"

module id_stage(
  input wire                             rst,
  input wire                             clk,

  // pipeline control
  input wire                             if_to_id_valid,
  input wire [`REG_BUS]                  if_to_id_pc,
  input wire [`INST_BUS]                 if_to_id_inst,
  output wire                            id_allowin,

  output wire                            id_to_ex_valid,
  output wire [`REG_BUS]                 id_to_ex_pc,
  output wire [`INST_BUS]                id_to_ex_inst,
  output wire [`ID_TO_EX_WIDTH-1:0]      id_to_ex_bus,
  input wire                             ex_allowin,

  // data from regfile and CSRs
//  input wire [`REG_BUS]             r_data1,
//  input wire [`REG_BUS]             r_data2,
  input wire [`REG_BUS]                  csr_data,
  
  // control reg
//  output wire                       rs1_r_ena,
//  output wire [4 : 0]               rs1_addr,
//  output wire                       rs2_r_ena,
//  output wire [4 : 0]               rs2_addr,

  // control csr
  output wire                            csr_rd_ena,
  output wire [11: 0]                    csr_rd_addr,

  input wire [`BJ_CTRL_WIDTH-1:0]        bj_ctrl_bus,

  output wire [`ID_TO_EX_DIFF_WIDTH-1:0] id_to_ex_diffbus
);

  wire [`REG_BUS] r_data1 = 64'b0;
  wire [`REG_BUS] r_data2 = 64'b0;
  wire                       rs1_r_ena;
  wire [4 : 0]               rs1_addr;
  wire                       rs2_r_ena;
  wire [4 : 0]               rs2_addr;

  wire [`REG_BUS] bj_pc;
  wire            bj_ena, bj_valid;
  assign {
    bj_pc,    // 65:2
    bj_ena,   // 1 :1
    bj_valid  // 0 :0
  } = bj_ctrl_bus;

  // pipeline control
  reg id_valid;
  wire id_ready_go;
  wire id_flush = bj_ena;
  reg [`REG_BUS] if_to_id_pc_r;
  reg [`INST_BUS] if_to_id_inst_r;

  assign id_ready_go = 1'b1;
  assign id_allowin = !id_valid || id_ready_go && ex_allowin;
  assign id_to_ex_valid = id_valid && id_ready_go && ~id_flush;

  always @(posedge clk) begin
    if (rst) begin
      id_valid <= 1'b0;
    end
    else if (id_allowin) begin
      id_valid <= if_to_id_valid;
    end
    else if (id_flush) begin // not allowin, and flush happen
      id_valid <= 1'b0;
    end
    
    if (if_to_id_valid && id_allowin) begin
      if_to_id_pc_r <= if_to_id_pc;
      if_to_id_inst_r <= if_to_id_inst;
    end
  end
  
  
  wire [`REG_BUS]  id_pc   = if_to_id_pc_r;
  wire [`INST_BUS] id_inst = if_to_id_inst_r;
  
  // decode
  wire [6  : 0] opcode = id_inst[6 : 0];
  wire [2  : 0] func3  = id_inst[14 : 12];
  wire [5  : 0] func6  = id_inst[31 : 26];
  wire [6  : 0] func7  = id_inst[31 : 25];
  wire [4  : 0] zimm = id_inst[19 : 15];
  
  assign rs1_addr = inst_putch ? 5'b01010 : {5{rs1_r_ena}} & id_inst[19 : 15];
  assign rs2_addr = {5{rs2_r_ena}} & id_inst[24 : 20];
  wire [11 : 0] id_csr_addr = id_inst[31 : 20];
  assign csr_rd_addr = id_csr_addr;
  wire [4  : 0] rd_addr = id_inst[11 : 7];
  
  wire [11 : 0] immI = id_csr_addr;
  wire [11 : 0] immS = {func7, id_inst[11 :  7]};
  wire [12 : 0] immB = {id_inst[31], id_inst[7], id_inst[30 : 25], id_inst[11 : 8], 1'b0};
  wire [19 : 0] immU = id_inst[31 : 12];
  wire [20 : 0] immJ = {id_inst[31], id_inst[19 : 12], id_inst[20], id_inst[30 : 21], 1'b0};
  
  // decode func3
  wire func3_0 = (func3 == 3'h0);
  wire func3_1 = (func3 == 3'h1);
  wire func3_2 = (func3 == 3'h2);
  wire func3_3 = (func3 == 3'h3);
  wire func3_4 = (func3 == 3'h4);
  wire func3_5 = (func3 == 3'h5);
  wire func3_6 = (func3 == 3'h6);
  wire func3_7 = (func3 == 3'h7);
  
  // decode func6
  wire func6_00 = (func6 == 6'h00);
  wire func6_10 = (func6 == 6'h10);
  
  // decode func7
  wire func7_00 = (func7 == 7'h00);
  wire func7_20 = (func7 == 7'h20);
  
  // decode imm12
  wire imm12_000 = (immI == 12'h000);
  wire imm12_001 = (immI == 12'h001);
  wire imm12_302 = (immI == 12'h302);
  
  // decode type
  wire inst_i_load        = (opcode == 7'h03);
  wire inst_i_fence       = (opcode == 7'h0f);
  wire inst_i_arith_dword = (opcode == 7'h13);
  wire inst_u_auipc       = (opcode == 7'h17);
  wire inst_i_arith_word  = (opcode == 7'h1b);
  wire inst_s             = (opcode == 7'h23);
  wire inst_r_dword       = (opcode == 7'h33);
  wire inst_u_lui         = (opcode == 7'h37);
  wire inst_r_word        = (opcode == 7'h3b);
  wire inst_b             = (opcode == 7'h63);
  wire inst_i_jalr        = (opcode == 7'h67);
  wire inst_j             = (opcode == 7'h6f);
  wire inst_i_sys         = (opcode == 7'h73);
  wire inst_i_excp        = inst_i_sys & func3_0;
  wire inst_i_csr_imm     = inst_i_sys & (func3[2] == 1) & ~func3_0;
  wire inst_i_csr_reg     = inst_i_sys & (func3[2] == 0) & ~func3_0;
  //wire inst_t             = (opcode == 7'h6b); // signal of termination
  wire inst_putch         = (opcode == 7'h7b); //signal of putch

  wire is_word_opt = inst_r_word | inst_i_arith_word;

  // decode arithmetic
  // load
  wire inst_lb      = inst_i_load & func3_0;
  wire inst_lh      = inst_i_load & func3_1;
  wire inst_lw      = inst_i_load & func3_2;
  wire inst_ld      = inst_i_load & func3_3;
  wire inst_lbu     = inst_i_load & func3_4;
  wire inst_lhu     = inst_i_load & func3_5;
  wire inst_lwu     = inst_i_load & func3_6;
  wire load_vld     = inst_lb | inst_lh | inst_lw | inst_ld 
                    | inst_lbu | inst_lhu | inst_lwu;
  
  // fence
  wire inst_fence   = inst_i_fence & func3_0;
  wire inst_fence_i = inst_i_fence & func3_1;
  wire fence_vld    = inst_fence | inst_fence_i;
  
  // arith-i-dword
  wire inst_addi    = inst_i_arith_dword & func3_0;
  wire inst_slli    = inst_i_arith_dword & func3_1 & func6_00;
  wire inst_slti    = inst_i_arith_dword & func3_2;
  wire inst_sltiu   = inst_i_arith_dword & func3_3;
  wire inst_xori    = inst_i_arith_dword & func3_4;
  wire inst_srli    = inst_i_arith_dword & func3_5 & func6_00;
  wire inst_srai    = inst_i_arith_dword & func3_5 & func6_10;
  wire inst_ori     = inst_i_arith_dword & func3_6;
  wire inst_andi    = inst_i_arith_dword & func3_7;
  wire arith_id_vld = inst_addi | inst_slli | inst_slti | inst_sltiu 
                    | inst_xori | inst_srli | inst_srai | inst_ori
                    | inst_andi;
  
  // auipc
  wire inst_auipc   = inst_u_auipc;
  wire auipc_vld    = inst_auipc;
  
  // arith-i-word
  wire inst_addiw   = inst_i_arith_word & func3_0;
  wire inst_slliw   = inst_i_arith_word & func3_1;
  wire inst_srliw   = inst_i_arith_word & func3_5 & func6_00;
  wire inst_sraiw   = inst_i_arith_word & func3_5 & func6_10;
  wire arith_iw_vld = inst_addiw | inst_slliw | inst_srliw | inst_sraiw;
  
  // store
  wire inst_sb      = inst_s & func3_0;
  wire inst_sh      = inst_s & func3_1;
  wire inst_sw      = inst_s & func3_2;
  wire inst_sd      = inst_s & func3_3;
  wire store_vld    = inst_sb | inst_sh | inst_sw | inst_sd;
  
  // arith-r-dword
  wire inst_add     = inst_r_dword & func3_0 & func7_00;
  wire inst_sub     = inst_r_dword & func3_0 & func7_20;
  wire inst_sll     = inst_r_dword & func3_1;
  wire inst_slt     = inst_r_dword & func3_2;
  wire inst_sltu    = inst_r_dword & func3_3;
  wire inst_xor     = inst_r_dword & func3_4;
  wire inst_srl     = inst_r_dword & func3_5 & func7_00;
  wire inst_sra     = inst_r_dword & func3_5 & func7_20;
  wire inst_or      = inst_r_dword & func3_6;
  wire inst_and     = inst_r_dword & func3_7;
  wire arith_rd_vld = inst_add  | inst_sub | inst_sll | inst_slt 
                    | inst_sltu | inst_xor | inst_srl | inst_sra
                    | inst_or   | inst_and;
  
  // lui
  wire inst_lui     = inst_u_lui;
  wire lui_vld      = inst_lui;
  
  // arith-r-word
  wire inst_addw    = inst_r_word & func3_0 & func7_00;
  wire inst_subw    = inst_r_word & func3_0 & func7_20;
  wire inst_sllw    = inst_r_word & func3_1;
  wire inst_srlw    = inst_r_word & func3_5 & func7_00;
  wire inst_sraw    = inst_r_word & func3_5 & func7_20;
  wire arith_rw_vld = inst_addw | inst_subw | inst_sllw 
                    | inst_srlw | inst_sraw;

  // branch
  wire inst_beq     = inst_b & func3_0;
  wire inst_bne     = inst_b & func3_1;
  wire inst_blt     = inst_b & func3_4;
  wire inst_bge     = inst_b & func3_5;
  wire inst_bltu    = inst_b & func3_6;
  wire inst_bgeu    = inst_b & func3_7;
  wire branch_vld   = inst_beq | inst_bne  | inst_blt 
                    | inst_bge | inst_bltu | inst_bgeu;
  
  // jump
  wire inst_jalr    = inst_i_jalr;
  wire inst_jal     = inst_j;
  wire jump_vld     = inst_jalr | inst_jal;
  
  // exception
  wire inst_ecall   = inst_i_excp    & imm12_000;
  wire inst_ebreak  = inst_i_excp    & imm12_001;
  wire inst_mret    = inst_i_excp    & imm12_302;
  wire excp_vld     = inst_ecall | inst_ebreak | inst_mret;
  
  // csr
  wire inst_csrrw   = inst_i_csr_reg & func3_1;
  wire inst_csrrs   = inst_i_csr_reg & func3_2;
  wire inst_csrrc   = inst_i_csr_reg & func3_3;
  wire inst_csrrwi  = inst_i_csr_imm & func3_5;
  wire inst_csrrsi  = inst_i_csr_imm & func3_6;
  wire inst_csrrci  = inst_i_csr_imm & func3_7;
  wire csr_vld      = inst_csrrw  | inst_csrrs  | inst_csrrc
                    | inst_csrrwi | inst_csrrsi | inst_csrrci;
  
  wire inst_vld     = load_vld | fence_vld | arith_id_vld | auipc_vld
                    | arith_iw_vld | store_vld | arith_rd_vld | lui_vld
                    | arith_rw_vld | branch_vld | jump_vld | excp_vld
                    | csr_vld;

  wire [`ALU_BUS] id_alu_info;
  assign id_alu_info[`ALU_ADD]  = inst_add   | inst_addi   | inst_addw  | inst_addiw 
                             | inst_auipc | inst_lui    | inst_i_load | inst_s 
                             | inst_jal   | inst_jalr;
  assign id_alu_info[`ALU_SUB]  = inst_sub   | inst_subw   | inst_b;
  assign id_alu_info[`ALU_SLT]  = inst_slt   | inst_slti   | inst_blt   | inst_bge;
  assign id_alu_info[`ALU_SLTU] = inst_sltu  | inst_sltiu  | inst_bltu  | inst_bgeu;
  assign id_alu_info[`ALU_XOR]  = inst_xor   | inst_xori   | inst_beq   | inst_bne;
  assign id_alu_info[`ALU_OR]   = inst_or    | inst_ori    | inst_csrrs | inst_csrrsi;
  assign id_alu_info[`ALU_AND]  = inst_and   | inst_andi;
  assign id_alu_info[`ALU_SLL]  = inst_sll   | inst_slli   | inst_sllw  | inst_slliw;
  assign id_alu_info[`ALU_SRL]  = inst_srl   | inst_srli   | inst_srlw  | inst_srliw;
  assign id_alu_info[`ALU_SRA]  = inst_sra   | inst_srai   | inst_sraw  | inst_sraiw;
  assign id_alu_info[`ALU_ANDN] = inst_csrrc | inst_csrrci;
  assign id_alu_info[`ALU_WRI]  = inst_csrrw | inst_csrrwi;
  
  wire [`BJ_BUS] id_bj_info;
  assign id_bj_info[`BJ_BEQ]  = inst_beq;
  assign id_bj_info[`BJ_BNE]  = inst_bne;
  assign id_bj_info[`BJ_BLT]  = inst_blt;
  assign id_bj_info[`BJ_BGE]  = inst_bge;
  assign id_bj_info[`BJ_BLTU] = inst_bltu;
  assign id_bj_info[`BJ_BGEU] = inst_bgeu;
  assign id_bj_info[`BJ_JALR] = inst_jalr;
  assign id_bj_info[`BJ_JAL]  = inst_jal;
  
  wire [`LOAD_BUS] id_load_info = {
    inst_lwu, inst_lhu, inst_lbu, inst_ld, inst_lw, inst_lh, inst_lb
  };
  
  wire [`SAVE_BUS] id_save_info = {
    inst_sd, inst_sw, inst_sh, inst_sb
  };
  
  assign rs1_r_ena  = ~rst & (inst_i_load | inst_i_fence | inst_i_arith_dword 
                            | inst_i_arith_word | inst_s | inst_r_dword 
                            | inst_r_word | inst_b | inst_i_jalr | inst_i_csr_reg
                            | inst_putch);
  assign rs2_r_ena  = ~rst & (inst_r_dword | inst_r_word | inst_s | inst_b);
  assign csr_rd_ena = csr_vld;
  
  wire [4 : 0] reg_wr_addr = (reg_wr_ena == 1'b1) ? rd_addr : 0;
  
  wire mem_wr_ena = ~rst & inst_s;
  wire mem_rd_ena = ~rst & inst_i_load;
  
  wire [`REG_BUS] id_op1 = {64{~rst}} & (
                  ({64{inst_i_load}}        & r_data1)
                | ({64{inst_i_fence}}       & r_data1)
                | ({64{inst_i_arith_dword}} & r_data1)
                | ({64{inst_u_auipc}}       & id_pc)
                | ({64{inst_i_arith_word}}  & r_data1)
                | ({64{inst_s}}             & r_data1)
                | ({64{inst_r_dword}}       & r_data1)
                | ({64{inst_u_lui}}         & 64'b0)
                | ({64{inst_r_word}}        & r_data1)
                | ({64{inst_b}}             & r_data1)
                | ({64{inst_i_jalr}}        & id_pc)
                | ({64{inst_jal}}           & id_pc)
                | ({64{inst_i_csr_imm}}     & {59'b0, zimm})
                | ({64{inst_i_csr_reg}}     & r_data1)
               );
  wire id_use_rs1 = inst_i_load | inst_i_fence | inst_i_arith_dword
                  | inst_i_arith_word | inst_s | inst_r_dword
                  | inst_r_word | inst_b | inst_i_csr_reg;
  wire [`REG_BUS] id_rs1_data = r_data1;
  
  wire [`REG_BUS] id_op2 = {64{~rst}} & (
                  ({64{inst_i_load}}        & {{52{immI[11]}}, immI})
                | ({64{inst_i_fence}}       & {{52{immI[11]}}, immI})
                | ({64{inst_i_arith_dword}} & {{52{immI[11]}}, immI})
                | ({64{inst_u_auipc}}       & {{32{immU[19]}}, immU, 12'b0})
                | ({64{inst_i_arith_word}}  & {{52{immI[11]}}, immI})
                | ({64{inst_s}}             & {{52{immS[11]}}, immS})
                | ({64{inst_r_dword}}       & r_data2)
                | ({64{inst_u_lui}}         & {{32{immU[19]}}, immU, 12'b0})
                | ({64{inst_r_word}}        & r_data2)
                | ({64{inst_b}}             & r_data2)
                | ({64{inst_i_jalr}}        & 64'h4)
                | ({64{inst_jal}}           & 64'h4)
                | ({64{inst_i_csr_imm}}     & csr_data)
                | ({64{inst_i_csr_reg}}     & csr_data)
               );
  wire id_use_rs2 = inst_r_dword | inst_r_word | inst_b;
  wire id_use_csr = inst_i_csr_imm | inst_i_csr_reg;
  wire [`REG_BUS] id_rs2_data = r_data2;
  
  wire [`REG_BUS] id_jmp_imm = ({64{inst_b}}      & {{51{immB[12]}}, immB})
                 | ({64{inst_j}}       & {{43{immJ[20]}}, immJ})
                 | ({64{inst_i_jalr}}  & {{52{immI[11]}}, immI});
  //               | ({64{inst_t}}       & 64'b0);
  
  // data to wb_stage
  wire csr_to_reg = ~rst & (inst_i_csr_imm | inst_i_csr_reg);
  wire mem_to_reg = ~rst & inst_i_load;
  wire exe_to_reg = ~rst & (
      inst_i_fence | inst_i_arith_dword | inst_u_auipc 
    | inst_i_arith_word | inst_r_dword | inst_u_lui
    | inst_r_word | inst_jal | inst_i_jalr
  );
  wire [`REG_CTRL_BUS] reg_wr_ctrl = {
    csr_to_reg,
    mem_to_reg,
    exe_to_reg
  };
  
  wire reg_wr_ena  = ~rst & (
      inst_i_load | inst_i_fence | inst_i_arith_dword
    | inst_u_auipc | inst_i_arith_word | inst_r_dword
    | inst_u_lui | inst_r_word | inst_i_jalr | inst_j
    | inst_i_csr_imm | inst_i_csr_reg
  );
  wire [4 : 0] reg_wr_addr = id_inst[11 :  7];
  wire csr_wr_ena  = ~rst & (inst_i_csr_imm | inst_i_csr_reg);
  wire [11: 0] csr_wr_addr = id_inst[31 : 20];
  
  wire [`EXCP_BUS] id_excp_bus;
  wire id_excp_exit = inst_mret;
  assign id_excp_bus[`EXCP_BRK_PT]  = inst_ebreak;
  assign id_excp_bus[`EXCP_ECALL_M] = inst_ecall;
  
  wire id_uart_out_valid = inst_putch;
 
  assign id_to_ex_pc = id_pc;
  assign id_to_ex_inst = id_inst;
  assign id_to_ex_bus = {
    // serial port output
    id_uart_out_valid, // 567:567
    
    // exception
    id_excp_exit,      // 566:566
    id_excp_bus,       // 565:550

    // -> ex
    rs1_addr,          // 451:447
    rs2_addr,          // 446:442
    id_op1,            // 441:378
    id_op2,            // 377:314
    id_use_rs1,        // 313:313
    id_use_rs2,        // 312:312
    id_rs1_data,       // 311:248
    id_rs2_data,       // 247:184
    is_word_opt,       // 183:183
    id_alu_info,       // 182:171
    id_bj_info,        // 170:163
    id_jmp_imm,        // 162:99
    
    // -> mem
    id_load_info,      // 98 :92
    id_save_info,      // 91 :88
    mem_rd_ena,        // 87 :87
    mem_wr_ena,        // 86 :86
    
    // -> wb
    reg_wr_ctrl,       // 85: 83
    reg_wr_ena,        // 82: 82
    reg_wr_addr,       // 81 :77
    csr_wr_ena,        // 76 :76
    csr_wr_addr,       // 75 :64
    csr_data           // 64 :0
  };
  
  wire id_skip_instr = inst_putch || (csr_vld && (csr_rd_addr == 12'hB00 || csr_rd_addr == 12'h344));
  assign id_to_ex_diffbus = (
    id_skip_instr
  );
endmodule

/* verilator lint_off UNUSED */
//--Sun Jiru, Nanjing University--

`include "defines.v"

module if_stage(
  input wire                          clk,
  input wire                          rst,
  
  // pipeline control
  output wire                         if_to_id_valid,
  output wire [`REG_BUS]              if_to_id_pc,
  output wire [`INST_BUS]             if_to_id_inst,
  input wire                          id_allowin,
  
  // branch and jump control
  output wire                         if_bj_ready,
  input wire [`BJ_CTRL_WIDTH-1:0]     bj_ctrl_bus,
  //input wire                          excp_jmp_ena,
  //input wire [`REG_BUS]               excp_pc,

  // AXI4
  output wire                         if_axi_valid, // master is valid
  input wire                          if_axi_ready, // slave is ready
  input wire [`REG_BUS]               if_axi_data_read,
  output reg [`REG_BUS]               if_axi_addr,
  output wire [1:0]                   if_axi_size,
  input wire [1:0]                    if_axi_resp
  );
  
  wire [`REG_BUS] bj_pc;
  wire            bj_ena, bj_valid;
  assign {
    bj_pc,    // 65:2
    bj_ena,   // 1 :1
    bj_valid  // 0 :0
  } = bj_ctrl_bus;

  // pre-IF stage
  wire pre_valid = 1'b1;
  wire pre_ready_go = if_state == RETN;
  wire pre_to_if_valid = pre_valid && pre_ready_go;
  wire [`REG_BUS] next_pc = /*excp_jmp_ena ? excp_pc :*/
                            bj_ena       ? bj_pc   :
                            (if_pc + 4);
  
  // fetch an instruction
  assign if_axi_valid = if_state == ADDR;
  wire   if_handshake = if_axi_valid & if_axi_ready;
  
  assign if_axi_size = `SIZE_W;
  assign if_bj_ready = if_state == IDLE;
  wire bj_handshake = if_bj_ready & bj_valid;
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
      IDLE: begin
        if_next_state = bj_handshake ? ADDR : IDLE;
      end
      ADDR:
        if_next_state = if_handshake ? RETN : ADDR;
      RETN:
        if_next_state = (pre_to_if_valid && if_allowin) ? IDLE : RETN;
      default:
        if_next_state = IDLE;
    endcase
  end
  
  always @(posedge clk) begin
    if (if_state == IDLE)
      if_axi_addr <= next_pc;
  end

  // IF stage
  
  // pipeline control
  reg if_valid;
  wire if_ready_go;
  wire if_flush = bj_ena;
  wire if_allowin;
  
  assign if_ready_go    = 1'b1;
  assign if_allowin     = !if_valid || if_ready_go && id_allowin;
  assign if_to_id_valid = if_valid && if_ready_go && ~if_flush;
  
  always @(posedge clk) begin
    if (rst) begin
      if_valid <= 1'b0;
    end
    else if (if_allowin) begin
      if_valid <= pre_to_if_valid;
    end
    else if (if_flush) begin
      if_valid <= 1'b0;
    end
  end
  
  reg [`REG_BUS] if_pc;
  reg [31 : 0]   if_inst;
  
  always @(posedge clk) begin
    if (rst) begin
      if_pc <= 64'h7ffffffc;
    end
    else if (pre_to_if_valid && if_allowin) begin
      if_pc <= if_axi_addr;
      if_inst <= if_axi_data_read[31 : 0]; // this inst
    end
  end

  assign if_to_id_pc = if_pc;
  assign if_to_id_inst = if_inst;
endmodule
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
  
  wire debug = mem_rw_addr[63:4] == 56'h00000000_801cc68;

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
  wire             mem_reg_wr_ena, mem_csr_wr_ena;
  
  assign mem_pc = ex_to_mem_pc_r;
  assign mem_inst = ex_to_mem_inst_r;
  assign {
    mem_uart_out_valid, // 319:319
    mem_uart_out_char,  // 318:311

    // mem
    mem_load_info,   // 214:208
    mem_save_info,   // 207:204
    mem_ram_wr_src,  // 203:140
    mem_addr,        // 139:76
    mem_csr_rd_data,    // 75 :12
    mem_ram_rd_ena,  // 11 :11
    mem_ram_wr_ena,  // 10 :10
    
    // wb
    mem_reg_wr_ctrl, // 9  :7
    mem_reg_wr_addr, // 6  :2
    mem_reg_wr_ena,  // 1  :1
    mem_csr_wr_ena   // 0  :0
  } = ex_to_mem_bus_r & {`EX_TO_MEM_WIDTH{mem_valid}};
  wire ex_ram_rd_ena = ex_to_mem_bus[11];
  wire ex_ram_wr_ena = ex_to_mem_bus[10];
  wire refresh = ex_to_mem_valid && mem_allowin;
  wire mem_handshake = mem_rw_valid && mem_rw_ready;

  wire op_sb = mem_save_info[`SAVE_SB];
  wire op_sh = mem_save_info[`SAVE_SH];
  wire op_sw = mem_save_info[`SAVE_SW];
  wire op_sd = mem_save_info[`SAVE_SD];

  wire op_lb  = mem_load_info[`LOAD_LB];
  wire op_lh  = mem_load_info[`LOAD_LH];
  wire op_lw  = mem_load_info[`LOAD_LW];
  wire op_ld  = mem_load_info[`LOAD_LD];
  wire op_lbu = mem_load_info[`LOAD_LBU];
  wire op_lhu = mem_load_info[`LOAD_LHU];
  wire op_lwu = mem_load_info[`LOAD_LWU];
  
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
      ADDR:
        if (mem_handshake) begin
          mem_next_state = RETN;
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
      default:
        mem_next_state = IDLE;
    endcase
  end

  assign mem_rw_valid = mem_state == ADDR;
  assign mem_rw_req = mem_ram_wr_ena;
  assign mem_w_data = mem_ram_wr_src & (
      ({64{op_sb}} & 64'hff)
    | ({64{op_sh}} & 64'hffff)
    | ({64{op_sw}} & 64'hffffffff)
    | ({64{op_sd}} & 64'hffffffffffffffff)
  );
  assign mem_rw_addr = mem_addr;
  assign mem_rw_size = (
      ({2{op_sb || op_lb || op_lbu}} & `SIZE_B)
    | ({2{op_sh || op_lh || op_lhu}} & `SIZE_H)
    | ({2{op_sw || op_lw || op_lwu}} & `SIZE_W)
    | ({2{op_sd || op_ld          }} & `SIZE_D)
  );
  

  reg[`REG_BUS] mem_data;
  always @(posedge clk) begin
    if (mem_handshake) begin
      mem_data <= (
          ({64{op_lb}} & {{56{mem_r_data[7 ]}}, mem_r_data[7  : 0]})
        | ({64{op_lh}} & {{48{mem_r_data[15]}}, mem_r_data[15 : 0]})
        | ({64{op_lw}} & {{32{mem_r_data[31]}}, mem_r_data[31 : 0]})
        | ({64{op_ld}} & mem_r_data)
        | ({64{op_lbu}} & {56'b0, mem_r_data[7  : 0]})
        | ({64{op_lhu}} & {48'b0, mem_r_data[15 : 0]})
        | ({64{op_lwu}} & {32'b0, mem_r_data[31 : 0]})
      );
    end
  end

  wire mem_finish = mem_state == RETN;
  wire [`REG_BUS] mem_ex_data = mem_addr;
  
  // difftest
  wire size_b = mem_rw_size == `SIZE_B;
  wire size_h = mem_rw_size == `SIZE_H;
  wire size_w = mem_rw_size == `SIZE_W;
  wire size_d = mem_rw_size == `SIZE_D;
  wire addr0 = mem_rw_addr[2:0] == 3'b000;
  wire addr1 = mem_rw_addr[2:0] == 3'b001;
  wire addr2 = mem_rw_addr[2:0] == 3'b010;
  wire addr3 = mem_rw_addr[2:0] == 3'b011;
  wire addr4 = mem_rw_addr[2:0] == 3'b100;
  wire addr5 = mem_rw_addr[2:0] == 3'b101;
  wire addr6 = mem_rw_addr[2:0] == 3'b110;
  wire addr7 = mem_rw_addr[2:0] == 3'b111;
  wire            difftest_s_valid = |mem_save_info;
  wire            difftest_l_valid = |mem_load_info;
  wire [`REG_BUS] difftest_addr = {mem_addr[63:3], 3'b0};
  wire [`REG_BUS] difftest_data = (
      ({64{size_b}} & {8{mem_w_data[7 :0]}})
    | ({64{size_h}} & {4{mem_w_data[15:0]}})
    | ({64{size_w}} & {2{mem_w_data[31:0]}})
    | ({64{size_d}} & {1{mem_w_data[63:0]}})
  ) & (
      {64{addr0 && size_d}} & 64'hffffffffffffffff
    | {64{addr0 && size_w}} & 64'h00000000ffffffff
    | {64{addr0 && size_h}} & 64'h000000000000ffff
    | {64{addr0 && size_b}} & 64'h00000000000000ff
    | {64{addr1 && size_b}} & 64'h000000000000ff00
    | {64{addr2 && size_h}} & 64'h00000000ffff0000
    | {64{addr2 && size_b}} & 64'h0000000000ff0000
    | {64{addr3 && size_b}} & 64'h00000000ff000000
    | {64{addr4 && size_w}} & 64'hffffffff00000000
    | {64{addr4 && size_h}} & 64'h0000ffff00000000
    | {64{addr4 && size_b}} & 64'h000000ff00000000
    | {64{addr5 && size_b}} & 64'h0000ff0000000000
    | {64{addr6 && size_h}} & 64'hffff000000000000
    | {64{addr6 && size_b}} & 64'h00ff000000000000
    | {64{addr7 && size_b}} & 64'hff00000000000000
  );
  wire [7:0]      difftest_mask = (
      ({8{size_b}} & 8'b00000001)
    | ({8{size_h}} & 8'b00000011)
    | ({8{size_w}} & 8'b00001111)
    | ({8{size_d}} & 8'b11111111)
  ) << mem_addr[2:0];
  assign mem_to_wb_diffbus = {
    ex_to_mem_diffbus_r,

    difftest_addr,      // 137:74
    difftest_data,      // 73 :10
    difftest_mask,      // 9  :2
    difftest_s_valid,   // 1  :1
    difftest_l_valid    // 0  :0
  };

  assign mem_to_wb_pc = mem_pc;
  assign mem_to_wb_inst = mem_inst;
  assign mem_to_wb_bus = {
    // serial port output
    mem_uart_out_valid, // 305:305
    mem_uart_out_char,  // 304:297

    // wb stage
    mem_reg_wr_ena,  // 200:200
    mem_reg_wr_addr, // 199:195
    mem_reg_wr_ctrl, // 194:192
    mem_ex_data,     // 191:0
    mem_data,        // 127:0
    mem_csr_rd_data  // 63 :0
  };

  assign mem_forward_bus = {
    mem_reg_wr_addr, // 72 :68
    mem_reg_wr_ena,  // 67 :67
    mem_ex_data,     // 66 :3
    mem_reg_wr_ctrl  // 2  :0
  };
endmodule
//--Sun Jiru, Nanjing University--

`include "defines.v"

module regfile(
  input  wire clk,
  input  wire rst,
	
	input  wire [4  : 0] w_addr,
	input  wire [`REG_BUS] w_data,
  input  wire w_ena,
	
	input  wire [4  : 0] r_addr1,
	output wire [`REG_BUS] r_data1,
	input  wire r_ena1,
	
	input  wire [4  : 0] r_addr2,
	output wire [`REG_BUS] r_data2,
	input  wire r_ena2,

	output wire [`REG_BUS] regs_o[0:31]
  );

    // 32 registers
	reg [`REG_BUS] 	regs[0 : 31];

	always @(posedge clk) 
	begin
		if ( rst == 1'b1 ) 
		begin
			regs[ 0] <= `ZERO_WORD;
			regs[ 1] <= `ZERO_WORD;
			regs[ 2] <= `ZERO_WORD;
			regs[ 3] <= `ZERO_WORD;
			regs[ 4] <= `ZERO_WORD;
			regs[ 5] <= `ZERO_WORD;
			regs[ 6] <= `ZERO_WORD;
			regs[ 7] <= `ZERO_WORD;
			regs[ 8] <= `ZERO_WORD;
			regs[ 9] <= `ZERO_WORD;
			regs[10] <= `ZERO_WORD;
			regs[11] <= `ZERO_WORD;
			regs[12] <= `ZERO_WORD;
			regs[13] <= `ZERO_WORD;
			regs[14] <= `ZERO_WORD;
			regs[15] <= `ZERO_WORD;
			regs[16] <= `ZERO_WORD;
			regs[17] <= `ZERO_WORD;
			regs[18] <= `ZERO_WORD;
			regs[19] <= `ZERO_WORD;
			regs[20] <= `ZERO_WORD;
			regs[21] <= `ZERO_WORD;
			regs[22] <= `ZERO_WORD;
			regs[23] <= `ZERO_WORD;
			regs[24] <= `ZERO_WORD;
			regs[25] <= `ZERO_WORD;
			regs[26] <= `ZERO_WORD;
			regs[27] <= `ZERO_WORD;
			regs[28] <= `ZERO_WORD;
			regs[29] <= `ZERO_WORD;
			regs[30] <= `ZERO_WORD;
			regs[31] <= `ZERO_WORD;
		end
		else 
		begin
			if ((w_ena == 1'b1) && (w_addr != 5'h00))	
				regs[w_addr] <= w_data;
		end
	end
	
	assign r_data1 = {64{~rst & r_ena1}} & (
    (r_addr1 == w_addr && (|r_addr1)) ? w_data : regs[r_addr1]
	);
	assign r_data2 = {64{~rst & r_ena2}} & (
    (r_addr2 == w_addr && (|r_addr2)) ? w_data : regs[r_addr2]
	);
  assign regs_o = regs;
endmodule

//--Sun Jiru, Nanjing University--

`include "defines.v"

module wb_stage (
  input wire                              clk,
  input wire                              rst,
  
  // pipeline control
  input wire                              mem_to_wb_valid,
  input wire [`REG_BUS]                   mem_to_wb_pc,
  input wire [`INST_BUS]                  mem_to_wb_inst,
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
  reg [`REG_BUS] mem_to_wb_pc_r;
  reg [`INST_BUS] mem_to_wb_inst_r;
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
      mem_to_wb_pc_r <= mem_to_wb_pc;
      mem_to_wb_inst_r <= mem_to_wb_inst;
      mem_to_wb_bus_r <= mem_to_wb_bus;
      mem_to_wb_diffbus_r <= mem_to_wb_diffbus;
    end
  end
  
  wire [`REG_BUS] wb_pc;
  wire [31 : 0]   wb_inst;
  wire            wb_wen;
  wire [4  : 0]   wb_wdest;
  
  assign wb_pc = mem_to_wb_pc_r;
  assign wb_inst = mem_to_wb_inst_r;
  assign {
    // serial port output
    wb_uart_out_valid, // 305:305
    wb_uart_out_char,  // 304:297
    
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