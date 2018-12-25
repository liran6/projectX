//
// Created by shani on 16/12/18.
//

#include "Parser.h"

#define LINE_SEPARATOR "@"

using namespace std;

// (find(oper.begin(), oper.end(), vecOfCommand[i]) != oper.end())


Parser::Parser(vector<string> vecOfCommand) {
    vector<char> oper;
    oper.push_back('+');
    oper.push_back('-');
    oper.push_back('*');
    oper.push_back('/');
    //commands = vecOfCommand;
    for (int i = 0; i < vecOfCommand.size(); i++) {
        if (vecOfCommand[i] == ",") {
            continue;
        } else if (vecOfCommand[i] == LINE_SEPARATOR) {
            commands.push_back(vecOfCommand[i]);
        } else if (isdigit(vecOfCommand[i].at(0)) || checkInVec(oper, vecOfCommand[i].at(0))) {
           string str ;//= vecOfCommand[i];
//            i++;
            if(isdigit(vecOfCommand[i].at(vecOfCommand[i].size()-1)) && isdigit(vecOfCommand[i+1].at(0))){
                str = vecOfCommand[i];
                commands.push_back(str);
                continue;
            }else while (!(isdigit(vecOfCommand[i].at(vecOfCommand[i].size()-1)) && isdigit(vecOfCommand[i+1].at(0))) && (vecOfCommand[i] != "," && vecOfCommand[i] != LINE_SEPARATOR)) {
                str += vecOfCommand[i];
                i++;
            }
            i--;
            commands.push_back(str);
        } else{
            commands.push_back(vecOfCommand[i]);
        }
    }
    index = 0;
    this->stringCommandMap.insert(pair<string, Command*>("openDataServer",new OpenServerCommand));
    this->stringCommandMap.insert(pair<string, Command*>("connect",new ConnectCommand));
    this->stringCommandMap.insert(pair<string, Command*>("var", new DefineVarCommand));
    this->stringCommandMap.insert(pair<string, Command*>("print", new PrintCommand));
    this->stringCommandMap.insert(pair<string, Command*>("sleep", new SleepCommand));
}

bool Parser:: checkInVec(vector<char> vec, char& c ){
    bool x = false;
    for (char i : vec) {
        if (i == c){
            x = true;
        }
    }
    return x;

}

void Parser::callCondition() {
    int bracketCounter = 0;
    vector<string> allConCom;
    bool haveOneCon = false;
    int i = index;
    for (i; i< commands.size(); i++){
        if(commands[i] == "{" ){
            bracketCounter++;
            haveOneCon = true;
        }else if(commands[i] == "}" ) {
            bracketCounter--;
        }
        if(bracketCounter == 0 && haveOneCon == true){
            break;
        }
        //not send last "}"
        allConCom.push_back(commands[i]);
    }

    this->index = i + 2;
    if (allConCom[0] == "while") {
        LoopCommand* loopCommand = new LoopCommand;
        loopCommand->doCommand(allConCom, index);
        delete loopCommand;
    } else if (allConCom[0] == "if") {
        IfCommand* ifCommand = new IfCommand;
        ifCommand->doCommand(allConCom, index);
        delete ifCommand;
    }
    //ConditionParser* conParser = new ConditionParser(allConCom);
    //conParser->conImp();
    //delete (conParser);
}

void Parser::parse() {

    while (index <= commands.size()-1) {
        Command *c;
        if (stringCommandMap.count(commands[index]) == 0) {
            c = NULL;
        } else {
            c = stringCommandMap.find(commands[index])->second;
        }

        if (c != NULL) {
            index += c->execute(commands, index);
            //   delete (c); - not good!
        } else if (mapHolder->getSymbolTable().count(commands[index])) {
            c = new DefinitionCommand; // symbol without var //
            index += c->doCommand(commands, index);
            delete (c);
        } else if (commands.at(index) == "if" || commands.at(index) == "while") {
            callCondition();
        }
    }
    index = 0;
}

int Parser::getReturnIndex(vector<string> commandOperation, int index) {
    int resIndex = index;
    // set the index to return
    while (commandOperation[resIndex] != "@") {
        ++resIndex;
    }
    resIndex++; // skip the "@"
    resIndex -= index;
    return resIndex;
}

