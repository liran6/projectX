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

using namespace std;
class Lexer {

public:

    string fileName;
    string line;
    vector<string> *vecOfCommands = new vector<string>;

    Lexer(string fileName) {//constructor
        this->fileName = fileName;
        if(fileName[fileName.length()] == 't' && (fileName[fileName.length()-1]) == 'x' &&
           fileName[fileName.length()-3] == '.'){
            this->vecOfCommands = txtToVec(fileName);
        }
        else {
            this->vecOfCommands = lexerToVector(fileName);
        }
    }

    vector<string> *txtToVec(string str){
        ifstream fileX;
        fileX.open (str, ifstream::in);
        string temp = "";
        if(!fileX.is_open()){
            cout << "Can't open the file: " << str << endl;
        }
        else{
            while (getline(fileX, line)){
                for (int i = 0; i< line.length(); i++){
                    if(line[i] != ' ' || line[i] != '\n') {// adding all the whitespace
                        temp += line[i];
                    }
                    else{
                        this->vecOfCommands->push_back(temp);
                        temp = "";
                    }
                }
            }
        }
        return this->vecOfCommands;
    }

    vector<string> *lexerToVector(string fileName){

        string splitedWord = "";
        for(int i = 0; i< fileName.length(); i++) {
            if (fileName[i] == '\n' || fileName[i] == '\r' || fileName[i] == '\t') {
                i++;
            } else if (fileName[i] == ' ') {
                vecOfCommands->push_back(splitedWord);
                splitedWord = "";
            } else {
                splitedWord.push_back(fileName[i]);
            }
        }
        return vecOfCommands;
    }

    vector<string> *getVecOfCommands() const {
        return this->vecOfCommands;
    }
};


#endif //PROJECTX_LEXER_H
