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
class PrintCommand;
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
    struct arg_struct {
        int arg1;
        int arg2;
    }argsForServer;
    virtual int execute(vector<string> vec, int i);
    virtual ~OpenServerCommand(){};
    void* SocketCreator(arg_struct argStruct);
};

class ConnectCommand : public Command
{
public:
    struct arg_struct {
        string arg1;
        int arg2;
    }argsForConnect;
    ConnectCommand() : Command(){}
    virtual int execute(vector<string> vec, int i);
    virtual void* OpenConnection(void *argStruct);
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

class PrintCommand : public Command
{
public:
    PrintCommand() : Command(){}
    virtual int execute(vector<string> vec, int i);
    virtual ~PrintCommand(){};
};
class ConditionParser : public Command
{
public:
    ConditionParser(): Command(){}
    virtual bool checkCondition(vector<string> vec);
    virtual int execute(vector<string> vec, int i){ return 0;}
    virtual ~ConditionParser(){};
};

#endif //PROJECTX_COMMAND_H
