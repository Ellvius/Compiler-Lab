#ifndef CODE_GEN_HEADER_FILE
#define CODE_GEN_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include "exprtree.h"

#define SP 4122
#define reg_index int

reg_index getReg(void);

int freeReg(void);

void codeGenHeader(FILE* fp);

void codeGenExit(FILE* fp);

reg_index codeGenID(tnode *node, FILE* fp);

reg_index codeGenNUM(tnode *node, FILE* fp);

reg_index codeGenOP(tnode *node, FILE* fp);

reg_index codeGenRead(tnode* node, FILE* fp);

reg_index codeGenWrite(tnode* node, FILE* fp);

int codeGenNODE(tnode* node, FILE* fp);

int codeGen(tnode *node);

#endif