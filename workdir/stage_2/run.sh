#!/bin/bash

# To generate the output xsm code
lex lexer.l
yacc -d parser.y
gcc lex.yy.c y.tab.c exprtree.c codeGen.c -o expl
./expl "${1:-}"

# To run the output xsm code
OUTPUT_FILE="$(pwd)/output.xsm"  
cd "$HOME/xsm_expl"
./xsm -l library.lib -e workdir/stage_2/output.xsm