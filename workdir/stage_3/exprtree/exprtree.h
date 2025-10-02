#ifndef EXPTREE_HEADER_FILE
#define EXPTREE_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    TYPE_NONE = -1,
    TYPE_INT = 0,
    TYPE_CHAR = 1,
    TYPE_BOOL = 2
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
    NODE_DIV,
    NODE_LT,
    NODE_GT,
    NODE_LE,
    NODE_GE,
    NODE_NE,
    NODE_EQ,
    NODE_IFELSE,
    NODE_WHILE,
    NODE_BREAK,
    NODE_CONTINUE
} node_type;

typedef struct tnode {
    int val;        // value of a number for NUM nodes.
    var_type vartype;       // type of variable
    char* varname;  // name of a variable for ID nodes
    node_type nodetype;   // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode *left, *middle, *right;  // left and right branches
} tnode;

/*Create a node tnode*/
tnode* createTree(int n, var_type vtype, char* vname, node_type ntype, tnode *l, tnode *m, tnode *r);

/*Make Leaf node (could be an ID or NUM)*/
tnode* makeLeafNode(int n, var_type vtype, char* vname);

/*Make non leaf nodes (conn, read, write, assign .. etc)*/
tnode* makeArithOPNode(node_type ntype, tnode* l, tnode* r);

tnode* makeRelOPNode(node_type ntype, tnode* l, tnode* r);

tnode* makeAssgnNode(tnode* l, tnode* r);

tnode* makeReadNode(tnode* l);

tnode* makeWriteNode(tnode* l);

tnode* makeConnNode(tnode* l, tnode* r);

tnode* makeWhileNode(tnode *l, tnode* r);

tnode* makeIfElseNode(tnode* l, tnode* m, tnode* r);

tnode* makeBreakNode(void);

tnode* makeContinueNode(void);

#endif