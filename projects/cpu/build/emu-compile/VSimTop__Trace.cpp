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
    VlWide<4>/*127:0*/ __Vtemp867;
    VlWide<4>/*127:0*/ __Vtemp868;
    VlWide<4>/*127:0*/ __Vtemp869;
    VlWide<4>/*127:0*/ __Vtemp870;
    VlWide<4>/*127:0*/ __Vtemp871;
    VlWide<4>/*127:0*/ __Vtemp872;
    VlWide<7>/*223:0*/ __Vtemp897;
    VlWide<23>/*735:0*/ __Vtemp900;
    VlWide<16>/*511:0*/ __Vtemp901;
    VlWide<3>/*95:0*/ __Vtemp987;
    VlWide<4>/*127:0*/ __Vtemp1028;
    VlWide<4>/*127:0*/ __Vtemp1029;
    VlWide<19>/*607:0*/ __Vtemp1039;
    VlWide<3>/*95:0*/ __Vtemp1046;
    VlWide<3>/*95:0*/ __Vtemp1049;
    VlWide<3>/*95:0*/ __Vtemp1055;
    VlWide<16>/*511:0*/ __Vtemp1062;
    VlWide<3>/*95:0*/ __Vtemp1064;
    VlWide<4>/*127:0*/ __Vtemp1070;
    VlWide<8>/*255:0*/ __Vtemp1071;
    VlWide<8>/*255:0*/ __Vtemp1072;
    VlWide<8>/*255:0*/ __Vtemp1073;
    VlWide<3>/*95:0*/ __Vtemp1081;
    VlWide<11>/*351:0*/ __Vtemp1082;
    VlWide<11>/*351:0*/ __Vtemp1083;
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->SimTop__DOT__cli_aw_ready));
            tracep->chgBit(oldp+1,((1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))));
            tracep->chgBit(oldp+2,((1U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state))));
            tracep->chgBit(oldp+3,(vlTOPp->SimTop__DOT__cli_aw_valid));
            tracep->chgQData(oldp+4,((0xfffffffffffffff8ULL 
                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)),64);
            tracep->chgQData(oldp+6,((0xfffffffffffffff8ULL 
                                      & vlTOPp->SimTop__DOT__if_rw_addr)),64);
            tracep->chgQData(oldp+8,(((- (QData)((IData)(
                                                         (1U 
                                                          == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state))))) 
                                      & vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_addr)),64);
            tracep->chgCData(oldp+10,((1U & (- (IData)(
                                                       (1U 
                                                        == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)))))),4);
            tracep->chgCData(oldp+11,(((- (IData)((1U 
                                                   == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_id))),4);
            tracep->chgCData(oldp+12,(((- (IData)((1U 
                                                   == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)))) 
                                       & (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_len))),8);
            tracep->chgCData(oldp+13,(((- (IData)((1U 
                                                   == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state)))) 
                                       & (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len))),8);
            tracep->chgCData(oldp+14,(((- (IData)((1U 
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
                                                & (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len)))))),8);
            tracep->chgCData(oldp+15,((3U & (- (IData)(
                                                       (1U 
                                                        == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)))))),3);
            tracep->chgCData(oldp+16,((3U & (- (IData)(
                                                       (1U 
                                                        == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state)))))),3);
            tracep->chgCData(oldp+17,(((- (IData)((1U 
                                                   == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_size))),3);
            tracep->chgCData(oldp+18,(vlTOPp->SimTop__DOT__cli_aw_burst),2);
            tracep->chgCData(oldp+19,((2U & ((- (IData)(
                                                        (1U 
                                                         == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                             & ((- (IData)(
                                                           (1U 
                                                            == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                                | (- (IData)(
                                                             (2U 
                                                              == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))))))),4);
            tracep->chgBit(oldp+20,(vlTOPp->SimTop__DOT__cli_w_valid));
            tracep->chgBit(oldp+21,((2U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))));
            tracep->chgBit(oldp+22,((2U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state))));
            tracep->chgQData(oldp+23,(vlTOPp->SimTop__DOT__mem_axi_w_data),64);
            tracep->chgQData(oldp+25,(vlTOPp->SimTop__DOT__if_axi_w_data),64);
            tracep->chgQData(oldp+27,(vlTOPp->SimTop__DOT__cli_w_data),64);
            tracep->chgCData(oldp+29,(vlTOPp->SimTop__DOT__mem_axi_w_strb),8);
            tracep->chgCData(oldp+30,(vlTOPp->SimTop__DOT__if_axi_w_strb),8);
            tracep->chgCData(oldp+31,(((- (IData)((1U 
                                                   == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_strb))),8);
            tracep->chgBit(oldp+32,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                     & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_last))));
            tracep->chgBit(oldp+33,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                     & (1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))));
            tracep->chgBit(oldp+34,((3U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))));
            tracep->chgBit(oldp+35,((3U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state))));
            tracep->chgBit(oldp+36,(vlTOPp->SimTop__DOT__cli_b_ready));
            tracep->chgBit(oldp+37,((2U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__w_state))));
            tracep->chgCData(oldp+38,(vlTOPp->SimTop__DOT__Clint__DOT__wr_id_reg),4);
            tracep->chgBit(oldp+39,(vlTOPp->SimTop__DOT__Clint__DOT__wr_user_reg));
            tracep->chgBit(oldp+40,(vlTOPp->SimTop__DOT__cli_ar_ready));
            tracep->chgBit(oldp+41,((1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))));
            tracep->chgBit(oldp+42,((1U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state))));
            tracep->chgBit(oldp+43,(vlTOPp->SimTop__DOT__cli_ar_valid));
            tracep->chgQData(oldp+44,(((- (QData)((IData)(
                                                          (1U 
                                                           == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state))))) 
                                       & vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_addr)),64);
            tracep->chgCData(oldp+46,((1U & (- (IData)(
                                                       (1U 
                                                        == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state)))))),4);
            tracep->chgCData(oldp+47,(((- (IData)((1U 
                                                   == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_id))),4);
            tracep->chgCData(oldp+48,(((- (IData)((1U 
                                                   == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state)))) 
                                       & (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_len))),8);
            tracep->chgCData(oldp+49,(((- (IData)((1U 
                                                   == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state)))) 
                                       & (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len))),8);
            tracep->chgCData(oldp+50,(((- (IData)((1U 
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
                                                & (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len)))))),8);
            tracep->chgCData(oldp+51,((3U & (- (IData)(
                                                       (1U 
                                                        == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state)))))),3);
            tracep->chgCData(oldp+52,((3U & (- (IData)(
                                                       (1U 
                                                        == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state)))))),3);
            tracep->chgCData(oldp+53,(((- (IData)((1U 
                                                   == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_size))),3);
            tracep->chgCData(oldp+54,((2U & ((- (IData)(
                                                        (1U 
                                                         == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                             & ((- (IData)(
                                                           (1U 
                                                            == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                                | (- (IData)(
                                                             (2U 
                                                              == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))))))),4);
            tracep->chgBit(oldp+55,((2U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))));
            tracep->chgBit(oldp+56,((2U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state))));
            tracep->chgBit(oldp+57,(vlTOPp->SimTop__DOT__cli_r_ready));
            tracep->chgQData(oldp+58,((((((- (QData)((IData)(
                                                             (0U 
                                                              == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))))) 
                                          & (((QData)((IData)(
                                                              (0xffU 
                                                               & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))) 
                                              << 0x38U) 
                                             | (((QData)((IData)(
                                                                 (0xffU 
                                                                  & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))) 
                                                 << 0x30U) 
                                                | (((QData)((IData)(
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
                                         | ((- (QData)((IData)(
                                                               (1U 
                                                                == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))))) 
                                            & (((QData)((IData)(
                                                                (0xffffU 
                                                                 & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))) 
                                                << 0x30U) 
                                               | (((QData)((IData)(
                                                                   (0xffffU 
                                                                    & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))) 
                                                   << 0x20U) 
                                                  | (((QData)((IData)(
                                                                      (0xffffU 
                                                                       & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)))) 
                                                      << 0x10U) 
                                                     | (QData)((IData)(
                                                                       (0xffffU 
                                                                        & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val))))))))) 
                                        | ((- (QData)((IData)(
                                                              (2U 
                                                               == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))))) 
                                           & (((QData)((IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val)) 
                                               << 0x20U) 
                                              | (QData)((IData)(vlTOPp->SimTop__DOT__Clint__DOT__clint_val))))) 
                                       | ((- (QData)((IData)(
                                                             (3U 
                                                              == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))))) 
                                          & vlTOPp->SimTop__DOT__Clint__DOT__clint_val))),64);
            tracep->chgCData(oldp+60,(vlTOPp->SimTop__DOT__Clint__DOT__rd_id_reg),4);
            tracep->chgBit(oldp+61,(vlTOPp->SimTop__DOT__Clint__DOT__rd_user_reg));
            tracep->chgBit(oldp+62,((1U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state))));
            tracep->chgBit(oldp+63,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__rw_ready));
            tracep->chgQData(oldp+64,(vlTOPp->SimTop__DOT__if_r_data),64);
            tracep->chgQData(oldp+66,(vlTOPp->SimTop__DOT__if_rw_addr),64);
            tracep->chgCData(oldp+68,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__rw_resp),2);
            tracep->chgBit(oldp+69,((1U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state))));
            tracep->chgBit(oldp+70,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__rw_ready));
            tracep->chgBit(oldp+71,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena));
            tracep->chgQData(oldp+72,(vlTOPp->SimTop__DOT__mem_r_data),64);
            tracep->chgQData(oldp+74,(vlTOPp->SimTop__DOT__mem_w_data),64);
            tracep->chgQData(oldp+76,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr),64);
            tracep->chgCData(oldp+78,(vlTOPp->SimTop__DOT__mem_rw_size),2);
            tracep->chgCData(oldp+79,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__rw_resp),2);
            tracep->chgSData(oldp+80,(vlTOPp->SimTop__DOT__clint_interupt_bus),12);
            tracep->chgQData(oldp+81,(((- (QData)((IData)(
                                                          (2U 
                                                           == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state))))) 
                                       & vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_data)),64);
            tracep->chgCData(oldp+83,((1U & ((- (IData)(
                                                        (1U 
                                                         == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                             & (- (IData)(
                                                          (1U 
                                                           == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))))))),4);
            tracep->chgBit(oldp+84,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_valid));
            tracep->chgQData(oldp+85,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_addr),64);
            tracep->chgCData(oldp+87,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_id),4);
            tracep->chgCData(oldp+88,((((- (IData)(
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
                                             & (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len))))),8);
            tracep->chgCData(oldp+89,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_size),3);
            tracep->chgCData(oldp+90,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_burst),2);
            tracep->chgCData(oldp+91,((2U & ((- (IData)(
                                                        (1U 
                                                         == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                             | (- (IData)(
                                                          (2U 
                                                           == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))))))),4);
            tracep->chgBit(oldp+92,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_last));
            tracep->chgQData(oldp+93,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_data),64);
            tracep->chgCData(oldp+95,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_strb),8);
            tracep->chgCData(oldp+96,((1U & (- (IData)(
                                                       (1U 
                                                        == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))))),4);
            tracep->chgBit(oldp+97,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_b_ready));
            tracep->chgBit(oldp+98,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_valid));
            tracep->chgQData(oldp+99,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_addr),64);
            tracep->chgCData(oldp+101,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_id),4);
            tracep->chgCData(oldp+102,((((- (IData)(
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
                                              & (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len))))),8);
            tracep->chgCData(oldp+103,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_size),3);
            tracep->chgCData(oldp+104,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_burst),2);
            tracep->chgCData(oldp+105,((2U & ((- (IData)(
                                                         (1U 
                                                          == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                              | (- (IData)(
                                                           (2U 
                                                            == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state))))))),4);
            tracep->chgBit(oldp+106,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_ready));
            tracep->chgBit(oldp+107,(((IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_ready) 
                                      & (1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))));
            tracep->chgBit(oldp+108,((((IData)(vlTOPp->SimTop__DOT__cli_b_ready) 
                                       & (2U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__w_state))) 
                                      & (1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))));
            tracep->chgCData(oldp+109,(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state),2);
            tracep->chgCData(oldp+110,(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state),2);
            tracep->chgBit(oldp+111,((0x200ULL == (0xffffffffffffULL 
                                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr 
                                                      >> 0x10U)))));
            tracep->chgBit(oldp+112,((0x200ULL != (0xffffffffffffULL 
                                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr 
                                                      >> 0x10U)))));
            tracep->chgBit(oldp+113,((0x200ULL == (0xffffffffffffULL 
                                                   & (vlTOPp->SimTop__DOT__if_rw_addr 
                                                      >> 0x10U)))));
            tracep->chgBit(oldp+114,((0x200ULL != (0xffffffffffffULL 
                                                   & (vlTOPp->SimTop__DOT__if_rw_addr 
                                                      >> 0x10U)))));
            tracep->chgCData(oldp+115,(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state),2);
            tracep->chgCData(oldp+116,(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state),2);
            tracep->chgBit(oldp+117,((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))));
            tracep->chgBit(oldp+118,((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))));
            tracep->chgBit(oldp+119,((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state))));
            tracep->chgBit(oldp+120,((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state))));
            tracep->chgBit(oldp+121,((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state))));
            tracep->chgBit(oldp+122,((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state))));
            tracep->chgBit(oldp+123,((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state))));
            tracep->chgBit(oldp+124,((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state))));
            tracep->chgBit(oldp+125,((1U & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena)))));
            tracep->chgBit(oldp+126,(((1U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state)) 
                                      & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena))));
            tracep->chgBit(oldp+127,(((1U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state)) 
                                      & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena)))));
            tracep->chgCData(oldp+128,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state),3);
            tracep->chgCData(oldp+129,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state),3);
            tracep->chgBit(oldp+130,((0U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))));
            tracep->chgBit(oldp+131,((0U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))));
            tracep->chgCData(oldp+132,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__len),8);
            tracep->chgBit(oldp+133,((0U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
            tracep->chgBit(oldp+134,((0U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))));
            tracep->chgBit(oldp+135,((1U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))));
            tracep->chgBit(oldp+136,((2U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))));
            tracep->chgBit(oldp+137,((3U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))));
            tracep->chgCData(oldp+138,((7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))),4);
            tracep->chgCData(oldp+139,((((1U & (- (IData)(
                                                          (1U 
                                                           == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                                         | (3U & (- (IData)(
                                                            (2U 
                                                             == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))) 
                                        | (7U & (- (IData)(
                                                           (3U 
                                                            == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))))),4);
            tracep->chgCData(oldp+140,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__addr_end),4);
            tracep->chgBit(oldp+141,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__addr_end) 
                                            >> 3U))));
            tracep->chgCData(oldp+142,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_len),8);
            tracep->chgCData(oldp+143,((0x38U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                                                 << 3U))),6);
            tracep->chgCData(oldp+144,((0x3fU & (- 
                                                 (0x38U 
                                                  & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                                                     << 3U))))),6);
            tracep->chgWData(oldp+145,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask),128);
            tracep->chgQData(oldp+149,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[0U])))),64);
            tracep->chgQData(oldp+151,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[3U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[2U])))),64);
            tracep->chgCData(oldp+153,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state),3);
            tracep->chgCData(oldp+154,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state),3);
            tracep->chgBit(oldp+155,((0U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state))));
            tracep->chgBit(oldp+156,((0U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state))));
            tracep->chgCData(oldp+157,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__len),8);
            tracep->chgBit(oldp+158,((0U == (7U & (IData)(vlTOPp->SimTop__DOT__if_rw_addr)))));
            tracep->chgCData(oldp+159,((7U & (IData)(vlTOPp->SimTop__DOT__if_rw_addr))),4);
            tracep->chgCData(oldp+160,((0xfU & ((IData)(3U) 
                                                + (7U 
                                                   & (IData)(vlTOPp->SimTop__DOT__if_rw_addr))))),4);
            tracep->chgBit(oldp+161,((1U & (((IData)(3U) 
                                             + (7U 
                                                & (IData)(vlTOPp->SimTop__DOT__if_rw_addr))) 
                                            >> 3U))));
            tracep->chgCData(oldp+162,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len),8);
            tracep->chgCData(oldp+163,((0x38U & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                                 << 3U))),6);
            tracep->chgCData(oldp+164,((0x3fU & (- 
                                                 (0x38U 
                                                  & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                                     << 3U))))),6);
            __Vtemp867[0U] = 0xffffffffU;
            __Vtemp867[1U] = 0U;
            __Vtemp867[2U] = 0U;
            __Vtemp867[3U] = 0U;
            VL_SHIFTL_WWI(128,128,6, __Vtemp868, __Vtemp867, 
                          (0x38U & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                    << 3U)));
            tracep->chgWData(oldp+165,(__Vtemp868),128);
            __Vtemp869[0U] = 0xffffffffU;
            __Vtemp869[1U] = 0U;
            __Vtemp869[2U] = 0U;
            __Vtemp869[3U] = 0U;
            VL_SHIFTL_WWI(128,128,6, __Vtemp870, __Vtemp869, 
                          (0x38U & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                    << 3U)));
            tracep->chgQData(oldp+169,((((QData)((IData)(
                                                         __Vtemp870[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          __Vtemp870[0U])))),64);
            __Vtemp871[0U] = 0xffffffffU;
            __Vtemp871[1U] = 0U;
            __Vtemp871[2U] = 0U;
            __Vtemp871[3U] = 0U;
            VL_SHIFTL_WWI(128,128,6, __Vtemp872, __Vtemp871, 
                          (0x38U & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                    << 3U)));
            tracep->chgQData(oldp+171,((((QData)((IData)(
                                                         __Vtemp872[3U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          __Vtemp872[2U])))),64);
            tracep->chgBit(oldp+173,(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_valid));
            tracep->chgBit(oldp+174,(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_to_wb_valid));
            tracep->chgBit(oldp+175,(vlTOPp->SimTop__DOT__u_cpu__DOT__id_allowin));
            tracep->chgBit(oldp+176,(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_allowin));
            tracep->chgBit(oldp+177,(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_allowin));
            tracep->chgBit(oldp+178,(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake));
            tracep->chgQData(oldp+179,(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_pc),64);
            tracep->chgQData(oldp+181,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_pc_r),64);
            tracep->chgQData(oldp+183,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r),64);
            tracep->chgQData(oldp+185,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_pc_r),64);
            tracep->chgIData(oldp+187,(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_inst),32);
            tracep->chgIData(oldp+188,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r),32);
            tracep->chgIData(oldp+189,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_inst_r),32);
            tracep->chgIData(oldp+190,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_inst_r),32);
            __Vtemp897[0U] = (IData)((((QData)((IData)(
                                                       (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[2U] 
                                                        & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                       << 0x35U) | 
                                      (((QData)((IData)(
                                                        (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[1U] 
                                                         & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                        << 0x15U) | 
                                       ((QData)((IData)(
                                                        (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
                                                         & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                        >> 0xbU))));
            __Vtemp897[1U] = (IData)(((((QData)((IData)(
                                                        (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[2U] 
                                                         & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                        << 0x35U) | 
                                       (((QData)((IData)(
                                                         (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[1U] 
                                                          & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                         << 0x15U) 
                                        | ((QData)((IData)(
                                                           (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
                                                            & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                           >> 0xbU))) 
                                      >> 0x20U));
            __Vtemp897[2U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_data);
            __Vtemp897[3U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_data 
                                      >> 0x20U));
            __Vtemp897[4U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr);
            __Vtemp897[5U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr 
                                      >> 0x20U));
            __Vtemp897[6U] = ((0x20000U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[6U] 
                                            & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                                           >> 0xdU)) 
                              | ((0x1fe00U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[6U] 
                                               & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                                              >> 0xdU)) 
                                 | ((0xffffff00U & 
                                     ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ena) 
                                      << 8U)) | ((0xfffffff8U 
                                                  & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_addr) 
                                                     << 3U)) 
                                                 | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ctrl)))));
            tracep->chgWData(oldp+191,(__Vtemp897),210);
            tracep->chgBit(oldp+198,(((0x7bU == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                      | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                         & ((0xb00U 
                                             == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U))) 
                                            | (0x344U 
                                               == (0xfffU 
                                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                      >> 0x14U))))))));
            __Vtemp900[0U] = ((0xfffffc00U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data) 
                                              << 0xaU)) 
                              | ((0x3fcU & ((((((1U 
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
                                             << (7U 
                                                 & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                            << 2U)) 
                                 | (((IData)((0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info))) 
                                     << 1U) | (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info)))));
            __Vtemp900[1U] = ((0x3ffU & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data) 
                                         >> 0x16U)) 
                              | (0xfffffc00U & ((IData)(
                                                        (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data 
                                                         >> 0x20U)) 
                                                << 0xaU)));
            __Vtemp900[2U] = ((0x3ffU & ((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data 
                                                  >> 0x20U)) 
                                         >> 0x16U)) 
                              | (0xfffffc00U & ((IData)(
                                                        (0xfffffffffffffff8ULL 
                                                         & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)) 
                                                << 0xaU)));
            __Vtemp900[3U] = ((0x3ffU & ((IData)((0xfffffffffffffff8ULL 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)) 
                                         >> 0x16U)) 
                              | (0xfffffc00U & ((IData)(
                                                        ((0xfffffffffffffff8ULL 
                                                          & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                                                         >> 0x20U)) 
                                                << 0xaU)));
            __Vtemp900[4U] = ((0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0U] 
                                              << 0xaU)) 
                              | (0x3ffU & ((IData)(
                                                   ((0xfffffffffffffff8ULL 
                                                     & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                                                    >> 0x20U)) 
                                           >> 0x16U)));
            __Vtemp900[5U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0U] 
                                         >> 0x16U)) 
                              | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[1U] 
                                                << 0xaU)));
            __Vtemp900[6U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[1U] 
                                         >> 0x16U)) 
                              | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[2U] 
                                                << 0xaU)));
            __Vtemp900[7U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[2U] 
                                         >> 0x16U)) 
                              | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[3U] 
                                                << 0xaU)));
            __Vtemp900[8U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[3U] 
                                         >> 0x16U)) 
                              | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[4U] 
                                                << 0xaU)));
            __Vtemp900[9U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[4U] 
                                         >> 0x16U)) 
                              | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[5U] 
                                                << 0xaU)));
            __Vtemp900[0xaU] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[5U] 
                                           >> 0x16U)) 
                                | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[6U] 
                                                  << 0xaU)));
            __Vtemp900[0xbU] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[6U] 
                                           >> 0x16U)) 
                                | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[7U] 
                                                  << 0xaU)));
            __Vtemp900[0xcU] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[7U] 
                                           >> 0x16U)) 
                                | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[8U] 
                                                  << 0xaU)));
            __Vtemp900[0xdU] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[8U] 
                                           >> 0x16U)) 
                                | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[9U] 
                                                  << 0xaU)));
            __Vtemp900[0xeU] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[9U] 
                                           >> 0x16U)) 
                                | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xaU] 
                                                  << 0xaU)));
            __Vtemp900[0xfU] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xaU] 
                                           >> 0x16U)) 
                                | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xbU] 
                                                  << 0xaU)));
            __Vtemp900[0x10U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xbU] 
                                            >> 0x16U)) 
                                 | (0xfffffc00U & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xcU] 
                                                   << 0xaU)));
            __Vtemp900[0x11U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xcU] 
                                            >> 0x16U)) 
                                 | (0xfffffc00U & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xdU] 
                                                   << 0xaU)));
            __Vtemp900[0x12U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xdU] 
                                            >> 0x16U)) 
                                 | (0xfffffc00U & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xeU] 
                                                   << 0xaU)));
            __Vtemp900[0x13U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xeU] 
                                            >> 0x16U)) 
                                 | (0xfffffc00U & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xfU] 
                                                   << 0xaU)));
            __Vtemp900[0x14U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xfU] 
                                            >> 0x16U)) 
                                 | (0xfffffc00U & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x10U] 
                                                   << 0xaU)));
            __Vtemp900[0x15U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x10U] 
                                            >> 0x16U)) 
                                 | (0xfffffc00U & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x11U] 
                                                   << 0xaU)));
            __Vtemp900[0x16U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x11U] 
                                            >> 0x16U)) 
                                 | (0xfffffc00U & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x12U] 
                                                   << 0xaU)));
            tracep->chgWData(oldp+199,(__Vtemp900),715);
            tracep->chgWData(oldp+222,(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus),812);
            tracep->chgWData(oldp+248,(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus),73);
            tracep->chgWData(oldp+251,(vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus),137);
            tracep->chgBit(oldp+256,((0U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state))));
            tracep->chgBit(oldp+257,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld));
            tracep->chgSData(oldp+258,((0xfffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                  >> 0x14U))),12);
            tracep->chgBit(oldp+259,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_ena));
            tracep->chgSData(oldp+260,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr),12);
            tracep->chgBit(oldp+261,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter));
            tracep->chgBit(oldp+262,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_exit));
            tracep->chgWData(oldp+263,(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus),320);
            tracep->chgCData(oldp+273,(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr),5);
            tracep->chgCData(oldp+274,(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr),5);
            tracep->chgBit(oldp+275,(vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_ena));
            tracep->chgCData(oldp+276,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_wdest),5);
            tracep->chgQData(oldp+277,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0]),64);
            tracep->chgQData(oldp+279,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[1]),64);
            tracep->chgQData(oldp+281,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[2]),64);
            tracep->chgQData(oldp+283,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[3]),64);
            tracep->chgQData(oldp+285,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[4]),64);
            tracep->chgQData(oldp+287,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[5]),64);
            tracep->chgQData(oldp+289,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[6]),64);
            tracep->chgQData(oldp+291,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[7]),64);
            tracep->chgQData(oldp+293,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[8]),64);
            tracep->chgQData(oldp+295,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[9]),64);
            tracep->chgQData(oldp+297,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[10]),64);
            tracep->chgQData(oldp+299,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[11]),64);
            tracep->chgQData(oldp+301,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[12]),64);
            tracep->chgQData(oldp+303,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[13]),64);
            tracep->chgQData(oldp+305,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[14]),64);
            tracep->chgQData(oldp+307,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[15]),64);
            tracep->chgQData(oldp+309,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[16]),64);
            tracep->chgQData(oldp+311,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[17]),64);
            tracep->chgQData(oldp+313,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[18]),64);
            tracep->chgQData(oldp+315,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[19]),64);
            tracep->chgQData(oldp+317,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[20]),64);
            tracep->chgQData(oldp+319,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[21]),64);
            tracep->chgQData(oldp+321,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[22]),64);
            tracep->chgQData(oldp+323,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[23]),64);
            tracep->chgQData(oldp+325,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[24]),64);
            tracep->chgQData(oldp+327,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[25]),64);
            tracep->chgQData(oldp+329,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[26]),64);
            tracep->chgQData(oldp+331,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[27]),64);
            tracep->chgQData(oldp+333,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[28]),64);
            tracep->chgQData(oldp+335,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[29]),64);
            tracep->chgQData(oldp+337,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[30]),64);
            tracep->chgQData(oldp+339,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[31]),64);
            tracep->chgBit(oldp+341,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wen));
            tracep->chgCData(oldp+342,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wdest),8);
            tracep->chgQData(oldp+343,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wdata),64);
            tracep->chgQData(oldp+345,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_pc),64);
            tracep->chgIData(oldp+347,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_inst),32);
            tracep->chgBit(oldp+348,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_valid));
            tracep->chgBit(oldp+349,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_skip));
            tracep->chgIData(oldp+350,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_itrp_NO),32);
            tracep->chgIData(oldp+351,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_excp_NO),32);
            tracep->chgQData(oldp+352,(vlTOPp->SimTop__DOT__u_cpu__DOT__cycleCnt),64);
            tracep->chgQData(oldp+354,(vlTOPp->SimTop__DOT__u_cpu__DOT__instrCnt),64);
            tracep->chgQData(oldp+356,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[3U])) 
                                         << 0x3fU) 
                                        | (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[2U])) 
                                            << 0x1fU) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[1U])) 
                                              >> 1U)))),64);
            tracep->chgQData(oldp+358,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[7U])) 
                                         << 0x35U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[6U])) 
                                            << 0x15U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[5U])) 
                                              >> 0xbU)))),64);
            tracep->chgQData(oldp+360,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[5U])) 
                                         << 0x35U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[4U])) 
                                            << 0x15U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[3U])) 
                                              >> 0xbU)))),64);
            tracep->chgIData(oldp+362,(((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[1U] 
                                         << 0x1fU) 
                                        | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0U] 
                                           >> 1U))),32);
            tracep->chgBit(oldp+363,((1U & vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0U])));
            tracep->chgBit(oldp+364,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[3U] 
                                            >> 2U))));
            tracep->chgBit(oldp+365,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[3U] 
                                            >> 1U))));
            tracep->chgBit(oldp+366,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x19U] 
                                            >> 0xbU))));
            tracep->chgCData(oldp+367,((0xffU & ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[4U] 
                                                  << 0x1dU) 
                                                 | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[3U] 
                                                    >> 3U)))),8);
            tracep->chgIData(oldp+368,(((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[9U] 
                                         << 0x15U) 
                                        | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[8U] 
                                           >> 0xbU))),32);
            tracep->chgIData(oldp+369,(((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[8U] 
                                         << 0x15U) 
                                        | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[7U] 
                                           >> 0xbU))),32);
            __Vtemp901[0U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xaU] 
                               << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[9U] 
                                            >> 0xbU));
            __Vtemp901[1U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xbU] 
                               << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xaU] 
                                            >> 0xbU));
            __Vtemp901[2U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xcU] 
                               << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xbU] 
                                            >> 0xbU));
            __Vtemp901[3U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xdU] 
                               << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xcU] 
                                            >> 0xbU));
            __Vtemp901[4U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xeU] 
                               << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xdU] 
                                            >> 0xbU));
            __Vtemp901[5U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xfU] 
                               << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xeU] 
                                            >> 0xbU));
            __Vtemp901[6U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x10U] 
                               << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xfU] 
                                            >> 0xbU));
            __Vtemp901[7U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x11U] 
                               << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x10U] 
                                            >> 0xbU));
            __Vtemp901[8U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x12U] 
                               << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x11U] 
                                            >> 0xbU));
            __Vtemp901[9U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x13U] 
                               << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x12U] 
                                            >> 0xbU));
            __Vtemp901[0xaU] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x14U] 
                                 << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x13U] 
                                              >> 0xbU));
            __Vtemp901[0xbU] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x15U] 
                                 << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x14U] 
                                              >> 0xbU));
            __Vtemp901[0xcU] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x16U] 
                                 << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x15U] 
                                              >> 0xbU));
            __Vtemp901[0xdU] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x17U] 
                                 << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x16U] 
                                              >> 0xbU));
            __Vtemp901[0xeU] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x18U] 
                                 << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x17U] 
                                              >> 0xbU));
            __Vtemp901[0xfU] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x19U] 
                                 << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x18U] 
                                              >> 0xbU));
            tracep->chgWData(oldp+370,(__Vtemp901),512);
            tracep->chgQData(oldp+386,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x19U])) 
                                         << 0x35U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x18U])) 
                                            << 0x15U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x17U])) 
                                              >> 0xbU)))),64);
            tracep->chgQData(oldp+388,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x17U])) 
                                         << 0x35U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x16U])) 
                                            << 0x15U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x15U])) 
                                              >> 0xbU)))),64);
            tracep->chgQData(oldp+390,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x15U])) 
                                         << 0x35U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x14U])) 
                                            << 0x15U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x13U])) 
                                              >> 0xbU)))),64);
            tracep->chgQData(oldp+392,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x13U])) 
                                         << 0x35U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x12U])) 
                                            << 0x15U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x11U])) 
                                              >> 0xbU)))),64);
            tracep->chgQData(oldp+394,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x11U])) 
                                         << 0x35U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x10U])) 
                                            << 0x15U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xfU])) 
                                              >> 0xbU)))),64);
            tracep->chgQData(oldp+396,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xfU])) 
                                         << 0x35U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xeU])) 
                                            << 0x15U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xdU])) 
                                              >> 0xbU)))),64);
            tracep->chgQData(oldp+398,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xdU])) 
                                         << 0x35U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xcU])) 
                                            << 0x15U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xbU])) 
                                              >> 0xbU)))),64);
            tracep->chgQData(oldp+400,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xbU])) 
                                         << 0x35U) 
                                        | (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xaU])) 
                                            << 0x15U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[9U])) 
                                              >> 0xbU)))),64);
            tracep->chgQData(oldp+402,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mstatus),64);
            tracep->chgQData(oldp+404,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mepc),64);
            tracep->chgQData(oldp+406,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mtval),64);
            tracep->chgQData(oldp+408,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mtvec),64);
            tracep->chgQData(oldp+410,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mcause),64);
            tracep->chgQData(oldp+412,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mip),64);
            tracep->chgQData(oldp+414,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mie),64);
            tracep->chgQData(oldp+416,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mscratch),64);
            tracep->chgQData(oldp+418,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_rw_addr),64);
            tracep->chgQData(oldp+420,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_data),64);
            tracep->chgQData(oldp+422,(vlTOPp->SimTop__DOT__u_cpu__DOT__buf_rw_addr),64);
            tracep->chgQData(oldp+424,(vlTOPp->SimTop__DOT__u_cpu__DOT__buf_w_data),64);
            tracep->chgCData(oldp+426,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_mask),8);
            tracep->chgCData(oldp+427,(vlTOPp->SimTop__DOT__u_cpu__DOT__buf_w_mask),8);
            tracep->chgBit(oldp+428,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_ena));
            tracep->chgBit(oldp+429,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_r_ena));
            tracep->chgBit(oldp+430,(vlTOPp->SimTop__DOT__u_cpu__DOT__buf_w_ena));
            tracep->chgBit(oldp+431,(vlTOPp->SimTop__DOT__u_cpu__DOT__buf_r_ena));
            tracep->chgBit(oldp+432,((2U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state))));
            tracep->chgCData(oldp+433,(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state),2);
            tracep->chgBit(oldp+434,(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_valid));
            tracep->chgBit(oldp+435,(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_allowin));
            tracep->chgBit(oldp+436,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_valid));
            tracep->chgCData(oldp+437,((0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)),7);
            tracep->chgCData(oldp+438,((7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                              >> 0xcU))),3);
            tracep->chgCData(oldp+439,((0x3fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x1aU))),6);
            tracep->chgCData(oldp+440,((0x7fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x19U))),7);
            tracep->chgCData(oldp+441,((0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0xfU))),5);
            tracep->chgCData(oldp+442,((0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 7U))),5);
            tracep->chgSData(oldp+443,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immS),12);
            tracep->chgSData(oldp+444,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immB),13);
            tracep->chgIData(oldp+445,((0xfffffU & 
                                        (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                         >> 0xcU))),20);
            tracep->chgIData(oldp+446,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immJ),21);
            tracep->chgBit(oldp+447,((0U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+448,((1U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+449,((2U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+450,((3U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+451,((4U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+452,((5U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+453,((6U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+454,((7U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+455,((0U == (0x3fU 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0x1aU)))));
            tracep->chgBit(oldp+456,((0x10U == (0x3fU 
                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0x1aU)))));
            tracep->chgBit(oldp+457,((0U == (0x7fU 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0x19U)))));
            tracep->chgBit(oldp+458,((0x20U == (0x7fU 
                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0x19U)))));
            tracep->chgBit(oldp+459,((0U == (0xfffU 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0x14U)))));
            tracep->chgBit(oldp+460,((1U == (0xfffU 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0x14U)))));
            tracep->chgBit(oldp+461,((0x302U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+462,((3U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
            tracep->chgBit(oldp+463,((0xfU == (0x7fU 
                                               & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
            tracep->chgBit(oldp+464,((0x13U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
            tracep->chgBit(oldp+465,((0x17U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
            tracep->chgBit(oldp+466,((0x1bU == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
            tracep->chgBit(oldp+467,((0x23U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
            tracep->chgBit(oldp+468,((0x33U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
            tracep->chgBit(oldp+469,((0x37U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
            tracep->chgBit(oldp+470,((0x3bU == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
            tracep->chgBit(oldp+471,((0x63U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
            tracep->chgBit(oldp+472,((0x67U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
            tracep->chgBit(oldp+473,((0x6fU == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
            tracep->chgBit(oldp+474,((0x73U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
            tracep->chgBit(oldp+475,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_excp));
            tracep->chgBit(oldp+476,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm));
            tracep->chgBit(oldp+477,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg));
            tracep->chgBit(oldp+478,((0x7bU == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
            tracep->chgBit(oldp+479,(((0x3bU == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                      | (0x1bU == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))));
            tracep->chgBit(oldp+480,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lb));
            tracep->chgBit(oldp+481,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lh));
            tracep->chgBit(oldp+482,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lw));
            tracep->chgBit(oldp+483,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ld));
            tracep->chgBit(oldp+484,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lbu));
            tracep->chgBit(oldp+485,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lhu));
            tracep->chgBit(oldp+486,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lwu));
            tracep->chgBit(oldp+487,((((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lb) 
                                           | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lh)) 
                                          | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lw)) 
                                         | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ld)) 
                                        | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lbu)) 
                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lhu)) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lwu))));
            tracep->chgBit(oldp+488,((IData)((0xfU 
                                              == (0x707fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))));
            tracep->chgBit(oldp+489,((IData)((0x100fU 
                                              == (0x707fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))));
            tracep->chgBit(oldp+490,(((IData)((0xfU 
                                               == (0x707fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                      | (IData)((0x100fU 
                                                 == 
                                                 (0x707fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))));
            tracep->chgBit(oldp+491,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addi));
            tracep->chgBit(oldp+492,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slli));
            tracep->chgBit(oldp+493,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slti));
            tracep->chgBit(oldp+494,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sltiu));
            tracep->chgBit(oldp+495,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_xori));
            tracep->chgBit(oldp+496,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srli));
            tracep->chgBit(oldp+497,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srai));
            tracep->chgBit(oldp+498,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ori));
            tracep->chgBit(oldp+499,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_andi));
            tracep->chgBit(oldp+500,((((((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addi) 
                                             | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slli)) 
                                            | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slti)) 
                                           | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sltiu)) 
                                          | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_xori)) 
                                         | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srli)) 
                                        | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srai)) 
                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ori)) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_andi))));
            tracep->chgBit(oldp+501,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addiw));
            tracep->chgBit(oldp+502,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slliw));
            tracep->chgBit(oldp+503,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srliw));
            tracep->chgBit(oldp+504,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sraiw));
            tracep->chgBit(oldp+505,(((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addiw) 
                                        | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slliw)) 
                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srliw)) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sraiw))));
            tracep->chgBit(oldp+506,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sb));
            tracep->chgBit(oldp+507,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sh));
            tracep->chgBit(oldp+508,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sw));
            tracep->chgBit(oldp+509,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sd));
            tracep->chgBit(oldp+510,(((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sb) 
                                        | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sh)) 
                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sw)) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sd))));
            tracep->chgBit(oldp+511,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_add));
            tracep->chgBit(oldp+512,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sub));
            tracep->chgBit(oldp+513,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sll));
            tracep->chgBit(oldp+514,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slt));
            tracep->chgBit(oldp+515,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sltu));
            tracep->chgBit(oldp+516,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_xor));
            tracep->chgBit(oldp+517,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srl));
            tracep->chgBit(oldp+518,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sra));
            tracep->chgBit(oldp+519,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_or));
            tracep->chgBit(oldp+520,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_and));
            tracep->chgBit(oldp+521,(((((((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_add) 
                                              | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sub)) 
                                             | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sll)) 
                                            | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slt)) 
                                           | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sltu)) 
                                          | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_xor)) 
                                         | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srl)) 
                                        | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sra)) 
                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_or)) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_and))));
            tracep->chgBit(oldp+522,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addw));
            tracep->chgBit(oldp+523,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_subw));
            tracep->chgBit(oldp+524,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sllw));
            tracep->chgBit(oldp+525,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srlw));
            tracep->chgBit(oldp+526,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sraw));
            tracep->chgBit(oldp+527,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addw) 
                                         | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_subw)) 
                                        | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sllw)) 
                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srlw)) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sraw))));
            tracep->chgBit(oldp+528,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_beq));
            tracep->chgBit(oldp+529,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bne));
            tracep->chgBit(oldp+530,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_blt));
            tracep->chgBit(oldp+531,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bge));
            tracep->chgBit(oldp+532,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bltu));
            tracep->chgBit(oldp+533,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bgeu));
            tracep->chgBit(oldp+534,(((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_beq) 
                                          | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bne)) 
                                         | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_blt)) 
                                        | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bge)) 
                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bltu)) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bgeu))));
            tracep->chgBit(oldp+535,(((0x67U == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                      | (0x6fU == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))));
            tracep->chgBit(oldp+536,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ecall));
            tracep->chgBit(oldp+537,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ebreak));
            tracep->chgBit(oldp+538,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_mret));
            tracep->chgBit(oldp+539,((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ecall) 
                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ebreak)) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_mret))));
            tracep->chgBit(oldp+540,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrw));
            tracep->chgBit(oldp+541,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrs));
            tracep->chgBit(oldp+542,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrc));
            tracep->chgBit(oldp+543,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrwi));
            tracep->chgBit(oldp+544,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrsi));
            tracep->chgBit(oldp+545,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrci));
            tracep->chgBit(oldp+546,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_vld));
            tracep->chgSData(oldp+547,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info),12);
            tracep->chgCData(oldp+548,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_bj_info),8);
            tracep->chgCData(oldp+549,((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lwu) 
                                         << 6U) | (
                                                   ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lhu) 
                                                    << 5U) 
                                                   | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lbu) 
                                                       << 4U) 
                                                      | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ld) 
                                                          << 3U) 
                                                         | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lw) 
                                                             << 2U) 
                                                            | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lh) 
                                                                << 1U) 
                                                               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lb)))))))),7);
            tracep->chgCData(oldp+550,((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sd) 
                                         << 3U) | (
                                                   ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sw) 
                                                    << 2U) 
                                                   | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sh) 
                                                       << 1U) 
                                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sb))))),4);
            tracep->chgBit(oldp+551,((((((((((3U == 
                                              (0x7fU 
                                               & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                             | (0xfU 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                            | (0x13U 
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                           | (0x1bU 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                          | (0x23U 
                                             == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                         | (0x33U == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                        | (0x3bU == 
                                           (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                       | (0x63U == 
                                          (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg))));
            tracep->chgBit(oldp+552,((((0x33U == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                       | (0x3bU == 
                                          (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                      | (0x63U == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))));
            tracep->chgBit(oldp+553,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg))));
            tracep->chgQData(oldp+554,(((((- (QData)((IData)(
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
                                                                    >> 0x14U)))))))),64);
            tracep->chgSData(oldp+556,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_excp_bus),16);
            tracep->chgBit(oldp+557,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid));
            tracep->chgBit(oldp+558,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_ready_go));
            tracep->chgWData(oldp+559,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r),344);
            tracep->chgBit(oldp+570,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_diffbus_r));
            tracep->chgBit(oldp+571,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid));
            tracep->chgBit(oldp+572,((1U & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__hazard)))));
            tracep->chgBit(oldp+573,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_valid) 
                                      & (0U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state)))));
            tracep->chgBit(oldp+574,((1U & ((__Vconst88[0xaU] 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[0xaU] 
                                                & (__Vconst72[0xaU] 
                                                   & (- (IData)(
                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                 & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                            >> 0x15U))));
            tracep->chgQData(oldp+575,((((QData)((IData)(
                                                         (__Vconst88[9U] 
                                                          & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[9U] 
                                                             & (__Vconst72[9U] 
                                                                & (- (IData)(
                                                                             ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                              & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                         << 0x26U) 
                                        | (((QData)((IData)(
                                                            (__Vconst88[8U] 
                                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[8U] 
                                                                & (__Vconst72[8U] 
                                                                   & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                            << 6U) 
                                           | ((QData)((IData)(
                                                              (__Vconst88[7U] 
                                                               & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[7U] 
                                                                  & (__Vconst72[7U] 
                                                                     & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                              >> 0x1aU)))),64);
            tracep->chgQData(oldp+577,((((QData)((IData)(
                                                         (__Vconst88[7U] 
                                                          & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[7U] 
                                                             & (__Vconst72[7U] 
                                                                & (- (IData)(
                                                                             ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                              & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                         << 0x26U) 
                                        | (((QData)((IData)(
                                                            (__Vconst88[6U] 
                                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[6U] 
                                                                & (__Vconst72[6U] 
                                                                   & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                            << 6U) 
                                           | ((QData)((IData)(
                                                              (__Vconst88[5U] 
                                                               & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                                                  & (__Vconst72[5U] 
                                                                     & (- (IData)(
                                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                              >> 0x1aU)))),64);
            tracep->chgBit(oldp+579,((1U & ((__Vconst88[5U] 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                                & (__Vconst72[5U] 
                                                   & (- (IData)(
                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                 & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                            >> 0x19U))));
            tracep->chgBit(oldp+580,((1U & ((__Vconst88[5U] 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                                & (__Vconst72[5U] 
                                                   & (- (IData)(
                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                 & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                            >> 0x18U))));
            tracep->chgBit(oldp+581,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_is_word_opt));
            tracep->chgSData(oldp+582,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info),12);
            tracep->chgCData(oldp+583,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_info),8);
            tracep->chgQData(oldp+584,((((QData)((IData)(
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
                                              >> 3U)))),64);
            tracep->chgCData(oldp+586,((0x7fU & (((
                                                   __Vconst88[3U] 
                                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[3U] 
                                                      & (__Vconst72[3U] 
                                                         & (- (IData)(
                                                                      ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                       & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                                  << 4U) 
                                                 | ((__Vconst88[2U] 
                                                     & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                                        & (__Vconst72[2U] 
                                                           & (- (IData)(
                                                                        ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                         & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                                    >> 0x1cU)))),7);
            tracep->chgCData(oldp+587,((0xfU & (((__Vconst88[3U] 
                                                  & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[3U] 
                                                     & (__Vconst72[3U] 
                                                        & (- (IData)(
                                                                     ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                      & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                                 << 8U) 
                                                | ((__Vconst88[2U] 
                                                    & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                                       & (__Vconst72[2U] 
                                                          & (- (IData)(
                                                                       ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                        & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                                   >> 0x18U)))),4);
            tracep->chgBit(oldp+588,((1U & ((__Vconst88[2U] 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                                & (__Vconst72[2U] 
                                                   & (- (IData)(
                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                 & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                            >> 0x17U))));
            tracep->chgBit(oldp+589,((1U & ((__Vconst88[2U] 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                                & (__Vconst72[2U] 
                                                   & (- (IData)(
                                                                ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                 & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                            >> 0x16U))));
            tracep->chgCData(oldp+590,((7U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                               & (__Vconst72[2U] 
                                                  & (- (IData)(
                                                               ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))))))) 
                                              >> 0x13U))),3);
            tracep->chgBit(oldp+591,((1U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                             & (__Vconst72[2U] 
                                                & (- (IData)(
                                                             ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                              & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))))))) 
                                            >> 0x12U))));
            tracep->chgCData(oldp+592,((0x1fU & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                                  & (__Vconst72[2U] 
                                                     & (- (IData)(
                                                                  ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                   & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))))))) 
                                                 >> 0xdU))),5);
            tracep->chgQData(oldp+593,(((((QData)((IData)(
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
                                                                            & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))))))))))),64);
            tracep->chgBit(oldp+595,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__hazard));
            tracep->chgSData(oldp+596,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus),16);
            tracep->chgBit(oldp+597,((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__meie_allowin) 
                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__mtie_allowin)) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__msie_allowin))));
            tracep->chgQData(oldp+598,((((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter))) 
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
                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[4U])))))),64);
            tracep->chgBit(oldp+600,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__excp_jmp_ena));
            tracep->chgBit(oldp+601,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_valid));
            tracep->chgIData(oldp+602,(((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))) 
                                        & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx))),32);
            tracep->chgIData(oldp+603,(((- (IData)(
                                                   (0U 
                                                    != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus)))) 
                                        & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__excp_idx))),32);
            tracep->chgCData(oldp+604,((0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                                 >> 4U))),5);
            tracep->chgCData(oldp+605,((0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                                 >> 4U))),5);
            tracep->chgBit(oldp+606,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                            >> 3U))));
            tracep->chgBit(oldp+607,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                            >> 3U))));
            tracep->chgQData(oldp+608,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U])) 
                                         << 0x3dU) 
                                        | (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[1U])) 
                                            << 0x1dU) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U])) 
                                              >> 3U)))),64);
            tracep->chgQData(oldp+610,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U])) 
                                         << 0x3dU) 
                                        | (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[3U])) 
                                            << 0x1dU) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[2U])) 
                                              >> 3U)))),64);
            tracep->chgQData(oldp+612,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[2U])) 
                                         << 0x3dU) 
                                        | (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[1U])) 
                                            << 0x1dU) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U])) 
                                              >> 3U)))),64);
            tracep->chgCData(oldp+614,((7U & vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U])),3);
            tracep->chgCData(oldp+615,((7U & vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U])),3);
            tracep->chgBit(oldp+616,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
                                         == (0x1fU 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                                >> 4U))) 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                           >> 3U)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr))) 
                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U])));
            tracep->chgBit(oldp+617,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
                                         == (0x1fU 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                                >> 4U))) 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                           >> 3U)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr))) 
                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U])));
            tracep->chgBit(oldp+618,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
                                         == (0x1fU 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                                >> 4U))) 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                           >> 3U)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr))) 
                                      & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U] 
                                         >> 1U))));
            tracep->chgBit(oldp+619,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
                                         == (0x1fU 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                                >> 4U))) 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                           >> 3U)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr))) 
                                      & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U] 
                                         >> 1U))));
            tracep->chgBit(oldp+620,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
                                      == (0x1fU & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                                   >> 4U)))));
            tracep->chgBit(oldp+621,((0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr))));
            tracep->chgBit(oldp+622,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U] 
                                            >> 1U))));
            tracep->chgBit(oldp+623,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr) 
                                         == (0x1fU 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                                >> 4U))) 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                           >> 3U)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr))) 
                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U])));
            tracep->chgBit(oldp+624,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr) 
                                         == (0x1fU 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                                >> 4U))) 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                           >> 3U)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr))) 
                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U])));
            tracep->chgBit(oldp+625,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr) 
                                         == (0x1fU 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                                >> 4U))) 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                           >> 3U)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr))) 
                                      & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U] 
                                         >> 1U))));
            tracep->chgBit(oldp+626,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr) 
                                         == (0x1fU 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                                >> 4U))) 
                                        & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                           >> 3U)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr))) 
                                      & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U] 
                                         >> 1U))));
            tracep->chgQData(oldp+627,((0x80ULL & (- (QData)((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlTOPp->SimTop__DOT__clint_interupt_bus) 
                                                                         >> 7U))))))),64);
            tracep->chgQData(oldp+629,((((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)) 
                                         << 0x3fU) 
                                        | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)
                                            ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx
                                            : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__excp_idx))),64);
            tracep->chgQData(oldp+631,((((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter))) 
                                         & ((0xffffffffffffff00ULL 
                                             & (((QData)((IData)(
                                                                 vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[9U])) 
                                                 << 0x20U) 
                                                | (0xffffffffffffff00ULL 
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
                                                                          & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U])))))))))),64);
            tracep->chgQData(oldp+633,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[9U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U])))),64);
            tracep->chgQData(oldp+635,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U])))),64);
            tracep->chgQData(oldp+637,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[5U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[4U])))),64);
            tracep->chgQData(oldp+639,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[0U])))),64);
            tracep->chgQData(oldp+641,((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[3U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[2U])))),64);
            tracep->chgBit(oldp+643,((0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus))));
            tracep->chgBit(oldp+644,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__msie_allowin));
            tracep->chgBit(oldp+645,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__mtie_allowin));
            tracep->chgBit(oldp+646,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__meie_allowin));
            tracep->chgBit(oldp+647,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__msie_allowin) 
                                      & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))));
            tracep->chgBit(oldp+648,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__mtie_allowin) 
                                      & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))));
            tracep->chgBit(oldp+649,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__meie_allowin) 
                                      & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))));
            tracep->chgQData(oldp+650,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx),63);
            tracep->chgBit(oldp+652,((1U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus))));
            tracep->chgBit(oldp+653,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                            >> 1U))));
            tracep->chgBit(oldp+654,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                            >> 2U))));
            tracep->chgBit(oldp+655,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                            >> 3U))));
            tracep->chgBit(oldp+656,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                            >> 4U))));
            tracep->chgBit(oldp+657,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                            >> 5U))));
            tracep->chgBit(oldp+658,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                            >> 6U))));
            tracep->chgBit(oldp+659,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                            >> 7U))));
            tracep->chgBit(oldp+660,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                            >> 0xbU))));
            tracep->chgBit(oldp+661,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                            >> 0xcU))));
            tracep->chgBit(oldp+662,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                            >> 0xdU))));
            tracep->chgBit(oldp+663,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                            >> 0xfU))));
            tracep->chgQData(oldp+664,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__excp_idx),63);
            tracep->chgBit(oldp+666,((IData)((0U != 
                                              (0x1003U 
                                               & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus))))));
            tracep->chgBit(oldp+667,((IData)((0U != 
                                              (0xa0f0U 
                                               & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus))))));
            tracep->chgQData(oldp+668,((0xffffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[9U])) 
                                            << 0x18U) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U])) 
                                              >> 8U)))),56);
            tracep->chgBit(oldp+670,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U] 
                                            >> 7U))));
            tracep->chgCData(oldp+671,((7U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[9U] 
                                               << 0x1cU) 
                                              | (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U] 
                                                 >> 4U)))),3);
            tracep->chgBit(oldp+672,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U] 
                                            >> 3U))));
            tracep->chgCData(oldp+673,((7U & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U])),3);
            tracep->chgQData(oldp+674,(((0xffffffffffffff00ULL 
                                         & (((QData)((IData)(
                                                             vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[9U])) 
                                             << 0x20U) 
                                            | (0xffffffffffffff00ULL 
                                               & (QData)((IData)(
                                                                 vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U]))))) 
                                        | (QData)((IData)(
                                                          ((0x80U 
                                                            & (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U] 
                                                               << 4U)) 
                                                           | ((0x70U 
                                                               & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U]) 
                                                              | (7U 
                                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U]))))))),64);
            tracep->chgQData(oldp+676,(((0xffffffffffffff00ULL 
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
                                                                    & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U])))))))),64);
            tracep->chgCData(oldp+678,((3U & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U])),2);
            tracep->chgBit(oldp+679,((0U == (3U & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))));
            tracep->chgBit(oldp+680,((1U == (3U & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))));
            tracep->chgQData(oldp+681,((0x3fffffffffffffffULL 
                                        & (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U])) 
                                            << 0x3eU) 
                                           | (((QData)((IData)(
                                                               vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                               << 0x1eU) 
                                              | ((QData)((IData)(
                                                                 vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U])) 
                                                 >> 2U))))),62);
            tracep->chgQData(oldp+683,(((0xfffffffffffffffcULL 
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
                                                    << 2U)))))),64);
            tracep->chgBit(oldp+685,((1U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info))));
            tracep->chgBit(oldp+686,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                            >> 1U))));
            tracep->chgBit(oldp+687,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                            >> 2U))));
            tracep->chgBit(oldp+688,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                            >> 3U))));
            tracep->chgBit(oldp+689,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                            >> 4U))));
            tracep->chgBit(oldp+690,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                            >> 5U))));
            tracep->chgBit(oldp+691,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                            >> 6U))));
            tracep->chgBit(oldp+692,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                            >> 7U))));
            tracep->chgBit(oldp+693,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                            >> 8U))));
            tracep->chgBit(oldp+694,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                            >> 9U))));
            tracep->chgBit(oldp+695,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                            >> 0xaU))));
            tracep->chgBit(oldp+696,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                            >> 0xbU))));
            tracep->chgBit(oldp+697,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_shift));
            tracep->chgBit(oldp+698,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub));
            tracep->chgBit(oldp+699,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub));
            __Vtemp987[0U] = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                               ? 1U : 0U);
            __Vtemp987[1U] = 0U;
            __Vtemp987[2U] = 0U;
            tracep->chgWData(oldp+700,(__Vtemp987),65);
            tracep->chgBit(oldp+703,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__excp_enter_wr));
            tracep->chgBit(oldp+704,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_exit) 
                                      & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake))));
            tracep->chgBit(oldp+705,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__excp_wr));
            tracep->chgBit(oldp+706,((0x300U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+707,((0x300U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
            tracep->chgBit(oldp+708,(((0x300U == (0xfffU 
                                                  & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                     >> 0x14U))) 
                                      & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld))));
            tracep->chgBit(oldp+709,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_wr_ena));
            tracep->chgQData(oldp+710,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mstatus),64);
            tracep->chgBit(oldp+712,((0x301U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+713,(((0x301U == (0xfffU 
                                                  & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                     >> 0x14U))) 
                                      & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld))));
            tracep->chgBit(oldp+714,((0x304U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+715,((0x304U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
            tracep->chgBit(oldp+716,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                      & (0x304U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+717,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_wr_ena));
            tracep->chgQData(oldp+718,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mie),64);
            tracep->chgBit(oldp+720,((0x305U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+721,((0x305U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
            tracep->chgBit(oldp+722,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                      & (0x305U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+723,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_wr_ena));
            tracep->chgQData(oldp+724,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mtvec),64);
            tracep->chgBit(oldp+726,((0x340U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+727,((0x340U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
            tracep->chgBit(oldp+728,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                      & (0x340U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+729,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_wr_ena));
            tracep->chgQData(oldp+730,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mscratch),64);
            tracep->chgBit(oldp+732,((0x341U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+733,((0x341U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
            tracep->chgBit(oldp+734,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                      & (0x341U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+735,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_wr_ena));
            tracep->chgQData(oldp+736,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mepc),64);
            tracep->chgBit(oldp+738,((0x342U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+739,((0x342U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
            tracep->chgBit(oldp+740,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                      & (0x342U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+741,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_wr_ena));
            tracep->chgQData(oldp+742,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mcause),64);
            tracep->chgBit(oldp+744,((0x343U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+745,((0x343U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
            tracep->chgBit(oldp+746,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                      & (0x343U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+747,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_wr_ena));
            tracep->chgQData(oldp+748,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mtval),64);
            tracep->chgBit(oldp+750,((0x344U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+751,((0x344U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
            tracep->chgBit(oldp+752,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                      & (0x344U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+753,((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_ena) 
                                       & (0x344U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))) 
                                      & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake))));
            tracep->chgQData(oldp+754,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mip),64);
            tracep->chgBit(oldp+756,((0xb00U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+757,((0xb00U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
            tracep->chgBit(oldp+758,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                      & (0xb00U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+759,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcycle_wr_ena));
            tracep->chgQData(oldp+760,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mcycle),64);
            tracep->chgBit(oldp+762,((0xf11U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+763,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                      & (0xf11U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+764,((0xf12U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+765,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                      & (0xf12U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+766,((0xf13U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+767,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                      & (0xf13U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+768,((0xf14U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+769,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                      & (0xf14U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+770,((0x801cc68ULL 
                                      == (0xfffffffffffffffULL 
                                          & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr 
                                             >> 4U)))));
            tracep->chgBit(oldp+771,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid));
            tracep->chgBit(oldp+772,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ready_go));
            tracep->chgWData(oldp+773,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r),223);
            tracep->chgWData(oldp+780,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r),577);
            tracep->chgBit(oldp+799,((1U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[6U] 
                                             & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                                            >> 0x1eU))));
            tracep->chgCData(oldp+800,((0xffU & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[6U] 
                                                  & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                                                 >> 0x16U))),8);
            tracep->chgCData(oldp+801,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info),7);
            tracep->chgCData(oldp+802,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info),4);
            tracep->chgQData(oldp+803,((((QData)((IData)(
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
                                              >> 0xbU)))),64);
            tracep->chgQData(oldp+805,((((QData)((IData)(
                                                         (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[2U] 
                                                          & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                         << 0x35U) 
                                        | (((QData)((IData)(
                                                            (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[1U] 
                                                             & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                            << 0x15U) 
                                           | ((QData)((IData)(
                                                              (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
                                                               & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                              >> 0xbU)))),64);
            tracep->chgBit(oldp+807,((1U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
                                             & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                                            >> 0xaU))));
            tracep->chgCData(oldp+808,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ctrl),3);
            tracep->chgCData(oldp+809,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_addr),5);
            tracep->chgBit(oldp+810,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ena));
            tracep->chgBit(oldp+811,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_valid) 
                                      & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_allowin))));
            tracep->chgBit(oldp+812,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_handshake));
            tracep->chgBit(oldp+813,((1U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info))));
            tracep->chgBit(oldp+814,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info) 
                                            >> 1U))));
            tracep->chgBit(oldp+815,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info) 
                                            >> 2U))));
            tracep->chgBit(oldp+816,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info) 
                                            >> 3U))));
            tracep->chgBit(oldp+817,((1U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info))));
            tracep->chgBit(oldp+818,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                            >> 1U))));
            tracep->chgBit(oldp+819,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                            >> 2U))));
            tracep->chgBit(oldp+820,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                            >> 3U))));
            tracep->chgBit(oldp+821,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                            >> 4U))));
            tracep->chgBit(oldp+822,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                            >> 5U))));
            tracep->chgBit(oldp+823,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                            >> 6U))));
            tracep->chgCData(oldp+824,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state),2);
            tracep->chgQData(oldp+825,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_data),64);
            tracep->chgBit(oldp+827,((2U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state))));
            tracep->chgBit(oldp+828,((1U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
            tracep->chgBit(oldp+829,((2U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
            tracep->chgBit(oldp+830,((3U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
            tracep->chgBit(oldp+831,((4U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
            tracep->chgBit(oldp+832,((5U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
            tracep->chgBit(oldp+833,((6U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
            tracep->chgBit(oldp+834,((7U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
            tracep->chgBit(oldp+835,((0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info))));
            tracep->chgBit(oldp+836,((0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info))));
            tracep->chgQData(oldp+837,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data),64);
            tracep->chgCData(oldp+839,((0xffU & (((
                                                   ((1U 
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
                                                  & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))))),8);
            tracep->chgBit(oldp+840,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid));
            tracep->chgQData(oldp+841,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_pc_r),64);
            tracep->chgIData(oldp+843,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_inst_r),32);
            tracep->chgWData(oldp+844,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r),210);
            tracep->chgWData(oldp+851,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r),715);
            tracep->chgBit(oldp+874,((1U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[6U] 
                                             & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid)))) 
                                            >> 8U))));
            tracep->chgCData(oldp+875,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_reg_wr_ctrl),3);
            tracep->chgQData(oldp+876,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_ex_data),64);
            tracep->chgQData(oldp+878,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_mem_rd_data),64);
            tracep->chgQData(oldp+880,(((((QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[1U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[0U]))) 
                                        & (((QData)((IData)(
                                                            (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid)))))))),64);
            tracep->chgBit(oldp+882,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_reg_wr_ctrl) 
                                            >> 1U))));
            tracep->chgBit(oldp+883,((1U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_reg_wr_ctrl))));
            tracep->chgBit(oldp+884,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_reg_wr_ctrl) 
                                            >> 2U))));
            tracep->chgQData(oldp+885,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0]),64);
            tracep->chgQData(oldp+887,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[1]),64);
            tracep->chgQData(oldp+889,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[2]),64);
            tracep->chgQData(oldp+891,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[3]),64);
            tracep->chgQData(oldp+893,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[4]),64);
            tracep->chgQData(oldp+895,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[5]),64);
            tracep->chgQData(oldp+897,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[6]),64);
            tracep->chgQData(oldp+899,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[7]),64);
            tracep->chgQData(oldp+901,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[8]),64);
            tracep->chgQData(oldp+903,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[9]),64);
            tracep->chgQData(oldp+905,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[10]),64);
            tracep->chgQData(oldp+907,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[11]),64);
            tracep->chgQData(oldp+909,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[12]),64);
            tracep->chgQData(oldp+911,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[13]),64);
            tracep->chgQData(oldp+913,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[14]),64);
            tracep->chgQData(oldp+915,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[15]),64);
            tracep->chgQData(oldp+917,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[16]),64);
            tracep->chgQData(oldp+919,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[17]),64);
            tracep->chgQData(oldp+921,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[18]),64);
            tracep->chgQData(oldp+923,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[19]),64);
            tracep->chgQData(oldp+925,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[20]),64);
            tracep->chgQData(oldp+927,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[21]),64);
            tracep->chgQData(oldp+929,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[22]),64);
            tracep->chgQData(oldp+931,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[23]),64);
            tracep->chgQData(oldp+933,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[24]),64);
            tracep->chgQData(oldp+935,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[25]),64);
            tracep->chgQData(oldp+937,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[26]),64);
            tracep->chgQData(oldp+939,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[27]),64);
            tracep->chgQData(oldp+941,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[28]),64);
            tracep->chgQData(oldp+943,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[29]),64);
            tracep->chgQData(oldp+945,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[30]),64);
            tracep->chgQData(oldp+947,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[31]),64);
            tracep->chgQData(oldp+949,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0]),64);
            tracep->chgQData(oldp+951,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[1]),64);
            tracep->chgQData(oldp+953,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[2]),64);
            tracep->chgQData(oldp+955,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[3]),64);
            tracep->chgQData(oldp+957,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[4]),64);
            tracep->chgQData(oldp+959,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[5]),64);
            tracep->chgQData(oldp+961,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[6]),64);
            tracep->chgQData(oldp+963,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[7]),64);
            tracep->chgQData(oldp+965,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[8]),64);
            tracep->chgQData(oldp+967,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[9]),64);
            tracep->chgQData(oldp+969,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[10]),64);
            tracep->chgQData(oldp+971,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[11]),64);
            tracep->chgQData(oldp+973,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[12]),64);
            tracep->chgQData(oldp+975,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[13]),64);
            tracep->chgQData(oldp+977,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[14]),64);
            tracep->chgQData(oldp+979,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[15]),64);
            tracep->chgQData(oldp+981,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[16]),64);
            tracep->chgQData(oldp+983,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[17]),64);
            tracep->chgQData(oldp+985,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[18]),64);
            tracep->chgQData(oldp+987,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[19]),64);
            tracep->chgQData(oldp+989,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[20]),64);
            tracep->chgQData(oldp+991,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[21]),64);
            tracep->chgQData(oldp+993,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[22]),64);
            tracep->chgQData(oldp+995,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[23]),64);
            tracep->chgQData(oldp+997,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[24]),64);
            tracep->chgQData(oldp+999,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[25]),64);
            tracep->chgQData(oldp+1001,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[26]),64);
            tracep->chgQData(oldp+1003,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[27]),64);
            tracep->chgQData(oldp+1005,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[28]),64);
            tracep->chgQData(oldp+1007,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[29]),64);
            tracep->chgQData(oldp+1009,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[30]),64);
            tracep->chgQData(oldp+1011,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[31]),64);
            tracep->chgBit(oldp+1013,((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_valid) 
                                        & (~ (IData)(
                                                     (0U 
                                                      != vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_excp_NO)))) 
                                       & (~ (IData)(
                                                    (0U 
                                                     != vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_itrp_NO))))));
            tracep->chgIData(oldp+1014,((vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_excp_NO 
                                         & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_valid))))),32);
            tracep->chgQData(oldp+1015,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0U]),64);
            tracep->chgQData(oldp+1017,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [1U]),64);
            tracep->chgQData(oldp+1019,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [2U]),64);
            tracep->chgQData(oldp+1021,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [3U]),64);
            tracep->chgQData(oldp+1023,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [4U]),64);
            tracep->chgQData(oldp+1025,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [5U]),64);
            tracep->chgQData(oldp+1027,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [6U]),64);
            tracep->chgQData(oldp+1029,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [7U]),64);
            tracep->chgQData(oldp+1031,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [8U]),64);
            tracep->chgQData(oldp+1033,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [9U]),64);
            tracep->chgQData(oldp+1035,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0xaU]),64);
            tracep->chgQData(oldp+1037,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0xbU]),64);
            tracep->chgQData(oldp+1039,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0xcU]),64);
            tracep->chgQData(oldp+1041,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0xdU]),64);
            tracep->chgQData(oldp+1043,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0xeU]),64);
            tracep->chgQData(oldp+1045,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0xfU]),64);
            tracep->chgQData(oldp+1047,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x10U]),64);
            tracep->chgQData(oldp+1049,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x11U]),64);
            tracep->chgQData(oldp+1051,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x12U]),64);
            tracep->chgQData(oldp+1053,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x13U]),64);
            tracep->chgQData(oldp+1055,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x14U]),64);
            tracep->chgQData(oldp+1057,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x15U]),64);
            tracep->chgQData(oldp+1059,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x16U]),64);
            tracep->chgQData(oldp+1061,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x17U]),64);
            tracep->chgQData(oldp+1063,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x18U]),64);
            tracep->chgQData(oldp+1065,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x19U]),64);
            tracep->chgQData(oldp+1067,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x1aU]),64);
            tracep->chgQData(oldp+1069,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x1bU]),64);
            tracep->chgQData(oldp+1071,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x1cU]),64);
            tracep->chgQData(oldp+1073,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x1dU]),64);
            tracep->chgQData(oldp+1075,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x1eU]),64);
            tracep->chgQData(oldp+1077,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                        [0x1fU]),64);
            tracep->chgBit(oldp+1079,((0x6bU == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_inst))));
            tracep->chgCData(oldp+1080,((7U & (IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                      [0xaU]))),3);
            tracep->chgQData(oldp+1081,((0x80000003000de122ULL 
                                         & vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mstatus)),64);
            tracep->chgBit(oldp+1083,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_ena) 
                                       & (0x200ULL 
                                          != (0xffffffffffffULL 
                                              & (((QData)((IData)(
                                                                  vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[7U])) 
                                                  << 0x25U) 
                                                 | (((QData)((IData)(
                                                                     vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[6U])) 
                                                     << 5U) 
                                                    | ((QData)((IData)(
                                                                       vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[5U])) 
                                                       >> 0x1bU))))))));
            tracep->chgCData(oldp+1084,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                         & (1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))),4);
            tracep->chgBit(oldp+1085,((((0x2000000ULL 
                                         == vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg) 
                                        | (0x200bff8ULL 
                                           == vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg)) 
                                       | (0x2004000ULL 
                                          == vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg))));
            tracep->chgBit(oldp+1086,((((0x2000000ULL 
                                         == vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg) 
                                        | (0x200bff8ULL 
                                           == vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg)) 
                                       | (0x2004000ULL 
                                          == vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg))));
            tracep->chgIData(oldp+1087,(vlTOPp->SimTop__DOT__Clint__DOT__csr_msip),32);
            tracep->chgQData(oldp+1088,(vlTOPp->SimTop__DOT__Clint__DOT__csr_mtime),64);
            tracep->chgQData(oldp+1090,(vlTOPp->SimTop__DOT__Clint__DOT__csr_mtimecmp),64);
            tracep->chgBit(oldp+1092,(vlTOPp->SimTop__DOT__Clint__DOT__ar_hs));
            tracep->chgBit(oldp+1093,(vlTOPp->SimTop__DOT__Clint__DOT__aw_hs));
            tracep->chgBit(oldp+1094,(((2U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__w_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__cli_b_ready))));
            tracep->chgBit(oldp+1095,(vlTOPp->SimTop__DOT__Clint__DOT__r_state));
            tracep->chgBit(oldp+1096,((1U & (~ (IData)(vlTOPp->SimTop__DOT__Clint__DOT__r_state)))));
            tracep->chgQData(oldp+1097,(vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg),64);
            tracep->chgCData(oldp+1099,(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg),3);
            tracep->chgBit(oldp+1100,((0U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))));
            tracep->chgBit(oldp+1101,((1U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))));
            tracep->chgBit(oldp+1102,((2U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))));
            tracep->chgBit(oldp+1103,((3U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))));
            tracep->chgBit(oldp+1104,((0x2000000ULL 
                                       == vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg)));
            tracep->chgBit(oldp+1105,((0x2004000ULL 
                                       == vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg)));
            tracep->chgBit(oldp+1106,((0x200bff8ULL 
                                       == vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg)));
            tracep->chgQData(oldp+1107,(vlTOPp->SimTop__DOT__Clint__DOT__clint_val),64);
            tracep->chgCData(oldp+1109,(vlTOPp->SimTop__DOT__Clint__DOT__w_state),2);
            tracep->chgBit(oldp+1110,((0U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__w_state))));
            tracep->chgBit(oldp+1111,((1U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__w_state))));
            tracep->chgQData(oldp+1112,(vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg),64);
            tracep->chgCData(oldp+1114,(vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg),3);
            tracep->chgBit(oldp+1115,((0U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg))));
            tracep->chgBit(oldp+1116,((1U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg))));
            tracep->chgBit(oldp+1117,((2U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg))));
            tracep->chgBit(oldp+1118,((3U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg))));
            tracep->chgCData(oldp+1119,((0xffU & ((
                                                   (((1U 
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
                                                   & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg))))),8);
            tracep->chgCData(oldp+1120,(vlTOPp->SimTop__DOT__Clint__DOT__mask_8bits),8);
            tracep->chgQData(oldp+1121,(vlTOPp->SimTop__DOT__Clint__DOT__wr_mask),64);
            tracep->chgBit(oldp+1123,((0x2000000ULL 
                                       == vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg)));
            tracep->chgBit(oldp+1124,((0x2004000ULL 
                                       == vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg)));
            tracep->chgBit(oldp+1125,((0x200bff8ULL 
                                       == vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg)));
        }
        if (VL_UNLIKELY((vlTOPp->__Vm_traceActivity
                         [1U] | vlTOPp->__Vm_traceActivity
                         [2U]))) {
            tracep->chgBit(oldp+1126,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_ready))));
            tracep->chgBit(oldp+1127,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_ready))));
            tracep->chgBit(oldp+1128,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_ready))));
            tracep->chgBit(oldp+1129,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_ready))));
            tracep->chgBit(oldp+1130,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_ready))));
            tracep->chgBit(oldp+1131,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_ready))));
            tracep->chgBit(oldp+1132,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_valid))));
            tracep->chgBit(oldp+1133,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_valid))));
            tracep->chgCData(oldp+1134,(((- (IData)(
                                                    (1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                         & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_resp))),2);
            tracep->chgCData(oldp+1135,(((- (IData)(
                                                    (2U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                         & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_resp))),2);
            tracep->chgBit(oldp+1136,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_last))));
            tracep->chgBit(oldp+1137,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_last))));
            tracep->chgBit(oldp+1138,(((((IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_valid) 
                                         & (2U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))) 
                                        & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_last)) 
                                       & (1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))));
            tracep->chgBit(oldp+1139,(((((IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_valid) 
                                         & (2U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state))) 
                                        & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_last)) 
                                       & (2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))));
            tracep->chgBit(oldp+1140,((((IData)(vlTOPp->SimTop__DOT__mem_axi_b_valid) 
                                        & (3U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))) 
                                       & (1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))));
            tracep->chgBit(oldp+1141,((((IData)(vlTOPp->SimTop__DOT__if_axi_b_valid) 
                                        & (3U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state))) 
                                       & (2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))));
            tracep->chgBit(oldp+1142,((((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                        & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_ready)) 
                                       & (1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state)))));
            tracep->chgBit(oldp+1143,(((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_hs) 
                                       & (2U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)))));
            tracep->chgBit(oldp+1144,((((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__len) 
                                        != (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_len)) 
                                       & ((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_hs) 
                                          | (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_hs)))));
            tracep->chgBit(oldp+1145,(((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__trans_done) 
                                       | (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__rw_ready))));
            tracep->chgQData(oldp+1146,(((vlTOPp->SimTop__DOT__mem_axi_r_data 
                                          & (((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[3U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[2U])))) 
                                         << (0x3fU 
                                             & (- (0x38U 
                                                   & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                                                      << 3U)))))),64);
            tracep->chgBit(oldp+1148,(((3U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__if_axi_b_valid))));
            tracep->chgBit(oldp+1149,((((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                        & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_ready)) 
                                       & (1U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state)))));
            tracep->chgBit(oldp+1150,(((IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_hs) 
                                       & (2U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state)))));
            tracep->chgBit(oldp+1151,((((IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__len) 
                                        != (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len)) 
                                       & ((IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_hs) 
                                          | (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_hs)))));
            tracep->chgBit(oldp+1152,(((IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_done) 
                                       | (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__rw_ready))));
            tracep->chgBit(oldp+1153,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_resp))));
            __Vtemp1028[0U] = 0xffffffffU;
            __Vtemp1028[1U] = 0U;
            __Vtemp1028[2U] = 0U;
            __Vtemp1028[3U] = 0U;
            VL_SHIFTL_WWI(128,128,6, __Vtemp1029, __Vtemp1028, 
                          (0x38U & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                    << 3U)));
            tracep->chgQData(oldp+1154,(((vlTOPp->SimTop__DOT__if_axi_r_data 
                                          & (((QData)((IData)(
                                                              __Vtemp1029[3U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               __Vtemp1029[2U])))) 
                                         << (0x3fU 
                                             & (- (0x38U 
                                                   & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                                      << 3U)))))),64);
            __Vtemp1039[0U] = ((- (IData)((0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus)))) 
                               & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__excp_idx));
            __Vtemp1039[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))) 
                               & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx));
            __Vtemp1039[2U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_rd_data);
            __Vtemp1039[3U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_rd_data 
                                       >> 0x20U));
            __Vtemp1039[4U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_rd_data);
            __Vtemp1039[5U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_rd_data 
                                       >> 0x20U));
            __Vtemp1039[6U] = (IData)((((QData)((IData)(
                                                        vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[9U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[8U]))));
            __Vtemp1039[7U] = (IData)(((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[9U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[8U]))) 
                                       >> 0x20U));
            __Vtemp1039[8U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data);
            __Vtemp1039[9U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data 
                                       >> 0x20U));
            __Vtemp1039[0xaU] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_rd_data);
            __Vtemp1039[0xbU] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_rd_data 
                                         >> 0x20U));
            __Vtemp1039[0xcU] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data);
            __Vtemp1039[0xdU] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data 
                                         >> 0x20U));
            __Vtemp1039[0xeU] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data);
            __Vtemp1039[0xfU] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data 
                                         >> 0x20U));
            __Vtemp1039[0x10U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_rd_data);
            __Vtemp1039[0x11U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_rd_data 
                                          >> 0x20U));
            __Vtemp1039[0x12U] = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_diffbus_r) 
                                  | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid));
            tracep->chgWData(oldp+1156,(__Vtemp1039),577);
            tracep->chgQData(oldp+1175,(((2U & vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U])
                                          ? (((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[2U])) 
                                              << 0x3eU) 
                                             | (((QData)((IData)(
                                                                 vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[1U])) 
                                                 << 0x1eU) 
                                                | ((QData)((IData)(
                                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U])) 
                                                   >> 2U)))
                                          : (4ULL + vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_pc))),64);
            tracep->chgCData(oldp+1177,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__reg_wr_addr),5);
            tracep->chgQData(oldp+1178,(((((QData)((IData)(
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
                                             : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r))),64);
            tracep->chgQData(oldp+1180,(((((- (QData)((IData)(
                                                              (0U 
                                                               != 
                                                               (0x1003U 
                                                                & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus)))))) 
                                           & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r) 
                                          | ((- (QData)((IData)(
                                                                (1U 
                                                                 & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                                                    >> 2U))))) 
                                             & (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_inst_r)))) 
                                         | ((- (QData)((IData)(
                                                               (0U 
                                                                != 
                                                                (0xa0f0U 
                                                                 & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus)))))) 
                                            & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data))),64);
            tracep->chgQData(oldp+1182,(((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res 
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
                                            & (~ vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask)))),64);
            __Vtemp1046[0U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1);
            __Vtemp1046[1U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                       >> 0x20U));
            __Vtemp1046[2U] = (1U & ((~ ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                         >> 3U)) & (IData)(
                                                           (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                            >> 0x3fU))));
            tracep->chgWData(oldp+1184,(__Vtemp1046),65);
            __Vtemp1049[0U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                               & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1));
            __Vtemp1049[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                               & (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                          >> 0x20U)));
            __Vtemp1049[2U] = (1U & ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                                     & ((~ ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                            >> 3U)) 
                                        & (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                   >> 0x3fU)))));
            tracep->chgWData(oldp+1187,(__Vtemp1049),65);
            __Vtemp1055[0U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                               & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                                   ? (~ vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U])
                                   : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U]));
            __Vtemp1055[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                               & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                                   ? (~ vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U])
                                   : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U]));
            __Vtemp1055[2U] = (1U & ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                                     & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                                         ? (~ vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U])
                                         : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U])));
            tracep->chgWData(oldp+1190,(__Vtemp1055),65);
            tracep->chgQData(oldp+1193,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcycle_wr_ena)
                                          ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data
                                          : (1ULL + vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mcycle))),64);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgBit(oldp+1195,(vlTOPp->SimTop__DOT__mem_axi_b_valid));
            tracep->chgBit(oldp+1196,(vlTOPp->SimTop__DOT__if_axi_b_valid));
            tracep->chgQData(oldp+1197,(vlTOPp->SimTop__DOT__mem_axi_r_data),64);
            tracep->chgQData(oldp+1199,(vlTOPp->SimTop__DOT__if_axi_r_data),64);
            tracep->chgBit(oldp+1201,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_ready));
            tracep->chgBit(oldp+1202,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_ready));
            tracep->chgBit(oldp+1203,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_b_valid));
            tracep->chgBit(oldp+1204,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_ready));
            tracep->chgBit(oldp+1205,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_valid));
            tracep->chgCData(oldp+1206,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_resp),2);
            tracep->chgQData(oldp+1207,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_data),64);
            tracep->chgBit(oldp+1209,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_last));
            tracep->chgCData(oldp+1210,(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_next_state),2);
            tracep->chgCData(oldp+1211,(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_next_state),2);
            tracep->chgCData(oldp+1212,(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_next_state),2);
            tracep->chgCData(oldp+1213,(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_next_state),2);
            tracep->chgBit(oldp+1214,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__aw_hs));
            tracep->chgBit(oldp+1215,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_hs));
            tracep->chgBit(oldp+1216,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__b_hs));
            tracep->chgBit(oldp+1217,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_hs));
            tracep->chgBit(oldp+1218,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_done));
            tracep->chgBit(oldp+1219,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__trans_done));
            tracep->chgQData(oldp+1220,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_r_data_l),64);
            tracep->chgBit(oldp+1222,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__aw_hs));
            tracep->chgBit(oldp+1223,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_hs));
            tracep->chgBit(oldp+1224,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_hs));
            tracep->chgBit(oldp+1225,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_done));
            tracep->chgQData(oldp+1226,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_r_data_l),64);
            tracep->chgBit(oldp+1228,(vlTOPp->SimTop__DOT__u_cpu__DOT__if_to_id_valid));
            tracep->chgBit(oldp+1229,(vlTOPp->SimTop__DOT__u_cpu__DOT__id_to_ex_valid));
            tracep->chgWData(oldp+1230,(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus),223);
            __Vtemp1062[0U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_rd_data);
            __Vtemp1062[1U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_rd_data 
                                       >> 0x20U));
            __Vtemp1062[2U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_rd_data);
            __Vtemp1062[3U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_rd_data 
                                       >> 0x20U));
            __Vtemp1062[4U] = (IData)((((QData)((IData)(
                                                        vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[9U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[8U]))));
            __Vtemp1062[5U] = (IData)(((((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[9U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[8U]))) 
                                       >> 0x20U));
            __Vtemp1062[6U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data);
            __Vtemp1062[7U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data 
                                       >> 0x20U));
            __Vtemp1062[8U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_rd_data);
            __Vtemp1062[9U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_rd_data 
                                       >> 0x20U));
            __Vtemp1062[0xaU] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data);
            __Vtemp1062[0xbU] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data 
                                         >> 0x20U));
            __Vtemp1062[0xcU] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data);
            __Vtemp1062[0xdU] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data 
                                         >> 0x20U));
            __Vtemp1062[0xeU] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_rd_data);
            __Vtemp1062[0xfU] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_rd_data 
                                         >> 0x20U));
            tracep->chgWData(oldp+1237,(__Vtemp1062),512);
            tracep->chgWData(oldp+1253,(vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus),66);
            tracep->chgQData(oldp+1256,(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_rd_data),64);
            tracep->chgQData(oldp+1258,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data),64);
            tracep->chgWData(oldp+1260,(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus),320);
            tracep->chgQData(oldp+1270,(vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_data),64);
            tracep->chgQData(oldp+1272,((((QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[2U])) 
                                          << 0x3eU) 
                                         | (((QData)((IData)(
                                                             vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[1U])) 
                                             << 0x1eU) 
                                            | ((QData)((IData)(
                                                               vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U])) 
                                               >> 2U)))),64);
            tracep->chgBit(oldp+1274,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U] 
                                             >> 1U))));
            tracep->chgBit(oldp+1275,((1U & vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U])));
            tracep->chgCData(oldp+1276,(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_next_state),2);
            tracep->chgBit(oldp+1277,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_flush));
            tracep->chgQData(oldp+1278,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2),64);
            tracep->chgBit(oldp+1280,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__reg_wr_ena));
            tracep->chgCData(oldp+1281,((0xffU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs1_forward))),8);
            tracep->chgQData(oldp+1282,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs1_forward),64);
            tracep->chgQData(oldp+1284,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs2_forward),64);
            tracep->chgQData(oldp+1286,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__true_op1),64);
            tracep->chgQData(oldp+1288,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__true_op2),64);
            tracep->chgQData(oldp+1290,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1),64);
            tracep->chgQData(oldp+1292,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2),64);
            tracep->chgCData(oldp+1294,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_data),8);
            tracep->chgQData(oldp+1295,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in1),64);
            tracep->chgCData(oldp+1297,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in2),6);
            tracep->chgQData(oldp+1298,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res),64);
            tracep->chgQData(oldp+1300,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res),64);
            tracep->chgQData(oldp+1302,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask),64);
            tracep->chgWData(oldp+1304,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2),65);
            tracep->chgWData(oldp+1307,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res),65);
            tracep->chgQData(oldp+1310,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res),64);
            tracep->chgQData(oldp+1312,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res),64);
            tracep->chgQData(oldp+1314,((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                         | vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2)),64);
            tracep->chgQData(oldp+1316,((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                         & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2)),64);
            tracep->chgQData(oldp+1318,(((~ vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1) 
                                         & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2)),64);
            tracep->chgQData(oldp+1320,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output),64);
            tracep->chgBit(oldp+1322,((1U & (~ (IData)(
                                                       (0U 
                                                        != vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res))))));
            tracep->chgQData(oldp+1323,((((QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[9U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[8U])))),64);
            tracep->chgQData(oldp+1325,((((QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[1U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[0U])))),64);
            tracep->chgQData(oldp+1327,((((QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[5U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[4U])))),64);
            tracep->chgQData(oldp+1329,((((QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[7U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[6U])))),64);
            tracep->chgQData(oldp+1331,((((QData)((IData)(
                                                          vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[3U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[2U])))),64);
            tracep->chgQData(oldp+1333,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_wr_data_full),64);
            tracep->chgQData(oldp+1335,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_wr_data_full),64);
            tracep->chgQData(oldp+1337,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_rd_data),64);
            tracep->chgQData(oldp+1339,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_rd_data),64);
            tracep->chgQData(oldp+1341,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_rd_data),64);
            tracep->chgQData(oldp+1343,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_rd_data),64);
            tracep->chgQData(oldp+1345,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data),64);
            tracep->chgQData(oldp+1347,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data),64);
            tracep->chgQData(oldp+1349,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data),64);
            tracep->chgBit(oldp+1351,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[0U] 
                                             >> 0xaU))));
            tracep->chgBit(oldp+1352,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[0U] 
                                             >> 9U))));
            tracep->chgCData(oldp+1353,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_next_state),2);
        }
        tracep->chgBit(oldp+1354,(vlTOPp->clock));
        tracep->chgBit(oldp+1355,(vlTOPp->reset));
        tracep->chgQData(oldp+1356,(vlTOPp->io_logCtrl_log_begin),64);
        tracep->chgQData(oldp+1358,(vlTOPp->io_logCtrl_log_end),64);
        tracep->chgQData(oldp+1360,(vlTOPp->io_logCtrl_log_level),64);
        tracep->chgBit(oldp+1362,(vlTOPp->io_perfInfo_clean));
        tracep->chgBit(oldp+1363,(vlTOPp->io_perfInfo_dump));
        tracep->chgBit(oldp+1364,(vlTOPp->io_uart_out_valid));
        tracep->chgCData(oldp+1365,(vlTOPp->io_uart_out_ch),8);
        tracep->chgBit(oldp+1366,(vlTOPp->io_uart_in_valid));
        tracep->chgCData(oldp+1367,(vlTOPp->io_uart_in_ch),8);
        tracep->chgBit(oldp+1368,(vlTOPp->io_memAXI_0_aw_ready));
        tracep->chgBit(oldp+1369,(vlTOPp->io_memAXI_0_aw_valid));
        tracep->chgQData(oldp+1370,(vlTOPp->io_memAXI_0_aw_bits_addr),64);
        tracep->chgCData(oldp+1372,(vlTOPp->io_memAXI_0_aw_bits_prot),3);
        tracep->chgCData(oldp+1373,(vlTOPp->io_memAXI_0_aw_bits_id),4);
        tracep->chgBit(oldp+1374,(vlTOPp->io_memAXI_0_aw_bits_user));
        tracep->chgCData(oldp+1375,(vlTOPp->io_memAXI_0_aw_bits_len),8);
        tracep->chgCData(oldp+1376,(vlTOPp->io_memAXI_0_aw_bits_size),3);
        tracep->chgCData(oldp+1377,(vlTOPp->io_memAXI_0_aw_bits_burst),2);
        tracep->chgBit(oldp+1378,(vlTOPp->io_memAXI_0_aw_bits_lock));
        tracep->chgCData(oldp+1379,(vlTOPp->io_memAXI_0_aw_bits_cache),4);
        tracep->chgCData(oldp+1380,(vlTOPp->io_memAXI_0_aw_bits_qos),4);
        tracep->chgBit(oldp+1381,(vlTOPp->io_memAXI_0_w_ready));
        tracep->chgBit(oldp+1382,(vlTOPp->io_memAXI_0_w_valid));
        tracep->chgQData(oldp+1383,(vlTOPp->io_memAXI_0_w_bits_data[0]),64);
        tracep->chgQData(oldp+1385,(vlTOPp->io_memAXI_0_w_bits_data[1]),64);
        tracep->chgQData(oldp+1387,(vlTOPp->io_memAXI_0_w_bits_data[2]),64);
        tracep->chgQData(oldp+1389,(vlTOPp->io_memAXI_0_w_bits_data[3]),64);
        tracep->chgCData(oldp+1391,(vlTOPp->io_memAXI_0_w_bits_strb),8);
        tracep->chgBit(oldp+1392,(vlTOPp->io_memAXI_0_w_bits_last));
        tracep->chgCData(oldp+1393,(vlTOPp->io_memAXI_0_w_bits_id),4);
        tracep->chgBit(oldp+1394,(vlTOPp->io_memAXI_0_b_ready));
        tracep->chgBit(oldp+1395,(vlTOPp->io_memAXI_0_b_valid));
        tracep->chgCData(oldp+1396,(vlTOPp->io_memAXI_0_b_bits_resp),2);
        tracep->chgCData(oldp+1397,(vlTOPp->io_memAXI_0_b_bits_id),4);
        tracep->chgBit(oldp+1398,(vlTOPp->io_memAXI_0_b_bits_user));
        tracep->chgBit(oldp+1399,(vlTOPp->io_memAXI_0_ar_ready));
        tracep->chgBit(oldp+1400,(vlTOPp->io_memAXI_0_ar_valid));
        tracep->chgQData(oldp+1401,(vlTOPp->io_memAXI_0_ar_bits_addr),64);
        tracep->chgCData(oldp+1403,(vlTOPp->io_memAXI_0_ar_bits_prot),3);
        tracep->chgCData(oldp+1404,(vlTOPp->io_memAXI_0_ar_bits_id),4);
        tracep->chgBit(oldp+1405,(vlTOPp->io_memAXI_0_ar_bits_user));
        tracep->chgCData(oldp+1406,(vlTOPp->io_memAXI_0_ar_bits_len),8);
        tracep->chgCData(oldp+1407,(vlTOPp->io_memAXI_0_ar_bits_size),3);
        tracep->chgCData(oldp+1408,(vlTOPp->io_memAXI_0_ar_bits_burst),2);
        tracep->chgBit(oldp+1409,(vlTOPp->io_memAXI_0_ar_bits_lock));
        tracep->chgCData(oldp+1410,(vlTOPp->io_memAXI_0_ar_bits_cache),4);
        tracep->chgCData(oldp+1411,(vlTOPp->io_memAXI_0_ar_bits_qos),4);
        tracep->chgBit(oldp+1412,(vlTOPp->io_memAXI_0_r_ready));
        tracep->chgBit(oldp+1413,(vlTOPp->io_memAXI_0_r_valid));
        tracep->chgCData(oldp+1414,(vlTOPp->io_memAXI_0_r_bits_resp),2);
        tracep->chgQData(oldp+1415,(vlTOPp->io_memAXI_0_r_bits_data[0]),64);
        tracep->chgQData(oldp+1417,(vlTOPp->io_memAXI_0_r_bits_data[1]),64);
        tracep->chgQData(oldp+1419,(vlTOPp->io_memAXI_0_r_bits_data[2]),64);
        tracep->chgQData(oldp+1421,(vlTOPp->io_memAXI_0_r_bits_data[3]),64);
        tracep->chgBit(oldp+1423,(vlTOPp->io_memAXI_0_r_bits_last));
        tracep->chgCData(oldp+1424,(vlTOPp->io_memAXI_0_r_bits_id),4);
        tracep->chgBit(oldp+1425,(vlTOPp->io_memAXI_0_r_bits_user));
        tracep->chgCData(oldp+1426,(((- (IData)((1U 
                                                 == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                     & ((- (IData)(
                                                   (2U 
                                                    == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                        & (IData)(vlTOPp->io_memAXI_0_b_bits_resp)))),2);
        tracep->chgCData(oldp+1427,(((- (IData)((2U 
                                                 == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                     & ((- (IData)(
                                                   (2U 
                                                    == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                        & (IData)(vlTOPp->io_memAXI_0_b_bits_resp)))),2);
        tracep->chgCData(oldp+1428,(((- (IData)((1U 
                                                 == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                     & (((- (IData)(
                                                    (1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                         & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_id_reg)) 
                                        | ((- (IData)(
                                                      (2U 
                                                       == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                           & (IData)(vlTOPp->io_memAXI_0_b_bits_id))))),4);
        tracep->chgCData(oldp+1429,(((- (IData)((2U 
                                                 == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                     & (((- (IData)(
                                                    (1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                         & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_id_reg)) 
                                        | ((- (IData)(
                                                      (2U 
                                                       == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                           & (IData)(vlTOPp->io_memAXI_0_b_bits_id))))),4);
        tracep->chgBit(oldp+1430,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                   & (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_user_reg)) 
                                      | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                         & (IData)(vlTOPp->io_memAXI_0_b_bits_user))))));
        tracep->chgBit(oldp+1431,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                   & (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_user_reg)) 
                                      | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                         & (IData)(vlTOPp->io_memAXI_0_b_bits_user))))));
        tracep->chgCData(oldp+1432,(((- (IData)((1U 
                                                 == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                     & (((- (IData)(
                                                    (1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                         & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_id_reg)) 
                                        | ((- (IData)(
                                                      (2U 
                                                       == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                           & (IData)(vlTOPp->io_memAXI_0_r_bits_id))))),4);
        tracep->chgCData(oldp+1433,(((- (IData)((2U 
                                                 == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                     & (((- (IData)(
                                                    (1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                         & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_id_reg)) 
                                        | ((- (IData)(
                                                      (2U 
                                                       == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                           & (IData)(vlTOPp->io_memAXI_0_r_bits_id))))),4);
        tracep->chgBit(oldp+1434,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                   & (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_user_reg)) 
                                      | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                         & (IData)(vlTOPp->io_memAXI_0_r_bits_user))))));
        tracep->chgBit(oldp+1435,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                   & (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                       & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_user_reg)) 
                                      | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                         & (IData)(vlTOPp->io_memAXI_0_r_bits_user))))));
        tracep->chgQData(oldp+1436,(vlTOPp->io_memAXI_0_r_bits_data
                                    [0U]),64);
        tracep->chgBit(oldp+1438,((0x801cc68ULL == 
                                   (0xfffffffffffffffULL 
                                    & (vlTOPp->io_memAXI_0_ar_bits_addr 
                                       >> 4U)))));
        tracep->chgBit(oldp+1439,((0x801cc68ULL == 
                                   (0xfffffffffffffffULL 
                                    & (vlTOPp->io_memAXI_0_aw_bits_addr 
                                       >> 4U)))));
        tracep->chgCData(oldp+1440,(((- (IData)((2U 
                                                 == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                     & (IData)(vlTOPp->io_memAXI_0_b_bits_resp))),2);
        tracep->chgCData(oldp+1441,((((- (IData)((1U 
                                                  == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                      & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_id_reg)) 
                                     | ((- (IData)(
                                                   (2U 
                                                    == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                        & (IData)(vlTOPp->io_memAXI_0_b_bits_id)))),4);
        tracep->chgBit(oldp+1442,((((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_user_reg)) 
                                   | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                      & (IData)(vlTOPp->io_memAXI_0_b_bits_user)))));
        tracep->chgCData(oldp+1443,((((- (IData)((1U 
                                                  == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                      & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_id_reg)) 
                                     | ((- (IData)(
                                                   (2U 
                                                    == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                        & (IData)(vlTOPp->io_memAXI_0_r_bits_id)))),4);
        tracep->chgBit(oldp+1444,((((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_user_reg)) 
                                   | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                      & (IData)(vlTOPp->io_memAXI_0_r_bits_user)))));
        tracep->chgBit(oldp+1445,(((((IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_ready) 
                                     & (IData)(vlTOPp->io_memAXI_0_r_valid)) 
                                    & (IData)(vlTOPp->io_memAXI_0_r_bits_last)) 
                                   & (2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))));
        tracep->chgBit(oldp+1446,((((IData)(vlTOPp->io_memAXI_0_b_ready) 
                                    & (IData)(vlTOPp->io_memAXI_0_b_valid)) 
                                   & (2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))));
        tracep->chgBit(oldp+1447,((((IData)(vlTOPp->reset) 
                                    | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena) 
                                       & (0U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)))) 
                                   | ((~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena)) 
                                      & (0U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))))));
        tracep->chgBit(oldp+1448,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena)
                                          ? ((- (IData)(
                                                        (1U 
                                                         == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                             & ((- (IData)(
                                                           (2U 
                                                            == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                                & (IData)(vlTOPp->io_memAXI_0_b_bits_resp)))
                                          : ((- (IData)(
                                                        (1U 
                                                         == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                             & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_resp))))));
        tracep->chgBit(oldp+1449,(((IData)(vlTOPp->reset) 
                                   | (0U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state)))));
        __Vtemp1064[0U] = ((0xfffff800U & ((IData)(
                                                   ((((- (QData)((IData)(
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
                                            << 9U) 
                                           | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lbu) 
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
        __Vtemp1064[1U] = ((0x7ffU & ((IData)(((((- (QData)((IData)(
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
                                      >> 0x15U)) | 
                           (0xfffff800U & ((IData)(
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
        __Vtemp1064[2U] = (0x7ffU & ((IData)((((((- (QData)((IData)(
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
        __Vtemp1070[3U] = ((0xfffffff8U & (((((((((
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
                                            | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg)) 
                                           << 3U)) 
                           | ((0xfffffffcU & ((((0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                                | (0x3bU 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                               | (0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                              << 2U)) 
                              | (3U & ((2U & (((0x3bU 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                               | (0x1bU 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                              << 1U)) 
                                       | ((3U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info) 
                                                 >> 0xbU)) 
                                          | ((3U & 
                                              ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_bj_info) 
                                               >> 0x13U)) 
                                             | (__Vtemp1064[2U] 
                                                >> 0x1eU)))))));
        __Vtemp1071[6U] = ((0xfU & ((IData)(((- (QData)((IData)(
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
        __Vtemp1072[7U] = ((0x1f0U & (((- (IData)((
                                                   (~ (IData)(vlTOPp->reset)) 
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
        __Vtemp1073[7U] = ((0xfffffe00U & (((0x7bU 
                                             == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))
                                             ? 0xaU
                                             : (0x1fU 
                                                & ((- (IData)(
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
                                           << 9U)) 
                           | __Vtemp1072[7U]);
        __Vtemp1081[2U] = ((0xfff80000U & ((((~ (IData)(vlTOPp->reset)) 
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
                                 | ((0xfffff000U & 
                                     (((~ (IData)(vlTOPp->reset)) 
                                       & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm) 
                                          | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg))) 
                                      << 0xcU)) | (0xfffU 
                                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                      >> 0x14U))))));
        __Vtemp1082[0U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_rd_data);
        __Vtemp1082[1U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__csr_rd_data 
                                   >> 0x20U));
        __Vtemp1082[2U] = ((0xffc00000U & ((0xff000000U 
                                            & (__Vtemp1064[0U] 
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
                           | __Vtemp1081[2U]);
        __Vtemp1082[3U] = ((0x3fffffU & ((0x3fffffU 
                                          & (__Vtemp1064[0U] 
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
                                              & (__Vtemp1064[0U] 
                                                 >> 8U)) 
                                             | (0xff000000U 
                                                & (__Vtemp1064[1U] 
                                                   << 0x18U)))));
        __Vtemp1082[4U] = ((0x3fffffU & (__Vtemp1064[1U] 
                                         >> 8U)) | 
                           (0xffc00000U & ((0xc00000U 
                                            & (__Vtemp1064[1U] 
                                               >> 8U)) 
                                           | (0xff000000U 
                                              & (__Vtemp1064[2U] 
                                                 << 0x18U)))));
        __Vtemp1082[5U] = ((0x3fffffU & ((0x3ff800U 
                                          & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info) 
                                             << 0xbU)) 
                                         | ((0x3ffff8U 
                                             & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_bj_info) 
                                                << 3U)) 
                                            | (0x3fffffU 
                                               & (__Vtemp1064[2U] 
                                                  >> 8U))))) 
                           | (0xffc00000U & ((0xfc000000U 
                                              & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2) 
                                                 << 0x1aU)) 
                                             | (__Vtemp1070[3U] 
                                                << 0x16U))));
        __Vtemp1082[6U] = ((0x3fffffU & ((0x3fffffU 
                                          & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2) 
                                             >> 6U)) 
                                         | (__Vtemp1070[3U] 
                                            >> 0xaU))) 
                           | (0xffc00000U & ((0x3c00000U 
                                              & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2) 
                                                 >> 6U)) 
                                             | (0xfc000000U 
                                                & ((IData)(
                                                           (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2 
                                                            >> 0x20U)) 
                                                   << 0x1aU)))));
        __Vtemp1082[7U] = ((0x3fffffU & ((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2 
                                                  >> 0x20U)) 
                                         >> 6U)) | 
                           (0xffc00000U & ((0x3c00000U 
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
        __Vtemp1082[8U] = ((0x3fffffU & ((IData)(((- (QData)((IData)(
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
                                         >> 6U)) | 
                           (0xffc00000U & (__Vtemp1071[6U] 
                                           << 0x16U)));
        __Vtemp1082[9U] = ((0x3fffffU & (__Vtemp1071[6U] 
                                         >> 0xaU)) 
                           | (0xffc00000U & (__Vtemp1073[7U] 
                                             << 0x16U)));
        __Vtemp1082[0xaU] = (0x3fffffU & ((0x200000U 
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
                                                | (__Vtemp1073[7U] 
                                                   >> 0xaU)))));
        VL_EXTEND_WW(344,342, __Vtemp1083, __Vtemp1082);
        tracep->chgWData(oldp+1450,(__Vtemp1083),344);
        tracep->chgQData(oldp+1461,(((- (QData)((IData)(
                                                        (1U 
                                                         & (~ (IData)(vlTOPp->reset)))))) 
                                     & ((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
                                          == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_wdest)) 
                                         & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr)))
                                         ? vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_data
                                         : vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
                                        [vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr]))),64);
        tracep->chgQData(oldp+1463,(((- (QData)((IData)(
                                                        (1U 
                                                         & (~ (IData)(vlTOPp->reset)))))) 
                                     & ((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr) 
                                          == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_wdest)) 
                                         & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr)))
                                         ? vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_data
                                         : vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
                                        [vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr]))),64);
        tracep->chgBit(oldp+1465,((((~ (IData)(vlTOPp->reset)) 
                                    & (1U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state))) 
                                   & (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__rw_ready))));
        tracep->chgBit(oldp+1466,((((~ (IData)(vlTOPp->reset)) 
                                    & (0U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state))) 
                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U])));
        tracep->chgBit(oldp+1467,(((~ (IData)(vlTOPp->reset)) 
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
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                           | (0x33U 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                          | (0x3bU 
                                             == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                         | (0x63U == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                        | (0x67U == 
                                           (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg)) 
                                      | (0x7bU == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))));
        tracep->chgCData(oldp+1468,(((0x7bU == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))
                                      ? 0xaU : (0x1fU 
                                                & ((- (IData)(
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
                                                      >> 0xfU))))),5);
        tracep->chgBit(oldp+1469,(((~ (IData)(vlTOPp->reset)) 
                                   & ((((0x33U == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                        | (0x3bU == 
                                           (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                       | (0x23U == 
                                          (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                      | (0x63U == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))));
        tracep->chgCData(oldp+1470,((0x1fU & ((- (IData)(
                                                         ((~ (IData)(vlTOPp->reset)) 
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
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))),5);
        tracep->chgBit(oldp+1471,(((~ (IData)(vlTOPp->reset)) 
                                   & (0x23U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))));
        tracep->chgBit(oldp+1472,(((~ (IData)(vlTOPp->reset)) 
                                   & (3U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))));
        tracep->chgQData(oldp+1473,(((- (QData)((IData)(
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
                                                                 >> 0xfU)))))))),64);
        tracep->chgBit(oldp+1475,(((~ (IData)(vlTOPp->reset)) 
                                   & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg)))));
        tracep->chgBit(oldp+1476,(((~ (IData)(vlTOPp->reset)) 
                                   & (((((((((0xfU 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                             | (0x13U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                            | (0x17U 
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                           | (0x1bU 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                          | (0x33U 
                                             == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                         | (0x37U == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                        | (0x3bU == 
                                           (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                       | (0x6fU == 
                                          (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                      | (0x67U == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))));
        tracep->chgCData(oldp+1477,(((((~ (IData)(vlTOPp->reset)) 
                                       & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm) 
                                          | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg))) 
                                      << 2U) | ((((~ (IData)(vlTOPp->reset)) 
                                                  & (3U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                                 << 1U) 
                                                | ((~ (IData)(vlTOPp->reset)) 
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
                                                          & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))))),3);
        tracep->chgBit(oldp+1478,((((~ (IData)(vlTOPp->reset)) 
                                    & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid)) 
                                   & (0U != ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_info) 
                                             & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_data))))));
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
    }
}
