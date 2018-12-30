//
// Created by liran-baruch on 12/25/18.
//


#include "Command.h"
#include "DataMaps.h"
#define LINE_SEPARATOR "@"

int PrintCommand::execute(vector<string> vec, int i) {

    string content;
    string var = vec[i];
    DataMaps* dataMaps = DataMaps::getInstance();

    for (vec[i]; vec[i] != LINE_SEPARATOR ; i++) {

        if (dataMaps->getSymbolTable().count(vec[i]) == 0){
            content += vec[i];
        }else{
            content += to_string(dataMaps->getSymbolTable().find(vec[i])->second);
        }
    }
    cout<< content<< endl;
    return i;
}