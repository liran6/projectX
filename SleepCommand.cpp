//
// Created by liran-baruch on 12/25/18.
//
#include "chrono"
#include "thread"
#include "Command.h"
#include "ShuntingYard.h"
#include "DataMaps.h"
#define LINE_SEPARATOR "@"

int SleepCommand::execute(vector<string> vec, int i) {
    ShuntingYard shuntingYard;
    string result;
    string var = vec[i];
    DataMaps* dataMaps = DataMaps::getInstance();

    for (vec[i]; vec[i] != LINE_SEPARATOR ; i++) {

        if (dataMaps->getSymbolTable().count(vec[i]) == 0){
            result += vec[i];
        }else{
            result += to_string(dataMaps->getSymbolTable().find(vec[i])->second);
        }
    }
    int milliseconds = shuntingYard.expressionEvaluate(result)->calculate();
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
    return i;
}

