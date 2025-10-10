#ifndef SYMBOLTABLE_HEADER_FILE
#define SYMBOLTABLE_HEADER_FILE
#include <string.h>
#include <stdlib.h>
#include "../abstree/abstree.h"

#define START_ADDR 4096

typedef struct Gsymbol {
    char* name;             // name of the variable
    int type;               // type of the variable
    int size;               // size of the type of the variable
    int rowsize;
    int colsize;
    int addr;            // stores the static memory address allocated to the variable
    struct Gsymbol *next;
} Gsymbol;

Gsymbol* GLookup(char * name);            // Lookup for global identifier
void GInstall(char *name, int type, int size, int r, int c);   // Creates a symbol table entry.

extern Gsymbol *Ghead, *Gtail;
extern int freeAddrPtr;

void printSymbolTable(void);            // Prints the Sybbol Table Entries
char* tokenToString(int);     // Prints the Var type instead of numerical value


#endif