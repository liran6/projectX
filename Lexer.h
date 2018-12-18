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
    ofstream fileX;
    string line;
    vector<string> *lexer(string fileX){
        vector<string> *vecOfComments = new vector<string>;
        //open the file
        ifstream in(fileX.c_str());
        if(!in.is_open()){//check if the file is not open.
            cout << "Cannot open the File : " << fileX << endl;
            return vecOfComments;
        }
        string temp;
        while (getline(in, line)){
            for (int i = 0; i< line.length(); i++){
                if(line[i] != ' ') {// adding all the whitespace
                    temp += line[i];
                }
                else{
                    vecOfComments->push_back(temp);
                    temp = "";
                }
            }
        }

        return vecOfComments;
    }

};


#endif //PROJECTX_LEXER_H
