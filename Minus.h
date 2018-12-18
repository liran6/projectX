//
// Created by liran-baruch on 12/18/18.
//

#ifndef PROJECTX_MINUS_H
#define PROJECTX_MINUS_H

#include "BinaryExpression.h"

class Minus : BinaryExpression{
public:
    Minus(Expression *leftExpression, Expression *rightExpression);
    double calculate();
};
#endif //PROJECTX_MINUS_H
