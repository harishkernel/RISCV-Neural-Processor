// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsystolic8x8_tb__pch.h"

//============================================================
// Constructors

Vsystolic8x8_tb::Vsystolic8x8_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsystolic8x8_tb__Syms(contextp(), _vcname__, this)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsystolic8x8_tb::Vsystolic8x8_tb(const char* _vcname__)
    : Vsystolic8x8_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsystolic8x8_tb::~Vsystolic8x8_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsystolic8x8_tb___024root___eval_debug_assertions(Vsystolic8x8_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vsystolic8x8_tb___024root___eval_static(Vsystolic8x8_tb___024root* vlSelf);
void Vsystolic8x8_tb___024root___eval_initial(Vsystolic8x8_tb___024root* vlSelf);
VL_ATTR_COLD bool Vsystolic8x8_tb___024root___eval_stl(Vsystolic8x8_tb___024root* vlSelf, CData/*0:0*/ firstIteration);
void Vsystolic8x8_tb___024root___eval_sample(Vsystolic8x8_tb___024root* vlSelf);
bool Vsystolic8x8_tb___024root___eval_ico(Vsystolic8x8_tb___024root* vlSelf, CData/*0:0*/ firstIteration);
bool Vsystolic8x8_tb___024root___eval_act(Vsystolic8x8_tb___024root* vlSelf);
bool Vsystolic8x8_tb___024root___eval_inact(Vsystolic8x8_tb___024root* vlSelf);
bool Vsystolic8x8_tb___024root___eval_nba(Vsystolic8x8_tb___024root* vlSelf);
bool Vsystolic8x8_tb___024root___eval_obs(Vsystolic8x8_tb___024root* vlSelf);
bool Vsystolic8x8_tb___024root___eval_react(Vsystolic8x8_tb___024root* vlSelf);
void Vsystolic8x8_tb___024root___eval_postponed(Vsystolic8x8_tb___024root* vlSelf);
VL_ATTR_COLD void Vsystolic8x8_tb___024root___eval_final(Vsystolic8x8_tb___024root* vlSelf);
VL_ATTR_COLD void Vsystolic8x8_tb___024root___eval_dump_triggers__stl(Vsystolic8x8_tb___024root* vlSelf);
VL_ATTR_COLD void Vsystolic8x8_tb___024root___eval_dump_triggers__ico(Vsystolic8x8_tb___024root* vlSelf);
VL_ATTR_COLD void Vsystolic8x8_tb___024root___eval_dump_triggers__act(Vsystolic8x8_tb___024root* vlSelf);
VL_ATTR_COLD void Vsystolic8x8_tb___024root___eval_dump_triggers__nba(Vsystolic8x8_tb___024root* vlSelf);
VL_ATTR_COLD void Vsystolic8x8_tb___024root___eval_dump_triggers__obs(Vsystolic8x8_tb___024root* vlSelf);
VL_ATTR_COLD void Vsystolic8x8_tb___024root___eval_dump_triggers__react(Vsystolic8x8_tb___024root* vlSelf);

void Vsystolic8x8_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsystolic8x8_tb::eval_step\n"); );
    m_evalLoop.eval();
}

void Vsystolic8x8_tb::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vsystolic8x8_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vsystolic8x8_tb::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
    vlSymsp->TOP.__VdlySched.cleanupForevered();
}

void Vsystolic8x8_tb::evalStatic() {
    Vsystolic8x8_tb___024root___eval_static(&(vlSymsp->TOP));
}

void Vsystolic8x8_tb::evalInitial() {
    Vsystolic8x8_tb___024root___eval_initial(&(vlSymsp->TOP));
}

bool Vsystolic8x8_tb::evalStl(bool firstIteration) {
    return Vsystolic8x8_tb___024root___eval_stl(&(vlSymsp->TOP), firstIteration);
}

void Vsystolic8x8_tb::evalSample() {
    Vsystolic8x8_tb___024root___eval_sample(&(vlSymsp->TOP));
}

bool Vsystolic8x8_tb::evalIco(bool firstIteration) {
    return Vsystolic8x8_tb___024root___eval_ico(&(vlSymsp->TOP), firstIteration);
}

bool Vsystolic8x8_tb::evalAct() {
    return Vsystolic8x8_tb___024root___eval_act(&(vlSymsp->TOP));
}

bool Vsystolic8x8_tb::evalInact() {
    return Vsystolic8x8_tb___024root___eval_inact(&(vlSymsp->TOP));
}

bool Vsystolic8x8_tb::evalNba() {
    return Vsystolic8x8_tb___024root___eval_nba(&(vlSymsp->TOP));
}

bool Vsystolic8x8_tb::evalObs() {
    return Vsystolic8x8_tb___024root___eval_obs(&(vlSymsp->TOP));
}

bool Vsystolic8x8_tb::evalReact() {
    return Vsystolic8x8_tb___024root___eval_react(&(vlSymsp->TOP));
}

void Vsystolic8x8_tb::evalPostponed() {
    Vsystolic8x8_tb___024root___eval_postponed(&(vlSymsp->TOP));
}

void Vsystolic8x8_tb::evalFinal() {
    Vsystolic8x8_tb___024root___eval_final(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsystolic8x8_tb::dumpTriggersStl() {
    Vsystolic8x8_tb___024root___eval_dump_triggers__stl(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsystolic8x8_tb::dumpTriggersIco() {
    Vsystolic8x8_tb___024root___eval_dump_triggers__ico(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsystolic8x8_tb::dumpTriggersAct() {
    Vsystolic8x8_tb___024root___eval_dump_triggers__act(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsystolic8x8_tb::dumpTriggersNba() {
    Vsystolic8x8_tb___024root___eval_dump_triggers__nba(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsystolic8x8_tb::dumpTriggersObs() {
    Vsystolic8x8_tb___024root___eval_dump_triggers__obs(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsystolic8x8_tb::dumpTriggersReact() {
    Vsystolic8x8_tb___024root___eval_dump_triggers__react(&(vlSymsp->TOP));
}

//============================================================
// Events and timing
bool Vsystolic8x8_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vsystolic8x8_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vsystolic8x8_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vsystolic8x8_tb::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsystolic8x8_tb::hierName() const { return vlSymsp->name(); }
const char* Vsystolic8x8_tb::modelName() const { return "Vsystolic8x8_tb"; }
unsigned Vsystolic8x8_tb::threads() const { return 1; }
void Vsystolic8x8_tb::prepareClone() const { contextp()->prepareClone(); }
void Vsystolic8x8_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
