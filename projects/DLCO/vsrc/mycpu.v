`include "defines.v"

// 这个可以根据自己的需求修改
module mycpu # (
  parameter RW_DATA_WIDTH     = 32,
  parameter RW_ADDR_WIDTH     = 32,
  parameter AXI_DATA_WIDTH    = 32,
  parameter AXI_ADDR_WIDTH    = 32,
  parameter AXI_ID_WIDTH      = 4,
  parameter AXI_USER_WIDTH    = 1
)(
	input             clock,
	input             reset,
	output [`REG_BUS] imemaddr,    //imem的地址
	input  [`REG_BUS] imemdataout, //imem读取到的数据
	output 	          imemclk,     //imem的时钟
	output [`REG_BUS] dmemaddr,    //dmem的地址
	input  [`REG_BUS] dmemdataout, //dmem读取到的数据
	output [`REG_BUS] dmemdatain,  //需要写入dmem的数据
	output            dmemrdclk,   //dmem读口时钟
	output            dmemwrclk,   //dmem写口时钟
	output [2:0]      dmemop,      //3'b000:sb 3'b001:sh 3'b010://sw
	output            dmemwe,      //dmem写有效
	output [`REG_BUS] dbg_pc,      //当前完成的指令的PC
	output            done,        //读取到Instr为0xdead10cc时认为程序结束
	output            wb,          //当前周期是否有指令完成

  output [`REG_BUS] dbgregs_0,   //直接接到RegFile中去
	output [`REG_BUS] dbgregs_1,
	output [`REG_BUS] dbgregs_2,
	output [`REG_BUS] dbgregs_3,
	output [`REG_BUS] dbgregs_4,
	output [`REG_BUS] dbgregs_5,
	output [`REG_BUS] dbgregs_6,
	output [`REG_BUS] dbgregs_7,
	output [`REG_BUS] dbgregs_8,
	output [`REG_BUS] dbgregs_9,
	output [`REG_BUS] dbgregs_10,
	output [`REG_BUS] dbgregs_11,
	output [`REG_BUS] dbgregs_12,
	output [`REG_BUS] dbgregs_13,
	output [`REG_BUS] dbgregs_14,
	output [`REG_BUS] dbgregs_15,
	output [`REG_BUS] dbgregs_16,
	output [`REG_BUS] dbgregs_17,
	output [`REG_BUS] dbgregs_18,
	output [`REG_BUS] dbgregs_19,
	output [`REG_BUS] dbgregs_20,
	output [`REG_BUS] dbgregs_21,
	output [`REG_BUS] dbgregs_22,
	output [`REG_BUS] dbgregs_23,
	output [`REG_BUS] dbgregs_24,
	output [`REG_BUS] dbgregs_25,
	output [`REG_BUS] dbgregs_26,
	output [`REG_BUS] dbgregs_27,
	output [`REG_BUS] dbgregs_28,
	output [`REG_BUS] dbgregs_29,
	output [`REG_BUS] dbgregs_30,
	output [`REG_BUS] dbgregs_31
);//add your code here
  
  assign imemclk = clock;
  assign dmemwrclk = clock;
  assign dmemrdclk = clock;

  // AXI4 wires
  wire                        mem_axi_aw_ready, imem_axi_aw_ready, dmem_axi_aw_ready, cli_axi_aw_ready;
  wire                        mem_axi_aw_valid, imem_axi_aw_valid, dmem_axi_aw_valid, cli_axi_aw_valid;
  wire [AXI_ADDR_WIDTH-1:0]   mem_axi_aw_addr,  imem_axi_aw_addr,  dmem_axi_aw_addr,  cli_axi_aw_addr;
  wire [2:0]                  mem_axi_aw_prot,  imem_axi_aw_prot,  dmem_axi_aw_prot,  cli_axi_aw_prot;
  wire [AXI_ID_WIDTH-1:0]     mem_axi_aw_id,    imem_axi_aw_id,    dmem_axi_aw_id,    cli_axi_aw_id;
  wire [AXI_USER_WIDTH-1:0]   mem_axi_aw_user,  imem_axi_aw_user,  dmem_axi_aw_user,  cli_axi_aw_user;
  wire [7:0]                  mem_axi_aw_len,   imem_axi_aw_len,   dmem_axi_aw_len,   cli_axi_aw_len;
  wire [2:0]                  mem_axi_aw_size,  imem_axi_aw_size,  dmem_axi_aw_size,  cli_axi_aw_size;
  wire [1:0]                  mem_axi_aw_burst, imem_axi_aw_burst, dmem_axi_aw_burst, cli_axi_aw_burst;
  wire                        mem_axi_aw_lock,  imem_axi_aw_lock,  dmem_axi_aw_lock,  cli_axi_aw_lock;
  wire [3:0]                  mem_axi_aw_cache, imem_axi_aw_cache, dmem_axi_aw_cache, cli_axi_aw_cache;
  wire [3:0]                  mem_axi_aw_qos,   imem_axi_aw_qos,   dmem_axi_aw_qos,   cli_axi_aw_qos;
  
  wire                        mem_axi_w_ready,  imem_axi_w_ready,  dmem_axi_w_ready,  cli_axi_w_ready;
  wire                        mem_axi_w_valid,  imem_axi_w_valid,  dmem_axi_w_valid,  cli_axi_w_valid;
  wire [AXI_DATA_WIDTH-1:0]   mem_axi_w_data,   imem_axi_w_data,   dmem_axi_w_data,   cli_axi_w_data;
  wire [AXI_DATA_WIDTH/8-1:0] mem_axi_w_strb,   imem_axi_w_strb,   dmem_axi_w_strb,   cli_axi_w_strb;
  wire                        mem_axi_w_last,   imem_axi_w_last,   dmem_axi_w_last,   cli_axi_w_last;
  wire [AXI_ID_WIDTH-1:0]     mem_axi_w_id,     imem_axi_w_id,     dmem_axi_w_id,     cli_axi_w_id;

  wire                        mem_axi_b_ready,  imem_axi_b_ready,  dmem_axi_b_ready,  cli_axi_b_ready;
  wire                        mem_axi_b_valid,  imem_axi_b_valid,  dmem_axi_b_valid,  cli_axi_b_valid;
  wire [1:0]                  mem_axi_b_resp,   imem_axi_b_resp,   dmem_axi_b_resp,   cli_axi_b_resp;
  wire [AXI_ID_WIDTH-1:0]     mem_axi_b_id,     imem_axi_b_id,     dmem_axi_b_id,     cli_axi_b_id;
  wire [AXI_USER_WIDTH-1:0]   mem_axi_b_user,   imem_axi_b_user,   dmem_axi_b_user,   cli_axi_b_user;

  wire                        mem_axi_ar_ready, imem_axi_ar_ready, dmem_axi_ar_ready, cli_axi_ar_ready;
  wire                        mem_axi_ar_valid, imem_axi_ar_valid, dmem_axi_ar_valid, cli_axi_ar_valid;
  wire [AXI_ADDR_WIDTH-1:0]   mem_axi_ar_addr,  imem_axi_ar_addr,  dmem_axi_ar_addr,  cli_axi_ar_addr;
  wire [2:0]                  mem_axi_ar_prot,  imem_axi_ar_prot,  dmem_axi_ar_prot,  cli_axi_ar_prot;
  wire [AXI_ID_WIDTH-1:0]     mem_axi_ar_id,    imem_axi_ar_id,    dmem_axi_ar_id,    cli_axi_ar_id;
  wire [AXI_USER_WIDTH-1:0]   mem_axi_ar_user,  imem_axi_ar_user,  dmem_axi_ar_user,  cli_axi_ar_user;
  wire [7:0]                  mem_axi_ar_len,   imem_axi_ar_len,   dmem_axi_ar_len,   cli_axi_ar_len;
  wire [2:0]                  mem_axi_ar_size,  imem_axi_ar_size,  dmem_axi_ar_size,  cli_axi_ar_size;
  wire [1:0]                  mem_axi_ar_burst, imem_axi_ar_burst, dmem_axi_ar_burst, cli_axi_ar_burst;
  wire                        mem_axi_ar_lock,  imem_axi_ar_lock,  dmem_axi_ar_lock,  cli_axi_ar_lock;
  wire [3:0]                  mem_axi_ar_cache, imem_axi_ar_cache, dmem_axi_ar_cache, cli_axi_ar_cache;
  wire [3:0]                  mem_axi_ar_qos,   imem_axi_ar_qos,   dmem_axi_ar_qos,   cli_axi_ar_qos;

  wire                        mem_axi_r_ready,  imem_axi_r_ready,  dmem_axi_r_ready,  cli_axi_r_ready;
  wire                        mem_axi_r_valid,  imem_axi_r_valid,  dmem_axi_r_valid,  cli_axi_r_valid;
  wire [1:0]                  mem_axi_r_resp,   imem_axi_r_resp,   dmem_axi_r_resp,   cli_axi_r_resp;
  wire [AXI_DATA_WIDTH-1:0]   mem_axi_r_data,   imem_axi_r_data,   dmem_axi_r_data,   cli_axi_r_data;
  wire                        mem_axi_r_last,   imem_axi_r_last,   dmem_axi_r_last,   cli_axi_r_last;
  wire [AXI_ID_WIDTH-1:0]     mem_axi_r_id,     imem_axi_r_id,     dmem_axi_r_id,     cli_axi_r_id;
  wire [AXI_USER_WIDTH-1:0]   mem_axi_r_user,   imem_axi_r_user,   dmem_axi_r_user,   cli_axi_r_user;
  
  naive_to_axi mem_naive_to_axi (
    .clk                            (clock),
    .rst                            (reset),

    .memaddr                        (dmemaddr),
    .memdataout                     (dmemdataout),
    .memdatain                      (dmemdatain),
    .memop                          (dmemop),
    .memwe                          (dmemwe),

    .axi_aw_ready                   (mem_axi_aw_ready),
    .axi_aw_valid                   (mem_axi_aw_valid),
    .axi_aw_addr                    (mem_axi_aw_addr),
    .axi_aw_prot                    (mem_axi_aw_prot),
    .axi_aw_id                      (mem_axi_aw_id),
    .axi_aw_user                    (mem_axi_aw_user),
    .axi_aw_len                     (mem_axi_aw_len),
    .axi_aw_size                    (mem_axi_aw_size),
    .axi_aw_burst                   (mem_axi_aw_burst),
    .axi_aw_lock                    (mem_axi_aw_lock),
    .axi_aw_cache                   (mem_axi_aw_cache),
    .axi_aw_qos                     (mem_axi_aw_qos),
    
    .axi_w_ready                    (mem_axi_w_ready),
    .axi_w_valid                    (mem_axi_w_valid),
    .axi_w_data                     (mem_axi_w_data),
    .axi_w_strb                     (mem_axi_w_strb),
    .axi_w_last                     (mem_axi_w_last),
    .axi_w_id                       (mem_axi_w_id),
    
    .axi_b_ready                    (mem_axi_b_ready),
    .axi_b_valid                    (mem_axi_b_valid),
    .axi_b_resp                     (mem_axi_b_resp),
    .axi_b_id                       (mem_axi_b_id),
    .axi_b_user                     (mem_axi_b_user),
    
    .axi_ar_ready                   (mem_axi_ar_ready),
    .axi_ar_valid                   (mem_axi_ar_valid),
    .axi_ar_addr                    (mem_axi_ar_addr),
    .axi_ar_prot                    (mem_axi_ar_prot),
    .axi_ar_id                      (mem_axi_ar_id),
    .axi_ar_user                    (mem_axi_ar_user),
    .axi_ar_len                     (mem_axi_ar_len),
    .axi_ar_size                    (mem_axi_ar_size),
    .axi_ar_burst                   (mem_axi_ar_burst),
    .axi_ar_lock                    (mem_axi_ar_lock),
    .axi_ar_cache                   (mem_axi_ar_cache),
    .axi_ar_qos                     (mem_axi_ar_qos),
    
    .axi_r_ready                    (mem_axi_r_ready),
    .axi_r_valid                    (mem_axi_r_valid),
    .axi_r_resp                     (mem_axi_r_resp),
    .axi_r_data                     (mem_axi_r_data),
    .axi_r_last                     (mem_axi_r_last),
    .axi_r_id                       (mem_axi_r_id),
    .axi_r_user                     (mem_axi_r_user)
  );

  naive_to_axi imem_naive_to_axi (
    .clk                            (clock),
    .rst                            (reset),

    .memaddr                        (dmemaddr),
    .memdataout                     (dmemdataout),
    .memdatain                      (),
    .memop                          (),
    .memwe                          (),

    .axi_aw_ready                   (imem_axi_aw_ready),
    .axi_aw_valid                   (imem_axi_aw_valid),
    .axi_aw_addr                    (imem_axi_aw_addr),
    .axi_aw_prot                    (imem_axi_aw_prot),
    .axi_aw_id                      (imem_axi_aw_id),
    .axi_aw_user                    (imem_axi_aw_user),
    .axi_aw_len                     (imem_axi_aw_len),
    .axi_aw_size                    (imem_axi_aw_size),
    .axi_aw_burst                   (imem_axi_aw_burst),
    .axi_aw_lock                    (imem_axi_aw_lock),
    .axi_aw_cache                   (imem_axi_aw_cache),
    .axi_aw_qos                     (imem_axi_aw_qos),
    
    .axi_w_ready                    (imem_axi_w_ready),
    .axi_w_valid                    (imem_axi_w_valid),
    .axi_w_data                     (imem_axi_w_data),
    .axi_w_strb                     (imem_axi_w_strb),
    .axi_w_last                     (imem_axi_w_last),
    .axi_w_id                       (imem_axi_w_id),
    
    .axi_b_ready                    (imem_axi_b_ready),
    .axi_b_valid                    (imem_axi_b_valid),
    .axi_b_resp                     (imem_axi_b_resp),
    .axi_b_id                       (imem_axi_b_id),
    .axi_b_user                     (imem_axi_b_user),
    
    .axi_ar_ready                   (imem_axi_ar_ready),
    .axi_ar_valid                   (imem_axi_ar_valid),
    .axi_ar_addr                    (imem_axi_ar_addr),
    .axi_ar_prot                    (imem_axi_ar_prot),
    .axi_ar_id                      (imem_axi_ar_id),
    .axi_ar_user                    (imem_axi_ar_user),
    .axi_ar_len                     (imem_axi_ar_len),
    .axi_ar_size                    (imem_axi_ar_size),
    .axi_ar_burst                   (imem_axi_ar_burst),
    .axi_ar_lock                    (imem_axi_ar_lock),
    .axi_ar_cache                   (imem_axi_ar_cache),
    .axi_ar_qos                     (imem_axi_ar_qos),
    
    .axi_r_ready                    (imem_axi_r_ready),
    .axi_r_valid                    (imem_axi_r_valid),
    .axi_r_resp                     (imem_axi_r_resp),
    .axi_r_data                     (imem_axi_r_data),
    .axi_r_last                     (imem_axi_r_last),
    .axi_r_id                       (imem_axi_r_id),
    .axi_r_user                     (imem_axi_r_user)
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

    // stay empty
    .aw_ready_o_1                   (),
    .aw_valid_i_1                   (),
    .aw_addr_i_1                    (),
    .aw_prot_i_1                    (),
    .aw_id_i_1                      (),
    .aw_user_i_1                    (),
    .aw_len_i_1                     (),
    .aw_size_i_1                    (),
    .aw_burst_i_1                   (),
    .aw_lock_i_1                    (),
    .aw_cache_i_1                   (),
    .aw_qos_i_1                     (),

    .w_ready_o_1                    (),
    .w_valid_i_1                    (),
    .w_data_i_1                     (),
    .w_strb_i_1                     (),
    .w_last_i_1                     (),
    .w_id_i_1                       (),

    .b_ready_i_1                    (),
    .b_valid_o_1                    (),
    .b_resp_o_1                     (),
    .b_id_o_1                       (),
    .b_user_o_1                     (),

    .ar_ready_o_1                   (),
    .ar_valid_i_1                   (),
    .ar_addr_i_1                    (),
    .ar_prot_i_1                    (),
    .ar_id_i_1                      (),
    .ar_user_i_1                    (),
    .ar_len_i_1                     (),
    .ar_size_i_1                    (),
    .ar_burst_i_1                   (),
    .ar_lock_i_1                    (),
    .ar_cache_i_1                   (),
    .ar_qos_i_1                     (),

    .r_ready_i_1                    (),
    .r_valid_o_1                    (),
    .r_resp_o_1                     (),
    .r_data_o_1                     (),
    .r_last_o_1                     (),
    .r_id_o_1                       (),
    .r_user_o_1                     (),
    
    // TOP INTERFACE
    .ram_aw_ready_i                 (dmem_axi_aw_ready),
    .ram_aw_valid_o                 (dmem_axi_aw_valid),
    .ram_aw_addr_o                  (dmem_axi_aw_addr),
    .ram_aw_prot_o                  (dmem_axi_aw_prot),
    .ram_aw_id_o                    (dmem_axi_aw_id),
    .ram_aw_user_o                  (dmem_axi_aw_user),
    .ram_aw_len_o                   (dmem_axi_aw_len),
    .ram_aw_size_o                  (dmem_axi_aw_size),
    .ram_aw_burst_o                 (dmem_axi_aw_burst),
    .ram_aw_lock_o                  (dmem_axi_aw_lock),
    .ram_aw_cache_o                 (dmem_axi_aw_cache),
    .ram_aw_qos_o                   (dmem_axi_aw_qos),

    .ram_w_ready_i                  (dmem_axi_w_ready),
    .ram_w_valid_o                  (dmem_axi_w_valid),
    .ram_w_data_o                   (dmem_axi_w_data),
    .ram_w_strb_o                   (dmem_axi_w_strb),
    .ram_w_last_o                   (dmem_axi_w_last),
    .ram_w_id_o                     (dmem_axi_w_id),
  
    .ram_b_ready_o                  (dmem_axi_b_ready),
    .ram_b_valid_i                  (dmem_axi_b_valid),
    .ram_b_resp_i                   (dmem_axi_b_resp),
    .ram_b_id_i                     (dmem_axi_b_id),
    .ram_b_user_i                   (dmem_axi_b_user),
  
    .ram_ar_ready_i                 (dmem_axi_ar_ready),
    .ram_ar_valid_o                 (dmem_axi_ar_valid),
    .ram_ar_addr_o                  (dmem_axi_ar_addr),
    .ram_ar_prot_o                  (dmem_axi_ar_prot),
    .ram_ar_id_o                    (dmem_axi_ar_id),
    .ram_ar_user_o                  (dmem_axi_ar_user),
    .ram_ar_len_o                   (dmem_axi_ar_len),
    .ram_ar_size_o                  (dmem_axi_ar_size),
    .ram_ar_burst_o                 (dmem_axi_ar_burst),
    .ram_ar_lock_o                  (dmem_axi_ar_lock),
    .ram_ar_cache_o                 (dmem_axi_ar_cache),
    .ram_ar_qos_o                   (dmem_axi_ar_qos),
  
    .ram_r_ready_o                  (dmem_axi_r_ready),
    .ram_r_valid_i                  (dmem_axi_r_valid),
    .ram_r_resp_i                   (dmem_axi_r_resp),
    .ram_r_data_i                   (dmem_axi_r_data),
    .ram_r_last_i                   (dmem_axi_r_last),
    .ram_r_id_i                     (dmem_axi_r_id),
    .ram_r_user_i                   (dmem_axi_r_user),

    // CLINT
    .cli_aw_ready_i                 (cli_axi_aw_ready),
    .cli_aw_valid_o                 (cli_axi_aw_valid),
    .cli_aw_addr_o                  (cli_axi_aw_addr),
    .cli_aw_prot_o                  (cli_axi_aw_prot),
    .cli_aw_id_o                    (cli_axi_aw_id),
    .cli_aw_user_o                  (cli_axi_aw_user),
    .cli_aw_len_o                   (cli_axi_aw_len),
    .cli_aw_size_o                  (cli_axi_aw_size),
    .cli_aw_burst_o                 (cli_axi_aw_burst),
    .cli_aw_lock_o                  (cli_axi_aw_lock),
    .cli_aw_cache_o                 (cli_axi_aw_cache),
    .cli_aw_qos_o                   (cli_axi_aw_qos),

    .cli_w_ready_i                  (cli_axi_w_ready),
    .cli_w_valid_o                  (cli_axi_w_valid),
    .cli_w_data_o                   (cli_axi_w_data),
    .cli_w_strb_o                   (cli_axi_w_strb),
    .cli_w_last_o                   (cli_axi_w_last),
    .cli_w_id_o                     (cli_axi_w_id),
  
    .cli_b_ready_o                  (cli_axi_b_ready),
    .cli_b_valid_i                  (cli_axi_b_valid),
    .cli_b_resp_i                   (cli_axi_b_resp),
    .cli_b_id_i                     (cli_axi_b_id),
    .cli_b_user_i                   (cli_axi_b_user),
  
    .cli_ar_ready_i                 (cli_axi_ar_ready),
    .cli_ar_valid_o                 (cli_axi_ar_valid),
    .cli_ar_addr_o                  (cli_axi_ar_addr),
    .cli_ar_prot_o                  (cli_axi_ar_prot),
    .cli_ar_id_o                    (cli_axi_ar_id),
    .cli_ar_user_o                  (cli_axi_ar_user),
    .cli_ar_len_o                   (cli_axi_ar_len),
    .cli_ar_size_o                  (cli_axi_ar_size),
    .cli_ar_burst_o                 (cli_axi_ar_burst),
    .cli_ar_lock_o                  (cli_axi_ar_lock),
    .cli_ar_cache_o                 (cli_axi_ar_cache),
    .cli_ar_qos_o                   (cli_axi_ar_qos),
  
    .cli_r_ready_o                  (cli_axi_r_ready),
    .cli_r_valid_i                  (cli_axi_r_valid),
    .cli_r_resp_i                   (cli_axi_r_resp),
    .cli_r_data_i                   (cli_axi_r_data),
    .cli_r_last_i                   (cli_axi_r_last),
    .cli_r_id_i                     (cli_axi_r_id),
    .cli_r_user_i                   (cli_axi_r_user)
  );

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
    
    .axi_aw_ready_i                 (imem_axi_aw_ready),
    .axi_aw_valid_o                 (imem_axi_aw_valid),
    .axi_aw_addr_o                  (imem_axi_aw_addr),
    .axi_aw_prot_o                  (imem_axi_aw_prot),
    .axi_aw_id_o                    (imem_axi_aw_id),
    .axi_aw_user_o                  (imem_axi_aw_user),
    .axi_aw_len_o                   (imem_axi_aw_len),
    .axi_aw_size_o                  (imem_axi_aw_size),
    .axi_aw_burst_o                 (imem_axi_aw_burst),
    .axi_aw_lock_o                  (imem_axi_aw_lock),
    .axi_aw_cache_o                 (imem_axi_aw_cache),
    .axi_aw_qos_o                   (imem_axi_aw_qos),
    
    .axi_w_ready_i                  (imem_axi_w_ready),
    .axi_w_valid_o                  (imem_axi_w_valid),
    .axi_w_data_o                   (imem_axi_w_data),
    .axi_w_strb_o                   (imem_axi_w_strb),
    .axi_w_last_o                   (imem_axi_w_last),
    .axi_w_id_o                     (imem_axi_w_id),
        
    .axi_b_ready_o                  (imem_axi_b_ready),
    .axi_b_valid_i                  (imem_axi_b_valid),
    .axi_b_resp_i                   (imem_axi_b_resp),
    .axi_b_id_i                     (imem_axi_b_id),
    .axi_b_user_i                   (imem_axi_b_user),

    .axi_ar_ready_i                 (imem_axi_ar_ready),
    .axi_ar_valid_o                 (imem_axi_ar_valid),
    .axi_ar_addr_o                  (imem_axi_ar_addr),
    .axi_ar_prot_o                  (imem_axi_ar_prot),
    .axi_ar_id_o                    (imem_axi_ar_id),
    .axi_ar_user_o                  (imem_axi_ar_user),
    .axi_ar_len_o                   (imem_axi_ar_len),
    .axi_ar_size_o                  (imem_axi_ar_size),
    .axi_ar_burst_o                 (imem_axi_ar_burst),
    .axi_ar_lock_o                  (imem_axi_ar_lock),
    .axi_ar_cache_o                 (imem_axi_ar_cache),
    .axi_ar_qos_o                   (imem_axi_ar_qos),
        
    .axi_r_ready_o                  (imem_axi_r_ready),
    .axi_r_valid_i                  (imem_axi_r_valid),
    .axi_r_resp_i                   (imem_axi_r_resp),
    .axi_r_data_i                   (imem_axi_r_data),
    .axi_r_last_i                   (imem_axi_r_last),
    .axi_r_id_i                     (imem_axi_r_id),
    .axi_r_user_i                   (imem_axi_r_user)
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

  wire io_uart_out_valid;
  wire [7:0] io_uart_out_ch;

  cpu u_cpu(
    .clock                         (clock),
    .reset                         (reset),
    
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

    .clint_interupt_bus            (clint_interupt_bus),

    .dbgregs_0                     (dbgregs_0),   //直接接到RegFile中去
	  .dbgregs_1                     (dbgregs_1),
	  .dbgregs_2                     (dbgregs_2),
	  .dbgregs_3                     (dbgregs_3),
	  .dbgregs_4                     (dbgregs_4),
	  .dbgregs_5                     (dbgregs_5),
	  .dbgregs_6                     (dbgregs_6),
	  .dbgregs_7                     (dbgregs_7),
	  .dbgregs_8                     (dbgregs_8),
	  .dbgregs_9                     (dbgregs_9),
	  .dbgregs_10                    (dbgregs_10),
	  .dbgregs_11                    (dbgregs_11),
	  .dbgregs_12                    (dbgregs_12),
	  .dbgregs_13                    (dbgregs_13),
	  .dbgregs_14                    (dbgregs_14),
	  .dbgregs_15                    (dbgregs_15),
	  .dbgregs_16                    (dbgregs_16),
	  .dbgregs_17                    (dbgregs_17),
	  .dbgregs_18                    (dbgregs_18),
	  .dbgregs_19                    (dbgregs_19),
	  .dbgregs_20                    (dbgregs_20),
	  .dbgregs_21                    (dbgregs_21),
	  .dbgregs_22                    (dbgregs_22),
	  .dbgregs_23                    (dbgregs_23),
	  .dbgregs_24                    (dbgregs_24),
	  .dbgregs_25                    (dbgregs_25),
	  .dbgregs_26                    (dbgregs_26),
	  .dbgregs_27                    (dbgregs_27),
	  .dbgregs_28                    (dbgregs_28),
	  .dbgregs_29                    (dbgregs_29),
	  .dbgregs_30                    (dbgregs_30),
	  .dbgregs_31                    (dbgregs_31),
    .done                          (done),
    .wb                            (wb),
    .dbg_pc                        (dbg_pc)
  );

  always @(posedge clock) begin
    if (io_uart_out_valid) begin
      $display("%c", io_uart_out_ch);
    end
  end
  
  clint Clint(
    .clk                           (clock),
    .rst                           (reset),

    .aw_ready_o                    (cli_axi_aw_ready),
    .aw_valid_i                    (cli_axi_aw_valid),
    .aw_addr_i                     (cli_axi_aw_addr),
    .aw_prot_i                     (cli_axi_aw_prot),
    .aw_id_i                       (cli_axi_aw_id),
    .aw_user_i                     (cli_axi_aw_user),
    .aw_len_i                      (cli_axi_aw_len),
    .aw_size_i                     (cli_axi_aw_size),
    .aw_burst_i                    (cli_axi_aw_burst),
    .aw_lock_i                     (cli_axi_aw_lock),
    .aw_cache_i                    (cli_axi_aw_cache),
    .aw_qos_i                      (cli_axi_aw_qos),
    
    .w_ready_o                     (cli_axi_w_ready),
    .w_valid_i                     (cli_axi_w_valid),
    .w_data_i                      (cli_axi_w_data),
    .w_strb_i                      (cli_axi_w_strb),
    .w_last_i                      (cli_axi_w_last),
    .w_id_i                        (cli_axi_w_id),
        
    .b_ready_i                     (cli_axi_b_ready),
    .b_valid_o                     (cli_axi_b_valid),
    .b_resp_o                      (cli_axi_b_resp),
    .b_id_o                        (cli_axi_b_id),
    .b_user_o                      (cli_axi_b_user),

    .ar_ready_o                    (cli_axi_ar_ready),
    .ar_valid_i                    (cli_axi_ar_valid),
    .ar_addr_i                     (cli_axi_ar_addr),
    .ar_prot_i                     (cli_axi_ar_prot),
    .ar_id_i                       (cli_axi_ar_id),
    .ar_user_i                     (cli_axi_ar_user),
    .ar_len_i                      (cli_axi_ar_len),
    .ar_size_i                     (cli_axi_ar_size),
    .ar_burst_i                    (cli_axi_ar_burst),
    .ar_lock_i                     (cli_axi_ar_lock),
    .ar_cache_i                    (cli_axi_ar_cache),
    .ar_qos_i                      (cli_axi_ar_qos),
        
    .r_ready_i                     (cli_axi_r_ready),
    .r_valid_o                     (cli_axi_r_valid),
    .r_resp_o                      (cli_axi_r_resp),
    .r_data_o                      (cli_axi_r_data),
    .r_last_o                      (cli_axi_r_last),
    .r_id_o                        (cli_axi_r_id),
    .r_user_o                      (cli_axi_r_user),

    .clint_interupt_bus            (clint_interupt_bus)
  );
endmodule