#!/bin/bash

# To generate the output xsm code
cd lex
lex lexer.l
cd ../yacc
yacc -d parser.y
cd ..
gcc lex/lex.yy.c yacc/y.tab.c exprtree/exprtree.c codeGen/codeGen.c -o expl
./expl "${1:-}"

# To run the output xsm code
OUTPUT_FILE="$(pwd)/output.xsm"  
cd "$HOME/xsm_expl"
./xsm -l library.lib -e workdir/stage_2/output.xsm