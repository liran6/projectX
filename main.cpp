#include <iostream>
#include "Lexer.h"

using namespace std;

int main() {
    Lexer lexer;
    vector<string> *vec;
    vec = lexer.lexer("testForLexer.txt");
for(int i= 0; i<vec->size(); i++){
    for(int j = 0; j<i; j++){
        cout<< vec[i][j]<<endl;
    }
}
    //cout << vec[3][5] << endl;
}