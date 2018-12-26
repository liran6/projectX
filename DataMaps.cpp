//
// Created by liran-baruch on 12/26/18.
//
#include "DataMaps.h"

DataMaps* DataMaps::instance = nullptr;
mutex myLock;

DataMaps *DataMaps::getInstance() {

    if(instance == nullptr){
        instance = new DataMaps();
    }
    return instance;

}

void DataMaps::setVarToPathValue(string &key, string path) {
    myLock.lock();
    varToPath[key] = path;
    myLock.unlock();
}

void DataMaps::setSymbolTable(const map<string, double> &symboleTable) {
    DataMaps::symbolTable = symboleTable;
}

void DataMaps::setVarToPath(const map<string, string> &varToPath) {
    DataMaps::varToPath = varToPath;
}

void DataMaps::setPathToVal(const map<string, double> &pathToVal) {
    DataMaps::pathToVal = pathToVal;
}

const map<string, double> &DataMaps::getPathToVal() const {
    return pathToVal;
}

const map<string, double> &DataMaps::getSymbolTable() const {
    return symbolTable;
}

const map<string, string> &DataMaps::getVarToPath() const {
    return varToPath;
}

string DataMaps::getVarToPathValue(string key) {
    return varToPath[key];
}

void DataMaps::setSymbolTableValue(string &key, double value) {
    myLock.lock();
    // Changed values.
    if(pathToVal.count(key))
    {
        pathToVal[key] = value;
        this->symbolTable[key] = value;
    }
    myLock.unlock();
}

void DataMaps::setSymbolTableValue(string &key, double value, string server) {
    myLock.lock();
    if(pathToVal.count(key))
        this->symbolTable[key] = value;
    myLock.unlock();
}

double DataMaps::getSymbolTableValue(string key) {
    double result = symbolTable[key];
    return result;
}






