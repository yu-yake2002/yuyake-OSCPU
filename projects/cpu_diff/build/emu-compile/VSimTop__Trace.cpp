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
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgQData(oldp+0,(vlTOPp->SimTop__DOT__pc),64);
            tracep->chgIData(oldp+2,(vlTOPp->SimTop__DOT__inst),32);
            tracep->chgBit(oldp+3,(vlTOPp->SimTop__DOT__inst_valid));
            tracep->chgQData(oldp+4,(vlTOPp->SimTop__DOT__If_stage__DOT__rdata),64);
            tracep->chgQData(oldp+6,(((vlTOPp->SimTop__DOT__pc 
                                       - 0x80000000ULL) 
                                      >> 3U)),64);
            tracep->chgBit(oldp+8,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addi));
            tracep->chgCData(oldp+9,((0x7fU & vlTOPp->SimTop__DOT__inst)),7);
            tracep->chgCData(oldp+10,((0x1fU & (vlTOPp->SimTop__DOT__inst 
                                                >> 7U))),5);
            tracep->chgCData(oldp+11,((7U & (vlTOPp->SimTop__DOT__inst 
                                             >> 0xcU))),3);
            tracep->chgCData(oldp+12,((0x1fU & (vlTOPp->SimTop__DOT__inst 
                                                >> 0xfU))),5);
            tracep->chgSData(oldp+13,((0xfffU & (vlTOPp->SimTop__DOT__inst 
                                                 >> 0x14U))),12);
            tracep->chgQData(oldp+14,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[0]),64);
            tracep->chgQData(oldp+16,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[1]),64);
            tracep->chgQData(oldp+18,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[2]),64);
            tracep->chgQData(oldp+20,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[3]),64);
            tracep->chgQData(oldp+22,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[4]),64);
            tracep->chgQData(oldp+24,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[5]),64);
            tracep->chgQData(oldp+26,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[6]),64);
            tracep->chgQData(oldp+28,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[7]),64);
            tracep->chgQData(oldp+30,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[8]),64);
            tracep->chgQData(oldp+32,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[9]),64);
            tracep->chgQData(oldp+34,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[10]),64);
            tracep->chgQData(oldp+36,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[11]),64);
            tracep->chgQData(oldp+38,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[12]),64);
            tracep->chgQData(oldp+40,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[13]),64);
            tracep->chgQData(oldp+42,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[14]),64);
            tracep->chgQData(oldp+44,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[15]),64);
            tracep->chgQData(oldp+46,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[16]),64);
            tracep->chgQData(oldp+48,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[17]),64);
            tracep->chgQData(oldp+50,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[18]),64);
            tracep->chgQData(oldp+52,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[19]),64);
            tracep->chgQData(oldp+54,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[20]),64);
            tracep->chgQData(oldp+56,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[21]),64);
            tracep->chgQData(oldp+58,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[22]),64);
            tracep->chgQData(oldp+60,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[23]),64);
            tracep->chgQData(oldp+62,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[24]),64);
            tracep->chgQData(oldp+64,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[25]),64);
            tracep->chgQData(oldp+66,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[26]),64);
            tracep->chgQData(oldp+68,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[27]),64);
            tracep->chgQData(oldp+70,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[28]),64);
            tracep->chgQData(oldp+72,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[29]),64);
            tracep->chgQData(oldp+74,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[30]),64);
            tracep->chgQData(oldp+76,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[31]),64);
        }
        if (VL_UNLIKELY((vlTOPp->__Vm_traceActivity
                         [1U] | vlTOPp->__Vm_traceActivity
                         [3U]))) {
            tracep->chgQData(oldp+78,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0]),64);
            tracep->chgQData(oldp+80,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[1]),64);
            tracep->chgQData(oldp+82,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[2]),64);
            tracep->chgQData(oldp+84,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[3]),64);
            tracep->chgQData(oldp+86,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[4]),64);
            tracep->chgQData(oldp+88,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[5]),64);
            tracep->chgQData(oldp+90,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[6]),64);
            tracep->chgQData(oldp+92,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[7]),64);
            tracep->chgQData(oldp+94,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[8]),64);
            tracep->chgQData(oldp+96,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[9]),64);
            tracep->chgQData(oldp+98,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[10]),64);
            tracep->chgQData(oldp+100,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[11]),64);
            tracep->chgQData(oldp+102,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[12]),64);
            tracep->chgQData(oldp+104,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[13]),64);
            tracep->chgQData(oldp+106,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[14]),64);
            tracep->chgQData(oldp+108,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[15]),64);
            tracep->chgQData(oldp+110,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[16]),64);
            tracep->chgQData(oldp+112,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[17]),64);
            tracep->chgQData(oldp+114,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[18]),64);
            tracep->chgQData(oldp+116,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[19]),64);
            tracep->chgQData(oldp+118,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[20]),64);
            tracep->chgQData(oldp+120,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[21]),64);
            tracep->chgQData(oldp+122,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[22]),64);
            tracep->chgQData(oldp+124,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[23]),64);
            tracep->chgQData(oldp+126,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[24]),64);
            tracep->chgQData(oldp+128,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[25]),64);
            tracep->chgQData(oldp+130,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[26]),64);
            tracep->chgQData(oldp+132,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[27]),64);
            tracep->chgQData(oldp+134,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[28]),64);
            tracep->chgQData(oldp+136,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[29]),64);
            tracep->chgQData(oldp+138,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[30]),64);
            tracep->chgQData(oldp+140,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[31]),64);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgBit(oldp+142,(vlTOPp->SimTop__DOT__cmt_wen));
            tracep->chgCData(oldp+143,(vlTOPp->SimTop__DOT__cmt_wdest),8);
            tracep->chgQData(oldp+144,(vlTOPp->SimTop__DOT__cmt_wdata),64);
            tracep->chgQData(oldp+146,(vlTOPp->SimTop__DOT__cmt_pc),64);
            tracep->chgIData(oldp+148,(vlTOPp->SimTop__DOT__cmt_inst),32);
            tracep->chgBit(oldp+149,(vlTOPp->SimTop__DOT__cmt_valid));
            tracep->chgBit(oldp+150,(vlTOPp->SimTop__DOT__trap));
            tracep->chgCData(oldp+151,(vlTOPp->SimTop__DOT__trap_code),8);
            tracep->chgQData(oldp+152,(vlTOPp->SimTop__DOT__cycleCnt),64);
            tracep->chgQData(oldp+154,(vlTOPp->SimTop__DOT__instrCnt),64);
            tracep->chgQData(oldp+156,(vlTOPp->SimTop__DOT__regs_diff[0]),64);
            tracep->chgQData(oldp+158,(vlTOPp->SimTop__DOT__regs_diff[1]),64);
            tracep->chgQData(oldp+160,(vlTOPp->SimTop__DOT__regs_diff[2]),64);
            tracep->chgQData(oldp+162,(vlTOPp->SimTop__DOT__regs_diff[3]),64);
            tracep->chgQData(oldp+164,(vlTOPp->SimTop__DOT__regs_diff[4]),64);
            tracep->chgQData(oldp+166,(vlTOPp->SimTop__DOT__regs_diff[5]),64);
            tracep->chgQData(oldp+168,(vlTOPp->SimTop__DOT__regs_diff[6]),64);
            tracep->chgQData(oldp+170,(vlTOPp->SimTop__DOT__regs_diff[7]),64);
            tracep->chgQData(oldp+172,(vlTOPp->SimTop__DOT__regs_diff[8]),64);
            tracep->chgQData(oldp+174,(vlTOPp->SimTop__DOT__regs_diff[9]),64);
            tracep->chgQData(oldp+176,(vlTOPp->SimTop__DOT__regs_diff[10]),64);
            tracep->chgQData(oldp+178,(vlTOPp->SimTop__DOT__regs_diff[11]),64);
            tracep->chgQData(oldp+180,(vlTOPp->SimTop__DOT__regs_diff[12]),64);
            tracep->chgQData(oldp+182,(vlTOPp->SimTop__DOT__regs_diff[13]),64);
            tracep->chgQData(oldp+184,(vlTOPp->SimTop__DOT__regs_diff[14]),64);
            tracep->chgQData(oldp+186,(vlTOPp->SimTop__DOT__regs_diff[15]),64);
            tracep->chgQData(oldp+188,(vlTOPp->SimTop__DOT__regs_diff[16]),64);
            tracep->chgQData(oldp+190,(vlTOPp->SimTop__DOT__regs_diff[17]),64);
            tracep->chgQData(oldp+192,(vlTOPp->SimTop__DOT__regs_diff[18]),64);
            tracep->chgQData(oldp+194,(vlTOPp->SimTop__DOT__regs_diff[19]),64);
            tracep->chgQData(oldp+196,(vlTOPp->SimTop__DOT__regs_diff[20]),64);
            tracep->chgQData(oldp+198,(vlTOPp->SimTop__DOT__regs_diff[21]),64);
            tracep->chgQData(oldp+200,(vlTOPp->SimTop__DOT__regs_diff[22]),64);
            tracep->chgQData(oldp+202,(vlTOPp->SimTop__DOT__regs_diff[23]),64);
            tracep->chgQData(oldp+204,(vlTOPp->SimTop__DOT__regs_diff[24]),64);
            tracep->chgQData(oldp+206,(vlTOPp->SimTop__DOT__regs_diff[25]),64);
            tracep->chgQData(oldp+208,(vlTOPp->SimTop__DOT__regs_diff[26]),64);
            tracep->chgQData(oldp+210,(vlTOPp->SimTop__DOT__regs_diff[27]),64);
            tracep->chgQData(oldp+212,(vlTOPp->SimTop__DOT__regs_diff[28]),64);
            tracep->chgQData(oldp+214,(vlTOPp->SimTop__DOT__regs_diff[29]),64);
            tracep->chgQData(oldp+216,(vlTOPp->SimTop__DOT__regs_diff[30]),64);
            tracep->chgQData(oldp+218,(vlTOPp->SimTop__DOT__regs_diff[31]),64);
            tracep->chgQData(oldp+220,(vlTOPp->SimTop__DOT__regs_diff
                                       [0U]),64);
            tracep->chgQData(oldp+222,(vlTOPp->SimTop__DOT__regs_diff
                                       [1U]),64);
            tracep->chgQData(oldp+224,(vlTOPp->SimTop__DOT__regs_diff
                                       [2U]),64);
            tracep->chgQData(oldp+226,(vlTOPp->SimTop__DOT__regs_diff
                                       [3U]),64);
            tracep->chgQData(oldp+228,(vlTOPp->SimTop__DOT__regs_diff
                                       [4U]),64);
            tracep->chgQData(oldp+230,(vlTOPp->SimTop__DOT__regs_diff
                                       [5U]),64);
            tracep->chgQData(oldp+232,(vlTOPp->SimTop__DOT__regs_diff
                                       [6U]),64);
            tracep->chgQData(oldp+234,(vlTOPp->SimTop__DOT__regs_diff
                                       [7U]),64);
            tracep->chgQData(oldp+236,(vlTOPp->SimTop__DOT__regs_diff
                                       [8U]),64);
            tracep->chgQData(oldp+238,(vlTOPp->SimTop__DOT__regs_diff
                                       [9U]),64);
            tracep->chgQData(oldp+240,(vlTOPp->SimTop__DOT__regs_diff
                                       [0xaU]),64);
            tracep->chgQData(oldp+242,(vlTOPp->SimTop__DOT__regs_diff
                                       [0xbU]),64);
            tracep->chgQData(oldp+244,(vlTOPp->SimTop__DOT__regs_diff
                                       [0xcU]),64);
            tracep->chgQData(oldp+246,(vlTOPp->SimTop__DOT__regs_diff
                                       [0xdU]),64);
            tracep->chgQData(oldp+248,(vlTOPp->SimTop__DOT__regs_diff
                                       [0xeU]),64);
            tracep->chgQData(oldp+250,(vlTOPp->SimTop__DOT__regs_diff
                                       [0xfU]),64);
            tracep->chgQData(oldp+252,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x10U]),64);
            tracep->chgQData(oldp+254,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x11U]),64);
            tracep->chgQData(oldp+256,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x12U]),64);
            tracep->chgQData(oldp+258,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x13U]),64);
            tracep->chgQData(oldp+260,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x14U]),64);
            tracep->chgQData(oldp+262,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x15U]),64);
            tracep->chgQData(oldp+264,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x16U]),64);
            tracep->chgQData(oldp+266,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x17U]),64);
            tracep->chgQData(oldp+268,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x18U]),64);
            tracep->chgQData(oldp+270,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x19U]),64);
            tracep->chgQData(oldp+272,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x1aU]),64);
            tracep->chgQData(oldp+274,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x1bU]),64);
            tracep->chgQData(oldp+276,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x1cU]),64);
            tracep->chgQData(oldp+278,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x1dU]),64);
            tracep->chgQData(oldp+280,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x1eU]),64);
            tracep->chgQData(oldp+282,(vlTOPp->SimTop__DOT__regs_diff
                                       [0x1fU]),64);
            tracep->chgCData(oldp+284,((7U & (IData)(vlTOPp->SimTop__DOT__trap_code))),3);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgBit(oldp+285,(vlTOPp->SimTop__DOT__rd_w_ena));
            tracep->chgCData(oldp+286,(vlTOPp->SimTop__DOT__rd_w_addr),5);
            tracep->chgCData(oldp+287,(vlTOPp->SimTop__DOT__inst_type),5);
            tracep->chgCData(oldp+288,(vlTOPp->SimTop__DOT__inst_opcode),8);
            tracep->chgQData(oldp+289,(vlTOPp->SimTop__DOT__regs[0]),64);
            tracep->chgQData(oldp+291,(vlTOPp->SimTop__DOT__regs[1]),64);
            tracep->chgQData(oldp+293,(vlTOPp->SimTop__DOT__regs[2]),64);
            tracep->chgQData(oldp+295,(vlTOPp->SimTop__DOT__regs[3]),64);
            tracep->chgQData(oldp+297,(vlTOPp->SimTop__DOT__regs[4]),64);
            tracep->chgQData(oldp+299,(vlTOPp->SimTop__DOT__regs[5]),64);
            tracep->chgQData(oldp+301,(vlTOPp->SimTop__DOT__regs[6]),64);
            tracep->chgQData(oldp+303,(vlTOPp->SimTop__DOT__regs[7]),64);
            tracep->chgQData(oldp+305,(vlTOPp->SimTop__DOT__regs[8]),64);
            tracep->chgQData(oldp+307,(vlTOPp->SimTop__DOT__regs[9]),64);
            tracep->chgQData(oldp+309,(vlTOPp->SimTop__DOT__regs[10]),64);
            tracep->chgQData(oldp+311,(vlTOPp->SimTop__DOT__regs[11]),64);
            tracep->chgQData(oldp+313,(vlTOPp->SimTop__DOT__regs[12]),64);
            tracep->chgQData(oldp+315,(vlTOPp->SimTop__DOT__regs[13]),64);
            tracep->chgQData(oldp+317,(vlTOPp->SimTop__DOT__regs[14]),64);
            tracep->chgQData(oldp+319,(vlTOPp->SimTop__DOT__regs[15]),64);
            tracep->chgQData(oldp+321,(vlTOPp->SimTop__DOT__regs[16]),64);
            tracep->chgQData(oldp+323,(vlTOPp->SimTop__DOT__regs[17]),64);
            tracep->chgQData(oldp+325,(vlTOPp->SimTop__DOT__regs[18]),64);
            tracep->chgQData(oldp+327,(vlTOPp->SimTop__DOT__regs[19]),64);
            tracep->chgQData(oldp+329,(vlTOPp->SimTop__DOT__regs[20]),64);
            tracep->chgQData(oldp+331,(vlTOPp->SimTop__DOT__regs[21]),64);
            tracep->chgQData(oldp+333,(vlTOPp->SimTop__DOT__regs[22]),64);
            tracep->chgQData(oldp+335,(vlTOPp->SimTop__DOT__regs[23]),64);
            tracep->chgQData(oldp+337,(vlTOPp->SimTop__DOT__regs[24]),64);
            tracep->chgQData(oldp+339,(vlTOPp->SimTop__DOT__regs[25]),64);
            tracep->chgQData(oldp+341,(vlTOPp->SimTop__DOT__regs[26]),64);
            tracep->chgQData(oldp+343,(vlTOPp->SimTop__DOT__regs[27]),64);
            tracep->chgQData(oldp+345,(vlTOPp->SimTop__DOT__regs[28]),64);
            tracep->chgQData(oldp+347,(vlTOPp->SimTop__DOT__regs[29]),64);
            tracep->chgQData(oldp+349,(vlTOPp->SimTop__DOT__regs[30]),64);
            tracep->chgQData(oldp+351,(vlTOPp->SimTop__DOT__regs[31]),64);
            tracep->chgQData(oldp+353,(vlTOPp->SimTop__DOT__rd_data),64);
        }
        tracep->chgBit(oldp+355,(vlTOPp->clock));
        tracep->chgBit(oldp+356,(vlTOPp->reset));
        tracep->chgQData(oldp+357,(vlTOPp->io_logCtrl_log_begin),64);
        tracep->chgQData(oldp+359,(vlTOPp->io_logCtrl_log_end),64);
        tracep->chgQData(oldp+361,(vlTOPp->io_logCtrl_log_level),64);
        tracep->chgBit(oldp+363,(vlTOPp->io_perfInfo_clean));
        tracep->chgBit(oldp+364,(vlTOPp->io_perfInfo_dump));
        tracep->chgBit(oldp+365,(vlTOPp->io_uart_out_valid));
        tracep->chgCData(oldp+366,(vlTOPp->io_uart_out_ch),8);
        tracep->chgBit(oldp+367,(vlTOPp->io_uart_in_valid));
        tracep->chgCData(oldp+368,(vlTOPp->io_uart_in_ch),8);
        tracep->chgBit(oldp+369,(((IData)(vlTOPp->reset)
                                   ? 0U : (1U & ((IData)(vlTOPp->SimTop__DOT__inst_type) 
                                                 >> 4U)))));
        tracep->chgCData(oldp+370,(((IData)(vlTOPp->reset)
                                     ? 0U : ((0x10U 
                                              & (IData)(vlTOPp->SimTop__DOT__inst_type))
                                              ? (0x1fU 
                                                 & (vlTOPp->SimTop__DOT__inst 
                                                    >> 0xfU))
                                              : 0U))),5);
        tracep->chgQData(oldp+371,(((IData)(vlTOPp->reset)
                                     ? 0ULL : ((0x10U 
                                                & (IData)(vlTOPp->SimTop__DOT__inst_type))
                                                ? ((IData)(vlTOPp->reset)
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
                                                : 0ULL))),64);
        tracep->chgQData(oldp+373,(((IData)(vlTOPp->reset)
                                     ? 0ULL : ((0x10U 
                                                & (IData)(vlTOPp->SimTop__DOT__inst_type))
                                                ? (
                                                   (0xfffffffffffff000ULL 
                                                    & ((- (QData)((IData)(
                                                                          (1U 
                                                                           & (vlTOPp->SimTop__DOT__inst 
                                                                              >> 0x1fU))))) 
                                                       << 0xcU)) 
                                                   | (QData)((IData)(
                                                                     (0xfffU 
                                                                      & (vlTOPp->SimTop__DOT__inst 
                                                                         >> 0x14U)))))
                                                : 0ULL))),64);
        tracep->chgQData(oldp+375,(((IData)(vlTOPp->reset)
                                     ? 0ULL : (((IData)(vlTOPp->reset)
                                                 ? 0U
                                                 : 
                                                (1U 
                                                 & ((IData)(vlTOPp->SimTop__DOT__inst_type) 
                                                    >> 4U)))
                                                ? vlTOPp->SimTop__DOT__Regfile__DOT__regs
                                               [((IData)(vlTOPp->reset)
                                                  ? 0U
                                                  : 
                                                 ((0x10U 
                                                   & (IData)(vlTOPp->SimTop__DOT__inst_type))
                                                   ? 
                                                  (0x1fU 
                                                   & (vlTOPp->SimTop__DOT__inst 
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
