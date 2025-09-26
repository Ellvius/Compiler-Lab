#!/bin/bash

# To generate the output xsm code
cd lexer
lex lexer.l
cd ../parser
yacc -d parser.y
cd ..
gcc lexer/lex.yy.c parser/y.tab.c exprtree/exprtree.c codeGen/codeGen.c -o expl
./expl "${1:-}"

# Generate label translator and run it
cd label
lex label.l
cd ..
gcc label/lex.yy.c label/label.c -o label_translator
./label_translator label_output.xsm output.xsm

# To run the output xsm code
OUTPUT_FILE="$(pwd)/output.xsm"  
cd "$HOME/xsm_expl"
./xsm -l library.lib -e workdir/stage_3/output.xsm