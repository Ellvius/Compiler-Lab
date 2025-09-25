#ifndef EXPTREE_HEADER_FILE
#define EXPTREE_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    TYPE_NONE = -1,
    TYPE_NUM = 0,
    TYPE_CHAR = 1
} var_type;

typedef enum {
    NODE_CONN,
    NODE_LEAF,
    NODE_READ,
    NODE_WRITE,
    NODE_ASSGN,
    NODE_ADD,
    NODE_SUB,
    NODE_MUL,
    NODE_DIV
} node_type;

typedef struct tnode {
    int val;        // value of a number for NUM nodes.
    var_type vartype;       // type of variable
    char* varname;  // name of a variable for ID nodes
    node_type nodetype;   // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode *left,*right;  // left and right branches
} tnode;

/*Create a node tnode*/
tnode* createTree(int n, var_type vtype, char* vname, node_type ntype, tnode *l, tnode *r);

/*Make Leaf node (could be an ID or NUM)*/
tnode* makeLeafNode(int n, var_type vtype, char* vname);

/*Make non leaf nodes (conn, read, write, assign .. etc)*/
tnode* makeOperatorNode(node_type ntype,tnode *l,tnode *r);

#endif