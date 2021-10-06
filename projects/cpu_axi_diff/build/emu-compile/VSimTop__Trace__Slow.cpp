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
        tracep->declBit(c+400,"clock", false,-1);
        tracep->declBit(c+401,"reset", false,-1);
        tracep->declQuad(c+402,"io_logCtrl_log_begin", false,-1, 63,0);
        tracep->declQuad(c+404,"io_logCtrl_log_end", false,-1, 63,0);
        tracep->declQuad(c+406,"io_logCtrl_log_level", false,-1, 63,0);
        tracep->declBit(c+408,"io_perfInfo_clean", false,-1);
        tracep->declBit(c+409,"io_perfInfo_dump", false,-1);
        tracep->declBit(c+410,"io_uart_out_valid", false,-1);
        tracep->declBus(c+411,"io_uart_out_ch", false,-1, 7,0);
        tracep->declBit(c+412,"io_uart_in_valid", false,-1);
        tracep->declBus(c+413,"io_uart_in_ch", false,-1, 7,0);
        tracep->declBit(c+414,"io_memAXI_0_aw_ready", false,-1);
        tracep->declBit(c+415,"io_memAXI_0_aw_valid", false,-1);
        tracep->declQuad(c+416,"io_memAXI_0_aw_bits_addr", false,-1, 63,0);
        tracep->declBus(c+418,"io_memAXI_0_aw_bits_prot", false,-1, 2,0);
        tracep->declBus(c+419,"io_memAXI_0_aw_bits_id", false,-1, 3,0);
        tracep->declBus(c+420,"io_memAXI_0_aw_bits_user", false,-1, 0,0);
        tracep->declBus(c+421,"io_memAXI_0_aw_bits_len", false,-1, 7,0);
        tracep->declBus(c+422,"io_memAXI_0_aw_bits_size", false,-1, 2,0);
        tracep->declBus(c+423,"io_memAXI_0_aw_bits_burst", false,-1, 1,0);
        tracep->declBit(c+424,"io_memAXI_0_aw_bits_lock", false,-1);
        tracep->declBus(c+425,"io_memAXI_0_aw_bits_cache", false,-1, 3,0);
        tracep->declBus(c+426,"io_memAXI_0_aw_bits_qos", false,-1, 3,0);
        tracep->declBit(c+427,"io_memAXI_0_w_ready", false,-1);
        tracep->declBit(c+428,"io_memAXI_0_w_valid", false,-1);
        {int i; for (i=0; i<4; i++) {
                tracep->declQuad(c+429+i*2,"io_memAXI_0_w_bits_data", true,(i+0), 63,0);}}
        tracep->declBus(c+437,"io_memAXI_0_w_bits_strb", false,-1, 7,0);
        tracep->declBit(c+438,"io_memAXI_0_w_bits_last", false,-1);
        tracep->declBit(c+439,"io_memAXI_0_b_ready", false,-1);
        tracep->declBit(c+440,"io_memAXI_0_b_valid", false,-1);
        tracep->declBus(c+441,"io_memAXI_0_b_bits_resp", false,-1, 1,0);
        tracep->declBus(c+442,"io_memAXI_0_b_bits_id", false,-1, 3,0);
        tracep->declBus(c+443,"io_memAXI_0_b_bits_user", false,-1, 0,0);
        tracep->declBit(c+444,"io_memAXI_0_ar_ready", false,-1);
        tracep->declBit(c+445,"io_memAXI_0_ar_valid", false,-1);
        tracep->declQuad(c+446,"io_memAXI_0_ar_bits_addr", false,-1, 63,0);
        tracep->declBus(c+448,"io_memAXI_0_ar_bits_prot", false,-1, 2,0);
        tracep->declBus(c+449,"io_memAXI_0_ar_bits_id", false,-1, 3,0);
        tracep->declBus(c+450,"io_memAXI_0_ar_bits_user", false,-1, 0,0);
        tracep->declBus(c+451,"io_memAXI_0_ar_bits_len", false,-1, 7,0);
        tracep->declBus(c+452,"io_memAXI_0_ar_bits_size", false,-1, 2,0);
        tracep->declBus(c+453,"io_memAXI_0_ar_bits_burst", false,-1, 1,0);
        tracep->declBit(c+454,"io_memAXI_0_ar_bits_lock", false,-1);
        tracep->declBus(c+455,"io_memAXI_0_ar_bits_cache", false,-1, 3,0);
        tracep->declBus(c+456,"io_memAXI_0_ar_bits_qos", false,-1, 3,0);
        tracep->declBit(c+457,"io_memAXI_0_r_ready", false,-1);
        tracep->declBit(c+458,"io_memAXI_0_r_valid", false,-1);
        tracep->declBus(c+459,"io_memAXI_0_r_bits_resp", false,-1, 1,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declQuad(c+460+i*2,"io_memAXI_0_r_bits_data", true,(i+0), 63,0);}}
        tracep->declBit(c+468,"io_memAXI_0_r_bits_last", false,-1);
        tracep->declBus(c+469,"io_memAXI_0_r_bits_id", false,-1, 3,0);
        tracep->declBus(c+470,"io_memAXI_0_r_bits_user", false,-1, 0,0);
        tracep->declBit(c+400,"SimTop clock", false,-1);
        tracep->declBit(c+401,"SimTop reset", false,-1);
        tracep->declQuad(c+402,"SimTop io_logCtrl_log_begin", false,-1, 63,0);
        tracep->declQuad(c+404,"SimTop io_logCtrl_log_end", false,-1, 63,0);
        tracep->declQuad(c+406,"SimTop io_logCtrl_log_level", false,-1, 63,0);
        tracep->declBit(c+408,"SimTop io_perfInfo_clean", false,-1);
        tracep->declBit(c+409,"SimTop io_perfInfo_dump", false,-1);
        tracep->declBit(c+410,"SimTop io_uart_out_valid", false,-1);
        tracep->declBus(c+411,"SimTop io_uart_out_ch", false,-1, 7,0);
        tracep->declBit(c+412,"SimTop io_uart_in_valid", false,-1);
        tracep->declBus(c+413,"SimTop io_uart_in_ch", false,-1, 7,0);
        tracep->declBit(c+414,"SimTop io_memAXI_0_aw_ready", false,-1);
        tracep->declBit(c+415,"SimTop io_memAXI_0_aw_valid", false,-1);
        tracep->declQuad(c+416,"SimTop io_memAXI_0_aw_bits_addr", false,-1, 63,0);
        tracep->declBus(c+418,"SimTop io_memAXI_0_aw_bits_prot", false,-1, 2,0);
        tracep->declBus(c+419,"SimTop io_memAXI_0_aw_bits_id", false,-1, 3,0);
        tracep->declBus(c+420,"SimTop io_memAXI_0_aw_bits_user", false,-1, 0,0);
        tracep->declBus(c+421,"SimTop io_memAXI_0_aw_bits_len", false,-1, 7,0);
        tracep->declBus(c+422,"SimTop io_memAXI_0_aw_bits_size", false,-1, 2,0);
        tracep->declBus(c+423,"SimTop io_memAXI_0_aw_bits_burst", false,-1, 1,0);
        tracep->declBit(c+424,"SimTop io_memAXI_0_aw_bits_lock", false,-1);
        tracep->declBus(c+425,"SimTop io_memAXI_0_aw_bits_cache", false,-1, 3,0);
        tracep->declBus(c+426,"SimTop io_memAXI_0_aw_bits_qos", false,-1, 3,0);
        tracep->declBit(c+427,"SimTop io_memAXI_0_w_ready", false,-1);
        tracep->declBit(c+428,"SimTop io_memAXI_0_w_valid", false,-1);
        {int i; for (i=0; i<4; i++) {
                tracep->declQuad(c+429+i*2,"SimTop io_memAXI_0_w_bits_data", true,(i+0), 63,0);}}
        tracep->declBus(c+437,"SimTop io_memAXI_0_w_bits_strb", false,-1, 7,0);
        tracep->declBit(c+438,"SimTop io_memAXI_0_w_bits_last", false,-1);
        tracep->declBit(c+439,"SimTop io_memAXI_0_b_ready", false,-1);
        tracep->declBit(c+440,"SimTop io_memAXI_0_b_valid", false,-1);
        tracep->declBus(c+441,"SimTop io_memAXI_0_b_bits_resp", false,-1, 1,0);
        tracep->declBus(c+442,"SimTop io_memAXI_0_b_bits_id", false,-1, 3,0);
        tracep->declBus(c+443,"SimTop io_memAXI_0_b_bits_user", false,-1, 0,0);
        tracep->declBit(c+444,"SimTop io_memAXI_0_ar_ready", false,-1);
        tracep->declBit(c+445,"SimTop io_memAXI_0_ar_valid", false,-1);
        tracep->declQuad(c+446,"SimTop io_memAXI_0_ar_bits_addr", false,-1, 63,0);
        tracep->declBus(c+448,"SimTop io_memAXI_0_ar_bits_prot", false,-1, 2,0);
        tracep->declBus(c+449,"SimTop io_memAXI_0_ar_bits_id", false,-1, 3,0);
        tracep->declBus(c+450,"SimTop io_memAXI_0_ar_bits_user", false,-1, 0,0);
        tracep->declBus(c+451,"SimTop io_memAXI_0_ar_bits_len", false,-1, 7,0);
        tracep->declBus(c+452,"SimTop io_memAXI_0_ar_bits_size", false,-1, 2,0);
        tracep->declBus(c+453,"SimTop io_memAXI_0_ar_bits_burst", false,-1, 1,0);
        tracep->declBit(c+454,"SimTop io_memAXI_0_ar_bits_lock", false,-1);
        tracep->declBus(c+455,"SimTop io_memAXI_0_ar_bits_cache", false,-1, 3,0);
        tracep->declBus(c+456,"SimTop io_memAXI_0_ar_bits_qos", false,-1, 3,0);
        tracep->declBit(c+457,"SimTop io_memAXI_0_r_ready", false,-1);
        tracep->declBit(c+458,"SimTop io_memAXI_0_r_valid", false,-1);
        tracep->declBus(c+459,"SimTop io_memAXI_0_r_bits_resp", false,-1, 1,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declQuad(c+460+i*2,"SimTop io_memAXI_0_r_bits_data", true,(i+0), 63,0);}}
        tracep->declBit(c+468,"SimTop io_memAXI_0_r_bits_last", false,-1);
        tracep->declBus(c+469,"SimTop io_memAXI_0_r_bits_id", false,-1, 3,0);
        tracep->declBus(c+470,"SimTop io_memAXI_0_r_bits_user", false,-1, 0,0);
        tracep->declBit(c+486,"SimTop aw_ready", false,-1);
        tracep->declBit(c+487,"SimTop aw_valid", false,-1);
        tracep->declQuad(c+488,"SimTop aw_addr", false,-1, 63,0);
        tracep->declBus(c+490,"SimTop aw_prot", false,-1, 2,0);
        tracep->declBus(c+491,"SimTop aw_id", false,-1, 3,0);
        tracep->declBus(c+492,"SimTop aw_user", false,-1, 0,0);
        tracep->declBus(c+493,"SimTop aw_len", false,-1, 7,0);
        tracep->declBus(c+494,"SimTop aw_size", false,-1, 2,0);
        tracep->declBus(c+495,"SimTop aw_burst", false,-1, 1,0);
        tracep->declBit(c+496,"SimTop aw_lock", false,-1);
        tracep->declBus(c+497,"SimTop aw_cache", false,-1, 3,0);
        tracep->declBus(c+498,"SimTop aw_qos", false,-1, 3,0);
        tracep->declBus(c+499,"SimTop aw_region", false,-1, 3,0);
        tracep->declBit(c+500,"SimTop w_ready", false,-1);
        tracep->declBit(c+501,"SimTop w_valid", false,-1);
        tracep->declQuad(c+502,"SimTop w_data", false,-1, 63,0);
        tracep->declBus(c+504,"SimTop w_strb", false,-1, 7,0);
        tracep->declBit(c+505,"SimTop w_last", false,-1);
        tracep->declBus(c+506,"SimTop w_user", false,-1, 0,0);
        tracep->declBit(c+507,"SimTop b_ready", false,-1);
        tracep->declBit(c+508,"SimTop b_valid", false,-1);
        tracep->declBus(c+509,"SimTop b_resp", false,-1, 1,0);
        tracep->declBus(c+510,"SimTop b_id", false,-1, 3,0);
        tracep->declBus(c+511,"SimTop b_user", false,-1, 0,0);
        tracep->declBit(c+444,"SimTop ar_ready", false,-1);
        tracep->declBit(c+3,"SimTop ar_valid", false,-1);
        tracep->declQuad(c+4,"SimTop ar_addr", false,-1, 63,0);
        tracep->declBus(c+512,"SimTop ar_prot", false,-1, 2,0);
        tracep->declBus(c+513,"SimTop ar_id", false,-1, 3,0);
        tracep->declBus(c+514,"SimTop ar_user", false,-1, 0,0);
        tracep->declBus(c+6,"SimTop ar_len", false,-1, 7,0);
        tracep->declBus(c+515,"SimTop ar_size", false,-1, 2,0);
        tracep->declBus(c+516,"SimTop ar_burst", false,-1, 1,0);
        tracep->declBit(c+517,"SimTop ar_lock", false,-1);
        tracep->declBus(c+518,"SimTop ar_cache", false,-1, 3,0);
        tracep->declBus(c+513,"SimTop ar_qos", false,-1, 3,0);
        tracep->declBus(c+519,"SimTop ar_region", false,-1, 3,0);
        tracep->declBit(c+7,"SimTop r_ready", false,-1);
        tracep->declBit(c+458,"SimTop r_valid", false,-1);
        tracep->declBus(c+459,"SimTop r_resp", false,-1, 1,0);
        tracep->declQuad(c+471,"SimTop r_data", false,-1, 63,0);
        tracep->declBit(c+468,"SimTop r_last", false,-1);
        tracep->declBus(c+469,"SimTop r_id", false,-1, 3,0);
        tracep->declBus(c+470,"SimTop r_user", false,-1, 0,0);
        tracep->declBit(c+520,"SimTop if_valid", false,-1);
        tracep->declBit(c+8,"SimTop if_ready", false,-1);
        tracep->declBit(c+517,"SimTop req", false,-1);
        tracep->declQuad(c+9,"SimTop if_data_read", false,-1, 63,0);
        tracep->declQuad(c+521,"SimTop data_write", false,-1, 63,0);
        tracep->declQuad(c+11,"SimTop if_addr", false,-1, 63,0);
        tracep->declBus(c+523,"SimTop if_size", false,-1, 1,0);
        tracep->declBus(c+13,"SimTop if_resp", false,-1, 1,0);
        tracep->declBus(c+524,"SimTop u_axi_rw RW_DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+524,"SimTop u_axi_rw RW_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+524,"SimTop u_axi_rw AXI_DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+524,"SimTop u_axi_rw AXI_ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+525,"SimTop u_axi_rw AXI_ID_WIDTH", false,-1, 31,0);
        tracep->declBus(c+526,"SimTop u_axi_rw AXI_USER_WIDTH", false,-1, 31,0);
        tracep->declBit(c+400,"SimTop u_axi_rw clock", false,-1);
        tracep->declBit(c+401,"SimTop u_axi_rw reset", false,-1);
        tracep->declBit(c+520,"SimTop u_axi_rw rw_valid_i", false,-1);
        tracep->declBit(c+8,"SimTop u_axi_rw rw_ready_o", false,-1);
        tracep->declBit(c+517,"SimTop u_axi_rw rw_req_i", false,-1);
        tracep->declArray(c+14,"SimTop u_axi_rw data_read_o", false,-1, 64,0);
        tracep->declArray(c+527,"SimTop u_axi_rw data_write_i", false,-1, 64,0);
        tracep->declArray(c+17,"SimTop u_axi_rw rw_addr_i", false,-1, 64,0);
        tracep->declBus(c+523,"SimTop u_axi_rw rw_size_i", false,-1, 1,0);
        tracep->declBus(c+13,"SimTop u_axi_rw rw_resp_o", false,-1, 1,0);
        tracep->declBit(c+486,"SimTop u_axi_rw axi_aw_ready_i", false,-1);
        tracep->declBit(c+487,"SimTop u_axi_rw axi_aw_valid_o", false,-1);
        tracep->declQuad(c+488,"SimTop u_axi_rw axi_aw_addr_o", false,-1, 63,0);
        tracep->declBus(c+490,"SimTop u_axi_rw axi_aw_prot_o", false,-1, 2,0);
        tracep->declBus(c+491,"SimTop u_axi_rw axi_aw_id_o", false,-1, 3,0);
        tracep->declBus(c+492,"SimTop u_axi_rw axi_aw_user_o", false,-1, 0,0);
        tracep->declBus(c+493,"SimTop u_axi_rw axi_aw_len_o", false,-1, 7,0);
        tracep->declBus(c+494,"SimTop u_axi_rw axi_aw_size_o", false,-1, 2,0);
        tracep->declBus(c+495,"SimTop u_axi_rw axi_aw_burst_o", false,-1, 1,0);
        tracep->declBit(c+496,"SimTop u_axi_rw axi_aw_lock_o", false,-1);
        tracep->declBus(c+497,"SimTop u_axi_rw axi_aw_cache_o", false,-1, 3,0);
        tracep->declBus(c+498,"SimTop u_axi_rw axi_aw_qos_o", false,-1, 3,0);
        tracep->declBus(c+499,"SimTop u_axi_rw axi_aw_region_o", false,-1, 3,0);
        tracep->declBit(c+500,"SimTop u_axi_rw axi_w_ready_i", false,-1);
        tracep->declBit(c+501,"SimTop u_axi_rw axi_w_valid_o", false,-1);
        tracep->declQuad(c+502,"SimTop u_axi_rw axi_w_data_o", false,-1, 63,0);
        tracep->declBus(c+504,"SimTop u_axi_rw axi_w_strb_o", false,-1, 7,0);
        tracep->declBit(c+505,"SimTop u_axi_rw axi_w_last_o", false,-1);
        tracep->declBus(c+506,"SimTop u_axi_rw axi_w_user_o", false,-1, 0,0);
        tracep->declBit(c+507,"SimTop u_axi_rw axi_b_ready_o", false,-1);
        tracep->declBit(c+508,"SimTop u_axi_rw axi_b_valid_i", false,-1);
        tracep->declBus(c+509,"SimTop u_axi_rw axi_b_resp_i", false,-1, 1,0);
        tracep->declBus(c+510,"SimTop u_axi_rw axi_b_id_i", false,-1, 3,0);
        tracep->declBus(c+511,"SimTop u_axi_rw axi_b_user_i", false,-1, 0,0);
        tracep->declBit(c+444,"SimTop u_axi_rw axi_ar_ready_i", false,-1);
        tracep->declBit(c+3,"SimTop u_axi_rw axi_ar_valid_o", false,-1);
        tracep->declQuad(c+4,"SimTop u_axi_rw axi_ar_addr_o", false,-1, 63,0);
        tracep->declBus(c+512,"SimTop u_axi_rw axi_ar_prot_o", false,-1, 2,0);
        tracep->declBus(c+513,"SimTop u_axi_rw axi_ar_id_o", false,-1, 3,0);
        tracep->declBus(c+514,"SimTop u_axi_rw axi_ar_user_o", false,-1, 0,0);
        tracep->declBus(c+6,"SimTop u_axi_rw axi_ar_len_o", false,-1, 7,0);
        tracep->declBus(c+515,"SimTop u_axi_rw axi_ar_size_o", false,-1, 2,0);
        tracep->declBus(c+516,"SimTop u_axi_rw axi_ar_burst_o", false,-1, 1,0);
        tracep->declBit(c+517,"SimTop u_axi_rw axi_ar_lock_o", false,-1);
        tracep->declBus(c+518,"SimTop u_axi_rw axi_ar_cache_o", false,-1, 3,0);
        tracep->declBus(c+513,"SimTop u_axi_rw axi_ar_qos_o", false,-1, 3,0);
        tracep->declBus(c+519,"SimTop u_axi_rw axi_ar_region_o", false,-1, 3,0);
        tracep->declBit(c+7,"SimTop u_axi_rw axi_r_ready_o", false,-1);
        tracep->declBit(c+458,"SimTop u_axi_rw axi_r_valid_i", false,-1);
        tracep->declBus(c+459,"SimTop u_axi_rw axi_r_resp_i", false,-1, 1,0);
        tracep->declQuad(c+471,"SimTop u_axi_rw axi_r_data_i", false,-1, 63,0);
        tracep->declBit(c+468,"SimTop u_axi_rw axi_r_last_i", false,-1);
        tracep->declBus(c+469,"SimTop u_axi_rw axi_r_id_i", false,-1, 3,0);
        tracep->declBus(c+470,"SimTop u_axi_rw axi_r_user_i", false,-1, 0,0);
        tracep->declBit(c+517,"SimTop u_axi_rw w_trans", false,-1);
        tracep->declBit(c+520,"SimTop u_axi_rw r_trans", false,-1);
        tracep->declBit(c+517,"SimTop u_axi_rw w_valid", false,-1);
        tracep->declBit(c+520,"SimTop u_axi_rw r_valid", false,-1);
        tracep->declBit(c+530,"SimTop u_axi_rw aw_hs", false,-1);
        tracep->declBit(c+1,"SimTop u_axi_rw w_hs", false,-1);
        tracep->declBit(c+531,"SimTop u_axi_rw b_hs", false,-1);
        tracep->declBit(c+473,"SimTop u_axi_rw ar_hs", false,-1);
        tracep->declBit(c+325,"SimTop u_axi_rw r_hs", false,-1);
        tracep->declBit(c+2,"SimTop u_axi_rw w_done", false,-1);
        tracep->declBit(c+326,"SimTop u_axi_rw r_done", false,-1);
        tracep->declBit(c+326,"SimTop u_axi_rw trans_done", false,-1);
        tracep->declBus(c+532,"SimTop u_axi_rw W_STATE_IDLE", false,-1, 1,0);
        tracep->declBus(c+516,"SimTop u_axi_rw W_STATE_ADDR", false,-1, 1,0);
        tracep->declBus(c+523,"SimTop u_axi_rw W_STATE_WRITE", false,-1, 1,0);
        tracep->declBus(c+533,"SimTop u_axi_rw W_STATE_RESP", false,-1, 1,0);
        tracep->declBus(c+532,"SimTop u_axi_rw R_STATE_IDLE", false,-1, 1,0);
        tracep->declBus(c+516,"SimTop u_axi_rw R_STATE_ADDR", false,-1, 1,0);
        tracep->declBus(c+523,"SimTop u_axi_rw R_STATE_READ", false,-1, 1,0);
        tracep->declBus(c+20,"SimTop u_axi_rw w_state", false,-1, 1,0);
        tracep->declBus(c+21,"SimTop u_axi_rw r_state", false,-1, 1,0);
        tracep->declBit(c+22,"SimTop u_axi_rw w_state_idle", false,-1);
        tracep->declBit(c+23,"SimTop u_axi_rw w_state_addr", false,-1);
        tracep->declBit(c+24,"SimTop u_axi_rw w_state_write", false,-1);
        tracep->declBit(c+25,"SimTop u_axi_rw w_state_resp", false,-1);
        tracep->declBit(c+26,"SimTop u_axi_rw r_state_idle", false,-1);
        tracep->declBit(c+3,"SimTop u_axi_rw r_state_addr", false,-1);
        tracep->declBit(c+7,"SimTop u_axi_rw r_state_read", false,-1);
        tracep->declBus(c+27,"SimTop u_axi_rw len", false,-1, 7,0);
        tracep->declBit(c+474,"SimTop u_axi_rw len_reset", false,-1);
        tracep->declBit(c+116,"SimTop u_axi_rw len_incr_en", false,-1);
        tracep->declBus(c+534,"SimTop u_axi_rw ALIGNED_WIDTH", false,-1, 31,0);
        tracep->declBus(c+535,"SimTop u_axi_rw OFFSET_WIDTH", false,-1, 31,0);
        tracep->declBus(c+534,"SimTop u_axi_rw AXI_SIZE", false,-1, 31,0);
        tracep->declBus(c+536,"SimTop u_axi_rw MASK_WIDTH", false,-1, 31,0);
        tracep->declBus(c+526,"SimTop u_axi_rw TRANS_LEN", false,-1, 31,0);
        tracep->declBus(c+514,"SimTop u_axi_rw BLOCK_TRANS", false,-1, 0,0);
        tracep->declBit(c+28,"SimTop u_axi_rw aligned", false,-1);
        tracep->declBit(c+517,"SimTop u_axi_rw size_b", false,-1);
        tracep->declBit(c+517,"SimTop u_axi_rw size_h", false,-1);
        tracep->declBit(c+520,"SimTop u_axi_rw size_w", false,-1);
        tracep->declBit(c+517,"SimTop u_axi_rw size_d", false,-1);
        tracep->declBus(c+29,"SimTop u_axi_rw addr_op1", false,-1, 3,0);
        tracep->declBus(c+537,"SimTop u_axi_rw addr_op2", false,-1, 3,0);
        tracep->declBus(c+30,"SimTop u_axi_rw addr_end", false,-1, 3,0);
        tracep->declBit(c+31,"SimTop u_axi_rw overstep", false,-1);
        tracep->declBus(c+6,"SimTop u_axi_rw axi_len", false,-1, 7,0);
        tracep->declBus(c+515,"SimTop u_axi_rw axi_size", false,-1, 2,0);
        tracep->declQuad(c+4,"SimTop u_axi_rw axi_addr", false,-1, 63,0);
        tracep->declBus(c+32,"SimTop u_axi_rw aligned_offset_l", false,-1, 5,0);
        tracep->declBus(c+33,"SimTop u_axi_rw aligned_offset_h", false,-1, 5,0);
        tracep->declArray(c+34,"SimTop u_axi_rw mask", false,-1, 127,0);
        tracep->declQuad(c+38,"SimTop u_axi_rw mask_l", false,-1, 63,0);
        tracep->declQuad(c+40,"SimTop u_axi_rw mask_h", false,-1, 63,0);
        tracep->declBus(c+513,"SimTop u_axi_rw axi_id", false,-1, 3,0);
        tracep->declBus(c+517,"SimTop u_axi_rw axi_user", false,-1, 0,0);
        tracep->declBit(c+8,"SimTop u_axi_rw rw_ready", false,-1);
        tracep->declBit(c+326,"SimTop u_axi_rw rw_ready_nxt", false,-1);
        tracep->declBit(c+117,"SimTop u_axi_rw rw_ready_en", false,-1);
        tracep->declBus(c+13,"SimTop u_axi_rw rw_resp", false,-1, 1,0);
        tracep->declBit(c+475,"SimTop u_axi_rw rw_resp_nxt", false,-1);
        tracep->declBit(c+326,"SimTop u_axi_rw resp_en", false,-1);
        tracep->declQuad(c+327,"SimTop u_axi_rw axi_r_data_l", false,-1, 63,0);
        tracep->declQuad(c+476,"SimTop u_axi_rw axi_r_data_h", false,-1, 63,0);
        tracep->declBit(c+400,"SimTop u_cpu clock", false,-1);
        tracep->declBit(c+401,"SimTop u_cpu reset", false,-1);
        tracep->declBit(c+520,"SimTop u_cpu if_valid", false,-1);
        tracep->declBit(c+8,"SimTop u_cpu if_ready", false,-1);
        tracep->declQuad(c+9,"SimTop u_cpu if_data_read", false,-1, 63,0);
        tracep->declQuad(c+11,"SimTop u_cpu if_addr", false,-1, 63,0);
        tracep->declBus(c+523,"SimTop u_cpu if_size", false,-1, 1,0);
        tracep->declBus(c+13,"SimTop u_cpu if_resp", false,-1, 1,0);
        tracep->declQuad(c+42,"SimTop u_cpu pc", false,-1, 63,0);
        tracep->declBus(c+44,"SimTop u_cpu inst", false,-1, 31,0);
        tracep->declBit(c+478,"SimTop u_cpu rs1_r_ena", false,-1);
        tracep->declBus(c+479,"SimTop u_cpu rs1_r_addr", false,-1, 4,0);
        tracep->declBit(c+517,"SimTop u_cpu rs2_r_ena", false,-1);
        tracep->declBus(c+538,"SimTop u_cpu rs2_r_addr", false,-1, 4,0);
        tracep->declBit(c+329,"SimTop u_cpu rd_w_ena", false,-1);
        tracep->declBus(c+330,"SimTop u_cpu rd_w_addr", false,-1, 4,0);
        tracep->declBus(c+331,"SimTop u_cpu inst_type", false,-1, 4,0);
        tracep->declBus(c+332,"SimTop u_cpu inst_opcode", false,-1, 7,0);
        tracep->declQuad(c+480,"SimTop u_cpu op1", false,-1, 63,0);
        tracep->declQuad(c+482,"SimTop u_cpu op2", false,-1, 63,0);
        tracep->declQuad(c+484,"SimTop u_cpu r_data1", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu r_data2", false,-1, 63,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+333+i*2,"SimTop u_cpu regs", true,(i+0), 63,0);}}
        tracep->declBus(c+331,"SimTop u_cpu inst_type_o", false,-1, 4,0);
        tracep->declQuad(c+397,"SimTop u_cpu rd_data", false,-1, 63,0);
        tracep->declBit(c+45,"SimTop u_cpu fetched", false,-1);
        tracep->declBit(c+399,"SimTop u_cpu w_ena", false,-1);
        tracep->declBit(c+182,"SimTop u_cpu cmt_wen", false,-1);
        tracep->declBus(c+183,"SimTop u_cpu cmt_wdest", false,-1, 7,0);
        tracep->declQuad(c+184,"SimTop u_cpu cmt_wdata", false,-1, 63,0);
        tracep->declQuad(c+186,"SimTop u_cpu cmt_pc", false,-1, 63,0);
        tracep->declBus(c+188,"SimTop u_cpu cmt_inst", false,-1, 31,0);
        tracep->declBit(c+189,"SimTop u_cpu cmt_valid", false,-1);
        tracep->declBit(c+190,"SimTop u_cpu trap", false,-1);
        tracep->declBus(c+191,"SimTop u_cpu trap_code", false,-1, 7,0);
        tracep->declQuad(c+192,"SimTop u_cpu cycleCnt", false,-1, 63,0);
        tracep->declQuad(c+194,"SimTop u_cpu instrCnt", false,-1, 63,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+196+i*2,"SimTop u_cpu regs_diff", true,(i+0), 63,0);}}
        tracep->declBit(c+45,"SimTop u_cpu inst_valid", false,-1);
        tracep->declBit(c+400,"SimTop u_cpu If_stage clk", false,-1);
        tracep->declBit(c+401,"SimTop u_cpu If_stage rst", false,-1);
        tracep->declQuad(c+42,"SimTop u_cpu If_stage pc", false,-1, 63,0);
        tracep->declBus(c+44,"SimTop u_cpu If_stage inst", false,-1, 31,0);
        tracep->declBit(c+520,"SimTop u_cpu If_stage if_valid", false,-1);
        tracep->declBit(c+8,"SimTop u_cpu If_stage if_ready", false,-1);
        tracep->declQuad(c+9,"SimTop u_cpu If_stage if_data_read", false,-1, 63,0);
        tracep->declQuad(c+11,"SimTop u_cpu If_stage if_addr", false,-1, 63,0);
        tracep->declBus(c+523,"SimTop u_cpu If_stage if_size", false,-1, 1,0);
        tracep->declBus(c+13,"SimTop u_cpu If_stage if_resp", false,-1, 1,0);
        tracep->declBit(c+45,"SimTop u_cpu If_stage fetched", false,-1);
        tracep->declBit(c+8,"SimTop u_cpu If_stage handshake_done", false,-1);
        tracep->declQuad(c+541,"SimTop u_cpu If_stage addr", false,-1, 63,0);
        tracep->declBit(c+401,"SimTop u_cpu Id_stage rst", false,-1);
        tracep->declBus(c+44,"SimTop u_cpu Id_stage inst", false,-1, 31,0);
        tracep->declQuad(c+484,"SimTop u_cpu Id_stage rs1_data", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu Id_stage rs2_data", false,-1, 63,0);
        tracep->declBit(c+478,"SimTop u_cpu Id_stage rs1_r_ena", false,-1);
        tracep->declBus(c+479,"SimTop u_cpu Id_stage rs1_r_addr", false,-1, 4,0);
        tracep->declBit(c+517,"SimTop u_cpu Id_stage rs2_r_ena", false,-1);
        tracep->declBus(c+538,"SimTop u_cpu Id_stage rs2_r_addr", false,-1, 4,0);
        tracep->declBit(c+329,"SimTop u_cpu Id_stage rd_w_ena", false,-1);
        tracep->declBus(c+330,"SimTop u_cpu Id_stage rd_w_addr", false,-1, 4,0);
        tracep->declBus(c+331,"SimTop u_cpu Id_stage inst_type", false,-1, 4,0);
        tracep->declBus(c+332,"SimTop u_cpu Id_stage inst_opcode", false,-1, 7,0);
        tracep->declQuad(c+480,"SimTop u_cpu Id_stage op1", false,-1, 63,0);
        tracep->declQuad(c+482,"SimTop u_cpu Id_stage op2", false,-1, 63,0);
        tracep->declBit(c+46,"SimTop u_cpu Id_stage inst_addi", false,-1);
        tracep->declBus(c+47,"SimTop u_cpu Id_stage opcode", false,-1, 6,0);
        tracep->declBus(c+48,"SimTop u_cpu Id_stage rd", false,-1, 4,0);
        tracep->declBus(c+49,"SimTop u_cpu Id_stage func3", false,-1, 2,0);
        tracep->declBus(c+50,"SimTop u_cpu Id_stage rs1", false,-1, 4,0);
        tracep->declBus(c+51,"SimTop u_cpu Id_stage imm", false,-1, 11,0);
        tracep->declBit(c+401,"SimTop u_cpu Exe_stage rst", false,-1);
        tracep->declBus(c+331,"SimTop u_cpu Exe_stage inst_type_i", false,-1, 4,0);
        tracep->declBus(c+332,"SimTop u_cpu Exe_stage inst_opcode", false,-1, 7,0);
        tracep->declQuad(c+480,"SimTop u_cpu Exe_stage op1", false,-1, 63,0);
        tracep->declQuad(c+482,"SimTop u_cpu Exe_stage op2", false,-1, 63,0);
        tracep->declBus(c+331,"SimTop u_cpu Exe_stage inst_type_o", false,-1, 4,0);
        tracep->declQuad(c+397,"SimTop u_cpu Exe_stage rd_data", false,-1, 63,0);
        tracep->declBit(c+400,"SimTop u_cpu Regfile clk", false,-1);
        tracep->declBit(c+401,"SimTop u_cpu Regfile rst", false,-1);
        tracep->declBus(c+330,"SimTop u_cpu Regfile w_addr", false,-1, 4,0);
        tracep->declQuad(c+397,"SimTop u_cpu Regfile w_data", false,-1, 63,0);
        tracep->declBit(c+399,"SimTop u_cpu Regfile w_ena", false,-1);
        tracep->declBus(c+479,"SimTop u_cpu Regfile r_addr1", false,-1, 4,0);
        tracep->declQuad(c+484,"SimTop u_cpu Regfile r_data1", false,-1, 63,0);
        tracep->declBit(c+478,"SimTop u_cpu Regfile r_ena1", false,-1);
        tracep->declBus(c+538,"SimTop u_cpu Regfile r_addr2", false,-1, 4,0);
        tracep->declQuad(c+539,"SimTop u_cpu Regfile r_data2", false,-1, 63,0);
        tracep->declBit(c+517,"SimTop u_cpu Regfile r_ena2", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+118+i*2,"SimTop u_cpu Regfile regs_o", true,(i+0), 63,0);}}
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+52+i*2,"SimTop u_cpu Regfile regs", true,(i+0), 63,0);}}
        tracep->declBit(c+400,"SimTop u_cpu DifftestInstrCommit clock", false,-1);
        tracep->declBus(c+543,"SimTop u_cpu DifftestInstrCommit coreid", false,-1, 7,0);
        tracep->declBus(c+543,"SimTop u_cpu DifftestInstrCommit index", false,-1, 7,0);
        tracep->declBit(c+189,"SimTop u_cpu DifftestInstrCommit valid", false,-1);
        tracep->declQuad(c+186,"SimTop u_cpu DifftestInstrCommit pc", false,-1, 63,0);
        tracep->declBus(c+188,"SimTop u_cpu DifftestInstrCommit instr", false,-1, 31,0);
        tracep->declBit(c+517,"SimTop u_cpu DifftestInstrCommit skip", false,-1);
        tracep->declBit(c+517,"SimTop u_cpu DifftestInstrCommit isRVC", false,-1);
        tracep->declBit(c+517,"SimTop u_cpu DifftestInstrCommit scFailed", false,-1);
        tracep->declBit(c+182,"SimTop u_cpu DifftestInstrCommit wen", false,-1);
        tracep->declBus(c+183,"SimTop u_cpu DifftestInstrCommit wdest", false,-1, 7,0);
        tracep->declQuad(c+184,"SimTop u_cpu DifftestInstrCommit wdata", false,-1, 63,0);
        tracep->declBit(c+400,"SimTop u_cpu DifftestArchIntRegState clock", false,-1);
        tracep->declBus(c+543,"SimTop u_cpu DifftestArchIntRegState coreid", false,-1, 7,0);
        tracep->declQuad(c+260,"SimTop u_cpu DifftestArchIntRegState gpr_0", false,-1, 63,0);
        tracep->declQuad(c+262,"SimTop u_cpu DifftestArchIntRegState gpr_1", false,-1, 63,0);
        tracep->declQuad(c+264,"SimTop u_cpu DifftestArchIntRegState gpr_2", false,-1, 63,0);
        tracep->declQuad(c+266,"SimTop u_cpu DifftestArchIntRegState gpr_3", false,-1, 63,0);
        tracep->declQuad(c+268,"SimTop u_cpu DifftestArchIntRegState gpr_4", false,-1, 63,0);
        tracep->declQuad(c+270,"SimTop u_cpu DifftestArchIntRegState gpr_5", false,-1, 63,0);
        tracep->declQuad(c+272,"SimTop u_cpu DifftestArchIntRegState gpr_6", false,-1, 63,0);
        tracep->declQuad(c+274,"SimTop u_cpu DifftestArchIntRegState gpr_7", false,-1, 63,0);
        tracep->declQuad(c+276,"SimTop u_cpu DifftestArchIntRegState gpr_8", false,-1, 63,0);
        tracep->declQuad(c+278,"SimTop u_cpu DifftestArchIntRegState gpr_9", false,-1, 63,0);
        tracep->declQuad(c+280,"SimTop u_cpu DifftestArchIntRegState gpr_10", false,-1, 63,0);
        tracep->declQuad(c+282,"SimTop u_cpu DifftestArchIntRegState gpr_11", false,-1, 63,0);
        tracep->declQuad(c+284,"SimTop u_cpu DifftestArchIntRegState gpr_12", false,-1, 63,0);
        tracep->declQuad(c+286,"SimTop u_cpu DifftestArchIntRegState gpr_13", false,-1, 63,0);
        tracep->declQuad(c+288,"SimTop u_cpu DifftestArchIntRegState gpr_14", false,-1, 63,0);
        tracep->declQuad(c+290,"SimTop u_cpu DifftestArchIntRegState gpr_15", false,-1, 63,0);
        tracep->declQuad(c+292,"SimTop u_cpu DifftestArchIntRegState gpr_16", false,-1, 63,0);
        tracep->declQuad(c+294,"SimTop u_cpu DifftestArchIntRegState gpr_17", false,-1, 63,0);
        tracep->declQuad(c+296,"SimTop u_cpu DifftestArchIntRegState gpr_18", false,-1, 63,0);
        tracep->declQuad(c+298,"SimTop u_cpu DifftestArchIntRegState gpr_19", false,-1, 63,0);
        tracep->declQuad(c+300,"SimTop u_cpu DifftestArchIntRegState gpr_20", false,-1, 63,0);
        tracep->declQuad(c+302,"SimTop u_cpu DifftestArchIntRegState gpr_21", false,-1, 63,0);
        tracep->declQuad(c+304,"SimTop u_cpu DifftestArchIntRegState gpr_22", false,-1, 63,0);
        tracep->declQuad(c+306,"SimTop u_cpu DifftestArchIntRegState gpr_23", false,-1, 63,0);
        tracep->declQuad(c+308,"SimTop u_cpu DifftestArchIntRegState gpr_24", false,-1, 63,0);
        tracep->declQuad(c+310,"SimTop u_cpu DifftestArchIntRegState gpr_25", false,-1, 63,0);
        tracep->declQuad(c+312,"SimTop u_cpu DifftestArchIntRegState gpr_26", false,-1, 63,0);
        tracep->declQuad(c+314,"SimTop u_cpu DifftestArchIntRegState gpr_27", false,-1, 63,0);
        tracep->declQuad(c+316,"SimTop u_cpu DifftestArchIntRegState gpr_28", false,-1, 63,0);
        tracep->declQuad(c+318,"SimTop u_cpu DifftestArchIntRegState gpr_29", false,-1, 63,0);
        tracep->declQuad(c+320,"SimTop u_cpu DifftestArchIntRegState gpr_30", false,-1, 63,0);
        tracep->declQuad(c+322,"SimTop u_cpu DifftestArchIntRegState gpr_31", false,-1, 63,0);
        tracep->declBit(c+400,"SimTop u_cpu DifftestTrapEvent clock", false,-1);
        tracep->declBus(c+543,"SimTop u_cpu DifftestTrapEvent coreid", false,-1, 7,0);
        tracep->declBit(c+190,"SimTop u_cpu DifftestTrapEvent valid", false,-1);
        tracep->declBus(c+324,"SimTop u_cpu DifftestTrapEvent code", false,-1, 2,0);
        tracep->declQuad(c+186,"SimTop u_cpu DifftestTrapEvent pc", false,-1, 63,0);
        tracep->declQuad(c+192,"SimTop u_cpu DifftestTrapEvent cycleCnt", false,-1, 63,0);
        tracep->declQuad(c+194,"SimTop u_cpu DifftestTrapEvent instrCnt", false,-1, 63,0);
        tracep->declBit(c+400,"SimTop u_cpu DifftestCSRState clock", false,-1);
        tracep->declBus(c+543,"SimTop u_cpu DifftestCSRState coreid", false,-1, 7,0);
        tracep->declBus(c+533,"SimTop u_cpu DifftestCSRState priviledgeMode", false,-1, 1,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState mstatus", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState sstatus", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState mepc", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState sepc", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState mtval", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState stval", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState mtvec", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState stvec", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState mcause", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState scause", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState satp", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState mip", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState mie", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState mscratch", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState sscratch", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState mideleg", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestCSRState medeleg", false,-1, 63,0);
        tracep->declBit(c+400,"SimTop u_cpu DifftestArchFpRegState clock", false,-1);
        tracep->declBus(c+543,"SimTop u_cpu DifftestArchFpRegState coreid", false,-1, 7,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_0", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_1", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_2", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_3", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_4", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_5", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_6", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_7", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_8", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_9", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_10", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_11", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_12", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_13", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_14", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_15", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_16", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_17", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_18", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_19", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_20", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_21", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_22", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_23", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_24", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_25", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_26", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_27", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_28", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_29", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_30", false,-1, 63,0);
        tracep->declQuad(c+539,"SimTop u_cpu DifftestArchFpRegState fpr_31", false,-1, 63,0);
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
    VlWide<3>/*95:0*/ __Vtemp21;
    VlWide<3>/*95:0*/ __Vtemp22;
    VlWide<3>/*95:0*/ __Vtemp23;
    VlWide<3>/*95:0*/ __Vtemp24;
    VlWide<3>/*95:0*/ __Vtemp25;
    VlWide<3>/*95:0*/ __Vtemp26;
    VlWide<3>/*95:0*/ __Vtemp27;
    VlWide<3>/*95:0*/ __Vtemp28;
    VlWide<4>/*127:0*/ __Vtemp29;
    VlWide<3>/*95:0*/ __Vtemp30;
    VlWide<4>/*127:0*/ __Vtemp31;
    VlWide<4>/*127:0*/ __Vtemp32;
    VlWide<3>/*95:0*/ __Vtemp33;
    VlWide<4>/*127:0*/ __Vtemp34;
    VlWide<4>/*127:0*/ __Vtemp35;
    VlWide<3>/*95:0*/ __Vtemp36;
    VlWide<4>/*127:0*/ __Vtemp37;
    VlWide<4>/*127:0*/ __Vtemp38;
    VlWide<3>/*95:0*/ __Vtemp39;
    VlWide<4>/*127:0*/ __Vtemp40;
    VlWide<3>/*95:0*/ __Vtemp41;
    VlWide<3>/*95:0*/ __Vtemp42;
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_hs));
        tracep->fullBit(oldp+2,(((IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_hs) 
                                 & (IData)(vlTOPp->SimTop__DOT__w_last))));
        tracep->fullBit(oldp+3,((1U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_state))));
        VL_EXTEND_WQ(65,64, __Vtemp21, vlTOPp->SimTop__DOT__if_addr);
        tracep->fullQData(oldp+4,((0xfffffffffffffff8ULL 
                                   & (((QData)((IData)(
                                                       __Vtemp21[1U])) 
                                       << 0x20U) | 
                                      (0xfffffffffffffff8ULL 
                                       & (QData)((IData)(
                                                         __Vtemp21[0U])))))),64);
        tracep->fullCData(oldp+6,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__axi_len),8);
        tracep->fullBit(oldp+7,((2U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_state))));
        tracep->fullBit(oldp+8,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__rw_ready));
        tracep->fullQData(oldp+9,((((QData)((IData)(
                                                    vlTOPp->SimTop__DOT____Vcellout__u_axi_rw__data_read_o[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlTOPp->SimTop__DOT____Vcellout__u_axi_rw__data_read_o[0U])))),64);
        tracep->fullQData(oldp+11,(vlTOPp->SimTop__DOT__if_addr),64);
        tracep->fullCData(oldp+13,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__rw_resp),2);
        tracep->fullWData(oldp+14,(vlTOPp->SimTop__DOT____Vcellout__u_axi_rw__data_read_o),65);
        VL_EXTEND_WQ(65,64, __Vtemp22, vlTOPp->SimTop__DOT__if_addr);
        tracep->fullWData(oldp+17,(__Vtemp22),65);
        tracep->fullCData(oldp+20,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_state),2);
        tracep->fullCData(oldp+21,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_state),2);
        tracep->fullBit(oldp+22,((0U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_state))));
        tracep->fullBit(oldp+23,((1U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_state))));
        tracep->fullBit(oldp+24,((2U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_state))));
        tracep->fullBit(oldp+25,((3U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_state))));
        tracep->fullBit(oldp+26,((0U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_state))));
        tracep->fullCData(oldp+27,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__len),8);
        VL_EXTEND_WQ(65,64, __Vtemp23, vlTOPp->SimTop__DOT__if_addr);
        tracep->fullBit(oldp+28,((0U == (7U & __Vtemp23[0U]))));
        VL_EXTEND_WQ(65,64, __Vtemp24, vlTOPp->SimTop__DOT__if_addr);
        tracep->fullCData(oldp+29,((7U & __Vtemp24[0U])),4);
        VL_EXTEND_WQ(65,64, __Vtemp25, vlTOPp->SimTop__DOT__if_addr);
        tracep->fullCData(oldp+30,((0xfU & ((IData)(3U) 
                                            + (7U & 
                                               __Vtemp25[0U])))),4);
        VL_EXTEND_WQ(65,64, __Vtemp26, vlTOPp->SimTop__DOT__if_addr);
        tracep->fullBit(oldp+31,((1U & (((IData)(3U) 
                                         + (7U & __Vtemp26[0U])) 
                                        >> 3U))));
        VL_EXTEND_WQ(65,64, __Vtemp27, vlTOPp->SimTop__DOT__if_addr);
        tracep->fullCData(oldp+32,((0x38U & (__Vtemp27[0U] 
                                             << 3U))),6);
        VL_EXTEND_WQ(65,64, __Vtemp28, vlTOPp->SimTop__DOT__if_addr);
        tracep->fullCData(oldp+33,((0x3fU & (- (0x38U 
                                                & (__Vtemp28[0U] 
                                                   << 3U))))),6);
        __Vtemp29[0U] = 0xffffffffU;
        __Vtemp29[1U] = 0U;
        __Vtemp29[2U] = 0U;
        __Vtemp29[3U] = 0U;
        VL_EXTEND_WQ(65,64, __Vtemp30, vlTOPp->SimTop__DOT__if_addr);
        VL_SHIFTL_WWI(128,128,6, __Vtemp31, __Vtemp29, 
                      (0x38U & (__Vtemp30[0U] << 3U)));
        tracep->fullWData(oldp+34,(__Vtemp31),128);
        __Vtemp32[0U] = 0xffffffffU;
        __Vtemp32[1U] = 0U;
        __Vtemp32[2U] = 0U;
        __Vtemp32[3U] = 0U;
        VL_EXTEND_WQ(65,64, __Vtemp33, vlTOPp->SimTop__DOT__if_addr);
        VL_SHIFTL_WWI(128,128,6, __Vtemp34, __Vtemp32, 
                      (0x38U & (__Vtemp33[0U] << 3U)));
        tracep->fullQData(oldp+38,((((QData)((IData)(
                                                     __Vtemp34[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 __Vtemp34[0U])))),64);
        __Vtemp35[0U] = 0xffffffffU;
        __Vtemp35[1U] = 0U;
        __Vtemp35[2U] = 0U;
        __Vtemp35[3U] = 0U;
        VL_EXTEND_WQ(65,64, __Vtemp36, vlTOPp->SimTop__DOT__if_addr);
        VL_SHIFTL_WWI(128,128,6, __Vtemp37, __Vtemp35, 
                      (0x38U & (__Vtemp36[0U] << 3U)));
        tracep->fullQData(oldp+40,((((QData)((IData)(
                                                     __Vtemp37[3U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 __Vtemp37[2U])))),64);
        tracep->fullQData(oldp+42,(vlTOPp->SimTop__DOT__u_cpu__DOT__pc),64);
        tracep->fullIData(oldp+44,(vlTOPp->SimTop__DOT__u_cpu__DOT__inst),32);
        tracep->fullBit(oldp+45,(vlTOPp->SimTop__DOT__u_cpu__DOT__fetched));
        tracep->fullBit(oldp+46,(vlTOPp->SimTop__DOT__u_cpu__DOT__Id_stage__DOT__inst_addi));
        tracep->fullCData(oldp+47,((0x7fU & vlTOPp->SimTop__DOT__u_cpu__DOT__inst)),7);
        tracep->fullCData(oldp+48,((0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__inst 
                                             >> 7U))),5);
        tracep->fullCData(oldp+49,((7U & (vlTOPp->SimTop__DOT__u_cpu__DOT__inst 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+50,((0x1fU & (vlTOPp->SimTop__DOT__u_cpu__DOT__inst 
                                             >> 0xfU))),5);
        tracep->fullSData(oldp+51,((0xfffU & (vlTOPp->SimTop__DOT__u_cpu__DOT__inst 
                                              >> 0x14U))),12);
        tracep->fullQData(oldp+52,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[0]),64);
        tracep->fullQData(oldp+54,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[1]),64);
        tracep->fullQData(oldp+56,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[2]),64);
        tracep->fullQData(oldp+58,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[3]),64);
        tracep->fullQData(oldp+60,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[4]),64);
        tracep->fullQData(oldp+62,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[5]),64);
        tracep->fullQData(oldp+64,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[6]),64);
        tracep->fullQData(oldp+66,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[7]),64);
        tracep->fullQData(oldp+68,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[8]),64);
        tracep->fullQData(oldp+70,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[9]),64);
        tracep->fullQData(oldp+72,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[10]),64);
        tracep->fullQData(oldp+74,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[11]),64);
        tracep->fullQData(oldp+76,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[12]),64);
        tracep->fullQData(oldp+78,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[13]),64);
        tracep->fullQData(oldp+80,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[14]),64);
        tracep->fullQData(oldp+82,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[15]),64);
        tracep->fullQData(oldp+84,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[16]),64);
        tracep->fullQData(oldp+86,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[17]),64);
        tracep->fullQData(oldp+88,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[18]),64);
        tracep->fullQData(oldp+90,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[19]),64);
        tracep->fullQData(oldp+92,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[20]),64);
        tracep->fullQData(oldp+94,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[21]),64);
        tracep->fullQData(oldp+96,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[22]),64);
        tracep->fullQData(oldp+98,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[23]),64);
        tracep->fullQData(oldp+100,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[24]),64);
        tracep->fullQData(oldp+102,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[25]),64);
        tracep->fullQData(oldp+104,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[26]),64);
        tracep->fullQData(oldp+106,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[27]),64);
        tracep->fullQData(oldp+108,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[28]),64);
        tracep->fullQData(oldp+110,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[29]),64);
        tracep->fullQData(oldp+112,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[30]),64);
        tracep->fullQData(oldp+114,(vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs[31]),64);
        tracep->fullBit(oldp+116,((((IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__len) 
                                    != (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__axi_len)) 
                                   & ((IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__w_hs) 
                                      | (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_hs)))));
        tracep->fullBit(oldp+117,(((IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_done) 
                                   | (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__rw_ready))));
        tracep->fullQData(oldp+118,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[0]),64);
        tracep->fullQData(oldp+120,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[1]),64);
        tracep->fullQData(oldp+122,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[2]),64);
        tracep->fullQData(oldp+124,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[3]),64);
        tracep->fullQData(oldp+126,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[4]),64);
        tracep->fullQData(oldp+128,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[5]),64);
        tracep->fullQData(oldp+130,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[6]),64);
        tracep->fullQData(oldp+132,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[7]),64);
        tracep->fullQData(oldp+134,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[8]),64);
        tracep->fullQData(oldp+136,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[9]),64);
        tracep->fullQData(oldp+138,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[10]),64);
        tracep->fullQData(oldp+140,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[11]),64);
        tracep->fullQData(oldp+142,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[12]),64);
        tracep->fullQData(oldp+144,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[13]),64);
        tracep->fullQData(oldp+146,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[14]),64);
        tracep->fullQData(oldp+148,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[15]),64);
        tracep->fullQData(oldp+150,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[16]),64);
        tracep->fullQData(oldp+152,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[17]),64);
        tracep->fullQData(oldp+154,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[18]),64);
        tracep->fullQData(oldp+156,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[19]),64);
        tracep->fullQData(oldp+158,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[20]),64);
        tracep->fullQData(oldp+160,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[21]),64);
        tracep->fullQData(oldp+162,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[22]),64);
        tracep->fullQData(oldp+164,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[23]),64);
        tracep->fullQData(oldp+166,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[24]),64);
        tracep->fullQData(oldp+168,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[25]),64);
        tracep->fullQData(oldp+170,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[26]),64);
        tracep->fullQData(oldp+172,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[27]),64);
        tracep->fullQData(oldp+174,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[28]),64);
        tracep->fullQData(oldp+176,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[29]),64);
        tracep->fullQData(oldp+178,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[30]),64);
        tracep->fullQData(oldp+180,(vlTOPp->SimTop__DOT__u_cpu__DOT____Vcellout__Regfile__regs_o[31]),64);
        tracep->fullBit(oldp+182,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wen));
        tracep->fullCData(oldp+183,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wdest),8);
        tracep->fullQData(oldp+184,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_wdata),64);
        tracep->fullQData(oldp+186,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_pc),64);
        tracep->fullIData(oldp+188,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_inst),32);
        tracep->fullBit(oldp+189,(vlTOPp->SimTop__DOT__u_cpu__DOT__cmt_valid));
        tracep->fullBit(oldp+190,(vlTOPp->SimTop__DOT__u_cpu__DOT__trap));
        tracep->fullCData(oldp+191,(vlTOPp->SimTop__DOT__u_cpu__DOT__trap_code),8);
        tracep->fullQData(oldp+192,(vlTOPp->SimTop__DOT__u_cpu__DOT__cycleCnt),64);
        tracep->fullQData(oldp+194,(vlTOPp->SimTop__DOT__u_cpu__DOT__instrCnt),64);
        tracep->fullQData(oldp+196,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[0]),64);
        tracep->fullQData(oldp+198,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[1]),64);
        tracep->fullQData(oldp+200,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[2]),64);
        tracep->fullQData(oldp+202,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[3]),64);
        tracep->fullQData(oldp+204,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[4]),64);
        tracep->fullQData(oldp+206,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[5]),64);
        tracep->fullQData(oldp+208,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[6]),64);
        tracep->fullQData(oldp+210,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[7]),64);
        tracep->fullQData(oldp+212,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[8]),64);
        tracep->fullQData(oldp+214,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[9]),64);
        tracep->fullQData(oldp+216,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[10]),64);
        tracep->fullQData(oldp+218,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[11]),64);
        tracep->fullQData(oldp+220,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[12]),64);
        tracep->fullQData(oldp+222,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[13]),64);
        tracep->fullQData(oldp+224,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[14]),64);
        tracep->fullQData(oldp+226,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[15]),64);
        tracep->fullQData(oldp+228,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[16]),64);
        tracep->fullQData(oldp+230,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[17]),64);
        tracep->fullQData(oldp+232,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[18]),64);
        tracep->fullQData(oldp+234,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[19]),64);
        tracep->fullQData(oldp+236,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[20]),64);
        tracep->fullQData(oldp+238,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[21]),64);
        tracep->fullQData(oldp+240,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[22]),64);
        tracep->fullQData(oldp+242,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[23]),64);
        tracep->fullQData(oldp+244,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[24]),64);
        tracep->fullQData(oldp+246,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[25]),64);
        tracep->fullQData(oldp+248,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[26]),64);
        tracep->fullQData(oldp+250,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[27]),64);
        tracep->fullQData(oldp+252,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[28]),64);
        tracep->fullQData(oldp+254,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[29]),64);
        tracep->fullQData(oldp+256,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[30]),64);
        tracep->fullQData(oldp+258,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff[31]),64);
        tracep->fullQData(oldp+260,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0U]),64);
        tracep->fullQData(oldp+262,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [1U]),64);
        tracep->fullQData(oldp+264,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [2U]),64);
        tracep->fullQData(oldp+266,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [3U]),64);
        tracep->fullQData(oldp+268,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [4U]),64);
        tracep->fullQData(oldp+270,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [5U]),64);
        tracep->fullQData(oldp+272,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [6U]),64);
        tracep->fullQData(oldp+274,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [7U]),64);
        tracep->fullQData(oldp+276,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [8U]),64);
        tracep->fullQData(oldp+278,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [9U]),64);
        tracep->fullQData(oldp+280,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0xaU]),64);
        tracep->fullQData(oldp+282,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0xbU]),64);
        tracep->fullQData(oldp+284,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0xcU]),64);
        tracep->fullQData(oldp+286,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0xdU]),64);
        tracep->fullQData(oldp+288,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0xeU]),64);
        tracep->fullQData(oldp+290,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0xfU]),64);
        tracep->fullQData(oldp+292,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x10U]),64);
        tracep->fullQData(oldp+294,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x11U]),64);
        tracep->fullQData(oldp+296,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x12U]),64);
        tracep->fullQData(oldp+298,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x13U]),64);
        tracep->fullQData(oldp+300,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x14U]),64);
        tracep->fullQData(oldp+302,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x15U]),64);
        tracep->fullQData(oldp+304,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x16U]),64);
        tracep->fullQData(oldp+306,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x17U]),64);
        tracep->fullQData(oldp+308,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x18U]),64);
        tracep->fullQData(oldp+310,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x19U]),64);
        tracep->fullQData(oldp+312,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x1aU]),64);
        tracep->fullQData(oldp+314,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x1bU]),64);
        tracep->fullQData(oldp+316,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x1cU]),64);
        tracep->fullQData(oldp+318,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x1dU]),64);
        tracep->fullQData(oldp+320,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x1eU]),64);
        tracep->fullQData(oldp+322,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs_diff
                                    [0x1fU]),64);
        tracep->fullCData(oldp+324,((7U & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__trap_code))),3);
        tracep->fullBit(oldp+325,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_hs));
        tracep->fullBit(oldp+326,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_done));
        tracep->fullQData(oldp+327,(vlTOPp->SimTop__DOT__u_axi_rw__DOT__axi_r_data_l),64);
        tracep->fullBit(oldp+329,(vlTOPp->SimTop__DOT__u_cpu__DOT__rd_w_ena));
        tracep->fullCData(oldp+330,(vlTOPp->SimTop__DOT__u_cpu__DOT__rd_w_addr),5);
        tracep->fullCData(oldp+331,(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_type),5);
        tracep->fullCData(oldp+332,(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_opcode),8);
        tracep->fullQData(oldp+333,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[0]),64);
        tracep->fullQData(oldp+335,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[1]),64);
        tracep->fullQData(oldp+337,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[2]),64);
        tracep->fullQData(oldp+339,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[3]),64);
        tracep->fullQData(oldp+341,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[4]),64);
        tracep->fullQData(oldp+343,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[5]),64);
        tracep->fullQData(oldp+345,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[6]),64);
        tracep->fullQData(oldp+347,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[7]),64);
        tracep->fullQData(oldp+349,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[8]),64);
        tracep->fullQData(oldp+351,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[9]),64);
        tracep->fullQData(oldp+353,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[10]),64);
        tracep->fullQData(oldp+355,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[11]),64);
        tracep->fullQData(oldp+357,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[12]),64);
        tracep->fullQData(oldp+359,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[13]),64);
        tracep->fullQData(oldp+361,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[14]),64);
        tracep->fullQData(oldp+363,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[15]),64);
        tracep->fullQData(oldp+365,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[16]),64);
        tracep->fullQData(oldp+367,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[17]),64);
        tracep->fullQData(oldp+369,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[18]),64);
        tracep->fullQData(oldp+371,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[19]),64);
        tracep->fullQData(oldp+373,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[20]),64);
        tracep->fullQData(oldp+375,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[21]),64);
        tracep->fullQData(oldp+377,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[22]),64);
        tracep->fullQData(oldp+379,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[23]),64);
        tracep->fullQData(oldp+381,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[24]),64);
        tracep->fullQData(oldp+383,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[25]),64);
        tracep->fullQData(oldp+385,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[26]),64);
        tracep->fullQData(oldp+387,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[27]),64);
        tracep->fullQData(oldp+389,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[28]),64);
        tracep->fullQData(oldp+391,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[29]),64);
        tracep->fullQData(oldp+393,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[30]),64);
        tracep->fullQData(oldp+395,(vlTOPp->SimTop__DOT__u_cpu__DOT__regs[31]),64);
        tracep->fullQData(oldp+397,(vlTOPp->SimTop__DOT__u_cpu__DOT__rd_data),64);
        tracep->fullBit(oldp+399,(vlTOPp->SimTop__DOT__u_cpu__DOT__w_ena));
        tracep->fullBit(oldp+400,(vlTOPp->clock));
        tracep->fullBit(oldp+401,(vlTOPp->reset));
        tracep->fullQData(oldp+402,(vlTOPp->io_logCtrl_log_begin),64);
        tracep->fullQData(oldp+404,(vlTOPp->io_logCtrl_log_end),64);
        tracep->fullQData(oldp+406,(vlTOPp->io_logCtrl_log_level),64);
        tracep->fullBit(oldp+408,(vlTOPp->io_perfInfo_clean));
        tracep->fullBit(oldp+409,(vlTOPp->io_perfInfo_dump));
        tracep->fullBit(oldp+410,(vlTOPp->io_uart_out_valid));
        tracep->fullCData(oldp+411,(vlTOPp->io_uart_out_ch),8);
        tracep->fullBit(oldp+412,(vlTOPp->io_uart_in_valid));
        tracep->fullCData(oldp+413,(vlTOPp->io_uart_in_ch),8);
        tracep->fullBit(oldp+414,(vlTOPp->io_memAXI_0_aw_ready));
        tracep->fullBit(oldp+415,(vlTOPp->io_memAXI_0_aw_valid));
        tracep->fullQData(oldp+416,(vlTOPp->io_memAXI_0_aw_bits_addr),64);
        tracep->fullCData(oldp+418,(vlTOPp->io_memAXI_0_aw_bits_prot),3);
        tracep->fullCData(oldp+419,(vlTOPp->io_memAXI_0_aw_bits_id),4);
        tracep->fullBit(oldp+420,(vlTOPp->io_memAXI_0_aw_bits_user));
        tracep->fullCData(oldp+421,(vlTOPp->io_memAXI_0_aw_bits_len),8);
        tracep->fullCData(oldp+422,(vlTOPp->io_memAXI_0_aw_bits_size),3);
        tracep->fullCData(oldp+423,(vlTOPp->io_memAXI_0_aw_bits_burst),2);
        tracep->fullBit(oldp+424,(vlTOPp->io_memAXI_0_aw_bits_lock));
        tracep->fullCData(oldp+425,(vlTOPp->io_memAXI_0_aw_bits_cache),4);
        tracep->fullCData(oldp+426,(vlTOPp->io_memAXI_0_aw_bits_qos),4);
        tracep->fullBit(oldp+427,(vlTOPp->io_memAXI_0_w_ready));
        tracep->fullBit(oldp+428,(vlTOPp->io_memAXI_0_w_valid));
        tracep->fullQData(oldp+429,(vlTOPp->io_memAXI_0_w_bits_data[0]),64);
        tracep->fullQData(oldp+431,(vlTOPp->io_memAXI_0_w_bits_data[1]),64);
        tracep->fullQData(oldp+433,(vlTOPp->io_memAXI_0_w_bits_data[2]),64);
        tracep->fullQData(oldp+435,(vlTOPp->io_memAXI_0_w_bits_data[3]),64);
        tracep->fullCData(oldp+437,(vlTOPp->io_memAXI_0_w_bits_strb),8);
        tracep->fullBit(oldp+438,(vlTOPp->io_memAXI_0_w_bits_last));
        tracep->fullBit(oldp+439,(vlTOPp->io_memAXI_0_b_ready));
        tracep->fullBit(oldp+440,(vlTOPp->io_memAXI_0_b_valid));
        tracep->fullCData(oldp+441,(vlTOPp->io_memAXI_0_b_bits_resp),2);
        tracep->fullCData(oldp+442,(vlTOPp->io_memAXI_0_b_bits_id),4);
        tracep->fullBit(oldp+443,(vlTOPp->io_memAXI_0_b_bits_user));
        tracep->fullBit(oldp+444,(vlTOPp->io_memAXI_0_ar_ready));
        tracep->fullBit(oldp+445,(vlTOPp->io_memAXI_0_ar_valid));
        tracep->fullQData(oldp+446,(vlTOPp->io_memAXI_0_ar_bits_addr),64);
        tracep->fullCData(oldp+448,(vlTOPp->io_memAXI_0_ar_bits_prot),3);
        tracep->fullCData(oldp+449,(vlTOPp->io_memAXI_0_ar_bits_id),4);
        tracep->fullBit(oldp+450,(vlTOPp->io_memAXI_0_ar_bits_user));
        tracep->fullCData(oldp+451,(vlTOPp->io_memAXI_0_ar_bits_len),8);
        tracep->fullCData(oldp+452,(vlTOPp->io_memAXI_0_ar_bits_size),3);
        tracep->fullCData(oldp+453,(vlTOPp->io_memAXI_0_ar_bits_burst),2);
        tracep->fullBit(oldp+454,(vlTOPp->io_memAXI_0_ar_bits_lock));
        tracep->fullCData(oldp+455,(vlTOPp->io_memAXI_0_ar_bits_cache),4);
        tracep->fullCData(oldp+456,(vlTOPp->io_memAXI_0_ar_bits_qos),4);
        tracep->fullBit(oldp+457,(vlTOPp->io_memAXI_0_r_ready));
        tracep->fullBit(oldp+458,(vlTOPp->io_memAXI_0_r_valid));
        tracep->fullCData(oldp+459,(vlTOPp->io_memAXI_0_r_bits_resp),2);
        tracep->fullQData(oldp+460,(vlTOPp->io_memAXI_0_r_bits_data[0]),64);
        tracep->fullQData(oldp+462,(vlTOPp->io_memAXI_0_r_bits_data[1]),64);
        tracep->fullQData(oldp+464,(vlTOPp->io_memAXI_0_r_bits_data[2]),64);
        tracep->fullQData(oldp+466,(vlTOPp->io_memAXI_0_r_bits_data[3]),64);
        tracep->fullBit(oldp+468,(vlTOPp->io_memAXI_0_r_bits_last));
        tracep->fullCData(oldp+469,(vlTOPp->io_memAXI_0_r_bits_id),4);
        tracep->fullBit(oldp+470,(vlTOPp->io_memAXI_0_r_bits_user));
        tracep->fullQData(oldp+471,(vlTOPp->io_memAXI_0_r_bits_data
                                    [0U]),64);
        tracep->fullBit(oldp+473,(((IData)(vlTOPp->io_memAXI_0_ar_ready) 
                                   & (1U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_state)))));
        tracep->fullBit(oldp+474,(((IData)(vlTOPp->reset) 
                                   | (0U == (IData)(vlTOPp->SimTop__DOT__u_axi_rw__DOT__r_state)))));
        tracep->fullBit(oldp+475,((1U & (IData)(vlTOPp->io_memAXI_0_r_bits_resp))));
        __Vtemp38[0U] = 0xffffffffU;
        __Vtemp38[1U] = 0U;
        __Vtemp38[2U] = 0U;
        __Vtemp38[3U] = 0U;
        VL_EXTEND_WQ(65,64, __Vtemp39, vlTOPp->SimTop__DOT__if_addr);
        VL_SHIFTL_WWI(128,128,6, __Vtemp40, __Vtemp38, 
                      (0x38U & (__Vtemp39[0U] << 3U)));
        VL_EXTEND_WQ(65,64, __Vtemp41, vlTOPp->SimTop__DOT__if_addr);
        tracep->fullQData(oldp+476,(((vlTOPp->io_memAXI_0_r_bits_data
                                      [0U] & (((QData)((IData)(
                                                               __Vtemp40[3U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                __Vtemp40[2U])))) 
                                     << (0x3fU & (- 
                                                  (0x38U 
                                                   & (__Vtemp41[0U] 
                                                      << 3U)))))),64);
        tracep->fullBit(oldp+478,(((IData)(vlTOPp->reset)
                                    ? 0U : (1U & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_type) 
                                                  >> 4U)))));
        tracep->fullCData(oldp+479,(((IData)(vlTOPp->reset)
                                      ? 0U : ((0x10U 
                                               & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_type))
                                               ? (0x1fU 
                                                  & (vlTOPp->SimTop__DOT__u_cpu__DOT__inst 
                                                     >> 0xfU))
                                               : 0U))),5);
        tracep->fullQData(oldp+480,(((IData)(vlTOPp->reset)
                                      ? 0ULL : ((0x10U 
                                                 & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_type))
                                                 ? 
                                                ((IData)(vlTOPp->reset)
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
        tracep->fullQData(oldp+482,(((IData)(vlTOPp->reset)
                                      ? 0ULL : ((0x10U 
                                                 & (IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_type))
                                                 ? 
                                                ((0xfffffffffffff000ULL 
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
        tracep->fullQData(oldp+484,(((IData)(vlTOPp->reset)
                                      ? 0ULL : (((IData)(vlTOPp->reset)
                                                  ? 0U
                                                  : 
                                                 (1U 
                                                  & ((IData)(vlTOPp->SimTop__DOT__u_cpu__DOT__inst_type) 
                                                     >> 4U)))
                                                 ? 
                                                vlTOPp->SimTop__DOT__u_cpu__DOT__Regfile__DOT__regs
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
        tracep->fullBit(oldp+486,(vlTOPp->SimTop__DOT__aw_ready));
        tracep->fullBit(oldp+487,(vlTOPp->SimTop__DOT__aw_valid));
        tracep->fullQData(oldp+488,(vlTOPp->SimTop__DOT__aw_addr),64);
        tracep->fullCData(oldp+490,(vlTOPp->SimTop__DOT__aw_prot),3);
        tracep->fullCData(oldp+491,(vlTOPp->SimTop__DOT__aw_id),4);
        tracep->fullBit(oldp+492,(vlTOPp->SimTop__DOT__aw_user));
        tracep->fullCData(oldp+493,(vlTOPp->SimTop__DOT__aw_len),8);
        tracep->fullCData(oldp+494,(vlTOPp->SimTop__DOT__aw_size),3);
        tracep->fullCData(oldp+495,(vlTOPp->SimTop__DOT__aw_burst),2);
        tracep->fullBit(oldp+496,(vlTOPp->SimTop__DOT__aw_lock));
        tracep->fullCData(oldp+497,(vlTOPp->SimTop__DOT__aw_cache),4);
        tracep->fullCData(oldp+498,(vlTOPp->SimTop__DOT__aw_qos),4);
        tracep->fullCData(oldp+499,(vlTOPp->SimTop__DOT__aw_region),4);
        tracep->fullBit(oldp+500,(vlTOPp->SimTop__DOT__w_ready));
        tracep->fullBit(oldp+501,(vlTOPp->SimTop__DOT__w_valid));
        tracep->fullQData(oldp+502,(vlTOPp->SimTop__DOT__w_data),64);
        tracep->fullCData(oldp+504,(vlTOPp->SimTop__DOT__w_strb),8);
        tracep->fullBit(oldp+505,(vlTOPp->SimTop__DOT__w_last));
        tracep->fullBit(oldp+506,(vlTOPp->SimTop__DOT__w_user));
        tracep->fullBit(oldp+507,(vlTOPp->SimTop__DOT__b_ready));
        tracep->fullBit(oldp+508,(vlTOPp->SimTop__DOT__b_valid));
        tracep->fullCData(oldp+509,(vlTOPp->SimTop__DOT__b_resp),2);
        tracep->fullCData(oldp+510,(vlTOPp->SimTop__DOT__b_id),4);
        tracep->fullBit(oldp+511,(vlTOPp->SimTop__DOT__b_user));
        tracep->fullCData(oldp+512,(0U),3);
        tracep->fullCData(oldp+513,(0U),4);
        tracep->fullBit(oldp+514,(0U));
        tracep->fullCData(oldp+515,(3U),3);
        tracep->fullCData(oldp+516,(1U),2);
        tracep->fullBit(oldp+517,(0U));
        tracep->fullCData(oldp+518,(2U),4);
        tracep->fullCData(oldp+519,(vlTOPp->SimTop__DOT__ar_region),4);
        tracep->fullBit(oldp+520,(1U));
        tracep->fullQData(oldp+521,(vlTOPp->SimTop__DOT__data_write),64);
        tracep->fullCData(oldp+523,(2U),2);
        tracep->fullIData(oldp+524,(0x40U),32);
        tracep->fullIData(oldp+525,(4U),32);
        tracep->fullIData(oldp+526,(1U),32);
        VL_EXTEND_WQ(65,64, __Vtemp42, vlTOPp->SimTop__DOT__data_write);
        tracep->fullWData(oldp+527,(__Vtemp42),65);
        tracep->fullBit(oldp+530,(((IData)(vlTOPp->SimTop__DOT__aw_ready) 
                                   & (IData)(vlTOPp->SimTop__DOT__aw_valid))));
        tracep->fullBit(oldp+531,(((IData)(vlTOPp->SimTop__DOT__b_ready) 
                                   & (IData)(vlTOPp->SimTop__DOT__b_valid))));
        tracep->fullCData(oldp+532,(0U),2);
        tracep->fullCData(oldp+533,(3U),2);
        tracep->fullIData(oldp+534,(3U),32);
        tracep->fullIData(oldp+535,(6U),32);
        tracep->fullIData(oldp+536,(0x80U),32);
        tracep->fullCData(oldp+537,(3U),4);
        tracep->fullCData(oldp+538,(0U),5);
        tracep->fullQData(oldp+539,(0ULL),64);
        tracep->fullQData(oldp+541,(vlTOPp->SimTop__DOT__u_cpu__DOT__If_stage__DOT__addr),64);
        tracep->fullCData(oldp+543,(0U),8);
    }
}
