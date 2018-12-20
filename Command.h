//
// Created by yuval on 12/18/18.
//

#ifndef PROJECTX_COMMAND_H
#define PROJECTX_COMMAND_H

#include "Expression.h"

//
class Command: public Expression {
public:
    virtual double execute(string s) = 0;

};


#endif //PROJECTX_COMMAND_H
