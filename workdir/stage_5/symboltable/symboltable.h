#ifndef SYMBOLTABLE_HEADER_FILE
#define SYMBOLTABLE_HEADER_FILE
#include <string.h>
#include <stdlib.h>
#include "../abstree/abstree.h"

#define START_ADDR 4096


typedef struct FieldList {
    char* name;
    int fieldIndex;
    struct TypeTable *type;
    struct FieldList *next;
} FieldList;

extern FieldList *Fhead, *Ftail;
FieldList *FLookup(char* name, struct FieldList *list);
void FInstall(char* name, struct TypeTable *type);


typedef struct TypeTable {
    char* name;
    int size;
    struct FieldList *fields;       // pointer to the head of the fieldList
    struct TypeTable *next;
} TypeTable;

extern TypeTable *Thead, *Ttail;
TypeTable *TLookup(char* name);
void TInstall(char* name, int size,struct FieldList* fields);\
void printTypeTable(void);


typedef struct Paramstruct {
    char *name;                 // name of the parameter
    TypeTable *type;                   // type of the parameter
    struct Paramstruct *next;   // points to the next parameter to the function
} Paramstruct;

extern Paramstruct *Phead, *Ptail;
Paramstruct *PLookup(char* name);           // Lookup for function identifier
void PInstall(char *name, TypeTable* type);        // Creates a param node
void freeParamList(void);                   // Free the ParamList for a new set of Params


typedef struct Gsymbol{ 
    char *name;             // name of the variable or function   
    TypeTable* type;               // type of the variable:(Integer / String)   
    int size;               // size of an array   
    int rowsize;            // size of row in case of array
    int colsize;            // size of col in case of 2d array
    int binding;            // static binding of global variables   
    int flabel;             // a label for identifying the starting address of a function's code   
    struct Paramstruct *paramlist;      // pointer to the head of the formal parameter list    
    struct Gsymbol *next;               // points to the next Global Symbol Table entry 
} Gsymbol;

extern Gsymbol *Ghead, *Gtail;
Gsymbol* GLookup(char * name);      // Lookup for global identifier
void GInstall(char *name, TypeTable* type, int size, int r, int c, Paramstruct *paramlist);   // Creates a symbol table entry.
void printGST(void);                // Prints the Global symbol table entries


typedef struct Lsymbol{
    char *name;             // name of the variable
    TypeTable* type;               // type of the variable:(Integer / String)
    int binding;            // local binding of the variable
    struct Lsymbol *next;   // points to the next Local Symbol Table entry
} Lsymbol;

extern Lsymbol *Lhead, *Ltail;
Lsymbol* LLookup(char *name);           // Lookup for local identifier              
void* LInstall(char *name, TypeTable* type);   // Creates entry in Local symbol table
void FreeLST(void);                 // Free local symbol table for subsequent function declarations
void printLST(char *name);          // Prints the Local symbol table entries

extern int nextFreeAddr;            // Next free binding address for Global variables
extern int functionLabelNum;        // Next function Label number 
extern int relFreeAddr;             // Relative address for Local variable

void PInstallLST(char *fname);      // Store function params in LST
int validateParams(char* fname, Paramstruct *head);


#endif