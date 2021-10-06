// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSimTop.h for the primary calling header

#include "VSimTop.h"
#include "VSimTop__Syms.h"

#include "verilated_dpi.h"

//==========

VerilatedContext* VSimTop::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void VSimTop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSimTop::eval\n"); );
    VSimTop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/yuyake/oscpu/projects/cpu_diff/build/SimTop.v", 6, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VSimTop::_eval_initial_loop(VSimTop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/yuyake/oscpu/projects/cpu_diff/build/SimTop.v", 6, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VSimTop::_sequent__TOP__2(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_sequent__TOP__2\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__SimTop__DOT__Regfile__DOT__regs__v0;
    CData/*4:0*/ __Vdlyvdim0__SimTop__DOT__Regfile__DOT__regs__v32;
    CData/*0:0*/ __Vdlyvset__SimTop__DOT__Regfile__DOT__regs__v32;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__Regfile__DOT__regs__v32;
    // Body
    __Vdlyvset__SimTop__DOT__Regfile__DOT__regs__v0 = 0U;
    __Vdlyvset__SimTop__DOT__Regfile__DOT__regs__v32 = 0U;
    vlSymsp->TOP____024unit.__Vdpiimwrap_ram_write_helper_TOP____024unit(0ULL, 0ULL, 0ULL, 0U);
    vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_CSRState_TOP____024unit(0U, 0U, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL);
    vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_ArchFpRegState_TOP____024unit(0U, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL);
    vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_ArchIntRegState_TOP____024unit(0U, 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [1U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [2U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [3U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [4U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [5U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [6U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [7U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [8U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [9U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0xaU], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0xbU], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0xcU], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0xdU], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0xeU], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0xfU], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x10U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x11U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x12U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x13U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x14U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x15U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x16U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x17U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x18U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x19U], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x1aU], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x1bU], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x1cU], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x1dU], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x1eU], 
                                                                                vlTOPp->SimTop__DOT__regs_diff
                                                                                [0x1fU]);
    vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_TrapEvent_TOP____024unit(0U, (IData)(vlTOPp->SimTop__DOT__trap), 
                                                                             (7U 
                                                                              & (IData)(vlTOPp->SimTop__DOT__trap_code)), vlTOPp->SimTop__DOT__cmt_pc, vlTOPp->SimTop__DOT__cycleCnt, vlTOPp->SimTop__DOT__instrCnt);
    if (vlTOPp->SimTop__DOT__cmt_valid) {
        vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_InstrCommit_TOP____024unit(0U, 0U, (IData)(vlTOPp->SimTop__DOT__cmt_valid), vlTOPp->SimTop__DOT__cmt_pc, vlTOPp->SimTop__DOT__cmt_inst, 0U, 0U, 0U, (IData)(vlTOPp->SimTop__DOT__cmt_wen), vlTOPp->SimTop__DOT__cmt_wdest, vlTOPp->SimTop__DOT__cmt_wdata);
    }
    if (vlTOPp->reset) {
        __Vdlyvset__SimTop__DOT__Regfile__DOT__regs__v0 = 1U;
    } else if (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
                & (0U != (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))) {
        __Vdlyvval__SimTop__DOT__Regfile__DOT__regs__v32 
            = vlTOPp->SimTop__DOT__rd_data;
        __Vdlyvset__SimTop__DOT__Regfile__DOT__regs__v32 = 1U;
        __Vdlyvdim0__SimTop__DOT__Regfile__DOT__regs__v32 
            = vlTOPp->SimTop__DOT__rd_w_addr;
    }
    vlTOPp->SimTop__DOT__pc = ((IData)(vlTOPp->reset)
                                ? 0x7ffffffcULL : (4ULL 
                                                   + vlTOPp->SimTop__DOT__pc));
    if (__Vdlyvset__SimTop__DOT__Regfile__DOT__regs__v0) {
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[1U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[2U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[3U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[4U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[5U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[6U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[7U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[8U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[9U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0xaU] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0xbU] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0xcU] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0xdU] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0xeU] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0xfU] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x10U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x11U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x12U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x13U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x14U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x15U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x16U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x17U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x18U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x19U] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x1aU] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x1bU] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x1cU] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x1dU] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x1eU] = 0ULL;
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x1fU] = 0ULL;
    }
    if (__Vdlyvset__SimTop__DOT__Regfile__DOT__regs__v32) {
        vlTOPp->SimTop__DOT__Regfile__DOT__regs[__Vdlyvdim0__SimTop__DOT__Regfile__DOT__regs__v32] 
            = __Vdlyvval__SimTop__DOT__Regfile__DOT__regs__v32;
    }
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0U];
    vlSymsp->TOP____024unit.__Vdpiimwrap_ram_read_helper_TOP____024unit(1U, 
                                                                        ((vlTOPp->SimTop__DOT__pc 
                                                                          - 0x80000000ULL) 
                                                                         >> 3U), vlTOPp->__Vfunc_ram_read_helper__0__Vfuncout);
    vlTOPp->SimTop__DOT__If_stage__DOT__rdata = vlTOPp->__Vfunc_ram_read_helper__0__Vfuncout;
    vlTOPp->SimTop__DOT__inst = ((1U & (IData)((vlTOPp->SimTop__DOT__pc 
                                                >> 2U)))
                                  ? (IData)((vlTOPp->SimTop__DOT__If_stage__DOT__rdata 
                                             >> 0x20U))
                                  : (IData)(vlTOPp->SimTop__DOT__If_stage__DOT__rdata));
    vlTOPp->SimTop__DOT__inst_valid = ((0x80000000ULL 
                                        != vlTOPp->SimTop__DOT__pc) 
                                       | (0U != vlTOPp->SimTop__DOT__inst));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addi = (IData)(
                                                            (0x10U 
                                                             == 
                                                             (0x703cU 
                                                              & vlTOPp->SimTop__DOT__inst)));
}

