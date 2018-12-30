//
// Created by liran-baruch on 12/30/18.
//
#include "Command.h"
#include <vector>
#include "ShuntingYard.h"
#include "DataMaps.h"
#define LINE_SEPARATOR "@"

 bool ConditionParser::checkCondition(vector<string> vec){
    int index = 0;
    string leftArg;
    string rightArg;
    string condition;
    int argFlag = 0;
    double left;
    double right;
    ShuntingYard shuntingYard;
    DataMaps* dataMaps = DataMaps::getInstance();
    vector<string> args = {"!=", "==", "<", ">", "<=", ">=", "!"};
    vector<string>::iterator iter;
    for (int i = 0; i < vec.size();i++) {
        if(dataMaps->getSymbolTable().count(vec[i])){
            vec[i] = to_string(dataMaps->getSymbolTable().find(vec[i])->second);
        }
        if (argFlag){
            rightArg += vec[i];
        }else{
            for(iter = args.begin();iter < args.end(); iter++) {
                if (vec[i] == *iter) {
                    condition = *iter;
                    argFlag = 1;
                    break;
                }
            }
            if(!argFlag){
                leftArg += vec[i];
            }
        }
    }

    left = shuntingYard.expressionEvaluate(leftArg)->calculate();
    right = shuntingYard.expressionEvaluate(rightArg)->calculate();
    if(condition == "=="){
        return (left == right);
    }
    if(condition == "!="){
        return (left != right);
    }
    if(condition == "<"){
        return (left < right);
    }
    if(condition == ">"){
        return (left > right);
    }
    if(condition == "<="){
        return (left <= right);
    }
    if(condition == ">="){
        return (left >= right);
    }
    if(condition == "!"){
        return !right;
    }
}