// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpe_tb__pch.h"

//============================================================
// Constructors

Vpe_tb::Vpe_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpe_tb__Syms(contextp(), _vcname__, this)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vpe_tb::Vpe_tb(const char* _vcname__)
    : Vpe_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpe_tb::~Vpe_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vpe_tb___024root___eval_debug_assertions(Vpe_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vpe_tb___024root___eval_static(Vpe_tb___024root* vlSelf);
void Vpe_tb___024root___eval_initial(Vpe_tb___024root* vlSelf);
VL_ATTR_COLD bool Vpe_tb___024root___eval_stl(Vpe_tb___024root* vlSelf, CData/*0:0*/ firstIteration);
void Vpe_tb___024root___eval_sample(Vpe_tb___024root* vlSelf);
bool Vpe_tb___024root___eval_ico(Vpe_tb___024root* vlSelf, CData/*0:0*/ firstIteration);
bool Vpe_tb___024root___eval_act(Vpe_tb___024root* vlSelf);
bool Vpe_tb___024root___eval_inact(Vpe_tb___024root* vlSelf);
bool Vpe_tb___024root___eval_nba(Vpe_tb___024root* vlSelf);
bool Vpe_tb___024root___eval_obs(Vpe_tb___024root* vlSelf);
bool Vpe_tb___024root___eval_react(Vpe_tb___024root* vlSelf);
void Vpe_tb___024root___eval_postponed(Vpe_tb___024root* vlSelf);
VL_ATTR_COLD void Vpe_tb___024root___eval_final(Vpe_tb___024root* vlSelf);
VL_ATTR_COLD void Vpe_tb___024root___eval_dump_triggers__stl(Vpe_tb___024root* vlSelf);
VL_ATTR_COLD void Vpe_tb___024root___eval_dump_triggers__ico(Vpe_tb___024root* vlSelf);
VL_ATTR_COLD void Vpe_tb___024root___eval_dump_triggers__act(Vpe_tb___024root* vlSelf);
VL_ATTR_COLD void Vpe_tb___024root___eval_dump_triggers__nba(Vpe_tb___024root* vlSelf);
VL_ATTR_COLD void Vpe_tb___024root___eval_dump_triggers__obs(Vpe_tb___024root* vlSelf);
VL_ATTR_COLD void Vpe_tb___024root___eval_dump_triggers__react(Vpe_tb___024root* vlSelf);

void Vpe_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpe_tb::eval_step\n"); );
    m_evalLoop.eval();
}

void Vpe_tb::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vpe_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vpe_tb::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
    vlSymsp->TOP.__VdlySched.cleanupForevered();
}

void Vpe_tb::evalStatic() {
    Vpe_tb___024root___eval_static(&(vlSymsp->TOP));
}

void Vpe_tb::evalInitial() {
    Vpe_tb___024root___eval_initial(&(vlSymsp->TOP));
}

bool Vpe_tb::evalStl(bool firstIteration) {
    return Vpe_tb___024root___eval_stl(&(vlSymsp->TOP), firstIteration);
}

void Vpe_tb::evalSample() {
    Vpe_tb___024root___eval_sample(&(vlSymsp->TOP));
}

bool Vpe_tb::evalIco(bool firstIteration) {
    return Vpe_tb___024root___eval_ico(&(vlSymsp->TOP), firstIteration);
}

bool Vpe_tb::evalAct() {
    return Vpe_tb___024root___eval_act(&(vlSymsp->TOP));
}

bool Vpe_tb::evalInact() {
    return Vpe_tb___024root___eval_inact(&(vlSymsp->TOP));
}

bool Vpe_tb::evalNba() {
    return Vpe_tb___024root___eval_nba(&(vlSymsp->TOP));
}

bool Vpe_tb::evalObs() {
    return Vpe_tb___024root___eval_obs(&(vlSymsp->TOP));
}

bool Vpe_tb::evalReact() {
    return Vpe_tb___024root___eval_react(&(vlSymsp->TOP));
}

void Vpe_tb::evalPostponed() {
    Vpe_tb___024root___eval_postponed(&(vlSymsp->TOP));
}

void Vpe_tb::evalFinal() {
    Vpe_tb___024root___eval_final(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vpe_tb::dumpTriggersStl() {
    Vpe_tb___024root___eval_dump_triggers__stl(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vpe_tb::dumpTriggersIco() {
    Vpe_tb___024root___eval_dump_triggers__ico(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vpe_tb::dumpTriggersAct() {
    Vpe_tb___024root___eval_dump_triggers__act(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vpe_tb::dumpTriggersNba() {
    Vpe_tb___024root___eval_dump_triggers__nba(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vpe_tb::dumpTriggersObs() {
    Vpe_tb___024root___eval_dump_triggers__obs(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vpe_tb::dumpTriggersReact() {
    Vpe_tb___024root___eval_dump_triggers__react(&(vlSymsp->TOP));
}

//============================================================
// Events and timing
bool Vpe_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vpe_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vpe_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vpe_tb::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpe_tb::hierName() const { return vlSymsp->name(); }
const char* Vpe_tb::modelName() const { return "Vpe_tb"; }
unsigned Vpe_tb::threads() const { return 1; }
void Vpe_tb::prepareClone() const { contextp()->prepareClone(); }
void Vpe_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
