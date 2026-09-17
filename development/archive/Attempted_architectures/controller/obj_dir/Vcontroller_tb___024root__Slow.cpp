// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontroller_tb.h for the primary calling header

#include "Vcontroller_tb__pch.h"

void Vcontroller_tb___024root___ctor_var_reset(Vcontroller_tb___024root* vlSelf);

Vcontroller_tb___024root::Vcontroller_tb___024root(Vcontroller_tb__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vcontroller_tb___024root___ctor_var_reset(this);
}

void Vcontroller_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vcontroller_tb___024root::~Vcontroller_tb___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
