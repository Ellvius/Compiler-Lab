#include "abstree.h"

ASTNode* TreeCreate(union Constant* val, VarType vtype, char* vname, NodeType ntype, ASTNode *l, ASTNode* m, ASTNode *r, ASTNode* arglist){
    ASTNode* temp = (ASTNode*)malloc(sizeof(ASTNode));
    Gsymbol* gdecl = NULL;
    Lsymbol* ldecl = NULL;

    temp->value = val;
    temp->type = vtype;
    temp->name = vname;
    temp->nodetype = ntype;
    temp->ptr1 = l;
    temp->ptr2 = m;
    temp->ptr3 = r;
    temp->arglist = arglist;
    temp->Gentry = NULL;
    temp->Lentry = NULL;

    if(temp->type == TYPE_ID){
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

ASTNode* makeLeafNode(int n, char* s, VarType vtype, char* vname){
    union Constant *value = malloc(sizeof(union Constant));

    switch(vtype){
        case TYPE_INT:
            value->intVal = n;
            break;
        case TYPE_STR:
            value->strVal = strdup(s);
            break;
        default:
            break;
    }
    ASTNode* temp = TreeCreate(value, vtype, vname, NODE_LEAF, NULL, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeArithOPNode(NodeType ntype, ASTNode* l, ASTNode* r){
    if(l->type != TYPE_INT || r->type != TYPE_INT){
        fprintf(stderr, "type mismatch: arith\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TYPE_INT, NULL, ntype, l, NULL, r, NULL);    
    return temp;
}

ASTNode* makeRelOPNode(NodeType ntype, ASTNode* l, ASTNode* r){
    if(l->type != r->type){
        fprintf(stderr, "type mismatch: relop\n");
        exit(1);
    }
    if(l->type != TYPE_INT && l->type != TYPE_STR){
        fprintf(stderr, "type mismatch: relop (not int/str)\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TYPE_BOOL, NULL, ntype, l, NULL, r, NULL);    
    return temp;
}

ASTNode* makeAssgnNode(ASTNode* l, ASTNode* r){
    if((l->nodetype != NODE_LEAF && l->nodetype != NODE_ARRAY && l->nodetype != NODE_PTR) || (l->nodetype != NODE_PTR && l->name == NULL)){
        fprintf(stderr, "type mismatch: assign (ID)\n");
        exit(1);
    }

    if(l->type != r->type){
        fprintf(stderr, "type mismatch: assign %d %d\n", l->type, r->type);
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, NODE_ASSGN, l, NULL, r, NULL);    
    return temp;
}

ASTNode* makeReadNode(ASTNode* l){
    if(l->type != TYPE_INT && l->type != TYPE_STR){
        fprintf(stderr, "type mismatch: read %d\n", l->type);
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, NODE_READ, l, NULL, NULL, NULL);
    return temp;
}

ASTNode* makeWriteNode(ASTNode* l){
    if(l->type != TYPE_INT && l->type != TYPE_BOOL && l->type != TYPE_STR && l->type != TYPE_INT_PTR && l->type != TYPE_STR_PTR){
        fprintf(stderr, "type mismatch: write %d\n", l->type);
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, NODE_WRITE, l, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeConnNode(ASTNode* l, ASTNode* r){
    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, NODE_CONN, l, NULL, r, NULL);    
    return temp;
}

ASTNode* makeIterationNode(NodeType ntype, ASTNode *l, ASTNode* r){
    if(l->type != TYPE_BOOL){
        fprintf(stderr, "type mismatch: while\n");
        exit(1);
    }
    
    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, ntype, l, NULL, r, NULL);
    return temp;
}

ASTNode* makeIfElseNode(ASTNode* l, ASTNode* m, ASTNode* r){
    if(l->type != TYPE_BOOL){
        fprintf(stderr, "type mismatch: ifelse\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, NODE_IFELSE, l, m, r, NULL);
    return temp;
}

ASTNode* makeBreakNode(void){
    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, NODE_BREAK, NULL, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeContinueNode(void){
    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, NODE_CONTINUE, NULL, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeArrayNode(char* arrName, VarType type, ASTNode* l, ASTNode* r){
    Gsymbol* var = GLookup(arrName);

    if(var->rowsize == 0){
        fprintf(stderr, "Not an array: %s\n", arrName);
        exit(1);
    }
    ASTNode* temp = TreeCreate(NULL, TYPE_ID, arrName, NODE_ARRAY, l, NULL, r, NULL);
    return temp;
}

ASTNode* makeAddrNode(ASTNode* var){
    VarType vtype = TYPE_NONE;

    switch(var->type){
        case TYPE_INT: vtype = TYPE_INT_PTR; break;
        case TYPE_STR: vtype = TYPE_STR_PTR; break;
        default: fprintf(stderr, "Address-of not supported for this type\n");
                exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, vtype, NULL, NODE_ADDR, var, NULL, NULL, NULL);
    return temp;
}


ASTNode* makePtrNode(ASTNode* ptrVar){
    VarType vtype = TYPE_NONE;

    switch(ptrVar->type){
        case TYPE_INT_PTR: vtype = TYPE_INT; break;
        case TYPE_STR_PTR: vtype = TYPE_STR; break;
        default: fprintf(stderr, "Dereference not supported for this type\n");
                exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, vtype, NULL, NODE_PTR, ptrVar, NULL, NULL, NULL);
    return temp;
}


ASTNode* makeFuncNode(char* fname, VarType vtype, ASTNode* arglist){
    ASTNode* funcNode = TreeCreate(NULL, vtype, fname, NODE_FUNC, NULL, NULL, NULL, arglist);
    Gsymbol *func = GLookup(fname);

    if(!func){
        fprintf(stderr, "undeclared function: %s\n", fname);
        exit(1);
    }

    Paramstruct* param = func->paramlist;
    ASTNode* arg = funcNode->arglist;

    while(param != NULL && arg != NULL){
        if(param->type != arg->type){
            fprintf(stderr, "type mismatch: function args: %s - types %s , %s\n", fname, tokenToString(param->type), tokenToString(arg->type));
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
    if(l->type != TYPE_BOOL || r->type != TYPE_BOOL){
        fprintf(stderr, "type mismatch: boolean operation\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TYPE_BOOL, NULL, ntype, l, NULL, r, NULL);    
    return temp;
}