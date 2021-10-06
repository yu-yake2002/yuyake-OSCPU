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
    VlWide<3>/*95:0*/ __Vtemp47;
    VlWide<3>/*95:0*/ __Vtemp50;
    VlWide<3>/*95:0*/ __Vtemp56;
    VlWide<3>/*95:0*/ __Vtemp59;
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgBit(oldp+0,((0U != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))));
            tracep->chgBit(oldp+1,(((0U != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info)) 
                                    | (IData)(vlTOPp->SimTop__DOT__excp_exit))));
            tracep->chgQData(oldp+2,((((((((((((1ULL 
                                                & (- (QData)((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                         >> 1U)))))) 
                                               | (2ULL 
                                                  & (- (QData)((IData)(
                                                                       (1U 
                                                                        & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                           >> 2U))))))) 
                                              | (3ULL 
                                                 & (- (QData)((IData)(
                                                                      (1U 
                                                                       & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                          >> 3U))))))) 
                                             | (4ULL 
                                                & (- (QData)((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                         >> 4U))))))) 
                                            | (5ULL 
                                               & (- (QData)((IData)(
                                                                    (1U 
                                                                     & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                        >> 5U))))))) 
                                           | (6ULL 
                                              & (- (QData)((IData)(
                                                                   (1U 
                                                                    & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                       >> 6U))))))) 
                                          | (7ULL & 
                                             (- (QData)((IData)(
                                                                (1U 
                                                                 & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                    >> 7U))))))) 
                                         | (0xbULL 
                                            & (- (QData)((IData)(
                                                                 (1U 
                                                                  & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                     >> 0xbU))))))) 
                                        | (0xcULL & 
                                           (- (QData)((IData)(
                                                              (1U 
                                                               & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                  >> 0xcU))))))) 
                                       | (0xdULL & 
                                          (- (QData)((IData)(
                                                             (1U 
                                                              & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                 >> 0xdU))))))) 
                                      | (0xfULL & (- (QData)((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                         >> 0xfU)))))))),64);
            tracep->chgSData(oldp+4,(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info),16);
            tracep->chgBit(oldp+5,((1U & (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))));
            tracep->chgBit(oldp+6,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                          >> 1U))));
            tracep->chgBit(oldp+7,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                          >> 2U))));
            tracep->chgBit(oldp+8,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                          >> 3U))));
            tracep->chgBit(oldp+9,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                          >> 4U))));
            tracep->chgBit(oldp+10,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                           >> 5U))));
            tracep->chgBit(oldp+11,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                           >> 6U))));
            tracep->chgBit(oldp+12,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                           >> 7U))));
            tracep->chgBit(oldp+13,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                           >> 0xbU))));
            tracep->chgBit(oldp+14,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                           >> 0xcU))));
            tracep->chgBit(oldp+15,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                           >> 0xdU))));
            tracep->chgBit(oldp+16,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                           >> 0xfU))));
            tracep->chgQData(oldp+17,((((((((((((1ULL 
                                                 & (- (QData)((IData)(
                                                                      (1U 
                                                                       & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                          >> 1U)))))) 
                                                | (2ULL 
                                                   & (- (QData)((IData)(
                                                                        (1U 
                                                                         & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                            >> 2U))))))) 
                                               | (3ULL 
                                                  & (- (QData)((IData)(
                                                                       (1U 
                                                                        & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                           >> 3U))))))) 
                                              | (4ULL 
                                                 & (- (QData)((IData)(
                                                                      (1U 
                                                                       & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                          >> 4U))))))) 
                                             | (5ULL 
                                                & (- (QData)((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                         >> 5U))))))) 
                                            | (6ULL 
                                               & (- (QData)((IData)(
                                                                    (1U 
                                                                     & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                        >> 6U))))))) 
                                           | (7ULL 
                                              & (- (QData)((IData)(
                                                                   (1U 
                                                                    & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                       >> 7U))))))) 
                                          | (0xbULL 
                                             & (- (QData)((IData)(
                                                                  (1U 
                                                                   & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                      >> 0xbU))))))) 
                                         | (0xcULL 
                                            & (- (QData)((IData)(
                                                                 (1U 
                                                                  & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                     >> 0xcU))))))) 
                                        | (0xdULL & 
                                           (- (QData)((IData)(
                                                              (1U 
                                                               & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                  >> 0xdU))))))) 
                                       | (0xfULL & 
                                          (- (QData)((IData)(
                                                             (1U 
                                                              & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                 >> 0xfU)))))))),63);
            tracep->chgBit(oldp+19,((IData)((0U != 
                                             (0x1003U 
                                              & (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))))));
            tracep->chgBit(oldp+20,((IData)((0U != 
                                             (0xa0f0U 
                                              & (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))))));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+21,(vlTOPp->SimTop__DOT__byte_enable),8);
            tracep->chgQData(oldp+22,((vlTOPp->SimTop__DOT__mem_ram_wr_src 
                                       << (0x38U & 
                                           ((IData)(vlTOPp->SimTop__DOT__mem_ex_data) 
                                            << 3U)))),64);
            tracep->chgQData(oldp+24,(vlTOPp->SimTop__DOT__ram_rd_data),64);
            tracep->chgQData(oldp+26,((vlTOPp->SimTop__DOT__ex_jmp_imm 
                                       + ((0x40U & (IData)(vlTOPp->SimTop__DOT__ex_bj_info))
                                           ? vlTOPp->SimTop__DOT__rs1_forward
                                           : vlTOPp->SimTop__DOT__ex_pc))),64);
            tracep->chgQData(oldp+28,((QData)((IData)(
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
                                                             & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mepc))))))),64);
            tracep->chgQData(oldp+30,(vlTOPp->SimTop__DOT__id_pc),64);
            tracep->chgIData(oldp+32,(vlTOPp->SimTop__DOT__id_inst),32);
            tracep->chgBit(oldp+33,(vlTOPp->SimTop__DOT__id_valid));
            tracep->chgBit(oldp+34,(((0x3bU == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst)) 
                                     | (0x1bU == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__id_inst)))));
            tracep->chgSData(oldp+35,(vlTOPp->SimTop__DOT__id_alu_info),12);
            tracep->chgCData(oldp+36,(vlTOPp->SimTop__DOT__id_bj_info),8);
            tracep->chgCData(oldp+37,(vlTOPp->SimTop__DOT__id_load_info),7);
            tracep->chgCData(oldp+38,((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sd) 
                                        << 3U) | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sw) 
                                                   << 2U) 
                                                  | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sh) 
                                                      << 1U) 
                                                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sb))))),4);
            tracep->chgQData(oldp+39,(((((- (QData)((IData)(
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
                                                                   >> 0x14U)))))))),64);
            tracep->chgBit(oldp+41,((((((((((3U == 
                                             (0x7fU 
                                              & vlTOPp->SimTop__DOT__id_inst)) 
                                            | (0xfU 
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                           | (0x13U 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__id_inst))) 
                                          | (0x1bU 
                                             == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__id_inst))) 
                                         | (0x23U == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))) 
                                        | (0x33U == 
                                           (0x7fU & vlTOPp->SimTop__DOT__id_inst))) 
                                       | (0x3bU == 
                                          (0x7fU & vlTOPp->SimTop__DOT__id_inst))) 
                                      | (0x63U == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg))));
            tracep->chgBit(oldp+42,((((0x33U == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__id_inst)) 
                                      | (0x3bU == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                     | (0x63U == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__id_inst)))));
            tracep->chgSData(oldp+43,((0xfffU & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U))),12);
            tracep->chgQData(oldp+44,(vlTOPp->SimTop__DOT__ex_pc),64);
            tracep->chgIData(oldp+46,(vlTOPp->SimTop__DOT__ex_inst),32);
            tracep->chgBit(oldp+47,(vlTOPp->SimTop__DOT__ex_is_word_opt));
            tracep->chgSData(oldp+48,(vlTOPp->SimTop__DOT__ex_alu_info),12);
            tracep->chgCData(oldp+49,(vlTOPp->SimTop__DOT__ex_bj_info),8);
            tracep->chgQData(oldp+50,(vlTOPp->SimTop__DOT__ex_jmp_imm),64);
            tracep->chgQData(oldp+52,(vlTOPp->SimTop__DOT__ex_now_op1),64);
            tracep->chgQData(oldp+54,(vlTOPp->SimTop__DOT__ex_now_op2),64);
            tracep->chgBit(oldp+56,(vlTOPp->SimTop__DOT__ex_use_rs1));
            tracep->chgBit(oldp+57,(vlTOPp->SimTop__DOT__ex_use_rs2));
            tracep->chgQData(oldp+58,(vlTOPp->SimTop__DOT__ex_rs1_data),64);
            tracep->chgQData(oldp+60,(vlTOPp->SimTop__DOT__ex_rs2_data),64);
            tracep->chgCData(oldp+62,(vlTOPp->SimTop__DOT__ex_rs1_addr),5);
            tracep->chgCData(oldp+63,(vlTOPp->SimTop__DOT__ex_rs2_addr),5);
            tracep->chgQData(oldp+64,(vlTOPp->SimTop__DOT__ex_csr_data),64);
            tracep->chgBit(oldp+66,(vlTOPp->SimTop__DOT__ex_ram_wr_ena_r));
            tracep->chgBit(oldp+67,(vlTOPp->SimTop__DOT__ex_ram_rd_ena_r));
            tracep->chgBit(oldp+68,(((IData)(vlTOPp->SimTop__DOT__ex_ram_wr_ena_r) 
                                     & (IData)(vlTOPp->SimTop__DOT__ex_valid))));
            tracep->chgBit(oldp+69,(vlTOPp->SimTop__DOT__ex_ram_rd_ena));
            tracep->chgCData(oldp+70,(vlTOPp->SimTop__DOT__ex_load_info),7);
            tracep->chgCData(oldp+71,(vlTOPp->SimTop__DOT__ex_save_info),4);
            tracep->chgCData(oldp+72,(vlTOPp->SimTop__DOT__ex_reg_wr_ctrl),3);
            tracep->chgCData(oldp+73,(vlTOPp->SimTop__DOT__ex_reg_wr_addr),5);
            tracep->chgBit(oldp+74,(vlTOPp->SimTop__DOT__ex_reg_wr_ena_r));
            tracep->chgBit(oldp+75,(((IData)(vlTOPp->SimTop__DOT__ex_reg_wr_ena_r) 
                                     & (IData)(vlTOPp->SimTop__DOT__ex_valid))));
            tracep->chgSData(oldp+76,(vlTOPp->SimTop__DOT__ex_csr_wr_addr),12);
            tracep->chgBit(oldp+77,(vlTOPp->SimTop__DOT__ex_csr_wr_ena_r));
            tracep->chgBit(oldp+78,(((IData)(vlTOPp->SimTop__DOT__ex_csr_wr_ena_r) 
                                     & (IData)(vlTOPp->SimTop__DOT__ex_valid))));
            tracep->chgBit(oldp+79,(vlTOPp->SimTop__DOT__ex_valid));
            tracep->chgQData(oldp+80,(vlTOPp->SimTop__DOT__rs1_forward),64);
            tracep->chgQData(oldp+82,(vlTOPp->SimTop__DOT__rs2_forward),64);
            tracep->chgQData(oldp+84,(vlTOPp->SimTop__DOT__true_op1),64);
            tracep->chgQData(oldp+86,(vlTOPp->SimTop__DOT__true_op2),64);
            tracep->chgQData(oldp+88,(vlTOPp->SimTop__DOT__mem_pc),64);
            tracep->chgIData(oldp+90,(vlTOPp->SimTop__DOT__mem_inst),32);
            tracep->chgCData(oldp+91,(vlTOPp->SimTop__DOT__mem_load_info),7);
            tracep->chgCData(oldp+92,(vlTOPp->SimTop__DOT__mem_save_info),4);
            tracep->chgQData(oldp+93,(vlTOPp->SimTop__DOT__mem_ram_wr_src),64);
            tracep->chgQData(oldp+95,(vlTOPp->SimTop__DOT__mem_ex_data),64);
            tracep->chgQData(oldp+97,(vlTOPp->SimTop__DOT__mem_csr_data),64);
            tracep->chgBit(oldp+99,(vlTOPp->SimTop__DOT__mem_ram_wr_ena));
            tracep->chgBit(oldp+100,(vlTOPp->SimTop__DOT__mem_ram_rd_ena));
            tracep->chgCData(oldp+101,(vlTOPp->SimTop__DOT__mem_reg_wr_ctrl),3);
            tracep->chgCData(oldp+102,(vlTOPp->SimTop__DOT__mem_reg_wr_addr),5);
            tracep->chgBit(oldp+103,(vlTOPp->SimTop__DOT__mem_reg_wr_ena));
            tracep->chgBit(oldp+104,(vlTOPp->SimTop__DOT__mem_csr_wr_ena));
            tracep->chgBit(oldp+105,(vlTOPp->SimTop__DOT__mem_valid));
            tracep->chgQData(oldp+106,(vlTOPp->SimTop__DOT__wb_pc),64);
            tracep->chgIData(oldp+108,(vlTOPp->SimTop__DOT__wb_inst),32);
            tracep->chgCData(oldp+109,(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl),3);
            tracep->chgQData(oldp+110,(vlTOPp->SimTop__DOT__wb_ex_data),64);
            tracep->chgQData(oldp+112,(vlTOPp->SimTop__DOT__wb_ram_data),64);
            tracep->chgQData(oldp+114,(vlTOPp->SimTop__DOT__wb_csr_data),64);
            tracep->chgCData(oldp+116,(vlTOPp->SimTop__DOT__wb_reg_wr_addr),5);
            tracep->chgBit(oldp+117,(vlTOPp->SimTop__DOT__wb_reg_wr_ena));
            tracep->chgSData(oldp+118,(vlTOPp->SimTop__DOT__wb_csr_wr_addr),12);
            tracep->chgBit(oldp+119,(vlTOPp->SimTop__DOT__wb_csr_wr_ena));
            tracep->chgBit(oldp+120,(vlTOPp->SimTop__DOT__wb_valid));
            tracep->chgQData(oldp+121,(vlTOPp->SimTop__DOT__regs[0]),64);
            tracep->chgQData(oldp+123,(vlTOPp->SimTop__DOT__regs[1]),64);
            tracep->chgQData(oldp+125,(vlTOPp->SimTop__DOT__regs[2]),64);
            tracep->chgQData(oldp+127,(vlTOPp->SimTop__DOT__regs[3]),64);
            tracep->chgQData(oldp+129,(vlTOPp->SimTop__DOT__regs[4]),64);
            tracep->chgQData(oldp+131,(vlTOPp->SimTop__DOT__regs[5]),64);
            tracep->chgQData(oldp+133,(vlTOPp->SimTop__DOT__regs[6]),64);
            tracep->chgQData(oldp+135,(vlTOPp->SimTop__DOT__regs[7]),64);
            tracep->chgQData(oldp+137,(vlTOPp->SimTop__DOT__regs[8]),64);
            tracep->chgQData(oldp+139,(vlTOPp->SimTop__DOT__regs[9]),64);
            tracep->chgQData(oldp+141,(vlTOPp->SimTop__DOT__regs[10]),64);
            tracep->chgQData(oldp+143,(vlTOPp->SimTop__DOT__regs[11]),64);
            tracep->chgQData(oldp+145,(vlTOPp->SimTop__DOT__regs[12]),64);
            tracep->chgQData(oldp+147,(vlTOPp->SimTop__DOT__regs[13]),64);
            tracep->chgQData(oldp+149,(vlTOPp->SimTop__DOT__regs[14]),64);
            tracep->chgQData(oldp+151,(vlTOPp->SimTop__DOT__regs[15]),64);
            tracep->chgQData(oldp+153,(vlTOPp->SimTop__DOT__regs[16]),64);
            tracep->chgQData(oldp+155,(vlTOPp->SimTop__DOT__regs[17]),64);
            tracep->chgQData(oldp+157,(vlTOPp->SimTop__DOT__regs[18]),64);
            tracep->chgQData(oldp+159,(vlTOPp->SimTop__DOT__regs[19]),64);
            tracep->chgQData(oldp+161,(vlTOPp->SimTop__DOT__regs[20]),64);
            tracep->chgQData(oldp+163,(vlTOPp->SimTop__DOT__regs[21]),64);
            tracep->chgQData(oldp+165,(vlTOPp->SimTop__DOT__regs[22]),64);
            tracep->chgQData(oldp+167,(vlTOPp->SimTop__DOT__regs[23]),64);
            tracep->chgQData(oldp+169,(vlTOPp->SimTop__DOT__regs[24]),64);
            tracep->chgQData(oldp+171,(vlTOPp->SimTop__DOT__regs[25]),64);
            tracep->chgQData(oldp+173,(vlTOPp->SimTop__DOT__regs[26]),64);
            tracep->chgQData(oldp+175,(vlTOPp->SimTop__DOT__regs[27]),64);
            tracep->chgQData(oldp+177,(vlTOPp->SimTop__DOT__regs[28]),64);
            tracep->chgQData(oldp+179,(vlTOPp->SimTop__DOT__regs[29]),64);
            tracep->chgQData(oldp+181,(vlTOPp->SimTop__DOT__regs[30]),64);
            tracep->chgQData(oldp+183,(vlTOPp->SimTop__DOT__regs[31]),64);
            tracep->chgQData(oldp+185,((((- (QData)((IData)(
                                                            (0U 
                                                             != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))))) 
                                         & ((0xffffffffffffff00ULL 
                                             & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus) 
                                            | (QData)((IData)(
                                                              ((0x80U 
                                                                & ((IData)(
                                                                           (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                                            >> 3U)) 
                                                                   << 7U)) 
                                                               | ((0x70U 
                                                                   & ((IData)(
                                                                              (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                                               >> 4U)) 
                                                                      << 4U)) 
                                                                  | (7U 
                                                                     & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus)))))))) 
                                        | ((- (QData)((IData)(vlTOPp->SimTop__DOT__excp_exit))) 
                                           & ((0xffffffffffffff00ULL 
                                               & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus) 
                                              | (QData)((IData)(
                                                                (0x80U 
                                                                 | ((0x70U 
                                                                     & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                                                >> 4U)) 
                                                                        << 4U)) 
                                                                    | ((8U 
                                                                        & ((IData)(
                                                                                (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                                                >> 7U)) 
                                                                           << 3U)) 
                                                                       | (7U 
                                                                          & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus))))))))))),64);
            tracep->chgQData(oldp+187,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus),64);
            tracep->chgQData(oldp+189,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mie),64);
            tracep->chgQData(oldp+191,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec),64);
            tracep->chgQData(oldp+193,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mscratch),64);
            tracep->chgQData(oldp+195,(((- (QData)((IData)(
                                                           (0U 
                                                            != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))))) 
                                        & vlTOPp->SimTop__DOT__mem_pc)),64);
            tracep->chgQData(oldp+197,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mepc),64);
            tracep->chgQData(oldp+199,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mcause),64);
            tracep->chgQData(oldp+201,((((- (QData)((IData)(
                                                            (0U 
                                                             != 
                                                             (0x1003U 
                                                              & (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info)))))) 
                                         & vlTOPp->SimTop__DOT__mem_pc) 
                                        | ((- (QData)((IData)(
                                                              (1U 
                                                               & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                  >> 2U))))) 
                                           & (QData)((IData)(vlTOPp->SimTop__DOT__mem_inst))))),64);
            tracep->chgQData(oldp+203,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mip),64);
            tracep->chgBit(oldp+205,(vlTOPp->SimTop__DOT__cmt_wen));
            tracep->chgCData(oldp+206,(vlTOPp->SimTop__DOT__cmt_wdest),8);
            tracep->chgQData(oldp+207,(vlTOPp->SimTop__DOT__cmt_wdata),64);
            tracep->chgQData(oldp+209,(vlTOPp->SimTop__DOT__cmt_pc),64);
            tracep->chgIData(oldp+211,(vlTOPp->SimTop__DOT__cmt_inst),32);
            tracep->chgBit(oldp+212,(vlTOPp->SimTop__DOT__vaild));
            tracep->chgBit(oldp+213,(vlTOPp->SimTop__DOT__skip));
            tracep->chgQData(oldp+214,(vlTOPp->SimTop__DOT__cycleCnt),64);
            tracep->chgQData(oldp+216,(vlTOPp->SimTop__DOT__instrCnt),64);
            tracep->chgQData(oldp+218,(vlTOPp->SimTop__DOT__RAM_1W2R__DOT__inst_2),64);
            tracep->chgQData(oldp+220,((((QData)((IData)(
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
                                                                                & (IData)(vlTOPp->SimTop__DOT__byte_enable)))))))))))),64);
            tracep->chgCData(oldp+222,((0x7fU & vlTOPp->SimTop__DOT__id_inst)),7);
            tracep->chgCData(oldp+223,((7U & (vlTOPp->SimTop__DOT__id_inst 
                                              >> 0xcU))),3);
            tracep->chgCData(oldp+224,((0x3fU & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x1aU))),6);
            tracep->chgCData(oldp+225,((0x7fU & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x19U))),7);
            tracep->chgCData(oldp+226,((0x1fU & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 7U))),5);
            tracep->chgSData(oldp+227,(vlTOPp->SimTop__DOT__Id_stage__DOT__immS),12);
            tracep->chgSData(oldp+228,(vlTOPp->SimTop__DOT__Id_stage__DOT__immB),13);
            tracep->chgIData(oldp+229,((0xfffffU & 
                                        (vlTOPp->SimTop__DOT__id_inst 
                                         >> 0xcU))),20);
            tracep->chgIData(oldp+230,(vlTOPp->SimTop__DOT__Id_stage__DOT__immJ),21);
            tracep->chgBit(oldp+231,((0U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+232,((1U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+233,((2U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+234,((3U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+235,((4U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+236,((5U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+237,((6U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+238,((7U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0xcU)))));
            tracep->chgBit(oldp+239,((0U == (0x3fU 
                                             & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0x1aU)))));
            tracep->chgBit(oldp+240,((0x10U == (0x3fU 
                                                & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0x1aU)))));
            tracep->chgBit(oldp+241,((0U == (0x7fU 
                                             & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0x19U)))));
            tracep->chgBit(oldp+242,((0x20U == (0x7fU 
                                                & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0x19U)))));
            tracep->chgBit(oldp+243,((0U == (0xfffU 
                                             & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0x14U)))));
            tracep->chgBit(oldp+244,((1U == (0xfffU 
                                             & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0x14U)))));
            tracep->chgBit(oldp+245,((0x102U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+246,((3U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))));
            tracep->chgBit(oldp+247,((0xfU == (0x7fU 
                                               & vlTOPp->SimTop__DOT__id_inst))));
            tracep->chgBit(oldp+248,((0x13U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst))));
            tracep->chgBit(oldp+249,((0x17U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst))));
            tracep->chgBit(oldp+250,((0x1bU == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst))));
            tracep->chgBit(oldp+251,((0x23U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst))));
            tracep->chgBit(oldp+252,((0x33U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst))));
            tracep->chgBit(oldp+253,((0x37U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst))));
            tracep->chgBit(oldp+254,((0x3bU == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst))));
            tracep->chgBit(oldp+255,((0x63U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst))));
            tracep->chgBit(oldp+256,((0x67U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst))));
            tracep->chgBit(oldp+257,((0x6fU == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst))));
            tracep->chgBit(oldp+258,((0x73U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst))));
            tracep->chgBit(oldp+259,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_excp));
            tracep->chgBit(oldp+260,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm));
            tracep->chgBit(oldp+261,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg));
            tracep->chgBit(oldp+262,((0x7bU == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst))));
            tracep->chgBit(oldp+263,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lb));
            tracep->chgBit(oldp+264,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lh));
            tracep->chgBit(oldp+265,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lw));
            tracep->chgBit(oldp+266,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_ld));
            tracep->chgBit(oldp+267,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lbu));
            tracep->chgBit(oldp+268,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lhu));
            tracep->chgBit(oldp+269,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lwu));
            tracep->chgBit(oldp+270,((((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lb) 
                                           | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lh)) 
                                          | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lw)) 
                                         | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_ld)) 
                                        | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lbu)) 
                                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lhu)) 
                                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lwu))));
            tracep->chgBit(oldp+271,((IData)((0xfU 
                                              == (0x707fU 
                                                  & vlTOPp->SimTop__DOT__id_inst)))));
            tracep->chgBit(oldp+272,((IData)((0x100fU 
                                              == (0x707fU 
                                                  & vlTOPp->SimTop__DOT__id_inst)))));
            tracep->chgBit(oldp+273,(((IData)((0xfU 
                                               == (0x707fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                      | (IData)((0x100fU 
                                                 == 
                                                 (0x707fU 
                                                  & vlTOPp->SimTop__DOT__id_inst))))));
            tracep->chgBit(oldp+274,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addi));
            tracep->chgBit(oldp+275,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slli));
            tracep->chgBit(oldp+276,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slti));
            tracep->chgBit(oldp+277,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sltiu));
            tracep->chgBit(oldp+278,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_xori));
            tracep->chgBit(oldp+279,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srli));
            tracep->chgBit(oldp+280,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srai));
            tracep->chgBit(oldp+281,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_ori));
            tracep->chgBit(oldp+282,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_andi));
            tracep->chgBit(oldp+283,((((((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addi) 
                                             | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slli)) 
                                            | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slti)) 
                                           | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sltiu)) 
                                          | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_xori)) 
                                         | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srli)) 
                                        | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srai)) 
                                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_ori)) 
                                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_andi))));
            tracep->chgBit(oldp+284,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addiw));
            tracep->chgBit(oldp+285,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slliw));
            tracep->chgBit(oldp+286,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srliw));
            tracep->chgBit(oldp+287,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sraiw));
            tracep->chgBit(oldp+288,(((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addiw) 
                                        | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slliw)) 
                                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srliw)) 
                                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sraiw))));
            tracep->chgBit(oldp+289,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sb));
            tracep->chgBit(oldp+290,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sh));
            tracep->chgBit(oldp+291,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sw));
            tracep->chgBit(oldp+292,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sd));
            tracep->chgBit(oldp+293,(((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sb) 
                                        | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sh)) 
                                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sw)) 
                                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sd))));
            tracep->chgBit(oldp+294,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_add));
            tracep->chgBit(oldp+295,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sub));
            tracep->chgBit(oldp+296,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sll));
            tracep->chgBit(oldp+297,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slt));
            tracep->chgBit(oldp+298,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sltu));
            tracep->chgBit(oldp+299,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_xor));
            tracep->chgBit(oldp+300,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srl));
            tracep->chgBit(oldp+301,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sra));
            tracep->chgBit(oldp+302,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_or));
            tracep->chgBit(oldp+303,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_and));
            tracep->chgBit(oldp+304,(((((((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_add) 
                                              | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sub)) 
                                             | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sll)) 
                                            | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slt)) 
                                           | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sltu)) 
                                          | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_xor)) 
                                         | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srl)) 
                                        | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sra)) 
                                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_or)) 
                                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_and))));
            tracep->chgBit(oldp+305,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addw));
            tracep->chgBit(oldp+306,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_subw));
            tracep->chgBit(oldp+307,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sllw));
            tracep->chgBit(oldp+308,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srlw));
            tracep->chgBit(oldp+309,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sraw));
            tracep->chgBit(oldp+310,((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addw) 
                                         | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_subw)) 
                                        | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sllw)) 
                                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srlw)) 
                                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sraw))));
            tracep->chgBit(oldp+311,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_beq));
            tracep->chgBit(oldp+312,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bne));
            tracep->chgBit(oldp+313,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_blt));
            tracep->chgBit(oldp+314,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bge));
            tracep->chgBit(oldp+315,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bltu));
            tracep->chgBit(oldp+316,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bgeu));
            tracep->chgBit(oldp+317,(((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_beq) 
                                          | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bne)) 
                                         | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_blt)) 
                                        | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bge)) 
                                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bltu)) 
                                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bgeu))));
            tracep->chgBit(oldp+318,(((0x67U == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__id_inst)) 
                                      | (0x6fU == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst)))));
            tracep->chgBit(oldp+319,(((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_excp) 
                                      & (0U == (0xfffU 
                                                & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0x14U))))));
            tracep->chgBit(oldp+320,(((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_excp) 
                                      & (1U == (0xfffU 
                                                & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0x14U))))));
            tracep->chgBit(oldp+321,(((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_excp) 
                                      & (0x102U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+322,(((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_excp) 
                                      & (((0U == (0xfffU 
                                                  & (vlTOPp->SimTop__DOT__id_inst 
                                                     >> 0x14U))) 
                                          | (1U == 
                                             (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))) 
                                         | (0x102U 
                                            == (0xfffU 
                                                & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0x14U)))))));
            tracep->chgBit(oldp+323,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrw));
            tracep->chgBit(oldp+324,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrs));
            tracep->chgBit(oldp+325,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrc));
            tracep->chgBit(oldp+326,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrwi));
            tracep->chgBit(oldp+327,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrsi));
            tracep->chgBit(oldp+328,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrci));
            tracep->chgBit(oldp+329,(((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrw) 
                                          | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrs)) 
                                         | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrc)) 
                                        | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrwi)) 
                                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrsi)) 
                                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrci))));
            tracep->chgBit(oldp+330,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_vld));
            tracep->chgBit(oldp+331,((((((IData)(vlTOPp->SimTop__DOT__ex_rs1_addr) 
                                         == (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_addr)) 
                                        & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ena)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs1_addr))) 
                                      & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ctrl))));
            tracep->chgBit(oldp+332,((((((IData)(vlTOPp->SimTop__DOT__ex_rs1_addr) 
                                         == (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)) 
                                        & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ena)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs1_addr))) 
                                      & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl))));
            tracep->chgBit(oldp+333,((((((IData)(vlTOPp->SimTop__DOT__ex_rs1_addr) 
                                         == (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_addr)) 
                                        & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ena)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs1_addr))) 
                                      & ((IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ctrl) 
                                         >> 1U))));
            tracep->chgBit(oldp+334,((((((IData)(vlTOPp->SimTop__DOT__ex_rs1_addr) 
                                         == (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)) 
                                        & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ena)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs1_addr))) 
                                      & ((IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl) 
                                         >> 1U))));
            tracep->chgBit(oldp+335,((((((IData)(vlTOPp->SimTop__DOT__ex_rs2_addr) 
                                         == (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_addr)) 
                                        & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ena)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs2_addr))) 
                                      & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ctrl))));
            tracep->chgBit(oldp+336,((((((IData)(vlTOPp->SimTop__DOT__ex_rs2_addr) 
                                         == (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)) 
                                        & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ena)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs2_addr))) 
                                      & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl))));
            tracep->chgBit(oldp+337,((((((IData)(vlTOPp->SimTop__DOT__ex_rs2_addr) 
                                         == (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_addr)) 
                                        & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ena)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs2_addr))) 
                                      & ((IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ctrl) 
                                         >> 1U))));
            tracep->chgBit(oldp+338,((((((IData)(vlTOPp->SimTop__DOT__ex_rs2_addr) 
                                         == (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)) 
                                        & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ena)) 
                                       & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs2_addr))) 
                                      & ((IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl) 
                                         >> 1U))));
            tracep->chgCData(oldp+339,(vlTOPp->SimTop__DOT__Ex_stage__DOT__bj_data),8);
            tracep->chgQData(oldp+340,(vlTOPp->SimTop__DOT__Ex_stage__DOT__op1),64);
            tracep->chgQData(oldp+342,(vlTOPp->SimTop__DOT__Ex_stage__DOT__op2),64);
            tracep->chgBit(oldp+344,((1U & (IData)(vlTOPp->SimTop__DOT__ex_alu_info))));
            tracep->chgBit(oldp+345,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                            >> 1U))));
            tracep->chgBit(oldp+346,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                            >> 2U))));
            tracep->chgBit(oldp+347,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                            >> 3U))));
            tracep->chgBit(oldp+348,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                            >> 4U))));
            tracep->chgBit(oldp+349,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                            >> 5U))));
            tracep->chgBit(oldp+350,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                            >> 6U))));
            tracep->chgBit(oldp+351,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                            >> 7U))));
            tracep->chgBit(oldp+352,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                            >> 8U))));
            tracep->chgBit(oldp+353,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                            >> 9U))));
            tracep->chgBit(oldp+354,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                            >> 0xaU))));
            tracep->chgBit(oldp+355,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                            >> 0xbU))));
            tracep->chgBit(oldp+356,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_shift));
            tracep->chgQData(oldp+357,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in1),64);
            tracep->chgCData(oldp+359,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in2),6);
            tracep->chgQData(oldp+360,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res),64);
            tracep->chgQData(oldp+362,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res),64);
            tracep->chgQData(oldp+364,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask),64);
            tracep->chgQData(oldp+366,(((vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res 
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
                                           & (~ vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask)))),64);
            tracep->chgBit(oldp+368,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub));
            tracep->chgBit(oldp+369,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub));
            __Vtemp47[0U] = (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__op1);
            __Vtemp47[1U] = (IData)((vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                     >> 0x20U));
            __Vtemp47[2U] = (1U & ((~ ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                       >> 3U)) & (IData)(
                                                         (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                          >> 0x3fU))));
            tracep->chgWData(oldp+370,(__Vtemp47),65);
            tracep->chgWData(oldp+373,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2),65);
            __Vtemp50[0U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                             & (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__op1));
            __Vtemp50[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                             & (IData)((vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                        >> 0x20U)));
            __Vtemp50[2U] = (1U & ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                                   & ((~ ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                          >> 3U)) & (IData)(
                                                            (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                             >> 0x3fU)))));
            tracep->chgWData(oldp+376,(__Vtemp50),65);
            __Vtemp56[0U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                             & ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                                 ? (~ vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U])
                                 : vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U]));
            __Vtemp56[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                             & ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                                 ? (~ vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U])
                                 : vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U]));
            __Vtemp56[2U] = (1U & ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                                   & ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                                       ? (~ vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U])
                                       : vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U])));
            tracep->chgWData(oldp+379,(__Vtemp56),65);
            __Vtemp59[0U] = ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                              ? 1U : 0U);
            __Vtemp59[1U] = 0U;
            __Vtemp59[2U] = 0U;
            tracep->chgWData(oldp+382,(__Vtemp59),65);
            tracep->chgWData(oldp+385,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res),65);
            tracep->chgQData(oldp+388,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res),64);
            tracep->chgQData(oldp+390,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res),64);
            tracep->chgQData(oldp+392,((vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                        | vlTOPp->SimTop__DOT__Ex_stage__DOT__op2)),64);
            tracep->chgQData(oldp+394,((vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                        & vlTOPp->SimTop__DOT__Ex_stage__DOT__op2)),64);
            tracep->chgQData(oldp+396,(((~ vlTOPp->SimTop__DOT__Ex_stage__DOT__op1) 
                                        & vlTOPp->SimTop__DOT__Ex_stage__DOT__op2)),64);
            tracep->chgBit(oldp+398,((1U & (~ (IData)(
                                                      (0U 
                                                       != vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res))))));
            tracep->chgBit(oldp+399,((0U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
            tracep->chgBit(oldp+400,((1U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
            tracep->chgBit(oldp+401,((2U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
            tracep->chgBit(oldp+402,((3U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
            tracep->chgBit(oldp+403,((4U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
            tracep->chgBit(oldp+404,((5U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
            tracep->chgBit(oldp+405,((6U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
            tracep->chgBit(oldp+406,((7U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
            tracep->chgBit(oldp+407,((1U & (IData)(vlTOPp->SimTop__DOT__mem_load_info))));
            tracep->chgBit(oldp+408,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                            >> 1U))));
            tracep->chgBit(oldp+409,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                            >> 2U))));
            tracep->chgBit(oldp+410,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                            >> 3U))));
            tracep->chgBit(oldp+411,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                            >> 4U))));
            tracep->chgBit(oldp+412,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                            >> 5U))));
            tracep->chgBit(oldp+413,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                            >> 6U))));
            tracep->chgQData(oldp+414,(vlTOPp->SimTop__DOT__Mem_stage__DOT__mem_part),64);
            tracep->chgBit(oldp+416,((1U & (IData)(vlTOPp->SimTop__DOT__mem_save_info))));
            tracep->chgBit(oldp+417,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                            >> 1U))));
            tracep->chgBit(oldp+418,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                            >> 2U))));
            tracep->chgBit(oldp+419,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                            >> 3U))));
            tracep->chgBit(oldp+420,((1U & ((IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl) 
                                            >> 1U))));
            tracep->chgBit(oldp+421,((1U & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl))));
            tracep->chgBit(oldp+422,((1U & ((IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl) 
                                            >> 2U))));
            tracep->chgQData(oldp+423,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0]),64);
            tracep->chgQData(oldp+425,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[1]),64);
            tracep->chgQData(oldp+427,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[2]),64);
            tracep->chgQData(oldp+429,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[3]),64);
            tracep->chgQData(oldp+431,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[4]),64);
            tracep->chgQData(oldp+433,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[5]),64);
            tracep->chgQData(oldp+435,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[6]),64);
            tracep->chgQData(oldp+437,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[7]),64);
            tracep->chgQData(oldp+439,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[8]),64);
            tracep->chgQData(oldp+441,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[9]),64);
            tracep->chgQData(oldp+443,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[10]),64);
            tracep->chgQData(oldp+445,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[11]),64);
            tracep->chgQData(oldp+447,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[12]),64);
            tracep->chgQData(oldp+449,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[13]),64);
            tracep->chgQData(oldp+451,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[14]),64);
            tracep->chgQData(oldp+453,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[15]),64);
            tracep->chgQData(oldp+455,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[16]),64);
            tracep->chgQData(oldp+457,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[17]),64);
            tracep->chgQData(oldp+459,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[18]),64);
            tracep->chgQData(oldp+461,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[19]),64);
            tracep->chgQData(oldp+463,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[20]),64);
            tracep->chgQData(oldp+465,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[21]),64);
            tracep->chgQData(oldp+467,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[22]),64);
            tracep->chgQData(oldp+469,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[23]),64);
            tracep->chgQData(oldp+471,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[24]),64);
            tracep->chgQData(oldp+473,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[25]),64);
            tracep->chgQData(oldp+475,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[26]),64);
            tracep->chgQData(oldp+477,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[27]),64);
            tracep->chgQData(oldp+479,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[28]),64);
            tracep->chgQData(oldp+481,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[29]),64);
            tracep->chgQData(oldp+483,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[30]),64);
            tracep->chgQData(oldp+485,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[31]),64);
            tracep->chgQData(oldp+487,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[0]),64);
            tracep->chgQData(oldp+489,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[1]),64);
            tracep->chgQData(oldp+491,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[2]),64);
            tracep->chgQData(oldp+493,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[3]),64);
            tracep->chgQData(oldp+495,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[4]),64);
            tracep->chgQData(oldp+497,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[5]),64);
            tracep->chgQData(oldp+499,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[6]),64);
            tracep->chgQData(oldp+501,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[7]),64);
            tracep->chgQData(oldp+503,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[8]),64);
            tracep->chgQData(oldp+505,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[9]),64);
            tracep->chgQData(oldp+507,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[10]),64);
            tracep->chgQData(oldp+509,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[11]),64);
            tracep->chgQData(oldp+511,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[12]),64);
            tracep->chgQData(oldp+513,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[13]),64);
            tracep->chgQData(oldp+515,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[14]),64);
            tracep->chgQData(oldp+517,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[15]),64);
            tracep->chgQData(oldp+519,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[16]),64);
            tracep->chgQData(oldp+521,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[17]),64);
            tracep->chgQData(oldp+523,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[18]),64);
            tracep->chgQData(oldp+525,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[19]),64);
            tracep->chgQData(oldp+527,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[20]),64);
            tracep->chgQData(oldp+529,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[21]),64);
            tracep->chgQData(oldp+531,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[22]),64);
            tracep->chgQData(oldp+533,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[23]),64);
            tracep->chgQData(oldp+535,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[24]),64);
            tracep->chgQData(oldp+537,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[25]),64);
            tracep->chgQData(oldp+539,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[26]),64);
            tracep->chgQData(oldp+541,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[27]),64);
            tracep->chgQData(oldp+543,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[28]),64);
            tracep->chgQData(oldp+545,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[29]),64);
            tracep->chgQData(oldp+547,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[30]),64);
            tracep->chgQData(oldp+549,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[31]),64);
            tracep->chgSData(oldp+551,((0xffffU & (
                                                   (0xfffcU 
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
                                                      & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mepc))))),16);
            tracep->chgQData(oldp+552,((0xffffffffffffffULL 
                                        & (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                           >> 8U))),56);
            tracep->chgBit(oldp+554,((1U & (IData)(
                                                   (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                    >> 7U)))));
            tracep->chgCData(oldp+555,((7U & (IData)(
                                                     (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                      >> 4U)))),3);
            tracep->chgBit(oldp+556,((1U & (IData)(
                                                   (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                    >> 3U)))));
            tracep->chgCData(oldp+557,((7U & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus))),3);
            tracep->chgQData(oldp+558,(((0xffffffffffffff00ULL 
                                         & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus) 
                                        | (QData)((IData)(
                                                          ((0x80U 
                                                            & ((IData)(
                                                                       (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                                        >> 3U)) 
                                                               << 7U)) 
                                                           | ((0x70U 
                                                               & ((IData)(
                                                                          (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                                           >> 4U)) 
                                                                  << 4U)) 
                                                              | (7U 
                                                                 & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus)))))))),64);
            tracep->chgQData(oldp+560,(((0xffffffffffffff00ULL 
                                         & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus) 
                                        | (QData)((IData)(
                                                          (0x80U 
                                                           | ((0x70U 
                                                               & ((IData)(
                                                                          (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                                           >> 4U)) 
                                                                  << 4U)) 
                                                              | ((8U 
                                                                  & ((IData)(
                                                                             (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                                              >> 7U)) 
                                                                     << 3U)) 
                                                                 | (7U 
                                                                    & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus))))))))),64);
            tracep->chgCData(oldp+562,((3U & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec))),2);
            tracep->chgBit(oldp+563,((0U == (3U & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec)))));
            tracep->chgBit(oldp+564,((1U == (3U & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec)))));
            tracep->chgQData(oldp+565,((0x3fffffffffffffffULL 
                                        & (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec 
                                           >> 2U))),62);
            tracep->chgQData(oldp+567,(((0xfffffffffffffffcULL 
                                         & ((- (QData)((IData)(
                                                               (0U 
                                                                == 
                                                                (3U 
                                                                 & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec)))))) 
                                            & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec)) 
                                        | (0x3ffffffffffffffcULL 
                                           & ((- (QData)((IData)(
                                                                 (1U 
                                                                  == 
                                                                  (3U 
                                                                   & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec)))))) 
                                              & (((- (QData)((IData)(
                                                                     (0U 
                                                                      != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))))) 
                                                  << 2U) 
                                                 & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec))))),64);
            tracep->chgBit(oldp+569,((0x300U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+570,((0x300U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
            tracep->chgBit(oldp+571,(((0x300U == (0xfffU 
                                                  & (vlTOPp->SimTop__DOT__id_inst 
                                                     >> 0x14U))) 
                                      & (IData)(vlTOPp->SimTop__DOT__csr_rd_ena))));
            tracep->chgBit(oldp+572,(((0x300U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)) 
                                      & (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena))));
            tracep->chgBit(oldp+573,((0x301U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+574,(((0x301U == (0xfffU 
                                                  & (vlTOPp->SimTop__DOT__id_inst 
                                                     >> 0x14U))) 
                                      & (IData)(vlTOPp->SimTop__DOT__csr_rd_ena))));
            tracep->chgBit(oldp+575,((0x304U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+576,((0x304U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
            tracep->chgBit(oldp+577,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                      & (0x304U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+578,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                      & (0x304U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
            tracep->chgBit(oldp+579,((0x305U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+580,((0x305U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
            tracep->chgBit(oldp+581,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                      & (0x305U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+582,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                      & (0x305U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
            tracep->chgBit(oldp+583,((0x430U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+584,((0x430U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
            tracep->chgBit(oldp+585,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                      & (0x430U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+586,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                      & (0x430U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
            tracep->chgBit(oldp+587,((0x341U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+588,((0x341U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
            tracep->chgBit(oldp+589,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                      & (0x341U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+590,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                      & (0x341U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
            tracep->chgBit(oldp+591,((0x342U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+592,((0x342U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
            tracep->chgBit(oldp+593,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                      & (0x342U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+594,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                      & (0x342U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
            tracep->chgBit(oldp+595,((0x343U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+596,((0x343U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
            tracep->chgBit(oldp+597,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                      & (0x343U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+598,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                      & (0x343U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
            tracep->chgQData(oldp+599,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtval),64);
            tracep->chgBit(oldp+601,((0x344U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+602,((0x344U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
            tracep->chgBit(oldp+603,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                      & (0x344U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+604,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                      & (0x344U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
            tracep->chgBit(oldp+605,((0xb00U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+606,((0xb00U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
            tracep->chgBit(oldp+607,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                      & (0xb00U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+608,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                      & (0xb00U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
            tracep->chgQData(oldp+609,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mcycle),64);
            tracep->chgBit(oldp+611,((0xf11U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+612,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                      & (0xf11U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+613,((0xf12U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+614,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                      & (0xf12U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+615,((0xf13U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+616,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                      & (0xf13U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U))))));
            tracep->chgBit(oldp+617,((0xf14U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))));
            tracep->chgBit(oldp+618,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                      & (0xf14U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U))))));
            tracep->chgQData(oldp+619,(vlTOPp->SimTop__DOT__regs
                                       [0U]),64);
            tracep->chgQData(oldp+621,(vlTOPp->SimTop__DOT__regs
                                       [1U]),64);
            tracep->chgQData(oldp+623,(vlTOPp->SimTop__DOT__regs
                                       [2U]),64);
            tracep->chgQData(oldp+625,(vlTOPp->SimTop__DOT__regs
                                       [3U]),64);
            tracep->chgQData(oldp+627,(vlTOPp->SimTop__DOT__regs
                                       [4U]),64);
            tracep->chgQData(oldp+629,(vlTOPp->SimTop__DOT__regs
                                       [5U]),64);
            tracep->chgQData(oldp+631,(vlTOPp->SimTop__DOT__regs
                                       [6U]),64);
            tracep->chgQData(oldp+633,(vlTOPp->SimTop__DOT__regs
                                       [7U]),64);
            tracep->chgQData(oldp+635,(vlTOPp->SimTop__DOT__regs
                                       [8U]),64);
            tracep->chgQData(oldp+637,(vlTOPp->SimTop__DOT__regs
                                       [9U]),64);
            tracep->chgQData(oldp+639,(vlTOPp->SimTop__DOT__regs
                                       [0xaU]),64);
            tracep->chgQData(oldp+641,(vlTOPp->SimTop__DOT__regs
                                       [0xbU]),64);
            tracep->chgQData(oldp+643,(vlTOPp->SimTop__DOT__regs
                                       [0xcU]),64);
            tracep->chgQData(oldp+645,(vlTOPp->SimTop__DOT__regs
                                       [0xdU]),64);
            tracep->chgQData(oldp+647,(vlTOPp->SimTop__DOT__regs
                                       [0xeU]),64);
            tracep->chgQData(oldp+649,(vlTOPp->SimTop__DOT__regs
                                       [0xfU]),64);
            tracep->chgQData(oldp+651,(vlTOPp->SimTop__DOT__regs
                                       [0x10U]),64);
            tracep->chgQData(oldp+653,(vlTOPp->SimTop__DOT__regs
                                       [0x11U]),64);
            tracep->chgQData(oldp+655,(vlTOPp->SimTop__DOT__regs
                                       [0x12U]),64);
            tracep->chgQData(oldp+657,(vlTOPp->SimTop__DOT__regs
                                       [0x13U]),64);
            tracep->chgQData(oldp+659,(vlTOPp->SimTop__DOT__regs
                                       [0x14U]),64);
            tracep->chgQData(oldp+661,(vlTOPp->SimTop__DOT__regs
                                       [0x15U]),64);
            tracep->chgQData(oldp+663,(vlTOPp->SimTop__DOT__regs
                                       [0x16U]),64);
            tracep->chgQData(oldp+665,(vlTOPp->SimTop__DOT__regs
                                       [0x17U]),64);
            tracep->chgQData(oldp+667,(vlTOPp->SimTop__DOT__regs
                                       [0x18U]),64);
            tracep->chgQData(oldp+669,(vlTOPp->SimTop__DOT__regs
                                       [0x19U]),64);
            tracep->chgQData(oldp+671,(vlTOPp->SimTop__DOT__regs
                                       [0x1aU]),64);
            tracep->chgQData(oldp+673,(vlTOPp->SimTop__DOT__regs
                                       [0x1bU]),64);
            tracep->chgQData(oldp+675,(vlTOPp->SimTop__DOT__regs
                                       [0x1cU]),64);
            tracep->chgQData(oldp+677,(vlTOPp->SimTop__DOT__regs
                                       [0x1dU]),64);
            tracep->chgQData(oldp+679,(vlTOPp->SimTop__DOT__regs
                                       [0x1eU]),64);
            tracep->chgQData(oldp+681,(vlTOPp->SimTop__DOT__regs
                                       [0x1fU]),64);
            tracep->chgBit(oldp+683,((0x6bU == (0x7fU 
                                                & vlTOPp->SimTop__DOT__wb_inst))));
            tracep->chgCData(oldp+684,((7U & (IData)(
                                                     vlTOPp->SimTop__DOT__regs
                                                     [0xaU]))),3);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgQData(oldp+685,(vlTOPp->SimTop__DOT__if_pc),64);
            tracep->chgBit(oldp+687,(vlTOPp->SimTop__DOT__bj_ena));
            tracep->chgBit(oldp+688,(vlTOPp->SimTop__DOT__id_allowin));
            tracep->chgBit(oldp+689,((1U & (~ (IData)(vlTOPp->SimTop__DOT__stall)))));
            tracep->chgBit(oldp+690,(vlTOPp->SimTop__DOT__id_to_ex_valid));
            tracep->chgBit(oldp+691,(vlTOPp->SimTop__DOT__stall));
            tracep->chgQData(oldp+692,(vlTOPp->SimTop__DOT__id_op1),64);
            tracep->chgQData(oldp+694,(vlTOPp->SimTop__DOT__id_op2),64);
            tracep->chgQData(oldp+696,(vlTOPp->SimTop__DOT__r_data1),64);
            tracep->chgQData(oldp+698,(vlTOPp->SimTop__DOT__r_data2),64);
            tracep->chgBit(oldp+700,(vlTOPp->SimTop__DOT__id_reg_wr_ena));
            tracep->chgQData(oldp+701,(vlTOPp->SimTop__DOT__mem_ram_data),64);
            tracep->chgBit(oldp+703,(vlTOPp->SimTop__DOT__rs1_r_ena));
            tracep->chgCData(oldp+704,(vlTOPp->SimTop__DOT__rs1_r_addr),5);
            tracep->chgBit(oldp+705,(vlTOPp->SimTop__DOT__rs2_r_ena));
            tracep->chgCData(oldp+706,(vlTOPp->SimTop__DOT__rs2_r_addr),5);
            tracep->chgQData(oldp+707,(vlTOPp->SimTop__DOT__wb_reg_wr_data),64);
            tracep->chgQData(oldp+709,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output),64);
        }
        tracep->chgBit(oldp+711,(vlTOPp->clock));
        tracep->chgBit(oldp+712,(vlTOPp->reset));
        tracep->chgQData(oldp+713,(vlTOPp->io_logCtrl_log_begin),64);
        tracep->chgQData(oldp+715,(vlTOPp->io_logCtrl_log_end),64);
        tracep->chgQData(oldp+717,(vlTOPp->io_logCtrl_log_level),64);
        tracep->chgBit(oldp+719,(vlTOPp->io_perfInfo_clean));
        tracep->chgBit(oldp+720,(vlTOPp->io_perfInfo_dump));
        tracep->chgBit(oldp+721,(vlTOPp->io_uart_out_valid));
        tracep->chgCData(oldp+722,(vlTOPp->io_uart_out_ch),8);
        tracep->chgBit(oldp+723,(vlTOPp->io_uart_in_valid));
        tracep->chgCData(oldp+724,(vlTOPp->io_uart_in_ch),8);
        tracep->chgBit(oldp+725,(((~ (IData)(vlTOPp->reset)) 
                                  & (0x23U == (0x7fU 
                                               & vlTOPp->SimTop__DOT__id_inst)))));
        tracep->chgBit(oldp+726,(((~ (IData)(vlTOPp->reset)) 
                                  & (3U == (0x7fU & vlTOPp->SimTop__DOT__id_inst)))));
        tracep->chgCData(oldp+727,(((((~ (IData)(vlTOPp->reset)) 
                                      & ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm) 
                                         | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg))) 
                                     << 2U) | ((((~ (IData)(vlTOPp->reset)) 
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
                                                         & vlTOPp->SimTop__DOT__id_inst))))))),3);
        tracep->chgCData(oldp+728,(vlTOPp->SimTop__DOT__id_reg_wr_addr),5);
        tracep->chgBit(oldp+729,(((~ (IData)(vlTOPp->reset)) 
                                  & ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm) 
                                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg)))));
        tracep->chgQData(oldp+730,((((QData)((IData)(
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
                                     << 0x20U) | (QData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output)))),64);
        tracep->chgQData(oldp+732,(((- (QData)((IData)(
                                                       (1U 
                                                        & (~ (IData)(vlTOPp->reset)))))) 
                                    & (((((((((((- (QData)((IData)(
                                                                   ((0x300U 
                                                                     == 
                                                                     (0xfffU 
                                                                      & (vlTOPp->SimTop__DOT__id_inst 
                                                                         >> 0x14U))) 
                                                                    & (IData)(vlTOPp->SimTop__DOT__csr_rd_ena))))) 
                                                & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus) 
                                               | (0x80000100ULL 
                                                  & (- (QData)((IData)(
                                                                       ((0x301U 
                                                                         == 
                                                                         (0xfffU 
                                                                          & (vlTOPp->SimTop__DOT__id_inst 
                                                                             >> 0x14U))) 
                                                                        & (IData)(vlTOPp->SimTop__DOT__csr_rd_ena))))))) 
                                              | ((- (QData)((IData)(
                                                                    ((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                                                     & (0x304U 
                                                                        == 
                                                                        (0xfffU 
                                                                         & (vlTOPp->SimTop__DOT__id_inst 
                                                                            >> 0x14U))))))) 
                                                 & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mie)) 
                                             | ((- (QData)((IData)(
                                                                   ((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                                                    & (0x305U 
                                                                       == 
                                                                       (0xfffU 
                                                                        & (vlTOPp->SimTop__DOT__id_inst 
                                                                           >> 0x14U))))))) 
                                                & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec)) 
                                            | ((- (QData)((IData)(
                                                                  ((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                                                   & (0x430U 
                                                                      == 
                                                                      (0xfffU 
                                                                       & (vlTOPp->SimTop__DOT__id_inst 
                                                                          >> 0x14U))))))) 
                                               & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mscratch)) 
                                           | ((- (QData)((IData)(
                                                                 ((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                                                  & (0x341U 
                                                                     == 
                                                                     (0xfffU 
                                                                      & (vlTOPp->SimTop__DOT__id_inst 
                                                                         >> 0x14U))))))) 
                                              & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mepc)) 
                                          | ((- (QData)((IData)(
                                                                ((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                                                 & (0x342U 
                                                                    == 
                                                                    (0xfffU 
                                                                     & (vlTOPp->SimTop__DOT__id_inst 
                                                                        >> 0x14U))))))) 
                                             & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mcause)) 
                                         | ((- (QData)((IData)(
                                                               ((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                                                & (0x343U 
                                                                   == 
                                                                   (0xfffU 
                                                                    & (vlTOPp->SimTop__DOT__id_inst 
                                                                       >> 0x14U))))))) 
                                            & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtval)) 
                                        | ((- (QData)((IData)(
                                                              ((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                                               & (0x344U 
                                                                  == 
                                                                  (0xfffU 
                                                                   & (vlTOPp->SimTop__DOT__id_inst 
                                                                      >> 0x14U))))))) 
                                           & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mip)) 
                                       | ((- (QData)((IData)(
                                                             ((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                                              & (0xb00U 
                                                                 == 
                                                                 (0xfffU 
                                                                  & (vlTOPp->SimTop__DOT__id_inst 
                                                                     >> 0x14U))))))) 
                                          & vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mcycle)))),64);
        tracep->chgBit(oldp+734,(((~ (IData)(vlTOPp->reset)) 
                                  & (((((((((0xfU == 
                                             (0x7fU 
                                              & vlTOPp->SimTop__DOT__id_inst)) 
                                            | (0x13U 
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                           | (0x17U 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__id_inst))) 
                                          | (0x1bU 
                                             == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__id_inst))) 
                                         | (0x33U == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))) 
                                        | (0x37U == 
                                           (0x7fU & vlTOPp->SimTop__DOT__id_inst))) 
                                       | (0x3bU == 
                                          (0x7fU & vlTOPp->SimTop__DOT__id_inst))) 
                                      | (0x6fU == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                     | (0x67U == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__id_inst))))));
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
