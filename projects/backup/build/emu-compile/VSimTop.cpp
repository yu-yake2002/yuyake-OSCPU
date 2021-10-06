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
            VL_FATAL_MT("/home/yuyake/oscpu/projects/backup/build/SimTop.v", 9, "",
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
            VL_FATAL_MT("/home/yuyake/oscpu/projects/backup/build/SimTop.v", 9, "",
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
    VlWide<3>/*95:0*/ __Vtemp23;
    VlWide<3>/*95:0*/ __Vtemp27;
    VlWide<3>/*95:0*/ __Vtemp28;
    VlWide<3>/*95:0*/ __Vtemp31;
    VlWide<3>/*95:0*/ __Vtemp32;
    QData/*63:0*/ __Vdlyvval__SimTop__DOT__Regfile__DOT__regs__v32;
    // Body
    __Vdlyvset__SimTop__DOT__Regfile__DOT__regs__v0 = 0U;
    __Vdlyvset__SimTop__DOT__Regfile__DOT__regs__v32 = 0U;
    vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_ArchFpRegState_TOP____024unit(0U, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL);
    vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_ArchIntRegState_TOP____024unit(0U, 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [1U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [2U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [3U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [4U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [5U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [6U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [7U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [8U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [9U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0xaU], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0xbU], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0xcU], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0xdU], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0xeU], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0xfU], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x10U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x11U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x12U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x13U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x14U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x15U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x16U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x17U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x18U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x19U], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x1aU], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x1bU], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x1cU], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x1dU], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x1eU], 
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0x1fU]);
    vlSymsp->TOP____024unit.__Vdpiimwrap_ram_write_helper_TOP____024unit(
                                                                         ((vlTOPp->SimTop__DOT__mem_ex_data 
                                                                           - 0x80000000ULL) 
                                                                          >> 3U), 
                                                                         (vlTOPp->SimTop__DOT__mem_ram_wr_src 
                                                                          << 
                                                                          (0x38U 
                                                                           & ((IData)(vlTOPp->SimTop__DOT__mem_ex_data) 
                                                                              << 3U))), 
                                                                         (((QData)((IData)(
                                                                                ((0xff000000U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__byte_enable) 
                                                                                >> 7U)))) 
                                                                                << 0x18U)) 
                                                                                | ((0xff0000U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__byte_enable) 
                                                                                >> 6U)))) 
                                                                                << 0x10U)) 
                                                                                | ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__byte_enable) 
                                                                                >> 5U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__byte_enable) 
                                                                                >> 4U)))))))))) 
                                                                           << 0x20U) 
                                                                          | (QData)((IData)(
                                                                                ((0xff000000U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__byte_enable) 
                                                                                >> 3U)))) 
                                                                                << 0x18U)) 
                                                                                | ((0xff0000U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__byte_enable) 
                                                                                >> 2U)))) 
                                                                                << 0x10U)) 
                                                                                | ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlTOPp->SimTop__DOT__byte_enable) 
                                                                                >> 1U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(vlTOPp->SimTop__DOT__byte_enable))))))))))), (IData)(vlTOPp->SimTop__DOT__mem_ram_wr_ena));
    vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_TrapEvent_TOP____024unit(0U, 
                                                                             (0x6bU 
                                                                              == 
                                                                              (0x7fU 
                                                                               & vlTOPp->SimTop__DOT__wb_inst)), 
                                                                             (7U 
                                                                              & (IData)(
                                                                                vlTOPp->SimTop__DOT__regs
                                                                                [0xaU])), vlTOPp->SimTop__DOT__cmt_pc, vlTOPp->SimTop__DOT__cycleCnt, vlTOPp->SimTop__DOT__instrCnt);
    if (vlTOPp->SimTop__DOT__vaild) {
        vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_InstrCommit_TOP____024unit(0U, 0U, (IData)(vlTOPp->SimTop__DOT__vaild), vlTOPp->SimTop__DOT__cmt_pc, vlTOPp->SimTop__DOT__cmt_inst, (IData)(vlTOPp->SimTop__DOT__skip), 0U, 0U, (IData)(vlTOPp->SimTop__DOT__cmt_wen), vlTOPp->SimTop__DOT__cmt_wdest, vlTOPp->SimTop__DOT__cmt_wdata);
    }
    vlSymsp->TOP____024unit.__Vdpiimwrap_v_difftest_CSRState_TOP____024unit(0U, 0U, vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus, 0ULL, vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mepc, 0ULL, vlTOPp->SimTop__DOT__mtval_rd_data, 0ULL, vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec, 0ULL, vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mcause, 0ULL, 0ULL, vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mip, 0ULL, vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mscratch, 0ULL, 0ULL, 0ULL);
    vlTOPp->SimTop__DOT__cycleCnt = ((IData)(vlTOPp->reset)
                                      ? 0ULL : (1ULL 
                                                + vlTOPp->SimTop__DOT__cycleCnt));
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_bj_info = vlTOPp->SimTop__DOT__id_bj_info;
    }
    if (vlTOPp->SimTop__DOT__ex_valid) {
        vlTOPp->SimTop__DOT__mem_load_info = vlTOPp->SimTop__DOT__ex_load_info;
    }
    vlTOPp->SimTop__DOT__instrCnt = ((IData)(vlTOPp->reset)
                                      ? 0ULL : (vlTOPp->SimTop__DOT__instrCnt 
                                                + ((IData)(vlTOPp->SimTop__DOT__wb_valid)
                                                    ? 1ULL
                                                    : 0ULL)));
    if (vlTOPp->SimTop__DOT__ex_valid) {
        vlTOPp->SimTop__DOT__mem_ram_rd_ena = ((IData)(vlTOPp->SimTop__DOT__ex_ram_rd_ena) 
                                               & (IData)(vlTOPp->SimTop__DOT__ex_valid));
    }
    if (vlTOPp->SimTop__DOT__mem_valid) {
        vlTOPp->SimTop__DOT__wb_csr_data = vlTOPp->SimTop__DOT__mem_csr_data;
    }
    if (vlTOPp->SimTop__DOT__ex_valid) {
        vlTOPp->SimTop__DOT__mem_save_info = vlTOPp->SimTop__DOT__ex_save_info;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_now_op1 = vlTOPp->SimTop__DOT__id_op1;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_csr_wr_addr = (0xfffU 
                                               & (vlTOPp->SimTop__DOT__id_inst 
                                                  >> 0x14U));
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_jmp_imm = ((((- (QData)((IData)(
                                                                (0x63U 
                                                                 == 
                                                                 (0x7fU 
                                                                  & vlTOPp->SimTop__DOT__id_inst))))) 
                                             & ((0xffffffffffffe000ULL 
                                                 & ((- (QData)((IData)(
                                                                       (1U 
                                                                        & ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__immB) 
                                                                           >> 0xcU))))) 
                                                    << 0xdU)) 
                                                | (QData)((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__immB)))) 
                                            | ((- (QData)((IData)(
                                                                  (0x6fU 
                                                                   == 
                                                                   (0x7fU 
                                                                    & vlTOPp->SimTop__DOT__id_inst))))) 
                                               & ((0xffffffffffe00000ULL 
                                                   & ((- (QData)((IData)(
                                                                         (1U 
                                                                          & (vlTOPp->SimTop__DOT__Id_stage__DOT__immJ 
                                                                             >> 0x14U))))) 
                                                      << 0x15U)) 
                                                  | (QData)((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__immJ))))) 
                                           | ((- (QData)((IData)(
                                                                 (0x67U 
                                                                  == 
                                                                  (0x7fU 
                                                                   & vlTOPp->SimTop__DOT__id_inst))))) 
                                              & ((0xfffffffffffff000ULL 
                                                  & ((- (QData)((IData)(
                                                                        (1U 
                                                                         & (vlTOPp->SimTop__DOT__id_inst 
                                                                            >> 0x1fU))))) 
                                                     << 0xcU)) 
                                                 | (QData)((IData)(
                                                                   (0xfffU 
                                                                    & (vlTOPp->SimTop__DOT__id_inst 
                                                                       >> 0x14U)))))));
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_ram_rd_ena_r = ((~ (IData)(vlTOPp->reset)) 
                                                & (3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SimTop__DOT__id_inst)));
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_now_op2 = vlTOPp->SimTop__DOT__id_op2;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_rs1_data = vlTOPp->SimTop__DOT__r_data1;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_rs1_addr = vlTOPp->SimTop__DOT__rs1_r_addr;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_alu_info = vlTOPp->SimTop__DOT__id_alu_info;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_use_rs1 = (((((((((3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SimTop__DOT__id_inst)) 
                                                  | (0xfU 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->SimTop__DOT__id_inst))) 
                                                 | (0x13U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->SimTop__DOT__id_inst))) 
                                                | (0x1bU 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SimTop__DOT__id_inst))) 
                                               | (0x23U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                              | (0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->SimTop__DOT__id_inst))) 
                                             | (0x3bU 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->SimTop__DOT__id_inst))) 
                                            | (0x63U 
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                           | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg));
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_use_rs2 = (((0x33U 
                                             == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__id_inst)) 
                                            | (0x3bU 
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                           | (0x63U 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__id_inst)));
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_rs2_data = vlTOPp->SimTop__DOT__r_data2;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_rs2_addr = vlTOPp->SimTop__DOT__rs2_r_addr;
    }
    if (vlTOPp->SimTop__DOT__mem_valid) {
        vlTOPp->SimTop__DOT__wb_ram_data = vlTOPp->SimTop__DOT__mem_ram_data;
    }
    if (vlTOPp->SimTop__DOT__mem_valid) {
        vlTOPp->SimTop__DOT__wb_reg_wr_ctrl = ((IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ctrl) 
                                               & (- (IData)((IData)(vlTOPp->SimTop__DOT__mem_valid))));
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mie = 0x888ULL;
    } else if (((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                & (0x304U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mie 
            = vlTOPp->SimTop__DOT__wb_ex_data;
    }
    vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mcycle = 
        ((IData)(vlTOPp->reset) ? 0ULL : (((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                           & (0xb00U 
                                              == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))
                                           ? vlTOPp->SimTop__DOT__wb_ex_data
                                           : (1ULL 
                                              + vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mcycle)));
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtval = 0ULL;
    } else if ((0U != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtval 
            = (((- (QData)((IData)((0U != (0x1003U 
                                           & (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info)))))) 
                & vlTOPp->SimTop__DOT__mem_pc) | ((- (QData)((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                         >> 2U))))) 
                                                  & (QData)((IData)(vlTOPp->SimTop__DOT__mem_inst))));
    } else if (((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                & (0x343U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtval 
            = vlTOPp->SimTop__DOT__wb_ex_data;
    }
    if (vlTOPp->reset) {
        __Vdlyvset__SimTop__DOT__Regfile__DOT__regs__v0 = 1U;
    } else if (((IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ena) 
                & (0U != (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)))) {
        __Vdlyvval__SimTop__DOT__Regfile__DOT__regs__v32 
            = vlTOPp->SimTop__DOT__wb_reg_wr_data;
        __Vdlyvset__SimTop__DOT__Regfile__DOT__regs__v32 = 1U;
        __Vdlyvdim0__SimTop__DOT__Regfile__DOT__regs__v32 
            = vlTOPp->SimTop__DOT__wb_reg_wr_addr;
    }
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
    if (vlTOPp->SimTop__DOT__ex_valid) {
        vlTOPp->SimTop__DOT__mem_ram_wr_src = vlTOPp->SimTop__DOT__rs2_forward;
    }
    if (vlTOPp->SimTop__DOT__ex_valid) {
        vlTOPp->SimTop__DOT__mem_ram_wr_ena = (((IData)(vlTOPp->SimTop__DOT__ex_ram_wr_ena_r) 
                                                & (IData)(vlTOPp->SimTop__DOT__ex_valid)) 
                                               & (IData)(vlTOPp->SimTop__DOT__ex_valid));
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        vlTOPp->SimTop__DOT__skip = (0x80000000ULL 
                                     == vlTOPp->SimTop__DOT__if_pc);
    }
    vlTOPp->SimTop__DOT__cmt_wdata = ((IData)(vlTOPp->reset)
                                       ? 0ULL : vlTOPp->SimTop__DOT__wb_reg_wr_data);
    vlTOPp->SimTop__DOT__vaild = ((~ (IData)(vlTOPp->reset)) 
                                  & (IData)(vlTOPp->SimTop__DOT__wb_valid));
    vlTOPp->SimTop__DOT__cmt_inst = ((IData)(vlTOPp->reset)
                                      ? 0U : vlTOPp->SimTop__DOT__wb_inst);
    vlTOPp->SimTop__DOT__cmt_wen = ((~ (IData)(vlTOPp->reset)) 
                                    & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ena));
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__cmt_wdest = 0U;
        vlTOPp->SimTop__DOT__cmt_pc = 0ULL;
    } else {
        vlTOPp->SimTop__DOT__cmt_wdest = vlTOPp->SimTop__DOT__wb_reg_wr_addr;
        vlTOPp->SimTop__DOT__cmt_pc = vlTOPp->SimTop__DOT__wb_pc;
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mip = 0ULL;
    } else if (((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                & (0x344U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mip 
            = vlTOPp->SimTop__DOT__wb_ex_data;
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mscratch = 0ULL;
    } else if (((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                & (0x430U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mscratch 
            = vlTOPp->SimTop__DOT__wb_ex_data;
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mcause = 0ULL;
    } else if ((0U != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mcause 
            = (((((((((((1ULL & (- (QData)((IData)(
                                                   (1U 
                                                    & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                       >> 1U)))))) 
                        | (2ULL & (- (QData)((IData)(
                                                     (1U 
                                                      & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                         >> 2U))))))) 
                       | (3ULL & (- (QData)((IData)(
                                                    (1U 
                                                     & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                        >> 3U))))))) 
                      | (4ULL & (- (QData)((IData)(
                                                   (1U 
                                                    & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                       >> 4U))))))) 
                     | (5ULL & (- (QData)((IData)((1U 
                                                   & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                      >> 5U))))))) 
                    | (6ULL & (- (QData)((IData)((1U 
                                                  & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                     >> 6U))))))) 
                   | (7ULL & (- (QData)((IData)((1U 
                                                 & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                    >> 7U))))))) 
                  | (0xbULL & (- (QData)((IData)((1U 
                                                  & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                     >> 0xbU))))))) 
                 | (0xcULL & (- (QData)((IData)((1U 
                                                 & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                    >> 0xcU))))))) 
                | (0xdULL & (- (QData)((IData)((1U 
                                                & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                   >> 0xdU))))))) 
               | (0xfULL & (- (QData)((IData)((1U & 
                                               ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                >> 0xfU)))))));
    } else if (((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                & (0x342U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mcause 
            = vlTOPp->SimTop__DOT__wb_ex_data;
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mepc = 0ULL;
    } else if ((1U & (~ (IData)((0U != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info)))))) {
        if (((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
             & (0x341U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))) {
            vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mepc 
                = vlTOPp->SimTop__DOT__wb_ex_data;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus = 0x1888ULL;
    } else if (((0U != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info)) 
                | (IData)(vlTOPp->SimTop__DOT__excp_exit))) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
            = (((- (QData)((IData)((0U != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))))) 
                & vlTOPp->SimTop__DOT__Excp_handler__DOT__mstatus_excp_enter) 
               | ((- (QData)((IData)(vlTOPp->SimTop__DOT__excp_exit))) 
                  & vlTOPp->SimTop__DOT__Excp_handler__DOT__mstatus_excp_exit));
    } else if (((0x300U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)) 
                & (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena))) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
            = vlTOPp->SimTop__DOT__wb_ex_data;
    }
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        if ((0U != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))) {
            vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec 
                = ((- (QData)((IData)((0U != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))))) 
                   & vlTOPp->SimTop__DOT__mem_pc);
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec = 0ULL;
    } else if (((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                & (0x305U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))) {
        vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec 
            = vlTOPp->SimTop__DOT__wb_ex_data;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_load_info = vlTOPp->SimTop__DOT__id_load_info;
    }
    if (vlTOPp->SimTop__DOT__ex_valid) {
        vlTOPp->SimTop__DOT__mem_csr_data = vlTOPp->SimTop__DOT__ex_csr_data;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_save_info = (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sd) 
                                              << 3U) 
                                             | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sw) 
                                                 << 2U) 
                                                | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sh) 
                                                    << 1U) 
                                                   | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sb))));
    }
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_shift 
        = (IData)((0U != (0x380U & (IData)(vlTOPp->SimTop__DOT__ex_alu_info))));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub 
        = (IData)((0U != (0xeU & (IData)(vlTOPp->SimTop__DOT__ex_alu_info))));
    if (vlTOPp->SimTop__DOT__ex_valid) {
        vlTOPp->SimTop__DOT__mem_reg_wr_ctrl = ((IData)(vlTOPp->SimTop__DOT__ex_reg_wr_ctrl) 
                                                & (- (IData)((IData)(vlTOPp->SimTop__DOT__ex_valid))));
    }
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[1U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[1U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[2U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[2U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[3U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[3U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[4U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[4U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[5U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[5U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[6U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[6U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[7U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[7U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[8U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[8U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[9U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[9U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0xaU] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0xaU];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0xbU] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0xbU];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0xcU] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0xcU];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0xdU] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0xdU];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0xeU] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0xeU];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0xfU] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0xfU];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x10U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x10U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x11U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x11U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x12U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x12U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x13U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x13U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x14U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x14U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x15U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x15U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x16U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x16U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x17U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x17U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x18U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x18U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x19U] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x19U];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x1aU] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x1aU];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x1bU] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x1bU];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x1cU] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x1cU];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x1dU] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x1dU];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x1eU] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x1eU];
    vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0x1fU] 
        = vlTOPp->SimTop__DOT__Regfile__DOT__regs[0x1fU];
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub 
        = (1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                 | (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)));
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
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_ram_wr_ena_r = ((~ (IData)(vlTOPp->reset)) 
                                                & (0x23U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SimTop__DOT__id_inst)));
    }
    vlTOPp->SimTop__DOT__wb_valid = ((~ (IData)(vlTOPp->reset)) 
                                     & (IData)(vlTOPp->SimTop__DOT__mem_valid));
    if (vlTOPp->SimTop__DOT__mem_valid) {
        vlTOPp->SimTop__DOT__wb_inst = vlTOPp->SimTop__DOT__mem_inst;
    }
    if (vlTOPp->SimTop__DOT__mem_valid) {
        vlTOPp->SimTop__DOT__wb_reg_wr_ena = ((IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ena) 
                                              & (IData)(vlTOPp->SimTop__DOT__mem_valid));
    }
    if (vlTOPp->SimTop__DOT__mem_valid) {
        vlTOPp->SimTop__DOT__wb_reg_wr_addr = vlTOPp->SimTop__DOT__mem_reg_wr_addr;
    }
    if (vlTOPp->SimTop__DOT__mem_valid) {
        vlTOPp->SimTop__DOT__wb_pc = vlTOPp->SimTop__DOT__mem_pc;
    }
    vlTOPp->SimTop__DOT__Excp_handler__DOT__mstatus_excp_enter 
        = ((0xffffffffffffff00ULL & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus) 
           | (QData)((IData)(((0x80U & ((IData)((vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                 >> 3U)) 
                                        << 7U)) | (
                                                   (0x70U 
                                                    & ((IData)(
                                                               (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                                >> 4U)) 
                                                       << 4U)) 
                                                   | (7U 
                                                      & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus)))))));
    vlTOPp->SimTop__DOT__Excp_handler__DOT__mstatus_excp_exit 
        = ((0xffffffffffffff00ULL & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus) 
           | (QData)((IData)((0x80U | ((0x70U & ((IData)(
                                                         (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                          >> 4U)) 
                                                 << 4U)) 
                                       | ((8U & ((IData)(
                                                         (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                          >> 7U)) 
                                                 << 3U)) 
                                          | (7U & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus))))))));
    if (vlTOPp->SimTop__DOT__mem_valid) {
        vlTOPp->SimTop__DOT__wb_csr_wr_addr = vlTOPp->SimTop__DOT__mem_csr_wr_addr;
    }
    if (vlTOPp->SimTop__DOT__mem_valid) {
        vlTOPp->SimTop__DOT__wb_csr_wr_ena = ((IData)(vlTOPp->SimTop__DOT__mem_csr_wr_ena) 
                                              & (IData)(vlTOPp->SimTop__DOT__mem_valid));
    }
    if (vlTOPp->SimTop__DOT__mem_valid) {
        vlTOPp->SimTop__DOT__wb_ex_data = vlTOPp->SimTop__DOT__mem_ex_data;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_csr_data = vlTOPp->SimTop__DOT__id_csr_data;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_reg_wr_ctrl = (((((~ (IData)(vlTOPp->reset)) 
                                                  & ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm) 
                                                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg))) 
                                                 << 2U) 
                                                | ((((~ (IData)(vlTOPp->reset)) 
                                                     & (3U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->SimTop__DOT__id_inst))) 
                                                    << 1U) 
                                                   | ((~ (IData)(vlTOPp->reset)) 
                                                      & (((((((((0xfU 
                                                                 == 
                                                                 (0x7fU 
                                                                  & vlTOPp->SimTop__DOT__id_inst)) 
                                                                | (0x13U 
                                                                   == 
                                                                   (0x7fU 
                                                                    & vlTOPp->SimTop__DOT__id_inst))) 
                                                               | (0x17U 
                                                                  == 
                                                                  (0x7fU 
                                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                                              | (0x1bU 
                                                                 == 
                                                                 (0x7fU 
                                                                  & vlTOPp->SimTop__DOT__id_inst))) 
                                                             | (0x33U 
                                                                == 
                                                                (0x7fU 
                                                                 & vlTOPp->SimTop__DOT__id_inst))) 
                                                            | (0x37U 
                                                               == 
                                                               (0x7fU 
                                                                & vlTOPp->SimTop__DOT__id_inst))) 
                                                           | (0x3bU 
                                                              == 
                                                              (0x7fU 
                                                               & vlTOPp->SimTop__DOT__id_inst))) 
                                                          | (0x6fU 
                                                             == 
                                                             (0x7fU 
                                                              & vlTOPp->SimTop__DOT__id_inst))) 
                                                         | (0x67U 
                                                            == 
                                                            (0x7fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)))))) 
                                               & (- (IData)((IData)(vlTOPp->SimTop__DOT__id_valid))));
    }
    if (vlTOPp->SimTop__DOT__ex_valid) {
        vlTOPp->SimTop__DOT__mem_inst = vlTOPp->SimTop__DOT__ex_inst;
    }
    if (vlTOPp->SimTop__DOT__ex_valid) {
        vlTOPp->SimTop__DOT__mem_reg_wr_ena = (((IData)(vlTOPp->SimTop__DOT__ex_reg_wr_ena_r) 
                                                & (IData)(vlTOPp->SimTop__DOT__ex_valid)) 
                                               & (IData)(vlTOPp->SimTop__DOT__ex_valid));
    }
    if (vlTOPp->SimTop__DOT__ex_valid) {
        vlTOPp->SimTop__DOT__mem_reg_wr_addr = vlTOPp->SimTop__DOT__ex_reg_wr_addr;
    }
    if (vlTOPp->SimTop__DOT__ex_valid) {
        vlTOPp->SimTop__DOT__mem_pc = vlTOPp->SimTop__DOT__ex_pc;
    }
    if (vlTOPp->SimTop__DOT__ex_valid) {
        vlTOPp->SimTop__DOT__mem_csr_wr_ena = (((IData)(vlTOPp->SimTop__DOT__ex_csr_wr_ena_r) 
                                                & (IData)(vlTOPp->SimTop__DOT__ex_valid)) 
                                               & (IData)(vlTOPp->SimTop__DOT__ex_valid));
    }
    vlTOPp->SimTop__DOT__mem_valid = ((~ (IData)(vlTOPp->reset)) 
                                      & (IData)(vlTOPp->SimTop__DOT__ex_valid));
    if (vlTOPp->SimTop__DOT__ex_valid) {
        vlTOPp->SimTop__DOT__mem_ex_data = (((QData)((IData)(
                                                             ((IData)(vlTOPp->SimTop__DOT__ex_is_word_opt)
                                                               ? 
                                                              (- (IData)(
                                                                         (1U 
                                                                          & (IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output 
                                                                                >> 0x1fU)))))
                                                               : (IData)(
                                                                         (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output 
                                                                          >> 0x20U))))) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output)));
    }
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__id_valid = 0U;
    } else if (vlTOPp->SimTop__DOT__id_allowin) {
        vlTOPp->SimTop__DOT__id_valid = 1U;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_inst = vlTOPp->SimTop__DOT__id_inst;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_reg_wr_ena_r = vlTOPp->SimTop__DOT__id_reg_wr_ena;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_reg_wr_addr = vlTOPp->SimTop__DOT__id_reg_wr_addr;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_pc = vlTOPp->SimTop__DOT__id_pc;
    }
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_csr_wr_ena_r = ((~ (IData)(vlTOPp->reset)) 
                                                & ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm) 
                                                   | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg)));
    }
    vlTOPp->SimTop__DOT__ex_valid = ((~ ((IData)(vlTOPp->reset) 
                                         | (IData)(vlTOPp->SimTop__DOT__bj_ena))) 
                                     & (IData)(vlTOPp->SimTop__DOT__id_to_ex_valid));
    vlTOPp->SimTop__DOT__byte_enable = ((0xfeU & (IData)(vlTOPp->SimTop__DOT__byte_enable)) 
                                        | ((IData)(
                                                   (0U 
                                                    != 
                                                    (0xfU 
                                                     & (IData)(vlTOPp->SimTop__DOT__mem_save_info)))) 
                                           & (0U == 
                                              (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
    vlTOPp->SimTop__DOT__byte_enable = ((0xfdU & (IData)(vlTOPp->SimTop__DOT__byte_enable)) 
                                        | ((((((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                               & (1U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))) 
                                              << 1U) 
                                             | (0xfffffffeU 
                                                & ((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                   & ((0U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                      << 1U)))) 
                                            | (0x7ffffffeU 
                                               & (((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                   >> 1U) 
                                                  & ((0U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                     << 1U)))) 
                                           | (0x3ffffffeU 
                                              & (((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                  >> 2U) 
                                                 & ((0U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                    << 1U)))));
    vlTOPp->SimTop__DOT__byte_enable = ((0xfbU & (IData)(vlTOPp->SimTop__DOT__byte_enable)) 
                                        | ((((((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                               << 2U) 
                                              | (0xfffffffcU 
                                                 & ((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                    << 1U))) 
                                             & ((2U 
                                                 == 
                                                 (7U 
                                                  & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                << 2U)) 
                                            | (0xfffffffcU 
                                               & ((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                  & ((0U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                     << 2U)))) 
                                           | (0x7ffffffcU 
                                              & (((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                  >> 1U) 
                                                 & ((0U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                    << 2U)))));
    vlTOPp->SimTop__DOT__byte_enable = ((0xf7U & (IData)(vlTOPp->SimTop__DOT__byte_enable)) 
                                        | ((((((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                               & (3U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))) 
                                              << 3U) 
                                             | (0xfffffff8U 
                                                & (((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                    << 2U) 
                                                   & ((2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                      << 3U)))) 
                                            | (0xfffffff8U 
                                               & (((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                   << 1U) 
                                                  & ((0U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                     << 3U)))) 
                                           | (0xfffffff8U 
                                              & ((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                 & ((0U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                    << 3U)))));
    vlTOPp->SimTop__DOT__byte_enable = ((0xefU & (IData)(vlTOPp->SimTop__DOT__byte_enable)) 
                                        | ((((IData)(
                                                     (0U 
                                                      != 
                                                      (7U 
                                                       & (IData)(vlTOPp->SimTop__DOT__mem_save_info)))) 
                                             & (4U 
                                                == 
                                                (7U 
                                                 & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))) 
                                            << 4U) 
                                           | (0xfffffff0U 
                                              & (((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                  << 1U) 
                                                 & ((0U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                    << 4U)))));
    vlTOPp->SimTop__DOT__byte_enable = ((0xdfU & (IData)(vlTOPp->SimTop__DOT__byte_enable)) 
                                        | ((((((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                               & (5U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))) 
                                              << 5U) 
                                             | (0xffffffe0U 
                                                & (((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                    << 4U) 
                                                   & ((4U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                      << 5U)))) 
                                            | (0xffffffe0U 
                                               & (((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                   << 3U) 
                                                  & ((4U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                     << 5U)))) 
                                           | (0xffffffe0U 
                                              & (((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                  << 2U) 
                                                 & ((0U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                    << 5U)))));
    vlTOPp->SimTop__DOT__byte_enable = ((0xbfU & (IData)(vlTOPp->SimTop__DOT__byte_enable)) 
                                        | ((((((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                               << 6U) 
                                              | (0xffffffc0U 
                                                 & ((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                    << 5U))) 
                                             & ((6U 
                                                 == 
                                                 (7U 
                                                  & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                << 6U)) 
                                            | (0xffffffc0U 
                                               & (((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                   << 4U) 
                                                  & ((4U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                     << 6U)))) 
                                           | (0xffffffc0U 
                                              & (((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                  << 3U) 
                                                 & ((0U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                    << 6U)))));
    vlTOPp->SimTop__DOT__byte_enable = ((0x7fU & (IData)(vlTOPp->SimTop__DOT__byte_enable)) 
                                        | ((((((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                               & (7U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))) 
                                              << 7U) 
                                             | (0xffffff80U 
                                                & (((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                    << 6U) 
                                                   & ((6U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                      << 7U)))) 
                                            | (0xffffff80U 
                                               & (((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                   << 5U) 
                                                  & ((4U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                     << 7U)))) 
                                           | (0xffffff80U 
                                              & (((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                                  << 4U) 
                                                 & ((0U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->SimTop__DOT__mem_ex_data))) 
                                                    << 7U)))));
    vlSymsp->TOP____024unit.__Vdpiimwrap_ram_read_helper_TOP____024unit(vlTOPp->SimTop__DOT__mem_ram_rd_ena, 
                                                                        ((vlTOPp->SimTop__DOT__mem_ex_data 
                                                                          - 0x80000000ULL) 
                                                                         >> 3U), vlTOPp->__Vfunc_ram_read_helper__1__Vfuncout);
    vlTOPp->SimTop__DOT__ram_rd_data = vlTOPp->__Vfunc_ram_read_helper__1__Vfuncout;
    vlTOPp->SimTop__DOT__rs1_forward = ((((((IData)(vlTOPp->SimTop__DOT__ex_rs1_addr) 
                                            == (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_addr)) 
                                           & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ena)) 
                                          & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs1_addr))) 
                                         & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ctrl))
                                         ? vlTOPp->SimTop__DOT__mem_ex_data
                                         : ((((((IData)(vlTOPp->SimTop__DOT__ex_rs1_addr) 
                                                == (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)) 
                                               & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ena)) 
                                              & (0U 
                                                 != (IData)(vlTOPp->SimTop__DOT__ex_rs1_addr))) 
                                             & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl))
                                             ? vlTOPp->SimTop__DOT__wb_ex_data
                                             : ((((
                                                   ((IData)(vlTOPp->SimTop__DOT__ex_rs1_addr) 
                                                    == (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)) 
                                                   & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ena)) 
                                                  & (0U 
                                                     != (IData)(vlTOPp->SimTop__DOT__ex_rs1_addr))) 
                                                 & ((IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl) 
                                                    >> 1U))
                                                 ? vlTOPp->SimTop__DOT__wb_ram_data
                                                 : vlTOPp->SimTop__DOT__ex_rs1_data)));
    vlTOPp->SimTop__DOT__rs2_forward = ((((((IData)(vlTOPp->SimTop__DOT__ex_rs2_addr) 
                                            == (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_addr)) 
                                           & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ena)) 
                                          & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs2_addr))) 
                                         & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ctrl))
                                         ? vlTOPp->SimTop__DOT__mem_ex_data
                                         : ((((((IData)(vlTOPp->SimTop__DOT__ex_rs2_addr) 
                                                == (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)) 
                                               & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ena)) 
                                              & (0U 
                                                 != (IData)(vlTOPp->SimTop__DOT__ex_rs2_addr))) 
                                             & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl))
                                             ? vlTOPp->SimTop__DOT__wb_ex_data
                                             : ((((
                                                   ((IData)(vlTOPp->SimTop__DOT__ex_rs2_addr) 
                                                    == (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)) 
                                                   & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ena)) 
                                                  & (0U 
                                                     != (IData)(vlTOPp->SimTop__DOT__ex_rs2_addr))) 
                                                 & ((IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl) 
                                                    >> 1U))
                                                 ? vlTOPp->SimTop__DOT__wb_ram_data
                                                 : vlTOPp->SimTop__DOT__ex_rs2_data)));
    if (vlTOPp->SimTop__DOT__id_to_ex_valid) {
        vlTOPp->SimTop__DOT__ex_is_word_opt = ((0x3bU 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->SimTop__DOT__id_inst)) 
                                               | (0x1bU 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst)));
    }
    vlTOPp->SimTop__DOT__Mem_stage__DOT__mem_part = 
        (vlTOPp->SimTop__DOT__ram_rd_data >> (0x38U 
                                              & ((IData)(vlTOPp->SimTop__DOT__mem_ex_data) 
                                                 << 3U)));
    vlTOPp->SimTop__DOT__true_op1 = ((IData)(vlTOPp->SimTop__DOT__ex_use_rs1)
                                      ? vlTOPp->SimTop__DOT__rs1_forward
                                      : vlTOPp->SimTop__DOT__ex_now_op1);
    vlTOPp->SimTop__DOT__true_op2 = ((IData)(vlTOPp->SimTop__DOT__ex_use_rs2)
                                      ? vlTOPp->SimTop__DOT__rs2_forward
                                      : vlTOPp->SimTop__DOT__ex_now_op2);
    if (vlTOPp->reset) {
        vlTOPp->SimTop__DOT__id_pc = 0x7ffffffcULL;
    } else if (vlTOPp->SimTop__DOT__id_allowin) {
        vlTOPp->SimTop__DOT__id_pc = vlTOPp->SimTop__DOT__if_pc;
    }
    vlTOPp->SimTop__DOT__ex_ram_rd_ena = ((IData)(vlTOPp->SimTop__DOT__ex_ram_rd_ena_r) 
                                          & (IData)(vlTOPp->SimTop__DOT__ex_valid));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 = (((QData)((IData)(
                                                                ((- (IData)(
                                                                            (1U 
                                                                             & (~ (IData)(vlTOPp->SimTop__DOT__ex_is_word_opt))))) 
                                                                 & (IData)(
                                                                           (vlTOPp->SimTop__DOT__true_op1 
                                                                            >> 0x20U))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlTOPp->SimTop__DOT__true_op1)));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__op2 = (((QData)((IData)(
                                                                ((- (IData)(
                                                                            (1U 
                                                                             & (~ (IData)(vlTOPp->SimTop__DOT__ex_is_word_opt))))) 
                                                                 & (IData)(
                                                                           (vlTOPp->SimTop__DOT__true_op2 
                                                                            >> 0x20U))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlTOPp->SimTop__DOT__true_op2)));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in1 
        = ((- (QData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_shift))) 
           & ((IData)((0U != (0x300U & (IData)(vlTOPp->SimTop__DOT__ex_alu_info))))
               ? (((QData)((IData)(((0x80000000U & 
                                     ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__op1) 
                                      << 0x1fU)) | 
                                    ((0x40000000U & 
                                      ((IData)((vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                >> 1U)) 
                                       << 0x1eU)) | 
                                     ((0x20000000U 
                                       & ((IData)((vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                   >> 2U)) 
                                          << 0x1dU)) 
                                      | ((0x10000000U 
                                          & ((IData)(
                                                     (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                      >> 3U)) 
                                             << 0x1cU)) 
                                         | ((0x8000000U 
                                             & ((IData)(
                                                        (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                         >> 4U)) 
                                                << 0x1bU)) 
                                            | ((0x4000000U 
                                                & ((IData)(
                                                           (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                            >> 5U)) 
                                                   << 0x1aU)) 
                                               | ((0x2000000U 
                                                   & ((IData)(
                                                              (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                               >> 6U)) 
                                                      << 0x19U)) 
                                                  | ((0x1000000U 
                                                      & ((IData)(
                                                                 (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                  >> 7U)) 
                                                         << 0x18U)) 
                                                     | ((0x800000U 
                                                         & ((IData)(
                                                                    (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                     >> 8U)) 
                                                            << 0x17U)) 
                                                        | ((0x400000U 
                                                            & ((IData)(
                                                                       (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                        >> 9U)) 
                                                               << 0x16U)) 
                                                           | ((0x200000U 
                                                               & ((IData)(
                                                                          (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                           >> 0xaU)) 
                                                                  << 0x15U)) 
                                                              | ((0x100000U 
                                                                  & ((IData)(
                                                                             (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                              >> 0xbU)) 
                                                                     << 0x14U)) 
                                                                 | ((0x80000U 
                                                                     & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0xcU)) 
                                                                        << 0x13U)) 
                                                                    | ((0x40000U 
                                                                        & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0xdU)) 
                                                                           << 0x12U)) 
                                                                       | ((0x20000U 
                                                                           & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0xeU)) 
                                                                              << 0x11U)) 
                                                                          | ((0x10000U 
                                                                              & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0xfU)) 
                                                                                << 0x10U)) 
                                                                             | ((0x8000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x10U)) 
                                                                                << 0xfU)) 
                                                                                | ((0x4000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x11U)) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x12U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x13U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x14U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x15U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x16U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x17U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x18U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x19U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x1cU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))))))))) 
                   << 0x20U) | (QData)((IData)(((0x80000000U 
                                                 & ((IData)(
                                                            (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                             >> 0x20U)) 
                                                    << 0x1fU)) 
                                                | ((0x40000000U 
                                                    & ((IData)(
                                                               (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                >> 0x21U)) 
                                                       << 0x1eU)) 
                                                   | ((0x20000000U 
                                                       & ((IData)(
                                                                  (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                   >> 0x22U)) 
                                                          << 0x1dU)) 
                                                      | ((0x10000000U 
                                                          & ((IData)(
                                                                     (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                      >> 0x23U)) 
                                                             << 0x1cU)) 
                                                         | ((0x8000000U 
                                                             & ((IData)(
                                                                        (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                         >> 0x24U)) 
                                                                << 0x1bU)) 
                                                            | ((0x4000000U 
                                                                & ((IData)(
                                                                           (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                            >> 0x25U)) 
                                                                   << 0x1aU)) 
                                                               | ((0x2000000U 
                                                                   & ((IData)(
                                                                              (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                               >> 0x26U)) 
                                                                      << 0x19U)) 
                                                                  | ((0x1000000U 
                                                                      & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x27U)) 
                                                                         << 0x18U)) 
                                                                     | ((0x800000U 
                                                                         & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x28U)) 
                                                                            << 0x17U)) 
                                                                        | ((0x400000U 
                                                                            & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x29U)) 
                                                                               << 0x16U)) 
                                                                           | ((0x200000U 
                                                                               & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x2aU)) 
                                                                                << 0x15U)) 
                                                                              | ((0x100000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x2bU)) 
                                                                                << 0x14U)) 
                                                                                | ((0x80000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x2cU)) 
                                                                                << 0x13U)) 
                                                                                | ((0x40000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x2dU)) 
                                                                                << 0x12U)) 
                                                                                | ((0x20000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x2eU)) 
                                                                                << 0x11U)) 
                                                                                | ((0x10000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x2fU)) 
                                                                                << 0x10U)) 
                                                                                | ((0x8000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x30U)) 
                                                                                << 0xfU)) 
                                                                                | ((0x4000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x31U)) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x32U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x33U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x34U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x35U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x36U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x37U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x38U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x39U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x3aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x3bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x3cU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x3dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x3eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                                >> 0x3fU)))))))))))))))))))))))))))))))))))))
               : vlTOPp->SimTop__DOT__Ex_stage__DOT__op1));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res 
        = (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
           ^ vlTOPp->SimTop__DOT__Ex_stage__DOT__op2);
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in2 
        = (0x3fU & ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_shift))) 
                    & ((IData)(vlTOPp->SimTop__DOT__ex_is_word_opt)
                        ? (0x1fU & (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__op2))
                        : (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__op2))));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U] 
        = (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__op2);
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U] 
        = (IData)((vlTOPp->SimTop__DOT__Ex_stage__DOT__op2 
                   >> 0x20U));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U] 
        = (1U & ((~ ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                     >> 3U)) & (IData)((vlTOPp->SimTop__DOT__Ex_stage__DOT__op2 
                                        >> 0x3fU))));
    vlSymsp->TOP____024unit.__Vdpiimwrap_ram_read_helper_TOP____024unit(1U, 
                                                                        ((vlTOPp->SimTop__DOT__id_pc 
                                                                          - 0x80000000ULL) 
                                                                         >> 3U), vlTOPp->__Vfunc_ram_read_helper__0__Vfuncout);
    vlTOPp->SimTop__DOT__RAM_1W2R__DOT__inst_2 = vlTOPp->__Vfunc_ram_read_helper__0__Vfuncout;
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask 
        = (((IData)(vlTOPp->SimTop__DOT__ex_is_word_opt)
             ? 0xffffffffULL : 0xffffffffffffffffULL) 
           >> (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in2));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
        = (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in1 
           << (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in2));
    __Vtemp23[0U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                     & (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__op1));
    __Vtemp23[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                     & (IData)((vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                >> 0x20U)));
    __Vtemp23[2U] = (1U & ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                           & ((~ ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                  >> 3U)) & (IData)(
                                                    (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                     >> 0x3fU)))));
    __Vtemp27[0U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                     & ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                         ? (~ vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U])
                         : vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U]));
    __Vtemp27[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                     & ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                         ? (~ vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U])
                         : vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U]));
    __Vtemp27[2U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                     & ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                         ? (~ vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U])
                         : vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U]));
    VL_ADD_W(3, __Vtemp28, __Vtemp23, __Vtemp27);
    __Vtemp31[0U] = ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                      ? 1U : 0U);
    __Vtemp31[1U] = 0U;
    __Vtemp31[2U] = 0U;
    VL_ADD_W(3, __Vtemp32, __Vtemp28, __Vtemp31);
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res[0U] 
        = __Vtemp32[0U];
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res[1U] 
        = __Vtemp32[1U];
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res[2U] 
        = (1U & __Vtemp32[2U]);
    vlTOPp->SimTop__DOT__id_inst = ((1U & (IData)((vlTOPp->SimTop__DOT__id_pc 
                                                   >> 2U)))
                                     ? (IData)((vlTOPp->SimTop__DOT__RAM_1W2R__DOT__inst_2 
                                                >> 0x20U))
                                     : (IData)(vlTOPp->SimTop__DOT__RAM_1W2R__DOT__inst_2));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res 
        = (((QData)((IData)(((0x80000000U & ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res) 
                                             << 0x1fU)) 
                             | ((0x40000000U & ((IData)(
                                                        (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                         >> 1U)) 
                                                << 0x1eU)) 
                                | ((0x20000000U & ((IData)(
                                                           (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                            >> 2U)) 
                                                   << 0x1dU)) 
                                   | ((0x10000000U 
                                       & ((IData)((vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                   >> 3U)) 
                                          << 0x1cU)) 
                                      | ((0x8000000U 
                                          & ((IData)(
                                                     (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                      >> 4U)) 
                                             << 0x1bU)) 
                                         | ((0x4000000U 
                                             & ((IData)(
                                                        (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                         >> 5U)) 
                                                << 0x1aU)) 
                                            | ((0x2000000U 
                                                & ((IData)(
                                                           (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                            >> 6U)) 
                                                   << 0x19U)) 
                                               | ((0x1000000U 
                                                   & ((IData)(
                                                              (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                               >> 7U)) 
                                                      << 0x18U)) 
                                                  | ((0x800000U 
                                                      & ((IData)(
                                                                 (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                  >> 8U)) 
                                                         << 0x17U)) 
                                                     | ((0x400000U 
                                                         & ((IData)(
                                                                    (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                     >> 9U)) 
                                                            << 0x16U)) 
                                                        | ((0x200000U 
                                                            & ((IData)(
                                                                       (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                        >> 0xaU)) 
                                                               << 0x15U)) 
                                                           | ((0x100000U 
                                                               & ((IData)(
                                                                          (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                           >> 0xbU)) 
                                                                  << 0x14U)) 
                                                              | ((0x80000U 
                                                                  & ((IData)(
                                                                             (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                              >> 0xcU)) 
                                                                     << 0x13U)) 
                                                                 | ((0x40000U 
                                                                     & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0xdU)) 
                                                                        << 0x12U)) 
                                                                    | ((0x20000U 
                                                                        & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0xeU)) 
                                                                           << 0x11U)) 
                                                                       | ((0x10000U 
                                                                           & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0xfU)) 
                                                                              << 0x10U)) 
                                                                          | ((0x8000U 
                                                                              & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x10U)) 
                                                                                << 0xfU)) 
                                                                             | ((0x4000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x11U)) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x12U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x13U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x14U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x15U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x16U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x17U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x18U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x19U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x1cU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))))))))) 
            << 0x20U) | (QData)((IData)(((0x80000000U 
                                          & ((IData)(
                                                     (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                      >> 0x20U)) 
                                             << 0x1fU)) 
                                         | ((0x40000000U 
                                             & ((IData)(
                                                        (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                         >> 0x21U)) 
                                                << 0x1eU)) 
                                            | ((0x20000000U 
                                                & ((IData)(
                                                           (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                            >> 0x22U)) 
                                                   << 0x1dU)) 
                                               | ((0x10000000U 
                                                   & ((IData)(
                                                              (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                               >> 0x23U)) 
                                                      << 0x1cU)) 
                                                  | ((0x8000000U 
                                                      & ((IData)(
                                                                 (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                  >> 0x24U)) 
                                                         << 0x1bU)) 
                                                     | ((0x4000000U 
                                                         & ((IData)(
                                                                    (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                     >> 0x25U)) 
                                                            << 0x1aU)) 
                                                        | ((0x2000000U 
                                                            & ((IData)(
                                                                       (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                        >> 0x26U)) 
                                                               << 0x19U)) 
                                                           | ((0x1000000U 
                                                               & ((IData)(
                                                                          (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                           >> 0x27U)) 
                                                                  << 0x18U)) 
                                                              | ((0x800000U 
                                                                  & ((IData)(
                                                                             (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                              >> 0x28U)) 
                                                                     << 0x17U)) 
                                                                 | ((0x400000U 
                                                                     & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x29U)) 
                                                                        << 0x16U)) 
                                                                    | ((0x200000U 
                                                                        & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x2aU)) 
                                                                           << 0x15U)) 
                                                                       | ((0x100000U 
                                                                           & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x2bU)) 
                                                                              << 0x14U)) 
                                                                          | ((0x80000U 
                                                                              & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x2cU)) 
                                                                                << 0x13U)) 
                                                                             | ((0x40000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x2dU)) 
                                                                                << 0x12U)) 
                                                                                | ((0x20000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x2eU)) 
                                                                                << 0x11U)) 
                                                                                | ((0x10000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x2fU)) 
                                                                                << 0x10U)) 
                                                                                | ((0x8000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x30U)) 
                                                                                << 0xfU)) 
                                                                                | ((0x4000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x31U)) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x32U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x33U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x34U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x35U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x36U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x37U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x38U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x39U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x3aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x3bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x3cU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x3dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x3eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (IData)(
                                                                                (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
                                                                                >> 0x3fU)))))))))))))))))))))))))))))))))))));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res 
        = (QData)((IData)((1U & ((IData)((0U != (0xcU 
                                                 & (IData)(vlTOPp->SimTop__DOT__ex_alu_info)))) 
                                 & vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res[2U]))));
    vlTOPp->SimTop__DOT__Id_stage__DOT__immB = ((0x1000U 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x13U)) 
                                                | ((0x800U 
                                                    & (vlTOPp->SimTop__DOT__id_inst 
                                                       << 4U)) 
                                                   | ((0x7e0U 
                                                       & (vlTOPp->SimTop__DOT__id_inst 
                                                          >> 0x14U)) 
                                                      | (0x1eU 
                                                         & (vlTOPp->SimTop__DOT__id_inst 
                                                            >> 7U)))));
    vlTOPp->SimTop__DOT__Id_stage__DOT__immJ = ((0x100000U 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0xbU)) 
                                                | ((0xff000U 
                                                    & vlTOPp->SimTop__DOT__id_inst) 
                                                   | ((0x800U 
                                                       & (vlTOPp->SimTop__DOT__id_inst 
                                                          >> 9U)) 
                                                      | (0x7feU 
                                                         & (vlTOPp->SimTop__DOT__id_inst 
                                                            >> 0x14U)))));
    vlTOPp->SimTop__DOT__id_reg_wr_addr = (0x1fU & 
                                           (vlTOPp->SimTop__DOT__id_inst 
                                            >> 7U));
    vlTOPp->SimTop__DOT__Id_stage__DOT__immS = ((0xfe0U 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)) 
                                                | (0x1fU 
                                                   & (vlTOPp->SimTop__DOT__id_inst 
                                                      >> 7U)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_excp 
        = (IData)((0x73U == (0x707fU & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sb = (IData)(
                                                          (0x23U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sh = (IData)(
                                                          (0x1023U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sw = (IData)(
                                                          (0x2023U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sd = (IData)(
                                                          (0x3023U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lbu = (IData)(
                                                           (0x4003U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lhu = (IData)(
                                                           (0x5003U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lwu = (IData)(
                                                           (0x6003U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lb = (IData)(
                                                          (3U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lh = (IData)(
                                                          (0x1003U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lw = (IData)(
                                                          (0x2003U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_ld = (IData)(
                                                          (0x3003U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_andi = (IData)(
                                                            (0x7013U 
                                                             == 
                                                             (0x707fU 
                                                              & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_and = (IData)(
                                                           (0x7033U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sub = (IData)(
                                                           (0x40000033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_subw = (IData)(
                                                            (0x4000003bU 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slli = (IData)(
                                                            (0x1013U 
                                                             == 
                                                             (0xfc00707fU 
                                                              & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slti = (IData)(
                                                            (0x2013U 
                                                             == 
                                                             (0x707fU 
                                                              & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sltiu 
        = (IData)((0x3013U == (0x707fU & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_xori = (IData)(
                                                            (0x4013U 
                                                             == 
                                                             (0x707fU 
                                                              & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srli = (IData)(
                                                            (0x5013U 
                                                             == 
                                                             (0xfc00707fU 
                                                              & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srai = (IData)(
                                                            (0x40005013U 
                                                             == 
                                                             (0xfc00707fU 
                                                              & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_ori = (IData)(
                                                           (0x6013U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slliw 
        = (IData)((0x101bU == (0x707fU & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srliw 
        = (IData)((0x501bU == (0xfc00707fU & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sraiw 
        = (IData)((0x4000501bU == (0xfc00707fU & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sll = (IData)(
                                                           (0x1033U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slt = (IData)(
                                                           (0x2033U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sltu = (IData)(
                                                            (0x3033U 
                                                             == 
                                                             (0x707fU 
                                                              & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_xor = (IData)(
                                                           (0x4033U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srl = (IData)(
                                                           (0x5033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sra = (IData)(
                                                           (0x40005033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_or = (IData)(
                                                          (0x6033U 
                                                           == 
                                                           (0x707fU 
                                                            & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sllw = (IData)(
                                                            (0x103bU 
                                                             == 
                                                             (0x707fU 
                                                              & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srlw = (IData)(
                                                            (0x503bU 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sraw = (IData)(
                                                            (0x4000503bU 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addi = (IData)(
                                                            (0x13U 
                                                             == 
                                                             (0x707fU 
                                                              & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addiw 
        = (IData)((0x1bU == (0x707fU & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_add = (IData)(
                                                           (0x33U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addw = (IData)(
                                                            (0x3bU 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bltu = (IData)(
                                                            (0x6063U 
                                                             == 
                                                             (0x707fU 
                                                              & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bgeu = (IData)(
                                                            (0x7063U 
                                                             == 
                                                             (0x707fU 
                                                              & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_beq = (IData)(
                                                           (0x63U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bne = (IData)(
                                                           (0x1063U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_blt = (IData)(
                                                           (0x4063U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bge = (IData)(
                                                           (0x5063U 
                                                            == 
                                                            (0x707fU 
                                                             & vlTOPp->SimTop__DOT__id_inst)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm 
        = ((IData)((0x4073U == (0x407fU & vlTOPp->SimTop__DOT__id_inst))) 
           & (0U != (7U & (vlTOPp->SimTop__DOT__id_inst 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg 
        = ((IData)((0x73U == (0x407fU & vlTOPp->SimTop__DOT__id_inst))) 
           & (0U != (7U & (vlTOPp->SimTop__DOT__id_inst 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__bj_data = (
                                                   (0xe7U 
                                                    & (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__bj_data)) 
                                                   | ((0x10U 
                                                       & ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res) 
                                                          << 4U)) 
                                                      | (8U 
                                                         & ((~ (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res)) 
                                                            << 3U))));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__bj_data = (
                                                   (0x9fU 
                                                    & (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__bj_data)) 
                                                   | (0x40U 
                                                      | (0x20U 
                                                         & ((~ (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res)) 
                                                            << 5U))));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__bj_data = (
                                                   (0xf8U 
                                                    & (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__bj_data)) 
                                                   | ((4U 
                                                       & ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res) 
                                                          << 2U)) 
                                                      | (((IData)(
                                                                  (0U 
                                                                   != vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res)) 
                                                          << 1U) 
                                                         | (1U 
                                                            & (~ (IData)(
                                                                         (0U 
                                                                          != vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res)))))));
    vlTOPp->SimTop__DOT__id_load_info = ((0xfU & (IData)(vlTOPp->SimTop__DOT__id_load_info)) 
                                         | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lwu) 
                                             << 6U) 
                                            | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lhu) 
                                                << 5U) 
                                               | ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lbu) 
                                                  << 4U))));
    vlTOPp->SimTop__DOT__id_load_info = ((0x70U & (IData)(vlTOPp->SimTop__DOT__id_load_info)) 
                                         | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_ld) 
                                             << 3U) 
                                            | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lw) 
                                                << 2U) 
                                               | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lh) 
                                                   << 1U) 
                                                  | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lb)))));
    vlTOPp->SimTop__DOT__id_alu_info = ((0xfbfU & (IData)(vlTOPp->SimTop__DOT__id_alu_info)) 
                                        | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_and) 
                                            | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_andi)) 
                                           << 6U));
    vlTOPp->SimTop__DOT__id_alu_info = ((0xffdU & (IData)(vlTOPp->SimTop__DOT__id_alu_info)) 
                                        | ((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sub) 
                                             | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_subw)) 
                                            | (0x63U 
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                           << 1U));
    vlTOPp->SimTop__DOT__id_alu_info = ((0xf7fU & (IData)(vlTOPp->SimTop__DOT__id_alu_info)) 
                                        | (((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sll) 
                                              | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slli)) 
                                             | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sllw)) 
                                            | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slliw)) 
                                           << 7U));
    vlTOPp->SimTop__DOT__id_alu_info = ((0xeffU & (IData)(vlTOPp->SimTop__DOT__id_alu_info)) 
                                        | (((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srl) 
                                              | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srli)) 
                                             | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srlw)) 
                                            | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srliw)) 
                                           << 8U));
    vlTOPp->SimTop__DOT__id_alu_info = ((0xdffU & (IData)(vlTOPp->SimTop__DOT__id_alu_info)) 
                                        | (((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sra) 
                                              | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srai)) 
                                             | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sraw)) 
                                            | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sraiw)) 
                                           << 9U));
    vlTOPp->SimTop__DOT__id_alu_info = ((0xffeU & (IData)(vlTOPp->SimTop__DOT__id_alu_info)) 
                                        | ((((((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_add) 
                                                   | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addi)) 
                                                  | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addw)) 
                                                 | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addiw)) 
                                                | (0x17U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SimTop__DOT__id_inst))) 
                                               | (0x37U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                              | (3U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->SimTop__DOT__id_inst))) 
                                             | (0x23U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->SimTop__DOT__id_inst))) 
                                            | (0x6fU 
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                           | (0x67U 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__id_inst))));
    vlTOPp->SimTop__DOT__id_bj_info = ((0xfU & (IData)(vlTOPp->SimTop__DOT__id_bj_info)) 
                                       | (((0x6fU == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst)) 
                                           << 7U) | 
                                          (((0x67U 
                                             == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__id_inst)) 
                                            << 6U) 
                                           | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bgeu) 
                                               << 5U) 
                                              | ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bltu) 
                                                 << 4U)))));
    vlTOPp->SimTop__DOT__id_alu_info = ((0xff7U & (IData)(vlTOPp->SimTop__DOT__id_alu_info)) 
                                        | (((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sltu) 
                                              | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sltiu)) 
                                             | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bltu)) 
                                            | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bgeu)) 
                                           << 3U));
    vlTOPp->SimTop__DOT__id_alu_info = ((0xfefU & (IData)(vlTOPp->SimTop__DOT__id_alu_info)) 
                                        | (((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_xor) 
                                              | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_xori)) 
                                             | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_beq)) 
                                            | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bne)) 
                                           << 4U));
    vlTOPp->SimTop__DOT__id_bj_info = ((0xf0U & (IData)(vlTOPp->SimTop__DOT__id_bj_info)) 
                                       | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bge) 
                                           << 3U) | 
                                          (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_blt) 
                                            << 2U) 
                                           | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bne) 
                                               << 1U) 
                                              | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_beq)))));
    vlTOPp->SimTop__DOT__id_alu_info = ((0xffbU & (IData)(vlTOPp->SimTop__DOT__id_alu_info)) 
                                        | (((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slt) 
                                              | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slti)) 
                                             | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_blt)) 
                                            | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bge)) 
                                           << 2U));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrwi 
        = ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm) 
           & (5U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrsi 
        = ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm) 
           & (6U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrci 
        = ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm) 
           & (7U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrw 
        = ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg) 
           & (1U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrs 
        = ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg) 
           & (2U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrc 
        = ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg) 
           & (3U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__id_alu_info = ((0xfdfU & (IData)(vlTOPp->SimTop__DOT__id_alu_info)) 
                                        | (((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_or) 
                                              | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_ori)) 
                                             | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrs)) 
                                            | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrsi)) 
                                           << 5U));
    vlTOPp->SimTop__DOT__id_alu_info = ((0x3ffU & (IData)(vlTOPp->SimTop__DOT__id_alu_info)) 
                                        | ((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrw) 
                                             | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrwi)) 
                                            << 0xbU) 
                                           | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrc) 
                                               | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrci)) 
                                              << 0xaU)));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_vld = 
        (((((((((((((((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lb) 
                          | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lh)) 
                         | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lw)) 
                        | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_ld)) 
                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lbu)) 
                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lhu)) 
                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lwu)) 
                    | ((IData)((0xfU == (0x707fU & vlTOPp->SimTop__DOT__id_inst))) 
                       | (IData)((0x100fU == (0x707fU 
                                              & vlTOPp->SimTop__DOT__id_inst))))) 
                   | (((((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addi) 
                             | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slli)) 
                            | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slti)) 
                           | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sltiu)) 
                          | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_xori)) 
                         | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srli)) 
                        | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srai)) 
                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_ori)) 
                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_andi))) 
                  | (0x17U == (0x7fU & vlTOPp->SimTop__DOT__id_inst))) 
                 | ((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addiw) 
                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slliw)) 
                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srliw)) 
                    | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sraiw))) 
                | ((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sb) 
                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sh)) 
                    | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sw)) 
                   | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sd))) 
               | ((((((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_add) 
                          | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sub)) 
                         | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sll)) 
                        | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slt)) 
                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sltu)) 
                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_xor)) 
                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srl)) 
                    | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sra)) 
                   | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_or)) 
                  | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_and))) 
              | (0x37U == (0x7fU & vlTOPp->SimTop__DOT__id_inst))) 
             | (((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addw) 
                   | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_subw)) 
                  | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sllw)) 
                 | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srlw)) 
                | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sraw))) 
            | ((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_beq) 
                   | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bne)) 
                  | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_blt)) 
                 | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bge)) 
                | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bltu)) 
               | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bgeu))) 
           | ((0x67U == (0x7fU & vlTOPp->SimTop__DOT__id_inst)) 
              | (0x6fU == (0x7fU & vlTOPp->SimTop__DOT__id_inst)))) 
          | ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_excp) 
             & (((0U == (0xfffU & (vlTOPp->SimTop__DOT__id_inst 
                                   >> 0x14U))) | (1U 
                                                  == 
                                                  (0xfffU 
                                                   & (vlTOPp->SimTop__DOT__id_inst 
                                                      >> 0x14U)))) 
                | (0x102U == (0xfffU & (vlTOPp->SimTop__DOT__id_inst 
                                        >> 0x14U)))))) 
         | ((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrw) 
                | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrs)) 
               | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrc)) 
              | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrwi)) 
             | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrsi)) 
            | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrci)));
}

