//
// Created by liran-baruch on 12/18/18.
//

#ifndef PROJECTX_NEG_H
#define PROJECTX_NEG_H

#include "UnaryExpression.h"

using namespace std;

class Neg : public UnaryExpression{
public:
    Neg(Expression *expression);

    double calculate();
};
#endif //PROJECTX_NEG_H
