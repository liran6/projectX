//
// Created by liran-baruch on 12/25/18.
//
#include "Parser.h"
#include "Command.h"
#include "ShuntingYard.h"
#include "DataMaps.h"
#define LINE_SEPARATOR "@"

int IfCommand::execute(vector<string> vec, int i) {
    int index = 1;
    ShuntingYard shuntingYard;
    vector<string> condition;
    vector<string> commands;
    DataMaps* dataMaps = DataMaps::getInstance();
    vector<string> args = {"!=", "==", "<", ">", "<=", ">=", "!"};
    vector<string>::iterator iter;

    for (vec[index]; vec[index] != LINE_SEPARATOR || vec[index] != "{" ; index++) {

        condition.push_back(vec[index]);
    }
    for (vec[index]; index < vec.size() ; index++) {

        commands.push_back(vec[index]);
    }

    Parser* parser = new Parser(commands);
    ConditionParser* conditionP = new ConditionParser();
    bool b = conditionP->checkCondition(condition);
    if (b){
        parser->parse();
    }
    delete conditionP;
    delete parser;
    return 0;
}
