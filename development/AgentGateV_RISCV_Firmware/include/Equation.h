#ifndef EQUATION_H
#define EQUATION_H

#include "Expression.h"

class Equation{
private:
    Expression* LHS, *RHS;

public:
    Equation(Expression* lhs, Expression* rhs)
        : LHS(lhs), RHS(rhs) {}

    Expression* getLHS() const {return LHS;}
    Expression* getRHS() const {return RHS;}

    void setLHS(Expression* lhs) {LHS = lhs;}
    void setRHS(Expression* rhs) {RHS = rhs;}
    ~Equation() { delete LHS; delete RHS; }
};

#endif