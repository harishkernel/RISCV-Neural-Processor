// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcontroller_tb.h for the primary calling header

#ifndef VERILATED_VCONTROLLER_TB___024ROOT_H_
#define VERILATED_VCONTROLLER_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vcontroller_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vcontroller_tb___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ controller_tb__DOT__clk;
        CData/*0:0*/ controller_tb__DOT__rst_n;
        CData/*0:0*/ controller_tb__DOT__start;
        CData/*0:0*/ controller_tb__DOT__done;
        CData/*0:0*/ controller_tb__DOT__busy;
        CData/*1:0*/ controller_tb__DOT__uut__DOT__state;
        CData/*4:0*/ controller_tb__DOT__uut__DOT__compute_counter;
        CData/*0:0*/ controller_tb__DOT__uut__DOT__sys_reset;
        CData/*0:0*/ controller_tb__DOT__uut__DOT__sys_enable;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe00__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe00__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe01__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe01__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe02__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe02__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe03__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe03__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe04__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe04__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe05__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe05__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe06__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe06__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe07__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe07__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe10__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe10__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe11__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe11__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe12__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe12__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe13__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe13__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe14__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe14__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe15__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe15__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe16__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe16__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe17__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe17__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe20__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe20__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe21__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe21__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe22__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe22__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe23__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe23__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe24__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe24__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe25__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe25__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe26__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe26__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe27__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe27__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe30__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe30__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe31__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe31__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe32__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe32__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe33__B_out;
    };
    struct {
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe33__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe34__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe34__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe35__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe35__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe36__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe36__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe37__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe37__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe40__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe40__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe41__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe41__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe42__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe42__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe43__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe43__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe44__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe44__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe45__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe45__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe46__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe46__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe47__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe47__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe50__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe50__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe51__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe51__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe52__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe52__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe53__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe53__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe54__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe54__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe55__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe55__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe56__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe56__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe57__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe57__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe60__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe60__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe61__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe61__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe62__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe62__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe63__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe63__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe64__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe64__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe65__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe65__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe66__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe66__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe67__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe67__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe70__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe70__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe71__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe71__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe72__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe72__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe73__B_out;
    };
    struct {
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe73__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe74__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe74__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe75__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe75__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe76__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe76__A_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe77__B_out;
        CData/*7:0*/ controller_tb__DOT__uut__DOT__array__DOT____Vcellout__pe77__A_out;
        CData/*1:0*/ __Vdly__controller_tb__DOT__uut__DOT__state;
        CData/*0:0*/ __Vtrigprevexpr___TOP__controller_tb__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__controller_tb__DOT__rst_n__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__controller_tb__DOT__done__0;
        VlWide<16>/*511:0*/ controller_tb__DOT__A_flat;
        VlWide<16>/*511:0*/ controller_tb__DOT__B_flat;
        IData/*31:0*/ controller_tb__DOT__cycle_count;
        IData/*31:0*/ controller_tb__DOT__C00;
        IData/*31:0*/ controller_tb__DOT__C01;
        IData/*31:0*/ controller_tb__DOT__C02;
        IData/*31:0*/ controller_tb__DOT__C03;
        IData/*31:0*/ controller_tb__DOT__C04;
        IData/*31:0*/ controller_tb__DOT__C05;
        IData/*31:0*/ controller_tb__DOT__C06;
        IData/*31:0*/ controller_tb__DOT__C07;
        IData/*31:0*/ controller_tb__DOT__C10;
        IData/*31:0*/ controller_tb__DOT__C11;
        IData/*31:0*/ controller_tb__DOT__C12;
        IData/*31:0*/ controller_tb__DOT__C13;
        IData/*31:0*/ controller_tb__DOT__C14;
        IData/*31:0*/ controller_tb__DOT__C15;
        IData/*31:0*/ controller_tb__DOT__C16;
        IData/*31:0*/ controller_tb__DOT__C17;
        IData/*31:0*/ controller_tb__DOT__C20;
        IData/*31:0*/ controller_tb__DOT__C21;
        IData/*31:0*/ controller_tb__DOT__C22;
        IData/*31:0*/ controller_tb__DOT__C23;
        IData/*31:0*/ controller_tb__DOT__C24;
        IData/*31:0*/ controller_tb__DOT__C25;
        IData/*31:0*/ controller_tb__DOT__C26;
        IData/*31:0*/ controller_tb__DOT__C27;
        IData/*31:0*/ controller_tb__DOT__C30;
        IData/*31:0*/ controller_tb__DOT__C31;
        IData/*31:0*/ controller_tb__DOT__C32;
        IData/*31:0*/ controller_tb__DOT__C33;
        IData/*31:0*/ controller_tb__DOT__C34;
        IData/*31:0*/ controller_tb__DOT__C35;
        IData/*31:0*/ controller_tb__DOT__C36;
        IData/*31:0*/ controller_tb__DOT__C37;
        IData/*31:0*/ controller_tb__DOT__C40;
        IData/*31:0*/ controller_tb__DOT__C41;
        IData/*31:0*/ controller_tb__DOT__C42;
        IData/*31:0*/ controller_tb__DOT__C43;
        IData/*31:0*/ controller_tb__DOT__C44;
        IData/*31:0*/ controller_tb__DOT__C45;
        IData/*31:0*/ controller_tb__DOT__C46;
        IData/*31:0*/ controller_tb__DOT__C47;
        IData/*31:0*/ controller_tb__DOT__C50;
        IData/*31:0*/ controller_tb__DOT__C51;
        IData/*31:0*/ controller_tb__DOT__C52;
        IData/*31:0*/ controller_tb__DOT__C53;
        IData/*31:0*/ controller_tb__DOT__C54;
        IData/*31:0*/ controller_tb__DOT__C55;
        IData/*31:0*/ controller_tb__DOT__C56;
        IData/*31:0*/ controller_tb__DOT__C57;
    };
    struct {
        IData/*31:0*/ controller_tb__DOT__C60;
        IData/*31:0*/ controller_tb__DOT__C61;
        IData/*31:0*/ controller_tb__DOT__C62;
        IData/*31:0*/ controller_tb__DOT__C63;
        IData/*31:0*/ controller_tb__DOT__C64;
        IData/*31:0*/ controller_tb__DOT__C65;
        IData/*31:0*/ controller_tb__DOT__C66;
        IData/*31:0*/ controller_tb__DOT__C67;
        IData/*31:0*/ controller_tb__DOT__C70;
        IData/*31:0*/ controller_tb__DOT__C71;
        IData/*31:0*/ controller_tb__DOT__C72;
        IData/*31:0*/ controller_tb__DOT__C73;
        IData/*31:0*/ controller_tb__DOT__C74;
        IData/*31:0*/ controller_tb__DOT__C75;
        IData/*31:0*/ controller_tb__DOT__C76;
        IData/*31:0*/ controller_tb__DOT__C77;
        IData/*31:0*/ controller_tb__DOT__uut__DOT__array__DOT__cycle;
        IData/*31:0*/ __Vi;
        VlUnpacked<VlUnpacked<IData/*31:0*/, 8>, 8> controller_tb__DOT__expected;
        VlUnpacked<VlUnpacked<IData/*31:0*/, 8>, 8> controller_tb__DOT__actual;
        VlUnpacked<VlUnpacked<CData/*7:0*/, 8>, 8> controller_tb__DOT__uut__DOT__array__DOT__A_matrix;
        VlUnpacked<VlUnpacked<CData/*7:0*/, 8>, 8> controller_tb__DOT__uut__DOT__array__DOT__B_matrix;
        VlUnpacked<VlUnpacked<CData/*7:0*/, 9>, 8> controller_tb__DOT__uut__DOT__array__DOT__A_wire;
        VlUnpacked<VlUnpacked<CData/*7:0*/, 8>, 9> controller_tb__DOT__uut__DOT__array__DOT__B_wire;
        VlUnpacked<CData/*7:0*/, 8> controller_tb__DOT__uut__DOT__array__DOT__A_feed;
        VlUnpacked<CData/*7:0*/, 8> controller_tb__DOT__uut__DOT__array__DOT__B_feed;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hee4b4f38__0;
    VlTriggerScheduler __VtrigSched_h06f34caf__0;

    // INTERNAL VARIABLES
    Vcontroller_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vcontroller_tb___024root(Vcontroller_tb__Syms* symsp, const char* namep);
    ~Vcontroller_tb___024root();
    VL_UNCOPYABLE(Vcontroller_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
