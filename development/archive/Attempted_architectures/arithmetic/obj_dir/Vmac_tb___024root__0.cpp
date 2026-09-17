// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmac_tb.h for the primary calling header

#include "Vmac_tb__pch.h"

VlCoroutine Vmac_tb___024root___eval_initial__TOP__Vtiming__0(Vmac_tb___024root* vlSelf);
VlCoroutine Vmac_tb___024root___eval_initial__TOP__Vtiming__1(Vmac_tb___024root* vlSelf);

void Vmac_tb___024root___eval_initial(Vmac_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___eval_initial\n"); );
    Vmac_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vmac_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vmac_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vmac_tb___024root___eval_sample(Vmac_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___eval_sample\n"); );
    Vmac_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmac_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vmac_tb___024root___eval_ico(Vmac_tb___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___eval_ico\n"); );
    Vmac_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmac_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vmac_tb___024root___timing_ready(Vmac_tb___024root* vlSelf);
void Vmac_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmac_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vmac_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vmac_tb___024root___timing_resume(Vmac_tb___024root* vlSelf);

bool Vmac_tb___024root___eval_act(Vmac_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___eval_act\n"); );
    Vmac_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                          << 1U) 
                                                         | ((IData)(vlSelfRef.mac_tb__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mac_tb__DOT__clk__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__mac_tb__DOT__clk__0 
            = vlSelfRef.mac_tb__DOT__clk;
    }
    Vmac_tb___024root___timing_ready(vlSelf);
    Vmac_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmac_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vmac_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vmac_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vmac_tb___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vmac_tb___024root___eval_inact(Vmac_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___eval_inact\n"); );
    Vmac_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("mac_tb.v", 3, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vmac_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vmac_tb___024root___eval_nba(Vmac_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___eval_nba\n"); );
    Vmac_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vmac_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__0
                    IData/*31:0*/ __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__mac_tb__DOT__acc_out;
                    __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__mac_tb__DOT__acc_out = 0;
                    __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__mac_tb__DOT__acc_out 
                        = vlSelfRef.mac_tb__DOT__acc_out;
                    if (vlSelfRef.mac_tb__DOT__reset) {
                        __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__mac_tb__DOT__acc_out = 0U;
                    } else if (vlSelfRef.mac_tb__DOT__enable) {
                        __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__mac_tb__DOT__acc_out 
                            = (vlSelfRef.mac_tb__DOT__acc_out 
                               + (0x0000ffffU & ((IData)(vlSelfRef.mac_tb__DOT__B) 
                                                 * (IData)(vlSelfRef.mac_tb__DOT__A))));
                    }
                    vlSelfRef.mac_tb__DOT__acc_out 
                        = __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__mac_tb__DOT__acc_out;
                }
            }
        }
        Vmac_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vmac_tb___024root___eval_obs(Vmac_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___eval_obs\n"); );
    Vmac_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vmac_tb___024root___eval_react(Vmac_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___eval_react\n"); );
    Vmac_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vmac_tb___024root___eval_postponed(Vmac_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___eval_postponed\n"); );
    Vmac_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vmac_tb___024root____VbeforeTrig_hf844d8d6__0(Vmac_tb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vmac_tb___024root___eval_initial__TOP__Vtiming__0(Vmac_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vmac_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ mac_tb__DOT__check__Vstatic__expected;
    mac_tb__DOT__check__Vstatic__expected = 0;
    IData/*31:0*/ __Vtask_mac_tb__DOT__check__0__expected;
    __Vtask_mac_tb__DOT__check__0__expected = 0;
    IData/*31:0*/ __Vtask_mac_tb__DOT__check__1__expected;
    __Vtask_mac_tb__DOT__check__1__expected = 0;
    IData/*31:0*/ __Vtask_mac_tb__DOT__check__2__expected;
    __Vtask_mac_tb__DOT__check__2__expected = 0;
    IData/*31:0*/ __Vtask_mac_tb__DOT__check__3__expected;
    __Vtask_mac_tb__DOT__check__3__expected = 0;
    IData/*31:0*/ __Vtask_mac_tb__DOT__check__4__expected;
    __Vtask_mac_tb__DOT__check__4__expected = 0;
    IData/*31:0*/ __Vtask_mac_tb__DOT__check__5__expected;
    __Vtask_mac_tb__DOT__check__5__expected = 0;
    // Body
    vlSymsp->_vm_contextp__->dumpfile("arithmetic/mac.vcd"s);
    VL_PRINTF_MT("-Info: mac_tb.v:54: $dumpvar ignored, as Verilated without --trace\n");
    vlSelfRef.mac_tb__DOT__clk = 0U;
    vlSelfRef.mac_tb__DOT__reset = 1U;
    vlSelfRef.mac_tb__DOT__enable = 0U;
    vlSelfRef.mac_tb__DOT__A = 0U;
    vlSelfRef.mac_tb__DOT__B = 0U;
    Vmac_tb___024root____VbeforeTrig_hf844d8d6__0(vlSelf, 
                                                  "@(posedge mac_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hf844d8d6__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge mac_tb.clk)", 
                                                         "mac_tb.v", 
                                                         63);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "mac_tb.v", 
                                         64);
    if ((0U != vlSelfRef.mac_tb__DOT__acc_out)) {
        VL_WRITEF_NX("FAIL: Reset did not clear accumulator\n",0);
        vlSelfRef.mac_tb__DOT__errors = ((IData)(1U) 
                                         + vlSelfRef.mac_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS: Reset | ACC=0\n",0);
    }
    vlSelfRef.mac_tb__DOT__reset = 0U;
    vlSelfRef.mac_tb__DOT__enable = 1U;
    vlSelfRef.mac_tb__DOT__A = 2U;
    vlSelfRef.mac_tb__DOT__B = 3U;
    Vmac_tb___024root____VbeforeTrig_hf844d8d6__0(vlSelf, 
                                                  "@(posedge mac_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hf844d8d6__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge mac_tb.clk)", 
                                                         "mac_tb.v", 
                                                         80);
    __Vtask_mac_tb__DOT__check__0__expected = 6U;
    mac_tb__DOT__check__Vstatic__expected = __Vtask_mac_tb__DOT__check__0__expected;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "mac_tb.v", 
                                         32);
    if ((vlSelfRef.mac_tb__DOT__acc_out != mac_tb__DOT__check__Vstatic__expected)) {
        VL_WRITEF_NX("FAIL: A=%0d B=%0d enable=%b | Got=%0d | Expected=%0d\n",5
                     , '#',8,vlSelfRef.mac_tb__DOT__A
                     , '#',8,(IData)(vlSelfRef.mac_tb__DOT__B)
                     , '#',1,vlSelfRef.mac_tb__DOT__enable
                     , '#',32,vlSelfRef.mac_tb__DOT__acc_out
                     , '#',32,mac_tb__DOT__check__Vstatic__expected);
        vlSelfRef.mac_tb__DOT__errors = ((IData)(1U) 
                                         + vlSelfRef.mac_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS: A=%0d B=%0d enable=%b | ACC=%0d\n",4
                     , '#',8,vlSelfRef.mac_tb__DOT__A
                     , '#',8,(IData)(vlSelfRef.mac_tb__DOT__B)
                     , '#',1,vlSelfRef.mac_tb__DOT__enable
                     , '#',32,vlSelfRef.mac_tb__DOT__acc_out);
    }
    vlSelfRef.mac_tb__DOT__A = 4U;
    vlSelfRef.mac_tb__DOT__B = 5U;
    Vmac_tb___024root____VbeforeTrig_hf844d8d6__0(vlSelf, 
                                                  "@(posedge mac_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hf844d8d6__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge mac_tb.clk)", 
                                                         "mac_tb.v", 
                                                         89);
    __Vtask_mac_tb__DOT__check__1__expected = 0x0000001aU;
    mac_tb__DOT__check__Vstatic__expected = __Vtask_mac_tb__DOT__check__1__expected;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "mac_tb.v", 
                                         32);
    if ((vlSelfRef.mac_tb__DOT__acc_out != mac_tb__DOT__check__Vstatic__expected)) {
        VL_WRITEF_NX("FAIL: A=%0d B=%0d enable=%b | Got=%0d | Expected=%0d\n",5
                     , '#',8,vlSelfRef.mac_tb__DOT__A
                     , '#',8,(IData)(vlSelfRef.mac_tb__DOT__B)
                     , '#',1,vlSelfRef.mac_tb__DOT__enable
                     , '#',32,vlSelfRef.mac_tb__DOT__acc_out
                     , '#',32,mac_tb__DOT__check__Vstatic__expected);
        vlSelfRef.mac_tb__DOT__errors = ((IData)(1U) 
                                         + vlSelfRef.mac_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS: A=%0d B=%0d enable=%b | ACC=%0d\n",4
                     , '#',8,vlSelfRef.mac_tb__DOT__A
                     , '#',8,(IData)(vlSelfRef.mac_tb__DOT__B)
                     , '#',1,vlSelfRef.mac_tb__DOT__enable
                     , '#',32,vlSelfRef.mac_tb__DOT__acc_out);
    }
    vlSelfRef.mac_tb__DOT__A = 0x0aU;
    vlSelfRef.mac_tb__DOT__B = 2U;
    Vmac_tb___024root____VbeforeTrig_hf844d8d6__0(vlSelf, 
                                                  "@(posedge mac_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hf844d8d6__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge mac_tb.clk)", 
                                                         "mac_tb.v", 
                                                         98);
    __Vtask_mac_tb__DOT__check__2__expected = 0x0000002eU;
    mac_tb__DOT__check__Vstatic__expected = __Vtask_mac_tb__DOT__check__2__expected;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "mac_tb.v", 
                                         32);
    if ((vlSelfRef.mac_tb__DOT__acc_out != mac_tb__DOT__check__Vstatic__expected)) {
        VL_WRITEF_NX("FAIL: A=%0d B=%0d enable=%b | Got=%0d | Expected=%0d\n",5
                     , '#',8,vlSelfRef.mac_tb__DOT__A
                     , '#',8,(IData)(vlSelfRef.mac_tb__DOT__B)
                     , '#',1,vlSelfRef.mac_tb__DOT__enable
                     , '#',32,vlSelfRef.mac_tb__DOT__acc_out
                     , '#',32,mac_tb__DOT__check__Vstatic__expected);
        vlSelfRef.mac_tb__DOT__errors = ((IData)(1U) 
                                         + vlSelfRef.mac_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS: A=%0d B=%0d enable=%b | ACC=%0d\n",4
                     , '#',8,vlSelfRef.mac_tb__DOT__A
                     , '#',8,(IData)(vlSelfRef.mac_tb__DOT__B)
                     , '#',1,vlSelfRef.mac_tb__DOT__enable
                     , '#',32,vlSelfRef.mac_tb__DOT__acc_out);
    }
    vlSelfRef.mac_tb__DOT__enable = 0U;
    vlSelfRef.mac_tb__DOT__A = 0x64U;
    vlSelfRef.mac_tb__DOT__B = 0x64U;
    Vmac_tb___024root____VbeforeTrig_hf844d8d6__0(vlSelf, 
                                                  "@(posedge mac_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hf844d8d6__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge mac_tb.clk)", 
                                                         "mac_tb.v", 
                                                         108);
    __Vtask_mac_tb__DOT__check__3__expected = 0x0000002eU;
    mac_tb__DOT__check__Vstatic__expected = __Vtask_mac_tb__DOT__check__3__expected;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "mac_tb.v", 
                                         32);
    if ((vlSelfRef.mac_tb__DOT__acc_out != mac_tb__DOT__check__Vstatic__expected)) {
        VL_WRITEF_NX("FAIL: A=%0d B=%0d enable=%b | Got=%0d | Expected=%0d\n",5
                     , '#',8,vlSelfRef.mac_tb__DOT__A
                     , '#',8,(IData)(vlSelfRef.mac_tb__DOT__B)
                     , '#',1,vlSelfRef.mac_tb__DOT__enable
                     , '#',32,vlSelfRef.mac_tb__DOT__acc_out
                     , '#',32,mac_tb__DOT__check__Vstatic__expected);
        vlSelfRef.mac_tb__DOT__errors = ((IData)(1U) 
                                         + vlSelfRef.mac_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS: A=%0d B=%0d enable=%b | ACC=%0d\n",4
                     , '#',8,vlSelfRef.mac_tb__DOT__A
                     , '#',8,(IData)(vlSelfRef.mac_tb__DOT__B)
                     , '#',1,vlSelfRef.mac_tb__DOT__enable
                     , '#',32,vlSelfRef.mac_tb__DOT__acc_out);
    }
    vlSelfRef.mac_tb__DOT__enable = 1U;
    vlSelfRef.mac_tb__DOT__A = 7U;
    vlSelfRef.mac_tb__DOT__B = 8U;
    Vmac_tb___024root____VbeforeTrig_hf844d8d6__0(vlSelf, 
                                                  "@(posedge mac_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hf844d8d6__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge mac_tb.clk)", 
                                                         "mac_tb.v", 
                                                         118);
    __Vtask_mac_tb__DOT__check__4__expected = 0x00000066U;
    mac_tb__DOT__check__Vstatic__expected = __Vtask_mac_tb__DOT__check__4__expected;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "mac_tb.v", 
                                         32);
    if ((vlSelfRef.mac_tb__DOT__acc_out != mac_tb__DOT__check__Vstatic__expected)) {
        VL_WRITEF_NX("FAIL: A=%0d B=%0d enable=%b | Got=%0d | Expected=%0d\n",5
                     , '#',8,vlSelfRef.mac_tb__DOT__A
                     , '#',8,(IData)(vlSelfRef.mac_tb__DOT__B)
                     , '#',1,vlSelfRef.mac_tb__DOT__enable
                     , '#',32,vlSelfRef.mac_tb__DOT__acc_out
                     , '#',32,mac_tb__DOT__check__Vstatic__expected);
        vlSelfRef.mac_tb__DOT__errors = ((IData)(1U) 
                                         + vlSelfRef.mac_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS: A=%0d B=%0d enable=%b | ACC=%0d\n",4
                     , '#',8,vlSelfRef.mac_tb__DOT__A
                     , '#',8,(IData)(vlSelfRef.mac_tb__DOT__B)
                     , '#',1,vlSelfRef.mac_tb__DOT__enable
                     , '#',32,vlSelfRef.mac_tb__DOT__acc_out);
    }
    vlSelfRef.mac_tb__DOT__A = 0xc8U;
    vlSelfRef.mac_tb__DOT__B = 0xc8U;
    Vmac_tb___024root____VbeforeTrig_hf844d8d6__0(vlSelf, 
                                                  "@(posedge mac_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hf844d8d6__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge mac_tb.clk)", 
                                                         "mac_tb.v", 
                                                         128);
    __Vtask_mac_tb__DOT__check__5__expected = 0x00009ca6U;
    mac_tb__DOT__check__Vstatic__expected = __Vtask_mac_tb__DOT__check__5__expected;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "mac_tb.v", 
                                         32);
    if ((vlSelfRef.mac_tb__DOT__acc_out != mac_tb__DOT__check__Vstatic__expected)) {
        VL_WRITEF_NX("FAIL: A=%0d B=%0d enable=%b | Got=%0d | Expected=%0d\n",5
                     , '#',8,vlSelfRef.mac_tb__DOT__A
                     , '#',8,(IData)(vlSelfRef.mac_tb__DOT__B)
                     , '#',1,vlSelfRef.mac_tb__DOT__enable
                     , '#',32,vlSelfRef.mac_tb__DOT__acc_out
                     , '#',32,mac_tb__DOT__check__Vstatic__expected);
        vlSelfRef.mac_tb__DOT__errors = ((IData)(1U) 
                                         + vlSelfRef.mac_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS: A=%0d B=%0d enable=%b | ACC=%0d\n",4
                     , '#',8,vlSelfRef.mac_tb__DOT__A
                     , '#',8,(IData)(vlSelfRef.mac_tb__DOT__B)
                     , '#',1,vlSelfRef.mac_tb__DOT__enable
                     , '#',32,vlSelfRef.mac_tb__DOT__acc_out);
    }
    if ((0U == vlSelfRef.mac_tb__DOT__errors)) {
        VL_WRITEF_NX("ALL MAC TESTS PASSED\n",0);
    } else {
        VL_WRITEF_NX("%0d MAC TEST(S) FAILED\n",1, '~',32,vlSelfRef.mac_tb__DOT__errors);
    }
    VL_FINISH_MT("mac_tb.v", 137, "");
    co_return;
}

VlCoroutine Vmac_tb___024root___eval_initial__TOP__Vtiming__1(Vmac_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vmac_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "mac_tb.v", 
                                             26);
        vlSelfRef.mac_tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.mac_tb__DOT__clk)));
    }
    co_return;
}

