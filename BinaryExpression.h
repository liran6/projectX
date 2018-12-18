//
// Created by liran-baruch on 12/18/18.
//

#ifndef PROJECTX_BINARYEXPRESSION_H
#define PROJECTX_BINARYEXPRESSION_H

#include "Expression.h"

using namespace std;

class BinaryExpression: public Expression{
    Expression* leftExpression;
    Expression* rightExpression;
public:
    BinaryExpression(Expression *leftExpression, Expression *rightExpression);



};
#endif //PROJECTX_BINARYEXPRESSION_H
