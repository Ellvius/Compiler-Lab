#include "symboltable.h"

Gsymbol* GLookup(char * name){
    Gsymbol *temp = Ghead;

    while(temp != NULL && (strcmp(temp->name, name) != 0)){
        temp = temp->next;
    }

    return temp;
}

void GInstall(char *name, int type, int size){
    Gsymbol *temp = GLookup(name);
    
    if(temp != NULL){
        fprintf(stdout, "Variable re-initialized \"%s\"\n", name);
        exit(1);
    }

    temp = (Gsymbol*)malloc(sizeof(Gsymbol));
    temp->name = (char*)malloc(strlen(name)*sizeof(char));
    strcpy(temp->name, name);
    temp->type = type;
    temp->size = size;
    temp->next = NULL;

    if(Ghead != NULL){
        Gtail->next = temp;
        Gtail = temp;
    }
    else {
        Ghead = temp;
        Gtail = temp;
    }
}


char* tokenToString(int type){
    switch(type){
        case TYPE_NONE: return "NONE";
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
        fprintf(stdout, "%s----%s----%d\n", temp->name, tokenToString(temp->type), temp->size);
        temp = temp->next;
    }
}