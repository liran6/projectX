//
// Created by liran-baruch on 12/18/18.
//

#include "Neg.h"

Neg::Neg(Expression *expression) : UnaryExpression(expression) {}

double Neg::calculate() {
    return getExpression()->calculate() * -1;
}