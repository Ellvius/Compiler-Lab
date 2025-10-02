#!/bin/bash

set -euo pipefail  # safer: stop on errors, undefined vars, and failed pipes

# Config
PROJECT_ROOT="$(pwd)"
OUTPUT_DIR="$PROJECT_ROOT"
XSM_DIR="$HOME/xsm_expl"
LIBRARY_FILE="library.lib"
STAGE_DIR="workdir/stage_3"

# To delete the existing binaries
rm -f "$OUTPUT_DIR/expl" \
      "$OUTPUT_DIR/label_translator" \
      "$OUTPUT_DIR/label_output.xsm" \
      "$OUTPUT_DIR/output.xsm"

# To generate the output xsm code
pushd lexer >/dev/null
lex lexer.l
popd >/dev/null

pushd parser >/dev/null
yacc -d parser.y
popd >/dev/null

gcc lexer/lex.yy.c \
    parser/y.tab.c \
    exprtree/exprtree.c \
    codeGen/codeGen.c \
    -o "$OUTPUT_DIR/expl"

"$OUTPUT_DIR/expl" "${1:-}"

# Generate label translator and run it
pushd label >/dev/null
lex label.l
popd >/dev/null

gcc label/lex.yy.c \
    label/label.c \
    -o "$OUTPUT_DIR/label_translator"

"$OUTPUT_DIR/label_translator" label_output.xsm output.xsm


# To run the output xsm code
cd "$XSM_DIR"
./xsm -l "$LIBRARY_FILE" -e "$STAGE_DIR/output.xsm" "${2:-}"