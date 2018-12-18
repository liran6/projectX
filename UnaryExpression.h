//
// Created by liran-baruch on 12/18/18.
//

#ifndef PROJECTX_UNARYEXPRESSION_H
#define PROJECTX_UNARYEXPRESSION_H
#include "Expression.h"

using namespace std;

class UnaryExpression: public Expression{
protected:
    Expression* expression;

public:

    UnaryExpression(Expression *expression);

    virtual Expression* getExpression(){return expression;};


};
#endif //PROJECTX_UNARYEXPRESSION_H
