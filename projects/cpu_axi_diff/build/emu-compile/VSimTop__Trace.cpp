// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSimTop__Syms.h"


void VSimTop::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VSimTop__Syms* __restrict vlSymsp = static_cast<VSimTop__Syms*>(userp);
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VSimTop::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VSimTop__Syms* __restrict vlSymsp = static_cast<VSimTop__Syms*>(userp);
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Variables
    VlWide<3>/*95:0*/ __Vtemp43;
    VlWide<3>/*95:0*/ __Vtemp44;
    VlWide<3>/*95:0*/ __Vtemp45;
    VlWide<3>/*95:0*/ __Vtemp46;
    VlWide<3>/*95:0*/ __Vtemp47;
    VlWide<3>/*95:0*/ __Vtemp48;
    VlWide<3>/*95:0*/ __Vtemp49;
    VlWide<3>/*95:0*/ __Vtemp50;
    VlWide<4>/*127:0*/ __Vtemp51;
    VlWide<3>/*95:0*/ __Vtemp52;
    VlWide<4>/*127:0*/ __Vtemp53;
    VlWide<4>/*127:0*/ __Vtemp54;
    VlWide<3>/*95:0*/ __Vtemp55;
    VlWide<4>/*127:0*/ __Vtemp56;
    VlWide<4>/*127:0*/ __Vtemp57;
    VlWide<3>/*95:0*/ __Vtemp58;
    VlWide<4>/*127:0*/ __Vtemp59;
    VlWide<4>/*127:0*/ __Vtemp60;
    VlWide<3>/*95:0*/ __Vtemp61;
    VlWide<4>/*127:0*/ __Vtemp62;
    VlWide<3>/*95:0*/ __Vtemp63;
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgBit(oldp+0,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_hs));
            tracep->chgBit(oldp+1,(((IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_hs) 
                                    & (IData)(vlTOPp->SimTop__DOT__w_last))));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+2,((1U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_state))));
            VL_EXTEND_WQ(65,64, __Vtemp43, vlTOPp->SimTop__DOT__if_addr);
            tracep->chgQData(oldp+3,((0xfffffffffffffff8ULL 
                                      & (((QData)((IData)(
                                                          __Vtemp43[1U])) 
                                          << 0x20U) 
                                         | (0xfffffffffffffff8ULL 
                                            & (QData)((IData)(
                                                              __Vtemp43[0U])))))),64);
            tracep->chgCData(oldp+5,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__axi_len),8);
            tracep->chgBit(oldp+6,((2U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_state))));
            tracep->chgBit(oldp+7,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__rw_ready));
            tracep->chgQData(oldp+8,((((QData)((IData)(
                                                       vlTOPp->SimTop__DOT____Vcellout__u_axi_rw__data_read_o[1U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlTOPp->SimTop__DOT____Vcellout__u_axi_rw__data_read_o[0U])))),64);
            tracep->chgQData(oldp+10,(vlTOPp->SimTop__DOT__if_addr),64);
            tracep->chgCData(oldp+12,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__rw_resp),2);
            tracep->chgWData(oldp+13,(vlTOPp->SimTop__DOT____Vcellout__u_axi_rw__data_read_o),65);
            VL_EXTEND_WQ(65,64, __Vtemp44, vlTOPp->SimTop__DOT__if_addr);
            tracep->chgWData(oldp+16,(__Vtemp44),65);
            tracep->chgCData(oldp+19,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_state),2);
            tracep->chgCData(oldp+20,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_state),2);
            tracep->chgBit(oldp+21,((0U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_state))));
            tracep->chgBit(oldp+22,((1U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_state))));
            tracep->chgBit(oldp+23,((2U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_state))));
            tracep->chgBit(oldp+24,((3U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_state))));
            tracep->chgBit(oldp+25,((0U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_state))));
            tracep->chgCData(oldp+26,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__len),8);
            VL_EXTEND_WQ(65,64, __Vtemp45, vlTOPp->SimTop__DOT__if_addr);
            tracep->chgBit(oldp+27,((0U == (7U & __Vtemp45[0U]))));
            VL_EXTEND_WQ(65,64, __Vtemp46, vlTOPp->SimTop__DOT__if_addr);
            tracep->chgCData(oldp+28,((7U & __Vtemp46[0U])),4);
            VL_EXTEND_WQ(65,64, __Vtemp47, vlTOPp->SimTop__DOT__if_addr);
            tracep->chgCData(oldp+29,((0xfU & ((IData)(3U) 
                                               + (7U 
                                                  & __Vtemp47[0U])))),4);
            VL_EXTEND_WQ(65,64, __Vtemp48, vlTOPp->SimTop__DOT__if_addr);
            tracep->chgBit(oldp+30,((1U & (((IData)(3U) 
                                            + (7U & 
                                               __Vtemp48[0U])) 
                                           >> 3U))));
            VL_EXTEND_WQ(65,64, __Vtemp49, vlTOPp->SimTop__DOT__if_addr);
            tracep->chgCData(oldp+31,((0x38U & (__Vtemp49[0U] 
                                                << 3U))),6);
            VL_EXTEND_WQ(65,64, __Vtemp50, vlTOPp->SimTop__DOT__if_addr);
            tracep->chgCData(oldp+32,((0x3fU & (- (0x38U 
                                                   & (__Vtemp50[0U] 
                                                      << 3U))))),6);
            __Vtemp51[0U] = 0xffffffffU;
            __Vtemp51[1U] = 0U;
            __Vtemp51[2U] = 0U;
            __Vtemp51[3U] = 0U;
            VL_EXTEND_WQ(65,64, __Vtemp52, vlTOPp->SimTop__DOT__if_addr);
            VL_SHIFTL_WWI(128,128,6, __Vtemp53, __Vtemp51, 
                          (0x38U & (__Vtemp52[0U] << 3U)));
            tracep->chgWData(oldp+33,(__Vtemp53),128);
            __Vtemp54[0U] = 0xffffffffU;
            __Vtemp54[1U] = 0U;
            __Vtemp54[2U] = 0U;
            __Vtemp54[3U] = 0U;
            VL_EXTEND_WQ(65,64, __Vtemp55, vlTOPp->SimTop__DOT__if_addr);
            VL_SHIFTL_WWI(128,128,6, __Vtemp56, __Vtemp54, 
                          (0x38U & (__Vtemp55[0U] << 3U)));
            tracep->chgQData(oldp+37,((((QData)((IData)(
                                                        __Vtemp56[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    __Vtemp56[0U])))),64);
            __Vtemp57[0U] = 0xffffffffU;
            __Vtemp57[1U] = 0U;
            __Vtemp57[2U] = 0U;
            __Vtemp57[3U] = 0U;
            VL_EXTEND_WQ(65,64, __Vtemp58, vlTOPp->SimTop__DOT__if_addr);
            VL_SHIFTL_WWI(128,128,6, __Vtemp59, __Vtemp57, 
                          (0x38U & (__Vtemp58[0U] << 3U)));
            tracep->chgQData(oldp+39,((((QData)((IData)(
                                                        __Vtemp59[3U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    __Vtemp59[2U])))),64);
            tracep->chgQData(oldp+41,(vlTOPp->SimTop__DOT__u_cpu__DOT__pc),64);
            tracep->chgIData(oldp+43,(vlTOPp->SimTop__DOT__u_cpu__DOT__inst),32);
            tracep->chgBit(oldp+44,(vlTOPp->SimTop__DOT__u_cpu__DOT__fetched));
            tracep->chgBit(oldp+45,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addi));
            tracep->chgCData(oldp+46,((0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__inst)),7);
            tracep->chgCData(oldp+47,((0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__inst 
                                                >> 7U))),5);
            tracep->chgCData(oldp+48,((7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__inst 
                                             >> 0xcU))),3);
            tracep->chgCData(oldp+49,((0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__inst 
                                                >> 0xfU))),5);
            tracep->chgSData(oldp+50,((0xfffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__inst 
                                                 >> 0x14U))),12);
            tracep->chgQData(oldp+51,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0]),64);
            tracep->chgQData(oldp+53,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[1]),64);
            tracep->chgQData(oldp+55,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[2]),64);
            tracep->chgQData(oldp+57,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[3]),64);
            tracep->chgQData(oldp+59,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[4]),64);
            tracep->chgQData(oldp+61,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[5]),64);
            tracep->chgQData(oldp+63,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[6]),64);
            tracep->chgQData(oldp+65,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[7]),64);
            tracep->chgQData(oldp+67,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[8]),64);
            tracep->chgQData(oldp+69,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[9]),64);
            tracep->chgQData(oldp+71,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[10]),64);
            tracep->chgQData(oldp+73,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[11]),64);
            tracep->chgQData(oldp+75,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[12]),64);
            tracep->chgQData(oldp+77,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[13]),64);
            tracep->chgQData(oldp+79,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[14]),64);
            tracep->chgQData(oldp+81,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[15]),64);
            tracep->chgQData(oldp+83,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[16]),64);
            tracep->chgQData(oldp+85,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[17]),64);
            tracep->chgQData(oldp+87,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[18]),64);
            tracep->chgQData(oldp+89,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[19]),64);
            tracep->chgQData(oldp+91,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[20]),64);
            tracep->chgQData(oldp+93,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[21]),64);
            tracep->chgQData(oldp+95,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[22]),64);
            tracep->chgQData(oldp+97,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[23]),64);
            tracep->chgQData(oldp+99,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[24]),64);
            tracep->chgQData(oldp+101,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[25]),64);
            tracep->chgQData(oldp+103,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[26]),64);
            tracep->chgQData(oldp+105,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[27]),64);
            tracep->chgQData(oldp+107,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[28]),64);
            tracep->chgQData(oldp+109,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[29]),64);
            tracep->chgQData(oldp+111,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[30]),64);
            tracep->chgQData(oldp+113,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[31]),64);
        }
        if (VL_UNLIKELY((vlTOPp->__Vm_traceActivity
                         [1U] | vlTOPp->__Vm_traceActivity
                         [3U]))) {
            tracep->chgBit(oldp+115,((((IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__len) 
                                       != (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__axi_len)) 
                                      & ((IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_hs) 
                                         | (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_hs)))));
            tracep->chgBit(oldp+116,(((IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_done) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__rw_ready))));
            tracep->chgQData(oldp+117,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0]),64);
            tracep->chgQData(oldp+119,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[1]),64);
            tracep->chgQData(oldp+121,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[2]),64);
            tracep->chgQData(oldp+123,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[3]),64);
            tracep->chgQData(oldp+125,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[4]),64);
            tracep->chgQData(oldp+127,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[5]),64);
            tracep->chgQData(oldp+129,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[6]),64);
            tracep->chgQData(oldp+131,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[7]),64);
            tracep->chgQData(oldp+133,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[8]),64);
            tracep->chgQData(oldp+135,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[9]),64);
            tracep->chgQData(oldp+137,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[10]),64);
            tracep->chgQData(oldp+139,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[11]),64);
            tracep->chgQData(oldp+141,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[12]),64);
            tracep->chgQData(oldp+143,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[13]),64);
            tracep->chgQData(oldp+145,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[14]),64);
            tracep->chgQData(oldp+147,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[15]),64);
            tracep->chgQData(oldp+149,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[16]),64);
            tracep->chgQData(oldp+151,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[17]),64);
            tracep->chgQData(oldp+153,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[18]),64);
            tracep->chgQData(oldp+155,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[19]),64);
            tracep->chgQData(oldp+157,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[20]),64);
            tracep->chgQData(oldp+159,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[21]),64);
            tracep->chgQData(oldp+161,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[22]),64);
            tracep->chgQData(oldp+163,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[23]),64);
            tracep->chgQData(oldp+165,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[24]),64);
            tracep->chgQData(oldp+167,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[25]),64);
            tracep->chgQData(oldp+169,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[26]),64);
            tracep->chgQData(oldp+171,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[27]),64);
            tracep->chgQData(oldp+173,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[28]),64);
            tracep->chgQData(oldp+175,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[29]),64);
            tracep->chgQData(oldp+177,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[30]),64);
            tracep->chgQData(oldp+179,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[31]),64);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgBit(oldp+181,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wen));
            tracep->chgCData(oldp+182,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wdest),8);
            tracep->chgQData(oldp+183,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wdata),64);
            tracep->chgQData(oldp+185,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_pc),64);
            tracep->chgIData(oldp+187,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_inst),32);
            tracep->chgBit(oldp+188,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_valid));
            tracep->chgBit(oldp+189,(vlTOPp->SimTop__DOT__u_cpu__DOT__trap));
            tracep->chgCData(oldp+190,(vlTOPp->SimTop__DOT__u_cpu__DOT__trap_code),8);
            tracep->chgQData(oldp+191,(vlTOPp->SimTop__DOT__u_cpu__DOT__cycleCnt),64);
            tracep->chgQData(oldp+193,(vlTOPp->SimTop__DOT__u_cpu__DOT__instrCnt),64);
            tracep->chgQData(oldp+195,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[0]),64);
            tracep->chgQData(oldp+197,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[1]),64);
            tracep->chgQData(oldp+199,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[2]),64);
            tracep->chgQData(oldp+201,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[3]),64);
            tracep->chgQData(oldp+203,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[4]),64);
            tracep->chgQData(oldp+205,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[5]),64);
            tracep->chgQData(oldp+207,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[6]),64);
            tracep->chgQData(oldp+209,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[7]),64);
            tracep->chgQData(oldp+211,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[8]),64);
            tracep->chgQData(oldp+213,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[9]),64);
            tracep->chgQData(oldp+215,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[10]),64);
            tracep->chgQData(oldp+217,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[11]),64);
            tracep->chgQData(oldp+219,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[12]),64);
            tracep->chgQData(oldp+221,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[13]),64);
            tracep->chgQData(oldp+223,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[14]),64);
            tracep->chgQData(oldp+225,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[15]),64);
            tracep->chgQData(oldp+227,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[16]),64);
            tracep->chgQData(oldp+229,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[17]),64);
            tracep->chgQData(oldp+231,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[18]),64);
            tracep->chgQData(oldp+233,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[19]),64);
            tracep->chgQData(oldp+235,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[20]),64);
            tracep->chgQData(oldp+237,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[21]),64);
            tracep->chgQData(oldp+239,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[22]),64);
            tracep->chgQData(oldp+241,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[23]),64);
            tracep->chgQData(oldp+243,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[24]),64);
            tracep->chgQData(oldp+245,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[25]),64);
            tracep->chgQData(oldp+247,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[26]),64);
            tracep->chgQData(oldp+249,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[27]),64);
            tracep->chgQData(oldp+251,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[28]),64);
            tracep->chgQData(oldp+253,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[29]),64);
            tracep->chgQData(oldp+255,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[30]),64);
            tracep->chgQData(oldp+257,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[31]),64);
            tracep->chgQData(oldp+259,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0U]),64);
            tracep->chgQData(oldp+261,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [1U]),64);
            tracep->chgQData(oldp+263,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [2U]),64);
            tracep->chgQData(oldp+265,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [3U]),64);
            tracep->chgQData(oldp+267,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [4U]),64);
            tracep->chgQData(oldp+269,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [5U]),64);
            tracep->chgQData(oldp+271,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [6U]),64);
            tracep->chgQData(oldp+273,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [7U]),64);
            tracep->chgQData(oldp+275,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [8U]),64);
            tracep->chgQData(oldp+277,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [9U]),64);
            tracep->chgQData(oldp+279,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0xaU]),64);
            tracep->chgQData(oldp+281,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0xbU]),64);
            tracep->chgQData(oldp+283,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0xcU]),64);
            tracep->chgQData(oldp+285,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0xdU]),64);
            tracep->chgQData(oldp+287,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0xeU]),64);
            tracep->chgQData(oldp+289,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0xfU]),64);
            tracep->chgQData(oldp+291,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x10U]),64);
            tracep->chgQData(oldp+293,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x11U]),64);
            tracep->chgQData(oldp+295,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x12U]),64);
            tracep->chgQData(oldp+297,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x13U]),64);
            tracep->chgQData(oldp+299,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x14U]),64);
            tracep->chgQData(oldp+301,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x15U]),64);
            tracep->chgQData(oldp+303,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x16U]),64);
            tracep->chgQData(oldp+305,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x17U]),64);
            tracep->chgQData(oldp+307,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x18U]),64);
            tracep->chgQData(oldp+309,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x19U]),64);
            tracep->chgQData(oldp+311,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x1aU]),64);
            tracep->chgQData(oldp+313,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x1bU]),64);
            tracep->chgQData(oldp+315,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x1cU]),64);
            tracep->chgQData(oldp+317,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x1dU]),64);
            tracep->chgQData(oldp+319,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x1eU]),64);
            tracep->chgQData(oldp+321,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                       [0x1fU]),64);
            tracep->chgCData(oldp+323,((7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__trap_code))),3);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgBit(oldp+324,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_hs));
            tracep->chgBit(oldp+325,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_done));
            tracep->chgQData(oldp+326,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__axi_r_data_l),64);
            tracep->chgBit(oldp+328,(vlTOPp->SimTop__DOT__u_cpu__DOT__rd_w_ena));
            tracep->chgCData(oldp+329,(vlTOPp->SimTop__DOT__u_cpu__DOT__rd_w_addr),5);
            tracep->chgCData(oldp+330,(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_type),5);
            tracep->chgCData(oldp+331,(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_opcode),8);
            tracep->chgQData(oldp+332,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0]),64);
            tracep->chgQData(oldp+334,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[1]),64);
            tracep->chgQData(oldp+336,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[2]),64);
            tracep->chgQData(oldp+338,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[3]),64);
            tracep->chgQData(oldp+340,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[4]),64);
            tracep->chgQData(oldp+342,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[5]),64);
            tracep->chgQData(oldp+344,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[6]),64);
            tracep->chgQData(oldp+346,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[7]),64);
            tracep->chgQData(oldp+348,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[8]),64);
            tracep->chgQData(oldp+350,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[9]),64);
            tracep->chgQData(oldp+352,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[10]),64);
            tracep->chgQData(oldp+354,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[11]),64);
            tracep->chgQData(oldp+356,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[12]),64);
            tracep->chgQData(oldp+358,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[13]),64);
            tracep->chgQData(oldp+360,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[14]),64);
            tracep->chgQData(oldp+362,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[15]),64);
            tracep->chgQData(oldp+364,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[16]),64);
            tracep->chgQData(oldp+366,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[17]),64);
            tracep->chgQData(oldp+368,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[18]),64);
            tracep->chgQData(oldp+370,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[19]),64);
            tracep->chgQData(oldp+372,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[20]),64);
            tracep->chgQData(oldp+374,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[21]),64);
            tracep->chgQData(oldp+376,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[22]),64);
            tracep->chgQData(oldp+378,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[23]),64);
            tracep->chgQData(oldp+380,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[24]),64);
            tracep->chgQData(oldp+382,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[25]),64);
            tracep->chgQData(oldp+384,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[26]),64);
            tracep->chgQData(oldp+386,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[27]),64);
            tracep->chgQData(oldp+388,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[28]),64);
            tracep->chgQData(oldp+390,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[29]),64);
            tracep->chgQData(oldp+392,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[30]),64);
            tracep->chgQData(oldp+394,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[31]),64);
            tracep->chgQData(oldp+396,(vlTOPp->SimTop__DOT__u_cpu__DOT__rd_data),64);
            tracep->chgBit(oldp+398,(vlTOPp->SimTop__DOT__u_cpu__DOT__w_ena));
        }
        tracep->chgBit(oldp+399,(vlTOPp->clock));
        tracep->chgBit(oldp+400,(vlTOPp->reset));
        tracep->chgQData(oldp+401,(vlTOPp->io_logCtrl_log_begin),64);
        tracep->chgQData(oldp+403,(vlTOPp->io_logCtrl_log_end),64);
        tracep->chgQData(oldp+405,(vlTOPp->io_logCtrl_log_level),64);
        tracep->chgBit(oldp+407,(vlTOPp->io_perfInfo_clean));
        tracep->chgBit(oldp+408,(vlTOPp->io_perfInfo_dump));
        tracep->chgBit(oldp+409,(vlTOPp->io_uart_out_valid));
        tracep->chgCData(oldp+410,(vlTOPp->io_uart_out_ch),8);
        tracep->chgBit(oldp+411,(vlTOPp->io_uart_in_valid));
        tracep->chgCData(oldp+412,(vlTOPp->io_uart_in_ch),8);
        tracep->chgBit(oldp+413,(vlTOPp->io_memAXI_0_aw_ready));
        tracep->chgBit(oldp+414,(vlTOPp->io_memAXI_0_aw_valid));
        tracep->chgQData(oldp+415,(vlTOPp->io_memAXI_0_aw_bits_addr),64);
        tracep->chgCData(oldp+417,(vlTOPp->io_memAXI_0_aw_bits_prot),3);
        tracep->chgCData(oldp+418,(vlTOPp->io_memAXI_0_aw_bits_id),4);
        tracep->chgBit(oldp+419,(vlTOPp->io_memAXI_0_aw_bits_user));
        tracep->chgCData(oldp+420,(vlTOPp->io_memAXI_0_aw_bits_len),8);
        tracep->chgCData(oldp+421,(vlTOPp->io_memAXI_0_aw_bits_size),3);
        tracep->chgCData(oldp+422,(vlTOPp->io_memAXI_0_aw_bits_burst),2);
        tracep->chgBit(oldp+423,(vlTOPp->io_memAXI_0_aw_bits_lock));
        tracep->chgCData(oldp+424,(vlTOPp->io_memAXI_0_aw_bits_cache),4);
        tracep->chgCData(oldp+425,(vlTOPp->io_memAXI_0_aw_bits_qos),4);
        tracep->chgBit(oldp+426,(vlTOPp->io_memAXI_0_w_ready));
        tracep->chgBit(oldp+427,(vlTOPp->io_memAXI_0_w_valid));
        tracep->chgQData(oldp+428,(vlTOPp->io_memAXI_0_w_bits_data[0]),64);
        tracep->chgQData(oldp+430,(vlTOPp->io_memAXI_0_w_bits_data[1]),64);
        tracep->chgQData(oldp+432,(vlTOPp->io_memAXI_0_w_bits_data[2]),64);
        tracep->chgQData(oldp+434,(vlTOPp->io_memAXI_0_w_bits_data[3]),64);
        tracep->chgCData(oldp+436,(vlTOPp->io_memAXI_0_w_bits_strb),8);
        tracep->chgBit(oldp+437,(vlTOPp->io_memAXI_0_w_bits_last));
        tracep->chgBit(oldp+438,(vlTOPp->io_memAXI_0_b_ready));
        tracep->chgBit(oldp+439,(vlTOPp->io_memAXI_0_b_valid));
        tracep->chgCData(oldp+440,(vlTOPp->io_memAXI_0_b_bits_resp),2);
        tracep->chgCData(oldp+441,(vlTOPp->io_memAXI_0_b_bits_id),4);
        tracep->chgBit(oldp+442,(vlTOPp->io_memAXI_0_b_bits_user));
        tracep->chgBit(oldp+443,(vlTOPp->io_memAXI_0_ar_ready));
        tracep->chgBit(oldp+444,(vlTOPp->io_memAXI_0_ar_valid));
        tracep->chgQData(oldp+445,(vlTOPp->io_memAXI_0_ar_bits_addr),64);
        tracep->chgCData(oldp+447,(vlTOPp->io_memAXI_0_ar_bits_prot),3);
        tracep->chgCData(oldp+448,(vlTOPp->io_memAXI_0_ar_bits_id),4);
        tracep->chgBit(oldp+449,(vlTOPp->io_memAXI_0_ar_bits_user));
        tracep->chgCData(oldp+450,(vlTOPp->io_memAXI_0_ar_bits_len),8);
        tracep->chgCData(oldp+451,(vlTOPp->io_memAXI_0_ar_bits_size),3);
        tracep->chgCData(oldp+452,(vlTOPp->io_memAXI_0_ar_bits_burst),2);
        tracep->chgBit(oldp+453,(vlTOPp->io_memAXI_0_ar_bits_lock));
        tracep->chgCData(oldp+454,(vlTOPp->io_memAXI_0_ar_bits_cache),4);
        tracep->chgCData(oldp+455,(vlTOPp->io_memAXI_0_ar_bits_qos),4);
        tracep->chgBit(oldp+456,(vlTOPp->io_memAXI_0_r_ready));
        tracep->chgBit(oldp+457,(vlTOPp->io_memAXI_0_r_valid));
        tracep->chgCData(oldp+458,(vlTOPp->io_memAXI_0_r_bits_resp),2);
        tracep->chgQData(oldp+459,(vlTOPp->io_memAXI_0_r_bits_data[0]),64);
        tracep->chgQData(oldp+461,(vlTOPp->io_memAXI_0_r_bits_data[1]),64);
        tracep->chgQData(oldp+463,(vlTOPp->io_memAXI_0_r_bits_data[2]),64);
        tracep->chgQData(oldp+465,(vlTOPp->io_memAXI_0_r_bits_data[3]),64);
        tracep->chgBit(oldp+467,(vlTOPp->io_memAXI_0_r_bits_last));
        tracep->chgCData(oldp+468,(vlTOPp->io_memAXI_0_r_bits_id),4);
        tracep->chgBit(oldp+469,(vlTOPp->io_memAXI_0_r_bits_user));
        tracep->chgQData(oldp+470,(vlTOPp->io_memAXI_0_r_bits_data
                                   [0U]),64);
        tracep->chgBit(oldp+472,(((IData)(vlTOPp->io_memAXI_0_ar_ready) 
                                  & (1U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_state)))));
        tracep->chgBit(oldp+473,(((IData)(vlTOPp->reset) 
                                  | (0U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_state)))));
        tracep->chgBit(oldp+474,((1U & (IData)(vlTOPp->io_memAXI_0_r_bits_resp))));
        __Vtemp60[0U] = 0xffffffffU;
        __Vtemp60[1U] = 0U;
        __Vtemp60[2U] = 0U;
        __Vtemp60[3U] = 0U;
        VL_EXTEND_WQ(65,64, __Vtemp61, vlTOPp->SimTop__DOT__if_addr);
        VL_SHIFTL_WWI(128,128,6, __Vtemp62, __Vtemp60, 
                      (0x38U & (__Vtemp61[0U] << 3U)));
        VL_EXTEND_WQ(65,64, __Vtemp63, vlTOPp->SimTop__DOT__if_addr);
        tracep->chgQData(oldp+475,(((vlTOPp->io_memAXI_0_r_bits_data
                                     [0U] & (((QData)((IData)(
                                                              __Vtemp62[3U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               __Vtemp62[2U])))) 
                                    << (0x3fU & (- 
                                                 (0x38U 
                                                  & (__Vtemp63[0U] 
                                                     << 3U)))))),64);
        tracep->chgBit(oldp+477,(((IData)(vlTOPp->reset)
                                   ? 0U : (1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_type) 
                                                 >> 4U)))));
        tracep->chgCData(oldp+478,(((IData)(vlTOPp->reset)
                                     ? 0U : ((0x10U 
                                              & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_type))
                                              ? (0x1fU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__inst 
                                                    >> 0xfU))
                                              : 0U))),5);
        tracep->chgQData(oldp+479,(((IData)(vlTOPp->reset)
                                     ? 0ULL : ((0x10U 
                                                & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_type))
                                                ? ((IData)(vlTOPp->reset)
                                                    ? 0ULL
                                                    : 
                                                   (((IData)(vlTOPp->reset)
                                                      ? 0U
                                                      : 
                                                     (1U 
                                                      & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_type) 
                                                         >> 4U)))
                                                     ? 
                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
                                                    [
                                                    ((IData)(vlTOPp->reset)
                                                      ? 0U
                                                      : 
                                                     ((0x10U 
                                                       & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_type))
                                                       ? 
                                                      (0x1fU 
                                                       & (vlTOPp->SimTop__DOT__u_cpu__DOT__inst 
                                                          >> 0xfU))
                                                       : 0U))]
                                                     : 0ULL))
                                                : 0ULL))),64);
        tracep->chgQData(oldp+481,(((IData)(vlTOPp->reset)
                                     ? 0ULL : ((0x10U 
                                                & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_type))
                                                ? (
                                                   (0xfffffffffffff000ULL 
                                                    & ((- (QData)((IData)(
                                                                          (1U 
                                                                           & (vlTOPp->SimTop__DOT__u_cpu__DOT__inst 
                                                                              >> 0x1fU))))) 
                                                       << 0xcU)) 
                                                   | (QData)((IData)(
                                                                     (0xfffU 
                                                                      & (vlTOPp->SimTop__DOT__u_cpu__DOT__inst 
                                                                         >> 0x14U)))))
                                                : 0ULL))),64);
        tracep->chgQData(oldp+483,(((IData)(vlTOPp->reset)
                                     ? 0ULL : (((IData)(vlTOPp->reset)
                                                 ? 0U
                                                 : 
                                                (1U 
                                                 & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_type) 
                                                    >> 4U)))
                                                ? vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
                                               [((IData)(vlTOPp->reset)
                                                  ? 0U
                                                  : 
                                                 ((0x10U 
                                                   & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_type))
                                                   ? 
                                                  (0x1fU 
                                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__inst 
                                                      >> 0xfU))
                                                   : 0U))]
                                                : 0ULL))),64);
    }
}

void VSimTop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VSimTop__Syms* __restrict vlSymsp = static_cast<VSimTop__Syms*>(userp);
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
    }
}
