//
// Created by yuval on 12/18/18.
//

#ifndef PROJECTX_COMMAND_H
#define PROJECTX_COMMAND_H

#include "Expression.h"

//
class Command
{
public:
    virtual double execute(int i) = 0;
};


#endif //PROJECTX_COMMAND_H
