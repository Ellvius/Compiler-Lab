#!/bin/bash

lex lexer.l
yacc -d parser.y
gcc lex.yy.c y.tab.c ./exprtree/exprtree.c -o expl
./expl "${1:-}"