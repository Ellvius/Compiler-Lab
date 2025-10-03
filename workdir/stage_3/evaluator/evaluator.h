#ifndef EVALUATOR_HEADER_FILE
#define EVALUATOR_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include "../exprtree/exprtree.h"

int evaluateCode(tnode *node);

int evaluate(tnode *root);

#endif