VL_INLINE_OPT void VSimTop::_sequent__TOP__3(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_sequent__TOP__3\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__SimTop__DOT__trap;
    CData/*0:0*/ __Vdlyvset__SimTop__DOT__regs_diff__v0;
    CData/*0:0*/ __Vdlyvset__SimTop__DOT__regs_diff__v1;
    QData/*63:0*/ __Vdly__SimTop__DOT__cycleCnt;
    QData/*63:0*/ __Vdly__SimTop__DOT__instrCnt;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v0;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v1;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v2;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v3;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v4;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v5;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v6;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v7;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v8;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v9;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v10;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v11;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v12;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v13;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v14;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v15;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v16;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v17;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v18;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v19;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v20;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v21;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v22;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v23;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v24;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v25;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v26;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v27;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v28;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v29;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v30;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__regs_diff__v31;
    // Body
    __Vdly__SimTop__DOT__instrCnt = vlTOPp->SimTop__DOT__instrCnt;
    __Vdly__SimTop__DOT__cycleCnt = vlTOPp->SimTop__DOT__cycleCnt;
    __Vdly__SimTop__DOT__trap = vlTOPp->SimTop__DOT__trap;
    __Vdlyvset__SimTop__DOT__regs_diff__v0 = 0U;
    __Vdlyvset__SimTop__DOT__regs_diff__v1 = 0U;
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__cmt_wen = 0U;
        vlTOPp->SimTop__DOT__cmt_wdest = 0U;
        vlTOPp->SimTop__DOT__cmt_wdata = 0ULL;
        vlTOPp->SimTop__DOT__cmt_pc = 0ULL;
        vlTOPp->SimTop__DOT__cmt_inst = 0U;
        vlTOPp->SimTop__DOT__cmt_valid = 0U;
        __Vdly__SimTop__DOT__trap = 0U;
        vlTOPp->SimTop__DOT__trap_code = 0U;
        __Vdly__SimTop__DOT__cycleCnt = 0ULL;
        __Vdly__SimTop__DOT__instrCnt = 0ULL;
    } else if ((1U & (~ (IData)(vlTOPp->SimTop__DOT__trap)))) {
        __Vdly__SimTop__DOT__cycleCnt = (1ULL + vlTOPp->SimTop__DOT__cycleCnt);
        __Vdly__SimTop__DOT__instrCnt = (vlTOPp->SimTop__DOT__instrCnt 
                                         + (QData)((IData)(vlTOPp->SimTop__DOT__inst_valid)));
        vlTOPp->SimTop__DOT__cmt_wen = vlTOPp->SimTop__DOT__rd_w_ena;
        vlTOPp->SimTop__DOT__cmt_wdest = vlTOPp->SimTop__DOT__rd_w_addr;
        vlTOPp->SimTop__DOT__cmt_wdata = vlTOPp->SimTop__DOT__rd_data;
        vlTOPp->SimTop__DOT__cmt_pc = vlTOPp->SimTop__DOT__pc;
        vlTOPp->SimTop__DOT__cmt_inst = vlTOPp->SimTop__DOT__inst;
        vlTOPp->SimTop__DOT__cmt_valid = vlTOPp->SimTop__DOT__inst_valid;
        __Vdlyvval__SimTop__DOT__regs_diff__v0 = vlTOPp->SimTop__DOT__regs
            [0U];
        __Vdlyvset__SimTop__DOT__regs_diff__v0 = 1U;
        __Vdly__SimTop__DOT__trap = (0x6bU == (0x7fU 
                                               & vlTOPp->SimTop__DOT__inst));
        vlTOPp->SimTop__DOT__trap_code = (0xffU & (IData)(
                                                          vlTOPp->SimTop__DOT__regs
                                                          [0xaU]));
        __Vdlyvval__SimTop__DOT__regs_diff__v1 = vlTOPp->SimTop__DOT__regs
            [1U];
        __Vdlyvset__SimTop__DOT__regs_diff__v1 = 1U;
        __Vdlyvval__SimTop__DOT__regs_diff__v2 = vlTOPp->SimTop__DOT__regs
            [2U];
        __Vdlyvval__SimTop__DOT__regs_diff__v3 = vlTOPp->SimTop__DOT__regs
            [3U];
        __Vdlyvval__SimTop__DOT__regs_diff__v4 = vlTOPp->SimTop__DOT__regs
            [4U];
        __Vdlyvval__SimTop__DOT__regs_diff__v5 = vlTOPp->SimTop__DOT__regs
            [5U];
        __Vdlyvval__SimTop__DOT__regs_diff__v6 = vlTOPp->SimTop__DOT__regs
            [6U];
        __Vdlyvval__SimTop__DOT__regs_diff__v7 = vlTOPp->SimTop__DOT__regs
            [7U];
        __Vdlyvval__SimTop__DOT__regs_diff__v8 = vlTOPp->SimTop__DOT__regs
            [8U];
        __Vdlyvval__SimTop__DOT__regs_diff__v9 = vlTOPp->SimTop__DOT__regs
            [9U];
        __Vdlyvval__SimTop__DOT__regs_diff__v10 = vlTOPp->SimTop__DOT__regs
            [0xaU];
        __Vdlyvval__SimTop__DOT__regs_diff__v11 = vlTOPp->SimTop__DOT__regs
            [0xbU];
        __Vdlyvval__SimTop__DOT__regs_diff__v12 = vlTOPp->SimTop__DOT__regs
            [0xcU];
        __Vdlyvval__SimTop__DOT__regs_diff__v13 = vlTOPp->SimTop__DOT__regs
            [0xdU];
        __Vdlyvval__SimTop__DOT__regs_diff__v14 = vlTOPp->SimTop__DOT__regs
            [0xeU];
        __Vdlyvval__SimTop__DOT__regs_diff__v15 = vlTOPp->SimTop__DOT__regs
            [0xfU];
        __Vdlyvval__SimTop__DOT__regs_diff__v16 = vlTOPp->SimTop__DOT__regs
            [0x10U];
        __Vdlyvval__SimTop__DOT__regs_diff__v17 = vlTOPp->SimTop__DOT__regs
            [0x11U];
        __Vdlyvval__SimTop__DOT__regs_diff__v18 = vlTOPp->SimTop__DOT__regs
            [0x12U];
        __Vdlyvval__SimTop__DOT__regs_diff__v19 = vlTOPp->SimTop__DOT__regs
            [0x13U];
        __Vdlyvval__SimTop__DOT__regs_diff__v20 = vlTOPp->SimTop__DOT__regs
            [0x14U];
        __Vdlyvval__SimTop__DOT__regs_diff__v21 = vlTOPp->SimTop__DOT__regs
            [0x15U];
        __Vdlyvval__SimTop__DOT__regs_diff__v22 = vlTOPp->SimTop__DOT__regs
            [0x16U];
        __Vdlyvval__SimTop__DOT__regs_diff__v23 = vlTOPp->SimTop__DOT__regs
            [0x17U];
        __Vdlyvval__SimTop__DOT__regs_diff__v24 = vlTOPp->SimTop__DOT__regs
            [0x18U];
        __Vdlyvval__SimTop__DOT__regs_diff__v25 = vlTOPp->SimTop__DOT__regs
            [0x19U];
        __Vdlyvval__SimTop__DOT__regs_diff__v26 = vlTOPp->SimTop__DOT__regs
            [0x1aU];
        __Vdlyvval__SimTop__DOT__regs_diff__v27 = vlTOPp->SimTop__DOT__regs
            [0x1bU];
        __Vdlyvval__SimTop__DOT__regs_diff__v28 = vlTOPp->SimTop__DOT__regs
            [0x1cU];
        __Vdlyvval__SimTop__DOT__regs_diff__v29 = vlTOPp->SimTop__DOT__regs
            [0x1dU];
        __Vdlyvval__SimTop__DOT__regs_diff__v30 = vlTOPp->SimTop__DOT__regs
            [0x1eU];
        __Vdlyvval__SimTop__DOT__regs_diff__v31 = vlTOPp->SimTop__DOT__regs
            [0x1fU];
    }
    vlTOPp->SimTop__DOT__trap = __Vdly__SimTop__DOT__trap;
    vlTOPp->SimTop__DOT__cycleCnt = __Vdly__SimTop__DOT__cycleCnt;
    vlTOPp->SimTop__DOT__instrCnt = __Vdly__SimTop__DOT__instrCnt;
    if (__Vdlyvset__SimTop__DOT__regs_diff__v0) {
        vlTOPp->SimTop__DOT__regs_diff[0U] = __Vdlyvval__SimTop__DOT__regs_diff__v0;
    }
    if (__Vdlyvset__SimTop__DOT__regs_diff__v1) {
        vlTOPp->SimTop__DOT__regs_diff[1U] = __Vdlyvval__SimTop__DOT__regs_diff__v1;
        vlTOPp->SimTop__DOT__regs_diff[2U] = __Vdlyvval__SimTop__DOT__regs_diff__v2;
        vlTOPp->SimTop__DOT__regs_diff[3U] = __Vdlyvval__SimTop__DOT__regs_diff__v3;
        vlTOPp->SimTop__DOT__regs_diff[4U] = __Vdlyvval__SimTop__DOT__regs_diff__v4;
        vlTOPp->SimTop__DOT__regs_diff[5U] = __Vdlyvval__SimTop__DOT__regs_diff__v5;
        vlTOPp->SimTop__DOT__regs_diff[6U] = __Vdlyvval__SimTop__DOT__regs_diff__v6;
        vlTOPp->SimTop__DOT__regs_diff[7U] = __Vdlyvval__SimTop__DOT__regs_diff__v7;
        vlTOPp->SimTop__DOT__regs_diff[8U] = __Vdlyvval__SimTop__DOT__regs_diff__v8;
        vlTOPp->SimTop__DOT__regs_diff[9U] = __Vdlyvval__SimTop__DOT__regs_diff__v9;
        vlTOPp->SimTop__DOT__regs_diff[0xaU] = __Vdlyvval__SimTop__DOT__regs_diff__v10;
        vlTOPp->SimTop__DOT__regs_diff[0xbU] = __Vdlyvval__SimTop__DOT__regs_diff__v11;
        vlTOPp->SimTop__DOT__regs_diff[0xcU] = __Vdlyvval__SimTop__DOT__regs_diff__v12;
        vlTOPp->SimTop__DOT__regs_diff[0xdU] = __Vdlyvval__SimTop__DOT__regs_diff__v13;
        vlTOPp->SimTop__DOT__regs_diff[0xeU] = __Vdlyvval__SimTop__DOT__regs_diff__v14;
        vlTOPp->SimTop__DOT__regs_diff[0xfU] = __Vdlyvval__SimTop__DOT__regs_diff__v15;
        vlTOPp->SimTop__DOT__regs_diff[0x10U] = __Vdlyvval__SimTop__DOT__regs_diff__v16;
        vlTOPp->SimTop__DOT__regs_diff[0x11U] = __Vdlyvval__SimTop__DOT__regs_diff__v17;
        vlTOPp->SimTop__DOT__regs_diff[0x12U] = __Vdlyvval__SimTop__DOT__regs_diff__v18;
        vlTOPp->SimTop__DOT__regs_diff[0x13U] = __Vdlyvval__SimTop__DOT__regs_diff__v19;
        vlTOPp->SimTop__DOT__regs_diff[0x14U] = __Vdlyvval__SimTop__DOT__regs_diff__v20;
        vlTOPp->SimTop__DOT__regs_diff[0x15U] = __Vdlyvval__SimTop__DOT__regs_diff__v21;
        vlTOPp->SimTop__DOT__regs_diff[0x16U] = __Vdlyvval__SimTop__DOT__regs_diff__v22;
        vlTOPp->SimTop__DOT__regs_diff[0x17U] = __Vdlyvval__SimTop__DOT__regs_diff__v23;
        vlTOPp->SimTop__DOT__regs_diff[0x18U] = __Vdlyvval__SimTop__DOT__regs_diff__v24;
        vlTOPp->SimTop__DOT__regs_diff[0x19U] = __Vdlyvval__SimTop__DOT__regs_diff__v25;
        vlTOPp->SimTop__DOT__regs_diff[0x1aU] = __Vdlyvval__SimTop__DOT__regs_diff__v26;
        vlTOPp->SimTop__DOT__regs_diff[0x1bU] = __Vdlyvval__SimTop__DOT__regs_diff__v27;
        vlTOPp->SimTop__DOT__regs_diff[0x1cU] = __Vdlyvval__SimTop__DOT__regs_diff__v28;
        vlTOPp->SimTop__DOT__regs_diff[0x1dU] = __Vdlyvval__SimTop__DOT__regs_diff__v29;
        vlTOPp->SimTop__DOT__regs_diff[0x1eU] = __Vdlyvval__SimTop__DOT__regs_diff__v30;
        vlTOPp->SimTop__DOT__regs_diff[0x1fU] = __Vdlyvval__SimTop__DOT__regs_diff__v31;
    }
}

