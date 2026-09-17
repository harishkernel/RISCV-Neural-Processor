// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsystolic8x8_tb.h for the primary calling header

#include "Vsystolic8x8_tb__pch.h"

void Vsystolic8x8_tb___024root___ctor_var_reset(Vsystolic8x8_tb___024root* vlSelf);

Vsystolic8x8_tb___024root::Vsystolic8x8_tb___024root(Vsystolic8x8_tb__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vsystolic8x8_tb___024root___ctor_var_reset(this);
}

void Vsystolic8x8_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsystolic8x8_tb___024root::~Vsystolic8x8_tb___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
