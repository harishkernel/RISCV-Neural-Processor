// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpe_tb.h for the primary calling header

#ifndef VERILATED_VPE_TB___024ROOT_H_
#define VERILATED_VPE_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vpe_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vpe_tb___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ pe_tb__DOT__clk;
    CData/*0:0*/ pe_tb__DOT__reset;
    CData/*0:0*/ pe_tb__DOT__enable;
    CData/*7:0*/ pe_tb__DOT__A_in;
    CData/*7:0*/ pe_tb__DOT__B_in;
    CData/*7:0*/ pe_tb__DOT__A_out;
    CData/*7:0*/ pe_tb__DOT__B_out;
    CData/*0:0*/ __Vtrigprevexpr___TOP__pe_tb__DOT__clk__0;
    IData/*31:0*/ pe_tb__DOT__acc_out;
    IData/*31:0*/ pe_tb__DOT__errors;
    IData/*31:0*/ __Vi;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h2e34af0c__0;

    // INTERNAL VARIABLES
    Vpe_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vpe_tb___024root(Vpe_tb__Syms* symsp, const char* namep);
    ~Vpe_tb___024root();
    VL_UNCOPYABLE(Vpe_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