VL_INLINE_OPT void VSimTop::_combo__TOP__4(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_combo__TOP__4\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SimTop__DOT__inst_opcode = ((0xfeU & (IData)(vlTOPp->SimTop__DOT__inst_opcode)) 
                                        | ((IData)(vlTOPp->reset)
                                            ? 0U : 
                                           (1U & (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addi))));
    vlTOPp->SimTop__DOT__inst_opcode = ((0xefU & (IData)(vlTOPp->SimTop__DOT__inst_opcode)) 
                                        | (((IData)(vlTOPp->reset)
                                             ? 0U : 
                                            (1U & (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addi))) 
                                           << 4U));
    vlTOPp->SimTop__DOT__inst_type = ((0xfU & (IData)(vlTOPp->SimTop__DOT__inst_type)) 
                                      | (((IData)(vlTOPp->reset)
                                           ? 0U : (1U 
                                                   & (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addi))) 
                                         << 4U));
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__rd_w_ena = 0U;
        vlTOPp->SimTop__DOT__rd_w_addr = 0U;
        vlTOPp->SimTop__DOT__rd_data = 0ULL;
    } else {
        vlTOPp->SimTop__DOT__rd_w_ena = (1U & ((IData)(vlTOPp->SimTop__DOT__inst_type) 
                                               >> 4U));
        vlTOPp->SimTop__DOT__rd_w_addr = ((0x10U & (IData)(vlTOPp->SimTop__DOT__inst_type))
                                           ? (0x1fU 
                                              & (vlTOPp->SimTop__DOT__inst 
                                                 >> 7U))
                                           : 0U);
        vlTOPp->SimTop__DOT__rd_data = ((0x11U == (IData)(vlTOPp->SimTop__DOT__inst_opcode))
                                         ? (((IData)(vlTOPp->reset)
                                              ? 0ULL
                                              : ((0x10U 
                                                  & (IData)(vlTOPp->SimTop__DOT__inst_type))
                                                  ? 
                                                 ((IData)(vlTOPp->reset)
                                                   ? 0ULL
                                                   : 
                                                  (((IData)(vlTOPp->reset)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & ((IData)(vlTOPp->SimTop__DOT__inst_type) 
                                                        >> 4U)))
                                                    ? 
                                                   vlTOPp->SimTop__DOT__Regfile__DOT__regs
                                                   [
                                                   ((IData)(vlTOPp->reset)
                                                     ? 0U
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlTOPp->SimTop__DOT__inst_type))
                                                      ? 
                                                     (0x1fU 
                                                      & (vlTOPp->SimTop__DOT__inst 
                                                         >> 0xfU))
                                                      : 0U))]
                                                    : 0ULL))
                                                  : 0ULL)) 
                                            + ((IData)(vlTOPp->reset)
                                                ? 0ULL
                                                : (
                                                   (0x10U 
                                                    & (IData)(vlTOPp->SimTop__DOT__inst_type))
                                                    ? 
                                                   ((0xfffffffffffff000ULL 
                                                     & ((- (QData)((IData)(
                                                                           (1U 
                                                                            & (vlTOPp->SimTop__DOT__inst 
                                                                               >> 0x1fU))))) 
                                                        << 0xcU)) 
                                                    | (QData)((IData)(
                                                                      (0xfffU 
                                                                       & (vlTOPp->SimTop__DOT__inst 
                                                                          >> 0x14U)))))
                                                    : 0ULL)))
                                         : 0ULL);
    }
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[1U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (1U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [1U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[2U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (2U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [2U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[3U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (3U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [3U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[4U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (4U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [4U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[5U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (5U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [5U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[6U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (6U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [6U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[7U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (7U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [7U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[8U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (8U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [8U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[9U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (9U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [9U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0xaU] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0xaU == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0xaU]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0xbU] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0xbU == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0xbU]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0xcU] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0xcU == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0xcU]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0xdU] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0xdU == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0xdU]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0xeU] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0xeU == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0xeU]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0xfU] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0xfU == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0xfU]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x10U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x10U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x10U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x11U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x11U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x11U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x12U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x12U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x12U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x13U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x13U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x13U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x14U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x14U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x14U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x15U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x15U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x15U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x16U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x16U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x16U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x17U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x17U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x17U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x18U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x18U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x18U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x19U] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x19U == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x19U]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x1aU] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x1aU == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x1aU]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x1bU] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x1bU == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x1bU]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x1cU] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x1cU == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x1cU]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x1dU] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x1dU == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x1dU]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x1eU] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x1eU == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x1eU]);
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x1fU] 
        = (((IData)(vlTOPp->SimTop__DOT__rd_w_ena) 
            & (0x1fU == (IData)(vlTOPp->SimTop__DOT__rd_w_addr)))
            ? vlTOPp->SimTop__DOT__rd_data : vlTOPp->SimTop__DOT__Regfile__DOT__regs
           [0x1fU]);
    vlTOPp->SimTop__DOT__regs[0U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0U];
    vlTOPp->SimTop__DOT__regs[1U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [1U];
    vlTOPp->SimTop__DOT__regs[2U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [2U];
    vlTOPp->SimTop__DOT__regs[3U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [3U];
    vlTOPp->SimTop__DOT__regs[4U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [4U];
    vlTOPp->SimTop__DOT__regs[5U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [5U];
    vlTOPp->SimTop__DOT__regs[6U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [6U];
    vlTOPp->SimTop__DOT__regs[7U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [7U];
    vlTOPp->SimTop__DOT__regs[8U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [8U];
    vlTOPp->SimTop__DOT__regs[9U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [9U];
    vlTOPp->SimTop__DOT__regs[0xaU] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0xaU];
    vlTOPp->SimTop__DOT__regs[0xbU] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0xbU];
    vlTOPp->SimTop__DOT__regs[0xcU] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0xcU];
    vlTOPp->SimTop__DOT__regs[0xdU] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0xdU];
    vlTOPp->SimTop__DOT__regs[0xeU] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0xeU];
    vlTOPp->SimTop__DOT__regs[0xfU] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0xfU];
    vlTOPp->SimTop__DOT__regs[0x10U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x10U];
    vlTOPp->SimTop__DOT__regs[0x11U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x11U];
    vlTOPp->SimTop__DOT__regs[0x12U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x12U];
    vlTOPp->SimTop__DOT__regs[0x13U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x13U];
    vlTOPp->SimTop__DOT__regs[0x14U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x14U];
    vlTOPp->SimTop__DOT__regs[0x15U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x15U];
    vlTOPp->SimTop__DOT__regs[0x16U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x16U];
    vlTOPp->SimTop__DOT__regs[0x17U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x17U];
    vlTOPp->SimTop__DOT__regs[0x18U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x18U];
    vlTOPp->SimTop__DOT__regs[0x19U] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x19U];
    vlTOPp->SimTop__DOT__regs[0x1aU] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x1aU];
    vlTOPp->SimTop__DOT__regs[0x1bU] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x1bU];
    vlTOPp->SimTop__DOT__regs[0x1cU] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x1cU];
    vlTOPp->SimTop__DOT__regs[0x1dU] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x1dU];
    vlTOPp->SimTop__DOT__regs[0x1eU] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x1eU];
    vlTOPp->SimTop__DOT__regs[0x1fU] = vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o
        [0x1fU];
}

void VSimTop::_eval(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_eval\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((~ (IData)(vlTOPp->clock)) & (IData)(vlTOPp->__Vclklast__TOP__clock))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData VSimTop::_change_request(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_change_request\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VSimTop::_change_request_1(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_change_request_1\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VSimTop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_perfInfo_clean & 0xfeU))) {
        Verilated::overWidthError("io_perfInfo_clean");}
    if (VL_UNLIKELY((io_perfInfo_dump & 0xfeU))) {
        Verilated::overWidthError("io_perfInfo_dump");}
}
#endif  // VL_DEBUG
