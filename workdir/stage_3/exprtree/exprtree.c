#include "exprtree.h"

tnode* createTree(int n, var_type vtype, char* vname, node_type ntype, tnode *l, tnode* m, tnode *r){
    tnode* temp = (tnode*)malloc(sizeof(tnode));

    temp->val = n;
    temp->vartype = vtype;
    temp->varname = vname;
    temp->nodetype = ntype;
    temp->left = l;
    temp->middle = m;
    temp->right = r;

    return temp;
}

tnode* makeLeafNode(int n, var_type vtype, char* vname){
    tnode* temp = createTree(n, vtype, vname, NODE_LEAF, NULL, NULL, NULL);    
    return temp;
}

tnode* makeArithOPNode(node_type ntype, tnode* l, tnode* r){
    if(l->vartype != TYPE_INT || r->vartype != TYPE_INT){
        fprintf(stderr, "type mismatch: arith\n");
        exit(1);
    }

    tnode* temp = createTree(0, TYPE_INT, NULL, ntype, l, NULL, r);    
    return temp;
}

tnode* makeRelOPNode(node_type ntype, tnode* l, tnode* r){
    if(l->vartype != TYPE_INT || r->vartype != TYPE_INT){
        fprintf(stderr, "type mismatch: relop\n");
        exit(1);
    }

    tnode* temp = createTree(0, TYPE_BOOL, NULL, ntype, l, NULL, r);    
    return temp;
}

tnode* makeAssgnNode(tnode* l, tnode* r){
    if(l->vartype != TYPE_INT || r->vartype != TYPE_INT){
        fprintf(stderr, "type mismatch: assign\n");
        exit(1);
    }

    tnode* temp = createTree(0, TYPE_NONE, NULL, NODE_ASSGN, l, NULL, r);    
    return temp;
}

tnode* makeReadNode(tnode* l){
    if(l->vartype != TYPE_INT ){
        fprintf(stderr, "type mismatch: read\n");
        exit(1);
    }

    tnode* temp = createTree(0, TYPE_NONE, NULL, NODE_READ, l, NULL, NULL);    
    return temp;
}

tnode* makeWriteNode(tnode* l){
    if(l->vartype != TYPE_INT && l->vartype != TYPE_BOOL){
        fprintf(stderr, "type mismatch: write %d\n", l->vartype);
        exit(1);
    }

    tnode* temp = createTree(0, TYPE_NONE, NULL, NODE_WRITE, l, NULL, NULL);    
    return temp;
}

tnode* makeConnNode(tnode* l, tnode* r){
    tnode* temp = createTree(0, TYPE_NONE, NULL, NODE_CONN, l, NULL, r);    
    return temp;
}

tnode* makeWhileNode(tnode *l, tnode* r){
    if(l->vartype != TYPE_BOOL){
        fprintf(stderr, "type mismatch: while\n");
        exit(1);
    }
    
    tnode* temp = createTree(0, TYPE_NONE, NULL, NODE_WHILE, l, NULL, r);
    return temp;
}

tnode* makeIfElseNode(tnode* l, tnode* m, tnode* r){
    if(l->vartype != TYPE_BOOL){
        fprintf(stderr, "type mismatch: ifelse\n");
        exit(1);
    }

    tnode* temp = createTree(0, TYPE_NONE, NULL, NODE_IFELSE, l, m, r);
    return temp;
}

tnode* makeBreakNode(void){
    tnode* temp = createTree(0, TYPE_NONE, NULL, NODE_BREAK, NULL, NULL, NULL);    
    return temp;
}

tnode* makeContinueNode(void){
    tnode* temp = createTree(0, TYPE_NONE, NULL, NODE_CONTINUE, NULL, NULL, NULL);    
    return temp;
}