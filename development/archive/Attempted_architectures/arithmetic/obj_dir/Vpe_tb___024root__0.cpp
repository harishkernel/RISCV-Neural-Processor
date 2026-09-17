// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpe_tb.h for the primary calling header

#include "Vpe_tb__pch.h"

VlCoroutine Vpe_tb___024root___eval_initial__TOP__Vtiming__0(Vpe_tb___024root* vlSelf);
VlCoroutine Vpe_tb___024root___eval_initial__TOP__Vtiming__1(Vpe_tb___024root* vlSelf);

void Vpe_tb___024root___eval_initial(Vpe_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___eval_initial\n"); );
    Vpe_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vpe_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vpe_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vpe_tb___024root___eval_sample(Vpe_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___eval_sample\n"); );
    Vpe_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpe_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vpe_tb___024root___eval_ico(Vpe_tb___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___eval_ico\n"); );
    Vpe_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpe_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vpe_tb___024root___timing_ready(Vpe_tb___024root* vlSelf);
void Vpe_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpe_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vpe_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vpe_tb___024root___timing_resume(Vpe_tb___024root* vlSelf);

bool Vpe_tb___024root___eval_act(Vpe_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___eval_act\n"); );
    Vpe_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                          << 1U) 
                                                         | ((IData)(vlSelfRef.pe_tb__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pe_tb__DOT__clk__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__pe_tb__DOT__clk__0 
            = vlSelfRef.pe_tb__DOT__clk;
    }
    Vpe_tb___024root___timing_ready(vlSelf);
    Vpe_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpe_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vpe_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vpe_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vpe_tb___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vpe_tb___024root___eval_inact(Vpe_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___eval_inact\n"); );
    Vpe_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("pe_tb.v", 3, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vpe_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vpe_tb___024root___eval_nba(Vpe_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___eval_nba\n"); );
    Vpe_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vpe_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__0
                    IData/*31:0*/ __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__pe_tb__DOT__acc_out;
                    __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__pe_tb__DOT__acc_out = 0;
                    __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__pe_tb__DOT__acc_out 
                        = vlSelfRef.pe_tb__DOT__acc_out;
                    if (vlSelfRef.pe_tb__DOT__reset) {
                        __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__pe_tb__DOT__acc_out = 0U;
                        vlSelfRef.pe_tb__DOT__A_out = 0U;
                        vlSelfRef.pe_tb__DOT__B_out = 0U;
                    } else if (vlSelfRef.pe_tb__DOT__enable) {
                        __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__pe_tb__DOT__acc_out 
                            = (vlSelfRef.pe_tb__DOT__acc_out 
                               + (0x0000ffffU & ((IData)(vlSelfRef.pe_tb__DOT__B_in) 
                                                 * (IData)(vlSelfRef.pe_tb__DOT__A_in))));
                        vlSelfRef.pe_tb__DOT__A_out 
                            = vlSelfRef.pe_tb__DOT__A_in;
                        vlSelfRef.pe_tb__DOT__B_out 
                            = vlSelfRef.pe_tb__DOT__B_in;
                    }
                    vlSelfRef.pe_tb__DOT__acc_out = __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__pe_tb__DOT__acc_out;
                }
            }
        }
        Vpe_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vpe_tb___024root___eval_obs(Vpe_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___eval_obs\n"); );
    Vpe_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vpe_tb___024root___eval_react(Vpe_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___eval_react\n"); );
    Vpe_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vpe_tb___024root___eval_postponed(Vpe_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___eval_postponed\n"); );
    Vpe_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vpe_tb___024root____VbeforeTrig_h2e34af0c__0(Vpe_tb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vpe_tb___024root___eval_initial__TOP__Vtiming__0(Vpe_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vpe_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ pe_tb__DOT__check__Vstatic__expected_acc;
    pe_tb__DOT__check__Vstatic__expected_acc = 0;
    CData/*7:0*/ pe_tb__DOT__check__Vstatic__expected_A;
    pe_tb__DOT__check__Vstatic__expected_A = 0;
    CData/*7:0*/ pe_tb__DOT__check__Vstatic__expected_B;
    pe_tb__DOT__check__Vstatic__expected_B = 0;
    IData/*31:0*/ __Vtask_pe_tb__DOT__check__0__expected_acc;
    __Vtask_pe_tb__DOT__check__0__expected_acc = 0;
    CData/*7:0*/ __Vtask_pe_tb__DOT__check__0__expected_A;
    __Vtask_pe_tb__DOT__check__0__expected_A = 0;
    CData/*7:0*/ __Vtask_pe_tb__DOT__check__0__expected_B;
    __Vtask_pe_tb__DOT__check__0__expected_B = 0;
    IData/*31:0*/ __Vtask_pe_tb__DOT__check__1__expected_acc;
    __Vtask_pe_tb__DOT__check__1__expected_acc = 0;
    CData/*7:0*/ __Vtask_pe_tb__DOT__check__1__expected_A;
    __Vtask_pe_tb__DOT__check__1__expected_A = 0;
    CData/*7:0*/ __Vtask_pe_tb__DOT__check__1__expected_B;
    __Vtask_pe_tb__DOT__check__1__expected_B = 0;
    IData/*31:0*/ __Vtask_pe_tb__DOT__check__2__expected_acc;
    __Vtask_pe_tb__DOT__check__2__expected_acc = 0;
    CData/*7:0*/ __Vtask_pe_tb__DOT__check__2__expected_A;
    __Vtask_pe_tb__DOT__check__2__expected_A = 0;
    CData/*7:0*/ __Vtask_pe_tb__DOT__check__2__expected_B;
    __Vtask_pe_tb__DOT__check__2__expected_B = 0;
    // Body
    vlSymsp->_vm_contextp__->dumpfile("arithmetic/pe.vcd"s);
    VL_PRINTF_MT("-Info: pe_tb.v:69: $dumpvar ignored, as Verilated without --trace\n");
    vlSelfRef.pe_tb__DOT__clk = 0U;
    vlSelfRef.pe_tb__DOT__reset = 1U;
    vlSelfRef.pe_tb__DOT__enable = 0U;
    vlSelfRef.pe_tb__DOT__A_in = 0U;
    vlSelfRef.pe_tb__DOT__B_in = 0U;
    Vpe_tb___024root____VbeforeTrig_h2e34af0c__0(vlSelf, 
                                                 "@(posedge pe_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h2e34af0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge pe_tb.clk)", 
                                                         "pe_tb.v", 
                                                         78);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "pe_tb.v", 
                                         79);
    if ((((0U != vlSelfRef.pe_tb__DOT__acc_out) | (0U 
                                                   != (IData)(vlSelfRef.pe_tb__DOT__A_out))) 
         | (0U != (IData)(vlSelfRef.pe_tb__DOT__B_out)))) {
        VL_WRITEF_NX("FAIL: Reset\n",0);
        vlSelfRef.pe_tb__DOT__errors = ((IData)(1U) 
                                        + vlSelfRef.pe_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS: Reset\n",0);
    }
    vlSelfRef.pe_tb__DOT__reset = 0U;
    vlSelfRef.pe_tb__DOT__enable = 1U;
    vlSelfRef.pe_tb__DOT__A_in = 2U;
    vlSelfRef.pe_tb__DOT__B_in = 3U;
    Vpe_tb___024root____VbeforeTrig_h2e34af0c__0(vlSelf, 
                                                 "@(posedge pe_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h2e34af0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge pe_tb.clk)", 
                                                         "pe_tb.v", 
                                                         95);
    __Vtask_pe_tb__DOT__check__0__expected_B = 3U;
    __Vtask_pe_tb__DOT__check__0__expected_A = 2U;
    __Vtask_pe_tb__DOT__check__0__expected_acc = 6U;
    pe_tb__DOT__check__Vstatic__expected_acc = __Vtask_pe_tb__DOT__check__0__expected_acc;
    pe_tb__DOT__check__Vstatic__expected_A = __Vtask_pe_tb__DOT__check__0__expected_A;
    pe_tb__DOT__check__Vstatic__expected_B = __Vtask_pe_tb__DOT__check__0__expected_B;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "pe_tb.v", 
                                         40);
    if (VL_UNLIKELY(((vlSelfRef.pe_tb__DOT__acc_out 
                      != pe_tb__DOT__check__Vstatic__expected_acc)))) {
        VL_WRITEF_NX("FAIL ACC: A=%0d B=%0d | Got=%0d | Expected=%0d\n",4
                     , '#',8,vlSelfRef.pe_tb__DOT__A_in
                     , '#',8,(IData)(vlSelfRef.pe_tb__DOT__B_in)
                     , '#',32,vlSelfRef.pe_tb__DOT__acc_out
                     , '#',32,pe_tb__DOT__check__Vstatic__expected_acc);
        vlSelfRef.pe_tb__DOT__errors = ((IData)(1U) 
                                        + vlSelfRef.pe_tb__DOT__errors);
    } else if ((((IData)(vlSelfRef.pe_tb__DOT__A_out) 
                 != (IData)(pe_tb__DOT__check__Vstatic__expected_A)) 
                | ((IData)(vlSelfRef.pe_tb__DOT__B_out) 
                   != (IData)(pe_tb__DOT__check__Vstatic__expected_B)))) {
        VL_WRITEF_NX("FAIL FORWARD: A_out=%0d B_out=%0d | Expected A=%0d B=%0d\n",4
                     , '#',8,vlSelfRef.pe_tb__DOT__A_out
                     , '#',8,(IData)(vlSelfRef.pe_tb__DOT__B_out)
                     , '#',8,pe_tb__DOT__check__Vstatic__expected_A
                     , '#',8,(IData)(pe_tb__DOT__check__Vstatic__expected_B));
        vlSelfRef.pe_tb__DOT__errors = ((IData)(1U) 
                                        + vlSelfRef.pe_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS: A=%0d B=%0d | ACC=%0d | A_out=%0d B_out=%0d\n",5
                     , '#',8,vlSelfRef.pe_tb__DOT__A_in
                     , '#',8,(IData)(vlSelfRef.pe_tb__DOT__B_in)
                     , '#',32,vlSelfRef.pe_tb__DOT__acc_out
                     , '#',8,(IData)(vlSelfRef.pe_tb__DOT__A_out)
                     , '#',8,vlSelfRef.pe_tb__DOT__B_out);
    }
    vlSelfRef.pe_tb__DOT__A_in = 4U;
    vlSelfRef.pe_tb__DOT__B_in = 5U;
    Vpe_tb___024root____VbeforeTrig_h2e34af0c__0(vlSelf, 
                                                 "@(posedge pe_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h2e34af0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge pe_tb.clk)", 
                                                         "pe_tb.v", 
                                                         104);
    __Vtask_pe_tb__DOT__check__1__expected_B = 5U;
    __Vtask_pe_tb__DOT__check__1__expected_A = 4U;
    __Vtask_pe_tb__DOT__check__1__expected_acc = 0x0000001aU;
    pe_tb__DOT__check__Vstatic__expected_acc = __Vtask_pe_tb__DOT__check__1__expected_acc;
    pe_tb__DOT__check__Vstatic__expected_A = __Vtask_pe_tb__DOT__check__1__expected_A;
    pe_tb__DOT__check__Vstatic__expected_B = __Vtask_pe_tb__DOT__check__1__expected_B;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "pe_tb.v", 
                                         40);
    vlSelfRef.pe_tb__DOT__enable = 0U;
    if (VL_UNLIKELY(((vlSelfRef.pe_tb__DOT__acc_out 
                      != pe_tb__DOT__check__Vstatic__expected_acc)))) {
        VL_WRITEF_NX("FAIL ACC: A=%0d B=%0d | Got=%0d | Expected=%0d\n",4
                     , '#',8,vlSelfRef.pe_tb__DOT__A_in
                     , '#',8,(IData)(vlSelfRef.pe_tb__DOT__B_in)
                     , '#',32,vlSelfRef.pe_tb__DOT__acc_out
                     , '#',32,pe_tb__DOT__check__Vstatic__expected_acc);
        vlSelfRef.pe_tb__DOT__errors = ((IData)(1U) 
                                        + vlSelfRef.pe_tb__DOT__errors);
    } else if ((((IData)(vlSelfRef.pe_tb__DOT__A_out) 
                 != (IData)(pe_tb__DOT__check__Vstatic__expected_A)) 
                | ((IData)(vlSelfRef.pe_tb__DOT__B_out) 
                   != (IData)(pe_tb__DOT__check__Vstatic__expected_B)))) {
        VL_WRITEF_NX("FAIL FORWARD: A_out=%0d B_out=%0d | Expected A=%0d B=%0d\n",4
                     , '#',8,vlSelfRef.pe_tb__DOT__A_out
                     , '#',8,(IData)(vlSelfRef.pe_tb__DOT__B_out)
                     , '#',8,pe_tb__DOT__check__Vstatic__expected_A
                     , '#',8,(IData)(pe_tb__DOT__check__Vstatic__expected_B));
        vlSelfRef.pe_tb__DOT__errors = ((IData)(1U) 
                                        + vlSelfRef.pe_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS: A=%0d B=%0d | ACC=%0d | A_out=%0d B_out=%0d\n",5
                     , '#',8,vlSelfRef.pe_tb__DOT__A_in
                     , '#',8,(IData)(vlSelfRef.pe_tb__DOT__B_in)
                     , '#',32,vlSelfRef.pe_tb__DOT__acc_out
                     , '#',8,(IData)(vlSelfRef.pe_tb__DOT__A_out)
                     , '#',8,vlSelfRef.pe_tb__DOT__B_out);
    }
    vlSelfRef.pe_tb__DOT__A_in = 0x64U;
    vlSelfRef.pe_tb__DOT__B_in = 0x64U;
    Vpe_tb___024root____VbeforeTrig_h2e34af0c__0(vlSelf, 
                                                 "@(posedge pe_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h2e34af0c__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge pe_tb.clk)", 
                                                         "pe_tb.v", 
                                                         114);
    __Vtask_pe_tb__DOT__check__2__expected_B = 5U;
    __Vtask_pe_tb__DOT__check__2__expected_A = 4U;
    __Vtask_pe_tb__DOT__check__2__expected_acc = 0x0000001aU;
    pe_tb__DOT__check__Vstatic__expected_acc = __Vtask_pe_tb__DOT__check__2__expected_acc;
    pe_tb__DOT__check__Vstatic__expected_A = __Vtask_pe_tb__DOT__check__2__expected_A;
    pe_tb__DOT__check__Vstatic__expected_B = __Vtask_pe_tb__DOT__check__2__expected_B;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "pe_tb.v", 
                                         40);
    if (VL_UNLIKELY(((vlSelfRef.pe_tb__DOT__acc_out 
                      != pe_tb__DOT__check__Vstatic__expected_acc)))) {
        VL_WRITEF_NX("FAIL ACC: A=%0d B=%0d | Got=%0d | Expected=%0d\n",4
                     , '#',8,vlSelfRef.pe_tb__DOT__A_in
                     , '#',8,(IData)(vlSelfRef.pe_tb__DOT__B_in)
                     , '#',32,vlSelfRef.pe_tb__DOT__acc_out
                     , '#',32,pe_tb__DOT__check__Vstatic__expected_acc);
        vlSelfRef.pe_tb__DOT__errors = ((IData)(1U) 
                                        + vlSelfRef.pe_tb__DOT__errors);
    } else if ((((IData)(vlSelfRef.pe_tb__DOT__A_out) 
                 != (IData)(pe_tb__DOT__check__Vstatic__expected_A)) 
                | ((IData)(vlSelfRef.pe_tb__DOT__B_out) 
                   != (IData)(pe_tb__DOT__check__Vstatic__expected_B)))) {
        VL_WRITEF_NX("FAIL FORWARD: A_out=%0d B_out=%0d | Expected A=%0d B=%0d\n",4
                     , '#',8,vlSelfRef.pe_tb__DOT__A_out
                     , '#',8,(IData)(vlSelfRef.pe_tb__DOT__B_out)
                     , '#',8,pe_tb__DOT__check__Vstatic__expected_A
                     , '#',8,(IData)(pe_tb__DOT__check__Vstatic__expected_B));
        vlSelfRef.pe_tb__DOT__errors = ((IData)(1U) 
                                        + vlSelfRef.pe_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS: A=%0d B=%0d | ACC=%0d | A_out=%0d B_out=%0d\n",5
                     , '#',8,vlSelfRef.pe_tb__DOT__A_in
                     , '#',8,(IData)(vlSelfRef.pe_tb__DOT__B_in)
                     , '#',32,vlSelfRef.pe_tb__DOT__acc_out
                     , '#',8,(IData)(vlSelfRef.pe_tb__DOT__A_out)
                     , '#',8,vlSelfRef.pe_tb__DOT__B_out);
    }
    if ((0U == vlSelfRef.pe_tb__DOT__errors)) {
        VL_WRITEF_NX("ALL PE TESTS PASSED\n",0);
    } else {
        VL_WRITEF_NX("%0d PE TEST(S) FAILED\n",1, '~',32,vlSelfRef.pe_tb__DOT__errors);
    }
    VL_FINISH_MT("pe_tb.v", 123, "");
    co_return;
}

VlCoroutine Vpe_tb___024root___eval_initial__TOP__Vtiming__1(Vpe_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vpe_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "pe_tb.v", 
                                             31);
        vlSelfRef.pe_tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.pe_tb__DOT__clk)));
    }
    co_return;
}

bool Vpe_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___trigger_anySet__ico\n"); );
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

bool Vpe_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___trigger_anySet__act\n"); );
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

void Vpe_tb___024root___timing_ready(Vpe_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___timing_ready\n"); );
    Vpe_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h2e34af0c__0.ready("@(posedge pe_tb.clk)");
    }
}

void Vpe_tb___024root___timing_resume(Vpe_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___timing_resume\n"); );
    Vpe_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h2e34af0c__0.moveToResumeQueue(
                                                          "@(posedge pe_tb.clk)");
    vlSelfRef.__VtrigSched_h2e34af0c__0.resume("@(posedge pe_tb.clk)");
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vpe_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vpe_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vpe_tb___024root____VbeforeTrig_h2e34af0c__0(Vpe_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root____VbeforeTrig_h2e34af0c__0\n"); );
    Vpe_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((IData)(vlSelfRef.pe_tb__DOT__clk) 
                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pe_tb__DOT__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__pe_tb__DOT__clk__0 
        = vlSelfRef.pe_tb__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h2e34af0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h2e34af0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h2e34af0c__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h2e34af0c__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vpe_tb___024root___eval_debug_assertions(Vpe_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpe_tb___024root___eval_debug_assertions\n"); );
    Vpe_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
