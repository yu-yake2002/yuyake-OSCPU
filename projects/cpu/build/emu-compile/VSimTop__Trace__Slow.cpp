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
        tracep->declBit(c+1355,"clock", false,-1);
        tracep->declBit(c+1356,"reset", false,-1);
        tracep->declQuad(c+1357,"io_logCtrl_log_begin", false,-1, 63,0);
        tracep->declQuad(c+1359,"io_logCtrl_log_end", false,-1, 63,0);
        tracep->declQuad(c+1361,"io_logCtrl_log_level", false,-1, 63,0);
        tracep->declBit(c+1363,"io_perfInfo_clean", false,-1);
        tracep->declBit(c+1364,"io_perfInfo_dump", false,-1);
        tracep->declBit(c+1365,"io_uart_out_valid", false,-1);
        tracep->declBus(c+1366,"io_uart_out_ch", false,-1, 7,0);
        tracep->declBit(c+1367,"io_uart_in_valid", false,-1);
        tracep->declBus(c+1368,"io_uart_in_ch", false,-1, 7,0);
        tracep->declBit(c+1369,"io_memAXI_0_aw_ready", false,-1);
        tracep->declBit(c+1370,"io_memAXI_0_aw_valid", false,-1);
        tracep->declQuad(c+1371,"io_memAXI_0_aw_bits_addr", false,-1, 63,0);
        tracep->declBus(c+1373,"io_memAXI_0_aw_bits_prot", false,-1, 2,0);
        tracep->declBus(c+1374,"io_memAXI_0_aw_bits_id", false,-1, 3,0);
        tracep->declBus(c+1375,"io_memAXI_0_aw_bits_user", false,-1, 0,0);
        tracep->declBus(c+1376,"io_memAXI_0_aw_bits_len", false,-1, 7,0);
        tracep->declBus(c+1377,"io_memAXI_0_aw_bits_size", false,-1, 2,0);
        tracep->declBus(c+1378,"io_memAXI_0_aw_bits_burst", false,-1, 1,0);
        tracep->declBit(c+1379,"io_memAXI_0_aw_bits_lock", false,-1);
        tracep->declBus(c+1380,"io_memAXI_0_aw_bits_cache", false,-1, 3,0);
        tracep->declBus(c+1381,"io_memAXI_0_aw_bits_qos", false,-1, 3,0);
        tracep->declBit(c+1382,"io_memAXI_0_w_ready", false,-1);
        tracep->declBit(c+1383,"io_memAXI_0_w_valid", false,-1);
        {int i; for (i=0; i<4; i++) {
                tracep->declQuad(c+1384+i*2,"io_memAXI_0_w_bits_data", true,(i+0), 63,0);}}
        tracep->declBus(c+1392,"io_memAXI_0_w_bits_strb", false,-1, 7,0);
        tracep->declBit(c+1393,"io_memAXI_0_w_bits_last", false,-1);
        tracep->declBus(c+1394,"io_memAXI_0_w_bits_id", false,-1, 3,0);
        tracep->declBit(c+1395,"io_memAXI_0_b_ready", false,-1);
        tracep->declBit(c+1396,"io_memAXI_0_b_valid", false,-1);
        tracep->declBus(c+1397,"io_memAXI_0_b_bits_resp", false,-1, 1,0);
        tracep->declBus(c+1398,"io_memAXI_0_b_bits_id", false,-1, 3,0);
        tracep->declBus(c+1399,"io_memAXI_0_b_bits_user", false,-1, 0,0);
        tracep->declBit(c+1400,"io_memAXI_0_ar_ready", false,-1);
        tracep->declBit(c+1401,"io_memAXI_0_ar_valid", false,-1);
        tracep->declQuad(c+1402,"io_memAXI_0_ar_bits_addr", false,-1, 63,0);
        tracep->declBus(c+1404,"io_memAXI_0_ar_bits_prot", false,-1, 2,0);
        tracep->declBus(c+1405,"io_memAXI_0_ar_bits_id", false,-1, 3,0);
        tracep->declBus(c+1406,"io_memAXI_0_ar_bits_user", false,-1, 0,0);
        tracep->declBus(c+1407,"io_memAXI_0_ar_bits_len", false,-1, 7,0);
        tracep->declBus(c+1408,"io_memAXI_0_ar_bits_size", false,-1, 2,0);
        tracep->declBus(c+1409,"io_memAXI_0_ar_bits_burst", false,-1, 1,0);
        tracep->declBit(c+1410,"io_memAXI_0_ar_bits_lock", false,-1);
        tracep->declBus(c+1411,"io_memAXI_0_ar_bits_cache", false,-1, 3,0);
        tracep->declBus(c+1412,"io_memAXI_0_ar_bits_qos", false,-1, 3,0);
        tracep->declBit(c+1413,"io_memAXI_0_r_ready", false,-1);
        tracep->declBit(c+1414,"io_memAXI_0_r_valid", false,-1);
        tracep->declBus(c+1415,"io_memAXI_0_r_bits_resp", false,-1, 1,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declQuad(c+1416+i*2,"io_memAXI_0_r_bits_data", true,(i+0), 63,0);}}
        tracep->declBit(c+1424,"io_memAXI_0_r_bits_last", false,-1);
        tracep->declBus(c+1425,"io_memAXI_0_r_bits_id", false,-1, 3,0);
        tracep->declBus(c+1426,"io_memAXI_0_r_bits_user", false,-1, 0,0);
        tracep->declBus(c+1480,"SimTop RW_DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1480,"SimTop RW_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1480,"SimTop AXI_DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1480,"SimTop AXI_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1481,"SimTop AXI_ID_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1482,"SimTop AXI_USER_WIDTH", false,-1, 31,0);
        tracep->declBit(c+1355,"SimTop clock", false,-1);
        tracep->declBit(c+1356,"SimTop reset", false,-1);
        tracep->declQuad(c+1357,"SimTop io_logCtrl_log_begin", false,-1, 63,0);
        tracep->declQuad(c+1359,"SimTop io_logCtrl_log_end", false,-1, 63,0);
        tracep->declQuad(c+1361,"SimTop io_logCtrl_log_level", false,-1, 63,0);
        tracep->declBit(c+1363,"SimTop io_perfInfo_clean", false,-1);
        tracep->declBit(c+1364,"SimTop io_perfInfo_dump", false,-1);
        tracep->declBit(c+1365,"SimTop io_uart_out_valid", false,-1);
        tracep->declBus(c+1366,"SimTop io_uart_out_ch", false,-1, 7,0);
        tracep->declBit(c+1367,"SimTop io_uart_in_valid", false,-1);
        tracep->declBus(c+1368,"SimTop io_uart_in_ch", false,-1, 7,0);
        tracep->declBit(c+1369,"SimTop io_memAXI_0_aw_ready", false,-1);
        tracep->declBit(c+1370,"SimTop io_memAXI_0_aw_valid", false,-1);
        tracep->declQuad(c+1371,"SimTop io_memAXI_0_aw_bits_addr", false,-1, 63,0);
        tracep->declBus(c+1373,"SimTop io_memAXI_0_aw_bits_prot", false,-1, 2,0);
        tracep->declBus(c+1374,"SimTop io_memAXI_0_aw_bits_id", false,-1, 3,0);
        tracep->declBus(c+1375,"SimTop io_memAXI_0_aw_bits_user", false,-1, 0,0);
        tracep->declBus(c+1376,"SimTop io_memAXI_0_aw_bits_len", false,-1, 7,0);
        tracep->declBus(c+1377,"SimTop io_memAXI_0_aw_bits_size", false,-1, 2,0);
        tracep->declBus(c+1378,"SimTop io_memAXI_0_aw_bits_burst", false,-1, 1,0);
        tracep->declBit(c+1379,"SimTop io_memAXI_0_aw_bits_lock", false,-1);
        tracep->declBus(c+1380,"SimTop io_memAXI_0_aw_bits_cache", false,-1, 3,0);
        tracep->declBus(c+1381,"SimTop io_memAXI_0_aw_bits_qos", false,-1, 3,0);
        tracep->declBit(c+1382,"SimTop io_memAXI_0_w_ready", false,-1);
        tracep->declBit(c+1383,"SimTop io_memAXI_0_w_valid", false,-1);
        {int i; for (i=0; i<4; i++) {
                tracep->declQuad(c+1384+i*2,"SimTop io_memAXI_0_w_bits_data", true,(i+0), 63,0);}}
        tracep->declBus(c+1392,"SimTop io_memAXI_0_w_bits_strb", false,-1, 7,0);
        tracep->declBit(c+1393,"SimTop io_memAXI_0_w_bits_last", false,-1);
        tracep->declBus(c+1394,"SimTop io_memAXI_0_w_bits_id", false,-1, 3,0);
        tracep->declBit(c+1395,"SimTop io_memAXI_0_b_ready", false,-1);
        tracep->declBit(c+1396,"SimTop io_memAXI_0_b_valid", false,-1);
        tracep->declBus(c+1397,"SimTop io_memAXI_0_b_bits_resp", false,-1, 1,0);
        tracep->declBus(c+1398,"SimTop io_memAXI_0_b_bits_id", false,-1, 3,0);
        tracep->declBus(c+1399,"SimTop io_memAXI_0_b_bits_user", false,-1, 0,0);
        tracep->declBit(c+1400,"SimTop io_memAXI_0_ar_ready", false,-1);
        tracep->declBit(c+1401,"SimTop io_memAXI_0_ar_valid", false,-1);
        tracep->declQuad(c+1402,"SimTop io_memAXI_0_ar_bits_addr", false,-1, 63,0);
        tracep->declBus(c+1404,"SimTop io_memAXI_0_ar_bits_prot", false,-1, 2,0);
        tracep->declBus(c+1405,"SimTop io_memAXI_0_ar_bits_id", false,-1, 3,0);
        tracep->declBus(c+1406,"SimTop io_memAXI_0_ar_bits_user", false,-1, 0,0);
        tracep->declBus(c+1407,"SimTop io_memAXI_0_ar_bits_len", false,-1, 7,0);
        tracep->declBus(c+1408,"SimTop io_memAXI_0_ar_bits_size", false,-1, 2,0);
        tracep->declBus(c+1409,"SimTop io_memAXI_0_ar_bits_burst", false,-1, 1,0);
        tracep->declBit(c+1410,"SimTop io_memAXI_0_ar_bits_lock", false,-1);
        tracep->declBus(c+1411,"SimTop io_memAXI_0_ar_bits_cache", false,-1, 3,0);
        tracep->declBus(c+1412,"SimTop io_memAXI_0_ar_bits_qos", false,-1, 3,0);
        tracep->declBit(c+1413,"SimTop io_memAXI_0_r_ready", false,-1);
        tracep->declBit(c+1414,"SimTop io_memAXI_0_r_valid", false,-1);
        tracep->declBus(c+1415,"SimTop io_memAXI_0_r_bits_resp", false,-1, 1,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declQuad(c+1416+i*2,"SimTop io_memAXI_0_r_bits_data", true,(i+0), 63,0);}}
        tracep->declBit(c+1424,"SimTop io_memAXI_0_r_bits_last", false,-1);
        tracep->declBus(c+1425,"SimTop io_memAXI_0_r_bits_id", false,-1, 3,0);
        tracep->declBus(c+1426,"SimTop io_memAXI_0_r_bits_user", false,-1, 0,0);
        tracep->declBit(c+1127,"SimTop mem_axi_aw_ready", false,-1);
        tracep->declBit(c+1128,"SimTop if_axi_aw_ready", false,-1);
        tracep->declBit(c+1,"SimTop cli_aw_ready", false,-1);
        tracep->declBit(c+2,"SimTop mem_axi_aw_valid", false,-1);
        tracep->declBit(c+3,"SimTop if_axi_aw_valid", false,-1);
        tracep->declBit(c+4,"SimTop cli_aw_valid", false,-1);
        tracep->declQuad(c+5,"SimTop mem_axi_aw_addr", false,-1, 63,0);
        tracep->declQuad(c+7,"SimTop if_axi_aw_addr", false,-1, 63,0);
        tracep->declQuad(c+9,"SimTop cli_aw_addr", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop mem_axi_aw_prot", false,-1, 2,0);
        tracep->declBus(c+1483,"SimTop if_axi_aw_prot", false,-1, 2,0);
        tracep->declBus(c+1483,"SimTop cli_aw_prot", false,-1, 2,0);
        tracep->declBus(c+11,"SimTop mem_axi_aw_id", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop if_axi_aw_id", false,-1, 3,0);
        tracep->declBus(c+12,"SimTop cli_aw_id", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop mem_axi_aw_user", false,-1, 0,0);
        tracep->declBus(c+1485,"SimTop if_axi_aw_user", false,-1, 0,0);
        tracep->declBus(c+1485,"SimTop cli_aw_user", false,-1, 0,0);
        tracep->declBus(c+13,"SimTop mem_axi_aw_len", false,-1, 7,0);
        tracep->declBus(c+14,"SimTop if_axi_aw_len", false,-1, 7,0);
        tracep->declBus(c+15,"SimTop cli_aw_len", false,-1, 7,0);
        tracep->declBus(c+16,"SimTop mem_axi_aw_size", false,-1, 2,0);
        tracep->declBus(c+17,"SimTop if_axi_aw_size", false,-1, 2,0);
        tracep->declBus(c+18,"SimTop cli_aw_size", false,-1, 2,0);
        tracep->declBus(c+1486,"SimTop mem_axi_aw_burst", false,-1, 1,0);
        tracep->declBus(c+1486,"SimTop if_axi_aw_burst", false,-1, 1,0);
        tracep->declBus(c+19,"SimTop cli_aw_burst", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop mem_axi_aw_lock", false,-1);
        tracep->declBit(c+1487,"SimTop if_axi_aw_lock", false,-1);
        tracep->declBit(c+1487,"SimTop cli_aw_lock", false,-1);
        tracep->declBus(c+1488,"SimTop mem_axi_aw_cache", false,-1, 3,0);
        tracep->declBus(c+1488,"SimTop if_axi_aw_cache", false,-1, 3,0);
        tracep->declBus(c+20,"SimTop cli_aw_cache", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop mem_axi_aw_qos", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop if_axi_aw_qos", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop cli_aw_qos", false,-1, 3,0);
        tracep->declBit(c+1129,"SimTop mem_axi_w_ready", false,-1);
        tracep->declBit(c+1130,"SimTop if_axi_w_ready", false,-1);
        tracep->declBit(c+21,"SimTop cli_w_ready", false,-1);
        tracep->declBit(c+22,"SimTop mem_axi_w_valid", false,-1);
        tracep->declBit(c+23,"SimTop if_axi_w_valid", false,-1);
        tracep->declBit(c+21,"SimTop cli_w_valid", false,-1);
        tracep->declQuad(c+24,"SimTop mem_axi_w_data", false,-1, 63,0);
        tracep->declQuad(c+26,"SimTop if_axi_w_data", false,-1, 63,0);
        tracep->declQuad(c+28,"SimTop cli_w_data", false,-1, 63,0);
        tracep->declBus(c+30,"SimTop mem_axi_w_strb", false,-1, 7,0);
        tracep->declBus(c+31,"SimTop if_axi_w_strb", false,-1, 7,0);
        tracep->declBus(c+32,"SimTop cli_w_strb", false,-1, 7,0);
        tracep->declBit(c+22,"SimTop mem_axi_w_last", false,-1);
        tracep->declBit(c+23,"SimTop if_axi_w_last", false,-1);
        tracep->declBit(c+33,"SimTop cli_w_last", false,-1);
        tracep->declBit(c+1489,"SimTop mem_axi_w_id", false,-1);
        tracep->declBit(c+1487,"SimTop if_axi_w_id", false,-1);
        tracep->declBit(c+34,"SimTop cli_w_id", false,-1);
        tracep->declBit(c+35,"SimTop mem_axi_b_ready", false,-1);
        tracep->declBit(c+36,"SimTop if_axi_b_ready", false,-1);
        tracep->declBit(c+37,"SimTop cli_b_ready", false,-1);
        tracep->declBit(c+1196,"SimTop mem_axi_b_valid", false,-1);
        tracep->declBit(c+1197,"SimTop if_axi_b_valid", false,-1);
        tracep->declBit(c+38,"SimTop cli_b_valid", false,-1);
        tracep->declBus(c+1427,"SimTop mem_axi_b_resp", false,-1, 1,0);
        tracep->declBus(c+1428,"SimTop if_axi_b_resp", false,-1, 1,0);
        tracep->declBus(c+1490,"SimTop cli_b_resp", false,-1, 1,0);
        tracep->declBus(c+1429,"SimTop mem_axi_b_id", false,-1, 3,0);
        tracep->declBus(c+1430,"SimTop if_axi_b_id", false,-1, 3,0);
        tracep->declBus(c+39,"SimTop cli_b_id", false,-1, 3,0);
        tracep->declBus(c+1431,"SimTop mem_axi_b_user", false,-1, 0,0);
        tracep->declBus(c+1432,"SimTop if_axi_b_user", false,-1, 0,0);
        tracep->declBus(c+40,"SimTop cli_b_user", false,-1, 0,0);
        tracep->declBit(c+1131,"SimTop mem_axi_ar_ready", false,-1);
        tracep->declBit(c+1132,"SimTop if_axi_ar_ready", false,-1);
        tracep->declBit(c+41,"SimTop cli_ar_ready", false,-1);
        tracep->declBit(c+42,"SimTop mem_axi_ar_valid", false,-1);
        tracep->declBit(c+43,"SimTop if_axi_ar_valid", false,-1);
        tracep->declBit(c+44,"SimTop cli_ar_valid", false,-1);
        tracep->declQuad(c+5,"SimTop mem_axi_ar_addr", false,-1, 63,0);
        tracep->declQuad(c+7,"SimTop if_axi_ar_addr", false,-1, 63,0);
        tracep->declQuad(c+45,"SimTop cli_ar_addr", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop mem_axi_ar_prot", false,-1, 2,0);
        tracep->declBus(c+1483,"SimTop if_axi_ar_prot", false,-1, 2,0);
        tracep->declBus(c+1483,"SimTop cli_ar_prot", false,-1, 2,0);
        tracep->declBus(c+47,"SimTop mem_axi_ar_id", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop if_axi_ar_id", false,-1, 3,0);
        tracep->declBus(c+48,"SimTop cli_ar_id", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop mem_axi_ar_user", false,-1, 0,0);
        tracep->declBus(c+1485,"SimTop if_axi_ar_user", false,-1, 0,0);
        tracep->declBus(c+1485,"SimTop cli_ar_user", false,-1, 0,0);
        tracep->declBus(c+49,"SimTop mem_axi_ar_len", false,-1, 7,0);
        tracep->declBus(c+50,"SimTop if_axi_ar_len", false,-1, 7,0);
        tracep->declBus(c+51,"SimTop cli_ar_len", false,-1, 7,0);
        tracep->declBus(c+52,"SimTop mem_axi_ar_size", false,-1, 2,0);
        tracep->declBus(c+53,"SimTop if_axi_ar_size", false,-1, 2,0);
        tracep->declBus(c+54,"SimTop cli_ar_size", false,-1, 2,0);
        tracep->declBus(c+1486,"SimTop mem_axi_ar_burst", false,-1, 1,0);
        tracep->declBus(c+1486,"SimTop if_axi_ar_burst", false,-1, 1,0);
        tracep->declBus(c+1491,"SimTop cli_ar_burst", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop mem_axi_ar_lock", false,-1);
        tracep->declBit(c+1487,"SimTop if_axi_ar_lock", false,-1);
        tracep->declBit(c+1487,"SimTop cli_ar_lock", false,-1);
        tracep->declBus(c+1488,"SimTop mem_axi_ar_cache", false,-1, 3,0);
        tracep->declBus(c+1488,"SimTop if_axi_ar_cache", false,-1, 3,0);
        tracep->declBus(c+55,"SimTop cli_ar_cache", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop mem_axi_ar_qos", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop if_axi_ar_qos", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop cli_ar_qos", false,-1, 3,0);
        tracep->declBit(c+56,"SimTop mem_axi_r_ready", false,-1);
        tracep->declBit(c+57,"SimTop if_axi_r_ready", false,-1);
        tracep->declBit(c+58,"SimTop cli_r_ready", false,-1);
        tracep->declBit(c+1133,"SimTop mem_axi_r_valid", false,-1);
        tracep->declBit(c+1134,"SimTop if_axi_r_valid", false,-1);
        tracep->declBit(c+1492,"SimTop cli_r_valid", false,-1);
        tracep->declBus(c+1135,"SimTop mem_axi_r_resp", false,-1, 1,0);
        tracep->declBus(c+1136,"SimTop if_axi_r_resp", false,-1, 1,0);
        tracep->declBus(c+1490,"SimTop cli_r_resp", false,-1, 1,0);
        tracep->declQuad(c+1198,"SimTop mem_axi_r_data", false,-1, 63,0);
        tracep->declQuad(c+1200,"SimTop if_axi_r_data", false,-1, 63,0);
        tracep->declQuad(c+59,"SimTop cli_r_data", false,-1, 63,0);
        tracep->declBit(c+1137,"SimTop mem_axi_r_last", false,-1);
        tracep->declBit(c+1138,"SimTop if_axi_r_last", false,-1);
        tracep->declBit(c+1492,"SimTop cli_r_last", false,-1);
        tracep->declBus(c+1433,"SimTop mem_axi_r_id", false,-1, 3,0);
        tracep->declBus(c+1434,"SimTop if_axi_r_id", false,-1, 3,0);
        tracep->declBus(c+61,"SimTop cli_r_id", false,-1, 3,0);
        tracep->declBus(c+1435,"SimTop mem_axi_r_user", false,-1, 0,0);
        tracep->declBus(c+1436,"SimTop if_axi_r_user", false,-1, 0,0);
        tracep->declBus(c+62,"SimTop cli_r_user", false,-1, 0,0);
        tracep->declBit(c+63,"SimTop if_rw_valid", false,-1);
        tracep->declBit(c+64,"SimTop if_rw_ready", false,-1);
        tracep->declBit(c+1487,"SimTop if_rw_req", false,-1);
        tracep->declQuad(c+65,"SimTop if_r_data", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop if_w_data", false,-1, 63,0);
        tracep->declQuad(c+67,"SimTop if_rw_addr", false,-1, 63,0);
        tracep->declBus(c+1495,"SimTop if_rw_size", false,-1, 1,0);
        tracep->declBus(c+69,"SimTop if_rw_resp", false,-1, 1,0);
        tracep->declBit(c+70,"SimTop mem_rw_valid", false,-1);
        tracep->declBit(c+71,"SimTop mem_rw_ready", false,-1);
        tracep->declBit(c+72,"SimTop mem_rw_req", false,-1);
        tracep->declQuad(c+73,"SimTop mem_r_data", false,-1, 63,0);
        tracep->declQuad(c+75,"SimTop mem_w_data", false,-1, 63,0);
        tracep->declQuad(c+77,"SimTop mem_rw_addr", false,-1, 63,0);
        tracep->declBus(c+79,"SimTop mem_rw_size", false,-1, 1,0);
        tracep->declBus(c+80,"SimTop mem_rw_resp", false,-1, 1,0);
        tracep->declBus(c+81,"SimTop clint_interupt_bus", false,-1, 11,0);
        tracep->declBus(c+1480,"SimTop axi_2x2 RW_DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1480,"SimTop axi_2x2 RW_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1480,"SimTop axi_2x2 AXI_DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1480,"SimTop axi_2x2 AXI_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1481,"SimTop axi_2x2 AXI_ID_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1482,"SimTop axi_2x2 AXI_USER_WIDTH", false,-1, 31,0);
        tracep->declBit(c+1355,"SimTop axi_2x2 clock", false,-1);
        tracep->declBit(c+1356,"SimTop axi_2x2 reset", false,-1);
        tracep->declBit(c+1127,"SimTop axi_2x2 aw_ready_o_0", false,-1);
        tracep->declBit(c+2,"SimTop axi_2x2 aw_valid_i_0", false,-1);
        tracep->declQuad(c+5,"SimTop axi_2x2 aw_addr_i_0", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop axi_2x2 aw_prot_i_0", false,-1, 2,0);
        tracep->declBus(c+11,"SimTop axi_2x2 aw_id_i_0", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop axi_2x2 aw_user_i_0", false,-1, 0,0);
        tracep->declBus(c+13,"SimTop axi_2x2 aw_len_i_0", false,-1, 7,0);
        tracep->declBus(c+16,"SimTop axi_2x2 aw_size_i_0", false,-1, 2,0);
        tracep->declBus(c+1486,"SimTop axi_2x2 aw_burst_i_0", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop axi_2x2 aw_lock_i_0", false,-1);
        tracep->declBus(c+1488,"SimTop axi_2x2 aw_cache_i_0", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop axi_2x2 aw_qos_i_0", false,-1, 3,0);
        tracep->declBit(c+1129,"SimTop axi_2x2 w_ready_o_0", false,-1);
        tracep->declBit(c+22,"SimTop axi_2x2 w_valid_i_0", false,-1);
        tracep->declQuad(c+24,"SimTop axi_2x2 w_data_i_0", false,-1, 63,0);
        tracep->declBus(c+30,"SimTop axi_2x2 w_strb_i_0", false,-1, 7,0);
        tracep->declBit(c+22,"SimTop axi_2x2 w_last_i_0", false,-1);
        tracep->declBus(c+1496,"SimTop axi_2x2 w_id_i_0", false,-1, 3,0);
        tracep->declBit(c+35,"SimTop axi_2x2 b_ready_i_0", false,-1);
        tracep->declBit(c+1196,"SimTop axi_2x2 b_valid_o_0", false,-1);
        tracep->declBus(c+1427,"SimTop axi_2x2 b_resp_o_0", false,-1, 1,0);
        tracep->declBus(c+1429,"SimTop axi_2x2 b_id_o_0", false,-1, 3,0);
        tracep->declBus(c+1431,"SimTop axi_2x2 b_user_o_0", false,-1, 0,0);
        tracep->declBit(c+1131,"SimTop axi_2x2 ar_ready_o_0", false,-1);
        tracep->declBit(c+42,"SimTop axi_2x2 ar_valid_i_0", false,-1);
        tracep->declQuad(c+5,"SimTop axi_2x2 ar_addr_i_0", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop axi_2x2 ar_prot_i_0", false,-1, 2,0);
        tracep->declBus(c+47,"SimTop axi_2x2 ar_id_i_0", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop axi_2x2 ar_user_i_0", false,-1, 0,0);
        tracep->declBus(c+49,"SimTop axi_2x2 ar_len_i_0", false,-1, 7,0);
        tracep->declBus(c+52,"SimTop axi_2x2 ar_size_i_0", false,-1, 2,0);
        tracep->declBus(c+1486,"SimTop axi_2x2 ar_burst_i_0", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop axi_2x2 ar_lock_i_0", false,-1);
        tracep->declBus(c+1488,"SimTop axi_2x2 ar_cache_i_0", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop axi_2x2 ar_qos_i_0", false,-1, 3,0);
        tracep->declBit(c+56,"SimTop axi_2x2 r_ready_i_0", false,-1);
        tracep->declBit(c+1133,"SimTop axi_2x2 r_valid_o_0", false,-1);
        tracep->declBus(c+1135,"SimTop axi_2x2 r_resp_o_0", false,-1, 1,0);
        tracep->declQuad(c+1198,"SimTop axi_2x2 r_data_o_0", false,-1, 63,0);
        tracep->declBit(c+1137,"SimTop axi_2x2 r_last_o_0", false,-1);
        tracep->declBus(c+1433,"SimTop axi_2x2 r_id_o_0", false,-1, 3,0);
        tracep->declBus(c+1435,"SimTop axi_2x2 r_user_o_0", false,-1, 0,0);
        tracep->declBit(c+1128,"SimTop axi_2x2 aw_ready_o_1", false,-1);
        tracep->declBit(c+3,"SimTop axi_2x2 aw_valid_i_1", false,-1);
        tracep->declQuad(c+7,"SimTop axi_2x2 aw_addr_i_1", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop axi_2x2 aw_prot_i_1", false,-1, 2,0);
        tracep->declBus(c+1484,"SimTop axi_2x2 aw_id_i_1", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop axi_2x2 aw_user_i_1", false,-1, 0,0);
        tracep->declBus(c+14,"SimTop axi_2x2 aw_len_i_1", false,-1, 7,0);
        tracep->declBus(c+17,"SimTop axi_2x2 aw_size_i_1", false,-1, 2,0);
        tracep->declBus(c+1486,"SimTop axi_2x2 aw_burst_i_1", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop axi_2x2 aw_lock_i_1", false,-1);
        tracep->declBus(c+1488,"SimTop axi_2x2 aw_cache_i_1", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop axi_2x2 aw_qos_i_1", false,-1, 3,0);
        tracep->declBit(c+1130,"SimTop axi_2x2 w_ready_o_1", false,-1);
        tracep->declBit(c+23,"SimTop axi_2x2 w_valid_i_1", false,-1);
        tracep->declQuad(c+26,"SimTop axi_2x2 w_data_i_1", false,-1, 63,0);
        tracep->declBus(c+31,"SimTop axi_2x2 w_strb_i_1", false,-1, 7,0);
        tracep->declBit(c+23,"SimTop axi_2x2 w_last_i_1", false,-1);
        tracep->declBus(c+1484,"SimTop axi_2x2 w_id_i_1", false,-1, 3,0);
        tracep->declBit(c+36,"SimTop axi_2x2 b_ready_i_1", false,-1);
        tracep->declBit(c+1197,"SimTop axi_2x2 b_valid_o_1", false,-1);
        tracep->declBus(c+1428,"SimTop axi_2x2 b_resp_o_1", false,-1, 1,0);
        tracep->declBus(c+1430,"SimTop axi_2x2 b_id_o_1", false,-1, 3,0);
        tracep->declBus(c+1432,"SimTop axi_2x2 b_user_o_1", false,-1, 0,0);
        tracep->declBit(c+1132,"SimTop axi_2x2 ar_ready_o_1", false,-1);
        tracep->declBit(c+43,"SimTop axi_2x2 ar_valid_i_1", false,-1);
        tracep->declQuad(c+7,"SimTop axi_2x2 ar_addr_i_1", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop axi_2x2 ar_prot_i_1", false,-1, 2,0);
        tracep->declBus(c+1484,"SimTop axi_2x2 ar_id_i_1", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop axi_2x2 ar_user_i_1", false,-1, 0,0);
        tracep->declBus(c+50,"SimTop axi_2x2 ar_len_i_1", false,-1, 7,0);
        tracep->declBus(c+53,"SimTop axi_2x2 ar_size_i_1", false,-1, 2,0);
        tracep->declBus(c+1486,"SimTop axi_2x2 ar_burst_i_1", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop axi_2x2 ar_lock_i_1", false,-1);
        tracep->declBus(c+1488,"SimTop axi_2x2 ar_cache_i_1", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop axi_2x2 ar_qos_i_1", false,-1, 3,0);
        tracep->declBit(c+57,"SimTop axi_2x2 r_ready_i_1", false,-1);
        tracep->declBit(c+1134,"SimTop axi_2x2 r_valid_o_1", false,-1);
        tracep->declBus(c+1136,"SimTop axi_2x2 r_resp_o_1", false,-1, 1,0);
        tracep->declQuad(c+1200,"SimTop axi_2x2 r_data_o_1", false,-1, 63,0);
        tracep->declBit(c+1138,"SimTop axi_2x2 r_last_o_1", false,-1);
        tracep->declBus(c+1434,"SimTop axi_2x2 r_id_o_1", false,-1, 3,0);
        tracep->declBus(c+1436,"SimTop axi_2x2 r_user_o_1", false,-1, 0,0);
        tracep->declBit(c+1369,"SimTop axi_2x2 ram_aw_ready_i", false,-1);
        tracep->declBit(c+1370,"SimTop axi_2x2 ram_aw_valid_o", false,-1);
        tracep->declQuad(c+1371,"SimTop axi_2x2 ram_aw_addr_o", false,-1, 63,0);
        tracep->declBus(c+1373,"SimTop axi_2x2 ram_aw_prot_o", false,-1, 2,0);
        tracep->declBus(c+1374,"SimTop axi_2x2 ram_aw_id_o", false,-1, 3,0);
        tracep->declBus(c+1375,"SimTop axi_2x2 ram_aw_user_o", false,-1, 0,0);
        tracep->declBus(c+1376,"SimTop axi_2x2 ram_aw_len_o", false,-1, 7,0);
        tracep->declBus(c+1377,"SimTop axi_2x2 ram_aw_size_o", false,-1, 2,0);
        tracep->declBus(c+1378,"SimTop axi_2x2 ram_aw_burst_o", false,-1, 1,0);
        tracep->declBit(c+1379,"SimTop axi_2x2 ram_aw_lock_o", false,-1);
        tracep->declBus(c+1380,"SimTop axi_2x2 ram_aw_cache_o", false,-1, 3,0);
        tracep->declBus(c+1381,"SimTop axi_2x2 ram_aw_qos_o", false,-1, 3,0);
        tracep->declBit(c+1382,"SimTop axi_2x2 ram_w_ready_i", false,-1);
        tracep->declBit(c+1383,"SimTop axi_2x2 ram_w_valid_o", false,-1);
        tracep->declQuad(c+82,"SimTop axi_2x2 ram_w_data_o", false,-1, 63,0);
        tracep->declBus(c+1392,"SimTop axi_2x2 ram_w_strb_o", false,-1, 7,0);
        tracep->declBit(c+1393,"SimTop axi_2x2 ram_w_last_o", false,-1);
        tracep->declBus(c+1394,"SimTop axi_2x2 ram_w_id_o", false,-1, 3,0);
        tracep->declBit(c+1395,"SimTop axi_2x2 ram_b_ready_o", false,-1);
        tracep->declBit(c+1396,"SimTop axi_2x2 ram_b_valid_i", false,-1);
        tracep->declBus(c+1397,"SimTop axi_2x2 ram_b_resp_i", false,-1, 1,0);
        tracep->declBus(c+1398,"SimTop axi_2x2 ram_b_id_i", false,-1, 3,0);
        tracep->declBus(c+1399,"SimTop axi_2x2 ram_b_user_i", false,-1, 0,0);
        tracep->declBit(c+1400,"SimTop axi_2x2 ram_ar_ready_i", false,-1);
        tracep->declBit(c+1401,"SimTop axi_2x2 ram_ar_valid_o", false,-1);
        tracep->declQuad(c+1402,"SimTop axi_2x2 ram_ar_addr_o", false,-1, 63,0);
        tracep->declBus(c+1404,"SimTop axi_2x2 ram_ar_prot_o", false,-1, 2,0);
        tracep->declBus(c+1405,"SimTop axi_2x2 ram_ar_id_o", false,-1, 3,0);
        tracep->declBus(c+1406,"SimTop axi_2x2 ram_ar_user_o", false,-1, 0,0);
        tracep->declBus(c+1407,"SimTop axi_2x2 ram_ar_len_o", false,-1, 7,0);
        tracep->declBus(c+1408,"SimTop axi_2x2 ram_ar_size_o", false,-1, 2,0);
        tracep->declBus(c+1409,"SimTop axi_2x2 ram_ar_burst_o", false,-1, 1,0);
        tracep->declBit(c+1410,"SimTop axi_2x2 ram_ar_lock_o", false,-1);
        tracep->declBus(c+1411,"SimTop axi_2x2 ram_ar_cache_o", false,-1, 3,0);
        tracep->declBus(c+1412,"SimTop axi_2x2 ram_ar_qos_o", false,-1, 3,0);
        tracep->declBit(c+1413,"SimTop axi_2x2 ram_r_ready_o", false,-1);
        tracep->declBit(c+1414,"SimTop axi_2x2 ram_r_valid_i", false,-1);
        tracep->declBus(c+1415,"SimTop axi_2x2 ram_r_resp_i", false,-1, 1,0);
        tracep->declQuad(c+1437,"SimTop axi_2x2 ram_r_data_i", false,-1, 63,0);
        tracep->declBit(c+1424,"SimTop axi_2x2 ram_r_last_i", false,-1);
        tracep->declBus(c+1425,"SimTop axi_2x2 ram_r_id_i", false,-1, 3,0);
        tracep->declBus(c+1426,"SimTop axi_2x2 ram_r_user_i", false,-1, 0,0);
        tracep->declBit(c+1,"SimTop axi_2x2 cli_aw_ready_i", false,-1);
        tracep->declBit(c+4,"SimTop axi_2x2 cli_aw_valid_o", false,-1);
        tracep->declQuad(c+9,"SimTop axi_2x2 cli_aw_addr_o", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop axi_2x2 cli_aw_prot_o", false,-1, 2,0);
        tracep->declBus(c+12,"SimTop axi_2x2 cli_aw_id_o", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop axi_2x2 cli_aw_user_o", false,-1, 0,0);
        tracep->declBus(c+15,"SimTop axi_2x2 cli_aw_len_o", false,-1, 7,0);
        tracep->declBus(c+18,"SimTop axi_2x2 cli_aw_size_o", false,-1, 2,0);
        tracep->declBus(c+19,"SimTop axi_2x2 cli_aw_burst_o", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop axi_2x2 cli_aw_lock_o", false,-1);
        tracep->declBus(c+20,"SimTop axi_2x2 cli_aw_cache_o", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop axi_2x2 cli_aw_qos_o", false,-1, 3,0);
        tracep->declBit(c+21,"SimTop axi_2x2 cli_w_ready_i", false,-1);
        tracep->declBit(c+21,"SimTop axi_2x2 cli_w_valid_o", false,-1);
        tracep->declQuad(c+28,"SimTop axi_2x2 cli_w_data_o", false,-1, 63,0);
        tracep->declBus(c+32,"SimTop axi_2x2 cli_w_strb_o", false,-1, 7,0);
        tracep->declBit(c+33,"SimTop axi_2x2 cli_w_last_o", false,-1);
        tracep->declBus(c+84,"SimTop axi_2x2 cli_w_id_o", false,-1, 3,0);
        tracep->declBit(c+37,"SimTop axi_2x2 cli_b_ready_o", false,-1);
        tracep->declBit(c+38,"SimTop axi_2x2 cli_b_valid_i", false,-1);
        tracep->declBus(c+1490,"SimTop axi_2x2 cli_b_resp_i", false,-1, 1,0);
        tracep->declBus(c+39,"SimTop axi_2x2 cli_b_id_i", false,-1, 3,0);
        tracep->declBus(c+40,"SimTop axi_2x2 cli_b_user_i", false,-1, 0,0);
        tracep->declBit(c+41,"SimTop axi_2x2 cli_ar_ready_i", false,-1);
        tracep->declBit(c+44,"SimTop axi_2x2 cli_ar_valid_o", false,-1);
        tracep->declQuad(c+45,"SimTop axi_2x2 cli_ar_addr_o", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop axi_2x2 cli_ar_prot_o", false,-1, 2,0);
        tracep->declBus(c+48,"SimTop axi_2x2 cli_ar_id_o", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop axi_2x2 cli_ar_user_o", false,-1, 0,0);
        tracep->declBus(c+51,"SimTop axi_2x2 cli_ar_len_o", false,-1, 7,0);
        tracep->declBus(c+54,"SimTop axi_2x2 cli_ar_size_o", false,-1, 2,0);
        tracep->declBus(c+19,"SimTop axi_2x2 cli_ar_burst_o", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop axi_2x2 cli_ar_lock_o", false,-1);
        tracep->declBus(c+55,"SimTop axi_2x2 cli_ar_cache_o", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop axi_2x2 cli_ar_qos_o", false,-1, 3,0);
        tracep->declBit(c+58,"SimTop axi_2x2 cli_r_ready_o", false,-1);
        tracep->declBit(c+1492,"SimTop axi_2x2 cli_r_valid_i", false,-1);
        tracep->declBus(c+1490,"SimTop axi_2x2 cli_r_resp_i", false,-1, 1,0);
        tracep->declQuad(c+59,"SimTop axi_2x2 cli_r_data_i", false,-1, 63,0);
        tracep->declBit(c+1492,"SimTop axi_2x2 cli_r_last_i", false,-1);
        tracep->declBus(c+61,"SimTop axi_2x2 cli_r_id_i", false,-1, 3,0);
        tracep->declBus(c+62,"SimTop axi_2x2 cli_r_user_i", false,-1, 0,0);
        tracep->declBit(c+1439,"SimTop axi_2x2 debug_oc_r", false,-1);
        tracep->declBit(c+1440,"SimTop axi_2x2 debug_oc_w", false,-1);
        tracep->declBit(c+1202,"SimTop axi_2x2 mid_aw_ready", false,-1);
        tracep->declBit(c+85,"SimTop axi_2x2 mid_aw_valid", false,-1);
        tracep->declQuad(c+86,"SimTop axi_2x2 mid_aw_addr", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop axi_2x2 mid_aw_prot", false,-1, 2,0);
        tracep->declBus(c+88,"SimTop axi_2x2 mid_aw_id", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop axi_2x2 mid_aw_user", false,-1, 0,0);
        tracep->declBus(c+89,"SimTop axi_2x2 mid_aw_len", false,-1, 7,0);
        tracep->declBus(c+90,"SimTop axi_2x2 mid_aw_size", false,-1, 2,0);
        tracep->declBus(c+91,"SimTop axi_2x2 mid_aw_burst", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop axi_2x2 mid_aw_lock", false,-1);
        tracep->declBus(c+92,"SimTop axi_2x2 mid_aw_cache", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop axi_2x2 mid_aw_qos", false,-1, 3,0);
        tracep->declBit(c+1203,"SimTop axi_2x2 mid_w_ready", false,-1);
        tracep->declBit(c+93,"SimTop axi_2x2 mid_w_valid", false,-1);
        tracep->declQuad(c+94,"SimTop axi_2x2 mid_w_data", false,-1, 63,0);
        tracep->declBus(c+96,"SimTop axi_2x2 mid_w_strb", false,-1, 7,0);
        tracep->declBit(c+93,"SimTop axi_2x2 mid_w_last", false,-1);
        tracep->declBus(c+97,"SimTop axi_2x2 mid_w_id", false,-1, 3,0);
        tracep->declBit(c+98,"SimTop axi_2x2 mid_b_ready", false,-1);
        tracep->declBit(c+1204,"SimTop axi_2x2 mid_b_valid", false,-1);
        tracep->declBus(c+1441,"SimTop axi_2x2 mid_b_resp", false,-1, 1,0);
        tracep->declBus(c+1442,"SimTop axi_2x2 mid_b_id", false,-1, 3,0);
        tracep->declBus(c+1443,"SimTop axi_2x2 mid_b_user", false,-1, 0,0);
        tracep->declBit(c+1205,"SimTop axi_2x2 mid_ar_ready", false,-1);
        tracep->declBit(c+99,"SimTop axi_2x2 mid_ar_valid", false,-1);
        tracep->declQuad(c+100,"SimTop axi_2x2 mid_ar_addr", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop axi_2x2 mid_ar_prot", false,-1, 2,0);
        tracep->declBus(c+102,"SimTop axi_2x2 mid_ar_id", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop axi_2x2 mid_ar_user", false,-1, 0,0);
        tracep->declBus(c+103,"SimTop axi_2x2 mid_ar_len", false,-1, 7,0);
        tracep->declBus(c+104,"SimTop axi_2x2 mid_ar_size", false,-1, 2,0);
        tracep->declBus(c+105,"SimTop axi_2x2 mid_ar_burst", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop axi_2x2 mid_ar_lock", false,-1);
        tracep->declBus(c+106,"SimTop axi_2x2 mid_ar_cache", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop axi_2x2 mid_ar_qos", false,-1, 3,0);
        tracep->declBit(c+107,"SimTop axi_2x2 mid_r_ready", false,-1);
        tracep->declBit(c+1206,"SimTop axi_2x2 mid_r_valid", false,-1);
        tracep->declBus(c+1207,"SimTop axi_2x2 mid_r_resp", false,-1, 1,0);
        tracep->declQuad(c+1208,"SimTop axi_2x2 mid_r_data", false,-1, 63,0);
        tracep->declBit(c+1210,"SimTop axi_2x2 mid_r_last", false,-1);
        tracep->declBus(c+1444,"SimTop axi_2x2 mid_r_id", false,-1, 3,0);
        tracep->declBus(c+1445,"SimTop axi_2x2 mid_r_user", false,-1, 0,0);
        tracep->declBit(c+1139,"SimTop axi_2x2 r_finish_0", false,-1);
        tracep->declBit(c+1140,"SimTop axi_2x2 r_finish_1", false,-1);
        tracep->declBit(c+108,"SimTop axi_2x2 r_finish_cli", false,-1);
        tracep->declBit(c+1446,"SimTop axi_2x2 r_finish_ram", false,-1);
        tracep->declBit(c+1141,"SimTop axi_2x2 w_finish_0", false,-1);
        tracep->declBit(c+1142,"SimTop axi_2x2 w_finish_1", false,-1);
        tracep->declBit(c+109,"SimTop axi_2x2 w_finish_cli", false,-1);
        tracep->declBit(c+1447,"SimTop axi_2x2 w_finish_ram", false,-1);
        tracep->declBus(c+1490,"SimTop axi_2x2 STATE_IDLE", false,-1, 1,0);
        tracep->declBus(c+1486,"SimTop axi_2x2 STATE_0", false,-1, 1,0);
        tracep->declBus(c+1495,"SimTop axi_2x2 STATE_1", false,-1, 1,0);
        tracep->declBus(c+1486,"SimTop axi_2x2 STATE_CLINT", false,-1, 1,0);
        tracep->declBus(c+1495,"SimTop axi_2x2 STATE_RAM", false,-1, 1,0);
        tracep->declBus(c+110,"SimTop axi_2x2 master_w_state", false,-1, 1,0);
        tracep->declBus(c+111,"SimTop axi_2x2 slave_w_state", false,-1, 1,0);
        tracep->declBit(c+112,"SimTop axi_2x2 w_0_to_cli", false,-1);
        tracep->declBit(c+113,"SimTop axi_2x2 w_0_to_ram", false,-1);
        tracep->declBit(c+114,"SimTop axi_2x2 w_1_to_cli", false,-1);
        tracep->declBit(c+115,"SimTop axi_2x2 w_1_to_ram", false,-1);
        tracep->declBus(c+1211,"SimTop axi_2x2 master_w_next_state", false,-1, 1,0);
        tracep->declBus(c+1212,"SimTop axi_2x2 slave_w_next_state", false,-1, 1,0);
        tracep->declBus(c+116,"SimTop axi_2x2 master_r_state", false,-1, 1,0);
        tracep->declBus(c+117,"SimTop axi_2x2 slave_r_state", false,-1, 1,0);
        tracep->declBit(c+112,"SimTop axi_2x2 r_0_to_cli", false,-1);
        tracep->declBit(c+113,"SimTop axi_2x2 r_0_to_ram", false,-1);
        tracep->declBit(c+114,"SimTop axi_2x2 r_1_to_cli", false,-1);
        tracep->declBit(c+115,"SimTop axi_2x2 r_1_to_ram", false,-1);
        tracep->declBus(c+1213,"SimTop axi_2x2 master_r_next_state", false,-1, 1,0);
        tracep->declBus(c+1214,"SimTop axi_2x2 slave_r_next_state", false,-1, 1,0);
        tracep->declBit(c+118,"SimTop axi_2x2 w_state_0", false,-1);
        tracep->declBit(c+119,"SimTop axi_2x2 w_state_1", false,-1);
        tracep->declBit(c+120,"SimTop axi_2x2 w_state_cli", false,-1);
        tracep->declBit(c+121,"SimTop axi_2x2 w_state_ram", false,-1);
        tracep->declBit(c+122,"SimTop axi_2x2 r_state_0", false,-1);
        tracep->declBit(c+123,"SimTop axi_2x2 r_state_1", false,-1);
        tracep->declBit(c+124,"SimTop axi_2x2 r_state_cli", false,-1);
        tracep->declBit(c+125,"SimTop axi_2x2 r_state_ram", false,-1);
        tracep->declBus(c+1480,"SimTop mem_axi_rw RW_DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1480,"SimTop mem_axi_rw RW_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1480,"SimTop mem_axi_rw AXI_DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1480,"SimTop mem_axi_rw AXI_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1481,"SimTop mem_axi_rw AXI_ID_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1482,"SimTop mem_axi_rw AXI_USER_WIDTH", false,-1, 31,0);
        tracep->declBit(c+1355,"SimTop mem_axi_rw clock", false,-1);
        tracep->declBit(c+1356,"SimTop mem_axi_rw reset", false,-1);
        tracep->declBus(c+1496,"SimTop mem_axi_rw device_id", false,-1, 3,0);
        tracep->declBit(c+70,"SimTop mem_axi_rw rw_valid_i", false,-1);
        tracep->declBit(c+71,"SimTop mem_axi_rw rw_ready_o", false,-1);
        tracep->declBit(c+72,"SimTop mem_axi_rw rw_req_i", false,-1);
        tracep->declQuad(c+73,"SimTop mem_axi_rw data_read_o", false,-1, 63,0);
        tracep->declQuad(c+75,"SimTop mem_axi_rw data_write_i", false,-1, 63,0);
        tracep->declQuad(c+77,"SimTop mem_axi_rw rw_addr_i", false,-1, 63,0);
        tracep->declBus(c+79,"SimTop mem_axi_rw rw_size_i", false,-1, 1,0);
        tracep->declBus(c+80,"SimTop mem_axi_rw rw_resp_o", false,-1, 1,0);
        tracep->declBit(c+1127,"SimTop mem_axi_rw axi_aw_ready_i", false,-1);
        tracep->declBit(c+2,"SimTop mem_axi_rw axi_aw_valid_o", false,-1);
        tracep->declQuad(c+5,"SimTop mem_axi_rw axi_aw_addr_o", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop mem_axi_rw axi_aw_prot_o", false,-1, 2,0);
        tracep->declBus(c+11,"SimTop mem_axi_rw axi_aw_id_o", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop mem_axi_rw axi_aw_user_o", false,-1, 0,0);
        tracep->declBus(c+13,"SimTop mem_axi_rw axi_aw_len_o", false,-1, 7,0);
        tracep->declBus(c+16,"SimTop mem_axi_rw axi_aw_size_o", false,-1, 2,0);
        tracep->declBus(c+1486,"SimTop mem_axi_rw axi_aw_burst_o", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop mem_axi_rw axi_aw_lock_o", false,-1);
        tracep->declBus(c+1488,"SimTop mem_axi_rw axi_aw_cache_o", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop mem_axi_rw axi_aw_qos_o", false,-1, 3,0);
        tracep->declBit(c+1129,"SimTop mem_axi_rw axi_w_ready_i", false,-1);
        tracep->declBit(c+22,"SimTop mem_axi_rw axi_w_valid_o", false,-1);
        tracep->declQuad(c+24,"SimTop mem_axi_rw axi_w_data_o", false,-1, 63,0);
        tracep->declBus(c+30,"SimTop mem_axi_rw axi_w_strb_o", false,-1, 7,0);
        tracep->declBit(c+22,"SimTop mem_axi_rw axi_w_last_o", false,-1);
        tracep->declBus(c+1496,"SimTop mem_axi_rw axi_w_id_o", false,-1, 3,0);
        tracep->declBit(c+35,"SimTop mem_axi_rw axi_b_ready_o", false,-1);
        tracep->declBit(c+1196,"SimTop mem_axi_rw axi_b_valid_i", false,-1);
        tracep->declBus(c+1427,"SimTop mem_axi_rw axi_b_resp_i", false,-1, 1,0);
        tracep->declBus(c+1429,"SimTop mem_axi_rw axi_b_id_i", false,-1, 3,0);
        tracep->declBus(c+1431,"SimTop mem_axi_rw axi_b_user_i", false,-1, 0,0);
        tracep->declBit(c+1131,"SimTop mem_axi_rw axi_ar_ready_i", false,-1);
        tracep->declBit(c+42,"SimTop mem_axi_rw axi_ar_valid_o", false,-1);
        tracep->declQuad(c+5,"SimTop mem_axi_rw axi_ar_addr_o", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop mem_axi_rw axi_ar_prot_o", false,-1, 2,0);
        tracep->declBus(c+47,"SimTop mem_axi_rw axi_ar_id_o", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop mem_axi_rw axi_ar_user_o", false,-1, 0,0);
        tracep->declBus(c+49,"SimTop mem_axi_rw axi_ar_len_o", false,-1, 7,0);
        tracep->declBus(c+52,"SimTop mem_axi_rw axi_ar_size_o", false,-1, 2,0);
        tracep->declBus(c+1486,"SimTop mem_axi_rw axi_ar_burst_o", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop mem_axi_rw axi_ar_lock_o", false,-1);
        tracep->declBus(c+1488,"SimTop mem_axi_rw axi_ar_cache_o", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop mem_axi_rw axi_ar_qos_o", false,-1, 3,0);
        tracep->declBit(c+56,"SimTop mem_axi_rw axi_r_ready_o", false,-1);
        tracep->declBit(c+1133,"SimTop mem_axi_rw axi_r_valid_i", false,-1);
        tracep->declBus(c+1135,"SimTop mem_axi_rw axi_r_resp_i", false,-1, 1,0);
        tracep->declQuad(c+1198,"SimTop mem_axi_rw axi_r_data_i", false,-1, 63,0);
        tracep->declBit(c+1137,"SimTop mem_axi_rw axi_r_last_i", false,-1);
        tracep->declBus(c+1433,"SimTop mem_axi_rw axi_r_id_i", false,-1, 3,0);
        tracep->declBus(c+1435,"SimTop mem_axi_rw axi_r_user_i", false,-1, 0,0);
        tracep->declBit(c+72,"SimTop mem_axi_rw w_trans", false,-1);
        tracep->declBit(c+126,"SimTop mem_axi_rw r_trans", false,-1);
        tracep->declBit(c+127,"SimTop mem_axi_rw w_valid", false,-1);
        tracep->declBit(c+128,"SimTop mem_axi_rw r_valid", false,-1);
        tracep->declBit(c+1215,"SimTop mem_axi_rw aw_hs", false,-1);
        tracep->declBit(c+1216,"SimTop mem_axi_rw w_hs", false,-1);
        tracep->declBit(c+1217,"SimTop mem_axi_rw b_hs", false,-1);
        tracep->declBit(c+1143,"SimTop mem_axi_rw ar_hs", false,-1);
        tracep->declBit(c+1218,"SimTop mem_axi_rw r_hs", false,-1);
        tracep->declBit(c+1144,"SimTop mem_axi_rw w_done", false,-1);
        tracep->declBit(c+1219,"SimTop mem_axi_rw r_done", false,-1);
        tracep->declBit(c+1220,"SimTop mem_axi_rw trans_done", false,-1);
        tracep->declBus(c+1483,"SimTop mem_axi_rw W_STATE_IDLE", false,-1, 2,0);
        tracep->declBus(c+1497,"SimTop mem_axi_rw W_STATE_ADDR", false,-1, 2,0);
        tracep->declBus(c+1498,"SimTop mem_axi_rw W_STATE_WRITE", false,-1, 2,0);
        tracep->declBus(c+1499,"SimTop mem_axi_rw W_STATE_RESP", false,-1, 2,0);
        tracep->declBus(c+1500,"SimTop mem_axi_rw W_STATE_RETN", false,-1, 2,0);
        tracep->declBus(c+1483,"SimTop mem_axi_rw R_STATE_IDLE", false,-1, 2,0);
        tracep->declBus(c+1497,"SimTop mem_axi_rw R_STATE_ADDR", false,-1, 2,0);
        tracep->declBus(c+1498,"SimTop mem_axi_rw R_STATE_READ", false,-1, 2,0);
        tracep->declBus(c+1499,"SimTop mem_axi_rw R_STATE_RETN", false,-1, 2,0);
        tracep->declBus(c+129,"SimTop mem_axi_rw w_state", false,-1, 2,0);
        tracep->declBus(c+130,"SimTop mem_axi_rw r_state", false,-1, 2,0);
        tracep->declBit(c+131,"SimTop mem_axi_rw w_state_idle", false,-1);
        tracep->declBit(c+2,"SimTop mem_axi_rw w_state_addr", false,-1);
        tracep->declBit(c+22,"SimTop mem_axi_rw w_state_write", false,-1);
        tracep->declBit(c+35,"SimTop mem_axi_rw w_state_resp", false,-1);
        tracep->declBit(c+132,"SimTop mem_axi_rw r_state_idle", false,-1);
        tracep->declBit(c+42,"SimTop mem_axi_rw r_state_addr", false,-1);
        tracep->declBit(c+56,"SimTop mem_axi_rw r_state_read", false,-1);
        tracep->declBus(c+133,"SimTop mem_axi_rw len", false,-1, 7,0);
        tracep->declBit(c+1448,"SimTop mem_axi_rw len_reset", false,-1);
        tracep->declBit(c+1145,"SimTop mem_axi_rw len_incr_en", false,-1);
        tracep->declBus(c+1501,"SimTop mem_axi_rw ALIGNED_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1502,"SimTop mem_axi_rw OFFSET_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1501,"SimTop mem_axi_rw AXI_SIZE", false,-1, 31,0);
        tracep->declBus(c+1503,"SimTop mem_axi_rw MASK_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1482,"SimTop mem_axi_rw TRANS_LEN", false,-1, 31,0);
        tracep->declBit(c+134,"SimTop mem_axi_rw aligned", false,-1);
        tracep->declBit(c+135,"SimTop mem_axi_rw size_b", false,-1);
        tracep->declBit(c+136,"SimTop mem_axi_rw size_h", false,-1);
        tracep->declBit(c+137,"SimTop mem_axi_rw size_w", false,-1);
        tracep->declBit(c+138,"SimTop mem_axi_rw size_d", false,-1);
        tracep->declBus(c+139,"SimTop mem_axi_rw addr_op1", false,-1, 3,0);
        tracep->declBus(c+140,"SimTop mem_axi_rw addr_op2", false,-1, 3,0);
        tracep->declBus(c+141,"SimTop mem_axi_rw addr_end", false,-1, 3,0);
        tracep->declBit(c+142,"SimTop mem_axi_rw overstep", false,-1);
        tracep->declBus(c+143,"SimTop mem_axi_rw axi_len", false,-1, 7,0);
        tracep->declBus(c+1499,"SimTop mem_axi_rw axi_size", false,-1, 2,0);
        tracep->declQuad(c+5,"SimTop mem_axi_rw axi_addr", false,-1, 63,0);
        tracep->declBus(c+144,"SimTop mem_axi_rw aligned_offset_l", false,-1, 5,0);
        tracep->declBus(c+145,"SimTop mem_axi_rw aligned_offset_h", false,-1, 5,0);
        tracep->declArray(c+146,"SimTop mem_axi_rw mask", false,-1, 127,0);
        tracep->declQuad(c+150,"SimTop mem_axi_rw mask_l", false,-1, 63,0);
        tracep->declQuad(c+152,"SimTop mem_axi_rw mask_h", false,-1, 63,0);
        tracep->declBus(c+1496,"SimTop mem_axi_rw axi_id", false,-1, 3,0);
        tracep->declBus(c+1487,"SimTop mem_axi_rw axi_user", false,-1, 0,0);
        tracep->declBit(c+71,"SimTop mem_axi_rw rw_ready", false,-1);
        tracep->declBit(c+1220,"SimTop mem_axi_rw rw_ready_nxt", false,-1);
        tracep->declBit(c+1146,"SimTop mem_axi_rw rw_ready_en", false,-1);
        tracep->declBus(c+80,"SimTop mem_axi_rw rw_resp", false,-1, 1,0);
        tracep->declBit(c+1449,"SimTop mem_axi_rw rw_resp_nxt", false,-1);
        tracep->declBit(c+1220,"SimTop mem_axi_rw resp_en", false,-1);
        tracep->declQuad(c+1221,"SimTop mem_axi_rw axi_r_data_l", false,-1, 63,0);
        tracep->declQuad(c+1147,"SimTop mem_axi_rw axi_r_data_h", false,-1, 63,0);
        tracep->declBus(c+1480,"SimTop if_axi_rw RW_DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1480,"SimTop if_axi_rw RW_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1480,"SimTop if_axi_rw AXI_DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1480,"SimTop if_axi_rw AXI_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1481,"SimTop if_axi_rw AXI_ID_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1482,"SimTop if_axi_rw AXI_USER_WIDTH", false,-1, 31,0);
        tracep->declBit(c+1355,"SimTop if_axi_rw clock", false,-1);
        tracep->declBit(c+1356,"SimTop if_axi_rw reset", false,-1);
        tracep->declBus(c+1484,"SimTop if_axi_rw device_id", false,-1, 3,0);
        tracep->declBit(c+63,"SimTop if_axi_rw rw_valid_i", false,-1);
        tracep->declBit(c+64,"SimTop if_axi_rw rw_ready_o", false,-1);
        tracep->declBit(c+1487,"SimTop if_axi_rw rw_req_i", false,-1);
        tracep->declQuad(c+65,"SimTop if_axi_rw data_read_o", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop if_axi_rw data_write_i", false,-1, 63,0);
        tracep->declQuad(c+67,"SimTop if_axi_rw rw_addr_i", false,-1, 63,0);
        tracep->declBus(c+1495,"SimTop if_axi_rw rw_size_i", false,-1, 1,0);
        tracep->declBus(c+69,"SimTop if_axi_rw rw_resp_o", false,-1, 1,0);
        tracep->declBit(c+1128,"SimTop if_axi_rw axi_aw_ready_i", false,-1);
        tracep->declBit(c+3,"SimTop if_axi_rw axi_aw_valid_o", false,-1);
        tracep->declQuad(c+7,"SimTop if_axi_rw axi_aw_addr_o", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop if_axi_rw axi_aw_prot_o", false,-1, 2,0);
        tracep->declBus(c+1484,"SimTop if_axi_rw axi_aw_id_o", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop if_axi_rw axi_aw_user_o", false,-1, 0,0);
        tracep->declBus(c+14,"SimTop if_axi_rw axi_aw_len_o", false,-1, 7,0);
        tracep->declBus(c+17,"SimTop if_axi_rw axi_aw_size_o", false,-1, 2,0);
        tracep->declBus(c+1486,"SimTop if_axi_rw axi_aw_burst_o", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop if_axi_rw axi_aw_lock_o", false,-1);
        tracep->declBus(c+1488,"SimTop if_axi_rw axi_aw_cache_o", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop if_axi_rw axi_aw_qos_o", false,-1, 3,0);
        tracep->declBit(c+1130,"SimTop if_axi_rw axi_w_ready_i", false,-1);
        tracep->declBit(c+23,"SimTop if_axi_rw axi_w_valid_o", false,-1);
        tracep->declQuad(c+26,"SimTop if_axi_rw axi_w_data_o", false,-1, 63,0);
        tracep->declBus(c+31,"SimTop if_axi_rw axi_w_strb_o", false,-1, 7,0);
        tracep->declBit(c+23,"SimTop if_axi_rw axi_w_last_o", false,-1);
        tracep->declBus(c+1484,"SimTop if_axi_rw axi_w_id_o", false,-1, 3,0);
        tracep->declBit(c+36,"SimTop if_axi_rw axi_b_ready_o", false,-1);
        tracep->declBit(c+1197,"SimTop if_axi_rw axi_b_valid_i", false,-1);
        tracep->declBus(c+1428,"SimTop if_axi_rw axi_b_resp_i", false,-1, 1,0);
        tracep->declBus(c+1430,"SimTop if_axi_rw axi_b_id_i", false,-1, 3,0);
        tracep->declBus(c+1432,"SimTop if_axi_rw axi_b_user_i", false,-1, 0,0);
        tracep->declBit(c+1132,"SimTop if_axi_rw axi_ar_ready_i", false,-1);
        tracep->declBit(c+43,"SimTop if_axi_rw axi_ar_valid_o", false,-1);
        tracep->declQuad(c+7,"SimTop if_axi_rw axi_ar_addr_o", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop if_axi_rw axi_ar_prot_o", false,-1, 2,0);
        tracep->declBus(c+1484,"SimTop if_axi_rw axi_ar_id_o", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop if_axi_rw axi_ar_user_o", false,-1, 0,0);
        tracep->declBus(c+50,"SimTop if_axi_rw axi_ar_len_o", false,-1, 7,0);
        tracep->declBus(c+53,"SimTop if_axi_rw axi_ar_size_o", false,-1, 2,0);
        tracep->declBus(c+1486,"SimTop if_axi_rw axi_ar_burst_o", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop if_axi_rw axi_ar_lock_o", false,-1);
        tracep->declBus(c+1488,"SimTop if_axi_rw axi_ar_cache_o", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop if_axi_rw axi_ar_qos_o", false,-1, 3,0);
        tracep->declBit(c+57,"SimTop if_axi_rw axi_r_ready_o", false,-1);
        tracep->declBit(c+1134,"SimTop if_axi_rw axi_r_valid_i", false,-1);
        tracep->declBus(c+1136,"SimTop if_axi_rw axi_r_resp_i", false,-1, 1,0);
        tracep->declQuad(c+1200,"SimTop if_axi_rw axi_r_data_i", false,-1, 63,0);
        tracep->declBit(c+1138,"SimTop if_axi_rw axi_r_last_i", false,-1);
        tracep->declBus(c+1434,"SimTop if_axi_rw axi_r_id_i", false,-1, 3,0);
        tracep->declBus(c+1436,"SimTop if_axi_rw axi_r_user_i", false,-1, 0,0);
        tracep->declBit(c+1487,"SimTop if_axi_rw w_trans", false,-1);
        tracep->declBit(c+1489,"SimTop if_axi_rw r_trans", false,-1);
        tracep->declBit(c+1487,"SimTop if_axi_rw w_valid", false,-1);
        tracep->declBit(c+63,"SimTop if_axi_rw r_valid", false,-1);
        tracep->declBit(c+1223,"SimTop if_axi_rw aw_hs", false,-1);
        tracep->declBit(c+1224,"SimTop if_axi_rw w_hs", false,-1);
        tracep->declBit(c+1149,"SimTop if_axi_rw b_hs", false,-1);
        tracep->declBit(c+1150,"SimTop if_axi_rw ar_hs", false,-1);
        tracep->declBit(c+1225,"SimTop if_axi_rw r_hs", false,-1);
        tracep->declBit(c+1151,"SimTop if_axi_rw w_done", false,-1);
        tracep->declBit(c+1226,"SimTop if_axi_rw r_done", false,-1);
        tracep->declBit(c+1226,"SimTop if_axi_rw trans_done", false,-1);
        tracep->declBus(c+1483,"SimTop if_axi_rw W_STATE_IDLE", false,-1, 2,0);
        tracep->declBus(c+1497,"SimTop if_axi_rw W_STATE_ADDR", false,-1, 2,0);
        tracep->declBus(c+1498,"SimTop if_axi_rw W_STATE_WRITE", false,-1, 2,0);
        tracep->declBus(c+1499,"SimTop if_axi_rw W_STATE_RESP", false,-1, 2,0);
        tracep->declBus(c+1500,"SimTop if_axi_rw W_STATE_RETN", false,-1, 2,0);
        tracep->declBus(c+1483,"SimTop if_axi_rw R_STATE_IDLE", false,-1, 2,0);
        tracep->declBus(c+1497,"SimTop if_axi_rw R_STATE_ADDR", false,-1, 2,0);
        tracep->declBus(c+1498,"SimTop if_axi_rw R_STATE_READ", false,-1, 2,0);
        tracep->declBus(c+1499,"SimTop if_axi_rw R_STATE_RETN", false,-1, 2,0);
        tracep->declBus(c+154,"SimTop if_axi_rw w_state", false,-1, 2,0);
        tracep->declBus(c+155,"SimTop if_axi_rw r_state", false,-1, 2,0);
        tracep->declBit(c+156,"SimTop if_axi_rw w_state_idle", false,-1);
        tracep->declBit(c+3,"SimTop if_axi_rw w_state_addr", false,-1);
        tracep->declBit(c+23,"SimTop if_axi_rw w_state_write", false,-1);
        tracep->declBit(c+36,"SimTop if_axi_rw w_state_resp", false,-1);
        tracep->declBit(c+157,"SimTop if_axi_rw r_state_idle", false,-1);
        tracep->declBit(c+43,"SimTop if_axi_rw r_state_addr", false,-1);
        tracep->declBit(c+57,"SimTop if_axi_rw r_state_read", false,-1);
        tracep->declBus(c+158,"SimTop if_axi_rw len", false,-1, 7,0);
        tracep->declBit(c+1450,"SimTop if_axi_rw len_reset", false,-1);
        tracep->declBit(c+1152,"SimTop if_axi_rw len_incr_en", false,-1);
        tracep->declBus(c+1501,"SimTop if_axi_rw ALIGNED_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1502,"SimTop if_axi_rw OFFSET_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1501,"SimTop if_axi_rw AXI_SIZE", false,-1, 31,0);
        tracep->declBus(c+1503,"SimTop if_axi_rw MASK_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1482,"SimTop if_axi_rw TRANS_LEN", false,-1, 31,0);
        tracep->declBit(c+159,"SimTop if_axi_rw aligned", false,-1);
        tracep->declBit(c+1487,"SimTop if_axi_rw size_b", false,-1);
        tracep->declBit(c+1487,"SimTop if_axi_rw size_h", false,-1);
        tracep->declBit(c+1489,"SimTop if_axi_rw size_w", false,-1);
        tracep->declBit(c+1487,"SimTop if_axi_rw size_d", false,-1);
        tracep->declBus(c+160,"SimTop if_axi_rw addr_op1", false,-1, 3,0);
        tracep->declBus(c+1504,"SimTop if_axi_rw addr_op2", false,-1, 3,0);
        tracep->declBus(c+161,"SimTop if_axi_rw addr_end", false,-1, 3,0);
        tracep->declBit(c+162,"SimTop if_axi_rw overstep", false,-1);
        tracep->declBus(c+163,"SimTop if_axi_rw axi_len", false,-1, 7,0);
        tracep->declBus(c+1499,"SimTop if_axi_rw axi_size", false,-1, 2,0);
        tracep->declQuad(c+7,"SimTop if_axi_rw axi_addr", false,-1, 63,0);
        tracep->declBus(c+164,"SimTop if_axi_rw aligned_offset_l", false,-1, 5,0);
        tracep->declBus(c+165,"SimTop if_axi_rw aligned_offset_h", false,-1, 5,0);
        tracep->declArray(c+166,"SimTop if_axi_rw mask", false,-1, 127,0);
        tracep->declQuad(c+170,"SimTop if_axi_rw mask_l", false,-1, 63,0);
        tracep->declQuad(c+172,"SimTop if_axi_rw mask_h", false,-1, 63,0);
        tracep->declBus(c+1484,"SimTop if_axi_rw axi_id", false,-1, 3,0);
        tracep->declBus(c+1487,"SimTop if_axi_rw axi_user", false,-1, 0,0);
        tracep->declBit(c+64,"SimTop if_axi_rw rw_ready", false,-1);
        tracep->declBit(c+1226,"SimTop if_axi_rw rw_ready_nxt", false,-1);
        tracep->declBit(c+1153,"SimTop if_axi_rw rw_ready_en", false,-1);
        tracep->declBus(c+69,"SimTop if_axi_rw rw_resp", false,-1, 1,0);
        tracep->declBit(c+1154,"SimTop if_axi_rw rw_resp_nxt", false,-1);
        tracep->declBit(c+1226,"SimTop if_axi_rw resp_en", false,-1);
        tracep->declQuad(c+1227,"SimTop if_axi_rw axi_r_data_l", false,-1, 63,0);
        tracep->declQuad(c+1155,"SimTop if_axi_rw axi_r_data_h", false,-1, 63,0);
        tracep->declBit(c+1355,"SimTop u_cpu clock", false,-1);
        tracep->declBit(c+1356,"SimTop u_cpu reset", false,-1);
        tracep->declBit(c+63,"SimTop u_cpu if_rw_valid", false,-1);
        tracep->declBit(c+64,"SimTop u_cpu if_rw_ready", false,-1);
        tracep->declQuad(c+65,"SimTop u_cpu if_r_data", false,-1, 63,0);
        tracep->declQuad(c+67,"SimTop u_cpu if_rw_addr", false,-1, 63,0);
        tracep->declBus(c+1495,"SimTop u_cpu if_rw_size", false,-1, 1,0);
        tracep->declBus(c+69,"SimTop u_cpu if_rw_resp", false,-1, 1,0);
        tracep->declBit(c+70,"SimTop u_cpu mem_rw_valid", false,-1);
        tracep->declBit(c+71,"SimTop u_cpu mem_rw_ready", false,-1);
        tracep->declBit(c+72,"SimTop u_cpu mem_rw_req", false,-1);
        tracep->declQuad(c+73,"SimTop u_cpu mem_r_data", false,-1, 63,0);
        tracep->declQuad(c+75,"SimTop u_cpu mem_w_data", false,-1, 63,0);
        tracep->declQuad(c+77,"SimTop u_cpu mem_rw_addr", false,-1, 63,0);
        tracep->declBus(c+79,"SimTop u_cpu mem_rw_size", false,-1, 1,0);
        tracep->declBus(c+80,"SimTop u_cpu mem_rw_resp", false,-1, 1,0);
        tracep->declBit(c+1365,"SimTop u_cpu uart_out_valid", false,-1);
        tracep->declBus(c+1366,"SimTop u_cpu uart_out_char", false,-1, 7,0);
        tracep->declBus(c+81,"SimTop u_cpu clint_interupt_bus", false,-1, 11,0);
        tracep->declBit(c+1229,"SimTop u_cpu if_to_id_valid", false,-1);
        tracep->declBit(c+1230,"SimTop u_cpu id_to_ex_valid", false,-1);
        tracep->declBit(c+174,"SimTop u_cpu ex_to_mem_valid", false,-1);
        tracep->declBit(c+175,"SimTop u_cpu mem_to_wb_valid", false,-1);
        tracep->declBit(c+176,"SimTop u_cpu id_allowin", false,-1);
        tracep->declBit(c+177,"SimTop u_cpu ex_allowin", false,-1);
        tracep->declBit(c+178,"SimTop u_cpu mem_allowin", false,-1);
        tracep->declBit(c+1489,"SimTop u_cpu wb_allowin", false,-1);
        tracep->declBit(c+179,"SimTop u_cpu ex_to_mem_handshake", false,-1);
        tracep->declQuad(c+180,"SimTop u_cpu if_to_id_pc", false,-1, 63,0);
        tracep->declQuad(c+182,"SimTop u_cpu id_to_ex_pc", false,-1, 63,0);
        tracep->declQuad(c+184,"SimTop u_cpu ex_to_mem_pc", false,-1, 63,0);
        tracep->declQuad(c+186,"SimTop u_cpu mem_to_wb_pc", false,-1, 63,0);
        tracep->declBus(c+188,"SimTop u_cpu if_to_id_inst", false,-1, 31,0);
        tracep->declBus(c+189,"SimTop u_cpu id_to_ex_inst", false,-1, 31,0);
        tracep->declBus(c+190,"SimTop u_cpu ex_to_mem_inst", false,-1, 31,0);
        tracep->declBus(c+191,"SimTop u_cpu mem_to_wb_inst", false,-1, 31,0);
        tracep->declArray(c+1451,"SimTop u_cpu id_to_ex_bus", false,-1, 343,0);
        tracep->declArray(c+1231,"SimTop u_cpu ex_to_mem_bus", false,-1, 222,0);
        tracep->declArray(c+192,"SimTop u_cpu mem_to_wb_bus", false,-1, 209,0);
        tracep->declArray(c+1238,"SimTop u_cpu csr_to_ex_diffbus", false,-1, 511,0);
        tracep->declBus(c+199,"SimTop u_cpu id_to_ex_diffbus", false,-1, 0,0);
        tracep->declArray(c+1157,"SimTop u_cpu ex_to_mem_diffbus", false,-1, 576,0);
        tracep->declArray(c+200,"SimTop u_cpu mem_to_wb_diffbus", false,-1, 714,0);
        tracep->declArray(c+223,"SimTop u_cpu difftest_bus", false,-1, 811,0);
        tracep->declArray(c+1254,"SimTop u_cpu bj_ctrl_bus", false,-1, 65,0);
        tracep->declArray(c+249,"SimTop u_cpu mem_forward_bus", false,-1, 72,0);
        tracep->declArray(c+252,"SimTop u_cpu wb_forward_bus", false,-1, 136,0);
        tracep->declBit(c+257,"SimTop u_cpu if_bj_ready", false,-1);
        tracep->declBit(c+258,"SimTop u_cpu csr_rd_ena", false,-1);
        tracep->declBus(c+259,"SimTop u_cpu csr_rd_addr", false,-1, 11,0);
        tracep->declQuad(c+1257,"SimTop u_cpu csr_rd_data", false,-1, 63,0);
        tracep->declBit(c+260,"SimTop u_cpu csr_wr_ena", false,-1);
        tracep->declBus(c+261,"SimTop u_cpu csr_wr_addr", false,-1, 11,0);
        tracep->declQuad(c+1259,"SimTop u_cpu csr_wr_data", false,-1, 63,0);
        tracep->declBit(c+262,"SimTop u_cpu excp_enter", false,-1);
        tracep->declBit(c+263,"SimTop u_cpu excp_exit", false,-1);
        tracep->declArray(c+264,"SimTop u_cpu csr_excp_rd_bus", false,-1, 319,0);
        tracep->declArray(c+1261,"SimTop u_cpu csr_excp_wr_bus", false,-1, 319,0);
        tracep->declBit(c+1489,"SimTop u_cpu rs1_r_ena", false,-1);
        tracep->declBus(c+274,"SimTop u_cpu rs1_r_addr", false,-1, 4,0);
        tracep->declQuad(c+1462,"SimTop u_cpu r_data1", false,-1, 63,0);
        tracep->declBit(c+1489,"SimTop u_cpu rs2_r_ena", false,-1);
        tracep->declBus(c+275,"SimTop u_cpu rs2_r_addr", false,-1, 4,0);
        tracep->declQuad(c+1464,"SimTop u_cpu r_data2", false,-1, 63,0);
        tracep->declBit(c+276,"SimTop u_cpu reg_wr_ena", false,-1);
        tracep->declBus(c+277,"SimTop u_cpu reg_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+1271,"SimTop u_cpu reg_wr_data", false,-1, 63,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+278+i*2,"SimTop u_cpu regs", true,(i+0), 63,0);}}
        tracep->declBit(c+342,"SimTop u_cpu cmt_wen", false,-1);
        tracep->declBus(c+343,"SimTop u_cpu cmt_wdest", false,-1, 7,0);
        tracep->declQuad(c+344,"SimTop u_cpu cmt_wdata", false,-1, 63,0);
        tracep->declQuad(c+346,"SimTop u_cpu cmt_pc", false,-1, 63,0);
        tracep->declBus(c+348,"SimTop u_cpu cmt_inst", false,-1, 31,0);
        tracep->declBit(c+349,"SimTop u_cpu cmt_valid", false,-1);
        tracep->declBit(c+350,"SimTop u_cpu cmt_skip", false,-1);
        tracep->declBus(c+351,"SimTop u_cpu cmt_itrp_NO", false,-1, 31,0);
        tracep->declBus(c+352,"SimTop u_cpu cmt_excp_NO", false,-1, 31,0);
        tracep->declQuad(c+353,"SimTop u_cpu cycleCnt", false,-1, 63,0);
        tracep->declQuad(c+355,"SimTop u_cpu instrCnt", false,-1, 63,0);
        tracep->declQuad(c+357,"SimTop u_cpu wb_pc", false,-1, 63,0);
        tracep->declQuad(c+359,"SimTop u_cpu wb_rw_addr", false,-1, 63,0);
        tracep->declQuad(c+361,"SimTop u_cpu wb_w_data", false,-1, 63,0);
        tracep->declBus(c+363,"SimTop u_cpu wb_inst", false,-1, 31,0);
        tracep->declBit(c+364,"SimTop u_cpu wb_commit", false,-1);
        tracep->declBit(c+365,"SimTop u_cpu wb_w_ena", false,-1);
        tracep->declBit(c+366,"SimTop u_cpu wb_r_ena", false,-1);
        tracep->declBit(c+367,"SimTop u_cpu wb_skip", false,-1);
        tracep->declBus(c+368,"SimTop u_cpu wb_w_mask", false,-1, 7,0);
        tracep->declBus(c+369,"SimTop u_cpu wb_itrp_NO", false,-1, 31,0);
        tracep->declBus(c+370,"SimTop u_cpu wb_excp_NO", false,-1, 31,0);
        tracep->declArray(c+371,"SimTop u_cpu wb_csr_diff", false,-1, 511,0);
        tracep->declQuad(c+387,"SimTop u_cpu wb_mstatus", false,-1, 63,0);
        tracep->declQuad(c+389,"SimTop u_cpu wb_mepc", false,-1, 63,0);
        tracep->declQuad(c+391,"SimTop u_cpu wb_mtval", false,-1, 63,0);
        tracep->declQuad(c+393,"SimTop u_cpu wb_mtvec", false,-1, 63,0);
        tracep->declQuad(c+395,"SimTop u_cpu wb_mcause", false,-1, 63,0);
        tracep->declQuad(c+397,"SimTop u_cpu wb_mip", false,-1, 63,0);
        tracep->declQuad(c+399,"SimTop u_cpu wb_mie", false,-1, 63,0);
        tracep->declQuad(c+401,"SimTop u_cpu wb_mscratch", false,-1, 63,0);
        tracep->declQuad(c+403,"SimTop u_cpu cmt_mstatus", false,-1, 63,0);
        tracep->declQuad(c+405,"SimTop u_cpu cmt_mepc", false,-1, 63,0);
        tracep->declQuad(c+407,"SimTop u_cpu cmt_mtval", false,-1, 63,0);
        tracep->declQuad(c+409,"SimTop u_cpu cmt_mtvec", false,-1, 63,0);
        tracep->declQuad(c+411,"SimTop u_cpu cmt_mcause", false,-1, 63,0);
        tracep->declQuad(c+413,"SimTop u_cpu cmt_mip", false,-1, 63,0);
        tracep->declQuad(c+415,"SimTop u_cpu cmt_mie", false,-1, 63,0);
        tracep->declQuad(c+417,"SimTop u_cpu cmt_mscratch", false,-1, 63,0);
        tracep->declQuad(c+419,"SimTop u_cpu cmt_rw_addr", false,-1, 63,0);
        tracep->declQuad(c+421,"SimTop u_cpu cmt_w_data", false,-1, 63,0);
        tracep->declQuad(c+423,"SimTop u_cpu buf_rw_addr", false,-1, 63,0);
        tracep->declQuad(c+425,"SimTop u_cpu buf_w_data", false,-1, 63,0);
        tracep->declBus(c+427,"SimTop u_cpu cmt_w_mask", false,-1, 7,0);
        tracep->declBus(c+428,"SimTop u_cpu buf_w_mask", false,-1, 7,0);
        tracep->declBit(c+429,"SimTop u_cpu cmt_w_ena", false,-1);
        tracep->declBit(c+430,"SimTop u_cpu cmt_r_ena", false,-1);
        tracep->declBit(c+431,"SimTop u_cpu buf_w_ena", false,-1);
        tracep->declBit(c+432,"SimTop u_cpu buf_r_ena", false,-1);
        tracep->declBit(c+1355,"SimTop u_cpu If_stage clk", false,-1);
        tracep->declBit(c+1356,"SimTop u_cpu If_stage rst", false,-1);
        tracep->declBit(c+1229,"SimTop u_cpu If_stage if_to_id_valid", false,-1);
        tracep->declQuad(c+180,"SimTop u_cpu If_stage if_to_id_pc", false,-1, 63,0);
        tracep->declBus(c+188,"SimTop u_cpu If_stage if_to_id_inst", false,-1, 31,0);
        tracep->declBit(c+176,"SimTop u_cpu If_stage id_allowin", false,-1);
        tracep->declBit(c+257,"SimTop u_cpu If_stage if_bj_ready", false,-1);
        tracep->declArray(c+1254,"SimTop u_cpu If_stage bj_ctrl_bus", false,-1, 65,0);
        tracep->declBit(c+63,"SimTop u_cpu If_stage if_axi_valid", false,-1);
        tracep->declBit(c+64,"SimTop u_cpu If_stage if_axi_ready", false,-1);
        tracep->declQuad(c+65,"SimTop u_cpu If_stage if_axi_data_read", false,-1, 63,0);
        tracep->declQuad(c+67,"SimTop u_cpu If_stage if_axi_addr", false,-1, 63,0);
        tracep->declBus(c+1495,"SimTop u_cpu If_stage if_axi_size", false,-1, 1,0);
        tracep->declBus(c+69,"SimTop u_cpu If_stage if_axi_resp", false,-1, 1,0);
        tracep->declQuad(c+1273,"SimTop u_cpu If_stage bj_pc", false,-1, 63,0);
        tracep->declBit(c+1275,"SimTop u_cpu If_stage bj_ena", false,-1);
        tracep->declBit(c+1276,"SimTop u_cpu If_stage bj_valid", false,-1);
        tracep->declBit(c+1489,"SimTop u_cpu If_stage pre_valid", false,-1);
        tracep->declBit(c+433,"SimTop u_cpu If_stage pre_ready_go", false,-1);
        tracep->declBit(c+433,"SimTop u_cpu If_stage pre_to_if_valid", false,-1);
        tracep->declQuad(c+1176,"SimTop u_cpu If_stage next_pc", false,-1, 63,0);
        tracep->declBit(c+1466,"SimTop u_cpu If_stage if_handshake", false,-1);
        tracep->declBit(c+1467,"SimTop u_cpu If_stage bj_handshake", false,-1);
        tracep->declBus(c+1490,"SimTop u_cpu If_stage IDLE", false,-1, 1,0);
        tracep->declBus(c+1486,"SimTop u_cpu If_stage ADDR", false,-1, 1,0);
        tracep->declBus(c+1495,"SimTop u_cpu If_stage RETN", false,-1, 1,0);
        tracep->declBus(c+434,"SimTop u_cpu If_stage if_state", false,-1, 1,0);
        tracep->declBus(c+1277,"SimTop u_cpu If_stage if_next_state", false,-1, 1,0);
        tracep->declBit(c+435,"SimTop u_cpu If_stage if_valid", false,-1);
        tracep->declBit(c+1489,"SimTop u_cpu If_stage if_ready_go", false,-1);
        tracep->declBit(c+1275,"SimTop u_cpu If_stage if_flush", false,-1);
        tracep->declBit(c+436,"SimTop u_cpu If_stage if_allowin", false,-1);
        tracep->declQuad(c+180,"SimTop u_cpu If_stage if_pc", false,-1, 63,0);
        tracep->declBus(c+188,"SimTop u_cpu If_stage if_inst", false,-1, 31,0);
        tracep->declBit(c+1356,"SimTop u_cpu Id_stage rst", false,-1);
        tracep->declBit(c+1355,"SimTop u_cpu Id_stage clk", false,-1);
        tracep->declBit(c+1229,"SimTop u_cpu Id_stage if_to_id_valid", false,-1);
        tracep->declQuad(c+180,"SimTop u_cpu Id_stage if_to_id_pc", false,-1, 63,0);
        tracep->declBus(c+188,"SimTop u_cpu Id_stage if_to_id_inst", false,-1, 31,0);
        tracep->declBit(c+176,"SimTop u_cpu Id_stage id_allowin", false,-1);
        tracep->declBit(c+1230,"SimTop u_cpu Id_stage id_to_ex_valid", false,-1);
        tracep->declQuad(c+182,"SimTop u_cpu Id_stage id_to_ex_pc", false,-1, 63,0);
        tracep->declBus(c+189,"SimTop u_cpu Id_stage id_to_ex_inst", false,-1, 31,0);
        tracep->declArray(c+1451,"SimTop u_cpu Id_stage id_to_ex_bus", false,-1, 343,0);
        tracep->declBit(c+177,"SimTop u_cpu Id_stage ex_allowin", false,-1);
        tracep->declQuad(c+1257,"SimTop u_cpu Id_stage csr_data", false,-1, 63,0);
        tracep->declBit(c+258,"SimTop u_cpu Id_stage csr_rd_ena", false,-1);
        tracep->declBus(c+259,"SimTop u_cpu Id_stage csr_rd_addr", false,-1, 11,0);
        tracep->declArray(c+1254,"SimTop u_cpu Id_stage bj_ctrl_bus", false,-1, 65,0);
        tracep->declBus(c+199,"SimTop u_cpu Id_stage id_to_ex_diffbus", false,-1, 0,0);
        tracep->declBit(c+1468,"SimTop u_cpu Id_stage rs1_r_ena", false,-1);
        tracep->declBus(c+1469,"SimTop u_cpu Id_stage rs1_addr", false,-1, 4,0);
        tracep->declBit(c+1470,"SimTop u_cpu Id_stage rs2_r_ena", false,-1);
        tracep->declBus(c+1471,"SimTop u_cpu Id_stage rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+1273,"SimTop u_cpu Id_stage bj_pc", false,-1, 63,0);
        tracep->declBit(c+1275,"SimTop u_cpu Id_stage bj_ena", false,-1);
        tracep->declBit(c+1276,"SimTop u_cpu Id_stage bj_valid", false,-1);
        tracep->declBit(c+437,"SimTop u_cpu Id_stage id_valid", false,-1);
        tracep->declBit(c+1489,"SimTop u_cpu Id_stage id_ready_go", false,-1);
        tracep->declBit(c+1278,"SimTop u_cpu Id_stage id_flush", false,-1);
        tracep->declQuad(c+182,"SimTop u_cpu Id_stage if_to_id_pc_r", false,-1, 63,0);
        tracep->declBus(c+189,"SimTop u_cpu Id_stage if_to_id_inst_r", false,-1, 31,0);
        tracep->declQuad(c+182,"SimTop u_cpu Id_stage id_pc", false,-1, 63,0);
        tracep->declBus(c+189,"SimTop u_cpu Id_stage id_inst", false,-1, 31,0);
        tracep->declBus(c+438,"SimTop u_cpu Id_stage opcode", false,-1, 6,0);
        tracep->declBus(c+439,"SimTop u_cpu Id_stage func3", false,-1, 2,0);
        tracep->declBus(c+440,"SimTop u_cpu Id_stage func6", false,-1, 5,0);
        tracep->declBus(c+441,"SimTop u_cpu Id_stage func7", false,-1, 6,0);
        tracep->declBus(c+442,"SimTop u_cpu Id_stage zimm", false,-1, 4,0);
        tracep->declBus(c+259,"SimTop u_cpu Id_stage id_csr_addr", false,-1, 11,0);
        tracep->declBus(c+443,"SimTop u_cpu Id_stage rd_addr", false,-1, 4,0);
        tracep->declBus(c+259,"SimTop u_cpu Id_stage immI", false,-1, 11,0);
        tracep->declBus(c+444,"SimTop u_cpu Id_stage immS", false,-1, 11,0);
        tracep->declBus(c+445,"SimTop u_cpu Id_stage immB", false,-1, 12,0);
        tracep->declBus(c+446,"SimTop u_cpu Id_stage immU", false,-1, 19,0);
        tracep->declBus(c+447,"SimTop u_cpu Id_stage immJ", false,-1, 20,0);
        tracep->declBit(c+448,"SimTop u_cpu Id_stage func3_0", false,-1);
        tracep->declBit(c+449,"SimTop u_cpu Id_stage func3_1", false,-1);
        tracep->declBit(c+450,"SimTop u_cpu Id_stage func3_2", false,-1);
        tracep->declBit(c+451,"SimTop u_cpu Id_stage func3_3", false,-1);
        tracep->declBit(c+452,"SimTop u_cpu Id_stage func3_4", false,-1);
        tracep->declBit(c+453,"SimTop u_cpu Id_stage func3_5", false,-1);
        tracep->declBit(c+454,"SimTop u_cpu Id_stage func3_6", false,-1);
        tracep->declBit(c+455,"SimTop u_cpu Id_stage func3_7", false,-1);
        tracep->declBit(c+456,"SimTop u_cpu Id_stage func6_00", false,-1);
        tracep->declBit(c+457,"SimTop u_cpu Id_stage func6_10", false,-1);
        tracep->declBit(c+458,"SimTop u_cpu Id_stage func7_00", false,-1);
        tracep->declBit(c+459,"SimTop u_cpu Id_stage func7_20", false,-1);
        tracep->declBit(c+460,"SimTop u_cpu Id_stage imm12_000", false,-1);
        tracep->declBit(c+461,"SimTop u_cpu Id_stage imm12_001", false,-1);
        tracep->declBit(c+462,"SimTop u_cpu Id_stage imm12_302", false,-1);
        tracep->declBit(c+463,"SimTop u_cpu Id_stage inst_i_load", false,-1);
        tracep->declBit(c+464,"SimTop u_cpu Id_stage inst_i_fence", false,-1);
        tracep->declBit(c+465,"SimTop u_cpu Id_stage inst_i_arith_dword", false,-1);
        tracep->declBit(c+466,"SimTop u_cpu Id_stage inst_u_auipc", false,-1);
        tracep->declBit(c+467,"SimTop u_cpu Id_stage inst_i_arith_word", false,-1);
        tracep->declBit(c+468,"SimTop u_cpu Id_stage inst_s", false,-1);
        tracep->declBit(c+469,"SimTop u_cpu Id_stage inst_r_dword", false,-1);
        tracep->declBit(c+470,"SimTop u_cpu Id_stage inst_u_lui", false,-1);
        tracep->declBit(c+471,"SimTop u_cpu Id_stage inst_r_word", false,-1);
        tracep->declBit(c+472,"SimTop u_cpu Id_stage inst_b", false,-1);
        tracep->declBit(c+473,"SimTop u_cpu Id_stage inst_i_jalr", false,-1);
        tracep->declBit(c+474,"SimTop u_cpu Id_stage inst_j", false,-1);
        tracep->declBit(c+475,"SimTop u_cpu Id_stage inst_i_sys", false,-1);
        tracep->declBit(c+476,"SimTop u_cpu Id_stage inst_i_excp", false,-1);
        tracep->declBit(c+477,"SimTop u_cpu Id_stage inst_i_csr_imm", false,-1);
        tracep->declBit(c+478,"SimTop u_cpu Id_stage inst_i_csr_reg", false,-1);
        tracep->declBit(c+479,"SimTop u_cpu Id_stage inst_putch", false,-1);
        tracep->declBit(c+480,"SimTop u_cpu Id_stage is_word_opt", false,-1);
        tracep->declBit(c+481,"SimTop u_cpu Id_stage inst_lb", false,-1);
        tracep->declBit(c+482,"SimTop u_cpu Id_stage inst_lh", false,-1);
        tracep->declBit(c+483,"SimTop u_cpu Id_stage inst_lw", false,-1);
        tracep->declBit(c+484,"SimTop u_cpu Id_stage inst_ld", false,-1);
        tracep->declBit(c+485,"SimTop u_cpu Id_stage inst_lbu", false,-1);
        tracep->declBit(c+486,"SimTop u_cpu Id_stage inst_lhu", false,-1);
        tracep->declBit(c+487,"SimTop u_cpu Id_stage inst_lwu", false,-1);
        tracep->declBit(c+488,"SimTop u_cpu Id_stage load_vld", false,-1);
        tracep->declBit(c+489,"SimTop u_cpu Id_stage inst_fence", false,-1);
        tracep->declBit(c+490,"SimTop u_cpu Id_stage inst_fence_i", false,-1);
        tracep->declBit(c+491,"SimTop u_cpu Id_stage fence_vld", false,-1);
        tracep->declBit(c+492,"SimTop u_cpu Id_stage inst_addi", false,-1);
        tracep->declBit(c+493,"SimTop u_cpu Id_stage inst_slli", false,-1);
        tracep->declBit(c+494,"SimTop u_cpu Id_stage inst_slti", false,-1);
        tracep->declBit(c+495,"SimTop u_cpu Id_stage inst_sltiu", false,-1);
        tracep->declBit(c+496,"SimTop u_cpu Id_stage inst_xori", false,-1);
        tracep->declBit(c+497,"SimTop u_cpu Id_stage inst_srli", false,-1);
        tracep->declBit(c+498,"SimTop u_cpu Id_stage inst_srai", false,-1);
        tracep->declBit(c+499,"SimTop u_cpu Id_stage inst_ori", false,-1);
        tracep->declBit(c+500,"SimTop u_cpu Id_stage inst_andi", false,-1);
        tracep->declBit(c+501,"SimTop u_cpu Id_stage arith_id_vld", false,-1);
        tracep->declBit(c+466,"SimTop u_cpu Id_stage inst_auipc", false,-1);
        tracep->declBit(c+466,"SimTop u_cpu Id_stage auipc_vld", false,-1);
        tracep->declBit(c+502,"SimTop u_cpu Id_stage inst_addiw", false,-1);
        tracep->declBit(c+503,"SimTop u_cpu Id_stage inst_slliw", false,-1);
        tracep->declBit(c+504,"SimTop u_cpu Id_stage inst_srliw", false,-1);
        tracep->declBit(c+505,"SimTop u_cpu Id_stage inst_sraiw", false,-1);
        tracep->declBit(c+506,"SimTop u_cpu Id_stage arith_iw_vld", false,-1);
        tracep->declBit(c+507,"SimTop u_cpu Id_stage inst_sb", false,-1);
        tracep->declBit(c+508,"SimTop u_cpu Id_stage inst_sh", false,-1);
        tracep->declBit(c+509,"SimTop u_cpu Id_stage inst_sw", false,-1);
        tracep->declBit(c+510,"SimTop u_cpu Id_stage inst_sd", false,-1);
        tracep->declBit(c+511,"SimTop u_cpu Id_stage store_vld", false,-1);
        tracep->declBit(c+512,"SimTop u_cpu Id_stage inst_add", false,-1);
        tracep->declBit(c+513,"SimTop u_cpu Id_stage inst_sub", false,-1);
        tracep->declBit(c+514,"SimTop u_cpu Id_stage inst_sll", false,-1);
        tracep->declBit(c+515,"SimTop u_cpu Id_stage inst_slt", false,-1);
        tracep->declBit(c+516,"SimTop u_cpu Id_stage inst_sltu", false,-1);
        tracep->declBit(c+517,"SimTop u_cpu Id_stage inst_xor", false,-1);
        tracep->declBit(c+518,"SimTop u_cpu Id_stage inst_srl", false,-1);
        tracep->declBit(c+519,"SimTop u_cpu Id_stage inst_sra", false,-1);
        tracep->declBit(c+520,"SimTop u_cpu Id_stage inst_or", false,-1);
        tracep->declBit(c+521,"SimTop u_cpu Id_stage inst_and", false,-1);
        tracep->declBit(c+522,"SimTop u_cpu Id_stage arith_rd_vld", false,-1);
        tracep->declBit(c+470,"SimTop u_cpu Id_stage inst_lui", false,-1);
        tracep->declBit(c+470,"SimTop u_cpu Id_stage lui_vld", false,-1);
        tracep->declBit(c+523,"SimTop u_cpu Id_stage inst_addw", false,-1);
        tracep->declBit(c+524,"SimTop u_cpu Id_stage inst_subw", false,-1);
        tracep->declBit(c+525,"SimTop u_cpu Id_stage inst_sllw", false,-1);
        tracep->declBit(c+526,"SimTop u_cpu Id_stage inst_srlw", false,-1);
        tracep->declBit(c+527,"SimTop u_cpu Id_stage inst_sraw", false,-1);
        tracep->declBit(c+528,"SimTop u_cpu Id_stage arith_rw_vld", false,-1);
        tracep->declBit(c+529,"SimTop u_cpu Id_stage inst_beq", false,-1);
        tracep->declBit(c+530,"SimTop u_cpu Id_stage inst_bne", false,-1);
        tracep->declBit(c+531,"SimTop u_cpu Id_stage inst_blt", false,-1);
        tracep->declBit(c+532,"SimTop u_cpu Id_stage inst_bge", false,-1);
        tracep->declBit(c+533,"SimTop u_cpu Id_stage inst_bltu", false,-1);
        tracep->declBit(c+534,"SimTop u_cpu Id_stage inst_bgeu", false,-1);
        tracep->declBit(c+535,"SimTop u_cpu Id_stage branch_vld", false,-1);
        tracep->declBit(c+473,"SimTop u_cpu Id_stage inst_jalr", false,-1);
        tracep->declBit(c+474,"SimTop u_cpu Id_stage inst_jal", false,-1);
        tracep->declBit(c+536,"SimTop u_cpu Id_stage jump_vld", false,-1);
        tracep->declBit(c+537,"SimTop u_cpu Id_stage inst_ecall", false,-1);
        tracep->declBit(c+538,"SimTop u_cpu Id_stage inst_ebreak", false,-1);
        tracep->declBit(c+539,"SimTop u_cpu Id_stage inst_mret", false,-1);
        tracep->declBit(c+540,"SimTop u_cpu Id_stage excp_vld", false,-1);
        tracep->declBit(c+541,"SimTop u_cpu Id_stage inst_csrrw", false,-1);
        tracep->declBit(c+542,"SimTop u_cpu Id_stage inst_csrrs", false,-1);
        tracep->declBit(c+543,"SimTop u_cpu Id_stage inst_csrrc", false,-1);
        tracep->declBit(c+544,"SimTop u_cpu Id_stage inst_csrrwi", false,-1);
        tracep->declBit(c+545,"SimTop u_cpu Id_stage inst_csrrsi", false,-1);
        tracep->declBit(c+546,"SimTop u_cpu Id_stage inst_csrrci", false,-1);
        tracep->declBit(c+258,"SimTop u_cpu Id_stage csr_vld", false,-1);
        tracep->declBit(c+547,"SimTop u_cpu Id_stage inst_vld", false,-1);
        tracep->declBus(c+548,"SimTop u_cpu Id_stage id_alu_info", false,-1, 11,0);
        tracep->declBus(c+549,"SimTop u_cpu Id_stage id_bj_info", false,-1, 7,0);
        tracep->declBus(c+550,"SimTop u_cpu Id_stage id_load_info", false,-1, 6,0);
        tracep->declBus(c+551,"SimTop u_cpu Id_stage id_save_info", false,-1, 3,0);
        tracep->declBus(c+1178,"SimTop u_cpu Id_stage reg_wr_addr", false,-1, 4,0);
        tracep->declBit(c+1472,"SimTop u_cpu Id_stage mem_wr_ena", false,-1);
        tracep->declBit(c+1473,"SimTop u_cpu Id_stage mem_rd_ena", false,-1);
        tracep->declQuad(c+1474,"SimTop u_cpu Id_stage id_op1", false,-1, 63,0);
        tracep->declBit(c+552,"SimTop u_cpu Id_stage id_use_rs1", false,-1);
        tracep->declQuad(c+1279,"SimTop u_cpu Id_stage id_op2", false,-1, 63,0);
        tracep->declBit(c+553,"SimTop u_cpu Id_stage id_use_rs2", false,-1);
        tracep->declBit(c+554,"SimTop u_cpu Id_stage id_use_csr", false,-1);
        tracep->declQuad(c+555,"SimTop u_cpu Id_stage id_jmp_imm", false,-1, 63,0);
        tracep->declBit(c+1476,"SimTop u_cpu Id_stage csr_to_reg", false,-1);
        tracep->declBit(c+1473,"SimTop u_cpu Id_stage mem_to_reg", false,-1);
        tracep->declBit(c+1477,"SimTop u_cpu Id_stage exe_to_reg", false,-1);
        tracep->declBus(c+1478,"SimTop u_cpu Id_stage reg_wr_ctrl", false,-1, 2,0);
        tracep->declBit(c+1281,"SimTop u_cpu Id_stage reg_wr_ena", false,-1);
        tracep->declBit(c+1476,"SimTop u_cpu Id_stage csr_wr_ena", false,-1);
        tracep->declBus(c+259,"SimTop u_cpu Id_stage csr_wr_addr", false,-1, 11,0);
        tracep->declBus(c+557,"SimTop u_cpu Id_stage id_excp_bus", false,-1, 15,0);
        tracep->declBit(c+539,"SimTop u_cpu Id_stage id_excp_exit", false,-1);
        tracep->declBit(c+479,"SimTop u_cpu Id_stage id_uart_out_valid", false,-1);
        tracep->declBit(c+199,"SimTop u_cpu Id_stage id_skip_instr", false,-1);
        tracep->declBit(c+1355,"SimTop u_cpu Ex_stage clk", false,-1);
        tracep->declBit(c+1356,"SimTop u_cpu Ex_stage rst", false,-1);
        tracep->declBit(c+1230,"SimTop u_cpu Ex_stage id_to_ex_valid", false,-1);
        tracep->declQuad(c+182,"SimTop u_cpu Ex_stage id_to_ex_pc", false,-1, 63,0);
        tracep->declBus(c+189,"SimTop u_cpu Ex_stage id_to_ex_inst", false,-1, 31,0);
        tracep->declArray(c+1451,"SimTop u_cpu Ex_stage id_to_ex_bus", false,-1, 343,0);
        tracep->declBit(c+177,"SimTop u_cpu Ex_stage ex_allowin", false,-1);
        tracep->declBit(c+174,"SimTop u_cpu Ex_stage ex_to_mem_valid", false,-1);
        tracep->declQuad(c+184,"SimTop u_cpu Ex_stage ex_to_mem_pc", false,-1, 63,0);
        tracep->declBus(c+190,"SimTop u_cpu Ex_stage ex_to_mem_inst", false,-1, 31,0);
        tracep->declArray(c+1231,"SimTop u_cpu Ex_stage ex_to_mem_bus", false,-1, 222,0);
        tracep->declBit(c+178,"SimTop u_cpu Ex_stage mem_allowin", false,-1);
        tracep->declArray(c+249,"SimTop u_cpu Ex_stage mem_forward_bus", false,-1, 72,0);
        tracep->declArray(c+252,"SimTop u_cpu Ex_stage wb_forward_bus", false,-1, 136,0);
        tracep->declBit(c+257,"SimTop u_cpu Ex_stage if_bj_ready", false,-1);
        tracep->declArray(c+1254,"SimTop u_cpu Ex_stage bj_ctrl_bus", false,-1, 65,0);
        tracep->declBit(c+179,"SimTop u_cpu Ex_stage csr_wr_clk", false,-1);
        tracep->declBit(c+260,"SimTop u_cpu Ex_stage csr_wr_ena", false,-1);
        tracep->declBus(c+261,"SimTop u_cpu Ex_stage csr_wr_addr", false,-1, 11,0);
        tracep->declQuad(c+1259,"SimTop u_cpu Ex_stage csr_wr_data", false,-1, 63,0);
        tracep->declBit(c+262,"SimTop u_cpu Ex_stage excp_enter", false,-1);
        tracep->declBit(c+263,"SimTop u_cpu Ex_stage excp_exit", false,-1);
        tracep->declArray(c+264,"SimTop u_cpu Ex_stage csr_excp_rd_bus", false,-1, 319,0);
        tracep->declArray(c+1261,"SimTop u_cpu Ex_stage csr_excp_wr_bus", false,-1, 319,0);
        tracep->declBus(c+81,"SimTop u_cpu Ex_stage clint_interupt_bus", false,-1, 11,0);
        tracep->declBit(c+1489,"SimTop u_cpu Ex_stage ex_rs1_r_ena", false,-1);
        tracep->declBus(c+274,"SimTop u_cpu Ex_stage ex_rs1_addr", false,-1, 4,0);
        tracep->declBit(c+1489,"SimTop u_cpu Ex_stage ex_rs2_r_ena", false,-1);
        tracep->declBus(c+275,"SimTop u_cpu Ex_stage ex_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+1462,"SimTop u_cpu Ex_stage rs1_data", false,-1, 63,0);
        tracep->declQuad(c+1464,"SimTop u_cpu Ex_stage rs2_data", false,-1, 63,0);
        tracep->declBus(c+199,"SimTop u_cpu Ex_stage id_to_ex_diffbus", false,-1, 0,0);
        tracep->declArray(c+1238,"SimTop u_cpu Ex_stage csr_to_ex_diffbus", false,-1, 511,0);
        tracep->declArray(c+1157,"SimTop u_cpu Ex_stage ex_to_mem_diffbus", false,-1, 576,0);
        tracep->declBit(c+558,"SimTop u_cpu Ex_stage ex_valid", false,-1);
        tracep->declBit(c+559,"SimTop u_cpu Ex_stage ex_ready_go", false,-1);
        tracep->declQuad(c+184,"SimTop u_cpu Ex_stage id_to_ex_pc_r", false,-1, 63,0);
        tracep->declBus(c+190,"SimTop u_cpu Ex_stage id_to_ex_inst_r", false,-1, 31,0);
        tracep->declArray(c+560,"SimTop u_cpu Ex_stage id_to_ex_bus_r", false,-1, 343,0);
        tracep->declBus(c+571,"SimTop u_cpu Ex_stage id_to_ex_diffbus_r", false,-1, 0,0);
        tracep->declBit(c+572,"SimTop u_cpu Ex_stage itrp_valid", false,-1);
        tracep->declBit(c+573,"SimTop u_cpu Ex_stage ex_done", false,-1);
        tracep->declBit(c+574,"SimTop u_cpu Ex_stage bj_handshake", false,-1);
        tracep->declBit(c+575,"SimTop u_cpu Ex_stage ex_uart_out_valid", false,-1);
        tracep->declBus(c+1282,"SimTop u_cpu Ex_stage ex_uart_out_char", false,-1, 7,0);
        tracep->declBus(c+190,"SimTop u_cpu Ex_stage ex_inst", false,-1, 31,0);
        tracep->declQuad(c+184,"SimTop u_cpu Ex_stage ex_pc", false,-1, 63,0);
        tracep->declQuad(c+576,"SimTop u_cpu Ex_stage ex_op1", false,-1, 63,0);
        tracep->declQuad(c+578,"SimTop u_cpu Ex_stage ex_op2", false,-1, 63,0);
        tracep->declBit(c+580,"SimTop u_cpu Ex_stage ex_use_rs1", false,-1);
        tracep->declBit(c+581,"SimTop u_cpu Ex_stage ex_use_rs2", false,-1);
        tracep->declBit(c+582,"SimTop u_cpu Ex_stage ex_is_word_opt", false,-1);
        tracep->declBus(c+583,"SimTop u_cpu Ex_stage ex_alu_info", false,-1, 11,0);
        tracep->declBus(c+584,"SimTop u_cpu Ex_stage ex_bj_info", false,-1, 7,0);
        tracep->declQuad(c+585,"SimTop u_cpu Ex_stage ex_jmp_imm", false,-1, 63,0);
        tracep->declBus(c+587,"SimTop u_cpu Ex_stage ex_load_info", false,-1, 6,0);
        tracep->declBus(c+588,"SimTop u_cpu Ex_stage ex_save_info", false,-1, 3,0);
        tracep->declBit(c+589,"SimTop u_cpu Ex_stage ex_ram_rd_ena", false,-1);
        tracep->declBit(c+590,"SimTop u_cpu Ex_stage ex_ram_wr_ena", false,-1);
        tracep->declBus(c+591,"SimTop u_cpu Ex_stage ex_reg_wr_ctrl", false,-1, 2,0);
        tracep->declBit(c+592,"SimTop u_cpu Ex_stage ex_reg_wr_ena", false,-1);
        tracep->declBit(c+260,"SimTop u_cpu Ex_stage ex_csr_wr_ena", false,-1);
        tracep->declBus(c+593,"SimTop u_cpu Ex_stage ex_reg_wr_addr", false,-1, 4,0);
        tracep->declBus(c+261,"SimTop u_cpu Ex_stage ex_csr_wr_addr", false,-1, 11,0);
        tracep->declQuad(c+594,"SimTop u_cpu Ex_stage ex_csr_rd_data", false,-1, 63,0);
        tracep->declBit(c+596,"SimTop u_cpu Ex_stage hazard", false,-1);
        tracep->declBus(c+597,"SimTop u_cpu Ex_stage ex_excp_bus", false,-1, 15,0);
        tracep->declBit(c+598,"SimTop u_cpu Ex_stage itrp_allowin", false,-1);
        tracep->declBit(c+263,"SimTop u_cpu Ex_stage ex_excp_exit", false,-1);
        tracep->declBit(c+262,"SimTop u_cpu Ex_stage ex_excp_enter", false,-1);
        tracep->declQuad(c+1283,"SimTop u_cpu Ex_stage rs1_forward", false,-1, 63,0);
        tracep->declQuad(c+1285,"SimTop u_cpu Ex_stage rs2_forward", false,-1, 63,0);
        tracep->declQuad(c+1287,"SimTop u_cpu Ex_stage true_op1", false,-1, 63,0);
        tracep->declQuad(c+1289,"SimTop u_cpu Ex_stage true_op2", false,-1, 63,0);
        tracep->declQuad(c+1291,"SimTop u_cpu Ex_stage op1", false,-1, 63,0);
        tracep->declQuad(c+1293,"SimTop u_cpu Ex_stage op2", false,-1, 63,0);
        tracep->declBus(c+1295,"SimTop u_cpu Ex_stage ex_bj_data", false,-1, 7,0);
        tracep->declQuad(c+1285,"SimTop u_cpu Ex_stage ex_ram_wr_src", false,-1, 63,0);
        tracep->declQuad(c+1259,"SimTop u_cpu Ex_stage ex_data", false,-1, 63,0);
        tracep->declQuad(c+1179,"SimTop u_cpu Ex_stage ex_bj_pc", false,-1, 63,0);
        tracep->declQuad(c+599,"SimTop u_cpu Ex_stage excp_jmp_pc", false,-1, 63,0);
        tracep->declBit(c+1479,"SimTop u_cpu Ex_stage ex_bj_ena", false,-1);
        tracep->declBit(c+601,"SimTop u_cpu Ex_stage excp_jmp_ena", false,-1);
        tracep->declBit(c+602,"SimTop u_cpu Ex_stage ex_bj_valid", false,-1);
        tracep->declBus(c+603,"SimTop u_cpu Ex_stage itrp_NO", false,-1, 31,0);
        tracep->declBus(c+604,"SimTop u_cpu Ex_stage excp_NO", false,-1, 31,0);
        tracep->declBus(c+274,"SimTop u_cpu Ex_stage Forward ex_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+275,"SimTop u_cpu Ex_stage Forward ex_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+1462,"SimTop u_cpu Ex_stage Forward ex_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+1464,"SimTop u_cpu Ex_stage Forward ex_rs2_data", false,-1, 63,0);
        tracep->declBit(c+580,"SimTop u_cpu Ex_stage Forward ex_use_rs1", false,-1);
        tracep->declBit(c+581,"SimTop u_cpu Ex_stage Forward ex_use_rs2", false,-1);
        tracep->declArray(c+249,"SimTop u_cpu Ex_stage Forward mem_forward_bus", false,-1, 72,0);
        tracep->declArray(c+252,"SimTop u_cpu Ex_stage Forward wb_forward_bus", false,-1, 136,0);
        tracep->declQuad(c+1283,"SimTop u_cpu Ex_stage Forward rs1_forward", false,-1, 63,0);
        tracep->declQuad(c+1285,"SimTop u_cpu Ex_stage Forward rs2_forward", false,-1, 63,0);
        tracep->declBit(c+596,"SimTop u_cpu Ex_stage Forward hazard", false,-1);
        tracep->declBus(c+605,"SimTop u_cpu Ex_stage Forward mem_reg_wr_addr", false,-1, 4,0);
        tracep->declBus(c+606,"SimTop u_cpu Ex_stage Forward wb_reg_wr_addr", false,-1, 4,0);
        tracep->declBit(c+607,"SimTop u_cpu Ex_stage Forward mem_reg_wr_ena", false,-1);
        tracep->declBit(c+608,"SimTop u_cpu Ex_stage Forward wb_reg_wr_ena", false,-1);
        tracep->declQuad(c+609,"SimTop u_cpu Ex_stage Forward mem_ex_data", false,-1, 63,0);
        tracep->declQuad(c+611,"SimTop u_cpu Ex_stage Forward wb_ex_data", false,-1, 63,0);
        tracep->declQuad(c+613,"SimTop u_cpu Ex_stage Forward wb_mem_data", false,-1, 63,0);
        tracep->declBus(c+615,"SimTop u_cpu Ex_stage Forward mem_reg_wr_ctrl", false,-1, 2,0);
        tracep->declBus(c+616,"SimTop u_cpu Ex_stage Forward wb_reg_wr_ctrl", false,-1, 2,0);
        tracep->declBit(c+617,"SimTop u_cpu Ex_stage Forward mem_op1_src_ex", false,-1);
        tracep->declBit(c+618,"SimTop u_cpu Ex_stage Forward wb_op1_src_ex", false,-1);
        tracep->declBit(c+619,"SimTop u_cpu Ex_stage Forward mem_op1_src_mem", false,-1);
        tracep->declBit(c+620,"SimTop u_cpu Ex_stage Forward wb_op1_src_mem", false,-1);
        tracep->declBit(c+621,"SimTop u_cpu Ex_stage Forward test_eq", false,-1);
        tracep->declBit(c+607,"SimTop u_cpu Ex_stage Forward test_wr_ena", false,-1);
        tracep->declBit(c+622,"SimTop u_cpu Ex_stage Forward test_rs1", false,-1);
        tracep->declBit(c+623,"SimTop u_cpu Ex_stage Forward test_wr_src", false,-1);
        tracep->declBit(c+624,"SimTop u_cpu Ex_stage Forward mem_op2_src_ex", false,-1);
        tracep->declBit(c+625,"SimTop u_cpu Ex_stage Forward wb_op2_src_ex", false,-1);
        tracep->declBit(c+626,"SimTop u_cpu Ex_stage Forward mem_op2_src_mem", false,-1);
        tracep->declBit(c+627,"SimTop u_cpu Ex_stage Forward wb_op2_src_mem", false,-1);
        tracep->declBus(c+597,"SimTop u_cpu Ex_stage Excp_handler excp_info", false,-1, 15,0);
        tracep->declBus(c+81,"SimTop u_cpu Ex_stage Excp_handler itrp_info", false,-1, 11,0);
        tracep->declQuad(c+184,"SimTop u_cpu Ex_stage Excp_handler now_pc", false,-1, 63,0);
        tracep->declBus(c+190,"SimTop u_cpu Ex_stage Excp_handler now_inst", false,-1, 31,0);
        tracep->declQuad(c+1259,"SimTop u_cpu Ex_stage Excp_handler mem_addr", false,-1, 63,0);
        tracep->declBit(c+263,"SimTop u_cpu Ex_stage Excp_handler excp_exit", false,-1);
        tracep->declBit(c+262,"SimTop u_cpu Ex_stage Excp_handler excp_enter", false,-1);
        tracep->declBit(c+598,"SimTop u_cpu Ex_stage Excp_handler itrp_allowin", false,-1);
        tracep->declArray(c+264,"SimTop u_cpu Ex_stage Excp_handler csr_excp_rd_bus", false,-1, 319,0);
        tracep->declArray(c+1261,"SimTop u_cpu Ex_stage Excp_handler csr_excp_wr_bus", false,-1, 319,0);
        tracep->declBit(c+601,"SimTop u_cpu Ex_stage Excp_handler excp_jmp_ena", false,-1);
        tracep->declQuad(c+599,"SimTop u_cpu Ex_stage Excp_handler excp_jmp_pc", false,-1, 63,0);
        tracep->declBit(c+572,"SimTop u_cpu Ex_stage Excp_handler itrp_valid", false,-1);
        tracep->declBus(c+603,"SimTop u_cpu Ex_stage Excp_handler itrp_NO", false,-1, 31,0);
        tracep->declBus(c+604,"SimTop u_cpu Ex_stage Excp_handler excp_NO", false,-1, 31,0);
        tracep->declQuad(c+628,"SimTop u_cpu Ex_stage Excp_handler mip_wr_data", false,-1, 63,0);
        tracep->declQuad(c+630,"SimTop u_cpu Ex_stage Excp_handler mcause_wr_data", false,-1, 63,0);
        tracep->declQuad(c+184,"SimTop u_cpu Ex_stage Excp_handler mepc_wr_data", false,-1, 63,0);
        tracep->declQuad(c+1181,"SimTop u_cpu Ex_stage Excp_handler mtval_wr_data", false,-1, 63,0);
        tracep->declQuad(c+632,"SimTop u_cpu Ex_stage Excp_handler mstatus_wr_data", false,-1, 63,0);
        tracep->declQuad(c+634,"SimTop u_cpu Ex_stage Excp_handler mstatus_rd_data", false,-1, 63,0);
        tracep->declQuad(c+636,"SimTop u_cpu Ex_stage Excp_handler mtvec_rd_data", false,-1, 63,0);
        tracep->declQuad(c+638,"SimTop u_cpu Ex_stage Excp_handler mepc_rd_data", false,-1, 63,0);
        tracep->declQuad(c+640,"SimTop u_cpu Ex_stage Excp_handler mie_rd_data", false,-1, 63,0);
        tracep->declQuad(c+642,"SimTop u_cpu Ex_stage Excp_handler mip_rd_data", false,-1, 63,0);
        tracep->declBit(c+644,"SimTop u_cpu Ex_stage Excp_handler sp_excp_ena", false,-1);
        tracep->declBit(c+572,"SimTop u_cpu Ex_stage Excp_handler sp_itrp_ena", false,-1);
        tracep->declBit(c+645,"SimTop u_cpu Ex_stage Excp_handler msie_allowin", false,-1);
        tracep->declBit(c+646,"SimTop u_cpu Ex_stage Excp_handler mtie_allowin", false,-1);
        tracep->declBit(c+647,"SimTop u_cpu Ex_stage Excp_handler meie_allowin", false,-1);
        tracep->declBit(c+648,"SimTop u_cpu Ex_stage Excp_handler soft_itrp", false,-1);
        tracep->declBit(c+649,"SimTop u_cpu Ex_stage Excp_handler timer_itrp", false,-1);
        tracep->declBit(c+650,"SimTop u_cpu Ex_stage Excp_handler exter_itrp", false,-1);
        tracep->declQuad(c+651,"SimTop u_cpu Ex_stage Excp_handler itrp_idx", false,-1, 62,0);
        tracep->declBit(c+653,"SimTop u_cpu Ex_stage Excp_handler excp_inst_misal", false,-1);
        tracep->declBit(c+654,"SimTop u_cpu Ex_stage Excp_handler excp_inst_acc", false,-1);
        tracep->declBit(c+655,"SimTop u_cpu Ex_stage Excp_handler excp_ilg_inst", false,-1);
        tracep->declBit(c+656,"SimTop u_cpu Ex_stage Excp_handler excp_brk_pt", false,-1);
        tracep->declBit(c+657,"SimTop u_cpu Ex_stage Excp_handler excp_load_misal", false,-1);
        tracep->declBit(c+658,"SimTop u_cpu Ex_stage Excp_handler excp_load_acc", false,-1);
        tracep->declBit(c+659,"SimTop u_cpu Ex_stage Excp_handler excp_stor_misal", false,-1);
        tracep->declBit(c+660,"SimTop u_cpu Ex_stage Excp_handler excp_stor_acc", false,-1);
        tracep->declBit(c+661,"SimTop u_cpu Ex_stage Excp_handler excp_ecall_m", false,-1);
        tracep->declBit(c+662,"SimTop u_cpu Ex_stage Excp_handler excp_inst_page", false,-1);
        tracep->declBit(c+663,"SimTop u_cpu Ex_stage Excp_handler excp_load_page", false,-1);
        tracep->declBit(c+664,"SimTop u_cpu Ex_stage Excp_handler excp_stor_page", false,-1);
        tracep->declQuad(c+665,"SimTop u_cpu Ex_stage Excp_handler excp_idx", false,-1, 62,0);
        tracep->declBit(c+667,"SimTop u_cpu Ex_stage Excp_handler inst_acc_fault", false,-1);
        tracep->declBit(c+668,"SimTop u_cpu Ex_stage Excp_handler mem_acc_fault", false,-1);
        tracep->declQuad(c+669,"SimTop u_cpu Ex_stage Excp_handler mstatus_p1", false,-1, 63,8);
        tracep->declBit(c+671,"SimTop u_cpu Ex_stage Excp_handler mstatus_mpie", false,-1);
        tracep->declBus(c+672,"SimTop u_cpu Ex_stage Excp_handler mstatus_p2", false,-1, 6,4);
        tracep->declBit(c+673,"SimTop u_cpu Ex_stage Excp_handler mstatus_mie", false,-1);
        tracep->declBus(c+674,"SimTop u_cpu Ex_stage Excp_handler mstatus_p3", false,-1, 2,0);
        tracep->declQuad(c+675,"SimTop u_cpu Ex_stage Excp_handler mstatus_excp_enter", false,-1, 63,0);
        tracep->declQuad(c+677,"SimTop u_cpu Ex_stage Excp_handler mstatus_excp_exit", false,-1, 63,0);
        tracep->declBus(c+679,"SimTop u_cpu Ex_stage Excp_handler mtvec_mode", false,-1, 1,0);
        tracep->declBit(c+680,"SimTop u_cpu Ex_stage Excp_handler mtvec_mode0", false,-1);
        tracep->declBit(c+681,"SimTop u_cpu Ex_stage Excp_handler mtvec_mode1", false,-1);
        tracep->declQuad(c+682,"SimTop u_cpu Ex_stage Excp_handler mtvec_base", false,-1, 61,0);
        tracep->declQuad(c+684,"SimTop u_cpu Ex_stage Excp_handler excp_enter_pc", false,-1, 63,0);
        tracep->declQuad(c+638,"SimTop u_cpu Ex_stage Excp_handler excp_exit_pc", false,-1, 63,0);
        tracep->declBit(c+1356,"SimTop u_cpu Ex_stage Exe_stage_alu rst", false,-1);
        tracep->declQuad(c+1291,"SimTop u_cpu Ex_stage Exe_stage_alu op1", false,-1, 63,0);
        tracep->declQuad(c+1293,"SimTop u_cpu Ex_stage Exe_stage_alu op2", false,-1, 63,0);
        tracep->declBus(c+583,"SimTop u_cpu Ex_stage Exe_stage_alu alu_info", false,-1, 11,0);
        tracep->declBit(c+582,"SimTop u_cpu Ex_stage Exe_stage_alu is_word_opt", false,-1);
        tracep->declQuad(c+1259,"SimTop u_cpu Ex_stage Exe_stage_alu alu_output", false,-1, 63,0);
        tracep->declBus(c+1295,"SimTop u_cpu Ex_stage Exe_stage_alu bj_data", false,-1, 7,0);
        tracep->declBit(c+686,"SimTop u_cpu Ex_stage Exe_stage_alu op_add", false,-1);
        tracep->declBit(c+687,"SimTop u_cpu Ex_stage Exe_stage_alu op_sub", false,-1);
        tracep->declBit(c+688,"SimTop u_cpu Ex_stage Exe_stage_alu op_slt", false,-1);
        tracep->declBit(c+689,"SimTop u_cpu Ex_stage Exe_stage_alu op_sltu", false,-1);
        tracep->declBit(c+690,"SimTop u_cpu Ex_stage Exe_stage_alu op_xor", false,-1);
        tracep->declBit(c+691,"SimTop u_cpu Ex_stage Exe_stage_alu op_or", false,-1);
        tracep->declBit(c+692,"SimTop u_cpu Ex_stage Exe_stage_alu op_and", false,-1);
        tracep->declBit(c+693,"SimTop u_cpu Ex_stage Exe_stage_alu op_sll", false,-1);
        tracep->declBit(c+694,"SimTop u_cpu Ex_stage Exe_stage_alu op_srl", false,-1);
        tracep->declBit(c+695,"SimTop u_cpu Ex_stage Exe_stage_alu op_sra", false,-1);
        tracep->declBit(c+696,"SimTop u_cpu Ex_stage Exe_stage_alu op_andn", false,-1);
        tracep->declBit(c+697,"SimTop u_cpu Ex_stage Exe_stage_alu op_wri", false,-1);
        tracep->declBit(c+698,"SimTop u_cpu Ex_stage Exe_stage_alu op_shift", false,-1);
        tracep->declQuad(c+1291,"SimTop u_cpu Ex_stage Exe_stage_alu shifter_op1", false,-1, 63,0);
        tracep->declQuad(c+1296,"SimTop u_cpu Ex_stage Exe_stage_alu shifter_in1", false,-1, 63,0);
        tracep->declBus(c+1298,"SimTop u_cpu Ex_stage Exe_stage_alu shifter_in2", false,-1, 5,0);
        tracep->declQuad(c+1299,"SimTop u_cpu Ex_stage Exe_stage_alu shifter_res", false,-1, 63,0);
        tracep->declQuad(c+1299,"SimTop u_cpu Ex_stage Exe_stage_alu sll_res", false,-1, 63,0);
        tracep->declQuad(c+1301,"SimTop u_cpu Ex_stage Exe_stage_alu srl_res", false,-1, 63,0);
        tracep->declQuad(c+1303,"SimTop u_cpu Ex_stage Exe_stage_alu eff_mask", false,-1, 63,0);
        tracep->declQuad(c+1183,"SimTop u_cpu Ex_stage Exe_stage_alu sra_res", false,-1, 63,0);
        tracep->declBit(c+686,"SimTop u_cpu Ex_stage Exe_stage_alu temp_add", false,-1);
        tracep->declBit(c+699,"SimTop u_cpu Ex_stage Exe_stage_alu temp_sub", false,-1);
        tracep->declBit(c+700,"SimTop u_cpu Ex_stage Exe_stage_alu op_addsub", false,-1);
        tracep->declBit(c+689,"SimTop u_cpu Ex_stage Exe_stage_alu op_unsigned", false,-1);
        tracep->declArray(c+1185,"SimTop u_cpu Ex_stage Exe_stage_alu adder_op1", false,-1, 64,0);
        tracep->declArray(c+1305,"SimTop u_cpu Ex_stage Exe_stage_alu adder_op2", false,-1, 64,0);
        tracep->declArray(c+1188,"SimTop u_cpu Ex_stage Exe_stage_alu adder_in1", false,-1, 64,0);
        tracep->declArray(c+1191,"SimTop u_cpu Ex_stage Exe_stage_alu adder_in2", false,-1, 64,0);
        tracep->declArray(c+701,"SimTop u_cpu Ex_stage Exe_stage_alu adder_cin", false,-1, 64,0);
        tracep->declArray(c+1308,"SimTop u_cpu Ex_stage Exe_stage_alu add_res", false,-1, 64,0);
        tracep->declQuad(c+1311,"SimTop u_cpu Ex_stage Exe_stage_alu slt_res", false,-1, 63,0);
        tracep->declQuad(c+1311,"SimTop u_cpu Ex_stage Exe_stage_alu sltu_res", false,-1, 63,0);
        tracep->declQuad(c+1313,"SimTop u_cpu Ex_stage Exe_stage_alu xor_res", false,-1, 63,0);
        tracep->declQuad(c+1315,"SimTop u_cpu Ex_stage Exe_stage_alu or_res", false,-1, 63,0);
        tracep->declQuad(c+1317,"SimTop u_cpu Ex_stage Exe_stage_alu and_res", false,-1, 63,0);
        tracep->declQuad(c+1319,"SimTop u_cpu Ex_stage Exe_stage_alu andn_res", false,-1, 63,0);
        tracep->declQuad(c+1291,"SimTop u_cpu Ex_stage Exe_stage_alu wri_res", false,-1, 63,0);
        tracep->declQuad(c+1321,"SimTop u_cpu Ex_stage Exe_stage_alu temp_output", false,-1, 63,0);
        tracep->declBit(c+1323,"SimTop u_cpu Ex_stage Exe_stage_alu eq_res", false,-1);
        tracep->declBit(c+1356,"SimTop u_cpu Ex_stage Exe_stage_bj rst", false,-1);
        tracep->declBit(c+558,"SimTop u_cpu Ex_stage Exe_stage_bj ex_valid", false,-1);
        tracep->declBus(c+584,"SimTop u_cpu Ex_stage Exe_stage_bj bj_info", false,-1, 7,0);
        tracep->declBus(c+1295,"SimTop u_cpu Ex_stage Exe_stage_bj bj_data", false,-1, 7,0);
        tracep->declQuad(c+585,"SimTop u_cpu Ex_stage Exe_stage_bj jmp_imm", false,-1, 63,0);
        tracep->declQuad(c+1283,"SimTop u_cpu Ex_stage Exe_stage_bj rs1_data", false,-1, 63,0);
        tracep->declQuad(c+184,"SimTop u_cpu Ex_stage Exe_stage_bj ex_pc", false,-1, 63,0);
        tracep->declBit(c+1479,"SimTop u_cpu Ex_stage Exe_stage_bj bj_ena", false,-1);
        tracep->declQuad(c+1179,"SimTop u_cpu Ex_stage Exe_stage_bj new_pc", false,-1, 63,0);
        tracep->declBit(c+1355,"SimTop u_cpu CSRfile clk", false,-1);
        tracep->declBit(c+1356,"SimTop u_cpu CSRfile rst", false,-1);
        tracep->declBit(c+179,"SimTop u_cpu CSRfile csr_wr_clk", false,-1);
        tracep->declBit(c+258,"SimTop u_cpu CSRfile csr_rd_ena", false,-1);
        tracep->declBus(c+259,"SimTop u_cpu CSRfile csr_rd_addr", false,-1, 11,0);
        tracep->declQuad(c+1257,"SimTop u_cpu CSRfile csr_rd_data", false,-1, 63,0);
        tracep->declBit(c+260,"SimTop u_cpu CSRfile csr_wr_ena", false,-1);
        tracep->declBus(c+261,"SimTop u_cpu CSRfile csr_wr_addr", false,-1, 11,0);
        tracep->declQuad(c+1259,"SimTop u_cpu CSRfile csr_wr_data", false,-1, 63,0);
        tracep->declArray(c+264,"SimTop u_cpu CSRfile csr_excp_rd_bus", false,-1, 319,0);
        tracep->declArray(c+1261,"SimTop u_cpu CSRfile csr_excp_wr_bus", false,-1, 319,0);
        tracep->declBit(c+262,"SimTop u_cpu CSRfile excp_enter", false,-1);
        tracep->declBit(c+263,"SimTop u_cpu CSRfile excp_exit", false,-1);
        tracep->declArray(c+1238,"SimTop u_cpu CSRfile csr_to_ex_diffbus", false,-1, 511,0);
        tracep->declQuad(c+1324,"SimTop u_cpu CSRfile mip_wr_data", false,-1, 63,0);
        tracep->declQuad(c+1326,"SimTop u_cpu CSRfile mstatus_wr_data", false,-1, 63,0);
        tracep->declQuad(c+1328,"SimTop u_cpu CSRfile mepc_wr_data", false,-1, 63,0);
        tracep->declQuad(c+1330,"SimTop u_cpu CSRfile mcause_wr_data", false,-1, 63,0);
        tracep->declQuad(c+1332,"SimTop u_cpu CSRfile mtval_wr_data", false,-1, 63,0);
        tracep->declBit(c+704,"SimTop u_cpu CSRfile excp_enter_wr", false,-1);
        tracep->declBit(c+705,"SimTop u_cpu CSRfile excp_exit_wr", false,-1);
        tracep->declBit(c+706,"SimTop u_cpu CSRfile excp_wr", false,-1);
        tracep->declBit(c+707,"SimTop u_cpu CSRfile sel_rd_mstatus", false,-1);
        tracep->declBit(c+708,"SimTop u_cpu CSRfile sel_wr_mstatus", false,-1);
        tracep->declBit(c+709,"SimTop u_cpu CSRfile mstatus_rd_ena", false,-1);
        tracep->declBit(c+710,"SimTop u_cpu CSRfile mstatus_wr_ena", false,-1);
        tracep->declQuad(c+1334,"SimTop u_cpu CSRfile mstatus_wr_data_full", false,-1, 63,0);
        tracep->declQuad(c+1336,"SimTop u_cpu CSRfile csr_wr_data_full", false,-1, 63,0);
        tracep->declQuad(c+711,"SimTop u_cpu CSRfile csr_mstatus", false,-1, 63,0);
        tracep->declQuad(c+1338,"SimTop u_cpu CSRfile mstatus_rd_data", false,-1, 63,0);
        tracep->declBit(c+713,"SimTop u_cpu CSRfile sel_misa", false,-1);
        tracep->declBit(c+714,"SimTop u_cpu CSRfile misa_rd_ena", false,-1);
        tracep->declQuad(c+1505,"SimTop u_cpu CSRfile csr_misa", false,-1, 63,0);
        tracep->declQuad(c+1505,"SimTop u_cpu CSRfile misa_rd_data", false,-1, 63,0);
        tracep->declBit(c+715,"SimTop u_cpu CSRfile sel_rd_mie", false,-1);
        tracep->declBit(c+716,"SimTop u_cpu CSRfile sel_wr_mie", false,-1);
        tracep->declBit(c+717,"SimTop u_cpu CSRfile mie_rd_ena", false,-1);
        tracep->declBit(c+718,"SimTop u_cpu CSRfile mie_wr_ena", false,-1);
        tracep->declQuad(c+719,"SimTop u_cpu CSRfile csr_mie", false,-1, 63,0);
        tracep->declQuad(c+1340,"SimTop u_cpu CSRfile mie_rd_data", false,-1, 63,0);
        tracep->declBit(c+721,"SimTop u_cpu CSRfile sel_rd_mtvec", false,-1);
        tracep->declBit(c+722,"SimTop u_cpu CSRfile sel_wr_mtvec", false,-1);
        tracep->declBit(c+723,"SimTop u_cpu CSRfile mtvec_rd_ena", false,-1);
        tracep->declBit(c+724,"SimTop u_cpu CSRfile mtvec_wr_ena", false,-1);
        tracep->declQuad(c+725,"SimTop u_cpu CSRfile csr_mtvec", false,-1, 63,0);
        tracep->declQuad(c+1342,"SimTop u_cpu CSRfile mtvec_rd_data", false,-1, 63,0);
        tracep->declBit(c+727,"SimTop u_cpu CSRfile sel_rd_mscratch", false,-1);
        tracep->declBit(c+728,"SimTop u_cpu CSRfile sel_wr_mscratch", false,-1);
        tracep->declBit(c+729,"SimTop u_cpu CSRfile mscratch_rd_ena", false,-1);
        tracep->declBit(c+730,"SimTop u_cpu CSRfile mscratch_wr_ena", false,-1);
        tracep->declQuad(c+731,"SimTop u_cpu CSRfile csr_mscratch", false,-1, 63,0);
        tracep->declQuad(c+1344,"SimTop u_cpu CSRfile mscratch_rd_data", false,-1, 63,0);
        tracep->declBit(c+733,"SimTop u_cpu CSRfile sel_rd_mepc", false,-1);
        tracep->declBit(c+734,"SimTop u_cpu CSRfile sel_wr_mepc", false,-1);
        tracep->declBit(c+735,"SimTop u_cpu CSRfile mepc_rd_ena", false,-1);
        tracep->declBit(c+736,"SimTop u_cpu CSRfile mepc_wr_ena", false,-1);
        tracep->declQuad(c+737,"SimTop u_cpu CSRfile csr_mepc", false,-1, 63,0);
        tracep->declQuad(c+1346,"SimTop u_cpu CSRfile mepc_rd_data", false,-1, 63,0);
        tracep->declBit(c+739,"SimTop u_cpu CSRfile sel_rd_mcause", false,-1);
        tracep->declBit(c+740,"SimTop u_cpu CSRfile sel_wr_mcause", false,-1);
        tracep->declBit(c+741,"SimTop u_cpu CSRfile mcause_rd_ena", false,-1);
        tracep->declBit(c+742,"SimTop u_cpu CSRfile mcause_wr_ena", false,-1);
        tracep->declQuad(c+743,"SimTop u_cpu CSRfile csr_mcause", false,-1, 63,0);
        tracep->declQuad(c+1348,"SimTop u_cpu CSRfile mcause_rd_data", false,-1, 63,0);
        tracep->declBit(c+745,"SimTop u_cpu CSRfile sel_rd_mtval", false,-1);
        tracep->declBit(c+746,"SimTop u_cpu CSRfile sel_wr_mtval", false,-1);
        tracep->declBit(c+747,"SimTop u_cpu CSRfile mtval_rd_ena", false,-1);
        tracep->declBit(c+748,"SimTop u_cpu CSRfile mtval_wr_ena", false,-1);
        tracep->declQuad(c+749,"SimTop u_cpu CSRfile csr_mtval", false,-1, 63,0);
        tracep->declQuad(c+1350,"SimTop u_cpu CSRfile mtval_rd_data", false,-1, 63,0);
        tracep->declBit(c+751,"SimTop u_cpu CSRfile sel_rd_mip", false,-1);
        tracep->declBit(c+752,"SimTop u_cpu CSRfile sel_wr_mip", false,-1);
        tracep->declBit(c+753,"SimTop u_cpu CSRfile mip_rd_ena", false,-1);
        tracep->declBit(c+754,"SimTop u_cpu CSRfile mip_wr_ena", false,-1);
        tracep->declQuad(c+755,"SimTop u_cpu CSRfile csr_mip", false,-1, 63,0);
        tracep->declQuad(c+1324,"SimTop u_cpu CSRfile mip_rd_data", false,-1, 63,0);
        tracep->declBit(c+757,"SimTop u_cpu CSRfile sel_rd_mcycle", false,-1);
        tracep->declBit(c+758,"SimTop u_cpu CSRfile sel_wr_mcycle", false,-1);
        tracep->declBit(c+759,"SimTop u_cpu CSRfile mcycle_rd_ena", false,-1);
        tracep->declBit(c+760,"SimTop u_cpu CSRfile mcycle_wr_ena", false,-1);
        tracep->declQuad(c+761,"SimTop u_cpu CSRfile csr_mcycle", false,-1, 63,0);
        tracep->declQuad(c+1194,"SimTop u_cpu CSRfile mcycle_rd_data", false,-1, 63,0);
        tracep->declBit(c+763,"SimTop u_cpu CSRfile sel_mvendorid", false,-1);
        tracep->declBit(c+764,"SimTop u_cpu CSRfile mvendorid_rd_ena", false,-1);
        tracep->declQuad(c+1493,"SimTop u_cpu CSRfile csr_mvendorid", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu CSRfile mvendorid_rd_data", false,-1, 63,0);
        tracep->declBit(c+765,"SimTop u_cpu CSRfile sel_marchid", false,-1);
        tracep->declBit(c+766,"SimTop u_cpu CSRfile marchid_rd_ena", false,-1);
        tracep->declQuad(c+1493,"SimTop u_cpu CSRfile csr_marchid", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu CSRfile marchid_rd_data", false,-1, 63,0);
        tracep->declBit(c+767,"SimTop u_cpu CSRfile sel_mimpid", false,-1);
        tracep->declBit(c+768,"SimTop u_cpu CSRfile mimpid_rd_ena", false,-1);
        tracep->declQuad(c+1493,"SimTop u_cpu CSRfile csr_mimpid", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu CSRfile mimpid_rd_data", false,-1, 63,0);
        tracep->declBit(c+769,"SimTop u_cpu CSRfile sel_mhartid", false,-1);
        tracep->declBit(c+770,"SimTop u_cpu CSRfile mhartid_rd_ena", false,-1);
        tracep->declQuad(c+1493,"SimTop u_cpu CSRfile csr_mhartid", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu CSRfile mhartid_rd_data", false,-1, 63,0);
        tracep->declBit(c+1355,"SimTop u_cpu Mem_stage clk", false,-1);
        tracep->declBit(c+1356,"SimTop u_cpu Mem_stage rst", false,-1);
        tracep->declBit(c+174,"SimTop u_cpu Mem_stage ex_to_mem_valid", false,-1);
        tracep->declQuad(c+184,"SimTop u_cpu Mem_stage ex_to_mem_pc", false,-1, 63,0);
        tracep->declBus(c+190,"SimTop u_cpu Mem_stage ex_to_mem_inst", false,-1, 31,0);
        tracep->declArray(c+1231,"SimTop u_cpu Mem_stage ex_to_mem_bus", false,-1, 222,0);
        tracep->declBit(c+178,"SimTop u_cpu Mem_stage mem_allowin", false,-1);
        tracep->declBit(c+179,"SimTop u_cpu Mem_stage ex_to_mem_handshake", false,-1);
        tracep->declBit(c+175,"SimTop u_cpu Mem_stage mem_to_wb_valid", false,-1);
        tracep->declQuad(c+186,"SimTop u_cpu Mem_stage mem_to_wb_pc", false,-1, 63,0);
        tracep->declBus(c+191,"SimTop u_cpu Mem_stage mem_to_wb_inst", false,-1, 31,0);
        tracep->declArray(c+192,"SimTop u_cpu Mem_stage mem_to_wb_bus", false,-1, 209,0);
        tracep->declBit(c+1489,"SimTop u_cpu Mem_stage wb_allowin", false,-1);
        tracep->declArray(c+249,"SimTop u_cpu Mem_stage mem_forward_bus", false,-1, 72,0);
        tracep->declArray(c+1157,"SimTop u_cpu Mem_stage ex_to_mem_diffbus", false,-1, 576,0);
        tracep->declArray(c+200,"SimTop u_cpu Mem_stage mem_to_wb_diffbus", false,-1, 714,0);
        tracep->declBit(c+70,"SimTop u_cpu Mem_stage mem_rw_valid", false,-1);
        tracep->declBit(c+71,"SimTop u_cpu Mem_stage mem_rw_ready", false,-1);
        tracep->declBit(c+72,"SimTop u_cpu Mem_stage mem_rw_req", false,-1);
        tracep->declQuad(c+73,"SimTop u_cpu Mem_stage mem_r_data", false,-1, 63,0);
        tracep->declQuad(c+75,"SimTop u_cpu Mem_stage mem_w_data", false,-1, 63,0);
        tracep->declQuad(c+77,"SimTop u_cpu Mem_stage mem_rw_addr", false,-1, 63,0);
        tracep->declBus(c+79,"SimTop u_cpu Mem_stage mem_rw_size", false,-1, 1,0);
        tracep->declBus(c+80,"SimTop u_cpu Mem_stage mem_rw_resp", false,-1, 1,0);
        tracep->declBit(c+771,"SimTop u_cpu Mem_stage debug", false,-1);
        tracep->declBit(c+772,"SimTop u_cpu Mem_stage mem_valid", false,-1);
        tracep->declBit(c+773,"SimTop u_cpu Mem_stage mem_ready_go", false,-1);
        tracep->declQuad(c+186,"SimTop u_cpu Mem_stage ex_to_mem_pc_r", false,-1, 63,0);
        tracep->declBus(c+191,"SimTop u_cpu Mem_stage ex_to_mem_inst_r", false,-1, 31,0);
        tracep->declArray(c+774,"SimTop u_cpu Mem_stage ex_to_mem_bus_r", false,-1, 222,0);
        tracep->declArray(c+781,"SimTop u_cpu Mem_stage ex_to_mem_diffbus_r", false,-1, 576,0);
        tracep->declBit(c+800,"SimTop u_cpu Mem_stage mem_uart_out_valid", false,-1);
        tracep->declBus(c+801,"SimTop u_cpu Mem_stage mem_uart_out_char", false,-1, 7,0);
        tracep->declQuad(c+186,"SimTop u_cpu Mem_stage mem_pc", false,-1, 63,0);
        tracep->declBus(c+191,"SimTop u_cpu Mem_stage mem_inst", false,-1, 31,0);
        tracep->declBus(c+802,"SimTop u_cpu Mem_stage mem_load_info", false,-1, 6,0);
        tracep->declBus(c+803,"SimTop u_cpu Mem_stage mem_save_info", false,-1, 3,0);
        tracep->declQuad(c+804,"SimTop u_cpu Mem_stage mem_ram_wr_src", false,-1, 63,0);
        tracep->declQuad(c+77,"SimTop u_cpu Mem_stage mem_addr", false,-1, 63,0);
        tracep->declQuad(c+806,"SimTop u_cpu Mem_stage mem_csr_rd_data", false,-1, 63,0);
        tracep->declBit(c+808,"SimTop u_cpu Mem_stage mem_ram_rd_ena", false,-1);
        tracep->declBit(c+72,"SimTop u_cpu Mem_stage mem_ram_wr_ena", false,-1);
        tracep->declBus(c+809,"SimTop u_cpu Mem_stage mem_reg_wr_ctrl", false,-1, 2,0);
        tracep->declBus(c+810,"SimTop u_cpu Mem_stage mem_reg_wr_addr", false,-1, 4,0);
        tracep->declBit(c+811,"SimTop u_cpu Mem_stage mem_reg_wr_ena", false,-1);
        tracep->declBit(c+1352,"SimTop u_cpu Mem_stage ex_ram_rd_ena", false,-1);
        tracep->declBit(c+1353,"SimTop u_cpu Mem_stage ex_ram_wr_ena", false,-1);
        tracep->declBit(c+812,"SimTop u_cpu Mem_stage refresh", false,-1);
        tracep->declBit(c+813,"SimTop u_cpu Mem_stage mem_handshake", false,-1);
        tracep->declBit(c+814,"SimTop u_cpu Mem_stage op_sb", false,-1);
        tracep->declBit(c+815,"SimTop u_cpu Mem_stage op_sh", false,-1);
        tracep->declBit(c+816,"SimTop u_cpu Mem_stage op_sw", false,-1);
        tracep->declBit(c+817,"SimTop u_cpu Mem_stage op_sd", false,-1);
        tracep->declBit(c+818,"SimTop u_cpu Mem_stage op_lb", false,-1);
        tracep->declBit(c+819,"SimTop u_cpu Mem_stage op_lh", false,-1);
        tracep->declBit(c+820,"SimTop u_cpu Mem_stage op_lw", false,-1);
        tracep->declBit(c+821,"SimTop u_cpu Mem_stage op_ld", false,-1);
        tracep->declBit(c+822,"SimTop u_cpu Mem_stage op_lbu", false,-1);
        tracep->declBit(c+823,"SimTop u_cpu Mem_stage op_lhu", false,-1);
        tracep->declBit(c+824,"SimTop u_cpu Mem_stage op_lwu", false,-1);
        tracep->declBus(c+1490,"SimTop u_cpu Mem_stage IDLE", false,-1, 1,0);
        tracep->declBus(c+1486,"SimTop u_cpu Mem_stage ADDR", false,-1, 1,0);
        tracep->declBus(c+1495,"SimTop u_cpu Mem_stage RETN", false,-1, 1,0);
        tracep->declBus(c+825,"SimTop u_cpu Mem_stage mem_state", false,-1, 1,0);
        tracep->declBus(c+1354,"SimTop u_cpu Mem_stage mem_next_state", false,-1, 1,0);
        tracep->declQuad(c+826,"SimTop u_cpu Mem_stage mem_data", false,-1, 63,0);
        tracep->declBit(c+828,"SimTop u_cpu Mem_stage mem_finish", false,-1);
        tracep->declQuad(c+77,"SimTop u_cpu Mem_stage mem_ex_data", false,-1, 63,0);
        tracep->declBit(c+135,"SimTop u_cpu Mem_stage size_b", false,-1);
        tracep->declBit(c+136,"SimTop u_cpu Mem_stage size_h", false,-1);
        tracep->declBit(c+137,"SimTop u_cpu Mem_stage size_w", false,-1);
        tracep->declBit(c+138,"SimTop u_cpu Mem_stage size_d", false,-1);
        tracep->declBit(c+134,"SimTop u_cpu Mem_stage addr0", false,-1);
        tracep->declBit(c+829,"SimTop u_cpu Mem_stage addr1", false,-1);
        tracep->declBit(c+830,"SimTop u_cpu Mem_stage addr2", false,-1);
        tracep->declBit(c+831,"SimTop u_cpu Mem_stage addr3", false,-1);
        tracep->declBit(c+832,"SimTop u_cpu Mem_stage addr4", false,-1);
        tracep->declBit(c+833,"SimTop u_cpu Mem_stage addr5", false,-1);
        tracep->declBit(c+834,"SimTop u_cpu Mem_stage addr6", false,-1);
        tracep->declBit(c+835,"SimTop u_cpu Mem_stage addr7", false,-1);
        tracep->declBit(c+836,"SimTop u_cpu Mem_stage difftest_s_valid", false,-1);
        tracep->declBit(c+837,"SimTop u_cpu Mem_stage difftest_l_valid", false,-1);
        tracep->declQuad(c+5,"SimTop u_cpu Mem_stage difftest_addr", false,-1, 63,0);
        tracep->declQuad(c+838,"SimTop u_cpu Mem_stage difftest_data", false,-1, 63,0);
        tracep->declBus(c+840,"SimTop u_cpu Mem_stage difftest_mask", false,-1, 7,0);
        tracep->declBit(c+1355,"SimTop u_cpu Wb_stage clk", false,-1);
        tracep->declBit(c+1356,"SimTop u_cpu Wb_stage rst", false,-1);
        tracep->declBit(c+175,"SimTop u_cpu Wb_stage mem_to_wb_valid", false,-1);
        tracep->declQuad(c+186,"SimTop u_cpu Wb_stage mem_to_wb_pc", false,-1, 63,0);
        tracep->declBus(c+191,"SimTop u_cpu Wb_stage mem_to_wb_inst", false,-1, 31,0);
        tracep->declArray(c+192,"SimTop u_cpu Wb_stage mem_to_wb_bus", false,-1, 209,0);
        tracep->declBit(c+1489,"SimTop u_cpu Wb_stage wb_allowin", false,-1);
        tracep->declArray(c+252,"SimTop u_cpu Wb_stage wb_forward_bus", false,-1, 136,0);
        tracep->declBit(c+276,"SimTop u_cpu Wb_stage reg_wr_ena", false,-1);
        tracep->declBus(c+277,"SimTop u_cpu Wb_stage reg_wr_addr", false,-1, 4,0);
        tracep->declQuad(c+1271,"SimTop u_cpu Wb_stage reg_wr_data", false,-1, 63,0);
        tracep->declArray(c+200,"SimTop u_cpu Wb_stage mem_to_wb_diffbus", false,-1, 714,0);
        tracep->declArray(c+223,"SimTop u_cpu Wb_stage difftest_bus", false,-1, 811,0);
        tracep->declBit(c+1365,"SimTop u_cpu Wb_stage wb_uart_out_valid", false,-1);
        tracep->declBus(c+1366,"SimTop u_cpu Wb_stage wb_uart_out_char", false,-1, 7,0);
        tracep->declBit(c+841,"SimTop u_cpu Wb_stage wb_valid", false,-1);
        tracep->declQuad(c+842,"SimTop u_cpu Wb_stage mem_to_wb_pc_r", false,-1, 63,0);
        tracep->declBus(c+844,"SimTop u_cpu Wb_stage mem_to_wb_inst_r", false,-1, 31,0);
        tracep->declArray(c+845,"SimTop u_cpu Wb_stage mem_to_wb_bus_r", false,-1, 209,0);
        tracep->declArray(c+852,"SimTop u_cpu Wb_stage mem_to_wb_diffbus_r", false,-1, 714,0);
        tracep->declQuad(c+842,"SimTop u_cpu Wb_stage wb_pc", false,-1, 63,0);
        tracep->declBus(c+844,"SimTop u_cpu Wb_stage wb_inst", false,-1, 31,0);
        tracep->declBit(c+875,"SimTop u_cpu Wb_stage wb_wen", false,-1);
        tracep->declBus(c+277,"SimTop u_cpu Wb_stage wb_wdest", false,-1, 4,0);
        tracep->declBus(c+876,"SimTop u_cpu Wb_stage wb_reg_wr_ctrl", false,-1, 2,0);
        tracep->declQuad(c+877,"SimTop u_cpu Wb_stage wb_ex_data", false,-1, 63,0);
        tracep->declQuad(c+879,"SimTop u_cpu Wb_stage wb_mem_rd_data", false,-1, 63,0);
        tracep->declQuad(c+881,"SimTop u_cpu Wb_stage wb_csr_rd_data", false,-1, 63,0);
        tracep->declBit(c+883,"SimTop u_cpu Wb_stage mem_to_reg", false,-1);
        tracep->declBit(c+884,"SimTop u_cpu Wb_stage ex_to_reg", false,-1);
        tracep->declBit(c+885,"SimTop u_cpu Wb_stage csr_to_reg", false,-1);
        tracep->declBus(c+1507,"SimTop u_cpu Wb_stage wb_excp_bus", false,-1, 15,0);
        tracep->declBit(c+841,"SimTop u_cpu Wb_stage wb_commit", false,-1);
        tracep->declBit(c+1355,"SimTop u_cpu Regfile clk", false,-1);
        tracep->declBit(c+1356,"SimTop u_cpu Regfile rst", false,-1);
        tracep->declBus(c+277,"SimTop u_cpu Regfile w_addr", false,-1, 4,0);
        tracep->declQuad(c+1271,"SimTop u_cpu Regfile w_data", false,-1, 63,0);
        tracep->declBit(c+276,"SimTop u_cpu Regfile w_ena", false,-1);
        tracep->declBus(c+274,"SimTop u_cpu Regfile r_addr1", false,-1, 4,0);
        tracep->declQuad(c+1462,"SimTop u_cpu Regfile r_data1", false,-1, 63,0);
        tracep->declBit(c+1489,"SimTop u_cpu Regfile r_ena1", false,-1);
        tracep->declBus(c+275,"SimTop u_cpu Regfile r_addr2", false,-1, 4,0);
        tracep->declQuad(c+1464,"SimTop u_cpu Regfile r_data2", false,-1, 63,0);
        tracep->declBit(c+1489,"SimTop u_cpu Regfile r_ena2", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+886+i*2,"SimTop u_cpu Regfile regs_o", true,(i+0), 63,0);}}
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+950+i*2,"SimTop u_cpu Regfile regs", true,(i+0), 63,0);}}
        tracep->declBit(c+1355,"SimTop u_cpu DifftestInstrCommit clock", false,-1);
        tracep->declBus(c+1508,"SimTop u_cpu DifftestInstrCommit coreid", false,-1, 7,0);
        tracep->declBus(c+1508,"SimTop u_cpu DifftestInstrCommit index", false,-1, 7,0);
        tracep->declBit(c+1014,"SimTop u_cpu DifftestInstrCommit valid", false,-1);
        tracep->declQuad(c+346,"SimTop u_cpu DifftestInstrCommit pc", false,-1, 63,0);
        tracep->declBus(c+348,"SimTop u_cpu DifftestInstrCommit instr", false,-1, 31,0);
        tracep->declBit(c+350,"SimTop u_cpu DifftestInstrCommit skip", false,-1);
        tracep->declBit(c+1487,"SimTop u_cpu DifftestInstrCommit isRVC", false,-1);
        tracep->declBit(c+1487,"SimTop u_cpu DifftestInstrCommit scFailed", false,-1);
        tracep->declBit(c+342,"SimTop u_cpu DifftestInstrCommit wen", false,-1);
        tracep->declBus(c+343,"SimTop u_cpu DifftestInstrCommit wdest", false,-1, 7,0);
        tracep->declQuad(c+344,"SimTop u_cpu DifftestInstrCommit wdata", false,-1, 63,0);
        tracep->declBit(c+1355,"SimTop u_cpu DifftestArchEvent clock", false,-1);
        tracep->declBus(c+1508,"SimTop u_cpu DifftestArchEvent coreid", false,-1, 7,0);
        tracep->declBus(c+351,"SimTop u_cpu DifftestArchEvent intrNO", false,-1, 31,0);
        tracep->declBus(c+1015,"SimTop u_cpu DifftestArchEvent cause", false,-1, 31,0);
        tracep->declQuad(c+346,"SimTop u_cpu DifftestArchEvent exceptionPC", false,-1, 63,0);
        tracep->declBus(c+348,"SimTop u_cpu DifftestArchEvent exceptionInst", false,-1, 31,0);
        tracep->declBit(c+1355,"SimTop u_cpu DifftestArchIntRegState clock", false,-1);
        tracep->declBus(c+1508,"SimTop u_cpu DifftestArchIntRegState coreid", false,-1, 7,0);
        tracep->declQuad(c+1016,"SimTop u_cpu DifftestArchIntRegState gpr_0", false,-1, 63,0);
        tracep->declQuad(c+1018,"SimTop u_cpu DifftestArchIntRegState gpr_1", false,-1, 63,0);
        tracep->declQuad(c+1020,"SimTop u_cpu DifftestArchIntRegState gpr_2", false,-1, 63,0);
        tracep->declQuad(c+1022,"SimTop u_cpu DifftestArchIntRegState gpr_3", false,-1, 63,0);
        tracep->declQuad(c+1024,"SimTop u_cpu DifftestArchIntRegState gpr_4", false,-1, 63,0);
        tracep->declQuad(c+1026,"SimTop u_cpu DifftestArchIntRegState gpr_5", false,-1, 63,0);
        tracep->declQuad(c+1028,"SimTop u_cpu DifftestArchIntRegState gpr_6", false,-1, 63,0);
        tracep->declQuad(c+1030,"SimTop u_cpu DifftestArchIntRegState gpr_7", false,-1, 63,0);
        tracep->declQuad(c+1032,"SimTop u_cpu DifftestArchIntRegState gpr_8", false,-1, 63,0);
        tracep->declQuad(c+1034,"SimTop u_cpu DifftestArchIntRegState gpr_9", false,-1, 63,0);
        tracep->declQuad(c+1036,"SimTop u_cpu DifftestArchIntRegState gpr_10", false,-1, 63,0);
        tracep->declQuad(c+1038,"SimTop u_cpu DifftestArchIntRegState gpr_11", false,-1, 63,0);
        tracep->declQuad(c+1040,"SimTop u_cpu DifftestArchIntRegState gpr_12", false,-1, 63,0);
        tracep->declQuad(c+1042,"SimTop u_cpu DifftestArchIntRegState gpr_13", false,-1, 63,0);
        tracep->declQuad(c+1044,"SimTop u_cpu DifftestArchIntRegState gpr_14", false,-1, 63,0);
        tracep->declQuad(c+1046,"SimTop u_cpu DifftestArchIntRegState gpr_15", false,-1, 63,0);
        tracep->declQuad(c+1048,"SimTop u_cpu DifftestArchIntRegState gpr_16", false,-1, 63,0);
        tracep->declQuad(c+1050,"SimTop u_cpu DifftestArchIntRegState gpr_17", false,-1, 63,0);
        tracep->declQuad(c+1052,"SimTop u_cpu DifftestArchIntRegState gpr_18", false,-1, 63,0);
        tracep->declQuad(c+1054,"SimTop u_cpu DifftestArchIntRegState gpr_19", false,-1, 63,0);
        tracep->declQuad(c+1056,"SimTop u_cpu DifftestArchIntRegState gpr_20", false,-1, 63,0);
        tracep->declQuad(c+1058,"SimTop u_cpu DifftestArchIntRegState gpr_21", false,-1, 63,0);
        tracep->declQuad(c+1060,"SimTop u_cpu DifftestArchIntRegState gpr_22", false,-1, 63,0);
        tracep->declQuad(c+1062,"SimTop u_cpu DifftestArchIntRegState gpr_23", false,-1, 63,0);
        tracep->declQuad(c+1064,"SimTop u_cpu DifftestArchIntRegState gpr_24", false,-1, 63,0);
        tracep->declQuad(c+1066,"SimTop u_cpu DifftestArchIntRegState gpr_25", false,-1, 63,0);
        tracep->declQuad(c+1068,"SimTop u_cpu DifftestArchIntRegState gpr_26", false,-1, 63,0);
        tracep->declQuad(c+1070,"SimTop u_cpu DifftestArchIntRegState gpr_27", false,-1, 63,0);
        tracep->declQuad(c+1072,"SimTop u_cpu DifftestArchIntRegState gpr_28", false,-1, 63,0);
        tracep->declQuad(c+1074,"SimTop u_cpu DifftestArchIntRegState gpr_29", false,-1, 63,0);
        tracep->declQuad(c+1076,"SimTop u_cpu DifftestArchIntRegState gpr_30", false,-1, 63,0);
        tracep->declQuad(c+1078,"SimTop u_cpu DifftestArchIntRegState gpr_31", false,-1, 63,0);
        tracep->declBit(c+1355,"SimTop u_cpu DifftestTrapEvent clock", false,-1);
        tracep->declBus(c+1508,"SimTop u_cpu DifftestTrapEvent coreid", false,-1, 7,0);
        tracep->declBit(c+1080,"SimTop u_cpu DifftestTrapEvent valid", false,-1);
        tracep->declBus(c+1081,"SimTop u_cpu DifftestTrapEvent code", false,-1, 2,0);
        tracep->declQuad(c+346,"SimTop u_cpu DifftestTrapEvent pc", false,-1, 63,0);
        tracep->declQuad(c+353,"SimTop u_cpu DifftestTrapEvent cycleCnt", false,-1, 63,0);
        tracep->declQuad(c+355,"SimTop u_cpu DifftestTrapEvent instrCnt", false,-1, 63,0);
        tracep->declBit(c+1355,"SimTop u_cpu DifftestCSRState clock", false,-1);
        tracep->declBus(c+1508,"SimTop u_cpu DifftestCSRState coreid", false,-1, 7,0);
        tracep->declBus(c+1509,"SimTop u_cpu DifftestCSRState priviledgeMode", false,-1, 1,0);
        tracep->declQuad(c+403,"SimTop u_cpu DifftestCSRState mstatus", false,-1, 63,0);
        tracep->declQuad(c+1082,"SimTop u_cpu DifftestCSRState sstatus", false,-1, 63,0);
        tracep->declQuad(c+405,"SimTop u_cpu DifftestCSRState mepc", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestCSRState sepc", false,-1, 63,0);
        tracep->declQuad(c+407,"SimTop u_cpu DifftestCSRState mtval", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestCSRState stval", false,-1, 63,0);
        tracep->declQuad(c+409,"SimTop u_cpu DifftestCSRState mtvec", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestCSRState stvec", false,-1, 63,0);
        tracep->declQuad(c+411,"SimTop u_cpu DifftestCSRState mcause", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestCSRState scause", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestCSRState satp", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestCSRState mip", false,-1, 63,0);
        tracep->declQuad(c+415,"SimTop u_cpu DifftestCSRState mie", false,-1, 63,0);
        tracep->declQuad(c+417,"SimTop u_cpu DifftestCSRState mscratch", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestCSRState sscratch", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestCSRState mideleg", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestCSRState medeleg", false,-1, 63,0);
        tracep->declBit(c+1355,"SimTop u_cpu DifftestArchFpRegState clock", false,-1);
        tracep->declBus(c+1508,"SimTop u_cpu DifftestArchFpRegState coreid", false,-1, 7,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_0", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_1", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_2", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_3", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_4", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_5", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_6", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_7", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_8", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_9", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_10", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_11", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_12", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_13", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_14", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_15", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_16", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_17", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_18", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_19", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_20", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_21", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_22", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_23", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_24", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_25", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_26", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_27", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_28", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_29", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_30", false,-1, 63,0);
        tracep->declQuad(c+1493,"SimTop u_cpu DifftestArchFpRegState fpr_31", false,-1, 63,0);
        tracep->declBit(c+1355,"SimTop u_cpu DifftestStoreEvent clock", false,-1);
        tracep->declBus(c+1508,"SimTop u_cpu DifftestStoreEvent coreid", false,-1, 7,0);
        tracep->declBus(c+1508,"SimTop u_cpu DifftestStoreEvent index", false,-1, 7,0);
        tracep->declBit(c+1084,"SimTop u_cpu DifftestStoreEvent valid", false,-1);
        tracep->declQuad(c+419,"SimTop u_cpu DifftestStoreEvent storeAddr", false,-1, 63,0);
        tracep->declQuad(c+421,"SimTop u_cpu DifftestStoreEvent storeData", false,-1, 63,0);
        tracep->declBus(c+427,"SimTop u_cpu DifftestStoreEvent storeMask", false,-1, 7,0);
        tracep->declBus(c+1480,"SimTop Clint RW_DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1480,"SimTop Clint RW_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1480,"SimTop Clint AXI_DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1480,"SimTop Clint AXI_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1481,"SimTop Clint AXI_ID_WIDTH", false,-1, 31,0);
        tracep->declBus(c+1482,"SimTop Clint AXI_USER_WIDTH", false,-1, 31,0);
        tracep->declBit(c+1355,"SimTop Clint clk", false,-1);
        tracep->declBit(c+1356,"SimTop Clint rst", false,-1);
        tracep->declBit(c+1,"SimTop Clint aw_ready_o", false,-1);
        tracep->declBit(c+4,"SimTop Clint aw_valid_i", false,-1);
        tracep->declQuad(c+9,"SimTop Clint aw_addr_i", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop Clint aw_prot_i", false,-1, 2,0);
        tracep->declBus(c+12,"SimTop Clint aw_id_i", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop Clint aw_user_i", false,-1, 0,0);
        tracep->declBus(c+15,"SimTop Clint aw_len_i", false,-1, 7,0);
        tracep->declBus(c+18,"SimTop Clint aw_size_i", false,-1, 2,0);
        tracep->declBus(c+19,"SimTop Clint aw_burst_i", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop Clint aw_lock_i", false,-1);
        tracep->declBus(c+20,"SimTop Clint aw_cache_i", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop Clint aw_qos_i", false,-1, 3,0);
        tracep->declBit(c+21,"SimTop Clint w_ready_o", false,-1);
        tracep->declBit(c+21,"SimTop Clint w_valid_i", false,-1);
        tracep->declQuad(c+28,"SimTop Clint w_data_i", false,-1, 63,0);
        tracep->declBus(c+32,"SimTop Clint w_strb_i", false,-1, 7,0);
        tracep->declBit(c+33,"SimTop Clint w_last_i", false,-1);
        tracep->declBus(c+1085,"SimTop Clint w_id_i", false,-1, 3,0);
        tracep->declBit(c+37,"SimTop Clint b_ready_i", false,-1);
        tracep->declBit(c+38,"SimTop Clint b_valid_o", false,-1);
        tracep->declBus(c+1490,"SimTop Clint b_resp_o", false,-1, 1,0);
        tracep->declBus(c+39,"SimTop Clint b_id_o", false,-1, 3,0);
        tracep->declBus(c+40,"SimTop Clint b_user_o", false,-1, 0,0);
        tracep->declBit(c+41,"SimTop Clint ar_ready_o", false,-1);
        tracep->declBit(c+44,"SimTop Clint ar_valid_i", false,-1);
        tracep->declQuad(c+45,"SimTop Clint ar_addr_i", false,-1, 63,0);
        tracep->declBus(c+1483,"SimTop Clint ar_prot_i", false,-1, 2,0);
        tracep->declBus(c+48,"SimTop Clint ar_id_i", false,-1, 3,0);
        tracep->declBus(c+1485,"SimTop Clint ar_user_i", false,-1, 0,0);
        tracep->declBus(c+51,"SimTop Clint ar_len_i", false,-1, 7,0);
        tracep->declBus(c+54,"SimTop Clint ar_size_i", false,-1, 2,0);
        tracep->declBus(c+1491,"SimTop Clint ar_burst_i", false,-1, 1,0);
        tracep->declBit(c+1487,"SimTop Clint ar_lock_i", false,-1);
        tracep->declBus(c+55,"SimTop Clint ar_cache_i", false,-1, 3,0);
        tracep->declBus(c+1484,"SimTop Clint ar_qos_i", false,-1, 3,0);
        tracep->declBit(c+58,"SimTop Clint r_ready_i", false,-1);
        tracep->declBit(c+1492,"SimTop Clint r_valid_o", false,-1);
        tracep->declBus(c+1490,"SimTop Clint r_resp_o", false,-1, 1,0);
        tracep->declQuad(c+59,"SimTop Clint r_data_o", false,-1, 63,0);
        tracep->declBit(c+1492,"SimTop Clint r_last_o", false,-1);
        tracep->declBus(c+61,"SimTop Clint r_id_o", false,-1, 3,0);
        tracep->declBus(c+62,"SimTop Clint r_user_o", false,-1, 0,0);
        tracep->declBus(c+81,"SimTop Clint clint_interupt_bus", false,-1, 11,0);
        tracep->declBit(c+1086,"SimTop Clint debug_wr", false,-1);
        tracep->declBit(c+1087,"SimTop Clint debug_rd", false,-1);
        tracep->declBus(c+1088,"SimTop Clint csr_msip", false,-1, 31,0);
        tracep->declQuad(c+1089,"SimTop Clint csr_mtime", false,-1, 63,0);
        tracep->declQuad(c+1091,"SimTop Clint csr_mtimecmp", false,-1, 63,0);
        tracep->declBit(c+1093,"SimTop Clint ar_hs", false,-1);
        tracep->declBit(c+58,"SimTop Clint r_hs", false,-1);
        tracep->declBit(c+1094,"SimTop Clint aw_hs", false,-1);
        tracep->declBit(c+21,"SimTop Clint w_hs", false,-1);
        tracep->declBit(c+1095,"SimTop Clint b_hs", false,-1);
        tracep->declBus(c+1485,"SimTop Clint R_STATE_IDLE", false,-1, 0,0);
        tracep->declBus(c+1492,"SimTop Clint R_STATE_READ", false,-1, 0,0);
        tracep->declBit(c+1096,"SimTop Clint r_state", false,-1);
        tracep->declBit(c+1097,"SimTop Clint r_state_idle", false,-1);
        tracep->declBit(c+1096,"SimTop Clint r_state_read", false,-1);
        tracep->declQuad(c+1098,"SimTop Clint rd_addr_reg", false,-1, 63,0);
        tracep->declBus(c+61,"SimTop Clint rd_id_reg", false,-1, 3,0);
        tracep->declBit(c+62,"SimTop Clint rd_user_reg", false,-1);
        tracep->declBus(c+1100,"SimTop Clint rd_size_reg", false,-1, 2,0);
        tracep->declBit(c+1101,"SimTop Clint rd_size_b", false,-1);
        tracep->declBit(c+1102,"SimTop Clint rd_size_h", false,-1);
        tracep->declBit(c+1103,"SimTop Clint rd_size_w", false,-1);
        tracep->declBit(c+1104,"SimTop Clint rd_size_d", false,-1);
        tracep->declBit(c+1105,"SimTop Clint msip_rd_ena", false,-1);
        tracep->declBit(c+1106,"SimTop Clint mtimecmp_rd_ena", false,-1);
        tracep->declBit(c+1107,"SimTop Clint mtime_rd_ena", false,-1);
        tracep->declQuad(c+1108,"SimTop Clint clint_val", false,-1, 63,0);
        tracep->declBus(c+1490,"SimTop Clint W_STATE_IDLE", false,-1, 1,0);
        tracep->declBus(c+1486,"SimTop Clint W_STATE_WRITE", false,-1, 1,0);
        tracep->declBus(c+1495,"SimTop Clint W_STATE_RESP", false,-1, 1,0);
        tracep->declBus(c+1110,"SimTop Clint w_state", false,-1, 1,0);
        tracep->declBit(c+1111,"SimTop Clint w_state_idle", false,-1);
        tracep->declBit(c+1112,"SimTop Clint w_state_write", false,-1);
        tracep->declBit(c+38,"SimTop Clint w_state_resp", false,-1);
        tracep->declQuad(c+1113,"SimTop Clint wr_addr_reg", false,-1, 63,0);
        tracep->declBus(c+39,"SimTop Clint wr_id_reg", false,-1, 3,0);
        tracep->declBus(c+40,"SimTop Clint wr_user_reg", false,-1, 0,0);
        tracep->declBus(c+1115,"SimTop Clint wr_size_reg", false,-1, 2,0);
        tracep->declBit(c+1116,"SimTop Clint wr_size_b", false,-1);
        tracep->declBit(c+1117,"SimTop Clint wr_size_h", false,-1);
        tracep->declBit(c+1118,"SimTop Clint wr_size_w", false,-1);
        tracep->declBit(c+1119,"SimTop Clint wr_size_d", false,-1);
        tracep->declBus(c+1120,"SimTop Clint mask_size", false,-1, 7,0);
        tracep->declBus(c+1121,"SimTop Clint mask_8bits", false,-1, 7,0);
        tracep->declQuad(c+1122,"SimTop Clint wr_mask", false,-1, 63,0);
        tracep->declBit(c+1124,"SimTop Clint msip_wr_ena", false,-1);
        tracep->declBit(c+1125,"SimTop Clint mtimecmp_wr_ena", false,-1);
        tracep->declBit(c+1126,"SimTop Clint mtime_wr_ena", false,-1);
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
    VlWide<4>/*127:0*/ __Vtemp650;
    VlWide<4>/*127:0*/ __Vtemp651;
    VlWide<4>/*127:0*/ __Vtemp652;
    VlWide<4>/*127:0*/ __Vtemp653;
    VlWide<4>/*127:0*/ __Vtemp654;
    VlWide<4>/*127:0*/ __Vtemp655;
    VlWide<7>/*223:0*/ __Vtemp680;
    VlWide<23>/*735:0*/ __Vtemp683;
    VlWide<16>/*511:0*/ __Vtemp684;
    VlWide<3>/*95:0*/ __Vtemp770;
    VlWide<4>/*127:0*/ __Vtemp811;
    VlWide<4>/*127:0*/ __Vtemp812;
    VlWide<19>/*607:0*/ __Vtemp822;
    VlWide<3>/*95:0*/ __Vtemp829;
    VlWide<3>/*95:0*/ __Vtemp832;
    VlWide<3>/*95:0*/ __Vtemp838;
    VlWide<16>/*511:0*/ __Vtemp845;
    VlWide<3>/*95:0*/ __Vtemp847;
    VlWide<4>/*127:0*/ __Vtemp853;
    VlWide<8>/*255:0*/ __Vtemp854;
    VlWide<8>/*255:0*/ __Vtemp855;
    VlWide<8>/*255:0*/ __Vtemp856;
    VlWide<3>/*95:0*/ __Vtemp864;
    VlWide<11>/*351:0*/ __Vtemp865;
    VlWide<11>/*351:0*/ __Vtemp866;
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->SimTop__DOT__cli_aw_ready));
        tracep->fullBit(oldp+2,((1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))));
        tracep->fullBit(oldp+3,((1U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state))));
        tracep->fullBit(oldp+4,(vlTOPp->SimTop__DOT__cli_aw_valid));
        tracep->fullQData(oldp+5,((0xfffffffffffffff8ULL 
                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)),64);
        tracep->fullQData(oldp+7,((0xfffffffffffffff8ULL 
                                   & vlTOPp->SimTop__DOT__if_rw_addr)),64);
        tracep->fullQData(oldp+9,(((- (QData)((IData)(
                                                      (1U 
                                                       == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state))))) 
                                   & vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_addr)),64);
        tracep->fullCData(oldp+11,((1U & (- (IData)(
                                                    (1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)))))),4);
        tracep->fullCData(oldp+12,(((- (IData)((1U 
                                                == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_id))),4);
        tracep->fullCData(oldp+13,(((- (IData)((1U 
                                                == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)))) 
                                    & (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_len))),8);
        tracep->fullCData(oldp+14,(((- (IData)((1U 
                                                == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state)))) 
                                    & (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len))),8);
        tracep->fullCData(oldp+15,(((- (IData)((1U 
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
        tracep->fullCData(oldp+16,((3U & (- (IData)(
                                                    (1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)))))),3);
        tracep->fullCData(oldp+17,((3U & (- (IData)(
                                                    (1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state)))))),3);
        tracep->fullCData(oldp+18,(((- (IData)((1U 
                                                == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_size))),3);
        tracep->fullCData(oldp+19,(vlTOPp->SimTop__DOT__cli_aw_burst),2);
        tracep->fullCData(oldp+20,((2U & ((- (IData)(
                                                     (1U 
                                                      == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                          & ((- (IData)(
                                                        (1U 
                                                         == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                             | (- (IData)(
                                                          (2U 
                                                           == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))))))),4);
        tracep->fullBit(oldp+21,(vlTOPp->SimTop__DOT__cli_w_valid));
        tracep->fullBit(oldp+22,((2U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))));
        tracep->fullBit(oldp+23,((2U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state))));
        tracep->fullQData(oldp+24,(vlTOPp->SimTop__DOT__mem_axi_w_data),64);
        tracep->fullQData(oldp+26,(vlTOPp->SimTop__DOT__if_axi_w_data),64);
        tracep->fullQData(oldp+28,(vlTOPp->SimTop__DOT__cli_w_data),64);
        tracep->fullCData(oldp+30,(vlTOPp->SimTop__DOT__mem_axi_w_strb),8);
        tracep->fullCData(oldp+31,(vlTOPp->SimTop__DOT__if_axi_w_strb),8);
        tracep->fullCData(oldp+32,(((- (IData)((1U 
                                                == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_strb))),8);
        tracep->fullBit(oldp+33,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                  & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_last))));
        tracep->fullBit(oldp+34,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                  & (1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))));
        tracep->fullBit(oldp+35,((3U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))));
        tracep->fullBit(oldp+36,((3U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state))));
        tracep->fullBit(oldp+37,(vlTOPp->SimTop__DOT__cli_b_ready));
        tracep->fullBit(oldp+38,((2U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__w_state))));
        tracep->fullCData(oldp+39,(vlTOPp->SimTop__DOT__Clint__DOT__wr_id_reg),4);
        tracep->fullBit(oldp+40,(vlTOPp->SimTop__DOT__Clint__DOT__wr_user_reg));
        tracep->fullBit(oldp+41,(vlTOPp->SimTop__DOT__cli_ar_ready));
        tracep->fullBit(oldp+42,((1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))));
        tracep->fullBit(oldp+43,((1U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state))));
        tracep->fullBit(oldp+44,(vlTOPp->SimTop__DOT__cli_ar_valid));
        tracep->fullQData(oldp+45,(((- (QData)((IData)(
                                                       (1U 
                                                        == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state))))) 
                                    & vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_addr)),64);
        tracep->fullCData(oldp+47,((1U & (- (IData)(
                                                    (1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state)))))),4);
        tracep->fullCData(oldp+48,(((- (IData)((1U 
                                                == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_id))),4);
        tracep->fullCData(oldp+49,(((- (IData)((1U 
                                                == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state)))) 
                                    & (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_len))),8);
        tracep->fullCData(oldp+50,(((- (IData)((1U 
                                                == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state)))) 
                                    & (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len))),8);
        tracep->fullCData(oldp+51,(((- (IData)((1U 
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
        tracep->fullCData(oldp+52,((3U & (- (IData)(
                                                    (1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state)))))),3);
        tracep->fullCData(oldp+53,((3U & (- (IData)(
                                                    (1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state)))))),3);
        tracep->fullCData(oldp+54,(((- (IData)((1U 
                                                == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_size))),3);
        tracep->fullCData(oldp+55,((2U & ((- (IData)(
                                                     (1U 
                                                      == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                          & ((- (IData)(
                                                        (1U 
                                                         == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                             | (- (IData)(
                                                          (2U 
                                                           == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))))))),4);
        tracep->fullBit(oldp+56,((2U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))));
        tracep->fullBit(oldp+57,((2U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state))));
        tracep->fullBit(oldp+58,(vlTOPp->SimTop__DOT__cli_r_ready));
        tracep->fullQData(oldp+59,((((((- (QData)((IData)(
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
        tracep->fullCData(oldp+61,(vlTOPp->SimTop__DOT__Clint__DOT__rd_id_reg),4);
        tracep->fullBit(oldp+62,(vlTOPp->SimTop__DOT__Clint__DOT__rd_user_reg));
        tracep->fullBit(oldp+63,((1U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state))));
        tracep->fullBit(oldp+64,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__rw_ready));
        tracep->fullQData(oldp+65,(vlTOPp->SimTop__DOT__if_r_data),64);
        tracep->fullQData(oldp+67,(vlTOPp->SimTop__DOT__if_rw_addr),64);
        tracep->fullCData(oldp+69,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__rw_resp),2);
        tracep->fullBit(oldp+70,((1U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state))));
        tracep->fullBit(oldp+71,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__rw_ready));
        tracep->fullBit(oldp+72,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena));
        tracep->fullQData(oldp+73,(vlTOPp->SimTop__DOT__mem_r_data),64);
        tracep->fullQData(oldp+75,(vlTOPp->SimTop__DOT__mem_w_data),64);
        tracep->fullQData(oldp+77,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr),64);
        tracep->fullCData(oldp+79,(vlTOPp->SimTop__DOT__mem_rw_size),2);
        tracep->fullCData(oldp+80,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__rw_resp),2);
        tracep->fullSData(oldp+81,(vlTOPp->SimTop__DOT__clint_interupt_bus),12);
        tracep->fullQData(oldp+82,(((- (QData)((IData)(
                                                       (2U 
                                                        == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state))))) 
                                    & vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_data)),64);
        tracep->fullCData(oldp+84,((1U & ((- (IData)(
                                                     (1U 
                                                      == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                          & (- (IData)(
                                                       (1U 
                                                        == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))))))),4);
        tracep->fullBit(oldp+85,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_valid));
        tracep->fullQData(oldp+86,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_addr),64);
        tracep->fullCData(oldp+88,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_id),4);
        tracep->fullCData(oldp+89,((((- (IData)((1U 
                                                 == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                     & ((- (IData)(
                                                   (1U 
                                                    == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)))) 
                                        & (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_len))) 
                                    | ((- (IData)((2U 
                                                   == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                       & ((- (IData)(
                                                     (1U 
                                                      == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state)))) 
                                          & (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len))))),8);
        tracep->fullCData(oldp+90,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_size),3);
        tracep->fullCData(oldp+91,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_burst),2);
        tracep->fullCData(oldp+92,((2U & ((- (IData)(
                                                     (1U 
                                                      == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                          | (- (IData)(
                                                       (2U 
                                                        == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))))))),4);
        tracep->fullBit(oldp+93,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_last));
        tracep->fullQData(oldp+94,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_data),64);
        tracep->fullCData(oldp+96,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_strb),8);
        tracep->fullCData(oldp+97,((1U & (- (IData)(
                                                    (1U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))))),4);
        tracep->fullBit(oldp+98,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_b_ready));
        tracep->fullBit(oldp+99,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_valid));
        tracep->fullQData(oldp+100,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_addr),64);
        tracep->fullCData(oldp+102,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_id),4);
        tracep->fullCData(oldp+103,((((- (IData)((1U 
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
        tracep->fullCData(oldp+104,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_size),3);
        tracep->fullCData(oldp+105,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_burst),2);
        tracep->fullCData(oldp+106,((2U & ((- (IData)(
                                                      (1U 
                                                       == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                           | (- (IData)(
                                                        (2U 
                                                         == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state))))))),4);
        tracep->fullBit(oldp+107,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_ready));
        tracep->fullBit(oldp+108,(((IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_ready) 
                                   & (1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))));
        tracep->fullBit(oldp+109,((((IData)(vlTOPp->SimTop__DOT__cli_b_ready) 
                                    & (2U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__w_state))) 
                                   & (1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))));
        tracep->fullCData(oldp+110,(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state),2);
        tracep->fullCData(oldp+111,(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state),2);
        tracep->fullBit(oldp+112,((0x200ULL == (0xffffffffffffULL 
                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr 
                                                   >> 0x10U)))));
        tracep->fullBit(oldp+113,((0x200ULL != (0xffffffffffffULL 
                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr 
                                                   >> 0x10U)))));
        tracep->fullBit(oldp+114,((0x200ULL == (0xffffffffffffULL 
                                                & (vlTOPp->SimTop__DOT__if_rw_addr 
                                                   >> 0x10U)))));
        tracep->fullBit(oldp+115,((0x200ULL != (0xffffffffffffULL 
                                                & (vlTOPp->SimTop__DOT__if_rw_addr 
                                                   >> 0x10U)))));
        tracep->fullCData(oldp+116,(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state),2);
        tracep->fullCData(oldp+117,(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state),2);
        tracep->fullBit(oldp+118,((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))));
        tracep->fullBit(oldp+119,((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state))));
        tracep->fullBit(oldp+120,((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state))));
        tracep->fullBit(oldp+121,((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state))));
        tracep->fullBit(oldp+122,((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state))));
        tracep->fullBit(oldp+123,((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state))));
        tracep->fullBit(oldp+124,((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state))));
        tracep->fullBit(oldp+125,((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state))));
        tracep->fullBit(oldp+126,((1U & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena)))));
        tracep->fullBit(oldp+127,(((1U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state)) 
                                   & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena))));
        tracep->fullBit(oldp+128,(((1U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state)) 
                                   & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena)))));
        tracep->fullCData(oldp+129,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state),3);
        tracep->fullCData(oldp+130,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state),3);
        tracep->fullBit(oldp+131,((0U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))));
        tracep->fullBit(oldp+132,((0U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))));
        tracep->fullCData(oldp+133,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__len),8);
        tracep->fullBit(oldp+134,((0U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
        tracep->fullBit(oldp+135,((0U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))));
        tracep->fullBit(oldp+136,((1U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))));
        tracep->fullBit(oldp+137,((2U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))));
        tracep->fullBit(oldp+138,((3U == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))));
        tracep->fullCData(oldp+139,((7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))),4);
        tracep->fullCData(oldp+140,((((1U & (- (IData)(
                                                       (1U 
                                                        == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                                      | (3U & (- (IData)(
                                                         (2U 
                                                          == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))) 
                                     | (7U & (- (IData)(
                                                        (3U 
                                                         == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))))),4);
        tracep->fullCData(oldp+141,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__addr_end),4);
        tracep->fullBit(oldp+142,((1U & ((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__addr_end) 
                                         >> 3U))));
        tracep->fullCData(oldp+143,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_len),8);
        tracep->fullCData(oldp+144,((0x38U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                                              << 3U))),6);
        tracep->fullCData(oldp+145,((0x3fU & (- (0x38U 
                                                 & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                                                    << 3U))))),6);
        tracep->fullWData(oldp+146,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask),128);
        tracep->fullQData(oldp+150,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[0U])))),64);
        tracep->fullQData(oldp+152,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[3U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[2U])))),64);
        tracep->fullCData(oldp+154,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state),3);
        tracep->fullCData(oldp+155,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state),3);
        tracep->fullBit(oldp+156,((0U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state))));
        tracep->fullBit(oldp+157,((0U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state))));
        tracep->fullCData(oldp+158,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__len),8);
        tracep->fullBit(oldp+159,((0U == (7U & (IData)(vlTOPp->SimTop__DOT__if_rw_addr)))));
        tracep->fullCData(oldp+160,((7U & (IData)(vlTOPp->SimTop__DOT__if_rw_addr))),4);
        tracep->fullCData(oldp+161,((0xfU & ((IData)(3U) 
                                             + (7U 
                                                & (IData)(vlTOPp->SimTop__DOT__if_rw_addr))))),4);
        tracep->fullBit(oldp+162,((1U & (((IData)(3U) 
                                          + (7U & (IData)(vlTOPp->SimTop__DOT__if_rw_addr))) 
                                         >> 3U))));
        tracep->fullCData(oldp+163,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len),8);
        tracep->fullCData(oldp+164,((0x38U & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                              << 3U))),6);
        tracep->fullCData(oldp+165,((0x3fU & (- (0x38U 
                                                 & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                                    << 3U))))),6);
        __Vtemp650[0U] = 0xffffffffU;
        __Vtemp650[1U] = 0U;
        __Vtemp650[2U] = 0U;
        __Vtemp650[3U] = 0U;
        VL_SHIFTL_WWI(128,128,6, __Vtemp651, __Vtemp650, 
                      (0x38U & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                << 3U)));
        tracep->fullWData(oldp+166,(__Vtemp651),128);
        __Vtemp652[0U] = 0xffffffffU;
        __Vtemp652[1U] = 0U;
        __Vtemp652[2U] = 0U;
        __Vtemp652[3U] = 0U;
        VL_SHIFTL_WWI(128,128,6, __Vtemp653, __Vtemp652, 
                      (0x38U & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                << 3U)));
        tracep->fullQData(oldp+170,((((QData)((IData)(
                                                      __Vtemp653[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  __Vtemp653[0U])))),64);
        __Vtemp654[0U] = 0xffffffffU;
        __Vtemp654[1U] = 0U;
        __Vtemp654[2U] = 0U;
        __Vtemp654[3U] = 0U;
        VL_SHIFTL_WWI(128,128,6, __Vtemp655, __Vtemp654, 
                      (0x38U & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                << 3U)));
        tracep->fullQData(oldp+172,((((QData)((IData)(
                                                      __Vtemp655[3U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  __Vtemp655[2U])))),64);
        tracep->fullBit(oldp+174,(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_valid));
        tracep->fullBit(oldp+175,(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_to_wb_valid));
        tracep->fullBit(oldp+176,(vlTOPp->SimTop__DOT__u_cpu__DOT__id_allowin));
        tracep->fullBit(oldp+177,(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_allowin));
        tracep->fullBit(oldp+178,(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_allowin));
        tracep->fullBit(oldp+179,(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake));
        tracep->fullQData(oldp+180,(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_pc),64);
        tracep->fullQData(oldp+182,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_pc_r),64);
        tracep->fullQData(oldp+184,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r),64);
        tracep->fullQData(oldp+186,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_pc_r),64);
        tracep->fullIData(oldp+188,(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_inst),32);
        tracep->fullIData(oldp+189,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r),32);
        tracep->fullIData(oldp+190,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_inst_r),32);
        tracep->fullIData(oldp+191,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_inst_r),32);
        __Vtemp680[0U] = (IData)((((QData)((IData)(
                                                   (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[2U] 
                                                    & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                   << 0x35U) | (((QData)((IData)(
                                                                 (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[1U] 
                                                                  & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                                 << 0x15U) 
                                                | ((QData)((IData)(
                                                                   (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
                                                                    & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                                   >> 0xbU))));
        __Vtemp680[1U] = (IData)(((((QData)((IData)(
                                                    (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[2U] 
                                                     & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                    << 0x35U) | (((QData)((IData)(
                                                                  (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[1U] 
                                                                   & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                                  << 0x15U) 
                                                 | ((QData)((IData)(
                                                                    (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
                                                                     & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                                    >> 0xbU))) 
                                  >> 0x20U));
        __Vtemp680[2U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_data);
        __Vtemp680[3U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_data 
                                  >> 0x20U));
        __Vtemp680[4U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr);
        __Vtemp680[5U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr 
                                  >> 0x20U));
        __Vtemp680[6U] = ((0x20000U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[6U] 
                                        & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                                       >> 0xdU)) | 
                          ((0x1fe00U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[6U] 
                                         & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                                        >> 0xdU)) | 
                           ((0xffffff00U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ena) 
                                            << 8U)) 
                            | ((0xfffffff8U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_addr) 
                                               << 3U)) 
                               | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ctrl)))));
        tracep->fullWData(oldp+192,(__Vtemp680),210);
        tracep->fullBit(oldp+199,(((0x7bU == (0x7fU 
                                              & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                   | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                      & ((0xb00U == 
                                          (0xfffU & 
                                           (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                            >> 0x14U))) 
                                         | (0x344U 
                                            == (0xfffU 
                                                & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0x14U))))))));
        __Vtemp683[0U] = ((0xfffffc00U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data) 
                                          << 0xaU)) 
                          | ((0x3fcU & ((((((1U & (- (IData)(
                                                             (0U 
                                                              == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                                            | (3U & 
                                               (- (IData)(
                                                          (1U 
                                                           == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))) 
                                           | (0xfU 
                                              & (- (IData)(
                                                           (2U 
                                                            == (IData)(vlTOPp->SimTop__DOT__mem_rw_size)))))) 
                                          | (- (IData)(
                                                       (3U 
                                                        == (IData)(vlTOPp->SimTop__DOT__mem_rw_size))))) 
                                         << (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))) 
                                        << 2U)) | (
                                                   ((IData)(
                                                            (0U 
                                                             != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info))) 
                                                    << 1U) 
                                                   | (0U 
                                                      != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info)))));
        __Vtemp683[1U] = ((0x3ffU & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data) 
                                     >> 0x16U)) | (0xfffffc00U 
                                                   & ((IData)(
                                                              (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data 
                                                               >> 0x20U)) 
                                                      << 0xaU)));
        __Vtemp683[2U] = ((0x3ffU & ((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data 
                                              >> 0x20U)) 
                                     >> 0x16U)) | (0xfffffc00U 
                                                   & ((IData)(
                                                              (0xfffffffffffffff8ULL 
                                                               & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)) 
                                                      << 0xaU)));
        __Vtemp683[3U] = ((0x3ffU & ((IData)((0xfffffffffffffff8ULL 
                                              & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)) 
                                     >> 0x16U)) | (0xfffffc00U 
                                                   & ((IData)(
                                                              ((0xfffffffffffffff8ULL 
                                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                                                               >> 0x20U)) 
                                                      << 0xaU)));
        __Vtemp683[4U] = ((0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0U] 
                                          << 0xaU)) 
                          | (0x3ffU & ((IData)(((0xfffffffffffffff8ULL 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                                                >> 0x20U)) 
                                       >> 0x16U)));
        __Vtemp683[5U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0U] 
                                     >> 0x16U)) | (0xfffffc00U 
                                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[1U] 
                                                      << 0xaU)));
        __Vtemp683[6U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[1U] 
                                     >> 0x16U)) | (0xfffffc00U 
                                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[2U] 
                                                      << 0xaU)));
        __Vtemp683[7U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[2U] 
                                     >> 0x16U)) | (0xfffffc00U 
                                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[3U] 
                                                      << 0xaU)));
        __Vtemp683[8U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[3U] 
                                     >> 0x16U)) | (0xfffffc00U 
                                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[4U] 
                                                      << 0xaU)));
        __Vtemp683[9U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[4U] 
                                     >> 0x16U)) | (0xfffffc00U 
                                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[5U] 
                                                      << 0xaU)));
        __Vtemp683[0xaU] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[5U] 
                                       >> 0x16U)) | 
                            (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[6U] 
                                            << 0xaU)));
        __Vtemp683[0xbU] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[6U] 
                                       >> 0x16U)) | 
                            (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[7U] 
                                            << 0xaU)));
        __Vtemp683[0xcU] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[7U] 
                                       >> 0x16U)) | 
                            (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[8U] 
                                            << 0xaU)));
        __Vtemp683[0xdU] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[8U] 
                                       >> 0x16U)) | 
                            (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[9U] 
                                            << 0xaU)));
        __Vtemp683[0xeU] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[9U] 
                                       >> 0x16U)) | 
                            (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xaU] 
                                            << 0xaU)));
        __Vtemp683[0xfU] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xaU] 
                                       >> 0x16U)) | 
                            (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xbU] 
                                            << 0xaU)));
        __Vtemp683[0x10U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xbU] 
                                        >> 0x16U)) 
                             | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xcU] 
                                               << 0xaU)));
        __Vtemp683[0x11U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xcU] 
                                        >> 0x16U)) 
                             | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xdU] 
                                               << 0xaU)));
        __Vtemp683[0x12U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xdU] 
                                        >> 0x16U)) 
                             | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xeU] 
                                               << 0xaU)));
        __Vtemp683[0x13U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xeU] 
                                        >> 0x16U)) 
                             | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xfU] 
                                               << 0xaU)));
        __Vtemp683[0x14U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0xfU] 
                                        >> 0x16U)) 
                             | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x10U] 
                                               << 0xaU)));
        __Vtemp683[0x15U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x10U] 
                                        >> 0x16U)) 
                             | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x11U] 
                                               << 0xaU)));
        __Vtemp683[0x16U] = ((0x3ffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x11U] 
                                        >> 0x16U)) 
                             | (0xfffffc00U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r[0x12U] 
                                               << 0xaU)));
        tracep->fullWData(oldp+200,(__Vtemp683),715);
        tracep->fullWData(oldp+223,(vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus),812);
        tracep->fullWData(oldp+249,(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus),73);
        tracep->fullWData(oldp+252,(vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus),137);
        tracep->fullBit(oldp+257,((0U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state))));
        tracep->fullBit(oldp+258,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld));
        tracep->fullSData(oldp+259,((0xfffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                               >> 0x14U))),12);
        tracep->fullBit(oldp+260,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_ena));
        tracep->fullSData(oldp+261,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr),12);
        tracep->fullBit(oldp+262,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter));
        tracep->fullBit(oldp+263,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_exit));
        tracep->fullWData(oldp+264,(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus),320);
        tracep->fullCData(oldp+274,(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr),5);
        tracep->fullCData(oldp+275,(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr),5);
        tracep->fullBit(oldp+276,(vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_ena));
        tracep->fullCData(oldp+277,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_wdest),5);
        tracep->fullQData(oldp+278,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0]),64);
        tracep->fullQData(oldp+280,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[1]),64);
        tracep->fullQData(oldp+282,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[2]),64);
        tracep->fullQData(oldp+284,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[3]),64);
        tracep->fullQData(oldp+286,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[4]),64);
        tracep->fullQData(oldp+288,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[5]),64);
        tracep->fullQData(oldp+290,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[6]),64);
        tracep->fullQData(oldp+292,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[7]),64);
        tracep->fullQData(oldp+294,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[8]),64);
        tracep->fullQData(oldp+296,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[9]),64);
        tracep->fullQData(oldp+298,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[10]),64);
        tracep->fullQData(oldp+300,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[11]),64);
        tracep->fullQData(oldp+302,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[12]),64);
        tracep->fullQData(oldp+304,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[13]),64);
        tracep->fullQData(oldp+306,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[14]),64);
        tracep->fullQData(oldp+308,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[15]),64);
        tracep->fullQData(oldp+310,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[16]),64);
        tracep->fullQData(oldp+312,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[17]),64);
        tracep->fullQData(oldp+314,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[18]),64);
        tracep->fullQData(oldp+316,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[19]),64);
        tracep->fullQData(oldp+318,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[20]),64);
        tracep->fullQData(oldp+320,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[21]),64);
        tracep->fullQData(oldp+322,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[22]),64);
        tracep->fullQData(oldp+324,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[23]),64);
        tracep->fullQData(oldp+326,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[24]),64);
        tracep->fullQData(oldp+328,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[25]),64);
        tracep->fullQData(oldp+330,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[26]),64);
        tracep->fullQData(oldp+332,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[27]),64);
        tracep->fullQData(oldp+334,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[28]),64);
        tracep->fullQData(oldp+336,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[29]),64);
        tracep->fullQData(oldp+338,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[30]),64);
        tracep->fullQData(oldp+340,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[31]),64);
        tracep->fullBit(oldp+342,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wen));
        tracep->fullCData(oldp+343,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wdest),8);
        tracep->fullQData(oldp+344,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wdata),64);
        tracep->fullQData(oldp+346,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_pc),64);
        tracep->fullIData(oldp+348,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_inst),32);
        tracep->fullBit(oldp+349,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_valid));
        tracep->fullBit(oldp+350,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_skip));
        tracep->fullIData(oldp+351,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_itrp_NO),32);
        tracep->fullIData(oldp+352,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_excp_NO),32);
        tracep->fullQData(oldp+353,(vlTOPp->SimTop__DOT__u_cpu__DOT__cycleCnt),64);
        tracep->fullQData(oldp+355,(vlTOPp->SimTop__DOT__u_cpu__DOT__instrCnt),64);
        tracep->fullQData(oldp+357,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[3U])) 
                                      << 0x3fU) | (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[2U])) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[1U])) 
                                                      >> 1U)))),64);
        tracep->fullQData(oldp+359,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[7U])) 
                                      << 0x35U) | (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[6U])) 
                                                    << 0x15U) 
                                                   | ((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[5U])) 
                                                      >> 0xbU)))),64);
        tracep->fullQData(oldp+361,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[5U])) 
                                      << 0x35U) | (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[4U])) 
                                                    << 0x15U) 
                                                   | ((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[3U])) 
                                                      >> 0xbU)))),64);
        tracep->fullIData(oldp+363,(((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[1U] 
                                      << 0x1fU) | (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0U] 
                                                   >> 1U))),32);
        tracep->fullBit(oldp+364,((1U & vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0U])));
        tracep->fullBit(oldp+365,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[3U] 
                                         >> 2U))));
        tracep->fullBit(oldp+366,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[3U] 
                                         >> 1U))));
        tracep->fullBit(oldp+367,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x19U] 
                                         >> 0xbU))));
        tracep->fullCData(oldp+368,((0xffU & ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[4U] 
                                               << 0x1dU) 
                                              | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[3U] 
                                                 >> 3U)))),8);
        tracep->fullIData(oldp+369,(((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[9U] 
                                      << 0x15U) | (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[8U] 
                                                   >> 0xbU))),32);
        tracep->fullIData(oldp+370,(((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[8U] 
                                      << 0x15U) | (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[7U] 
                                                   >> 0xbU))),32);
        __Vtemp684[0U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xaU] 
                           << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[9U] 
                                        >> 0xbU));
        __Vtemp684[1U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xbU] 
                           << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xaU] 
                                        >> 0xbU));
        __Vtemp684[2U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xcU] 
                           << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xbU] 
                                        >> 0xbU));
        __Vtemp684[3U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xdU] 
                           << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xcU] 
                                        >> 0xbU));
        __Vtemp684[4U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xeU] 
                           << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xdU] 
                                        >> 0xbU));
        __Vtemp684[5U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xfU] 
                           << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xeU] 
                                        >> 0xbU));
        __Vtemp684[6U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x10U] 
                           << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xfU] 
                                        >> 0xbU));
        __Vtemp684[7U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x11U] 
                           << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x10U] 
                                        >> 0xbU));
        __Vtemp684[8U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x12U] 
                           << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x11U] 
                                        >> 0xbU));
        __Vtemp684[9U] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x13U] 
                           << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x12U] 
                                        >> 0xbU));
        __Vtemp684[0xaU] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x14U] 
                             << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x13U] 
                                          >> 0xbU));
        __Vtemp684[0xbU] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x15U] 
                             << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x14U] 
                                          >> 0xbU));
        __Vtemp684[0xcU] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x16U] 
                             << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x15U] 
                                          >> 0xbU));
        __Vtemp684[0xdU] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x17U] 
                             << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x16U] 
                                          >> 0xbU));
        __Vtemp684[0xeU] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x18U] 
                             << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x17U] 
                                          >> 0xbU));
        __Vtemp684[0xfU] = ((vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x19U] 
                             << 0x15U) | (vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x18U] 
                                          >> 0xbU));
        tracep->fullWData(oldp+371,(__Vtemp684),512);
        tracep->fullQData(oldp+387,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x19U])) 
                                      << 0x35U) | (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x18U])) 
                                                    << 0x15U) 
                                                   | ((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x17U])) 
                                                      >> 0xbU)))),64);
        tracep->fullQData(oldp+389,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x17U])) 
                                      << 0x35U) | (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x16U])) 
                                                    << 0x15U) 
                                                   | ((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x15U])) 
                                                      >> 0xbU)))),64);
        tracep->fullQData(oldp+391,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x15U])) 
                                      << 0x35U) | (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x14U])) 
                                                    << 0x15U) 
                                                   | ((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x13U])) 
                                                      >> 0xbU)))),64);
        tracep->fullQData(oldp+393,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x13U])) 
                                      << 0x35U) | (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x12U])) 
                                                    << 0x15U) 
                                                   | ((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x11U])) 
                                                      >> 0xbU)))),64);
        tracep->fullQData(oldp+395,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x11U])) 
                                      << 0x35U) | (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0x10U])) 
                                                    << 0x15U) 
                                                   | ((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xfU])) 
                                                      >> 0xbU)))),64);
        tracep->fullQData(oldp+397,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xfU])) 
                                      << 0x35U) | (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xeU])) 
                                                    << 0x15U) 
                                                   | ((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xdU])) 
                                                      >> 0xbU)))),64);
        tracep->fullQData(oldp+399,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xdU])) 
                                      << 0x35U) | (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xcU])) 
                                                    << 0x15U) 
                                                   | ((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xbU])) 
                                                      >> 0xbU)))),64);
        tracep->fullQData(oldp+401,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xbU])) 
                                      << 0x35U) | (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[0xaU])) 
                                                    << 0x15U) 
                                                   | ((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__difftest_bus[9U])) 
                                                      >> 0xbU)))),64);
        tracep->fullQData(oldp+403,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mstatus),64);
        tracep->fullQData(oldp+405,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mepc),64);
        tracep->fullQData(oldp+407,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mtval),64);
        tracep->fullQData(oldp+409,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mtvec),64);
        tracep->fullQData(oldp+411,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mcause),64);
        tracep->fullQData(oldp+413,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mip),64);
        tracep->fullQData(oldp+415,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mie),64);
        tracep->fullQData(oldp+417,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mscratch),64);
        tracep->fullQData(oldp+419,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_rw_addr),64);
        tracep->fullQData(oldp+421,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_data),64);
        tracep->fullQData(oldp+423,(vlTOPp->SimTop__DOT__u_cpu__DOT__buf_rw_addr),64);
        tracep->fullQData(oldp+425,(vlTOPp->SimTop__DOT__u_cpu__DOT__buf_w_data),64);
        tracep->fullCData(oldp+427,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_mask),8);
        tracep->fullCData(oldp+428,(vlTOPp->SimTop__DOT__u_cpu__DOT__buf_w_mask),8);
        tracep->fullBit(oldp+429,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_ena));
        tracep->fullBit(oldp+430,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_r_ena));
        tracep->fullBit(oldp+431,(vlTOPp->SimTop__DOT__u_cpu__DOT__buf_w_ena));
        tracep->fullBit(oldp+432,(vlTOPp->SimTop__DOT__u_cpu__DOT__buf_r_ena));
        tracep->fullBit(oldp+433,((2U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state))));
        tracep->fullCData(oldp+434,(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state),2);
        tracep->fullBit(oldp+435,(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_valid));
        tracep->fullBit(oldp+436,(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_allowin));
        tracep->fullBit(oldp+437,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_valid));
        tracep->fullCData(oldp+438,((0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)),7);
        tracep->fullCData(oldp+439,((7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0xcU))),3);
        tracep->fullCData(oldp+440,((0x3fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                              >> 0x1aU))),6);
        tracep->fullCData(oldp+441,((0x7fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                              >> 0x19U))),7);
        tracep->fullCData(oldp+442,((0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+443,((0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                              >> 7U))),5);
        tracep->fullSData(oldp+444,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immS),12);
        tracep->fullSData(oldp+445,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immB),13);
        tracep->fullIData(oldp+446,((0xfffffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0xcU))),20);
        tracep->fullIData(oldp+447,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__immJ),21);
        tracep->fullBit(oldp+448,((0U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+449,((1U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+450,((2U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+451,((3U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+452,((4U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+453,((5U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+454,((6U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+455,((7U == (7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0xcU)))));
        tracep->fullBit(oldp+456,((0U == (0x3fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0x1aU)))));
        tracep->fullBit(oldp+457,((0x10U == (0x3fU 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0x1aU)))));
        tracep->fullBit(oldp+458,((0U == (0x7fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                   >> 0x19U)))));
        tracep->fullBit(oldp+459,((0x20U == (0x7fU 
                                             & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                >> 0x19U)))));
        tracep->fullBit(oldp+460,((0U == (0xfffU & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U)))));
        tracep->fullBit(oldp+461,((1U == (0xfffU & 
                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                           >> 0x14U)))));
        tracep->fullBit(oldp+462,((0x302U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+463,((3U == (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
        tracep->fullBit(oldp+464,((0xfU == (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
        tracep->fullBit(oldp+465,((0x13U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
        tracep->fullBit(oldp+466,((0x17U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
        tracep->fullBit(oldp+467,((0x1bU == (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
        tracep->fullBit(oldp+468,((0x23U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
        tracep->fullBit(oldp+469,((0x33U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
        tracep->fullBit(oldp+470,((0x37U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
        tracep->fullBit(oldp+471,((0x3bU == (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
        tracep->fullBit(oldp+472,((0x63U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
        tracep->fullBit(oldp+473,((0x67U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
        tracep->fullBit(oldp+474,((0x6fU == (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
        tracep->fullBit(oldp+475,((0x73U == (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
        tracep->fullBit(oldp+476,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_excp));
        tracep->fullBit(oldp+477,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm));
        tracep->fullBit(oldp+478,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg));
        tracep->fullBit(oldp+479,((0x7bU == (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))));
        tracep->fullBit(oldp+480,(((0x3bU == (0x7fU 
                                              & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                   | (0x1bU == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))));
        tracep->fullBit(oldp+481,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lb));
        tracep->fullBit(oldp+482,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lh));
        tracep->fullBit(oldp+483,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lw));
        tracep->fullBit(oldp+484,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ld));
        tracep->fullBit(oldp+485,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lbu));
        tracep->fullBit(oldp+486,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lhu));
        tracep->fullBit(oldp+487,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lwu));
        tracep->fullBit(oldp+488,((((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lb) 
                                        | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lh)) 
                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lw)) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ld)) 
                                     | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lbu)) 
                                    | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lhu)) 
                                   | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lwu))));
        tracep->fullBit(oldp+489,((IData)((0xfU == 
                                           (0x707fU 
                                            & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))));
        tracep->fullBit(oldp+490,((IData)((0x100fU 
                                           == (0x707fU 
                                               & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))));
        tracep->fullBit(oldp+491,(((IData)((0xfU == 
                                            (0x707fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                   | (IData)((0x100fU 
                                              == (0x707fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))));
        tracep->fullBit(oldp+492,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addi));
        tracep->fullBit(oldp+493,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slli));
        tracep->fullBit(oldp+494,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slti));
        tracep->fullBit(oldp+495,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sltiu));
        tracep->fullBit(oldp+496,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_xori));
        tracep->fullBit(oldp+497,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srli));
        tracep->fullBit(oldp+498,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srai));
        tracep->fullBit(oldp+499,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ori));
        tracep->fullBit(oldp+500,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_andi));
        tracep->fullBit(oldp+501,((((((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addi) 
                                          | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slli)) 
                                         | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slti)) 
                                        | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sltiu)) 
                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_xori)) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srli)) 
                                     | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srai)) 
                                    | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ori)) 
                                   | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_andi))));
        tracep->fullBit(oldp+502,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addiw));
        tracep->fullBit(oldp+503,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slliw));
        tracep->fullBit(oldp+504,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srliw));
        tracep->fullBit(oldp+505,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sraiw));
        tracep->fullBit(oldp+506,(((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addiw) 
                                     | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slliw)) 
                                    | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srliw)) 
                                   | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sraiw))));
        tracep->fullBit(oldp+507,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sb));
        tracep->fullBit(oldp+508,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sh));
        tracep->fullBit(oldp+509,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sw));
        tracep->fullBit(oldp+510,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sd));
        tracep->fullBit(oldp+511,(((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sb) 
                                     | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sh)) 
                                    | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sw)) 
                                   | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sd))));
        tracep->fullBit(oldp+512,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_add));
        tracep->fullBit(oldp+513,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sub));
        tracep->fullBit(oldp+514,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sll));
        tracep->fullBit(oldp+515,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slt));
        tracep->fullBit(oldp+516,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sltu));
        tracep->fullBit(oldp+517,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_xor));
        tracep->fullBit(oldp+518,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srl));
        tracep->fullBit(oldp+519,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sra));
        tracep->fullBit(oldp+520,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_or));
        tracep->fullBit(oldp+521,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_and));
        tracep->fullBit(oldp+522,(((((((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_add) 
                                           | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sub)) 
                                          | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sll)) 
                                         | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_slt)) 
                                        | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sltu)) 
                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_xor)) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srl)) 
                                     | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sra)) 
                                    | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_or)) 
                                   | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_and))));
        tracep->fullBit(oldp+523,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addw));
        tracep->fullBit(oldp+524,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_subw));
        tracep->fullBit(oldp+525,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sllw));
        tracep->fullBit(oldp+526,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srlw));
        tracep->fullBit(oldp+527,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sraw));
        tracep->fullBit(oldp+528,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addw) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_subw)) 
                                     | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sllw)) 
                                    | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_srlw)) 
                                   | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sraw))));
        tracep->fullBit(oldp+529,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_beq));
        tracep->fullBit(oldp+530,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bne));
        tracep->fullBit(oldp+531,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_blt));
        tracep->fullBit(oldp+532,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bge));
        tracep->fullBit(oldp+533,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bltu));
        tracep->fullBit(oldp+534,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bgeu));
        tracep->fullBit(oldp+535,(((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_beq) 
                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bne)) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_blt)) 
                                     | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bge)) 
                                    | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bltu)) 
                                   | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_bgeu))));
        tracep->fullBit(oldp+536,(((0x67U == (0x7fU 
                                              & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                   | (0x6fU == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))));
        tracep->fullBit(oldp+537,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ecall));
        tracep->fullBit(oldp+538,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ebreak));
        tracep->fullBit(oldp+539,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_mret));
        tracep->fullBit(oldp+540,((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ecall) 
                                    | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_ebreak)) 
                                   | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_mret))));
        tracep->fullBit(oldp+541,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrw));
        tracep->fullBit(oldp+542,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrs));
        tracep->fullBit(oldp+543,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrc));
        tracep->fullBit(oldp+544,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrwi));
        tracep->fullBit(oldp+545,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrsi));
        tracep->fullBit(oldp+546,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_csrrci));
        tracep->fullBit(oldp+547,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_vld));
        tracep->fullSData(oldp+548,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info),12);
        tracep->fullCData(oldp+549,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_bj_info),8);
        tracep->fullCData(oldp+550,((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lwu) 
                                      << 6U) | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_lhu) 
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
        tracep->fullCData(oldp+551,((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sd) 
                                      << 3U) | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sw) 
                                                 << 2U) 
                                                | (((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sh) 
                                                    << 1U) 
                                                   | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_sb))))),4);
        tracep->fullBit(oldp+552,((((((((((3U == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                          | (0xfU == 
                                             (0x7fU 
                                              & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                         | (0x13U == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                        | (0x1bU == 
                                           (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                       | (0x23U == 
                                          (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                      | (0x33U == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                     | (0x3bU == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                    | (0x63U == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                   | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg))));
        tracep->fullBit(oldp+553,((((0x33U == (0x7fU 
                                               & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                    | (0x3bU == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                   | (0x63U == (0x7fU 
                                                & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))));
        tracep->fullBit(oldp+554,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm) 
                                   | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg))));
        tracep->fullQData(oldp+555,(((((- (QData)((IData)(
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
        tracep->fullSData(oldp+557,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_excp_bus),16);
        tracep->fullBit(oldp+558,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid));
        tracep->fullBit(oldp+559,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_ready_go));
        tracep->fullWData(oldp+560,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r),344);
        tracep->fullBit(oldp+571,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_diffbus_r));
        tracep->fullBit(oldp+572,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid));
        tracep->fullBit(oldp+573,((1U & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__hazard)))));
        tracep->fullBit(oldp+574,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_valid) 
                                   & (0U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state)))));
        tracep->fullBit(oldp+575,((1U & ((__Vconst88[0xaU] 
                                          & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[0xaU] 
                                             & (__Vconst72[0xaU] 
                                                & (- (IData)(
                                                             ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                              & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                         >> 0x15U))));
        tracep->fullQData(oldp+576,((((QData)((IData)(
                                                      (__Vconst88[9U] 
                                                       & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[9U] 
                                                          & (__Vconst72[9U] 
                                                             & (- (IData)(
                                                                          ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                           & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                      << 0x26U) | (
                                                   ((QData)((IData)(
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
        tracep->fullQData(oldp+578,((((QData)((IData)(
                                                      (__Vconst88[7U] 
                                                       & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[7U] 
                                                          & (__Vconst72[7U] 
                                                             & (- (IData)(
                                                                          ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                           & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                      << 0x26U) | (
                                                   ((QData)((IData)(
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
        tracep->fullBit(oldp+580,((1U & ((__Vconst88[5U] 
                                          & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                             & (__Vconst72[5U] 
                                                & (- (IData)(
                                                             ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                              & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                         >> 0x19U))));
        tracep->fullBit(oldp+581,((1U & ((__Vconst88[5U] 
                                          & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                             & (__Vconst72[5U] 
                                                & (- (IData)(
                                                             ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                              & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                         >> 0x18U))));
        tracep->fullBit(oldp+582,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_is_word_opt));
        tracep->fullSData(oldp+583,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info),12);
        tracep->fullCData(oldp+584,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_info),8);
        tracep->fullQData(oldp+585,((((QData)((IData)(
                                                      (__Vconst88[5U] 
                                                       & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                                          & (__Vconst72[5U] 
                                                             & (- (IData)(
                                                                          ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                           & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                      << 0x3dU) | (
                                                   ((QData)((IData)(
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
        tracep->fullCData(oldp+587,((0x7fU & (((__Vconst88[3U] 
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
        tracep->fullCData(oldp+588,((0xfU & (((__Vconst88[3U] 
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
        tracep->fullBit(oldp+589,((1U & ((__Vconst88[2U] 
                                          & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                             & (__Vconst72[2U] 
                                                & (- (IData)(
                                                             ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                              & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                         >> 0x17U))));
        tracep->fullBit(oldp+590,((1U & ((__Vconst88[2U] 
                                          & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                             & (__Vconst72[2U] 
                                                & (- (IData)(
                                                             ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                              & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))) 
                                         >> 0x16U))));
        tracep->fullCData(oldp+591,((7U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                            & (__Vconst72[2U] 
                                               & (- (IData)(
                                                            ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                             & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))))))) 
                                           >> 0x13U))),3);
        tracep->fullBit(oldp+592,((1U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                          & (__Vconst72[2U] 
                                             & (- (IData)(
                                                          ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                           & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))))))) 
                                         >> 0x12U))));
        tracep->fullCData(oldp+593,((0x1fU & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[2U] 
                                               & (__Vconst72[2U] 
                                                  & (- (IData)(
                                                               ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))))))) 
                                              >> 0xdU))),5);
        tracep->fullQData(oldp+594,(((((QData)((IData)(
                                                       vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[1U])) 
                                       << 0x20U) | (QData)((IData)(
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
        tracep->fullBit(oldp+596,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__hazard));
        tracep->fullSData(oldp+597,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus),16);
        tracep->fullBit(oldp+598,((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__meie_allowin) 
                                    | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__mtie_allowin)) 
                                   | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__msie_allowin))));
        tracep->fullQData(oldp+599,((((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter))) 
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
        tracep->fullBit(oldp+601,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__excp_jmp_ena));
        tracep->fullBit(oldp+602,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_valid));
        tracep->fullIData(oldp+603,(((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))) 
                                     & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx))),32);
        tracep->fullIData(oldp+604,(((- (IData)((0U 
                                                 != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus)))) 
                                     & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__excp_idx))),32);
        tracep->fullCData(oldp+605,((0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                              >> 4U))),5);
        tracep->fullCData(oldp+606,((0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                              >> 4U))),5);
        tracep->fullBit(oldp+607,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                         >> 3U))));
        tracep->fullBit(oldp+608,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                         >> 3U))));
        tracep->fullQData(oldp+609,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U])) 
                                      << 0x3dU) | (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[1U])) 
                                                    << 0x1dU) 
                                                   | ((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U])) 
                                                      >> 3U)))),64);
        tracep->fullQData(oldp+611,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U])) 
                                      << 0x3dU) | (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[3U])) 
                                                    << 0x1dU) 
                                                   | ((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[2U])) 
                                                      >> 3U)))),64);
        tracep->fullQData(oldp+613,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[2U])) 
                                      << 0x3dU) | (
                                                   ((QData)((IData)(
                                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[1U])) 
                                                    << 0x1dU) 
                                                   | ((QData)((IData)(
                                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U])) 
                                                      >> 3U)))),64);
        tracep->fullCData(oldp+615,((7U & vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U])),3);
        tracep->fullCData(oldp+616,((7U & vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U])),3);
        tracep->fullBit(oldp+617,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
                                      == (0x1fU & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                                   >> 4U))) 
                                     & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                        >> 3U)) & (0U 
                                                   != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr))) 
                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U])));
        tracep->fullBit(oldp+618,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
                                      == (0x1fU & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                                   >> 4U))) 
                                     & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                        >> 3U)) & (0U 
                                                   != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr))) 
                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U])));
        tracep->fullBit(oldp+619,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
                                      == (0x1fU & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                                   >> 4U))) 
                                     & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                        >> 3U)) & (0U 
                                                   != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr))) 
                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U] 
                                      >> 1U))));
        tracep->fullBit(oldp+620,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
                                      == (0x1fU & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                                   >> 4U))) 
                                     & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                        >> 3U)) & (0U 
                                                   != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr))) 
                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U] 
                                      >> 1U))));
        tracep->fullBit(oldp+621,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
                                   == (0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                                >> 4U)))));
        tracep->fullBit(oldp+622,((0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr))));
        tracep->fullBit(oldp+623,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U] 
                                         >> 1U))));
        tracep->fullBit(oldp+624,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr) 
                                      == (0x1fU & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                                   >> 4U))) 
                                     & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                        >> 3U)) & (0U 
                                                   != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr))) 
                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U])));
        tracep->fullBit(oldp+625,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr) 
                                      == (0x1fU & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                                   >> 4U))) 
                                     & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                        >> 3U)) & (0U 
                                                   != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr))) 
                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U])));
        tracep->fullBit(oldp+626,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr) 
                                      == (0x1fU & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                                   >> 4U))) 
                                     & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[2U] 
                                        >> 3U)) & (0U 
                                                   != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr))) 
                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__mem_forward_bus[0U] 
                                      >> 1U))));
        tracep->fullBit(oldp+627,((((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr) 
                                      == (0x1fU & (
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                                   >> 4U))) 
                                     & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[4U] 
                                        >> 3U)) & (0U 
                                                   != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr))) 
                                   & (vlTOPp->SimTop__DOT__u_cpu__DOT__wb_forward_bus[0U] 
                                      >> 1U))));
        tracep->fullQData(oldp+628,((0x80ULL & (- (QData)((IData)(
                                                                  (1U 
                                                                   & ((IData)(vlTOPp->SimTop__DOT__clint_interupt_bus) 
                                                                      >> 7U))))))),64);
        tracep->fullQData(oldp+630,((((QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)) 
                                      << 0x3fU) | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)
                                                    ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx
                                                    : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__excp_idx))),64);
        tracep->fullQData(oldp+632,((((- (QData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_enter))) 
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
        tracep->fullQData(oldp+634,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[9U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U])))),64);
        tracep->fullQData(oldp+636,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U])))),64);
        tracep->fullQData(oldp+638,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[5U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[4U])))),64);
        tracep->fullQData(oldp+640,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[0U])))),64);
        tracep->fullQData(oldp+642,((((QData)((IData)(
                                                      vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[3U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[2U])))),64);
        tracep->fullBit(oldp+644,((0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus))));
        tracep->fullBit(oldp+645,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__msie_allowin));
        tracep->fullBit(oldp+646,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__mtie_allowin));
        tracep->fullBit(oldp+647,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__meie_allowin));
        tracep->fullBit(oldp+648,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__msie_allowin) 
                                   & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))));
        tracep->fullBit(oldp+649,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__mtie_allowin) 
                                   & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))));
        tracep->fullBit(oldp+650,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__meie_allowin) 
                                   & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))));
        tracep->fullQData(oldp+651,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx),63);
        tracep->fullBit(oldp+653,((1U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus))));
        tracep->fullBit(oldp+654,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                         >> 1U))));
        tracep->fullBit(oldp+655,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                         >> 2U))));
        tracep->fullBit(oldp+656,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                         >> 3U))));
        tracep->fullBit(oldp+657,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                         >> 4U))));
        tracep->fullBit(oldp+658,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                         >> 5U))));
        tracep->fullBit(oldp+659,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                         >> 6U))));
        tracep->fullBit(oldp+660,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                         >> 7U))));
        tracep->fullBit(oldp+661,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                         >> 0xbU))));
        tracep->fullBit(oldp+662,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                         >> 0xcU))));
        tracep->fullBit(oldp+663,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                         >> 0xdU))));
        tracep->fullBit(oldp+664,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus) 
                                         >> 0xfU))));
        tracep->fullQData(oldp+665,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__excp_idx),63);
        tracep->fullBit(oldp+667,((IData)((0U != (0x1003U 
                                                  & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus))))));
        tracep->fullBit(oldp+668,((IData)((0U != (0xa0f0U 
                                                  & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus))))));
        tracep->fullQData(oldp+669,((0xffffffffffffffULL 
                                     & (((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[9U])) 
                                         << 0x18U) 
                                        | ((QData)((IData)(
                                                           vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U])) 
                                           >> 8U)))),56);
        tracep->fullBit(oldp+671,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U] 
                                         >> 7U))));
        tracep->fullCData(oldp+672,((7U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[9U] 
                                            << 0x1cU) 
                                           | (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U] 
                                              >> 4U)))),3);
        tracep->fullBit(oldp+673,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U] 
                                         >> 3U))));
        tracep->fullCData(oldp+674,((7U & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U])),3);
        tracep->fullQData(oldp+675,(((0xffffffffffffff00ULL 
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
        tracep->fullQData(oldp+677,(((0xffffffffffffff00ULL 
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
        tracep->fullCData(oldp+679,((3U & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U])),2);
        tracep->fullBit(oldp+680,((0U == (3U & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))));
        tracep->fullBit(oldp+681,((1U == (3U & vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U]))));
        tracep->fullQData(oldp+682,((0x3fffffffffffffffULL 
                                     & (((QData)((IData)(
                                                         vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[8U])) 
                                         << 0x3eU) 
                                        | (((QData)((IData)(
                                                            vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[7U])) 
                                            << 0x1eU) 
                                           | ((QData)((IData)(
                                                              vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_rd_bus[6U])) 
                                              >> 2U))))),62);
        tracep->fullQData(oldp+684,(((0xfffffffffffffffcULL 
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
        tracep->fullBit(oldp+686,((1U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info))));
        tracep->fullBit(oldp+687,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                         >> 1U))));
        tracep->fullBit(oldp+688,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                         >> 2U))));
        tracep->fullBit(oldp+689,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                         >> 3U))));
        tracep->fullBit(oldp+690,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                         >> 4U))));
        tracep->fullBit(oldp+691,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                         >> 5U))));
        tracep->fullBit(oldp+692,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                         >> 6U))));
        tracep->fullBit(oldp+693,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                         >> 7U))));
        tracep->fullBit(oldp+694,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                         >> 8U))));
        tracep->fullBit(oldp+695,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                         >> 9U))));
        tracep->fullBit(oldp+696,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                         >> 0xaU))));
        tracep->fullBit(oldp+697,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                         >> 0xbU))));
        tracep->fullBit(oldp+698,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_shift));
        tracep->fullBit(oldp+699,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub));
        tracep->fullBit(oldp+700,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub));
        __Vtemp770[0U] = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                           ? 1U : 0U);
        __Vtemp770[1U] = 0U;
        __Vtemp770[2U] = 0U;
        tracep->fullWData(oldp+701,(__Vtemp770),65);
        tracep->fullBit(oldp+704,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__excp_enter_wr));
        tracep->fullBit(oldp+705,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_exit) 
                                   & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake))));
        tracep->fullBit(oldp+706,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__excp_wr));
        tracep->fullBit(oldp+707,((0x300U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+708,((0x300U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
        tracep->fullBit(oldp+709,(((0x300U == (0xfffU 
                                               & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                  >> 0x14U))) 
                                   & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld))));
        tracep->fullBit(oldp+710,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_wr_ena));
        tracep->fullQData(oldp+711,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mstatus),64);
        tracep->fullBit(oldp+713,((0x301U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+714,(((0x301U == (0xfffU 
                                               & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                  >> 0x14U))) 
                                   & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld))));
        tracep->fullBit(oldp+715,((0x304U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+716,((0x304U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
        tracep->fullBit(oldp+717,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                   & (0x304U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+718,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_wr_ena));
        tracep->fullQData(oldp+719,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mie),64);
        tracep->fullBit(oldp+721,((0x305U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+722,((0x305U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
        tracep->fullBit(oldp+723,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                   & (0x305U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+724,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_wr_ena));
        tracep->fullQData(oldp+725,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mtvec),64);
        tracep->fullBit(oldp+727,((0x340U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+728,((0x340U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
        tracep->fullBit(oldp+729,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                   & (0x340U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+730,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_wr_ena));
        tracep->fullQData(oldp+731,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mscratch),64);
        tracep->fullBit(oldp+733,((0x341U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+734,((0x341U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
        tracep->fullBit(oldp+735,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                   & (0x341U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+736,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_wr_ena));
        tracep->fullQData(oldp+737,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mepc),64);
        tracep->fullBit(oldp+739,((0x342U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+740,((0x342U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
        tracep->fullBit(oldp+741,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                   & (0x342U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+742,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_wr_ena));
        tracep->fullQData(oldp+743,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mcause),64);
        tracep->fullBit(oldp+745,((0x343U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+746,((0x343U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
        tracep->fullBit(oldp+747,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                   & (0x343U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+748,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_wr_ena));
        tracep->fullQData(oldp+749,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mtval),64);
        tracep->fullBit(oldp+751,((0x344U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+752,((0x344U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
        tracep->fullBit(oldp+753,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                   & (0x344U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+754,((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_ena) 
                                    & (0x344U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))) 
                                   & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_handshake))));
        tracep->fullQData(oldp+755,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mip),64);
        tracep->fullBit(oldp+757,((0xb00U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+758,((0xb00U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_csr_wr_addr))));
        tracep->fullBit(oldp+759,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                   & (0xb00U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+760,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcycle_wr_ena));
        tracep->fullQData(oldp+761,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mcycle),64);
        tracep->fullBit(oldp+763,((0xf11U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+764,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                   & (0xf11U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+765,((0xf12U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+766,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                   & (0xf12U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+767,((0xf13U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+768,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                   & (0xf13U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+769,((0xf14U == (0xfffU 
                                              & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                 >> 0x14U)))));
        tracep->fullBit(oldp+770,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__csr_vld) 
                                   & (0xf14U == (0xfffU 
                                                 & (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r 
                                                    >> 0x14U))))));
        tracep->fullBit(oldp+771,((0x801cc68ULL == 
                                   (0xfffffffffffffffULL 
                                    & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr 
                                       >> 4U)))));
        tracep->fullBit(oldp+772,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid));
        tracep->fullBit(oldp+773,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ready_go));
        tracep->fullWData(oldp+774,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r),223);
        tracep->fullWData(oldp+781,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_diffbus_r),577);
        tracep->fullBit(oldp+800,((1U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[6U] 
                                          & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                                         >> 0x1eU))));
        tracep->fullCData(oldp+801,((0xffU & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[6U] 
                                               & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                                              >> 0x16U))),8);
        tracep->fullCData(oldp+802,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info),7);
        tracep->fullCData(oldp+803,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info),4);
        tracep->fullQData(oldp+804,((((QData)((IData)(
                                                      (0x7ffU 
                                                       & (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[6U] 
                                                          & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid))))))) 
                                      << 0x35U) | (
                                                   ((QData)((IData)(
                                                                    (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[5U] 
                                                                     & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                                    << 0x15U) 
                                                   | ((QData)((IData)(
                                                                      (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[4U] 
                                                                       & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                                      >> 0xbU)))),64);
        tracep->fullQData(oldp+806,((((QData)((IData)(
                                                      (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[2U] 
                                                       & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                      << 0x35U) | (
                                                   ((QData)((IData)(
                                                                    (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[1U] 
                                                                     & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                                    << 0x15U) 
                                                   | ((QData)((IData)(
                                                                      (vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
                                                                       & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))))) 
                                                      >> 0xbU)))),64);
        tracep->fullBit(oldp+808,((1U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__ex_to_mem_bus_r[0U] 
                                          & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_valid)))) 
                                         >> 0xaU))));
        tracep->fullCData(oldp+809,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ctrl),3);
        tracep->fullCData(oldp+810,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_addr),5);
        tracep->fullBit(oldp+811,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_reg_wr_ena));
        tracep->fullBit(oldp+812,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_valid) 
                                   & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__mem_allowin))));
        tracep->fullBit(oldp+813,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_handshake));
        tracep->fullBit(oldp+814,((1U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info))));
        tracep->fullBit(oldp+815,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info) 
                                         >> 1U))));
        tracep->fullBit(oldp+816,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info) 
                                         >> 2U))));
        tracep->fullBit(oldp+817,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info) 
                                         >> 3U))));
        tracep->fullBit(oldp+818,((1U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info))));
        tracep->fullBit(oldp+819,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                         >> 1U))));
        tracep->fullBit(oldp+820,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                         >> 2U))));
        tracep->fullBit(oldp+821,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                         >> 3U))));
        tracep->fullBit(oldp+822,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                         >> 4U))));
        tracep->fullBit(oldp+823,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                         >> 5U))));
        tracep->fullBit(oldp+824,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info) 
                                         >> 6U))));
        tracep->fullCData(oldp+825,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state),2);
        tracep->fullQData(oldp+826,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_data),64);
        tracep->fullBit(oldp+828,((2U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_state))));
        tracep->fullBit(oldp+829,((1U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
        tracep->fullBit(oldp+830,((2U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
        tracep->fullBit(oldp+831,((3U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
        tracep->fullBit(oldp+832,((4U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
        tracep->fullBit(oldp+833,((5U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
        tracep->fullBit(oldp+834,((6U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
        tracep->fullBit(oldp+835,((7U == (7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr)))));
        tracep->fullBit(oldp+836,((0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_save_info))));
        tracep->fullBit(oldp+837,((0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_load_info))));
        tracep->fullQData(oldp+838,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__difftest_data),64);
        tracep->fullCData(oldp+840,((0xffU & (((((1U 
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
                                                  & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr))))),8);
        tracep->fullBit(oldp+841,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid));
        tracep->fullQData(oldp+842,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_pc_r),64);
        tracep->fullIData(oldp+844,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_inst_r),32);
        tracep->fullWData(oldp+845,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r),210);
        tracep->fullWData(oldp+852,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_diffbus_r),715);
        tracep->fullBit(oldp+875,((1U & ((vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[6U] 
                                          & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid)))) 
                                         >> 8U))));
        tracep->fullCData(oldp+876,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_reg_wr_ctrl),3);
        tracep->fullQData(oldp+877,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_ex_data),64);
        tracep->fullQData(oldp+879,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_mem_rd_data),64);
        tracep->fullQData(oldp+881,(((((QData)((IData)(
                                                       vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[1U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__mem_to_wb_bus_r[0U]))) 
                                     & (((QData)((IData)(
                                                         (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid))))) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_valid)))))))),64);
        tracep->fullBit(oldp+883,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_reg_wr_ctrl) 
                                         >> 1U))));
        tracep->fullBit(oldp+884,((1U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_reg_wr_ctrl))));
        tracep->fullBit(oldp+885,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_reg_wr_ctrl) 
                                         >> 2U))));
        tracep->fullQData(oldp+886,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0]),64);
        tracep->fullQData(oldp+888,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[1]),64);
        tracep->fullQData(oldp+890,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[2]),64);
        tracep->fullQData(oldp+892,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[3]),64);
        tracep->fullQData(oldp+894,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[4]),64);
        tracep->fullQData(oldp+896,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[5]),64);
        tracep->fullQData(oldp+898,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[6]),64);
        tracep->fullQData(oldp+900,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[7]),64);
        tracep->fullQData(oldp+902,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[8]),64);
        tracep->fullQData(oldp+904,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[9]),64);
        tracep->fullQData(oldp+906,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[10]),64);
        tracep->fullQData(oldp+908,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[11]),64);
        tracep->fullQData(oldp+910,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[12]),64);
        tracep->fullQData(oldp+912,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[13]),64);
        tracep->fullQData(oldp+914,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[14]),64);
        tracep->fullQData(oldp+916,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[15]),64);
        tracep->fullQData(oldp+918,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[16]),64);
        tracep->fullQData(oldp+920,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[17]),64);
        tracep->fullQData(oldp+922,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[18]),64);
        tracep->fullQData(oldp+924,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[19]),64);
        tracep->fullQData(oldp+926,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[20]),64);
        tracep->fullQData(oldp+928,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[21]),64);
        tracep->fullQData(oldp+930,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[22]),64);
        tracep->fullQData(oldp+932,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[23]),64);
        tracep->fullQData(oldp+934,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[24]),64);
        tracep->fullQData(oldp+936,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[25]),64);
        tracep->fullQData(oldp+938,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[26]),64);
        tracep->fullQData(oldp+940,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[27]),64);
        tracep->fullQData(oldp+942,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[28]),64);
        tracep->fullQData(oldp+944,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[29]),64);
        tracep->fullQData(oldp+946,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[30]),64);
        tracep->fullQData(oldp+948,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[31]),64);
        tracep->fullQData(oldp+950,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0]),64);
        tracep->fullQData(oldp+952,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[1]),64);
        tracep->fullQData(oldp+954,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[2]),64);
        tracep->fullQData(oldp+956,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[3]),64);
        tracep->fullQData(oldp+958,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[4]),64);
        tracep->fullQData(oldp+960,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[5]),64);
        tracep->fullQData(oldp+962,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[6]),64);
        tracep->fullQData(oldp+964,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[7]),64);
        tracep->fullQData(oldp+966,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[8]),64);
        tracep->fullQData(oldp+968,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[9]),64);
        tracep->fullQData(oldp+970,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[10]),64);
        tracep->fullQData(oldp+972,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[11]),64);
        tracep->fullQData(oldp+974,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[12]),64);
        tracep->fullQData(oldp+976,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[13]),64);
        tracep->fullQData(oldp+978,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[14]),64);
        tracep->fullQData(oldp+980,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[15]),64);
        tracep->fullQData(oldp+982,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[16]),64);
        tracep->fullQData(oldp+984,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[17]),64);
        tracep->fullQData(oldp+986,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[18]),64);
        tracep->fullQData(oldp+988,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[19]),64);
        tracep->fullQData(oldp+990,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[20]),64);
        tracep->fullQData(oldp+992,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[21]),64);
        tracep->fullQData(oldp+994,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[22]),64);
        tracep->fullQData(oldp+996,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[23]),64);
        tracep->fullQData(oldp+998,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[24]),64);
        tracep->fullQData(oldp+1000,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[25]),64);
        tracep->fullQData(oldp+1002,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[26]),64);
        tracep->fullQData(oldp+1004,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[27]),64);
        tracep->fullQData(oldp+1006,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[28]),64);
        tracep->fullQData(oldp+1008,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[29]),64);
        tracep->fullQData(oldp+1010,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[30]),64);
        tracep->fullQData(oldp+1012,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[31]),64);
        tracep->fullBit(oldp+1014,((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_valid) 
                                     & (~ (IData)((0U 
                                                   != vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_excp_NO)))) 
                                    & (~ (IData)((0U 
                                                  != vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_itrp_NO))))));
        tracep->fullIData(oldp+1015,((vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_excp_NO 
                                      & (- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_valid))))),32);
        tracep->fullQData(oldp+1016,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0U]),64);
        tracep->fullQData(oldp+1018,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [1U]),64);
        tracep->fullQData(oldp+1020,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [2U]),64);
        tracep->fullQData(oldp+1022,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [3U]),64);
        tracep->fullQData(oldp+1024,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [4U]),64);
        tracep->fullQData(oldp+1026,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [5U]),64);
        tracep->fullQData(oldp+1028,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [6U]),64);
        tracep->fullQData(oldp+1030,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [7U]),64);
        tracep->fullQData(oldp+1032,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [8U]),64);
        tracep->fullQData(oldp+1034,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [9U]),64);
        tracep->fullQData(oldp+1036,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0xaU]),64);
        tracep->fullQData(oldp+1038,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0xbU]),64);
        tracep->fullQData(oldp+1040,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0xcU]),64);
        tracep->fullQData(oldp+1042,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0xdU]),64);
        tracep->fullQData(oldp+1044,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0xeU]),64);
        tracep->fullQData(oldp+1046,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0xfU]),64);
        tracep->fullQData(oldp+1048,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x10U]),64);
        tracep->fullQData(oldp+1050,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x11U]),64);
        tracep->fullQData(oldp+1052,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x12U]),64);
        tracep->fullQData(oldp+1054,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x13U]),64);
        tracep->fullQData(oldp+1056,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x14U]),64);
        tracep->fullQData(oldp+1058,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x15U]),64);
        tracep->fullQData(oldp+1060,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x16U]),64);
        tracep->fullQData(oldp+1062,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x17U]),64);
        tracep->fullQData(oldp+1064,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x18U]),64);
        tracep->fullQData(oldp+1066,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x19U]),64);
        tracep->fullQData(oldp+1068,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x1aU]),64);
        tracep->fullQData(oldp+1070,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x1bU]),64);
        tracep->fullQData(oldp+1072,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x1cU]),64);
        tracep->fullQData(oldp+1074,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x1dU]),64);
        tracep->fullQData(oldp+1076,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x1eU]),64);
        tracep->fullQData(oldp+1078,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                     [0x1fU]),64);
        tracep->fullBit(oldp+1080,((0x6bU == (0x7fU 
                                              & vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_inst))));
        tracep->fullCData(oldp+1081,((7U & (IData)(
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__regs
                                                   [0xaU]))),3);
        tracep->fullQData(oldp+1082,((0x80000003000de122ULL 
                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_mstatus)),64);
        tracep->fullBit(oldp+1084,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_w_ena) 
                                    & (0x200ULL != 
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
        tracep->fullCData(oldp+1085,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                      & (1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))),4);
        tracep->fullBit(oldp+1086,((((0x2000000ULL 
                                      == vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg) 
                                     | (0x200bff8ULL 
                                        == vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg)) 
                                    | (0x2004000ULL 
                                       == vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg))));
        tracep->fullBit(oldp+1087,((((0x2000000ULL 
                                      == vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg) 
                                     | (0x200bff8ULL 
                                        == vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg)) 
                                    | (0x2004000ULL 
                                       == vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg))));
        tracep->fullIData(oldp+1088,(vlTOPp->SimTop__DOT__Clint__DOT__csr_msip),32);
        tracep->fullQData(oldp+1089,(vlTOPp->SimTop__DOT__Clint__DOT__csr_mtime),64);
        tracep->fullQData(oldp+1091,(vlTOPp->SimTop__DOT__Clint__DOT__csr_mtimecmp),64);
        tracep->fullBit(oldp+1093,(vlTOPp->SimTop__DOT__Clint__DOT__ar_hs));
        tracep->fullBit(oldp+1094,(vlTOPp->SimTop__DOT__Clint__DOT__aw_hs));
        tracep->fullBit(oldp+1095,(((2U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__w_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__cli_b_ready))));
        tracep->fullBit(oldp+1096,(vlTOPp->SimTop__DOT__Clint__DOT__r_state));
        tracep->fullBit(oldp+1097,((1U & (~ (IData)(vlTOPp->SimTop__DOT__Clint__DOT__r_state)))));
        tracep->fullQData(oldp+1098,(vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg),64);
        tracep->fullCData(oldp+1100,(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg),3);
        tracep->fullBit(oldp+1101,((0U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))));
        tracep->fullBit(oldp+1102,((1U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))));
        tracep->fullBit(oldp+1103,((2U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))));
        tracep->fullBit(oldp+1104,((3U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_size_reg))));
        tracep->fullBit(oldp+1105,((0x2000000ULL == vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg)));
        tracep->fullBit(oldp+1106,((0x2004000ULL == vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg)));
        tracep->fullBit(oldp+1107,((0x200bff8ULL == vlTOPp->SimTop__DOT__Clint__DOT__rd_addr_reg)));
        tracep->fullQData(oldp+1108,(vlTOPp->SimTop__DOT__Clint__DOT__clint_val),64);
        tracep->fullCData(oldp+1110,(vlTOPp->SimTop__DOT__Clint__DOT__w_state),2);
        tracep->fullBit(oldp+1111,((0U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__w_state))));
        tracep->fullBit(oldp+1112,((1U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__w_state))));
        tracep->fullQData(oldp+1113,(vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg),64);
        tracep->fullCData(oldp+1115,(vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg),3);
        tracep->fullBit(oldp+1116,((0U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg))));
        tracep->fullBit(oldp+1117,((1U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg))));
        tracep->fullBit(oldp+1118,((2U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg))));
        tracep->fullBit(oldp+1119,((3U == (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_size_reg))));
        tracep->fullCData(oldp+1120,((0xffU & (((((1U 
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
                                               << (7U 
                                                   & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg))))),8);
        tracep->fullCData(oldp+1121,(vlTOPp->SimTop__DOT__Clint__DOT__mask_8bits),8);
        tracep->fullQData(oldp+1122,(vlTOPp->SimTop__DOT__Clint__DOT__wr_mask),64);
        tracep->fullBit(oldp+1124,((0x2000000ULL == vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg)));
        tracep->fullBit(oldp+1125,((0x2004000ULL == vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg)));
        tracep->fullBit(oldp+1126,((0x200bff8ULL == vlTOPp->SimTop__DOT__Clint__DOT__wr_addr_reg)));
        tracep->fullBit(oldp+1127,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_ready))));
        tracep->fullBit(oldp+1128,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_ready))));
        tracep->fullBit(oldp+1129,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_ready))));
        tracep->fullBit(oldp+1130,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_ready))));
        tracep->fullBit(oldp+1131,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_ready))));
        tracep->fullBit(oldp+1132,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_ready))));
        tracep->fullBit(oldp+1133,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_valid))));
        tracep->fullBit(oldp+1134,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_valid))));
        tracep->fullCData(oldp+1135,(((- (IData)((1U 
                                                  == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                      & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_resp))),2);
        tracep->fullCData(oldp+1136,(((- (IData)((2U 
                                                  == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                      & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_resp))),2);
        tracep->fullBit(oldp+1137,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_last))));
        tracep->fullBit(oldp+1138,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_last))));
        tracep->fullBit(oldp+1139,(((((IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_valid) 
                                      & (2U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))) 
                                     & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_last)) 
                                    & (1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))));
        tracep->fullBit(oldp+1140,(((((IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_valid) 
                                      & (2U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state))) 
                                     & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_last)) 
                                    & (2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))));
        tracep->fullBit(oldp+1141,((((IData)(vlTOPp->SimTop__DOT__mem_axi_b_valid) 
                                     & (3U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state))) 
                                    & (1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))));
        tracep->fullBit(oldp+1142,((((IData)(vlTOPp->SimTop__DOT__if_axi_b_valid) 
                                     & (3U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state))) 
                                    & (2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))));
        tracep->fullBit(oldp+1143,((((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                     & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_ready)) 
                                    & (1U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state)))));
        tracep->fullBit(oldp+1144,(((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_hs) 
                                    & (2U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)))));
        tracep->fullBit(oldp+1145,((((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__len) 
                                     != (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_len)) 
                                    & ((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_hs) 
                                       | (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_hs)))));
        tracep->fullBit(oldp+1146,(((IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__trans_done) 
                                    | (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__rw_ready))));
        tracep->fullQData(oldp+1147,(((vlTOPp->SimTop__DOT__mem_axi_r_data 
                                       & (((QData)((IData)(
                                                           vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[3U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            vlTOPp->SimTop__DOT__mem_axi_rw__DOT__mask[2U])))) 
                                      << (0x3fU & (- 
                                                   (0x38U 
                                                    & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_addr) 
                                                       << 3U)))))),64);
        tracep->fullBit(oldp+1149,(((3U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__if_axi_b_valid))));
        tracep->fullBit(oldp+1150,((((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                     & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_ready)) 
                                    & (1U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state)))));
        tracep->fullBit(oldp+1151,(((IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_hs) 
                                    & (2U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_state)))));
        tracep->fullBit(oldp+1152,((((IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__len) 
                                     != (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_len)) 
                                    & ((IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_hs) 
                                       | (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_hs)))));
        tracep->fullBit(oldp+1153,(((IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_done) 
                                    | (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__rw_ready))));
        tracep->fullBit(oldp+1154,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                    & (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_resp))));
        __Vtemp811[0U] = 0xffffffffU;
        __Vtemp811[1U] = 0U;
        __Vtemp811[2U] = 0U;
        __Vtemp811[3U] = 0U;
        VL_SHIFTL_WWI(128,128,6, __Vtemp812, __Vtemp811, 
                      (0x38U & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                << 3U)));
        tracep->fullQData(oldp+1155,(((vlTOPp->SimTop__DOT__if_axi_r_data 
                                       & (((QData)((IData)(
                                                           __Vtemp812[3U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            __Vtemp812[2U])))) 
                                      << (0x3fU & (- 
                                                   (0x38U 
                                                    & ((IData)(vlTOPp->SimTop__DOT__if_rw_addr) 
                                                       << 3U)))))),64);
        __Vtemp822[0U] = ((- (IData)((0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_excp_bus)))) 
                          & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__excp_idx));
        __Vtemp822[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid))) 
                          & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Excp_handler__DOT__itrp_idx));
        __Vtemp822[2U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_rd_data);
        __Vtemp822[3U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_rd_data 
                                  >> 0x20U));
        __Vtemp822[4U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_rd_data);
        __Vtemp822[5U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_rd_data 
                                  >> 0x20U));
        __Vtemp822[6U] = (IData)((((QData)((IData)(
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[9U])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[8U]))));
        __Vtemp822[7U] = (IData)(((((QData)((IData)(
                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[9U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[8U]))) 
                                  >> 0x20U));
        __Vtemp822[8U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data);
        __Vtemp822[9U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data 
                                  >> 0x20U));
        __Vtemp822[0xaU] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_rd_data);
        __Vtemp822[0xbU] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_rd_data 
                                    >> 0x20U));
        __Vtemp822[0xcU] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data);
        __Vtemp822[0xdU] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data 
                                    >> 0x20U));
        __Vtemp822[0xeU] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data);
        __Vtemp822[0xfU] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data 
                                    >> 0x20U));
        __Vtemp822[0x10U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_rd_data);
        __Vtemp822[0x11U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_rd_data 
                                     >> 0x20U));
        __Vtemp822[0x12U] = ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_diffbus_r) 
                             | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid));
        tracep->fullWData(oldp+1157,(__Vtemp822),577);
        tracep->fullQData(oldp+1176,(((2U & vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U])
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
        tracep->fullCData(oldp+1178,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__reg_wr_addr),5);
        tracep->fullQData(oldp+1179,(((((QData)((IData)(
                                                        (__Vconst88[5U] 
                                                         & (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_bus_r[5U] 
                                                            & (__Vconst72[5U] 
                                                               & (- (IData)(
                                                                            ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid) 
                                                                             & (~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__itrp_valid)))))))))) 
                                        << 0x3dU) | 
                                       (((QData)((IData)(
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
                                      + ((0x40U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_info))
                                          ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs1_forward
                                          : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__id_to_ex_pc_r))),64);
        tracep->fullQData(oldp+1181,(((((- (QData)((IData)(
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
        tracep->fullQData(oldp+1183,(((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res 
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
        __Vtemp829[0U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1);
        __Vtemp829[1U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                  >> 0x20U));
        __Vtemp829[2U] = (1U & ((~ ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                    >> 3U)) & (IData)(
                                                      (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                       >> 0x3fU))));
        tracep->fullWData(oldp+1185,(__Vtemp829),65);
        __Vtemp832[0U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                          & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1));
        __Vtemp832[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                          & (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                     >> 0x20U)));
        __Vtemp832[2U] = (1U & ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                                & ((~ ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_alu_info) 
                                       >> 3U)) & (IData)(
                                                         (vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                                          >> 0x3fU)))));
        tracep->fullWData(oldp+1188,(__Vtemp832),65);
        __Vtemp838[0U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                          & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                              ? (~ vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U])
                              : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[0U]));
        __Vtemp838[1U] = ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                          & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                              ? (~ vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U])
                              : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[1U]));
        __Vtemp838[2U] = (1U & ((- (IData)((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__op_addsub))) 
                                & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_sub)
                                    ? (~ vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U])
                                    : vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2[2U])));
        tracep->fullWData(oldp+1191,(__Vtemp838),65);
        tracep->fullQData(oldp+1194,(((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcycle_wr_ena)
                                       ? vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data
                                       : (1ULL + vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_mcycle))),64);
        tracep->fullBit(oldp+1196,(vlTOPp->SimTop__DOT__mem_axi_b_valid));
        tracep->fullBit(oldp+1197,(vlTOPp->SimTop__DOT__if_axi_b_valid));
        tracep->fullQData(oldp+1198,(vlTOPp->SimTop__DOT__mem_axi_r_data),64);
        tracep->fullQData(oldp+1200,(vlTOPp->SimTop__DOT__if_axi_r_data),64);
        tracep->fullBit(oldp+1202,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_aw_ready));
        tracep->fullBit(oldp+1203,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_w_ready));
        tracep->fullBit(oldp+1204,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_b_valid));
        tracep->fullBit(oldp+1205,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_ar_ready));
        tracep->fullBit(oldp+1206,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_valid));
        tracep->fullCData(oldp+1207,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_resp),2);
        tracep->fullQData(oldp+1208,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_data),64);
        tracep->fullBit(oldp+1210,(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_last));
        tracep->fullCData(oldp+1211,(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_next_state),2);
        tracep->fullCData(oldp+1212,(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_next_state),2);
        tracep->fullCData(oldp+1213,(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_next_state),2);
        tracep->fullCData(oldp+1214,(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_next_state),2);
        tracep->fullBit(oldp+1215,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__aw_hs));
        tracep->fullBit(oldp+1216,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_hs));
        tracep->fullBit(oldp+1217,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__b_hs));
        tracep->fullBit(oldp+1218,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_hs));
        tracep->fullBit(oldp+1219,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_done));
        tracep->fullBit(oldp+1220,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__trans_done));
        tracep->fullQData(oldp+1221,(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__axi_r_data_l),64);
        tracep->fullBit(oldp+1223,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__aw_hs));
        tracep->fullBit(oldp+1224,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__w_hs));
        tracep->fullBit(oldp+1225,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_hs));
        tracep->fullBit(oldp+1226,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_done));
        tracep->fullQData(oldp+1227,(vlTOPp->SimTop__DOT__if_axi_rw__DOT__axi_r_data_l),64);
        tracep->fullBit(oldp+1229,(vlTOPp->SimTop__DOT__u_cpu__DOT__if_to_id_valid));
        tracep->fullBit(oldp+1230,(vlTOPp->SimTop__DOT__u_cpu__DOT__id_to_ex_valid));
        tracep->fullWData(oldp+1231,(vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus),223);
        __Vtemp845[0U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_rd_data);
        __Vtemp845[1U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_rd_data 
                                  >> 0x20U));
        __Vtemp845[2U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_rd_data);
        __Vtemp845[3U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_rd_data 
                                  >> 0x20U));
        __Vtemp845[4U] = (IData)((((QData)((IData)(
                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[9U])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[8U]))));
        __Vtemp845[5U] = (IData)(((((QData)((IData)(
                                                    vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[9U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[8U]))) 
                                  >> 0x20U));
        __Vtemp845[6U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data);
        __Vtemp845[7U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data 
                                  >> 0x20U));
        __Vtemp845[8U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_rd_data);
        __Vtemp845[9U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_rd_data 
                                  >> 0x20U));
        __Vtemp845[0xaU] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data);
        __Vtemp845[0xbU] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data 
                                    >> 0x20U));
        __Vtemp845[0xcU] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data);
        __Vtemp845[0xdU] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data 
                                    >> 0x20U));
        __Vtemp845[0xeU] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_rd_data);
        __Vtemp845[0xfU] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_rd_data 
                                    >> 0x20U));
        tracep->fullWData(oldp+1238,(__Vtemp845),512);
        tracep->fullWData(oldp+1254,(vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus),66);
        tracep->fullQData(oldp+1257,(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_rd_data),64);
        tracep->fullQData(oldp+1259,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_data),64);
        tracep->fullWData(oldp+1261,(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus),320);
        tracep->fullQData(oldp+1271,(vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_data),64);
        tracep->fullQData(oldp+1273,((((QData)((IData)(
                                                       vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[2U])) 
                                       << 0x3eU) | 
                                      (((QData)((IData)(
                                                        vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[1U])) 
                                        << 0x1eU) | 
                                       ((QData)((IData)(
                                                        vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U])) 
                                        >> 2U)))),64);
        tracep->fullBit(oldp+1275,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U] 
                                          >> 1U))));
        tracep->fullBit(oldp+1276,((1U & vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U])));
        tracep->fullCData(oldp+1277,(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_next_state),2);
        tracep->fullBit(oldp+1278,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_flush));
        tracep->fullQData(oldp+1279,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2),64);
        tracep->fullBit(oldp+1281,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__reg_wr_ena));
        tracep->fullCData(oldp+1282,((0xffU & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs1_forward))),8);
        tracep->fullQData(oldp+1283,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs1_forward),64);
        tracep->fullQData(oldp+1285,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__rs2_forward),64);
        tracep->fullQData(oldp+1287,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__true_op1),64);
        tracep->fullQData(oldp+1289,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__true_op2),64);
        tracep->fullQData(oldp+1291,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1),64);
        tracep->fullQData(oldp+1293,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2),64);
        tracep->fullCData(oldp+1295,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_data),8);
        tracep->fullQData(oldp+1296,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in1),64);
        tracep->fullCData(oldp+1298,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_in2),6);
        tracep->fullQData(oldp+1299,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__shifter_res),64);
        tracep->fullQData(oldp+1301,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__srl_res),64);
        tracep->fullQData(oldp+1303,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__eff_mask),64);
        tracep->fullWData(oldp+1305,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__adder_op2),65);
        tracep->fullWData(oldp+1308,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__add_res),65);
        tracep->fullQData(oldp+1311,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__slt_res),64);
        tracep->fullQData(oldp+1313,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res),64);
        tracep->fullQData(oldp+1315,((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                      | vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2)),64);
        tracep->fullQData(oldp+1317,((vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1 
                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2)),64);
        tracep->fullQData(oldp+1319,(((~ vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op1) 
                                      & vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__op2)),64);
        tracep->fullQData(oldp+1321,(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__temp_output),64);
        tracep->fullBit(oldp+1323,((1U & (~ (IData)(
                                                    (0U 
                                                     != vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__Exe_stage_alu__DOT__xor_res))))));
        tracep->fullQData(oldp+1324,((((QData)((IData)(
                                                       vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[9U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[8U])))),64);
        tracep->fullQData(oldp+1326,((((QData)((IData)(
                                                       vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[1U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[0U])))),64);
        tracep->fullQData(oldp+1328,((((QData)((IData)(
                                                       vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[5U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[4U])))),64);
        tracep->fullQData(oldp+1330,((((QData)((IData)(
                                                       vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[7U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[6U])))),64);
        tracep->fullQData(oldp+1332,((((QData)((IData)(
                                                       vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[3U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlTOPp->SimTop__DOT__u_cpu__DOT__csr_excp_wr_bus[2U])))),64);
        tracep->fullQData(oldp+1334,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_wr_data_full),64);
        tracep->fullQData(oldp+1336,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__csr_wr_data_full),64);
        tracep->fullQData(oldp+1338,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mstatus_rd_data),64);
        tracep->fullQData(oldp+1340,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mie_rd_data),64);
        tracep->fullQData(oldp+1342,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtvec_rd_data),64);
        tracep->fullQData(oldp+1344,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mscratch_rd_data),64);
        tracep->fullQData(oldp+1346,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mepc_rd_data),64);
        tracep->fullQData(oldp+1348,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mcause_rd_data),64);
        tracep->fullQData(oldp+1350,(vlTOPp->SimTop__DOT__u_cpu__DOT__CSRfile__DOT__mtval_rd_data),64);
        tracep->fullBit(oldp+1352,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[0U] 
                                          >> 0xaU))));
        tracep->fullBit(oldp+1353,((1U & (vlTOPp->SimTop__DOT__u_cpu__DOT__ex_to_mem_bus[0U] 
                                          >> 9U))));
        tracep->fullCData(oldp+1354,(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_next_state),2);
        tracep->fullBit(oldp+1355,(vlTOPp->clock));
        tracep->fullBit(oldp+1356,(vlTOPp->reset));
        tracep->fullQData(oldp+1357,(vlTOPp->io_logCtrl_log_begin),64);
        tracep->fullQData(oldp+1359,(vlTOPp->io_logCtrl_log_end),64);
        tracep->fullQData(oldp+1361,(vlTOPp->io_logCtrl_log_level),64);
        tracep->fullBit(oldp+1363,(vlTOPp->io_perfInfo_clean));
        tracep->fullBit(oldp+1364,(vlTOPp->io_perfInfo_dump));
        tracep->fullBit(oldp+1365,(vlTOPp->io_uart_out_valid));
        tracep->fullCData(oldp+1366,(vlTOPp->io_uart_out_ch),8);
        tracep->fullBit(oldp+1367,(vlTOPp->io_uart_in_valid));
        tracep->fullCData(oldp+1368,(vlTOPp->io_uart_in_ch),8);
        tracep->fullBit(oldp+1369,(vlTOPp->io_memAXI_0_aw_ready));
        tracep->fullBit(oldp+1370,(vlTOPp->io_memAXI_0_aw_valid));
        tracep->fullQData(oldp+1371,(vlTOPp->io_memAXI_0_aw_bits_addr),64);
        tracep->fullCData(oldp+1373,(vlTOPp->io_memAXI_0_aw_bits_prot),3);
        tracep->fullCData(oldp+1374,(vlTOPp->io_memAXI_0_aw_bits_id),4);
        tracep->fullBit(oldp+1375,(vlTOPp->io_memAXI_0_aw_bits_user));
        tracep->fullCData(oldp+1376,(vlTOPp->io_memAXI_0_aw_bits_len),8);
        tracep->fullCData(oldp+1377,(vlTOPp->io_memAXI_0_aw_bits_size),3);
        tracep->fullCData(oldp+1378,(vlTOPp->io_memAXI_0_aw_bits_burst),2);
        tracep->fullBit(oldp+1379,(vlTOPp->io_memAXI_0_aw_bits_lock));
        tracep->fullCData(oldp+1380,(vlTOPp->io_memAXI_0_aw_bits_cache),4);
        tracep->fullCData(oldp+1381,(vlTOPp->io_memAXI_0_aw_bits_qos),4);
        tracep->fullBit(oldp+1382,(vlTOPp->io_memAXI_0_w_ready));
        tracep->fullBit(oldp+1383,(vlTOPp->io_memAXI_0_w_valid));
        tracep->fullQData(oldp+1384,(vlTOPp->io_memAXI_0_w_bits_data[0]),64);
        tracep->fullQData(oldp+1386,(vlTOPp->io_memAXI_0_w_bits_data[1]),64);
        tracep->fullQData(oldp+1388,(vlTOPp->io_memAXI_0_w_bits_data[2]),64);
        tracep->fullQData(oldp+1390,(vlTOPp->io_memAXI_0_w_bits_data[3]),64);
        tracep->fullCData(oldp+1392,(vlTOPp->io_memAXI_0_w_bits_strb),8);
        tracep->fullBit(oldp+1393,(vlTOPp->io_memAXI_0_w_bits_last));
        tracep->fullCData(oldp+1394,(vlTOPp->io_memAXI_0_w_bits_id),4);
        tracep->fullBit(oldp+1395,(vlTOPp->io_memAXI_0_b_ready));
        tracep->fullBit(oldp+1396,(vlTOPp->io_memAXI_0_b_valid));
        tracep->fullCData(oldp+1397,(vlTOPp->io_memAXI_0_b_bits_resp),2);
        tracep->fullCData(oldp+1398,(vlTOPp->io_memAXI_0_b_bits_id),4);
        tracep->fullBit(oldp+1399,(vlTOPp->io_memAXI_0_b_bits_user));
        tracep->fullBit(oldp+1400,(vlTOPp->io_memAXI_0_ar_ready));
        tracep->fullBit(oldp+1401,(vlTOPp->io_memAXI_0_ar_valid));
        tracep->fullQData(oldp+1402,(vlTOPp->io_memAXI_0_ar_bits_addr),64);
        tracep->fullCData(oldp+1404,(vlTOPp->io_memAXI_0_ar_bits_prot),3);
        tracep->fullCData(oldp+1405,(vlTOPp->io_memAXI_0_ar_bits_id),4);
        tracep->fullBit(oldp+1406,(vlTOPp->io_memAXI_0_ar_bits_user));
        tracep->fullCData(oldp+1407,(vlTOPp->io_memAXI_0_ar_bits_len),8);
        tracep->fullCData(oldp+1408,(vlTOPp->io_memAXI_0_ar_bits_size),3);
        tracep->fullCData(oldp+1409,(vlTOPp->io_memAXI_0_ar_bits_burst),2);
        tracep->fullBit(oldp+1410,(vlTOPp->io_memAXI_0_ar_bits_lock));
        tracep->fullCData(oldp+1411,(vlTOPp->io_memAXI_0_ar_bits_cache),4);
        tracep->fullCData(oldp+1412,(vlTOPp->io_memAXI_0_ar_bits_qos),4);
        tracep->fullBit(oldp+1413,(vlTOPp->io_memAXI_0_r_ready));
        tracep->fullBit(oldp+1414,(vlTOPp->io_memAXI_0_r_valid));
        tracep->fullCData(oldp+1415,(vlTOPp->io_memAXI_0_r_bits_resp),2);
        tracep->fullQData(oldp+1416,(vlTOPp->io_memAXI_0_r_bits_data[0]),64);
        tracep->fullQData(oldp+1418,(vlTOPp->io_memAXI_0_r_bits_data[1]),64);
        tracep->fullQData(oldp+1420,(vlTOPp->io_memAXI_0_r_bits_data[2]),64);
        tracep->fullQData(oldp+1422,(vlTOPp->io_memAXI_0_r_bits_data[3]),64);
        tracep->fullBit(oldp+1424,(vlTOPp->io_memAXI_0_r_bits_last));
        tracep->fullCData(oldp+1425,(vlTOPp->io_memAXI_0_r_bits_id),4);
        tracep->fullBit(oldp+1426,(vlTOPp->io_memAXI_0_r_bits_user));
        tracep->fullCData(oldp+1427,(((- (IData)((1U 
                                                  == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                      & ((- (IData)(
                                                    (2U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                         & (IData)(vlTOPp->io_memAXI_0_b_bits_resp)))),2);
        tracep->fullCData(oldp+1428,(((- (IData)((2U 
                                                  == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                      & ((- (IData)(
                                                    (2U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                         & (IData)(vlTOPp->io_memAXI_0_b_bits_resp)))),2);
        tracep->fullCData(oldp+1429,(((- (IData)((1U 
                                                  == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                      & (((- (IData)(
                                                     (1U 
                                                      == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                          & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_id_reg)) 
                                         | ((- (IData)(
                                                       (2U 
                                                        == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                            & (IData)(vlTOPp->io_memAXI_0_b_bits_id))))),4);
        tracep->fullCData(oldp+1430,(((- (IData)((2U 
                                                  == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)))) 
                                      & (((- (IData)(
                                                     (1U 
                                                      == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                          & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_id_reg)) 
                                         | ((- (IData)(
                                                       (2U 
                                                        == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                            & (IData)(vlTOPp->io_memAXI_0_b_bits_id))))),4);
        tracep->fullBit(oldp+1431,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                    & (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                        & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_user_reg)) 
                                       | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                          & (IData)(vlTOPp->io_memAXI_0_b_bits_user))))));
        tracep->fullBit(oldp+1432,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_w_state)) 
                                    & (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                        & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_user_reg)) 
                                       | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                          & (IData)(vlTOPp->io_memAXI_0_b_bits_user))))));
        tracep->fullCData(oldp+1433,(((- (IData)((1U 
                                                  == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                      & (((- (IData)(
                                                     (1U 
                                                      == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                          & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_id_reg)) 
                                         | ((- (IData)(
                                                       (2U 
                                                        == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                            & (IData)(vlTOPp->io_memAXI_0_r_bits_id))))),4);
        tracep->fullCData(oldp+1434,(((- (IData)((2U 
                                                  == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)))) 
                                      & (((- (IData)(
                                                     (1U 
                                                      == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                          & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_id_reg)) 
                                         | ((- (IData)(
                                                       (2U 
                                                        == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                            & (IData)(vlTOPp->io_memAXI_0_r_bits_id))))),4);
        tracep->fullBit(oldp+1435,(((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                    & (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                        & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_user_reg)) 
                                       | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                          & (IData)(vlTOPp->io_memAXI_0_r_bits_user))))));
        tracep->fullBit(oldp+1436,(((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__master_r_state)) 
                                    & (((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                        & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_user_reg)) 
                                       | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                          & (IData)(vlTOPp->io_memAXI_0_r_bits_user))))));
        tracep->fullQData(oldp+1437,(vlTOPp->io_memAXI_0_r_bits_data
                                     [0U]),64);
        tracep->fullBit(oldp+1439,((0x801cc68ULL == 
                                    (0xfffffffffffffffULL 
                                     & (vlTOPp->io_memAXI_0_ar_bits_addr 
                                        >> 4U)))));
        tracep->fullBit(oldp+1440,((0x801cc68ULL == 
                                    (0xfffffffffffffffULL 
                                     & (vlTOPp->io_memAXI_0_aw_bits_addr 
                                        >> 4U)))));
        tracep->fullCData(oldp+1441,(((- (IData)((2U 
                                                  == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                      & (IData)(vlTOPp->io_memAXI_0_b_bits_resp))),2);
        tracep->fullCData(oldp+1442,((((- (IData)((1U 
                                                   == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                       & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_id_reg)) 
                                      | ((- (IData)(
                                                    (2U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))) 
                                         & (IData)(vlTOPp->io_memAXI_0_b_bits_id)))),4);
        tracep->fullBit(oldp+1443,((((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                     & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__wr_user_reg)) 
                                    | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)) 
                                       & (IData)(vlTOPp->io_memAXI_0_b_bits_user)))));
        tracep->fullCData(oldp+1444,((((- (IData)((1U 
                                                   == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                       & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_id_reg)) 
                                      | ((- (IData)(
                                                    (2U 
                                                     == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))) 
                                         & (IData)(vlTOPp->io_memAXI_0_r_bits_id)))),4);
        tracep->fullBit(oldp+1445,((((1U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                     & (IData)(vlTOPp->SimTop__DOT__Clint__DOT__rd_user_reg)) 
                                    | ((2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)) 
                                       & (IData)(vlTOPp->io_memAXI_0_r_bits_user)))));
        tracep->fullBit(oldp+1446,(((((IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__mid_r_ready) 
                                      & (IData)(vlTOPp->io_memAXI_0_r_valid)) 
                                     & (IData)(vlTOPp->io_memAXI_0_r_bits_last)) 
                                    & (2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_r_state)))));
        tracep->fullBit(oldp+1447,((((IData)(vlTOPp->io_memAXI_0_b_ready) 
                                     & (IData)(vlTOPp->io_memAXI_0_b_valid)) 
                                    & (2U == (IData)(vlTOPp->SimTop__DOT__axi_2x2__DOT__slave_w_state)))));
        tracep->fullBit(oldp+1448,((((IData)(vlTOPp->reset) 
                                     | ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena) 
                                        & (0U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__w_state)))) 
                                    | ((~ (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena)) 
                                       & (0U == (IData)(vlTOPp->SimTop__DOT__mem_axi_rw__DOT__r_state))))));
        tracep->fullBit(oldp+1449,((1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Mem_stage__DOT__mem_ram_wr_ena)
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
        tracep->fullBit(oldp+1450,(((IData)(vlTOPp->reset) 
                                    | (0U == (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__r_state)))));
        __Vtemp847[0U] = ((0xfffff800U & ((IData)((
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
        __Vtemp847[1U] = ((0x7ffU & ((IData)(((((- (QData)((IData)(
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
        __Vtemp847[2U] = (0x7ffU & ((IData)((((((- (QData)((IData)(
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
        __Vtemp853[3U] = ((0xfffffff8U & ((((((((((3U 
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
                                          | (__Vtemp847[2U] 
                                             >> 0x1eU)))))));
        __Vtemp854[6U] = ((0xfU & ((IData)(((- (QData)((IData)(
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
        __Vtemp855[7U] = ((0x1f0U & (((- (IData)(((~ (IData)(vlTOPp->reset)) 
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
        __Vtemp856[7U] = ((0xfffffe00U & (((0x7bU == 
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
                          __Vtemp855[7U]);
        __Vtemp864[2U] = ((0xfff80000U & ((((~ (IData)(vlTOPp->reset)) 
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
        __Vtemp865[0U] = (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__csr_rd_data);
        __Vtemp865[1U] = (IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__csr_rd_data 
                                  >> 0x20U));
        __Vtemp865[2U] = ((0xffc00000U & ((0xff000000U 
                                           & (__Vtemp847[0U] 
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
                          | __Vtemp864[2U]);
        __Vtemp865[3U] = ((0x3fffffU & ((0x3fffffU 
                                         & (__Vtemp847[0U] 
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
                                             & (__Vtemp847[0U] 
                                                >> 8U)) 
                                            | (0xff000000U 
                                               & (__Vtemp847[1U] 
                                                  << 0x18U)))));
        __Vtemp865[4U] = ((0x3fffffU & (__Vtemp847[1U] 
                                        >> 8U)) | (0xffc00000U 
                                                   & ((0xc00000U 
                                                       & (__Vtemp847[1U] 
                                                          >> 8U)) 
                                                      | (0xff000000U 
                                                         & (__Vtemp847[2U] 
                                                            << 0x18U)))));
        __Vtemp865[5U] = ((0x3fffffU & ((0x3ff800U 
                                         & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_alu_info) 
                                            << 0xbU)) 
                                        | ((0x3ffff8U 
                                            & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_bj_info) 
                                               << 3U)) 
                                           | (0x3fffffU 
                                              & (__Vtemp847[2U] 
                                                 >> 8U))))) 
                          | (0xffc00000U & ((0xfc000000U 
                                             & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2) 
                                                << 0x1aU)) 
                                            | (__Vtemp853[3U] 
                                               << 0x16U))));
        __Vtemp865[6U] = ((0x3fffffU & ((0x3fffffU 
                                         & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2) 
                                            >> 6U)) 
                                        | (__Vtemp853[3U] 
                                           >> 0xaU))) 
                          | (0xffc00000U & ((0x3c00000U 
                                             & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2) 
                                                >> 6U)) 
                                            | (0xfc000000U 
                                               & ((IData)(
                                                          (vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2 
                                                           >> 0x20U)) 
                                                  << 0x1aU)))));
        __Vtemp865[7U] = ((0x3fffffU & ((IData)((vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__id_op2 
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
        __Vtemp865[8U] = ((0x3fffffU & ((IData)(((- (QData)((IData)(
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
                                                   & (__Vtemp854[6U] 
                                                      << 0x16U)));
        __Vtemp865[9U] = ((0x3fffffU & (__Vtemp854[6U] 
                                        >> 0xaU)) | 
                          (0xffc00000U & (__Vtemp856[7U] 
                                          << 0x16U)));
        __Vtemp865[0xaU] = (0x3fffffU & ((0x200000U 
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
                                               | (__Vtemp856[7U] 
                                                  >> 0xaU)))));
        VL_EXTEND_WW(344,342, __Vtemp866, __Vtemp865);
        tracep->fullWData(oldp+1451,(__Vtemp866),344);
        tracep->fullQData(oldp+1462,(((- (QData)((IData)(
                                                         (1U 
                                                          & (~ (IData)(vlTOPp->reset)))))) 
                                      & ((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr) 
                                           == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_wdest)) 
                                          & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr)))
                                          ? vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_data
                                          : vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
                                         [vlTOPp->SimTop__DOT__u_cpu__DOT__rs1_r_addr]))),64);
        tracep->fullQData(oldp+1464,(((- (QData)((IData)(
                                                         (1U 
                                                          & (~ (IData)(vlTOPp->reset)))))) 
                                      & ((((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr) 
                                           == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_wdest)) 
                                          & (0U != (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr)))
                                          ? vlTOPp->SimTop__DOT__u_cpu__DOT__reg_wr_data
                                          : vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
                                         [vlTOPp->SimTop__DOT__u_cpu__DOT__rs2_r_addr]))),64);
        tracep->fullBit(oldp+1466,((((~ (IData)(vlTOPp->reset)) 
                                     & (1U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state))) 
                                    & (IData)(vlTOPp->SimTop__DOT__if_axi_rw__DOT__rw_ready))));
        tracep->fullBit(oldp+1467,((((~ (IData)(vlTOPp->reset)) 
                                     & (0U == (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__if_state))) 
                                    & vlTOPp->SimTop__DOT__u_cpu__DOT__bj_ctrl_bus[0U])));
        tracep->fullBit(oldp+1468,(((~ (IData)(vlTOPp->reset)) 
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
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                           | (0x3bU 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                          | (0x63U 
                                             == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                         | (0x67U == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                        | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg)) 
                                       | (0x7bU == 
                                          (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))));
        tracep->fullCData(oldp+1469,(((0x7bU == (0x7fU 
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
        tracep->fullBit(oldp+1470,(((~ (IData)(vlTOPp->reset)) 
                                    & ((((0x33U == 
                                          (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)) 
                                         | (0x3bU == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                        | (0x23U == 
                                           (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                       | (0x63U == 
                                          (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))));
        tracep->fullCData(oldp+1471,((0x1fU & ((- (IData)(
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
        tracep->fullBit(oldp+1472,(((~ (IData)(vlTOPp->reset)) 
                                    & (0x23U == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))));
        tracep->fullBit(oldp+1473,(((~ (IData)(vlTOPp->reset)) 
                                    & (3U == (0x7fU 
                                              & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r)))));
        tracep->fullQData(oldp+1474,(((- (QData)((IData)(
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
        tracep->fullBit(oldp+1476,(((~ (IData)(vlTOPp->reset)) 
                                    & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm) 
                                       | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg)))));
        tracep->fullBit(oldp+1477,(((~ (IData)(vlTOPp->reset)) 
                                    & (((((((((0xfU 
                                               == (0x7fU 
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
                                               == (0x7fU 
                                                   & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                           | (0x33U 
                                              == (0x7fU 
                                                  & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                          | (0x37U 
                                             == (0x7fU 
                                                 & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                         | (0x3bU == 
                                            (0x7fU 
                                             & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                        | (0x6fU == 
                                           (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))) 
                                       | (0x67U == 
                                          (0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__if_to_id_inst_r))))));
        tracep->fullCData(oldp+1478,(((((~ (IData)(vlTOPp->reset)) 
                                        & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_imm) 
                                           | (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_i_csr_reg))) 
                                       << 2U) | (((
                                                   (~ (IData)(vlTOPp->reset)) 
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
        tracep->fullBit(oldp+1479,((((~ (IData)(vlTOPp->reset)) 
                                     & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_valid)) 
                                    & (0U != ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_info) 
                                              & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__Ex_stage__DOT__ex_bj_data))))));
        tracep->fullIData(oldp+1480,(0x40U),32);
        tracep->fullIData(oldp+1481,(4U),32);
        tracep->fullIData(oldp+1482,(1U),32);
        tracep->fullCData(oldp+1483,(0U),3);
        tracep->fullCData(oldp+1484,(0U),4);
        tracep->fullBit(oldp+1485,(0U));
        tracep->fullCData(oldp+1486,(1U),2);
        tracep->fullBit(oldp+1487,(0U));
        tracep->fullCData(oldp+1488,(2U),4);
        tracep->fullBit(oldp+1489,(1U));
        tracep->fullCData(oldp+1490,(0U),2);
        tracep->fullCData(oldp+1491,(vlTOPp->SimTop__DOT__cli_ar_burst),2);
        tracep->fullBit(oldp+1492,(1U));
        tracep->fullQData(oldp+1493,(0ULL),64);
        tracep->fullCData(oldp+1495,(2U),2);
        tracep->fullCData(oldp+1496,(1U),4);
        tracep->fullCData(oldp+1497,(1U),3);
        tracep->fullCData(oldp+1498,(2U),3);
        tracep->fullCData(oldp+1499,(3U),3);
        tracep->fullCData(oldp+1500,(4U),3);
        tracep->fullIData(oldp+1501,(3U),32);
        tracep->fullIData(oldp+1502,(6U),32);
        tracep->fullIData(oldp+1503,(0x80U),32);
        tracep->fullCData(oldp+1504,(3U),4);
        tracep->fullQData(oldp+1505,(0x80000100ULL),64);
        tracep->fullSData(oldp+1507,(vlTOPp->SimTop__DOT__u_cpu__DOT__Wb_stage__DOT__wb_excp_bus),16);
        tracep->fullCData(oldp+1508,(0U),8);
        tracep->fullCData(oldp+1509,(3U),2);
    }
}
