//
// Created by liran-baruch on 12/25/18.
//

#include "Command.h"
#include "DataMaps.h"

int VarCommand::execute(vector<string> vec, int i) {
    string var = vec[i+1];
    DataMaps* dataMaps = DataMaps::getInstance();
    if(vec[i+2] == "="){
        if(vec[i+3] == "bind"){
            dataMaps->setVarToPathValue(var, vec[i+4]);
            dataMaps->setSymbolTableValue(var, 0);
            return i+5;
        }//else if(isvec[i+3])
    }
    return 0;
}
