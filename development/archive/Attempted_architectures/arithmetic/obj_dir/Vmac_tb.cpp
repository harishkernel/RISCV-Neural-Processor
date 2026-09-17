// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmac_tb__pch.h"

//============================================================
// Constructors

Vmac_tb::Vmac_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmac_tb__Syms(contextp(), _vcname__, this)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmac_tb::Vmac_tb(const char* _vcname__)
    : Vmac_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmac_tb::~Vmac_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmac_tb___024root___eval_debug_assertions(Vmac_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vmac_tb___024root___eval_static(Vmac_tb___024root* vlSelf);
void Vmac_tb___024root___eval_initial(Vmac_tb___024root* vlSelf);
VL_ATTR_COLD bool Vmac_tb___024root___eval_stl(Vmac_tb___024root* vlSelf, CData/*0:0*/ firstIteration);
void Vmac_tb___024root___eval_sample(Vmac_tb___024root* vlSelf);
bool Vmac_tb___024root___eval_ico(Vmac_tb___024root* vlSelf, CData/*0:0*/ firstIteration);
bool Vmac_tb___024root___eval_act(Vmac_tb___024root* vlSelf);
bool Vmac_tb___024root___eval_inact(Vmac_tb___024root* vlSelf);
bool Vmac_tb___024root___eval_nba(Vmac_tb___024root* vlSelf);
bool Vmac_tb___024root___eval_obs(Vmac_tb___024root* vlSelf);
bool Vmac_tb___024root___eval_react(Vmac_tb___024root* vlSelf);
void Vmac_tb___024root___eval_postponed(Vmac_tb___024root* vlSelf);
VL_ATTR_COLD void Vmac_tb___024root___eval_final(Vmac_tb___024root* vlSelf);
VL_ATTR_COLD void Vmac_tb___024root___eval_dump_triggers__stl(Vmac_tb___024root* vlSelf);
VL_ATTR_COLD void Vmac_tb___024root___eval_dump_triggers__ico(Vmac_tb___024root* vlSelf);
VL_ATTR_COLD void Vmac_tb___024root___eval_dump_triggers__act(Vmac_tb___024root* vlSelf);
VL_ATTR_COLD void Vmac_tb___024root___eval_dump_triggers__nba(Vmac_tb___024root* vlSelf);
VL_ATTR_COLD void Vmac_tb___024root___eval_dump_triggers__obs(Vmac_tb___024root* vlSelf);
VL_ATTR_COLD void Vmac_tb___024root___eval_dump_triggers__react(Vmac_tb___024root* vlSelf);

void Vmac_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmac_tb::eval_step\n"); );
    m_evalLoop.eval();
}

void Vmac_tb::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vmac_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vmac_tb::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
    vlSymsp->TOP.__VdlySched.cleanupForevered();
}

void Vmac_tb::evalStatic() {
    Vmac_tb___024root___eval_static(&(vlSymsp->TOP));
}

void Vmac_tb::evalInitial() {
    Vmac_tb___024root___eval_initial(&(vlSymsp->TOP));
}

bool Vmac_tb::evalStl(bool firstIteration) {
    return Vmac_tb___024root___eval_stl(&(vlSymsp->TOP), firstIteration);
}

void Vmac_tb::evalSample() {
    Vmac_tb___024root___eval_sample(&(vlSymsp->TOP));
}

bool Vmac_tb::evalIco(bool firstIteration) {
    return Vmac_tb___024root___eval_ico(&(vlSymsp->TOP), firstIteration);
}

bool Vmac_tb::evalAct() {
    return Vmac_tb___024root___eval_act(&(vlSymsp->TOP));
}

bool Vmac_tb::evalInact() {
    return Vmac_tb___024root___eval_inact(&(vlSymsp->TOP));
}

bool Vmac_tb::evalNba() {
    return Vmac_tb___024root___eval_nba(&(vlSymsp->TOP));
}

bool Vmac_tb::evalObs() {
    return Vmac_tb___024root___eval_obs(&(vlSymsp->TOP));
}

bool Vmac_tb::evalReact() {
    return Vmac_tb___024root___eval_react(&(vlSymsp->TOP));
}

void Vmac_tb::evalPostponed() {
    Vmac_tb___024root___eval_postponed(&(vlSymsp->TOP));
}

void Vmac_tb::evalFinal() {
    Vmac_tb___024root___eval_final(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vmac_tb::dumpTriggersStl() {
    Vmac_tb___024root___eval_dump_triggers__stl(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vmac_tb::dumpTriggersIco() {
    Vmac_tb___024root___eval_dump_triggers__ico(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vmac_tb::dumpTriggersAct() {
    Vmac_tb___024root___eval_dump_triggers__act(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vmac_tb::dumpTriggersNba() {
    Vmac_tb___024root___eval_dump_triggers__nba(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vmac_tb::dumpTriggersObs() {
    Vmac_tb___024root___eval_dump_triggers__obs(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vmac_tb::dumpTriggersReact() {
    Vmac_tb___024root___eval_dump_triggers__react(&(vlSymsp->TOP));
}

//============================================================
// Events and timing
bool Vmac_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vmac_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vmac_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vmac_tb::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmac_tb::hierName() const { return vlSymsp->name(); }
const char* Vmac_tb::modelName() const { return "Vmac_tb"; }
unsigned Vmac_tb::threads() const { return 1; }
void Vmac_tb::prepareClone() const { contextp()->prepareClone(); }
void Vmac_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
