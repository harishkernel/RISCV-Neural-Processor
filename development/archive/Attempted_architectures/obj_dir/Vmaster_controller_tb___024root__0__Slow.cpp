// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmaster_controller_tb.h for the primary calling header

#include "Vmaster_controller_tb__pch.h"

void Vmaster_controller_tb___024root___timing_ready(Vmaster_controller_tb___024root* vlSelf);

VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_static(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_static\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_static__TOP
        const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
        vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__n = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7760834103631805901ull);
        vlSelfRef.master_controller_tb__DOT__load_tile__Vstatic__idx = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11614729831637804972ull);
        vlSelfRef.master_controller_tb__DOT__verify_results__Vstatic__local_errors = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6222629320926271576ull);
    }
    vlSelfRef.__VactTriggered[0U] = (8ULL | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__Vtrigprevexpr___TOP__master_controller_tb__DOT__clk__0 
        = vlSelfRef.master_controller_tb__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__master_controller_tb__DOT__rst_n__0 
        = vlSelfRef.master_controller_tb__DOT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__master_controller_tb__DOT__dut__DOT__ctrl_done__0 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_done;
    Vmaster_controller_tb___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmaster_controller_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vmaster_controller_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);
VL_ATTR_COLD void Vmaster_controller_tb___024root___stl_sequent__TOP__0(Vmaster_controller_tb___024root* vlSelf);

