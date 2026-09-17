// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSYSTOLIC8X8_TB__SYMS_H_
#define VERILATED_VSYSTOLIC8X8_TB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsystolic8x8_tb.h"

// INCLUDE MODULE CLASSES
#include "Vsystolic8x8_tb___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vsystolic8x8_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsystolic8x8_tb* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool& __Vm_didInit;

    // MODULE INSTANCE STATE
    Vsystolic8x8_tb___024root      TOP;

    // CONSTRUCTORS
    Vsystolic8x8_tb__Syms(VerilatedContext* contextp, const char* namep, Vsystolic8x8_tb* modelp);
    ~Vsystolic8x8_tb__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
