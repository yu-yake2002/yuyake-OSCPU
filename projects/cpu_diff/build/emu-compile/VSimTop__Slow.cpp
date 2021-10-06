// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSimTop.h for the primary calling header

#include "VSimTop.h"
#include "VSimTop__Syms.h"

#include "verilated_dpi.h"

//==========

VSimTop::VSimTop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    VSimTop__Syms* __restrict vlSymsp = __VlSymsp = new VSimTop__Syms(_vcontextp__, this, name());
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(__PVT____024unit, VSimTop___024unit);
    // Reset internal values

    // Reset structure values
    _ctor_var_reset(this);
}

void VSimTop::__Vconfigure(VSimTop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-9);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

VSimTop::~VSimTop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void VSimTop::_settle__TOP__1(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_settle__TOP__1\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SimTop__DOT__inst_opcode = (0xf1U & (IData)(vlTOPp->SimTop__DOT__inst_opcode));
    vlTOPp->SimTop__DOT__inst_opcode = (0x1fU & (IData)(vlTOPp->SimTop__DOT__inst_opcode));
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

void VSimTop::_eval_initial(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_eval_initial\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VSimTop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::final\n"); );
    // Variables
    VSimTop__Syms* __restrict vlSymsp = this->__VlSymsp;
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VSimTop::_eval_settle(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_eval_settle\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void VSimTop::_ctor_var_reset(VSimTop* self) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_ctor_var_reset\n"); );
    // Body
    if (false && self) {}  // Prevent unused
    self->clock = VL_RAND_RESET_I(1);
    self->reset = VL_RAND_RESET_I(1);
    self->io_logCtrl_log_begin = VL_RAND_RESET_Q(64);
    self->io_logCtrl_log_end = VL_RAND_RESET_Q(64);
    self->io_logCtrl_log_level = VL_RAND_RESET_Q(64);
    self->io_perfInfo_clean = VL_RAND_RESET_I(1);
    self->io_perfInfo_dump = VL_RAND_RESET_I(1);
    self->io_uart_out_valid = VL_RAND_RESET_I(1);
    self->io_uart_out_ch = VL_RAND_RESET_I(8);
    self->io_uart_in_valid = VL_RAND_RESET_I(1);
    self->io_uart_in_ch = VL_RAND_RESET_I(8);
    self->SimTop__DOT__pc = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__inst = VL_RAND_RESET_I(32);
    self->SimTop__DOT__rd_w_ena = VL_RAND_RESET_I(1);
    self->SimTop__DOT__rd_w_addr = VL_RAND_RESET_I(5);
    self->SimTop__DOT__inst_type = VL_RAND_RESET_I(5);
    self->SimTop__DOT__inst_opcode = VL_RAND_RESET_I(8);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        self->SimTop__DOT__regs[__Vi0] = VL_RAND_RESET_Q(64);
    }
    self->SimTop__DOT__rd_data = VL_RAND_RESET_Q(64);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        self->SimTop__DOT____Vcellout__Regfile__regs_o[__Vi0] = VL_RAND_RESET_Q(64);
    }
    self->SimTop__DOT__cmt_wen = VL_RAND_RESET_I(1);
    self->SimTop__DOT__cmt_wdest = VL_RAND_RESET_I(8);
    self->SimTop__DOT__cmt_wdata = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__cmt_pc = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__cmt_inst = VL_RAND_RESET_I(32);
    self->SimTop__DOT__cmt_valid = VL_RAND_RESET_I(1);
    self->SimTop__DOT__trap = VL_RAND_RESET_I(1);
    self->SimTop__DOT__trap_code = VL_RAND_RESET_I(8);
    self->SimTop__DOT__cycleCnt = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__instrCnt = VL_RAND_RESET_Q(64);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        self->SimTop__DOT__regs_diff[__Vi0] = VL_RAND_RESET_Q(64);
    }
    self->SimTop__DOT__inst_valid = VL_RAND_RESET_I(1);
    self->SimTop__DOT__If_stage__DOT__rdata = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__Id_stage__DOT__inst_addi = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        self->SimTop__DOT__Regfile__DOT__regs[__Vi0] = VL_RAND_RESET_Q(64);
    }
    self->__Vfunc_ram_read_helper__0__Vfuncout = 0;
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
