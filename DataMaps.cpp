//
// Created by liran-baruch on 12/26/18.
//
#include "DataMaps.h"

DataMaps* DataMaps::instance = nullptr;

DataMaps *DataMaps::getInstance() {

    if(instance == nullptr){
        instance = new DataMaps();
    }
    return instance;

}

void DataMaps::setSymboleTable(const map<string, double> &symboleTable) {
    DataMaps::symboleTable = symboleTable;
}

void DataMaps::setVarToPath(const map<string, string> &varToPath) {
    DataMaps::varToPath = varToPath;
}

const map<string, double> &DataMaps::getPathToVal() const {
    return pathToVal;
}

void DataMaps::setPathToVal(const map<string, double> &pathToVal) {
    DataMaps::pathToVal = pathToVal;
}

const map<string, double> &DataMaps::getSymboleTable() const {
    return symboleTable;
}
const map<string, string> &DataMaps::getVarToPath() const {
    return varToPath;
}

