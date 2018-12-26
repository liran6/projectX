//
// Created by yuval on 12/18/18.
//

#ifndef PROJECTX_COMMAND_H
#define PROJECTX_COMMAND_H

#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <strings.h>

using namespace std;

struct threadsAndLock;
class IfCommand;
class ConditionParser;
class Expression;
class Command;
class AssignCommand;
class OpenServerCommand;
class VarCommand;
class BindCommand;
class ConnectCommand;
class SleepCommand;


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
    void SoketConnector(int port, int hz);
};

class ConnectCommand : public Command
{
public:
    ConnectCommand() : Command(){}
    virtual int execute(vector<string> vec, int i);
    virtual ~ConnectCommand(){};
};

//WhileCommand class
class WhileCommand : public Command
{
public:
    WhileCommand() : Command(){}
    virtual int execute(vector<string> vec, int i);
    virtual ~WhileCommand(){};
};

class SleepCommand : public Command
{
public:
    SleepCommand() : Command(){}
    virtual int execute(vector<string> vec, int i);
    virtual ~SleepCommand(){};
};

class IfCommand : public Command
{
public:
    IfCommand() : Command(){}
    virtual int execute(vector<string> vec, int i);
    virtual ~IfCommand(){};
};

class AssignCommand : public Command
{
public:
    AssignCommand() : Command(){}
    virtual int execute(vector<string> vec, int i);
    virtual ~AssignCommand(){};
};

class VarCommand : public Command
{
public:
    VarCommand() : Command(){}
    virtual int execute(vector<string> vec, int i);
    virtual ~VarCommand(){};
};

class BindCommand : public Command
{
public:
    BindCommand() : Command(){}
    virtual int execute(vector<string> vec, int i);
    virtual ~BindCommand(){};
};

#endif //PROJECTX_COMMAND_H
