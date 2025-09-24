#include <stdio.h>
#include <stdlib.h>
#include "expr.h"

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
