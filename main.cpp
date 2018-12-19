#include <iostream>
#include "Expression.h"
#include "ShuntingYard.h"
#include "Lexer.h"
#include "Parser.h"

using namespace std;

int main() {
    Parser *pars;
    pars->parseToCommand();
    /*
    cout << "Hello, World!" << endl;
    ShuntingYard x = ShuntingYard();
    Expression* a = x.expressionEvaluate("10 + 2 * 6");
    Expression* b = x.expressionEvaluate("100 * 2 + 12");
    Expression* c = x.expressionEvaluate("100 * ( 2 + 12 )");
    Expression* d = x.expressionEvaluate("100 * ( 2 + 12 ) / 14");
    Expression* e = x.expressionEvaluate("-12");
//    double r = i->calculate();
    cout<<a->calculate()<<endl;
    cout<<b->calculate()<<endl;
    cout<<c->calculate()<<endl;
    cout<<d->calculate()<<endl;
    */

    return 0;
}