// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcontroller_tb__pch.h"

//============================================================
// Constructors

Vcontroller_tb::Vcontroller_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcontroller_tb__Syms(contextp(), _vcname__, this)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcontroller_tb::Vcontroller_tb(const char* _vcname__)
    : Vcontroller_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcontroller_tb::~Vcontroller_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vcontroller_tb___024root___eval_debug_assertions(Vcontroller_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vcontroller_tb___024root___eval_static(Vcontroller_tb___024root* vlSelf);
void Vcontroller_tb___024root___eval_initial(Vcontroller_tb___024root* vlSelf);
VL_ATTR_COLD bool Vcontroller_tb___024root___eval_stl(Vcontroller_tb___024root* vlSelf, CData/*0:0*/ firstIteration);
void Vcontroller_tb___024root___eval_sample(Vcontroller_tb___024root* vlSelf);
bool Vcontroller_tb___024root___eval_ico(Vcontroller_tb___024root* vlSelf, CData/*0:0*/ firstIteration);
bool Vcontroller_tb___024root___eval_act(Vcontroller_tb___024root* vlSelf);
bool Vcontroller_tb___024root___eval_inact(Vcontroller_tb___024root* vlSelf);
bool Vcontroller_tb___024root___eval_nba(Vcontroller_tb___024root* vlSelf);
bool Vcontroller_tb___024root___eval_obs(Vcontroller_tb___024root* vlSelf);
bool Vcontroller_tb___024root___eval_react(Vcontroller_tb___024root* vlSelf);
void Vcontroller_tb___024root___eval_postponed(Vcontroller_tb___024root* vlSelf);
VL_ATTR_COLD void Vcontroller_tb___024root___eval_final(Vcontroller_tb___024root* vlSelf);
VL_ATTR_COLD void Vcontroller_tb___024root___eval_dump_triggers__stl(Vcontroller_tb___024root* vlSelf);
VL_ATTR_COLD void Vcontroller_tb___024root___eval_dump_triggers__ico(Vcontroller_tb___024root* vlSelf);
VL_ATTR_COLD void Vcontroller_tb___024root___eval_dump_triggers__act(Vcontroller_tb___024root* vlSelf);
VL_ATTR_COLD void Vcontroller_tb___024root___eval_dump_triggers__nba(Vcontroller_tb___024root* vlSelf);
VL_ATTR_COLD void Vcontroller_tb___024root___eval_dump_triggers__obs(Vcontroller_tb___024root* vlSelf);
VL_ATTR_COLD void Vcontroller_tb___024root___eval_dump_triggers__react(Vcontroller_tb___024root* vlSelf);

void Vcontroller_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcontroller_tb::eval_step\n"); );
    m_evalLoop.eval();
}

void Vcontroller_tb::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vcontroller_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vcontroller_tb::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
    vlSymsp->TOP.__VdlySched.cleanupForevered();
}

void Vcontroller_tb::evalStatic() {
    Vcontroller_tb___024root___eval_static(&(vlSymsp->TOP));
}

void Vcontroller_tb::evalInitial() {
    Vcontroller_tb___024root___eval_initial(&(vlSymsp->TOP));
}

bool Vcontroller_tb::evalStl(bool firstIteration) {
    return Vcontroller_tb___024root___eval_stl(&(vlSymsp->TOP), firstIteration);
}

void Vcontroller_tb::evalSample() {
    Vcontroller_tb___024root___eval_sample(&(vlSymsp->TOP));
}

bool Vcontroller_tb::evalIco(bool firstIteration) {
    return Vcontroller_tb___024root___eval_ico(&(vlSymsp->TOP), firstIteration);
}

bool Vcontroller_tb::evalAct() {
    return Vcontroller_tb___024root___eval_act(&(vlSymsp->TOP));
}

bool Vcontroller_tb::evalInact() {
    return Vcontroller_tb___024root___eval_inact(&(vlSymsp->TOP));
}

bool Vcontroller_tb::evalNba() {
    return Vcontroller_tb___024root___eval_nba(&(vlSymsp->TOP));
}

bool Vcontroller_tb::evalObs() {
    return Vcontroller_tb___024root___eval_obs(&(vlSymsp->TOP));
}

bool Vcontroller_tb::evalReact() {
    return Vcontroller_tb___024root___eval_react(&(vlSymsp->TOP));
}

void Vcontroller_tb::evalPostponed() {
    Vcontroller_tb___024root___eval_postponed(&(vlSymsp->TOP));
}

void Vcontroller_tb::evalFinal() {
    Vcontroller_tb___024root___eval_final(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vcontroller_tb::dumpTriggersStl() {
    Vcontroller_tb___024root___eval_dump_triggers__stl(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vcontroller_tb::dumpTriggersIco() {
    Vcontroller_tb___024root___eval_dump_triggers__ico(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vcontroller_tb::dumpTriggersAct() {
    Vcontroller_tb___024root___eval_dump_triggers__act(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vcontroller_tb::dumpTriggersNba() {
    Vcontroller_tb___024root___eval_dump_triggers__nba(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vcontroller_tb::dumpTriggersObs() {
    Vcontroller_tb___024root___eval_dump_triggers__obs(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vcontroller_tb::dumpTriggersReact() {
    Vcontroller_tb___024root___eval_dump_triggers__react(&(vlSymsp->TOP));
}

//============================================================
// Events and timing
bool Vcontroller_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vcontroller_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vcontroller_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vcontroller_tb::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcontroller_tb::hierName() const { return vlSymsp->name(); }
const char* Vcontroller_tb::modelName() const { return "Vcontroller_tb"; }
unsigned Vcontroller_tb::threads() const { return 1; }
void Vcontroller_tb::prepareClone() const { contextp()->prepareClone(); }
void Vcontroller_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