bool Vmac_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___trigger_anySet__ico\n"); );
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

bool Vmac_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___trigger_anySet__act\n"); );
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

void Vmac_tb___024root___timing_ready(Vmac_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___timing_ready\n"); );
    Vmac_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hf844d8d6__0.ready("@(posedge mac_tb.clk)");
    }
}

void Vmac_tb___024root___timing_resume(Vmac_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___timing_resume\n"); );
    Vmac_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_hf844d8d6__0.moveToResumeQueue(
                                                          "@(posedge mac_tb.clk)");
    vlSelfRef.__VtrigSched_hf844d8d6__0.resume("@(posedge mac_tb.clk)");
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vmac_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vmac_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vmac_tb___024root____VbeforeTrig_hf844d8d6__0(Vmac_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root____VbeforeTrig_hf844d8d6__0\n"); );
    Vmac_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((IData)(vlSelfRef.mac_tb__DOT__clk) 
                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__mac_tb__DOT__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__mac_tb__DOT__clk__0 
        = vlSelfRef.mac_tb__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_hf844d8d6__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hf844d8d6__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hf844d8d6__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hf844d8d6__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hf844d8d6__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hf844d8d6__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hf844d8d6__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vmac_tb___024root___eval_debug_assertions(Vmac_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_tb___024root___eval_debug_assertions\n"); );
    Vmac_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
