// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmaster_controller_tb.h for the primary calling header

#include "Vmaster_controller_tb__pch.h"

VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_initial__TOP(Vmaster_controller_tb___024root* vlSelf);
VlCoroutine Vmaster_controller_tb___024root___eval_initial__TOP__Vtiming__0(Vmaster_controller_tb___024root* vlSelf);
VlCoroutine Vmaster_controller_tb___024root___eval_initial__TOP__Vtiming__1(Vmaster_controller_tb___024root* vlSelf);

void Vmaster_controller_tb___024root___eval_initial(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_initial\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vmaster_controller_tb___024root___eval_initial__TOP(vlSelf);
    Vmaster_controller_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vmaster_controller_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vmaster_controller_tb___024root___eval_sample(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_sample\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmaster_controller_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vmaster_controller_tb___024root___eval_ico(Vmaster_controller_tb___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_ico\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmaster_controller_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vmaster_controller_tb___024root___timing_ready(Vmaster_controller_tb___024root* vlSelf);
void Vmaster_controller_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmaster_controller_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vmaster_controller_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vmaster_controller_tb___024root___timing_resume(Vmaster_controller_tb___024root* vlSelf);

bool Vmaster_controller_tb___024root___eval_act(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_act\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_done) 
                                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__master_controller_tb__DOT__dut__DOT__ctrl_done__0)) 
                                                           << 3U) 
                                                          | (vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                             << 2U)) 
                                                         | ((((~ (IData)(vlSelfRef.master_controller_tb__DOT__rst_n)) 
                                                              & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__master_controller_tb__DOT__rst_n__0)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.master_controller_tb__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__master_controller_tb__DOT__clk__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__master_controller_tb__DOT__clk__0 
            = vlSelfRef.master_controller_tb__DOT__clk;
        vlSelfRef.__Vtrigprevexpr___TOP__master_controller_tb__DOT__rst_n__0 
            = vlSelfRef.master_controller_tb__DOT__rst_n;
        vlSelfRef.__Vtrigprevexpr___TOP__master_controller_tb__DOT__dut__DOT__ctrl_done__0 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_done;
    }
    Vmaster_controller_tb___024root___timing_ready(vlSelf);
    Vmaster_controller_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmaster_controller_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vmaster_controller_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vmaster_controller_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vmaster_controller_tb___024root___timing_resume(vlSelf);
        {
            // Inlined CFunc: _eval_body__act
            if ((0x000000000000000dULL & vlSelfRef.__VactTriggered[0U])) {
                {
                    // Inlined CFunc: _act_comb__TOP__0
                    vlSelfRef.master_controller_tb__DOT__dut__DOT__safe_compute_start 
                        = ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__buf_compute_valid) 
                           & ((~ (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_busy)) 
                              & (IData)(vlSelfRef.master_controller_tb__DOT__compute_start)));
                }
            }
        }
    }
    return (__VactExecute);
}

