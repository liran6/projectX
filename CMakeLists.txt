cmake_minimum_required(VERSION 3.12)
project(projectX)

set(CMAKE_CXX_STANDARD 14)

add_executable(projectX main.cpp Lexer.cpp Lexer.h Expression.h Number.cpp Number.h BinaryExpression.cpp BinaryExpression.h Plus.cpp Plus.cpp Plus.h Minus.cpp Minus.h Mul.cpp Mul.h Div.cpp Div.h ShuntingYard.cpp ShuntingYard.h UnaryExpression.cpp UnaryExpression.h Neg.cpp Neg.h Parser.cpp Parser.h OpenServerCommand.cpp VarCommand.cpp WhileCommand.cpp SleepCommand.cpp PrintCommand.cpp IfCommand.cpp ExitCommand.cpp ConnectCommand.cpp AssignCommand.cpp SymbolTable.cpp BindCommand.cpp DataMaps.h DataMaps.cpp OPENDADACOMMAND.cpp)