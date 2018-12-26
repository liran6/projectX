//
// Created by liran-baruch on 12/26/18.
//

#ifndef PROJECTX_DATAMAPS_H
#define PROJECTX_DATAMAPS_H


#include <map>
#include <string>
#include <iostream>
#include <mutex>

using namespace std;

class DataMaps{
    static DataMaps* instance;
    map<string, string> varToPath;
    map<string, double> pathToVal;
    map<string, double> symboleTable;
    mutex mylock;
    DataMaps(){};

public:
    static DataMaps* getInstance();

    const map<string, string> &getVarToPath() const;

    void setVarToPath(const map<string, string> &varToPath);

    const map<string, double> &getPathToVal() const;

    void setPathToVal(const map<string, double> &pathToVal);

    const map<string, double> &getSymboleTable() const;

    void setSymboleTable(const map<string, double> &symboleTable);


};






#endif //PROJECTX_DATAMAPS_H
