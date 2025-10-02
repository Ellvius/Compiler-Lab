#!/bin/bash
set -euo pipefail  # safer script: exit on error, fail on unset vars, fail on broken pipes

rm -f "expl"

pushd lexer >/dev/null
lex lexer.l
popd >/dev/null

pushd parser >/dev/null
yacc -d eval_parser.y
popd >/dev/null

gcc -g lexer/lex.yy.c \
    parser/y.tab.c \
    exprtree/exprtree.c \
    evaluator/evaluator.c \
    -o "expl"

"./expl" "${1:-}"