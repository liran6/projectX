//
// Created by liran-baruch on 12/18/18.
//

#ifndef PROJECTX_NUMBER_H
#define PROJECTX_NUMBER_H

#include "Expression.h"

using namespace std;

class Number : public Expression{
    double value;
public:
    Number(double value);
    virtual double getValue(){ return value;};
};
#endif //PROJECTX_NUMBER_H
