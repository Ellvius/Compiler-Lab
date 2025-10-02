#ifndef CODE_GEN_HEADER_FILE
#define CODE_GEN_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include "../exprtree/exprtree.h"

#define SP 4096
#define reg_index int

typedef struct snode {
    int start;
    int end;
    struct snode* next;
} snode;

// Stack structure
typedef struct {
    snode* top;
} Stack;

// Stack operations
Stack* createStack(void);
void push(Stack* stack, int start, int end);
snode* pop(Stack* stack);
snode* peek(Stack* stack);
void freeStack(Stack* stack);

reg_index getReg(void);
int freeReg(void);

void codeGenHeader(FILE* fp);
void codeGenExit(FILE* fp);

reg_index codeGenID(tnode *node, FILE* fp);
reg_index codeGenNUM(tnode *node, FILE* fp);
reg_index codeGenOP(tnode *node, FILE* fp);
reg_index codeGenRead(tnode* node, FILE* fp);
reg_index codeGenWrite(tnode* node, FILE* fp);

reg_index codeGenIfElse(tnode* node, FILE* fp);
reg_index codeGenWhile(tnode* node, FILE* fp);
reg_index codeGenBreak(tnode* node, FILE* fp);
reg_index codeGenContinue(tnode* node, FILE* fp);

int codeGenNODE(tnode* node, FILE* fp);
int codeGen(tnode *node);

#endif