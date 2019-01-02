#include <iostream>
#include <list>
#include "Expression.h"
#include "ShuntingYard.h"
#include "Lexer.h"
#include "Parser.h"
#define FILE_INDEX 1
using namespace std;


/**
 * Run the program
 * @param file_name is the file name to read from.
 */
void run(string file_name) {
    Lexer *lex = new Lexer();
    lex->lexer(file_name);
    Parser *pars = new Parser(lex->vecOfCommands);
    pars->parse();
    // delete memory
    delete pars;
    delete lex;

}

/**
 * Main
 * @param argc
 * @param argv includes the file name of the script.
 */
int main(int argc, char *argv[]) {

    run(argv[FILE_INDEX]);
    pthread_exit(nullptr);
}