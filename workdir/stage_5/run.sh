#!/bin/bash

set -euo pipefail   # stop on error, undeclared var and pipeline fails

# Config
PROJECT_ROOT="$(pwd)"

# Delete existing binaries
rm -f "$PROJECT_ROOT/expl"

# Frontend generation
pushd abstree >/dev/null
lex abstree.l
yacc -d abstree.y
popd >/dev/null

gcc -g abstree/lex.yy.c \
    abstree/y.tab.c \
    symboltable/symboltable.c \
    -o "$PROJECT_ROOT/expl"

"$PROJECT_ROOT/expl" "${1:-}"