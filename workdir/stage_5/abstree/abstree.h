#ifndef ABSTREE_HEADER_FILE
#define ABSTREE_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    TYPE_NONE,
    TYPE_ID,
    TYPE_INT,
    TYPE_CHAR,
    TYPE_BOOL,
    TYPE_STR,
    TYPE_INT_PTR,
    TYPE_STR_PTR
} VarType;

#endif