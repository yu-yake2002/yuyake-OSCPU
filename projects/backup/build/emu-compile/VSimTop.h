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
class VSimTop_VerilatedVcd;
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
    VL_IN64(io_logCtrl_log_begin,63,0);
    VL_IN64(io_logCtrl_log_end,63,0);
    VL_IN64(io_logCtrl_log_level,63,0);

    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*7:0*/ SimTop__DOT__byte_enable;
        CData/*0:0*/ SimTop__DOT__bj_ena;
        CData/*0:0*/ SimTop__DOT__id_valid;
        CData/*0:0*/ SimTop__DOT__id_allowin;
        CData/*0:0*/ SimTop__DOT__id_to_ex_valid;
        CData/*0:0*/ SimTop__DOT__stall;
        CData/*7:0*/ SimTop__DOT__id_bj_info;
        CData/*6:0*/ SimTop__DOT__id_load_info;
        CData/*4:0*/ SimTop__DOT__id_reg_wr_addr;
        CData/*0:0*/ SimTop__DOT__id_reg_wr_ena;
        CData/*0:0*/ SimTop__DOT__ex_is_word_opt;
        CData/*7:0*/ SimTop__DOT__ex_bj_info;
        CData/*0:0*/ SimTop__DOT__ex_use_rs1;
        CData/*0:0*/ SimTop__DOT__ex_use_rs2;
        CData/*4:0*/ SimTop__DOT__ex_rs1_addr;
        CData/*4:0*/ SimTop__DOT__ex_rs2_addr;
        CData/*0:0*/ SimTop__DOT__ex_ram_wr_ena_r;
        CData/*0:0*/ SimTop__DOT__ex_ram_rd_ena_r;
        CData/*0:0*/ SimTop__DOT__ex_ram_rd_ena;
        CData/*6:0*/ SimTop__DOT__ex_load_info;
        CData/*3:0*/ SimTop__DOT__ex_save_info;
        CData/*2:0*/ SimTop__DOT__ex_reg_wr_ctrl;
        CData/*4:0*/ SimTop__DOT__ex_reg_wr_addr;
        CData/*0:0*/ SimTop__DOT__ex_reg_wr_ena_r;
        CData/*0:0*/ SimTop__DOT__ex_csr_wr_ena_r;
        CData/*0:0*/ SimTop__DOT__ex_valid;
        CData/*6:0*/ SimTop__DOT__mem_load_info;
        CData/*3:0*/ SimTop__DOT__mem_save_info;
        CData/*0:0*/ SimTop__DOT__mem_ram_wr_ena;
        CData/*0:0*/ SimTop__DOT__mem_ram_rd_ena;
        CData/*2:0*/ SimTop__DOT__mem_reg_wr_ctrl;
        CData/*4:0*/ SimTop__DOT__mem_reg_wr_addr;
        CData/*0:0*/ SimTop__DOT__mem_reg_wr_ena;
        CData/*0:0*/ SimTop__DOT__mem_csr_wr_ena;
        CData/*0:0*/ SimTop__DOT__mem_valid;
        CData/*2:0*/ SimTop__DOT__wb_reg_wr_ctrl;
        CData/*4:0*/ SimTop__DOT__wb_reg_wr_addr;
        CData/*0:0*/ SimTop__DOT__wb_reg_wr_ena;
        CData/*0:0*/ SimTop__DOT__wb_csr_wr_ena;
        CData/*0:0*/ SimTop__DOT__wb_valid;
        CData/*0:0*/ SimTop__DOT__rs1_r_ena;
        CData/*4:0*/ SimTop__DOT__rs1_r_addr;
        CData/*0:0*/ SimTop__DOT__rs2_r_ena;
        CData/*4:0*/ SimTop__DOT__rs2_r_addr;
        CData/*0:0*/ SimTop__DOT__excp_exit;
        CData/*0:0*/ SimTop__DOT__csr_rd_ena;
        CData/*0:0*/ SimTop__DOT__csr_wr_ena;
        CData/*0:0*/ SimTop__DOT__cmt_wen;
        CData/*7:0*/ SimTop__DOT__cmt_wdest;
        CData/*0:0*/ SimTop__DOT__vaild;
        CData/*0:0*/ SimTop__DOT__skip;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_i_excp;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_i_csr_imm;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_i_csr_reg;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_lb;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_lh;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_lw;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_ld;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_lbu;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_lhu;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_lwu;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_addi;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_slli;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_slti;
    };
    struct {
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_sltiu;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_xori;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_srli;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_srai;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_ori;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_andi;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_addiw;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_slliw;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_srliw;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_sraiw;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_sb;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_sh;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_sw;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_sd;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_add;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_sub;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_sll;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_slt;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_sltu;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_xor;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_srl;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_sra;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_or;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_and;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_addw;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_subw;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_sllw;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_srlw;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_sraw;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_beq;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_bne;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_blt;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_bge;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_bltu;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_bgeu;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_csrrw;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_csrrs;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_csrrc;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_csrrwi;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_csrrsi;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_csrrci;
        CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_vld;
        CData/*7:0*/ SimTop__DOT__Ex_stage__DOT__bj_data;
        CData/*0:0*/ SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_shift;
        CData/*5:0*/ SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in2;
        CData/*0:0*/ SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub;
        CData/*0:0*/ SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub;
        SData/*15:0*/ SimTop__DOT__if_excp;
        SData/*15:0*/ SimTop__DOT__id_excp;
        SData/*11:0*/ SimTop__DOT__id_alu_info;
        SData/*11:0*/ SimTop__DOT__ex_alu_info;
        SData/*11:0*/ SimTop__DOT__ex_csr_wr_addr;
        SData/*11:0*/ SimTop__DOT__mem_csr_wr_addr;
        SData/*15:0*/ SimTop__DOT__mem_excp;
        SData/*11:0*/ SimTop__DOT__wb_csr_wr_addr;
        SData/*11:0*/ SimTop__DOT__csr_wr_addr;
        SData/*11:0*/ SimTop__DOT__Id_stage__DOT__immS;
        SData/*12:0*/ SimTop__DOT__Id_stage__DOT__immB;
        SData/*15:0*/ SimTop__DOT__Excp_handler__DOT__excp_info;
        IData/*31:0*/ SimTop__DOT__id_inst;
        IData/*31:0*/ SimTop__DOT__ex_inst;
        IData/*31:0*/ SimTop__DOT__mem_inst;
        IData/*31:0*/ SimTop__DOT__wb_inst;
        IData/*31:0*/ SimTop__DOT__cmt_inst;
    };
    struct {
        IData/*20:0*/ SimTop__DOT__Id_stage__DOT__immJ;
        VlWide<3>/*64:0*/ SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2;
        VlWide<3>/*64:0*/ SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res;
        QData/*63:0*/ SimTop__DOT__rd_data;
        QData/*63:0*/ SimTop__DOT__ram_rd_data;
        QData/*63:0*/ SimTop__DOT__if_pc;
        QData/*63:0*/ SimTop__DOT__id_pc;
        QData/*63:0*/ SimTop__DOT__id_op1;
        QData/*63:0*/ SimTop__DOT__id_op2;
        QData/*63:0*/ SimTop__DOT__id_csr_data;
        QData/*63:0*/ SimTop__DOT__ex_pc;
        QData/*63:0*/ SimTop__DOT__ex_jmp_imm;
        QData/*63:0*/ SimTop__DOT__ex_now_op1;
        QData/*63:0*/ SimTop__DOT__ex_now_op2;
        QData/*63:0*/ SimTop__DOT__ex_rs1_data;
        QData/*63:0*/ SimTop__DOT__ex_rs2_data;
        QData/*63:0*/ SimTop__DOT__ex_csr_data;
        QData/*63:0*/ SimTop__DOT__rs1_forward;
        QData/*63:0*/ SimTop__DOT__rs2_forward;
        QData/*63:0*/ SimTop__DOT__true_op1;
        QData/*63:0*/ SimTop__DOT__true_op2;
        QData/*63:0*/ SimTop__DOT__mem_pc;
        QData/*63:0*/ SimTop__DOT__mem_ram_wr_src;
        QData/*63:0*/ SimTop__DOT__mem_ex_data;
        QData/*63:0*/ SimTop__DOT__mem_csr_data;
        QData/*63:0*/ SimTop__DOT__mem_ram_data;
        QData/*63:0*/ SimTop__DOT__wb_pc;
        QData/*63:0*/ SimTop__DOT__wb_ex_data;
        QData/*63:0*/ SimTop__DOT__wb_ram_data;
        QData/*63:0*/ SimTop__DOT__wb_csr_data;
        QData/*63:0*/ SimTop__DOT__r_data1;
        QData/*63:0*/ SimTop__DOT__r_data2;
        QData/*63:0*/ SimTop__DOT__wb_reg_wr_data;
        QData/*63:0*/ SimTop__DOT__mtval_rd_data;
        QData/*63:0*/ SimTop__DOT__cmt_wdata;
        QData/*63:0*/ SimTop__DOT__cmt_pc;
        QData/*63:0*/ SimTop__DOT__cycleCnt;
        QData/*63:0*/ SimTop__DOT__instrCnt;
        QData/*63:0*/ SimTop__DOT__RAM_1W2R__DOT__inst_2;
        QData/*63:0*/ SimTop__DOT__Ex_stage__DOT__op1;
        QData/*63:0*/ SimTop__DOT__Ex_stage__DOT__op2;
        QData/*63:0*/ SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in1;
        QData/*63:0*/ SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res;
        QData/*63:0*/ SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res;
        QData/*63:0*/ SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask;
        QData/*63:0*/ SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res;
        QData/*63:0*/ SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res;
        QData/*63:0*/ SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output;
        QData/*63:0*/ SimTop__DOT__Mem_stage__DOT__mem_part;
        QData/*63:0*/ SimTop__DOT__Excp_handler__DOT__mstatus_excp_enter;
        QData/*63:0*/ SimTop__DOT__Excp_handler__DOT__mstatus_excp_exit;
        QData/*63:0*/ SimTop__DOT__CSRfile__DOT__csr_mstatus;
        QData/*63:0*/ SimTop__DOT__CSRfile__DOT__csr_mie;
        QData/*63:0*/ SimTop__DOT__CSRfile__DOT__csr_mtvec;
        QData/*63:0*/ SimTop__DOT__CSRfile__DOT__csr_mscratch;
        QData/*63:0*/ SimTop__DOT__CSRfile__DOT__csr_mepc;
        QData/*63:0*/ SimTop__DOT__CSRfile__DOT__csr_mcause;
        QData/*63:0*/ SimTop__DOT__CSRfile__DOT__csr_mtval;
        QData/*63:0*/ SimTop__DOT__CSRfile__DOT__csr_mip;
        QData/*63:0*/ SimTop__DOT__CSRfile__DOT__csr_mcycle;
        VlUnpacked<QData/*63:0*/, 32> SimTop__DOT__regs;
        VlUnpacked<QData/*63:0*/, 32> SimTop__DOT__Regfile__DOT__regs;
    };

    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    QData/*63:0*/ __Vfunc_ram_read_helper__0__Vfuncout;
    QData/*63:0*/ __Vfunc_ram_read_helper__1__Vfuncout;
    VlUnpacked<QData/*63:0*/, 32> SimTop__DOT____Vcellout__Regfile__regs_o;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;

    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VSimTop__Syms* __VlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
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
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);

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
  private:
    static QData _change_request(VSimTop__Syms* __restrict vlSymsp);
    static QData _change_request_1(VSimTop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(VSimTop__Syms* __restrict vlSymsp);
  private:
    static void _ctor_var_reset(VSimTop* self) VL_ATTR_COLD;
  public:
    static void _eval(VSimTop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VSimTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VSimTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(VSimTop__Syms* __restrict vlSymsp);
    static void _settle__TOP__1(VSimTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
