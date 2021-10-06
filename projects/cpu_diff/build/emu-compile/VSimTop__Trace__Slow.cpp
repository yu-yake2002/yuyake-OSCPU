// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSimTop__Syms.h"


//======================

void VSimTop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VSimTop::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VSimTop__Syms* __restrict vlSymsp = static_cast<VSimTop__Syms*>(userp);
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VSimTop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VSimTop::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VSimTop__Syms* __restrict vlSymsp = static_cast<VSimTop__Syms*>(userp);
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VSimTop::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VSimTop__Syms* __restrict vlSymsp = static_cast<VSimTop__Syms*>(userp);
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+356,"clock", false,-1);
        tracep->declBit(c+357,"reset", false,-1);
        tracep->declQuad(c+358,"io_logCtrl_log_begin", false,-1, 63,0);
        tracep->declQuad(c+360,"io_logCtrl_log_end", false,-1, 63,0);
        tracep->declQuad(c+362,"io_logCtrl_log_level", false,-1, 63,0);
        tracep->declBit(c+364,"io_perfInfo_clean", false,-1);
        tracep->declBit(c+365,"io_perfInfo_dump", false,-1);
        tracep->declBit(c+366,"io_uart_out_valid", false,-1);
        tracep->declBus(c+367,"io_uart_out_ch", false,-1, 7,0);
        tracep->declBit(c+368,"io_uart_in_valid", false,-1);
        tracep->declBus(c+369,"io_uart_in_ch", false,-1, 7,0);
        tracep->declBit(c+356,"SimTop clock", false,-1);
        tracep->declBit(c+357,"SimTop reset", false,-1);
        tracep->declQuad(c+358,"SimTop io_logCtrl_log_begin", false,-1, 63,0);
        tracep->declQuad(c+360,"SimTop io_logCtrl_log_end", false,-1, 63,0);
        tracep->declQuad(c+362,"SimTop io_logCtrl_log_level", false,-1, 63,0);
        tracep->declBit(c+364,"SimTop io_perfInfo_clean", false,-1);
        tracep->declBit(c+365,"SimTop io_perfInfo_dump", false,-1);
        tracep->declBit(c+366,"SimTop io_uart_out_valid", false,-1);
        tracep->declBus(c+367,"SimTop io_uart_out_ch", false,-1, 7,0);
        tracep->declBit(c+368,"SimTop io_uart_in_valid", false,-1);
        tracep->declBus(c+369,"SimTop io_uart_in_ch", false,-1, 7,0);
        tracep->declQuad(c+1,"SimTop pc", false,-1, 63,0);
        tracep->declBus(c+3,"SimTop inst", false,-1, 31,0);
        tracep->declBit(c+370,"SimTop rs1_r_ena", false,-1);
        tracep->declBus(c+371,"SimTop rs1_r_addr", false,-1, 4,0);
        tracep->declBit(c+378,"SimTop rs2_r_ena", false,-1);
        tracep->declBus(c+379,"SimTop rs2_r_addr", false,-1, 4,0);
        tracep->declBit(c+286,"SimTop rd_w_ena", false,-1);
        tracep->declBus(c+287,"SimTop rd_w_addr", false,-1, 4,0);
        tracep->declBus(c+288,"SimTop inst_type", false,-1, 4,0);
        tracep->declBus(c+289,"SimTop inst_opcode", false,-1, 7,0);
        tracep->declQuad(c+372,"SimTop op1", false,-1, 63,0);
        tracep->declQuad(c+374,"SimTop op2", false,-1, 63,0);
        tracep->declQuad(c+376,"SimTop r_data1", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop r_data2", false,-1, 63,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+290+i*2,"SimTop regs", true,(i+0), 63,0);}}
        tracep->declBus(c+288,"SimTop inst_type_o", false,-1, 4,0);
        tracep->declQuad(c+354,"SimTop rd_data", false,-1, 63,0);
        tracep->declBit(c+143,"SimTop cmt_wen", false,-1);
        tracep->declBus(c+144,"SimTop cmt_wdest", false,-1, 7,0);
        tracep->declQuad(c+145,"SimTop cmt_wdata", false,-1, 63,0);
        tracep->declQuad(c+147,"SimTop cmt_pc", false,-1, 63,0);
        tracep->declBus(c+149,"SimTop cmt_inst", false,-1, 31,0);
        tracep->declBit(c+150,"SimTop cmt_valid", false,-1);
        tracep->declBit(c+151,"SimTop trap", false,-1);
        tracep->declBus(c+152,"SimTop trap_code", false,-1, 7,0);
        tracep->declQuad(c+153,"SimTop cycleCnt", false,-1, 63,0);
        tracep->declQuad(c+155,"SimTop instrCnt", false,-1, 63,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+157+i*2,"SimTop regs_diff", true,(i+0), 63,0);}}
        tracep->declBit(c+4,"SimTop inst_valid", false,-1);
        tracep->declBit(c+356,"SimTop If_stage clk", false,-1);
        tracep->declBit(c+357,"SimTop If_stage rst", false,-1);
        tracep->declQuad(c+1,"SimTop If_stage pc", false,-1, 63,0);
        tracep->declBus(c+3,"SimTop If_stage inst", false,-1, 31,0);
        tracep->declQuad(c+382,"SimTop If_stage PC_START_RESET", false,-1, 63,0);
        tracep->declQuad(c+5,"SimTop If_stage rdata", false,-1, 63,0);
        tracep->declBit(c+356,"SimTop If_stage RAMHelper clk", false,-1);
        tracep->declBit(c+384,"SimTop If_stage RAMHelper en", false,-1);
        tracep->declQuad(c+7,"SimTop If_stage RAMHelper rIdx", false,-1, 63,0);
        tracep->declQuad(c+5,"SimTop If_stage RAMHelper rdata", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop If_stage RAMHelper wIdx", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop If_stage RAMHelper wdata", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop If_stage RAMHelper wmask", false,-1, 63,0);
        tracep->declBit(c+378,"SimTop If_stage RAMHelper wen", false,-1);
        tracep->declBit(c+357,"SimTop Id_stage rst", false,-1);
        tracep->declBus(c+3,"SimTop Id_stage inst", false,-1, 31,0);
        tracep->declQuad(c+376,"SimTop Id_stage rs1_data", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop Id_stage rs2_data", false,-1, 63,0);
        tracep->declBit(c+370,"SimTop Id_stage rs1_r_ena", false,-1);
        tracep->declBus(c+371,"SimTop Id_stage rs1_r_addr", false,-1, 4,0);
        tracep->declBit(c+378,"SimTop Id_stage rs2_r_ena", false,-1);
        tracep->declBus(c+379,"SimTop Id_stage rs2_r_addr", false,-1, 4,0);
        tracep->declBit(c+286,"SimTop Id_stage rd_w_ena", false,-1);
        tracep->declBus(c+287,"SimTop Id_stage rd_w_addr", false,-1, 4,0);
        tracep->declBus(c+288,"SimTop Id_stage inst_type", false,-1, 4,0);
        tracep->declBus(c+289,"SimTop Id_stage inst_opcode", false,-1, 7,0);
        tracep->declQuad(c+372,"SimTop Id_stage op1", false,-1, 63,0);
        tracep->declQuad(c+374,"SimTop Id_stage op2", false,-1, 63,0);
        tracep->declBit(c+9,"SimTop Id_stage inst_addi", false,-1);
        tracep->declBus(c+10,"SimTop Id_stage opcode", false,-1, 6,0);
        tracep->declBus(c+11,"SimTop Id_stage rd", false,-1, 4,0);
        tracep->declBus(c+12,"SimTop Id_stage func3", false,-1, 2,0);
        tracep->declBus(c+13,"SimTop Id_stage rs1", false,-1, 4,0);
        tracep->declBus(c+14,"SimTop Id_stage imm", false,-1, 11,0);
        tracep->declBit(c+357,"SimTop Exe_stage rst", false,-1);
        tracep->declBus(c+288,"SimTop Exe_stage inst_type_i", false,-1, 4,0);
        tracep->declBus(c+289,"SimTop Exe_stage inst_opcode", false,-1, 7,0);
        tracep->declQuad(c+372,"SimTop Exe_stage op1", false,-1, 63,0);
        tracep->declQuad(c+374,"SimTop Exe_stage op2", false,-1, 63,0);
        tracep->declBus(c+288,"SimTop Exe_stage inst_type_o", false,-1, 4,0);
        tracep->declQuad(c+354,"SimTop Exe_stage rd_data", false,-1, 63,0);
        tracep->declBit(c+356,"SimTop Regfile clk", false,-1);
        tracep->declBit(c+357,"SimTop Regfile rst", false,-1);
        tracep->declBus(c+287,"SimTop Regfile w_addr", false,-1, 4,0);
        tracep->declQuad(c+354,"SimTop Regfile w_data", false,-1, 63,0);
        tracep->declBit(c+286,"SimTop Regfile w_ena", false,-1);
        tracep->declBus(c+371,"SimTop Regfile r_addr1", false,-1, 4,0);
        tracep->declQuad(c+376,"SimTop Regfile r_data1", false,-1, 63,0);
        tracep->declBit(c+370,"SimTop Regfile r_ena1", false,-1);
        tracep->declBus(c+379,"SimTop Regfile r_addr2", false,-1, 4,0);
        tracep->declQuad(c+380,"SimTop Regfile r_data2", false,-1, 63,0);
        tracep->declBit(c+378,"SimTop Regfile r_ena2", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+79+i*2,"SimTop Regfile regs_o", true,(i+0), 63,0);}}
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+15+i*2,"SimTop Regfile regs", true,(i+0), 63,0);}}
        tracep->declBit(c+356,"SimTop DifftestInstrCommit clock", false,-1);
        tracep->declBus(c+385,"SimTop DifftestInstrCommit coreid", false,-1, 7,0);
        tracep->declBus(c+385,"SimTop DifftestInstrCommit index", false,-1, 7,0);
        tracep->declBit(c+150,"SimTop DifftestInstrCommit valid", false,-1);
        tracep->declQuad(c+147,"SimTop DifftestInstrCommit pc", false,-1, 63,0);
        tracep->declBus(c+149,"SimTop DifftestInstrCommit instr", false,-1, 31,0);
        tracep->declBit(c+378,"SimTop DifftestInstrCommit skip", false,-1);
        tracep->declBit(c+378,"SimTop DifftestInstrCommit isRVC", false,-1);
        tracep->declBit(c+378,"SimTop DifftestInstrCommit scFailed", false,-1);
        tracep->declBit(c+143,"SimTop DifftestInstrCommit wen", false,-1);
        tracep->declBus(c+144,"SimTop DifftestInstrCommit wdest", false,-1, 7,0);
        tracep->declQuad(c+145,"SimTop DifftestInstrCommit wdata", false,-1, 63,0);
        tracep->declBit(c+356,"SimTop DifftestArchIntRegState clock", false,-1);
        tracep->declBus(c+385,"SimTop DifftestArchIntRegState coreid", false,-1, 7,0);
        tracep->declQuad(c+221,"SimTop DifftestArchIntRegState gpr_0", false,-1, 63,0);
        tracep->declQuad(c+223,"SimTop DifftestArchIntRegState gpr_1", false,-1, 63,0);
        tracep->declQuad(c+225,"SimTop DifftestArchIntRegState gpr_2", false,-1, 63,0);
        tracep->declQuad(c+227,"SimTop DifftestArchIntRegState gpr_3", false,-1, 63,0);
        tracep->declQuad(c+229,"SimTop DifftestArchIntRegState gpr_4", false,-1, 63,0);
        tracep->declQuad(c+231,"SimTop DifftestArchIntRegState gpr_5", false,-1, 63,0);
        tracep->declQuad(c+233,"SimTop DifftestArchIntRegState gpr_6", false,-1, 63,0);
        tracep->declQuad(c+235,"SimTop DifftestArchIntRegState gpr_7", false,-1, 63,0);
        tracep->declQuad(c+237,"SimTop DifftestArchIntRegState gpr_8", false,-1, 63,0);
        tracep->declQuad(c+239,"SimTop DifftestArchIntRegState gpr_9", false,-1, 63,0);
        tracep->declQuad(c+241,"SimTop DifftestArchIntRegState gpr_10", false,-1, 63,0);
        tracep->declQuad(c+243,"SimTop DifftestArchIntRegState gpr_11", false,-1, 63,0);
        tracep->declQuad(c+245,"SimTop DifftestArchIntRegState gpr_12", false,-1, 63,0);
        tracep->declQuad(c+247,"SimTop DifftestArchIntRegState gpr_13", false,-1, 63,0);
        tracep->declQuad(c+249,"SimTop DifftestArchIntRegState gpr_14", false,-1, 63,0);
        tracep->declQuad(c+251,"SimTop DifftestArchIntRegState gpr_15", false,-1, 63,0);
        tracep->declQuad(c+253,"SimTop DifftestArchIntRegState gpr_16", false,-1, 63,0);
        tracep->declQuad(c+255,"SimTop DifftestArchIntRegState gpr_17", false,-1, 63,0);
        tracep->declQuad(c+257,"SimTop DifftestArchIntRegState gpr_18", false,-1, 63,0);
        tracep->declQuad(c+259,"SimTop DifftestArchIntRegState gpr_19", false,-1, 63,0);
        tracep->declQuad(c+261,"SimTop DifftestArchIntRegState gpr_20", false,-1, 63,0);
        tracep->declQuad(c+263,"SimTop DifftestArchIntRegState gpr_21", false,-1, 63,0);
        tracep->declQuad(c+265,"SimTop DifftestArchIntRegState gpr_22", false,-1, 63,0);
        tracep->declQuad(c+267,"SimTop DifftestArchIntRegState gpr_23", false,-1, 63,0);
        tracep->declQuad(c+269,"SimTop DifftestArchIntRegState gpr_24", false,-1, 63,0);
        tracep->declQuad(c+271,"SimTop DifftestArchIntRegState gpr_25", false,-1, 63,0);
        tracep->declQuad(c+273,"SimTop DifftestArchIntRegState gpr_26", false,-1, 63,0);
        tracep->declQuad(c+275,"SimTop DifftestArchIntRegState gpr_27", false,-1, 63,0);
        tracep->declQuad(c+277,"SimTop DifftestArchIntRegState gpr_28", false,-1, 63,0);
        tracep->declQuad(c+279,"SimTop DifftestArchIntRegState gpr_29", false,-1, 63,0);
        tracep->declQuad(c+281,"SimTop DifftestArchIntRegState gpr_30", false,-1, 63,0);
        tracep->declQuad(c+283,"SimTop DifftestArchIntRegState gpr_31", false,-1, 63,0);
        tracep->declBit(c+356,"SimTop DifftestTrapEvent clock", false,-1);
        tracep->declBus(c+385,"SimTop DifftestTrapEvent coreid", false,-1, 7,0);
        tracep->declBit(c+151,"SimTop DifftestTrapEvent valid", false,-1);
        tracep->declBus(c+285,"SimTop DifftestTrapEvent code", false,-1, 2,0);
        tracep->declQuad(c+147,"SimTop DifftestTrapEvent pc", false,-1, 63,0);
        tracep->declQuad(c+153,"SimTop DifftestTrapEvent cycleCnt", false,-1, 63,0);
        tracep->declQuad(c+155,"SimTop DifftestTrapEvent instrCnt", false,-1, 63,0);
        tracep->declBit(c+356,"SimTop DifftestCSRState clock", false,-1);
        tracep->declBus(c+385,"SimTop DifftestCSRState coreid", false,-1, 7,0);
        tracep->declBus(c+386,"SimTop DifftestCSRState priviledgeMode", false,-1, 1,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState mstatus", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState sstatus", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState mepc", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState sepc", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState mtval", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState stval", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState mtvec", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState stvec", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState mcause", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState scause", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState satp", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState mip", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState mie", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState mscratch", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState sscratch", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState mideleg", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestCSRState medeleg", false,-1, 63,0);
        tracep->declBit(c+356,"SimTop DifftestArchFpRegState clock", false,-1);
        tracep->declBus(c+385,"SimTop DifftestArchFpRegState coreid", false,-1, 7,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_0", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_1", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_2", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_3", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_4", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_5", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_6", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_7", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_8", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_9", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_10", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_11", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_12", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_13", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_14", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_15", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_16", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_17", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_18", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_19", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_20", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_21", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_22", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_23", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_24", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_25", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_26", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_27", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_28", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_29", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_30", false,-1, 63,0);
        tracep->declQuad(c+380,"SimTop DifftestArchFpRegState fpr_31", false,-1, 63,0);
    }
}

