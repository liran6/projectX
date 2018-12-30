//
// Created by yuvl on 18/12/18.
//

#include "Parser.h"


#define LINE_SEPARATOR "@"

using namespace std;

// (find(oper.begin(), oper.end(), vecOfCommand[i]) != oper.end())


Parser::Parser(vector<string> vecOfCommand) {
    index = 0;
    vector<char> oper;
    oper.push_back('+');
    oper.push_back('-');
    oper.push_back('*');
    oper.push_back('/');
    for (int i = 0; i < vecOfCommand.size(); i++) {
        if (vecOfCommand[i] == ",") {
            continue;
        } else if (vecOfCommand[i] == LINE_SEPARATOR) {
            commands.push_back(vecOfCommand[i]);
        }else if(vecOfCommand[i] == "<" || vecOfCommand[i] == ">" || vecOfCommand[i] == "!" || vecOfCommand[i] == "="){
            string str = vecOfCommand[i];
            if(vecOfCommand[i+1] == "="){
                str += vecOfCommand[i+1];
                i++;
            }
            commands.push_back(str);
        } else if (isdigit(vecOfCommand[i].at(0)) || checkInVec(oper, vecOfCommand[i].at(0))) {
           string str ;
            //if the index is a number and the next index also.
            if(isdigit(vecOfCommand[i].at(vecOfCommand[i].size()-1)) && isdigit(vecOfCommand[i+1].at(0))){
                str = vecOfCommand[i];
                commands.push_back(str);
                continue;
            }//while we don't have two numbers in a sequence.
            else while (!(isdigit(vecOfCommand[i].at(vecOfCommand[i].size()-1)) && isdigit(vecOfCommand[i+1].at(0))) /*&& (vecOfCommand[i] != "," && vecOfCommand[i] != LINE_SEPARATOR)*/) {
                if(vecOfCommand[i] == "," || vecOfCommand[i] == LINE_SEPARATOR || vecOfCommand[i] == "{" || vecOfCommand[i] == "}"){
                    break;
                }
                if(checkInVec(oper, vecOfCommand[i].at(0)) && (isalpha(vecOfCommand[i+1].at(0)))){
                    str = vecOfCommand[i];
                    i++;
                    break;
                }
                str += vecOfCommand[i];
                i++;
            }
            i--;
            commands.push_back(str);
        }else if(vecOfCommand[i] == "\""){
            i++;
            string str;
            while (vecOfCommand[i] != "\""){

                str+= vecOfCommand[i];
                i++;
            }
            commands.push_back(str);

        } else{
            commands.push_back(vecOfCommand[i]);
        }
    }

    this->stringCommandMap.insert(pair<string, Command*>("openDataServer",new OpenServerCommand()));
    this->stringCommandMap.insert(pair<string, Command*>("connect",new ConnectCommand()));
    this->stringCommandMap.insert(pair<string, Command*>("var", new VarCommand()));
    this->stringCommandMap.insert(pair<string, Command*>("print", new PrintCommand()));
    this->stringCommandMap.insert(pair<string, Command*>("sleep", new SleepCommand()));
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
        WhileCommand* loopCommand = new WhileCommand;
        loopCommand->execute(allConCom, index);
        delete loopCommand;
    } else if (allConCom[0] == "if") {
        IfCommand* ifCommand = new IfCommand;
        ifCommand->execute(allConCom, index);
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
            index = c->execute(commands, index);
            //   delete (c); - not good!
        } else if (dataMaps->getSymbolTable().count(commands[index])) {
            c = new AssignCommand; // symbol without var //
            index = c->execute(commands, index);
            delete (c);
        } else if (commands.at(index) == "if" || commands.at(index) == "while") {
            callCondition();
        }else{
            index++;
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

