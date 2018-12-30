//
// Created by yuval on 24/18/18.
//

#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include "Lexer.h"
#include <map>
#include "stdio.h"
#include "Command.h"
#include <vector>
#include <list>
#include <algorithm>


#define LINE_SEPARATOR "@"

using namespace std;


vector<string> Lexer::lexer(string fileName) {
    //constructor
    vector<string> vecOfCommands;
    if (fileName[fileName.length() - 1] == 't' && (fileName[fileName.length() - 2]) == 'x' &&
        fileName[fileName.length() - 4] == '.') {
        txtToVec(fileName);
    } else {
        lexerToVector(fileName);
    }
    return this->vecOfCommands;
}

void Lexer::txtToVec(string str) {
    string line;
    ifstream file;
    file.open(str);
//        vector<string> vec;
    //file.open (str, ifstream::in);
    if(!file.is_open()){
        cout << "Can't open the file: " << str << endl;
    }
    else{
        vector <string> args = { ",", "*", "/", "+", "=", "-", "\"", "{", "}", "<", ">", "(", ")"};
        vector<string>::iterator iter;
        while (getline(file, line)){
//                for (int i = 0; i< line.length(); i++){
//                    if(line[i] != ' ') {// adding all the whitespace
//                        temp += line[i];
//                    }
//                    else{
//                        this->vecOfCommands.push_back(temp);
//                        temp = "";
//                    }
//                }
            for (iter = args.begin();iter < args.end(); iter++) {
//                if(line.find(*iter) != -1) {
//                    line.insert(line.find(*iter), 1, ' ');
//                    line.insert(line.find(*iter) + 1, 1, ' ');
//                }
//                string x = boost::replaceAll()
                string s = line ;
                string y;
                string delimiter = *iter;

                size_t pos = 0;
                string token;
                while ((pos = s.find(delimiter)) != string::npos) {
                    token = s.substr(0, pos);
                    y += token + ' '+*iter+' ';
                    s.erase(0, pos + delimiter.length());
                }
                y += s;
                line = y;
            }
//            for (int i = 0; i < ; ++i) {
//
//            }
//            if(line.find(',') != -1){
//                line.insert(line.find(','), 1, ' ');
//                line.insert(line.find(',') + 1 , 1, ' ');
//            }
//            if(line.find('-') != -1){
//                line.insert(line.find('-'), 1, ' ');
//                line.insert(line.find('-') + 1 , 1, ' ');
//            }
//            if(line.find('*') != -1){
//                line.insert(line.find('*'), 1, ' ');
//                line.insert(line.find('*') + 1 , 1, ' ');
//            }
//            if(line.find('/') != -1){
//                line.insert(line.find('/'), 1, ' ');
//                line.insert(line.find('/') + 1 , 1, ' ');
//            }
//            if(line.find('+') != -1){
//                line.insert(line.find('+'), 1, ' ');
//                line.insert(line.find('+') + 1 , 1, ' ');
//            }
//            if(line.find('=') != -1){
//                line.insert(line.find('='), 1, ' ');
//                line.insert(line.find('=') + 1 , 1, ' ');
//            }
//            if(line.find('{') != -1){
//                line.insert(line.find('{'), 1, ' ');
//                line.insert(line.find('{') + 1 , 1, ' ');
//            }
//            if(line.find('}') != -1){
//                line.insert(line.find('}'), 1, ' ');
//                line.insert(line.find('}') + 1 , 1, ' ');
//            }
//            if(line.find('\"') != -1){
//                line.insert(line.find('\"'), 1, ' ');
//                line.insert(line.find('\"') + 1 , 1, ' ');
//            }
//            if(line.find("bind") != -1){
//                line.insert(line.find("bind"), 1, ' ');
//                line.insert(line.find("bind") + 4 , 1, ' ');
//            }

            splitToExpression(line);
        }
    }

}

void Lexer::splitToExpression(string line) {
    string expression = "";
    int splitter = 0;

    while(splitter != -1){
        splitter = line.find(' ');
        expression = line.substr(0, splitter);
        if(expression.empty()){
            line = line.substr(splitter + 1, line.length());
            continue;
        }
        line = line.substr(splitter + 1, line.length());
        this->vecOfCommands.push_back(expression);
    }
    this->vecOfCommands.push_back(LINE_SEPARATOR);

}

void Lexer::lexerToVector(string fileName) {

    string splitedWord = "";
    for(int i = 0; i< fileName.length(); i++) {
        if (fileName[i] == '\n' || fileName[i] == '\r' || fileName[i] == '\t') {
            i++;
        } else if (fileName[i] == ' ') {
            vecOfCommands.push_back(splitedWord);
            splitedWord = "";
        } else {
            splitedWord.push_back(fileName[i]);
        }
    }
}


