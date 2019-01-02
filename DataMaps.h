//
// Created by liran-baruch on 12/26/18.
//

#ifndef PROJECTX_DATAMAPS_H
#define PROJECTX_DATAMAPS_H


#include <map>
#include <string>
#include <iostream>
#include <mutex>
#include <vector>

using namespace std;

class DataMaps{
    static DataMaps* instance;
    map<string, string> varToPath;
    map<string, double> pathToVal;
    map<string, double> symbolTable;
    vector<pair<string, double>> paths;

    DataMaps(){};

public:

    static DataMaps* getInstance();

    const map<string, string> &getVarToPath() const;

    void setVarToPath(const map<string, string> &varToPath);

    void addVarToPathValues(string &key, string path);

    void addSymbolTableValues(string &key, double value);

    const map<string, double> &getPathToVal() const;

    //void setPathToVal(const map<string, double> &pathToVal);
    void setPathToVal(string buffFromServer);

    const map<string, double> &getSymbolTable() const;

    void setSymbolTable(const map<string, double> &symbolTable);

    void setVarToPathValue(string &key, string path);

    string getVarToPathValue(string key);

    void setSymbolTableValue(string &key, double value);
    // The server sets all the time.
    //void setSymbolTableValue(string &key, double value,string server);

    double getSymbolTableValue(string key);
    void initializePaths();





};






#endif //PROJECTX_DATAMAPS_H
