#ifndef EVALUATOR_HEADER_FILE
#define EVALUATOR_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include "../abstree/abstree.h"

int evaluateCode(ASTNode *node);

int evaluate(ASTNode *root);

#endif