//
// Created by liran-baruch on 12/18/18.
//

#ifndef PROJECTX_DIV_H
#define PROJECTX_DIV_H

#include <stdexcept>
#include "BinaryExpression.h"

class Div : public BinaryExpression {
public:
    Div(Expression *leftExpression, Expression *rightExpression);

    double calculate();
};
#endif //PROJECTX_DIV_H
