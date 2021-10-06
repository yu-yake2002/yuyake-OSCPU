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
    CData/*0:0*/ SimTop__DOT__rd_w_ena;
    CData/*4:0*/ SimTop__DOT__rd_w_addr;
    CData/*4:0*/ SimTop__DOT__inst_type;
    CData/*7:0*/ SimTop__DOT__inst_opcode;
    CData/*0:0*/ SimTop__DOT__cmt_wen;
    CData/*7:0*/ SimTop__DOT__cmt_wdest;
    CData/*0:0*/ SimTop__DOT__cmt_valid;
    CData/*0:0*/ SimTop__DOT__trap;
    CData/*7:0*/ SimTop__DOT__trap_code;
    CData/*0:0*/ SimTop__DOT__inst_valid;
    CData/*0:0*/ SimTop__DOT__Id_stage__DOT__inst_addi;
    IData/*31:0*/ SimTop__DOT__inst;
    IData/*31:0*/ SimTop__DOT__cmt_inst;
    QData/*63:0*/ SimTop__DOT__pc;
    QData/*63:0*/ SimTop__DOT__rd_data;
    QData/*63:0*/ SimTop__DOT__cmt_wdata;
    QData/*63:0*/ SimTop__DOT__cmt_pc;
    QData/*63:0*/ SimTop__DOT__cycleCnt;
    QData/*63:0*/ SimTop__DOT__instrCnt;
    QData/*63:0*/ SimTop__DOT__If_stage__DOT__rdata;
    VlUnpacked<QData/*63:0*/, 32> SimTop__DOT__regs;
    VlUnpacked<QData/*63:0*/, 32> SimTop__DOT__regs_diff;
    VlUnpacked<QData/*63:0*/, 32> SimTop__DOT__Regfile__DOT__regs;

    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    QData/*63:0*/ __Vfunc_ram_read_helper__0__Vfuncout;
    VlUnpacked<QData/*63:0*/, 32> SimTop__DOT____Vcellout__Regfile__regs_o;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;

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
    static void _combo__TOP__4(VSimTop__Syms* __restrict vlSymsp);
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
    static void _sequent__TOP__3(VSimTop__Syms* __restrict vlSymsp);
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
