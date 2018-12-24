
//
// Created by yuval on 12/19/18.
//

#ifndef PROJECTX_PARSER_H
#define PROJECTX_PARSER_H


#include "Lexer.h"
#include "Command.h"
#include <map>
#include <map>
#include <iostream>
#include <fstream>
#define SEPARATOR "@"
using namespace std;

class Parser {
    Lexer* lexer;
    MAP<string, Command>;


public:
    Parser(Lexer* lexer) {
        this->lexer = lexer;
        this->map<>
    }

private:
    void sendToCommand(string strFromLexer){

    lexer->vecOfCommands;
    for(int i = 0; )
}

string lineXfromVector(vector vec, int index){

    while(vec.at(index) != SEPARATOR) {
        int i=0;
        string str[i] = (string) vec.at(index);
        i++;
        index++;

    }
    return str;
}
};


#endif //PROJECTX_PARSER_H

