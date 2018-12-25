//
// Created by yuval on 12/25/18.
//
#include "iostream"
#include "Command.h"
#include <map>

using namespace std;

class DataMap{
    map<string, Command> mapToCommands;
    map<string, string> mapToVars;
    map<string, double> mapToNums;

protected:
    static DataMap *obj;

public:
    static DataMap *getInstance(){
        return obj;
    }

    void prn(){
        cout<<"this works!";
    }
};

int main(void){
    DataMap &sys = DataMap::getInstance();
    sys.prn();
}
