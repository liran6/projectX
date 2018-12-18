//
// Created by liran-baruch on 12/18/18.
//

#include "Div.h"

Div::Div(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression, rightExpression) {}



double Div:: calculate(){
    if(getRightExpression()->calculate() == 0.0){
        throw runtime_error("Math error! Fuck you!!!");
    }
    return getLeftExpression()->calculate() / getRightExpression()->calculate();
}
