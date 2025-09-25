#ifndef EVALUATOR_HEADER_FILE
#define EVALUATOR_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include "exprtree.h"

int evaluateOperation(tnode* node);

int evaluateCode(tnode *node);

int evaluateAST(tnode *root);

#endif