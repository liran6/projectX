//
// Created by yuval on 12/18/18.
//

#include "Lexer.h" //l

Lexer::Lexer(string fileName) {
    //constructor
    this->fileName = fileName;
    if (fileName[fileName.length() - 1] == 't' && (fileName[fileName.length() - 2]) == 'x' &&
        fileName[fileName.length() - 4] == '.') {
        this->vecOfCommands = txtToVec(fileName);
    } else {
        this->vecOfCommands = lexerToVector(fileName);
    }
}

vector<string> *Lexer::txtToVec(string str) {
    string temp = "";
    ifstream fileX(str);
//        vector<string> vec;
    //fileX.open (str, ifstream::in);
    if(!fileX.is_open()){
        cout << "Can't open the file: " << str << endl;
    }
    else{
        while (getline(fileX, line)){
//                for (int i = 0; i< line.length(); i++){
//                    if(line[i] != ' ') {// adding all the whitespace
//                        temp += line[i];
//                    }
//                    else{
//                        this->vecOfCommands.push_back(temp);
//                        temp = "";
//                    }
//                }
            splitToExpression(line);
        }
    }
    return this->vecOfCommands;
}

void Lexer::splitToExpression(string line) {
    string expression;
    int splitter;

    while(splitter != -1){
        splitter = line.find(' ');
        expression = line.substr(0, splitter);
        if(expression == ""){
            line = line.substr(splitter + 1, line.length());
            continue;
        }
        line = line.substr(splitter + 1, line.length());
        this->vecOfCommands->push_back(expression);
    }
    this->vecOfCommands->push_back(LINE_SEPARATOR);



}

vector<string> *Lexer::lexerToVector(string fileName) {

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
