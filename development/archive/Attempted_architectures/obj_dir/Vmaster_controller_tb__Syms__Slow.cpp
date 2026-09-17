// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vmaster_controller_tb__pch.h"

Vmaster_controller_tb__Syms::Vmaster_controller_tb__Syms(VerilatedContext* contextp, const char* namep, Vmaster_controller_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    , __Vm_didInit{modelp->m_didInit}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(965);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}

Vmaster_controller_tb__Syms::~Vmaster_controller_tb__Syms() {
    // Tear down scopes
    // Tear down sub module instances
}