bool Vmaster_controller_tb___024root___eval_inact(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_inact\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("master_controller\\master_controller_tb.v", 27, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vmaster_controller_tb___024root___nba_sequent__TOP__1(Vmaster_controller_tb___024root* vlSelf);
void Vmaster_controller_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vmaster_controller_tb___024root___eval_nba(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_nba\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vmaster_controller_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__0
                    vlSelfRef.__Vdly__master_controller_tb__DOT__dut__DOT__ctrl__DOT__state 
                        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__state;
                }
            }
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vmaster_controller_tb___024root___nba_sequent__TOP__1(vlSelf);
            }
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__2
                    if (vlSelfRef.master_controller_tb__DOT__rst_n) {
                        if ((2U & (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__state))) {
                            if ((1U & (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__state))) {
                                vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_done = 1U;
                                vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_busy = 0U;
                                vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__sys_reset = 0U;
                                vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__sys_enable = 0U;
                                vlSelfRef.__Vdly__master_controller_tb__DOT__dut__DOT__ctrl__DOT__state = 0U;
                            } else {
                                vlSelfRef.master_controller_tb__DOT__cycle_count 
                                    = ((IData)(1U) 
                                       + vlSelfRef.master_controller_tb__DOT__cycle_count);
                                if ((0x16U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__compute_counter))) {
                                    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__sys_enable = 0U;
                                    vlSelfRef.__Vdly__master_controller_tb__DOT__dut__DOT__ctrl__DOT__state = 3U;
                                } else {
                                    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__compute_counter 
                                        = (0x0000001fU 
                                           & ((IData)(1U) 
                                              + (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__compute_counter)));
                                }
                            }
                        } else if ((1U & (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__state))) {
                            vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__compute_counter = 0U;
                            vlSelfRef.master_controller_tb__DOT__cycle_count = 0U;
                            vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__sys_reset = 0U;
                            vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__sys_enable = 1U;
                            vlSelfRef.__Vdly__master_controller_tb__DOT__dut__DOT__ctrl__DOT__state = 2U;
                        } else {
                            vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_done = 0U;
                            vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__sys_reset = 0U;
                            vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__sys_enable = 0U;
                            if (vlSelfRef.master_controller_tb__DOT__dut__DOT__safe_compute_start) {
                                vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__compute_counter = 0U;
                                vlSelfRef.master_controller_tb__DOT__cycle_count = 0U;
                                vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_busy = 1U;
                                vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__sys_reset = 1U;
                                vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__sys_enable = 0U;
                                vlSelfRef.__Vdly__master_controller_tb__DOT__dut__DOT__ctrl__DOT__state = 1U;
                            }
                        }
                    } else {
                        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__compute_counter = 0U;
                        vlSelfRef.master_controller_tb__DOT__cycle_count = 0U;
                        vlSelfRef.__Vdly__master_controller_tb__DOT__dut__DOT__ctrl__DOT__state = 0U;
                        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__sys_reset = 1U;
                        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__sys_enable = 0U;
                        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_done = 0U;
                        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_busy = 0U;
                    }
                    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__state 
                        = vlSelfRef.__Vdly__master_controller_tb__DOT__dut__DOT__ctrl__DOT__state;
                }
            }
            if ((0x000000000000000fULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _act_comb__TOP__0
                    vlSelfRef.master_controller_tb__DOT__dut__DOT__safe_compute_start 
                        = ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__buf_compute_valid) 
                           & ((~ (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_busy)) 
                              & (IData)(vlSelfRef.master_controller_tb__DOT__compute_start)));
                }
            }
        }
        Vmaster_controller_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vmaster_controller_tb___024root___eval_obs(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_obs\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vmaster_controller_tb___024root___eval_react(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_react\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vmaster_controller_tb___024root___eval_postponed(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_postponed\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(Vmaster_controller_tb___024root* vlSelf, const char* __VeventDescription);
void Vmaster_controller_tb___024root____VbeforeTrig_hebaf5695__0(Vmaster_controller_tb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vmaster_controller_tb___024root___eval_initial__TOP__Vtiming__0(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ master_controller_tb__DOT__errors;
    master_controller_tb__DOT__errors = 0;
    IData/*31:0*/ master_controller_tb__DOT__unnamedblk1_1__DOT____Vrepeat0;
    master_controller_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ master_controller_tb__DOT__unnamedblk1_2__DOT____Vrepeat1;
    master_controller_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    VlWide<4>/*127:0*/ __Vtask_master_controller_tb__DOT__verify_results__3__tag;
    VL_ZERO_W(128, __Vtask_master_controller_tb__DOT__verify_results__3__tag);
    VlWide<4>/*127:0*/ __Vtask_master_controller_tb__DOT__verify_results__5__tag;
    VL_ZERO_W(128, __Vtask_master_controller_tb__DOT__verify_results__5__tag);
    // Body
    vlSymsp->_vm_contextp__->dumpfile("master_controller.vcd"s);
    VL_PRINTF_MT("-Info: master_controller\\master_controller_tb.v:333: $dumpvar ignored, as Verilated without --trace\n");
    master_controller_tb__DOT__errors = 0U;
    vlSelfRef.master_controller_tb__DOT__rst_n = 0U;
    vlSelfRef.master_controller_tb__DOT__wr_en = 0U;
    vlSelfRef.master_controller_tb__DOT__wr_addr = 0U;
    vlSelfRef.master_controller_tb__DOT__wr_data = 0U;
    vlSelfRef.master_controller_tb__DOT__load_done_in = 0U;
    vlSelfRef.master_controller_tb__DOT__compute_start = 0U;
    master_controller_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 = 3U;
    while (VL_LTS_III(32, 0U, master_controller_tb__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                    "@(posedge master_controller_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge master_controller_tb.clk)", 
                                                             "master_controller\\master_controller_tb.v", 
                                                             349);
        master_controller_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (master_controller_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         351);
    vlSelfRef.master_controller_tb__DOT__rst_n = 1U;
    Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                "@(posedge master_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge master_controller_tb.clk)", 
                                                         "master_controller\\master_controller_tb.v", 
                                                         354);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         355);
    VL_WRITEF_NX("\n=========================================\nIntegration Test: master_controller\n=========================================\n\n--- T9-INT: Reject compute without READY buffer ---\n",0);
    if (VL_UNLIKELY((vlSelfRef.master_controller_tb__DOT__dut__DOT__buf_compute_valid))) {
        VL_WRITEF_NX("FAIL T9-INT pre: compute_valid=%b expected 0\n",1
                     , '#',1,vlSelfRef.master_controller_tb__DOT__dut__DOT__buf_compute_valid);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                "@(posedge master_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge master_controller_tb.clk)", 
                                                         "master_controller\\master_controller_tb.v", 
                                                         379);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         380);
    vlSelfRef.master_controller_tb__DOT__compute_start = 1U;
    Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                "@(posedge master_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge master_controller_tb.clk)", 
                                                         "master_controller\\master_controller_tb.v", 
                                                         384);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         385);
    vlSelfRef.master_controller_tb__DOT__compute_start = 0U;
    master_controller_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 = 5U;
    while (VL_LTS_III(32, 0U, master_controller_tb__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
        Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                    "@(posedge master_controller_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge master_controller_tb.clk)", 
                                                             "master_controller\\master_controller_tb.v", 
                                                             389);
        master_controller_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 
            = (master_controller_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 
               - (IData)(1U));
    }
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         390);
    if (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_busy) {
        VL_WRITEF_NX("FAIL T9-INT: compute_busy=%b expected 0\n",1
                     , '#',1,vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_busy);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS T9-INT: controller did not start\n",0);
    }
    if (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_done) {
        VL_WRITEF_NX("FAIL T9-INT: unexpected compute_done\n",0);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS T9-INT: no compute_done pulse\n",0);
    }
    if (((0U != (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st)) 
         | (0U != (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st)))) {
        VL_WRITEF_NX("FAIL T9-INT: ping=%b pong=%b expected FREE/FREE\n",2
                     , '#',2,vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st
                     , '#',2,(IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st));
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS T9-INT: both buffers remain FREE\n",0);
    }
    VL_WRITEF_NX("\n--- Step 1: Load TILE-1 into PING ---\n",0);
    vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n = 0U;
    if (VL_UNLIKELY((vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel))) {
        VL_WRITEF_NX("FAIL Step1: load_buf_id=%b expected PING(0)\n",1
                     , '#',1,vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    while (VL_GTS_III(32, 0x00000080U, vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n)) {
        Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                    "@(posedge master_controller_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge master_controller_tb.clk)", 
                                                             "master_controller\\master_controller_tb.v", 
                                                             233);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "master_controller\\master_controller_tb.v", 
                                             234);
        vlSelfRef.master_controller_tb__DOT__wr_en = 1U;
        vlSelfRef.master_controller_tb__DOT__wr_addr 
            = (0x0000007fU & vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n);
        vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__idx 
            = (VL_GTS_III(32, 0x00000040U, vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n)
                ? vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n
                : (vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n 
                   - (IData)(0x00000040U)));
        vlSelfRef.master_controller_tb__DOT__wr_data 
            = (0x000000ffU & ((IData)(1U) + (VL_DIVS_III(32, vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__idx, (IData)(8U)) 
                                             + VL_MODDIVS_III(32, vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__idx, (IData)(8U)))));
        vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n);
    }
    Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                "@(posedge master_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge master_controller_tb.clk)", 
                                                         "master_controller\\master_controller_tb.v", 
                                                         253);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         254);
    vlSelfRef.master_controller_tb__DOT__wr_en = 0U;
    vlSelfRef.master_controller_tb__DOT__load_done_in = 1U;
    Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                "@(posedge master_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge master_controller_tb.clk)", 
                                                         "master_controller\\master_controller_tb.v", 
                                                         259);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         260);
    vlSelfRef.master_controller_tb__DOT__load_done_in = 0U;
    VL_WRITEF_NX("\n--- Step 2: Confirm PING READY ---\n",0);
    if ((2U != (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st))) {
        VL_WRITEF_NX("FAIL Step2: ping_state=%b expected READY\n",1
                     , '#',2,vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS Step2: PING READY\n",0);
    }
    if (vlSelfRef.master_controller_tb__DOT__dut__DOT__buf_compute_valid) {
        VL_WRITEF_NX("PASS Step2: compute_valid=1\n",0);
    } else {
        VL_WRITEF_NX("FAIL Step2: compute_valid=0\n",0);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    VL_WRITEF_NX("\n--- Step 3: Start PING compute ---\n",0);
    Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                "@(posedge master_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge master_controller_tb.clk)", 
                                                         "master_controller\\master_controller_tb.v", 
                                                         273);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         274);
    vlSelfRef.master_controller_tb__DOT__compute_start = 1U;
    Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                "@(posedge master_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge master_controller_tb.clk)", 
                                                         "master_controller\\master_controller_tb.v", 
                                                         278);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         279);
    vlSelfRef.master_controller_tb__DOT__compute_start = 0U;
    Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                "@(posedge master_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge master_controller_tb.clk)", 
                                                         "master_controller\\master_controller_tb.v", 
                                                         496);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         497);
    if ((3U != (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st))) {
        VL_WRITEF_NX("FAIL Step3: PING=%b expected COMPUTING\n",1
                     , '#',2,vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS Step3: PING COMPUTING\n",0);
    }
    if (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_busy) {
        VL_WRITEF_NX("PASS Step3: compute_busy=1\n",0);
    } else {
        VL_WRITEF_NX("FAIL Step3: compute_busy=0\n",0);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    VL_WRITEF_NX("\n--- Step 4: Load TILE-2 into PONG ---\n",0);
    if (vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel) {
        VL_WRITEF_NX("PASS Step4 pre: PONG selected for loading\n",0);
    } else {
        VL_WRITEF_NX("FAIL Step4: load_buf_id=%b expected PONG(1)\n",1
                     , '#',1,vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n = 0U;
    while (VL_GTS_III(32, 0x00000080U, vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n)) {
        Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                    "@(posedge master_controller_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge master_controller_tb.clk)", 
                                                             "master_controller\\master_controller_tb.v", 
                                                             233);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "master_controller\\master_controller_tb.v", 
                                             234);
        vlSelfRef.master_controller_tb__DOT__wr_en = 1U;
        vlSelfRef.master_controller_tb__DOT__wr_addr 
            = (0x0000007fU & vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n);
        vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__idx 
            = (VL_GTS_III(32, 0x00000040U, vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n)
                ? vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n
                : (vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n 
                   - (IData)(0x00000040U)));
        vlSelfRef.master_controller_tb__DOT__wr_data 
            = (0x000000ffU & ((IData)(1U) + (VL_DIVS_III(32, vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__idx, (IData)(8U)) 
                                             + VL_MODDIVS_III(32, vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__idx, (IData)(8U)))));
        vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n);
    }
    Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                "@(posedge master_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge master_controller_tb.clk)", 
                                                         "master_controller\\master_controller_tb.v", 
                                                         253);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         254);
    vlSelfRef.master_controller_tb__DOT__wr_en = 0U;
    vlSelfRef.master_controller_tb__DOT__load_done_in = 1U;
    Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                "@(posedge master_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge master_controller_tb.clk)", 
                                                         "master_controller\\master_controller_tb.v", 
                                                         259);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         260);
    vlSelfRef.master_controller_tb__DOT__load_done_in = 0U;
    VL_WRITEF_NX("\n--- Step 5: Confirm PONG READY ---\n",0);
    if ((2U != (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st))) {
        VL_WRITEF_NX("FAIL Step5: PONG=%b expected READY\n",1
                     , '#',2,vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS Step5: PONG READY\n",0);
    }
    if (VL_UNLIKELY(((3U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st))))) {
        VL_WRITEF_NX("INFO Step5: PING still COMPUTING\n",0);
    } else if ((0U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st))) {
        VL_WRITEF_NX("INFO Step5: PING already completed and is FREE\n",0);
    } else {
        VL_WRITEF_NX("FAIL Step5: unexpected PING state=%b\n",1
                     , '#',2,vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st);
    }
    VL_WRITEF_NX("\n--- Step 6: Confirm PING completion ---\n",0);
    if (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_busy) {
        while ((1U & (~ (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_done)))) {
            Vmaster_controller_tb___024root____VbeforeTrig_hebaf5695__0(vlSelf, 
                                                                        "@( master_controller_tb.dut.ctrl_done)");
            co_await vlSelfRef.__VtrigSched_hebaf5695__0.trigger(1U, 
                                                                 nullptr, 
                                                                 "@( master_controller_tb.dut.ctrl_done)", 
                                                                 "master_controller\\master_controller_tb.v", 
                                                                 591);
        }
        Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                    "@(posedge master_controller_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge master_controller_tb.clk)", 
                                                             "master_controller\\master_controller_tb.v", 
                                                             592);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "master_controller\\master_controller_tb.v", 
                                             593);
        VL_WRITEF_NX("PASS Step6: PING compute_done received\n",0);
    } else {
        VL_WRITEF_NX("PASS Step6: PING computation already completed\n",0);
    }
    VL_WRITEF_NX("\n--- Step 7: Verify PING results ---\ncycle_count=%0d\n",1
                 , '#',32,vlSelfRef.master_controller_tb__DOT__cycle_count);
    __Vtask_master_controller_tb__DOT__verify_results__3__tag[0U] = 0x50494e47U;
    __Vtask_master_controller_tb__DOT__verify_results__3__tag[1U] = 0U;
    __Vtask_master_controller_tb__DOT__verify_results__3__tag[2U] = 0U;
    __Vtask_master_controller_tb__DOT__verify_results__3__tag[3U] = 0U;
    vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors = 0U;
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][0U])))) {
        VL_WRITEF_NX("FAIL             PING C[0][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][1U])))) {
        VL_WRITEF_NX("FAIL             PING C[0][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][2U])))) {
        VL_WRITEF_NX("FAIL             PING C[0][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][3U])))) {
        VL_WRITEF_NX("FAIL             PING C[0][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][4U])))) {
        VL_WRITEF_NX("FAIL             PING C[0][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][5U])))) {
        VL_WRITEF_NX("FAIL             PING C[0][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][6U])))) {
        VL_WRITEF_NX("FAIL             PING C[0][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][7U])))) {
        VL_WRITEF_NX("FAIL             PING C[0][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][0U])))) {
        VL_WRITEF_NX("FAIL             PING C[1][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][1U])))) {
        VL_WRITEF_NX("FAIL             PING C[1][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][2U])))) {
        VL_WRITEF_NX("FAIL             PING C[1][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][3U])))) {
        VL_WRITEF_NX("FAIL             PING C[1][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][4U])))) {
        VL_WRITEF_NX("FAIL             PING C[1][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][5U])))) {
        VL_WRITEF_NX("FAIL             PING C[1][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][6U])))) {
        VL_WRITEF_NX("FAIL             PING C[1][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][7U])))) {
        VL_WRITEF_NX("FAIL             PING C[1][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][0U])))) {
        VL_WRITEF_NX("FAIL             PING C[2][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][1U])))) {
        VL_WRITEF_NX("FAIL             PING C[2][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][2U])))) {
        VL_WRITEF_NX("FAIL             PING C[2][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][3U])))) {
        VL_WRITEF_NX("FAIL             PING C[2][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][4U])))) {
        VL_WRITEF_NX("FAIL             PING C[2][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][5U])))) {
        VL_WRITEF_NX("FAIL             PING C[2][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][6U])))) {
        VL_WRITEF_NX("FAIL             PING C[2][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][7U])))) {
        VL_WRITEF_NX("FAIL             PING C[2][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][0U])))) {
        VL_WRITEF_NX("FAIL             PING C[3][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][1U])))) {
        VL_WRITEF_NX("FAIL             PING C[3][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][2U])))) {
        VL_WRITEF_NX("FAIL             PING C[3][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][3U])))) {
        VL_WRITEF_NX("FAIL             PING C[3][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][4U])))) {
        VL_WRITEF_NX("FAIL             PING C[3][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][5U])))) {
        VL_WRITEF_NX("FAIL             PING C[3][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][6U])))) {
        VL_WRITEF_NX("FAIL             PING C[3][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][7U])))) {
        VL_WRITEF_NX("FAIL             PING C[3][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][0U])))) {
        VL_WRITEF_NX("FAIL             PING C[4][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][1U])))) {
        VL_WRITEF_NX("FAIL             PING C[4][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][2U])))) {
        VL_WRITEF_NX("FAIL             PING C[4][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][3U])))) {
        VL_WRITEF_NX("FAIL             PING C[4][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][4U])))) {
        VL_WRITEF_NX("FAIL             PING C[4][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][5U])))) {
        VL_WRITEF_NX("FAIL             PING C[4][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][6U])))) {
        VL_WRITEF_NX("FAIL             PING C[4][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][7U])))) {
        VL_WRITEF_NX("FAIL             PING C[4][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][0U])))) {
        VL_WRITEF_NX("FAIL             PING C[5][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][1U])))) {
        VL_WRITEF_NX("FAIL             PING C[5][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][2U])))) {
        VL_WRITEF_NX("FAIL             PING C[5][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][3U])))) {
        VL_WRITEF_NX("FAIL             PING C[5][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][4U])))) {
        VL_WRITEF_NX("FAIL             PING C[5][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][5U])))) {
        VL_WRITEF_NX("FAIL             PING C[5][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][6U])))) {
        VL_WRITEF_NX("FAIL             PING C[5][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][7U])))) {
        VL_WRITEF_NX("FAIL             PING C[5][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][0U])))) {
        VL_WRITEF_NX("FAIL             PING C[6][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][1U])))) {
        VL_WRITEF_NX("FAIL             PING C[6][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][2U])))) {
        VL_WRITEF_NX("FAIL             PING C[6][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][3U])))) {
        VL_WRITEF_NX("FAIL             PING C[6][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][4U])))) {
        VL_WRITEF_NX("FAIL             PING C[6][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][5U])))) {
        VL_WRITEF_NX("FAIL             PING C[6][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][6U])))) {
        VL_WRITEF_NX("FAIL             PING C[6][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][7U])))) {
        VL_WRITEF_NX("FAIL             PING C[6][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][0U])))) {
        VL_WRITEF_NX("FAIL             PING C[7][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][1U])))) {
        VL_WRITEF_NX("FAIL             PING C[7][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][2U])))) {
        VL_WRITEF_NX("FAIL             PING C[7][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][3U])))) {
        VL_WRITEF_NX("FAIL             PING C[7][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][4U])))) {
        VL_WRITEF_NX("FAIL             PING C[7][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][5U])))) {
        VL_WRITEF_NX("FAIL             PING C[7][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][6U])))) {
        VL_WRITEF_NX("FAIL             PING C[7][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][7U])))) {
        VL_WRITEF_NX("FAIL             PING C[7][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((0U == vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors)))) {
        VL_WRITEF_NX("PASS %s: all 64 results correct\n",1
                     , '#',128,__Vtask_master_controller_tb__DOT__verify_results__3__tag.data());
    }
    VL_WRITEF_NX("\n--- Step 8: Start PONG compute ---\n",0);
    if (vlSelfRef.master_controller_tb__DOT__dut__DOT__buf_compute_valid) {
        VL_WRITEF_NX("PASS Step8 pre: READY buffer exists\n",0);
    } else {
        VL_WRITEF_NX("FAIL Step8: compute_valid=0 expected 1\n",0);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                "@(posedge master_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge master_controller_tb.clk)", 
                                                         "master_controller\\master_controller_tb.v", 
                                                         273);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         274);
    vlSelfRef.master_controller_tb__DOT__compute_start = 1U;
    Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                "@(posedge master_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge master_controller_tb.clk)", 
                                                         "master_controller\\master_controller_tb.v", 
                                                         278);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         279);
    vlSelfRef.master_controller_tb__DOT__compute_start = 0U;
    Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                "@(posedge master_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge master_controller_tb.clk)", 
                                                         "master_controller\\master_controller_tb.v", 
                                                         640);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         641);
    if ((3U != (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st))) {
        VL_WRITEF_NX("FAIL Step8: PONG=%b expected COMPUTING\n",1
                     , '#',2,vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS Step8: PONG COMPUTING\n",0);
    }
    VL_WRITEF_NX("\n--- Step 9: Wait for PONG compute_done ---\n",0);
    while ((1U & (~ (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_done)))) {
        Vmaster_controller_tb___024root____VbeforeTrig_hebaf5695__0(vlSelf, 
                                                                    "@( master_controller_tb.dut.ctrl_done)");
        co_await vlSelfRef.__VtrigSched_hebaf5695__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( master_controller_tb.dut.ctrl_done)", 
                                                             "master_controller\\master_controller_tb.v", 
                                                             664);
    }
    Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(vlSelf, 
                                                                "@(posedge master_controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h5d0549c5__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge master_controller_tb.clk)", 
                                                         "master_controller\\master_controller_tb.v", 
                                                         666);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "master_controller\\master_controller_tb.v", 
                                         667);
    VL_WRITEF_NX("PASS Step9: PONG compute_done received, cycle_count=%0d\n\n--- Step 10: Verify PONG results ---\n",1
                 , '#',32,vlSelfRef.master_controller_tb__DOT__cycle_count);
    __Vtask_master_controller_tb__DOT__verify_results__5__tag[0U] = 0x504f4e47U;
    __Vtask_master_controller_tb__DOT__verify_results__5__tag[1U] = 0U;
    __Vtask_master_controller_tb__DOT__verify_results__5__tag[2U] = 0U;
    __Vtask_master_controller_tb__DOT__verify_results__5__tag[3U] = 0U;
    vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors = 0U;
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][0U])))) {
        VL_WRITEF_NX("FAIL             PONG C[0][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][1U])))) {
        VL_WRITEF_NX("FAIL             PONG C[0][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][2U])))) {
        VL_WRITEF_NX("FAIL             PONG C[0][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][3U])))) {
        VL_WRITEF_NX("FAIL             PONG C[0][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][4U])))) {
        VL_WRITEF_NX("FAIL             PONG C[0][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][5U])))) {
        VL_WRITEF_NX("FAIL             PONG C[0][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][6U])))) {
        VL_WRITEF_NX("FAIL             PONG C[0][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[0U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[0U][7U])))) {
        VL_WRITEF_NX("FAIL             PONG C[0][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[0U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[0U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][0U])))) {
        VL_WRITEF_NX("FAIL             PONG C[1][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][1U])))) {
        VL_WRITEF_NX("FAIL             PONG C[1][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][2U])))) {
        VL_WRITEF_NX("FAIL             PONG C[1][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][3U])))) {
        VL_WRITEF_NX("FAIL             PONG C[1][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][4U])))) {
        VL_WRITEF_NX("FAIL             PONG C[1][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][5U])))) {
        VL_WRITEF_NX("FAIL             PONG C[1][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][6U])))) {
        VL_WRITEF_NX("FAIL             PONG C[1][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[1U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[1U][7U])))) {
        VL_WRITEF_NX("FAIL             PONG C[1][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[1U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[1U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][0U])))) {
        VL_WRITEF_NX("FAIL             PONG C[2][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][1U])))) {
        VL_WRITEF_NX("FAIL             PONG C[2][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][2U])))) {
        VL_WRITEF_NX("FAIL             PONG C[2][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][3U])))) {
        VL_WRITEF_NX("FAIL             PONG C[2][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][4U])))) {
        VL_WRITEF_NX("FAIL             PONG C[2][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][5U])))) {
        VL_WRITEF_NX("FAIL             PONG C[2][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][6U])))) {
        VL_WRITEF_NX("FAIL             PONG C[2][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[2U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[2U][7U])))) {
        VL_WRITEF_NX("FAIL             PONG C[2][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[2U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[2U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][0U])))) {
        VL_WRITEF_NX("FAIL             PONG C[3][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][1U])))) {
        VL_WRITEF_NX("FAIL             PONG C[3][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][2U])))) {
        VL_WRITEF_NX("FAIL             PONG C[3][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][3U])))) {
        VL_WRITEF_NX("FAIL             PONG C[3][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][4U])))) {
        VL_WRITEF_NX("FAIL             PONG C[3][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][5U])))) {
        VL_WRITEF_NX("FAIL             PONG C[3][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][6U])))) {
        VL_WRITEF_NX("FAIL             PONG C[3][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[3U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[3U][7U])))) {
        VL_WRITEF_NX("FAIL             PONG C[3][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[3U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[3U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][0U])))) {
        VL_WRITEF_NX("FAIL             PONG C[4][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][1U])))) {
        VL_WRITEF_NX("FAIL             PONG C[4][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][2U])))) {
        VL_WRITEF_NX("FAIL             PONG C[4][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][3U])))) {
        VL_WRITEF_NX("FAIL             PONG C[4][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][4U])))) {
        VL_WRITEF_NX("FAIL             PONG C[4][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][5U])))) {
        VL_WRITEF_NX("FAIL             PONG C[4][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][6U])))) {
        VL_WRITEF_NX("FAIL             PONG C[4][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[4U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[4U][7U])))) {
        VL_WRITEF_NX("FAIL             PONG C[4][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[4U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[4U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][0U])))) {
        VL_WRITEF_NX("FAIL             PONG C[5][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][1U])))) {
        VL_WRITEF_NX("FAIL             PONG C[5][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][2U])))) {
        VL_WRITEF_NX("FAIL             PONG C[5][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][3U])))) {
        VL_WRITEF_NX("FAIL             PONG C[5][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][4U])))) {
        VL_WRITEF_NX("FAIL             PONG C[5][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][5U])))) {
        VL_WRITEF_NX("FAIL             PONG C[5][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][6U])))) {
        VL_WRITEF_NX("FAIL             PONG C[5][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[5U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[5U][7U])))) {
        VL_WRITEF_NX("FAIL             PONG C[5][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[5U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[5U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][0U])))) {
        VL_WRITEF_NX("FAIL             PONG C[6][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][1U])))) {
        VL_WRITEF_NX("FAIL             PONG C[6][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][2U])))) {
        VL_WRITEF_NX("FAIL             PONG C[6][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][3U])))) {
        VL_WRITEF_NX("FAIL             PONG C[6][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][4U])))) {
        VL_WRITEF_NX("FAIL             PONG C[6][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][5U])))) {
        VL_WRITEF_NX("FAIL             PONG C[6][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][6U])))) {
        VL_WRITEF_NX("FAIL             PONG C[6][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[6U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[6U][7U])))) {
        VL_WRITEF_NX("FAIL             PONG C[6][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[6U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[6U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][0U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][0U])))) {
        VL_WRITEF_NX("FAIL             PONG C[7][0]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][0U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][0U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][1U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][1U])))) {
        VL_WRITEF_NX("FAIL             PONG C[7][1]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][1U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][1U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][2U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][2U])))) {
        VL_WRITEF_NX("FAIL             PONG C[7][2]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][2U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][2U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][3U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][3U])))) {
        VL_WRITEF_NX("FAIL             PONG C[7][3]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][3U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][3U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][4U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][4U])))) {
        VL_WRITEF_NX("FAIL             PONG C[7][4]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][4U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][4U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][5U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][5U])))) {
        VL_WRITEF_NX("FAIL             PONG C[7][5]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][5U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][5U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][6U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][6U])))) {
        VL_WRITEF_NX("FAIL             PONG C[7][6]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][6U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][6U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((vlSelfRef.master_controller_tb__DOT__C[7U][7U] 
                      != vlSelfRef.master_controller_tb__DOT__expected[7U][7U])))) {
        VL_WRITEF_NX("FAIL             PONG C[7][7]: got %0d expected %0d\n",2
                     , '#',32,vlSelfRef.master_controller_tb__DOT__C[7U][7U]
                     , '#',32,vlSelfRef.master_controller_tb__DOT__expected[7U][7U]);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors);
        master_controller_tb__DOT__errors = ((IData)(1U) 
                                             + master_controller_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((0U == vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors)))) {
        VL_WRITEF_NX("PASS %s: all 64 results correct\n",1
                     , '#',128,__Vtask_master_controller_tb__DOT__verify_results__5__tag.data());
    }
    VL_WRITEF_NX("\n=========================================\n",0);
    if ((0U == master_controller_tb__DOT__errors)) {
        VL_WRITEF_NX("ALL INTEGRATION TESTS PASSED\n",0);
    } else {
        VL_WRITEF_NX("%0d ERROR(S) DETECTED\n",1, '~',32,master_controller_tb__DOT__errors);
    }
    VL_WRITEF_NX("=========================================\n",0);
    VL_FINISH_MT("master_controller\\master_controller_tb.v", 695, "");
    co_return;
}

VlCoroutine Vmaster_controller_tb___024root___eval_initial__TOP__Vtiming__1(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "master_controller\\master_controller_tb.v", 
                                             124);
        vlSelfRef.master_controller_tb__DOT__clk = 
            (1U & (~ (IData)(vlSelfRef.master_controller_tb__DOT__clk)));
    }
    co_return;
}

bool Vmaster_controller_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

bool Vmaster_controller_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vmaster_controller_tb___024root___nba_sequent__TOP__1(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___nba_sequent__TOP__1\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<16>/*511:0*/ master_controller_tb__DOT__dut__DOT__A_buf;
    VL_ZERO_W(512, master_controller_tb__DOT__dut__DOT__A_buf);
    VlWide<16>/*511:0*/ master_controller_tb__DOT__dut__DOT__B_buf;
    VL_ZERO_W(512, master_controller_tb__DOT__dut__DOT__B_buf);
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle;
    __Vdly__master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C77;
    __Vdly__master_controller_tb__DOT__C77 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C76;
    __Vdly__master_controller_tb__DOT__C76 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C75;
    __Vdly__master_controller_tb__DOT__C75 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C74;
    __Vdly__master_controller_tb__DOT__C74 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C73;
    __Vdly__master_controller_tb__DOT__C73 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C72;
    __Vdly__master_controller_tb__DOT__C72 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C71;
    __Vdly__master_controller_tb__DOT__C71 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C70;
    __Vdly__master_controller_tb__DOT__C70 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C67;
    __Vdly__master_controller_tb__DOT__C67 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C66;
    __Vdly__master_controller_tb__DOT__C66 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C65;
    __Vdly__master_controller_tb__DOT__C65 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C64;
    __Vdly__master_controller_tb__DOT__C64 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C63;
    __Vdly__master_controller_tb__DOT__C63 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C62;
    __Vdly__master_controller_tb__DOT__C62 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C61;
    __Vdly__master_controller_tb__DOT__C61 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C60;
    __Vdly__master_controller_tb__DOT__C60 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C57;
    __Vdly__master_controller_tb__DOT__C57 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C56;
    __Vdly__master_controller_tb__DOT__C56 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C55;
    __Vdly__master_controller_tb__DOT__C55 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C54;
    __Vdly__master_controller_tb__DOT__C54 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C53;
    __Vdly__master_controller_tb__DOT__C53 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C52;
    __Vdly__master_controller_tb__DOT__C52 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C51;
    __Vdly__master_controller_tb__DOT__C51 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C50;
    __Vdly__master_controller_tb__DOT__C50 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C47;
    __Vdly__master_controller_tb__DOT__C47 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C46;
    __Vdly__master_controller_tb__DOT__C46 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C45;
    __Vdly__master_controller_tb__DOT__C45 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C44;
    __Vdly__master_controller_tb__DOT__C44 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C43;
    __Vdly__master_controller_tb__DOT__C43 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C42;
    __Vdly__master_controller_tb__DOT__C42 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C41;
    __Vdly__master_controller_tb__DOT__C41 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C40;
    __Vdly__master_controller_tb__DOT__C40 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C37;
    __Vdly__master_controller_tb__DOT__C37 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C36;
    __Vdly__master_controller_tb__DOT__C36 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C35;
    __Vdly__master_controller_tb__DOT__C35 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C34;
    __Vdly__master_controller_tb__DOT__C34 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C33;
    __Vdly__master_controller_tb__DOT__C33 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C32;
    __Vdly__master_controller_tb__DOT__C32 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C31;
    __Vdly__master_controller_tb__DOT__C31 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C30;
    __Vdly__master_controller_tb__DOT__C30 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C27;
    __Vdly__master_controller_tb__DOT__C27 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C26;
    __Vdly__master_controller_tb__DOT__C26 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C25;
    __Vdly__master_controller_tb__DOT__C25 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C24;
    __Vdly__master_controller_tb__DOT__C24 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C23;
    __Vdly__master_controller_tb__DOT__C23 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C22;
    __Vdly__master_controller_tb__DOT__C22 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C21;
    __Vdly__master_controller_tb__DOT__C21 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C20;
    __Vdly__master_controller_tb__DOT__C20 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C17;
    __Vdly__master_controller_tb__DOT__C17 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C16;
    __Vdly__master_controller_tb__DOT__C16 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C15;
    __Vdly__master_controller_tb__DOT__C15 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C14;
    __Vdly__master_controller_tb__DOT__C14 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C13;
    __Vdly__master_controller_tb__DOT__C13 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C12;
    __Vdly__master_controller_tb__DOT__C12 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C11;
    __Vdly__master_controller_tb__DOT__C11 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C10;
    __Vdly__master_controller_tb__DOT__C10 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C07;
    __Vdly__master_controller_tb__DOT__C07 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C06;
    __Vdly__master_controller_tb__DOT__C06 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C05;
    __Vdly__master_controller_tb__DOT__C05 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C04;
    __Vdly__master_controller_tb__DOT__C04 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C03;
    __Vdly__master_controller_tb__DOT__C03 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C02;
    __Vdly__master_controller_tb__DOT__C02 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C01;
    __Vdly__master_controller_tb__DOT__C01 = 0;
    IData/*31:0*/ __Vdly__master_controller_tb__DOT__C00;
    __Vdly__master_controller_tb__DOT__C00 = 0;
    CData/*0:0*/ __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_loaded_since_compute_done;
    __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_loaded_since_compute_done = 0;
    CData/*1:0*/ __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st;
    __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st = 0;
    CData/*1:0*/ __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st;
    __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st = 0;
    CData/*0:0*/ __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel;
    __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel = 0;
    CData/*7:0*/ __VdlyVal__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem__v0;
    __VdlyVal__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem__v0 = 0;
    CData/*6:0*/ __VdlyDim0__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem__v0;
    __VdlyDim0__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem__v0 = 0;
    CData/*0:0*/ __VdlySet__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem__v0;
    __VdlySet__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem__v0;
    __VdlyVal__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem__v0 = 0;
    CData/*6:0*/ __VdlyDim0__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem__v0;
    __VdlyDim0__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem__v0 = 0;
    CData/*0:0*/ __VdlySet__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem__v0;
    __VdlySet__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem__v0 = 0;
    // Body
    __Vdly__master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle;
    __Vdly__master_controller_tb__DOT__C77 = vlSelfRef.master_controller_tb__DOT__C77;
    __Vdly__master_controller_tb__DOT__C76 = vlSelfRef.master_controller_tb__DOT__C76;
    __Vdly__master_controller_tb__DOT__C75 = vlSelfRef.master_controller_tb__DOT__C75;
    __Vdly__master_controller_tb__DOT__C74 = vlSelfRef.master_controller_tb__DOT__C74;
    __Vdly__master_controller_tb__DOT__C73 = vlSelfRef.master_controller_tb__DOT__C73;
    __Vdly__master_controller_tb__DOT__C72 = vlSelfRef.master_controller_tb__DOT__C72;
    __Vdly__master_controller_tb__DOT__C71 = vlSelfRef.master_controller_tb__DOT__C71;
    __Vdly__master_controller_tb__DOT__C70 = vlSelfRef.master_controller_tb__DOT__C70;
    __Vdly__master_controller_tb__DOT__C67 = vlSelfRef.master_controller_tb__DOT__C67;
    __Vdly__master_controller_tb__DOT__C66 = vlSelfRef.master_controller_tb__DOT__C66;
    __Vdly__master_controller_tb__DOT__C65 = vlSelfRef.master_controller_tb__DOT__C65;
    __Vdly__master_controller_tb__DOT__C64 = vlSelfRef.master_controller_tb__DOT__C64;
    __Vdly__master_controller_tb__DOT__C63 = vlSelfRef.master_controller_tb__DOT__C63;
    __Vdly__master_controller_tb__DOT__C62 = vlSelfRef.master_controller_tb__DOT__C62;
    __Vdly__master_controller_tb__DOT__C61 = vlSelfRef.master_controller_tb__DOT__C61;
    __Vdly__master_controller_tb__DOT__C60 = vlSelfRef.master_controller_tb__DOT__C60;
    __Vdly__master_controller_tb__DOT__C57 = vlSelfRef.master_controller_tb__DOT__C57;
    __Vdly__master_controller_tb__DOT__C56 = vlSelfRef.master_controller_tb__DOT__C56;
    __Vdly__master_controller_tb__DOT__C55 = vlSelfRef.master_controller_tb__DOT__C55;
    __Vdly__master_controller_tb__DOT__C54 = vlSelfRef.master_controller_tb__DOT__C54;
    __Vdly__master_controller_tb__DOT__C53 = vlSelfRef.master_controller_tb__DOT__C53;
    __Vdly__master_controller_tb__DOT__C52 = vlSelfRef.master_controller_tb__DOT__C52;
    __Vdly__master_controller_tb__DOT__C51 = vlSelfRef.master_controller_tb__DOT__C51;
    __Vdly__master_controller_tb__DOT__C50 = vlSelfRef.master_controller_tb__DOT__C50;
    __Vdly__master_controller_tb__DOT__C47 = vlSelfRef.master_controller_tb__DOT__C47;
    __Vdly__master_controller_tb__DOT__C46 = vlSelfRef.master_controller_tb__DOT__C46;
    __Vdly__master_controller_tb__DOT__C45 = vlSelfRef.master_controller_tb__DOT__C45;
    __Vdly__master_controller_tb__DOT__C44 = vlSelfRef.master_controller_tb__DOT__C44;
    __Vdly__master_controller_tb__DOT__C43 = vlSelfRef.master_controller_tb__DOT__C43;
    __Vdly__master_controller_tb__DOT__C42 = vlSelfRef.master_controller_tb__DOT__C42;
    __Vdly__master_controller_tb__DOT__C41 = vlSelfRef.master_controller_tb__DOT__C41;
    __Vdly__master_controller_tb__DOT__C40 = vlSelfRef.master_controller_tb__DOT__C40;
    __Vdly__master_controller_tb__DOT__C37 = vlSelfRef.master_controller_tb__DOT__C37;
    __Vdly__master_controller_tb__DOT__C36 = vlSelfRef.master_controller_tb__DOT__C36;
    __Vdly__master_controller_tb__DOT__C35 = vlSelfRef.master_controller_tb__DOT__C35;
    __Vdly__master_controller_tb__DOT__C34 = vlSelfRef.master_controller_tb__DOT__C34;
    __Vdly__master_controller_tb__DOT__C33 = vlSelfRef.master_controller_tb__DOT__C33;
    __Vdly__master_controller_tb__DOT__C32 = vlSelfRef.master_controller_tb__DOT__C32;
    __Vdly__master_controller_tb__DOT__C31 = vlSelfRef.master_controller_tb__DOT__C31;
    __Vdly__master_controller_tb__DOT__C30 = vlSelfRef.master_controller_tb__DOT__C30;
    __Vdly__master_controller_tb__DOT__C27 = vlSelfRef.master_controller_tb__DOT__C27;
    __Vdly__master_controller_tb__DOT__C26 = vlSelfRef.master_controller_tb__DOT__C26;
    __Vdly__master_controller_tb__DOT__C25 = vlSelfRef.master_controller_tb__DOT__C25;
    __Vdly__master_controller_tb__DOT__C24 = vlSelfRef.master_controller_tb__DOT__C24;
    __Vdly__master_controller_tb__DOT__C23 = vlSelfRef.master_controller_tb__DOT__C23;
    __Vdly__master_controller_tb__DOT__C22 = vlSelfRef.master_controller_tb__DOT__C22;
    __Vdly__master_controller_tb__DOT__C21 = vlSelfRef.master_controller_tb__DOT__C21;
    __Vdly__master_controller_tb__DOT__C20 = vlSelfRef.master_controller_tb__DOT__C20;
    __Vdly__master_controller_tb__DOT__C17 = vlSelfRef.master_controller_tb__DOT__C17;
    __Vdly__master_controller_tb__DOT__C16 = vlSelfRef.master_controller_tb__DOT__C16;
    __Vdly__master_controller_tb__DOT__C15 = vlSelfRef.master_controller_tb__DOT__C15;
    __Vdly__master_controller_tb__DOT__C14 = vlSelfRef.master_controller_tb__DOT__C14;
    __Vdly__master_controller_tb__DOT__C13 = vlSelfRef.master_controller_tb__DOT__C13;
    __Vdly__master_controller_tb__DOT__C12 = vlSelfRef.master_controller_tb__DOT__C12;
    __Vdly__master_controller_tb__DOT__C11 = vlSelfRef.master_controller_tb__DOT__C11;
    __Vdly__master_controller_tb__DOT__C10 = vlSelfRef.master_controller_tb__DOT__C10;
    __Vdly__master_controller_tb__DOT__C07 = vlSelfRef.master_controller_tb__DOT__C07;
    __Vdly__master_controller_tb__DOT__C06 = vlSelfRef.master_controller_tb__DOT__C06;
    __Vdly__master_controller_tb__DOT__C05 = vlSelfRef.master_controller_tb__DOT__C05;
    __Vdly__master_controller_tb__DOT__C04 = vlSelfRef.master_controller_tb__DOT__C04;
    __Vdly__master_controller_tb__DOT__C03 = vlSelfRef.master_controller_tb__DOT__C03;
    __Vdly__master_controller_tb__DOT__C02 = vlSelfRef.master_controller_tb__DOT__C02;
    __Vdly__master_controller_tb__DOT__C01 = vlSelfRef.master_controller_tb__DOT__C01;
    __Vdly__master_controller_tb__DOT__C00 = vlSelfRef.master_controller_tb__DOT__C00;
    __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_loaded_since_compute_done 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_loaded_since_compute_done;
    __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel;
    __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st;
    __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st;
    __VdlySet__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem__v0 = 0U;
    __VdlySet__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem__v0 = 0U;
    if (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__sys_reset) {
        __Vdly__master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle = 0U;
        __Vdly__master_controller_tb__DOT__C77 = 0U;
        __Vdly__master_controller_tb__DOT__C76 = 0U;
        __Vdly__master_controller_tb__DOT__C75 = 0U;
        __Vdly__master_controller_tb__DOT__C74 = 0U;
        __Vdly__master_controller_tb__DOT__C73 = 0U;
        __Vdly__master_controller_tb__DOT__C72 = 0U;
        __Vdly__master_controller_tb__DOT__C71 = 0U;
        __Vdly__master_controller_tb__DOT__C70 = 0U;
        __Vdly__master_controller_tb__DOT__C67 = 0U;
        __Vdly__master_controller_tb__DOT__C66 = 0U;
        __Vdly__master_controller_tb__DOT__C65 = 0U;
        __Vdly__master_controller_tb__DOT__C64 = 0U;
        __Vdly__master_controller_tb__DOT__C63 = 0U;
        __Vdly__master_controller_tb__DOT__C62 = 0U;
        __Vdly__master_controller_tb__DOT__C61 = 0U;
        __Vdly__master_controller_tb__DOT__C60 = 0U;
        __Vdly__master_controller_tb__DOT__C57 = 0U;
        __Vdly__master_controller_tb__DOT__C56 = 0U;
        __Vdly__master_controller_tb__DOT__C55 = 0U;
        __Vdly__master_controller_tb__DOT__C54 = 0U;
        __Vdly__master_controller_tb__DOT__C53 = 0U;
        __Vdly__master_controller_tb__DOT__C52 = 0U;
        __Vdly__master_controller_tb__DOT__C51 = 0U;
        __Vdly__master_controller_tb__DOT__C50 = 0U;
        __Vdly__master_controller_tb__DOT__C47 = 0U;
        __Vdly__master_controller_tb__DOT__C46 = 0U;
        __Vdly__master_controller_tb__DOT__C45 = 0U;
        __Vdly__master_controller_tb__DOT__C44 = 0U;
        __Vdly__master_controller_tb__DOT__C43 = 0U;
        __Vdly__master_controller_tb__DOT__C42 = 0U;
        __Vdly__master_controller_tb__DOT__C41 = 0U;
        __Vdly__master_controller_tb__DOT__C40 = 0U;
        __Vdly__master_controller_tb__DOT__C37 = 0U;
        __Vdly__master_controller_tb__DOT__C36 = 0U;
        __Vdly__master_controller_tb__DOT__C35 = 0U;
        __Vdly__master_controller_tb__DOT__C34 = 0U;
        __Vdly__master_controller_tb__DOT__C33 = 0U;
        __Vdly__master_controller_tb__DOT__C32 = 0U;
        __Vdly__master_controller_tb__DOT__C31 = 0U;
        __Vdly__master_controller_tb__DOT__C30 = 0U;
        __Vdly__master_controller_tb__DOT__C27 = 0U;
        __Vdly__master_controller_tb__DOT__C26 = 0U;
        __Vdly__master_controller_tb__DOT__C25 = 0U;
        __Vdly__master_controller_tb__DOT__C24 = 0U;
        __Vdly__master_controller_tb__DOT__C23 = 0U;
        __Vdly__master_controller_tb__DOT__C22 = 0U;
        __Vdly__master_controller_tb__DOT__C21 = 0U;
        __Vdly__master_controller_tb__DOT__C20 = 0U;
        __Vdly__master_controller_tb__DOT__C17 = 0U;
        __Vdly__master_controller_tb__DOT__C16 = 0U;
        __Vdly__master_controller_tb__DOT__C15 = 0U;
        __Vdly__master_controller_tb__DOT__C14 = 0U;
        __Vdly__master_controller_tb__DOT__C13 = 0U;
        __Vdly__master_controller_tb__DOT__C12 = 0U;
        __Vdly__master_controller_tb__DOT__C11 = 0U;
        __Vdly__master_controller_tb__DOT__C10 = 0U;
        __Vdly__master_controller_tb__DOT__C07 = 0U;
        __Vdly__master_controller_tb__DOT__C06 = 0U;
        __Vdly__master_controller_tb__DOT__C05 = 0U;
        __Vdly__master_controller_tb__DOT__C04 = 0U;
        __Vdly__master_controller_tb__DOT__C03 = 0U;
        __Vdly__master_controller_tb__DOT__C02 = 0U;
        __Vdly__master_controller_tb__DOT__C01 = 0U;
        __Vdly__master_controller_tb__DOT__C00 = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe77__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe77__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe76__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe76__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe75__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe75__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe74__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe74__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe73__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe73__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe72__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe72__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe71__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe71__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe70__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe70__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe67__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe67__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe66__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe66__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe65__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe65__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe64__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe64__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe63__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe63__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe62__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe62__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe61__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe61__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe60__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe60__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe57__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe57__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe56__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe56__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe55__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe55__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe54__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe54__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe53__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe53__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe52__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe52__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe51__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe51__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe50__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe50__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe47__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe47__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe46__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe46__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe45__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe45__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe44__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe44__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe43__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe43__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe42__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe42__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe41__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe41__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe40__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe40__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe37__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe37__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe36__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe36__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe35__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe35__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe34__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe34__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe33__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe33__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe32__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe32__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe31__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe31__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe30__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe30__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe27__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe27__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe26__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe26__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe25__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe25__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe24__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe24__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe23__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe23__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe22__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe22__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe21__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe21__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe20__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe20__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe17__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe17__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe16__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe16__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe15__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe15__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe14__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe14__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe13__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe13__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe12__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe12__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe11__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe11__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe10__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe10__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe07__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe07__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe06__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe06__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe05__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe05__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe04__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe04__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe03__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe03__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe02__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe02__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe01__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe01__B_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe00__A_out = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe00__B_out = 0U;
    } else if (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__sys_enable) {
        __Vdly__master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
            = ((IData)(1U) + vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle);
        __Vdly__master_controller_tb__DOT__C77 = (vlSelfRef.master_controller_tb__DOT__C77 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][7U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][7U])));
        __Vdly__master_controller_tb__DOT__C76 = (vlSelfRef.master_controller_tb__DOT__C76 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][6U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][6U])));
        __Vdly__master_controller_tb__DOT__C75 = (vlSelfRef.master_controller_tb__DOT__C75 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][5U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][5U])));
        __Vdly__master_controller_tb__DOT__C74 = (vlSelfRef.master_controller_tb__DOT__C74 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][4U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][4U])));
        __Vdly__master_controller_tb__DOT__C73 = (vlSelfRef.master_controller_tb__DOT__C73 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][3U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][3U])));
        __Vdly__master_controller_tb__DOT__C72 = (vlSelfRef.master_controller_tb__DOT__C72 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][2U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][2U])));
        __Vdly__master_controller_tb__DOT__C71 = (vlSelfRef.master_controller_tb__DOT__C71 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][1U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][1U])));
        __Vdly__master_controller_tb__DOT__C70 = (vlSelfRef.master_controller_tb__DOT__C70 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][0U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][0U])));
        __Vdly__master_controller_tb__DOT__C67 = (vlSelfRef.master_controller_tb__DOT__C67 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][7U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][7U])));
        __Vdly__master_controller_tb__DOT__C66 = (vlSelfRef.master_controller_tb__DOT__C66 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][6U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][6U])));
        __Vdly__master_controller_tb__DOT__C65 = (vlSelfRef.master_controller_tb__DOT__C65 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][5U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][5U])));
        __Vdly__master_controller_tb__DOT__C64 = (vlSelfRef.master_controller_tb__DOT__C64 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][4U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][4U])));
        __Vdly__master_controller_tb__DOT__C63 = (vlSelfRef.master_controller_tb__DOT__C63 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][3U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][3U])));
        __Vdly__master_controller_tb__DOT__C62 = (vlSelfRef.master_controller_tb__DOT__C62 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][2U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][2U])));
        __Vdly__master_controller_tb__DOT__C61 = (vlSelfRef.master_controller_tb__DOT__C61 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][1U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][1U])));
        __Vdly__master_controller_tb__DOT__C60 = (vlSelfRef.master_controller_tb__DOT__C60 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][0U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][0U])));
        __Vdly__master_controller_tb__DOT__C57 = (vlSelfRef.master_controller_tb__DOT__C57 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][7U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][7U])));
        __Vdly__master_controller_tb__DOT__C56 = (vlSelfRef.master_controller_tb__DOT__C56 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][6U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][6U])));
        __Vdly__master_controller_tb__DOT__C55 = (vlSelfRef.master_controller_tb__DOT__C55 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][5U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][5U])));
        __Vdly__master_controller_tb__DOT__C54 = (vlSelfRef.master_controller_tb__DOT__C54 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][4U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][4U])));
        __Vdly__master_controller_tb__DOT__C53 = (vlSelfRef.master_controller_tb__DOT__C53 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][3U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][3U])));
        __Vdly__master_controller_tb__DOT__C52 = (vlSelfRef.master_controller_tb__DOT__C52 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][2U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][2U])));
        __Vdly__master_controller_tb__DOT__C51 = (vlSelfRef.master_controller_tb__DOT__C51 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][1U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][1U])));
        __Vdly__master_controller_tb__DOT__C50 = (vlSelfRef.master_controller_tb__DOT__C50 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][0U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][0U])));
        __Vdly__master_controller_tb__DOT__C47 = (vlSelfRef.master_controller_tb__DOT__C47 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][7U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][7U])));
        __Vdly__master_controller_tb__DOT__C46 = (vlSelfRef.master_controller_tb__DOT__C46 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][6U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][6U])));
        __Vdly__master_controller_tb__DOT__C45 = (vlSelfRef.master_controller_tb__DOT__C45 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][5U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][5U])));
        __Vdly__master_controller_tb__DOT__C44 = (vlSelfRef.master_controller_tb__DOT__C44 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][4U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][4U])));
        __Vdly__master_controller_tb__DOT__C43 = (vlSelfRef.master_controller_tb__DOT__C43 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][3U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][3U])));
        __Vdly__master_controller_tb__DOT__C42 = (vlSelfRef.master_controller_tb__DOT__C42 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][2U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][2U])));
        __Vdly__master_controller_tb__DOT__C41 = (vlSelfRef.master_controller_tb__DOT__C41 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][1U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][1U])));
        __Vdly__master_controller_tb__DOT__C40 = (vlSelfRef.master_controller_tb__DOT__C40 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][0U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][0U])));
        __Vdly__master_controller_tb__DOT__C37 = (vlSelfRef.master_controller_tb__DOT__C37 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][7U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][7U])));
        __Vdly__master_controller_tb__DOT__C36 = (vlSelfRef.master_controller_tb__DOT__C36 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][6U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][6U])));
        __Vdly__master_controller_tb__DOT__C35 = (vlSelfRef.master_controller_tb__DOT__C35 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][5U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][5U])));
        __Vdly__master_controller_tb__DOT__C34 = (vlSelfRef.master_controller_tb__DOT__C34 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][4U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][4U])));
        __Vdly__master_controller_tb__DOT__C33 = (vlSelfRef.master_controller_tb__DOT__C33 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][3U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][3U])));
        __Vdly__master_controller_tb__DOT__C32 = (vlSelfRef.master_controller_tb__DOT__C32 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][2U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][2U])));
        __Vdly__master_controller_tb__DOT__C31 = (vlSelfRef.master_controller_tb__DOT__C31 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][1U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][1U])));
        __Vdly__master_controller_tb__DOT__C30 = (vlSelfRef.master_controller_tb__DOT__C30 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][0U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][0U])));
        __Vdly__master_controller_tb__DOT__C27 = (vlSelfRef.master_controller_tb__DOT__C27 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][7U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][7U])));
        __Vdly__master_controller_tb__DOT__C26 = (vlSelfRef.master_controller_tb__DOT__C26 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][6U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][6U])));
        __Vdly__master_controller_tb__DOT__C25 = (vlSelfRef.master_controller_tb__DOT__C25 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][5U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][5U])));
        __Vdly__master_controller_tb__DOT__C24 = (vlSelfRef.master_controller_tb__DOT__C24 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][4U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][4U])));
        __Vdly__master_controller_tb__DOT__C23 = (vlSelfRef.master_controller_tb__DOT__C23 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][3U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][3U])));
        __Vdly__master_controller_tb__DOT__C22 = (vlSelfRef.master_controller_tb__DOT__C22 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][2U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][2U])));
        __Vdly__master_controller_tb__DOT__C21 = (vlSelfRef.master_controller_tb__DOT__C21 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][1U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][1U])));
        __Vdly__master_controller_tb__DOT__C20 = (vlSelfRef.master_controller_tb__DOT__C20 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][0U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][0U])));
        __Vdly__master_controller_tb__DOT__C17 = (vlSelfRef.master_controller_tb__DOT__C17 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][7U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][7U])));
        __Vdly__master_controller_tb__DOT__C16 = (vlSelfRef.master_controller_tb__DOT__C16 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][6U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][6U])));
        __Vdly__master_controller_tb__DOT__C15 = (vlSelfRef.master_controller_tb__DOT__C15 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][5U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][5U])));
        __Vdly__master_controller_tb__DOT__C14 = (vlSelfRef.master_controller_tb__DOT__C14 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][4U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][4U])));
        __Vdly__master_controller_tb__DOT__C13 = (vlSelfRef.master_controller_tb__DOT__C13 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][3U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][3U])));
        __Vdly__master_controller_tb__DOT__C12 = (vlSelfRef.master_controller_tb__DOT__C12 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][2U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][2U])));
        __Vdly__master_controller_tb__DOT__C11 = (vlSelfRef.master_controller_tb__DOT__C11 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][1U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][1U])));
        __Vdly__master_controller_tb__DOT__C10 = (vlSelfRef.master_controller_tb__DOT__C10 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][0U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][0U])));
        __Vdly__master_controller_tb__DOT__C07 = (vlSelfRef.master_controller_tb__DOT__C07 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][7U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][7U])));
        __Vdly__master_controller_tb__DOT__C06 = (vlSelfRef.master_controller_tb__DOT__C06 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][6U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][6U])));
        __Vdly__master_controller_tb__DOT__C05 = (vlSelfRef.master_controller_tb__DOT__C05 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][5U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][5U])));
        __Vdly__master_controller_tb__DOT__C04 = (vlSelfRef.master_controller_tb__DOT__C04 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][4U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][4U])));
        __Vdly__master_controller_tb__DOT__C03 = (vlSelfRef.master_controller_tb__DOT__C03 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][3U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][3U])));
        __Vdly__master_controller_tb__DOT__C02 = (vlSelfRef.master_controller_tb__DOT__C02 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][2U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][2U])));
        __Vdly__master_controller_tb__DOT__C01 = (vlSelfRef.master_controller_tb__DOT__C01 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][1U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][1U])));
        __Vdly__master_controller_tb__DOT__C00 = (vlSelfRef.master_controller_tb__DOT__C00 
                                                  + 
                                                  (0x0000ffffU 
                                                   & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][0U] 
                                                      * vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][0U])));
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe77__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe77__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe76__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe76__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe75__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe75__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe74__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe74__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe73__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe73__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe72__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe72__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe71__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe71__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe70__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][0U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe70__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][0U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe67__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe67__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe66__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe66__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe65__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe65__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe64__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe64__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe63__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe63__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe62__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe62__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe61__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe61__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe60__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][0U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe60__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][0U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe57__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe57__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe56__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe56__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe55__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe55__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe54__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe54__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe53__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe53__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe52__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe52__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe51__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe51__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe50__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][0U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe50__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][0U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe47__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe47__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe46__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe46__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe45__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe45__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe44__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe44__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe43__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe43__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe42__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe42__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe41__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe41__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe40__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][0U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe40__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][0U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe37__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe37__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe36__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe36__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe35__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe35__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe34__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe34__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe33__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe33__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe32__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe32__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe31__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe31__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe30__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][0U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe30__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][0U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe27__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe27__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe26__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe26__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe25__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe25__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe24__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe24__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe23__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe23__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe22__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe22__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe21__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe21__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe20__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][0U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe20__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][0U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe17__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe17__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe16__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe16__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe15__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe15__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe14__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe14__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe13__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe13__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe12__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe12__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe11__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe11__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe10__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][0U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe10__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][0U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe07__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe07__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][7U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe06__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe06__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][6U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe05__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe05__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][5U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe04__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe04__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][4U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe03__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe03__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][3U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe02__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe02__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][2U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe01__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe01__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][1U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe00__A_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][0U];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe00__B_out 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][0U];
    }
    if (vlSelfRef.master_controller_tb__DOT__rst_n) {
        if (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_done) {
            __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_loaded_since_compute_done = 0U;
        } else if (((IData)(vlSelfRef.master_controller_tb__DOT__load_done_in) 
                    & (~ (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel)))) {
            __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_loaded_since_compute_done = 1U;
        }
        if ((2U & (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st))) {
            if ((1U & (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st))) {
                if (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_done) {
                    __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st = 0U;
                }
            } else if ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__safe_compute_start) 
                         & (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__buf_compute_valid)) 
                        & (~ (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel_next)))) {
                __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st = 3U;
            }
        } else if ((1U & (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st))) {
            if (vlSelfRef.master_controller_tb__DOT__load_done_in) {
                __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st = 2U;
            }
        } else if (((~ (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel)) 
                    & (IData)(vlSelfRef.master_controller_tb__DOT__wr_en))) {
            __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st = 1U;
        }
        if ((2U & (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st))) {
            if ((1U & (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st))) {
                if (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_done) {
                    __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st = 0U;
                }
            } else if ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__safe_compute_start) 
                         & (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__buf_compute_valid)) 
                        & (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel_next))) {
                __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st = 3U;
            }
        } else if ((1U & (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st))) {
            if (vlSelfRef.master_controller_tb__DOT__load_done_in) {
                __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st = 2U;
            }
        } else if (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel) 
                    & (IData)(vlSelfRef.master_controller_tb__DOT__wr_en))) {
            __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st = 1U;
        }
        if (vlSelfRef.master_controller_tb__DOT__load_done_in) {
            if (vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel) {
                if ((0U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st))) {
                    __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel = 0U;
                }
            } else if ((0U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st))) {
                __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel = 1U;
            }
        } else if (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__safe_compute_start) 
                    & (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__buf_compute_valid))) {
            if (vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel_next) {
                if ((0U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st))) {
                    __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel = 0U;
                }
            } else if ((0U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st))) {
                __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel = 1U;
            }
        } else if (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_done) {
            if (vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel) {
                if ((((~ (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel)) 
                      & (0U != (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st))) 
                     & (1U != (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st)))) {
                    __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel = 1U;
                }
            } else if ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_loaded_since_compute_done) 
                         & (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel)) 
                        & (0U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st)))) {
                __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel = 0U;
            } else if ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel) 
                         & (0U != (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st))) 
                        & (1U != (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st)))) {
                __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel = 0U;
            }
        }
        if (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__safe_compute_start) 
             & (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__buf_compute_valid))) {
            vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel 
                = vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel_next;
        }
    } else {
        __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st = 0U;
        __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st = 0U;
        __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel = 0U;
        __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_loaded_since_compute_done = 0U;
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel = 0U;
    }
    if (((IData)(vlSelfRef.master_controller_tb__DOT__wr_en) 
         & ((~ (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel)) 
            & ((0U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st)) 
               | (1U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st)))))) {
        __VdlyVal__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem__v0 
            = vlSelfRef.master_controller_tb__DOT__wr_data;
        __VdlyDim0__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem__v0 
            = vlSelfRef.master_controller_tb__DOT__wr_addr;
        __VdlySet__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.master_controller_tb__DOT__wr_en) 
         & ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel) 
            & ((0U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st)) 
               | (1U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st)))))) {
        __VdlyVal__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem__v0 
            = vlSelfRef.master_controller_tb__DOT__wr_data;
        __VdlyDim0__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem__v0 
            = vlSelfRef.master_controller_tb__DOT__wr_addr;
        __VdlySet__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem__v0 = 1U;
    }
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
        = __Vdly__master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle;
    vlSelfRef.master_controller_tb__DOT__C77 = __Vdly__master_controller_tb__DOT__C77;
    vlSelfRef.master_controller_tb__DOT__C76 = __Vdly__master_controller_tb__DOT__C76;
    vlSelfRef.master_controller_tb__DOT__C75 = __Vdly__master_controller_tb__DOT__C75;
    vlSelfRef.master_controller_tb__DOT__C74 = __Vdly__master_controller_tb__DOT__C74;
    vlSelfRef.master_controller_tb__DOT__C73 = __Vdly__master_controller_tb__DOT__C73;
    vlSelfRef.master_controller_tb__DOT__C72 = __Vdly__master_controller_tb__DOT__C72;
    vlSelfRef.master_controller_tb__DOT__C71 = __Vdly__master_controller_tb__DOT__C71;
    vlSelfRef.master_controller_tb__DOT__C70 = __Vdly__master_controller_tb__DOT__C70;
    vlSelfRef.master_controller_tb__DOT__C67 = __Vdly__master_controller_tb__DOT__C67;
    vlSelfRef.master_controller_tb__DOT__C66 = __Vdly__master_controller_tb__DOT__C66;
    vlSelfRef.master_controller_tb__DOT__C65 = __Vdly__master_controller_tb__DOT__C65;
    vlSelfRef.master_controller_tb__DOT__C64 = __Vdly__master_controller_tb__DOT__C64;
    vlSelfRef.master_controller_tb__DOT__C63 = __Vdly__master_controller_tb__DOT__C63;
    vlSelfRef.master_controller_tb__DOT__C62 = __Vdly__master_controller_tb__DOT__C62;
    vlSelfRef.master_controller_tb__DOT__C61 = __Vdly__master_controller_tb__DOT__C61;
    vlSelfRef.master_controller_tb__DOT__C60 = __Vdly__master_controller_tb__DOT__C60;
    vlSelfRef.master_controller_tb__DOT__C57 = __Vdly__master_controller_tb__DOT__C57;
    vlSelfRef.master_controller_tb__DOT__C56 = __Vdly__master_controller_tb__DOT__C56;
    vlSelfRef.master_controller_tb__DOT__C55 = __Vdly__master_controller_tb__DOT__C55;
    vlSelfRef.master_controller_tb__DOT__C54 = __Vdly__master_controller_tb__DOT__C54;
    vlSelfRef.master_controller_tb__DOT__C53 = __Vdly__master_controller_tb__DOT__C53;
    vlSelfRef.master_controller_tb__DOT__C52 = __Vdly__master_controller_tb__DOT__C52;
    vlSelfRef.master_controller_tb__DOT__C51 = __Vdly__master_controller_tb__DOT__C51;
    vlSelfRef.master_controller_tb__DOT__C50 = __Vdly__master_controller_tb__DOT__C50;
    vlSelfRef.master_controller_tb__DOT__C47 = __Vdly__master_controller_tb__DOT__C47;
    vlSelfRef.master_controller_tb__DOT__C46 = __Vdly__master_controller_tb__DOT__C46;
    vlSelfRef.master_controller_tb__DOT__C45 = __Vdly__master_controller_tb__DOT__C45;
    vlSelfRef.master_controller_tb__DOT__C44 = __Vdly__master_controller_tb__DOT__C44;
    vlSelfRef.master_controller_tb__DOT__C43 = __Vdly__master_controller_tb__DOT__C43;
    vlSelfRef.master_controller_tb__DOT__C42 = __Vdly__master_controller_tb__DOT__C42;
    vlSelfRef.master_controller_tb__DOT__C41 = __Vdly__master_controller_tb__DOT__C41;
    vlSelfRef.master_controller_tb__DOT__C40 = __Vdly__master_controller_tb__DOT__C40;
    vlSelfRef.master_controller_tb__DOT__C37 = __Vdly__master_controller_tb__DOT__C37;
    vlSelfRef.master_controller_tb__DOT__C36 = __Vdly__master_controller_tb__DOT__C36;
    vlSelfRef.master_controller_tb__DOT__C35 = __Vdly__master_controller_tb__DOT__C35;
    vlSelfRef.master_controller_tb__DOT__C34 = __Vdly__master_controller_tb__DOT__C34;
    vlSelfRef.master_controller_tb__DOT__C33 = __Vdly__master_controller_tb__DOT__C33;
    vlSelfRef.master_controller_tb__DOT__C32 = __Vdly__master_controller_tb__DOT__C32;
    vlSelfRef.master_controller_tb__DOT__C31 = __Vdly__master_controller_tb__DOT__C31;
    vlSelfRef.master_controller_tb__DOT__C30 = __Vdly__master_controller_tb__DOT__C30;
    vlSelfRef.master_controller_tb__DOT__C27 = __Vdly__master_controller_tb__DOT__C27;
    vlSelfRef.master_controller_tb__DOT__C26 = __Vdly__master_controller_tb__DOT__C26;
    vlSelfRef.master_controller_tb__DOT__C25 = __Vdly__master_controller_tb__DOT__C25;
    vlSelfRef.master_controller_tb__DOT__C24 = __Vdly__master_controller_tb__DOT__C24;
    vlSelfRef.master_controller_tb__DOT__C23 = __Vdly__master_controller_tb__DOT__C23;
    vlSelfRef.master_controller_tb__DOT__C22 = __Vdly__master_controller_tb__DOT__C22;
    vlSelfRef.master_controller_tb__DOT__C21 = __Vdly__master_controller_tb__DOT__C21;
    vlSelfRef.master_controller_tb__DOT__C20 = __Vdly__master_controller_tb__DOT__C20;
    vlSelfRef.master_controller_tb__DOT__C17 = __Vdly__master_controller_tb__DOT__C17;
    vlSelfRef.master_controller_tb__DOT__C16 = __Vdly__master_controller_tb__DOT__C16;
    vlSelfRef.master_controller_tb__DOT__C15 = __Vdly__master_controller_tb__DOT__C15;
    vlSelfRef.master_controller_tb__DOT__C14 = __Vdly__master_controller_tb__DOT__C14;
    vlSelfRef.master_controller_tb__DOT__C13 = __Vdly__master_controller_tb__DOT__C13;
    vlSelfRef.master_controller_tb__DOT__C12 = __Vdly__master_controller_tb__DOT__C12;
    vlSelfRef.master_controller_tb__DOT__C11 = __Vdly__master_controller_tb__DOT__C11;
    vlSelfRef.master_controller_tb__DOT__C10 = __Vdly__master_controller_tb__DOT__C10;
    vlSelfRef.master_controller_tb__DOT__C07 = __Vdly__master_controller_tb__DOT__C07;
    vlSelfRef.master_controller_tb__DOT__C06 = __Vdly__master_controller_tb__DOT__C06;
    vlSelfRef.master_controller_tb__DOT__C05 = __Vdly__master_controller_tb__DOT__C05;
    vlSelfRef.master_controller_tb__DOT__C04 = __Vdly__master_controller_tb__DOT__C04;
    vlSelfRef.master_controller_tb__DOT__C03 = __Vdly__master_controller_tb__DOT__C03;
    vlSelfRef.master_controller_tb__DOT__C02 = __Vdly__master_controller_tb__DOT__C02;
    vlSelfRef.master_controller_tb__DOT__C01 = __Vdly__master_controller_tb__DOT__C01;
    vlSelfRef.master_controller_tb__DOT__C00 = __Vdly__master_controller_tb__DOT__C00;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_loaded_since_compute_done 
        = __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_loaded_since_compute_done;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st 
        = __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st;
    if (__VdlySet__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem__v0) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[__VdlyDim0__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem__v0] 
            = __VdlyVal__master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem__v0;
    }
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel 
        = __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st 
        = __Vdly__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st;
    if (__VdlySet__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem__v0) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[__VdlyDim0__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem__v0] 
            = __VdlyVal__master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem__v0;
    }
    vlSelfRef.master_controller_tb__DOT__C[7U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C77;
    vlSelfRef.master_controller_tb__DOT__C[7U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C76;
    vlSelfRef.master_controller_tb__DOT__C[7U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C75;
    vlSelfRef.master_controller_tb__DOT__C[7U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C74;
    vlSelfRef.master_controller_tb__DOT__C[7U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C73;
    vlSelfRef.master_controller_tb__DOT__C[7U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C72;
    vlSelfRef.master_controller_tb__DOT__C[7U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C71;
    vlSelfRef.master_controller_tb__DOT__C[7U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C70;
    vlSelfRef.master_controller_tb__DOT__C[6U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C67;
    vlSelfRef.master_controller_tb__DOT__C[6U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C66;
    vlSelfRef.master_controller_tb__DOT__C[6U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C65;
    vlSelfRef.master_controller_tb__DOT__C[6U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C64;
    vlSelfRef.master_controller_tb__DOT__C[6U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C63;
    vlSelfRef.master_controller_tb__DOT__C[6U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C62;
    vlSelfRef.master_controller_tb__DOT__C[6U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C61;
    vlSelfRef.master_controller_tb__DOT__C[6U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C60;
    vlSelfRef.master_controller_tb__DOT__C[5U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C57;
    vlSelfRef.master_controller_tb__DOT__C[5U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C56;
    vlSelfRef.master_controller_tb__DOT__C[5U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C55;
    vlSelfRef.master_controller_tb__DOT__C[5U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C54;
    vlSelfRef.master_controller_tb__DOT__C[5U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C53;
    vlSelfRef.master_controller_tb__DOT__C[5U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C52;
    vlSelfRef.master_controller_tb__DOT__C[5U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C51;
    vlSelfRef.master_controller_tb__DOT__C[5U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C50;
    vlSelfRef.master_controller_tb__DOT__C[4U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C47;
    vlSelfRef.master_controller_tb__DOT__C[4U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C46;
    vlSelfRef.master_controller_tb__DOT__C[4U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C45;
    vlSelfRef.master_controller_tb__DOT__C[4U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C44;
    vlSelfRef.master_controller_tb__DOT__C[4U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C43;
    vlSelfRef.master_controller_tb__DOT__C[4U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C42;
    vlSelfRef.master_controller_tb__DOT__C[4U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C41;
    vlSelfRef.master_controller_tb__DOT__C[4U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C40;
    vlSelfRef.master_controller_tb__DOT__C[3U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C37;
    vlSelfRef.master_controller_tb__DOT__C[3U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C36;
    vlSelfRef.master_controller_tb__DOT__C[3U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C35;
    vlSelfRef.master_controller_tb__DOT__C[3U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C34;
    vlSelfRef.master_controller_tb__DOT__C[3U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C33;
    vlSelfRef.master_controller_tb__DOT__C[3U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C32;
    vlSelfRef.master_controller_tb__DOT__C[3U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C31;
    vlSelfRef.master_controller_tb__DOT__C[3U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C30;
    vlSelfRef.master_controller_tb__DOT__C[2U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C27;
    vlSelfRef.master_controller_tb__DOT__C[2U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C26;
    vlSelfRef.master_controller_tb__DOT__C[2U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C25;
    vlSelfRef.master_controller_tb__DOT__C[2U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C24;
    vlSelfRef.master_controller_tb__DOT__C[2U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C23;
    vlSelfRef.master_controller_tb__DOT__C[2U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C22;
    vlSelfRef.master_controller_tb__DOT__C[2U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C21;
    vlSelfRef.master_controller_tb__DOT__C[2U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C20;
    vlSelfRef.master_controller_tb__DOT__C[1U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C17;
    vlSelfRef.master_controller_tb__DOT__C[1U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C16;
    vlSelfRef.master_controller_tb__DOT__C[1U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C15;
    vlSelfRef.master_controller_tb__DOT__C[1U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C14;
    vlSelfRef.master_controller_tb__DOT__C[1U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C13;
    vlSelfRef.master_controller_tb__DOT__C[1U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C12;
    vlSelfRef.master_controller_tb__DOT__C[1U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C11;
    vlSelfRef.master_controller_tb__DOT__C[1U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C10;
    vlSelfRef.master_controller_tb__DOT__C[0U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C07;
    vlSelfRef.master_controller_tb__DOT__C[0U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C06;
    vlSelfRef.master_controller_tb__DOT__C[0U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C05;
    vlSelfRef.master_controller_tb__DOT__C[0U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C04;
    vlSelfRef.master_controller_tb__DOT__C[0U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C03;
    vlSelfRef.master_controller_tb__DOT__C[0U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C02;
    vlSelfRef.master_controller_tb__DOT__C[0U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C01;
    vlSelfRef.master_controller_tb__DOT__C[0U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C00;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe77__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe77__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe76__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe76__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe75__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe75__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe74__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe74__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe73__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe73__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe72__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe72__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe71__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe71__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe70__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe70__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe67__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe67__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe66__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe66__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe65__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe65__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe64__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe64__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe63__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe63__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe62__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe62__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe61__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe61__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe60__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe60__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe57__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe57__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe56__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe56__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe55__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe55__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe54__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe54__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe53__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe53__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe52__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe52__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe51__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe51__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe50__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe50__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe47__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe47__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe46__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe46__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe45__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe45__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe44__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe44__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe43__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe43__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe42__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe42__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe41__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe41__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe40__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe40__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe37__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe37__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe36__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe36__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe35__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe35__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe34__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe34__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe33__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe33__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe32__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe32__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe31__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe31__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe30__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe30__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe27__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe27__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe26__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe26__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe25__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe25__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe24__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe24__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe23__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe23__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe22__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe22__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe21__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe21__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe20__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe20__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe17__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe17__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe16__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe16__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe15__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe15__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe14__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe14__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe13__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe13__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe12__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe12__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe11__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe11__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe10__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe10__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe07__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe07__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe06__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe06__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe05__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe05__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe04__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe04__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe03__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe03__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe02__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe02__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe01__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe01__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe00__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe00__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__buf_compute_valid 
        = ((2U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st)) 
           | (2U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st)));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel_next 
        = ((2U != (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st)) 
           & ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel) 
              | (2U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st))));
    master_controller_tb__DOT__dut__DOT__A_buf[0U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[3U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[3U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[2U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[2U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[1U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[1U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[0U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[0U])));
    master_controller_tb__DOT__dut__DOT__A_buf[1U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[7U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[7U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[6U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[6U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[5U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[5U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[4U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[4U])));
    master_controller_tb__DOT__dut__DOT__A_buf[2U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[11U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[11U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[10U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[10U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[9U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[9U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[8U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[8U])));
    master_controller_tb__DOT__dut__DOT__A_buf[3U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[15U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[15U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[14U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[14U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[13U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[13U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[12U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[12U])));
    master_controller_tb__DOT__dut__DOT__A_buf[4U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[19U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[19U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[18U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[18U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[17U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[17U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[16U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[16U])));
    master_controller_tb__DOT__dut__DOT__A_buf[5U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[23U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[23U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[22U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[22U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[21U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[21U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[20U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[20U])));
    master_controller_tb__DOT__dut__DOT__A_buf[6U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[27U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[27U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[26U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[26U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[25U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[25U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[24U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[24U])));
    master_controller_tb__DOT__dut__DOT__A_buf[7U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[31U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[31U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[30U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[30U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[29U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[29U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[28U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[28U])));
    master_controller_tb__DOT__dut__DOT__A_buf[8U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[35U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[35U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[34U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[34U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[33U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[33U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[32U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[32U])));
    master_controller_tb__DOT__dut__DOT__A_buf[9U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[39U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[39U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[38U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[38U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[37U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[37U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[36U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[36U])));
    master_controller_tb__DOT__dut__DOT__A_buf[10U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[43U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[43U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[42U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[42U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[41U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[41U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[40U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[40U])));
    master_controller_tb__DOT__dut__DOT__A_buf[11U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[47U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[47U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[46U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[46U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[45U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[45U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[44U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[44U])));
    master_controller_tb__DOT__dut__DOT__A_buf[12U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[51U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[51U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[50U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[50U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[49U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[49U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[48U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[48U])));
    master_controller_tb__DOT__dut__DOT__A_buf[13U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[55U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[55U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[54U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[54U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[53U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[53U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[52U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[52U])));
    master_controller_tb__DOT__dut__DOT__A_buf[14U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[59U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[59U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[58U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[58U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[57U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[57U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[56U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[56U])));
    master_controller_tb__DOT__dut__DOT__A_buf[15U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[63U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[63U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[62U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[62U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[61U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[61U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[60U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[60U])));
    master_controller_tb__DOT__dut__DOT__B_buf[0U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[67U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[67U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[66U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[66U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[65U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[65U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[64U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[64U])));
    master_controller_tb__DOT__dut__DOT__B_buf[1U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[71U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[71U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[70U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[70U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[69U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[69U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[68U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[68U])));
    master_controller_tb__DOT__dut__DOT__B_buf[2U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[75U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[75U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[74U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[74U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[73U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[73U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[72U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[72U])));
    master_controller_tb__DOT__dut__DOT__B_buf[3U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[79U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[79U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[78U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[78U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[77U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[77U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[76U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[76U])));
    master_controller_tb__DOT__dut__DOT__B_buf[4U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[83U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[83U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[82U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[82U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[81U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[81U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[80U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[80U])));
    master_controller_tb__DOT__dut__DOT__B_buf[5U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[87U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[87U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[86U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[86U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[85U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[85U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[84U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[84U])));
    master_controller_tb__DOT__dut__DOT__B_buf[6U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[91U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[91U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[90U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[90U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[89U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[89U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[88U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[88U])));
    master_controller_tb__DOT__dut__DOT__B_buf[7U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[95U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[95U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[94U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[94U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[93U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[93U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[92U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[92U])));
    master_controller_tb__DOT__dut__DOT__B_buf[8U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[99U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[99U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[98U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[98U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[97U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[97U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[96U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[96U])));
    master_controller_tb__DOT__dut__DOT__B_buf[9U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[103U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[103U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[102U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[102U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[101U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[101U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[100U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[100U])));
    master_controller_tb__DOT__dut__DOT__B_buf[10U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[107U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[107U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[106U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[106U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[105U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[105U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[104U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[104U])));
    master_controller_tb__DOT__dut__DOT__B_buf[11U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[111U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[111U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[110U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[110U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[109U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[109U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[108U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[108U])));
    master_controller_tb__DOT__dut__DOT__B_buf[12U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[115U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[115U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[114U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[114U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[113U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[113U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[112U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[112U])));
    master_controller_tb__DOT__dut__DOT__B_buf[13U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[119U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[119U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[118U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[118U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[117U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[117U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[116U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[116U])));
    master_controller_tb__DOT__dut__DOT__B_buf[14U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[123U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[123U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[122U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[122U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[121U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[121U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[120U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[120U])));
    master_controller_tb__DOT__dut__DOT__B_buf[15U] 
        = (((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[127U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[127U]) 
             << 0x00000018U) | (((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                                  ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[126U]
                                  : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[126U]) 
                                << 0x00000010U)) | 
           ((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
               ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[125U]
               : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[125U]) 
             << 8U) | ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel)
                        ? vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[124U]
                        : vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[124U])));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[0U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[0U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[0U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[0U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[0U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[0U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[0U][3U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[0U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[0U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[1U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[0U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[1U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[0U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[1U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[0U][7U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[1U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[1U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[2U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[1U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[2U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[1U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[2U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[1U][3U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[2U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[1U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[3U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[1U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[3U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[1U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[3U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[1U][7U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[3U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[2U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[4U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[2U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[4U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[2U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[4U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[2U][3U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[4U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[2U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[5U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[2U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[5U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[2U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[5U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[2U][7U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[5U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[3U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[6U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[3U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[6U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[3U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[6U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[3U][3U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[6U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[3U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[7U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[3U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[7U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[3U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[7U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[3U][7U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[7U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[4U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[8U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[4U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[8U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[4U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[8U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[4U][3U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[8U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[4U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[9U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[4U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[9U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[4U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[9U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[4U][7U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[9U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[5U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[10U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[5U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[10U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[5U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[10U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[5U][3U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[10U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[5U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[11U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[5U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[11U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[5U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[11U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[5U][7U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[11U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[6U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[12U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[6U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[12U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[6U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[12U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[6U][3U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[12U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[6U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[13U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[6U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[13U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[6U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[13U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[6U][7U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[13U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[7U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[14U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[7U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[14U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[7U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[14U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[7U][3U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[14U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[7U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__A_buf[15U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[7U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[15U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[7U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__A_buf[15U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[7U][7U] 
        = (master_controller_tb__DOT__dut__DOT__A_buf[15U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[0U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[0U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[0U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[0U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[0U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[0U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[0U][3U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[0U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[0U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[1U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[0U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[1U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[0U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[1U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[0U][7U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[1U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[1U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[2U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[1U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[2U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[1U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[2U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[1U][3U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[2U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[1U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[3U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[1U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[3U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[1U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[3U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[1U][7U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[3U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[2U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[4U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[2U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[4U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[2U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[4U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[2U][3U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[4U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[2U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[5U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[2U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[5U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[2U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[5U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[2U][7U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[5U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[3U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[6U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[3U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[6U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[3U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[6U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[3U][3U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[6U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[3U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[7U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[3U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[7U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[3U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[7U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[3U][7U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[7U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[4U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[8U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[4U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[8U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[4U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[8U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[4U][3U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[8U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[4U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[9U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[4U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[9U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[4U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[9U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[4U][7U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[9U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[5U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[10U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[5U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[10U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[5U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[10U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[5U][3U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[10U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[5U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[11U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[5U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[11U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[5U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[11U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[5U][7U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[11U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[6U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[12U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[6U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[12U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[6U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[12U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[6U][3U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[12U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[6U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[13U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[6U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[13U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[6U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[13U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[6U][7U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[13U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[7U][0U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[14U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[7U][1U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[14U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[7U][2U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[14U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[7U][3U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[14U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[7U][4U] 
        = (0x000000ffU & master_controller_tb__DOT__dut__DOT__B_buf[15U]);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[7U][5U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[15U] 
                          >> 8U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[7U][6U] 
        = (0x000000ffU & (master_controller_tb__DOT__dut__DOT__B_buf[15U] 
                          >> 0x00000010U));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[7U][7U] 
        = (master_controller_tb__DOT__dut__DOT__B_buf[15U] 
           >> 0x00000018U);
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[0U] = 0U;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[1U] = 0U;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[2U] = 0U;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[3U] = 0U;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[4U] = 0U;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[5U] = 0U;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[6U] = 0U;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[7U] = 0U;
    if ((VL_LTES_III(32, 0U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 8U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle))) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[0U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[0U]
            [(7U & vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle)];
    }
    if ((VL_LTES_III(32, 1U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 9U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle))) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[1U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[1U]
            [(7U & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
                    - (IData)(1U)))];
    }
    if ((VL_LTES_III(32, 2U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000aU, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle))) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[2U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[2U]
            [(7U & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
                    - (IData)(2U)))];
    }
    if ((VL_LTES_III(32, 3U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000bU, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle))) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[3U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[3U]
            [(7U & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
                    - (IData)(3U)))];
    }
    if ((VL_LTES_III(32, 4U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000cU, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle))) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[4U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[4U]
            [(7U & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
                    - (IData)(4U)))];
    }
    if ((VL_LTES_III(32, 5U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000dU, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle))) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[5U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[5U]
            [(7U & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
                    - (IData)(5U)))];
    }
    if ((VL_LTES_III(32, 6U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000eU, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle))) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[6U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[6U]
            [(7U & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
                    - (IData)(6U)))];
    }
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[0U] = 0U;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[1U] = 0U;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[2U] = 0U;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[3U] = 0U;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[4U] = 0U;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[5U] = 0U;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[6U] = 0U;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[7U] = 0U;
    if ((VL_LTES_III(32, 0U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 8U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle))) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[0U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix
            [(7U & vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle)][0U];
    }
    if ((VL_LTES_III(32, 1U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 9U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle))) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[1U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix
            [(7U & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
                    - (IData)(1U)))][1U];
    }
    if ((VL_LTES_III(32, 2U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000aU, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle))) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[2U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix
            [(7U & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
                    - (IData)(2U)))][2U];
    }
    if ((VL_LTES_III(32, 3U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000bU, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle))) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[3U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix
            [(7U & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
                    - (IData)(3U)))][3U];
    }
    if ((VL_LTES_III(32, 4U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000cU, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle))) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[4U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix
            [(7U & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
                    - (IData)(4U)))][4U];
    }
    if ((VL_LTES_III(32, 5U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000dU, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle))) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[5U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix
            [(7U & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
                    - (IData)(5U)))][5U];
    }
    if ((VL_LTES_III(32, 6U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000eU, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle))) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[6U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix
            [(7U & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
                    - (IData)(6U)))][6U];
    }
    if ((VL_LTES_III(32, 7U, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000fU, vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle))) {
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[7U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[7U]
            [(7U & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
                    - (IData)(7U)))];
        vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[7U] 
            = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix
            [(7U & (vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle 
                    - (IData)(7U)))][7U];
    }
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[0U];
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[1U];
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[2U];
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[3U];
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[4U];
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[5U];
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[6U];
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[7U];
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[0U];
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[1U];
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[2U];
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[3U];
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[4U];
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[5U];
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[6U];
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[0U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[7U];
}

void Vmaster_controller_tb___024root___timing_ready(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___timing_ready\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready("@(posedge master_controller_tb.clk)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hebaf5695__0.ready("@( master_controller_tb.dut.ctrl_done)");
    }
}

void Vmaster_controller_tb___024root___timing_resume(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___timing_resume\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h5d0549c5__0.moveToResumeQueue(
                                                          "@(posedge master_controller_tb.clk)");
    vlSelfRef.__VtrigSched_hebaf5695__0.moveToResumeQueue(
                                                          "@( master_controller_tb.dut.ctrl_done)");
    vlSelfRef.__VtrigSched_h5d0549c5__0.resume("@(posedge master_controller_tb.clk)");
    vlSelfRef.__VtrigSched_hebaf5695__0.resume("@( master_controller_tb.dut.ctrl_done)");
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vmaster_controller_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vmaster_controller_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0(Vmaster_controller_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root____VbeforeTrig_h5d0549c5__0\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((IData)(vlSelfRef.master_controller_tb__DOT__clk) 
                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__master_controller_tb__DOT__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__master_controller_tb__DOT__clk__0 
        = vlSelfRef.master_controller_tb__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h5d0549c5__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vmaster_controller_tb___024root____VbeforeTrig_hebaf5695__0(Vmaster_controller_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root____VbeforeTrig_hebaf5695__0\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)((((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_done) 
                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__master_controller_tb__DOT__dut__DOT__ctrl_done__0)) 
                                  << 3U)));
    vlSelfRef.__Vtrigprevexpr___TOP__master_controller_tb__DOT__dut__DOT__ctrl_done__0 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_done;
    if ((8ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_hebaf5695__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hebaf5695__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vmaster_controller_tb___024root___eval_debug_assertions(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_debug_assertions\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
