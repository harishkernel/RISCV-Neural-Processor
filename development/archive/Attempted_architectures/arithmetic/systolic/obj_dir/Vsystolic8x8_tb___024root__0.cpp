// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic8x8_tb.h for the primary calling header

#include "Vsystolic8x8_tb__pch.h"

VlCoroutine Vsystolic8x8_tb___024root___eval_initial__TOP__Vtiming__0(Vsystolic8x8_tb___024root* vlSelf);
VlCoroutine Vsystolic8x8_tb___024root___eval_initial__TOP__Vtiming__1(Vsystolic8x8_tb___024root* vlSelf);

void Vsystolic8x8_tb___024root___eval_initial(Vsystolic8x8_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___eval_initial\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsystolic8x8_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vsystolic8x8_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vsystolic8x8_tb___024root___eval_sample(Vsystolic8x8_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___eval_sample\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic8x8_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vsystolic8x8_tb___024root___eval_ico(Vsystolic8x8_tb___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___eval_ico\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsystolic8x8_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vsystolic8x8_tb___024root___timing_ready(Vsystolic8x8_tb___024root* vlSelf);
void Vsystolic8x8_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsystolic8x8_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vsystolic8x8_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vsystolic8x8_tb___024root___timing_resume(Vsystolic8x8_tb___024root* vlSelf);
void Vsystolic8x8_tb___024root___act_comb__TOP__0(Vsystolic8x8_tb___024root* vlSelf);

bool Vsystolic8x8_tb___024root___eval_act(Vsystolic8x8_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___eval_act\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                          << 1U) 
                                                         | ((IData)(vlSelfRef.systolic8x8_tb__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__systolic8x8_tb__DOT__clk__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__systolic8x8_tb__DOT__clk__0 
            = vlSelfRef.systolic8x8_tb__DOT__clk;
    }
    Vsystolic8x8_tb___024root___timing_ready(vlSelf);
    Vsystolic8x8_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsystolic8x8_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vsystolic8x8_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vsystolic8x8_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vsystolic8x8_tb___024root___timing_resume(vlSelf);
        {
            // Inlined CFunc: _eval_body__act
            if ((3ULL & vlSelfRef.__VactTriggered[0U])) {
                Vsystolic8x8_tb___024root___act_comb__TOP__0(vlSelf);
            }
        }
    }
    return (__VactExecute);
}

bool Vsystolic8x8_tb___024root___eval_inact(Vsystolic8x8_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___eval_inact\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("systolic8x8_tb.v", 3, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vsystolic8x8_tb___024root___nba_sequent__TOP__0(Vsystolic8x8_tb___024root* vlSelf);
void Vsystolic8x8_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vsystolic8x8_tb___024root___eval_nba(Vsystolic8x8_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___eval_nba\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vsystolic8x8_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vsystolic8x8_tb___024root___nba_sequent__TOP__0(vlSelf);
            }
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vsystolic8x8_tb___024root___act_comb__TOP__0(vlSelf);
            }
        }
        Vsystolic8x8_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vsystolic8x8_tb___024root___eval_obs(Vsystolic8x8_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___eval_obs\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vsystolic8x8_tb___024root___eval_react(Vsystolic8x8_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___eval_react\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vsystolic8x8_tb___024root___eval_postponed(Vsystolic8x8_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___eval_postponed\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

extern const VlWide<16>/*511:0*/ Vsystolic8x8_tb__ConstPool__CONST_heb6e377c_0;
extern const VlWide<16>/*511:0*/ Vsystolic8x8_tb__ConstPool__CONST_h7c856ef8_0;
void Vsystolic8x8_tb___024root____VbeforeTrig_had55cf4f__0(Vsystolic8x8_tb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vsystolic8x8_tb___024root___eval_initial__TOP__Vtiming__0(Vsystolic8x8_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ systolic8x8_tb__DOT__unnamedblk1_1__DOT____Vrepeat0;
    systolic8x8_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ systolic8x8_tb__DOT__unnamedblk1_2__DOT____Vrepeat1;
    systolic8x8_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    // Body
    vlSymsp->_vm_contextp__->dumpfile("arithmetic/systolic/systolic8x8.vcd"s);
    VL_PRINTF_MT("-Info: systolic8x8_tb.v:73: $dumpvar ignored, as Verilated without --trace\n");
    vlSelfRef.systolic8x8_tb__DOT__clk = 0U;
    vlSelfRef.systolic8x8_tb__DOT__reset = 1U;
    vlSelfRef.systolic8x8_tb__DOT__enable = 0U;
    VL_ASSIGN_W(512, vlSelfRef.systolic8x8_tb__DOT__A, Vsystolic8x8_tb__ConstPool__CONST_heb6e377c_0);
    VL_ASSIGN_W(512, vlSelfRef.systolic8x8_tb__DOT__B, Vsystolic8x8_tb__ConstPool__CONST_h7c856ef8_0);
    systolic8x8_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    while (VL_LTS_III(32, 0U, systolic8x8_tb__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vsystolic8x8_tb___024root____VbeforeTrig_had55cf4f__0(vlSelf, 
                                                              "@(posedge systolic8x8_tb.clk)");
        co_await vlSelfRef.__VtrigSched_had55cf4f__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge systolic8x8_tb.clk)", 
                                                             "systolic8x8_tb.v", 
                                                             142);
        systolic8x8_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (systolic8x8_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.systolic8x8_tb__DOT__reset = 0U;
    vlSelfRef.systolic8x8_tb__DOT__enable = 1U;
    systolic8x8_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0x00000017U;
    while (VL_LTS_III(32, 0U, systolic8x8_tb__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
        Vsystolic8x8_tb___024root____VbeforeTrig_had55cf4f__0(vlSelf, 
                                                              "@(posedge systolic8x8_tb.clk)");
        co_await vlSelfRef.__VtrigSched_had55cf4f__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge systolic8x8_tb.clk)", 
                                                             "systolic8x8_tb.v", 
                                                             154);
        systolic8x8_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 
            = (systolic8x8_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 
               - (IData)(1U));
    }
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "systolic8x8_tb.v", 
                                         156);
    if ((0x000000ccU != vlSelfRef.systolic8x8_tb__DOT__C00)) {
        VL_WRITEF_NX("FAIL C00: got %0d, expected 204\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C00);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C00 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C00);
    }
    if ((0x000000f0U != vlSelfRef.systolic8x8_tb__DOT__C01)) {
        VL_WRITEF_NX("FAIL C01: got %0d, expected 240\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C01);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C01 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C01);
    }
    if ((0x00000114U != vlSelfRef.systolic8x8_tb__DOT__C02)) {
        VL_WRITEF_NX("FAIL C02: got %0d, expected 276\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C02);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C02 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C02);
    }
    if ((0x00000138U != vlSelfRef.systolic8x8_tb__DOT__C03)) {
        VL_WRITEF_NX("FAIL C03: got %0d, expected 312\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C03);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C03 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C03);
    }
    if ((0x0000015cU != vlSelfRef.systolic8x8_tb__DOT__C04)) {
        VL_WRITEF_NX("FAIL C04: got %0d, expected 348\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C04);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C04 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C04);
    }
    if ((0x00000180U != vlSelfRef.systolic8x8_tb__DOT__C05)) {
        VL_WRITEF_NX("FAIL C05: got %0d, expected 384\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C05);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C05 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C05);
    }
    if ((0x000001a4U != vlSelfRef.systolic8x8_tb__DOT__C06)) {
        VL_WRITEF_NX("FAIL C06: got %0d, expected 420\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C06);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C06 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C06);
    }
    if ((0x000001c8U != vlSelfRef.systolic8x8_tb__DOT__C07)) {
        VL_WRITEF_NX("FAIL C07: got %0d, expected 456\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C07);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C07 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C07);
    }
    if ((0x000001ecU != vlSelfRef.systolic8x8_tb__DOT__C10)) {
        VL_WRITEF_NX("FAIL C10: got %0d, expected 492\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C10);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C10 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C10);
    }
    if ((0x00000250U != vlSelfRef.systolic8x8_tb__DOT__C11)) {
        VL_WRITEF_NX("FAIL C11: got %0d, expected 592\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C11);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C11 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C11);
    }
    if ((0x000002b4U != vlSelfRef.systolic8x8_tb__DOT__C12)) {
        VL_WRITEF_NX("FAIL C12: got %0d, expected 692\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C12);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C12 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C12);
    }
    if ((0x00000318U != vlSelfRef.systolic8x8_tb__DOT__C13)) {
        VL_WRITEF_NX("FAIL C13: got %0d, expected 792\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C13);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C13 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C13);
    }
    if ((0x0000037cU != vlSelfRef.systolic8x8_tb__DOT__C14)) {
        VL_WRITEF_NX("FAIL C14: got %0d, expected 892\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C14);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C14 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C14);
    }
    if ((0x000003e0U != vlSelfRef.systolic8x8_tb__DOT__C15)) {
        VL_WRITEF_NX("FAIL C15: got %0d, expected 992\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C15);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C15 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C15);
    }
    if ((0x00000444U != vlSelfRef.systolic8x8_tb__DOT__C16)) {
        VL_WRITEF_NX("FAIL C16: got %0d, expected 1092\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C16);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C16 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C16);
    }
    if ((0x000004a8U != vlSelfRef.systolic8x8_tb__DOT__C17)) {
        VL_WRITEF_NX("FAIL C17: got %0d, expected 1192\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C17);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C17 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C17);
    }
    if ((0x0000030cU != vlSelfRef.systolic8x8_tb__DOT__C20)) {
        VL_WRITEF_NX("FAIL C20: got %0d, expected 780\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C20);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C20 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C20);
    }
    if ((0x000003b0U != vlSelfRef.systolic8x8_tb__DOT__C21)) {
        VL_WRITEF_NX("FAIL C21: got %0d, expected 944\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C21);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C21 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C21);
    }
    if ((0x00000454U != vlSelfRef.systolic8x8_tb__DOT__C22)) {
        VL_WRITEF_NX("FAIL C22: got %0d, expected 1108\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C22);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C22 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C22);
    }
    if ((0x000004f8U != vlSelfRef.systolic8x8_tb__DOT__C23)) {
        VL_WRITEF_NX("FAIL C23: got %0d, expected 1272\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C23);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C23 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C23);
    }
    if ((0x0000059cU != vlSelfRef.systolic8x8_tb__DOT__C24)) {
        VL_WRITEF_NX("FAIL C24: got %0d, expected 1436\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C24);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C24 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C24);
    }
    if ((0x00000640U != vlSelfRef.systolic8x8_tb__DOT__C25)) {
        VL_WRITEF_NX("FAIL C25: got %0d, expected 1600\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C25);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C25 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C25);
    }
    if ((0x000006e4U != vlSelfRef.systolic8x8_tb__DOT__C26)) {
        VL_WRITEF_NX("FAIL C26: got %0d, expected 1764\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C26);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C26 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C26);
    }
    if ((0x00000788U != vlSelfRef.systolic8x8_tb__DOT__C27)) {
        VL_WRITEF_NX("FAIL C27: got %0d, expected 1928\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C27);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C27 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C27);
    }
    if ((0x0000042cU != vlSelfRef.systolic8x8_tb__DOT__C30)) {
        VL_WRITEF_NX("FAIL C30: got %0d, expected 1068\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C30);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C30 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C30);
    }
    if ((0x00000510U != vlSelfRef.systolic8x8_tb__DOT__C31)) {
        VL_WRITEF_NX("FAIL C31: got %0d, expected 1296\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C31);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C31 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C31);
    }
    if ((0x000005f4U != vlSelfRef.systolic8x8_tb__DOT__C32)) {
        VL_WRITEF_NX("FAIL C32: got %0d, expected 1524\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C32);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C32 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C32);
    }
    if ((0x000006d8U != vlSelfRef.systolic8x8_tb__DOT__C33)) {
        VL_WRITEF_NX("FAIL C33: got %0d, expected 1752\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C33);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C33 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C33);
    }
    if ((0x000007bcU != vlSelfRef.systolic8x8_tb__DOT__C34)) {
        VL_WRITEF_NX("FAIL C34: got %0d, expected 1980\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C34);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C34 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C34);
    }
    if ((0x000008a0U != vlSelfRef.systolic8x8_tb__DOT__C35)) {
        VL_WRITEF_NX("FAIL C35: got %0d, expected 2208\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C35);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C35 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C35);
    }
    if ((0x00000984U != vlSelfRef.systolic8x8_tb__DOT__C36)) {
        VL_WRITEF_NX("FAIL C36: got %0d, expected 2436\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C36);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C36 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C36);
    }
    if ((0x00000a68U != vlSelfRef.systolic8x8_tb__DOT__C37)) {
        VL_WRITEF_NX("FAIL C37: got %0d, expected 2664\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C37);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C37 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C37);
    }
    if ((0x0000054cU != vlSelfRef.systolic8x8_tb__DOT__C40)) {
        VL_WRITEF_NX("FAIL C40: got %0d, expected 1356\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C40);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C40 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C40);
    }
    if ((0x00000670U != vlSelfRef.systolic8x8_tb__DOT__C41)) {
        VL_WRITEF_NX("FAIL C41: got %0d, expected 1648\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C41);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C41 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C41);
    }
    if ((0x00000794U != vlSelfRef.systolic8x8_tb__DOT__C42)) {
        VL_WRITEF_NX("FAIL C42: got %0d, expected 1940\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C42);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C42 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C42);
    }
    if ((0x000008b8U != vlSelfRef.systolic8x8_tb__DOT__C43)) {
        VL_WRITEF_NX("FAIL C43: got %0d, expected 2232\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C43);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C43 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C43);
    }
    if ((0x000009dcU != vlSelfRef.systolic8x8_tb__DOT__C44)) {
        VL_WRITEF_NX("FAIL C44: got %0d, expected 2524\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C44);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C44 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C44);
    }
    if ((0x00000b00U != vlSelfRef.systolic8x8_tb__DOT__C45)) {
        VL_WRITEF_NX("FAIL C45: got %0d, expected 2816\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C45);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C45 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C45);
    }
    if ((0x00000c24U != vlSelfRef.systolic8x8_tb__DOT__C46)) {
        VL_WRITEF_NX("FAIL C46: got %0d, expected 3108\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C46);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C46 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C46);
    }
    if ((0x00000d48U != vlSelfRef.systolic8x8_tb__DOT__C47)) {
        VL_WRITEF_NX("FAIL C47: got %0d, expected 3400\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C47);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C47 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C47);
    }
    if ((0x0000066cU != vlSelfRef.systolic8x8_tb__DOT__C50)) {
        VL_WRITEF_NX("FAIL C50: got %0d, expected 1644\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C50);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C50 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C50);
    }
    if ((0x000007d0U != vlSelfRef.systolic8x8_tb__DOT__C51)) {
        VL_WRITEF_NX("FAIL C51: got %0d, expected 2000\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C51);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C51 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C51);
    }
    if ((0x00000934U != vlSelfRef.systolic8x8_tb__DOT__C52)) {
        VL_WRITEF_NX("FAIL C52: got %0d, expected 2356\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C52);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C52 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C52);
    }
    if ((0x00000a98U != vlSelfRef.systolic8x8_tb__DOT__C53)) {
        VL_WRITEF_NX("FAIL C53: got %0d, expected 2712\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C53);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C53 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C53);
    }
    if ((0x00000bfcU != vlSelfRef.systolic8x8_tb__DOT__C54)) {
        VL_WRITEF_NX("FAIL C54: got %0d, expected 3068\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C54);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C54 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C54);
    }
    if ((0x00000d60U != vlSelfRef.systolic8x8_tb__DOT__C55)) {
        VL_WRITEF_NX("FAIL C55: got %0d, expected 3424\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C55);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C55 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C55);
    }
    if ((0x00000ec4U != vlSelfRef.systolic8x8_tb__DOT__C56)) {
        VL_WRITEF_NX("FAIL C56: got %0d, expected 3780\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C56);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C56 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C56);
    }
    if ((0x00001028U != vlSelfRef.systolic8x8_tb__DOT__C57)) {
        VL_WRITEF_NX("FAIL C57: got %0d, expected 4136\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C57);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C57 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C57);
    }
    if ((0x0000078cU != vlSelfRef.systolic8x8_tb__DOT__C60)) {
        VL_WRITEF_NX("FAIL C60: got %0d, expected 1932\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C60);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C60 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C60);
    }
    if ((0x00000930U != vlSelfRef.systolic8x8_tb__DOT__C61)) {
        VL_WRITEF_NX("FAIL C61: got %0d, expected 2352\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C61);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C61 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C61);
    }
    if ((0x00000ad4U != vlSelfRef.systolic8x8_tb__DOT__C62)) {
        VL_WRITEF_NX("FAIL C62: got %0d, expected 2772\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C62);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C62 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C62);
    }
    if ((0x00000c78U != vlSelfRef.systolic8x8_tb__DOT__C63)) {
        VL_WRITEF_NX("FAIL C63: got %0d, expected 3192\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C63);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C63 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C63);
    }
    if ((0x00000e1cU != vlSelfRef.systolic8x8_tb__DOT__C64)) {
        VL_WRITEF_NX("FAIL C64: got %0d, expected 3612\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C64);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C64 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C64);
    }
    if ((0x00000fc0U != vlSelfRef.systolic8x8_tb__DOT__C65)) {
        VL_WRITEF_NX("FAIL C65: got %0d, expected 4032\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C65);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C65 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C65);
    }
    if ((0x00001164U != vlSelfRef.systolic8x8_tb__DOT__C66)) {
        VL_WRITEF_NX("FAIL C66: got %0d, expected 4452\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C66);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C66 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C66);
    }
    if ((0x00001308U != vlSelfRef.systolic8x8_tb__DOT__C67)) {
        VL_WRITEF_NX("FAIL C67: got %0d, expected 4872\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C67);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C67 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C67);
    }
    if ((0x000008acU != vlSelfRef.systolic8x8_tb__DOT__C70)) {
        VL_WRITEF_NX("FAIL C70: got %0d, expected 2220\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C70);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C70 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C70);
    }
    if ((0x00000a90U != vlSelfRef.systolic8x8_tb__DOT__C71)) {
        VL_WRITEF_NX("FAIL C71: got %0d, expected 2704\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C71);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C71 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C71);
    }
    if ((0x00000c74U != vlSelfRef.systolic8x8_tb__DOT__C72)) {
        VL_WRITEF_NX("FAIL C72: got %0d, expected 3188\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C72);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C72 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C72);
    }
    if ((0x00000e58U != vlSelfRef.systolic8x8_tb__DOT__C73)) {
        VL_WRITEF_NX("FAIL C73: got %0d, expected 3672\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C73);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C73 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C73);
    }
    if ((0x0000103cU != vlSelfRef.systolic8x8_tb__DOT__C74)) {
        VL_WRITEF_NX("FAIL C74: got %0d, expected 4156\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C74);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C74 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C74);
    }
    if ((0x00001220U != vlSelfRef.systolic8x8_tb__DOT__C75)) {
        VL_WRITEF_NX("FAIL C75: got %0d, expected 4640\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C75);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C75 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C75);
    }
    if ((0x00001404U != vlSelfRef.systolic8x8_tb__DOT__C76)) {
        VL_WRITEF_NX("FAIL C76: got %0d, expected 5124\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C76);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C76 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C76);
    }
    if ((0x000015e8U != vlSelfRef.systolic8x8_tb__DOT__C77)) {
        VL_WRITEF_NX("FAIL C77: got %0d, expected 5608\n",1
                     , '#',32,vlSelfRef.systolic8x8_tb__DOT__C77);
        vlSelfRef.systolic8x8_tb__DOT__errors = ((IData)(1U) 
                                                 + vlSelfRef.systolic8x8_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C77 = %0d\n",1, '#',32,vlSelfRef.systolic8x8_tb__DOT__C77);
    }
    if ((0U == vlSelfRef.systolic8x8_tb__DOT__errors)) {
        VL_WRITEF_NX("================================\nALL SYSTOLIC 8x8 TESTS PASSED\n================================\n",0);
    } else {
        VL_WRITEF_NX("%0d TESTS FAILED\n",1, '~',32,vlSelfRef.systolic8x8_tb__DOT__errors);
    }
    VL_FINISH_MT("systolic8x8_tb.v", 642, "");
    co_return;
}

VlCoroutine Vsystolic8x8_tb___024root___eval_initial__TOP__Vtiming__1(Vsystolic8x8_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "systolic8x8_tb.v", 
                                             63);
        vlSelfRef.systolic8x8_tb__DOT__clk = (1U & 
                                              (~ (IData)(vlSelfRef.systolic8x8_tb__DOT__clk)));
    }
    co_return;
}

bool Vsystolic8x8_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___trigger_anySet__ico\n"); );
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

bool Vsystolic8x8_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___trigger_anySet__act\n"); );
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

void Vsystolic8x8_tb___024root___act_comb__TOP__0(Vsystolic8x8_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___act_comb__TOP__0\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[0U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[0U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[0U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[0U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[0U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[0U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[0U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[0U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[0U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[1U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[0U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[1U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[0U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[1U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[0U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[1U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[1U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[2U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[1U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[2U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[1U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[2U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[1U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[2U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[1U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[3U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[1U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[3U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[1U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[3U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[1U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[3U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[2U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[4U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[2U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[4U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[2U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[4U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[2U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[4U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[2U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[5U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[2U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[5U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[2U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[5U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[2U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[5U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[3U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[6U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[3U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[6U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[3U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[6U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[3U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[6U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[3U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[7U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[3U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[7U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[3U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[7U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[3U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[7U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[4U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[8U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[4U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[8U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[4U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[8U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[4U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[8U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[4U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[9U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[4U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[9U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[4U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[9U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[4U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[9U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[5U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[10U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[5U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[10U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[5U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[10U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[5U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[10U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[5U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[11U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[5U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[11U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[5U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[11U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[5U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[11U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[6U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[12U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[6U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[12U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[6U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[12U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[6U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[12U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[6U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[13U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[6U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[13U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[6U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[13U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[6U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[13U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[7U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[14U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[7U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[14U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[7U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[14U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[7U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[14U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[7U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__A[15U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[7U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[15U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[7U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__A[15U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[7U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__A[15U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[0U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[0U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[0U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[0U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[0U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[0U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[0U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[0U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[0U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[1U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[0U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[1U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[0U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[1U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[0U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[1U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[1U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[2U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[1U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[2U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[1U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[2U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[1U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[2U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[1U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[3U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[1U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[3U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[1U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[3U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[1U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[3U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[2U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[4U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[2U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[4U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[2U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[4U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[2U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[4U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[2U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[5U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[2U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[5U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[2U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[5U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[2U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[5U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[3U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[6U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[3U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[6U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[3U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[6U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[3U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[6U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[3U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[7U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[3U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[7U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[3U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[7U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[3U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[7U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[4U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[8U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[4U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[8U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[4U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[8U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[4U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[8U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[4U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[9U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[4U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[9U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[4U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[9U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[4U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[9U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[5U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[10U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[5U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[10U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[5U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[10U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[5U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[10U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[5U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[11U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[5U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[11U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[5U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[11U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[5U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[11U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[6U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[12U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[6U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[12U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[6U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[12U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[6U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[12U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[6U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[13U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[6U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[13U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[6U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[13U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[6U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[13U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[7U][0U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[14U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[7U][1U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[14U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[7U][2U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[14U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[7U][3U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[14U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[7U][4U] 
        = (0x000000ffU & vlSelfRef.systolic8x8_tb__DOT__B[15U]);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[7U][5U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[15U] 
                          >> 8U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[7U][6U] 
        = (0x000000ffU & (vlSelfRef.systolic8x8_tb__DOT__B[15U] 
                          >> 0x00000010U));
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix[7U][7U] 
        = (vlSelfRef.systolic8x8_tb__DOT__B[15U] >> 0x00000018U);
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[0U] = 0U;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[1U] = 0U;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[2U] = 0U;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[3U] = 0U;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[4U] = 0U;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[5U] = 0U;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[6U] = 0U;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[7U] = 0U;
    if ((VL_LTES_III(32, 0U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle) 
         & VL_GTS_III(32, 8U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle))) {
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[0U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[0U]
            [(7U & vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle)];
    }
    if ((VL_LTES_III(32, 1U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle) 
         & VL_GTS_III(32, 9U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle))) {
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[1U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[1U]
            [(7U & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle 
                    - (IData)(1U)))];
    }
    if ((VL_LTES_III(32, 2U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000aU, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle))) {
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[2U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[2U]
            [(7U & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle 
                    - (IData)(2U)))];
    }
    if ((VL_LTES_III(32, 3U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000bU, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle))) {
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[3U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[3U]
            [(7U & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle 
                    - (IData)(3U)))];
    }
    if ((VL_LTES_III(32, 4U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000cU, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle))) {
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[4U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[4U]
            [(7U & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle 
                    - (IData)(4U)))];
    }
    if ((VL_LTES_III(32, 5U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000dU, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle))) {
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[5U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[5U]
            [(7U & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle 
                    - (IData)(5U)))];
    }
    if ((VL_LTES_III(32, 6U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000eU, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle))) {
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[6U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[6U]
            [(7U & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle 
                    - (IData)(6U)))];
    }
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[0U] = 0U;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[1U] = 0U;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[2U] = 0U;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[3U] = 0U;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[4U] = 0U;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[5U] = 0U;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[6U] = 0U;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[7U] = 0U;
    if ((VL_LTES_III(32, 0U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle) 
         & VL_GTS_III(32, 8U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle))) {
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[0U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix
            [(7U & vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle)][0U];
    }
    if ((VL_LTES_III(32, 1U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle) 
         & VL_GTS_III(32, 9U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle))) {
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[1U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix
            [(7U & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle 
                    - (IData)(1U)))][1U];
    }
    if ((VL_LTES_III(32, 2U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000aU, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle))) {
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[2U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix
            [(7U & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle 
                    - (IData)(2U)))][2U];
    }
    if ((VL_LTES_III(32, 3U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000bU, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle))) {
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[3U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix
            [(7U & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle 
                    - (IData)(3U)))][3U];
    }
    if ((VL_LTES_III(32, 4U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000cU, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle))) {
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[4U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix
            [(7U & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle 
                    - (IData)(4U)))][4U];
    }
    if ((VL_LTES_III(32, 5U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000dU, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle))) {
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[5U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix
            [(7U & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle 
                    - (IData)(5U)))][5U];
    }
    if ((VL_LTES_III(32, 6U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000eU, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle))) {
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[6U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix
            [(7U & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle 
                    - (IData)(6U)))][6U];
    }
    if ((VL_LTES_III(32, 7U, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000fU, vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle))) {
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[7U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_matrix[7U]
            [(7U & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle 
                    - (IData)(7U)))];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[7U] 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_matrix
            [(7U & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle 
                    - (IData)(7U)))][7U];
    }
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[0U];
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[1U];
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[2U];
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[3U];
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[4U];
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[5U];
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[6U];
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_feed[7U];
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[0U];
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[1U];
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[2U];
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[3U];
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[4U];
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[5U];
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[6U];
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_feed[7U];
}

void Vsystolic8x8_tb___024root___nba_sequent__TOP__0(Vsystolic8x8_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___nba_sequent__TOP__0\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__uut__DOT__cycle;
    __Vdly__systolic8x8_tb__DOT__uut__DOT__cycle = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C77;
    __Vdly__systolic8x8_tb__DOT__C77 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C76;
    __Vdly__systolic8x8_tb__DOT__C76 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C75;
    __Vdly__systolic8x8_tb__DOT__C75 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C74;
    __Vdly__systolic8x8_tb__DOT__C74 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C73;
    __Vdly__systolic8x8_tb__DOT__C73 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C72;
    __Vdly__systolic8x8_tb__DOT__C72 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C71;
    __Vdly__systolic8x8_tb__DOT__C71 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C70;
    __Vdly__systolic8x8_tb__DOT__C70 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C67;
    __Vdly__systolic8x8_tb__DOT__C67 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C66;
    __Vdly__systolic8x8_tb__DOT__C66 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C65;
    __Vdly__systolic8x8_tb__DOT__C65 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C64;
    __Vdly__systolic8x8_tb__DOT__C64 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C63;
    __Vdly__systolic8x8_tb__DOT__C63 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C62;
    __Vdly__systolic8x8_tb__DOT__C62 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C61;
    __Vdly__systolic8x8_tb__DOT__C61 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C60;
    __Vdly__systolic8x8_tb__DOT__C60 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C57;
    __Vdly__systolic8x8_tb__DOT__C57 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C56;
    __Vdly__systolic8x8_tb__DOT__C56 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C55;
    __Vdly__systolic8x8_tb__DOT__C55 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C54;
    __Vdly__systolic8x8_tb__DOT__C54 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C53;
    __Vdly__systolic8x8_tb__DOT__C53 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C52;
    __Vdly__systolic8x8_tb__DOT__C52 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C51;
    __Vdly__systolic8x8_tb__DOT__C51 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C50;
    __Vdly__systolic8x8_tb__DOT__C50 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C47;
    __Vdly__systolic8x8_tb__DOT__C47 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C46;
    __Vdly__systolic8x8_tb__DOT__C46 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C45;
    __Vdly__systolic8x8_tb__DOT__C45 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C44;
    __Vdly__systolic8x8_tb__DOT__C44 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C43;
    __Vdly__systolic8x8_tb__DOT__C43 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C42;
    __Vdly__systolic8x8_tb__DOT__C42 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C41;
    __Vdly__systolic8x8_tb__DOT__C41 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C40;
    __Vdly__systolic8x8_tb__DOT__C40 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C37;
    __Vdly__systolic8x8_tb__DOT__C37 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C36;
    __Vdly__systolic8x8_tb__DOT__C36 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C35;
    __Vdly__systolic8x8_tb__DOT__C35 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C34;
    __Vdly__systolic8x8_tb__DOT__C34 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C33;
    __Vdly__systolic8x8_tb__DOT__C33 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C32;
    __Vdly__systolic8x8_tb__DOT__C32 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C31;
    __Vdly__systolic8x8_tb__DOT__C31 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C30;
    __Vdly__systolic8x8_tb__DOT__C30 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C27;
    __Vdly__systolic8x8_tb__DOT__C27 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C26;
    __Vdly__systolic8x8_tb__DOT__C26 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C25;
    __Vdly__systolic8x8_tb__DOT__C25 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C24;
    __Vdly__systolic8x8_tb__DOT__C24 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C23;
    __Vdly__systolic8x8_tb__DOT__C23 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C22;
    __Vdly__systolic8x8_tb__DOT__C22 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C21;
    __Vdly__systolic8x8_tb__DOT__C21 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C20;
    __Vdly__systolic8x8_tb__DOT__C20 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C17;
    __Vdly__systolic8x8_tb__DOT__C17 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C16;
    __Vdly__systolic8x8_tb__DOT__C16 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C15;
    __Vdly__systolic8x8_tb__DOT__C15 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C14;
    __Vdly__systolic8x8_tb__DOT__C14 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C13;
    __Vdly__systolic8x8_tb__DOT__C13 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C12;
    __Vdly__systolic8x8_tb__DOT__C12 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C11;
    __Vdly__systolic8x8_tb__DOT__C11 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C10;
    __Vdly__systolic8x8_tb__DOT__C10 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C07;
    __Vdly__systolic8x8_tb__DOT__C07 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C06;
    __Vdly__systolic8x8_tb__DOT__C06 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C05;
    __Vdly__systolic8x8_tb__DOT__C05 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C04;
    __Vdly__systolic8x8_tb__DOT__C04 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C03;
    __Vdly__systolic8x8_tb__DOT__C03 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C02;
    __Vdly__systolic8x8_tb__DOT__C02 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C01;
    __Vdly__systolic8x8_tb__DOT__C01 = 0;
    IData/*31:0*/ __Vdly__systolic8x8_tb__DOT__C00;
    __Vdly__systolic8x8_tb__DOT__C00 = 0;
    // Body
    __Vdly__systolic8x8_tb__DOT__uut__DOT__cycle = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle;
    __Vdly__systolic8x8_tb__DOT__C77 = vlSelfRef.systolic8x8_tb__DOT__C77;
    __Vdly__systolic8x8_tb__DOT__C76 = vlSelfRef.systolic8x8_tb__DOT__C76;
    __Vdly__systolic8x8_tb__DOT__C75 = vlSelfRef.systolic8x8_tb__DOT__C75;
    __Vdly__systolic8x8_tb__DOT__C74 = vlSelfRef.systolic8x8_tb__DOT__C74;
    __Vdly__systolic8x8_tb__DOT__C73 = vlSelfRef.systolic8x8_tb__DOT__C73;
    __Vdly__systolic8x8_tb__DOT__C72 = vlSelfRef.systolic8x8_tb__DOT__C72;
    __Vdly__systolic8x8_tb__DOT__C71 = vlSelfRef.systolic8x8_tb__DOT__C71;
    __Vdly__systolic8x8_tb__DOT__C70 = vlSelfRef.systolic8x8_tb__DOT__C70;
    __Vdly__systolic8x8_tb__DOT__C67 = vlSelfRef.systolic8x8_tb__DOT__C67;
    __Vdly__systolic8x8_tb__DOT__C66 = vlSelfRef.systolic8x8_tb__DOT__C66;
    __Vdly__systolic8x8_tb__DOT__C65 = vlSelfRef.systolic8x8_tb__DOT__C65;
    __Vdly__systolic8x8_tb__DOT__C64 = vlSelfRef.systolic8x8_tb__DOT__C64;
    __Vdly__systolic8x8_tb__DOT__C63 = vlSelfRef.systolic8x8_tb__DOT__C63;
    __Vdly__systolic8x8_tb__DOT__C62 = vlSelfRef.systolic8x8_tb__DOT__C62;
    __Vdly__systolic8x8_tb__DOT__C61 = vlSelfRef.systolic8x8_tb__DOT__C61;
    __Vdly__systolic8x8_tb__DOT__C60 = vlSelfRef.systolic8x8_tb__DOT__C60;
    __Vdly__systolic8x8_tb__DOT__C57 = vlSelfRef.systolic8x8_tb__DOT__C57;
    __Vdly__systolic8x8_tb__DOT__C56 = vlSelfRef.systolic8x8_tb__DOT__C56;
    __Vdly__systolic8x8_tb__DOT__C55 = vlSelfRef.systolic8x8_tb__DOT__C55;
    __Vdly__systolic8x8_tb__DOT__C54 = vlSelfRef.systolic8x8_tb__DOT__C54;
    __Vdly__systolic8x8_tb__DOT__C53 = vlSelfRef.systolic8x8_tb__DOT__C53;
    __Vdly__systolic8x8_tb__DOT__C52 = vlSelfRef.systolic8x8_tb__DOT__C52;
    __Vdly__systolic8x8_tb__DOT__C51 = vlSelfRef.systolic8x8_tb__DOT__C51;
    __Vdly__systolic8x8_tb__DOT__C50 = vlSelfRef.systolic8x8_tb__DOT__C50;
    __Vdly__systolic8x8_tb__DOT__C47 = vlSelfRef.systolic8x8_tb__DOT__C47;
    __Vdly__systolic8x8_tb__DOT__C46 = vlSelfRef.systolic8x8_tb__DOT__C46;
    __Vdly__systolic8x8_tb__DOT__C45 = vlSelfRef.systolic8x8_tb__DOT__C45;
    __Vdly__systolic8x8_tb__DOT__C44 = vlSelfRef.systolic8x8_tb__DOT__C44;
    __Vdly__systolic8x8_tb__DOT__C43 = vlSelfRef.systolic8x8_tb__DOT__C43;
    __Vdly__systolic8x8_tb__DOT__C42 = vlSelfRef.systolic8x8_tb__DOT__C42;
    __Vdly__systolic8x8_tb__DOT__C41 = vlSelfRef.systolic8x8_tb__DOT__C41;
    __Vdly__systolic8x8_tb__DOT__C40 = vlSelfRef.systolic8x8_tb__DOT__C40;
    __Vdly__systolic8x8_tb__DOT__C37 = vlSelfRef.systolic8x8_tb__DOT__C37;
    __Vdly__systolic8x8_tb__DOT__C36 = vlSelfRef.systolic8x8_tb__DOT__C36;
    __Vdly__systolic8x8_tb__DOT__C35 = vlSelfRef.systolic8x8_tb__DOT__C35;
    __Vdly__systolic8x8_tb__DOT__C34 = vlSelfRef.systolic8x8_tb__DOT__C34;
    __Vdly__systolic8x8_tb__DOT__C33 = vlSelfRef.systolic8x8_tb__DOT__C33;
    __Vdly__systolic8x8_tb__DOT__C32 = vlSelfRef.systolic8x8_tb__DOT__C32;
    __Vdly__systolic8x8_tb__DOT__C31 = vlSelfRef.systolic8x8_tb__DOT__C31;
    __Vdly__systolic8x8_tb__DOT__C30 = vlSelfRef.systolic8x8_tb__DOT__C30;
    __Vdly__systolic8x8_tb__DOT__C27 = vlSelfRef.systolic8x8_tb__DOT__C27;
    __Vdly__systolic8x8_tb__DOT__C26 = vlSelfRef.systolic8x8_tb__DOT__C26;
    __Vdly__systolic8x8_tb__DOT__C25 = vlSelfRef.systolic8x8_tb__DOT__C25;
    __Vdly__systolic8x8_tb__DOT__C24 = vlSelfRef.systolic8x8_tb__DOT__C24;
    __Vdly__systolic8x8_tb__DOT__C23 = vlSelfRef.systolic8x8_tb__DOT__C23;
    __Vdly__systolic8x8_tb__DOT__C22 = vlSelfRef.systolic8x8_tb__DOT__C22;
    __Vdly__systolic8x8_tb__DOT__C21 = vlSelfRef.systolic8x8_tb__DOT__C21;
    __Vdly__systolic8x8_tb__DOT__C20 = vlSelfRef.systolic8x8_tb__DOT__C20;
    __Vdly__systolic8x8_tb__DOT__C17 = vlSelfRef.systolic8x8_tb__DOT__C17;
    __Vdly__systolic8x8_tb__DOT__C16 = vlSelfRef.systolic8x8_tb__DOT__C16;
    __Vdly__systolic8x8_tb__DOT__C15 = vlSelfRef.systolic8x8_tb__DOT__C15;
    __Vdly__systolic8x8_tb__DOT__C14 = vlSelfRef.systolic8x8_tb__DOT__C14;
    __Vdly__systolic8x8_tb__DOT__C13 = vlSelfRef.systolic8x8_tb__DOT__C13;
    __Vdly__systolic8x8_tb__DOT__C12 = vlSelfRef.systolic8x8_tb__DOT__C12;
    __Vdly__systolic8x8_tb__DOT__C11 = vlSelfRef.systolic8x8_tb__DOT__C11;
    __Vdly__systolic8x8_tb__DOT__C10 = vlSelfRef.systolic8x8_tb__DOT__C10;
    __Vdly__systolic8x8_tb__DOT__C07 = vlSelfRef.systolic8x8_tb__DOT__C07;
    __Vdly__systolic8x8_tb__DOT__C06 = vlSelfRef.systolic8x8_tb__DOT__C06;
    __Vdly__systolic8x8_tb__DOT__C05 = vlSelfRef.systolic8x8_tb__DOT__C05;
    __Vdly__systolic8x8_tb__DOT__C04 = vlSelfRef.systolic8x8_tb__DOT__C04;
    __Vdly__systolic8x8_tb__DOT__C03 = vlSelfRef.systolic8x8_tb__DOT__C03;
    __Vdly__systolic8x8_tb__DOT__C02 = vlSelfRef.systolic8x8_tb__DOT__C02;
    __Vdly__systolic8x8_tb__DOT__C01 = vlSelfRef.systolic8x8_tb__DOT__C01;
    __Vdly__systolic8x8_tb__DOT__C00 = vlSelfRef.systolic8x8_tb__DOT__C00;
    if (vlSelfRef.systolic8x8_tb__DOT__reset) {
        __Vdly__systolic8x8_tb__DOT__uut__DOT__cycle = 0U;
        __Vdly__systolic8x8_tb__DOT__C77 = 0U;
        __Vdly__systolic8x8_tb__DOT__C76 = 0U;
        __Vdly__systolic8x8_tb__DOT__C75 = 0U;
        __Vdly__systolic8x8_tb__DOT__C74 = 0U;
        __Vdly__systolic8x8_tb__DOT__C73 = 0U;
        __Vdly__systolic8x8_tb__DOT__C72 = 0U;
        __Vdly__systolic8x8_tb__DOT__C71 = 0U;
        __Vdly__systolic8x8_tb__DOT__C70 = 0U;
        __Vdly__systolic8x8_tb__DOT__C67 = 0U;
        __Vdly__systolic8x8_tb__DOT__C66 = 0U;
        __Vdly__systolic8x8_tb__DOT__C65 = 0U;
        __Vdly__systolic8x8_tb__DOT__C64 = 0U;
        __Vdly__systolic8x8_tb__DOT__C63 = 0U;
        __Vdly__systolic8x8_tb__DOT__C62 = 0U;
        __Vdly__systolic8x8_tb__DOT__C61 = 0U;
        __Vdly__systolic8x8_tb__DOT__C60 = 0U;
        __Vdly__systolic8x8_tb__DOT__C57 = 0U;
        __Vdly__systolic8x8_tb__DOT__C56 = 0U;
        __Vdly__systolic8x8_tb__DOT__C55 = 0U;
        __Vdly__systolic8x8_tb__DOT__C54 = 0U;
        __Vdly__systolic8x8_tb__DOT__C53 = 0U;
        __Vdly__systolic8x8_tb__DOT__C52 = 0U;
        __Vdly__systolic8x8_tb__DOT__C51 = 0U;
        __Vdly__systolic8x8_tb__DOT__C50 = 0U;
        __Vdly__systolic8x8_tb__DOT__C47 = 0U;
        __Vdly__systolic8x8_tb__DOT__C46 = 0U;
        __Vdly__systolic8x8_tb__DOT__C45 = 0U;
        __Vdly__systolic8x8_tb__DOT__C44 = 0U;
        __Vdly__systolic8x8_tb__DOT__C43 = 0U;
        __Vdly__systolic8x8_tb__DOT__C42 = 0U;
        __Vdly__systolic8x8_tb__DOT__C41 = 0U;
        __Vdly__systolic8x8_tb__DOT__C40 = 0U;
        __Vdly__systolic8x8_tb__DOT__C37 = 0U;
        __Vdly__systolic8x8_tb__DOT__C36 = 0U;
        __Vdly__systolic8x8_tb__DOT__C35 = 0U;
        __Vdly__systolic8x8_tb__DOT__C34 = 0U;
        __Vdly__systolic8x8_tb__DOT__C33 = 0U;
        __Vdly__systolic8x8_tb__DOT__C32 = 0U;
        __Vdly__systolic8x8_tb__DOT__C31 = 0U;
        __Vdly__systolic8x8_tb__DOT__C30 = 0U;
        __Vdly__systolic8x8_tb__DOT__C27 = 0U;
        __Vdly__systolic8x8_tb__DOT__C26 = 0U;
        __Vdly__systolic8x8_tb__DOT__C25 = 0U;
        __Vdly__systolic8x8_tb__DOT__C24 = 0U;
        __Vdly__systolic8x8_tb__DOT__C23 = 0U;
        __Vdly__systolic8x8_tb__DOT__C22 = 0U;
        __Vdly__systolic8x8_tb__DOT__C21 = 0U;
        __Vdly__systolic8x8_tb__DOT__C20 = 0U;
        __Vdly__systolic8x8_tb__DOT__C17 = 0U;
        __Vdly__systolic8x8_tb__DOT__C16 = 0U;
        __Vdly__systolic8x8_tb__DOT__C15 = 0U;
        __Vdly__systolic8x8_tb__DOT__C14 = 0U;
        __Vdly__systolic8x8_tb__DOT__C13 = 0U;
        __Vdly__systolic8x8_tb__DOT__C12 = 0U;
        __Vdly__systolic8x8_tb__DOT__C11 = 0U;
        __Vdly__systolic8x8_tb__DOT__C10 = 0U;
        __Vdly__systolic8x8_tb__DOT__C07 = 0U;
        __Vdly__systolic8x8_tb__DOT__C06 = 0U;
        __Vdly__systolic8x8_tb__DOT__C05 = 0U;
        __Vdly__systolic8x8_tb__DOT__C04 = 0U;
        __Vdly__systolic8x8_tb__DOT__C03 = 0U;
        __Vdly__systolic8x8_tb__DOT__C02 = 0U;
        __Vdly__systolic8x8_tb__DOT__C01 = 0U;
        __Vdly__systolic8x8_tb__DOT__C00 = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe77__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe77__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe76__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe76__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe75__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe75__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe74__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe74__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe73__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe73__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe72__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe72__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe71__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe71__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe70__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe70__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe67__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe67__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe66__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe66__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe65__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe65__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe64__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe64__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe63__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe63__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe62__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe62__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe61__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe61__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe60__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe60__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe57__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe57__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe56__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe56__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe55__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe55__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe54__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe54__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe53__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe53__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe52__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe52__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe51__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe51__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe50__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe50__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe47__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe47__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe46__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe46__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe45__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe45__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe44__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe44__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe43__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe43__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe42__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe42__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe41__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe41__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe40__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe40__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe37__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe37__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe36__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe36__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe35__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe35__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe34__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe34__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe33__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe33__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe32__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe32__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe31__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe31__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe30__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe30__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe27__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe27__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe26__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe26__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe25__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe25__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe24__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe24__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe23__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe23__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe22__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe22__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe21__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe21__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe20__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe20__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe17__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe17__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe16__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe16__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe15__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe15__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe14__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe14__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe13__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe13__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe12__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe12__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe11__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe11__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe10__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe10__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe07__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe07__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe06__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe06__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe05__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe05__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe04__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe04__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe03__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe03__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe02__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe02__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe01__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe01__B_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe00__A_out = 0U;
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe00__B_out = 0U;
    } else if (vlSelfRef.systolic8x8_tb__DOT__enable) {
        __Vdly__systolic8x8_tb__DOT__uut__DOT__cycle 
            = ((IData)(1U) + vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle);
        __Vdly__systolic8x8_tb__DOT__C77 = (vlSelfRef.systolic8x8_tb__DOT__C77 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][7U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][7U])));
        __Vdly__systolic8x8_tb__DOT__C76 = (vlSelfRef.systolic8x8_tb__DOT__C76 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][6U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][6U])));
        __Vdly__systolic8x8_tb__DOT__C75 = (vlSelfRef.systolic8x8_tb__DOT__C75 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][5U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][5U])));
        __Vdly__systolic8x8_tb__DOT__C74 = (vlSelfRef.systolic8x8_tb__DOT__C74 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][4U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][4U])));
        __Vdly__systolic8x8_tb__DOT__C73 = (vlSelfRef.systolic8x8_tb__DOT__C73 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][3U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][3U])));
        __Vdly__systolic8x8_tb__DOT__C72 = (vlSelfRef.systolic8x8_tb__DOT__C72 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][2U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][2U])));
        __Vdly__systolic8x8_tb__DOT__C71 = (vlSelfRef.systolic8x8_tb__DOT__C71 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][1U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][1U])));
        __Vdly__systolic8x8_tb__DOT__C70 = (vlSelfRef.systolic8x8_tb__DOT__C70 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][0U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][0U])));
        __Vdly__systolic8x8_tb__DOT__C67 = (vlSelfRef.systolic8x8_tb__DOT__C67 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][7U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][7U])));
        __Vdly__systolic8x8_tb__DOT__C66 = (vlSelfRef.systolic8x8_tb__DOT__C66 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][6U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][6U])));
        __Vdly__systolic8x8_tb__DOT__C65 = (vlSelfRef.systolic8x8_tb__DOT__C65 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][5U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][5U])));
        __Vdly__systolic8x8_tb__DOT__C64 = (vlSelfRef.systolic8x8_tb__DOT__C64 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][4U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][4U])));
        __Vdly__systolic8x8_tb__DOT__C63 = (vlSelfRef.systolic8x8_tb__DOT__C63 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][3U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][3U])));
        __Vdly__systolic8x8_tb__DOT__C62 = (vlSelfRef.systolic8x8_tb__DOT__C62 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][2U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][2U])));
        __Vdly__systolic8x8_tb__DOT__C61 = (vlSelfRef.systolic8x8_tb__DOT__C61 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][1U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][1U])));
        __Vdly__systolic8x8_tb__DOT__C60 = (vlSelfRef.systolic8x8_tb__DOT__C60 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][0U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][0U])));
        __Vdly__systolic8x8_tb__DOT__C57 = (vlSelfRef.systolic8x8_tb__DOT__C57 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][7U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][7U])));
        __Vdly__systolic8x8_tb__DOT__C56 = (vlSelfRef.systolic8x8_tb__DOT__C56 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][6U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][6U])));
        __Vdly__systolic8x8_tb__DOT__C55 = (vlSelfRef.systolic8x8_tb__DOT__C55 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][5U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][5U])));
        __Vdly__systolic8x8_tb__DOT__C54 = (vlSelfRef.systolic8x8_tb__DOT__C54 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][4U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][4U])));
        __Vdly__systolic8x8_tb__DOT__C53 = (vlSelfRef.systolic8x8_tb__DOT__C53 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][3U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][3U])));
        __Vdly__systolic8x8_tb__DOT__C52 = (vlSelfRef.systolic8x8_tb__DOT__C52 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][2U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][2U])));
        __Vdly__systolic8x8_tb__DOT__C51 = (vlSelfRef.systolic8x8_tb__DOT__C51 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][1U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][1U])));
        __Vdly__systolic8x8_tb__DOT__C50 = (vlSelfRef.systolic8x8_tb__DOT__C50 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][0U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][0U])));
        __Vdly__systolic8x8_tb__DOT__C47 = (vlSelfRef.systolic8x8_tb__DOT__C47 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][7U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][7U])));
        __Vdly__systolic8x8_tb__DOT__C46 = (vlSelfRef.systolic8x8_tb__DOT__C46 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][6U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][6U])));
        __Vdly__systolic8x8_tb__DOT__C45 = (vlSelfRef.systolic8x8_tb__DOT__C45 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][5U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][5U])));
        __Vdly__systolic8x8_tb__DOT__C44 = (vlSelfRef.systolic8x8_tb__DOT__C44 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][4U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][4U])));
        __Vdly__systolic8x8_tb__DOT__C43 = (vlSelfRef.systolic8x8_tb__DOT__C43 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][3U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][3U])));
        __Vdly__systolic8x8_tb__DOT__C42 = (vlSelfRef.systolic8x8_tb__DOT__C42 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][2U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][2U])));
        __Vdly__systolic8x8_tb__DOT__C41 = (vlSelfRef.systolic8x8_tb__DOT__C41 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][1U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][1U])));
        __Vdly__systolic8x8_tb__DOT__C40 = (vlSelfRef.systolic8x8_tb__DOT__C40 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][0U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][0U])));
        __Vdly__systolic8x8_tb__DOT__C37 = (vlSelfRef.systolic8x8_tb__DOT__C37 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][7U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][7U])));
        __Vdly__systolic8x8_tb__DOT__C36 = (vlSelfRef.systolic8x8_tb__DOT__C36 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][6U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][6U])));
        __Vdly__systolic8x8_tb__DOT__C35 = (vlSelfRef.systolic8x8_tb__DOT__C35 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][5U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][5U])));
        __Vdly__systolic8x8_tb__DOT__C34 = (vlSelfRef.systolic8x8_tb__DOT__C34 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][4U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][4U])));
        __Vdly__systolic8x8_tb__DOT__C33 = (vlSelfRef.systolic8x8_tb__DOT__C33 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][3U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][3U])));
        __Vdly__systolic8x8_tb__DOT__C32 = (vlSelfRef.systolic8x8_tb__DOT__C32 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][2U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][2U])));
        __Vdly__systolic8x8_tb__DOT__C31 = (vlSelfRef.systolic8x8_tb__DOT__C31 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][1U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][1U])));
        __Vdly__systolic8x8_tb__DOT__C30 = (vlSelfRef.systolic8x8_tb__DOT__C30 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][0U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][0U])));
        __Vdly__systolic8x8_tb__DOT__C27 = (vlSelfRef.systolic8x8_tb__DOT__C27 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][7U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][7U])));
        __Vdly__systolic8x8_tb__DOT__C26 = (vlSelfRef.systolic8x8_tb__DOT__C26 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][6U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][6U])));
        __Vdly__systolic8x8_tb__DOT__C25 = (vlSelfRef.systolic8x8_tb__DOT__C25 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][5U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][5U])));
        __Vdly__systolic8x8_tb__DOT__C24 = (vlSelfRef.systolic8x8_tb__DOT__C24 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][4U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][4U])));
        __Vdly__systolic8x8_tb__DOT__C23 = (vlSelfRef.systolic8x8_tb__DOT__C23 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][3U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][3U])));
        __Vdly__systolic8x8_tb__DOT__C22 = (vlSelfRef.systolic8x8_tb__DOT__C22 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][2U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][2U])));
        __Vdly__systolic8x8_tb__DOT__C21 = (vlSelfRef.systolic8x8_tb__DOT__C21 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][1U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][1U])));
        __Vdly__systolic8x8_tb__DOT__C20 = (vlSelfRef.systolic8x8_tb__DOT__C20 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][0U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][0U])));
        __Vdly__systolic8x8_tb__DOT__C17 = (vlSelfRef.systolic8x8_tb__DOT__C17 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][7U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][7U])));
        __Vdly__systolic8x8_tb__DOT__C16 = (vlSelfRef.systolic8x8_tb__DOT__C16 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][6U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][6U])));
        __Vdly__systolic8x8_tb__DOT__C15 = (vlSelfRef.systolic8x8_tb__DOT__C15 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][5U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][5U])));
        __Vdly__systolic8x8_tb__DOT__C14 = (vlSelfRef.systolic8x8_tb__DOT__C14 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][4U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][4U])));
        __Vdly__systolic8x8_tb__DOT__C13 = (vlSelfRef.systolic8x8_tb__DOT__C13 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][3U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][3U])));
        __Vdly__systolic8x8_tb__DOT__C12 = (vlSelfRef.systolic8x8_tb__DOT__C12 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][2U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][2U])));
        __Vdly__systolic8x8_tb__DOT__C11 = (vlSelfRef.systolic8x8_tb__DOT__C11 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][1U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][1U])));
        __Vdly__systolic8x8_tb__DOT__C10 = (vlSelfRef.systolic8x8_tb__DOT__C10 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][0U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][0U])));
        __Vdly__systolic8x8_tb__DOT__C07 = (vlSelfRef.systolic8x8_tb__DOT__C07 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][7U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][7U])));
        __Vdly__systolic8x8_tb__DOT__C06 = (vlSelfRef.systolic8x8_tb__DOT__C06 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][6U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][6U])));
        __Vdly__systolic8x8_tb__DOT__C05 = (vlSelfRef.systolic8x8_tb__DOT__C05 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][5U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][5U])));
        __Vdly__systolic8x8_tb__DOT__C04 = (vlSelfRef.systolic8x8_tb__DOT__C04 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][4U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][4U])));
        __Vdly__systolic8x8_tb__DOT__C03 = (vlSelfRef.systolic8x8_tb__DOT__C03 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][3U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][3U])));
        __Vdly__systolic8x8_tb__DOT__C02 = (vlSelfRef.systolic8x8_tb__DOT__C02 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][2U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][2U])));
        __Vdly__systolic8x8_tb__DOT__C01 = (vlSelfRef.systolic8x8_tb__DOT__C01 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][1U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][1U])));
        __Vdly__systolic8x8_tb__DOT__C00 = (vlSelfRef.systolic8x8_tb__DOT__C00 
                                            + (0x0000ffffU 
                                               & (vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][0U] 
                                                  * vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][0U])));
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe77__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe77__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe76__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe76__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe75__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe75__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe74__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe74__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe73__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe73__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe72__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe72__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe71__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe71__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe70__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][0U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe70__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][0U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe67__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe67__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe66__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe66__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe65__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe65__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe64__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe64__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe63__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe63__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe62__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe62__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe61__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe61__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe60__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][0U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe60__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][0U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe57__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe57__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe56__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe56__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe55__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe55__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe54__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe54__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe53__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe53__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe52__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe52__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe51__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe51__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe50__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][0U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe50__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][0U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe47__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe47__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe46__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe46__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe45__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe45__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe44__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe44__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe43__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe43__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe42__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe42__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe41__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe41__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe40__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][0U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe40__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][0U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe37__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe37__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe36__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe36__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe35__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe35__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe34__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe34__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe33__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe33__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe32__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe32__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe31__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe31__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe30__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][0U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe30__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][0U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe27__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe27__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe26__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe26__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe25__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe25__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe24__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe24__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe23__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe23__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe22__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe22__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe21__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe21__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe20__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][0U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe20__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][0U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe17__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe17__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe16__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe16__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe15__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe15__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe14__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe14__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe13__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe13__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe12__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe12__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe11__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe11__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe10__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][0U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe10__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][0U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe07__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe07__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][7U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe06__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe06__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][6U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe05__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe05__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][5U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe04__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe04__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][4U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe03__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe03__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][3U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe02__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe02__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][2U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe01__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe01__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][1U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe00__A_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][0U];
        vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe00__B_out 
            = vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[0U][0U];
    }
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__cycle 
        = __Vdly__systolic8x8_tb__DOT__uut__DOT__cycle;
    vlSelfRef.systolic8x8_tb__DOT__C77 = __Vdly__systolic8x8_tb__DOT__C77;
    vlSelfRef.systolic8x8_tb__DOT__C76 = __Vdly__systolic8x8_tb__DOT__C76;
    vlSelfRef.systolic8x8_tb__DOT__C75 = __Vdly__systolic8x8_tb__DOT__C75;
    vlSelfRef.systolic8x8_tb__DOT__C74 = __Vdly__systolic8x8_tb__DOT__C74;
    vlSelfRef.systolic8x8_tb__DOT__C73 = __Vdly__systolic8x8_tb__DOT__C73;
    vlSelfRef.systolic8x8_tb__DOT__C72 = __Vdly__systolic8x8_tb__DOT__C72;
    vlSelfRef.systolic8x8_tb__DOT__C71 = __Vdly__systolic8x8_tb__DOT__C71;
    vlSelfRef.systolic8x8_tb__DOT__C70 = __Vdly__systolic8x8_tb__DOT__C70;
    vlSelfRef.systolic8x8_tb__DOT__C67 = __Vdly__systolic8x8_tb__DOT__C67;
    vlSelfRef.systolic8x8_tb__DOT__C66 = __Vdly__systolic8x8_tb__DOT__C66;
    vlSelfRef.systolic8x8_tb__DOT__C65 = __Vdly__systolic8x8_tb__DOT__C65;
    vlSelfRef.systolic8x8_tb__DOT__C64 = __Vdly__systolic8x8_tb__DOT__C64;
    vlSelfRef.systolic8x8_tb__DOT__C63 = __Vdly__systolic8x8_tb__DOT__C63;
    vlSelfRef.systolic8x8_tb__DOT__C62 = __Vdly__systolic8x8_tb__DOT__C62;
    vlSelfRef.systolic8x8_tb__DOT__C61 = __Vdly__systolic8x8_tb__DOT__C61;
    vlSelfRef.systolic8x8_tb__DOT__C60 = __Vdly__systolic8x8_tb__DOT__C60;
    vlSelfRef.systolic8x8_tb__DOT__C57 = __Vdly__systolic8x8_tb__DOT__C57;
    vlSelfRef.systolic8x8_tb__DOT__C56 = __Vdly__systolic8x8_tb__DOT__C56;
    vlSelfRef.systolic8x8_tb__DOT__C55 = __Vdly__systolic8x8_tb__DOT__C55;
    vlSelfRef.systolic8x8_tb__DOT__C54 = __Vdly__systolic8x8_tb__DOT__C54;
    vlSelfRef.systolic8x8_tb__DOT__C53 = __Vdly__systolic8x8_tb__DOT__C53;
    vlSelfRef.systolic8x8_tb__DOT__C52 = __Vdly__systolic8x8_tb__DOT__C52;
    vlSelfRef.systolic8x8_tb__DOT__C51 = __Vdly__systolic8x8_tb__DOT__C51;
    vlSelfRef.systolic8x8_tb__DOT__C50 = __Vdly__systolic8x8_tb__DOT__C50;
    vlSelfRef.systolic8x8_tb__DOT__C47 = __Vdly__systolic8x8_tb__DOT__C47;
    vlSelfRef.systolic8x8_tb__DOT__C46 = __Vdly__systolic8x8_tb__DOT__C46;
    vlSelfRef.systolic8x8_tb__DOT__C45 = __Vdly__systolic8x8_tb__DOT__C45;
    vlSelfRef.systolic8x8_tb__DOT__C44 = __Vdly__systolic8x8_tb__DOT__C44;
    vlSelfRef.systolic8x8_tb__DOT__C43 = __Vdly__systolic8x8_tb__DOT__C43;
    vlSelfRef.systolic8x8_tb__DOT__C42 = __Vdly__systolic8x8_tb__DOT__C42;
    vlSelfRef.systolic8x8_tb__DOT__C41 = __Vdly__systolic8x8_tb__DOT__C41;
    vlSelfRef.systolic8x8_tb__DOT__C40 = __Vdly__systolic8x8_tb__DOT__C40;
    vlSelfRef.systolic8x8_tb__DOT__C37 = __Vdly__systolic8x8_tb__DOT__C37;
    vlSelfRef.systolic8x8_tb__DOT__C36 = __Vdly__systolic8x8_tb__DOT__C36;
    vlSelfRef.systolic8x8_tb__DOT__C35 = __Vdly__systolic8x8_tb__DOT__C35;
    vlSelfRef.systolic8x8_tb__DOT__C34 = __Vdly__systolic8x8_tb__DOT__C34;
    vlSelfRef.systolic8x8_tb__DOT__C33 = __Vdly__systolic8x8_tb__DOT__C33;
    vlSelfRef.systolic8x8_tb__DOT__C32 = __Vdly__systolic8x8_tb__DOT__C32;
    vlSelfRef.systolic8x8_tb__DOT__C31 = __Vdly__systolic8x8_tb__DOT__C31;
    vlSelfRef.systolic8x8_tb__DOT__C30 = __Vdly__systolic8x8_tb__DOT__C30;
    vlSelfRef.systolic8x8_tb__DOT__C27 = __Vdly__systolic8x8_tb__DOT__C27;
    vlSelfRef.systolic8x8_tb__DOT__C26 = __Vdly__systolic8x8_tb__DOT__C26;
    vlSelfRef.systolic8x8_tb__DOT__C25 = __Vdly__systolic8x8_tb__DOT__C25;
    vlSelfRef.systolic8x8_tb__DOT__C24 = __Vdly__systolic8x8_tb__DOT__C24;
    vlSelfRef.systolic8x8_tb__DOT__C23 = __Vdly__systolic8x8_tb__DOT__C23;
    vlSelfRef.systolic8x8_tb__DOT__C22 = __Vdly__systolic8x8_tb__DOT__C22;
    vlSelfRef.systolic8x8_tb__DOT__C21 = __Vdly__systolic8x8_tb__DOT__C21;
    vlSelfRef.systolic8x8_tb__DOT__C20 = __Vdly__systolic8x8_tb__DOT__C20;
    vlSelfRef.systolic8x8_tb__DOT__C17 = __Vdly__systolic8x8_tb__DOT__C17;
    vlSelfRef.systolic8x8_tb__DOT__C16 = __Vdly__systolic8x8_tb__DOT__C16;
    vlSelfRef.systolic8x8_tb__DOT__C15 = __Vdly__systolic8x8_tb__DOT__C15;
    vlSelfRef.systolic8x8_tb__DOT__C14 = __Vdly__systolic8x8_tb__DOT__C14;
    vlSelfRef.systolic8x8_tb__DOT__C13 = __Vdly__systolic8x8_tb__DOT__C13;
    vlSelfRef.systolic8x8_tb__DOT__C12 = __Vdly__systolic8x8_tb__DOT__C12;
    vlSelfRef.systolic8x8_tb__DOT__C11 = __Vdly__systolic8x8_tb__DOT__C11;
    vlSelfRef.systolic8x8_tb__DOT__C10 = __Vdly__systolic8x8_tb__DOT__C10;
    vlSelfRef.systolic8x8_tb__DOT__C07 = __Vdly__systolic8x8_tb__DOT__C07;
    vlSelfRef.systolic8x8_tb__DOT__C06 = __Vdly__systolic8x8_tb__DOT__C06;
    vlSelfRef.systolic8x8_tb__DOT__C05 = __Vdly__systolic8x8_tb__DOT__C05;
    vlSelfRef.systolic8x8_tb__DOT__C04 = __Vdly__systolic8x8_tb__DOT__C04;
    vlSelfRef.systolic8x8_tb__DOT__C03 = __Vdly__systolic8x8_tb__DOT__C03;
    vlSelfRef.systolic8x8_tb__DOT__C02 = __Vdly__systolic8x8_tb__DOT__C02;
    vlSelfRef.systolic8x8_tb__DOT__C01 = __Vdly__systolic8x8_tb__DOT__C01;
    vlSelfRef.systolic8x8_tb__DOT__C00 = __Vdly__systolic8x8_tb__DOT__C00;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][8U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe77__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[8U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe77__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe76__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[8U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe76__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe75__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[8U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe75__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe74__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[8U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe74__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe73__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[8U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe73__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe72__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[8U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe72__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe71__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[8U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe71__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[7U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe70__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[8U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe70__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][8U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe67__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe67__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe66__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe66__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe65__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe65__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe64__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe64__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe63__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe63__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe62__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe62__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe61__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe61__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[6U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe60__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[7U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe60__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][8U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe57__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe57__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe56__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe56__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe55__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe55__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe54__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe54__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe53__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe53__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe52__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe52__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe51__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe51__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[5U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe50__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[6U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe50__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][8U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe47__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe47__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe46__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe46__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe45__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe45__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe44__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe44__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe43__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe43__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe42__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe42__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe41__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe41__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[4U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe40__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[5U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe40__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][8U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe37__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe37__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe36__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe36__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe35__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe35__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe34__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe34__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe33__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe33__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe32__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe32__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe31__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe31__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[3U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe30__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[4U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe30__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][8U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe27__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe27__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe26__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe26__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe25__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe25__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe24__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe24__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe23__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe23__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe22__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe22__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe21__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe21__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[2U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe20__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[3U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe20__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][8U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe17__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe17__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe16__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe16__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe15__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe15__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe14__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe14__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe13__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe13__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe12__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe12__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe11__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe11__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[1U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe10__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[2U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe10__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][8U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe07__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe07__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][7U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe06__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe06__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][6U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe05__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe05__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][5U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe04__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe04__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][4U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe03__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe03__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][3U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe02__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe02__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][2U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe01__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe01__B_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__A_wire[0U][1U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe00__A_out;
    vlSelfRef.systolic8x8_tb__DOT__uut__DOT__B_wire[1U][0U] 
        = vlSelfRef.systolic8x8_tb__DOT__uut__DOT____Vcellout__pe00__B_out;
}

void Vsystolic8x8_tb___024root___timing_ready(Vsystolic8x8_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___timing_ready\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_had55cf4f__0.ready("@(posedge systolic8x8_tb.clk)");
    }
}

void Vsystolic8x8_tb___024root___timing_resume(Vsystolic8x8_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___timing_resume\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_had55cf4f__0.moveToResumeQueue(
                                                          "@(posedge systolic8x8_tb.clk)");
    vlSelfRef.__VtrigSched_had55cf4f__0.resume("@(posedge systolic8x8_tb.clk)");
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vsystolic8x8_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vsystolic8x8_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vsystolic8x8_tb___024root____VbeforeTrig_had55cf4f__0(Vsystolic8x8_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root____VbeforeTrig_had55cf4f__0\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((IData)(vlSelfRef.systolic8x8_tb__DOT__clk) 
                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__systolic8x8_tb__DOT__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__systolic8x8_tb__DOT__clk__0 
        = vlSelfRef.systolic8x8_tb__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_had55cf4f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_had55cf4f__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vsystolic8x8_tb___024root___eval_debug_assertions(Vsystolic8x8_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsystolic8x8_tb___024root___eval_debug_assertions\n"); );
    Vsystolic8x8_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
