//
// Created by yuval on 12/19/18.
//

#ifndef PROJECTX_PARSER_H
#define PROJECTX_PARSER_H


#include "Lexer.h"
#include "Command.h"
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

class Parser {
Lexer* lexer;
map<string, Command> map1;
vector<string> *vecOfComments = lexer->lexer("commandsForTheParser.txt");
public:
void parseToCommand() {
    for (vector<string>::iterator it = vecOfComments->begin(); it != vecOfComments->end(); it++) {
        cout << *it << endl;
    }
}



};


#endif //PROJECTX_PARSER_H