VL_ATTR_COLD bool Vmaster_controller_tb___024root___eval_stl(Vmaster_controller_tb___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_stl\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmaster_controller_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vmaster_controller_tb___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vmaster_controller_tb___024root___stl_sequent__TOP__0(vlSelf);
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_dump_triggers__stl(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_dump_triggers__stl\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vmaster_controller_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmaster_controller_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_dump_triggers__ico(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_dump_triggers__ico\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vmaster_controller_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmaster_controller_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_dump_triggers__act(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_dump_triggers__act\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vmaster_controller_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_dump_triggers__nba(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_dump_triggers__nba\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vmaster_controller_tb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_dump_triggers__obs(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_dump_triggers__obs\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_dump_triggers__react(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_dump_triggers__react\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_final(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_final\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_initial__TOP(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___eval_initial__TOP\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.master_controller_tb__DOT__clk = 0U;
    vlSelfRef.master_controller_tb__DOT__expected[0U][0U] = 0x000000ccU;
    vlSelfRef.master_controller_tb__DOT__expected[0U][1U] = 0x000000f0U;
    vlSelfRef.master_controller_tb__DOT__expected[0U][2U] = 0x00000114U;
    vlSelfRef.master_controller_tb__DOT__expected[0U][3U] = 0x00000138U;
    vlSelfRef.master_controller_tb__DOT__expected[0U][4U] = 0x0000015cU;
    vlSelfRef.master_controller_tb__DOT__expected[0U][5U] = 0x00000180U;
    vlSelfRef.master_controller_tb__DOT__expected[0U][6U] = 0x000001a4U;
    vlSelfRef.master_controller_tb__DOT__expected[0U][7U] = 0x000001c8U;
    vlSelfRef.master_controller_tb__DOT__expected[1U][0U] = 0x000000f0U;
    vlSelfRef.master_controller_tb__DOT__expected[1U][1U] = 0x0000011cU;
    vlSelfRef.master_controller_tb__DOT__expected[1U][2U] = 0x00000148U;
    vlSelfRef.master_controller_tb__DOT__expected[1U][3U] = 0x00000174U;
    vlSelfRef.master_controller_tb__DOT__expected[1U][4U] = 0x000001a0U;
    vlSelfRef.master_controller_tb__DOT__expected[1U][5U] = 0x000001ccU;
    vlSelfRef.master_controller_tb__DOT__expected[1U][6U] = 0x000001f8U;
    vlSelfRef.master_controller_tb__DOT__expected[1U][7U] = 0x00000224U;
    vlSelfRef.master_controller_tb__DOT__expected[2U][0U] = 0x00000114U;
    vlSelfRef.master_controller_tb__DOT__expected[2U][1U] = 0x00000148U;
    vlSelfRef.master_controller_tb__DOT__expected[2U][2U] = 0x0000017cU;
    vlSelfRef.master_controller_tb__DOT__expected[2U][3U] = 0x000001b0U;
    vlSelfRef.master_controller_tb__DOT__expected[2U][4U] = 0x000001e4U;
    vlSelfRef.master_controller_tb__DOT__expected[2U][5U] = 0x00000218U;
    vlSelfRef.master_controller_tb__DOT__expected[2U][6U] = 0x0000024cU;
    vlSelfRef.master_controller_tb__DOT__expected[2U][7U] = 0x00000280U;
    vlSelfRef.master_controller_tb__DOT__expected[3U][0U] = 0x00000138U;
    vlSelfRef.master_controller_tb__DOT__expected[3U][1U] = 0x00000174U;
    vlSelfRef.master_controller_tb__DOT__expected[3U][2U] = 0x000001b0U;
    vlSelfRef.master_controller_tb__DOT__expected[3U][3U] = 0x000001ecU;
    vlSelfRef.master_controller_tb__DOT__expected[3U][4U] = 0x00000228U;
    vlSelfRef.master_controller_tb__DOT__expected[3U][5U] = 0x00000264U;
    vlSelfRef.master_controller_tb__DOT__expected[3U][6U] = 0x000002a0U;
    vlSelfRef.master_controller_tb__DOT__expected[3U][7U] = 0x000002dcU;
    vlSelfRef.master_controller_tb__DOT__expected[4U][0U] = 0x0000015cU;
    vlSelfRef.master_controller_tb__DOT__expected[4U][1U] = 0x000001a0U;
    vlSelfRef.master_controller_tb__DOT__expected[4U][2U] = 0x000001e4U;
    vlSelfRef.master_controller_tb__DOT__expected[4U][3U] = 0x00000228U;
    vlSelfRef.master_controller_tb__DOT__expected[4U][4U] = 0x0000026cU;
    vlSelfRef.master_controller_tb__DOT__expected[4U][5U] = 0x000002b0U;
    vlSelfRef.master_controller_tb__DOT__expected[4U][6U] = 0x000002f4U;
    vlSelfRef.master_controller_tb__DOT__expected[4U][7U] = 0x00000338U;
    vlSelfRef.master_controller_tb__DOT__expected[5U][0U] = 0x00000180U;
    vlSelfRef.master_controller_tb__DOT__expected[5U][1U] = 0x000001ccU;
    vlSelfRef.master_controller_tb__DOT__expected[5U][2U] = 0x00000218U;
    vlSelfRef.master_controller_tb__DOT__expected[5U][3U] = 0x00000264U;
    vlSelfRef.master_controller_tb__DOT__expected[5U][4U] = 0x000002b0U;
    vlSelfRef.master_controller_tb__DOT__expected[5U][5U] = 0x000002fcU;
    vlSelfRef.master_controller_tb__DOT__expected[5U][6U] = 0x00000348U;
    vlSelfRef.master_controller_tb__DOT__expected[5U][7U] = 0x00000394U;
    vlSelfRef.master_controller_tb__DOT__expected[6U][0U] = 0x000001a4U;
    vlSelfRef.master_controller_tb__DOT__expected[6U][1U] = 0x000001f8U;
    vlSelfRef.master_controller_tb__DOT__expected[6U][2U] = 0x0000024cU;
    vlSelfRef.master_controller_tb__DOT__expected[6U][3U] = 0x000002a0U;
    vlSelfRef.master_controller_tb__DOT__expected[6U][4U] = 0x000002f4U;
    vlSelfRef.master_controller_tb__DOT__expected[6U][5U] = 0x00000348U;
    vlSelfRef.master_controller_tb__DOT__expected[6U][6U] = 0x0000039cU;
    vlSelfRef.master_controller_tb__DOT__expected[6U][7U] = 0x000003f0U;
    vlSelfRef.master_controller_tb__DOT__expected[7U][0U] = 0x000001c8U;
    vlSelfRef.master_controller_tb__DOT__expected[7U][1U] = 0x00000224U;
    vlSelfRef.master_controller_tb__DOT__expected[7U][2U] = 0x00000280U;
    vlSelfRef.master_controller_tb__DOT__expected[7U][3U] = 0x000002dcU;
    vlSelfRef.master_controller_tb__DOT__expected[7U][4U] = 0x00000338U;
    vlSelfRef.master_controller_tb__DOT__expected[7U][5U] = 0x00000394U;
    vlSelfRef.master_controller_tb__DOT__expected[7U][6U] = 0x000003f0U;
    vlSelfRef.master_controller_tb__DOT__expected[7U][7U] = 0x0000044cU;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmaster_controller_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vmaster_controller_tb___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vmaster_controller_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vmaster_controller_tb___024root___stl_sequent__TOP__0(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___stl_sequent__TOP__0\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<16>/*511:0*/ master_controller_tb__DOT__dut__DOT__A_buf;
    VL_ZERO_W(512, master_controller_tb__DOT__dut__DOT__A_buf);
    VlWide<16>/*511:0*/ master_controller_tb__DOT__dut__DOT__B_buf;
    VL_ZERO_W(512, master_controller_tb__DOT__dut__DOT__B_buf);
    // Body
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel_next 
        = ((2U != (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st)) 
           & ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel) 
              | (2U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st))));
    vlSelfRef.master_controller_tb__DOT__dut__DOT__buf_compute_valid 
        = ((2U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st)) 
           | (2U == (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st)));
    vlSelfRef.master_controller_tb__DOT__C[0U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C00;
    vlSelfRef.master_controller_tb__DOT__C[0U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C01;
    vlSelfRef.master_controller_tb__DOT__C[0U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C02;
    vlSelfRef.master_controller_tb__DOT__C[0U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C03;
    vlSelfRef.master_controller_tb__DOT__C[0U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C04;
    vlSelfRef.master_controller_tb__DOT__C[0U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C05;
    vlSelfRef.master_controller_tb__DOT__C[0U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C06;
    vlSelfRef.master_controller_tb__DOT__C[0U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C07;
    vlSelfRef.master_controller_tb__DOT__C[1U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C10;
    vlSelfRef.master_controller_tb__DOT__C[1U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C11;
    vlSelfRef.master_controller_tb__DOT__C[1U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C12;
    vlSelfRef.master_controller_tb__DOT__C[1U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C13;
    vlSelfRef.master_controller_tb__DOT__C[1U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C14;
    vlSelfRef.master_controller_tb__DOT__C[1U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C15;
    vlSelfRef.master_controller_tb__DOT__C[1U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C16;
    vlSelfRef.master_controller_tb__DOT__C[1U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C17;
    vlSelfRef.master_controller_tb__DOT__C[2U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C20;
    vlSelfRef.master_controller_tb__DOT__C[2U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C21;
    vlSelfRef.master_controller_tb__DOT__C[2U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C22;
    vlSelfRef.master_controller_tb__DOT__C[2U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C23;
    vlSelfRef.master_controller_tb__DOT__C[2U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C24;
    vlSelfRef.master_controller_tb__DOT__C[2U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C25;
    vlSelfRef.master_controller_tb__DOT__C[2U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C26;
    vlSelfRef.master_controller_tb__DOT__C[2U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C27;
    vlSelfRef.master_controller_tb__DOT__C[3U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C30;
    vlSelfRef.master_controller_tb__DOT__C[3U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C31;
    vlSelfRef.master_controller_tb__DOT__C[3U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C32;
    vlSelfRef.master_controller_tb__DOT__C[3U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C33;
    vlSelfRef.master_controller_tb__DOT__C[3U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C34;
    vlSelfRef.master_controller_tb__DOT__C[3U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C35;
    vlSelfRef.master_controller_tb__DOT__C[3U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C36;
    vlSelfRef.master_controller_tb__DOT__C[3U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C37;
    vlSelfRef.master_controller_tb__DOT__C[4U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C40;
    vlSelfRef.master_controller_tb__DOT__C[4U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C41;
    vlSelfRef.master_controller_tb__DOT__C[4U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C42;
    vlSelfRef.master_controller_tb__DOT__C[4U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C43;
    vlSelfRef.master_controller_tb__DOT__C[4U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C44;
    vlSelfRef.master_controller_tb__DOT__C[4U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C45;
    vlSelfRef.master_controller_tb__DOT__C[4U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C46;
    vlSelfRef.master_controller_tb__DOT__C[4U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C47;
    vlSelfRef.master_controller_tb__DOT__C[5U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C50;
    vlSelfRef.master_controller_tb__DOT__C[5U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C51;
    vlSelfRef.master_controller_tb__DOT__C[5U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C52;
    vlSelfRef.master_controller_tb__DOT__C[5U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C53;
    vlSelfRef.master_controller_tb__DOT__C[5U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C54;
    vlSelfRef.master_controller_tb__DOT__C[5U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C55;
    vlSelfRef.master_controller_tb__DOT__C[5U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C56;
    vlSelfRef.master_controller_tb__DOT__C[5U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C57;
    vlSelfRef.master_controller_tb__DOT__C[6U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C60;
    vlSelfRef.master_controller_tb__DOT__C[6U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C61;
    vlSelfRef.master_controller_tb__DOT__C[6U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C62;
    vlSelfRef.master_controller_tb__DOT__C[6U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C63;
    vlSelfRef.master_controller_tb__DOT__C[6U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C64;
    vlSelfRef.master_controller_tb__DOT__C[6U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C65;
    vlSelfRef.master_controller_tb__DOT__C[6U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C66;
    vlSelfRef.master_controller_tb__DOT__C[6U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C67;
    vlSelfRef.master_controller_tb__DOT__C[7U][0U] 
        = vlSelfRef.master_controller_tb__DOT__C70;
    vlSelfRef.master_controller_tb__DOT__C[7U][1U] 
        = vlSelfRef.master_controller_tb__DOT__C71;
    vlSelfRef.master_controller_tb__DOT__C[7U][2U] 
        = vlSelfRef.master_controller_tb__DOT__C72;
    vlSelfRef.master_controller_tb__DOT__C[7U][3U] 
        = vlSelfRef.master_controller_tb__DOT__C73;
    vlSelfRef.master_controller_tb__DOT__C[7U][4U] 
        = vlSelfRef.master_controller_tb__DOT__C74;
    vlSelfRef.master_controller_tb__DOT__C[7U][5U] 
        = vlSelfRef.master_controller_tb__DOT__C75;
    vlSelfRef.master_controller_tb__DOT__C[7U][6U] 
        = vlSelfRef.master_controller_tb__DOT__C76;
    vlSelfRef.master_controller_tb__DOT__C[7U][7U] 
        = vlSelfRef.master_controller_tb__DOT__C77;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe00__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe00__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe01__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe01__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe02__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe02__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe03__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe03__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe04__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe04__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe05__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe05__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe06__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe06__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[1U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe07__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[0U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe07__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe10__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe10__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe11__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe11__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe12__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe12__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe13__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe13__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe14__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe14__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe15__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe15__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe16__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe16__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[2U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe17__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[1U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe17__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe20__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe20__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe21__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe21__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe22__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe22__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe23__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe23__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe24__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe24__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe25__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe25__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe26__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe26__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[3U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe27__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[2U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe27__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe30__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe30__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe31__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe31__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe32__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe32__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe33__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe33__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe34__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe34__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe35__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe35__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe36__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe36__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[4U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe37__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[3U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe37__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe40__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe40__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe41__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe41__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe42__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe42__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe43__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe43__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe44__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe44__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe45__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe45__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe46__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe46__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[5U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe47__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[4U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe47__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe50__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe50__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe51__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe51__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe52__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe52__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe53__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe53__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe54__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe54__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe55__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe55__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe56__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe56__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[6U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe57__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[5U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe57__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe60__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe60__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe61__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe61__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe62__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe62__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe63__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe63__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe64__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe64__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe65__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe65__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe66__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe66__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[7U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe67__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[6U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe67__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][0U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe70__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe70__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][1U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe71__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe71__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][2U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe72__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe72__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][3U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe73__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe73__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][4U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe74__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe74__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][5U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe75__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe75__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][6U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe76__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe76__A_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[8U][7U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe77__B_out;
    vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[7U][8U] 
        = vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe77__A_out;
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
    vlSelfRef.master_controller_tb__DOT__dut__DOT__safe_compute_start 
        = ((IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__buf_compute_valid) 
           & ((~ (IData)(vlSelfRef.master_controller_tb__DOT__dut__DOT__ctrl_busy)) 
              & (IData)(vlSelfRef.master_controller_tb__DOT__compute_start)));
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

bool Vmaster_controller_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmaster_controller_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vmaster_controller_tb___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vmaster_controller_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmaster_controller_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vmaster_controller_tb___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge master_controller_tb.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge master_controller_tb.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( master_controller_tb.dut.ctrl_done)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmaster_controller_tb___024root___ctor_var_reset(Vmaster_controller_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster_controller_tb___024root___ctor_var_reset\n"); );
    Vmaster_controller_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->master_controller_tb__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10821848557661051010ull);
    vlSelf->master_controller_tb__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 440750747499029539ull);
    vlSelf->master_controller_tb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2732296313637432719ull);
    vlSelf->master_controller_tb__DOT__wr_addr = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 6686336552462329496ull);
    vlSelf->master_controller_tb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 677211941172933246ull);
    vlSelf->master_controller_tb__DOT__load_done_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14697993850858752798ull);
    vlSelf->master_controller_tb__DOT__compute_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17046605092621471558ull);
    vlSelf->master_controller_tb__DOT__C00 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7525868985504035161ull);
    vlSelf->master_controller_tb__DOT__C01 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13563729938647669103ull);
    vlSelf->master_controller_tb__DOT__C02 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 853828380136582327ull);
    vlSelf->master_controller_tb__DOT__C03 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9529932700547061704ull);
    vlSelf->master_controller_tb__DOT__C04 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8250476496967434297ull);
    vlSelf->master_controller_tb__DOT__C05 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17490043508640509676ull);
    vlSelf->master_controller_tb__DOT__C06 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10618373357527661616ull);
    vlSelf->master_controller_tb__DOT__C07 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11426007877267207283ull);
    vlSelf->master_controller_tb__DOT__C10 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7199689983144324916ull);
    vlSelf->master_controller_tb__DOT__C11 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10147423465671929348ull);
    vlSelf->master_controller_tb__DOT__C12 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9578987433797546187ull);
    vlSelf->master_controller_tb__DOT__C13 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7952786042056149660ull);
    vlSelf->master_controller_tb__DOT__C14 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4123624933397315346ull);
    vlSelf->master_controller_tb__DOT__C15 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16554459387953751323ull);
    vlSelf->master_controller_tb__DOT__C16 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14575886189022275121ull);
    vlSelf->master_controller_tb__DOT__C17 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11553615508546477056ull);
    vlSelf->master_controller_tb__DOT__C20 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7432054443285948196ull);
    vlSelf->master_controller_tb__DOT__C21 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1597216221961250973ull);
    vlSelf->master_controller_tb__DOT__C22 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13946712648270896122ull);
    vlSelf->master_controller_tb__DOT__C23 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10089524577909387658ull);
    vlSelf->master_controller_tb__DOT__C24 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6226006508227042468ull);
    vlSelf->master_controller_tb__DOT__C25 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6352803981206430541ull);
    vlSelf->master_controller_tb__DOT__C26 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9532645665961365026ull);
    vlSelf->master_controller_tb__DOT__C27 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5543905827534096315ull);
    vlSelf->master_controller_tb__DOT__C30 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11412054449212896774ull);
    vlSelf->master_controller_tb__DOT__C31 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6573263072896560467ull);
    vlSelf->master_controller_tb__DOT__C32 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9570227690983418136ull);
    vlSelf->master_controller_tb__DOT__C33 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7771572258218506450ull);
    vlSelf->master_controller_tb__DOT__C34 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17208493880318282557ull);
    vlSelf->master_controller_tb__DOT__C35 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5709742945158208058ull);
    vlSelf->master_controller_tb__DOT__C36 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7099189263159221453ull);
    vlSelf->master_controller_tb__DOT__C37 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 489595475700371396ull);
    vlSelf->master_controller_tb__DOT__C40 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16729231841647800254ull);
    vlSelf->master_controller_tb__DOT__C41 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4407771528375874923ull);
    vlSelf->master_controller_tb__DOT__C42 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7855621435267792756ull);
    vlSelf->master_controller_tb__DOT__C43 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2418620363055308366ull);
    vlSelf->master_controller_tb__DOT__C44 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18430459720356480882ull);
    vlSelf->master_controller_tb__DOT__C45 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18305974684125188339ull);
    vlSelf->master_controller_tb__DOT__C46 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11264202316530214391ull);
    vlSelf->master_controller_tb__DOT__C47 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8709087048445752927ull);
    vlSelf->master_controller_tb__DOT__C50 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12176234220446085927ull);
    vlSelf->master_controller_tb__DOT__C51 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6424749915818996241ull);
    vlSelf->master_controller_tb__DOT__C52 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10416153999543422761ull);
    vlSelf->master_controller_tb__DOT__C53 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3392599498201776500ull);
    vlSelf->master_controller_tb__DOT__C54 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2188648678835565095ull);
    vlSelf->master_controller_tb__DOT__C55 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5116041592104069215ull);
    vlSelf->master_controller_tb__DOT__C56 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6026705845932648549ull);
    vlSelf->master_controller_tb__DOT__C57 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9138882710444461106ull);
    vlSelf->master_controller_tb__DOT__C60 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9939863327193713924ull);
    vlSelf->master_controller_tb__DOT__C61 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 930769413823523967ull);
    vlSelf->master_controller_tb__DOT__C62 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12444738319316818157ull);
    vlSelf->master_controller_tb__DOT__C63 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16428791986786946197ull);
    vlSelf->master_controller_tb__DOT__C64 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17046882776563238297ull);
    vlSelf->master_controller_tb__DOT__C65 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11877833010902342132ull);
    vlSelf->master_controller_tb__DOT__C66 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12692122377699879779ull);
    vlSelf->master_controller_tb__DOT__C67 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8486590620802182118ull);
    vlSelf->master_controller_tb__DOT__C70 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18310671332767945359ull);
    vlSelf->master_controller_tb__DOT__C71 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5209557520478628ull);
    vlSelf->master_controller_tb__DOT__C72 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14025403351926007232ull);
    vlSelf->master_controller_tb__DOT__C73 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7326837984636987085ull);
    vlSelf->master_controller_tb__DOT__C74 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10549836342218118469ull);
    vlSelf->master_controller_tb__DOT__C75 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18026360164539596346ull);
    vlSelf->master_controller_tb__DOT__C76 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8072048011376049454ull);
    vlSelf->master_controller_tb__DOT__C77 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1368645834818994225ull);
    vlSelf->master_controller_tb__DOT__cycle_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3990448546122381211ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->master_controller_tb__DOT__expected[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12930724426103823563ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->master_controller_tb__DOT__C[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10517340157300893537ull);
        }
    }
    vlSelf->master_controller_tb__DOT__dut__DOT__buf_compute_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1459638703130981675ull);
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11453696696160007025ull);
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10127631274580022288ull);
    vlSelf->master_controller_tb__DOT__dut__DOT__safe_compute_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5992225406730940301ull);
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1458783472514218314ull);
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__compute_counter = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5498756712176013872ull);
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__sys_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8221806086962938924ull);
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__sys_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11134919999279356476ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_matrix[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1587213231963640307ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_matrix[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3732742690005423078ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 9; ++__Vi1) {
            vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_wire[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 761249452053441597ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 9; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_wire[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15922898273857373784ull);
        }
    }
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__cycle = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4951939865738734930ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__A_feed[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14535440506871442428ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT__B_feed[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13530975847939180054ull);
    }
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe00__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe00__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe01__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe01__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe02__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe02__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe03__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe03__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe04__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe04__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe05__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe05__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe06__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe06__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe07__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe07__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe10__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe10__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe11__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe11__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe12__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe12__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe13__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe13__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe14__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe14__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe15__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe15__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe16__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe16__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe17__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe17__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe20__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe20__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe21__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe21__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe22__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe22__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe23__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe23__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe24__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe24__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe25__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe25__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe26__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe26__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe27__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe27__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe30__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe30__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe31__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe31__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe32__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe32__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe33__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe33__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe34__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe34__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe35__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe35__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe36__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe36__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe37__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe37__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe40__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe40__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe41__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe41__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe42__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe42__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe43__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe43__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe44__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe44__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe45__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe45__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe46__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe46__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe47__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe47__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe50__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe50__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe51__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe51__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe52__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe52__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe53__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe53__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe54__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe54__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe55__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe55__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe56__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe56__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe57__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe57__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe60__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe60__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe61__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe61__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe62__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe62__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe63__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe63__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe64__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe64__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe65__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe65__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe66__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe66__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe67__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe67__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe70__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe70__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe71__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe71__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe72__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe72__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe73__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe73__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe74__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe74__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe75__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe75__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe76__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe76__A_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe77__B_out = 0;
    vlSelf->master_controller_tb__DOT__dut__DOT__ctrl__DOT__array__DOT____Vcellout__pe77__A_out = 0;
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_mem[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12441417914034780086ull);
    }
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_mem[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17867331427108354445ull);
    }
    vlSelf->master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_st = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6872013949981407554ull);
    vlSelf->master_controller_tb__DOT__dut__DOT__ppb__DOT__pong_st = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12229943406385934543ull);
    vlSelf->master_controller_tb__DOT__dut__DOT__ppb__DOT__load_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15361914554048900073ull);
    vlSelf->master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7462216077977979167ull);
    vlSelf->master_controller_tb__DOT__dut__DOT__ppb__DOT__ping_loaded_since_compute_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11161627165533188668ull);
    vlSelf->master_controller_tb__DOT__dut__DOT__ppb__DOT__compute_sel_next = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10200020692256122853ull);
    vlSelf->__Vdly__master_controller_tb__DOT__dut__DOT__ctrl__DOT__state = 0;
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
    vlSelf->__Vtrigprevexpr___TOP__master_controller_tb__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__master_controller_tb__DOT__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__master_controller_tb__DOT__dut__DOT__ctrl_done__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
