// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMASTER_CONTROLLER_TB__SYMS_H_
#define VERILATED_VMASTER_CONTROLLER_TB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vmaster_controller_tb.h"

// INCLUDE MODULE CLASSES
#include "Vmaster_controller_tb___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vmaster_controller_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vmaster_controller_tb* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool& __Vm_didInit;

    // MODULE INSTANCE STATE
    Vmaster_controller_tb___024root TOP;

    // CONSTRUCTORS
    Vmaster_controller_tb__Syms(VerilatedContext* contextp, const char* namep, Vmaster_controller_tb* modelp);
    ~Vmaster_controller_tb__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
