#ifndef CODE_GEN_HEADER_FILE
#define CODE_GEN_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include "../abstree/abstree.h"

#define SP 4096
#define RegIndex int

typedef struct LabelNode {
    int start;
    int end;
    struct LabelNode* next;
} LabelNode;

// Stack structure
typedef struct {
    LabelNode* top;
} Stack;

// Stack operations
Stack* createStack(void);
void push(Stack* stack, int start, int end);
LabelNode* pop(Stack* stack);
LabelNode* peek(Stack* stack);
void freeStack(Stack* stack);

RegIndex getReg(void);
int freeReg(void);

void codeGenHeader(FILE* fp);
void codeGenExit(FILE* fp);

RegIndex codeGenID(ASTNode *node, FILE* fp);
RegIndex codeGenConst(ASTNode *node, FILE* fp);
RegIndex codeGenOP(ASTNode *node, FILE* fp);
RegIndex codeGenRead(ASTNode* node, FILE* fp);
RegIndex codeGenWrite(ASTNode* node, FILE* fp);

RegIndex codeGenIfElse(ASTNode* node, FILE* fp);
RegIndex codeGenIteration(ASTNode* node, FILE* fp);
RegIndex codeGenBreak(ASTNode* node, FILE* fp);
RegIndex codeGenContinue(ASTNode* node, FILE* fp);

int codeGenNODE(ASTNode* node, FILE* fp);
int codeGen(ASTNode *node);

#endif