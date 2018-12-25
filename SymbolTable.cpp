//
// Created by yuval on 12/25/18.
//

#ifndef UNTITLED4_SYMBOLETABLE_H
#define UNTITLED4_SYMBOLETABLE_H

#include <map>
#include <string>
#include <iostream>
#include <mutex>

using namespace std;

class SymbolTable {
    static SymbolTable* Stable;
    map<string, double> symbolTable;
    SymbolTable(){};
    map<string,double> pathToValue;
    mutex myLock;

public:
    static SymbolTable* getInstance(){
        if(Stable == NULL){
            Stable = new SymbolTable();
        }
        return Stable;
    }

    void setValue(string &key, double value){
        myLock.lock();
        // Changed values.
        if(pathToValue.count(key))
        {
            pathToValue[key] = value;
            this->symbolTable[key] = value;
        }
        myLock.unlock();
    }
    // The server sets all the time.
    void setValue(string &key, double value,string server){
        myLock.lock();
        if(pathToValue.count(key))
            this->symbolTable[key] = value;
        myLock.unlock();
    }

    double getValue(string key) {

        double result = symbolTable[key];
        return result;
    }

    const map<string, double> &getSymbolTable() const {
        return symbolTable;
    }
    map<string,double> &changedValuesMap(){
        return pathToValue;
    }

};



#endif //UNTITLED4_SYMBOLETABLE_H