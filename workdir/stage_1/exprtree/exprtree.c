#include <stdio.h>
#include <stdlib.h>
#include "exprtree.h"

struct tnode* makeLeafNode(int n){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}

void prefixForm(struct tnode *t){
    if(t->op == NULL){
        printf("%d ", t->val);
    }
    else{
        printf("%s ", t->op);
        prefixForm(t->left);
        prefixForm(t->right);
    }
}

void postfixForm(struct tnode *t){
    if(t->op == NULL){
        printf("%d ", t->val);
    }
    else{
        postfixForm(t->left);
        postfixForm(t->right);
        printf("%s ", t->op);
    }
}


static int regNum = 0;

reg_index getReg(void){
    if(regNum==19){
        fprintf(stderr, "\nRegisters exhausted\n"); 
        exit(1);
    }
    return regNum++;
}


int freeReg(void){
    if(regNum == 0){
        fprintf(stderr,"\nNo registers to be freed\n");
        exit(1);
    }
    return regNum--;
}

void generateHeader(FILE* fp){
    fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\n");
}

void codeGenWrite(FILE* fp, int val){
    int r = getReg();
    fprintf(fp, "MOV [4096], R%d\n", val);
    fprintf(fp, "MOV R%d,\"Write\"\n", r);
    fprintf(fp, "PUSH R%d\n", r);
    fprintf(fp, "MOV R%d, -2\n", r);
    fprintf(fp, "PUSH R%d\n", r);
    fprintf(fp, "PUSH R%d\n", val);
    fprintf(fp, "PUSH R%d\n", val);
    fprintf(fp, "PUSH R%d\n", val);
    fprintf(fp, "CALL 0\n");
    fprintf(fp, "POP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n", val, val, val, val, val);
    freeReg();
    freeReg();
}

void codeGenExit(FILE* fp){
    int r = getReg();
    fprintf(fp, "MOV R%d,\"Exit\"\n", r);
    fprintf(fp, "PUSH R%d\n", r);
    fprintf(fp, "PUSH R%d\n", r);
    fprintf(fp, "PUSH R%d\n", r);
    fprintf(fp, "PUSH R%d\n", r);
    fprintf(fp, "PUSH R%d\n", r);
    fprintf(fp, "CALL 0\n");
    freeReg();
}

reg_index codeGen(struct tnode *node, FILE* fp){
    if(node->op == NULL){
        int r = getReg();
        fprintf(fp,"MOV R%d, %d\n", r, node->val);
        return r;
    }
    int l = codeGen(node->left, fp);
    int r = codeGen(node->right, fp);

    fprintf(fp, "ADD R%d, R%d\n", l, r);
    freeReg();

    return l;
}

int generateCode(struct tnode *node){
    FILE *fp = fopen("./output.xsm", "w");     // output xsm file
    if(!fp){
        printf("Couldn't create output file\n");
        exit(1);
    }

    generateHeader(fp);
    int r = codeGen(node, fp);
    codeGenWrite(fp, r);
    codeGenExit(fp);
    fclose(fp);
    return 0;
}