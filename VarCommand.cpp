//
// Created by liran-baruch on 12/25/18.
//

#include "Command.h"
#include "DataMaps.h"
#include "ShuntingYard.h"

#define LINE_SEPARATOR "@"

int VarCommand::execute(vector<string> vec, int i) {
    ShuntingYard shuntingYard;
    string var = vec[i+1];
    DataMaps* dataMaps = DataMaps::getInstance();
    if(vec[i+2] == "="){
        if(vec[i+3] == "bind"){
            dataMaps->addVarToPathValues(var, vec[i+4]);
            dataMaps->addSymbolTableValues(var, 0);
            return i+5;
        }else {
            dataMaps->addSymbolTableValues(var, 0);
            Command* c = new AssignCommand;
//            int x = i + 3;
//            string result;
//            for (vec[x]; vec[x] != LINE_SEPARATOR ; x++) {
//
//                if (dataMaps->getSymbolTable().count(vec[x]) == 0){
//                    result += vec[x];
//                }else{
//                    result += to_string(dataMaps->getSymbolTable().find(vec[x])->second);
//                }
//            }
//            double val = shuntingYard.expressionEvaluate(result)->calculate();
//            dataMaps->setSymbolTableValue(var, val);
            return c->execute(vec, i+1);
        }
    }
}
