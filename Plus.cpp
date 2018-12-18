//
// Created by liran-baruch on 12/18/18.
//

#include "Plus.h"


Plus::Plus(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression,
                                                                                       rightExpression) {}
double Plus ::calculate() {
    return getLeftExpression()->calculate() + getRightExpression()->calculate();
}