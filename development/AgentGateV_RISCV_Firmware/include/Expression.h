#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include <string>

class Expression {
public:
  enum class Type {
    NUMBER,
    VARIABLE,
    OPERATOR,
    FUNCTION // combination of multiple `Type`
  };

protected:
  Type type;
  std::vector<Expression *> children;

public:
  Expression(Type t) : type(t) {}

  Type getType() { return type; }

  void addChild(Expression *child) { children.push_back(child); }
  const std::vector<Expression *> getChildren() const { return children; }

  virtual ~Expression() {
    for (auto &child : children) {
      delete child;
    }
  }
};

#endif