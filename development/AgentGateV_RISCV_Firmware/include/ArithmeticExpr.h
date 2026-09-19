#ifndef ARITHMETICEXPR_H
#define ARITHMETICEXPR_H

#include "Expression.h"

class NumberExpression : public Expression {
private:
    double value;
public:
    NumberExpression(double val) : Expression(Type::NUMBER), value(val) {}
    double getValue() const { return value; }
};

class VariableExpression : public Expression {
private:
    std::string name;
public:
    VariableExpression(const std::string& n) : Expression(Type::VARIABLE), name(n) {}
    std::string getName() const { return name; }
};

class OperatorExpression : public Expression {
private:
    char op;
public:
    OperatorExpression(char o) : Expression(Type::OPERATOR), op(o) {}
    char getOperator() const { return op; }
};

#endif