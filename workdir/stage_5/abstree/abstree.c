#include "abstree.h"

ASTNode* TreeCreate(union Constant* val,struct TypeTable* vtype, char* vname, NodeType ntype, ASTNode *l, ASTNode* m, ASTNode *r, ASTNode* arglist){
    ASTNode* temp = (ASTNode*)malloc(sizeof(ASTNode));
    Gsymbol* gdecl = NULL;
    Lsymbol* ldecl = NULL;

    temp->value = val;
    temp->type = vtype;
    temp->name = vname;
    temp->nodetype = ntype;
    temp->left = l;
    temp->middle = m;
    temp->right = r;
    temp->arglist = arglist;
    temp->Gentry = NULL;
    temp->Lentry = NULL;

    if(temp->type == TLookup("dummy")){
        ldecl = LLookup(vname);
        temp->Lentry = ldecl;
        if(!ldecl){
            gdecl = GLookup(vname);
            temp->Gentry = gdecl;
            if(!gdecl){
                fprintf(stderr, "Undeclared variable: %s\n", vname);
                exit(1);
            }
            temp->type = gdecl->type;
        }
        else{
            temp->type = ldecl->type;
        }
    }

    return temp;
}

ASTNode* makeLeafNode(int n, char* s, struct TypeTable* vtype, char* vname){
    union Constant *value = malloc(sizeof(union Constant));

    if(vtype == TLookup("integer")){
        value->intVal = n;
    }
    else if(vtype == TLookup("string")){
        value->strVal = strdup(s);
    }

    ASTNode* temp = TreeCreate(value, vtype, vname, NODE_LEAF, NULL, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeArithOPNode(NodeType ntype, ASTNode* l, ASTNode* r){
    if(l->type != TLookup("integer") || r->type != TLookup("integer")){
        fprintf(stderr, "type mismatch: arith\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TLookup("integer"), NULL, ntype, l, NULL, r, NULL);    
    return temp;
}

ASTNode* makeRelOPNode(NodeType ntype, ASTNode* l, ASTNode* r){
    if(l->type != r->type){
        fprintf(stderr, "type mismatch: relop\n");
        exit(1);
    }
    if(l->type != TLookup("integer") && l->type != TLookup("string")){
        fprintf(stderr, "type mismatch: relop (not int/str)\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TLookup("bool"), NULL, ntype, l, NULL, r, NULL);    
    return temp;
}

ASTNode* makeAssgnNode(ASTNode* l, ASTNode* r){
    if((l->nodetype != NODE_LEAF && l->nodetype != NODE_ARRAY && l->nodetype != NODE_PTR) || (l->nodetype != NODE_PTR && l->name == NULL)){
        fprintf(stderr, "type mismatch: assign (ID)\n");
        exit(1);
    }

    if(l->type != r->type){
        fprintf(stderr, "type mismatch: assign %s %s\n", l->type->name, r->type->name);
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TLookup("void"), NULL, NODE_ASSGN, l, NULL, r, NULL);    
    return temp;
}

ASTNode* makeReadNode(ASTNode* l){
    if(l->type != TLookup("integer") && l->type != TLookup("string")){
        fprintf(stderr, "type mismatch: read %s\n", l->type->name);
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TLookup("void"), NULL, NODE_READ, l, NULL, NULL, NULL);
    return temp;
}

ASTNode* makeWriteNode(ASTNode* l){
    if(l->type != TLookup("integer") && l->type != TLookup("bool") && l->type != TLookup("string") && l->type != TLookup("integer_ptr") && l->type != TLookup("string_ptr")){
        fprintf(stderr, "type mismatch: write %s\n", l->type->name);
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TLookup("void"), NULL, NODE_WRITE, l, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeConnNode(ASTNode* l, ASTNode* r){
    ASTNode* temp = TreeCreate(NULL, TLookup("void"), NULL, NODE_CONN, l, NULL, r, NULL);    
    return temp;
}

ASTNode* makeIterationNode(NodeType ntype, ASTNode *l, ASTNode* r){
    if(l->type != TLookup("bool")){
        fprintf(stderr, "type mismatch: while\n");
        exit(1);
    }
    
    ASTNode* temp = TreeCreate(NULL, TLookup("void"), NULL, ntype, l, NULL, r, NULL);
    return temp;
}

ASTNode* makeIfElseNode(ASTNode* l, ASTNode* m, ASTNode* r){
    if(l->type != TLookup("bool")){
        fprintf(stderr, "type mismatch: ifelse\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TLookup("void"), NULL, NODE_IFELSE, l, m, r, NULL);
    return temp;
}

ASTNode* makeBreakNode(void){
    ASTNode* temp = TreeCreate(NULL, TLookup("void"), NULL, NODE_BREAK, NULL, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeContinueNode(void){
    ASTNode* temp = TreeCreate(NULL, TLookup("void"), NULL, NODE_CONTINUE, NULL, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeArrayNode(char* arrName, TypeTable* type, ASTNode* l, ASTNode* r){
    Gsymbol* var = GLookup(arrName);

    if(var->rowsize == 0){
        fprintf(stderr, "Not an array: %s\n", arrName);
        exit(1);
    }
    ASTNode* temp = TreeCreate(NULL, TLookup("dummy"), arrName, NODE_ARRAY, l, NULL, r, NULL);
    return temp;
}

ASTNode* makeAddrNode(ASTNode* var){
    TypeTable* vtype = NULL;

    if(var->type == TLookup("integer")){
        vtype = TLookup("integer_ptr");
    }
    else if(var->type == TLookup("string")){
        vtype = TLookup("string_ptr");
    }

    ASTNode* temp = TreeCreate(NULL, vtype, NULL, NODE_ADDR, var, NULL, NULL, NULL);
    return temp;
}


ASTNode* makePtrNode(ASTNode* ptrVar){
    TypeTable* vtype = NULL;

    if(ptrVar->type == TLookup("integer_ptr")){
        vtype = TLookup("integer");
    }
    else if(ptrVar->type == TLookup("string_ptr")){
        vtype = TLookup("string");
    }

    ASTNode* temp = TreeCreate(NULL, vtype, NULL, NODE_PTR, ptrVar, NULL, NULL, NULL);
    return temp;
}


ASTNode* makeFuncNode(char* fname, TypeTable* vtype, ASTNode* arglist){
    ASTNode* id = TreeCreate(NULL, vtype, fname, NODE_FUNC, NULL, NULL, NULL, arglist);
    ASTNode* funcNode = TreeCreate(NULL, vtype, fname, NODE_FUNC, id, NULL, NULL, NULL);
    Gsymbol *func = GLookup(fname);

    if(!func){
        fprintf(stderr, "undeclared function: %s\n", fname);
        exit(1);
    }

    Paramstruct* param = func->paramlist;
    ASTNode* arg = id->arglist;

    while(param != NULL && arg != NULL){
        if(param->type != arg->type){
            fprintf(stderr, "type mismatch: function args: %s - types %s , %s\n", fname, param->type->name, arg->type->name);
            exit(1);
        }
        param = param->next;
        arg = arg->arglist;
    }

    if(param != NULL || arg != NULL){
        fprintf(stderr, "params count mismatch: %s\n", fname);
    }
    return funcNode;
}


ASTNode* makeArgNode(ASTNode* argHead, ASTNode* arg){
    ASTNode *temp = argHead;

    while(temp->arglist != NULL){
        temp = temp->arglist;
    }
    temp->arglist = arg;
    return argHead;
}


ASTNode* makeRetNode(ASTNode* retnode){
    ASTNode *temp = TreeCreate(NULL, retnode->type, NULL, NODE_RET, retnode, NULL, NULL, NULL);
    return temp;
}


ASTNode* makeLogicOPNode(NodeType ntype, ASTNode* l, ASTNode* r){
    if(l->type != TLookup("bool") || r->type != TLookup("bool")){
        fprintf(stderr, "type mismatch: boolean operation\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TLookup("bool"), NULL, ntype, l, NULL, r, NULL);    
    return temp;
}


ASTNode* makeTupleNode(char *tupleName, char* fieldName){
    TypeTable *type = TLookup(tupleName);

    if(type == NULL){
        fprintf(stderr, "tuple type not declared: %s\n", tupleName);
        exit(1);
    }

    FieldList *field = type->fields;

    while(field != NULL && strcmp(field->name, fieldName) != 0){
        field = field->next;
    }

    if(field == NULL){
        fprintf(stderr, "field %s does not exists for tuple %s\n", fieldName, tupleName);
        exit(1);
    }

    ASTNode* tupleField = makeLeafNode(0, NULL, field->type, fieldName);

    ASTNode* temp = TreeCreate(NULL, type, tupleName, NODE_TUP, tupleField, NULL, NULL, NULL);

}