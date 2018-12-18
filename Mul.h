//
// Created by liran-baruch on 12/18/18.
//

#ifndef PROJECTX_MUL_H
#define PROJECTX_MUL_H

#include "BinaryExpression.h"

class Mul : public BinaryExpression{
public:
    Mul(Expression *leftExpression, Expression *rightExpression);
    double calculate();
};
#endif //PROJECTX_MUL_H
