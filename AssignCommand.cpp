//
// Created by liran-baruch on 12/25/18.
//

#include "Command.h"
#include "ShuntingYard.h"
#include "DataMaps.h"

#define LINE_SEPARATOR "@"

int AssignCommand::execute(vector<string> vec, int i) {
    string var = vec[i];
    ShuntingYard shuntingYard;
    DataMaps* dataMaps = DataMaps::getInstance();
    int x = i +2;
    string result;
    for (vec[x]; vec[x] != LINE_SEPARATOR ; x++) {

        if (dataMaps->getSymbolTable().count(vec[x]) == 0){
            result += vec[x];
        }else{
            result += to_string(dataMaps->getSymbolTable().find(vec[x])->second);
        }
    }
    double val = shuntingYard.expressionEvaluate(result)->calculate();
    dataMaps->setSymbolTableValue(var, val);
    return x;


    //return 0;
}
