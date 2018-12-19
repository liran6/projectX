//
// Created by liran-baruch on 12/18/18.
//

#include "ShuntingYard.h"
#include "Plus.h"
#include "Mul.h"
#include "Div.h"
#include "Minus.h"
#include "Number.h"
#include <bits/stdc++.h>
using namespace std;

// Function to find precedence of
// operators.
int ShuntingYard::precedence(char op){
    if(op == '+'||op == '-')
        return 1;
    if(op == '*'||op == '/')
        return 2;
    return 0;
}

// Function to perform arithmetic operations.
Expression *ShuntingYard::applyOp(Expression *leftVal, Expression *rightVal, char op){
    switch(op){
        case '+': return new Plus(leftVal, rightVal);
        case '-': return new Minus(leftVal, rightVal);
        case '*': return new Mul(leftVal, rightVal);
        case '/': return new Div(leftVal, rightVal);
    }
}

// Function that returns value of
// expression after evaluation.
Expression * ShuntingYard::expressionEvaluate(string tokens){
    int i;
    bool afterOp = true;
    bool makeNeg = false;
    // stack to store integer values.
    stack <Expression*> values;

    // stack to store operators.
    stack <char> ops;

    for(i = 0; i < tokens.length(); i++) {

        // Current token is a whitespace,
        // skip it.
        if (tokens[i] == ' ')
            continue;
        else if (tokens[i] == '-' && afterOp) {
//                Expression *num = new Number(0);
//                values.push(num);
//            if(ops.top() == '*' || ops.top() == '/'){
//                Expression *num = new Number(-1);
                makeNeg = true;
//
//            }

        }
            // Current token is an opening
            // brace, push it to 'ops'
        else if (tokens[i] == '(') {
            if(makeNeg){
                Expression *num = new Number(-1);
                values.push(num);
                ops.push('*');
                makeNeg = false;
            }
            ops.push(tokens[i]);
            afterOp = true;
        }else if(tokens[i] == '.' && isdigit(tokens[i+1])){

        }

            // Current token is a number, push
            // it to stack for numbers.
        else if (isdigit(tokens[i]) || (tokens[i] == '.' && isdigit(tokens[i+1]))) {
            double val = 0;
            int floatCheck = 0;
            int afterDot = 1;
            while (i < tokens.length() && ( tokens[i] == '.' ||
                   isdigit(tokens[i]))) {
                if(floatCheck > 1){
                    throw runtime_error("Exception, cannot put 2 dots in a number.");
                }
                if(tokens[i] == '.'){
                    floatCheck ++;
                    i++;
                }else if(floatCheck == 0) {
                    val = (val * 10) + (tokens[i] - '0');
                    i++;
                }else{
                    val += ((double)tokens[i] - '0') / (10 * afterDot);
                    i++;
                    afterDot++;
                }
            }

            i--;
            if (makeNeg){
                val *= -1;
                makeNeg = false;
            }
            Expression *num = new Number(val);
            values.push(num);
            afterOp = false;
        }

            // Closing brace encountered, solve
            // entire brace.
        else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                Expression *val2 = values.top();
                values.pop();

                Expression *val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // pop opening brace.
            ops.pop();
        }
            // Current token is an operator.
        else {
                if(tokens[i] == '+' && afterOp){
                    continue;
                }
                if((tokens[i] == '/' || tokens [i] == '*') && afterOp){
                    throw runtime_error("Syntax ERROR!, fuck you! madafaka! ");
                }
                if(values.empty() && (tokens[i] == '/' || tokens [i] == '*')){
                    throw runtime_error("Syntax ERROR!, fuck you! madafaka! ");
                }
                // While top of 'ops' has same or greater
                // precedence to current token, which
                // is an operator. Apply operator on top
                // of 'ops' to top two elements in values stack.
                while (!ops.empty() && precedence(ops.top())
                                       >= precedence(tokens[i])) {
                    Expression *val2 = values.top();
                    values.pop();

                    Expression *val1 = values.top();
                    values.pop();

                    char op = ops.top();
                    ops.pop();

                    values.push(applyOp(val1, val2, op));
                }

            // Push current token to 'ops'.
            ops.push(tokens[i]);
            afterOp = true;
        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while(!ops.empty()){
        Expression *val2 = values.top();
        values.pop();

        Expression *val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    // Top of 'values' contains result, return it.
    return values.top();
}
