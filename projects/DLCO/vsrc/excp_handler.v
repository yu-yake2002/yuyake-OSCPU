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
  wire [30 : 0] itrp_idx = (
      ({31{soft_itrp}}       & 31'd3)
    | ({31{timer_itrp}}      & 31'd7)
    | ({31{exter_itrp}}      & 31'd11)
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
  wire [30 : 0] excp_idx = (
      ({31{excp_inst_misal}} & 31'd0)
    | ({31{excp_inst_acc}}   & 31'd1)
    | ({31{excp_ilg_inst}}   & 31'd2)
    | ({31{excp_brk_pt}}     & 31'd3)
    | ({31{excp_load_misal}} & 31'd4)
    | ({31{excp_load_acc}}   & 31'd5)
    | ({31{excp_stor_misal}} & 31'd6)
    | ({31{excp_stor_acc}}   & 31'd7)
    | ({31{excp_ecall_m}}    & 31'd11)
    | ({31{excp_inst_page}}  & 31'd12)
    | ({31{excp_load_page}}  & 31'd13)
    | ({31{excp_stor_page}}  & 31'd15)
  );
  wire inst_acc_fault = excp_inst_misal | excp_inst_acc | excp_inst_page ;
  wire mem_acc_fault = excp_load_misal | excp_load_acc | excp_stor_misal 
                     | excp_stor_acc | excp_load_page | excp_stor_page;
  
  assign mip_wr_data = {32{itrp_info[`TIMER_ITRP]}} & 32'h80;

  /* -----------Write CSRs----------- */
  // write mcause
  assign mcause_wr_data = { sp_itrp_ena ? 1'b1 : 1'b0,
    sp_itrp_ena ? itrp_idx : excp_idx
  };
  
  // write mepc
  assign mepc_wr_data = now_pc;
  
  // write mtval
  assign mtval_wr_data = (
      ({32{inst_acc_fault}} & now_pc)
    | ({32{excp_ilg_inst}}  & now_inst)
    | ({32{mem_acc_fault}}  & mem_addr)
  );
  
  // write mstatus
  wire [31 : 8] mstatus_p1 = mstatus_rd_data[31 : 8];
  wire mstatus_mpie = mstatus_rd_data[7];  // MPIE
  wire [6 : 4] mstatus_p2 = mstatus_rd_data[6 : 4];
  wire mstatus_mie = mstatus_rd_data[3];   // MIE
  wire [2 : 0] mstatus_p3 = mstatus_rd_data[2 : 0];
  wire [`REG_BUS] mstatus_excp_enter = {mstatus_p1, mstatus_mie, mstatus_p2, 1'b0, mstatus_p3};
  wire [`REG_BUS] mstatus_excp_exit = {mstatus_p1, 1'b1, mstatus_p2, mstatus_mpie, mstatus_p3};
  assign mstatus_wr_data = (
      ({32{excp_enter}} & mstatus_excp_enter)
    | ({32{excp_exit}} & mstatus_excp_exit)
  );

  /* -----------Jump control----------- */
  // load mtvec
  wire [1  : 0] mtvec_mode = mtvec_rd_data[1  : 0];
  wire mtvec_mode0 = (mtvec_mode == 2'b0);
  wire mtvec_mode1 = (mtvec_mode == 2'b1);
  wire [29 : 0] mtvec_base = mtvec_rd_data[31 : 2];
  wire [`REG_BUS] mode0_addr = {mtvec_base, 2'b0};
  wire [`REG_BUS] mode1_excp_addr = {mtvec_base, 2'b0};
  wire [`REG_BUS] mode1_itrp_addr = {mtvec_base + itrp_idx[29:0], 2'b0};
  wire [`REG_BUS] mode1_addr = (
           ({32{sp_excp_ena}} & mode1_excp_addr) // when exception, jump to base
         | ({32{sp_itrp_ena}} & mode1_itrp_addr) // when interruption, jump to base + code
  );
  wire [`REG_BUS] excp_enter_pc = 
      ({32{mtvec_mode0}} & mode0_addr) // mode0, jump to base
    | ({32{mtvec_mode1}} & mode1_addr); // mode 1
  wire [`REG_BUS] excp_exit_pc = mepc_rd_data;
  assign excp_jmp_ena = excp_enter | excp_exit;
  assign excp_jmp_pc = ({32{excp_enter}} & excp_enter_pc) | ({32{excp_exit}} & excp_exit_pc);
  
  /* -----------Difftest Control-----------*/
  assign itrp_NO = {32{sp_itrp_ena}} & {1'b0, itrp_idx [30:0]};
  assign excp_NO = {32{sp_excp_ena}} & {1'b0, excp_idx [30:0]};
endmodule