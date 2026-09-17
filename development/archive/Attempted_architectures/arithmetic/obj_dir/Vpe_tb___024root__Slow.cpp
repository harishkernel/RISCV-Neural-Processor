// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpe_tb.h for the primary calling header

#include "Vpe_tb__pch.h"

void Vpe_tb___024root___ctor_var_reset(Vpe_tb___024root* vlSelf);

Vpe_tb___024root::Vpe_tb___024root(Vpe_tb__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vpe_tb___024root___ctor_var_reset(this);
}

void Vpe_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vpe_tb___024root::~Vpe_tb___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
