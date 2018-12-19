cmake_minimum_required(VERSION 3.12)
project(projectX)

set(CMAKE_CXX_STANDARD 14)

add_executable(projectX main.cpp Lexer.cpp Lexer.h Parser.cpp Parser.h)