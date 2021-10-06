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
        tracep->declBit(c+712,"clock", false,-1);
        tracep->declBit(c+713,"reset", false,-1);
        tracep->declQuad(c+714,"io_logCtrl_log_begin", false,-1, 63,0);
        tracep->declQuad(c+716,"io_logCtrl_log_end", false,-1, 63,0);
        tracep->declQuad(c+718,"io_logCtrl_log_level", false,-1, 63,0);
        tracep->declBit(c+720,"io_perfInfo_clean", false,-1);
        tracep->declBit(c+721,"io_perfInfo_dump", false,-1);
        tracep->declBit(c+722,"io_uart_out_valid", false,-1);
        tracep->declBus(c+723,"io_uart_out_ch", false,-1, 7,0);
        tracep->declBit(c+724,"io_uart_in_valid", false,-1);
        tracep->declBus(c+725,"io_uart_in_ch", false,-1, 7,0);
        tracep->declBit(c+712,"SimTop clock", false,-1);
        tracep->declBit(c+713,"SimTop reset", false,-1);
        tracep->declQuad(c+714,"SimTop io_logCtrl_log_begin", false,-1, 63,0);
        tracep->declQuad(c+716,"SimTop io_logCtrl_log_end", false,-1, 63,0);
        tracep->declQuad(c+718,"SimTop io_logCtrl_log_level", false,-1, 63,0);
        tracep->declBit(c+720,"SimTop io_perfInfo_clean", false,-1);
        tracep->declBit(c+721,"SimTop io_perfInfo_dump", false,-1);
        tracep->declBit(c+722,"SimTop io_uart_out_valid", false,-1);
        tracep->declBus(c+723,"SimTop io_uart_out_ch", false,-1, 7,0);
        tracep->declBit(c+724,"SimTop io_uart_in_valid", false,-1);
        tracep->declBus(c+725,"SimTop io_uart_in_ch", false,-1, 7,0);
        tracep->declQuad(c+736,"SimTop rd_data", false,-1, 63,0);
        tracep->declBus(c+22,"SimTop byte_enable", false,-1, 7,0);
        tracep->declQuad(c+23,"SimTop ram_wr_data", false,-1, 63,0);
        tracep->declQuad(c+25,"SimTop ram_rd_data", false,-1, 63,0);
        tracep->declBus(c+738,"SimTop if_excp", false,-1, 15,0);
        tracep->declQuad(c+27,"SimTop bj_pc", false,-1, 63,0);
        tracep->declQuad(c+29,"SimTop excp_pc", false,-1, 63,0);
        tracep->declQuad(c+686,"SimTop if_pc", false,-1, 63,0);
        tracep->declBit(c+688,"SimTop bj_ena", false,-1);
        tracep->declQuad(c+31,"SimTop id_pc", false,-1, 63,0);
        tracep->declBus(c+33,"SimTop id_inst", false,-1, 31,0);
        tracep->declBit(c+688,"SimTop flush", false,-1);
        tracep->declBit(c+34,"SimTop id_valid", false,-1);
        tracep->declBit(c+689,"SimTop id_allowin", false,-1);
        tracep->declBit(c+690,"SimTop id_ready_go", false,-1);
        tracep->declBit(c+691,"SimTop id_to_ex_valid", false,-1);
        tracep->declBit(c+692,"SimTop stall", false,-1);
        tracep->declBus(c+739,"SimTop id_excp", false,-1, 15,0);
        tracep->declBit(c+35,"SimTop id_is_word_opt", false,-1);
        tracep->declBus(c+36,"SimTop id_alu_info", false,-1, 11,0);
        tracep->declBus(c+37,"SimTop id_bj_info", false,-1, 7,0);
        tracep->declBus(c+38,"SimTop id_load_info", false,-1, 6,0);
        tracep->declBus(c+39,"SimTop id_save_info", false,-1, 3,0);
        tracep->declQuad(c+40,"SimTop id_jmp_imm", false,-1, 63,0);
        tracep->declQuad(c+693,"SimTop id_op1", false,-1, 63,0);
        tracep->declQuad(c+695,"SimTop id_op2", false,-1, 63,0);
        tracep->declBit(c+42,"SimTop id_use_rs1", false,-1);
        tracep->declBit(c+43,"SimTop id_use_rs2", false,-1);
        tracep->declQuad(c+697,"SimTop id_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+699,"SimTop id_rs2_data", false,-1, 63,0);
        tracep->declQuad(c+740,"SimTop id_csr_data", false,-1, 63,0);
        tracep->declBit(c+726,"SimTop id_ram_wr_ena", false,-1);
        tracep->declBit(c+727,"SimTop id_ram_rd_ena", false,-1);
        tracep->declBus(c+728,"SimTop id_reg_wr_ctrl", false,-1, 2,0);
        tracep->declBus(c+729,"SimTop id_reg_wr_addr", false,-1, 4,0);
        tracep->declBit(c+701,"SimTop id_reg_wr_ena", false,-1);
        tracep->declBus(c+44,"SimTop id_csr_wr_addr", false,-1, 11,0);
        tracep->declBit(c+730,"SimTop id_csr_wr_ena", false,-1);
        tracep->declQuad(c+45,"SimTop ex_pc", false,-1, 63,0);
        tracep->declBus(c+47,"SimTop ex_inst", false,-1, 31,0);
        tracep->declBit(c+48,"SimTop ex_is_word_opt", false,-1);
        tracep->declBus(c+49,"SimTop ex_alu_info", false,-1, 11,0);
        tracep->declBus(c+50,"SimTop ex_bj_info", false,-1, 7,0);
        tracep->declQuad(c+51,"SimTop ex_jmp_imm", false,-1, 63,0);
        tracep->declQuad(c+53,"SimTop ex_now_op1", false,-1, 63,0);
        tracep->declQuad(c+55,"SimTop ex_now_op2", false,-1, 63,0);
        tracep->declBit(c+57,"SimTop ex_use_rs1", false,-1);
        tracep->declBit(c+58,"SimTop ex_use_rs2", false,-1);
        tracep->declQuad(c+59,"SimTop ex_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+61,"SimTop ex_rs2_data", false,-1, 63,0);
        tracep->declBus(c+63,"SimTop ex_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+64,"SimTop ex_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+65,"SimTop ex_csr_data", false,-1, 63,0);
        tracep->declBit(c+67,"SimTop ex_ram_wr_ena_r", false,-1);
        tracep->declBit(c+68,"SimTop ex_ram_rd_ena_r", false,-1);
        tracep->declBit(c+69,"SimTop ex_ram_wr_ena", false,-1);
        tracep->declBit(c+70,"SimTop ex_ram_rd_ena", false,-1);
        tracep->declBus(c+71,"SimTop ex_load_info", false,-1, 6,0);
        tracep->declBus(c+72,"SimTop ex_save_info", false,-1, 3,0);
        tracep->declBus(c+73,"SimTop ex_reg_wr_ctrl", false,-1, 2,0);
        tracep->declBus(c+74,"SimTop ex_reg_wr_addr", false,-1, 4,0);
        tracep->declBit(c+75,"SimTop ex_reg_wr_ena_r", false,-1);
        tracep->declBit(c+76,"SimTop ex_reg_wr_ena", false,-1);
        tracep->declBus(c+77,"SimTop ex_csr_wr_addr", false,-1, 11,0);
        tracep->declBit(c+78,"SimTop ex_csr_wr_ena_r", false,-1);
        tracep->declBit(c+79,"SimTop ex_csr_wr_ena", false,-1);
        tracep->declBit(c+80,"SimTop ex_valid", false,-1);
        tracep->declBit(c+742,"SimTop ex_allowin", false,-1);
        tracep->declBit(c+742,"SimTop ex_ready_go", false,-1);
        tracep->declBit(c+80,"SimTop ex_to_mem_valid", false,-1);
        tracep->declQuad(c+81,"SimTop rs1_forward", false,-1, 63,0);
        tracep->declQuad(c+83,"SimTop rs2_forward", false,-1, 63,0);
        tracep->declQuad(c+85,"SimTop true_op1", false,-1, 63,0);
        tracep->declQuad(c+87,"SimTop true_op2", false,-1, 63,0);
        tracep->declQuad(c+731,"SimTop ex_data", false,-1, 63,0);
        tracep->declQuad(c+89,"SimTop mem_pc", false,-1, 63,0);
        tracep->declBus(c+91,"SimTop mem_inst", false,-1, 31,0);
        tracep->declBus(c+92,"SimTop mem_load_info", false,-1, 6,0);
        tracep->declBus(c+93,"SimTop mem_save_info", false,-1, 3,0);
        tracep->declQuad(c+94,"SimTop mem_ram_wr_src", false,-1, 63,0);
        tracep->declQuad(c+96,"SimTop mem_ex_data", false,-1, 63,0);
        tracep->declQuad(c+98,"SimTop mem_csr_data", false,-1, 63,0);
        tracep->declBit(c+100,"SimTop mem_ram_wr_ena", false,-1);
        tracep->declBit(c+101,"SimTop mem_ram_rd_ena", false,-1);
        tracep->declBus(c+102,"SimTop mem_reg_wr_ctrl", false,-1, 2,0);
        tracep->declBus(c+103,"SimTop mem_reg_wr_addr", false,-1, 4,0);
        tracep->declBit(c+104,"SimTop mem_reg_wr_ena", false,-1);
        tracep->declBus(c+743,"SimTop mem_csr_wr_addr", false,-1, 11,0);
        tracep->declBit(c+105,"SimTop mem_csr_wr_ena", false,-1);
        tracep->declBit(c+106,"SimTop mem_valid", false,-1);
        tracep->declBit(c+742,"SimTop mem_allowin", false,-1);
        tracep->declBit(c+742,"SimTop mem_ready_go", false,-1);
        tracep->declBit(c+106,"SimTop mem_to_wb_valid", false,-1);
        tracep->declBus(c+744,"SimTop mem_excp", false,-1, 15,0);
        tracep->declQuad(c+702,"SimTop mem_ram_data", false,-1, 63,0);
        tracep->declQuad(c+107,"SimTop wb_pc", false,-1, 63,0);
        tracep->declBus(c+109,"SimTop wb_inst", false,-1, 31,0);
        tracep->declBus(c+110,"SimTop wb_reg_wr_ctrl", false,-1, 2,0);
        tracep->declQuad(c+111,"SimTop wb_ex_data", false,-1, 63,0);
        tracep->declQuad(c+113,"SimTop wb_ram_data", false,-1, 63,0);
        tracep->declQuad(c+115,"SimTop wb_csr_data", false,-1, 63,0);
        tracep->declBus(c+117,"SimTop wb_reg_wr_addr", false,-1, 4,0);
        tracep->declBit(c+118,"SimTop wb_reg_wr_ena", false,-1);
        tracep->declBus(c+119,"SimTop wb_csr_wr_addr", false,-1, 11,0);
        tracep->declBit(c+120,"SimTop wb_csr_wr_ena", false,-1);
        tracep->declBit(c+121,"SimTop wb_valid", false,-1);
        tracep->declBit(c+742,"SimTop wb_allowin", false,-1);
        tracep->declBit(c+704,"SimTop rs1_r_ena", false,-1);
        tracep->declBus(c+705,"SimTop rs1_r_addr", false,-1, 4,0);
        tracep->declQuad(c+697,"SimTop r_data1", false,-1, 63,0);
        tracep->declBit(c+706,"SimTop rs2_r_ena", false,-1);
        tracep->declBus(c+707,"SimTop rs2_r_addr", false,-1, 4,0);
        tracep->declQuad(c+699,"SimTop r_data2", false,-1, 63,0);
        tracep->declQuad(c+708,"SimTop wb_reg_wr_data", false,-1, 63,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+122+i*2,"SimTop regs", true,(i+0), 63,0);}}
        tracep->declBit(c+1,"SimTop excp_enter", false,-1);
        tracep->declBit(c+745,"SimTop excp_exit", false,-1);
        tracep->declBit(c+2,"SimTop excp_jmp_ena", false,-1);
        tracep->declBit(c+746,"SimTop csr_rd_ena", false,-1);
        tracep->declBus(c+44,"SimTop csr_rd_addr", false,-1, 11,0);
        tracep->declBit(c+747,"SimTop csr_wr_ena", false,-1);
        tracep->declBus(c+748,"SimTop csr_wr_addr", false,-1, 11,0);
        tracep->declQuad(c+733,"SimTop csr_rd_data", false,-1, 63,0);
        tracep->declQuad(c+186,"SimTop mstatus_wr_data", false,-1, 63,0);
        tracep->declQuad(c+188,"SimTop mstatus_rd_data", false,-1, 63,0);
        tracep->declQuad(c+190,"SimTop mie_rd_data", false,-1, 63,0);
        tracep->declQuad(c+192,"SimTop mtvec_rd_data", false,-1, 63,0);
        tracep->declQuad(c+194,"SimTop mscratch_rd_data", false,-1, 63,0);
        tracep->declQuad(c+196,"SimTop mepc_wr_data", false,-1, 63,0);
        tracep->declQuad(c+198,"SimTop mepc_rd_data", false,-1, 63,0);
        tracep->declQuad(c+3,"SimTop mcause_wr_data", false,-1, 63,0);
        tracep->declQuad(c+200,"SimTop mcause_rd_data", false,-1, 63,0);
        tracep->declQuad(c+749,"SimTop mtval_rd_data", false,-1, 63,0);
        tracep->declQuad(c+202,"SimTop mtval_wr_data", false,-1, 63,0);
        tracep->declQuad(c+204,"SimTop mip_rd_data", false,-1, 63,0);
        tracep->declBit(c+206,"SimTop cmt_wen", false,-1);
        tracep->declBus(c+207,"SimTop cmt_wdest", false,-1, 7,0);
        tracep->declQuad(c+208,"SimTop cmt_wdata", false,-1, 63,0);
        tracep->declQuad(c+210,"SimTop cmt_pc", false,-1, 63,0);
        tracep->declBus(c+212,"SimTop cmt_inst", false,-1, 31,0);
        tracep->declBit(c+213,"SimTop vaild", false,-1);
        tracep->declBit(c+214,"SimTop skip", false,-1);
        tracep->declQuad(c+215,"SimTop cycleCnt", false,-1, 63,0);
        tracep->declQuad(c+217,"SimTop instrCnt", false,-1, 63,0);
        tracep->declBit(c+712,"SimTop RAM_1W2R clk", false,-1);
        tracep->declQuad(c+31,"SimTop RAM_1W2R inst_addr", false,-1, 63,0);
        tracep->declBit(c+742,"SimTop RAM_1W2R inst_ena", false,-1);
        tracep->declBus(c+33,"SimTop RAM_1W2R inst", false,-1, 31,0);
        tracep->declBit(c+100,"SimTop RAM_1W2R mem_wr_ena", false,-1);
        tracep->declBit(c+101,"SimTop RAM_1W2R mem_rd_ena", false,-1);
        tracep->declBus(c+22,"SimTop RAM_1W2R byte_enable", false,-1, 7,0);
        tracep->declQuad(c+96,"SimTop RAM_1W2R mem_addr", false,-1, 63,0);
        tracep->declQuad(c+23,"SimTop RAM_1W2R mem_wr_data", false,-1, 63,0);
        tracep->declQuad(c+25,"SimTop RAM_1W2R mem_rd_data", false,-1, 63,0);
        tracep->declQuad(c+219,"SimTop RAM_1W2R inst_2", false,-1, 63,0);
        tracep->declQuad(c+221,"SimTop RAM_1W2R wmask", false,-1, 63,0);
        tracep->declBit(c+712,"SimTop If_stage clk", false,-1);
        tracep->declBit(c+713,"SimTop If_stage rst", false,-1);
        tracep->declQuad(c+31,"SimTop If_stage pc_now", false,-1, 63,0);
        tracep->declBit(c+688,"SimTop If_stage bj_ena", false,-1);
        tracep->declQuad(c+27,"SimTop If_stage bj_pc", false,-1, 63,0);
        tracep->declBit(c+2,"SimTop If_stage excp_jmp_ena", false,-1);
        tracep->declQuad(c+29,"SimTop If_stage excp_pc", false,-1, 63,0);
        tracep->declQuad(c+686,"SimTop If_stage pc", false,-1, 63,0);
        tracep->declBit(c+70,"SimTop Hazard ex_ram_rd_ena", false,-1);
        tracep->declBus(c+74,"SimTop Hazard ex_reg_wr_addr", false,-1, 4,0);
        tracep->declBus(c+705,"SimTop Hazard rs1_addr", false,-1, 4,0);
        tracep->declBus(c+707,"SimTop Hazard rs2_addr", false,-1, 4,0);
        tracep->declBit(c+692,"SimTop Hazard stall", false,-1);
        tracep->declBit(c+713,"SimTop Id_stage rst", false,-1);
        tracep->declBit(c+712,"SimTop Id_stage clk", false,-1);
        tracep->declBus(c+33,"SimTop Id_stage inst", false,-1, 31,0);
        tracep->declQuad(c+31,"SimTop Id_stage pc_id", false,-1, 63,0);
        tracep->declQuad(c+697,"SimTop Id_stage r_data1", false,-1, 63,0);
        tracep->declQuad(c+699,"SimTop Id_stage r_data2", false,-1, 63,0);
        tracep->declQuad(c+740,"SimTop Id_stage csr_data", false,-1, 63,0);
        tracep->declBit(c+704,"SimTop Id_stage rs1_r_ena", false,-1);
        tracep->declBus(c+705,"SimTop Id_stage rs1_addr", false,-1, 4,0);
        tracep->declBit(c+706,"SimTop Id_stage rs2_r_ena", false,-1);
        tracep->declBus(c+707,"SimTop Id_stage rs2_addr", false,-1, 4,0);
        tracep->declBit(c+746,"SimTop Id_stage csr_rd_ena", false,-1);
        tracep->declBus(c+44,"SimTop Id_stage csr_rd_addr", false,-1, 11,0);
        tracep->declQuad(c+693,"SimTop Id_stage id_op1", false,-1, 63,0);
        tracep->declQuad(c+695,"SimTop Id_stage id_op2", false,-1, 63,0);
        tracep->declBit(c+42,"SimTop Id_stage use_rs1", false,-1);
        tracep->declBit(c+43,"SimTop Id_stage use_rs2", false,-1);
        tracep->declQuad(c+697,"SimTop Id_stage id_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+699,"SimTop Id_stage id_rs2_data", false,-1, 63,0);
        tracep->declBit(c+35,"SimTop Id_stage is_word_opt", false,-1);
        tracep->declBus(c+36,"SimTop Id_stage alu_info", false,-1, 11,0);
        tracep->declBus(c+37,"SimTop Id_stage bj_info", false,-1, 7,0);
        tracep->declBus(c+38,"SimTop Id_stage load_info", false,-1, 6,0);
        tracep->declBus(c+39,"SimTop Id_stage save_info", false,-1, 3,0);
        tracep->declQuad(c+40,"SimTop Id_stage jmp_imm", false,-1, 63,0);
        tracep->declBit(c+727,"SimTop Id_stage mem_rd_ena", false,-1);
        tracep->declBit(c+726,"SimTop Id_stage mem_wr_ena", false,-1);
        tracep->declBus(c+728,"SimTop Id_stage reg_wr_ctrl", false,-1, 2,0);
        tracep->declBit(c+701,"SimTop Id_stage reg_wr_ena", false,-1);
        tracep->declBus(c+729,"SimTop Id_stage reg_wr_addr", false,-1, 4,0);
        tracep->declBit(c+730,"SimTop Id_stage csr_wr_ena", false,-1);
        tracep->declBus(c+44,"SimTop Id_stage csr_wr_addr", false,-1, 11,0);
        tracep->declBus(c+223,"SimTop Id_stage opcode", false,-1, 6,0);
        tracep->declBus(c+224,"SimTop Id_stage func3", false,-1, 2,0);
        tracep->declBus(c+225,"SimTop Id_stage func6", false,-1, 5,0);
        tracep->declBus(c+226,"SimTop Id_stage func7", false,-1, 6,0);
        tracep->declBus(c+44,"SimTop Id_stage csr_addr", false,-1, 11,0);
        tracep->declBus(c+227,"SimTop Id_stage rd_addr", false,-1, 4,0);
        tracep->declBus(c+705,"SimTop Id_stage zimm", false,-1, 4,0);
        tracep->declBus(c+44,"SimTop Id_stage immI", false,-1, 11,0);
        tracep->declBus(c+228,"SimTop Id_stage immS", false,-1, 11,0);
        tracep->declBus(c+229,"SimTop Id_stage immB", false,-1, 12,0);
        tracep->declBus(c+230,"SimTop Id_stage immU", false,-1, 19,0);
        tracep->declBus(c+231,"SimTop Id_stage immJ", false,-1, 20,0);
        tracep->declBit(c+232,"SimTop Id_stage func3_0", false,-1);
        tracep->declBit(c+233,"SimTop Id_stage func3_1", false,-1);
        tracep->declBit(c+234,"SimTop Id_stage func3_2", false,-1);
        tracep->declBit(c+235,"SimTop Id_stage func3_3", false,-1);
        tracep->declBit(c+236,"SimTop Id_stage func3_4", false,-1);
        tracep->declBit(c+237,"SimTop Id_stage func3_5", false,-1);
        tracep->declBit(c+238,"SimTop Id_stage func3_6", false,-1);
        tracep->declBit(c+239,"SimTop Id_stage func3_7", false,-1);
        tracep->declBit(c+240,"SimTop Id_stage func6_00", false,-1);
        tracep->declBit(c+241,"SimTop Id_stage func6_10", false,-1);
        tracep->declBit(c+242,"SimTop Id_stage func7_00", false,-1);
        tracep->declBit(c+243,"SimTop Id_stage func7_20", false,-1);
        tracep->declBit(c+244,"SimTop Id_stage imm12_000", false,-1);
        tracep->declBit(c+245,"SimTop Id_stage imm12_001", false,-1);
        tracep->declBit(c+246,"SimTop Id_stage imm12_102", false,-1);
        tracep->declBit(c+247,"SimTop Id_stage inst_i_load", false,-1);
        tracep->declBit(c+248,"SimTop Id_stage inst_i_fence", false,-1);
        tracep->declBit(c+249,"SimTop Id_stage inst_i_arith_dword", false,-1);
        tracep->declBit(c+250,"SimTop Id_stage inst_u_auipc", false,-1);
        tracep->declBit(c+251,"SimTop Id_stage inst_i_arith_word", false,-1);
        tracep->declBit(c+252,"SimTop Id_stage inst_s", false,-1);
        tracep->declBit(c+253,"SimTop Id_stage inst_r_dword", false,-1);
        tracep->declBit(c+254,"SimTop Id_stage inst_u_lui", false,-1);
        tracep->declBit(c+255,"SimTop Id_stage inst_r_word", false,-1);
        tracep->declBit(c+256,"SimTop Id_stage inst_b", false,-1);
        tracep->declBit(c+257,"SimTop Id_stage inst_i_jalr", false,-1);
        tracep->declBit(c+258,"SimTop Id_stage inst_j", false,-1);
        tracep->declBit(c+259,"SimTop Id_stage inst_i_sys", false,-1);
        tracep->declBit(c+260,"SimTop Id_stage inst_i_excp", false,-1);
        tracep->declBit(c+261,"SimTop Id_stage inst_i_csr_imm", false,-1);
        tracep->declBit(c+262,"SimTop Id_stage inst_i_csr_reg", false,-1);
        tracep->declBit(c+263,"SimTop Id_stage inst_putch", false,-1);
        tracep->declBit(c+264,"SimTop Id_stage inst_lb", false,-1);
        tracep->declBit(c+265,"SimTop Id_stage inst_lh", false,-1);
        tracep->declBit(c+266,"SimTop Id_stage inst_lw", false,-1);
        tracep->declBit(c+267,"SimTop Id_stage inst_ld", false,-1);
        tracep->declBit(c+268,"SimTop Id_stage inst_lbu", false,-1);
        tracep->declBit(c+269,"SimTop Id_stage inst_lhu", false,-1);
        tracep->declBit(c+270,"SimTop Id_stage inst_lwu", false,-1);
        tracep->declBit(c+271,"SimTop Id_stage load_vld", false,-1);
        tracep->declBit(c+272,"SimTop Id_stage inst_fence", false,-1);
        tracep->declBit(c+273,"SimTop Id_stage inst_fence_i", false,-1);
        tracep->declBit(c+274,"SimTop Id_stage fence_vld", false,-1);
        tracep->declBit(c+275,"SimTop Id_stage inst_addi", false,-1);
        tracep->declBit(c+276,"SimTop Id_stage inst_slli", false,-1);
        tracep->declBit(c+277,"SimTop Id_stage inst_slti", false,-1);
        tracep->declBit(c+278,"SimTop Id_stage inst_sltiu", false,-1);
        tracep->declBit(c+279,"SimTop Id_stage inst_xori", false,-1);
        tracep->declBit(c+280,"SimTop Id_stage inst_srli", false,-1);
        tracep->declBit(c+281,"SimTop Id_stage inst_srai", false,-1);
        tracep->declBit(c+282,"SimTop Id_stage inst_ori", false,-1);
        tracep->declBit(c+283,"SimTop Id_stage inst_andi", false,-1);
        tracep->declBit(c+284,"SimTop Id_stage arith_id_vld", false,-1);
        tracep->declBit(c+250,"SimTop Id_stage inst_auipc", false,-1);
        tracep->declBit(c+250,"SimTop Id_stage auipc_vld", false,-1);
        tracep->declBit(c+285,"SimTop Id_stage inst_addiw", false,-1);
        tracep->declBit(c+286,"SimTop Id_stage inst_slliw", false,-1);
        tracep->declBit(c+287,"SimTop Id_stage inst_srliw", false,-1);
        tracep->declBit(c+288,"SimTop Id_stage inst_sraiw", false,-1);
        tracep->declBit(c+289,"SimTop Id_stage arith_iw_vld", false,-1);
        tracep->declBit(c+290,"SimTop Id_stage inst_sb", false,-1);
        tracep->declBit(c+291,"SimTop Id_stage inst_sh", false,-1);
        tracep->declBit(c+292,"SimTop Id_stage inst_sw", false,-1);
        tracep->declBit(c+293,"SimTop Id_stage inst_sd", false,-1);
        tracep->declBit(c+294,"SimTop Id_stage store_vld", false,-1);
        tracep->declBit(c+295,"SimTop Id_stage inst_add", false,-1);
        tracep->declBit(c+296,"SimTop Id_stage inst_sub", false,-1);
        tracep->declBit(c+297,"SimTop Id_stage inst_sll", false,-1);
        tracep->declBit(c+298,"SimTop Id_stage inst_slt", false,-1);
        tracep->declBit(c+299,"SimTop Id_stage inst_sltu", false,-1);
        tracep->declBit(c+300,"SimTop Id_stage inst_xor", false,-1);
        tracep->declBit(c+301,"SimTop Id_stage inst_srl", false,-1);
        tracep->declBit(c+302,"SimTop Id_stage inst_sra", false,-1);
        tracep->declBit(c+303,"SimTop Id_stage inst_or", false,-1);
        tracep->declBit(c+304,"SimTop Id_stage inst_and", false,-1);
        tracep->declBit(c+305,"SimTop Id_stage arith_rd_vld", false,-1);
        tracep->declBit(c+254,"SimTop Id_stage inst_lui", false,-1);
        tracep->declBit(c+254,"SimTop Id_stage lui_vld", false,-1);
        tracep->declBit(c+306,"SimTop Id_stage inst_addw", false,-1);
        tracep->declBit(c+307,"SimTop Id_stage inst_subw", false,-1);
        tracep->declBit(c+308,"SimTop Id_stage inst_sllw", false,-1);
        tracep->declBit(c+309,"SimTop Id_stage inst_srlw", false,-1);
        tracep->declBit(c+310,"SimTop Id_stage inst_sraw", false,-1);
        tracep->declBit(c+311,"SimTop Id_stage arith_rw_vld", false,-1);
        tracep->declBit(c+312,"SimTop Id_stage inst_beq", false,-1);
        tracep->declBit(c+313,"SimTop Id_stage inst_bne", false,-1);
        tracep->declBit(c+314,"SimTop Id_stage inst_blt", false,-1);
        tracep->declBit(c+315,"SimTop Id_stage inst_bge", false,-1);
        tracep->declBit(c+316,"SimTop Id_stage inst_bltu", false,-1);
        tracep->declBit(c+317,"SimTop Id_stage inst_bgeu", false,-1);
        tracep->declBit(c+318,"SimTop Id_stage branch_vld", false,-1);
        tracep->declBit(c+257,"SimTop Id_stage inst_jalr", false,-1);
        tracep->declBit(c+258,"SimTop Id_stage inst_jal", false,-1);
        tracep->declBit(c+319,"SimTop Id_stage jump_vld", false,-1);
        tracep->declBit(c+320,"SimTop Id_stage inst_ecall", false,-1);
        tracep->declBit(c+321,"SimTop Id_stage inst_ebreak", false,-1);
        tracep->declBit(c+322,"SimTop Id_stage inst_mret", false,-1);
        tracep->declBit(c+323,"SimTop Id_stage excp_vld", false,-1);
        tracep->declBit(c+324,"SimTop Id_stage inst_csrrw", false,-1);
        tracep->declBit(c+325,"SimTop Id_stage inst_csrrs", false,-1);
        tracep->declBit(c+326,"SimTop Id_stage inst_csrrc", false,-1);
        tracep->declBit(c+327,"SimTop Id_stage inst_csrrwi", false,-1);
        tracep->declBit(c+328,"SimTop Id_stage inst_csrrsi", false,-1);
        tracep->declBit(c+329,"SimTop Id_stage inst_csrrci", false,-1);
        tracep->declBit(c+330,"SimTop Id_stage csr_vld", false,-1);
        tracep->declBit(c+331,"SimTop Id_stage inst_vld", false,-1);
        tracep->declBit(c+730,"SimTop Id_stage csr_to_reg", false,-1);
        tracep->declBit(c+727,"SimTop Id_stage mem_to_reg", false,-1);
        tracep->declBit(c+735,"SimTop Id_stage exe_to_reg", false,-1);
        tracep->declBus(c+63,"SimTop Forward rs1_addr", false,-1, 4,0);
        tracep->declBus(c+64,"SimTop Forward rs2_addr", false,-1, 4,0);
        tracep->declBus(c+103,"SimTop Forward mem_reg_wr_addr", false,-1, 4,0);
        tracep->declBit(c+104,"SimTop Forward mem_reg_wr_ena", false,-1);
        tracep->declBus(c+117,"SimTop Forward wb_reg_wr_addr", false,-1, 4,0);
        tracep->declBit(c+118,"SimTop Forward wb_reg_wr_ena", false,-1);
        tracep->declQuad(c+96,"SimTop Forward mem_ex_data", false,-1, 63,0);
        tracep->declQuad(c+111,"SimTop Forward wb_ex_data", false,-1, 63,0);
        tracep->declQuad(c+113,"SimTop Forward wb_mem_data", false,-1, 63,0);
        tracep->declBus(c+102,"SimTop Forward mem_reg_wr_ctrl", false,-1, 2,0);
        tracep->declBus(c+110,"SimTop Forward wb_reg_wr_ctrl", false,-1, 2,0);
        tracep->declQuad(c+59,"SimTop Forward rs1_now", false,-1, 63,0);
        tracep->declQuad(c+61,"SimTop Forward rs2_now", false,-1, 63,0);
        tracep->declQuad(c+81,"SimTop Forward rs1_forward", false,-1, 63,0);
        tracep->declQuad(c+83,"SimTop Forward rs2_forward", false,-1, 63,0);
        tracep->declBit(c+332,"SimTop Forward mem_op1_src_ex", false,-1);
        tracep->declBit(c+333,"SimTop Forward wb_op1_src_ex", false,-1);
        tracep->declBit(c+334,"SimTop Forward mem_op1_src_mem", false,-1);
        tracep->declBit(c+335,"SimTop Forward wb_op1_src_mem", false,-1);
        tracep->declBit(c+336,"SimTop Forward mem_op2_src_ex", false,-1);
        tracep->declBit(c+337,"SimTop Forward wb_op2_src_ex", false,-1);
        tracep->declBit(c+338,"SimTop Forward mem_op2_src_mem", false,-1);
        tracep->declBit(c+339,"SimTop Forward wb_op2_src_mem", false,-1);
        tracep->declBit(c+713,"SimTop Ex_stage rst", false,-1);
        tracep->declBit(c+80,"SimTop Ex_stage ex_valid", false,-1);
        tracep->declQuad(c+85,"SimTop Ex_stage ex_op1", false,-1, 63,0);
        tracep->declQuad(c+87,"SimTop Ex_stage ex_op2", false,-1, 63,0);
        tracep->declQuad(c+81,"SimTop Ex_stage rs1_forward", false,-1, 63,0);
        tracep->declQuad(c+83,"SimTop Ex_stage rs2_forward", false,-1, 63,0);
        tracep->declBit(c+48,"SimTop Ex_stage is_word_opt", false,-1);
        tracep->declBus(c+49,"SimTop Ex_stage alu_info", false,-1, 11,0);
        tracep->declBus(c+50,"SimTop Ex_stage bj_info", false,-1, 7,0);
        tracep->declQuad(c+51,"SimTop Ex_stage jmp_imm", false,-1, 63,0);
        tracep->declQuad(c+45,"SimTop Ex_stage now_pc", false,-1, 63,0);
        tracep->declQuad(c+731,"SimTop Ex_stage rd_data", false,-1, 63,0);
        tracep->declQuad(c+27,"SimTop Ex_stage bj_pc", false,-1, 63,0);
        tracep->declBit(c+688,"SimTop Ex_stage bj_ena", false,-1);
        tracep->declBus(c+340,"SimTop Ex_stage bj_data", false,-1, 7,0);
        tracep->declQuad(c+341,"SimTop Ex_stage op1", false,-1, 63,0);
        tracep->declQuad(c+343,"SimTop Ex_stage op2", false,-1, 63,0);
        tracep->declBit(c+713,"SimTop Ex_stage Exe_stage_alu rst", false,-1);
        tracep->declQuad(c+341,"SimTop Ex_stage Exe_stage_alu op1", false,-1, 63,0);
        tracep->declQuad(c+343,"SimTop Ex_stage Exe_stage_alu op2", false,-1, 63,0);
        tracep->declBus(c+49,"SimTop Ex_stage Exe_stage_alu alu_info", false,-1, 11,0);
        tracep->declBit(c+48,"SimTop Ex_stage Exe_stage_alu is_word_opt", false,-1);
        tracep->declQuad(c+731,"SimTop Ex_stage Exe_stage_alu alu_output", false,-1, 63,0);
        tracep->declBus(c+340,"SimTop Ex_stage Exe_stage_alu bj_data", false,-1, 7,0);
        tracep->declBit(c+345,"SimTop Ex_stage Exe_stage_alu op_add", false,-1);
        tracep->declBit(c+346,"SimTop Ex_stage Exe_stage_alu op_sub", false,-1);
        tracep->declBit(c+347,"SimTop Ex_stage Exe_stage_alu op_slt", false,-1);
        tracep->declBit(c+348,"SimTop Ex_stage Exe_stage_alu op_sltu", false,-1);
        tracep->declBit(c+349,"SimTop Ex_stage Exe_stage_alu op_xor", false,-1);
        tracep->declBit(c+350,"SimTop Ex_stage Exe_stage_alu op_or", false,-1);
        tracep->declBit(c+351,"SimTop Ex_stage Exe_stage_alu op_and", false,-1);
        tracep->declBit(c+352,"SimTop Ex_stage Exe_stage_alu op_sll", false,-1);
        tracep->declBit(c+353,"SimTop Ex_stage Exe_stage_alu op_srl", false,-1);
        tracep->declBit(c+354,"SimTop Ex_stage Exe_stage_alu op_sra", false,-1);
        tracep->declBit(c+355,"SimTop Ex_stage Exe_stage_alu op_andn", false,-1);
        tracep->declBit(c+356,"SimTop Ex_stage Exe_stage_alu op_wri", false,-1);
        tracep->declBit(c+357,"SimTop Ex_stage Exe_stage_alu op_shift", false,-1);
        tracep->declQuad(c+341,"SimTop Ex_stage Exe_stage_alu shifter_op1", false,-1, 63,0);
        tracep->declQuad(c+358,"SimTop Ex_stage Exe_stage_alu shifter_in1", false,-1, 63,0);
        tracep->declBus(c+360,"SimTop Ex_stage Exe_stage_alu shifter_in2", false,-1, 5,0);
        tracep->declQuad(c+361,"SimTop Ex_stage Exe_stage_alu shifter_res", false,-1, 63,0);
        tracep->declQuad(c+361,"SimTop Ex_stage Exe_stage_alu sll_res", false,-1, 63,0);
        tracep->declQuad(c+363,"SimTop Ex_stage Exe_stage_alu srl_res", false,-1, 63,0);
        tracep->declQuad(c+365,"SimTop Ex_stage Exe_stage_alu eff_mask", false,-1, 63,0);
        tracep->declQuad(c+367,"SimTop Ex_stage Exe_stage_alu sra_res", false,-1, 63,0);
        tracep->declBit(c+345,"SimTop Ex_stage Exe_stage_alu temp_add", false,-1);
        tracep->declBit(c+369,"SimTop Ex_stage Exe_stage_alu temp_sub", false,-1);
        tracep->declBit(c+370,"SimTop Ex_stage Exe_stage_alu op_addsub", false,-1);
        tracep->declBit(c+348,"SimTop Ex_stage Exe_stage_alu op_unsigned", false,-1);
        tracep->declArray(c+371,"SimTop Ex_stage Exe_stage_alu adder_op1", false,-1, 64,0);
        tracep->declArray(c+374,"SimTop Ex_stage Exe_stage_alu adder_op2", false,-1, 64,0);
        tracep->declArray(c+377,"SimTop Ex_stage Exe_stage_alu adder_in1", false,-1, 64,0);
        tracep->declArray(c+380,"SimTop Ex_stage Exe_stage_alu adder_in2", false,-1, 64,0);
        tracep->declArray(c+383,"SimTop Ex_stage Exe_stage_alu adder_cin", false,-1, 64,0);
        tracep->declArray(c+386,"SimTop Ex_stage Exe_stage_alu add_res", false,-1, 64,0);
        tracep->declQuad(c+389,"SimTop Ex_stage Exe_stage_alu slt_res", false,-1, 63,0);
        tracep->declQuad(c+389,"SimTop Ex_stage Exe_stage_alu sltu_res", false,-1, 63,0);
        tracep->declQuad(c+391,"SimTop Ex_stage Exe_stage_alu xor_res", false,-1, 63,0);
        tracep->declQuad(c+393,"SimTop Ex_stage Exe_stage_alu or_res", false,-1, 63,0);
        tracep->declQuad(c+395,"SimTop Ex_stage Exe_stage_alu and_res", false,-1, 63,0);
        tracep->declQuad(c+397,"SimTop Ex_stage Exe_stage_alu andn_res", false,-1, 63,0);
        tracep->declQuad(c+343,"SimTop Ex_stage Exe_stage_alu wri_res", false,-1, 63,0);
        tracep->declQuad(c+710,"SimTop Ex_stage Exe_stage_alu temp_output", false,-1, 63,0);
        tracep->declBit(c+399,"SimTop Ex_stage Exe_stage_alu eq_res", false,-1);
        tracep->declBit(c+713,"SimTop Ex_stage Exe_stage_bj rst", false,-1);
        tracep->declBit(c+80,"SimTop Ex_stage Exe_stage_bj ex_valid", false,-1);
        tracep->declBus(c+50,"SimTop Ex_stage Exe_stage_bj bj_info", false,-1, 7,0);
        tracep->declBus(c+340,"SimTop Ex_stage Exe_stage_bj bj_data", false,-1, 7,0);
        tracep->declQuad(c+51,"SimTop Ex_stage Exe_stage_bj jmp_imm", false,-1, 63,0);
        tracep->declQuad(c+81,"SimTop Ex_stage Exe_stage_bj ex_op1", false,-1, 63,0);
        tracep->declQuad(c+45,"SimTop Ex_stage Exe_stage_bj now_pc", false,-1, 63,0);
        tracep->declBit(c+688,"SimTop Ex_stage Exe_stage_bj bj_ena", false,-1);
        tracep->declQuad(c+27,"SimTop Ex_stage Exe_stage_bj new_pc", false,-1, 63,0);
        tracep->declBit(c+712,"SimTop Mem_stage clk", false,-1);
        tracep->declBit(c+713,"SimTop Mem_stage rst", false,-1);
        tracep->declQuad(c+94,"SimTop Mem_stage r_data2", false,-1, 63,0);
        tracep->declBus(c+92,"SimTop Mem_stage load_info", false,-1, 6,0);
        tracep->declBus(c+93,"SimTop Mem_stage save_info", false,-1, 3,0);
        tracep->declQuad(c+96,"SimTop Mem_stage mem_addr", false,-1, 63,0);
        tracep->declQuad(c+25,"SimTop Mem_stage ram_rd_data", false,-1, 63,0);
        tracep->declQuad(c+702,"SimTop Mem_stage mem_data", false,-1, 63,0);
        tracep->declQuad(c+23,"SimTop Mem_stage ram_wr_data", false,-1, 63,0);
        tracep->declBus(c+22,"SimTop Mem_stage byte_enable", false,-1, 7,0);
        tracep->declBus(c+744,"SimTop Mem_stage mem_excp", false,-1, 15,0);
        tracep->declBit(c+400,"SimTop Mem_stage addr_0", false,-1);
        tracep->declBit(c+401,"SimTop Mem_stage addr_1", false,-1);
        tracep->declBit(c+402,"SimTop Mem_stage addr_2", false,-1);
        tracep->declBit(c+403,"SimTop Mem_stage addr_3", false,-1);
        tracep->declBit(c+404,"SimTop Mem_stage addr_4", false,-1);
        tracep->declBit(c+405,"SimTop Mem_stage addr_5", false,-1);
        tracep->declBit(c+406,"SimTop Mem_stage addr_6", false,-1);
        tracep->declBit(c+407,"SimTop Mem_stage addr_7", false,-1);
        tracep->declBit(c+408,"SimTop Mem_stage op_lb", false,-1);
        tracep->declBit(c+409,"SimTop Mem_stage op_lh", false,-1);
        tracep->declBit(c+410,"SimTop Mem_stage op_lw", false,-1);
        tracep->declBit(c+411,"SimTop Mem_stage op_ld", false,-1);
        tracep->declBit(c+412,"SimTop Mem_stage op_lbu", false,-1);
        tracep->declBit(c+413,"SimTop Mem_stage op_lhu", false,-1);
        tracep->declBit(c+414,"SimTop Mem_stage op_lwu", false,-1);
        tracep->declQuad(c+415,"SimTop Mem_stage mem_part", false,-1, 63,0);
        tracep->declBit(c+417,"SimTop Mem_stage op_sb", false,-1);
        tracep->declBit(c+418,"SimTop Mem_stage op_sh", false,-1);
        tracep->declBit(c+419,"SimTop Mem_stage op_sw", false,-1);
        tracep->declBit(c+420,"SimTop Mem_stage op_sd", false,-1);
        tracep->declBit(c+713,"SimTop Wb_stage rst", false,-1);
        tracep->declBus(c+110,"SimTop Wb_stage reg_wr_ctrl", false,-1, 2,0);
        tracep->declQuad(c+111,"SimTop Wb_stage exe_data", false,-1, 63,0);
        tracep->declQuad(c+113,"SimTop Wb_stage mem_data", false,-1, 63,0);
        tracep->declQuad(c+115,"SimTop Wb_stage csr_data", false,-1, 63,0);
        tracep->declQuad(c+708,"SimTop Wb_stage reg_wr_data", false,-1, 63,0);
        tracep->declBit(c+421,"SimTop Wb_stage mem_to_reg", false,-1);
        tracep->declBit(c+422,"SimTop Wb_stage exe_to_reg", false,-1);
        tracep->declBit(c+423,"SimTop Wb_stage csr_to_reg", false,-1);
        tracep->declBit(c+712,"SimTop Regfile clk", false,-1);
        tracep->declBit(c+713,"SimTop Regfile rst", false,-1);
        tracep->declBus(c+117,"SimTop Regfile w_addr", false,-1, 4,0);
        tracep->declQuad(c+708,"SimTop Regfile w_data", false,-1, 63,0);
        tracep->declBit(c+118,"SimTop Regfile w_ena", false,-1);
        tracep->declBus(c+705,"SimTop Regfile r_addr1", false,-1, 4,0);
        tracep->declQuad(c+697,"SimTop Regfile r_data1", false,-1, 63,0);
        tracep->declBit(c+704,"SimTop Regfile r_ena1", false,-1);
        tracep->declBus(c+707,"SimTop Regfile r_addr2", false,-1, 4,0);
        tracep->declQuad(c+699,"SimTop Regfile r_data2", false,-1, 63,0);
        tracep->declBit(c+706,"SimTop Regfile r_ena2", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+424+i*2,"SimTop Regfile regs_o", true,(i+0), 63,0);}}
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+488+i*2,"SimTop Regfile regs", true,(i+0), 63,0);}}
        tracep->declBus(c+738,"SimTop Excp_handler if_excp", false,-1, 15,0);
        tracep->declBus(c+739,"SimTop Excp_handler id_excp", false,-1, 15,0);
        tracep->declBus(c+744,"SimTop Excp_handler mem_excp", false,-1, 15,0);
        tracep->declBus(c+751,"SimTop Excp_handler itrp_info", false,-1, 11,0);
        tracep->declQuad(c+89,"SimTop Excp_handler now_pc", false,-1, 63,0);
        tracep->declBus(c+91,"SimTop Excp_handler now_inst", false,-1, 31,0);
        tracep->declQuad(c+752,"SimTop Excp_handler mem_acc_addr", false,-1, 63,0);
        tracep->declBit(c+745,"SimTop Excp_handler excp_exit", false,-1);
        tracep->declBit(c+1,"SimTop Excp_handler excp_enter", false,-1);
        tracep->declQuad(c+3,"SimTop Excp_handler mcause_wr_data", false,-1, 63,0);
        tracep->declQuad(c+196,"SimTop Excp_handler mepc_wr_data", false,-1, 63,0);
        tracep->declQuad(c+202,"SimTop Excp_handler mtval_wr_data", false,-1, 63,0);
        tracep->declQuad(c+186,"SimTop Excp_handler mstatus_wr_data", false,-1, 63,0);
        tracep->declQuad(c+188,"SimTop Excp_handler mstatus_rd_data", false,-1, 63,0);
        tracep->declQuad(c+192,"SimTop Excp_handler mtvec_rd_data", false,-1, 63,0);
        tracep->declQuad(c+198,"SimTop Excp_handler mepc_rd_data", false,-1, 63,0);
        tracep->declBit(c+2,"SimTop Excp_handler excp_jmp_ena", false,-1);
        tracep->declBus(c+552,"SimTop Excp_handler excp_pc", false,-1, 15,0);
        tracep->declBus(c+5,"SimTop Excp_handler excp_info", false,-1, 15,0);
        tracep->declBit(c+1,"SimTop Excp_handler sp_excp_ena", false,-1);
        tracep->declBit(c+754,"SimTop Excp_handler sp_itrp_ena", false,-1);
        tracep->declBit(c+754,"SimTop Excp_handler soft_itrp", false,-1);
        tracep->declBit(c+754,"SimTop Excp_handler timer_itrp", false,-1);
        tracep->declBit(c+754,"SimTop Excp_handler exter_itrp", false,-1);
        tracep->declQuad(c+755,"SimTop Excp_handler itrp_idx", false,-1, 62,0);
        tracep->declBit(c+6,"SimTop Excp_handler excp_inst_misal", false,-1);
        tracep->declBit(c+7,"SimTop Excp_handler excp_inst_acc", false,-1);
        tracep->declBit(c+8,"SimTop Excp_handler excp_ilg_inst", false,-1);
        tracep->declBit(c+9,"SimTop Excp_handler excp_brk_pt", false,-1);
        tracep->declBit(c+10,"SimTop Excp_handler excp_load_misal", false,-1);
        tracep->declBit(c+11,"SimTop Excp_handler excp_load_acc", false,-1);
        tracep->declBit(c+12,"SimTop Excp_handler excp_stor_misal", false,-1);
        tracep->declBit(c+13,"SimTop Excp_handler excp_stor_acc", false,-1);
        tracep->declBit(c+14,"SimTop Excp_handler excp_ecall_m", false,-1);
        tracep->declBit(c+15,"SimTop Excp_handler excp_inst_page", false,-1);
        tracep->declBit(c+16,"SimTop Excp_handler excp_load_page", false,-1);
        tracep->declBit(c+17,"SimTop Excp_handler excp_stor_page", false,-1);
        tracep->declQuad(c+18,"SimTop Excp_handler excp_idx", false,-1, 62,0);
        tracep->declBit(c+20,"SimTop Excp_handler inst_acc_fault", false,-1);
        tracep->declBit(c+21,"SimTop Excp_handler mem_acc_fault", false,-1);
        tracep->declQuad(c+553,"SimTop Excp_handler mstatus_p1", false,-1, 63,8);
        tracep->declBit(c+555,"SimTop Excp_handler mstatus_mpie", false,-1);
        tracep->declBus(c+556,"SimTop Excp_handler mstatus_p2", false,-1, 6,4);
        tracep->declBit(c+557,"SimTop Excp_handler mstatus_mie", false,-1);
        tracep->declBus(c+558,"SimTop Excp_handler mstatus_p3", false,-1, 2,0);
        tracep->declQuad(c+559,"SimTop Excp_handler mstatus_excp_enter", false,-1, 63,0);
        tracep->declQuad(c+561,"SimTop Excp_handler mstatus_excp_exit", false,-1, 63,0);
        tracep->declBus(c+563,"SimTop Excp_handler mtvec_mode", false,-1, 1,0);
        tracep->declBit(c+564,"SimTop Excp_handler mtvec_mode0", false,-1);
        tracep->declBit(c+565,"SimTop Excp_handler mtvec_mode1", false,-1);
        tracep->declQuad(c+566,"SimTop Excp_handler mtvec_base", false,-1, 61,0);
        tracep->declQuad(c+568,"SimTop Excp_handler excp_enter_pc", false,-1, 63,0);
        tracep->declQuad(c+198,"SimTop Excp_handler excp_exit_pc", false,-1, 63,0);
        tracep->declBit(c+712,"SimTop CSRfile clk", false,-1);
        tracep->declBit(c+713,"SimTop CSRfile rst", false,-1);
        tracep->declBit(c+120,"SimTop CSRfile csr_wr_ena", false,-1);
        tracep->declBus(c+119,"SimTop CSRfile csr_wr_addr", false,-1, 11,0);
        tracep->declBit(c+746,"SimTop CSRfile csr_rd_ena", false,-1);
        tracep->declBus(c+44,"SimTop CSRfile csr_rd_addr", false,-1, 11,0);
        tracep->declQuad(c+111,"SimTop CSRfile csr_wr_data", false,-1, 63,0);
        tracep->declQuad(c+733,"SimTop CSRfile csr_rd_data", false,-1, 63,0);
        tracep->declBit(c+1,"SimTop CSRfile excp_enter", false,-1);
        tracep->declBit(c+745,"SimTop CSRfile excp_exit", false,-1);
        tracep->declQuad(c+186,"SimTop CSRfile mstatus_wr_data", false,-1, 63,0);
        tracep->declQuad(c+188,"SimTop CSRfile mstatus_rd_data", false,-1, 63,0);
        tracep->declQuad(c+190,"SimTop CSRfile mie_rd_data", false,-1, 63,0);
        tracep->declQuad(c+192,"SimTop CSRfile mtvec_rd_data", false,-1, 63,0);
        tracep->declQuad(c+194,"SimTop CSRfile mscratch_rd_data", false,-1, 63,0);
        tracep->declQuad(c+196,"SimTop CSRfile mepc_wr_data", false,-1, 63,0);
        tracep->declQuad(c+198,"SimTop CSRfile mepc_rd_data", false,-1, 63,0);
        tracep->declQuad(c+3,"SimTop CSRfile mcause_wr_data", false,-1, 63,0);
        tracep->declQuad(c+200,"SimTop CSRfile mcause_rd_data", false,-1, 63,0);
        tracep->declQuad(c+202,"SimTop CSRfile mtval_wr_data", false,-1, 63,0);
        tracep->declQuad(c+749,"SimTop CSRfile mtval_rd_data", false,-1, 63,0);
        tracep->declQuad(c+204,"SimTop CSRfile mip_rd_data", false,-1, 63,0);
        tracep->declBit(c+570,"SimTop CSRfile sel_rd_mstatus", false,-1);
        tracep->declBit(c+571,"SimTop CSRfile sel_wr_mstatus", false,-1);
        tracep->declBit(c+572,"SimTop CSRfile rd_mstatus", false,-1);
        tracep->declBit(c+573,"SimTop CSRfile wr_mstatus", false,-1);
        tracep->declQuad(c+188,"SimTop CSRfile csr_mstatus", false,-1, 63,0);
        tracep->declBit(c+574,"SimTop CSRfile sel_misa", false,-1);
        tracep->declBit(c+575,"SimTop CSRfile rd_misa", false,-1);
        tracep->declQuad(c+757,"SimTop CSRfile csr_misa", false,-1, 63,0);
        tracep->declBit(c+576,"SimTop CSRfile sel_rd_mie", false,-1);
        tracep->declBit(c+577,"SimTop CSRfile sel_wr_mie", false,-1);
        tracep->declBit(c+578,"SimTop CSRfile rd_mie", false,-1);
        tracep->declBit(c+579,"SimTop CSRfile wr_mie", false,-1);
        tracep->declQuad(c+190,"SimTop CSRfile csr_mie", false,-1, 63,0);
        tracep->declBit(c+580,"SimTop CSRfile sel_rd_mtvec", false,-1);
        tracep->declBit(c+581,"SimTop CSRfile sel_wr_mtvec", false,-1);
        tracep->declBit(c+582,"SimTop CSRfile rd_mtvec", false,-1);
        tracep->declBit(c+583,"SimTop CSRfile wr_mtvec", false,-1);
        tracep->declQuad(c+192,"SimTop CSRfile csr_mtvec", false,-1, 63,0);
        tracep->declBit(c+584,"SimTop CSRfile sel_rd_mscratch", false,-1);
        tracep->declBit(c+585,"SimTop CSRfile sel_wr_mscratch", false,-1);
        tracep->declBit(c+586,"SimTop CSRfile rd_mscratch", false,-1);
        tracep->declBit(c+587,"SimTop CSRfile wr_mscratch", false,-1);
        tracep->declQuad(c+194,"SimTop CSRfile csr_mscratch", false,-1, 63,0);
        tracep->declBit(c+588,"SimTop CSRfile sel_rd_mepc", false,-1);
        tracep->declBit(c+589,"SimTop CSRfile sel_wr_mepc", false,-1);
        tracep->declBit(c+590,"SimTop CSRfile rd_mepc", false,-1);
        tracep->declBit(c+591,"SimTop CSRfile wr_mepc", false,-1);
        tracep->declQuad(c+198,"SimTop CSRfile csr_mepc", false,-1, 63,0);
        tracep->declBit(c+592,"SimTop CSRfile sel_rd_mcause", false,-1);
        tracep->declBit(c+593,"SimTop CSRfile sel_wr_mcause", false,-1);
        tracep->declBit(c+594,"SimTop CSRfile rd_mcause", false,-1);
        tracep->declBit(c+595,"SimTop CSRfile wr_mcause", false,-1);
        tracep->declQuad(c+200,"SimTop CSRfile csr_mcause", false,-1, 63,0);
        tracep->declBit(c+596,"SimTop CSRfile sel_rd_mtval", false,-1);
        tracep->declBit(c+597,"SimTop CSRfile sel_wr_mtval", false,-1);
        tracep->declBit(c+598,"SimTop CSRfile rd_mtval", false,-1);
        tracep->declBit(c+599,"SimTop CSRfile wr_mtval", false,-1);
        tracep->declQuad(c+600,"SimTop CSRfile csr_mtval", false,-1, 63,0);
        tracep->declBit(c+602,"SimTop CSRfile sel_rd_mip", false,-1);
        tracep->declBit(c+603,"SimTop CSRfile sel_wr_mip", false,-1);
        tracep->declBit(c+604,"SimTop CSRfile rd_mip", false,-1);
        tracep->declBit(c+605,"SimTop CSRfile wr_mip", false,-1);
        tracep->declQuad(c+204,"SimTop CSRfile csr_mip", false,-1, 63,0);
        tracep->declBit(c+606,"SimTop CSRfile sel_rd_mcycle", false,-1);
        tracep->declBit(c+607,"SimTop CSRfile sel_wr_mcycle", false,-1);
        tracep->declBit(c+608,"SimTop CSRfile rd_mcycle", false,-1);
        tracep->declBit(c+609,"SimTop CSRfile wr_mcycle", false,-1);
        tracep->declQuad(c+610,"SimTop CSRfile csr_mcycle", false,-1, 63,0);
        tracep->declBit(c+612,"SimTop CSRfile sel_mvendorid", false,-1);
        tracep->declBit(c+613,"SimTop CSRfile rd_mvendorid", false,-1);
        tracep->declQuad(c+752,"SimTop CSRfile csr_mvendorid", false,-1, 63,0);
        tracep->declBit(c+614,"SimTop CSRfile sel_marchid", false,-1);
        tracep->declBit(c+615,"SimTop CSRfile rd_marchid", false,-1);
        tracep->declQuad(c+752,"SimTop CSRfile csr_marchid", false,-1, 63,0);
        tracep->declBit(c+616,"SimTop CSRfile sel_mimpid", false,-1);
        tracep->declBit(c+617,"SimTop CSRfile rd_mimpid", false,-1);
        tracep->declQuad(c+752,"SimTop CSRfile csr_mimpid", false,-1, 63,0);
        tracep->declBit(c+618,"SimTop CSRfile sel_mhartid", false,-1);
        tracep->declBit(c+619,"SimTop CSRfile rd_mhartid", false,-1);
        tracep->declQuad(c+752,"SimTop CSRfile csr_mhartid", false,-1, 63,0);
        tracep->declBit(c+712,"SimTop DifftestInstrCommit clock", false,-1);
        tracep->declBus(c+759,"SimTop DifftestInstrCommit coreid", false,-1, 7,0);
        tracep->declBus(c+759,"SimTop DifftestInstrCommit index", false,-1, 7,0);
        tracep->declBit(c+213,"SimTop DifftestInstrCommit valid", false,-1);
        tracep->declQuad(c+210,"SimTop DifftestInstrCommit pc", false,-1, 63,0);
        tracep->declBus(c+212,"SimTop DifftestInstrCommit instr", false,-1, 31,0);
        tracep->declBit(c+214,"SimTop DifftestInstrCommit skip", false,-1);
        tracep->declBit(c+754,"SimTop DifftestInstrCommit isRVC", false,-1);
        tracep->declBit(c+754,"SimTop DifftestInstrCommit scFailed", false,-1);
        tracep->declBit(c+206,"SimTop DifftestInstrCommit wen", false,-1);
        tracep->declBus(c+207,"SimTop DifftestInstrCommit wdest", false,-1, 7,0);
        tracep->declQuad(c+208,"SimTop DifftestInstrCommit wdata", false,-1, 63,0);
        tracep->declBit(c+712,"SimTop DifftestArchIntRegState clock", false,-1);
        tracep->declBus(c+759,"SimTop DifftestArchIntRegState coreid", false,-1, 7,0);
        tracep->declQuad(c+620,"SimTop DifftestArchIntRegState gpr_0", false,-1, 63,0);
        tracep->declQuad(c+622,"SimTop DifftestArchIntRegState gpr_1", false,-1, 63,0);
        tracep->declQuad(c+624,"SimTop DifftestArchIntRegState gpr_2", false,-1, 63,0);
        tracep->declQuad(c+626,"SimTop DifftestArchIntRegState gpr_3", false,-1, 63,0);
        tracep->declQuad(c+628,"SimTop DifftestArchIntRegState gpr_4", false,-1, 63,0);
        tracep->declQuad(c+630,"SimTop DifftestArchIntRegState gpr_5", false,-1, 63,0);
        tracep->declQuad(c+632,"SimTop DifftestArchIntRegState gpr_6", false,-1, 63,0);
        tracep->declQuad(c+634,"SimTop DifftestArchIntRegState gpr_7", false,-1, 63,0);
        tracep->declQuad(c+636,"SimTop DifftestArchIntRegState gpr_8", false,-1, 63,0);
        tracep->declQuad(c+638,"SimTop DifftestArchIntRegState gpr_9", false,-1, 63,0);
        tracep->declQuad(c+640,"SimTop DifftestArchIntRegState gpr_10", false,-1, 63,0);
        tracep->declQuad(c+642,"SimTop DifftestArchIntRegState gpr_11", false,-1, 63,0);
        tracep->declQuad(c+644,"SimTop DifftestArchIntRegState gpr_12", false,-1, 63,0);
        tracep->declQuad(c+646,"SimTop DifftestArchIntRegState gpr_13", false,-1, 63,0);
        tracep->declQuad(c+648,"SimTop DifftestArchIntRegState gpr_14", false,-1, 63,0);
        tracep->declQuad(c+650,"SimTop DifftestArchIntRegState gpr_15", false,-1, 63,0);
        tracep->declQuad(c+652,"SimTop DifftestArchIntRegState gpr_16", false,-1, 63,0);
        tracep->declQuad(c+654,"SimTop DifftestArchIntRegState gpr_17", false,-1, 63,0);
        tracep->declQuad(c+656,"SimTop DifftestArchIntRegState gpr_18", false,-1, 63,0);
        tracep->declQuad(c+658,"SimTop DifftestArchIntRegState gpr_19", false,-1, 63,0);
        tracep->declQuad(c+660,"SimTop DifftestArchIntRegState gpr_20", false,-1, 63,0);
        tracep->declQuad(c+662,"SimTop DifftestArchIntRegState gpr_21", false,-1, 63,0);
        tracep->declQuad(c+664,"SimTop DifftestArchIntRegState gpr_22", false,-1, 63,0);
        tracep->declQuad(c+666,"SimTop DifftestArchIntRegState gpr_23", false,-1, 63,0);
        tracep->declQuad(c+668,"SimTop DifftestArchIntRegState gpr_24", false,-1, 63,0);
        tracep->declQuad(c+670,"SimTop DifftestArchIntRegState gpr_25", false,-1, 63,0);
        tracep->declQuad(c+672,"SimTop DifftestArchIntRegState gpr_26", false,-1, 63,0);
        tracep->declQuad(c+674,"SimTop DifftestArchIntRegState gpr_27", false,-1, 63,0);
        tracep->declQuad(c+676,"SimTop DifftestArchIntRegState gpr_28", false,-1, 63,0);
        tracep->declQuad(c+678,"SimTop DifftestArchIntRegState gpr_29", false,-1, 63,0);
        tracep->declQuad(c+680,"SimTop DifftestArchIntRegState gpr_30", false,-1, 63,0);
        tracep->declQuad(c+682,"SimTop DifftestArchIntRegState gpr_31", false,-1, 63,0);
        tracep->declBit(c+712,"SimTop DifftestTrapEvent clock", false,-1);
        tracep->declBus(c+759,"SimTop DifftestTrapEvent coreid", false,-1, 7,0);
        tracep->declBit(c+684,"SimTop DifftestTrapEvent valid", false,-1);
        tracep->declBus(c+685,"SimTop DifftestTrapEvent code", false,-1, 2,0);
        tracep->declQuad(c+210,"SimTop DifftestTrapEvent pc", false,-1, 63,0);
        tracep->declQuad(c+215,"SimTop DifftestTrapEvent cycleCnt", false,-1, 63,0);
        tracep->declQuad(c+217,"SimTop DifftestTrapEvent instrCnt", false,-1, 63,0);
        tracep->declBit(c+712,"SimTop DifftestCSRState clock", false,-1);
        tracep->declBus(c+759,"SimTop DifftestCSRState coreid", false,-1, 7,0);
        tracep->declBus(c+760,"SimTop DifftestCSRState priviledgeMode", false,-1, 1,0);
        tracep->declQuad(c+188,"SimTop DifftestCSRState mstatus", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestCSRState sstatus", false,-1, 63,0);
        tracep->declQuad(c+198,"SimTop DifftestCSRState mepc", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestCSRState sepc", false,-1, 63,0);
        tracep->declQuad(c+749,"SimTop DifftestCSRState mtval", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestCSRState stval", false,-1, 63,0);
        tracep->declQuad(c+192,"SimTop DifftestCSRState mtvec", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestCSRState stvec", false,-1, 63,0);
        tracep->declQuad(c+200,"SimTop DifftestCSRState mcause", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestCSRState scause", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestCSRState satp", false,-1, 63,0);
        tracep->declQuad(c+204,"SimTop DifftestCSRState mip", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestCSRState mie", false,-1, 63,0);
        tracep->declQuad(c+194,"SimTop DifftestCSRState mscratch", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestCSRState sscratch", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestCSRState mideleg", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestCSRState medeleg", false,-1, 63,0);
        tracep->declBit(c+712,"SimTop DifftestArchFpRegState clock", false,-1);
        tracep->declBus(c+759,"SimTop DifftestArchFpRegState coreid", false,-1, 7,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_0", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_1", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_2", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_3", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_4", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_5", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_6", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_7", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_8", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_9", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_10", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_11", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_12", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_13", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_14", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_15", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_16", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_17", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_18", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_19", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_20", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_21", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_22", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_23", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_24", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_25", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_26", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_27", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_28", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_29", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_30", false,-1, 63,0);
        tracep->declQuad(c+752,"SimTop DifftestArchFpRegState fpr_31", false,-1, 63,0);
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
    // Variables
    VlWide<3>/*95:0*/ __Vtemp34;
    VlWide<3>/*95:0*/ __Vtemp37;
    VlWide<3>/*95:0*/ __Vtemp43;
    VlWide<3>/*95:0*/ __Vtemp46;
    // Body
    {
        tracep->fullBit(oldp+1,((0U != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))));
        tracep->fullBit(oldp+2,(((0U != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info)) 
                                 | (IData)(vlTOPp->SimTop__DOT__excp_exit))));
        tracep->fullQData(oldp+3,((((((((((((1ULL & 
                                             (- (QData)((IData)(
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
                                          | (4ULL & 
                                             (- (QData)((IData)(
                                                                (1U 
                                                                 & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                    >> 4U))))))) 
                                         | (5ULL & 
                                            (- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                   >> 5U))))))) 
                                        | (6ULL & (- (QData)((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                         >> 6U))))))) 
                                       | (7ULL & (- (QData)((IData)(
                                                                    (1U 
                                                                     & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                        >> 7U))))))) 
                                      | (0xbULL & (- (QData)((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                         >> 0xbU))))))) 
                                     | (0xcULL & (- (QData)((IData)(
                                                                    (1U 
                                                                     & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                        >> 0xcU))))))) 
                                    | (0xdULL & (- (QData)((IData)(
                                                                   (1U 
                                                                    & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                       >> 0xdU))))))) 
                                   | (0xfULL & (- (QData)((IData)(
                                                                  (1U 
                                                                   & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                      >> 0xfU)))))))),64);
        tracep->fullSData(oldp+5,(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info),16);
        tracep->fullBit(oldp+6,((1U & (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))));
        tracep->fullBit(oldp+7,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                       >> 1U))));
        tracep->fullBit(oldp+8,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                       >> 2U))));
        tracep->fullBit(oldp+9,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                       >> 3U))));
        tracep->fullBit(oldp+10,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                        >> 4U))));
        tracep->fullBit(oldp+11,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                        >> 5U))));
        tracep->fullBit(oldp+12,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                        >> 6U))));
        tracep->fullBit(oldp+13,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                        >> 7U))));
        tracep->fullBit(oldp+14,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                        >> 0xbU))));
        tracep->fullBit(oldp+15,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                        >> 0xcU))));
        tracep->fullBit(oldp+16,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                        >> 0xdU))));
        tracep->fullBit(oldp+17,((1U & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                        >> 0xfU))));
        tracep->fullQData(oldp+18,((((((((((((1ULL 
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
                                          | (5ULL & 
                                             (- (QData)((IData)(
                                                                (1U 
                                                                 & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                    >> 5U))))))) 
                                         | (6ULL & 
                                            (- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                   >> 6U))))))) 
                                        | (7ULL & (- (QData)((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                         >> 7U))))))) 
                                       | (0xbULL & 
                                          (- (QData)((IData)(
                                                             (1U 
                                                              & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                 >> 0xbU))))))) 
                                      | (0xcULL & (- (QData)((IData)(
                                                                     (1U 
                                                                      & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                         >> 0xcU))))))) 
                                     | (0xdULL & (- (QData)((IData)(
                                                                    (1U 
                                                                     & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                        >> 0xdU))))))) 
                                    | (0xfULL & (- (QData)((IData)(
                                                                   (1U 
                                                                    & ((IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info) 
                                                                       >> 0xfU)))))))),63);
        tracep->fullBit(oldp+20,((IData)((0U != (0x1003U 
                                                 & (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))))));
        tracep->fullBit(oldp+21,((IData)((0U != (0xa0f0U 
                                                 & (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))))));
        tracep->fullCData(oldp+22,(vlTOPp->SimTop__DOT__byte_enable),8);
        tracep->fullQData(oldp+23,((vlTOPp->SimTop__DOT__mem_ram_wr_src 
                                    << (0x38U & ((IData)(vlTOPp->SimTop__DOT__mem_ex_data) 
                                                 << 3U)))),64);
        tracep->fullQData(oldp+25,(vlTOPp->SimTop__DOT__ram_rd_data),64);
        tracep->fullQData(oldp+27,((vlTOPp->SimTop__DOT__ex_jmp_imm 
                                    + ((0x40U & (IData)(vlTOPp->SimTop__DOT__ex_bj_info))
                                        ? vlTOPp->SimTop__DOT__rs1_forward
                                        : vlTOPp->SimTop__DOT__ex_pc))),64);
        tracep->fullQData(oldp+29,((QData)((IData)(
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
        tracep->fullQData(oldp+31,(vlTOPp->SimTop__DOT__id_pc),64);
        tracep->fullIData(oldp+33,(vlTOPp->SimTop__DOT__id_inst),32);
        tracep->fullBit(oldp+34,(vlTOPp->SimTop__DOT__id_valid));
        tracep->fullBit(oldp+35,(((0x3bU == (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst)) 
                                  | (0x1bU == (0x7fU 
                                               & vlTOPp->SimTop__DOT__id_inst)))));
        tracep->fullSData(oldp+36,(vlTOPp->SimTop__DOT__id_alu_info),12);
        tracep->fullCData(oldp+37,(vlTOPp->SimTop__DOT__id_bj_info),8);
        tracep->fullCData(oldp+38,(vlTOPp->SimTop__DOT__id_load_info),7);
        tracep->fullCData(oldp+39,((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sd) 
                                     << 3U) | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sw) 
                                                << 2U) 
                                               | (((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sh) 
                                                   << 1U) 
                                                  | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sb))))),4);
        tracep->fullQData(oldp+40,(((((- (QData)((IData)(
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
        tracep->fullBit(oldp+42,((((((((((3U == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__id_inst)) 
                                         | (0xfU == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))) 
                                        | (0x13U == 
                                           (0x7fU & vlTOPp->SimTop__DOT__id_inst))) 
                                       | (0x1bU == 
                                          (0x7fU & vlTOPp->SimTop__DOT__id_inst))) 
                                      | (0x23U == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                     | (0x33U == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__id_inst))) 
                                    | (0x3bU == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__id_inst))) 
                                   | (0x63U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst))) 
                                  | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg))));
        tracep->fullBit(oldp+43,((((0x33U == (0x7fU 
                                              & vlTOPp->SimTop__DOT__id_inst)) 
                                   | (0x3bU == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst))) 
                                  | (0x63U == (0x7fU 
                                               & vlTOPp->SimTop__DOT__id_inst)))));
        tracep->fullSData(oldp+44,((0xfffU & (vlTOPp->SimTop__DOT__id_inst 
                                              >> 0x14U))),12);
        tracep->fullQData(oldp+45,(vlTOPp->SimTop__DOT__ex_pc),64);
        tracep->fullIData(oldp+47,(vlTOPp->SimTop__DOT__ex_inst),32);
        tracep->fullBit(oldp+48,(vlTOPp->SimTop__DOT__ex_is_word_opt));
        tracep->fullSData(oldp+49,(vlTOPp->SimTop__DOT__ex_alu_info),12);
        tracep->fullCData(oldp+50,(vlTOPp->SimTop__DOT__ex_bj_info),8);
        tracep->fullQData(oldp+51,(vlTOPp->SimTop__DOT__ex_jmp_imm),64);
        tracep->fullQData(oldp+53,(vlTOPp->SimTop__DOT__ex_now_op1),64);
        tracep->fullQData(oldp+55,(vlTOPp->SimTop__DOT__ex_now_op2),64);
        tracep->fullBit(oldp+57,(vlTOPp->SimTop__DOT__ex_use_rs1));
        tracep->fullBit(oldp+58,(vlTOPp->SimTop__DOT__ex_use_rs2));
        tracep->fullQData(oldp+59,(vlTOPp->SimTop__DOT__ex_rs1_data),64);
        tracep->fullQData(oldp+61,(vlTOPp->SimTop__DOT__ex_rs2_data),64);
        tracep->fullCData(oldp+63,(vlTOPp->SimTop__DOT__ex_rs1_addr),5);
        tracep->fullCData(oldp+64,(vlTOPp->SimTop__DOT__ex_rs2_addr),5);
        tracep->fullQData(oldp+65,(vlTOPp->SimTop__DOT__ex_csr_data),64);
        tracep->fullBit(oldp+67,(vlTOPp->SimTop__DOT__ex_ram_wr_ena_r));
        tracep->fullBit(oldp+68,(vlTOPp->SimTop__DOT__ex_ram_rd_ena_r));
        tracep->fullBit(oldp+69,(((IData)(vlTOPp->SimTop__DOT__ex_ram_wr_ena_r) 
                                  & (IData)(vlTOPp->SimTop__DOT__ex_valid))));
        tracep->fullBit(oldp+70,(vlTOPp->SimTop__DOT__ex_ram_rd_ena));
        tracep->fullCData(oldp+71,(vlTOPp->SimTop__DOT__ex_load_info),7);
        tracep->fullCData(oldp+72,(vlTOPp->SimTop__DOT__ex_save_info),4);
        tracep->fullCData(oldp+73,(vlTOPp->SimTop__DOT__ex_reg_wr_ctrl),3);
        tracep->fullCData(oldp+74,(vlTOPp->SimTop__DOT__ex_reg_wr_addr),5);
        tracep->fullBit(oldp+75,(vlTOPp->SimTop__DOT__ex_reg_wr_ena_r));
        tracep->fullBit(oldp+76,(((IData)(vlTOPp->SimTop__DOT__ex_reg_wr_ena_r) 
                                  & (IData)(vlTOPp->SimTop__DOT__ex_valid))));
        tracep->fullSData(oldp+77,(vlTOPp->SimTop__DOT__ex_csr_wr_addr),12);
        tracep->fullBit(oldp+78,(vlTOPp->SimTop__DOT__ex_csr_wr_ena_r));
        tracep->fullBit(oldp+79,(((IData)(vlTOPp->SimTop__DOT__ex_csr_wr_ena_r) 
                                  & (IData)(vlTOPp->SimTop__DOT__ex_valid))));
        tracep->fullBit(oldp+80,(vlTOPp->SimTop__DOT__ex_valid));
        tracep->fullQData(oldp+81,(vlTOPp->SimTop__DOT__rs1_forward),64);
        tracep->fullQData(oldp+83,(vlTOPp->SimTop__DOT__rs2_forward),64);
        tracep->fullQData(oldp+85,(vlTOPp->SimTop__DOT__true_op1),64);
        tracep->fullQData(oldp+87,(vlTOPp->SimTop__DOT__true_op2),64);
        tracep->fullQData(oldp+89,(vlTOPp->SimTop__DOT__mem_pc),64);
        tracep->fullIData(oldp+91,(vlTOPp->SimTop__DOT__mem_inst),32);
        tracep->fullCData(oldp+92,(vlTOPp->SimTop__DOT__mem_load_info),7);
        tracep->fullCData(oldp+93,(vlTOPp->SimTop__DOT__mem_save_info),4);
        tracep->fullQData(oldp+94,(vlTOPp->SimTop__DOT__mem_ram_wr_src),64);
        tracep->fullQData(oldp+96,(vlTOPp->SimTop__DOT__mem_ex_data),64);
        tracep->fullQData(oldp+98,(vlTOPp->SimTop__DOT__mem_csr_data),64);
        tracep->fullBit(oldp+100,(vlTOPp->SimTop__DOT__mem_ram_wr_ena));
        tracep->fullBit(oldp+101,(vlTOPp->SimTop__DOT__mem_ram_rd_ena));
        tracep->fullCData(oldp+102,(vlTOPp->SimTop__DOT__mem_reg_wr_ctrl),3);
        tracep->fullCData(oldp+103,(vlTOPp->SimTop__DOT__mem_reg_wr_addr),5);
        tracep->fullBit(oldp+104,(vlTOPp->SimTop__DOT__mem_reg_wr_ena));
        tracep->fullBit(oldp+105,(vlTOPp->SimTop__DOT__mem_csr_wr_ena));
        tracep->fullBit(oldp+106,(vlTOPp->SimTop__DOT__mem_valid));
        tracep->fullQData(oldp+107,(vlTOPp->SimTop__DOT__wb_pc),64);
        tracep->fullIData(oldp+109,(vlTOPp->SimTop__DOT__wb_inst),32);
        tracep->fullCData(oldp+110,(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl),3);
        tracep->fullQData(oldp+111,(vlTOPp->SimTop__DOT__wb_ex_data),64);
        tracep->fullQData(oldp+113,(vlTOPp->SimTop__DOT__wb_ram_data),64);
        tracep->fullQData(oldp+115,(vlTOPp->SimTop__DOT__wb_csr_data),64);
        tracep->fullCData(oldp+117,(vlTOPp->SimTop__DOT__wb_reg_wr_addr),5);
        tracep->fullBit(oldp+118,(vlTOPp->SimTop__DOT__wb_reg_wr_ena));
        tracep->fullSData(oldp+119,(vlTOPp->SimTop__DOT__wb_csr_wr_addr),12);
        tracep->fullBit(oldp+120,(vlTOPp->SimTop__DOT__wb_csr_wr_ena));
        tracep->fullBit(oldp+121,(vlTOPp->SimTop__DOT__wb_valid));
        tracep->fullQData(oldp+122,(vlTOPp->SimTop__DOT__regs[0]),64);
        tracep->fullQData(oldp+124,(vlTOPp->SimTop__DOT__regs[1]),64);
        tracep->fullQData(oldp+126,(vlTOPp->SimTop__DOT__regs[2]),64);
        tracep->fullQData(oldp+128,(vlTOPp->SimTop__DOT__regs[3]),64);
        tracep->fullQData(oldp+130,(vlTOPp->SimTop__DOT__regs[4]),64);
        tracep->fullQData(oldp+132,(vlTOPp->SimTop__DOT__regs[5]),64);
        tracep->fullQData(oldp+134,(vlTOPp->SimTop__DOT__regs[6]),64);
        tracep->fullQData(oldp+136,(vlTOPp->SimTop__DOT__regs[7]),64);
        tracep->fullQData(oldp+138,(vlTOPp->SimTop__DOT__regs[8]),64);
        tracep->fullQData(oldp+140,(vlTOPp->SimTop__DOT__regs[9]),64);
        tracep->fullQData(oldp+142,(vlTOPp->SimTop__DOT__regs[10]),64);
        tracep->fullQData(oldp+144,(vlTOPp->SimTop__DOT__regs[11]),64);
        tracep->fullQData(oldp+146,(vlTOPp->SimTop__DOT__regs[12]),64);
        tracep->fullQData(oldp+148,(vlTOPp->SimTop__DOT__regs[13]),64);
        tracep->fullQData(oldp+150,(vlTOPp->SimTop__DOT__regs[14]),64);
        tracep->fullQData(oldp+152,(vlTOPp->SimTop__DOT__regs[15]),64);
        tracep->fullQData(oldp+154,(vlTOPp->SimTop__DOT__regs[16]),64);
        tracep->fullQData(oldp+156,(vlTOPp->SimTop__DOT__regs[17]),64);
        tracep->fullQData(oldp+158,(vlTOPp->SimTop__DOT__regs[18]),64);
        tracep->fullQData(oldp+160,(vlTOPp->SimTop__DOT__regs[19]),64);
        tracep->fullQData(oldp+162,(vlTOPp->SimTop__DOT__regs[20]),64);
        tracep->fullQData(oldp+164,(vlTOPp->SimTop__DOT__regs[21]),64);
        tracep->fullQData(oldp+166,(vlTOPp->SimTop__DOT__regs[22]),64);
        tracep->fullQData(oldp+168,(vlTOPp->SimTop__DOT__regs[23]),64);
        tracep->fullQData(oldp+170,(vlTOPp->SimTop__DOT__regs[24]),64);
        tracep->fullQData(oldp+172,(vlTOPp->SimTop__DOT__regs[25]),64);
        tracep->fullQData(oldp+174,(vlTOPp->SimTop__DOT__regs[26]),64);
        tracep->fullQData(oldp+176,(vlTOPp->SimTop__DOT__regs[27]),64);
        tracep->fullQData(oldp+178,(vlTOPp->SimTop__DOT__regs[28]),64);
        tracep->fullQData(oldp+180,(vlTOPp->SimTop__DOT__regs[29]),64);
        tracep->fullQData(oldp+182,(vlTOPp->SimTop__DOT__regs[30]),64);
        tracep->fullQData(oldp+184,(vlTOPp->SimTop__DOT__regs[31]),64);
        tracep->fullQData(oldp+186,((((- (QData)((IData)(
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
        tracep->fullQData(oldp+188,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus),64);
        tracep->fullQData(oldp+190,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mie),64);
        tracep->fullQData(oldp+192,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec),64);
        tracep->fullQData(oldp+194,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mscratch),64);
        tracep->fullQData(oldp+196,(((- (QData)((IData)(
                                                        (0U 
                                                         != (IData)(vlTOPp->SimTop__DOT__Excp_handler__DOT__excp_info))))) 
                                     & vlTOPp->SimTop__DOT__mem_pc)),64);
        tracep->fullQData(oldp+198,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mepc),64);
        tracep->fullQData(oldp+200,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mcause),64);
        tracep->fullQData(oldp+202,((((- (QData)((IData)(
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
        tracep->fullQData(oldp+204,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mip),64);
        tracep->fullBit(oldp+206,(vlTOPp->SimTop__DOT__cmt_wen));
        tracep->fullCData(oldp+207,(vlTOPp->SimTop__DOT__cmt_wdest),8);
        tracep->fullQData(oldp+208,(vlTOPp->SimTop__DOT__cmt_wdata),64);
        tracep->fullQData(oldp+210,(vlTOPp->SimTop__DOT__cmt_pc),64);
        tracep->fullIData(oldp+212,(vlTOPp->SimTop__DOT__cmt_inst),32);
        tracep->fullBit(oldp+213,(vlTOPp->SimTop__DOT__vaild));
        tracep->fullBit(oldp+214,(vlTOPp->SimTop__DOT__skip));
        tracep->fullQData(oldp+215,(vlTOPp->SimTop__DOT__cycleCnt),64);
        tracep->fullQData(oldp+217,(vlTOPp->SimTop__DOT__instrCnt),64);
        tracep->fullQData(oldp+219,(vlTOPp->SimTop__DOT__RAM_1W2R__DOT__inst_2),64);
        tracep->fullQData(oldp+221,((((QData)((IData)(
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
                                      << 0x20U) | (QData)((IData)(
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
        tracep->fullCData(oldp+223,((0x7fU & vlTOPp->SimTop__DOT__id_inst)),7);
        tracep->fullCData(oldp+224,((7U & (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0xcU))),3);
        tracep->fullCData(oldp+225,((0x3fU & (vlTOPp->SimTop__DOT__id_inst 
                                              >> 0x1aU))),6);
        tracep->fullCData(oldp+226,((0x7fU & (vlTOPp->SimTop__DOT__id_inst 
                                              >> 0x19U))),7);
        tracep->fullCData(oldp+227,((0x1fU & (vlTOPp->SimTop__DOT__id_inst 
                                              >> 7U))),5);
        tracep->fullSData(oldp+228,(vlTOPp->SimTop__DOT__Id_stage__DOT__immS),12);
        tracep->fullSData(oldp+229,(vlTOPp->SimTop__DOT__Id_stage__DOT__immB),13);
        tracep->fullIData(oldp+230,((0xfffffU & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0xcU))),20);
        tracep->fullIData(oldp+231,(vlTOPp->SimTop__DOT__Id_stage__DOT__immJ),21);
        tracep->fullBit(oldp+232,((0U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+233,((1U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+234,((2U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+235,((3U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+236,((4U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+237,((5U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+238,((6U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+239,((7U == (7U & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+240,((0U == (0x3fU & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0x1aU)))));
        tracep->fullBit(oldp+241,((0x10U == (0x3fU 
                                             & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0x1aU)))));
        tracep->fullBit(oldp+242,((0U == (0x7fU & (vlTOPp->SimTop__DOT__id_inst 
                                                   >> 0x19U)))));
        tracep->fullBit(oldp+243,((0x20U == (0x7fU 
                                             & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0x19U)))));
        tracep->fullBit(oldp+244,((0U == (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U)))));
        tracep->fullBit(oldp+245,((1U == (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U)))));
        tracep->fullBit(oldp+246,((0x102U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+247,((3U == (0x7fU & vlTOPp->SimTop__DOT__id_inst))));
        tracep->fullBit(oldp+248,((0xfU == (0x7fU & vlTOPp->SimTop__DOT__id_inst))));
        tracep->fullBit(oldp+249,((0x13U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))));
        tracep->fullBit(oldp+250,((0x17U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))));
        tracep->fullBit(oldp+251,((0x1bU == (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))));
        tracep->fullBit(oldp+252,((0x23U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))));
        tracep->fullBit(oldp+253,((0x33U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))));
        tracep->fullBit(oldp+254,((0x37U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))));
        tracep->fullBit(oldp+255,((0x3bU == (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))));
        tracep->fullBit(oldp+256,((0x63U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))));
        tracep->fullBit(oldp+257,((0x67U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))));
        tracep->fullBit(oldp+258,((0x6fU == (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))));
        tracep->fullBit(oldp+259,((0x73U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))));
        tracep->fullBit(oldp+260,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_excp));
        tracep->fullBit(oldp+261,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm));
        tracep->fullBit(oldp+262,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg));
        tracep->fullBit(oldp+263,((0x7bU == (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))));
        tracep->fullBit(oldp+264,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lb));
        tracep->fullBit(oldp+265,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lh));
        tracep->fullBit(oldp+266,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lw));
        tracep->fullBit(oldp+267,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_ld));
        tracep->fullBit(oldp+268,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lbu));
        tracep->fullBit(oldp+269,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lhu));
        tracep->fullBit(oldp+270,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lwu));
        tracep->fullBit(oldp+271,((((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lb) 
                                        | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lh)) 
                                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lw)) 
                                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_ld)) 
                                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lbu)) 
                                    | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lhu)) 
                                   | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_lwu))));
        tracep->fullBit(oldp+272,((IData)((0xfU == 
                                           (0x707fU 
                                            & vlTOPp->SimTop__DOT__id_inst)))));
        tracep->fullBit(oldp+273,((IData)((0x100fU 
                                           == (0x707fU 
                                               & vlTOPp->SimTop__DOT__id_inst)))));
        tracep->fullBit(oldp+274,(((IData)((0xfU == 
                                            (0x707fU 
                                             & vlTOPp->SimTop__DOT__id_inst))) 
                                   | (IData)((0x100fU 
                                              == (0x707fU 
                                                  & vlTOPp->SimTop__DOT__id_inst))))));
        tracep->fullBit(oldp+275,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addi));
        tracep->fullBit(oldp+276,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slli));
        tracep->fullBit(oldp+277,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slti));
        tracep->fullBit(oldp+278,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sltiu));
        tracep->fullBit(oldp+279,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_xori));
        tracep->fullBit(oldp+280,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srli));
        tracep->fullBit(oldp+281,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srai));
        tracep->fullBit(oldp+282,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_ori));
        tracep->fullBit(oldp+283,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_andi));
        tracep->fullBit(oldp+284,((((((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addi) 
                                          | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slli)) 
                                         | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slti)) 
                                        | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sltiu)) 
                                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_xori)) 
                                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srli)) 
                                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srai)) 
                                    | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_ori)) 
                                   | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_andi))));
        tracep->fullBit(oldp+285,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addiw));
        tracep->fullBit(oldp+286,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slliw));
        tracep->fullBit(oldp+287,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srliw));
        tracep->fullBit(oldp+288,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sraiw));
        tracep->fullBit(oldp+289,(((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addiw) 
                                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slliw)) 
                                    | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srliw)) 
                                   | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sraiw))));
        tracep->fullBit(oldp+290,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sb));
        tracep->fullBit(oldp+291,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sh));
        tracep->fullBit(oldp+292,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sw));
        tracep->fullBit(oldp+293,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sd));
        tracep->fullBit(oldp+294,(((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sb) 
                                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sh)) 
                                    | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sw)) 
                                   | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sd))));
        tracep->fullBit(oldp+295,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_add));
        tracep->fullBit(oldp+296,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sub));
        tracep->fullBit(oldp+297,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sll));
        tracep->fullBit(oldp+298,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slt));
        tracep->fullBit(oldp+299,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sltu));
        tracep->fullBit(oldp+300,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_xor));
        tracep->fullBit(oldp+301,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srl));
        tracep->fullBit(oldp+302,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sra));
        tracep->fullBit(oldp+303,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_or));
        tracep->fullBit(oldp+304,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_and));
        tracep->fullBit(oldp+305,(((((((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_add) 
                                           | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sub)) 
                                          | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sll)) 
                                         | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_slt)) 
                                        | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sltu)) 
                                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_xor)) 
                                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srl)) 
                                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sra)) 
                                    | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_or)) 
                                   | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_and))));
        tracep->fullBit(oldp+306,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addw));
        tracep->fullBit(oldp+307,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_subw));
        tracep->fullBit(oldp+308,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sllw));
        tracep->fullBit(oldp+309,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srlw));
        tracep->fullBit(oldp+310,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sraw));
        tracep->fullBit(oldp+311,((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_addw) 
                                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_subw)) 
                                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sllw)) 
                                    | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_srlw)) 
                                   | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_sraw))));
        tracep->fullBit(oldp+312,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_beq));
        tracep->fullBit(oldp+313,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bne));
        tracep->fullBit(oldp+314,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_blt));
        tracep->fullBit(oldp+315,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bge));
        tracep->fullBit(oldp+316,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bltu));
        tracep->fullBit(oldp+317,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bgeu));
        tracep->fullBit(oldp+318,(((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_beq) 
                                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bne)) 
                                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_blt)) 
                                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bge)) 
                                    | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bltu)) 
                                   | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_bgeu))));
        tracep->fullBit(oldp+319,(((0x67U == (0x7fU 
                                              & vlTOPp->SimTop__DOT__id_inst)) 
                                   | (0x6fU == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst)))));
        tracep->fullBit(oldp+320,(((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_excp) 
                                   & (0U == (0xfffU 
                                             & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0x14U))))));
        tracep->fullBit(oldp+321,(((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_excp) 
                                   & (1U == (0xfffU 
                                             & (vlTOPp->SimTop__DOT__id_inst 
                                                >> 0x14U))))));
        tracep->fullBit(oldp+322,(((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_excp) 
                                   & (0x102U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+323,(((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_excp) 
                                   & (((0U == (0xfffU 
                                               & (vlTOPp->SimTop__DOT__id_inst 
                                                  >> 0x14U))) 
                                       | (1U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U)))) 
                                      | (0x102U == 
                                         (0xfffU & 
                                          (vlTOPp->SimTop__DOT__id_inst 
                                           >> 0x14U)))))));
        tracep->fullBit(oldp+324,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrw));
        tracep->fullBit(oldp+325,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrs));
        tracep->fullBit(oldp+326,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrc));
        tracep->fullBit(oldp+327,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrwi));
        tracep->fullBit(oldp+328,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrsi));
        tracep->fullBit(oldp+329,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrci));
        tracep->fullBit(oldp+330,(((((((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrw) 
                                       | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrs)) 
                                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrc)) 
                                     | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrwi)) 
                                    | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrsi)) 
                                   | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_csrrci))));
        tracep->fullBit(oldp+331,(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_vld));
        tracep->fullBit(oldp+332,((((((IData)(vlTOPp->SimTop__DOT__ex_rs1_addr) 
                                      == (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_addr)) 
                                     & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ena)) 
                                    & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs1_addr))) 
                                   & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ctrl))));
        tracep->fullBit(oldp+333,((((((IData)(vlTOPp->SimTop__DOT__ex_rs1_addr) 
                                      == (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)) 
                                     & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ena)) 
                                    & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs1_addr))) 
                                   & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl))));
        tracep->fullBit(oldp+334,((((((IData)(vlTOPp->SimTop__DOT__ex_rs1_addr) 
                                      == (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_addr)) 
                                     & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ena)) 
                                    & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs1_addr))) 
                                   & ((IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ctrl) 
                                      >> 1U))));
        tracep->fullBit(oldp+335,((((((IData)(vlTOPp->SimTop__DOT__ex_rs1_addr) 
                                      == (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)) 
                                     & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ena)) 
                                    & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs1_addr))) 
                                   & ((IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl) 
                                      >> 1U))));
        tracep->fullBit(oldp+336,((((((IData)(vlTOPp->SimTop__DOT__ex_rs2_addr) 
                                      == (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_addr)) 
                                     & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ena)) 
                                    & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs2_addr))) 
                                   & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ctrl))));
        tracep->fullBit(oldp+337,((((((IData)(vlTOPp->SimTop__DOT__ex_rs2_addr) 
                                      == (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)) 
                                     & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ena)) 
                                    & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs2_addr))) 
                                   & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl))));
        tracep->fullBit(oldp+338,((((((IData)(vlTOPp->SimTop__DOT__ex_rs2_addr) 
                                      == (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_addr)) 
                                     & (IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ena)) 
                                    & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs2_addr))) 
                                   & ((IData)(vlTOPp->SimTop__DOT__mem_reg_wr_ctrl) 
                                      >> 1U))));
        tracep->fullBit(oldp+339,((((((IData)(vlTOPp->SimTop__DOT__ex_rs2_addr) 
                                      == (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_addr)) 
                                     & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ena)) 
                                    & (0U != (IData)(vlTOPp->SimTop__DOT__ex_rs2_addr))) 
                                   & ((IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl) 
                                      >> 1U))));
        tracep->fullCData(oldp+340,(vlTOPp->SimTop__DOT__Ex_stage__DOT__bj_data),8);
        tracep->fullQData(oldp+341,(vlTOPp->SimTop__DOT__Ex_stage__DOT__op1),64);
        tracep->fullQData(oldp+343,(vlTOPp->SimTop__DOT__Ex_stage__DOT__op2),64);
        tracep->fullBit(oldp+345,((1U & (IData)(vlTOPp->SimTop__DOT__ex_alu_info))));
        tracep->fullBit(oldp+346,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                         >> 1U))));
        tracep->fullBit(oldp+347,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                         >> 2U))));
        tracep->fullBit(oldp+348,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                         >> 3U))));
        tracep->fullBit(oldp+349,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                         >> 4U))));
        tracep->fullBit(oldp+350,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                         >> 5U))));
        tracep->fullBit(oldp+351,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                         >> 6U))));
        tracep->fullBit(oldp+352,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                         >> 7U))));
        tracep->fullBit(oldp+353,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                         >> 8U))));
        tracep->fullBit(oldp+354,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                         >> 9U))));
        tracep->fullBit(oldp+355,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                         >> 0xaU))));
        tracep->fullBit(oldp+356,((1U & ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                         >> 0xbU))));
        tracep->fullBit(oldp+357,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_shift));
        tracep->fullQData(oldp+358,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in1),64);
        tracep->fullCData(oldp+360,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in2),6);
        tracep->fullQData(oldp+361,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res),64);
        tracep->fullQData(oldp+363,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res),64);
        tracep->fullQData(oldp+365,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask),64);
        tracep->fullQData(oldp+367,(((vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res 
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
        tracep->fullBit(oldp+369,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub));
        tracep->fullBit(oldp+370,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub));
        __Vtemp34[0U] = (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__op1);
        __Vtemp34[1U] = (IData)((vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                 >> 0x20U));
        __Vtemp34[2U] = (1U & ((~ ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                   >> 3U)) & (IData)(
                                                     (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                      >> 0x3fU))));
        tracep->fullWData(oldp+371,(__Vtemp34),65);
        tracep->fullWData(oldp+374,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2),65);
        __Vtemp37[0U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                         & (IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__op1));
        __Vtemp37[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                         & (IData)((vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                    >> 0x20U)));
        __Vtemp37[2U] = (1U & ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                               & ((~ ((IData)(vlTOPp->SimTop__DOT__ex_alu_info) 
                                      >> 3U)) & (IData)(
                                                        (vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                                         >> 0x3fU)))));
        tracep->fullWData(oldp+377,(__Vtemp37),65);
        __Vtemp43[0U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                         & ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                             ? (~ vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U])
                             : vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U]));
        __Vtemp43[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                         & ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                             ? (~ vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U])
                             : vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U]));
        __Vtemp43[2U] = (1U & ((- (IData)((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                               & ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                                   ? (~ vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U])
                                   : vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U])));
        tracep->fullWData(oldp+380,(__Vtemp43),65);
        __Vtemp46[0U] = ((IData)(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                          ? 1U : 0U);
        __Vtemp46[1U] = 0U;
        __Vtemp46[2U] = 0U;
        tracep->fullWData(oldp+383,(__Vtemp46),65);
        tracep->fullWData(oldp+386,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res),65);
        tracep->fullQData(oldp+389,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res),64);
        tracep->fullQData(oldp+391,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res),64);
        tracep->fullQData(oldp+393,((vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                     | vlTOPp->SimTop__DOT__Ex_stage__DOT__op2)),64);
        tracep->fullQData(oldp+395,((vlTOPp->SimTop__DOT__Ex_stage__DOT__op1 
                                     & vlTOPp->SimTop__DOT__Ex_stage__DOT__op2)),64);
        tracep->fullQData(oldp+397,(((~ vlTOPp->SimTop__DOT__Ex_stage__DOT__op1) 
                                     & vlTOPp->SimTop__DOT__Ex_stage__DOT__op2)),64);
        tracep->fullBit(oldp+399,((1U & (~ (IData)(
                                                   (0U 
                                                    != vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res))))));
        tracep->fullBit(oldp+400,((0U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
        tracep->fullBit(oldp+401,((1U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
        tracep->fullBit(oldp+402,((2U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
        tracep->fullBit(oldp+403,((3U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
        tracep->fullBit(oldp+404,((4U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
        tracep->fullBit(oldp+405,((5U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
        tracep->fullBit(oldp+406,((6U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
        tracep->fullBit(oldp+407,((7U == (7U & (IData)(vlTOPp->SimTop__DOT__mem_ex_data)))));
        tracep->fullBit(oldp+408,((1U & (IData)(vlTOPp->SimTop__DOT__mem_load_info))));
        tracep->fullBit(oldp+409,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                         >> 1U))));
        tracep->fullBit(oldp+410,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                         >> 2U))));
        tracep->fullBit(oldp+411,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                         >> 3U))));
        tracep->fullBit(oldp+412,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                         >> 4U))));
        tracep->fullBit(oldp+413,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                         >> 5U))));
        tracep->fullBit(oldp+414,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_load_info) 
                                         >> 6U))));
        tracep->fullQData(oldp+415,(vlTOPp->SimTop__DOT__Mem_stage__DOT__mem_part),64);
        tracep->fullBit(oldp+417,((1U & (IData)(vlTOPp->SimTop__DOT__mem_save_info))));
        tracep->fullBit(oldp+418,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                         >> 1U))));
        tracep->fullBit(oldp+419,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                         >> 2U))));
        tracep->fullBit(oldp+420,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_save_info) 
                                         >> 3U))));
        tracep->fullBit(oldp+421,((1U & ((IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl) 
                                         >> 1U))));
        tracep->fullBit(oldp+422,((1U & (IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl))));
        tracep->fullBit(oldp+423,((1U & ((IData)(vlTOPp->SimTop__DOT__wb_reg_wr_ctrl) 
                                         >> 2U))));
        tracep->fullQData(oldp+424,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[0]),64);
        tracep->fullQData(oldp+426,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[1]),64);
        tracep->fullQData(oldp+428,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[2]),64);
        tracep->fullQData(oldp+430,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[3]),64);
        tracep->fullQData(oldp+432,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[4]),64);
        tracep->fullQData(oldp+434,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[5]),64);
        tracep->fullQData(oldp+436,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[6]),64);
        tracep->fullQData(oldp+438,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[7]),64);
        tracep->fullQData(oldp+440,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[8]),64);
        tracep->fullQData(oldp+442,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[9]),64);
        tracep->fullQData(oldp+444,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[10]),64);
        tracep->fullQData(oldp+446,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[11]),64);
        tracep->fullQData(oldp+448,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[12]),64);
        tracep->fullQData(oldp+450,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[13]),64);
        tracep->fullQData(oldp+452,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[14]),64);
        tracep->fullQData(oldp+454,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[15]),64);
        tracep->fullQData(oldp+456,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[16]),64);
        tracep->fullQData(oldp+458,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[17]),64);
        tracep->fullQData(oldp+460,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[18]),64);
        tracep->fullQData(oldp+462,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[19]),64);
        tracep->fullQData(oldp+464,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[20]),64);
        tracep->fullQData(oldp+466,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[21]),64);
        tracep->fullQData(oldp+468,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[22]),64);
        tracep->fullQData(oldp+470,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[23]),64);
        tracep->fullQData(oldp+472,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[24]),64);
        tracep->fullQData(oldp+474,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[25]),64);
        tracep->fullQData(oldp+476,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[26]),64);
        tracep->fullQData(oldp+478,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[27]),64);
        tracep->fullQData(oldp+480,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[28]),64);
        tracep->fullQData(oldp+482,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[29]),64);
        tracep->fullQData(oldp+484,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[30]),64);
        tracep->fullQData(oldp+486,(vlTOPp->SimTop__DOT____Vcellout__Regfile__regs_o[31]),64);
        tracep->fullQData(oldp+488,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[0]),64);
        tracep->fullQData(oldp+490,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[1]),64);
        tracep->fullQData(oldp+492,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[2]),64);
        tracep->fullQData(oldp+494,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[3]),64);
        tracep->fullQData(oldp+496,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[4]),64);
        tracep->fullQData(oldp+498,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[5]),64);
        tracep->fullQData(oldp+500,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[6]),64);
        tracep->fullQData(oldp+502,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[7]),64);
        tracep->fullQData(oldp+504,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[8]),64);
        tracep->fullQData(oldp+506,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[9]),64);
        tracep->fullQData(oldp+508,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[10]),64);
        tracep->fullQData(oldp+510,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[11]),64);
        tracep->fullQData(oldp+512,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[12]),64);
        tracep->fullQData(oldp+514,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[13]),64);
        tracep->fullQData(oldp+516,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[14]),64);
        tracep->fullQData(oldp+518,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[15]),64);
        tracep->fullQData(oldp+520,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[16]),64);
        tracep->fullQData(oldp+522,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[17]),64);
        tracep->fullQData(oldp+524,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[18]),64);
        tracep->fullQData(oldp+526,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[19]),64);
        tracep->fullQData(oldp+528,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[20]),64);
        tracep->fullQData(oldp+530,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[21]),64);
        tracep->fullQData(oldp+532,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[22]),64);
        tracep->fullQData(oldp+534,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[23]),64);
        tracep->fullQData(oldp+536,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[24]),64);
        tracep->fullQData(oldp+538,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[25]),64);
        tracep->fullQData(oldp+540,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[26]),64);
        tracep->fullQData(oldp+542,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[27]),64);
        tracep->fullQData(oldp+544,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[28]),64);
        tracep->fullQData(oldp+546,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[29]),64);
        tracep->fullQData(oldp+548,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[30]),64);
        tracep->fullQData(oldp+550,(vlTOPp->SimTop__DOT__Regfile__DOT__regs[31]),64);
        tracep->fullSData(oldp+552,((0xffffU & ((0xfffcU 
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
        tracep->fullQData(oldp+553,((0xffffffffffffffULL 
                                     & (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                        >> 8U))),56);
        tracep->fullBit(oldp+555,((1U & (IData)((vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                 >> 7U)))));
        tracep->fullCData(oldp+556,((7U & (IData)((vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                   >> 4U)))),3);
        tracep->fullBit(oldp+557,((1U & (IData)((vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus 
                                                 >> 3U)))));
        tracep->fullCData(oldp+558,((7U & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mstatus))),3);
        tracep->fullQData(oldp+559,(((0xffffffffffffff00ULL 
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
        tracep->fullQData(oldp+561,(((0xffffffffffffff00ULL 
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
        tracep->fullCData(oldp+563,((3U & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec))),2);
        tracep->fullBit(oldp+564,((0U == (3U & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec)))));
        tracep->fullBit(oldp+565,((1U == (3U & (IData)(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec)))));
        tracep->fullQData(oldp+566,((0x3fffffffffffffffULL 
                                     & (vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtvec 
                                        >> 2U))),62);
        tracep->fullQData(oldp+568,(((0xfffffffffffffffcULL 
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
        tracep->fullBit(oldp+570,((0x300U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+571,((0x300U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
        tracep->fullBit(oldp+572,(((0x300U == (0xfffU 
                                               & (vlTOPp->SimTop__DOT__id_inst 
                                                  >> 0x14U))) 
                                   & (IData)(vlTOPp->SimTop__DOT__csr_rd_ena))));
        tracep->fullBit(oldp+573,(((0x300U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)) 
                                   & (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena))));
        tracep->fullBit(oldp+574,((0x301U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+575,(((0x301U == (0xfffU 
                                               & (vlTOPp->SimTop__DOT__id_inst 
                                                  >> 0x14U))) 
                                   & (IData)(vlTOPp->SimTop__DOT__csr_rd_ena))));
        tracep->fullBit(oldp+576,((0x304U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+577,((0x304U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
        tracep->fullBit(oldp+578,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                   & (0x304U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+579,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                   & (0x304U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
        tracep->fullBit(oldp+580,((0x305U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+581,((0x305U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
        tracep->fullBit(oldp+582,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                   & (0x305U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+583,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                   & (0x305U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
        tracep->fullBit(oldp+584,((0x430U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+585,((0x430U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
        tracep->fullBit(oldp+586,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                   & (0x430U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+587,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                   & (0x430U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
        tracep->fullBit(oldp+588,((0x341U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+589,((0x341U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
        tracep->fullBit(oldp+590,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                   & (0x341U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+591,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                   & (0x341U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
        tracep->fullBit(oldp+592,((0x342U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+593,((0x342U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
        tracep->fullBit(oldp+594,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                   & (0x342U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+595,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                   & (0x342U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
        tracep->fullBit(oldp+596,((0x343U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+597,((0x343U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
        tracep->fullBit(oldp+598,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                   & (0x343U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+599,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                   & (0x343U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
        tracep->fullQData(oldp+600,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mtval),64);
        tracep->fullBit(oldp+602,((0x344U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+603,((0x344U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
        tracep->fullBit(oldp+604,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                   & (0x344U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+605,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                   & (0x344U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
        tracep->fullBit(oldp+606,((0xb00U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+607,((0xb00U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr))));
        tracep->fullBit(oldp+608,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                   & (0xb00U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+609,(((IData)(vlTOPp->SimTop__DOT__wb_csr_wr_ena) 
                                   & (0xb00U == (IData)(vlTOPp->SimTop__DOT__wb_csr_wr_addr)))));
        tracep->fullQData(oldp+610,(vlTOPp->SimTop__DOT__CSRfile__DOT__csr_mcycle),64);
        tracep->fullBit(oldp+612,((0xf11U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+613,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                   & (0xf11U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+614,((0xf12U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+615,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                   & (0xf12U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+616,((0xf13U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+617,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                   & (0xf13U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+618,((0xf14U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__id_inst 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+619,(((IData)(vlTOPp->SimTop__DOT__csr_rd_ena) 
                                   & (0xf14U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__id_inst 
                                                    >> 0x14U))))));
        tracep->fullQData(oldp+620,(vlTOPp->SimTop__DOT__regs
                                    [0U]),64);
        tracep->fullQData(oldp+622,(vlTOPp->SimTop__DOT__regs
                                    [1U]),64);
        tracep->fullQData(oldp+624,(vlTOPp->SimTop__DOT__regs
                                    [2U]),64);
        tracep->fullQData(oldp+626,(vlTOPp->SimTop__DOT__regs
                                    [3U]),64);
        tracep->fullQData(oldp+628,(vlTOPp->SimTop__DOT__regs
                                    [4U]),64);
        tracep->fullQData(oldp+630,(vlTOPp->SimTop__DOT__regs
                                    [5U]),64);
        tracep->fullQData(oldp+632,(vlTOPp->SimTop__DOT__regs
                                    [6U]),64);
        tracep->fullQData(oldp+634,(vlTOPp->SimTop__DOT__regs
                                    [7U]),64);
        tracep->fullQData(oldp+636,(vlTOPp->SimTop__DOT__regs
                                    [8U]),64);
        tracep->fullQData(oldp+638,(vlTOPp->SimTop__DOT__regs
                                    [9U]),64);
        tracep->fullQData(oldp+640,(vlTOPp->SimTop__DOT__regs
                                    [0xaU]),64);
        tracep->fullQData(oldp+642,(vlTOPp->SimTop__DOT__regs
                                    [0xbU]),64);
        tracep->fullQData(oldp+644,(vlTOPp->SimTop__DOT__regs
                                    [0xcU]),64);
        tracep->fullQData(oldp+646,(vlTOPp->SimTop__DOT__regs
                                    [0xdU]),64);
        tracep->fullQData(oldp+648,(vlTOPp->SimTop__DOT__regs
                                    [0xeU]),64);
        tracep->fullQData(oldp+650,(vlTOPp->SimTop__DOT__regs
                                    [0xfU]),64);
        tracep->fullQData(oldp+652,(vlTOPp->SimTop__DOT__regs
                                    [0x10U]),64);
        tracep->fullQData(oldp+654,(vlTOPp->SimTop__DOT__regs
                                    [0x11U]),64);
        tracep->fullQData(oldp+656,(vlTOPp->SimTop__DOT__regs
                                    [0x12U]),64);
        tracep->fullQData(oldp+658,(vlTOPp->SimTop__DOT__regs
                                    [0x13U]),64);
        tracep->fullQData(oldp+660,(vlTOPp->SimTop__DOT__regs
                                    [0x14U]),64);
        tracep->fullQData(oldp+662,(vlTOPp->SimTop__DOT__regs
                                    [0x15U]),64);
        tracep->fullQData(oldp+664,(vlTOPp->SimTop__DOT__regs
                                    [0x16U]),64);
        tracep->fullQData(oldp+666,(vlTOPp->SimTop__DOT__regs
                                    [0x17U]),64);
        tracep->fullQData(oldp+668,(vlTOPp->SimTop__DOT__regs
                                    [0x18U]),64);
        tracep->fullQData(oldp+670,(vlTOPp->SimTop__DOT__regs
                                    [0x19U]),64);
        tracep->fullQData(oldp+672,(vlTOPp->SimTop__DOT__regs
                                    [0x1aU]),64);
        tracep->fullQData(oldp+674,(vlTOPp->SimTop__DOT__regs
                                    [0x1bU]),64);
        tracep->fullQData(oldp+676,(vlTOPp->SimTop__DOT__regs
                                    [0x1cU]),64);
        tracep->fullQData(oldp+678,(vlTOPp->SimTop__DOT__regs
                                    [0x1dU]),64);
        tracep->fullQData(oldp+680,(vlTOPp->SimTop__DOT__regs
                                    [0x1eU]),64);
        tracep->fullQData(oldp+682,(vlTOPp->SimTop__DOT__regs
                                    [0x1fU]),64);
        tracep->fullBit(oldp+684,((0x6bU == (0x7fU 
                                             & vlTOPp->SimTop__DOT__wb_inst))));
        tracep->fullCData(oldp+685,((7U & (IData)(vlTOPp->SimTop__DOT__regs
                                                  [0xaU]))),3);
        tracep->fullQData(oldp+686,(vlTOPp->SimTop__DOT__if_pc),64);
        tracep->fullBit(oldp+688,(vlTOPp->SimTop__DOT__bj_ena));
        tracep->fullBit(oldp+689,(vlTOPp->SimTop__DOT__id_allowin));
        tracep->fullBit(oldp+690,((1U & (~ (IData)(vlTOPp->SimTop__DOT__stall)))));
        tracep->fullBit(oldp+691,(vlTOPp->SimTop__DOT__id_to_ex_valid));
        tracep->fullBit(oldp+692,(vlTOPp->SimTop__DOT__stall));
        tracep->fullQData(oldp+693,(vlTOPp->SimTop__DOT__id_op1),64);
        tracep->fullQData(oldp+695,(vlTOPp->SimTop__DOT__id_op2),64);
        tracep->fullQData(oldp+697,(vlTOPp->SimTop__DOT__r_data1),64);
        tracep->fullQData(oldp+699,(vlTOPp->SimTop__DOT__r_data2),64);
        tracep->fullBit(oldp+701,(vlTOPp->SimTop__DOT__id_reg_wr_ena));
        tracep->fullQData(oldp+702,(vlTOPp->SimTop__DOT__mem_ram_data),64);
        tracep->fullBit(oldp+704,(vlTOPp->SimTop__DOT__rs1_r_ena));
        tracep->fullCData(oldp+705,(vlTOPp->SimTop__DOT__rs1_r_addr),5);
        tracep->fullBit(oldp+706,(vlTOPp->SimTop__DOT__rs2_r_ena));
        tracep->fullCData(oldp+707,(vlTOPp->SimTop__DOT__rs2_r_addr),5);
        tracep->fullQData(oldp+708,(vlTOPp->SimTop__DOT__wb_reg_wr_data),64);
        tracep->fullQData(oldp+710,(vlTOPp->SimTop__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output),64);
        tracep->fullBit(oldp+712,(vlTOPp->clock));
        tracep->fullBit(oldp+713,(vlTOPp->reset));
        tracep->fullQData(oldp+714,(vlTOPp->io_logCtrl_log_begin),64);
        tracep->fullQData(oldp+716,(vlTOPp->io_logCtrl_log_end),64);
        tracep->fullQData(oldp+718,(vlTOPp->io_logCtrl_log_level),64);
        tracep->fullBit(oldp+720,(vlTOPp->io_perfInfo_clean));
        tracep->fullBit(oldp+721,(vlTOPp->io_perfInfo_dump));
        tracep->fullBit(oldp+722,(vlTOPp->io_uart_out_valid));
        tracep->fullCData(oldp+723,(vlTOPp->io_uart_out_ch),8);
        tracep->fullBit(oldp+724,(vlTOPp->io_uart_in_valid));
        tracep->fullCData(oldp+725,(vlTOPp->io_uart_in_ch),8);
        tracep->fullBit(oldp+726,(((~ (IData)(vlTOPp->reset)) 
                                   & (0x23U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__id_inst)))));
        tracep->fullBit(oldp+727,(((~ (IData)(vlTOPp->reset)) 
                                   & (3U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst)))));
        tracep->fullCData(oldp+728,(((((~ (IData)(vlTOPp->reset)) 
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
        tracep->fullCData(oldp+729,(vlTOPp->SimTop__DOT__id_reg_wr_addr),5);
        tracep->fullBit(oldp+730,(((~ (IData)(vlTOPp->reset)) 
                                   & ((IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_imm) 
                                      | (IData)(vlTOPp->SimTop__DOT__Id_stage__DOT__inst_i_csr_reg)))));
        tracep->fullQData(oldp+731,((((QData)((IData)(
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
        tracep->fullQData(oldp+733,(((- (QData)((IData)(
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
        tracep->fullBit(oldp+735,(((~ (IData)(vlTOPp->reset)) 
                                   & (((((((((0xfU 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__id_inst)) 
                                             | (0x13U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->SimTop__DOT__id_inst))) 
                                            | (0x17U 
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))) 
                                           | (0x1bU 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__id_inst))) 
                                          | (0x33U 
                                             == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__id_inst))) 
                                         | (0x37U == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__id_inst))) 
                                        | (0x3bU == 
                                           (0x7fU & vlTOPp->SimTop__DOT__id_inst))) 
                                       | (0x6fU == 
                                          (0x7fU & vlTOPp->SimTop__DOT__id_inst))) 
                                      | (0x67U == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__id_inst))))));
        tracep->fullQData(oldp+736,(vlTOPp->SimTop__DOT__rd_data),64);
        tracep->fullSData(oldp+738,(vlTOPp->SimTop__DOT__if_excp),16);
        tracep->fullSData(oldp+739,(vlTOPp->SimTop__DOT__id_excp),16);
        tracep->fullQData(oldp+740,(vlTOPp->SimTop__DOT__id_csr_data),64);
        tracep->fullBit(oldp+742,(1U));
        tracep->fullSData(oldp+743,(vlTOPp->SimTop__DOT__mem_csr_wr_addr),12);
        tracep->fullSData(oldp+744,(vlTOPp->SimTop__DOT__mem_excp),16);
        tracep->fullBit(oldp+745,(vlTOPp->SimTop__DOT__excp_exit));
        tracep->fullBit(oldp+746,(vlTOPp->SimTop__DOT__csr_rd_ena));
        tracep->fullBit(oldp+747,(vlTOPp->SimTop__DOT__csr_wr_ena));
        tracep->fullSData(oldp+748,(vlTOPp->SimTop__DOT__csr_wr_addr),12);
        tracep->fullQData(oldp+749,(vlTOPp->SimTop__DOT__mtval_rd_data),64);
        tracep->fullSData(oldp+751,(0U),12);
        tracep->fullQData(oldp+752,(0ULL),64);
        tracep->fullBit(oldp+754,(0U));
        tracep->fullQData(oldp+755,(0ULL),63);
        tracep->fullQData(oldp+757,(0x80000100ULL),64);
        tracep->fullCData(oldp+759,(0U),8);
        tracep->fullCData(oldp+760,(0U),2);
    }
}
