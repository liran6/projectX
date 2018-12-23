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
    vector<string> *vecOfCommands = new vector<string>;
public:

    string fileName;
    string line;
    //ofstream fileX;

    Lexer(string fileName) {//constructor
        this->fileName = fileName;
        this->vecOfCommands = lexerToVector(fileName);
    }

    vector<string> txtToVect(string str){
        ifstream fileX(str);
        vector<string> *vec = new vector<string>;
        if(!fileX.is_open()){
            cout << "Can't open the file: " << str << endl;
        }
        else{
            string toLex = "";
            int i =0;
            while(str[i] != '\n'){
                toLex.push_back(str[i]);
            }
            i++;

                    vec = lexerToVector(toLex);
        }
        return *vec;
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
                splitedWord.push_back(fileName.at(i));

            }
        }
        return vecOfCommands;
    }
/*    vector<string> *lexerToVector(string fileName) {
        ifstream fileX(fileName);
        if (fileX.is_open()) {
            while (!fileX.eof()) {
                string temp;
                getline(fileX, line);
                for (int i = 0; i < line.length(); i++) {
                    if (line[i] != ' ') {// adding all the whitespace
                        temp += line[i];
                    } else if (line[i] == '/n') {
                        vecOfCommands->push_back("/n");
                    } else {
                        vecOfCommands->push_back(temp);
                        temp = "";
                    }
                }
            }
        }
        return vecOfCommands;
    }*/
/*    vector<string> *lexer(string fileName){

        //open the file

        ifstream open("fileName.txt");
        if(!fileName.is_open()){//check if the file is not open.
            cout << "Cannot open the File : " << fileName << endl;
            return vecOfCommands;
        }
        string temp;
        while (getline(fileName, line)){
            for (int i = 0; i< line.length(); i++){
                if(line[i] != ' ') {// adding all the whitespace
                    temp += line[i];
                }
                else{
                    vecOfCommands->push_back(temp);
                    temp = "";
                }
            }
        }
        return vecOfCommands;
    }*/


    vector<string> *getVecOfCommands() const {
        return this->vecOfCommands;
    }

};


#endif //PROJECTX_LEXER_H
