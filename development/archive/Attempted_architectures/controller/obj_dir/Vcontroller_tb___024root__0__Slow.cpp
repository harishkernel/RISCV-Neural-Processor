// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontroller_tb.h for the primary calling header

#include "Vcontroller_tb__pch.h"

void Vcontroller_tb___024root___timing_ready(Vcontroller_tb___024root* vlSelf);

VL_ATTR_COLD void Vcontroller_tb___024root___eval_static(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_static\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (8ULL | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__Vtrigprevexpr___TOP__controller_tb__DOT__clk__0 
        = vlSelfRef.controller_tb__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__controller_tb__DOT__rst_n__0 
        = vlSelfRef.controller_tb__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__controller_tb__DOT__done__0 
        = vlSelfRef.controller_tb__DOT__done;
    Vcontroller_tb___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontroller_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vcontroller_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);
VL_ATTR_COLD void Vcontroller_tb___024root___stl_sequent__TOP__0(Vcontroller_tb___024root* vlSelf);

VL_ATTR_COLD bool Vcontroller_tb___024root___eval_stl(Vcontroller_tb___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_stl\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcontroller_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vcontroller_tb___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vcontroller_tb___024root___stl_sequent__TOP__0(vlSelf);
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vcontroller_tb___024root___eval_dump_triggers__stl(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_dump_triggers__stl\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vcontroller_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontroller_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vcontroller_tb___024root___eval_dump_triggers__ico(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_dump_triggers__ico\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vcontroller_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontroller_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vcontroller_tb___024root___eval_dump_triggers__act(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_dump_triggers__act\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vcontroller_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vcontroller_tb___024root___eval_dump_triggers__nba(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_dump_triggers__nba\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vcontroller_tb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vcontroller_tb___024root___eval_dump_triggers__obs(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_dump_triggers__obs\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vcontroller_tb___024root___eval_dump_triggers__react(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_dump_triggers__react\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vcontroller_tb___024root___eval_final(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_final\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vcontroller_tb___024root___eval_initial__TOP(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___eval_initial__TOP\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.controller_tb__DOT__clk = 0U;
    vlSelfRef.controller_tb__DOT__expected[0U][0U] = 0x000000ccU;
    vlSelfRef.controller_tb__DOT__expected[0U][1U] = 0x000000f0U;
    vlSelfRef.controller_tb__DOT__expected[0U][2U] = 0x00000114U;
    vlSelfRef.controller_tb__DOT__expected[0U][3U] = 0x00000138U;
    vlSelfRef.controller_tb__DOT__expected[0U][4U] = 0x0000015cU;
    vlSelfRef.controller_tb__DOT__expected[0U][5U] = 0x00000180U;
    vlSelfRef.controller_tb__DOT__expected[0U][6U] = 0x000001a4U;
    vlSelfRef.controller_tb__DOT__expected[0U][7U] = 0x000001c8U;
    vlSelfRef.controller_tb__DOT__expected[1U][0U] = 0x000000f0U;
    vlSelfRef.controller_tb__DOT__expected[1U][1U] = 0x0000011cU;
    vlSelfRef.controller_tb__DOT__expected[1U][2U] = 0x00000148U;
    vlSelfRef.controller_tb__DOT__expected[1U][3U] = 0x00000174U;
    vlSelfRef.controller_tb__DOT__expected[1U][4U] = 0x000001a0U;
    vlSelfRef.controller_tb__DOT__expected[1U][5U] = 0x000001ccU;
    vlSelfRef.controller_tb__DOT__expected[1U][6U] = 0x000001f8U;
    vlSelfRef.controller_tb__DOT__expected[1U][7U] = 0x00000224U;
    vlSelfRef.controller_tb__DOT__expected[2U][0U] = 0x00000114U;
    vlSelfRef.controller_tb__DOT__expected[2U][1U] = 0x00000148U;
    vlSelfRef.controller_tb__DOT__expected[2U][2U] = 0x0000017cU;
    vlSelfRef.controller_tb__DOT__expected[2U][3U] = 0x000001b0U;
    vlSelfRef.controller_tb__DOT__expected[2U][4U] = 0x000001e4U;
    vlSelfRef.controller_tb__DOT__expected[2U][5U] = 0x00000218U;
    vlSelfRef.controller_tb__DOT__expected[2U][6U] = 0x0000024cU;
    vlSelfRef.controller_tb__DOT__expected[2U][7U] = 0x00000280U;
    vlSelfRef.controller_tb__DOT__expected[3U][0U] = 0x00000138U;
    vlSelfRef.controller_tb__DOT__expected[3U][1U] = 0x00000174U;
    vlSelfRef.controller_tb__DOT__expected[3U][2U] = 0x000001b0U;
    vlSelfRef.controller_tb__DOT__expected[3U][3U] = 0x000001ecU;
    vlSelfRef.controller_tb__DOT__expected[3U][4U] = 0x00000228U;
    vlSelfRef.controller_tb__DOT__expected[3U][5U] = 0x00000264U;
    vlSelfRef.controller_tb__DOT__expected[3U][6U] = 0x000002a0U;
    vlSelfRef.controller_tb__DOT__expected[3U][7U] = 0x000002dcU;
    vlSelfRef.controller_tb__DOT__expected[4U][0U] = 0x0000015cU;
    vlSelfRef.controller_tb__DOT__expected[4U][1U] = 0x000001a0U;
    vlSelfRef.controller_tb__DOT__expected[4U][2U] = 0x000001e4U;
    vlSelfRef.controller_tb__DOT__expected[4U][3U] = 0x00000228U;
    vlSelfRef.controller_tb__DOT__expected[4U][4U] = 0x0000026cU;
    vlSelfRef.controller_tb__DOT__expected[4U][5U] = 0x000002b0U;
    vlSelfRef.controller_tb__DOT__expected[4U][6U] = 0x000002f4U;
    vlSelfRef.controller_tb__DOT__expected[4U][7U] = 0x00000338U;
    vlSelfRef.controller_tb__DOT__expected[5U][0U] = 0x00000180U;
    vlSelfRef.controller_tb__DOT__expected[5U][1U] = 0x000001ccU;
    vlSelfRef.controller_tb__DOT__expected[5U][2U] = 0x00000218U;
    vlSelfRef.controller_tb__DOT__expected[5U][3U] = 0x00000264U;
    vlSelfRef.controller_tb__DOT__expected[5U][4U] = 0x000002b0U;
    vlSelfRef.controller_tb__DOT__expected[5U][5U] = 0x000002fcU;
    vlSelfRef.controller_tb__DOT__expected[5U][6U] = 0x00000348U;
    vlSelfRef.controller_tb__DOT__expected[5U][7U] = 0x00000394U;
    vlSelfRef.controller_tb__DOT__expected[6U][0U] = 0x000001a4U;
    vlSelfRef.controller_tb__DOT__expected[6U][1U] = 0x000001f8U;
    vlSelfRef.controller_tb__DOT__expected[6U][2U] = 0x0000024cU;
    vlSelfRef.controller_tb__DOT__expected[6U][3U] = 0x000002a0U;
    vlSelfRef.controller_tb__DOT__expected[6U][4U] = 0x000002f4U;
    vlSelfRef.controller_tb__DOT__expected[6U][5U] = 0x00000348U;
    vlSelfRef.controller_tb__DOT__expected[6U][6U] = 0x0000039cU;
    vlSelfRef.controller_tb__DOT__expected[6U][7U] = 0x000003f0U;
    vlSelfRef.controller_tb__DOT__expected[7U][0U] = 0x000001c8U;
    vlSelfRef.controller_tb__DOT__expected[7U][1U] = 0x00000224U;
    vlSelfRef.controller_tb__DOT__expected[7U][2U] = 0x00000280U;
    vlSelfRef.controller_tb__DOT__expected[7U][3U] = 0x000002dcU;
    vlSelfRef.controller_tb__DOT__expected[7U][4U] = 0x00000338U;
    vlSelfRef.controller_tb__DOT__expected[7U][5U] = 0x00000394U;
    vlSelfRef.controller_tb__DOT__expected[7U][6U] = 0x000003f0U;
    vlSelfRef.controller_tb__DOT__expected[7U][7U] = 0x0000044cU;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontroller_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vcontroller_tb___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vcontroller_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vcontroller_tb___024root___stl_sequent__TOP__0(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___stl_sequent__TOP__0\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.controller_tb__DOT__actual[0U][0U] = vlSelfRef.controller_tb__DOT__C00;
    vlSelfRef.controller_tb__DOT__actual[0U][1U] = vlSelfRef.controller_tb__DOT__C01;
    vlSelfRef.controller_tb__DOT__actual[0U][2U] = vlSelfRef.controller_tb__DOT__C02;
    vlSelfRef.controller_tb__DOT__actual[0U][3U] = vlSelfRef.controller_tb__DOT__C03;
    vlSelfRef.controller_tb__DOT__actual[0U][4U] = vlSelfRef.controller_tb__DOT__C04;
    vlSelfRef.controller_tb__DOT__actual[0U][5U] = vlSelfRef.controller_tb__DOT__C05;
    vlSelfRef.controller_tb__DOT__actual[0U][6U] = vlSelfRef.controller_tb__DOT__C06;
    vlSelfRef.controller_tb__DOT__actual[0U][7U] = vlSelfRef.controller_tb__DOT__C07;
    vlSelfRef.controller_tb__DOT__actual[1U][0U] = vlSelfRef.controller_tb__DOT__C10;
    vlSelfRef.controller_tb__DOT__actual[1U][1U] = vlSelfRef.controller_tb__DOT__C11;
    vlSelfRef.controller_tb__DOT__actual[1U][2U] = vlSelfRef.controller_tb__DOT__C12;
    vlSelfRef.controller_tb__DOT__actual[1U][3U] = vlSelfRef.controller_tb__DOT__C13;
    vlSelfRef.controller_tb__DOT__actual[1U][4U] = vlSelfRef.controller_tb__DOT__C14;
    vlSelfRef.controller_tb__DOT__actual[1U][5U] = vlSelfRef.controller_tb__DOT__C15;
    vlSelfRef.controller_tb__DOT__actual[1U][6U] = vlSelfRef.controller_tb__DOT__C16;
    vlSelfRef.controller_tb__DOT__actual[1U][7U] = vlSelfRef.controller_tb__DOT__C17;
    vlSelfRef.controller_tb__DOT__actual[2U][0U] = vlSelfRef.controller_tb__DOT__C20;
    vlSelfRef.controller_tb__DOT__actual[2U][1U] = vlSelfRef.controller_tb__DOT__C21;
    vlSelfRef.controller_tb__DOT__actual[2U][2U] = vlSelfRef.controller_tb__DOT__C22;
    vlSelfRef.controller_tb__DOT__actual[2U][3U] = vlSelfRef.controller_tb__DOT__C23;
    vlSelfRef.controller_tb__DOT__actual[2U][4U] = vlSelfRef.controller_tb__DOT__C24;
    vlSelfRef.controller_tb__DOT__actual[2U][5U] = vlSelfRef.controller_tb__DOT__C25;
    vlSelfRef.controller_tb__DOT__actual[2U][6U] = vlSelfRef.controller_tb__DOT__C26;
    vlSelfRef.controller_tb__DOT__actual[2U][7U] = vlSelfRef.controller_tb__DOT__C27;
    vlSelfRef.controller_tb__DOT__actual[3U][0U] = vlSelfRef.controller_tb__DOT__C30;
    vlSelfRef.controller_tb__DOT__actual[3U][1U] = vlSelfRef.controller_tb__DOT__C31;
    vlSelfRef.controller_tb__DOT__actual[3U][2U] = vlSelfRef.controller_tb__DOT__C32;
    vlSelfRef.controller_tb__DOT__actual[3U][3U] = vlSelfRef.controller_tb__DOT__C33;
    vlSelfRef.controller_tb__DOT__actual[3U][4U] = vlSelfRef.controller_tb__DOT__C34;
    vlSelfRef.controller_tb__DOT__actual[3U][5U] = vlSelfRef.controller_tb__DOT__C35;
    vlSelfRef.controller_tb__DOT__actual[3U][6U] = vlSelfRef.controller_tb__DOT__C36;
    vlSelfRef.controller_tb__DOT__actual[3U][7U] = vlSelfRef.controller_tb__DOT__C37;
    vlSelfRef.controller_tb__DOT__actual[4U][0U] = vlSelfRef.controller_tb__DOT__C40;
    vlSelfRef.controller_tb__DOT__actual[4U][1U] = vlSelfRef.controller_tb__DOT__C41;
    vlSelfRef.controller_tb__DOT__actual[4U][2U] = vlSelfRef.controller_tb__DOT__C42;
    vlSelfRef.controller_tb__DOT__actual[4U][3U] = vlSelfRef.controller_tb__DOT__C43;
    vlSelfRef.controller_tb__DOT__actual[4U][4U] = vlSelfRef.controller_tb__DOT__C44;
    vlSelfRef.controller_tb__DOT__actual[4U][5U] = vlSelfRef.controller_tb__DOT__C45;
    vlSelfRef.controller_tb__DOT__actual[4U][6U] = vlSelfRef.controller_tb__DOT__C46;
    vlSelfRef.controller_tb__DOT__actual[4U][7U] = vlSelfRef.controller_tb__DOT__C47;
    vlSelfRef.controller_tb__DOT__actual[5U][0U] = vlSelfRef.controller_tb__DOT__C50;
    vlSelfRef.controller_tb__DOT__actual[5U][1U] = vlSelfRef.controller_tb__DOT__C51;
    vlSelfRef.controller_tb__DOT__actual[5U][2U] = vlSelfRef.controller_tb__DOT__C52;
    vlSelfRef.controller_tb__DOT__actual[5U][3U] = vlSelfRef.controller_tb__DOT__C53;
    vlSelfRef.controller_tb__DOT__actual[5U][4U] = vlSelfRef.controller_tb__DOT__C54;
    vlSelfRef.controller_tb__DOT__actual[5U][5U] = vlSelfRef.controller_tb__DOT__C55;
    vlSelfRef.controller_tb__DOT__actual[5U][6U] = vlSelfRef.controller_tb__DOT__C56;
    vlSelfRef.controller_tb__DOT__actual[5U][7U] = vlSelfRef.controller_tb__DOT__C57;
    vlSelfRef.controller_tb__DOT__actual[6U][0U] = vlSelfRef.controller_tb__DOT__C60;
    vlSelfRef.controller_tb__DOT__actual[6U][1U] = vlSelfRef.controller_tb__DOT__C61;
    vlSelfRef.controller_tb__DOT__actual[6U][2U] = vlSelfRef.controller_tb__DOT__C62;
    vlSelfRef.controller_tb__DOT__actual[6U][3U] = vlSelfRef.controller_tb__DOT__C63;
    vlSelfRef.controller_tb__DOT__actual[6U][4U] = vlSelfRef.controller_tb__DOT__C64;
    vlSelfRef.controller_tb__DOT__actual[6U][5U] = vlSelfRef.controller_tb__DOT__C65;
    vlSelfRef.controller_tb__DOT__actual[6U][6U] = vlSelfRef.controller_tb__DOT__C66;
    vlSelfRef.controller_tb__DOT__actual[6U][7U] = vlSelfRef.controller_tb__DOT__C67;
    vlSelfRef.controller_tb__DOT__actual[7U][0U] = vlSelfRef.controller_tb__DOT__C70;
    vlSelfRef.controller_tb__DOT__actual[7U][1U] = vlSelfRef.controller_tb__DOT__C71;
    vlSelfRef.controller_tb__DOT__actual[7U][2U] = vlSelfRef.controller_tb__DOT__C72;
    vlSelfRef.controller_tb__DOT__actual[7U][3U] = vlSelfRef.controller_tb__DOT__C73;
    vlSelfRef.controller_tb__DOT__actual[7U][4U] = vlSelfRef.controller_tb__DOT__C74;
    vlSelfRef.controller_tb__DOT__actual[7U][5U] = vlSelfRef.controller_tb__DOT__C75;
    vlSelfRef.controller_tb__DOT__actual[7U][6U] = vlSelfRef.controller_tb__DOT__C76;
    vlSelfRef.controller_tb__DOT__actual[7U][7U] = vlSelfRef.controller_tb__DOT__C77;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe00__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe00__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe01__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe01__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe02__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe02__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe03__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe03__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe04__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe04__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe05__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe05__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe06__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe06__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[1U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe07__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[0U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe07__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe10__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe10__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe11__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe11__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe12__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe12__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe13__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe13__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe14__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe14__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe15__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe15__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe16__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe16__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[2U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe17__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[1U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe17__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe20__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe20__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe21__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe21__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe22__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe22__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe23__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe23__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe24__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe24__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe25__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe25__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe26__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe26__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[3U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe27__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[2U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe27__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe30__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe30__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe31__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe31__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe32__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe32__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe33__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe33__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe34__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe34__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe35__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe35__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe36__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe36__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[4U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe37__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[3U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe37__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe40__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe40__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe41__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe41__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe42__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe42__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe43__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe43__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe44__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe44__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe45__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe45__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe46__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe46__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[5U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe47__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[4U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe47__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe50__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe50__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe51__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe51__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe52__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe52__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe53__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe53__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe54__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe54__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe55__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe55__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe56__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe56__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[6U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe57__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[5U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe57__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe60__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe60__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe61__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe61__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe62__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe62__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe63__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe63__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe64__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe64__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe65__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe65__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe66__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe66__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[7U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe67__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[6U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe67__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][0U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe70__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe70__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][1U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe71__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe71__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][2U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe72__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe72__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][3U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe73__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe73__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][4U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe74__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe74__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][5U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe75__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe75__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][6U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe76__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe76__A_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__B_wire[8U][7U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe77__B_out;
    vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT__A_wire[7U][8U] 
        = vlSelfRef.controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe77__A_out;
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

bool Vcontroller_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontroller_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vcontroller_tb___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vcontroller_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcontroller_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vcontroller_tb___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge controller_tb.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge controller_tb.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( controller_tb.done)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vcontroller_tb___024root___ctor_var_reset(Vcontroller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontroller_tb___024root___ctor_var_reset\n"); );
    Vcontroller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->controller_tb__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2081432633758259629ull);
    vlSelf->controller_tb__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8217160649502697952ull);
    vlSelf->controller_tb__DOT__start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1112682397344971795ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->controller_tb__DOT__A_flat, __VscopeHash, 14982597758034555115ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->controller_tb__DOT__B_flat, __VscopeHash, 16144716684938249321ull);
    vlSelf->controller_tb__DOT__done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 304644652414436896ull);
    vlSelf->controller_tb__DOT__busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8935479434643382353ull);
    vlSelf->controller_tb__DOT__cycle_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14893463028545820452ull);
    vlSelf->controller_tb__DOT__C00 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12881856618917478743ull);
    vlSelf->controller_tb__DOT__C01 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1685899966376528683ull);
    vlSelf->controller_tb__DOT__C02 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4641211001003978414ull);
    vlSelf->controller_tb__DOT__C03 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15260951909616732603ull);
    vlSelf->controller_tb__DOT__C04 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17358130190229037345ull);
    vlSelf->controller_tb__DOT__C05 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2799969844930994581ull);
    vlSelf->controller_tb__DOT__C06 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6303927136920390217ull);
    vlSelf->controller_tb__DOT__C07 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8042877586258896923ull);
    vlSelf->controller_tb__DOT__C10 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16008817055237475286ull);
    vlSelf->controller_tb__DOT__C11 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4239087577188906389ull);
    vlSelf->controller_tb__DOT__C12 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15971396939789390537ull);
    vlSelf->controller_tb__DOT__C13 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12061852308386103165ull);
    vlSelf->controller_tb__DOT__C14 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13147471583491365494ull);
    vlSelf->controller_tb__DOT__C15 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9268036186281796390ull);
    vlSelf->controller_tb__DOT__C16 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15709097905887295895ull);
    vlSelf->controller_tb__DOT__C17 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9912315858520504015ull);
    vlSelf->controller_tb__DOT__C20 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14006254107230597458ull);
    vlSelf->controller_tb__DOT__C21 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6734399732611959316ull);
    vlSelf->controller_tb__DOT__C22 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1205076325457092212ull);
    vlSelf->controller_tb__DOT__C23 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6692491474257476571ull);
    vlSelf->controller_tb__DOT__C24 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8186777309945721869ull);
    vlSelf->controller_tb__DOT__C25 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18038872820738929025ull);
    vlSelf->controller_tb__DOT__C26 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10584003991474719712ull);
    vlSelf->controller_tb__DOT__C27 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7462990444701107114ull);
    vlSelf->controller_tb__DOT__C30 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13299904118258678815ull);
    vlSelf->controller_tb__DOT__C31 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15674754201244393865ull);
    vlSelf->controller_tb__DOT__C32 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14774168097372541241ull);
    vlSelf->controller_tb__DOT__C33 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4394709052704632ull);
    vlSelf->controller_tb__DOT__C34 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11112412974276383825ull);
    vlSelf->controller_tb__DOT__C35 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7496009742925164151ull);
    vlSelf->controller_tb__DOT__C36 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9164466893161566619ull);
    vlSelf->controller_tb__DOT__C37 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12682869007397445332ull);
    vlSelf->controller_tb__DOT__C40 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18014805021661895123ull);
    vlSelf->controller_tb__DOT__C41 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15920758409521129048ull);
    vlSelf->controller_tb__DOT__C42 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13580015506872376415ull);
    vlSelf->controller_tb__DOT__C43 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4016250775472400817ull);
    vlSelf->controller_tb__DOT__C44 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10798426937139320701ull);
    vlSelf->controller_tb__DOT__C45 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8934935554424195280ull);
    vlSelf->controller_tb__DOT__C46 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12813456553037717108ull);
    vlSelf->controller_tb__DOT__C47 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11715808278848819679ull);
    vlSelf->controller_tb__DOT__C50 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4535708848430323925ull);
    vlSelf->controller_tb__DOT__C51 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11508656748214542774ull);
    vlSelf->controller_tb__DOT__C52 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12729786019693664134ull);
    vlSelf->controller_tb__DOT__C53 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5902114307732553590ull);
    vlSelf->controller_tb__DOT__C54 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13763241939813881323ull);
    vlSelf->controller_tb__DOT__C55 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6240476901250205819ull);
    vlSelf->controller_tb__DOT__C56 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10035101840594955126ull);
    vlSelf->controller_tb__DOT__C57 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16997695367105004309ull);
    vlSelf->controller_tb__DOT__C60 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17128368271251458333ull);
    vlSelf->controller_tb__DOT__C61 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 670148703652595ull);
    vlSelf->controller_tb__DOT__C62 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8582600962485359967ull);
    vlSelf->controller_tb__DOT__C63 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17197388532626869681ull);
    vlSelf->controller_tb__DOT__C64 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10397838172548037967ull);
    vlSelf->controller_tb__DOT__C65 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2620239740077915892ull);
    vlSelf->controller_tb__DOT__C66 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17931101242934940658ull);
    vlSelf->controller_tb__DOT__C67 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16421499980950066175ull);
    vlSelf->controller_tb__DOT__C70 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8583203022832422019ull);
    vlSelf->controller_tb__DOT__C71 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12300390054119431523ull);
    vlSelf->controller_tb__DOT__C72 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8228857865993063470ull);
    vlSelf->controller_tb__DOT__C73 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14338107646121330551ull);
    vlSelf->controller_tb__DOT__C74 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6060127641774716302ull);
    vlSelf->controller_tb__DOT__C75 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4705172220982288231ull);
    vlSelf->controller_tb__DOT__C76 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8291364494059668353ull);
    vlSelf->controller_tb__DOT__C77 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9321085724672766645ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->controller_tb__DOT__expected[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7518794288613127693ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->controller_tb__DOT__actual[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13319982680111047306ull);
        }
    }
    vlSelf->controller_tb__DOT__uut__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11607029959601875667ull);
    vlSelf->controller_tb__DOT__uut__DOT__compute_counter = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8694864133278139956ull);
    vlSelf->controller_tb__DOT__uut__DOT__sys_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14909093743235451119ull);
    vlSelf->controller_tb__DOT__uut__DOT__sys_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 877301193126234559ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->controller_tb__DOT__uut__DOT__array__DOT__A_matrix[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12476237408917674086ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->controller_tb__DOT__uut__DOT__array__DOT__B_matrix[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12290751343619235290ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 9; ++__Vi1) {
            vlSelf->controller_tb__DOT__uut__DOT__array__DOT__A_wire[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2287759729364338521ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 9; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->controller_tb__DOT__uut__DOT__array__DOT__B_wire[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10514656048896420126ull);
        }
    }
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT__cycle = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2899865318968902251ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->controller_tb__DOT__uut__DOT__array__DOT__A_feed[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15126808575606188683ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->controller_tb__DOT__uut__DOT__array__DOT__B_feed[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16282122022926367093ull);
    }
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe00__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe00__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe01__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe01__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe02__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe02__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe03__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe03__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe04__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe04__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe05__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe05__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe06__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe06__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe07__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe07__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe10__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe10__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe11__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe11__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe12__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe12__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe13__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe13__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe14__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe14__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe15__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe15__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe16__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe16__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe17__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe17__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe20__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe20__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe21__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe21__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe22__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe22__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe23__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe23__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe24__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe24__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe25__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe25__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe26__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe26__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe27__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe27__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe30__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe30__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe31__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe31__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe32__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe32__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe33__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe33__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe34__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe34__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe35__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe35__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe36__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe36__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe37__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe37__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe40__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe40__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe41__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe41__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe42__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe42__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe43__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe43__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe44__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe44__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe45__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe45__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe46__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe46__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe47__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe47__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe50__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe50__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe51__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe51__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe52__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe52__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe53__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe53__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe54__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe54__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe55__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe55__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe56__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe56__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe57__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe57__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe60__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe60__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe61__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe61__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe62__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe62__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe63__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe63__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe64__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe64__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe65__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe65__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe66__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe66__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe67__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe67__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe70__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe70__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe71__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe71__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe72__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe72__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe73__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe73__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe74__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe74__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe75__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe75__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe76__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe76__A_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe77__B_out = 0;
    vlSelf->controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe77__A_out = 0;
    vlSelf->__Vdly__controller_tb__DOT__uut__DOT__state = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__controller_tb__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__controller_tb__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__controller_tb__DOT__done__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
