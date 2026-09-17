// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontroller_tb.h for the primary calling header

#include "Vcontroller_tb__pch.h"

VL_ATTR_COLD void Vcontroller_tb___024root___eval_initial__TOP(Vcontroller_tb___024root* vlSelf);
VlCoroutine Vcontroller_tb___024root___eval_initial__TOP__Vtiming__0(Vcontroller_tb___024root* vlSelf);
VlCoroutine Vcontroller_tb___024root___eval_initial__TOP__Vtiming__1(Vcontroller_tb___024root* vlSelf);

void Vcontroller_tb___024root___eval_initial(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_initial\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vcontroller_tb___024root___eval_initial__TOP(vlSelf);
    Vcontroller_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vcontroller_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vcontroller_tb___024root___eval_sample(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_sample\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontroller_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vcontroller_tb___024root___eval_ico(Vcontroller_tb___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_ico\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcontroller_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vcontroller_tb___024root___timing_ready(Vcontroller_tb___024root* vlSelf);
void Vcontroller_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontroller_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vcontroller_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vcontroller_tb___024root___timing_resume(Vcontroller_tb___024root* vlSelf);
void Vcontroller_tb___024root___act_comb__TOP__0(Vcontroller_tb___024root* vlSelf);

bool Vcontroller_tb___024root___eval_act(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_act\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        (((((IData)(vlSelfRef.controller_tb__DOT__done) 
                                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__controller_tb__DOT__done__0)) 
                                                           << 3U) 
                                                          | (vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                             << 2U)) 
                                                         | ((((~ (IData)(vlSelfRef.controller_tb__DOT__rst_n)) 
                                                              & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__controller_tb__DOT__rst_n__0)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.controller_tb__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__controller_tb__DOT__clk__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__controller_tb__DOT__clk__0 
            = vlSelfRef.controller_tb__DOT__clk;
        vlSelfRef.__Vtrigprevexpr___TOP__controller_tb__DOT__rst_n__0 
            = vlSelfRef.controller_tb__DOT__rst_n;
        vlSelfRef.__Vtrigprevexpr___TOP__controller_tb__DOT__done__0 
            = vlSelfRef.controller_tb__DOT__done;
    }
    Vcontroller_tb___024root___timing_ready(vlSelf);
    Vcontroller_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcontroller_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vcontroller_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vcontroller_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vcontroller_tb___024root___timing_resume(vlSelf);
        {
            // Inlined CFunc: _eval_body__act
            if ((0x000000000000000dULL & vlSelfRef.__VactTriggered[0U])) {
                Vcontroller_tb___024root___act_comb__TOP__0(vlSelf);
            }
        }
    }
    return (__VactExecute);
}

bool Vcontroller_tb___024root___eval_inact(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_inact\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("controller_tb.v", 20, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vcontroller_tb___024root___nba_sequent__TOP__1(Vcontroller_tb___024root* vlSelf);
void Vcontroller_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vcontroller_tb___024root___eval_nba(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_nba\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vcontroller_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__0
                    vlSelfRef.__Vdly__controller_tb__DOT__uut__DOT__state 
                        = vlSelfRef.controller_tb__DOT__uut__DOT__state;
                }
            }
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vcontroller_tb___024root___nba_sequent__TOP__1(vlSelf);
            }
            if ((0x000000000000000dULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vcontroller_tb___024root___act_comb__TOP__0(vlSelf);
            }
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__2
                    if (vlSelfRef.controller_tb__DOT__rst_n) {
                        if ((2U & (IData)(vlSelfRef.controller_tb__DOT__uut__DOT__state))) {
                            if ((1U & (IData)(vlSelfRef.controller_tb__DOT__uut__DOT__state))) {
                                vlSelfRef.controller_tb__DOT__done = 1U;
                                vlSelfRef.controller_tb__DOT__busy = 0U;
                                vlSelfRef.controller_tb__DOT__uut__DOT__sys_reset = 0U;
                                vlSelfRef.controller_tb__DOT__uut__DOT__sys_enable = 0U;
                                vlSelfRef.__Vdly__controller_tb__DOT__uut__DOT__state = 0U;
                            } else {
                                vlSelfRef.controller_tb__DOT__cycle_count 
                                    = ((IData)(1U) 
                                       + vlSelfRef.controller_tb__DOT__cycle_count);
                                if ((0x16U == (IData)(vlSelfRef.controller_tb__DOT__uut__DOT__compute_counter))) {
                                    vlSelfRef.controller_tb__DOT__uut__DOT__sys_enable = 0U;
                                    vlSelfRef.__Vdly__controller_tb__DOT__uut__DOT__state = 3U;
                                } else {
                                    vlSelfRef.controller_tb__DOT__uut__DOT__compute_counter 
                                        = (0x0000001fU 
                                           & ((IData)(1U) 
                                              + (IData)(vlSelfRef.controller_tb__DOT__uut__DOT__compute_counter)));
                                }
                            }
                        } else if ((1U & (IData)(vlSelfRef.controller_tb__DOT__uut__DOT__state))) {
                            vlSelfRef.controller_tb__DOT__uut__DOT__compute_counter = 0U;
                            vlSelfRef.controller_tb__DOT__cycle_count = 0U;
                            vlSelfRef.controller_tb__DOT__uut__DOT__sys_reset = 0U;
                            vlSelfRef.controller_tb__DOT__uut__DOT__sys_enable = 1U;
                            vlSelfRef.__Vdly__controller_tb__DOT__uut__DOT__state = 2U;
                        } else {
                            vlSelfRef.controller_tb__DOT__done = 0U;
                            vlSelfRef.controller_tb__DOT__uut__DOT__sys_reset = 0U;
                            vlSelfRef.controller_tb__DOT__uut__DOT__sys_enable = 0U;
                            if (vlSelfRef.controller_tb__DOT__start) {
                                vlSelfRef.controller_tb__DOT__uut__DOT__compute_counter = 0U;
                                vlSelfRef.controller_tb__DOT__cycle_count = 0U;
                                vlSelfRef.controller_tb__DOT__busy = 1U;
                                vlSelfRef.controller_tb__DOT__uut__DOT__sys_reset = 1U;
                                vlSelfRef.controller_tb__DOT__uut__DOT__sys_enable = 0U;
                                vlSelfRef.__Vdly__controller_tb__DOT__uut__DOT__state = 1U;
                            }
                        }
                    } else {
                        vlSelfRef.controller_tb__DOT__uut__DOT__compute_counter = 0U;
                        vlSelfRef.controller_tb__DOT__cycle_count = 0U;
                        vlSelfRef.__Vdly__controller_tb__DOT__uut__DOT__state = 0U;
                        vlSelfRef.controller_tb__DOT__uut__DOT__sys_reset = 1U;
                        vlSelfRef.controller_tb__DOT__uut__DOT__sys_enable = 0U;
                        vlSelfRef.controller_tb__DOT__done = 0U;
                        vlSelfRef.controller_tb__DOT__busy = 0U;
                    }
                    vlSelfRef.controller_tb__DOT__uut__DOT__state 
                        = vlSelfRef.__Vdly__controller_tb__DOT__uut__DOT__state;
                }
            }
        }
        Vcontroller_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vcontroller_tb___024root___eval_obs(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_obs\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vcontroller_tb___024root___eval_react(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_react\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vcontroller_tb___024root___eval_postponed(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_postponed\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

extern const VlWide<16>/*511:0*/ Vcontroller_tb__ConstPool__CONST_h93e1b771_0;
void Vcontroller_tb___024root____VbeforeTrig_hee4b4f38__0(Vcontroller_tb___024root* vlSelf, const char* __VeventDescription);
void Vcontroller_tb___024root____VbeforeTrig_h06f34caf__0(Vcontroller_tb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vcontroller_tb___024root___eval_initial__TOP__Vtiming__0(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ controller_tb__DOT__errors;
    controller_tb__DOT__errors = 0;
    // Body
    vlSymsp->_vm_contextp__->dumpfile("controller.vcd"s);
    VL_PRINTF_MT("-Info: controller_tb.v:235: $dumpvar ignored, as Verilated without --trace\n");
    controller_tb__DOT__errors = 0U;
    VL_ASSIGN_W(512, vlSelfRef.controller_tb__DOT__A_flat, Vcontroller_tb__ConstPool__CONST_h93e1b771_0);
    VL_ASSIGN_W(512, vlSelfRef.controller_tb__DOT__B_flat, Vcontroller_tb__ConstPool__CONST_h93e1b771_0);
    vlSelfRef.controller_tb__DOT__A_flat[0U] = (1U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[0U]));
    vlSelfRef.controller_tb__DOT__B_flat[0U] = (1U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[0U]));
    vlSelfRef.controller_tb__DOT__A_flat[0U] = (0x00000200U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[0U]));
    vlSelfRef.controller_tb__DOT__B_flat[0U] = (0x00000200U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[0U]));
    vlSelfRef.controller_tb__DOT__A_flat[0U] = (0x00030000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[0U]));
    vlSelfRef.controller_tb__DOT__B_flat[0U] = (0x00030000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[0U]));
    vlSelfRef.controller_tb__DOT__A_flat[0U] = (0x04000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[0U]));
    vlSelfRef.controller_tb__DOT__B_flat[0U] = (0x04000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[0U]));
    vlSelfRef.controller_tb__DOT__A_flat[1U] = (5U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[1U]));
    vlSelfRef.controller_tb__DOT__B_flat[1U] = (5U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[1U]));
    vlSelfRef.controller_tb__DOT__A_flat[1U] = (0x00000600U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[1U]));
    vlSelfRef.controller_tb__DOT__B_flat[1U] = (0x00000600U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[1U]));
    vlSelfRef.controller_tb__DOT__A_flat[1U] = (0x00070000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[1U]));
    vlSelfRef.controller_tb__DOT__B_flat[1U] = (0x00070000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[1U]));
    vlSelfRef.controller_tb__DOT__A_flat[1U] = (0x08000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[1U]));
    vlSelfRef.controller_tb__DOT__B_flat[1U] = (0x08000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[1U]));
    vlSelfRef.controller_tb__DOT__A_flat[2U] = (2U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[2U]));
    vlSelfRef.controller_tb__DOT__B_flat[2U] = (2U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[2U]));
    vlSelfRef.controller_tb__DOT__A_flat[2U] = (0x00000300U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[2U]));
    vlSelfRef.controller_tb__DOT__B_flat[2U] = (0x00000300U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[2U]));
    vlSelfRef.controller_tb__DOT__A_flat[2U] = (0x00040000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[2U]));
    vlSelfRef.controller_tb__DOT__B_flat[2U] = (0x00040000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[2U]));
    vlSelfRef.controller_tb__DOT__A_flat[2U] = (0x05000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[2U]));
    vlSelfRef.controller_tb__DOT__B_flat[2U] = (0x05000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[2U]));
    vlSelfRef.controller_tb__DOT__A_flat[3U] = (6U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[3U]));
    vlSelfRef.controller_tb__DOT__B_flat[3U] = (6U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[3U]));
    vlSelfRef.controller_tb__DOT__A_flat[3U] = (0x00000700U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[3U]));
    vlSelfRef.controller_tb__DOT__B_flat[3U] = (0x00000700U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[3U]));
    vlSelfRef.controller_tb__DOT__A_flat[3U] = (0x00080000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[3U]));
    vlSelfRef.controller_tb__DOT__B_flat[3U] = (0x00080000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[3U]));
    vlSelfRef.controller_tb__DOT__A_flat[3U] = (0x09000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[3U]));
    vlSelfRef.controller_tb__DOT__B_flat[3U] = (0x09000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[3U]));
    vlSelfRef.controller_tb__DOT__A_flat[4U] = (3U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[4U]));
    vlSelfRef.controller_tb__DOT__B_flat[4U] = (3U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[4U]));
    vlSelfRef.controller_tb__DOT__A_flat[4U] = (0x00000400U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[4U]));
    vlSelfRef.controller_tb__DOT__B_flat[4U] = (0x00000400U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[4U]));
    vlSelfRef.controller_tb__DOT__A_flat[4U] = (0x00050000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[4U]));
    vlSelfRef.controller_tb__DOT__B_flat[4U] = (0x00050000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[4U]));
    vlSelfRef.controller_tb__DOT__A_flat[4U] = (0x06000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[4U]));
    vlSelfRef.controller_tb__DOT__B_flat[4U] = (0x06000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[4U]));
    vlSelfRef.controller_tb__DOT__A_flat[5U] = (7U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[5U]));
    vlSelfRef.controller_tb__DOT__B_flat[5U] = (7U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[5U]));
    vlSelfRef.controller_tb__DOT__A_flat[5U] = (0x00000800U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[5U]));
    vlSelfRef.controller_tb__DOT__B_flat[5U] = (0x00000800U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[5U]));
    vlSelfRef.controller_tb__DOT__A_flat[5U] = (0x00090000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[5U]));
    vlSelfRef.controller_tb__DOT__B_flat[5U] = (0x00090000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[5U]));
    vlSelfRef.controller_tb__DOT__A_flat[5U] = (0x0a000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[5U]));
    vlSelfRef.controller_tb__DOT__B_flat[5U] = (0x0a000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[5U]));
    vlSelfRef.controller_tb__DOT__A_flat[6U] = (4U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[6U]));
    vlSelfRef.controller_tb__DOT__B_flat[6U] = (4U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[6U]));
    vlSelfRef.controller_tb__DOT__A_flat[6U] = (0x00000500U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[6U]));
    vlSelfRef.controller_tb__DOT__B_flat[6U] = (0x00000500U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[6U]));
    vlSelfRef.controller_tb__DOT__A_flat[6U] = (0x00060000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[6U]));
    vlSelfRef.controller_tb__DOT__B_flat[6U] = (0x00060000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[6U]));
    vlSelfRef.controller_tb__DOT__A_flat[6U] = (0x07000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[6U]));
    vlSelfRef.controller_tb__DOT__B_flat[6U] = (0x07000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[6U]));
    vlSelfRef.controller_tb__DOT__A_flat[7U] = (8U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[7U]));
    vlSelfRef.controller_tb__DOT__B_flat[7U] = (8U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[7U]));
    vlSelfRef.controller_tb__DOT__A_flat[7U] = (0x00000900U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[7U]));
    vlSelfRef.controller_tb__DOT__B_flat[7U] = (0x00000900U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[7U]));
    vlSelfRef.controller_tb__DOT__A_flat[7U] = (0x000a0000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[7U]));
    vlSelfRef.controller_tb__DOT__B_flat[7U] = (0x000a0000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[7U]));
    vlSelfRef.controller_tb__DOT__A_flat[7U] = (0x0b000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[7U]));
    vlSelfRef.controller_tb__DOT__B_flat[7U] = (0x0b000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[7U]));
    vlSelfRef.controller_tb__DOT__A_flat[8U] = (5U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[8U]));
    vlSelfRef.controller_tb__DOT__B_flat[8U] = (5U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[8U]));
    vlSelfRef.controller_tb__DOT__A_flat[8U] = (0x00000600U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[8U]));
    vlSelfRef.controller_tb__DOT__B_flat[8U] = (0x00000600U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[8U]));
    vlSelfRef.controller_tb__DOT__A_flat[8U] = (0x00070000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[8U]));
    vlSelfRef.controller_tb__DOT__B_flat[8U] = (0x00070000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[8U]));
    vlSelfRef.controller_tb__DOT__A_flat[8U] = (0x08000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[8U]));
    vlSelfRef.controller_tb__DOT__B_flat[8U] = (0x08000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[8U]));
    vlSelfRef.controller_tb__DOT__A_flat[9U] = (9U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[9U]));
    vlSelfRef.controller_tb__DOT__B_flat[9U] = (9U 
                                                | (0xffffff00U 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[9U]));
    vlSelfRef.controller_tb__DOT__A_flat[9U] = (0x00000a00U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[9U]));
    vlSelfRef.controller_tb__DOT__B_flat[9U] = (0x00000a00U 
                                                | (0xffff00ffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[9U]));
    vlSelfRef.controller_tb__DOT__A_flat[9U] = (0x000b0000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[9U]));
    vlSelfRef.controller_tb__DOT__B_flat[9U] = (0x000b0000U 
                                                | (0xff00ffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[9U]));
    vlSelfRef.controller_tb__DOT__A_flat[9U] = (0x0c000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__A_flat[9U]));
    vlSelfRef.controller_tb__DOT__B_flat[9U] = (0x0c000000U 
                                                | (0x00ffffffU 
                                                   & vlSelfRef.controller_tb__DOT__B_flat[9U]));
    vlSelfRef.controller_tb__DOT__A_flat[10U] = (6U 
                                                 | (0xffffff00U 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[10U]));
    vlSelfRef.controller_tb__DOT__B_flat[10U] = (6U 
                                                 | (0xffffff00U 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[10U]));
    vlSelfRef.controller_tb__DOT__A_flat[10U] = (0x00000700U 
                                                 | (0xffff00ffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[10U]));
    vlSelfRef.controller_tb__DOT__B_flat[10U] = (0x00000700U 
                                                 | (0xffff00ffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[10U]));
    vlSelfRef.controller_tb__DOT__A_flat[10U] = (0x00080000U 
                                                 | (0xff00ffffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[10U]));
    vlSelfRef.controller_tb__DOT__B_flat[10U] = (0x00080000U 
                                                 | (0xff00ffffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[10U]));
    vlSelfRef.controller_tb__DOT__A_flat[10U] = (0x09000000U 
                                                 | (0x00ffffffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[10U]));
    vlSelfRef.controller_tb__DOT__B_flat[10U] = (0x09000000U 
                                                 | (0x00ffffffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[10U]));
    vlSelfRef.controller_tb__DOT__A_flat[11U] = (0x0aU 
                                                 | (0xffffff00U 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[11U]));
    vlSelfRef.controller_tb__DOT__B_flat[11U] = (0x0aU 
                                                 | (0xffffff00U 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[11U]));
    vlSelfRef.controller_tb__DOT__A_flat[11U] = (0x00000b00U 
                                                 | (0xffff00ffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[11U]));
    vlSelfRef.controller_tb__DOT__B_flat[11U] = (0x00000b00U 
                                                 | (0xffff00ffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[11U]));
    vlSelfRef.controller_tb__DOT__A_flat[11U] = (0x000c0000U 
                                                 | (0xff00ffffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[11U]));
    vlSelfRef.controller_tb__DOT__B_flat[11U] = (0x000c0000U 
                                                 | (0xff00ffffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[11U]));
    vlSelfRef.controller_tb__DOT__A_flat[11U] = (0x0d000000U 
                                                 | (0x00ffffffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[11U]));
    vlSelfRef.controller_tb__DOT__B_flat[11U] = (0x0d000000U 
                                                 | (0x00ffffffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[11U]));
    vlSelfRef.controller_tb__DOT__A_flat[12U] = (7U 
                                                 | (0xffffff00U 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[12U]));
    vlSelfRef.controller_tb__DOT__B_flat[12U] = (7U 
                                                 | (0xffffff00U 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[12U]));
    vlSelfRef.controller_tb__DOT__A_flat[12U] = (0x00000800U 
                                                 | (0xffff00ffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[12U]));
    vlSelfRef.controller_tb__DOT__B_flat[12U] = (0x00000800U 
                                                 | (0xffff00ffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[12U]));
    vlSelfRef.controller_tb__DOT__A_flat[12U] = (0x00090000U 
                                                 | (0xff00ffffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[12U]));
    vlSelfRef.controller_tb__DOT__B_flat[12U] = (0x00090000U 
                                                 | (0xff00ffffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[12U]));
    vlSelfRef.controller_tb__DOT__A_flat[12U] = (0x0a000000U 
                                                 | (0x00ffffffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[12U]));
    vlSelfRef.controller_tb__DOT__B_flat[12U] = (0x0a000000U 
                                                 | (0x00ffffffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[12U]));
    vlSelfRef.controller_tb__DOT__A_flat[13U] = (0x0bU 
                                                 | (0xffffff00U 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[13U]));
    vlSelfRef.controller_tb__DOT__B_flat[13U] = (0x0bU 
                                                 | (0xffffff00U 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[13U]));
    vlSelfRef.controller_tb__DOT__A_flat[13U] = (0x00000c00U 
                                                 | (0xffff00ffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[13U]));
    vlSelfRef.controller_tb__DOT__B_flat[13U] = (0x00000c00U 
                                                 | (0xffff00ffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[13U]));
    vlSelfRef.controller_tb__DOT__A_flat[13U] = (0x000d0000U 
                                                 | (0xff00ffffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[13U]));
    vlSelfRef.controller_tb__DOT__B_flat[13U] = (0x000d0000U 
                                                 | (0xff00ffffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[13U]));
    vlSelfRef.controller_tb__DOT__A_flat[13U] = (0x0e000000U 
                                                 | (0x00ffffffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[13U]));
    vlSelfRef.controller_tb__DOT__B_flat[13U] = (0x0e000000U 
                                                 | (0x00ffffffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[13U]));
    vlSelfRef.controller_tb__DOT__A_flat[14U] = (8U 
                                                 | (0xffffff00U 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[14U]));
    vlSelfRef.controller_tb__DOT__B_flat[14U] = (8U 
                                                 | (0xffffff00U 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[14U]));
    vlSelfRef.controller_tb__DOT__A_flat[14U] = (0x00000900U 
                                                 | (0xffff00ffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[14U]));
    vlSelfRef.controller_tb__DOT__B_flat[14U] = (0x00000900U 
                                                 | (0xffff00ffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[14U]));
    vlSelfRef.controller_tb__DOT__A_flat[14U] = (0x000a0000U 
                                                 | (0xff00ffffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[14U]));
    vlSelfRef.controller_tb__DOT__B_flat[14U] = (0x000a0000U 
                                                 | (0xff00ffffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[14U]));
    vlSelfRef.controller_tb__DOT__A_flat[14U] = (0x0b000000U 
                                                 | (0x00ffffffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[14U]));
    vlSelfRef.controller_tb__DOT__B_flat[14U] = (0x0b000000U 
                                                 | (0x00ffffffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[14U]));
    vlSelfRef.controller_tb__DOT__A_flat[15U] = (0x0cU 
                                                 | (0xffffff00U 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[15U]));
    vlSelfRef.controller_tb__DOT__B_flat[15U] = (0x0cU 
                                                 | (0xffffff00U 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[15U]));
    vlSelfRef.controller_tb__DOT__A_flat[15U] = (0x00000d00U 
                                                 | (0xffff00ffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[15U]));
    vlSelfRef.controller_tb__DOT__B_flat[15U] = (0x00000d00U 
                                                 | (0xffff00ffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[15U]));
    vlSelfRef.controller_tb__DOT__A_flat[15U] = (0x000e0000U 
                                                 | (0xff00ffffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[15U]));
    vlSelfRef.controller_tb__DOT__B_flat[15U] = (0x000e0000U 
                                                 | (0xff00ffffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[15U]));
    vlSelfRef.controller_tb__DOT__A_flat[15U] = (0x0f000000U 
                                                 | (0x00ffffffU 
                                                    & vlSelfRef.controller_tb__DOT__A_flat[15U]));
    vlSelfRef.controller_tb__DOT__B_flat[15U] = (0x0f000000U 
                                                 | (0x00ffffffU 
                                                    & vlSelfRef.controller_tb__DOT__B_flat[15U]));
    vlSelfRef.controller_tb__DOT__rst_n = 0U;
    vlSelfRef.controller_tb__DOT__start = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "controller_tb.v", 
                                         264);
    vlSelfRef.controller_tb__DOT__rst_n = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                         nullptr, "controller_tb.v", 
                                         266);
    VL_WRITEF_NX("\n==============================================\nTEST 1: Controller 8x8 Matrix Multiplication\n==============================================\n",0);
    Vcontroller_tb___024root____VbeforeTrig_hee4b4f38__0(vlSelf, 
                                                         "@(posedge controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hee4b4f38__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge controller_tb.clk)", 
                                                         "controller_tb.v", 
                                                         277);
    vlSelfRef.controller_tb__DOT__start = 1U;
    Vcontroller_tb___024root____VbeforeTrig_hee4b4f38__0(vlSelf, 
                                                         "@(posedge controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hee4b4f38__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge controller_tb.clk)", 
                                                         "controller_tb.v", 
                                                         280);
    vlSelfRef.controller_tb__DOT__start = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "controller_tb.v", 
                                         284);
    if (vlSelfRef.controller_tb__DOT__busy) {
        VL_WRITEF_NX("PASS: busy asserted\n",0);
    } else {
        VL_WRITEF_NX("FAIL: busy did not go high\n",0);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    }
    while ((1U & (~ (IData)(vlSelfRef.controller_tb__DOT__done)))) {
        Vcontroller_tb___024root____VbeforeTrig_h06f34caf__0(vlSelf, 
                                                             "@( controller_tb.done)");
        co_await vlSelfRef.__VtrigSched_h06f34caf__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( controller_tb.done)", 
                                                             "controller_tb.v", 
                                                             294);
    }
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "controller_tb.v", 
                                         295);
    VL_WRITEF_NX("Controller compute cycles = %0d\n",1
                 , '#',32,vlSelfRef.controller_tb__DOT__cycle_count);
    if ((0x00000017U != vlSelfRef.controller_tb__DOT__cycle_count)) {
        VL_WRITEF_NX("FAIL: cycle_count = %0d, expected 23\n",1
                     , '#',32,vlSelfRef.controller_tb__DOT__cycle_count);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS: cycle_count = 23\n",0);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[0U][0U] 
         != vlSelfRef.controller_tb__DOT__expected[0U][0U])) {
        VL_WRITEF_NX("FAIL C[0][0]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[0U][0U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[0U][0U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[0][0] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[0U][0U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[0U][1U] 
         != vlSelfRef.controller_tb__DOT__expected[0U][1U])) {
        VL_WRITEF_NX("FAIL C[0][1]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[0U][1U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[0U][1U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[0][1] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[0U][1U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[0U][2U] 
         != vlSelfRef.controller_tb__DOT__expected[0U][2U])) {
        VL_WRITEF_NX("FAIL C[0][2]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[0U][2U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[0U][2U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[0][2] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[0U][2U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[0U][3U] 
         != vlSelfRef.controller_tb__DOT__expected[0U][3U])) {
        VL_WRITEF_NX("FAIL C[0][3]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[0U][3U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[0U][3U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[0][3] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[0U][3U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[0U][4U] 
         != vlSelfRef.controller_tb__DOT__expected[0U][4U])) {
        VL_WRITEF_NX("FAIL C[0][4]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[0U][4U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[0U][4U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[0][4] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[0U][4U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[0U][5U] 
         != vlSelfRef.controller_tb__DOT__expected[0U][5U])) {
        VL_WRITEF_NX("FAIL C[0][5]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[0U][5U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[0U][5U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[0][5] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[0U][5U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[0U][6U] 
         != vlSelfRef.controller_tb__DOT__expected[0U][6U])) {
        VL_WRITEF_NX("FAIL C[0][6]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[0U][6U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[0U][6U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[0][6] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[0U][6U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[0U][7U] 
         != vlSelfRef.controller_tb__DOT__expected[0U][7U])) {
        VL_WRITEF_NX("FAIL C[0][7]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[0U][7U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[0U][7U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[0][7] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[0U][7U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[1U][0U] 
         != vlSelfRef.controller_tb__DOT__expected[1U][0U])) {
        VL_WRITEF_NX("FAIL C[1][0]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[1U][0U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[1U][0U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[1][0] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[1U][0U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[1U][1U] 
         != vlSelfRef.controller_tb__DOT__expected[1U][1U])) {
        VL_WRITEF_NX("FAIL C[1][1]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[1U][1U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[1U][1U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[1][1] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[1U][1U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[1U][2U] 
         != vlSelfRef.controller_tb__DOT__expected[1U][2U])) {
        VL_WRITEF_NX("FAIL C[1][2]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[1U][2U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[1U][2U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[1][2] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[1U][2U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[1U][3U] 
         != vlSelfRef.controller_tb__DOT__expected[1U][3U])) {
        VL_WRITEF_NX("FAIL C[1][3]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[1U][3U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[1U][3U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[1][3] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[1U][3U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[1U][4U] 
         != vlSelfRef.controller_tb__DOT__expected[1U][4U])) {
        VL_WRITEF_NX("FAIL C[1][4]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[1U][4U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[1U][4U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[1][4] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[1U][4U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[1U][5U] 
         != vlSelfRef.controller_tb__DOT__expected[1U][5U])) {
        VL_WRITEF_NX("FAIL C[1][5]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[1U][5U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[1U][5U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[1][5] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[1U][5U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[1U][6U] 
         != vlSelfRef.controller_tb__DOT__expected[1U][6U])) {
        VL_WRITEF_NX("FAIL C[1][6]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[1U][6U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[1U][6U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[1][6] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[1U][6U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[1U][7U] 
         != vlSelfRef.controller_tb__DOT__expected[1U][7U])) {
        VL_WRITEF_NX("FAIL C[1][7]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[1U][7U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[1U][7U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[1][7] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[1U][7U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[2U][0U] 
         != vlSelfRef.controller_tb__DOT__expected[2U][0U])) {
        VL_WRITEF_NX("FAIL C[2][0]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[2U][0U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[2U][0U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[2][0] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[2U][0U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[2U][1U] 
         != vlSelfRef.controller_tb__DOT__expected[2U][1U])) {
        VL_WRITEF_NX("FAIL C[2][1]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[2U][1U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[2U][1U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[2][1] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[2U][1U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[2U][2U] 
         != vlSelfRef.controller_tb__DOT__expected[2U][2U])) {
        VL_WRITEF_NX("FAIL C[2][2]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[2U][2U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[2U][2U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[2][2] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[2U][2U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[2U][3U] 
         != vlSelfRef.controller_tb__DOT__expected[2U][3U])) {
        VL_WRITEF_NX("FAIL C[2][3]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[2U][3U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[2U][3U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[2][3] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[2U][3U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[2U][4U] 
         != vlSelfRef.controller_tb__DOT__expected[2U][4U])) {
        VL_WRITEF_NX("FAIL C[2][4]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[2U][4U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[2U][4U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[2][4] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[2U][4U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[2U][5U] 
         != vlSelfRef.controller_tb__DOT__expected[2U][5U])) {
        VL_WRITEF_NX("FAIL C[2][5]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[2U][5U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[2U][5U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[2][5] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[2U][5U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[2U][6U] 
         != vlSelfRef.controller_tb__DOT__expected[2U][6U])) {
        VL_WRITEF_NX("FAIL C[2][6]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[2U][6U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[2U][6U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[2][6] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[2U][6U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[2U][7U] 
         != vlSelfRef.controller_tb__DOT__expected[2U][7U])) {
        VL_WRITEF_NX("FAIL C[2][7]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[2U][7U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[2U][7U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[2][7] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[2U][7U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[3U][0U] 
         != vlSelfRef.controller_tb__DOT__expected[3U][0U])) {
        VL_WRITEF_NX("FAIL C[3][0]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[3U][0U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[3U][0U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[3][0] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[3U][0U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[3U][1U] 
         != vlSelfRef.controller_tb__DOT__expected[3U][1U])) {
        VL_WRITEF_NX("FAIL C[3][1]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[3U][1U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[3U][1U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[3][1] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[3U][1U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[3U][2U] 
         != vlSelfRef.controller_tb__DOT__expected[3U][2U])) {
        VL_WRITEF_NX("FAIL C[3][2]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[3U][2U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[3U][2U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[3][2] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[3U][2U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[3U][3U] 
         != vlSelfRef.controller_tb__DOT__expected[3U][3U])) {
        VL_WRITEF_NX("FAIL C[3][3]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[3U][3U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[3U][3U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[3][3] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[3U][3U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[3U][4U] 
         != vlSelfRef.controller_tb__DOT__expected[3U][4U])) {
        VL_WRITEF_NX("FAIL C[3][4]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[3U][4U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[3U][4U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[3][4] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[3U][4U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[3U][5U] 
         != vlSelfRef.controller_tb__DOT__expected[3U][5U])) {
        VL_WRITEF_NX("FAIL C[3][5]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[3U][5U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[3U][5U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[3][5] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[3U][5U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[3U][6U] 
         != vlSelfRef.controller_tb__DOT__expected[3U][6U])) {
        VL_WRITEF_NX("FAIL C[3][6]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[3U][6U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[3U][6U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[3][6] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[3U][6U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[3U][7U] 
         != vlSelfRef.controller_tb__DOT__expected[3U][7U])) {
        VL_WRITEF_NX("FAIL C[3][7]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[3U][7U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[3U][7U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[3][7] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[3U][7U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[4U][0U] 
         != vlSelfRef.controller_tb__DOT__expected[4U][0U])) {
        VL_WRITEF_NX("FAIL C[4][0]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[4U][0U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[4U][0U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[4][0] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[4U][0U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[4U][1U] 
         != vlSelfRef.controller_tb__DOT__expected[4U][1U])) {
        VL_WRITEF_NX("FAIL C[4][1]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[4U][1U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[4U][1U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[4][1] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[4U][1U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[4U][2U] 
         != vlSelfRef.controller_tb__DOT__expected[4U][2U])) {
        VL_WRITEF_NX("FAIL C[4][2]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[4U][2U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[4U][2U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[4][2] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[4U][2U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[4U][3U] 
         != vlSelfRef.controller_tb__DOT__expected[4U][3U])) {
        VL_WRITEF_NX("FAIL C[4][3]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[4U][3U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[4U][3U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[4][3] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[4U][3U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[4U][4U] 
         != vlSelfRef.controller_tb__DOT__expected[4U][4U])) {
        VL_WRITEF_NX("FAIL C[4][4]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[4U][4U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[4U][4U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[4][4] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[4U][4U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[4U][5U] 
         != vlSelfRef.controller_tb__DOT__expected[4U][5U])) {
        VL_WRITEF_NX("FAIL C[4][5]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[4U][5U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[4U][5U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[4][5] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[4U][5U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[4U][6U] 
         != vlSelfRef.controller_tb__DOT__expected[4U][6U])) {
        VL_WRITEF_NX("FAIL C[4][6]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[4U][6U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[4U][6U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[4][6] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[4U][6U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[4U][7U] 
         != vlSelfRef.controller_tb__DOT__expected[4U][7U])) {
        VL_WRITEF_NX("FAIL C[4][7]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[4U][7U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[4U][7U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[4][7] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[4U][7U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[5U][0U] 
         != vlSelfRef.controller_tb__DOT__expected[5U][0U])) {
        VL_WRITEF_NX("FAIL C[5][0]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[5U][0U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[5U][0U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[5][0] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[5U][0U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[5U][1U] 
         != vlSelfRef.controller_tb__DOT__expected[5U][1U])) {
        VL_WRITEF_NX("FAIL C[5][1]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[5U][1U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[5U][1U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[5][1] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[5U][1U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[5U][2U] 
         != vlSelfRef.controller_tb__DOT__expected[5U][2U])) {
        VL_WRITEF_NX("FAIL C[5][2]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[5U][2U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[5U][2U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[5][2] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[5U][2U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[5U][3U] 
         != vlSelfRef.controller_tb__DOT__expected[5U][3U])) {
        VL_WRITEF_NX("FAIL C[5][3]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[5U][3U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[5U][3U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[5][3] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[5U][3U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[5U][4U] 
         != vlSelfRef.controller_tb__DOT__expected[5U][4U])) {
        VL_WRITEF_NX("FAIL C[5][4]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[5U][4U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[5U][4U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[5][4] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[5U][4U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[5U][5U] 
         != vlSelfRef.controller_tb__DOT__expected[5U][5U])) {
        VL_WRITEF_NX("FAIL C[5][5]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[5U][5U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[5U][5U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[5][5] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[5U][5U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[5U][6U] 
         != vlSelfRef.controller_tb__DOT__expected[5U][6U])) {
        VL_WRITEF_NX("FAIL C[5][6]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[5U][6U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[5U][6U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[5][6] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[5U][6U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[5U][7U] 
         != vlSelfRef.controller_tb__DOT__expected[5U][7U])) {
        VL_WRITEF_NX("FAIL C[5][7]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[5U][7U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[5U][7U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[5][7] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[5U][7U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[6U][0U] 
         != vlSelfRef.controller_tb__DOT__expected[6U][0U])) {
        VL_WRITEF_NX("FAIL C[6][0]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[6U][0U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[6U][0U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[6][0] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[6U][0U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[6U][1U] 
         != vlSelfRef.controller_tb__DOT__expected[6U][1U])) {
        VL_WRITEF_NX("FAIL C[6][1]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[6U][1U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[6U][1U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[6][1] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[6U][1U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[6U][2U] 
         != vlSelfRef.controller_tb__DOT__expected[6U][2U])) {
        VL_WRITEF_NX("FAIL C[6][2]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[6U][2U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[6U][2U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[6][2] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[6U][2U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[6U][3U] 
         != vlSelfRef.controller_tb__DOT__expected[6U][3U])) {
        VL_WRITEF_NX("FAIL C[6][3]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[6U][3U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[6U][3U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[6][3] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[6U][3U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[6U][4U] 
         != vlSelfRef.controller_tb__DOT__expected[6U][4U])) {
        VL_WRITEF_NX("FAIL C[6][4]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[6U][4U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[6U][4U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[6][4] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[6U][4U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[6U][5U] 
         != vlSelfRef.controller_tb__DOT__expected[6U][5U])) {
        VL_WRITEF_NX("FAIL C[6][5]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[6U][5U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[6U][5U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[6][5] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[6U][5U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[6U][6U] 
         != vlSelfRef.controller_tb__DOT__expected[6U][6U])) {
        VL_WRITEF_NX("FAIL C[6][6]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[6U][6U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[6U][6U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[6][6] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[6U][6U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[6U][7U] 
         != vlSelfRef.controller_tb__DOT__expected[6U][7U])) {
        VL_WRITEF_NX("FAIL C[6][7]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[6U][7U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[6U][7U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[6][7] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[6U][7U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[7U][0U] 
         != vlSelfRef.controller_tb__DOT__expected[7U][0U])) {
        VL_WRITEF_NX("FAIL C[7][0]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[7U][0U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[7U][0U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[7][0] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[7U][0U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[7U][1U] 
         != vlSelfRef.controller_tb__DOT__expected[7U][1U])) {
        VL_WRITEF_NX("FAIL C[7][1]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[7U][1U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[7U][1U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[7][1] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[7U][1U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[7U][2U] 
         != vlSelfRef.controller_tb__DOT__expected[7U][2U])) {
        VL_WRITEF_NX("FAIL C[7][2]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[7U][2U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[7U][2U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[7][2] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[7U][2U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[7U][3U] 
         != vlSelfRef.controller_tb__DOT__expected[7U][3U])) {
        VL_WRITEF_NX("FAIL C[7][3]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[7U][3U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[7U][3U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[7][3] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[7U][3U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[7U][4U] 
         != vlSelfRef.controller_tb__DOT__expected[7U][4U])) {
        VL_WRITEF_NX("FAIL C[7][4]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[7U][4U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[7U][4U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[7][4] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[7U][4U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[7U][5U] 
         != vlSelfRef.controller_tb__DOT__expected[7U][5U])) {
        VL_WRITEF_NX("FAIL C[7][5]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[7U][5U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[7U][5U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[7][5] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[7U][5U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[7U][6U] 
         != vlSelfRef.controller_tb__DOT__expected[7U][6U])) {
        VL_WRITEF_NX("FAIL C[7][6]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[7U][6U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[7U][6U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[7][6] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[7U][6U]);
    }
    if ((vlSelfRef.controller_tb__DOT__actual[7U][7U] 
         != vlSelfRef.controller_tb__DOT__expected[7U][7U])) {
        VL_WRITEF_NX("FAIL C[7][7]: got %0d, expected %0d\n",2
                     , '#',32,vlSelfRef.controller_tb__DOT__actual[7U][7U]
                     , '#',32,vlSelfRef.controller_tb__DOT__expected[7U][7U]);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C[7][7] = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__actual[7U][7U]);
    }
    VL_WRITEF_NX("\n==============================================\nTEST 2: Re-run Same 8x8 Matrix\n==============================================\n",0);
    Vcontroller_tb___024root____VbeforeTrig_hee4b4f38__0(vlSelf, 
                                                         "@(posedge controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hee4b4f38__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge controller_tb.clk)", 
                                                         "controller_tb.v", 
                                                         339);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "controller_tb.v", 
                                         340);
    Vcontroller_tb___024root____VbeforeTrig_hee4b4f38__0(vlSelf, 
                                                         "@(posedge controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hee4b4f38__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge controller_tb.clk)", 
                                                         "controller_tb.v", 
                                                         342);
    vlSelfRef.controller_tb__DOT__start = 1U;
    Vcontroller_tb___024root____VbeforeTrig_hee4b4f38__0(vlSelf, 
                                                         "@(posedge controller_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hee4b4f38__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge controller_tb.clk)", 
                                                         "controller_tb.v", 
                                                         345);
    vlSelfRef.controller_tb__DOT__start = 0U;
    while ((1U & (~ (IData)(vlSelfRef.controller_tb__DOT__done)))) {
        Vcontroller_tb___024root____VbeforeTrig_h06f34caf__0(vlSelf, 
                                                             "@( controller_tb.done)");
        co_await vlSelfRef.__VtrigSched_h06f34caf__0.trigger(1U, 
                                                             nullptr, 
                                                             "@( controller_tb.done)", 
                                                             "controller_tb.v", 
                                                             348);
    }
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "controller_tb.v", 
                                         349);
    VL_WRITEF_NX("Second compute cycles = %0d\n",1, '#',32,vlSelfRef.controller_tb__DOT__cycle_count);
    if ((0x00000017U != vlSelfRef.controller_tb__DOT__cycle_count)) {
        VL_WRITEF_NX("FAIL: second cycle_count = %0d, expected 23\n",1
                     , '#',32,vlSelfRef.controller_tb__DOT__cycle_count);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS: second cycle_count = 23\n",0);
    }
    if ((0x000000ccU != vlSelfRef.controller_tb__DOT__C00)) {
        VL_WRITEF_NX("FAIL C00 (second run): got %0d, expected 204\n",1
                     , '#',32,vlSelfRef.controller_tb__DOT__C00);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C00 (second run) = %0d\n",1
                     , '#',32,vlSelfRef.controller_tb__DOT__C00);
    }
    if ((0x0000044cU != vlSelfRef.controller_tb__DOT__C77)) {
        VL_WRITEF_NX("FAIL C77 (second run): got %0d, expected 1100\n",1
                     , '#',32,vlSelfRef.controller_tb__DOT__C77);
        controller_tb__DOT__errors = ((IData)(1U) + controller_tb__DOT__errors);
    } else {
        VL_WRITEF_NX("PASS C77 (second run) = %0d\n",1
                     , '#',32,vlSelfRef.controller_tb__DOT__C77);
    }
    VL_WRITEF_NX("\n",0);
    if ((0U == controller_tb__DOT__errors)) {
        VL_WRITEF_NX("==============================================\nALL CONTROLLER TESTS PASSED\n==============================================\n",0);
    } else {
        VL_WRITEF_NX("==============================================\n%0d TEST(S) FAILED\n==============================================\n",1
                     , '~',32,controller_tb__DOT__errors);
    }
    VL_FINISH_MT("controller_tb.v", 394, "");
    co_return;
}