void VSimTop::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VSimTop::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VSimTop__Syms* __restrict vlSymsp = static_cast<VSimTop__Syms*>(userp);
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VSimTop::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VSimTop__Syms* __restrict vlSymsp = static_cast<VSimTop__Syms*>(userp);
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullQData(oldp+1,(vlTOPp->SimTop__DOT__pc),64);
        tracep->fullIData(oldp+3,(vlTOPp->SimTop__DOT__inst),32);
        tracep->fullBit(oldp+4,(vlTOPp->SimTop__DOT__inst_valid));
        tracep->fullQData(oldp+5,(vlTOPp->SimTop__DOT__If_stage__DOT__rdata),64);
        tracep->fullQData(oldp+7,(((vlTOPp->SimTop__DOT__pc 
                                    - 0x80000000ULL) 
                                   >> 3U)),64);
        tracep->fullBit(oldp+9,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addi));
        tracep->fullCData(oldp+10,((0x7fU & vlTOPp->SimTop__DOT__inst)),7);
        tracep->fullCData(oldp+11,((0x1fU & (vlTOPp->SimTop__DOT__inst 
                                             >> 7U))),5);
        tracep->fullCData(oldp+12,((7U & (vlTOPp->SimTop__DOT__inst 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+13,((0x1fU & (vlTOPp->SimTop__DOT__inst 
                                             >> 0xfU))),5);
        tracep->fullSData(oldp+14,((0xfffU & (vlTOPp->SimTop__DOT__inst 
                                              >> 0x14U))),12);
        tracep->fullQData(oldp+15,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[0]),64);
        tracep->fullQData(oldp+17,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[1]),64);
        tracep->fullQData(oldp+19,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[2]),64);
        tracep->fullQData(oldp+21,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[3]),64);
        tracep->fullQData(oldp+23,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[4]),64);
        tracep->fullQData(oldp+25,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[5]),64);
        tracep->fullQData(oldp+27,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[6]),64);
        tracep->fullQData(oldp+29,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[7]),64);
        tracep->fullQData(oldp+31,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[8]),64);
        tracep->fullQData(oldp+33,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[9]),64);
        tracep->fullQData(oldp+35,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[10]),64);
        tracep->fullQData(oldp+37,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[11]),64);
        tracep->fullQData(oldp+39,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[12]),64);
        tracep->fullQData(oldp+41,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[13]),64);
        tracep->fullQData(oldp+43,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[14]),64);
        tracep->fullQData(oldp+45,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[15]),64);
        tracep->fullQData(oldp+47,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[16]),64);
        tracep->fullQData(oldp+49,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[17]),64);
        tracep->fullQData(oldp+51,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[18]),64);
        tracep->fullQData(oldp+53,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[19]),64);
        tracep->fullQData(oldp+55,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[20]),64);
        tracep->fullQData(oldp+57,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[21]),64);
        tracep->fullQData(oldp+59,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[22]),64);
        tracep->fullQData(oldp+61,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[23]),64);
        tracep->fullQData(oldp+63,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[24]),64);
        tracep->fullQData(oldp+65,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[25]),64);
        tracep->fullQData(oldp+67,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[26]),64);
        tracep->fullQData(oldp+69,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[27]),64);
        tracep->fullQData(oldp+71,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[28]),64);
        tracep->fullQData(oldp+73,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[29]),64);
        tracep->fullQData(oldp+75,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[30]),64);
        tracep->fullQData(oldp+77,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[31]),64);
        tracep->fullQData(oldp+79,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0]),64);
        tracep->fullQData(oldp+81,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[1]),64);
        tracep->fullQData(oldp+83,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[2]),64);
        tracep->fullQData(oldp+85,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[3]),64);
        tracep->fullQData(oldp+87,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[4]),64);
        tracep->fullQData(oldp+89,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[5]),64);
        tracep->fullQData(oldp+91,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[6]),64);
        tracep->fullQData(oldp+93,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[7]),64);
        tracep->fullQData(oldp+95,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[8]),64);
        tracep->fullQData(oldp+97,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[9]),64);
        tracep->fullQData(oldp+99,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[10]),64);
        tracep->fullQData(oldp+101,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[11]),64);
        tracep->fullQData(oldp+103,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[12]),64);
        tracep->fullQData(oldp+105,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[13]),64);
        tracep->fullQData(oldp+107,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[14]),64);
        tracep->fullQData(oldp+109,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[15]),64);
        tracep->fullQData(oldp+111,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[16]),64);
        tracep->fullQData(oldp+113,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[17]),64);
        tracep->fullQData(oldp+115,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[18]),64);
        tracep->fullQData(oldp+117,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[19]),64);
        tracep->fullQData(oldp+119,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[20]),64);
        tracep->fullQData(oldp+121,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[21]),64);
        tracep->fullQData(oldp+123,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[22]),64);
        tracep->fullQData(oldp+125,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[23]),64);
        tracep->fullQData(oldp+127,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[24]),64);
        tracep->fullQData(oldp+129,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[25]),64);
        tracep->fullQData(oldp+131,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[26]),64);
        tracep->fullQData(oldp+133,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[27]),64);
        tracep->fullQData(oldp+135,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[28]),64);
        tracep->fullQData(oldp+137,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[29]),64);
        tracep->fullQData(oldp+139,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[30]),64);
        tracep->fullQData(oldp+141,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[31]),64);
        tracep->fullBit(oldp+143,(vlTOPp->SimTop__DOT__cmt_wen));
        tracep->fullCData(oldp+144,(vlTOPp->SimTop__DOT__cmt_wdest),8);
        tracep->fullQData(oldp+145,(vlTOPp->SimTop__DOT__cmt_wdata),64);
        tracep->fullQData(oldp+147,(vlTOPp->SimTop__DOT__cmt_pc),64);
        tracep->fullIData(oldp+149,(vlTOPp->SimTop__DOT__cmt_inst),32);
        tracep->fullBit(oldp+150,(vlTOPp->SimTop__DOT__cmt_valid));
        tracep->fullBit(oldp+151,(vlTOPp->SimTop__DOT__trap));
        tracep->fullCData(oldp+152,(vlTOPp->SimTop__DOT__trap_code),8);
        tracep->fullQData(oldp+153,(vlTOPp->SimTop__DOT__cycleCnt),64);
        tracep->fullQData(oldp+155,(vlTOPp->SimTop__DOT__instrCnt),64);
        tracep->fullQData(oldp+157,(vlTOPp->SimTop__DOT__regs_diff[0]),64);
        tracep->fullQData(oldp+159,(vlTOPp->SimTop__DOT__regs_diff[1]),64);
        tracep->fullQData(oldp+161,(vlTOPp->SimTop__DOT__regs_diff[2]),64);
        tracep->fullQData(oldp+163,(vlTOPp->SimTop__DOT__regs_diff[3]),64);
        tracep->fullQData(oldp+165,(vlTOPp->SimTop__DOT__regs_diff[4]),64);
        tracep->fullQData(oldp+167,(vlTOPp->SimTop__DOT__regs_diff[5]),64);
        tracep->fullQData(oldp+169,(vlTOPp->SimTop__DOT__regs_diff[6]),64);
        tracep->fullQData(oldp+171,(vlTOPp->SimTop__DOT__regs_diff[7]),64);
        tracep->fullQData(oldp+173,(vlTOPp->SimTop__DOT__regs_diff[8]),64);
        tracep->fullQData(oldp+175,(vlTOPp->SimTop__DOT__regs_diff[9]),64);
        tracep->fullQData(oldp+177,(vlTOPp->SimTop__DOT__regs_diff[10]),64);
        tracep->fullQData(oldp+179,(vlTOPp->SimTop__DOT__regs_diff[11]),64);
        tracep->fullQData(oldp+181,(vlTOPp->SimTop__DOT__regs_diff[12]),64);
        tracep->fullQData(oldp+183,(vlTOPp->SimTop__DOT__regs_diff[13]),64);
        tracep->fullQData(oldp+185,(vlTOPp->SimTop__DOT__regs_diff[14]),64);
        tracep->fullQData(oldp+187,(vlTOPp->SimTop__DOT__regs_diff[15]),64);
        tracep->fullQData(oldp+189,(vlTOPp->SimTop__DOT__regs_diff[16]),64);
        tracep->fullQData(oldp+191,(vlTOPp->SimTop__DOT__regs_diff[17]),64);
        tracep->fullQData(oldp+193,(vlTOPp->SimTop__DOT__regs_diff[18]),64);
        tracep->fullQData(oldp+195,(vlTOPp->SimTop__DOT__regs_diff[19]),64);
        tracep->fullQData(oldp+197,(vlTOPp->SimTop__DOT__regs_diff[20]),64);
        tracep->fullQData(oldp+199,(vlTOPp->SimTop__DOT__regs_diff[21]),64);
        tracep->fullQData(oldp+201,(vlTOPp->SimTop__DOT__regs_diff[22]),64);
        tracep->fullQData(oldp+203,(vlTOPp->SimTop__DOT__regs_diff[23]),64);
        tracep->fullQData(oldp+205,(vlTOPp->SimTop__DOT__regs_diff[24]),64);
        tracep->fullQData(oldp+207,(vlTOPp->SimTop__DOT__regs_diff[25]),64);
        tracep->fullQData(oldp+209,(vlTOPp->SimTop__DOT__regs_diff[26]),64);
        tracep->fullQData(oldp+211,(vlTOPp->SimTop__DOT__regs_diff[27]),64);
        tracep->fullQData(oldp+213,(vlTOPp->SimTop__DOT__regs_diff[28]),64);
        tracep->fullQData(oldp+215,(vlTOPp->SimTop__DOT__regs_diff[29]),64);
        tracep->fullQData(oldp+217,(vlTOPp->SimTop__DOT__regs_diff[30]),64);
        tracep->fullQData(oldp+219,(vlTOPp->SimTop__DOT__regs_diff[31]),64);
        tracep->fullQData(oldp+221,(vlTOPp->SimTop__DOT__regs_diff
                                    [0U]),64);
        tracep->fullQData(oldp+223,(vlTOPp->SimTop__DOT__regs_diff
                                    [1U]),64);
        tracep->fullQData(oldp+225,(vlTOPp->SimTop__DOT__regs_diff
                                    [2U]),64);
        tracep->fullQData(oldp+227,(vlTOPp->SimTop__DOT__regs_diff
                                    [3U]),64);
        tracep->fullQData(oldp+229,(vlTOPp->SimTop__DOT__regs_diff
                                    [4U]),64);
        tracep->fullQData(oldp+231,(vlTOPp->SimTop__DOT__regs_diff
                                    [5U]),64);
        tracep->fullQData(oldp+233,(vlTOPp->SimTop__DOT__regs_diff
                                    [6U]),64);
        tracep->fullQData(oldp+235,(vlTOPp->SimTop__DOT__regs_diff
                                    [7U]),64);
        tracep->fullQData(oldp+237,(vlTOPp->SimTop__DOT__regs_diff
                                    [8U]),64);
        tracep->fullQData(oldp+239,(vlTOPp->SimTop__DOT__regs_diff
                                    [9U]),64);
        tracep->fullQData(oldp+241,(vlTOPp->SimTop__DOT__regs_diff
                                    [0xaU]),64);
        tracep->fullQData(oldp+243,(vlTOPp->SimTop__DOT__regs_diff
                                    [0xbU]),64);
        tracep->fullQData(oldp+245,(vlTOPp->SimTop__DOT__regs_diff
                                    [0xcU]),64);
        tracep->fullQData(oldp+247,(vlTOPp->SimTop__DOT__regs_diff
                                    [0xdU]),64);
        tracep->fullQData(oldp+249,(vlTOPp->SimTop__DOT__regs_diff
                                    [0xeU]),64);
        tracep->fullQData(oldp+251,(vlTOPp->SimTop__DOT__regs_diff
                                    [0xfU]),64);
        tracep->fullQData(oldp+253,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x10U]),64);
        tracep->fullQData(oldp+255,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x11U]),64);
        tracep->fullQData(oldp+257,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x12U]),64);
        tracep->fullQData(oldp+259,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x13U]),64);
        tracep->fullQData(oldp+261,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x14U]),64);
        tracep->fullQData(oldp+263,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x15U]),64);
        tracep->fullQData(oldp+265,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x16U]),64);
        tracep->fullQData(oldp+267,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x17U]),64);
        tracep->fullQData(oldp+269,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x18U]),64);
        tracep->fullQData(oldp+271,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x19U]),64);
        tracep->fullQData(oldp+273,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x1aU]),64);
        tracep->fullQData(oldp+275,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x1bU]),64);
        tracep->fullQData(oldp+277,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x1cU]),64);
        tracep->fullQData(oldp+279,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x1dU]),64);
        tracep->fullQData(oldp+281,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x1eU]),64);
        tracep->fullQData(oldp+283,(vlTOPp->SimTop__DOT__regs_diff
                                    [0x1fU]),64);
        tracep->fullCData(oldp+285,((7U & (IData)(vlTOPp->SimTop__DOT__trap_code))),3);
        tracep->fullBit(oldp+286,(vlTOPp->SimTop__DOT__rd_w_ena));
        tracep->fullCData(oldp+287,(vlTOPp->SimTop__DOT__rd_w_addr),5);
        tracep->fullCData(oldp+288,(vlTOPp->SimTop__DOT__inst_type),5);
        tracep->fullCData(oldp+289,(vlTOPp->SimTop__DOT__inst_opcode),8);
        tracep->fullQData(oldp+290,(vlTOPp->SimTop__DOT__regs[0]),64);
        tracep->fullQData(oldp+292,(vlTOPp->SimTop__DOT__regs[1]),64);
        tracep->fullQData(oldp+294,(vlTOPp->SimTop__DOT__regs[2]),64);
        tracep->fullQData(oldp+296,(vlTOPp->SimTop__DOT__regs[3]),64);
        tracep->fullQData(oldp+298,(vlTOPp->SimTop__DOT__regs[4]),64);
        tracep->fullQData(oldp+300,(vlTOPp->SimTop__DOT__regs[5]),64);
        tracep->fullQData(oldp+302,(vlTOPp->SimTop__DOT__regs[6]),64);
        tracep->fullQData(oldp+304,(vlTOPp->SimTop__DOT__regs[7]),64);
        tracep->fullQData(oldp+306,(vlTOPp->SimTop__DOT__regs[8]),64);
        tracep->fullQData(oldp+308,(vlTOPp->SimTop__DOT__regs[9]),64);
        tracep->fullQData(oldp+310,(vlTOPp->SimTop__DOT__regs[10]),64);
        tracep->fullQData(oldp+312,(vlTOPp->SimTop__DOT__regs[11]),64);
        tracep->fullQData(oldp+314,(vlTOPp->SimTop__DOT__regs[12]),64);
        tracep->fullQData(oldp+316,(vlTOPp->SimTop__DOT__regs[13]),64);
        tracep->fullQData(oldp+318,(vlTOPp->SimTop__DOT__regs[14]),64);
        tracep->fullQData(oldp+320,(vlTOPp->SimTop__DOT__regs[15]),64);
        tracep->fullQData(oldp+322,(vlTOPp->SimTop__DOT__regs[16]),64);
        tracep->fullQData(oldp+324,(vlTOPp->SimTop__DOT__regs[17]),64);
        tracep->fullQData(oldp+326,(vlTOPp->SimTop__DOT__regs[18]),64);
        tracep->fullQData(oldp+328,(vlTOPp->SimTop__DOT__regs[19]),64);
        tracep->fullQData(oldp+330,(vlTOPp->SimTop__DOT__regs[20]),64);
        tracep->fullQData(oldp+332,(vlTOPp->SimTop__DOT__regs[21]),64);
        tracep->fullQData(oldp+334,(vlTOPp->SimTop__DOT__regs[22]),64);
        tracep->fullQData(oldp+336,(vlTOPp->SimTop__DOT__regs[23]),64);
        tracep->fullQData(oldp+338,(vlTOPp->SimTop__DOT__regs[24]),64);
        tracep->fullQData(oldp+340,(vlTOPp->SimTop__DOT__regs[25]),64);
        tracep->fullQData(oldp+342,(vlTOPp->SimTop__DOT__regs[26]),64);
        tracep->fullQData(oldp+344,(vlTOPp->SimTop__DOT__regs[27]),64);
        tracep->fullQData(oldp+346,(vlTOPp->SimTop__DOT__regs[28]),64);
        tracep->fullQData(oldp+348,(vlTOPp->SimTop__DOT__regs[29]),64);
        tracep->fullQData(oldp+350,(vlTOPp->SimTop__DOT__regs[30]),64);
        tracep->fullQData(oldp+352,(vlTOPp->SimTop__DOT__regs[31]),64);
        tracep->fullQData(oldp+354,(vlTOPp->SimTop__DOT__rd_data),64);
        tracep->fullBit(oldp+356,(vlTOPp->clock));
        tracep->fullBit(oldp+357,(vlTOPp->reset));
        tracep->fullQData(oldp+358,(vlTOPp->io_logCtrl_log_begin),64);
        tracep->fullQData(oldp+360,(vlTOPp->io_logCtrl_log_end),64);
        tracep->fullQData(oldp+362,(vlTOPp->io_logCtrl_log_level),64);
        tracep->fullBit(oldp+364,(vlTOPp->io_perfInfo_clean));
        tracep->fullBit(oldp+365,(vlTOPp->io_perfInfo_dump));
        tracep->fullBit(oldp+366,(vlTOPp->io_uart_out_valid));
        tracep->fullCData(oldp+367,(vlTOPp->io_uart_out_ch),8);
        tracep->fullBit(oldp+368,(vlTOPp->io_uart_in_valid));
        tracep->fullCData(oldp+369,(vlTOPp->io_uart_in_ch),8);
        tracep->fullBit(oldp+370,(((IData)(vlTOPp->reset)
                                    ? 0U : (1U & ((IData)(vlTOPp->SimTop__DOT__inst_type) 
                                                  >> 4U)))));
        tracep->fullCData(oldp+371,(((IData)(vlTOPp->reset)
                                      ? 0U : ((0x10U 
                                               & (IData)(vlTOPp->SimTop__DOT__inst_type))
                                               ? (0x1fU 
                                                  & (vlTOPp->SimTop__DOT__inst 
                                                     >> 0xfU))
                                               : 0U))),5);
        tracep->fullQData(oldp+372,(((IData)(vlTOPp->reset)
                                      ? 0ULL : ((0x10U 
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
                                                 : 0ULL))),64);
        tracep->fullQData(oldp+374,(((IData)(vlTOPp->reset)
                                      ? 0ULL : ((0x10U 
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
                                                 : 0ULL))),64);
        tracep->fullQData(oldp+376,(((IData)(vlTOPp->reset)
                                      ? 0ULL : (((IData)(vlTOPp->reset)
                                                  ? 0U
                                                  : 
                                                 (1U 
                                                  & ((IData)(vlTOPp->SimTop__DOT__inst_type) 
                                                     >> 4U)))
                                                 ? 
                                                vlTOPp->SimTop__DOT__Regfile__DOT__regs
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
        tracep->fullBit(oldp+378,(0U));
        tracep->fullCData(oldp+379,(0U),5);
        tracep->fullQData(oldp+380,(0ULL),64);
        tracep->fullQData(oldp+382,(0x7ffffffcULL),64);
        tracep->fullBit(oldp+384,(1U));
        tracep->fullCData(oldp+385,(0U),8);
        tracep->fullCData(oldp+386,(0U),2);
    }
}
