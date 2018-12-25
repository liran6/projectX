#include <iostream>
#include <list>
#include "Expression.h"
#include "ShuntingYard.h"
#include "Lexer.h"
#include "Parser.h"

using namespace std;

int main() {
    /*cout<< "insert input bitch"<< endl;*/
    string str = "testForLexer.txt";
    cout << str[str.length()-1] << endl;
    Lexer* lex = new Lexer();
    lex->lexer(str);
    Parser *pars = new Parser(lex->vecOfCommands);
    string strFromCommandLine = "hello world and be happy";
    cout << lex->vecOfCommands.at(0) << endl;
    cout << "london goodbye" << endl;

/*    for (vector<char*>::const_iterator iter = lexer.getVecOfCommands();
         iter != getVecOfCommands().end(); ++iter) {
        char firstsquare = lexer.getVecOfCommands()->at(iter);
        cout << *iter << endl;
        cout << lexer.getVecOfCommands() << endl;
        cout << lexer.getVecOfCommands() << endl;
        cout << lexer.getVecOfCommands() << endl;
        cout << lexer.getVecOfCommands() << endl;*/

    return 0;
    }

/*    ShuntingYard x = ShuntingYard();
    list < Expression * > list1;
    Expression* a = x.expressionEvaluate("10 + 2 * 6");
    list1.push_back(a);
    Expression* b = x.expressionEvaluate("100 * 2 + 12");
    list1.push_back(b);
    Expression* c = x.expressionEvaluate("100 * ( 2 + 12 )");
    list1.push_back(c);
    Expression* d = x.expressionEvaluate("100 * ( 2 + 12 ) / 14");
    list1.push_back(d);
    Expression* d1 = x.expressionEvaluate(" + -  40");
    list1.push_back(d1);
    Expression* e = x.expressionEvaluate("5 - + - 3");
    list1.push_back(e);
    Expression* e0 = x.expressionEvaluate("5 + - + 3");
    list1.push_back(e0);
    Expression* e1 = x.expressionEvaluate("5 - - 3");
    list1.push_back(e1);
    Expression* e2 = x.expressionEvaluate("3 - + 10");
    list1.push_back(e2);
    Expression* e22 = x.expressionEvaluate("3 + - 10");
    list1.push_back(e22);
    Expression* e3 = x.expressionEvaluate("3 * - 10");
    list1.push_back(e3);
    Expression* e31 = x.expressionEvaluate("3 * + 10");
    list1.push_back(e31);
    Expression* e32 = x.expressionEvaluate("81 / - 9");
    list1.push_back(e32);
    Expression* e33 = x.expressionEvaluate("81 / + 9");
    list1.push_back(e33);
    Expression* f = x.expressionEvaluate(" - ( - 2 + 4)");
    list1.push_back(f);
    Expression* g = x.expressionEvaluate(" - ( - 6 / - 2)");
    list1.push_back(g);
    Expression* h = x.expressionEvaluate(" - ( - 6 * - 2)");
    list1.push_back(h);
    Expression* i = x.expressionEvaluate(" 0.2 * 0.5 ");
    list1.push_back(i);
    Expression* i1 = x.expressionEvaluate(" (0.8 -(0.2 * 0.5) + 0.8 ) / 0.5 ");
    list1.push_back(i1);
    Expression* i2 = x.expressionEvaluate(" 1/3 ");
    list1.push_back(i2);
    Expression* i3 = x.expressionEvaluate(" 1 / 3 / 1 / 4 / 1 / 5");
    list1.push_back(i3);
    Expression* i4 = x.expressionEvaluate(" (1 / 3)* (1 / 4) * (1 / 5) ");
    list1.push_back(i4);
    Expression* i5 = x.expressionEvaluate(" 51.1676 + 0.8324");
    list1.push_back(i5);


    for (Expression* e : list1){
        cout<< e->calculate()<<endl;
    }*/

/*output:
 * 22
 * 212
 * 1400
 * 100
 * -40
 * 8
 * 2
 * 8
 * -7
 * -7
 * -30
 * 30
 * -9
 * 9
 * -2
 * -3
 * -12
 * 0.1
 * 3
 * 0.333333
 * 0.166667
 * 0.166667
 * */
