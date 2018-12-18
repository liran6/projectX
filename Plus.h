//
// Created by liran-baruch on 12/18/18.
//

#ifndef PROJECTX_PLUS_H
#define PROJECTX_PLUS_H

#include "BinaryExpression.h"

using namespace std;

class Plus : public BinaryExpression{

public:
    Plus(Expression *leftExpression, Expression *rightExpression);
    double calculate();

};
#endif //PROJECTX_PLUS_H
