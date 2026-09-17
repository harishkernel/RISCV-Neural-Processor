// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmaster_controller_tb.h for the primary calling header

#include "Vmaster_controller_tb__pch.h"

void Vmaster_controller_tb___024root___ctor_var_reset(Vmaster_controller_tb___024root* vlSelf);

Vmaster_controller_tb___024root::Vmaster_controller_tb___024root(Vmaster_controller_tb__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vmaster_controller_tb___024root___ctor_var_reset(this);
}

void Vmaster_controller_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vmaster_controller_tb___024root::~Vmaster_controller_tb___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
