#include "abstree.h"

ASTNode* createTree(int n, VarType vtype, char* vname, NodeType ntype, ASTNode *l, ASTNode* m, ASTNode *r){
    ASTNode* temp = (ASTNode*)malloc(sizeof(ASTNode));

    temp->val = n;
    temp->type = vtype;
    temp->varname = vname;
    temp->nodetype = ntype;
    temp->left = l;
    temp->middle = m;
    temp->right = r;

    return temp;
}

ASTNode* makeLeafNode(int n, VarType vtype, char* vname){
    ASTNode* temp = createTree(n, vtype, vname, NODE_LEAF, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeArithOPNode(NodeType ntype, ASTNode* l, ASTNode* r){
    if(l->type != TYPE_INT || r->type != TYPE_INT){
        fprintf(stderr, "type mismatch: arith\n");
        exit(1);
    }

    ASTNode* temp = createTree(0, TYPE_INT, NULL, ntype, l, NULL, r);    
    return temp;
}

ASTNode* makeRelOPNode(NodeType ntype, ASTNode* l, ASTNode* r){
    if(l->type != TYPE_INT || r->type != TYPE_INT){
        fprintf(stderr, "type mismatch: relop\n");
        exit(1);
    }

    ASTNode* temp = createTree(0, TYPE_BOOL, NULL, ntype, l, NULL, r);    
    return temp;
}

ASTNode* makeAssgnNode(ASTNode* l, ASTNode* r){
    if(l->type != TYPE_INT || r->type != TYPE_INT){
        fprintf(stderr, "type mismatch: assign\n");
        exit(1);
    }

    ASTNode* temp = createTree(0, TYPE_NONE, NULL, NODE_ASSGN, l, NULL, r);    
    return temp;
}

ASTNode* makeReadNode(ASTNode* l){
    if(l->type != TYPE_INT ){
        fprintf(stderr, "type mismatch: read\n");
        exit(1);
    }

    ASTNode* temp = createTree(0, TYPE_NONE, NULL, NODE_READ, l, NULL, NULL);    
    return temp;
}

ASTNode* makeWriteNode(ASTNode* l){
    if(l->type != TYPE_INT && l->type != TYPE_BOOL){
        fprintf(stderr, "type mismatch: write %d\n", l->type);
        exit(1);
    }

    ASTNode* temp = createTree(0, TYPE_NONE, NULL, NODE_WRITE, l, NULL, NULL);    
    return temp;
}

ASTNode* makeConnNode(ASTNode* l, ASTNode* r){
    ASTNode* temp = createTree(0, TYPE_NONE, NULL, NODE_CONN, l, NULL, r);    
    return temp;
}

ASTNode* makeIterationNode(NodeType ntype, ASTNode *l, ASTNode* r){
    if(l->type != TYPE_BOOL){
        fprintf(stderr, "type mismatch: while\n");
        exit(1);
    }
    
    ASTNode* temp = createTree(0, TYPE_NONE, NULL, ntype, l, NULL, r);
    return temp;
}

ASTNode* makeIfElseNode(ASTNode* l, ASTNode* m, ASTNode* r){
    if(l->type != TYPE_BOOL){
        fprintf(stderr, "type mismatch: ifelse\n");
        exit(1);
    }

    ASTNode* temp = createTree(0, TYPE_NONE, NULL, NODE_IFELSE, l, m, r);
    return temp;
}

ASTNode* makeBreakNode(void){
    ASTNode* temp = createTree(0, TYPE_NONE, NULL, NODE_BREAK, NULL, NULL, NULL);    
    return temp;
}

ASTNode* makeContinueNode(void){
    ASTNode* temp = createTree(0, TYPE_NONE, NULL, NODE_CONTINUE, NULL, NULL, NULL);    
    return temp;
}