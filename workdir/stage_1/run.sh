#!/bin/bash

lex lexer.l
yacc -d parser.y
gcc lex.yy.c y.tab.c expr.c -o expr
./expr "${1:-}"