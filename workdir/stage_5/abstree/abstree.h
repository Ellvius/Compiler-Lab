#ifndef ABSTREE_HEADER_FILE
#define ABSTREE_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include "../symboltable/symboltable.h"

typedef enum {
    TYPE_NONE,
    TYPE_ID,
    TYPE_INT,
    TYPE_CHAR,
    TYPE_BOOL,
    TYPE_STR,
    TYPE_INT_PTR,
    TYPE_STR_PTR
} VarType;

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
    NODE_MOD,
    NODE_LT,
    NODE_GT,
    NODE_LE,
    NODE_GE,
    NODE_NE,
    NODE_EQ,
    NODE_IFELSE,
    NODE_WHILE,
    NODE_DOWHILE,
    NODE_REPEAT,
    NODE_BREAK,
    NODE_CONTINUE,
    NODE_ARRAY,
    NODE_ADDR,
    NODE_PTR,
    NODE_FUNC,
    NODE_AND,
    NODE_OR,
    NODE_NOT,
    NODE_RET
} NodeType;



typedef union Constant {
    int intVal;                             // value of the constant
    char* strVal;
} Constant;

typedef struct ASTNode{
    VarType type;           //pointer to the type table entry
    NodeType nodetype;                     //node type information,eg:NODETYPE_WHILE,NODETYPE_PLUS,NODETYPE_STMT etc
    char *name;                       //stores the variable/function name in case of variable/function nodes
    union Constant *value;             //stores the value of the constant if the node corresponds to a constant
    struct ASTNode *arglist;          //pointer to the expression list given as arguments to a function call
    struct ASTNode *ptr1,*ptr2,*ptr3; //Subtrees of the node. (Maximum Subtrees for IF THEN ELSE)
    struct Gsymbol *Gentry;           //pointer to GST entry for global variables and functions
    struct Lsymbol *Lentry;           //pointer to the function's LST for local variables and arguements
} ASTNode;

/* Create a generic AST node */
ASTNode* TreeCreate(union Constant *val, VarType vtype, char* vname, NodeType ntype, ASTNode *l, ASTNode *m, ASTNode *r, ASTNode* arglist);

/* Make Leaf node (NUM constant or ID variable) */
ASTNode* makeLeafNode(int n, char* s, VarType vtype, char* vname);

/* Make arithmetic operator node (+, -, *, /) */
ASTNode* makeArithOPNode(NodeType ntype, ASTNode* l, ASTNode* r);

/* Make relational operator node (<, <=, >, >=, ==, !=) */
ASTNode* makeRelOPNode(NodeType ntype, ASTNode* l, ASTNode* r);

/* Make assignment statement node (ID = expr) */
ASTNode* makeAssgnNode(ASTNode* l, ASTNode* r);

/* Make READ statement node */
ASTNode* makeReadNode(ASTNode* l);

/* Make WRITE statement node */
ASTNode* makeWriteNode(ASTNode* l);

/* Make connector node (stmt1 ; stmt2) */
ASTNode* makeConnNode(ASTNode* l, ASTNode* r);

/* Make loop node (while, do-while, repeat-until) */
ASTNode* makeIterationNode(NodeType ntype, ASTNode *l, ASTNode* r);

/* Make IF-ELSE conditional node */
ASTNode* makeIfElseNode(ASTNode* l, ASTNode* m, ASTNode* r);

/* Make BREAK statement node */
ASTNode* makeBreakNode(void);

/* Make CONTINUE statement node */
ASTNode* makeContinueNode(void);

/* Make Int/String array node*/
ASTNode* makeArrayNode(char* arrName, VarType type, ASTNode* l, ASTNode* r);

ASTNode* makeAddrNode(ASTNode* node);

ASTNode* makePtrNode(ASTNode* node);

ASTNode* makeFuncNode(char* fname, VarType vtype, ASTNode* param);

ASTNode* makeArgNode(ASTNode* argHead, ASTNode* arg);

ASTNode* makeRetNode(ASTNode* ret);

ASTNode* makeLogicOPNode(NodeType ntype, ASTNode* l, ASTNode* r);

#endif