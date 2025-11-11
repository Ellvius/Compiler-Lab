#include "symboltable.h"

Gsymbol *Ghead = NULL, *Gtail = NULL;
Lsymbol *Lhead = NULL, *Ltail = NULL;
Paramstruct *Phead = NULL, *Ptail = NULL;
FieldList *Fhead = NULL, *Ftail = NULL;
TypeTable *Thead = NULL, *Ttail = NULL;
Classtable *Chead = NULL, *Ctail = NULL;
int nextFreeAddr = START_ADDR;
int functionLabelNum = 0;
int relFreeAddr = 1;
int fieldIndex = 0;


//-----------------------------PARAMETER TABLE------------------------------------

Paramstruct *PLookup(char* name){
    Paramstruct *temp = Phead;

    while(temp != NULL && (strcmp(temp->name, name) != 0)){
        temp = temp->next;
    }
    return temp;
}   

void PInstall(char *name, TypeTable* type){
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



//--------------------------CLASS TABLE------------------------------------------

Classtable* CLookup(char *name){
    Classtable *temp = Chead;

    while(temp != NULL && strcmp(temp->name, name) != 0){
        temp = temp->next;
    }

    return temp;
}

FieldList* ClassFlookup(Classtable* ctype,char* name){
    FieldList *temp = ctype->methods;

    while(temp != NULL && strcmp(temp->name, name) != 0){
        temp = temp->next;
    }
    return temp;
}

MethodList* ClassMlookup(Classtable* ctype,char* name){
    MethodList *temp = ctype->methods;

    while(temp != NULL && strcmp(temp->name, name) != 0){
        temp = temp->next;
    }
    return temp;
}

Classtable* CInstall(char *name,char *parentname){
    if(CLookup(name);){
        fprintf(stderr, "Class redeclared: %s\n", name);
        exit(1);
    }

    if(TLookup(name)){
        fprintf(stderr, "User defined type already exists: %s\n", name);
        exit(1);
    }

    Classtable *classnode = (Classtable *)malloc(sizeof(Classtable));
    classnode->name = name;
    classnode->fields = NULL;
    classnode->methods = NULL;
    classnode->parent =  CLookup(parentname);
    classnode->classindex = -1;
    classnode->fieldcount = 0;
    classnode->methodcount = 0;
    classnode->next = NULL;

    if(Chead == NULL){
        Chead = classnode;
        Ctail = classnode;
    }
    else {
        Ctail->next = classnode;
        Ctail = classnode;
    }
    return classnode;
}

void ClassFinstall(Classtable *cptr, char *typename, char *name){
    if(ClassFlookup(cptr, name)){
        fprintf(stderr, "Member field already declared: %s\n", name);
        exit(1);
    }

    if(cptr->fieldcount == 8){
        fprintf(stderr, "Maximum of 8 members are allowed in a class: %s\n", cptr->name);
        exit(1);
    }

    FieldList *fieldnode = (FieldList *)malloc(sizeof(FieldList));
    fieldnode->name = name;
    fieldnode->fieldIndex = fieldIndex++;
    fieldnode->type = TLookup(typename);
    fieldnode->ctype = CLookup(typename);
    fieldnode->next = NULL;

    if(cptr->fields == NULL){
        cptr->fields = fieldnode;
        cptr->fieldcount++;
    }
    else {
        FieldList *temp = cptr->fields;

        while(temp->next){
            temp = temp->next;
        }
        temp->next = fieldnode;
        cptr->fieldcount++;
    }
}

void ClassMinstall(Classtable *cptr, char *name, TypeTable *type, Paramstruct *Paramlist){
    if(ClassMlookup(cptr, name)){
        fprintf(stderr, "Method already declared in class: %s %s\n", cptr->name, name);
        exit(1);
    }

    if(cptr->methodcount == 8){
        fprintf(stderr, "Maximum of 8 methods are allowed in a class: %s\n", cptr->name);
        exit(1);
    }

    MethodList *methodnode = (MethodList *)malloc(sizeof(MethodList));
    methodnode->name = name;
    methodnode->type = type;
    methodnode->paramlist = Paramlist;
    methodnode->position = cptr->methodcount;
    methodnode->flabel = functionLabelNum++;
    methodnode->next = NULL;

    if(cptr->methods == NULL){
        cptr->methods = methodnode;
        cptr->methodcount++;
    }
    else {
        MethodList *temp = cptr->methods;

        while(temp->next){
            temp = temp->next;
        }
        temp->next = methodnode;
        cptr->methodcount++;
    }
}

void printClassTable(void){
    Classtable *node = Chead;
    
    while(node != NULL){
        fprintf(stdout, "CLASS TABLE: %s\n", node->name);
        fprintf(stdout, "%-15s %-7s %-7s %-7s\n","parent", "index", "fcount", "mcount");
        fprintf(stdout, "%-15s %-7d %-7d %-7d\n",node->parent ? node->parent : "null", node->classindex, node->fieldcount, node->membercount);
        fprintf(stdout, "\n");

        fprintf(stdout, "\tMEMBERS:\n");
        fprintf(stdout, "%-15s %-7s %-7s\n","name", "index", "type");
        FieldList *ftemp = node->fields;
        while(ftemp){
            fprintf(stdout, "%-15s %-7d %-7s\n",ftemp->name, ftemp->fieldIndex, ftemp->type ? ftemp->type->name : ftemp->ctype->name);
            ftemp = ftemp->next;
        }
        
        fprintf(stdout, "\tMETHODS:\n");
        fprintf(stdout, "%-15s %-7s %-7s %-7s\n","name", "type", "position", "flabel");
        MethodList *mtemp = node->methods;
        while(mtemp){
            fprintf(stdout, "%-15s %-7s %-7d %-7d\n",mtemp->name, mtemp->type->name, mtemp->position, mtemp->flabel);
            mtemp = mtemp->next;
        }

        node = node->next;
    }

    fprintf(stdout,"\n");

}



//--------------------------GLOBAL SYMBOL TABLE-----------------------------------

Gsymbol* GLookup(char * name){
    Gsymbol *temp = Ghead;

    while(temp != NULL && (strcmp(temp->name, name) != 0)){
        temp = temp->next;
    }

    return temp;
}

void GInstall(char *name, TypeTable* type, int size, int r, int c, Paramstruct *paramlist){
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
        fprintf(stdout, "%-15s %-10s %-7d %-7d %-7d %-7d\n", temp->name, temp->type->name, temp->size, temp->binding, temp->rowsize, temp->colsize);
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

void* LInstall(char *name, TypeTable* type){
    Lsymbol *temp = LLookup(name);
    if(temp != NULL){
        fprintf(stdout, "Local variable redeclared: %s\n", name);
        exit(1);
    }

    temp = (Lsymbol*)malloc(sizeof(Lsymbol));
    temp->name = strdup(name);
    temp->type = type;
    temp->next = NULL;
    temp->binding = -1;

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
        fprintf(stdout, "%-15s %-10s %-7d\n", temp->name, temp->type->name, temp->binding);
        temp = temp->next;
    }
    fprintf(stdout, "\n");
}



//-----------------------------------FIELD LIST-------------------------------------------------

FieldList *FLookup(char* name, FieldList *list){
    FieldList* temp = list;

    while(temp != NULL && strcmp(temp->name, name) != 0)
        temp = temp->next;

    return temp;
}

void FInstall(char* name, TypeTable *type){
    if(FLookup(name, Fhead) != NULL){
        fprintf(stderr, "Field element re declared\n");
        exit(1);
    }
    FieldList *temp = (FieldList*)malloc(sizeof(FieldList));

    temp->name = strdup(name);
    temp->type = type;
    temp->ctype = NULL;
    temp->fieldIndex = -1;
    temp->next = NULL;

    if(Fhead == NULL){
        Fhead = temp;
        Ftail = temp;
    }
    else {
        Ftail->next = temp;
        Ftail = temp;
    }
}



//-----------------------------------TYPE TABLE-------------------------------------------------

TypeTable *TLookup(char* name){
    TypeTable *temp = Thead;

    while(temp != NULL && strcmp(temp->name, name) != 0)
        temp = temp->next;

    return temp;
}

void TInstall(char* name, int size, FieldList* fields){
    TypeTable *temp = (TypeTable*)malloc(sizeof(TypeTable));

    temp->name = strdup(name);
    temp->size = size;
    temp->fields = fields;
    temp->next = NULL;

    if(Thead == NULL){
        Thead = temp;
        Ttail = temp;
    }
    else {
        Ttail->next = temp;
        Ttail = temp;
    }

    FieldList* ftemp = fields;
    int fieldIndex = 0;

    while(ftemp != NULL){
        if(ftemp->type == TLookup("dummy")){
            ftemp->type = TLookup(name);
        }
        ftemp->fieldIndex = fieldIndex++;
        ftemp = ftemp->next;
    }

    if(fieldIndex > 8){
        fprintf(stderr, "Maximum 8 members are allowed for a user defined type\n");
        exit(1);
    }

    Fhead = NULL;
    Ftail = NULL;
}

void printTypeTable(void){
    TypeTable *temp = Thead;

    fprintf(stdout, "TYPE TABLE :\n");
    fprintf(stdout, "%-15s %-10s\n","name", "size");

    while(temp != NULL){
        fprintf(stdout, "%-15s %-10d\n", temp->name, temp->size);

        if(temp->fields != NULL){
            FieldList *ftemp = temp->fields;
            fprintf(stdout, "\tFIELD TABLE : %s\n", temp->name);
            fprintf(stdout, "\t%-15s %-15s %-10s\n","name", "type", "index");

            while(ftemp){
                fprintf(stdout, "\t%-15s %-15s %-10d\n", ftemp->name, ftemp->type->name, ftemp->fieldIndex);
                ftemp = ftemp->next;
            }
            
            fprintf(stdout, "\n");
        }

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

int validateParams(char *fname, Paramstruct *head) {
    Gsymbol *stentry = GLookup(fname);
    int total_params = 0;

    if (stentry == NULL) {
        fprintf(stderr, "Function not declared: %s\n", fname);
        exit(1);
    }

    Paramstruct *decl = stentry->paramlist;
    Paramstruct *def = head;

    if (decl == NULL && def == NULL)
        return 0;

    if ((decl == NULL && def != NULL) || (decl != NULL && def == NULL)) {
        fprintf(stderr, "param count mismatch in function: %s.\n", fname);
        exit(1);
    }

    while (decl != NULL && def != NULL) {
        if (decl->type != def->type) {
            fprintf(stderr, "param type mismatch in function: %s\n", fname);
            exit(1);
        }

        if (strcmp(decl->name, def->name) != 0) {
            fprintf(stderr, "param name mismatch in function: %s \n", fname);
            exit(1);
        }

        decl = decl->next;
        def = def->next;
        total_params++;
    }

    if (decl != NULL || def != NULL) {
        fprintf(stderr, "param count mismatch in function: %s\n", fname);
        exit(1);
    }
    return total_params;
}
