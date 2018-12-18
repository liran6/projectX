//
// Created by liran-baruch on 12/18/18.
//

#include "Mul.h"

Mul::Mul(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression, rightExpression) {}

double Mul::calculate() {
    return getRightExpression()->calculate() * getLeftExpression()->calculate();
}
