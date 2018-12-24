//
// Created by yuval on 12/18/18.
//

#ifndef PROJECTX_LEXER_H
#define PROJECTX_LEXER_H

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "stdio.h"
#include "Command.h"
#include <vector>
#define LINE_SEPARATOR "@"

using namespace std;
class Lexer {


public:
    string fileName;
    string line;
    vector<string>* vecOfCommands;

    Lexer(string fileName);

    vector<string> *txtToVec(string str);

    void splitToExpression(string line);


    vector<string> *lexerToVector(string fileName);

    vector<string> *getVecOfCommands() const {
        return this->vecOfCommands;
    }
};


#endif //PROJECTX_LEXER_H
