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

    vector<string> vecOfCommands;

    vector<string> lexer(string fileName);

    void txtToVec(string str);

    void splitToExpression(string line);


    void lexerToVector(string fileName);


};


#endif //PROJECTX_LEXER_H
