//
// Created by yuval on 12/18/18.
//

#ifndef PROJECTX_COMMAND_H
#define PROJECTX_COMMAND_H

#include <string>
#include <vector>

using namespace std;

struct threadsAndLock;

class ConditionParser;
class Expression;
class Command;
class AssignCommand;
class OpenServerCommand;
class CreateVarCommand;
class BindCommand;


class Command
{
public:
    virtual int execute(vector<string> vec, int i) = 0;

};

//OpenDataServerCommand class
class OpenServerCommand : public Command
{
public:
    virtual int execute(vector<string> vec, int i);
    virtual ~OpenServerCommand(){};
};

#endif //PROJECTX_COMMAND_H
