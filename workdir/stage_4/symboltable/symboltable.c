#include "symboltable.h"

Gsymbol *Ghead = NULL, *Gtail = NULL;
int freeAddrPtr = START_ADDR;

Gsymbol* GLookup(char * name){
    Gsymbol *temp = Ghead;

    while(temp != NULL && (strcmp(temp->name, name) != 0)){
        temp = temp->next;
    }

    return temp;
}

void GInstall(char *name, int type, int size, int r, int c){
    Gsymbol *newEntry = GLookup(name);
    
    if(newEntry != NULL){
        fprintf(stdout, "Variable re-initialized \"%s\"\n", name);
        exit(1);
    }

    newEntry = (Gsymbol*)malloc(sizeof(Gsymbol));
    newEntry->name = strdup(name);
    newEntry->type = type;
    newEntry->size = size;
    newEntry->addr = freeAddrPtr;
    freeAddrPtr += size;    // advance addr pointer
    newEntry->rowsize = r;
    newEntry->colsize = c;
    newEntry->next = NULL;

    if(Ghead != NULL){
        Gtail->next = newEntry;
        Gtail = newEntry;
    }
    else {
        Ghead = newEntry;
        Gtail = newEntry;
    }
}


char* tokenToString(int type){
    switch(type){
        case TYPE_NONE: return "NONE";
        case TYPE_ID: return "ID";
        case TYPE_INT:  return "INT";
        case TYPE_CHAR: return "CHAR";
        case TYPE_BOOL: return "BOOL";
        case TYPE_STR: return "STR";
        case TYPE_INT_PTR: return "INT_PTR";
        case TYPE_STR_PTR: return "STR_PTR";
        default: return "UNDEFINED";
    }
}

void printSymbolTable(void){
    Gsymbol* temp = Ghead;

    while(temp != NULL){
        fprintf(stdout, "%s----%s----%d----%d----%d----%d\n", temp->name, tokenToString(temp->type), temp->size, temp->addr, temp->rowsize, temp->colsize);
        temp = temp->next;
    }
}