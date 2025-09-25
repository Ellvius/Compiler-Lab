#!/bin/bash

# To generate the output xsm code
cd lexer
lex lexer.l
cd ../parser
yacc -d eval_parser.y
cd ..
gcc -g lexer/lex.yy.c parser/y.tab.c exprtree/exprtree.c evaluator/evaluator.c -o expl
./expl "${1:-}"