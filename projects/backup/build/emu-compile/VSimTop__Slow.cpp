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
    // Variables
    VlWide<3>/*95:0*/ __Vtemp5;
    VlWide<3>/*95:0*/ __Vtemp9;
    VlWide<3>/*95:0*/ __Vtemp10;
    VlWide<3>/*95:0*/ __Vtemp13;
    VlWide<3>/*95:0*/ __Vtemp14;
    // Body
    vlTOPp->SimTop__DOT__Ex_stage__DOT__bj_data = (0x80U 
                                                   | (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__bj_data));
    vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info 
        = (((IData)(vlTOPp->SimTop__DOT__if_excp) | (IData)(vlTOPp->SimTop__DOT__id_excp)) 
           | (IData)(vlTOPp->SimTop__DOT__mem_excp));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_shift 
        = (IData)((0U != (0x380U & (IData)(vlTOPp->SimTop__DOT__ex_alu_info))));
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
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub 
        = (IData)((0U != (0xeU & (IData)(vlTOPp->SimTop__DOT__ex_alu_info))));
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
    vlTOPp->SimTop__DOT__ex_ram_rd_ena = ((IData)(vlTOPp->SimTop__DOT__ex_ram_rd_ena_r) 
                                          & (IData)(vlTOPp->SimTop__DOT__ex_valid));
    vlSymsp->TOP____024unit.__Vdpiimwrap_ram_read_helper_TOP____024unit(1U, 
                                                                        ((vlTOPp->SimTop__DOT__id_pc 
                                                                          - 0x80000000ULL) 
                                                                         >> 3U), vlTOPp->__Vfunc_ram_read_helper__0__Vfuncout);
    vlTOPp->SimTop__DOT__RAM_1W2R__DOT__inst_2 = vlTOPp->__Vfunc_ram_read_helper__0__Vfuncout;
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
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub 
        = (1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                 | (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)));
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
    vlTOPp->SimTop__DOT__id_inst = ((1U & (IData)((vlTOPp->SimTop__DOT__id_pc 
                                                   >> 2U)))
                                     ? (IData)((vlTOPp->SimTop__DOT__RAM_1W2R__DOT__inst_2 
                                                >> 0x20U))
                                     : (IData)(vlTOPp->SimTop__DOT__RAM_1W2R__DOT__inst_2));
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
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm 
        = ((IData)((0x4073U == (0x407fU & vlTOPp->SimTop__DOT__id_inst))) 
           & (0U != (7U & (vlTOPp->SimTop__DOT__id_inst 
                           >> 0xcU))));
    vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg 
        = ((IData)((0x73U == (0x407fU & vlTOPp->SimTop__DOT__id_inst))) 
           & (0U != (7U & (vlTOPp->SimTop__DOT__id_inst 
                           >> 0xcU))));
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
    vlTOPp->SimTop__DOT__rs2_r_addr = (0x1fU & ((- (IData)((IData)(vlTOPp->SimTop__DOT__rs2_r_ena))) 
                                                & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0x14U)));
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
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask 
        = (((IData)(vlTOPp->SimTop__DOT__ex_is_word_opt)
             ? 0xffffffffULL : 0xffffffffffffffffULL) 
           >> (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in2));
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res 
        = (vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in1 
           << (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in2));
    __Vtemp5[0U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                    & (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__op1));
    __Vtemp5[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                    & (IData)((vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                               >> 0x20U)));
    __Vtemp5[2U] = (1U & ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                          & ((~ ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                 >> 3U)) & (IData)(
                                                   (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                    >> 0x3fU)))));
    __Vtemp9[0U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                    & ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                        ? (~ vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U])
                        : vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U]));
    __Vtemp9[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                    & ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                        ? (~ vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U])
                        : vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U]));
    __Vtemp9[2U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                    & ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                        ? (~ vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U])
                        : vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U]));
    VL_ADD_W(3, __Vtemp10, __Vtemp5, __Vtemp9);
    __Vtemp13[0U] = ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                      ? 1U : 0U);
    __Vtemp13[1U] = 0U;
    __Vtemp13[2U] = 0U;
    VL_ADD_W(3, __Vtemp14, __Vtemp10, __Vtemp13);
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res[0U] 
        = __Vtemp14[0U];
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res[1U] 
        = __Vtemp14[1U];
    vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res[2U] 
        = (1U & __Vtemp14[2U]);
    vlTOPp->SimTop__DOT__r_data2 = ((- (QData)((IData)(
                                                       ((~ (IData)(vlTOPp->reset)) 
                                                        & (IData)(vlTOPp->SimTop__DOT__rs2_r_ena))))) 
                                    & ((((IData)(vlTOPp->SimTop__DOT__rs2_r_addr) 
                                         == (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)) 
                                        & (0U != (IData)(vlTOPp->SimTop__DOT__rs2_r_addr)))
                                        ? vlTOPp->SimTop__DOT__wb_reg_wr_data
                                        : vlTOPp->SimTop__DOT__Regfile__DOT__regs
                                       [vlTOPp->SimTop__DOT__rs2_r_addr]));
    vlTOPp->SimTop__DOT__id_reg_wr_addr = ((IData)(vlTOPp->SimTop__DOT__id_reg_wr_ena)
                                            ? (0x1fU 
                                               & (vlTOPp->SimTop__DOT__id_inst 
                                                  >> 7U))
                                            : 0U);
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
    vlTOPp->SimTop__DOT__rs1_r_addr = (0x1fU & ((- (IData)((IData)(vlTOPp->SimTop__DOT__rs1_r_ena))) 
                                                & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0xfU)));
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
    vlTOPp->SimTop__DOT__bj_ena = (((~ (IData)(vlTOPp->reset)) 
                                    & (IData)(vlTOPp->SimTop__DOT__ex_valid)) 
                                   & (0U != ((IData)(vlTOPp->SimTop__DOT__ex_bj_info) 
                                             & (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__bj_data))));
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
    self->SimTop__DOT__rd_data = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__byte_enable = VL_RAND_RESET_I(8);
    self->SimTop__DOT__ram_rd_data = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__if_excp = VL_RAND_RESET_I(16);
    self->SimTop__DOT__if_pc = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__bj_ena = VL_RAND_RESET_I(1);
    self->SimTop__DOT__id_pc = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__id_inst = VL_RAND_RESET_I(32);
    self->SimTop__DOT__id_valid = VL_RAND_RESET_I(1);
    self->SimTop__DOT__id_allowin = VL_RAND_RESET_I(1);
    self->SimTop__DOT__id_to_ex_valid = VL_RAND_RESET_I(1);
    self->SimTop__DOT__stall = VL_RAND_RESET_I(1);
    self->SimTop__DOT__id_excp = VL_RAND_RESET_I(16);
    self->SimTop__DOT__id_alu_info = VL_RAND_RESET_I(12);
    self->SimTop__DOT__id_bj_info = VL_RAND_RESET_I(8);
    self->SimTop__DOT__id_load_info = VL_RAND_RESET_I(7);
    self->SimTop__DOT__id_op1 = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__id_op2 = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__id_csr_data = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__id_reg_wr_addr = VL_RAND_RESET_I(5);
    self->SimTop__DOT__id_reg_wr_ena = VL_RAND_RESET_I(1);
    self->SimTop__DOT__ex_pc = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__ex_inst = VL_RAND_RESET_I(32);
    self->SimTop__DOT__ex_is_word_opt = VL_RAND_RESET_I(1);
    self->SimTop__DOT__ex_alu_info = VL_RAND_RESET_I(12);
    self->SimTop__DOT__ex_bj_info = VL_RAND_RESET_I(8);
    self->SimTop__DOT__ex_jmp_imm = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__ex_now_op1 = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__ex_now_op2 = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__ex_use_rs1 = VL_RAND_RESET_I(1);
    self->SimTop__DOT__ex_use_rs2 = VL_RAND_RESET_I(1);
    self->SimTop__DOT__ex_rs1_data = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__ex_rs2_data = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__ex_rs1_addr = VL_RAND_RESET_I(5);
    self->SimTop__DOT__ex_rs2_addr = VL_RAND_RESET_I(5);
    self->SimTop__DOT__ex_csr_data = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__ex_ram_wr_ena_r = VL_RAND_RESET_I(1);
    self->SimTop__DOT__ex_ram_rd_ena_r = VL_RAND_RESET_I(1);
    self->SimTop__DOT__ex_ram_rd_ena = VL_RAND_RESET_I(1);
    self->SimTop__DOT__ex_load_info = VL_RAND_RESET_I(7);
    self->SimTop__DOT__ex_save_info = VL_RAND_RESET_I(4);
    self->SimTop__DOT__ex_reg_wr_ctrl = VL_RAND_RESET_I(3);
    self->SimTop__DOT__ex_reg_wr_addr = VL_RAND_RESET_I(5);
    self->SimTop__DOT__ex_reg_wr_ena_r = VL_RAND_RESET_I(1);
    self->SimTop__DOT__ex_csr_wr_addr = VL_RAND_RESET_I(12);
    self->SimTop__DOT__ex_csr_wr_ena_r = VL_RAND_RESET_I(1);
    self->SimTop__DOT__ex_valid = VL_RAND_RESET_I(1);
    self->SimTop__DOT__rs1_forward = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__rs2_forward = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__true_op1 = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__true_op2 = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__mem_pc = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__mem_inst = VL_RAND_RESET_I(32);
    self->SimTop__DOT__mem_load_info = VL_RAND_RESET_I(7);
    self->SimTop__DOT__mem_save_info = VL_RAND_RESET_I(4);
    self->SimTop__DOT__mem_ram_wr_src = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__mem_ex_data = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__mem_csr_data = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__mem_ram_wr_ena = VL_RAND_RESET_I(1);
    self->SimTop__DOT__mem_ram_rd_ena = VL_RAND_RESET_I(1);
    self->SimTop__DOT__mem_reg_wr_ctrl = VL_RAND_RESET_I(3);
    self->SimTop__DOT__mem_reg_wr_addr = VL_RAND_RESET_I(5);
    self->SimTop__DOT__mem_reg_wr_ena = VL_RAND_RESET_I(1);
    self->SimTop__DOT__mem_csr_wr_addr = VL_RAND_RESET_I(12);
    self->SimTop__DOT__mem_csr_wr_ena = VL_RAND_RESET_I(1);
    self->SimTop__DOT__mem_valid = VL_RAND_RESET_I(1);
    self->SimTop__DOT__mem_excp = VL_RAND_RESET_I(16);
    self->SimTop__DOT__mem_ram_data = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__wb_pc = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__wb_inst = VL_RAND_RESET_I(32);
    self->SimTop__DOT__wb_reg_wr_ctrl = VL_RAND_RESET_I(3);
    self->SimTop__DOT__wb_ex_data = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__wb_ram_data = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__wb_csr_data = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__wb_reg_wr_addr = VL_RAND_RESET_I(5);
    self->SimTop__DOT__wb_reg_wr_ena = VL_RAND_RESET_I(1);
    self->SimTop__DOT__wb_csr_wr_addr = VL_RAND_RESET_I(12);
    self->SimTop__DOT__wb_csr_wr_ena = VL_RAND_RESET_I(1);
    self->SimTop__DOT__wb_valid = VL_RAND_RESET_I(1);
    self->SimTop__DOT__rs1_r_ena = VL_RAND_RESET_I(1);
    self->SimTop__DOT__rs1_r_addr = VL_RAND_RESET_I(5);
    self->SimTop__DOT__r_data1 = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__rs2_r_ena = VL_RAND_RESET_I(1);
    self->SimTop__DOT__rs2_r_addr = VL_RAND_RESET_I(5);
    self->SimTop__DOT__r_data2 = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__wb_reg_wr_data = VL_RAND_RESET_Q(64);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        self->SimTop__DOT__regs[__Vi0] = VL_RAND_RESET_Q(64);
    }
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        self->SimTop__DOT____Vcellout__Regfile__regs_o[__Vi0] = VL_RAND_RESET_Q(64);
    }
    self->SimTop__DOT__excp_exit = VL_RAND_RESET_I(1);
    self->SimTop__DOT__csr_rd_ena = VL_RAND_RESET_I(1);
    self->SimTop__DOT__csr_wr_ena = VL_RAND_RESET_I(1);
    self->SimTop__DOT__csr_wr_addr = VL_RAND_RESET_I(12);
    self->SimTop__DOT__mtval_rd_data = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__cmt_wen = VL_RAND_RESET_I(1);
    self->SimTop__DOT__cmt_wdest = VL_RAND_RESET_I(8);
    self->SimTop__DOT__cmt_wdata = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__cmt_pc = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__cmt_inst = VL_RAND_RESET_I(32);
    self->SimTop__DOT__vaild = VL_RAND_RESET_I(1);
    self->SimTop__DOT__skip = VL_RAND_RESET_I(1);
    self->SimTop__DOT__cycleCnt = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__instrCnt = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__RAM_1W2R__DOT__inst_2 = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__Id_stage__DOT__immS = VL_RAND_RESET_I(12);
    self->SimTop__DOT__Id_stage__DOT__immB = VL_RAND_RESET_I(13);
    self->SimTop__DOT__Id_stage__DOT__immJ = VL_RAND_RESET_I(21);
    self->SimTop__DOT__Id_stage__DOT__inst_i_excp = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_lb = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_lh = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_lw = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_ld = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_lbu = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_lhu = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_lwu = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_addi = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_slli = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_slti = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_sltiu = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_xori = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_srli = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_srai = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_ori = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_andi = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_addiw = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_slliw = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_srliw = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_sraiw = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_sb = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_sh = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_sw = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_sd = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_add = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_sub = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_sll = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_slt = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_sltu = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_xor = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_srl = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_sra = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_or = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_and = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_addw = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_subw = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_sllw = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_srlw = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_sraw = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_beq = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_bne = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_blt = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_bge = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_bltu = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_bgeu = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_csrrw = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_csrrs = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_csrrc = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_csrrwi = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_csrrsi = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_csrrci = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Id_stage__DOT__inst_vld = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Ex_stage__DOT__bj_data = VL_RAND_RESET_I(8);
    self->SimTop__DOT__Ex_stage__DOT__op1 = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__Ex_stage__DOT__op2 = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_shift = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in1 = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in2 = VL_RAND_RESET_I(6);
    self->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub = VL_RAND_RESET_I(1);
    self->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(65, self->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2);
    VL_RAND_RESET_W(65, self->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res);
    self->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__Mem_stage__DOT__mem_part = VL_RAND_RESET_Q(64);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        self->SimTop__DOT__Regfile__DOT__regs[__Vi0] = VL_RAND_RESET_Q(64);
    }
    self->SimTop__DOT__Excp_handler__DOT__excp_info = VL_RAND_RESET_I(16);
    self->SimTop__DOT__Excp_handler__DOT__mstatus_excp_enter = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__Excp_handler__DOT__mstatus_excp_exit = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__CSRfile__DOT__csr_mstatus = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__CSRfile__DOT__csr_mie = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__CSRfile__DOT__csr_mtvec = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__CSRfile__DOT__csr_mscratch = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__CSRfile__DOT__csr_mepc = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__CSRfile__DOT__csr_mcause = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__CSRfile__DOT__csr_mtval = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__CSRfile__DOT__csr_mip = VL_RAND_RESET_Q(64);
    self->SimTop__DOT__CSRfile__DOT__csr_mcycle = VL_RAND_RESET_Q(64);
    self->__Vfunc_ram_read_helper__0__Vfuncout = 0;
    self->__Vfunc_ram_read_helper__1__Vfuncout = 0;
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        self->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
