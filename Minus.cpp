//
// Created by liran-baruch on 12/18/18.
//

#include "Minus.h"

Minus::Minus(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression,
                                                                                        rightExpression) {}
double Minus ::calculate() {
    return getLeftExpression()->calculate() - getRightExpression()->calculate();
}
