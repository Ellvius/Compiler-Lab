#!/bin/bash

# To generate the output xsm code
lex lexer.l
yacc -d evaluator_parser.y
gcc -g lex.yy.c y.tab.c exprtree.c evaluator.c -o expl
./expl "${1:-}"