//
// Created by liran-baruch on 12/18/18.
//

#ifndef PROJECTX_BINARYEXPRESSION_H
#define PROJECTX_BINARYEXPRESSION_H

#include "Expression.h"

using namespace std;

class BinaryExpression: public Expression{
protected:
    Expression* leftExpression;
    Expression* rightExpression;
public:
    BinaryExpression(Expression *leftExpression, Expression *rightExpression);

     virtual Expression* getLeftExpression(){return leftExpression;};
     virtual Expression* getRightExpression(){return rightExpression;};


};
#endif //PROJECTX_BINARYEXPRESSION_H
