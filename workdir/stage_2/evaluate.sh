#!/bin/bash

# To generate the output xsm code
cd lex
lex lexer.l
cd ../yacc
yacc -d evaluator.y
cd ..
gcc -g lex/lex.yy.c yacc/y.tab.c exprtree/exprtree.c evaluator/evaluator.c -o expl
./expl "${1:-}"