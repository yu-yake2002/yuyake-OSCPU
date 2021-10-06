// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VSIMTOP_H_
#define VERILATED_VSIMTOP_H_  // guard

#include "verilated_heavy.h"
#include "VSimTop__Dpi.h"

//==========

class VSimTop__Syms;
class VSimTop___024unit;


//----------

VL_MODULE(VSimTop) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    VSimTop___024unit* __PVT____024unit;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_perfInfo_clean,0,0);
    VL_IN8(io_perfInfo_dump,0,0);
    VL_OUT8(io_uart_out_valid,0,0);
    VL_OUT8(io_uart_out_ch,7,0);
    VL_OUT8(io_uart_in_valid,0,0);
    VL_IN8(io_uart_in_ch,7,0);
    VL_IN8(io_memAXI_0_aw_ready,0,0);
    VL_OUT8(io_memAXI_0_aw_valid,0,0);
    VL_OUT8(io_memAXI_0_aw_bits_prot,2,0);
    VL_OUT8(io_memAXI_0_aw_bits_id,3,0);
    VL_OUT8(io_memAXI_0_aw_bits_user,0,0);
    VL_OUT8(io_memAXI_0_aw_bits_len,7,0);
    VL_OUT8(io_memAXI_0_aw_bits_size,2,0);
    VL_OUT8(io_memAXI_0_aw_bits_burst,1,0);
    VL_OUT8(io_memAXI_0_aw_bits_lock,0,0);
    VL_OUT8(io_memAXI_0_aw_bits_cache,3,0);
    VL_OUT8(io_memAXI_0_aw_bits_qos,3,0);
    VL_IN8(io_memAXI_0_w_ready,0,0);
    VL_OUT8(io_memAXI_0_w_valid,0,0);
    VL_OUT8(io_memAXI_0_w_bits_strb,7,0);
    VL_OUT8(io_memAXI_0_w_bits_last,0,0);
    VL_OUT8(io_memAXI_0_w_bits_id,3,0);
    VL_OUT8(io_memAXI_0_b_ready,0,0);
    VL_IN8(io_memAXI_0_b_valid,0,0);
    VL_IN8(io_memAXI_0_b_bits_resp,1,0);
    VL_IN8(io_memAXI_0_b_bits_id,3,0);
    VL_IN8(io_memAXI_0_b_bits_user,0,0);
    VL_IN8(io_memAXI_0_ar_ready,0,0);
    VL_OUT8(io_memAXI_0_ar_valid,0,0);
    VL_OUT8(io_memAXI_0_ar_bits_prot,2,0);
    VL_OUT8(io_memAXI_0_ar_bits_id,3,0);
    VL_OUT8(io_memAXI_0_ar_bits_user,0,0);
    VL_OUT8(io_memAXI_0_ar_bits_len,7,0);
    VL_OUT8(io_memAXI_0_ar_bits_size,2,0);
    VL_OUT8(io_memAXI_0_ar_bits_burst,1,0);
    VL_OUT8(io_memAXI_0_ar_bits_lock,0,0);
    VL_OUT8(io_memAXI_0_ar_bits_cache,3,0);
    VL_OUT8(io_memAXI_0_ar_bits_qos,3,0);
    VL_OUT8(io_memAXI_0_r_ready,0,0);
    VL_IN8(io_memAXI_0_r_valid,0,0);
    VL_IN8(io_memAXI_0_r_bits_resp,1,0);
    VL_IN8(io_memAXI_0_r_bits_last,0,0);
    VL_IN8(io_memAXI_0_r_bits_id,3,0);
    VL_IN8(io_memAXI_0_r_bits_user,0,0);
    VL_IN64(io_logCtrl_log_begin,63,0);
    VL_IN64(io_logCtrl_log_end,63,0);
    VL_IN64(io_logCtrl_log_level,63,0);
    VL_OUT64(io_memAXI_0_aw_bits_addr,63,0);
    VL_OUT64(io_memAXI_0_ar_bits_addr,63,0);
    VL_OUT64(io_memAXI_0_w_bits_data[4],63,0);
    VL_IN64(io_memAXI_0_r_bits_data[4],63,0);

    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ SimTop__DOT__cli_aw_ready;
        CData/*0:0*/ SimTop__DOT__cli_aw_valid;
        CData/*0:0*/ SimTop__DOT__cli_w_valid;
        CData/*7:0*/ SimTop__DOT__mem_axi_w_strb;
        CData/*7:0*/ SimTop__DOT__if_axi_w_strb;
        CData/*0:0*/ SimTop__DOT__cli_b_ready;
        CData/*0:0*/ SimTop__DOT__mem_axi_b_valid;
        CData/*0:0*/ SimTop__DOT__if_axi_b_valid;
        CData/*0:0*/ SimTop__DOT__cli_ar_ready;
        CData/*0:0*/ SimTop__DOT__cli_ar_valid;
        CData/*0:0*/ SimTop__DOT__cli_r_ready;
        CData/*1:0*/ SimTop__DOT__mem_rw_size;
        CData/*0:0*/ SimTop__DOT__axi_2x2__DOT__mid_aw_ready;
        CData/*0:0*/ SimTop__DOT__axi_2x2__DOT__mid_aw_valid;
        CData/*3:0*/ SimTop__DOT__axi_2x2__DOT__mid_aw_id;
        CData/*2:0*/ SimTop__DOT__axi_2x2__DOT__mid_aw_size;
        CData/*1:0*/ SimTop__DOT__axi_2x2__DOT__mid_aw_burst;
        CData/*0:0*/ SimTop__DOT__axi_2x2__DOT__mid_w_ready;
        CData/*7:0*/ SimTop__DOT__axi_2x2__DOT__mid_w_strb;
        CData/*0:0*/ SimTop__DOT__axi_2x2__DOT__mid_w_last;
        CData/*0:0*/ SimTop__DOT__axi_2x2__DOT__mid_b_ready;
        CData/*0:0*/ SimTop__DOT__axi_2x2__DOT__mid_b_valid;
        CData/*0:0*/ SimTop__DOT__axi_2x2__DOT__mid_ar_ready;
        CData/*0:0*/ SimTop__DOT__axi_2x2__DOT__mid_ar_valid;
        CData/*3:0*/ SimTop__DOT__axi_2x2__DOT__mid_ar_id;
        CData/*2:0*/ SimTop__DOT__axi_2x2__DOT__mid_ar_size;
        CData/*1:0*/ SimTop__DOT__axi_2x2__DOT__mid_ar_burst;
        CData/*0:0*/ SimTop__DOT__axi_2x2__DOT__mid_r_ready;
        CData/*0:0*/ SimTop__DOT__axi_2x2__DOT__mid_r_valid;
        CData/*0:0*/ SimTop__DOT__axi_2x2__DOT__mid_r_last;
        CData/*1:0*/ SimTop__DOT__axi_2x2__DOT__master_w_state;
        CData/*1:0*/ SimTop__DOT__axi_2x2__DOT__slave_w_state;
        CData/*1:0*/ SimTop__DOT__axi_2x2__DOT__master_w_next_state;
        CData/*1:0*/ SimTop__DOT__axi_2x2__DOT__slave_w_next_state;
        CData/*1:0*/ SimTop__DOT__axi_2x2__DOT__master_r_state;
        CData/*1:0*/ SimTop__DOT__axi_2x2__DOT__slave_r_state;
        CData/*1:0*/ SimTop__DOT__axi_2x2__DOT__master_r_next_state;
        CData/*1:0*/ SimTop__DOT__axi_2x2__DOT__slave_r_next_state;
        CData/*0:0*/ SimTop__DOT__mem_axi_rw__DOT__aw_hs;
        CData/*0:0*/ SimTop__DOT__mem_axi_rw__DOT__w_hs;
        CData/*0:0*/ SimTop__DOT__mem_axi_rw__DOT__b_hs;
        CData/*0:0*/ SimTop__DOT__mem_axi_rw__DOT__ar_hs;
        CData/*0:0*/ SimTop__DOT__mem_axi_rw__DOT__r_hs;
        CData/*0:0*/ SimTop__DOT__mem_axi_rw__DOT__w_done;
        CData/*0:0*/ SimTop__DOT__mem_axi_rw__DOT__r_done;
        CData/*0:0*/ SimTop__DOT__mem_axi_rw__DOT__trans_done;
        CData/*2:0*/ SimTop__DOT__mem_axi_rw__DOT__w_state;
        CData/*2:0*/ SimTop__DOT__mem_axi_rw__DOT__r_state;
        CData/*7:0*/ SimTop__DOT__mem_axi_rw__DOT__len;
        CData/*0:0*/ SimTop__DOT__mem_axi_rw__DOT__len_incr_en;
        CData/*3:0*/ SimTop__DOT__mem_axi_rw__DOT__addr_end;
        CData/*7:0*/ SimTop__DOT__mem_axi_rw__DOT__axi_len;
        CData/*0:0*/ SimTop__DOT__mem_axi_rw__DOT__rw_ready;
        CData/*0:0*/ SimTop__DOT__mem_axi_rw__DOT__rw_ready_en;
        CData/*0:0*/ SimTop__DOT__if_axi_rw__DOT__aw_hs;
        CData/*0:0*/ SimTop__DOT__if_axi_rw__DOT__w_hs;
        CData/*0:0*/ SimTop__DOT__if_axi_rw__DOT__ar_hs;
        CData/*0:0*/ SimTop__DOT__if_axi_rw__DOT__r_hs;
        CData/*0:0*/ SimTop__DOT__if_axi_rw__DOT__r_done;
        CData/*2:0*/ SimTop__DOT__if_axi_rw__DOT__w_state;
        CData/*2:0*/ SimTop__DOT__if_axi_rw__DOT__r_state;
        CData/*7:0*/ SimTop__DOT__if_axi_rw__DOT__len;
        CData/*0:0*/ SimTop__DOT__if_axi_rw__DOT__len_incr_en;
        CData/*7:0*/ SimTop__DOT__if_axi_rw__DOT__axi_len;
    };
    struct {
        CData/*0:0*/ SimTop__DOT__if_axi_rw__DOT__rw_ready;
        CData/*0:0*/ SimTop__DOT__if_axi_rw__DOT__rw_ready_en;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__if_to_id_valid;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__id_to_ex_valid;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__ex_to_mem_valid;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__mem_to_wb_valid;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__id_allowin;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__ex_allowin;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__mem_allowin;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake;
        CData/*4:0*/ SimTop__DOT__u_cpu__DOT__rs1_r_addr;
        CData/*4:0*/ SimTop__DOT__u_cpu__DOT__rs2_r_addr;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__reg_wr_ena;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__cmt_wen;
        CData/*7:0*/ SimTop__DOT__u_cpu__DOT__cmt_wdest;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__cmt_valid;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__cmt_skip;
        CData/*7:0*/ SimTop__DOT__u_cpu__DOT__cmt_w_mask;
        CData/*7:0*/ SimTop__DOT__u_cpu__DOT__buf_w_mask;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__cmt_w_ena;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__buf_w_ena;
        CData/*1:0*/ SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state;
        CData/*1:0*/ SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_next_state;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_valid;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_allowin;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_valid;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_flush;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_excp;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lb;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lh;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lw;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ld;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lbu;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lhu;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lwu;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addi;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slli;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slti;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sltiu;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_xori;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srli;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srai;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ori;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_andi;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addiw;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slliw;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srliw;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sraiw;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sb;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sh;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sw;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sd;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_add;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sub;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sll;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slt;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sltu;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_xor;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srl;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sra;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_or;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_and;
    };
    struct {
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addw;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_subw;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sllw;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srlw;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sraw;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_beq;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bne;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_blt;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bge;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bltu;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bgeu;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ecall;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ebreak;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_mret;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrw;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrs;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrc;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrwi;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrsi;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrci;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld;
        CData/*7:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_bj_info;
        CData/*4:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__reg_wr_addr;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__reg_wr_ena;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_ready_go;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_diffbus_r;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_is_word_opt;
        CData/*7:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_info;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_ena;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__hazard;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_exit;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter;
        CData/*7:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_data;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__excp_jmp_ena;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_valid;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__msie_allowin;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__mtie_allowin;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__meie_allowin;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_shift;
        CData/*5:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in2;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__excp_enter_wr;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__excp_wr;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_wr_ena;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_wr_ena;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_wr_ena;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_wr_ena;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_wr_ena;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_wr_ena;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_wr_ena;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcycle_wr_ena;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ready_go;
        CData/*6:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info;
        CData/*3:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena;
        CData/*2:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ctrl;
        CData/*4:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_addr;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ena;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_handshake;
        CData/*1:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state;
    };
    struct {
        CData/*1:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_next_state;
        CData/*0:0*/ SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid;
        CData/*4:0*/ SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_wdest;
        CData/*2:0*/ SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_reg_wr_ctrl;
        CData/*0:0*/ SimTop__DOT__Clint__DOT__ar_hs;
        CData/*0:0*/ SimTop__DOT__Clint__DOT__aw_hs;
        CData/*0:0*/ SimTop__DOT__Clint__DOT__b_hs;
        CData/*0:0*/ SimTop__DOT__Clint__DOT__r_state;
        CData/*2:0*/ SimTop__DOT__Clint__DOT__rd_size_reg;
        CData/*1:0*/ SimTop__DOT__Clint__DOT__w_state;
        CData/*2:0*/ SimTop__DOT__Clint__DOT__wr_size_reg;
        CData/*7:0*/ SimTop__DOT__Clint__DOT__mask_8bits;
        SData/*11:0*/ SimTop__DOT__clint_interupt_bus;
        SData/*11:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immS;
        SData/*12:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immB;
        SData/*11:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info;
        SData/*15:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_excp_bus;
        SData/*11:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info;
        SData/*11:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr;
        SData/*15:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus;
        VlWide<4>/*127:0*/ SimTop__DOT__mem_axi_rw__DOT__mask;
        VlWide<7>/*222:0*/ SimTop__DOT__u_cpu__DOT__ex_to_mem_bus;
        VlWide<26>/*811:0*/ SimTop__DOT__u_cpu__DOT__difftest_bus;
        VlWide<3>/*65:0*/ SimTop__DOT__u_cpu__DOT__bj_ctrl_bus;
        VlWide<3>/*72:0*/ SimTop__DOT__u_cpu__DOT__mem_forward_bus;
        VlWide<5>/*136:0*/ SimTop__DOT__u_cpu__DOT__wb_forward_bus;
        VlWide<10>/*319:0*/ SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus;
        VlWide<10>/*319:0*/ SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus;
        IData/*31:0*/ SimTop__DOT__u_cpu__DOT__cmt_inst;
        IData/*31:0*/ SimTop__DOT__u_cpu__DOT__cmt_itrp_NO;
        IData/*31:0*/ SimTop__DOT__u_cpu__DOT__cmt_excp_NO;
        IData/*31:0*/ SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_inst;
        IData/*31:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r;
        IData/*20:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immJ;
        IData/*31:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_inst_r;
        VlWide<11>/*343:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r;
        VlWide<3>/*64:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2;
        VlWide<3>/*64:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res;
        IData/*31:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_inst_r;
        VlWide<7>/*222:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r;
        VlWide<19>/*576:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r;
        IData/*31:0*/ SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_inst_r;
        VlWide<7>/*209:0*/ SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r;
        VlWide<23>/*714:0*/ SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r;
        IData/*31:0*/ SimTop__DOT__Clint__DOT__csr_msip;
        QData/*63:0*/ SimTop__DOT__mem_axi_w_data;
        QData/*63:0*/ SimTop__DOT__if_axi_w_data;
        QData/*63:0*/ SimTop__DOT__cli_w_data;
        QData/*63:0*/ SimTop__DOT__mem_axi_r_data;
        QData/*63:0*/ SimTop__DOT__if_axi_r_data;
        QData/*63:0*/ SimTop__DOT__if_r_data;
        QData/*63:0*/ SimTop__DOT__if_rw_addr;
        QData/*63:0*/ SimTop__DOT__mem_r_data;
        QData/*63:0*/ SimTop__DOT__mem_w_data;
        QData/*63:0*/ SimTop__DOT__axi_2x2__DOT__mid_aw_addr;
        QData/*63:0*/ SimTop__DOT__axi_2x2__DOT__mid_w_data;
        QData/*63:0*/ SimTop__DOT__axi_2x2__DOT__mid_ar_addr;
        QData/*63:0*/ SimTop__DOT__axi_2x2__DOT__mid_r_data;
        QData/*63:0*/ SimTop__DOT__mem_axi_rw__DOT__axi_r_data_l;
        QData/*63:0*/ SimTop__DOT__if_axi_rw__DOT__axi_r_data_l;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__csr_rd_data;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__reg_wr_data;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__cmt_wdata;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__cmt_pc;
    };
    struct {
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__cycleCnt;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__instrCnt;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__cmt_mstatus;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__cmt_mepc;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__cmt_mtval;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__cmt_mtvec;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__cmt_mcause;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__cmt_mie;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__cmt_mscratch;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__cmt_rw_addr;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__cmt_w_data;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__buf_rw_addr;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__buf_w_data;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_pc;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_pc_r;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs1_forward;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs2_forward;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__true_op1;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__true_op2;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data;
        QData/*62:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx;
        QData/*62:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__excp_idx;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in1;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_wr_data_full;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_wr_data_full;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mstatus;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_rd_data;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mie;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_rd_data;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mtvec;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_rd_data;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mscratch;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_rd_data;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mepc;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mcause;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mtval;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mip;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mcycle;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_pc_r;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_data;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_pc_r;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_ex_data;
        QData/*63:0*/ SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_mem_rd_data;
        QData/*63:0*/ SimTop__DOT__Clint__DOT__csr_mtime;
        QData/*63:0*/ SimTop__DOT__Clint__DOT__csr_mtimecmp;
        QData/*63:0*/ SimTop__DOT__Clint__DOT__rd_addr_reg;
        QData/*63:0*/ SimTop__DOT__Clint__DOT__clint_val;
        QData/*63:0*/ SimTop__DOT__Clint__DOT__wr_addr_reg;
        QData/*63:0*/ SimTop__DOT__Clint__DOT__wr_mask;
    };
    struct {
        VlUnpacked<QData/*63:0*/, 32> SimTop__DOT__u_cpu__DOT__regs;
        VlUnpacked<QData/*63:0*/, 32> SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs;
    };

    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*6:0*/ __Vtableidx4;
    CData/*6:0*/ __Vtableidx5;
    CData/*0:0*/ __Vclklast__TOP__clock;
    VlUnpacked<QData/*63:0*/, 32> SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o;
    VlUnpacked<CData/*0:0*/, 256> __Vtablechg1;
    VlUnpacked<CData/*0:0*/, 128> __Vtablechg2;
    VlUnpacked<CData/*0:0*/, 128> __Vtablechg3;
    VlUnpacked<CData/*0:0*/, 128> __Vtablechg5;
    VlUnpacked<CData/*0:0*/, 128> __Vtablechg6;
    static VlWide<11>/*351:0*/ __Vconst72;
    static VlWide<11>/*351:0*/ __Vconst88;
    static VlUnpacked<CData/*2:0*/, 256> __Vtable1_SimTop__DOT__mem_axi_rw__DOT__w_state;
    static VlUnpacked<CData/*2:0*/, 128> __Vtable2_SimTop__DOT__mem_axi_rw__DOT__r_state;
    static VlUnpacked<CData/*2:0*/, 128> __Vtable3_SimTop__DOT__if_axi_rw__DOT__r_state;
    static VlUnpacked<CData/*1:0*/, 128> __Vtable4_SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_next_state;
    static VlUnpacked<CData/*1:0*/, 128> __Vtable5_SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_next_state;
    static VlUnpacked<CData/*1:0*/, 128> __Vtable6_SimTop__DOT__Clint__DOT__w_state;

    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VSimTop__Syms* __VlSymsp;  // Symbol table

    // CONSTRUCTORS
  public:
    VL_UNCOPYABLE(VSimTop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VSimTop(VerilatedContext* contextp, const char* name = "TOP");
    VSimTop(const char* name = "TOP")
      : VSimTop(nullptr, name) {}
    /// Destroy the model; called (often implicitly) by application code
    ~VSimTop();

    // API METHODS
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp();
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();

    // INTERNAL METHODS
    static void _eval_initial_loop(VSimTop__Syms* __restrict vlSymsp);
    void __Vconfigure(VSimTop__Syms* symsp, bool first);
  public:
    static QData _change_request(VSimTop__Syms* __restrict vlSymsp);
    static QData _change_request_1(VSimTop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(VSimTop__Syms* __restrict vlSymsp);
  public:
    static void _ctor_var_reset(VSimTop* self) VL_ATTR_COLD;
  public:
    static void _eval(VSimTop__Syms* __restrict vlSymsp);
  public:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VSimTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VSimTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(VSimTop__Syms* __restrict vlSymsp);
    static void _settle__TOP__1(VSimTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