VL_INLINE_OPT void VSimTop::_combo__TOP__3(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_combo__TOP__3\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SimTop__DOT__wb_reg_wr_data = ((- (QData)((IData)(
                                                              (1U 
                                                               & (~ (IData)(vlTOPp->reset)))))) 
                                           & ((((- (QData)((IData)(
                                                                   (1U 
                                                                    & ((IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl) 
                                                                       >> 1U))))) 
                                                & vlTOPp->SimTop__DOT__wb_ram_data) 
                                               | ((- (QData)((IData)(
                                                                     (1U 
                                                                      & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl))))) 
                                                  & vlTOPp->SimTop__DOT__wb_ex_data)) 
                                              | ((- (QData)((IData)(
                                                                    (1U 
                                                                     & ((IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl) 
                                                                        >> 2U))))) 
                                                 & vlTOPp->SimTop__DOT__wb_csr_data)));
    vlTOPp->SimTop__DOT__mem_ram_data = ((- (QData)((IData)(
                                                            (1U 
                                                             & (~ (IData)(vlTOPp->reset)))))) 
                                         & ((((((((- (QData)((IData)(
                                                                     (1U 
                                                                      & (IData)(vlTOPp->SimTop__DOT__mem_load_info))))) 
                                                  & ((0xffffffffffffff00ULL 
                                                      & ((- (QData)((IData)(
                                                                            (1U 
                                                                             & (IData)(
                                                                                (vlTOPp->SimTop__DOT__Mem_stage__DOT__mem_part 
                                                                                >> 7U)))))) 
                                                         << 8U)) 
                                                     | (QData)((IData)(
                                                                       (0xffU 
                                                                        & (IData)(vlTOPp->SimTop__DOT__Mem_stage__DOT__mem_part)))))) 
                                                 | ((- (QData)((IData)(
                                                                       (1U 
                                                                        & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                                                           >> 1U))))) 
                                                    & ((0xffffffffffff0000ULL 
                                                        & ((- (QData)((IData)(
                                                                              (1U 
                                                                               & (IData)(
                                                                                (vlTOPp->SimTop__DOT__Mem_stage__DOT__mem_part 
                                                                                >> 0xfU)))))) 
                                                           << 0x10U)) 
                                                       | (QData)((IData)(
                                                                         (0xffffU 
                                                                          & (IData)(vlTOPp->SimTop__DOT__Mem_stage__DOT__mem_part))))))) 
                                                | ((- (QData)((IData)(
                                                                      (1U 
                                                                       & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                                                          >> 2U))))) 
                                                   & (((QData)((IData)(
                                                                       (- (IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlTOPp->SimTop__DOT__Mem_stage__DOT__mem_part 
                                                                                >> 0x1fU))))))) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(vlTOPp->SimTop__DOT__Mem_stage__DOT__mem_part))))) 
                                               | ((- (QData)((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                                                         >> 3U))))) 
                                                  & vlTOPp->SimTop__DOT__Mem_stage__DOT__mem_part)) 
                                              | ((- (QData)((IData)(
                                                                    (1U 
                                                                     & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                                                        >> 4U))))) 
                                                 & (QData)((IData)(
                                                                   (0xffU 
                                                                    & (IData)(vlTOPp->SimTop__DOT__Mem_stage__DOT__mem_part)))))) 
                                             | ((- (QData)((IData)(
                                                                   (1U 
                                                                    & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                                                       >> 5U))))) 
                                                & (QData)((IData)(
                                                                  (0xffffU 
                                                                   & (IData)(vlTOPp->SimTop__DOT__Mem_stage__DOT__mem_part)))))) 
                                            | ((- (QData)((IData)(
                                                                  (1U 
                                                                   & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                                                      >> 6U))))) 
                                               & (QData)((IData)(vlTOPp->SimTop__DOT__Mem_stage__DOT__mem_part)))));
    vlTOPp->SimTop__DOT__rs2_r_ena = ((~ (IData)(vlTOPp->reset)) 
                                      & ((((0x33U == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst)) 
                                           | (0x3bU 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__id_inst))) 
                                          | (0x23U 
                                             == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__id_inst))) 
                                         | (0x63U == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output 
        = ((- (QData)((IData)((1U & (~ (IData)(vlTOPp->reset)))))) 
           & ((((((((((((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                                  >> 7U))))) 
                        & vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res) 
                       | ((- (QData)((IData)((1U & 
                                              ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                               >> 8U))))) 
                          & vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res)) 
                      | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                                   >> 9U))))) 
                         & ((vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res 
                             & vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask) 
                            | (((IData)(vlTOPp->SimTop__DOT__ex_is_word_opt)
                                 ? (QData)((IData)(
                                                   (- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                          >> 0x1fU)))))))
                                 : (- (QData)((IData)(
                                                      (1U 
                                                       & (IData)(
                                                                 (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                                  >> 0x3fU))))))) 
                               & (~ vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask))))) 
                     | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                                  >> 2U))))) 
                        & vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res)) 
                    | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                                 >> 3U))))) 
                       & vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res)) 
                   | ((- (QData)((IData)((0U != (3U 
                                                 & (IData)(vlTOPp->SimTop__DOT__ex_alu_info)))))) 
                      & (((QData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res[1U])) 
                          << 0x20U) | (QData)((IData)(
                                                      vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res[0U]))))) 
                  | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                               >> 4U))))) 
                     & vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res)) 
                 | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                              >> 5U))))) 
                    & (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                       | vlTOPp->SimTop__DOT__Ex_stage__DOT__op2))) 
                | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                             >> 6U))))) 
                   & (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                      & vlTOPp->SimTop__DOT__Ex_stage__DOT__op2))) 
               | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                            >> 0xaU))))) 
                  & ((~ vlTOPp->SimTop__DOT__Ex_stage__DOT__op1) 
                     & vlTOPp->SimTop__DOT__Ex_stage__DOT__op2))) 
              | ((- (QData)((IData)((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                           >> 0xbU))))) 
                 & vlTOPp->SimTop__DOT__Ex_stage__DOT__op2)));
    vlTOPp->SimTop__DOT__id_reg_wr_ena = ((~ (IData)(vlTOPp->reset)) 
                                          & ((((((((((((3U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->SimTop__DOT__id_inst)) 
                                                       | (0xfU 
                                                          == 
                                                          (0x7fU 
                                                           & vlTOPp->SimTop__DOT__id_inst))) 
                                                      | (0x13U 
                                                         == 
                                                         (0x7fU 
                                                          & vlTOPp->SimTop__DOT__id_inst))) 
                                                     | (0x17U 
                                                        == 
                                                        (0x7fU 
                                                         & vlTOPp->SimTop__DOT__id_inst))) 
                                                    | (0x1bU 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->SimTop__DOT__id_inst))) 
                                                   | (0x33U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->SimTop__DOT__id_inst))) 
                                                  | (0x37U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->SimTop__DOT__id_inst))) 
                                                 | (0x3bU 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->SimTop__DOT__id_inst))) 
                                                | (0x67U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SimTop__DOT__id_inst))) 
                                               | (0x6fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                              | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm)) 
                                             | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg)));
    vlTOPp->SimTop__DOT__rs1_r_ena = ((~ (IData)(vlTOPp->reset)) 
                                      & (((((((((((3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SimTop__DOT__id_inst)) 
                                                  | (0xfU 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->SimTop__DOT__id_inst))) 
                                                 | (0x13U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->SimTop__DOT__id_inst))) 
                                                | (0x1bU 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SimTop__DOT__id_inst))) 
                                               | (0x23U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                              | (0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->SimTop__DOT__id_inst))) 
                                             | (0x3bU 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->SimTop__DOT__id_inst))) 
                                            | (0x63U 
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                           | (0x67U 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__id_inst))) 
                                          | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg)) 
                                         | (0x7bU == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))));
    vlTOPp->SimTop__DOT__bj_ena = (((~ (IData)(vlTOPp->reset)) 
                                    & (IData)(vlTOPp->SimTop__DOT__ex_valid)) 
                                   & (0U != ((IData)(vlTOPp->SimTop__DOT__ex_bj_info) 
                                             & (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__bj_data))));
    vlTOPp->SimTop__DOT__rs2_r_addr = (0x1fU & ((- (IData)((IData)(vlTOPp->SimTop__DOT__rs2_r_ena))) 
                                                & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0x14U)));
    vlTOPp->SimTop__DOT__id_reg_wr_addr = ((IData)(vlTOPp->SimTop__DOT__id_reg_wr_ena)
                                            ? (0x1fU 
                                               & (vlTOPp->SimTop__DOT__id_inst 
                                                  >> 7U))
                                            : 0U);
    vlTOPp->SimTop__DOT__rs1_r_addr = (0x1fU & ((- (IData)((IData)(vlTOPp->SimTop__DOT__rs1_r_ena))) 
                                                & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0xfU)));
    vlTOPp->SimTop__DOT__if_pc = (((0U != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info)) 
                                   | (IData)(vlTOPp->SimTop__DOT__excp_exit))
                                   ? (QData)((IData)(
                                                     (0xffffU 
                                                      & ((0xfffcU 
                                                          & ((IData)(
                                                                     (- (QData)((IData)(
                                                                                (0U 
                                                                                != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info)))))) 
                                                             & (((IData)(
                                                                         (- (QData)((IData)(
                                                                                (0U 
                                                                                == 
                                                                                (3U 
                                                                                & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec))))))) 
                                                                 & ((IData)(
                                                                            (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec 
                                                                             >> 2U)) 
                                                                    << 2U)) 
                                                                | ((IData)(
                                                                           (- (QData)((IData)(
                                                                                (1U 
                                                                                == 
                                                                                (3U 
                                                                                & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec))))))) 
                                                                   & (((IData)(
                                                                               (0xfffffffffffffffULL 
                                                                                & (- (QData)((IData)(
                                                                                (0U 
                                                                                != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))))))) 
                                                                       & (IData)(
                                                                                (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec 
                                                                                >> 2U))) 
                                                                      << 2U))))) 
                                                         | ((IData)(
                                                                    (- (QData)((IData)(vlTOPp->SimTop__DOT__excp_exit)))) 
                                                            & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mepc))))))
                                   : ((IData)(vlTOPp->SimTop__DOT__bj_ena)
                                       ? (vlTOPp->SimTop__DOT__ex_jmp_imm 
                                          + ((0x40U 
                                              & (IData)(vlTOPp->SimTop__DOT__ex_bj_info))
                                              ? vlTOPp->SimTop__DOT__rs1_forward
                                              : vlTOPp->SimTop__DOT__ex_pc))
                                       : (4ULL + vlTOPp->SimTop__DOT__id_pc)));
    vlTOPp->SimTop__DOT__r_data2 = ((- (QData)((IData)(
                                                       ((~ (IData)(vlTOPp->reset)) 
                                                        & (IData)(vlTOPp->SimTop__DOT__rs2_r_ena))))) 
                                    & ((((IData)(vlTOPp->SimTop__DOT__rs2_r_addr) 
                                         == (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)) 
                                        & (0U != (IData)(vlTOPp->SimTop__DOT__rs2_r_addr)))
                                        ? vlTOPp->SimTop__DOT__wb_reg_wr_data
                                        : vlTOPp->SimTop__DOT__Regfile__DOT__regs
                                       [vlTOPp->SimTop__DOT__rs2_r_addr]));
    vlTOPp->SimTop__DOT__stall = ((IData)(vlTOPp->SimTop__DOT__ex_ram_rd_ena) 
                                  & ((((IData)(vlTOPp->SimTop__DOT__ex_reg_wr_addr) 
                                       == (IData)(vlTOPp->SimTop__DOT__rs1_r_addr)) 
                                      & (0U != (IData)(vlTOPp->SimTop__DOT__rs1_r_addr))) 
                                     | (((IData)(vlTOPp->SimTop__DOT__ex_reg_wr_addr) 
                                         == (IData)(vlTOPp->SimTop__DOT__rs2_r_addr)) 
                                        & (0U != (IData)(vlTOPp->SimTop__DOT__rs2_r_addr)))));
    vlTOPp->SimTop__DOT__r_data1 = ((- (QData)((IData)(
                                                       ((~ (IData)(vlTOPp->reset)) 
                                                        & (IData)(vlTOPp->SimTop__DOT__rs1_r_ena))))) 
                                    & ((((IData)(vlTOPp->SimTop__DOT__rs1_r_addr) 
                                         == (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)) 
                                        & (0U != (IData)(vlTOPp->SimTop__DOT__rs1_r_addr)))
                                        ? vlTOPp->SimTop__DOT__wb_reg_wr_data
                                        : vlTOPp->SimTop__DOT__Regfile__DOT__regs
                                       [vlTOPp->SimTop__DOT__rs1_r_addr]));
    vlTOPp->SimTop__DOT__id_op2 = ((- (QData)((IData)(
                                                      (1U 
                                                       & (~ (IData)(vlTOPp->reset)))))) 
                                   & (((((((((((((((- (QData)((IData)(
                                                                      (3U 
                                                                       == 
                                                                       (0x7fU 
                                                                        & vlTOPp->SimTop__DOT__id_inst))))) 
                                                   & ((0xfffffffffffff000ULL 
                                                       & ((- (QData)((IData)(
                                                                             (1U 
                                                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                                                >> 0x1fU))))) 
                                                          << 0xcU)) 
                                                      | (QData)((IData)(
                                                                        (0xfffU 
                                                                         & (vlTOPp->SimTop__DOT__id_inst 
                                                                            >> 0x14U)))))) 
                                                  | ((- (QData)((IData)(
                                                                        (0xfU 
                                                                         == 
                                                                         (0x7fU 
                                                                          & vlTOPp->SimTop__DOT__id_inst))))) 
                                                     & ((0xfffffffffffff000ULL 
                                                         & ((- (QData)((IData)(
                                                                               (1U 
                                                                                & (vlTOPp->SimTop__DOT__id_inst 
                                                                                >> 0x1fU))))) 
                                                            << 0xcU)) 
                                                        | (QData)((IData)(
                                                                          (0xfffU 
                                                                           & (vlTOPp->SimTop__DOT__id_inst 
                                                                              >> 0x14U))))))) 
                                                 | ((- (QData)((IData)(
                                                                       (0x13U 
                                                                        == 
                                                                        (0x7fU 
                                                                         & vlTOPp->SimTop__DOT__id_inst))))) 
                                                    & ((0xfffffffffffff000ULL 
                                                        & ((- (QData)((IData)(
                                                                              (1U 
                                                                               & (vlTOPp->SimTop__DOT__id_inst 
                                                                                >> 0x1fU))))) 
                                                           << 0xcU)) 
                                                       | (QData)((IData)(
                                                                         (0xfffU 
                                                                          & (vlTOPp->SimTop__DOT__id_inst 
                                                                             >> 0x14U))))))) 
                                                | ((- (QData)((IData)(
                                                                      (0x17U 
                                                                       == 
                                                                       (0x7fU 
                                                                        & vlTOPp->SimTop__DOT__id_inst))))) 
                                                   & (((QData)((IData)(
                                                                       (- (IData)(
                                                                                (1U 
                                                                                & (vlTOPp->SimTop__DOT__id_inst 
                                                                                >> 0x1fU)))))) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        (0xfffff000U 
                                                                         & vlTOPp->SimTop__DOT__id_inst)))))) 
                                               | ((- (QData)((IData)(
                                                                     (0x1bU 
                                                                      == 
                                                                      (0x7fU 
                                                                       & vlTOPp->SimTop__DOT__id_inst))))) 
                                                  & ((0xfffffffffffff000ULL 
                                                      & ((- (QData)((IData)(
                                                                            (1U 
                                                                             & (vlTOPp->SimTop__DOT__id_inst 
                                                                                >> 0x1fU))))) 
                                                         << 0xcU)) 
                                                     | (QData)((IData)(
                                                                       (0xfffU 
                                                                        & (vlTOPp->SimTop__DOT__id_inst 
                                                                           >> 0x14U))))))) 
                                              | ((- (QData)((IData)(
                                                                    (0x23U 
                                                                     == 
                                                                     (0x7fU 
                                                                      & vlTOPp->SimTop__DOT__id_inst))))) 
                                                 & ((0xfffffffffffff000ULL 
                                                     & ((- (QData)((IData)(
                                                                           (1U 
                                                                            & ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__immS) 
                                                                               >> 0xbU))))) 
                                                        << 0xcU)) 
                                                    | (QData)((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__immS))))) 
                                             | ((- (QData)((IData)(
                                                                   (0x33U 
                                                                    == 
                                                                    (0x7fU 
                                                                     & vlTOPp->SimTop__DOT__id_inst))))) 
                                                & vlTOPp->SimTop__DOT__r_data2)) 
                                            | ((- (QData)((IData)(
                                                                  (0x37U 
                                                                   == 
                                                                   (0x7fU 
                                                                    & vlTOPp->SimTop__DOT__id_inst))))) 
                                               & (((QData)((IData)(
                                                                   (- (IData)(
                                                                              (1U 
                                                                               & (vlTOPp->SimTop__DOT__id_inst 
                                                                                >> 0x1fU)))))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    (0xfffff000U 
                                                                     & vlTOPp->SimTop__DOT__id_inst)))))) 
                                           | ((- (QData)((IData)(
                                                                 (0x3bU 
                                                                  == 
                                                                  (0x7fU 
                                                                   & vlTOPp->SimTop__DOT__id_inst))))) 
                                              & vlTOPp->SimTop__DOT__r_data2)) 
                                          | ((- (QData)((IData)(
                                                                (0x63U 
                                                                 == 
                                                                 (0x7fU 
                                                                  & vlTOPp->SimTop__DOT__id_inst))))) 
                                             & vlTOPp->SimTop__DOT__r_data2)) 
                                         | (4ULL & 
                                            (- (QData)((IData)(
                                                               (0x67U 
                                                                == 
                                                                (0x7fU 
                                                                 & vlTOPp->SimTop__DOT__id_inst))))))) 
                                        | (4ULL & (- (QData)((IData)(
                                                                     (0x6fU 
                                                                      == 
                                                                      (0x7fU 
                                                                       & vlTOPp->SimTop__DOT__id_inst))))))) 
                                       | ((- (QData)((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm))) 
                                          & vlTOPp->SimTop__DOT__id_csr_data)) 
                                      | ((- (QData)((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg))) 
                                         & vlTOPp->SimTop__DOT__id_csr_data)));
    vlTOPp->SimTop__DOT__id_allowin = (1U & ((~ (IData)(vlTOPp->SimTop__DOT__id_valid)) 
                                             | (~ (IData)(vlTOPp->SimTop__DOT__stall))));
    vlTOPp->SimTop__DOT__id_to_ex_valid = ((IData)(vlTOPp->SimTop__DOT__id_valid) 
                                           & (~ (IData)(vlTOPp->SimTop__DOT__stall)));
    vlTOPp->SimTop__DOT__id_op1 = ((- (QData)((IData)(
                                                      (1U 
                                                       & (~ (IData)(vlTOPp->reset)))))) 
                                   & ((((((((((((((- (QData)((IData)(
                                                                     (3U 
                                                                      == 
                                                                      (0x7fU 
                                                                       & vlTOPp->SimTop__DOT__id_inst))))) 
                                                  | (- (QData)((IData)(
                                                                       (0xfU 
                                                                        == 
                                                                        (0x7fU 
                                                                         & vlTOPp->SimTop__DOT__id_inst)))))) 
                                                 | (- (QData)((IData)(
                                                                      (0x13U 
                                                                       == 
                                                                       (0x7fU 
                                                                        & vlTOPp->SimTop__DOT__id_inst)))))) 
                                                & vlTOPp->SimTop__DOT__r_data1) 
                                               | ((- (QData)((IData)(
                                                                     (0x17U 
                                                                      == 
                                                                      (0x7fU 
                                                                       & vlTOPp->SimTop__DOT__id_inst))))) 
                                                  & vlTOPp->SimTop__DOT__id_pc)) 
                                              | ((- (QData)((IData)(
                                                                    (0x1bU 
                                                                     == 
                                                                     (0x7fU 
                                                                      & vlTOPp->SimTop__DOT__id_inst))))) 
                                                 & vlTOPp->SimTop__DOT__r_data1)) 
                                             | ((- (QData)((IData)(
                                                                   (0x23U 
                                                                    == 
                                                                    (0x7fU 
                                                                     & vlTOPp->SimTop__DOT__id_inst))))) 
                                                & vlTOPp->SimTop__DOT__r_data1)) 
                                            | ((- (QData)((IData)(
                                                                  (0x33U 
                                                                   == 
                                                                   (0x7fU 
                                                                    & vlTOPp->SimTop__DOT__id_inst))))) 
                                               & vlTOPp->SimTop__DOT__r_data1)) 
                                           | ((- (QData)((IData)(
                                                                 (0x3bU 
                                                                  == 
                                                                  (0x7fU 
                                                                   & vlTOPp->SimTop__DOT__id_inst))))) 
                                              & vlTOPp->SimTop__DOT__r_data1)) 
                                          | ((- (QData)((IData)(
                                                                (0x63U 
                                                                 == 
                                                                 (0x7fU 
                                                                  & vlTOPp->SimTop__DOT__id_inst))))) 
                                             & vlTOPp->SimTop__DOT__r_data1)) 
                                         | ((- (QData)((IData)(
                                                               (0x67U 
                                                                == 
                                                                (0x7fU 
                                                                 & vlTOPp->SimTop__DOT__id_inst))))) 
                                            & vlTOPp->SimTop__DOT__id_pc)) 
                                        | ((- (QData)((IData)(
                                                              (0x6fU 
                                                               == 
                                                               (0x7fU 
                                                                & vlTOPp->SimTop__DOT__id_inst))))) 
                                           & vlTOPp->SimTop__DOT__id_pc)) 
                                       | ((- (QData)((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm))) 
                                          & (QData)((IData)(vlTOPp->SimTop__DOT__rs1_r_addr)))) 
                                      | ((- (QData)((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg))) 
                                         & vlTOPp->SimTop__DOT__r_data1)));
}

void VSimTop::_eval(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_eval\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
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
