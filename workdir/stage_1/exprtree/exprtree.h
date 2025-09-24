#define reg_index int

typedef struct tnode{
    int val;
    char *op; //indicates the name of the operator for a non leaf node
    struct tnode *left, *right; //left and right branches
} tnode;

// #define YYSTYPE tnode*
// use %union{..} instead

/*Make a leaf tnode and set the value of val field*/
struct tnode* makeLeafNode(int n);

/*Make a tnode with operator, left and right branches set*/
struct tnode* makeOperatorNode(char op,struct tnode *l,struct tnode *r);

/*To get free register*/
reg_index getReg(void);

/*Frees the used register with largest regnum*/
int freeReg(void);

/*Function that generates the output xsm code*/
int codeGen(struct tnode *node);