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

void prefixForm(struct tnode *t);

void postfixForm(struct tnode *t);

reg_index getReg(void);

int freeReg(void);

int generateCode(struct tnode* t);

reg_index codeGen(struct tnode* t, FILE* fp);