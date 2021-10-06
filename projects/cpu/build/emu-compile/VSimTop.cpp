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
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/yuyake/oscpu/projects/cpu/build/SimTop.v", 5, "",
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
            VL_FATAL_MT("/home/yuyake/oscpu/projects/cpu/build/SimTop.v", 5, "",
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
    CData/*7:0*/ __Vtableidx1;
    CData/*6:0*/ __Vtableidx2;
    CData/*6:0*/ __Vtableidx3;
    CData/*6:0*/ __Vtableidx6;
    CData/*7:0*/ __Vdly__SimTop__DOT__mem_axi_rw__DOT__len;
    CData/*7:0*/ __Vdly__SimTop__DOT__if_axi_rw__DOT__len;
    CData/*0:0*/ __Vdly__SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid;
    CData/*0:0*/ __Vdlyvset__SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs__v0;
    CData/*4:0*/ __Vdlyvdim0__SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs__v32;
    CData/*0:0*/ __Vdlyvset__SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs__v32;
    CData/*0:0*/ __Vdly__SimTop__DOT__Clint__DOT__r_state;
    IData/*31:0*/ __Vdly__SimTop__DOT__Clint__DOT__csr_msip;
    VlWide<4>/*127:0*/ __Vtemp298;
    VlWide<4>/*127:0*/ __Vtemp299;
    VlWide<3>/*95:0*/ __Vtemp304;
    VlWide<4>/*127:0*/ __Vtemp310;
    VlWide<8>/*255:0*/ __Vtemp311;
    VlWide<8>/*255:0*/ __Vtemp312;
    VlWide<8>/*255:0*/ __Vtemp313;
    VlWide<3>/*95:0*/ __Vtemp321;
    VlWide<11>/*351:0*/ __Vtemp322;
    VlWide<11>/*351:0*/ __Vtemp323;
    VlWide<4>/*127:0*/ __Vtemp533;
    VlWide<4>/*127:0*/ __Vtemp534;
    QData/*63:0*/ __Vdly__SimTop__DOT__mem_r_data;
    QData/*63:0*/ __Vdly__SimTop__DOT__if_r_data;
    QData/*63:0*/ __Vdly__SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_pc;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs__v32;
    QData/*63:0*/ __Vdly__SimTop__DOT__Clint__DOT__csr_mtimecmp;
    // Body
    __Vdly__SimTop__DOT__Clint__DOT__r_state = vlTOPp->SimTop__DOT__Clint__DOT__r_state;
    __Vdly__SimTop__DOT__if_axi_rw__DOT__len = vlTOPp->SimTop__DOT__if_axi_rw__DOT__len;
    __Vdly__SimTop__DOT__Clint__DOT__csr_msip = vlTOPp->SimTop__DOT__Clint__DOT__csr_msip;
    __Vdly__SimTop__DOT__Clint__DOT__csr_mtimecmp = vlTOPp->SimTop__DOT__Clint__DOT__csr_mtimecmp;
    __Vdly__SimTop__DOT__mem_axi_rw__DOT__len = vlTOPp->SimTop__DOT__mem_axi_rw__DOT__len;
    __Vdly__SimTop__DOT__if_r_data = vlTOPp->SimTop__DOT__if_r_data;
    __Vdly__SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_pc 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_pc;
    __Vdly__SimTop__DOT__mem_r_data = vlTOPp->SimTop__DOT__mem_r_data;
    __Vdly__SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid;
    __Vdlyvset__SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs__v0 = 0U;
    __Vdlyvset__SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs__v32 = 0U;
    vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_ArchFpRegState_TOP____024unit(0U, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL);
    vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_ArchEvent_TOP____024unit(0U, vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_itrp_NO, 
                                                                             (vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_excp_NO 
                                                                              & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_valid)))), vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_pc, (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_inst)));
    vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_CSRState_TOP____024unit(0U, 3U, vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mstatus, 
                                                                            (0x80000003000de122ULL 
                                                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mstatus), vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mepc, 0ULL, vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mtval, 0ULL, vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mtvec, 0ULL, vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mcause, 0ULL, 0ULL, 0ULL, vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mie, vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mscratch, 0ULL, 0ULL, 0ULL);
    if (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_ena) 
         & (0x200ULL != (0xffffffffffffULL & (((QData)((IData)(
                                                               vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[7U])) 
                                               << 0x25U) 
                                              | (((QData)((IData)(
                                                                  vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[6U])) 
                                                  << 5U) 
                                                 | ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[5U])) 
                                                    >> 0x1bU))))))) {
        vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_StoreEvent_TOP____024unit(0U, 0U, 
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_ena) 
                                                                                & (0x200ULL 
                                                                                != 
                                                                                (0xffffffffffffULL 
                                                                                & (((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[7U])) 
                                                                                << 0x25U) 
                                                                                | (((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[6U])) 
                                                                                << 5U) 
                                                                                | ((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[5U])) 
                                                                                >> 0x1bU)))))), vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_rw_addr, vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_data, (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_mask));
    }
    vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_ArchIntRegState_TOP____024unit(0U, 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [1U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [2U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [3U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [4U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [5U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [6U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [7U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [8U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [9U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0xaU], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0xbU], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0xcU], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0xdU], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0xeU], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0xfU], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x10U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x11U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x12U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x13U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x14U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x15U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x16U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x17U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x18U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x19U], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x1aU], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x1bU], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x1cU], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x1dU], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x1eU], 
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0x1fU]);
    vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_TrapEvent_TOP____024unit(0U, 
                                                                             (0x6bU 
                                                                              == 
                                                                              (0x7fU 
                                                                               & vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_inst)), 
                                                                             (7U 
                                                                              & (IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                                                [0xaU])), vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_pc, vlTOPp->SimTop__DOT__u_cpu__DOT__cycleCnt, vlTOPp->SimTop__DOT__u_cpu__DOT__instrCnt);
    if ((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_valid) 
          & (~ (IData)((0U != vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_excp_NO)))) 
         & (~ (IData)((0U != vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_itrp_NO))))) {
        vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_InstrCommit_TOP____024unit(0U, 0U, 
                                                                                (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_valid) 
                                                                                & (~ (IData)(
                                                                                (0U 
                                                                                != vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_excp_NO)))) 
                                                                                & (~ (IData)(
                                                                                (0U 
                                                                                != vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_itrp_NO)))), vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_pc, vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_inst, (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_skip), 0U, 0U, (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wen), vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wdest, vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wdata);
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__cycleCnt = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__instrCnt = 0ULL;
    } else {
        vlTOPp->SimTop__DOT__u_cpu__DOT__cycleCnt = 
            (1ULL + vlTOPp->SimTop__DOT__u_cpu__DOT__cycleCnt);
        vlTOPp->SimTop__DOT__u_cpu__DOT__instrCnt = 
            (vlTOPp->SimTop__DOT__u_cpu__DOT__instrCnt 
             + (QData)((IData)((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0U] 
                                      & (~ (IData)(
                                                   (0U 
                                                    != 
                                                    ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[9U] 
                                                      << 0x15U) 
                                                     | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[8U] 
                                                        >> 0xbU))))))))));
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__if_axi_rw__DOT__rw_ready = 0U;
    } else if (vlTOPp->SimTop__DOT__if_axi_rw__DOT__rw_ready_en) {
        vlTOPp->SimTop__DOT__if_axi_rw__DOT__rw_ready 
            = vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_done;
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__if_axi_w_data = 0ULL;
    } else if (vlTOPp->SimTop__DOT__if_axi_rw__DOT__aw_hs) {
        vlTOPp->SimTop__DOT__if_axi_w_data = 0ULL;
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__mem_axi_rw__DOT__rw_ready = 0U;
    } else if (vlTOPp->SimTop__DOT__mem_axi_rw__DOT__rw_ready_en) {
        vlTOPp->SimTop__DOT__mem_axi_rw__DOT__rw_ready 
            = vlTOPp->SimTop__DOT__mem_axi_rw__DOT__trans_done;
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_valid = 0U;
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__id_allowin) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_valid 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__if_to_id_valid;
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_flush) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_valid = 0U;
    }
    if (vlTOPp->reset) {
        __Vdly__SimTop__DOT__Clint__DOT__r_state = 0U;
    } else if (vlTOPp->SimTop__DOT__Clint__DOT__r_state) {
        if (vlTOPp->SimTop__DOT__Clint__DOT__r_state) {
            if (vlTOPp->SimTop__DOT__cli_r_ready) {
                __Vdly__SimTop__DOT__Clint__DOT__r_state = 0U;
            }
        }
    } else if (vlTOPp->SimTop__DOT__Clint__DOT__ar_hs) {
        __Vdly__SimTop__DOT__Clint__DOT__r_state = 1U;
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__mem_axi_w_data = 0ULL;
    } else if (vlTOPp->SimTop__DOT__mem_axi_rw__DOT__aw_hs) {
        vlTOPp->SimTop__DOT__mem_axi_w_data = (((((- (QData)((IData)(
                                                                     (0U 
                                                                      == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                                                  & (((QData)((IData)(
                                                                      (0xffU 
                                                                       & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                                      << 0x38U) 
                                                     | (((QData)((IData)(
                                                                         (0xffU 
                                                                          & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                                         << 0x30U) 
                                                        | (((QData)((IData)(
                                                                            (0xffU 
                                                                             & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                                            << 0x28U) 
                                                           | (((QData)((IData)(
                                                                               (0xffU 
                                                                                & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                                               << 0x20U) 
                                                              | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                                                  << 0x18U) 
                                                                 | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                                                     << 0x10U) 
                                                                    | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                                                        << 8U) 
                                                                       | (QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))))))))))) 
                                                 | ((- (QData)((IData)(
                                                                       (1U 
                                                                        == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                                                    & (((QData)((IData)(
                                                                        (0xffffU 
                                                                         & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                                        << 0x30U) 
                                                       | (((QData)((IData)(
                                                                           (0xffffU 
                                                                            & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                                           << 0x20U) 
                                                          | (((QData)((IData)(
                                                                              (0xffffU 
                                                                               & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                                              << 0x10U) 
                                                             | (QData)((IData)(
                                                                               (0xffffU 
                                                                                & (IData)(vlTOPp->SimTop__DOT__mem_w_data))))))))) 
                                                | ((- (QData)((IData)(
                                                                      (2U 
                                                                       == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                                                   & (((QData)((IData)(vlTOPp->SimTop__DOT__mem_w_data)) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(vlTOPp->SimTop__DOT__mem_w_data))))) 
                                               | ((- (QData)((IData)(
                                                                     (3U 
                                                                      == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                                                  & vlTOPp->SimTop__DOT__mem_w_data));
    }
    if (((IData)(vlTOPp->reset) | (0U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state)))) {
        __Vdly__SimTop__DOT__if_axi_rw__DOT__len = 0U;
    } else if (vlTOPp->SimTop__DOT__if_axi_rw__DOT__len_incr_en) {
        __Vdly__SimTop__DOT__if_axi_rw__DOT__len = 
            (0xffU & ((IData)(1U) + (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__len)));
    }
    vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_next_state));
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg = 0U;
    } else if (vlTOPp->SimTop__DOT__Clint__DOT__ar_hs) {
        vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg 
            = ((- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
               & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_size));
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg = 0ULL;
    } else if (vlTOPp->SimTop__DOT__Clint__DOT__ar_hs) {
        vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg 
            = ((- (QData)((IData)((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state))))) 
               & vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_addr);
    } else if (vlTOPp->SimTop__DOT__cli_r_ready) {
        vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg = 0ULL;
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state = 0U;
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg = 0U;
    } else if (vlTOPp->SimTop__DOT__Clint__DOT__aw_hs) {
        vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg 
            = ((- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
               & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_size));
    }
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mcycle 
        = ((IData)(vlTOPp->reset) ? 0ULL : ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcycle_wr_ena)
                                             ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data
                                             : (1ULL 
                                                + vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mcycle)));
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mscratch = 0ULL;
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_wr_ena) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mscratch 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data;
    }
    vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_next_state));
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mtval = 0ULL;
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__excp_enter_wr) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mtval 
            = (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[3U])) 
                << 0x20U) | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[2U])));
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_wr_ena) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mtval 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data;
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mcause = 0ULL;
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__excp_enter_wr) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mcause 
            = (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[7U])) 
                << 0x20U) | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[6U])));
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_wr_ena) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mcause 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data;
    }
    __Vtableidx6 = (((IData)(vlTOPp->SimTop__DOT__Clint__DOT__b_hs) 
                     << 6U) | ((((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                 & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_last)) 
                                << 5U) | (((IData)(vlTOPp->SimTop__DOT__cli_w_valid) 
                                           << 4U) | 
                                          (((IData)(vlTOPp->SimTop__DOT__Clint__DOT__aw_hs) 
                                            << 3U) 
                                           | (((IData)(vlTOPp->SimTop__DOT__Clint__DOT__w_state) 
                                               << 1U) 
                                              | (IData)(vlTOPp->reset))))));
    if (vlTOPp->__Vtablechg6[__Vtableidx6]) {
        vlTOPp->SimTop__DOT__Clint__DOT__w_state = 
            vlTOPp->__Vtable6_SimTop__DOT__Clint__DOT__w_state
            [__Vtableidx6];
    }
    if (vlTOPp->reset) {
        __Vdly__SimTop__DOT__Clint__DOT__csr_msip = 0U;
    } else if (((IData)(vlTOPp->SimTop__DOT__cli_w_valid) 
                & (0x2000000ULL == vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg))) {
        __Vdly__SimTop__DOT__Clint__DOT__csr_msip = 
            (((~ (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_mask)) 
              & vlTOPp->SimTop__DOT__Clint__DOT__csr_msip) 
             | ((IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_mask) 
                & (IData)(vlTOPp->SimTop__DOT__cli_w_data)));
    }
    vlTOPp->SimTop__DOT__Clint__DOT__csr_mtime = ((IData)(vlTOPp->reset)
                                                   ? 0ULL
                                                   : 
                                                  (((IData)(vlTOPp->SimTop__DOT__cli_w_valid) 
                                                    & (0x200bff8ULL 
                                                       == vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg))
                                                    ? 
                                                   (((~ vlTOPp->SimTop__DOT__Clint__DOT__wr_mask) 
                                                     & vlTOPp->SimTop__DOT__Clint__DOT__csr_mtime) 
                                                    | (vlTOPp->SimTop__DOT__Clint__DOT__wr_mask 
                                                       & vlTOPp->SimTop__DOT__cli_w_data))
                                                    : 
                                                   (1ULL 
                                                    + vlTOPp->SimTop__DOT__Clint__DOT__csr_mtime)));
    if (vlTOPp->reset) {
        __Vdly__SimTop__DOT__Clint__DOT__csr_mtimecmp = 0ULL;
    } else if (((IData)(vlTOPp->SimTop__DOT__cli_w_valid) 
                & (0x2004000ULL == vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg))) {
        __Vdly__SimTop__DOT__Clint__DOT__csr_mtimecmp 
            = (((~ vlTOPp->SimTop__DOT__Clint__DOT__wr_mask) 
                & vlTOPp->SimTop__DOT__Clint__DOT__csr_mtimecmp) 
               | (vlTOPp->SimTop__DOT__Clint__DOT__wr_mask 
                  & vlTOPp->SimTop__DOT__cli_w_data));
    }
    if (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_to_wb_valid) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_pc_r 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_pc_r;
    }
    if ((((IData)(vlTOPp->reset) | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena) 
                                    & (0U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)))) 
         | ((~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena)) 
            & (0U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))))) {
        __Vdly__SimTop__DOT__mem_axi_rw__DOT__len = 0U;
    } else if (vlTOPp->SimTop__DOT__mem_axi_rw__DOT__len_incr_en) {
        __Vdly__SimTop__DOT__mem_axi_rw__DOT__len = 
            (0xffU & ((IData)(1U) + (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__len)));
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_valid = 0U;
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_allowin) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_valid 
            = (2U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state));
    } else if ((2U & vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U])) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_valid = 0U;
    }
    if (vlTOPp->reset) {
        __Vdly__SimTop__DOT__if_r_data = 0ULL;
    } else if (vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_hs) {
        if ((1U & ((0U != (7U & (IData)(vlTOPp->SimTop__DOT__if_rw_addr))) 
                   & (((IData)(3U) + (7U & (IData)(vlTOPp->SimTop__DOT__if_rw_addr))) 
                      >> 3U)))) {
            __Vtemp298[0U] = 0xffffffffU;
            __Vtemp298[1U] = 0U;
            __Vtemp298[2U] = 0U;
            __Vtemp298[3U] = 0U;
            VL_SHIFTL_WWI(128,128,6, __Vtemp299, __Vtemp298, 
                          (0x38U & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                    << 3U)));
            __Vdly__SimTop__DOT__if_r_data = ((1U & (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__len))
                                               ? (vlTOPp->SimTop__DOT__if_r_data 
                                                  | ((vlTOPp->SimTop__DOT__if_axi_r_data 
                                                      & (((QData)((IData)(
                                                                          __Vtemp299[3U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           __Vtemp299[2U])))) 
                                                     << 
                                                     (0x3fU 
                                                      & (- 
                                                         (0x38U 
                                                          & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                                             << 3U))))))
                                               : vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_r_data_l);
        } else if ((0U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__len))) {
            __Vdly__SimTop__DOT__if_r_data = vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_r_data_l;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__if_axi_w_strb = 0U;
    } else if (vlTOPp->SimTop__DOT__if_axi_rw__DOT__aw_hs) {
        vlTOPp->SimTop__DOT__if_axi_w_strb = (0xffU 
                                              & ((IData)(0xfU) 
                                                 << 
                                                 (7U 
                                                  & (IData)(vlTOPp->SimTop__DOT__if_rw_addr))));
    }
    __Vtableidx3 = (((IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__ar_hs) 
                     << 6U) | (((IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_done) 
                                << 5U) | (((IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state) 
                                           << 2U) | 
                                          (((1U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state)) 
                                            << 1U) 
                                           | (IData)(vlTOPp->reset)))));
    if (vlTOPp->__Vtablechg3[__Vtableidx3]) {
        vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state 
            = vlTOPp->__Vtable3_SimTop__DOT__if_axi_rw__DOT__r_state
            [__Vtableidx3];
    }
    __Vtableidx2 = (((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__ar_hs) 
                     << 6U) | (((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_done) 
                                << 5U) | (((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state) 
                                           << 2U) | 
                                          ((((1U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state)) 
                                             & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena))) 
                                            << 1U) 
                                           | (IData)(vlTOPp->reset)))));
    if (vlTOPp->__Vtablechg2[__Vtableidx2]) {
        vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state 
            = vlTOPp->__Vtable2_SimTop__DOT__mem_axi_rw__DOT__r_state
            [__Vtableidx2];
    }
    __Vtableidx1 = (((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__aw_hs) 
                     << 7U) | (((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_done) 
                                << 6U) | (((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__b_hs) 
                                           << 5U) | 
                                          (((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state) 
                                            << 2U) 
                                           | ((((1U 
                                                 == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state)) 
                                                & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena)) 
                                               << 1U) 
                                              | (IData)(vlTOPp->reset))))));
    if (vlTOPp->__Vtablechg1[__Vtableidx1]) {
        vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state 
            = vlTOPp->__Vtable1_SimTop__DOT__mem_axi_rw__DOT__w_state
            [__Vtableidx1];
    }
    if (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_to_wb_valid) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_inst_r 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_inst_r;
    }
    if (vlTOPp->reset) {
        __Vdly__SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_pc = 0x7ffffffcULL;
    } else if (((2U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state)) 
                & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_allowin))) {
        __Vdly__SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_pc 
            = vlTOPp->SimTop__DOT__if_rw_addr;
    }
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mip 
        = ((IData)(vlTOPp->reset) ? 0x80ULL : (((QData)((IData)(
                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[9U])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[8U]))));
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mstatus = 0x1880ULL;
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__excp_wr) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mstatus 
            = (0x800000000001f888ULL & vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_wr_data_full);
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_wr_ena) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mstatus 
            = (0x800000000001f888ULL & vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_wr_data_full);
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mtvec = 0ULL;
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_wr_ena) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mtvec 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data;
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mie = 0x888ULL;
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_wr_ena) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mie 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data;
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mepc = 0ULL;
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__excp_enter_wr) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mepc 
            = (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[5U])) 
                << 0x20U) | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[4U])));
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_wr_ena) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mepc 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data;
    }
    if (vlTOPp->reset) {
        __Vdly__SimTop__DOT__mem_r_data = 0ULL;
    } else if (vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_hs) {
        if (((0U != (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
             & ((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__addr_end) 
                >> 3U))) {
            __Vdly__SimTop__DOT__mem_r_data = ((1U 
                                                & (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__len))
                                                ? (vlTOPp->SimTop__DOT__mem_r_data 
                                                   | ((vlTOPp->SimTop__DOT__mem_axi_r_data 
                                                       & (((QData)((IData)(
                                                                           vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[3U])) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(
                                                                            vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[2U])))) 
                                                      << 
                                                      (0x3fU 
                                                       & (- 
                                                          (0x38U 
                                                           & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                                                              << 3U))))))
                                                : vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_r_data_l);
        } else if ((0U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__len))) {
            __Vdly__SimTop__DOT__mem_r_data = vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_r_data_l;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__mem_axi_w_strb = 0U;
    } else if (vlTOPp->SimTop__DOT__mem_axi_rw__DOT__aw_hs) {
        vlTOPp->SimTop__DOT__mem_axi_w_strb = (0xffU 
                                               & (((((1U 
                                                      & (- (IData)(
                                                                   (0U 
                                                                    == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                                                     | (3U 
                                                        & (- (IData)(
                                                                     (1U 
                                                                      == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))) 
                                                    | (0xfU 
                                                       & (- (IData)(
                                                                    (2U 
                                                                     == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))) 
                                                   | (- (IData)(
                                                                (3U 
                                                                 == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                                                  << 
                                                  (7U 
                                                   & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))));
    }
    if (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_to_wb_valid) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0U] 
            = ((0xfffffc00U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data) 
                               << 0xaU)) | ((0x3fcU 
                                             & ((((((1U 
                                                     & (- (IData)(
                                                                  (0U 
                                                                   == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                                                    | (3U 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))) 
                                                   | (0xfU 
                                                      & (- (IData)(
                                                                   (2U 
                                                                    == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))) 
                                                  | (- (IData)(
                                                               (3U 
                                                                == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                                                 << 
                                                 (7U 
                                                  & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                                << 2U)) 
                                            | (((IData)(
                                                        (0U 
                                                         != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info))) 
                                                << 1U) 
                                               | (0U 
                                                  != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info)))));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[1U] 
            = ((0x3ffU & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data) 
                          >> 0x16U)) | (0xfffffc00U 
                                        & ((IData)(
                                                   (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data 
                                                    >> 0x20U)) 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[2U] 
            = ((0x3ffU & ((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data 
                                   >> 0x20U)) >> 0x16U)) 
               | (0xfffffc00U & ((IData)((0xfffffffffffffff8ULL 
                                          & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)) 
                                 << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[3U] 
            = ((0x3ffU & ((IData)((0xfffffffffffffff8ULL 
                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)) 
                          >> 0x16U)) | (0xfffffc00U 
                                        & ((IData)(
                                                   ((0xfffffffffffffff8ULL 
                                                     & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                                                    >> 0x20U)) 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[4U] 
            = ((0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0U] 
                               << 0xaU)) | (0x3ffU 
                                            & ((IData)(
                                                       ((0xfffffffffffffff8ULL 
                                                         & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                                                        >> 0x20U)) 
                                               >> 0x16U)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[5U] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0U] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[1U] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[6U] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[1U] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[2U] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[7U] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[2U] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[3U] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[8U] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[3U] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[4U] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[9U] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[4U] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[5U] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xaU] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[5U] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[6U] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xbU] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[6U] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[7U] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xcU] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[7U] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[8U] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xdU] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[8U] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[9U] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xeU] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[9U] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xaU] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xfU] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xaU] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xbU] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x10U] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xbU] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xcU] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x11U] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xcU] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xdU] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x12U] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xdU] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xeU] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x13U] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xeU] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xfU] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x14U] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xfU] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x10U] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x15U] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x10U] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x11U] 
                                           << 0xaU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x16U] 
            = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x11U] 
                          >> 0x16U)) | (0xfffffc00U 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x12U] 
                                           << 0xaU)));
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid = 0U;
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__ex_allowin) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__id_to_ex_valid;
    }
    if (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__id_to_ex_valid) 
         & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_allowin))) {
        __Vtemp304[0U] = ((0xfffff800U & ((IData)((
                                                   (((- (QData)((IData)(
                                                                        (0x63U 
                                                                         == 
                                                                         (0x7fU 
                                                                          & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                     & ((0xffffffffffffe000ULL 
                                                         & ((- (QData)((IData)(
                                                                               (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immB) 
                                                                                >> 0xcU))))) 
                                                            << 0xdU)) 
                                                        | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immB)))) 
                                                    | ((- (QData)((IData)(
                                                                          (0x6fU 
                                                                           == 
                                                                           (0x7fU 
                                                                            & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                       & ((0xffffffffffe00000ULL 
                                                           & ((- (QData)((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immJ 
                                                                                >> 0x14U))))) 
                                                              << 0x15U)) 
                                                          | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immJ))))) 
                                                   | ((- (QData)((IData)(
                                                                         (0x67U 
                                                                          == 
                                                                          (0x7fU 
                                                                           & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                      & ((0xfffffffffffff000ULL 
                                                          & ((- (QData)((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                                >> 0x1fU))))) 
                                                             << 0xcU)) 
                                                         | (QData)((IData)(
                                                                           (0xfffU 
                                                                            & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                               >> 0x14U)))))))) 
                                          << 0xbU)) 
                          | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lwu) 
                              << 0xaU) | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lhu) 
                                           << 9U) | 
                                          (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lbu) 
                                            << 8U) 
                                           | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ld) 
                                               << 7U) 
                                              | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lw) 
                                                  << 6U) 
                                                 | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lh) 
                                                     << 5U) 
                                                    | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lb) 
                                                        << 4U) 
                                                       | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sd) 
                                                           << 3U) 
                                                          | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sw) 
                                                              << 2U) 
                                                             | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sh) 
                                                                 << 1U) 
                                                                | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sb))))))))))));
        __Vtemp304[1U] = ((0x7ffU & ((IData)(((((- (QData)((IData)(
                                                                   (0x63U 
                                                                    == 
                                                                    (0x7fU 
                                                                     & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                & ((0xffffffffffffe000ULL 
                                                    & ((- (QData)((IData)(
                                                                          (1U 
                                                                           & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immB) 
                                                                              >> 0xcU))))) 
                                                       << 0xdU)) 
                                                   | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immB)))) 
                                               | ((- (QData)((IData)(
                                                                     (0x6fU 
                                                                      == 
                                                                      (0x7fU 
                                                                       & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                  & ((0xffffffffffe00000ULL 
                                                      & ((- (QData)((IData)(
                                                                            (1U 
                                                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immJ 
                                                                                >> 0x14U))))) 
                                                         << 0x15U)) 
                                                     | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immJ))))) 
                                              | ((- (QData)((IData)(
                                                                    (0x67U 
                                                                     == 
                                                                     (0x7fU 
                                                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                 & ((0xfffffffffffff000ULL 
                                                     & ((- (QData)((IData)(
                                                                           (1U 
                                                                            & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                               >> 0x1fU))))) 
                                                        << 0xcU)) 
                                                    | (QData)((IData)(
                                                                      (0xfffU 
                                                                       & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                          >> 0x14U)))))))) 
                                     >> 0x15U)) | (0xfffff800U 
                                                   & ((IData)(
                                                              (((((- (QData)((IData)(
                                                                                (0x63U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                                  & ((0xffffffffffffe000ULL 
                                                                      & ((- (QData)((IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immB) 
                                                                                >> 0xcU))))) 
                                                                         << 0xdU)) 
                                                                     | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immB)))) 
                                                                 | ((- (QData)((IData)(
                                                                                (0x6fU 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                                    & ((0xffffffffffe00000ULL 
                                                                        & ((- (QData)((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immJ 
                                                                                >> 0x14U))))) 
                                                                           << 0x15U)) 
                                                                       | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immJ))))) 
                                                                | ((- (QData)((IData)(
                                                                                (0x67U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                                   & ((0xfffffffffffff000ULL 
                                                                       & ((- (QData)((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                                >> 0x1fU))))) 
                                                                          << 0xcU)) 
                                                                      | (QData)((IData)(
                                                                                (0xfffU 
                                                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                                >> 0x14U))))))) 
                                                               >> 0x20U)) 
                                                      << 0xbU)));
        __Vtemp304[2U] = (0x7ffU & ((IData)((((((- (QData)((IData)(
                                                                   (0x63U 
                                                                    == 
                                                                    (0x7fU 
                                                                     & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                & ((0xffffffffffffe000ULL 
                                                    & ((- (QData)((IData)(
                                                                          (1U 
                                                                           & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immB) 
                                                                              >> 0xcU))))) 
                                                       << 0xdU)) 
                                                   | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immB)))) 
                                               | ((- (QData)((IData)(
                                                                     (0x6fU 
                                                                      == 
                                                                      (0x7fU 
                                                                       & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                  & ((0xffffffffffe00000ULL 
                                                      & ((- (QData)((IData)(
                                                                            (1U 
                                                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immJ 
                                                                                >> 0x14U))))) 
                                                         << 0x15U)) 
                                                     | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immJ))))) 
                                              | ((- (QData)((IData)(
                                                                    (0x67U 
                                                                     == 
                                                                     (0x7fU 
                                                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                 & ((0xfffffffffffff000ULL 
                                                     & ((- (QData)((IData)(
                                                                           (1U 
                                                                            & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                               >> 0x1fU))))) 
                                                        << 0xcU)) 
                                                    | (QData)((IData)(
                                                                      (0xfffU 
                                                                       & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                          >> 0x14U))))))) 
                                             >> 0x20U)) 
                                    >> 0x15U));
        __Vtemp310[3U] = ((0xfffffff8U & ((((((((((3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                                  | (0xfU 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                 | (0x13U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                | (0x1bU 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                               | (0x23U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                              | (0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                             | (0x3bU 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                            | (0x63U 
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                           | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg)) 
                                          << 3U)) | 
                          ((0xfffffffcU & ((((0x33U 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                             | (0x3bU 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                            | (0x63U 
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                           << 2U)) 
                           | (3U & ((2U & (((0x3bU 
                                             == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                            | (0x1bU 
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                           << 1U)) 
                                    | ((3U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info) 
                                              >> 0xbU)) 
                                       | ((3U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_bj_info) 
                                                 >> 0x13U)) 
                                          | (__Vtemp304[2U] 
                                             >> 0x1eU)))))));
        __Vtemp311[6U] = ((0xfU & ((IData)(((- (QData)((IData)(
                                                               (1U 
                                                                & (~ (IData)(vlTOPp->reset)))))) 
                                            & (((((- (QData)((IData)(
                                                                     (0x17U 
                                                                      == 
                                                                      (0x7fU 
                                                                       & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                  | (- (QData)((IData)(
                                                                       (0x67U 
                                                                        == 
                                                                        (0x7fU 
                                                                         & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))))) 
                                                 | (- (QData)((IData)(
                                                                      (0x6fU 
                                                                       == 
                                                                       (0x7fU 
                                                                        & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))))) 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_pc_r) 
                                               | ((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm))) 
                                                  & (QData)((IData)(
                                                                    (0x1fU 
                                                                     & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                        >> 0xfU)))))))) 
                                   >> 0x1cU)) | (0xfffffff0U 
                                                 & ((IData)(
                                                            (((- (QData)((IData)(
                                                                                (1U 
                                                                                & (~ (IData)(vlTOPp->reset)))))) 
                                                              & (((((- (QData)((IData)(
                                                                                (0x17U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                                    | (- (QData)((IData)(
                                                                                (0x67U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))))) 
                                                                   | (- (QData)((IData)(
                                                                                (0x6fU 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))))) 
                                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_pc_r) 
                                                                 | ((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm))) 
                                                                    & (QData)((IData)(
                                                                                (0x1fU 
                                                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                                >> 0xfU))))))) 
                                                             >> 0x20U)) 
                                                    << 4U)));
        __Vtemp312[7U] = ((0x1f0U & (((- (IData)(((~ (IData)(vlTOPp->reset)) 
                                                  & ((((0x33U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                                       | (0x3bU 
                                                          == 
                                                          (0x7fU 
                                                           & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                      | (0x23U 
                                                         == 
                                                         (0x7fU 
                                                          & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                     | (0x63U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))))) 
                                      << 4U) & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0x10U))) 
                          | (0xfU & ((IData)((((- (QData)((IData)(
                                                                  (1U 
                                                                   & (~ (IData)(vlTOPp->reset)))))) 
                                               & (((((- (QData)((IData)(
                                                                        (0x17U 
                                                                         == 
                                                                         (0x7fU 
                                                                          & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                     | (- (QData)((IData)(
                                                                          (0x67U 
                                                                           == 
                                                                           (0x7fU 
                                                                            & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))))) 
                                                    | (- (QData)((IData)(
                                                                         (0x6fU 
                                                                          == 
                                                                          (0x7fU 
                                                                           & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))))) 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_pc_r) 
                                                  | ((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm))) 
                                                     & (QData)((IData)(
                                                                       (0x1fU 
                                                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                           >> 0xfU))))))) 
                                              >> 0x20U)) 
                                     >> 0x1cU)));
        __Vtemp313[7U] = ((0xfffffe00U & (((0x7bU == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))
                                            ? 0xaU : 
                                           (0x1fU & 
                                            ((- (IData)(
                                                        ((~ (IData)(vlTOPp->reset)) 
                                                         & (((((((((((3U 
                                                                      == 
                                                                      (0x7fU 
                                                                       & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                                                     | (0xfU 
                                                                        == 
                                                                        (0x7fU 
                                                                         & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                                    | (0x13U 
                                                                       == 
                                                                       (0x7fU 
                                                                        & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                                   | (0x1bU 
                                                                      == 
                                                                      (0x7fU 
                                                                       & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                                  | (0x23U 
                                                                     == 
                                                                     (0x7fU 
                                                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                                 | (0x33U 
                                                                    == 
                                                                    (0x7fU 
                                                                     & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                                | (0x3bU 
                                                                   == 
                                                                   (0x7fU 
                                                                    & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                               | (0x63U 
                                                                  == 
                                                                  (0x7fU 
                                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                              | (0x67U 
                                                                 == 
                                                                 (0x7fU 
                                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                             | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg)) 
                                                            | (0x7bU 
                                                               == 
                                                               (0x7fU 
                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))))) 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0xfU)))) 
                                          << 9U)) | 
                          __Vtemp312[7U]);
        __Vtemp321[2U] = ((0xfff80000U & ((((~ (IData)(vlTOPp->reset)) 
                                            & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm) 
                                               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg))) 
                                           << 0x15U) 
                                          | ((((~ (IData)(vlTOPp->reset)) 
                                               & (3U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                              << 0x14U) 
                                             | (((~ (IData)(vlTOPp->reset)) 
                                                 & (((((((((0xfU 
                                                            == 
                                                            (0x7fU 
                                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                                           | (0x13U 
                                                              == 
                                                              (0x7fU 
                                                               & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                          | (0x17U 
                                                             == 
                                                             (0x7fU 
                                                              & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                         | (0x1bU 
                                                            == 
                                                            (0x7fU 
                                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                        | (0x33U 
                                                           == 
                                                           (0x7fU 
                                                            & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                       | (0x37U 
                                                          == 
                                                          (0x7fU 
                                                           & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                      | (0x3bU 
                                                         == 
                                                         (0x7fU 
                                                          & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                     | (0x6fU 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                    | (0x67U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))) 
                                                << 0x13U)))) 
                          | ((0xfffc0000U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__reg_wr_ena) 
                                             << 0x12U)) 
                             | ((0xffffe000U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__reg_wr_addr) 
                                                << 0xdU)) 
                                | ((0xfffff000U & (
                                                   ((~ (IData)(vlTOPp->reset)) 
                                                    & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm) 
                                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg))) 
                                                   << 0xcU)) 
                                   | (0xfffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0x14U))))));
        __Vtemp322[0U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_rd_data);
        __Vtemp322[1U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__csr_rd_data 
                                  >> 0x20U));
        __Vtemp322[2U] = ((0xffc00000U & ((0xff000000U 
                                           & (__Vtemp304[0U] 
                                              << 0x18U)) 
                                          | ((((~ (IData)(vlTOPp->reset)) 
                                               & (3U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                              << 0x17U) 
                                             | (((~ (IData)(vlTOPp->reset)) 
                                                 & (0x23U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                << 0x16U)))) 
                          | __Vtemp321[2U]);
        __Vtemp322[3U] = ((0x3fffffU & ((0x3fffffU 
                                         & (__Vtemp304[0U] 
                                            >> 8U)) 
                                        | ((0x3fffffU 
                                            & (((~ (IData)(vlTOPp->reset)) 
                                                & (3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                               >> 9U)) 
                                           | (((~ (IData)(vlTOPp->reset)) 
                                               & (0x23U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                              >> 0xaU)))) 
                          | (0xffc00000U & ((0xc00000U 
                                             & (__Vtemp304[0U] 
                                                >> 8U)) 
                                            | (0xff000000U 
                                               & (__Vtemp304[1U] 
                                                  << 0x18U)))));
        __Vtemp322[4U] = ((0x3fffffU & (__Vtemp304[1U] 
                                        >> 8U)) | (0xffc00000U 
                                                   & ((0xc00000U 
                                                       & (__Vtemp304[1U] 
                                                          >> 8U)) 
                                                      | (0xff000000U 
                                                         & (__Vtemp304[2U] 
                                                            << 0x18U)))));
        __Vtemp322[5U] = ((0x3fffffU & ((0x3ff800U 
                                         & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info) 
                                            << 0xbU)) 
                                        | ((0x3ffff8U 
                                            & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_bj_info) 
                                               << 3U)) 
                                           | (0x3fffffU 
                                              & (__Vtemp304[2U] 
                                                 >> 8U))))) 
                          | (0xffc00000U & ((0xfc000000U 
                                             & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2) 
                                                << 0x1aU)) 
                                            | (__Vtemp310[3U] 
                                               << 0x16U))));
        __Vtemp322[6U] = ((0x3fffffU & ((0x3fffffU 
                                         & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2) 
                                            >> 6U)) 
                                        | (__Vtemp310[3U] 
                                           >> 0xaU))) 
                          | (0xffc00000U & ((0x3c00000U 
                                             & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2) 
                                                >> 6U)) 
                                            | (0xfc000000U 
                                               & ((IData)(
                                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2 
                                                           >> 0x20U)) 
                                                  << 0x1aU)))));
        __Vtemp322[7U] = ((0x3fffffU & ((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2 
                                                 >> 0x20U)) 
                                        >> 6U)) | (0xffc00000U 
                                                   & ((0x3c00000U 
                                                       & ((IData)(
                                                                  (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2 
                                                                   >> 0x20U)) 
                                                          >> 6U)) 
                                                      | (0xfc000000U 
                                                         & ((IData)(
                                                                    ((- (QData)((IData)(
                                                                                (1U 
                                                                                & (~ (IData)(vlTOPp->reset)))))) 
                                                                     & (((((- (QData)((IData)(
                                                                                (0x17U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                                           | (- (QData)((IData)(
                                                                                (0x67U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))))) 
                                                                          | (- (QData)((IData)(
                                                                                (0x6fU 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))))) 
                                                                         & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_pc_r) 
                                                                        | ((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm))) 
                                                                           & (QData)((IData)(
                                                                                (0x1fU 
                                                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                                >> 0xfU)))))))) 
                                                            << 0x1aU)))));
        __Vtemp322[8U] = ((0x3fffffU & ((IData)(((- (QData)((IData)(
                                                                    (1U 
                                                                     & (~ (IData)(vlTOPp->reset)))))) 
                                                 & (((((- (QData)((IData)(
                                                                          (0x17U 
                                                                           == 
                                                                           (0x7fU 
                                                                            & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                                                       | (- (QData)((IData)(
                                                                            (0x67U 
                                                                             == 
                                                                             (0x7fU 
                                                                              & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))))) 
                                                      | (- (QData)((IData)(
                                                                           (0x6fU 
                                                                            == 
                                                                            (0x7fU 
                                                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))))) 
                                                     & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_pc_r) 
                                                    | ((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm))) 
                                                       & (QData)((IData)(
                                                                         (0x1fU 
                                                                          & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                             >> 0xfU)))))))) 
                                        >> 6U)) | (0xffc00000U 
                                                   & (__Vtemp311[6U] 
                                                      << 0x16U)));
        __Vtemp322[9U] = ((0x3fffffU & (__Vtemp311[6U] 
                                        >> 0xaU)) | 
                          (0xffc00000U & (__Vtemp313[7U] 
                                          << 0x16U)));
        __Vtemp322[0xaU] = (0x3fffffU & ((0x200000U 
                                          & ((0x7bU 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                             << 0x15U)) 
                                         | ((0x300000U 
                                             & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_mret) 
                                                << 0x14U)) 
                                            | ((0x3ffff0U 
                                                & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_excp_bus) 
                                                   << 4U)) 
                                               | (__Vtemp313[7U] 
                                                  >> 0xaU)))));
        VL_EXTEND_WW(344,342, __Vtemp323, __Vtemp322);
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[0U] 
            = __Vtemp323[0U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[1U] 
            = __Vtemp323[1U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
            = __Vtemp323[2U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[3U] 
            = __Vtemp323[3U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[4U] 
            = __Vtemp323[4U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
            = __Vtemp323[5U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[6U] 
            = __Vtemp323[6U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[7U] 
            = __Vtemp323[7U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[8U] 
            = __Vtemp323[8U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[9U] 
            = __Vtemp323[9U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[0xaU] 
            = __Vtemp323[0xaU];
    }
    if (vlTOPp->reset) {
        __Vdly__SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid = 0U;
    } else if (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid) 
                & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake))) {
        __Vdly__SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid = 0U;
    } else if (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__id_to_ex_valid) 
                & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_allowin))) {
        __Vdly__SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid 
            = (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__meie_allowin) 
                | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__mtie_allowin)) 
               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__msie_allowin));
    }
    if (vlTOPp->reset) {
        __Vdlyvset__SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs__v0 = 1U;
    } else if (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_ena) 
                & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_wdest)))) {
        __Vdlyvval__SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs__v32 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_data;
        __Vdlyvset__SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs__v32 = 1U;
        __Vdlyvdim0__SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs__v32 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_wdest;
    }
    vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_to_wb_valid));
    if (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_to_wb_valid) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[0U] 
            = (IData)((((QData)((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[2U] 
                                         & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                        << 0x35U) | (((QData)((IData)(
                                                      (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[1U] 
                                                       & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                      << 0x15U) | ((QData)((IData)(
                                                                   (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
                                                                    & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                                   >> 0xbU))));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[1U] 
            = (IData)(((((QData)((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[2U] 
                                          & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                         << 0x35U) | (((QData)((IData)(
                                                       (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[1U] 
                                                        & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                       << 0x15U) | 
                                      ((QData)((IData)(
                                                       (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
                                                        & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                       >> 0xbU))) >> 0x20U));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[2U] 
            = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_data);
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[3U] 
            = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_data 
                       >> 0x20U));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[4U] 
            = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr);
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[5U] 
            = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr 
                       >> 0x20U));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[6U] 
            = ((0x20000U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[6U] 
                             & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                            >> 0xdU)) | ((0x1fe00U 
                                          & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[6U] 
                                              & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                                             >> 0xdU)) 
                                         | ((0xffffff00U 
                                             & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ena) 
                                                << 8U)) 
                                            | ((0xfffffff8U 
                                                & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_addr) 
                                                   << 3U)) 
                                               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ctrl)))));
    }
    vlTOPp->SimTop__DOT__Clint__DOT__r_state = __Vdly__SimTop__DOT__Clint__DOT__r_state;
    vlTOPp->SimTop__DOT__Clint__DOT__csr_msip = __Vdly__SimTop__DOT__Clint__DOT__csr_msip;
    vlTOPp->SimTop__DOT__Clint__DOT__csr_mtimecmp = __Vdly__SimTop__DOT__Clint__DOT__csr_mtimecmp;
    vlTOPp->SimTop__DOT__if_axi_rw__DOT__len = __Vdly__SimTop__DOT__if_axi_rw__DOT__len;
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__len = __Vdly__SimTop__DOT__mem_axi_rw__DOT__len;
    if (__Vdlyvset__SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs__v0) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[1U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[2U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[3U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[4U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[5U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[6U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[7U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[8U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[9U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0xaU] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0xbU] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0xcU] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0xdU] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0xeU] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0xfU] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x10U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x11U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x12U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x13U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x14U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x15U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x16U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x17U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x18U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x19U] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x1aU] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x1bU] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x1cU] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x1dU] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x1eU] = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0x1fU] = 0ULL;
    }
    if (__Vdlyvset__SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs__v32) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[__Vdlyvdim0__SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs__v32] 
            = __Vdlyvval__SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs__v32;
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mstatus = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mepc = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mtval = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mtvec = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mcause = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mie = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mscratch = 0ULL;
    } else {
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mstatus 
            = (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x19U])) 
                << 0x35U) | (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x18U])) 
                              << 0x15U) | ((QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x17U])) 
                                           >> 0xbU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mepc = 
            (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x17U])) 
              << 0x35U) | (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x16U])) 
                            << 0x15U) | ((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x15U])) 
                                         >> 0xbU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mtval 
            = (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x15U])) 
                << 0x35U) | (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x14U])) 
                              << 0x15U) | ((QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x13U])) 
                                           >> 0xbU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mtvec 
            = (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x13U])) 
                << 0x35U) | (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x12U])) 
                              << 0x15U) | ((QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x11U])) 
                                           >> 0xbU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mcause 
            = (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x11U])) 
                << 0x35U) | (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x10U])) 
                              << 0x15U) | ((QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xfU])) 
                                           >> 0xbU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mie = 
            (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xdU])) 
              << 0x35U) | (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xcU])) 
                            << 0x15U) | ((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xbU])) 
                                         >> 0xbU)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mscratch 
            = (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xbU])) 
                << 0x35U) | (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xaU])) 
                              << 0x15U) | ((QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[9U])) 
                                           >> 0xbU)));
    }
    vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_ena = ((~ (IData)(vlTOPp->reset)) 
                                                  & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__buf_w_ena));
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_rw_addr = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_data = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_mask = 0U;
    } else {
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_rw_addr 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__buf_rw_addr;
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_data 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__buf_w_data;
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_mask 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__buf_w_mask;
    }
    vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_skip = (1U 
                                                 & ((~ (IData)(vlTOPp->reset)) 
                                                    & ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x19U] 
                                                        >> 0xbU) 
                                                       | (0x200ULL 
                                                          == 
                                                          (0xffffffffffffULL 
                                                           & (((QData)((IData)(
                                                                               vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[7U])) 
                                                               << 0x25U) 
                                                              | (((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[6U])) 
                                                                  << 5U) 
                                                                 | ((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[5U])) 
                                                                    >> 0x1bU))))))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_valid = (1U 
                                                  & ((~ (IData)(vlTOPp->reset)) 
                                                     & (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0U] 
                                                        & (~ (IData)(
                                                                     (0U 
                                                                      != 
                                                                      ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[9U] 
                                                                        << 0x15U) 
                                                                       | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[8U] 
                                                                          >> 0xbU))))))));
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_excp_NO = 0U;
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_itrp_NO = 0U;
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_pc = 0ULL;
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_inst = 0U;
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wdata = 0ULL;
    } else {
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_excp_NO 
            = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[8U] 
                << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[7U] 
                             >> 0xbU));
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_itrp_NO 
            = (((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[9U] 
                 << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[8U] 
                              >> 0xbU)) & (- (IData)(
                                                     (1U 
                                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0U]))));
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_pc = (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[3U])) 
                                                    << 0x3fU) 
                                                   | (((QData)((IData)(
                                                                       vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[2U])) 
                                                       << 0x1fU) 
                                                      | ((QData)((IData)(
                                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[1U])) 
                                                         >> 1U)));
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_inst = 
            ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[1U] 
              << 0x1fU) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0U] 
                           >> 1U));
        vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wdata 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_data;
    }
    vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wen = ((~ (IData)(vlTOPp->reset)) 
                                                & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_ena));
    vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wdest = ((IData)(vlTOPp->reset)
                                                   ? 0U
                                                   : (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_wdest));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_burst 
        = (1U & ((- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                 | (- (IData)((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state))))));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_next_state));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_burst 
        = (1U & ((- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                 | (- (IData)((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))))));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_data = 
        (((- (QData)((IData)((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))))) 
          & vlTOPp->SimTop__DOT__mem_axi_w_data) | 
         ((- (QData)((IData)((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))))) 
          & vlTOPp->SimTop__DOT__if_axi_w_data));
    vlTOPp->SimTop__DOT__clint_interupt_bus = ((0xff7U 
                                                & (IData)(vlTOPp->SimTop__DOT__clint_interupt_bus)) 
                                               | ((1U 
                                                   == vlTOPp->SimTop__DOT__Clint__DOT__csr_msip) 
                                                  << 3U));
    vlTOPp->SimTop__DOT__Clint__DOT__clint_val = ((
                                                   (((- (QData)((IData)(
                                                                        (0x2000000ULL 
                                                                         == vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg)))) 
                                                     & (((QData)((IData)(
                                                                         (- (IData)(
                                                                                (1U 
                                                                                & (vlTOPp->SimTop__DOT__Clint__DOT__csr_msip 
                                                                                >> 0x1fU)))))) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(vlTOPp->SimTop__DOT__Clint__DOT__csr_msip)))) 
                                                    | ((- (QData)((IData)(
                                                                          (0x2004000ULL 
                                                                           == vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg)))) 
                                                       & vlTOPp->SimTop__DOT__Clint__DOT__csr_mtimecmp)) 
                                                   | ((- (QData)((IData)(
                                                                         (0x200bff8ULL 
                                                                          == vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg)))) 
                                                      & vlTOPp->SimTop__DOT__Clint__DOT__csr_mtime)) 
                                                  >> 
                                                  (7U 
                                                   & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg)));
    vlTOPp->SimTop__DOT__clint_interupt_bus = ((0xf7fU 
                                                & (IData)(vlTOPp->SimTop__DOT__clint_interupt_bus)) 
                                               | ((vlTOPp->SimTop__DOT__Clint__DOT__csr_mtime 
                                                   >= vlTOPp->SimTop__DOT__Clint__DOT__csr_mtimecmp) 
                                                  << 7U));
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg = 0ULL;
    } else if (vlTOPp->SimTop__DOT__Clint__DOT__aw_hs) {
        vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg 
            = ((- (QData)((IData)((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state))))) 
               & vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_addr);
    } else if (vlTOPp->SimTop__DOT__cli_w_valid) {
        vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg = 0ULL;
    }
    if (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_valid) 
         & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_allowin))) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_pc_r 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r;
    }
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_id = 
        (1U & ((- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
               & (- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))))));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_size 
        = (3U & (((- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                  & (- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))))) 
                 | ((- (IData)((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                    & (- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state)))))));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_ready 
        = (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
            & (2U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))) 
           | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
              & (2U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state))));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_valid 
        = (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
            & (1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))) 
           | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
              & (1U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state))));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_id = 
        (1U & ((- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
               & (- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))))));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_size 
        = (3U & (((- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                  & (- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))))) 
                 | ((- (IData)((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                    & (- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state)))))));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_b_ready 
        = (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
            & (3U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))) 
           | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
              & (3U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state))));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_valid 
        = (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
            & (1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))) 
           | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
              & (1U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state))));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_last = 
        (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
          & (2U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))) 
         | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
            & (2U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_next_state));
    if (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_valid) 
         & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_allowin))) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_inst_r 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_inst_r;
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__if_rw_addr = 0ULL;
    } else if ((0U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state))) {
        vlTOPp->SimTop__DOT__if_rw_addr = ((2U & vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U])
                                            ? (((QData)((IData)(
                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[2U])) 
                                                << 0x3eU) 
                                               | (((QData)((IData)(
                                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[1U])) 
                                                   << 0x1eU) 
                                                  | ((QData)((IData)(
                                                                     vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U])) 
                                                     >> 2U)))
                                            : (4ULL 
                                               + vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_pc));
    }
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[0U] 
        = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mie);
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[1U] 
        = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mie 
                   >> 0x20U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[2U] 
        = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mip);
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[3U] 
        = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mip 
                   >> 0x20U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[4U] 
        = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mepc);
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[5U] 
        = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mepc 
                   >> 0x20U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U] 
        = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mtvec);
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U] 
        = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mtvec 
                   >> 0x20U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U] 
        = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mstatus);
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[9U] 
        = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mstatus 
                   >> 0x20U));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_strb = 
        (((- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
          & (IData)(vlTOPp->SimTop__DOT__mem_axi_w_strb)) 
         | ((- (IData)((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
            & (IData)(vlTOPp->SimTop__DOT__if_axi_w_strb)));
    if (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_valid) 
         & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_allowin))) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0U] 
            = ((- (IData)((0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus)))) 
               & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__excp_idx));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[1U] 
            = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))) 
               & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[2U] 
            = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_rd_data);
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[3U] 
            = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_rd_data 
                       >> 0x20U));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[4U] 
            = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_rd_data);
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[5U] 
            = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_rd_data 
                       >> 0x20U));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[6U] 
            = (IData)((((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[9U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[8U]))));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[7U] 
            = (IData)(((((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[9U])) 
                         << 0x20U) | (QData)((IData)(
                                                     vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[8U]))) 
                       >> 0x20U));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[8U] 
            = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data);
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[9U] 
            = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data 
                       >> 0x20U));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xaU] 
            = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_rd_data);
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xbU] 
            = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_rd_data 
                       >> 0x20U));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xcU] 
            = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data);
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xdU] 
            = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data 
                       >> 0x20U));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xeU] 
            = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data);
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xfU] 
            = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data 
                       >> 0x20U));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x10U] 
            = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_rd_data);
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x11U] 
            = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_rd_data 
                       >> 0x20U));
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x12U] 
            = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_diffbus_r) 
               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid));
    }
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[1U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [1U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[2U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [2U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[3U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [3U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[4U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [4U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[5U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [5U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[6U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [6U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[7U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [7U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[8U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [8U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[9U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [9U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0xaU] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0xaU];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0xbU] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0xbU];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0xcU] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0xcU];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0xdU] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0xdU];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0xeU] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0xeU];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0xfU] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0xfU];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x10U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x10U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x11U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x11U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x12U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x12U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x13U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x13U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x14U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x14U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x15U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x15U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x16U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x16U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x17U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x17U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x18U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x18U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x19U] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x19U];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x1aU] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x1aU];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x1bU] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x1bU];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x1cU] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x1cU];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x1dU] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x1dU];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x1eU] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x1eU];
    vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0x1fU] 
        = vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
        [0x1fU];
    if (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_handshake) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_data 
            = ((((((((- (QData)((IData)((1U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info))))) 
                     & ((0xffffffffffffff00ULL & ((- (QData)((IData)(
                                                                     (1U 
                                                                      & (IData)(
                                                                                (vlTOPp->SimTop__DOT__mem_r_data 
                                                                                >> 7U)))))) 
                                                  << 8U)) 
                        | (QData)((IData)((0xffU & (IData)(vlTOPp->SimTop__DOT__mem_r_data)))))) 
                    | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                                 >> 1U))))) 
                       & ((0xffffffffffff0000ULL & 
                           ((- (QData)((IData)((1U 
                                                & (IData)(
                                                          (vlTOPp->SimTop__DOT__mem_r_data 
                                                           >> 0xfU)))))) 
                            << 0x10U)) | (QData)((IData)(
                                                         (0xffffU 
                                                          & (IData)(vlTOPp->SimTop__DOT__mem_r_data))))))) 
                   | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                                >> 2U))))) 
                      & (((QData)((IData)((- (IData)(
                                                     (1U 
                                                      & (IData)(
                                                                (vlTOPp->SimTop__DOT__mem_r_data 
                                                                 >> 0x1fU))))))) 
                          << 0x20U) | (QData)((IData)(vlTOPp->SimTop__DOT__mem_r_data))))) 
                  | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                               >> 3U))))) 
                     & vlTOPp->SimTop__DOT__mem_r_data)) 
                 | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                              >> 4U))))) 
                    & (QData)((IData)((0xffU & (IData)(vlTOPp->SimTop__DOT__mem_r_data)))))) 
                | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                             >> 5U))))) 
                   & (QData)((IData)((0xffffU & (IData)(vlTOPp->SimTop__DOT__mem_r_data)))))) 
               | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                            >> 6U))))) 
                  & (QData)((IData)(vlTOPp->SimTop__DOT__mem_r_data))));
    }
    if (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_valid) 
         & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_allowin))) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[0U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[1U] 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[1U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[2U] 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[2U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[3U] 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[3U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[4U] 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[4U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[5U] 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[5U];
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[6U] 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[6U];
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid = 0U;
    } else if (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_allowin) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_valid;
    }
    vlTOPp->io_uart_out_valid = (1U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[6U] 
                                        & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid)))) 
                                       >> 0x11U));
    vlTOPp->io_uart_out_ch = (0xffU & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[6U] 
                                        & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid)))) 
                                       >> 9U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_reg_wr_ctrl 
        = (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[6U] 
                 & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid)))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_ex_data 
        = (((QData)((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[5U] 
                             & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid)))))) 
            << 0x20U) | (QData)((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[4U] 
                                         & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid)))))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_mem_rd_data 
        = (((QData)((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[3U] 
                             & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid)))))) 
            << 0x20U) | (QData)((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[2U] 
                                         & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid)))))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_ena = (1U 
                                                   & (((vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[6U] 
                                                        & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid)))) 
                                                       >> 8U) 
                                                      & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_wdest 
        = (0x1fU & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[6U] 
                     & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid)))) 
                    >> 3U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__msie_allowin 
        = (1U & (((vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U] 
                   & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[0U]) 
                  & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[2U]) 
                 >> 3U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__mtie_allowin 
        = (1U & (((vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U] 
                   >> 3U) & (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[0U] 
                             >> 7U)) & (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[2U] 
                                        >> 7U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__meie_allowin 
        = (1U & (((vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U] 
                   >> 3U) & (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[0U] 
                             >> 0xbU)) & (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[2U] 
                                          >> 0xbU)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid 
        = __Vdly__SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid;
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0U] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[1U] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [1U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[2U] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [2U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[3U] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [3U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[4U] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [4U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[5U] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [5U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[6U] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [6U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[7U] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [7U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[8U] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [8U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[9U] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [9U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0xaU] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0xaU];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0xbU] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0xbU];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0xcU] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0xcU];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0xdU] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0xdU];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0xeU] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0xeU];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0xfU] = vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0xfU];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x10U] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x10U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x11U] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x11U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x12U] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x12U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x13U] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x13U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x14U] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x14U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x15U] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x15U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x16U] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x16U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x17U] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x17U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x18U] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x18U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x19U] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x19U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x1aU] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x1aU];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x1bU] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x1bU];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x1cU] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x1cU];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x1dU] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x1dU];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x1eU] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x1eU];
    vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0x1fU] = 
        vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o
        [0x1fU];
    vlTOPp->SimTop__DOT__mem_r_data = __Vdly__SimTop__DOT__mem_r_data;
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__buf_w_ena 
            = (1U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[3U] 
                      >> 2U) & vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0U]));
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__buf_rw_addr 
            = (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[7U])) 
                << 0x35U) | (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[6U])) 
                              << 0x15U) | ((QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[5U])) 
                                           >> 0xbU)));
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__buf_w_data 
            = (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[5U])) 
                << 0x35U) | (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[4U])) 
                              << 0x15U) | ((QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[3U])) 
                                           >> 0xbU)));
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__buf_w_mask 
            = (0xffU & ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[4U] 
                         << 0x1dU) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[3U] 
                                      >> 3U)));
    }
    vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U] 
        = ((0xfffffff8U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_mem_rd_data) 
                           << 3U)) | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_reg_wr_ctrl));
    vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[1U] 
        = ((7U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_mem_rd_data) 
                  >> 0x1dU)) | (0xfffffff8U & ((IData)(
                                                       (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_mem_rd_data 
                                                        >> 0x20U)) 
                                               << 3U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[2U] 
        = ((7U & ((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_mem_rd_data 
                           >> 0x20U)) >> 0x1dU)) | 
           (0xfffffff8U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_ex_data) 
                           << 3U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[3U] 
        = ((7U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_ex_data) 
                  >> 0x1dU)) | (0xfffffff8U & ((IData)(
                                                       (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_ex_data 
                                                        >> 0x20U)) 
                                               << 3U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
        = ((0xfffffff0U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_wdest) 
                           << 4U)) | ((0xfffffff8U 
                                       & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_ena) 
                                          << 3U)) | 
                                      (7U & ((IData)(
                                                     (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_ex_data 
                                                      >> 0x20U)) 
                                             >> 0x1dU))));
    vlTOPp->io_memAXI_0_ar_valid = ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_valid));
    vlTOPp->io_memAXI_0_ar_bits_id = ((- (IData)((2U 
                                                  == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                      & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_id));
    vlTOPp->io_memAXI_0_ar_bits_size = ((- (IData)(
                                                   (2U 
                                                    == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                        & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_size));
    vlTOPp->io_memAXI_0_ar_bits_burst = ((- (IData)(
                                                    (2U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                         & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_burst));
    vlTOPp->io_memAXI_0_ar_bits_cache = (2U & ((- (IData)(
                                                          (2U 
                                                           == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                               & ((- (IData)(
                                                             (1U 
                                                              == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                                  | (- (IData)(
                                                               (2U 
                                                                == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))))));
    vlTOPp->io_memAXI_0_r_ready = ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                   & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_ready));
    vlTOPp->SimTop__DOT__cli_r_ready = ((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                        & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_ready));
    vlTOPp->SimTop__DOT__cli_ar_valid = ((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                         & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_valid));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_next_state));
    if (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__id_to_ex_valid) 
         & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_allowin))) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_pc_r;
    }
    vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_handshake 
        = ((1U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state)) 
           & (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__rw_ready));
    if (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__id_to_ex_valid) 
         & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_allowin))) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_inst_r 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r;
    }
    vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len = 
        ((0U == (7U & (IData)(vlTOPp->SimTop__DOT__if_rw_addr)))
          ? 0U : (1U & (((IData)(3U) + (7U & (IData)(vlTOPp->SimTop__DOT__if_rw_addr))) 
                        >> 3U)));
    if (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__id_to_ex_valid) 
         & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_allowin))) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_diffbus_r 
            = ((0x7bU == (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
               | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                  & ((0xb00U == (0xfffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U))) 
                     | (0x344U == (0xfffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                             >> 0x14U))))));
    }
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx 
        = (((3ULL & (- (QData)((IData)(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__msie_allowin) 
                                        & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))) 
            | (7ULL & (- (QData)((IData)(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__mtie_allowin) 
                                          & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))))))) 
           | (0xbULL & (- (QData)((IData)(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__meie_allowin) 
                                           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_ena 
        = (1U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                  & (__Vconst72[2U] & (- (IData)(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                  & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))))))) 
                 >> 0xcU));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr 
        = (0xfffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                     & (__Vconst72[2U] & (- (IData)(
                                                    ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                     & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))))))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_exit 
        = (1U & ((__Vconst88[0xaU] & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[0xaU] 
                                      & (__Vconst72[0xaU] 
                                         & (- (IData)(
                                                      ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                       & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                 >> 0x14U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_info 
        = (0xffU & (((__Vconst88[6U] & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[6U] 
                                        & (__Vconst72[6U] 
                                           & (- (IData)(
                                                        ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                         & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                     << 0x1dU) | ((__Vconst88[5U] & 
                                   (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                    & (__Vconst72[5U] 
                                       & (- (IData)(
                                                    ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                     & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                  >> 3U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus 
        = (0xffffU & ((__Vconst88[0xaU] & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[0xaU] 
                                           & (__Vconst72[0xaU] 
                                              & (- (IData)(
                                                           ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                            & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                      >> 4U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_is_word_opt 
        = (1U & ((__Vconst88[5U] & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                    & (__Vconst72[5U] 
                                       & (- (IData)(
                                                    ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                     & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                 >> 0x17U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info 
        = (0xfffU & (((__Vconst88[6U] & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[6U] 
                                         & (__Vconst72[6U] 
                                            & (- (IData)(
                                                         ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                          & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                      << 0x15U) | ((__Vconst88[5U] 
                                    & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                       & (__Vconst72[5U] 
                                          & (- (IData)(
                                                       ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                        & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                   >> 0xbU)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr = (0x1fU 
                                                   & (((__Vconst88[0xaU] 
                                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[0xaU] 
                                                           & (__Vconst72[0xaU] 
                                                              & (- (IData)(
                                                                           ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                            & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                                       << 1U) 
                                                      | ((__Vconst88[9U] 
                                                          & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[9U] 
                                                             & (__Vconst72[9U] 
                                                                & (- (IData)(
                                                                             ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                              & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                                         >> 0x1fU)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr = (0x1fU 
                                                   & (((__Vconst88[0xaU] 
                                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[0xaU] 
                                                           & (__Vconst72[0xaU] 
                                                              & (- (IData)(
                                                                           ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                            & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                                       << 6U) 
                                                      | ((__Vconst88[9U] 
                                                          & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[9U] 
                                                             & (__Vconst72[9U] 
                                                                & (- (IData)(
                                                                             ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                              & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                                         >> 0x1aU)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info 
        = (0x7fU & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[6U] 
                     & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                    >> 0xfU));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info 
        = (0xfU & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[6U] 
                    & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                   >> 0xbU));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena 
        = (1U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
                  & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                 >> 9U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ctrl 
        = (7U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
                  & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                 >> 6U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_addr 
        = (0x1fU & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
                     & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                    >> 1U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ena 
        = (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr 
        = (((QData)((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[4U] 
                             & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
            << 0x35U) | (((QData)((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[3U] 
                                           & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                          << 0x15U) | ((QData)((IData)(
                                                       (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[2U] 
                                                        & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                       >> 0xbU)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0U] 
        = ((0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_inst_r 
                           << 1U)) | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[1U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_inst_r 
                  >> 0x1fU)) | (0xfffffffeU & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_pc_r) 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[2U] 
        = ((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_pc_r) 
                  >> 0x1fU)) | (0xfffffffeU & ((IData)(
                                                       (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_pc_r 
                                                        >> 0x20U)) 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[3U] 
        = ((0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0U] 
                           << 1U)) | (1U & ((IData)(
                                                    (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_pc_r 
                                                     >> 0x20U)) 
                                            >> 0x1fU)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[4U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[1U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[5U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[1U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[2U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[6U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[2U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[3U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[7U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[3U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[4U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[8U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[4U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[5U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[9U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[5U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[6U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xaU] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[6U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[7U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xbU] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[7U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[8U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xcU] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[8U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[9U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xdU] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[9U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xaU] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xeU] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xaU] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xbU] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xfU] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xbU] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xcU] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x10U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xcU] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xdU] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x11U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xdU] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xeU] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x12U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xeU] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xfU] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x13U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0xfU] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x10U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x14U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x10U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x11U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x15U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x11U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x12U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x16U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x12U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x13U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x17U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x13U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x14U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x18U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x14U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x15U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x19U] 
        = ((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x15U] 
                  >> 0x1fU)) | (0xfffffffeU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r[0x16U] 
                                               << 1U)));
    vlTOPp->SimTop__DOT__cli_ar_ready = ((~ (IData)(vlTOPp->SimTop__DOT__Clint__DOT__r_state)) 
                                         & (IData)(vlTOPp->SimTop__DOT__cli_ar_valid));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__excp_idx 
        = (((((((((((1ULL & (- (QData)((IData)((1U 
                                                & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                                   >> 1U)))))) 
                    | (2ULL & (- (QData)((IData)((1U 
                                                  & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                                     >> 2U))))))) 
                   | (3ULL & (- (QData)((IData)((1U 
                                                 & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                                    >> 3U))))))) 
                  | (4ULL & (- (QData)((IData)((1U 
                                                & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                                   >> 4U))))))) 
                 | (5ULL & (- (QData)((IData)((1U & 
                                               ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                                >> 5U))))))) 
                | (6ULL & (- (QData)((IData)((1U & 
                                              ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                               >> 6U))))))) 
               | (7ULL & (- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                                   >> 7U))))))) 
              | (0xbULL & (- (QData)((IData)((1U & 
                                              ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                               >> 0xbU))))))) 
             | (0xcULL & (- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                                   >> 0xcU))))))) 
            | (0xdULL & (- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                                  >> 0xdU))))))) 
           | (0xfULL & (- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                                 >> 0xfU)))))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter 
        = ((0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus)) 
           | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub 
        = (IData)((0U != (0xeU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_shift 
        = (IData)((0U != (0x380U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info))));
    vlTOPp->SimTop__DOT__mem_w_data = ((((QData)((IData)(
                                                         (0x7ffU 
                                                          & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[6U] 
                                                             & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid))))))) 
                                         << 0x35U) 
                                        | (((QData)((IData)(
                                                            (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[5U] 
                                                             & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                            << 0x15U) 
                                           | ((QData)((IData)(
                                                              (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[4U] 
                                                               & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                              >> 0xbU))) 
                                       & ((((0xffULL 
                                             & (- (QData)((IData)(
                                                                  (1U 
                                                                   & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info)))))) 
                                            | (0xffffULL 
                                               & (- (QData)((IData)(
                                                                    (1U 
                                                                     & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info) 
                                                                        >> 1U))))))) 
                                           | (0xffffffffULL 
                                              & (- (QData)((IData)(
                                                                   (1U 
                                                                    & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info) 
                                                                       >> 2U))))))) 
                                          | (- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info) 
                                                                   >> 3U)))))));
    vlTOPp->SimTop__DOT__mem_rw_size = (3U & (((1U 
                                                & (- (IData)((IData)(
                                                                     ((0U 
                                                                       != 
                                                                       (2U 
                                                                        & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info))) 
                                                                      | (0U 
                                                                         != 
                                                                         (0x22U 
                                                                          & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info)))))))) 
                                               | (2U 
                                                  & (- (IData)((IData)(
                                                                       ((0U 
                                                                         != 
                                                                         (4U 
                                                                          & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info))) 
                                                                        | (0U 
                                                                           != 
                                                                           (0x44U 
                                                                            & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info))))))))) 
                                              | (- (IData)(
                                                           (1U 
                                                            & (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info) 
                                                                >> 3U) 
                                                               | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                                                  >> 3U)))))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ready_go 
        = (1U & ((2U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state)) 
                 | ((~ (1U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
                               & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                              >> 0xaU))) & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena)))));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_addr 
        = (0xfffffffffffffff8ULL & (((- (QData)((IData)(
                                                        (1U 
                                                         == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))))) 
                                     & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                                    | ((- (QData)((IData)(
                                                          (2U 
                                                           == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))))) 
                                       & vlTOPp->SimTop__DOT__if_rw_addr)));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_addr 
        = (0xfffffffffffffff8ULL & (((- (QData)((IData)(
                                                        (1U 
                                                         == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state))))) 
                                     & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                                    | ((- (QData)((IData)(
                                                          (2U 
                                                           == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state))))) 
                                       & vlTOPp->SimTop__DOT__if_rw_addr)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U] 
        = ((0xfffffff8U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                           << 3U)) | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ctrl));
    vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[1U] 
        = ((7U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                  >> 0x1dU)) | (0xfffffff8U & ((IData)(
                                                       (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr 
                                                        >> 0x20U)) 
                                               << 3U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
        = ((0xfffffff0U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_addr) 
                           << 4U)) | ((0xfffffff8U 
                                       & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ena) 
                                          << 3U)) | 
                                      (7U & ((IData)(
                                                     (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr 
                                                      >> 0x20U)) 
                                             >> 0x1dU))));
    vlTOPp->SimTop__DOT__Clint__DOT__ar_hs = ((IData)(vlTOPp->SimTop__DOT__cli_ar_valid) 
                                              & (IData)(vlTOPp->SimTop__DOT__cli_ar_ready));
    vlTOPp->io_memAXI_0_w_bits_data[0U] = ((- (QData)((IData)(
                                                              (2U 
                                                               == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state))))) 
                                           & vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_data);
    vlTOPp->io_memAXI_0_aw_valid = ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_valid));
    vlTOPp->io_memAXI_0_aw_bits_id = ((- (IData)((2U 
                                                  == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                      & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_id));
    vlTOPp->io_memAXI_0_aw_bits_size = ((- (IData)(
                                                   (2U 
                                                    == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                        & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_size));
    vlTOPp->io_memAXI_0_aw_bits_burst = ((- (IData)(
                                                    (2U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                         & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_burst));
    vlTOPp->io_memAXI_0_aw_bits_cache = (2U & ((- (IData)(
                                                          (2U 
                                                           == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                               & ((- (IData)(
                                                             (1U 
                                                              == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                                  | (- (IData)(
                                                               (2U 
                                                                == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))))));
    vlTOPp->io_memAXI_0_w_valid = ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                   & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_last));
    vlTOPp->io_memAXI_0_w_bits_strb = ((- (IData)((2U 
                                                   == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_strb));
    vlTOPp->io_memAXI_0_w_bits_last = ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_last));
    vlTOPp->io_memAXI_0_w_bits_id = (1U & ((- (IData)(
                                                      (2U 
                                                       == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                           & (- (IData)(
                                                        (1U 
                                                         == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))))));
    vlTOPp->SimTop__DOT__cli_w_data = ((- (QData)((IData)(
                                                          (1U 
                                                           == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state))))) 
                                       & vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_data);
    vlTOPp->SimTop__DOT__Clint__DOT__mask_8bits = (
                                                   ((- (IData)(
                                                               (1U 
                                                                == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_strb)) 
                                                   & (((((1U 
                                                          & (- (IData)(
                                                                       (0U 
                                                                        == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg))))) 
                                                         | (3U 
                                                            & (- (IData)(
                                                                         (1U 
                                                                          == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg)))))) 
                                                        | (0xfU 
                                                           & (- (IData)(
                                                                        (2U 
                                                                         == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg)))))) 
                                                       | (- (IData)(
                                                                    (3U 
                                                                     == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg))))) 
                                                      << 
                                                      (7U 
                                                       & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg))));
    vlTOPp->io_memAXI_0_b_ready = ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                   & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_b_ready));
    vlTOPp->SimTop__DOT__cli_b_ready = ((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                        & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_b_ready));
    vlTOPp->SimTop__DOT__cli_aw_valid = ((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                         & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_valid));
    vlTOPp->SimTop__DOT__cli_w_valid = ((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                        & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_last));
    if (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__if_to_id_valid) 
         & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__id_allowin))) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_pc_r 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_pc;
    }
    if (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__if_to_id_valid) 
         & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__id_allowin))) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
            = vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_inst;
    }
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__excp_jmp_ena 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter) 
           | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_exit));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub 
        = (1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                 | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data 
        = ((((((- (QData)((IData)((0U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
               & (((QData)((IData)((0xffU & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                   << 0x38U) | (((QData)((IData)((0xffU 
                                                  & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                 << 0x30U) | (((QData)((IData)(
                                                               (0xffU 
                                                                & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                               << 0x28U) 
                                              | (((QData)((IData)(
                                                                  (0xffU 
                                                                   & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                                  << 0x20U) 
                                                 | (((QData)((IData)(
                                                                     (0xffU 
                                                                      & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                                     << 0x18U) 
                                                    | (((QData)((IData)(
                                                                        (0xffU 
                                                                         & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                                        << 0x10U) 
                                                       | (((QData)((IData)(
                                                                           (0xffU 
                                                                            & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                                           << 8U) 
                                                          | (QData)((IData)(
                                                                            (0xffU 
                                                                             & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))))))))))) 
              | ((- (QData)((IData)((1U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                 & (((QData)((IData)((0xffffU & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                     << 0x30U) | (((QData)((IData)(
                                                   (0xffffU 
                                                    & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                   << 0x20U) | (((QData)((IData)(
                                                                 (0xffffU 
                                                                  & (IData)(vlTOPp->SimTop__DOT__mem_w_data)))) 
                                                 << 0x10U) 
                                                | (QData)((IData)(
                                                                  (0xffffU 
                                                                   & (IData)(vlTOPp->SimTop__DOT__mem_w_data))))))))) 
             | ((- (QData)((IData)((2U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                & (((QData)((IData)(vlTOPp->SimTop__DOT__mem_w_data)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->SimTop__DOT__mem_w_data))))) 
            | ((- (QData)((IData)((3U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
               & vlTOPp->SimTop__DOT__mem_w_data)) 
           & (((((((((((((((- (QData)((IData)(((0U 
                                                == 
                                                (7U 
                                                 & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                               & (3U 
                                                  == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))) 
                           | (0xffffffffULL & (- (QData)((IData)(
                                                                 ((0U 
                                                                   == 
                                                                   (7U 
                                                                    & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                                                  & (2U 
                                                                     == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))))) 
                          | (0xffffULL & (- (QData)((IData)(
                                                            ((0U 
                                                              == 
                                                              (7U 
                                                               & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                                             & (1U 
                                                                == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))))) 
                         | (0xffULL & (- (QData)((IData)(
                                                         ((0U 
                                                           == 
                                                           (7U 
                                                            & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                                          & (0U 
                                                             == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))))) 
                        | (0xff00ULL & (- (QData)((IData)(
                                                          ((1U 
                                                            == 
                                                            (7U 
                                                             & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                                           & (0U 
                                                              == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))))) 
                       | (0xffff0000ULL & (- (QData)((IData)(
                                                             ((2U 
                                                               == 
                                                               (7U 
                                                                & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                                              & (1U 
                                                                 == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))))) 
                      | (0xff0000ULL & (- (QData)((IData)(
                                                          ((2U 
                                                            == 
                                                            (7U 
                                                             & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                                           & (0U 
                                                              == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))))) 
                     | (0xff000000ULL & (- (QData)((IData)(
                                                           ((3U 
                                                             == 
                                                             (7U 
                                                              & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                                            & (0U 
                                                               == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))))) 
                    | (0xffffffff00000000ULL & (- (QData)((IData)(
                                                                  ((4U 
                                                                    == 
                                                                    (7U 
                                                                     & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                                                   & (2U 
                                                                      == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))))) 
                   | (0xffff00000000ULL & (- (QData)((IData)(
                                                             ((4U 
                                                               == 
                                                               (7U 
                                                                & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                                              & (1U 
                                                                 == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))))) 
                  | (0xff00000000ULL & (- (QData)((IData)(
                                                          ((4U 
                                                            == 
                                                            (7U 
                                                             & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                                           & (0U 
                                                              == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))))) 
                 | (0xff0000000000ULL & (- (QData)((IData)(
                                                           ((5U 
                                                             == 
                                                             (7U 
                                                              & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                                            & (0U 
                                                               == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))))) 
                | (0xffff000000000000ULL & (- (QData)((IData)(
                                                              ((6U 
                                                                == 
                                                                (7U 
                                                                 & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                                               & (1U 
                                                                  == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))))) 
               | (0xff000000000000ULL & (- (QData)((IData)(
                                                           ((6U 
                                                             == 
                                                             (7U 
                                                              & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                                            & (0U 
                                                               == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))))) 
              | (0xff00000000000000ULL & (- (QData)((IData)(
                                                            ((7U 
                                                              == 
                                                              (7U 
                                                               & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                                             & (0U 
                                                                == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))))));
    __Vtemp533[0U] = ((((0xffU & (- (IData)((0U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                        | (0xffffU & (- (IData)((1U 
                                                 == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))) 
                       | (- (IData)((2U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                      | (- (IData)((3U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))));
    __Vtemp533[1U] = (- (IData)((3U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))));
    __Vtemp533[2U] = 0U;
    __Vtemp533[3U] = 0U;
    VL_SHIFTL_WWI(128,128,6, __Vtemp534, __Vtemp533, 
                  (0x38U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                            << 3U)));
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[0U] 
        = __Vtemp534[0U];
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[1U] 
        = __Vtemp534[1U];
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[2U] 
        = __Vtemp534[2U];
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[3U] 
        = __Vtemp534[3U];
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__addr_end 
        = (0xfU & ((7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)) 
                   + (((1U & (- (IData)((1U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                       | (3U & (- (IData)((2U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))) 
                      | (7U & (- (IData)((3U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__mem_to_wb_valid 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid) 
           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ready_go));
    vlTOPp->SimTop__DOT__u_cpu__DOT__mem_allowin = 
        (1U & ((~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)) 
               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ready_go)));
    vlTOPp->io_memAXI_0_aw_bits_addr = ((- (QData)((IData)(
                                                           (2U 
                                                            == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state))))) 
                                        & vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_addr);
    vlTOPp->io_memAXI_0_ar_bits_addr = ((- (QData)((IData)(
                                                           (2U 
                                                            == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state))))) 
                                        & vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_addr);
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__hazard 
        = ((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
               == (0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                            >> 4U))) & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                        >> 3U)) & (0U 
                                                   != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr))) 
            & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U] 
               >> 1U)) | (((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr) 
                             == (0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                          >> 4U))) 
                            & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                               >> 3U)) & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr))) 
                          & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U] 
                             >> 1U)));
    vlTOPp->SimTop__DOT__Clint__DOT__wr_mask = (((QData)((IData)(
                                                                 ((0xff000000U 
                                                                   & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__Clint__DOT__mask_8bits) 
                                                                                >> 7U)))) 
                                                                      << 0x18U)) 
                                                                  | ((0xff0000U 
                                                                      & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__Clint__DOT__mask_8bits) 
                                                                                >> 6U)))) 
                                                                         << 0x10U)) 
                                                                     | ((0xff00U 
                                                                         & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__Clint__DOT__mask_8bits) 
                                                                                >> 5U)))) 
                                                                            << 8U)) 
                                                                        | (0xffU 
                                                                           & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__Clint__DOT__mask_8bits) 
                                                                                >> 4U)))))))))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  ((0xff000000U 
                                                                    & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__Clint__DOT__mask_8bits) 
                                                                                >> 3U)))) 
                                                                       << 0x18U)) 
                                                                   | ((0xff0000U 
                                                                       & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__Clint__DOT__mask_8bits) 
                                                                                >> 2U)))) 
                                                                          << 0x10U)) 
                                                                      | ((0xff00U 
                                                                          & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__Clint__DOT__mask_8bits) 
                                                                                >> 1U)))) 
                                                                             << 8U)) 
                                                                         | (0xffU 
                                                                            & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__mask_8bits)))))))))));
    vlTOPp->SimTop__DOT__Clint__DOT__b_hs = ((2U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__w_state)) 
                                             & (IData)(vlTOPp->SimTop__DOT__cli_b_ready));
    vlTOPp->SimTop__DOT__cli_aw_ready = ((0U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__w_state)) 
                                         & (IData)(vlTOPp->SimTop__DOT__cli_aw_valid));
    vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_pc 
        = __Vdly__SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_pc;
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_len = 
        ((0U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))
          ? 0U : (1U & ((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__addr_end) 
                        >> 3U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_valid 
        = (1U & ((~ (IData)((0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_info)))) 
                 | (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__hazard))));
    vlTOPp->SimTop__DOT__Clint__DOT__aw_hs = ((IData)(vlTOPp->SimTop__DOT__cli_aw_valid) 
                                              & (IData)(vlTOPp->SimTop__DOT__cli_aw_ready));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immB 
        = ((0x1000U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                       >> 0x13U)) | ((0x800U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                << 4U)) 
                                     | ((0x7e0U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0x14U)) 
                                        | (0x1eU & 
                                           (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                            >> 7U)))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immJ 
        = ((0x100000U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                         >> 0xbU)) | ((0xff000U & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r) 
                                      | ((0x800U & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 9U)) 
                                         | (0x7feU 
                                            & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                               >> 0x14U)))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lb 
        = (IData)((3U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lh 
        = (IData)((0x1003U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lw 
        = (IData)((0x2003U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ld 
        = (IData)((0x3003U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lbu 
        = (IData)((0x4003U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lhu 
        = (IData)((0x5003U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lwu 
        = (IData)((0x6003U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sb 
        = (IData)((0x23U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sh 
        = (IData)((0x1023U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sw 
        = (IData)((0x2023U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sd 
        = (IData)((0x3023U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__reg_wr_addr 
        = (0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                    >> 7U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immS 
        = ((0xfe0U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                      >> 0x14U)) | (0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                             >> 7U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_andi 
        = (IData)((0x7013U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_and 
        = (IData)((0x7033U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sub 
        = (IData)((0x40000033U == (0xfe00707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_subw 
        = (IData)((0x4000003bU == (0xfe00707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slli 
        = (IData)((0x1013U == (0xfc00707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slti 
        = (IData)((0x2013U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sltiu 
        = (IData)((0x3013U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_xori 
        = (IData)((0x4013U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srli 
        = (IData)((0x5013U == (0xfc00707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srai 
        = (IData)((0x40005013U == (0xfc00707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ori 
        = (IData)((0x6013U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slliw 
        = (IData)((0x101bU == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srliw 
        = (IData)((0x501bU == (0xfc00707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sraiw 
        = (IData)((0x4000501bU == (0xfc00707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sll 
        = (IData)((0x1033U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slt 
        = (IData)((0x2033U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sltu 
        = (IData)((0x3033U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_xor 
        = (IData)((0x4033U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srl 
        = (IData)((0x5033U == (0xfe00707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sra 
        = (IData)((0x40005033U == (0xfe00707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_or 
        = (IData)((0x6033U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sllw 
        = (IData)((0x103bU == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srlw 
        = (IData)((0x503bU == (0xfe00707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sraw 
        = (IData)((0x4000503bU == (0xfe00707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addi 
        = (IData)((0x13U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addiw 
        = (IData)((0x1bU == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_add 
        = (IData)((0x33U == (0xfe00707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addw 
        = (IData)((0x3bU == (0xfe00707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bltu 
        = (IData)((0x6063U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bgeu 
        = (IData)((0x7063U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_beq 
        = (IData)((0x63U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bne 
        = (IData)((0x1063U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_blt 
        = (IData)((0x4063U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bge 
        = (IData)((0x5063U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_excp 
        = (IData)((0x73U == (0x707fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm 
        = ((IData)((0x4073U == (0x407fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
           & (0U != (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg 
        = ((IData)((0x73U == (0x407fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
           & (0U != (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                           >> 0xcU))));
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if (((2U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state)) 
             & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_allowin))) {
            vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_inst 
                = (IData)(vlTOPp->SimTop__DOT__if_r_data);
        }
    }
    vlTOPp->io_memAXI_0_aw_bits_len = ((- (IData)((2U 
                                                   == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                       & (((- (IData)(
                                                      (1U 
                                                       == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                           & ((- (IData)(
                                                         (1U 
                                                          == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)))) 
                                              & (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_len))) 
                                          | ((- (IData)(
                                                        (2U 
                                                         == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                             & ((- (IData)(
                                                           (1U 
                                                            == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state)))) 
                                                & (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len)))));
    vlTOPp->io_memAXI_0_ar_bits_len = ((- (IData)((2U 
                                                   == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                       & (((- (IData)(
                                                      (1U 
                                                       == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                           & ((- (IData)(
                                                         (1U 
                                                          == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state)))) 
                                              & (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_len))) 
                                          | ((- (IData)(
                                                        (2U 
                                                         == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                             & ((- (IData)(
                                                           (1U 
                                                            == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state)))) 
                                                & (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len)))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info 
        = ((0xfbfU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info)) 
           | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_and) 
               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_andi)) 
              << 6U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info 
        = ((0xffdU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info)) 
           | ((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sub) 
                | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_subw)) 
               | (0x63U == (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
              << 1U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info 
        = ((0xf7fU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info)) 
           | (((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sll) 
                 | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slli)) 
                | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sllw)) 
               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slliw)) 
              << 7U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info 
        = ((0xeffU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info)) 
           | (((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srl) 
                 | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srli)) 
                | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srlw)) 
               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srliw)) 
              << 8U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info 
        = ((0xdffU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info)) 
           | (((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sra) 
                 | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srai)) 
                | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sraw)) 
               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sraiw)) 
              << 9U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info 
        = ((0xffeU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info)) 
           | ((((((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_add) 
                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addi)) 
                     | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addw)) 
                    | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addiw)) 
                   | (0x17U == (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                  | (0x37U == (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                 | (3U == (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                | (0x23U == (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
               | (0x6fU == (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
              | (0x67U == (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_bj_info 
        = ((0xfU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_bj_info)) 
           | (((0x6fU == (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
               << 7U) | (((0x67U == (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                          << 6U) | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bgeu) 
                                     << 5U) | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bltu) 
                                               << 4U)))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info 
        = ((0xff7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info)) 
           | (((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sltu) 
                 | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sltiu)) 
                | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bltu)) 
               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bgeu)) 
              << 3U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info 
        = ((0xfefU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info)) 
           | (((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_xor) 
                 | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_xori)) 
                | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_beq)) 
               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bne)) 
              << 4U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_bj_info 
        = ((0xf0U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_bj_info)) 
           | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bge) 
               << 3U) | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_blt) 
                          << 2U) | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bne) 
                                     << 1U) | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_beq)))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info 
        = ((0xffbU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info)) 
           | (((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slt) 
                 | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slti)) 
                | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_blt)) 
               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bge)) 
              << 2U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_mret 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_excp) 
           & (0x302U == (0xfffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                   >> 0x14U))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ecall 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_excp) 
           & (0U == (0xfffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                               >> 0x14U))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ebreak 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_excp) 
           & (1U == (0xfffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                               >> 0x14U))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrwi 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm) 
           & (5U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrsi 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm) 
           & (6U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrci 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm) 
           & (7U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrw 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg) 
           & (1U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrs 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg) 
           & (2U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrc 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg) 
           & (3U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__if_r_data = __Vdly__SimTop__DOT__if_r_data;
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_excp_bus 
        = ((0xf7ffU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_excp_bus)) 
           | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ecall) 
              << 0xbU));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_excp_bus 
        = ((0xfff7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_excp_bus)) 
           | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ebreak) 
              << 3U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info 
        = ((0xfdfU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info)) 
           | (((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_or) 
                 | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ori)) 
                | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrs)) 
               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrsi)) 
              << 5U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info 
        = ((0x3ffU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info)) 
           | ((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrw) 
                | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrwi)) 
               << 0xbU) | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrc) 
                            | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrci)) 
                           << 0xaU)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld 
        = ((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrw) 
               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrs)) 
              | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrc)) 
             | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrwi)) 
            | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrsi)) 
           | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrci));
    vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_next_state));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_ready_go 
        = (1U & ((((~ (IData)((0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_info)))) 
                   & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__excp_jmp_ena))) 
                  | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_valid) 
                     & (0U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state)))) 
                 & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__hazard))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__ex_allowin = (1U 
                                                   & ((~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid)) 
                                                      | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_ready_go) 
                                                         & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_allowin))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_valid 
        = (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
            | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)) 
           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_ready_go));
    vlTOPp->SimTop__DOT__u_cpu__DOT__id_allowin = (1U 
                                                   & ((~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_valid)) 
                                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_allowin)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_valid) 
           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_allowin));
    vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_allowin 
        = (1U & ((~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_valid)) 
                 | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__id_allowin)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__excp_enter_wr 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter) 
           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake));
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcycle_wr_ena 
        = (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_ena) 
            & (0xb00U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))) 
           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake));
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_wr_ena 
        = (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_ena) 
            & (0x304U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))) 
           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake));
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_wr_ena 
        = (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_ena) 
            & (0x305U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))) 
           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake));
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_wr_ena 
        = (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_ena) 
            & (0x340U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))) 
           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake));
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__excp_wr 
        = (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter) 
            | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_exit)) 
           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake));
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_wr_ena 
        = (((0x300U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr)) 
            & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_ena)) 
           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake));
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_wr_ena 
        = (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_ena) 
            & (0x341U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))) 
           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake));
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_wr_ena 
        = (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_ena) 
            & (0x342U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))) 
           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake));
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_wr_ena 
        = (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_ena) 
            & (0x343U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))) 
           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake));
}

VL_INLINE_OPT void VSimTop::_combo__TOP__3(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_combo__TOP__3\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VlWide<4>/*127:0*/ __Vtemp562;
    VlWide<4>/*127:0*/ __Vtemp563;
    VlWide<3>/*95:0*/ __Vtemp568;
    VlWide<3>/*95:0*/ __Vtemp572;
    VlWide<3>/*95:0*/ __Vtemp573;
    VlWide<3>/*95:0*/ __Vtemp576;
    VlWide<3>/*95:0*/ __Vtemp577;
    VlWide<3>/*95:0*/ __Vtemp585;
    VlWide<7>/*223:0*/ __Vtemp641;
    VlWide<7>/*223:0*/ __Vtemp643;
    VlWide<10>/*319:0*/ __Vtemp649;
    // Body
    vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_data = 
        ((- (QData)((IData)((1U & (~ (IData)(vlTOPp->reset)))))) 
         & ((((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_reg_wr_ctrl) 
                                        >> 1U))))) 
              & vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_mem_rd_data) 
             | ((- (QData)((IData)((1U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_reg_wr_ctrl))))) 
                & vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_ex_data)) 
            | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_reg_wr_ctrl) 
                                         >> 2U))))) 
               & ((((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[1U])) 
                    << 0x20U) | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[0U]))) 
                  & (((QData)((IData)((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid))))) 
                      << 0x20U) | (QData)((IData)((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid))))))))));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_data = 
        (((- (QData)((IData)((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state))))) 
          & (((((- (QData)((IData)((0U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))))) 
                & (((QData)((IData)((0xffU & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))) 
                    << 0x38U) | (((QData)((IData)((0xffU 
                                                   & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))) 
                                  << 0x30U) | (((QData)((IData)(
                                                                (0xffU 
                                                                 & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))) 
                                                << 0x28U) 
                                               | (((QData)((IData)(
                                                                   (0xffU 
                                                                    & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))) 
                                                   << 0x20U) 
                                                  | (((QData)((IData)(
                                                                      (0xffU 
                                                                       & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))) 
                                                      << 0x18U) 
                                                     | (((QData)((IData)(
                                                                         (0xffU 
                                                                          & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))) 
                                                         << 0x10U) 
                                                        | (((QData)((IData)(
                                                                            (0xffU 
                                                                             & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))) 
                                                            << 8U) 
                                                           | (QData)((IData)(
                                                                             (0xffU 
                                                                              & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))))))))))) 
               | ((- (QData)((IData)((1U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))))) 
                  & (((QData)((IData)((0xffffU & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))) 
                      << 0x30U) | (((QData)((IData)(
                                                    (0xffffU 
                                                     & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))) 
                                    << 0x20U) | (((QData)((IData)(
                                                                  (0xffffU 
                                                                   & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))) 
                                                  << 0x10U) 
                                                 | (QData)((IData)(
                                                                   (0xffffU 
                                                                    & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val))))))))) 
              | ((- (QData)((IData)((2U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))))) 
                 & (((QData)((IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val))))) 
             | ((- (QData)((IData)((3U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))))) 
                & vlTOPp->SimTop__DOT__Clint__DOT__clint_val))) 
         | ((- (QData)((IData)((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state))))) 
            & vlTOPp->io_memAXI_0_r_bits_data[0U]));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_last = 
        ((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
         | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
            & (IData)(vlTOPp->io_memAXI_0_r_bits_last)));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_valid 
        = ((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
           | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
              & (IData)(vlTOPp->io_memAXI_0_r_valid)));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_ready 
        = (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
            & (IData)(vlTOPp->SimTop__DOT__cli_ar_ready)) 
           | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
              & (IData)(vlTOPp->io_memAXI_0_ar_ready)));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_b_valid 
        = (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
            & (2U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__w_state))) 
           | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
              & (IData)(vlTOPp->io_memAXI_0_b_valid)));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_ready 
        = (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
            & (IData)(vlTOPp->SimTop__DOT__cli_w_valid)) 
           | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
              & (IData)(vlTOPp->io_memAXI_0_w_ready)));
    vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_ready 
        = (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
            & (IData)(vlTOPp->SimTop__DOT__cli_aw_ready)) 
           | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
              & (IData)(vlTOPp->io_memAXI_0_aw_ready)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__reg_wr_ena 
        = ((~ (IData)(vlTOPp->reset)) & (((((((((((
                                                   (3U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                                   | (0xfU 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                  | (0x13U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                 | (0x17U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                | (0x1bU 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                               | (0x33U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                              | (0x37U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                             | (0x3bU 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                            | (0x67U 
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                           | (0x6fU 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                          | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm)) 
                                         | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs1_forward 
        = ((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
               == (0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                            >> 4U))) & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                        >> 3U)) & (0U 
                                                   != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr))) 
            & vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U])
            ? (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U])) 
                << 0x3dU) | (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[1U])) 
                              << 0x1dU) | ((QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U])) 
                                           >> 3U)))
            : ((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
                   == (0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                >> 4U))) & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                            >> 3U)) 
                 & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr))) 
                & vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U])
                ? (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U])) 
                    << 0x3dU) | (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[3U])) 
                                  << 0x1dU) | ((QData)((IData)(
                                                               vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[2U])) 
                                               >> 3U)))
                : ((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
                       == (0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                    >> 4U))) & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                                >> 3U)) 
                     & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr))) 
                    & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U] 
                       >> 1U)) ? (((QData)((IData)(
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[2U])) 
                                   << 0x3dU) | (((QData)((IData)(
                                                                 vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[1U])) 
                                                 << 0x1dU) 
                                                | ((QData)((IData)(
                                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U])) 
                                                   >> 3U)))
                    : ((- (QData)((IData)((1U & (~ (IData)(vlTOPp->reset)))))) 
                       & ((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
                            == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_wdest)) 
                           & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr)))
                           ? vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_data
                           : vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
                          [vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr])))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs2_forward 
        = ((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr) 
               == (0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                            >> 4U))) & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                        >> 3U)) & (0U 
                                                   != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr))) 
            & vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U])
            ? (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U])) 
                << 0x3dU) | (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[1U])) 
                              << 0x1dU) | ((QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U])) 
                                           >> 3U)))
            : ((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr) 
                   == (0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                >> 4U))) & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                            >> 3U)) 
                 & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr))) 
                & vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U])
                ? (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U])) 
                    << 0x3dU) | (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[3U])) 
                                  << 0x1dU) | ((QData)((IData)(
                                                               vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[2U])) 
                                               >> 3U)))
                : ((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr) 
                       == (0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                    >> 4U))) & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                                >> 3U)) 
                     & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr))) 
                    & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U] 
                       >> 1U)) ? (((QData)((IData)(
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[2U])) 
                                   << 0x3dU) | (((QData)((IData)(
                                                                 vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[1U])) 
                                                 << 0x1dU) 
                                                | ((QData)((IData)(
                                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U])) 
                                                   >> 3U)))
                    : ((- (QData)((IData)((1U & (~ (IData)(vlTOPp->reset)))))) 
                       & ((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr) 
                            == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_wdest)) 
                           & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr)))
                           ? vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_data
                           : vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
                          [vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr])))));
    vlTOPp->SimTop__DOT__if_axi_r_data = ((- (QData)((IData)(
                                                             (2U 
                                                              == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state))))) 
                                          & vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_data);
    vlTOPp->SimTop__DOT__mem_axi_r_data = ((- (QData)((IData)(
                                                              (1U 
                                                               == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state))))) 
                                           & vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_data);
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_next_state = 0U;
        vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_next_state = 0U;
    } else {
        vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_next_state 
            = ((0U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state))
                ? ((1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))
                    ? 1U : ((1U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state))
                             ? 2U : 0U)) : ((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state))
                                             ? (((((IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_valid) 
                                                   & (2U 
                                                      == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))) 
                                                  & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_last)) 
                                                 & (1U 
                                                    == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))
                                                 ? 0U
                                                 : 1U)
                                             : ((2U 
                                                 == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state))
                                                 ? 
                                                (((((IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_valid) 
                                                    & (2U 
                                                       == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state))) 
                                                   & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_last)) 
                                                  & (2U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))
                                                  ? 0U
                                                  : 2U)
                                                 : 0U)));
        vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_next_state 
            = ((0U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state))
                ? (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_next_state)) 
                    & (1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state)))
                    ? ((0x200ULL != (0xffffffffffffULL 
                                     & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr 
                                        >> 0x10U)))
                        ? 2U : 1U) : (((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_next_state)) 
                                       & (1U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state)))
                                       ? ((0x200ULL 
                                           != (0xffffffffffffULL 
                                               & (vlTOPp->SimTop__DOT__if_rw_addr 
                                                  >> 0x10U)))
                                           ? 2U : 1U)
                                       : 0U)) : ((1U 
                                                  == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state))
                                                  ? 
                                                 (((IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_ready) 
                                                   & (1U 
                                                      == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))
                                                   ? 0U
                                                   : 1U)
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state))
                                                   ? 
                                                  (((((IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_ready) 
                                                      & (IData)(vlTOPp->io_memAXI_0_r_valid)) 
                                                     & (IData)(vlTOPp->io_memAXI_0_r_bits_last)) 
                                                    & (2U 
                                                       == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))
                                                    ? 0U
                                                    : 2U)
                                                   : 0U)));
    }
    vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_hs = ((2U 
                                                  == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state)) 
                                                 & ((2U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_valid)));
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_hs = ((2U 
                                                   == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state)) 
                                                  & ((1U 
                                                      == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                                     & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_valid)));
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__ar_hs = (
                                                   ((1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_ready)) 
                                                   & (1U 
                                                      == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state)));
    vlTOPp->SimTop__DOT__if_axi_rw__DOT__ar_hs = ((
                                                   (2U 
                                                    == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                                   & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_ready)) 
                                                  & (1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state)));
    vlTOPp->SimTop__DOT__if_axi_b_valid = ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                           & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_b_valid));
    vlTOPp->SimTop__DOT__mem_axi_b_valid = ((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                            & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_b_valid));
    vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_hs = (((2U 
                                                   == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                                  & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_ready)) 
                                                 & (2U 
                                                    == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state)));
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_hs = ((
                                                   (1U 
                                                    == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                                   & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_ready)) 
                                                  & (2U 
                                                     == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)));
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__aw_hs = (
                                                   ((1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_ready)) 
                                                   & (1U 
                                                      == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)));
    vlTOPp->SimTop__DOT__if_axi_rw__DOT__aw_hs = ((
                                                   (2U 
                                                    == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                                   & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_ready)) 
                                                  & (1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__reg_wr_addr 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__reg_wr_ena)
            ? (0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                        >> 7U)) : 0U);
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__true_op1 
        = ((0x2000000U & (__Vconst88[5U] & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                            & (__Vconst72[5U] 
                                               & (- (IData)(
                                                            ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                             & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))
            ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs1_forward
            : (((QData)((IData)((__Vconst88[9U] & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[9U] 
                                                   & (__Vconst72[9U] 
                                                      & (- (IData)(
                                                                   ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                    & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                << 0x26U) | (((QData)((IData)((__Vconst88[8U] 
                                               & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[8U] 
                                                  & (__Vconst72[8U] 
                                                     & (- (IData)(
                                                                  ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                   & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                              << 6U) | ((QData)((IData)(
                                                        (__Vconst88[7U] 
                                                         & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[7U] 
                                                            & (__Vconst72[7U] 
                                                               & (- (IData)(
                                                                            ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                             & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                        >> 0x1aU))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__true_op2 
        = ((0x1000000U & (__Vconst88[5U] & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                            & (__Vconst72[5U] 
                                               & (- (IData)(
                                                            ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                             & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))
            ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs2_forward
            : (((QData)((IData)((__Vconst88[7U] & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[7U] 
                                                   & (__Vconst72[7U] 
                                                      & (- (IData)(
                                                                   ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                    & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                << 0x26U) | (((QData)((IData)((__Vconst88[6U] 
                                               & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[6U] 
                                                  & (__Vconst72[6U] 
                                                     & (- (IData)(
                                                                  ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                   & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                              << 6U) | ((QData)((IData)(
                                                        (__Vconst88[5U] 
                                                         & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                                            & (__Vconst72[5U] 
                                                               & (- (IData)(
                                                                            ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                             & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                        >> 0x1aU))));
    __Vtemp562[0U] = 0xffffffffU;
    __Vtemp562[1U] = 0U;
    __Vtemp562[2U] = 0U;
    __Vtemp562[3U] = 0U;
    VL_SHIFTL_WWI(128,128,6, __Vtemp563, __Vtemp562, 
                  (0x38U & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                            << 3U)));
    vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_r_data_l 
        = ((vlTOPp->SimTop__DOT__if_axi_r_data & (((QData)((IData)(
                                                                   __Vtemp563[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    __Vtemp563[0U])))) 
           >> (0x38U & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                        << 3U)));
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_r_data_l 
        = ((vlTOPp->SimTop__DOT__mem_axi_r_data & (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[0U])))) 
           >> (0x38U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                        << 3U)));
    vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_done = ((IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_hs) 
                                                   & ((2U 
                                                       == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                                      & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_last)));
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_done = 
        ((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_hs) 
         & ((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
            & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_last)));
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_next_state = 0U;
        vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_next_state = 0U;
    } else {
        vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_next_state 
            = ((0U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))
                ? ((1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))
                    ? 1U : ((1U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state))
                             ? 2U : 0U)) : ((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))
                                             ? ((((IData)(vlTOPp->SimTop__DOT__mem_axi_b_valid) 
                                                  & (3U 
                                                     == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))) 
                                                 & (1U 
                                                    == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))
                                                 ? 0U
                                                 : 1U)
                                             : ((2U 
                                                 == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))
                                                 ? 
                                                ((((IData)(vlTOPp->SimTop__DOT__if_axi_b_valid) 
                                                   & (3U 
                                                      == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state))) 
                                                  & (2U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))
                                                  ? 0U
                                                  : 2U)
                                                 : 0U)));
        vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_next_state 
            = ((0U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state))
                ? (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_next_state)) 
                    & (1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)))
                    ? ((0x200ULL != (0xffffffffffffULL 
                                     & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr 
                                        >> 0x10U)))
                        ? 2U : 1U) : (((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_next_state)) 
                                       & (1U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state)))
                                       ? ((0x200ULL 
                                           != (0xffffffffffffULL 
                                               & (vlTOPp->SimTop__DOT__if_rw_addr 
                                                  >> 0x10U)))
                                           ? 2U : 1U)
                                       : 0U)) : ((1U 
                                                  == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state))
                                                  ? 
                                                 ((((IData)(vlTOPp->SimTop__DOT__cli_b_ready) 
                                                    & (2U 
                                                       == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__w_state))) 
                                                   & (1U 
                                                      == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))
                                                   ? 0U
                                                   : 1U)
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state))
                                                   ? 
                                                  ((((IData)(vlTOPp->io_memAXI_0_b_ready) 
                                                     & (IData)(vlTOPp->io_memAXI_0_b_valid)) 
                                                    & (2U 
                                                       == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))
                                                    ? 0U
                                                    : 2U)
                                                   : 0U)));
    }
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__b_hs = ((3U 
                                                   == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)) 
                                                  & (IData)(vlTOPp->SimTop__DOT__mem_axi_b_valid));
    vlTOPp->SimTop__DOT__if_axi_rw__DOT__len_incr_en 
        = (((IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__len) 
            != (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len)) 
           & ((IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_hs) 
              | (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_hs)));
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_done = 
        ((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_hs) 
         & (2U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)));
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__len_incr_en 
        = (((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__len) 
            != (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_len)) 
           & ((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_hs) 
              | (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_hs)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
        = (((QData)((IData)(((- (IData)((1U & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_is_word_opt))))) 
                             & (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__true_op1 
                                        >> 0x20U))))) 
            << 0x20U) | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__true_op1)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2 
        = (((QData)((IData)(((- (IData)((1U & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_is_word_opt))))) 
                             & (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__true_op2 
                                        >> 0x20U))))) 
            << 0x20U) | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__true_op2)));
    vlTOPp->SimTop__DOT__if_axi_rw__DOT__rw_ready_en 
        = ((IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_done) 
           | (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__rw_ready));
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__trans_done 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena)
            ? (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__b_hs)
            : (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_done));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in1 
        = ((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_shift))) 
           & ((IData)((0U != (0x300U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info))))
               ? (((QData)((IData)(((0x80000000U & 
                                     ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1) 
                                      << 0x1fU)) | 
                                    ((0x40000000U & 
                                      ((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                >> 1U)) 
                                       << 0x1eU)) | 
                                     ((0x20000000U 
                                       & ((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                   >> 2U)) 
                                          << 0x1dU)) 
                                      | ((0x10000000U 
                                          & ((IData)(
                                                     (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                      >> 3U)) 
                                             << 0x1cU)) 
                                         | ((0x8000000U 
                                             & ((IData)(
                                                        (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                         >> 4U)) 
                                                << 0x1bU)) 
                                            | ((0x4000000U 
                                                & ((IData)(
                                                           (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                            >> 5U)) 
                                                   << 0x1aU)) 
                                               | ((0x2000000U 
                                                   & ((IData)(
                                                              (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                               >> 6U)) 
                                                      << 0x19U)) 
                                                  | ((0x1000000U 
                                                      & ((IData)(
                                                                 (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                  >> 7U)) 
                                                         << 0x18U)) 
                                                     | ((0x800000U 
                                                         & ((IData)(
                                                                    (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                     >> 8U)) 
                                                            << 0x17U)) 
                                                        | ((0x400000U 
                                                            & ((IData)(
                                                                       (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                        >> 9U)) 
                                                               << 0x16U)) 
                                                           | ((0x200000U 
                                                               & ((IData)(
                                                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                           >> 0xaU)) 
                                                                  << 0x15U)) 
                                                              | ((0x100000U 
                                                                  & ((IData)(
                                                                             (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                              >> 0xbU)) 
                                                                     << 0x14U)) 
                                                                 | ((0x80000U 
                                                                     & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0xcU)) 
                                                                        << 0x13U)) 
                                                                    | ((0x40000U 
                                                                        & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0xdU)) 
                                                                           << 0x12U)) 
                                                                       | ((0x20000U 
                                                                           & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0xeU)) 
                                                                              << 0x11U)) 
                                                                          | ((0x10000U 
                                                                              & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0xfU)) 
                                                                                << 0x10U)) 
                                                                             | ((0x8000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x10U)) 
                                                                                << 0xfU)) 
                                                                                | ((0x4000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x11U)) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x12U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x13U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x14U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x15U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x16U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x17U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x18U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x19U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x1cU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))))))))) 
                   << 0x20U) | (QData)((IData)(((0x80000000U 
                                                 & ((IData)(
                                                            (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                             >> 0x20U)) 
                                                    << 0x1fU)) 
                                                | ((0x40000000U 
                                                    & ((IData)(
                                                               (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                >> 0x21U)) 
                                                       << 0x1eU)) 
                                                   | ((0x20000000U 
                                                       & ((IData)(
                                                                  (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                   >> 0x22U)) 
                                                          << 0x1dU)) 
                                                      | ((0x10000000U 
                                                          & ((IData)(
                                                                     (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                      >> 0x23U)) 
                                                             << 0x1cU)) 
                                                         | ((0x8000000U 
                                                             & ((IData)(
                                                                        (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                         >> 0x24U)) 
                                                                << 0x1bU)) 
                                                            | ((0x4000000U 
                                                                & ((IData)(
                                                                           (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                            >> 0x25U)) 
                                                                   << 0x1aU)) 
                                                               | ((0x2000000U 
                                                                   & ((IData)(
                                                                              (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                               >> 0x26U)) 
                                                                      << 0x19U)) 
                                                                  | ((0x1000000U 
                                                                      & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x27U)) 
                                                                         << 0x18U)) 
                                                                     | ((0x800000U 
                                                                         & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x28U)) 
                                                                            << 0x17U)) 
                                                                        | ((0x400000U 
                                                                            & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x29U)) 
                                                                               << 0x16U)) 
                                                                           | ((0x200000U 
                                                                               & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x2aU)) 
                                                                                << 0x15U)) 
                                                                              | ((0x100000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x2bU)) 
                                                                                << 0x14U)) 
                                                                                | ((0x80000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x2cU)) 
                                                                                << 0x13U)) 
                                                                                | ((0x40000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x2dU)) 
                                                                                << 0x12U)) 
                                                                                | ((0x20000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x2eU)) 
                                                                                << 0x11U)) 
                                                                                | ((0x10000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x2fU)) 
                                                                                << 0x10U)) 
                                                                                | ((0x8000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x30U)) 
                                                                                << 0xfU)) 
                                                                                | ((0x4000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x31U)) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x32U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x33U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x34U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x35U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x36U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x37U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x38U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x39U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x3aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x3bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x3cU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x3dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x3eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x3fU)))))))))))))))))))))))))))))))))))))
               : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res 
        = (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
           ^ vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2);
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U] 
        = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2);
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U] 
        = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2 
                   >> 0x20U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U] 
        = (1U & ((~ ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                     >> 3U)) & (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2 
                                        >> 0x3fU))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in2 
        = (0x3fU & ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_shift))) 
                    & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_is_word_opt)
                        ? (0x1fU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2))
                        : (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2))));
    vlTOPp->SimTop__DOT__mem_axi_rw__DOT__rw_ready_en 
        = ((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__trans_done) 
           | (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__rw_ready));
    __Vtemp568[0U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                      & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1));
    __Vtemp568[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                      & (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                 >> 0x20U)));
    __Vtemp568[2U] = (1U & ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                            & ((~ ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                   >> 3U)) & (IData)(
                                                     (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                      >> 0x3fU)))));
    __Vtemp572[0U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                      & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                          ? (~ vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U])
                          : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U]));
    __Vtemp572[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                      & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                          ? (~ vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U])
                          : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U]));
    __Vtemp572[2U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                      & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                          ? (~ vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U])
                          : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U]));
    VL_ADD_W(3, __Vtemp573, __Vtemp568, __Vtemp572);
    __Vtemp576[0U] = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                       ? 1U : 0U);
    __Vtemp576[1U] = 0U;
    __Vtemp576[2U] = 0U;
    VL_ADD_W(3, __Vtemp577, __Vtemp573, __Vtemp576);
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res[0U] 
        = __Vtemp577[0U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res[1U] 
        = __Vtemp577[1U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res[2U] 
        = (1U & __Vtemp577[2U]);
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask 
        = (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_is_word_opt)
             ? 0xffffffffULL : 0xffffffffffffffffULL) 
           >> (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in2));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
        = (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in1 
           << (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in2));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res 
        = (QData)((IData)((1U & ((IData)((0U != (0xcU 
                                                 & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info)))) 
                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res[2U]))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res 
        = (((QData)((IData)(((0x80000000U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res) 
                                             << 0x1fU)) 
                             | ((0x40000000U & ((IData)(
                                                        (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                         >> 1U)) 
                                                << 0x1eU)) 
                                | ((0x20000000U & ((IData)(
                                                           (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                            >> 2U)) 
                                                   << 0x1dU)) 
                                   | ((0x10000000U 
                                       & ((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                   >> 3U)) 
                                          << 0x1cU)) 
                                      | ((0x8000000U 
                                          & ((IData)(
                                                     (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                      >> 4U)) 
                                             << 0x1bU)) 
                                         | ((0x4000000U 
                                             & ((IData)(
                                                        (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                         >> 5U)) 
                                                << 0x1aU)) 
                                            | ((0x2000000U 
                                                & ((IData)(
                                                           (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                            >> 6U)) 
                                                   << 0x19U)) 
                                               | ((0x1000000U 
                                                   & ((IData)(
                                                              (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                               >> 7U)) 
                                                      << 0x18U)) 
                                                  | ((0x800000U 
                                                      & ((IData)(
                                                                 (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                  >> 8U)) 
                                                         << 0x17U)) 
                                                     | ((0x400000U 
                                                         & ((IData)(
                                                                    (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                     >> 9U)) 
                                                            << 0x16U)) 
                                                        | ((0x200000U 
                                                            & ((IData)(
                                                                       (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                        >> 0xaU)) 
                                                               << 0x15U)) 
                                                           | ((0x100000U 
                                                               & ((IData)(
                                                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                           >> 0xbU)) 
                                                                  << 0x14U)) 
                                                              | ((0x80000U 
                                                                  & ((IData)(
                                                                             (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                              >> 0xcU)) 
                                                                     << 0x13U)) 
                                                                 | ((0x40000U 
                                                                     & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0xdU)) 
                                                                        << 0x12U)) 
                                                                    | ((0x20000U 
                                                                        & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0xeU)) 
                                                                           << 0x11U)) 
                                                                       | ((0x10000U 
                                                                           & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0xfU)) 
                                                                              << 0x10U)) 
                                                                          | ((0x8000U 
                                                                              & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x10U)) 
                                                                                << 0xfU)) 
                                                                             | ((0x4000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x11U)) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x12U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x13U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x14U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x15U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x16U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x17U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x18U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x19U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x1cU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))))))))) 
            << 0x20U) | (QData)((IData)(((0x80000000U 
                                          & ((IData)(
                                                     (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                      >> 0x20U)) 
                                             << 0x1fU)) 
                                         | ((0x40000000U 
                                             & ((IData)(
                                                        (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                         >> 0x21U)) 
                                                << 0x1eU)) 
                                            | ((0x20000000U 
                                                & ((IData)(
                                                           (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                            >> 0x22U)) 
                                                   << 0x1dU)) 
                                               | ((0x10000000U 
                                                   & ((IData)(
                                                              (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                               >> 0x23U)) 
                                                      << 0x1cU)) 
                                                  | ((0x8000000U 
                                                      & ((IData)(
                                                                 (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                  >> 0x24U)) 
                                                         << 0x1bU)) 
                                                     | ((0x4000000U 
                                                         & ((IData)(
                                                                    (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                     >> 0x25U)) 
                                                            << 0x1aU)) 
                                                        | ((0x2000000U 
                                                            & ((IData)(
                                                                       (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                        >> 0x26U)) 
                                                               << 0x19U)) 
                                                           | ((0x1000000U 
                                                               & ((IData)(
                                                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                           >> 0x27U)) 
                                                                  << 0x18U)) 
                                                              | ((0x800000U 
                                                                  & ((IData)(
                                                                             (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                              >> 0x28U)) 
                                                                     << 0x17U)) 
                                                                 | ((0x400000U 
                                                                     & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x29U)) 
                                                                        << 0x16U)) 
                                                                    | ((0x200000U 
                                                                        & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x2aU)) 
                                                                           << 0x15U)) 
                                                                       | ((0x100000U 
                                                                           & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x2bU)) 
                                                                              << 0x14U)) 
                                                                          | ((0x80000U 
                                                                              & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x2cU)) 
                                                                                << 0x13U)) 
                                                                             | ((0x40000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x2dU)) 
                                                                                << 0x12U)) 
                                                                                | ((0x20000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x2eU)) 
                                                                                << 0x11U)) 
                                                                                | ((0x10000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x2fU)) 
                                                                                << 0x10U)) 
                                                                                | ((0x8000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x30U)) 
                                                                                << 0xfU)) 
                                                                                | ((0x4000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x31U)) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x32U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x33U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x34U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x35U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x36U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x37U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x38U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x39U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x3aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x3bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x3cU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x3dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x3eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (IData)(
                                                                                (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x3fU)))))))))))))))))))))))))))))))))))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_data 
        = ((0xe7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_data)) 
           | ((0x10U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res) 
                        << 4U)) | (8U & ((~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res)) 
                                         << 3U))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_data 
        = ((0x9fU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_data)) 
           | (0x40U | (0x20U & ((~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res)) 
                                << 5U))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_data 
        = ((0xf8U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_data)) 
           | ((4U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res) 
                     << 2U)) | (((IData)((0U != vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res)) 
                                 << 1U) | (1U & (~ (IData)(
                                                           (0U 
                                                            != vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res)))))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output 
        = ((- (QData)((IData)((1U & (~ (IData)(vlTOPp->reset)))))) 
           & ((((((((((((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                                  >> 7U))))) 
                        & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res) 
                       | ((- (QData)((IData)((1U & 
                                              ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                               >> 8U))))) 
                          & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res)) 
                      | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                                   >> 9U))))) 
                         & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res 
                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask) 
                            | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_is_word_opt)
                                 ? (QData)((IData)(
                                                   (- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                          >> 0x1fU)))))))
                                 : (- (QData)((IData)(
                                                      (1U 
                                                       & (IData)(
                                                                 (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                                  >> 0x3fU))))))) 
                               & (~ vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask))))) 
                     | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                                  >> 2U))))) 
                        & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res)) 
                    | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                                 >> 3U))))) 
                       & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res)) 
                   | ((- (QData)((IData)((0U != (3U 
                                                 & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info)))))) 
                      & (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res[1U])) 
                          << 0x20U) | (QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res[0U]))))) 
                  | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                               >> 4U))))) 
                     & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res)) 
                 | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                              >> 5U))))) 
                    & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                       | vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2))) 
                | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                             >> 6U))))) 
                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                      & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2))) 
               | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                            >> 0xaU))))) 
                  & ((~ vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1) 
                     & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2))) 
              | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                           >> 0xbU))))) 
                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1)));
    __Vtemp585[0U] = ((0xfffffffcU & ((IData)(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__excp_jmp_ena)
                                                ? (
                                                   ((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter))) 
                                                    & ((0xfffffffffffffffcULL 
                                                        & ((- (QData)((IData)(
                                                                              (0U 
                                                                               == 
                                                                               (3U 
                                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))))) 
                                                           & (((QData)((IData)(
                                                                               vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                                               << 0x20U) 
                                                              | (0xfffffffffffffffcULL 
                                                                 & (QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U])))))) 
                                                       | (0x3ffffffffffffffcULL 
                                                          & ((- (QData)((IData)(
                                                                                (1U 
                                                                                == 
                                                                                (3U 
                                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))))) 
                                                             & ((((- (QData)((IData)(
                                                                                (0U 
                                                                                != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus))))) 
                                                                  << 2U) 
                                                                 & (((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                                                     << 0x20U) 
                                                                    | (0xfffffffffffffffcULL 
                                                                       & (QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))))) 
                                                                | (((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))) 
                                                                    & ((((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U])) 
                                                                         << 0x3eU) 
                                                                        | (((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                                                            << 0x1eU) 
                                                                           | ((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U])) 
                                                                              >> 2U))) 
                                                                       + vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx)) 
                                                                   << 2U)))))) 
                                                   | ((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_exit))) 
                                                      & (((QData)((IData)(
                                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[5U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[4U])))))
                                                : (
                                                   (((QData)((IData)(
                                                                     (__Vconst88[5U] 
                                                                      & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                                                         & (__Vconst72[5U] 
                                                                            & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                                     << 0x3dU) 
                                                    | (((QData)((IData)(
                                                                        (__Vconst88[4U] 
                                                                         & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[4U] 
                                                                            & (__Vconst72[4U] 
                                                                               & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                                        << 0x1dU) 
                                                       | ((QData)((IData)(
                                                                          (__Vconst88[3U] 
                                                                           & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[3U] 
                                                                              & (__Vconst72[3U] 
                                                                                & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                                          >> 3U))) 
                                                   + 
                                                   ((0x40U 
                                                     & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_info))
                                                     ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs1_forward
                                                     : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r)))) 
                                      << 2U)) | (((
                                                   (((~ (IData)(vlTOPp->reset)) 
                                                     & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid)) 
                                                    & (0U 
                                                       != 
                                                       ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_info) 
                                                        & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_data)))) 
                                                   | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__excp_jmp_ena)) 
                                                  << 1U) 
                                                 | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_valid)));
    __Vtemp585[1U] = ((3U & ((IData)(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__excp_jmp_ena)
                                       ? (((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter))) 
                                           & ((0xfffffffffffffffcULL 
                                               & ((- (QData)((IData)(
                                                                     (0U 
                                                                      == 
                                                                      (3U 
                                                                       & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))))) 
                                                  & (((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                                      << 0x20U) 
                                                     | (0xfffffffffffffffcULL 
                                                        & (QData)((IData)(
                                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U])))))) 
                                              | (0x3ffffffffffffffcULL 
                                                 & ((- (QData)((IData)(
                                                                       (1U 
                                                                        == 
                                                                        (3U 
                                                                         & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))))) 
                                                    & ((((- (QData)((IData)(
                                                                            (0U 
                                                                             != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus))))) 
                                                         << 2U) 
                                                        & (((QData)((IData)(
                                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                                            << 0x20U) 
                                                           | (0xfffffffffffffffcULL 
                                                              & (QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))))) 
                                                       | (((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))) 
                                                           & ((((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U])) 
                                                                << 0x3eU) 
                                                               | (((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                                                   << 0x1eU) 
                                                                  | ((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U])) 
                                                                     >> 2U))) 
                                                              + vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx)) 
                                                          << 2U)))))) 
                                          | ((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_exit))) 
                                             & (((QData)((IData)(
                                                                 vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[5U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[4U])))))
                                       : ((((QData)((IData)(
                                                            (__Vconst88[5U] 
                                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                                                & (__Vconst72[5U] 
                                                                   & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               (__Vconst88[4U] 
                                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[4U] 
                                                                   & (__Vconst72[4U] 
                                                                      & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 (__Vconst88[3U] 
                                                                  & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[3U] 
                                                                     & (__Vconst72[3U] 
                                                                        & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                                 >> 3U))) 
                                          + ((0x40U 
                                              & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_info))
                                              ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs1_forward
                                              : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r)))) 
                             >> 0x1eU)) | (0xfffffffcU 
                                           & ((IData)(
                                                      (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__excp_jmp_ena)
                                                         ? 
                                                        (((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter))) 
                                                          & ((0xfffffffffffffffcULL 
                                                              & ((- (QData)((IData)(
                                                                                (0U 
                                                                                == 
                                                                                (3U 
                                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))))) 
                                                                 & (((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                                                     << 0x20U) 
                                                                    | (0xfffffffffffffffcULL 
                                                                       & (QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U])))))) 
                                                             | (0x3ffffffffffffffcULL 
                                                                & ((- (QData)((IData)(
                                                                                (1U 
                                                                                == 
                                                                                (3U 
                                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))))) 
                                                                   & ((((- (QData)((IData)(
                                                                                (0U 
                                                                                != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus))))) 
                                                                        << 2U) 
                                                                       & (((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                                                           << 0x20U) 
                                                                          | (0xfffffffffffffffcULL 
                                                                             & (QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))))) 
                                                                      | (((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))) 
                                                                          & ((((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U])) 
                                                                               << 0x3eU) 
                                                                              | (((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                                                                << 0x1eU) 
                                                                                | ((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U])) 
                                                                                >> 2U))) 
                                                                             + vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx)) 
                                                                         << 2U)))))) 
                                                         | ((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_exit))) 
                                                            & (((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[5U])) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[4U])))))
                                                         : 
                                                        ((((QData)((IData)(
                                                                           (__Vconst88[5U] 
                                                                            & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                                                               & (__Vconst72[5U] 
                                                                                & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                                           << 0x3dU) 
                                                          | (((QData)((IData)(
                                                                              (__Vconst88[4U] 
                                                                               & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[4U] 
                                                                                & (__Vconst72[4U] 
                                                                                & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                                              << 0x1dU) 
                                                             | ((QData)((IData)(
                                                                                (__Vconst88[3U] 
                                                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[3U] 
                                                                                & (__Vconst72[3U] 
                                                                                & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                                                >> 3U))) 
                                                         + 
                                                         ((0x40U 
                                                           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_info))
                                                           ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs1_forward
                                                           : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r))) 
                                                       >> 0x20U)) 
                                              << 2U)));
    __Vtemp585[2U] = (3U & ((IData)((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__excp_jmp_ena)
                                       ? (((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter))) 
                                           & ((0xfffffffffffffffcULL 
                                               & ((- (QData)((IData)(
                                                                     (0U 
                                                                      == 
                                                                      (3U 
                                                                       & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))))) 
                                                  & (((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                                      << 0x20U) 
                                                     | (0xfffffffffffffffcULL 
                                                        & (QData)((IData)(
                                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U])))))) 
                                              | (0x3ffffffffffffffcULL 
                                                 & ((- (QData)((IData)(
                                                                       (1U 
                                                                        == 
                                                                        (3U 
                                                                         & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))))) 
                                                    & ((((- (QData)((IData)(
                                                                            (0U 
                                                                             != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus))))) 
                                                         << 2U) 
                                                        & (((QData)((IData)(
                                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                                            << 0x20U) 
                                                           | (0xfffffffffffffffcULL 
                                                              & (QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))))) 
                                                       | (((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))) 
                                                           & ((((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U])) 
                                                                << 0x3eU) 
                                                               | (((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                                                   << 0x1eU) 
                                                                  | ((QData)((IData)(
                                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U])) 
                                                                     >> 2U))) 
                                                              + vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx)) 
                                                          << 2U)))))) 
                                          | ((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_exit))) 
                                             & (((QData)((IData)(
                                                                 vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[5U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[4U])))))
                                       : ((((QData)((IData)(
                                                            (__Vconst88[5U] 
                                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                                                & (__Vconst72[5U] 
                                                                   & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               (__Vconst88[4U] 
                                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[4U] 
                                                                   & (__Vconst72[4U] 
                                                                      & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                               << 0x1dU) 
                                              | ((QData)((IData)(
                                                                 (__Vconst88[3U] 
                                                                  & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[3U] 
                                                                     & (__Vconst72[3U] 
                                                                        & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                                 >> 3U))) 
                                          + ((0x40U 
                                              & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_info))
                                              ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs1_forward
                                              : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r))) 
                                     >> 0x20U)) >> 0x1eU));
    vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U] 
        = __Vtemp585[0U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[1U] 
        = __Vtemp585[1U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[2U] 
        = __Vtemp585[2U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data 
        = (((QData)((IData)(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_is_word_opt)
                              ? (- (IData)((1U & (IData)(
                                                         (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output 
                                                          >> 0x1fU)))))
                              : (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output 
                                         >> 0x20U))))) 
            << 0x20U) | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__if_to_id_valid 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_valid) 
           & (~ (vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U] 
                 >> 1U)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_flush 
        = (1U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U] 
                  >> 1U) & vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U]));
    vlTOPp->__Vtableidx4 = (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_allowin) 
                             << 6U) | (((2U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state)) 
                                        << 5U) | ((
                                                   (((~ (IData)(vlTOPp->reset)) 
                                                     & (1U 
                                                        == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state))) 
                                                    & (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__rw_ready)) 
                                                   << 4U) 
                                                  | (((((~ (IData)(vlTOPp->reset)) 
                                                        & (0U 
                                                           == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state))) 
                                                       & vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U]) 
                                                      << 3U) 
                                                     | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state) 
                                                         << 1U) 
                                                        | (IData)(vlTOPp->reset))))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_next_state 
        = vlTOPp->__Vtable4_SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_next_state
        [vlTOPp->__Vtableidx4];
    __Vtemp641[0U] = ((0xfffff800U & ((IData)(((((QData)((IData)(
                                                                 vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[0U]))) 
                                               & (((QData)((IData)(
                                                                   (__Vconst72[1U] 
                                                                    & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    (__Vconst72[0U] 
                                                                     & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))))))))))) 
                                      << 0xbU)) | (
                                                   (0x400U 
                                                    & ((__Vconst88[2U] 
                                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                                           & (__Vconst72[2U] 
                                                              & (- (IData)(
                                                                           ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                            & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                                       >> 0xdU)) 
                                                   | ((0x200U 
                                                       & ((__Vconst88[2U] 
                                                           & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                                              & (__Vconst72[2U] 
                                                                 & (- (IData)(
                                                                              ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                               & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                                          >> 0xdU)) 
                                                      | ((0x1c0U 
                                                          & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                                              & (__Vconst72[2U] 
                                                                 & (- (IData)(
                                                                              ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                               & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))))))) 
                                                             >> 0xdU)) 
                                                         | ((0x3eU 
                                                             & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                                                 & (__Vconst72[2U] 
                                                                    & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))))))) 
                                                                >> 0xcU)) 
                                                            | (1U 
                                                               & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                                                   & (__Vconst72[2U] 
                                                                      & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))))))) 
                                                                  >> 0x12U)))))));
    __Vtemp641[1U] = ((0x7ffU & ((IData)(((((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[1U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[0U]))) 
                                          & (((QData)((IData)(
                                                              (__Vconst72[1U] 
                                                               & (- (IData)(
                                                                            ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                             & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               (__Vconst72[0U] 
                                                                & (- (IData)(
                                                                             ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                              & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))))))))))) 
                                 >> 0x15U)) | (0xfffff800U 
                                               & ((IData)(
                                                          (((((QData)((IData)(
                                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[1U])) 
                                                              << 0x20U) 
                                                             | (QData)((IData)(
                                                                               vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[0U]))) 
                                                            & (((QData)((IData)(
                                                                                (__Vconst72[1U] 
                                                                                & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                (__Vconst72[0U] 
                                                                                & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                                           >> 0x20U)) 
                                                  << 0xbU)));
    __Vtemp643[6U] = ((0x3f8000U & (((__Vconst88[3U] 
                                      & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[3U] 
                                         & (__Vconst72[3U] 
                                            & (- (IData)(
                                                         ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                          & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                     << 0x13U) | (0x78000U 
                                                  & ((__Vconst88[2U] 
                                                      & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                                         & (__Vconst72[2U] 
                                                            & (- (IData)(
                                                                         ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                          & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                                     >> 0xdU)))) 
                      | ((0x7800U & (((__Vconst88[3U] 
                                       & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[3U] 
                                          & (__Vconst72[3U] 
                                             & (- (IData)(
                                                          ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                           & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                      << 0x13U) | (0x7f800U 
                                                   & ((__Vconst88[2U] 
                                                       & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                                          & (__Vconst72[2U] 
                                                             & (- (IData)(
                                                                          ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                           & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                                      >> 0xdU)))) 
                         | (0x7ffU & ((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs2_forward 
                                               >> 0x20U)) 
                                      >> 0x15U))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[0U] 
        = __Vtemp641[0U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[1U] 
        = __Vtemp641[1U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[2U] 
        = ((0x7ffU & ((IData)((((((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[1U])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[0U]))) 
                                & (((QData)((IData)(
                                                    (__Vconst72[1U] 
                                                     & (- (IData)(
                                                                  ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                   & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                    << 0x20U) | (QData)((IData)(
                                                                (__Vconst72[0U] 
                                                                 & (- (IData)(
                                                                              ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                               & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                               >> 0x20U)) >> 0x15U)) 
           | (0xfffff800U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data) 
                             << 0xbU)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[3U] 
        = ((0x7ffU & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data) 
                      >> 0x15U)) | (0xfffff800U & ((IData)(
                                                           (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data 
                                                            >> 0x20U)) 
                                                   << 0xbU)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[4U] 
        = ((0x7ffU & ((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data 
                               >> 0x20U)) >> 0x15U)) 
           | (0xfffff800U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs2_forward) 
                             << 0xbU)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[5U] 
        = ((0x7ffU & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs2_forward) 
                      >> 0x15U)) | (0xfffff800U & ((IData)(
                                                           (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs2_forward 
                                                            >> 0x20U)) 
                                                   << 0xbU)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[6U] 
        = ((0x40000000U & ((__Vconst88[0xaU] & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[0xaU] 
                                                & (__Vconst72[0xaU] 
                                                   & (- (IData)(
                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                 & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                           << 9U)) | ((0x3fc00000U 
                                       & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs1_forward) 
                                          << 0x16U)) 
                                      | __Vtemp643[6U]));
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_wr_data_full 
        = (((QData)((IData)(((3U == (3U & (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data 
                                                   >> 0xdU)))) 
                             | (3U == (3U & (IData)(
                                                    (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data 
                                                     >> 0xfU))))))) 
            << 0x3fU) | (0x7fffffffffffffffULL & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data));
    __Vtemp649[0U] = (IData)((((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter))) 
                               & ((0xffffffffffffff00ULL 
                                   & (((QData)((IData)(
                                                       vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[9U])) 
                                       << 0x20U) | 
                                      (0xffffffffffffff00ULL 
                                       & (QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U]))))) 
                                  | (QData)((IData)(
                                                    ((0x80U 
                                                      & (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U] 
                                                         << 4U)) 
                                                     | ((0x70U 
                                                         & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U]) 
                                                        | (7U 
                                                           & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U]))))))) 
                              | ((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_exit))) 
                                 & ((0xffffffffffffff00ULL 
                                     & (((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[9U])) 
                                         << 0x20U) 
                                        | (0xffffffffffffff00ULL 
                                           & (QData)((IData)(
                                                             vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U]))))) 
                                    | (QData)((IData)(
                                                      (0x80U 
                                                       | ((0x70U 
                                                           & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U]) 
                                                          | ((8U 
                                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U] 
                                                                 >> 4U)) 
                                                             | (7U 
                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U]))))))))));
    __Vtemp649[1U] = (IData)(((((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter))) 
                                & ((0xffffffffffffff00ULL 
                                    & (((QData)((IData)(
                                                        vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[9U])) 
                                        << 0x20U) | 
                                       (0xffffffffffffff00ULL 
                                        & (QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U]))))) 
                                   | (QData)((IData)(
                                                     ((0x80U 
                                                       & (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U] 
                                                          << 4U)) 
                                                      | ((0x70U 
                                                          & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U]) 
                                                         | (7U 
                                                            & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U]))))))) 
                               | ((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_exit))) 
                                  & ((0xffffffffffffff00ULL 
                                      & (((QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[9U])) 
                                          << 0x20U) 
                                         | (0xffffffffffffff00ULL 
                                            & (QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U]))))) 
                                     | (QData)((IData)(
                                                       (0x80U 
                                                        | ((0x70U 
                                                            & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U]) 
                                                           | ((8U 
                                                               & (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U] 
                                                                  >> 4U)) 
                                                              | (7U 
                                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U]))))))))) 
                              >> 0x20U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[0U] 
        = __Vtemp649[0U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[1U] 
        = __Vtemp649[1U];
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[2U] 
        = (IData)(((((- (QData)((IData)((0U != (0x1003U 
                                                & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus)))))) 
                     & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r) 
                    | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                                 >> 2U))))) 
                       & (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_inst_r)))) 
                   | ((- (QData)((IData)((0U != (0xa0f0U 
                                                 & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus)))))) 
                      & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[3U] 
        = (IData)((((((- (QData)((IData)((0U != (0x1003U 
                                                 & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus)))))) 
                      & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r) 
                     | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                                  >> 2U))))) 
                        & (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_inst_r)))) 
                    | ((- (QData)((IData)((0U != (0xa0f0U 
                                                  & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus)))))) 
                       & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data)) 
                   >> 0x20U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[4U] 
        = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r);
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[5U] 
        = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r 
                   >> 0x20U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[6U] 
        = (IData)((((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)) 
                    << 0x3fU) | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)
                                  ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx
                                  : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__excp_idx)));
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[7U] 
        = (IData)(((((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)) 
                     << 0x3fU) | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)
                                   ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx
                                   : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__excp_idx)) 
                   >> 0x20U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[8U] 
        = (IData)((0x80ULL & (- (QData)((IData)((1U 
                                                 & ((IData)(vlTOPp->SimTop__DOT__clint_interupt_bus) 
                                                    >> 7U)))))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[9U] 
        = (IData)(((0x80ULL & (- (QData)((IData)((1U 
                                                  & ((IData)(vlTOPp->SimTop__DOT__clint_interupt_bus) 
                                                     >> 7U)))))) 
                   >> 0x20U));
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_rd_data 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_wr_ena)
            ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data
            : vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mie);
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_rd_data 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_wr_ena)
            ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data
            : vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mtvec);
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_rd_data 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_wr_ena)
            ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data
            : vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mscratch);
    vlTOPp->SimTop__DOT__u_cpu__DOT__id_to_ex_valid 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_valid) 
           & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_flush)));
    vlTOPp->__Vtableidx5 = (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_handshake) 
                             << 6U) | ((0x20U & (vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[0U] 
                                                 >> 4U)) 
                                       | ((0x10U & 
                                           (vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[0U] 
                                            >> 6U)) 
                                          | ((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_valid) 
                                               & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_allowin)) 
                                              << 3U) 
                                             | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state) 
                                                 << 1U) 
                                                | (IData)(vlTOPp->reset))))));
    if (vlTOPp->__Vtablechg5[vlTOPp->__Vtableidx5]) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_next_state 
            = vlTOPp->__Vtable5_SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_next_state
            [vlTOPp->__Vtableidx5];
    }
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_wr_data_full 
        = (((QData)((IData)(((3U == (3U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[1U] 
                                            << 0x13U) 
                                           | (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[0U] 
                                              >> 0xdU)))) 
                             | (3U == (3U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[1U] 
                                              << 0x11U) 
                                             | (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[0U] 
                                                >> 0xfU))))))) 
            << 0x3fU) | (0x7fffffffffffffffULL & (((QData)((IData)(
                                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[0U])))));
    if (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter) {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data 
            = (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[5U])) 
                << 0x20U) | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[4U])));
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data 
            = (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[7U])) 
                << 0x20U) | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[6U])));
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data 
            = (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[3U])) 
                << 0x20U) | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[2U])));
    } else {
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data 
            = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_wr_ena)
                ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data
                : vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mepc);
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data 
            = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_wr_ena)
                ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data
                : vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mcause);
        vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data 
            = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_wr_ena)
                ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data
                : vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mtval);
    }
    vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_rd_data 
        = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__excp_wr)
            ? vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_wr_data_full
            : ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_wr_ena)
                ? vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_wr_data_full
                : vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mstatus));
    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_rd_data = 
        ((- (QData)((IData)((1U & (~ (IData)(vlTOPp->reset)))))) 
         & (((((((((((- (QData)((IData)(((0x300U == 
                                          (0xfffU & 
                                           (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                            >> 0x14U))) 
                                         & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld))))) 
                     & vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_rd_data) 
                    | (0x80000100ULL & (- (QData)((IData)(
                                                          ((0x301U 
                                                            == 
                                                            (0xfffU 
                                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                >> 0x14U))) 
                                                           & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld))))))) 
                   | ((- (QData)((IData)(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                          & (0x304U 
                                             == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U))))))) 
                      & vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_rd_data)) 
                  | ((- (QData)((IData)(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                         & (0x305U 
                                            == (0xfffU 
                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0x14U))))))) 
                     & vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_rd_data)) 
                 | ((- (QData)((IData)(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                        & (0x340U == 
                                           (0xfffU 
                                            & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                               >> 0x14U))))))) 
                    & vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_rd_data)) 
                | ((- (QData)((IData)(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                       & (0x341U == 
                                          (0xfffU & 
                                           (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                            >> 0x14U))))))) 
                   & vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data)) 
               | ((- (QData)((IData)(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                      & (0x342U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U))))))) 
                  & vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data)) 
              | ((- (QData)((IData)(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                     & (0x343U == (0xfffU 
                                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                      >> 0x14U))))))) 
                 & vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data)) 
             | ((- (QData)((IData)(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                    & (0x344U == (0xfffU 
                                                  & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                     >> 0x14U))))))) 
                & (((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[9U])) 
                    << 0x20U) | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[8U]))))) 
            | ((- (QData)((IData)(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                   & (0xb00U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U))))))) 
               & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcycle_wr_ena)
                   ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data
                   : (1ULL + vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mcycle)))));
    vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2 
        = ((- (QData)((IData)((1U & (~ (IData)(vlTOPp->reset)))))) 
           & ((((((((((((- (QData)((IData)((3U == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                        & ((0xfffffffffffff000ULL & 
                            ((- (QData)((IData)((1U 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x1fU))))) 
                             << 0xcU)) | (QData)((IData)(
                                                         (0xfffU 
                                                          & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                             >> 0x14U)))))) 
                       | ((- (QData)((IData)((0xfU 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                          & ((0xfffffffffffff000ULL 
                              & ((- (QData)((IData)(
                                                    (1U 
                                                     & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                        >> 0x1fU))))) 
                                 << 0xcU)) | (QData)((IData)(
                                                             (0xfffU 
                                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                 >> 0x14U))))))) 
                      | ((- (QData)((IData)((0x13U 
                                             == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                         & ((0xfffffffffffff000ULL 
                             & ((- (QData)((IData)(
                                                   (1U 
                                                    & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                       >> 0x1fU))))) 
                                << 0xcU)) | (QData)((IData)(
                                                            (0xfffU 
                                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                                >> 0x14U))))))) 
                     | ((- (QData)((IData)((0x17U == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                        & (((QData)((IData)((- (IData)(
                                                       (1U 
                                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                           >> 0x1fU)))))) 
                            << 0x20U) | (QData)((IData)(
                                                        (0xfffff000U 
                                                         & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))))) 
                    | ((- (QData)((IData)((0x1bU == 
                                           (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                       & ((0xfffffffffffff000ULL & 
                           ((- (QData)((IData)((1U 
                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0x1fU))))) 
                            << 0xcU)) | (QData)((IData)(
                                                        (0xfffU 
                                                         & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                            >> 0x14U))))))) 
                   | ((- (QData)((IData)((0x23U == 
                                          (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                      & ((0xfffffffffffff000ULL & (
                                                   (- (QData)((IData)(
                                                                      (1U 
                                                                       & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immS) 
                                                                          >> 0xbU))))) 
                                                   << 0xcU)) 
                         | (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immS))))) 
                  | ((- (QData)((IData)((0x37U == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))) 
                     & (((QData)((IData)((- (IData)(
                                                    (1U 
                                                     & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                        >> 0x1fU)))))) 
                         << 0x20U) | (QData)((IData)(
                                                     (0xfffff000U 
                                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))))) 
                 | (4ULL & (- (QData)((IData)((0x67U 
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))))) 
                | (4ULL & (- (QData)((IData)((0x6fU 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))))) 
               | ((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm))) 
                  & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_rd_data)) 
              | ((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg))) 
                 & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_rd_data)));
}

void VSimTop::_eval(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_eval\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
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
    if (VL_UNLIKELY((io_memAXI_0_aw_ready & 0xfeU))) {
        Verilated::overWidthError("io_memAXI_0_aw_ready");}
    if (VL_UNLIKELY((io_memAXI_0_w_ready & 0xfeU))) {
        Verilated::overWidthError("io_memAXI_0_w_ready");}
    if (VL_UNLIKELY((io_memAXI_0_b_valid & 0xfeU))) {
        Verilated::overWidthError("io_memAXI_0_b_valid");}
    if (VL_UNLIKELY((io_memAXI_0_b_bits_resp & 0xfcU))) {
        Verilated::overWidthError("io_memAXI_0_b_bits_resp");}
    if (VL_UNLIKELY((io_memAXI_0_b_bits_id & 0xf0U))) {
        Verilated::overWidthError("io_memAXI_0_b_bits_id");}
    if (VL_UNLIKELY((io_memAXI_0_b_bits_user & 0xfeU))) {
        Verilated::overWidthError("io_memAXI_0_b_bits_user");}
    if (VL_UNLIKELY((io_memAXI_0_ar_ready & 0xfeU))) {
        Verilated::overWidthError("io_memAXI_0_ar_ready");}
    if (VL_UNLIKELY((io_memAXI_0_r_valid & 0xfeU))) {
        Verilated::overWidthError("io_memAXI_0_r_valid");}
    if (VL_UNLIKELY((io_memAXI_0_r_bits_resp & 0xfcU))) {
        Verilated::overWidthError("io_memAXI_0_r_bits_resp");}
    if (VL_UNLIKELY((io_memAXI_0_r_bits_last & 0xfeU))) {
        Verilated::overWidthError("io_memAXI_0_r_bits_last");}
    if (VL_UNLIKELY((io_memAXI_0_r_bits_id & 0xf0U))) {
        Verilated::overWidthError("io_memAXI_0_r_bits_id");}
    if (VL_UNLIKELY((io_memAXI_0_r_bits_user & 0xfeU))) {
        Verilated::overWidthError("io_memAXI_0_r_bits_user");}
}
#endif  // VL_DEBUG
