// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmaster_controller_tb__pch.h"

//============================================================
// Constructors

Vmaster_controller_tb::Vmaster_controller_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmaster_controller_tb__Syms(contextp(), _vcname__, this)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmaster_controller_tb::Vmaster_controller_tb(const char* _vcname__)
    : Vmaster_controller_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmaster_controller_tb::~Vmaster_controller_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmaster_controller_tb___024root___eval_debug_assertions(Vmaster_controller_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_static(Vmaster_controller_tb___024root* vlSelf);
void Vmaster_controller_tb___024root___eval_initial(Vmaster_controller_tb___024root* vlSelf);
VL_ATTR_COLD bool Vmaster_controller_tb___024root___eval_stl(Vmaster_controller_tb___024root* vlSelf, CData/*0:0*/ firstIteration);
void Vmaster_controller_tb___024root___eval_sample(Vmaster_controller_tb___024root* vlSelf);
bool Vmaster_controller_tb___024root___eval_ico(Vmaster_controller_tb___024root* vlSelf, CData/*0:0*/ firstIteration);
bool Vmaster_controller_tb___024root___eval_act(Vmaster_controller_tb___024root* vlSelf);
bool Vmaster_controller_tb___024root___eval_inact(Vmaster_controller_tb___024root* vlSelf);
bool Vmaster_controller_tb___024root___eval_nba(Vmaster_controller_tb___024root* vlSelf);
bool Vmaster_controller_tb___024root___eval_obs(Vmaster_controller_tb___024root* vlSelf);
bool Vmaster_controller_tb___024root___eval_react(Vmaster_controller_tb___024root* vlSelf);
void Vmaster_controller_tb___024root___eval_postponed(Vmaster_controller_tb___024root* vlSelf);
VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_final(Vmaster_controller_tb___024root* vlSelf);
VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_dump_triggers__stl(Vmaster_controller_tb___024root* vlSelf);
VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_dump_triggers__ico(Vmaster_controller_tb___024root* vlSelf);
VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_dump_triggers__act(Vmaster_controller_tb___024root* vlSelf);
VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_dump_triggers__nba(Vmaster_controller_tb___024root* vlSelf);
VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_dump_triggers__obs(Vmaster_controller_tb___024root* vlSelf);
VL_ATTR_COLD void Vmaster_controller_tb___024root___eval_dump_triggers__react(Vmaster_controller_tb___024root* vlSelf);

void Vmaster_controller_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmaster_controller_tb::eval_step\n"); );
    m_evalLoop.eval();
}

void Vmaster_controller_tb::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vmaster_controller_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vmaster_controller_tb::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
    vlSymsp->TOP.__VdlySched.cleanupForevered();
}

void Vmaster_controller_tb::evalStatic() {
    Vmaster_controller_tb___024root___eval_static(&(vlSymsp->TOP));
}

void Vmaster_controller_tb::evalInitial() {
    Vmaster_controller_tb___024root___eval_initial(&(vlSymsp->TOP));
}

bool Vmaster_controller_tb::evalStl(bool firstIteration) {
    return Vmaster_controller_tb___024root___eval_stl(&(vlSymsp->TOP), firstIteration);
}

void Vmaster_controller_tb::evalSample() {
    Vmaster_controller_tb___024root___eval_sample(&(vlSymsp->TOP));
}

bool Vmaster_controller_tb::evalIco(bool firstIteration) {
    return Vmaster_controller_tb___024root___eval_ico(&(vlSymsp->TOP), firstIteration);
}

bool Vmaster_controller_tb::evalAct() {
    return Vmaster_controller_tb___024root___eval_act(&(vlSymsp->TOP));
}

bool Vmaster_controller_tb::evalInact() {
    return Vmaster_controller_tb___024root___eval_inact(&(vlSymsp->TOP));
}

bool Vmaster_controller_tb::evalNba() {
    return Vmaster_controller_tb___024root___eval_nba(&(vlSymsp->TOP));
}

bool Vmaster_controller_tb::evalObs() {
    return Vmaster_controller_tb___024root___eval_obs(&(vlSymsp->TOP));
}

bool Vmaster_controller_tb::evalReact() {
    return Vmaster_controller_tb___024root___eval_react(&(vlSymsp->TOP));
}

void Vmaster_controller_tb::evalPostponed() {
    Vmaster_controller_tb___024root___eval_postponed(&(vlSymsp->TOP));
}

void Vmaster_controller_tb::evalFinal() {
    Vmaster_controller_tb___024root___eval_final(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vmaster_controller_tb::dumpTriggersStl() {
    Vmaster_controller_tb___024root___eval_dump_triggers__stl(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vmaster_controller_tb::dumpTriggersIco() {
    Vmaster_controller_tb___024root___eval_dump_triggers__ico(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vmaster_controller_tb::dumpTriggersAct() {
    Vmaster_controller_tb___024root___eval_dump_triggers__act(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vmaster_controller_tb::dumpTriggersNba() {
    Vmaster_controller_tb___024root___eval_dump_triggers__nba(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vmaster_controller_tb::dumpTriggersObs() {
    Vmaster_controller_tb___024root___eval_dump_triggers__obs(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vmaster_controller_tb::dumpTriggersReact() {
    Vmaster_controller_tb___024root___eval_dump_triggers__react(&(vlSymsp->TOP));
}

//============================================================
// Events and timing
bool Vmaster_controller_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vmaster_controller_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vmaster_controller_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vmaster_controller_tb::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmaster_controller_tb::hierName() const { return vlSymsp->name(); }
const char* Vmaster_controller_tb::modelName() const { return "Vmaster_controller_tb"; }
unsigned Vmaster_controller_tb::threads() const { return 1; }
void Vmaster_controller_tb::prepareClone() const { contextp()->prepareClone(); }
void Vmaster_controller_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
