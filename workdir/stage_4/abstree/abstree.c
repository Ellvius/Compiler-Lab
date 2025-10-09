#include "abstree.h"

ASTNode* TreeCreate(int n, char* s, VarType vtype, char* vname, NodeType ntype, ASTNode *l, ASTNode* m, ASTNode *r){
    ASTNode* temp = (ASTNode*)malloc(sizeof(ASTNode));

    temp->type = vtype;
    switch (vtype) {
        case TYPE_INT:
            temp->value.intVal = n;
            break;
        
        case TYPE_STR:
            if (s) {
                temp->value.strVal = strdup(s); // safe copy
            } else {
                temp->value.strVal = NULL;
            }
            break;
        
        case TYPE_NONE: // variable (ID)
            if (vname) {
                temp->value.varName = strdup(vname); // safe copy
                Gsymbol *var = GLookup(vname);
                temp->type = var->type;
            } else {
                temp->value.varName = NULL;
            }
            break;
    }
    temp->nodetype = ntype;
    temp->left = l;
    temp->middle = m;
    temp->right = r;
    temp->GEntry = NULL;

    return temp;
}

ASTNode* makeLeafNode(int n, char* s, VarType vtype, char* vname){
    ASTNode* temp = TreeCreate(n, s, vtype, vname, NODE_LEAF, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeArithOPNode(NodeType ntype, ASTNode* l, ASTNode* r){
    if(l->type != TYPE_INT || r->type != TYPE_INT){
        fprintf(stderr, "type mismatch: arith\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(0, NULL, TYPE_INT, NULL, ntype, l, NULL, r);    
    return temp;
}

ASTNode* makeRelOPNode(NodeType ntype, ASTNode* l, ASTNode* r){
    if(l->type != TYPE_INT || r->type != TYPE_INT){
        fprintf(stderr, "type mismatch: relop\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(0, NULL, TYPE_BOOL, NULL, ntype, l, NULL, r);    
    return temp;
}

ASTNode* makeAssgnNode(ASTNode* l, ASTNode* r){
    if(l->nodetype != NODE_LEAF){
        fprintf(stderr, "type mismatch: assign (ID)\n");
        exit(1);
    }

    if(l->type != r->type){
        fprintf(stderr, "type mismatch: assign\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(0, NULL, TYPE_NONE, NULL, NODE_ASSGN, l, NULL, r);    
    return temp;
}

ASTNode* makeReadNode(ASTNode* l){
    if(l->type != TYPE_INT ){
        fprintf(stderr, "type mismatch: read\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(0, NULL, TYPE_NONE, NULL, NODE_READ, l, NULL, NULL);    
    return temp;
}

ASTNode* makeWriteNode(ASTNode* l){
    if(l->type != TYPE_INT && l->type != TYPE_BOOL && l->type != TYPE_STR){
        fprintf(stderr, "type mismatch: write %d\n", l->type);
        exit(1);
    }

    ASTNode* temp = TreeCreate(0, NULL, TYPE_NONE, NULL, NODE_WRITE, l, NULL, NULL);    
    return temp;
}

ASTNode* makeConnNode(ASTNode* l, ASTNode* r){
    ASTNode* temp = TreeCreate(0, NULL, TYPE_NONE, NULL, NODE_CONN, l, NULL, r);    
    return temp;
}

ASTNode* makeIterationNode(NodeType ntype, ASTNode *l, ASTNode* r){
    if(l->type != TYPE_BOOL){
        fprintf(stderr, "type mismatch: while\n");
        exit(1);
    }
    
    ASTNode* temp = TreeCreate(0, NULL, TYPE_NONE, NULL, ntype, l, NULL, r);
    return temp;
}

ASTNode* makeIfElseNode(ASTNode* l, ASTNode* m, ASTNode* r){
    if(l->type != TYPE_BOOL){
        fprintf(stderr, "type mismatch: ifelse\n");
        exit(1);
    }

    ASTNode* temp = TreeCreate(0, NULL, TYPE_NONE, NULL, NODE_IFELSE, l, m, r);
    return temp;
}

ASTNode* makeBreakNode(void){
    ASTNode* temp = TreeCreate(0, NULL, TYPE_NONE, NULL, NODE_BREAK, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeContinueNode(void){
    ASTNode* temp = TreeCreate(0, NULL, TYPE_NONE, NULL, NODE_CONTINUE, NULL, NULL, NULL);    
    return temp;
}