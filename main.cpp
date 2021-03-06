#include <iostream>
#include <list>
#include "Expression.h"
#include "ShuntingYard.h"

using namespace std;

int main() {
    ShuntingYard x = ShuntingYard();
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
    Expression* i4 = x.expressionEvaluate(" 1 / 3 * 1 / 4 * 1 / 5 ");
    list1.push_back(i4);


    for (Expression* e : list1){
        cout<< e->calculate()<<endl;
    }

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
 * */

    return 0;
}