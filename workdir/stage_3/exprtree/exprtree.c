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

tnode* makeOperatorNode(node_type ntype,tnode *l,tnode *r){
    tnode* temp = createTree(0, TYPE_NONE, NULL, ntype, l, NULL, r);    
    return temp;
}

tnode* makeWhileNode(tnode *l, tnode* r){
    tnode* temp = createTree(0, TYPE_NONE, NULL, NODE_WHILE, l, NULL, r);
    return temp;
}

tnode* makeIfElseNode(tnode* l, tnode* m, tnode* r){
    tnode* temp = createTree(0, TYPE_NONE, NULL, NODE_IFELSE, l, m, r);
}