VlCoroutine Vcontroller_tb___024root___eval_initial__TOP__Vtiming__1(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "controller_tb.v", 
                                             89);
        vlSelfRef.controller_tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.controller_tb__DOT__clk)));
    }
    co_return;
}

bool Vcontroller_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___trigger_anySet__ico\n"); );
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

bool Vcontroller_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___trigger_anySet__act\n"); );
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

void Vcontroller_tb___024root___act_comb__TOP__0(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___act_comb__TOP__0\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[0U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[0U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[0U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[0U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[0U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[0U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[0U][3U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[0U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[0U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[1U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[0U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[1U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[0U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[1U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[0U][7U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[1U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[1U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[2U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[1U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[2U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[1U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[2U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[1U][3U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[2U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[1U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[3U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[1U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[3U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[1U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[3U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[1U][7U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[3U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[2U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[4U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[2U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[4U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[2U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[4U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[2U][3U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[4U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[2U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[5U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[2U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[5U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[2U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[5U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[2U][7U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[5U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[3U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[6U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[3U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[6U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[3U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[6U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[3U][3U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[6U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[3U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[7U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[3U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[7U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[3U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[7U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[3U][7U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[7U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[4U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[8U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[4U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[8U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[4U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[8U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[4U][3U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[8U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[4U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[9U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[4U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[9U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[4U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[9U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[4U][7U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[9U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[5U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[10U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[5U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[10U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[5U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[10U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[5U][3U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[10U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[5U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[11U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[5U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[11U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[5U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[11U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[5U][7U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[11U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[6U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[12U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[6U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[12U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[6U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[12U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[6U][3U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[12U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[6U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[13U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[6U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[13U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[6U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[13U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[6U][7U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[13U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[7U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[14U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[7U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[14U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[7U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[14U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[7U][3U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[14U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[7U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__A_flat[15U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[7U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[15U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[7U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__A_flat[15U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[7U][7U] 
        = (vlSelfRef.controller_tb__DOT__A_flat[15U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[0U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[0U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[0U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[0U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[0U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[0U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[0U][3U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[0U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[0U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[1U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[0U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[1U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[0U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[1U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[0U][7U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[1U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[1U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[2U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[1U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[2U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[1U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[2U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[1U][3U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[2U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[1U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[3U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[1U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[3U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[1U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[3U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[1U][7U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[3U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[2U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[4U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[2U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[4U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[2U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[4U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[2U][3U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[4U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[2U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[5U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[2U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[5U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[2U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[5U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[2U][7U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[5U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[3U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[6U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[3U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[6U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[3U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[6U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[3U][3U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[6U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[3U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[7U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[3U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[7U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[3U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[7U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[3U][7U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[7U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[4U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[8U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[4U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[8U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[4U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[8U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[4U][3U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[8U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[4U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[9U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[4U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[9U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[4U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[9U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[4U][7U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[9U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[5U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[10U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[5U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[10U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[5U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[10U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[5U][3U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[10U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[5U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[11U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[5U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[11U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[5U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[11U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[5U][7U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[11U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[6U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[12U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[6U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[12U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[6U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[12U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[6U][3U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[12U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[6U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[13U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[6U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[13U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[6U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[13U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[6U][7U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[13U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[7U][0U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[14U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[7U][1U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[14U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[7U][2U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[14U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[7U][3U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[14U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[7U][4U] 
        = (0x000000ffU & vlSelfRef.controller_tb__DOT__B_flat[15U]);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[7U][5U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[15U] 
                          >> 8U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[7U][6U] 
        = (0x000000ffU & (vlSelfRef.controller_tb__DOT__B_flat[15U] 
                          >> 0x00000010U));
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix[7U][7U] 
        = (vlSelfRef.controller_tb__DOT__B_flat[15U] 
           >> 0x00000018U);
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[0U] = 0U;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[1U] = 0U;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[2U] = 0U;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[3U] = 0U;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[4U] = 0U;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[5U] = 0U;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[6U] = 0U;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[7U] = 0U;
    if ((VL_LTES_III(32, 0U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 8U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle))) {
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[0U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[0U]
            [(7U & vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle)];
    }
    if ((VL_LTES_III(32, 1U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 9U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle))) {
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[1U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[1U]
            [(7U & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle 
                    - (IData)(1U)))];
    }
    if ((VL_LTES_III(32, 2U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000aU, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle))) {
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[2U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[2U]
            [(7U & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle 
                    - (IData)(2U)))];
    }
    if ((VL_LTES_III(32, 3U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000bU, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle))) {
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[3U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[3U]
            [(7U & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle 
                    - (IData)(3U)))];
    }
    if ((VL_LTES_III(32, 4U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000cU, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle))) {
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[4U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[4U]
            [(7U & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle 
                    - (IData)(4U)))];
    }
    if ((VL_LTES_III(32, 5U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000dU, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle))) {
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[5U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[5U]
            [(7U & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle 
                    - (IData)(5U)))];
    }
    if ((VL_LTES_III(32, 6U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000eU, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle))) {
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[6U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[6U]
            [(7U & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle 
                    - (IData)(6U)))];
    }
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[0U] = 0U;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[1U] = 0U;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[2U] = 0U;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[3U] = 0U;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[4U] = 0U;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[5U] = 0U;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[6U] = 0U;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[7U] = 0U;
    if ((VL_LTES_III(32, 0U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 8U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle))) {
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[0U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix
            [(7U & vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle)][0U];
    }
    if ((VL_LTES_III(32, 1U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 9U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle))) {
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[1U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix
            [(7U & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle 
                    - (IData)(1U)))][1U];
    }
    if ((VL_LTES_III(32, 2U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000aU, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle))) {
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[2U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix
            [(7U & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle 
                    - (IData)(2U)))][2U];
    }
    if ((VL_LTES_III(32, 3U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000bU, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle))) {
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[3U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix
            [(7U & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle 
                    - (IData)(3U)))][3U];
    }
    if ((VL_LTES_III(32, 4U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000cU, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle))) {
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[4U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix
            [(7U & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle 
                    - (IData)(4U)))][4U];
    }
    if ((VL_LTES_III(32, 5U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000dU, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle))) {
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[5U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix
            [(7U & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle 
                    - (IData)(5U)))][5U];
    }
    if ((VL_LTES_III(32, 6U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000eU, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle))) {
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[6U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix
            [(7U & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle 
                    - (IData)(6U)))][6U];
    }
    if ((VL_LTES_III(32, 7U, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle) 
         & VL_GTS_III(32, 0x0000000fU, vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle))) {
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[7U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_matrix[7U]
            [(7U & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle 
                    - (IData)(7U)))];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[7U] 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_matrix
            [(7U & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle 
                    - (IData)(7U)))][7U];
    }
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[0U];
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[1U];
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[2U];
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[3U];
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[4U];
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[5U];
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[6U];
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_feed[7U];
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[0U];
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[1U];
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[2U];
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[3U];
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[4U];
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[5U];
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[6U];
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_feed[7U];
}

void Vcontroller_tb___024root___nba_sequent__TOP__1(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___nba_sequent__TOP__1\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__controller_tb__DOT__uut__DOT__array__DOT__cycle;
    __Vdly__controller_tb__DOT__uut__DOT__array__DOT__cycle = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C77;
    __Vdly__controller_tb__DOT__C77 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C76;
    __Vdly__controller_tb__DOT__C76 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C75;
    __Vdly__controller_tb__DOT__C75 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C74;
    __Vdly__controller_tb__DOT__C74 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C73;
    __Vdly__controller_tb__DOT__C73 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C72;
    __Vdly__controller_tb__DOT__C72 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C71;
    __Vdly__controller_tb__DOT__C71 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C70;
    __Vdly__controller_tb__DOT__C70 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C67;
    __Vdly__controller_tb__DOT__C67 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C66;
    __Vdly__controller_tb__DOT__C66 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C65;
    __Vdly__controller_tb__DOT__C65 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C64;
    __Vdly__controller_tb__DOT__C64 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C63;
    __Vdly__controller_tb__DOT__C63 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C62;
    __Vdly__controller_tb__DOT__C62 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C61;
    __Vdly__controller_tb__DOT__C61 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C60;
    __Vdly__controller_tb__DOT__C60 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C57;
    __Vdly__controller_tb__DOT__C57 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C56;
    __Vdly__controller_tb__DOT__C56 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C55;
    __Vdly__controller_tb__DOT__C55 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C54;
    __Vdly__controller_tb__DOT__C54 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C53;
    __Vdly__controller_tb__DOT__C53 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C52;
    __Vdly__controller_tb__DOT__C52 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C51;
    __Vdly__controller_tb__DOT__C51 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C50;
    __Vdly__controller_tb__DOT__C50 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C47;
    __Vdly__controller_tb__DOT__C47 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C46;
    __Vdly__controller_tb__DOT__C46 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C45;
    __Vdly__controller_tb__DOT__C45 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C44;
    __Vdly__controller_tb__DOT__C44 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C43;
    __Vdly__controller_tb__DOT__C43 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C42;
    __Vdly__controller_tb__DOT__C42 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C41;
    __Vdly__controller_tb__DOT__C41 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C40;
    __Vdly__controller_tb__DOT__C40 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C37;
    __Vdly__controller_tb__DOT__C37 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C36;
    __Vdly__controller_tb__DOT__C36 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C35;
    __Vdly__controller_tb__DOT__C35 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C34;
    __Vdly__controller_tb__DOT__C34 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C33;
    __Vdly__controller_tb__DOT__C33 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C32;
    __Vdly__controller_tb__DOT__C32 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C31;
    __Vdly__controller_tb__DOT__C31 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C30;
    __Vdly__controller_tb__DOT__C30 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C27;
    __Vdly__controller_tb__DOT__C27 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C26;
    __Vdly__controller_tb__DOT__C26 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C25;
    __Vdly__controller_tb__DOT__C25 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C24;
    __Vdly__controller_tb__DOT__C24 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C23;
    __Vdly__controller_tb__DOT__C23 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C22;
    __Vdly__controller_tb__DOT__C22 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C21;
    __Vdly__controller_tb__DOT__C21 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C20;
    __Vdly__controller_tb__DOT__C20 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C17;
    __Vdly__controller_tb__DOT__C17 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C16;
    __Vdly__controller_tb__DOT__C16 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C15;
    __Vdly__controller_tb__DOT__C15 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C14;
    __Vdly__controller_tb__DOT__C14 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C13;
    __Vdly__controller_tb__DOT__C13 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C12;
    __Vdly__controller_tb__DOT__C12 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C11;
    __Vdly__controller_tb__DOT__C11 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C10;
    __Vdly__controller_tb__DOT__C10 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C07;
    __Vdly__controller_tb__DOT__C07 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C06;
    __Vdly__controller_tb__DOT__C06 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C05;
    __Vdly__controller_tb__DOT__C05 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C04;
    __Vdly__controller_tb__DOT__C04 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C03;
    __Vdly__controller_tb__DOT__C03 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C02;
    __Vdly__controller_tb__DOT__C02 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C01;
    __Vdly__controller_tb__DOT__C01 = 0;
    IData/*31:0*/ __Vdly__controller_tb__DOT__C00;
    __Vdly__controller_tb__DOT__C00 = 0;
    // Body
    __Vdly__controller_tb__DOT__uut__DOT__array__DOT__cycle 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle;
    __Vdly__controller_tb__DOT__C77 = vlSelfRef.controller_tb__DOT__C77;
    __Vdly__controller_tb__DOT__C76 = vlSelfRef.controller_tb__DOT__C76;
    __Vdly__controller_tb__DOT__C75 = vlSelfRef.controller_tb__DOT__C75;
    __Vdly__controller_tb__DOT__C74 = vlSelfRef.controller_tb__DOT__C74;
    __Vdly__controller_tb__DOT__C73 = vlSelfRef.controller_tb__DOT__C73;
    __Vdly__controller_tb__DOT__C72 = vlSelfRef.controller_tb__DOT__C72;
    __Vdly__controller_tb__DOT__C71 = vlSelfRef.controller_tb__DOT__C71;
    __Vdly__controller_tb__DOT__C70 = vlSelfRef.controller_tb__DOT__C70;
    __Vdly__controller_tb__DOT__C67 = vlSelfRef.controller_tb__DOT__C67;
    __Vdly__controller_tb__DOT__C66 = vlSelfRef.controller_tb__DOT__C66;
    __Vdly__controller_tb__DOT__C65 = vlSelfRef.controller_tb__DOT__C65;
    __Vdly__controller_tb__DOT__C64 = vlSelfRef.controller_tb__DOT__C64;
    __Vdly__controller_tb__DOT__C63 = vlSelfRef.controller_tb__DOT__C63;
    __Vdly__controller_tb__DOT__C62 = vlSelfRef.controller_tb__DOT__C62;
    __Vdly__controller_tb__DOT__C61 = vlSelfRef.controller_tb__DOT__C61;
    __Vdly__controller_tb__DOT__C60 = vlSelfRef.controller_tb__DOT__C60;
    __Vdly__controller_tb__DOT__C57 = vlSelfRef.controller_tb__DOT__C57;
    __Vdly__controller_tb__DOT__C56 = vlSelfRef.controller_tb__DOT__C56;
    __Vdly__controller_tb__DOT__C55 = vlSelfRef.controller_tb__DOT__C55;
    __Vdly__controller_tb__DOT__C54 = vlSelfRef.controller_tb__DOT__C54;
    __Vdly__controller_tb__DOT__C53 = vlSelfRef.controller_tb__DOT__C53;
    __Vdly__controller_tb__DOT__C52 = vlSelfRef.controller_tb__DOT__C52;
    __Vdly__controller_tb__DOT__C51 = vlSelfRef.controller_tb__DOT__C51;
    __Vdly__controller_tb__DOT__C50 = vlSelfRef.controller_tb__DOT__C50;
    __Vdly__controller_tb__DOT__C47 = vlSelfRef.controller_tb__DOT__C47;
    __Vdly__controller_tb__DOT__C46 = vlSelfRef.controller_tb__DOT__C46;
    __Vdly__controller_tb__DOT__C45 = vlSelfRef.controller_tb__DOT__C45;
    __Vdly__controller_tb__DOT__C44 = vlSelfRef.controller_tb__DOT__C44;
    __Vdly__controller_tb__DOT__C43 = vlSelfRef.controller_tb__DOT__C43;
    __Vdly__controller_tb__DOT__C42 = vlSelfRef.controller_tb__DOT__C42;
    __Vdly__controller_tb__DOT__C41 = vlSelfRef.controller_tb__DOT__C41;
    __Vdly__controller_tb__DOT__C40 = vlSelfRef.controller_tb__DOT__C40;
    __Vdly__controller_tb__DOT__C37 = vlSelfRef.controller_tb__DOT__C37;
    __Vdly__controller_tb__DOT__C36 = vlSelfRef.controller_tb__DOT__C36;
    __Vdly__controller_tb__DOT__C35 = vlSelfRef.controller_tb__DOT__C35;
    __Vdly__controller_tb__DOT__C34 = vlSelfRef.controller_tb__DOT__C34;
    __Vdly__controller_tb__DOT__C33 = vlSelfRef.controller_tb__DOT__C33;
    __Vdly__controller_tb__DOT__C32 = vlSelfRef.controller_tb__DOT__C32;
    __Vdly__controller_tb__DOT__C31 = vlSelfRef.controller_tb__DOT__C31;
    __Vdly__controller_tb__DOT__C30 = vlSelfRef.controller_tb__DOT__C30;
    __Vdly__controller_tb__DOT__C27 = vlSelfRef.controller_tb__DOT__C27;
    __Vdly__controller_tb__DOT__C26 = vlSelfRef.controller_tb__DOT__C26;
    __Vdly__controller_tb__DOT__C25 = vlSelfRef.controller_tb__DOT__C25;
    __Vdly__controller_tb__DOT__C24 = vlSelfRef.controller_tb__DOT__C24;
    __Vdly__controller_tb__DOT__C23 = vlSelfRef.controller_tb__DOT__C23;
    __Vdly__controller_tb__DOT__C22 = vlSelfRef.controller_tb__DOT__C22;
    __Vdly__controller_tb__DOT__C21 = vlSelfRef.controller_tb__DOT__C21;
    __Vdly__controller_tb__DOT__C20 = vlSelfRef.controller_tb__DOT__C20;
    __Vdly__controller_tb__DOT__C17 = vlSelfRef.controller_tb__DOT__C17;
    __Vdly__controller_tb__DOT__C16 = vlSelfRef.controller_tb__DOT__C16;
    __Vdly__controller_tb__DOT__C15 = vlSelfRef.controller_tb__DOT__C15;
    __Vdly__controller_tb__DOT__C14 = vlSelfRef.controller_tb__DOT__C14;
    __Vdly__controller_tb__DOT__C13 = vlSelfRef.controller_tb__DOT__C13;
    __Vdly__controller_tb__DOT__C12 = vlSelfRef.controller_tb__DOT__C12;
    __Vdly__controller_tb__DOT__C11 = vlSelfRef.controller_tb__DOT__C11;
    __Vdly__controller_tb__DOT__C10 = vlSelfRef.controller_tb__DOT__C10;
    __Vdly__controller_tb__DOT__C07 = vlSelfRef.controller_tb__DOT__C07;
    __Vdly__controller_tb__DOT__C06 = vlSelfRef.controller_tb__DOT__C06;
    __Vdly__controller_tb__DOT__C05 = vlSelfRef.controller_tb__DOT__C05;
    __Vdly__controller_tb__DOT__C04 = vlSelfRef.controller_tb__DOT__C04;
    __Vdly__controller_tb__DOT__C03 = vlSelfRef.controller_tb__DOT__C03;
    __Vdly__controller_tb__DOT__C02 = vlSelfRef.controller_tb__DOT__C02;
    __Vdly__controller_tb__DOT__C01 = vlSelfRef.controller_tb__DOT__C01;
    __Vdly__controller_tb__DOT__C00 = vlSelfRef.controller_tb__DOT__C00;
    if (vlSelfRef.controller_tb__DOT__uut__DOT__sys_reset) {
        __Vdly__controller_tb__DOT__uut__DOT__array__DOT__cycle = 0U;
        __Vdly__controller_tb__DOT__C77 = 0U;
        __Vdly__controller_tb__DOT__C76 = 0U;
        __Vdly__controller_tb__DOT__C75 = 0U;
        __Vdly__controller_tb__DOT__C74 = 0U;
        __Vdly__controller_tb__DOT__C73 = 0U;
        __Vdly__controller_tb__DOT__C72 = 0U;
        __Vdly__controller_tb__DOT__C71 = 0U;
        __Vdly__controller_tb__DOT__C70 = 0U;
        __Vdly__controller_tb__DOT__C67 = 0U;
        __Vdly__controller_tb__DOT__C66 = 0U;
        __Vdly__controller_tb__DOT__C65 = 0U;
        __Vdly__controller_tb__DOT__C64 = 0U;
        __Vdly__controller_tb__DOT__C63 = 0U;
        __Vdly__controller_tb__DOT__C62 = 0U;
        __Vdly__controller_tb__DOT__C61 = 0U;
        __Vdly__controller_tb__DOT__C60 = 0U;
        __Vdly__controller_tb__DOT__C57 = 0U;
        __Vdly__controller_tb__DOT__C56 = 0U;
        __Vdly__controller_tb__DOT__C55 = 0U;
        __Vdly__controller_tb__DOT__C54 = 0U;
        __Vdly__controller_tb__DOT__C53 = 0U;
        __Vdly__controller_tb__DOT__C52 = 0U;
        __Vdly__controller_tb__DOT__C51 = 0U;
        __Vdly__controller_tb__DOT__C50 = 0U;
        __Vdly__controller_tb__DOT__C47 = 0U;
        __Vdly__controller_tb__DOT__C46 = 0U;
        __Vdly__controller_tb__DOT__C45 = 0U;
        __Vdly__controller_tb__DOT__C44 = 0U;
        __Vdly__controller_tb__DOT__C43 = 0U;
        __Vdly__controller_tb__DOT__C42 = 0U;
        __Vdly__controller_tb__DOT__C41 = 0U;
        __Vdly__controller_tb__DOT__C40 = 0U;
        __Vdly__controller_tb__DOT__C37 = 0U;
        __Vdly__controller_tb__DOT__C36 = 0U;
        __Vdly__controller_tb__DOT__C35 = 0U;
        __Vdly__controller_tb__DOT__C34 = 0U;
        __Vdly__controller_tb__DOT__C33 = 0U;
        __Vdly__controller_tb__DOT__C32 = 0U;
        __Vdly__controller_tb__DOT__C31 = 0U;
        __Vdly__controller_tb__DOT__C30 = 0U;
        __Vdly__controller_tb__DOT__C27 = 0U;
        __Vdly__controller_tb__DOT__C26 = 0U;
        __Vdly__controller_tb__DOT__C25 = 0U;
        __Vdly__controller_tb__DOT__C24 = 0U;
        __Vdly__controller_tb__DOT__C23 = 0U;
        __Vdly__controller_tb__DOT__C22 = 0U;
        __Vdly__controller_tb__DOT__C21 = 0U;
        __Vdly__controller_tb__DOT__C20 = 0U;
        __Vdly__controller_tb__DOT__C17 = 0U;
        __Vdly__controller_tb__DOT__C16 = 0U;
        __Vdly__controller_tb__DOT__C15 = 0U;
        __Vdly__controller_tb__DOT__C14 = 0U;
        __Vdly__controller_tb__DOT__C13 = 0U;
        __Vdly__controller_tb__DOT__C12 = 0U;
        __Vdly__controller_tb__DOT__C11 = 0U;
        __Vdly__controller_tb__DOT__C10 = 0U;
        __Vdly__controller_tb__DOT__C07 = 0U;
        __Vdly__controller_tb__DOT__C06 = 0U;
        __Vdly__controller_tb__DOT__C05 = 0U;
        __Vdly__controller_tb__DOT__C04 = 0U;
        __Vdly__controller_tb__DOT__C03 = 0U;
        __Vdly__controller_tb__DOT__C02 = 0U;
        __Vdly__controller_tb__DOT__C01 = 0U;
        __Vdly__controller_tb__DOT__C00 = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe77__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe77__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe76__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe76__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe75__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe75__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe74__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe74__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe73__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe73__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe72__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe72__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe71__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe71__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe70__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe70__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe67__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe67__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe66__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe66__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe65__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe65__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe64__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe64__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe63__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe63__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe62__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe62__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe61__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe61__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe60__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe60__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe57__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe57__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe56__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe56__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe55__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe55__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe54__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe54__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe53__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe53__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe52__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe52__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe51__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe51__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe50__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe50__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe47__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe47__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe46__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe46__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe45__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe45__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe44__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe44__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe43__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe43__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe42__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe42__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe41__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe41__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe40__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe40__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe37__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe37__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe36__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe36__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe35__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe35__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe34__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe34__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe33__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe33__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe32__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe32__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe31__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe31__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe30__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe30__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe27__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe27__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe26__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe26__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe25__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe25__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe24__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe24__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe23__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe23__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe22__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe22__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe21__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe21__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe20__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe20__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe17__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe17__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe16__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe16__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe15__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe15__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe14__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe14__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe13__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe13__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe12__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe12__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe11__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe11__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe10__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe10__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe07__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe07__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe06__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe06__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe05__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe05__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe04__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe04__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe03__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe03__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe02__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe02__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe01__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe01__B_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe00__A_out = 0U;
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe00__B_out = 0U;
    } else if (vlSelfRef.controller_tb__DOT__uut__DOT__sys_enable) {
        __Vdly__controller_tb__DOT__uut__DOT__array__DOT__cycle 
            = ((IData)(1U) + vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle);
        __Vdly__controller_tb__DOT__C77 = (vlSelfRef.controller_tb__DOT__C77 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][7U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][7U])));
        __Vdly__controller_tb__DOT__C76 = (vlSelfRef.controller_tb__DOT__C76 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][6U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][6U])));
        __Vdly__controller_tb__DOT__C75 = (vlSelfRef.controller_tb__DOT__C75 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][5U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][5U])));
        __Vdly__controller_tb__DOT__C74 = (vlSelfRef.controller_tb__DOT__C74 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][4U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][4U])));
        __Vdly__controller_tb__DOT__C73 = (vlSelfRef.controller_tb__DOT__C73 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][3U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][3U])));
        __Vdly__controller_tb__DOT__C72 = (vlSelfRef.controller_tb__DOT__C72 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][2U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][2U])));
        __Vdly__controller_tb__DOT__C71 = (vlSelfRef.controller_tb__DOT__C71 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][1U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][1U])));
        __Vdly__controller_tb__DOT__C70 = (vlSelfRef.controller_tb__DOT__C70 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][0U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][0U])));
        __Vdly__controller_tb__DOT__C67 = (vlSelfRef.controller_tb__DOT__C67 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][7U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][7U])));
        __Vdly__controller_tb__DOT__C66 = (vlSelfRef.controller_tb__DOT__C66 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][6U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][6U])));
        __Vdly__controller_tb__DOT__C65 = (vlSelfRef.controller_tb__DOT__C65 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][5U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][5U])));
        __Vdly__controller_tb__DOT__C64 = (vlSelfRef.controller_tb__DOT__C64 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][4U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][4U])));
        __Vdly__controller_tb__DOT__C63 = (vlSelfRef.controller_tb__DOT__C63 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][3U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][3U])));
        __Vdly__controller_tb__DOT__C62 = (vlSelfRef.controller_tb__DOT__C62 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][2U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][2U])));
        __Vdly__controller_tb__DOT__C61 = (vlSelfRef.controller_tb__DOT__C61 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][1U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][1U])));
        __Vdly__controller_tb__DOT__C60 = (vlSelfRef.controller_tb__DOT__C60 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][0U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][0U])));
        __Vdly__controller_tb__DOT__C57 = (vlSelfRef.controller_tb__DOT__C57 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][7U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][7U])));
        __Vdly__controller_tb__DOT__C56 = (vlSelfRef.controller_tb__DOT__C56 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][6U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][6U])));
        __Vdly__controller_tb__DOT__C55 = (vlSelfRef.controller_tb__DOT__C55 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][5U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][5U])));
        __Vdly__controller_tb__DOT__C54 = (vlSelfRef.controller_tb__DOT__C54 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][4U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][4U])));
        __Vdly__controller_tb__DOT__C53 = (vlSelfRef.controller_tb__DOT__C53 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][3U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][3U])));
        __Vdly__controller_tb__DOT__C52 = (vlSelfRef.controller_tb__DOT__C52 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][2U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][2U])));
        __Vdly__controller_tb__DOT__C51 = (vlSelfRef.controller_tb__DOT__C51 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][1U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][1U])));
        __Vdly__controller_tb__DOT__C50 = (vlSelfRef.controller_tb__DOT__C50 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][0U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][0U])));
        __Vdly__controller_tb__DOT__C47 = (vlSelfRef.controller_tb__DOT__C47 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][7U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][7U])));
        __Vdly__controller_tb__DOT__C46 = (vlSelfRef.controller_tb__DOT__C46 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][6U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][6U])));
        __Vdly__controller_tb__DOT__C45 = (vlSelfRef.controller_tb__DOT__C45 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][5U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][5U])));
        __Vdly__controller_tb__DOT__C44 = (vlSelfRef.controller_tb__DOT__C44 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][4U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][4U])));
        __Vdly__controller_tb__DOT__C43 = (vlSelfRef.controller_tb__DOT__C43 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][3U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][3U])));
        __Vdly__controller_tb__DOT__C42 = (vlSelfRef.controller_tb__DOT__C42 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][2U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][2U])));
        __Vdly__controller_tb__DOT__C41 = (vlSelfRef.controller_tb__DOT__C41 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][1U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][1U])));
        __Vdly__controller_tb__DOT__C40 = (vlSelfRef.controller_tb__DOT__C40 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][0U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][0U])));
        __Vdly__controller_tb__DOT__C37 = (vlSelfRef.controller_tb__DOT__C37 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][7U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][7U])));
        __Vdly__controller_tb__DOT__C36 = (vlSelfRef.controller_tb__DOT__C36 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][6U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][6U])));
        __Vdly__controller_tb__DOT__C35 = (vlSelfRef.controller_tb__DOT__C35 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][5U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][5U])));
        __Vdly__controller_tb__DOT__C34 = (vlSelfRef.controller_tb__DOT__C34 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][4U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][4U])));
        __Vdly__controller_tb__DOT__C33 = (vlSelfRef.controller_tb__DOT__C33 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][3U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][3U])));
        __Vdly__controller_tb__DOT__C32 = (vlSelfRef.controller_tb__DOT__C32 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][2U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][2U])));
        __Vdly__controller_tb__DOT__C31 = (vlSelfRef.controller_tb__DOT__C31 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][1U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][1U])));
        __Vdly__controller_tb__DOT__C30 = (vlSelfRef.controller_tb__DOT__C30 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][0U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][0U])));
        __Vdly__controller_tb__DOT__C27 = (vlSelfRef.controller_tb__DOT__C27 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][7U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][7U])));
        __Vdly__controller_tb__DOT__C26 = (vlSelfRef.controller_tb__DOT__C26 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][6U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][6U])));
        __Vdly__controller_tb__DOT__C25 = (vlSelfRef.controller_tb__DOT__C25 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][5U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][5U])));
        __Vdly__controller_tb__DOT__C24 = (vlSelfRef.controller_tb__DOT__C24 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][4U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][4U])));
        __Vdly__controller_tb__DOT__C23 = (vlSelfRef.controller_tb__DOT__C23 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][3U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][3U])));
        __Vdly__controller_tb__DOT__C22 = (vlSelfRef.controller_tb__DOT__C22 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][2U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][2U])));
        __Vdly__controller_tb__DOT__C21 = (vlSelfRef.controller_tb__DOT__C21 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][1U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][1U])));
        __Vdly__controller_tb__DOT__C20 = (vlSelfRef.controller_tb__DOT__C20 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][0U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][0U])));
        __Vdly__controller_tb__DOT__C17 = (vlSelfRef.controller_tb__DOT__C17 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][7U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][7U])));
        __Vdly__controller_tb__DOT__C16 = (vlSelfRef.controller_tb__DOT__C16 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][6U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][6U])));
        __Vdly__controller_tb__DOT__C15 = (vlSelfRef.controller_tb__DOT__C15 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][5U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][5U])));
        __Vdly__controller_tb__DOT__C14 = (vlSelfRef.controller_tb__DOT__C14 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][4U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][4U])));
        __Vdly__controller_tb__DOT__C13 = (vlSelfRef.controller_tb__DOT__C13 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][3U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][3U])));
        __Vdly__controller_tb__DOT__C12 = (vlSelfRef.controller_tb__DOT__C12 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][2U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][2U])));
        __Vdly__controller_tb__DOT__C11 = (vlSelfRef.controller_tb__DOT__C11 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][1U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][1U])));
        __Vdly__controller_tb__DOT__C10 = (vlSelfRef.controller_tb__DOT__C10 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][0U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][0U])));
        __Vdly__controller_tb__DOT__C07 = (vlSelfRef.controller_tb__DOT__C07 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][7U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][7U])));
        __Vdly__controller_tb__DOT__C06 = (vlSelfRef.controller_tb__DOT__C06 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][6U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][6U])));
        __Vdly__controller_tb__DOT__C05 = (vlSelfRef.controller_tb__DOT__C05 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][5U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][5U])));
        __Vdly__controller_tb__DOT__C04 = (vlSelfRef.controller_tb__DOT__C04 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][4U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][4U])));
        __Vdly__controller_tb__DOT__C03 = (vlSelfRef.controller_tb__DOT__C03 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][3U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][3U])));
        __Vdly__controller_tb__DOT__C02 = (vlSelfRef.controller_tb__DOT__C02 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][2U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][2U])));
        __Vdly__controller_tb__DOT__C01 = (vlSelfRef.controller_tb__DOT__C01 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][1U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][1U])));
        __Vdly__controller_tb__DOT__C00 = (vlSelfRef.controller_tb__DOT__C00 
                                           + (0x0000ffffU 
                                              & (vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][0U] 
                                                 * vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][0U])));
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe77__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe77__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe76__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe76__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe75__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe75__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe74__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe74__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe73__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe73__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe72__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe72__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe71__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe71__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe70__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][0U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe70__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][0U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe67__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe67__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe66__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe66__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe65__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe65__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe64__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe64__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe63__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe63__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe62__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe62__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe61__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe61__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe60__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][0U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe60__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][0U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe57__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe57__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe56__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe56__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe55__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe55__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe54__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe54__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe53__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe53__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe52__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe52__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe51__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe51__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe50__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][0U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe50__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][0U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe47__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe47__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe46__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe46__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe45__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe45__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe44__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe44__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe43__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe43__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe42__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe42__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe41__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe41__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe40__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][0U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe40__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][0U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe37__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe37__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe36__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe36__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe35__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe35__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe34__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe34__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe33__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe33__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe32__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe32__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe31__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe31__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe30__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][0U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe30__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][0U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe27__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe27__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe26__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe26__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe25__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe25__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe24__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe24__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe23__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe23__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe22__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe22__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe21__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe21__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe20__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][0U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe20__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][0U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe17__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe17__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe16__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe16__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe15__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe15__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe14__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe14__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe13__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe13__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe12__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe12__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe11__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe11__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe10__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][0U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe10__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][0U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe07__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe07__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][7U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe06__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe06__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][6U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe05__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe05__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][5U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe04__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe04__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][4U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe03__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe03__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][3U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe02__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe02__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][2U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe01__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe01__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][1U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe00__A_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][0U];
        vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe00__B_out 
            = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[0U][0U];
    }
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__cycle 
        = __Vdly__controller_tb__DOT__uut__DOT__array__DOT__cycle;
    vlSelfRef.controller_tb__DOT__C77 = __Vdly__controller_tb__DOT__C77;
    vlSelfRef.controller_tb__DOT__C76 = __Vdly__controller_tb__DOT__C76;
    vlSelfRef.controller_tb__DOT__C75 = __Vdly__controller_tb__DOT__C75;
    vlSelfRef.controller_tb__DOT__C74 = __Vdly__controller_tb__DOT__C74;
    vlSelfRef.controller_tb__DOT__C73 = __Vdly__controller_tb__DOT__C73;
    vlSelfRef.controller_tb__DOT__C72 = __Vdly__controller_tb__DOT__C72;
    vlSelfRef.controller_tb__DOT__C71 = __Vdly__controller_tb__DOT__C71;
    vlSelfRef.controller_tb__DOT__C70 = __Vdly__controller_tb__DOT__C70;
    vlSelfRef.controller_tb__DOT__C67 = __Vdly__controller_tb__DOT__C67;
    vlSelfRef.controller_tb__DOT__C66 = __Vdly__controller_tb__DOT__C66;
    vlSelfRef.controller_tb__DOT__C65 = __Vdly__controller_tb__DOT__C65;
    vlSelfRef.controller_tb__DOT__C64 = __Vdly__controller_tb__DOT__C64;
    vlSelfRef.controller_tb__DOT__C63 = __Vdly__controller_tb__DOT__C63;
    vlSelfRef.controller_tb__DOT__C62 = __Vdly__controller_tb__DOT__C62;
    vlSelfRef.controller_tb__DOT__C61 = __Vdly__controller_tb__DOT__C61;
    vlSelfRef.controller_tb__DOT__C60 = __Vdly__controller_tb__DOT__C60;
    vlSelfRef.controller_tb__DOT__C57 = __Vdly__controller_tb__DOT__C57;
    vlSelfRef.controller_tb__DOT__C56 = __Vdly__controller_tb__DOT__C56;
    vlSelfRef.controller_tb__DOT__C55 = __Vdly__controller_tb__DOT__C55;
    vlSelfRef.controller_tb__DOT__C54 = __Vdly__controller_tb__DOT__C54;
    vlSelfRef.controller_tb__DOT__C53 = __Vdly__controller_tb__DOT__C53;
    vlSelfRef.controller_tb__DOT__C52 = __Vdly__controller_tb__DOT__C52;
    vlSelfRef.controller_tb__DOT__C51 = __Vdly__controller_tb__DOT__C51;
    vlSelfRef.controller_tb__DOT__C50 = __Vdly__controller_tb__DOT__C50;
    vlSelfRef.controller_tb__DOT__C47 = __Vdly__controller_tb__DOT__C47;
    vlSelfRef.controller_tb__DOT__C46 = __Vdly__controller_tb__DOT__C46;
    vlSelfRef.controller_tb__DOT__C45 = __Vdly__controller_tb__DOT__C45;
    vlSelfRef.controller_tb__DOT__C44 = __Vdly__controller_tb__DOT__C44;
    vlSelfRef.controller_tb__DOT__C43 = __Vdly__controller_tb__DOT__C43;
    vlSelfRef.controller_tb__DOT__C42 = __Vdly__controller_tb__DOT__C42;
    vlSelfRef.controller_tb__DOT__C41 = __Vdly__controller_tb__DOT__C41;
    vlSelfRef.controller_tb__DOT__C40 = __Vdly__controller_tb__DOT__C40;
    vlSelfRef.controller_tb__DOT__C37 = __Vdly__controller_tb__DOT__C37;
    vlSelfRef.controller_tb__DOT__C36 = __Vdly__controller_tb__DOT__C36;
    vlSelfRef.controller_tb__DOT__C35 = __Vdly__controller_tb__DOT__C35;
    vlSelfRef.controller_tb__DOT__C34 = __Vdly__controller_tb__DOT__C34;
    vlSelfRef.controller_tb__DOT__C33 = __Vdly__controller_tb__DOT__C33;
    vlSelfRef.controller_tb__DOT__C32 = __Vdly__controller_tb__DOT__C32;
    vlSelfRef.controller_tb__DOT__C31 = __Vdly__controller_tb__DOT__C31;
    vlSelfRef.controller_tb__DOT__C30 = __Vdly__controller_tb__DOT__C30;
    vlSelfRef.controller_tb__DOT__C27 = __Vdly__controller_tb__DOT__C27;
    vlSelfRef.controller_tb__DOT__C26 = __Vdly__controller_tb__DOT__C26;
    vlSelfRef.controller_tb__DOT__C25 = __Vdly__controller_tb__DOT__C25;
    vlSelfRef.controller_tb__DOT__C24 = __Vdly__controller_tb__DOT__C24;
    vlSelfRef.controller_tb__DOT__C23 = __Vdly__controller_tb__DOT__C23;
    vlSelfRef.controller_tb__DOT__C22 = __Vdly__controller_tb__DOT__C22;
    vlSelfRef.controller_tb__DOT__C21 = __Vdly__controller_tb__DOT__C21;
    vlSelfRef.controller_tb__DOT__C20 = __Vdly__controller_tb__DOT__C20;
    vlSelfRef.controller_tb__DOT__C17 = __Vdly__controller_tb__DOT__C17;
    vlSelfRef.controller_tb__DOT__C16 = __Vdly__controller_tb__DOT__C16;
    vlSelfRef.controller_tb__DOT__C15 = __Vdly__controller_tb__DOT__C15;
    vlSelfRef.controller_tb__DOT__C14 = __Vdly__controller_tb__DOT__C14;
    vlSelfRef.controller_tb__DOT__C13 = __Vdly__controller_tb__DOT__C13;
    vlSelfRef.controller_tb__DOT__C12 = __Vdly__controller_tb__DOT__C12;
    vlSelfRef.controller_tb__DOT__C11 = __Vdly__controller_tb__DOT__C11;
    vlSelfRef.controller_tb__DOT__C10 = __Vdly__controller_tb__DOT__C10;
    vlSelfRef.controller_tb__DOT__C07 = __Vdly__controller_tb__DOT__C07;
    vlSelfRef.controller_tb__DOT__C06 = __Vdly__controller_tb__DOT__C06;
    vlSelfRef.controller_tb__DOT__C05 = __Vdly__controller_tb__DOT__C05;
    vlSelfRef.controller_tb__DOT__C04 = __Vdly__controller_tb__DOT__C04;
    vlSelfRef.controller_tb__DOT__C03 = __Vdly__controller_tb__DOT__C03;
    vlSelfRef.controller_tb__DOT__C02 = __Vdly__controller_tb__DOT__C02;
    vlSelfRef.controller_tb__DOT__C01 = __Vdly__controller_tb__DOT__C01;
    vlSelfRef.controller_tb__DOT__C00 = __Vdly__controller_tb__DOT__C00;
    vlSelfRef.controller_tb__DOT__actual[7U][7U] = vlSelfRef.controller_tb__DOT__C77;
    vlSelfRef.controller_tb__DOT__actual[7U][6U] = vlSelfRef.controller_tb__DOT__C76;
    vlSelfRef.controller_tb__DOT__actual[7U][5U] = vlSelfRef.controller_tb__DOT__C75;
    vlSelfRef.controller_tb__DOT__actual[7U][4U] = vlSelfRef.controller_tb__DOT__C74;
    vlSelfRef.controller_tb__DOT__actual[7U][3U] = vlSelfRef.controller_tb__DOT__C73;
    vlSelfRef.controller_tb__DOT__actual[7U][2U] = vlSelfRef.controller_tb__DOT__C72;
    vlSelfRef.controller_tb__DOT__actual[7U][1U] = vlSelfRef.controller_tb__DOT__C71;
    vlSelfRef.controller_tb__DOT__actual[7U][0U] = vlSelfRef.controller_tb__DOT__C70;
    vlSelfRef.controller_tb__DOT__actual[6U][7U] = vlSelfRef.controller_tb__DOT__C67;
    vlSelfRef.controller_tb__DOT__actual[6U][6U] = vlSelfRef.controller_tb__DOT__C66;
    vlSelfRef.controller_tb__DOT__actual[6U][5U] = vlSelfRef.controller_tb__DOT__C65;
    vlSelfRef.controller_tb__DOT__actual[6U][4U] = vlSelfRef.controller_tb__DOT__C64;
    vlSelfRef.controller_tb__DOT__actual[6U][3U] = vlSelfRef.controller_tb__DOT__C63;
    vlSelfRef.controller_tb__DOT__actual[6U][2U] = vlSelfRef.controller_tb__DOT__C62;
    vlSelfRef.controller_tb__DOT__actual[6U][1U] = vlSelfRef.controller_tb__DOT__C61;
    vlSelfRef.controller_tb__DOT__actual[6U][0U] = vlSelfRef.controller_tb__DOT__C60;
    vlSelfRef.controller_tb__DOT__actual[5U][7U] = vlSelfRef.controller_tb__DOT__C57;
    vlSelfRef.controller_tb__DOT__actual[5U][6U] = vlSelfRef.controller_tb__DOT__C56;
    vlSelfRef.controller_tb__DOT__actual[5U][5U] = vlSelfRef.controller_tb__DOT__C55;
    vlSelfRef.controller_tb__DOT__actual[5U][4U] = vlSelfRef.controller_tb__DOT__C54;
    vlSelfRef.controller_tb__DOT__actual[5U][3U] = vlSelfRef.controller_tb__DOT__C53;
    vlSelfRef.controller_tb__DOT__actual[5U][2U] = vlSelfRef.controller_tb__DOT__C52;
    vlSelfRef.controller_tb__DOT__actual[5U][1U] = vlSelfRef.controller_tb__DOT__C51;
    vlSelfRef.controller_tb__DOT__actual[5U][0U] = vlSelfRef.controller_tb__DOT__C50;
    vlSelfRef.controller_tb__DOT__actual[4U][7U] = vlSelfRef.controller_tb__DOT__C47;
    vlSelfRef.controller_tb__DOT__actual[4U][6U] = vlSelfRef.controller_tb__DOT__C46;
    vlSelfRef.controller_tb__DOT__actual[4U][5U] = vlSelfRef.controller_tb__DOT__C45;
    vlSelfRef.controller_tb__DOT__actual[4U][4U] = vlSelfRef.controller_tb__DOT__C44;
    vlSelfRef.controller_tb__DOT__actual[4U][3U] = vlSelfRef.controller_tb__DOT__C43;
    vlSelfRef.controller_tb__DOT__actual[4U][2U] = vlSelfRef.controller_tb__DOT__C42;
    vlSelfRef.controller_tb__DOT__actual[4U][1U] = vlSelfRef.controller_tb__DOT__C41;
    vlSelfRef.controller_tb__DOT__actual[4U][0U] = vlSelfRef.controller_tb__DOT__C40;
    vlSelfRef.controller_tb__DOT__actual[3U][7U] = vlSelfRef.controller_tb__DOT__C37;
    vlSelfRef.controller_tb__DOT__actual[3U][6U] = vlSelfRef.controller_tb__DOT__C36;
    vlSelfRef.controller_tb__DOT__actual[3U][5U] = vlSelfRef.controller_tb__DOT__C35;
    vlSelfRef.controller_tb__DOT__actual[3U][4U] = vlSelfRef.controller_tb__DOT__C34;
    vlSelfRef.controller_tb__DOT__actual[3U][3U] = vlSelfRef.controller_tb__DOT__C33;
    vlSelfRef.controller_tb__DOT__actual[3U][2U] = vlSelfRef.controller_tb__DOT__C32;
    vlSelfRef.controller_tb__DOT__actual[3U][1U] = vlSelfRef.controller_tb__DOT__C31;
    vlSelfRef.controller_tb__DOT__actual[3U][0U] = vlSelfRef.controller_tb__DOT__C30;
    vlSelfRef.controller_tb__DOT__actual[2U][7U] = vlSelfRef.controller_tb__DOT__C27;
    vlSelfRef.controller_tb__DOT__actual[2U][6U] = vlSelfRef.controller_tb__DOT__C26;
    vlSelfRef.controller_tb__DOT__actual[2U][5U] = vlSelfRef.controller_tb__DOT__C25;
    vlSelfRef.controller_tb__DOT__actual[2U][4U] = vlSelfRef.controller_tb__DOT__C24;
    vlSelfRef.controller_tb__DOT__actual[2U][3U] = vlSelfRef.controller_tb__DOT__C23;
    vlSelfRef.controller_tb__DOT__actual[2U][2U] = vlSelfRef.controller_tb__DOT__C22;
    vlSelfRef.controller_tb__DOT__actual[2U][1U] = vlSelfRef.controller_tb__DOT__C21;
    vlSelfRef.controller_tb__DOT__actual[2U][0U] = vlSelfRef.controller_tb__DOT__C20;
    vlSelfRef.controller_tb__DOT__actual[1U][7U] = vlSelfRef.controller_tb__DOT__C17;
    vlSelfRef.controller_tb__DOT__actual[1U][6U] = vlSelfRef.controller_tb__DOT__C16;
    vlSelfRef.controller_tb__DOT__actual[1U][5U] = vlSelfRef.controller_tb__DOT__C15;
    vlSelfRef.controller_tb__DOT__actual[1U][4U] = vlSelfRef.controller_tb__DOT__C14;
    vlSelfRef.controller_tb__DOT__actual[1U][3U] = vlSelfRef.controller_tb__DOT__C13;
    vlSelfRef.controller_tb__DOT__actual[1U][2U] = vlSelfRef.controller_tb__DOT__C12;
    vlSelfRef.controller_tb__DOT__actual[1U][1U] = vlSelfRef.controller_tb__DOT__C11;
    vlSelfRef.controller_tb__DOT__actual[1U][0U] = vlSelfRef.controller_tb__DOT__C10;
    vlSelfRef.controller_tb__DOT__actual[0U][7U] = vlSelfRef.controller_tb__DOT__C07;
    vlSelfRef.controller_tb__DOT__actual[0U][6U] = vlSelfRef.controller_tb__DOT__C06;
    vlSelfRef.controller_tb__DOT__actual[0U][5U] = vlSelfRef.controller_tb__DOT__C05;
    vlSelfRef.controller_tb__DOT__actual[0U][4U] = vlSelfRef.controller_tb__DOT__C04;
    vlSelfRef.controller_tb__DOT__actual[0U][3U] = vlSelfRef.controller_tb__DOT__C03;
    vlSelfRef.controller_tb__DOT__actual[0U][2U] = vlSelfRef.controller_tb__DOT__C02;
    vlSelfRef.controller_tb__DOT__actual[0U][1U] = vlSelfRef.controller_tb__DOT__C01;
    vlSelfRef.controller_tb__DOT__actual[0U][0U] = vlSelfRef.controller_tb__DOT__C00;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe77__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe77__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe76__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe76__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe75__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe75__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe74__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe74__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe73__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe73__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe72__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe72__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe71__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe71__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe70__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe70__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe67__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe67__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe66__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe66__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe65__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe65__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe64__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe64__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe63__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe63__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe62__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe62__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe61__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe61__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe60__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe60__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe57__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe57__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe56__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe56__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe55__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe55__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe54__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe54__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe53__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe53__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe52__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe52__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe51__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe51__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe50__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe50__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe47__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe47__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe46__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe46__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe45__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe45__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe44__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe44__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe43__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe43__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe42__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe42__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe41__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe41__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe40__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe40__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe37__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe37__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe36__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe36__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe35__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe35__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe34__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe34__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe33__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe33__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe32__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe32__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe31__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe31__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe30__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe30__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe27__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe27__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe26__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe26__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe25__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe25__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe24__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe24__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe23__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe23__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe22__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe22__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe21__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe21__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe20__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe20__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe17__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe17__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe16__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe16__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe15__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe15__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe14__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe14__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe13__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe13__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe12__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe12__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe11__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe11__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe10__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe10__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe07__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe07__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe06__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe06__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe05__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe05__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe04__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe04__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe03__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe03__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe02__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe02__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe01__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe01__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe00__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe00__B_out;
}

void Vcontroller_tb___024root___timing_ready(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___timing_ready\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hee4b4f38__0.ready("@(posedge controller_tb.clk)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h06f34caf__0.ready("@( controller_tb.done)");
    }
}

void Vcontroller_tb___024root___timing_resume(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___timing_resume\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_hee4b4f38__0.moveToResumeQueue(
                                                          "@(posedge controller_tb.clk)");
    vlSelfRef.__VtrigSched_h06f34caf__0.moveToResumeQueue(
                                                          "@( controller_tb.done)");
    vlSelfRef.__VtrigSched_hee4b4f38__0.resume("@(posedge controller_tb.clk)");
    vlSelfRef.__VtrigSched_h06f34caf__0.resume("@( controller_tb.done)");
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vcontroller_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vcontroller_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vcontroller_tb___024root____VbeforeTrig_hee4b4f38__0(Vcontroller_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root____VbeforeTrig_hee4b4f38__0\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((IData)(vlSelfRef.controller_tb__DOT__clk) 
                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__controller_tb__DOT__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__controller_tb__DOT__clk__0 
        = vlSelfRef.controller_tb__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_hee4b4f38__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hee4b4f38__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hee4b4f38__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hee4b4f38__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hee4b4f38__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vcontroller_tb___024root____VbeforeTrig_h06f34caf__0(Vcontroller_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root____VbeforeTrig_h06f34caf__0\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)((((IData)(vlSelfRef.controller_tb__DOT__done) 
                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__controller_tb__DOT__done__0)) 
                                  << 3U)));
    vlSelfRef.__Vtrigprevexpr___TOP__controller_tb__DOT__done__0 
        = vlSelfRef.controller_tb__DOT__done;
    if ((8ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h06f34caf__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h06f34caf__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vcontroller_tb___024root___eval_debug_assertions(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_debug_assertions\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
