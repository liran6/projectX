//
// Created by liran-baruch on 12/26/18.
//
#include "DataMaps.h"
#include <sstream>

DataMaps* DataMaps::instance = nullptr;
mutex myLock;

DataMaps *DataMaps::getInstance() {

   if(instance == nullptr){
        instance = new DataMaps();
    }
    return instance;

}

double DataMaps::getSymbolTableValue(string key) {
    double result = symbolTable[key];
    return result;
}


void DataMaps::setSymbolTableValue(string &key, double value) {
    myLock.lock();
    // Changed values.
    if(varToPath.count(key))
    {
        string path = varToPath.find(key)->second;
        pathToVal[path] = value;
    }
    this->symbolTable[key] = value;
    myLock.unlock();
}

string DataMaps::getVarToPathValue(string key) {
    return varToPath[key];
}

void DataMaps::setVarToPathValue(string &key, string path) {
    myLock.lock();
    string x = varToPath.find(key)->second;
    if(pathToVal.count(x)) {
        pathToVal[path] = pathToVal[x];
        //pathToVal.erase(x);
    }
    varToPath[key] = path;

    myLock.unlock();
}

void DataMaps::setSymbolTable(const map<string, double> &symbolTable) {
    DataMaps::symbolTable = symbolTable;
}

void DataMaps::setVarToPath(const map<string, string> &varToPath) {
    DataMaps::varToPath = varToPath;
}

void DataMaps::setPathToVal(string buffFromServer) {
    istringstream ss(buffFromServer);
    string token;
    vector<double> values;
    while(getline(ss, token, ',')) {
        values.push_back(stod(token));
    }
    int i;
    for(i = 0; i< sizeof(values); i++){
        this->pathToVal;
    }

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

void DataMaps::addVarToPathValues(string &key, string path) {
    DataMaps::varToPath.insert(pair<string, string>(key, path));
    DataMaps::pathToVal.insert(pair<string, double >(path, 0));
}

void DataMaps::addSymbolTableValues(string &key, double value) {
    DataMaps::symbolTable.insert(pair<string, double>(key, value));
    setSymbolTableValue(key, value);
}
void DataMaps::initializePaths() {
    this->paths = {pair<string, double>("/instrumentation/airspeed-indicator/indicated-speed-kt", 0),
                        pair<string, double>("/instrumentation/altimeter/indicated-altitude-ft", 0),
                        pair<string, double>("/instrumentation/altimeter/pressure-alt-ft", 0),
                        pair<string, double>("/instrumentation/attitude-indicator/indicated-pitch-deg", 0),
                        pair<string, double>("/instrumentation/attitude-indicator/indicated-roll-deg", 0),
                        pair<string, double>("/instrumentation/attitude-indicator/internal-pitch-deg", 0),
                        pair<string, double>("/instrumentation/attitude-indicator/internal-roll-deg", 0),
                        pair<string, double>("/instrumentation/encoder/indicated-altitude-ft", 0),
                        pair<string, double>("/instrumentation/encoder/pressure-alt-ft", 0),
                        pair<string, double>("/instrumentation/gps/indicated-altitude-ft", 0),
                        pair<string, double>("/instrumentation/gps/indicated-ground-speed-kt", 0),
                        pair<string, double>("/instrumentation/gps/indicated-vertical-speed", 0),
                        pair<string, double>("/instrumentation/heading-indicator/indicated-heading-deg", 0),
                        pair<string, double>("/instrumentation/magnetic-compass/indicated-heading-deg", 0),
                        pair<string, double>("/instrumentation/slip-skid-ball/indicated-slip-skid", 0),
                        pair<string, double>("/instrumentation/turn-indicator/indicated-turn-rate", 0),
                        pair<string, double>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0),
                        pair<string, double>("/controls/flight/aileron", 0),
                        pair<string, double>("/controls/flight/elevator", 0),
                        pair<string, double>("/controls/flight/rudder", 0),
                        pair<string, double>("/controls/flight/flaps", 0),
                        pair<string, double>("/controls/engines/engine/throttle", 0),
                        pair<string, double>("/engines/engine/rpm", 0)};
}

//
//void DataMaps::setSymbolTableValue(string &key, double value, string server) {
//    myLock.lock();
//    if(pathToVal.count(key))
//        this->symbolTable[key] = value;
//    myLock.unlock();
//}







