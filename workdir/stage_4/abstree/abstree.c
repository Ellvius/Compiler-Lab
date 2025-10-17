#include "abstree.h"

ASTNode* TreeCreate(union Constant* val, VarType vtype, char* vname, NodeType ntype, ASTNode *l, ASTNode* m, ASTNode *r){
    ASTNode* temp = (ASTNode*)malloc(sizeof(ASTNode));
    Gsymbol* var = NULL;

    temp->value = val;
    temp->type = vtype;
    temp->varName = vname;
    temp->nodetype = ntype;
    temp->left = l;
    temp->middle = m;
    temp->right = r;

    if(temp->type == TYPE_ID){
        var = GLookup(vname);
        if(!var){
            fprintf(stderr, "Undefined variables: %s\n", vname);
            exit(1);
        }
        temp->type = var->type;
    }
    temp->GEntry = var;

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
    ASTNode* temp = TreeCreate(value, vtype, vname, NODE_LEAF, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeArithOPNode(NodeType ntype, ASTNode* l, ASTNode* r){
    if(l->type != TYPE_INT || r->type != TYPE_INT){
        fprintf(stderr, "type mismatch: arith\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TYPE_INT, NULL, ntype, l, NULL, r);    
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

    ASTNode* temp = TreeCreate(NULL, TYPE_BOOL, NULL, ntype, l, NULL, r);    
    return temp;
}

ASTNode* makeAssgnNode(ASTNode* l, ASTNode* r){
    if((l->nodetype != NODE_LEAF && l->nodetype != NODE_ARRAY && l->nodetype != NODE_PTR) || (l->nodetype != NODE_PTR && l->varName == NULL)){
        fprintf(stderr, "type mismatch: assign (ID)\n");
        exit(1);
    }

    if(l->type != r->type){
        fprintf(stderr, "type mismatch: assign %d %d\n", l->type, r->type);
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, NODE_ASSGN, l, NULL, r);    
    return temp;
}

ASTNode* makeReadNode(ASTNode* l){
    if(l->type != TYPE_INT && l->type != TYPE_STR){
        fprintf(stderr, "type mismatch: read %d\n", l->type);
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, NODE_READ, l, NULL, NULL);
    return temp;
}

ASTNode* makeWriteNode(ASTNode* l){
    if(l->type != TYPE_INT && l->type != TYPE_BOOL && l->type != TYPE_STR && l->type != TYPE_INT_PTR && l->type != TYPE_STR_PTR){
        fprintf(stderr, "type mismatch: write %d\n", l->type);
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, NODE_WRITE, l, NULL, NULL);    
    return temp;
}

ASTNode* makeConnNode(ASTNode* l, ASTNode* r){
    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, NODE_CONN, l, NULL, r);    
    return temp;
}

ASTNode* makeIterationNode(NodeType ntype, ASTNode *l, ASTNode* r){
    if(l->type != TYPE_BOOL){
        fprintf(stderr, "type mismatch: while\n");
        exit(1);
    }
    
    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, ntype, l, NULL, r);
    return temp;
}

ASTNode* makeIfElseNode(ASTNode* l, ASTNode* m, ASTNode* r){
    if(l->type != TYPE_BOOL){
        fprintf(stderr, "type mismatch: ifelse\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, NODE_IFELSE, l, m, r);
    return temp;
}

ASTNode* makeBreakNode(void){
    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, NODE_BREAK, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeContinueNode(void){
    ASTNode* temp = TreeCreate(NULL, TYPE_NONE, NULL, NODE_CONTINUE, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeArrayNode(char* arrName, VarType type, ASTNode* l, ASTNode* r){
    Gsymbol* var = GLookup(arrName);

    if(var->rowsize == 0){
        fprintf(stderr, "Not an array: %s\n", arrName);
        exit(1);
    }
    ASTNode* temp = TreeCreate(NULL, TYPE_ID, arrName, NODE_ARRAY, l, NULL, r);
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

    ASTNode* temp = TreeCreate(NULL, vtype, NULL, NODE_ADDR, var, NULL, NULL);
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

    ASTNode* temp = TreeCreate(NULL, vtype, NULL, NODE_PTR, ptrVar, NULL, NULL);
    return temp;
}