#!/bin/bash

set -euo pipefail   # stop on error, undeclared var and pipeline fails

# Config
PROJECT_ROOT="$(pwd)"
XSM_DIR="$HOME/xsm_expl"
LIBRARY_FILE="library.lib"

# Delete existing binaries
rm -f "$PROJECT_ROOT/expl" \
    "$PROJECT_ROOT/label_translator" \
    "$PROJECT_ROOT/label_output.xsm" \
    "$PROJECT_ROOT/output.xsm"

# Frontend generation
pushd abstree >/dev/null
lex abstree.l
yacc -d abstree.y
popd >/dev/null

gcc -g abstree/lex.yy.c \
    abstree/y.tab.c \
    symboltable/symboltable.c \
    abstree/abstree.c \
    codeGen/codeGen.c \
    -o "$PROJECT_ROOT/expl"

"$PROJECT_ROOT/expl" "${1:-}"

# Label translator generation
pushd label >/dev/null
lex label.l
popd >/dev/null

gcc label/lex.yy.c \
    label/label.c \
    -o "$PROJECT_ROOT/label_translator"

"$PROJECT_ROOT/label_translator" label_output.xsm output.xsm

# # To run the output xsm code
cd "$XSM_DIR"
./xsm -l "$LIBRARY_FILE" -e "workdir/stage_6/output.xsm" "${2:-}"