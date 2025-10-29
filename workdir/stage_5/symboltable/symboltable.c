#include "symboltable.h"

Gsymbol *Ghead = NULL, *Gtail = NULL;
Lsymbol *Lhead = NULL, *Ltail = NULL;
Paramstruct *Phead = NULL, *Ptail = NULL;
int nextFreeAddr = START_ADDR;
int functionLabelNum = 0;
int relFreeAddr = 1;


//-----------------------------PARAMETER TABLE------------------------------------

Paramstruct *PLookup(char* name){
    Paramstruct *temp = Phead;

    while(temp != NULL && (strcmp(temp->name, name) != 0)){
        temp = temp->next;
    }
    return temp;
}   

void PInstall(char *name, int type){
    Paramstruct *temp = PLookup(name);

    if(temp != NULL){
        fprintf(stdout, "Parameter redeclared: %s\n", name);
        exit(1);
    }

    temp = (Paramstruct*)malloc(sizeof(Paramstruct));
    temp->name = name;
    temp->type = type;
    temp->next = NULL;

    if(Phead != NULL){
        Ptail->next = temp;
        Ptail = temp;
    }
    else {
        Phead = temp;
        Ptail = temp;
    }
}

void freeParamList(void){
    Paramstruct *temp = Phead;
    Paramstruct *next;

    while(temp != NULL){
        next = temp->next;
        free(temp->name);
        free(temp);
        temp = next;
    }

    Phead = NULL;
    Ptail = NULL;
}

//--------------------------GLOBAL SYMBOL TABLE-----------------------------------

Gsymbol* GLookup(char * name){
    Gsymbol *temp = Ghead;

    while(temp != NULL && (strcmp(temp->name, name) != 0)){
        temp = temp->next;
    }

    return temp;
}

void GInstall(char *name, int type, int size, int r, int c, Paramstruct *paramlist){
    Gsymbol *temp = GLookup(name);
    
    if(temp != NULL){
        fprintf(stdout, "Global variable redeclared: %s\n", name);
        exit(1);
    }

    temp = (Gsymbol*)malloc(sizeof(Gsymbol));
    temp->name = strdup(name);
    temp->type = type;
    temp->size = size;
    temp->rowsize = r;
    temp->colsize = c;
    temp->paramlist = paramlist;
    temp->next = NULL;
    
    if(temp->size == -1){   // function
        temp->binding = -1;
        temp->flabel = functionLabelNum;
        functionLabelNum++;

        Phead = NULL;   // free the param pointers for the next declarations
        Ptail = NULL;
    } 
    else {
        temp->binding = nextFreeAddr;
        temp->flabel = -1;
        nextFreeAddr += size;    // advance free address
    }

    if(Ghead != NULL){
        Gtail->next = temp;
        Gtail = temp;
    }
    else {
        Ghead = temp;
        Gtail = temp;
    }
}

void printGST(void){
    Gsymbol* temp = Ghead;
    
    fprintf(stdout, "GLOBAL DECLARATIONS:\n");
    fprintf(stdout, "%-15s %-10s %-7s %-7s %-7s %-7s\n","name", "type", "size", "addr", "row", "col");

    while(temp != NULL){
        fprintf(stdout, "%-15s %-10s %-7d %-7d %-7d %-7d\n", temp->name, tokenToString(temp->type), temp->size, temp->binding, temp->rowsize, temp->colsize);
        temp = temp->next;
    }

    fprintf(stdout,"\n");
}


//------------------------------LOCAL SYMBOL TABLE---------------------------------------

Lsymbol* LLookup(char *name){
    Lsymbol *temp = Lhead;

    while(temp != NULL && (strcmp(temp->name, name) != 0)){
        temp = temp->next;
    }

    return temp;
}

void* LInstall(char *name, int type){
    Lsymbol *temp = LLookup(name);
    if(temp != NULL){
        fprintf(stdout, "Local variable redeclared: %s\n", name);
        exit(1);
    }

    temp = (Lsymbol*)malloc(sizeof(Lsymbol));
    temp->name = strdup(name);
    temp->type = type;
    temp->next = NULL;
    temp->binding = relFreeAddr;
    relFreeAddr++;

    if(Lhead != NULL){
        Ltail->next = temp;
        Ltail = temp;
    }
    else {
        Lhead = temp;
        Ltail = temp;
    }
}

void FreeLST(void){
    Lsymbol *temp = Lhead;
    Lsymbol *next;

    while (temp != NULL) {
        next = temp->next;   
        free(temp->name);    
        free(temp);         
        temp = next;
    }

    Lhead = NULL;
    Ltail = NULL;
    relFreeAddr = 1;
}

void printLST(char *name){
    Lsymbol* temp = Lhead;

    fprintf(stdout, "LOCAL DECLARATIONS: %s\n", name);
    fprintf(stdout, "%-15s %-10s %-7s\n","name", "type", "addr");

    while(temp != NULL){
        fprintf(stdout, "%-15s %-10s %-7d\n", temp->name, tokenToString(temp->type), temp->binding);
        temp = temp->next;
    }
    fprintf(stdout, "\n");
}

//---------------------------------HELPER FUNCTIONS---------------------------------------------

void PInstallLST(char *fname){
    Gsymbol *fn = GLookup(fname);
    Paramstruct *temp = fn->paramlist;
    
    while(temp != NULL){
        LInstall(temp->name, temp->type);
        temp = temp->next;
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