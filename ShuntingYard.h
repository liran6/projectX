//
// Created by liran-baruch on 12/18/18.
//

#ifndef PROJECTX_SHUNTINGYARD_H
#define PROJECTX_SHUNTINGYARD_H

#include <string>
#include "Expression.h"
#include "stack"
using namespace std;

class ShuntingYard{
public:
    int precedence(char op);
    Expression* applyOp(Expression *leftVal, Expression *rightVal, char op);
    Expression *expressionEvaluate(string tokens);

};
#endif //PROJECTX_SHUNTINGYARD_H
