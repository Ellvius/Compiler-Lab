#ifndef LABEL_HEADER_FILE
#define LABEL_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lnode {
    char* label;
    int address;
    struct lnode* next;
} lnode;

lnode* createLabel(char* label, int addr);

int getLabelAddr(char* label);

#endif