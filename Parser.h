//
// Created by yuval on 12/18/18.
//

#ifndef MILESTONE1_PARSER_H
#define MILESTONE1_PARSER_H

#include <iostream>
#include <map>
#include <vector>
#include "Command.h"
#include "DataMaps.h"
#include <algorithm>
#include <list>

using namespace std;

class Parser {
    map<string, Command*> stringCommandMap;
    DataMaps* dataMaps = DataMaps::getInstance();
    vector<string> commands;
    int index;
public:
    Parser(vector<string> vecOfCommand);
    //void parse(vector<string> lexedData);
    void parse();
    void callCondition();
    static int getReturnIndex(vector<string> commandOperation, int index);
    bool checkInVec(vector<char> vec, char & c );
};


#endif //MILESTONE1_PARSER_H
