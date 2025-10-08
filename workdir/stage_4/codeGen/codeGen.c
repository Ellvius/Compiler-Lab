#include "codeGen.h"

static int regNum = 0;
static int symbolTable[20];
static int lnum = 0;

static Stack* loopStack = NULL;


/* ========== STACK IMPLEMENTATION ==========*/

// Create a new empty stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

// Push a (start, end) pair onto the stack
void push(Stack* stack, int start, int end) {
    LabelNode* newNode = (LabelNode*)malloc(sizeof(LabelNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->start = start;
    newNode->end = end;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop a node from the stack
LabelNode* pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow! Cannot pop.\n");
        exit(1);
    }
    LabelNode* temp = stack->top;
    LabelNode* popped = temp;  // copy values
    stack->top = temp->next;
    free(temp);
    return popped;
}

// Peek at the top element of the stack
LabelNode* peek(Stack* stack) {
    return stack->top;
}

// Free the entire stack
void freeStack(Stack* stack) {
    while (stack->top != NULL) {
        pop(stack);
    }
    free(stack);
}


/*========== XSM CODE GENERATION IMPLEMENTATION ==========*/

RegIndex getReg(void){
    if(regNum==19){
        fprintf(stderr, "\nRegisters exhausted\n"); 
        exit(1);
    }
    return regNum++;
}


int freeReg(void){
    if(regNum == 0){
        fprintf(stderr,"\nNo registers to be freed\n");
        exit(1);
    }
    return regNum--;
}

int getLabel(void){
    return lnum++;
}

void codeGenHeader(FILE* fp){
    fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(fp, "MOV SP, %d\n", SP+26);
}


void codeGenExit(FILE* fp){
    fprintf(fp, "MOV R0,\"Exit\"\n");
    fprintf(fp, "PUSH R0\n");
    fprintf(fp, "PUSH R0\n");
    fprintf(fp, "PUSH R0\n");
    fprintf(fp, "PUSH R0\n");
    fprintf(fp, "PUSH R0\n");
    fprintf(fp, "CALL 0\n");
}


RegIndex codeGenID(ASTNode* node, FILE* fp){
    char varname = *(node->varname);
    int loc = varname - 'a' + SP;

    int r = getReg();
    symbolTable[r] = loc;

    fprintf(fp, "MOV R%d, [%d]\n", r, loc);
    return r;
}


RegIndex codeGenNUM(ASTNode *node, FILE* fp){
    int r = getReg();
    fprintf(fp, "MOV R%d, %d\n", r, node->val);
    return r;
}


RegIndex codeGenIfElse(ASTNode* node, FILE* fp){
    int label_1 = getLabel();

    int r = codeGenNODE(node->left, fp);        // code for if condition
    fprintf(fp, "JZ R%d, _L%d\n", r, label_1);
    codeGenNODE(node->middle, fp);

    int label_2 = -1;
    if(node->right){
        label_2 = getLabel();
        fprintf(fp, "JMP _L%d\n", label_2);
    }

    fprintf(fp, "_L%d:\n", label_1);

    if(node->right){
        codeGenNODE(node->right, fp);
        fprintf(fp, "_L%d:\n", label_2);
    }

    freeReg();
    return -1;
}


RegIndex codeGenIteration(ASTNode* node, FILE* fp){
    int startLabel = getLabel();
    int endLabel = getLabel();

    push(loopStack, startLabel, endLabel);
    int condReg;

    switch(node->nodetype){
        case NODE_WHILE: 
            fprintf(fp, "_L%d:\n", startLabel);

            condReg = codeGenNODE(node->left, fp);        // code for while condition
            fprintf(fp, "JZ R%d, _L%d\n", condReg, endLabel);  // jump out of loop

            codeGenNODE(node->right, fp);               // code for while statements
            fprintf(fp, "JMP _L%d\n", startLabel);         // jump back to statements
            fprintf(fp, "_L%d:\n", endLabel);            // out of loop label
            break;

        default: 
            fprintf(fp, "_L%d:\n", startLabel);
            codeGenNODE(node->right, fp);               // code for statements

            condReg = codeGenNODE(node->left, fp);        // code for condition

            if (node->nodetype == NODE_DOWHILE) {
                fprintf(fp, "JNZ R%d, _L%d\n", condReg, startLabel); // repeat while true
            } else {
                fprintf(fp, "JZ R%d, _L%d\n", condReg, startLabel);  // repeat while false
            }

            fprintf(fp, "_L%d:\n", endLabel);            // out of loop label
            break;        
    }
    freeReg();

    pop(loopStack);

    return -1;
}


RegIndex codeGenBreak(ASTNode* node, FILE* fp){
    LabelNode* top = peek(loopStack);
    if(top){
        fprintf(fp, "JMP _L%d\n", top->end);
    }
    return -1;
}


RegIndex codeGenContinue(ASTNode* node, FILE* fp){
    LabelNode* top = peek(loopStack);
    if(top){
        fprintf(fp, "JMP _L%d\n", top->start);
    }
    return -1;
}


RegIndex codeGenOP(ASTNode *node, FILE* fp){
    int i = codeGenNODE(node->left, fp);
    int j = codeGenNODE(node->right, fp);

    switch(node->nodetype){
        case NODE_ADD : 
            fprintf(fp, "ADD R%d, R%d\n", i, j);
            break;
        case NODE_SUB : 
            fprintf(fp, "SUB R%d, R%d\n", i, j);
            break;
        case NODE_MUL : 
            fprintf(fp, "MUL R%d, R%d\n", i, j);
            break;
        case NODE_DIV: 
            fprintf(fp, "DIV R%d, R%d\n", i, j);
            break;

        case NODE_LT: 
            fprintf(fp, "LT R%d, R%d\n", i, j);
            break;
        case NODE_GT: 
            fprintf(fp, "GT R%d, R%d\n", i, j);
            break;
        case NODE_LE: 
            fprintf(fp, "LE R%d, R%d\n", i, j);
            break;
        case NODE_GE: 
            fprintf(fp, "GE R%d, R%d\n", i, j);
            break;
        case NODE_NE: 
            fprintf(fp, "NE R%d, R%d\n", i, j);
            break;
        case NODE_EQ:
            fprintf(fp, "EQ R%d, R%d\n", i, j);
            break;

        case NODE_ASSGN:
            fprintf(fp, "MOV [%d], R%d\n", symbolTable[i], j);
            freeReg();      // to free up the left (here actually right is freed) subtree reg
            symbolTable[i] = -1;
            i = -1;
            break;

        case NODE_CONN:
            if(i != -1)
                freeReg();  // to free up the left stmt also
            if(j != -1)
                freeReg();
            return -1;            
    }

    freeReg();

    return i;
}


RegIndex codeGenRead(ASTNode* node, FILE* fp){
    // left node has the var
    ASTNode* var = node->left;
    char varname = *(var->varname);
    int loc = varname - 'a' + SP;
    int r = getReg();

    for(int i = 0; i < r; i++){
        fprintf(fp, "PUSH R%d\n", i);
    }

    int i = getReg();

    fprintf(fp, "MOV R%d,\"Read\"\n", i);
    fprintf(fp, "PUSH R%d\n", i);
    fprintf(fp, "MOV R%d, -1\n", i);
    fprintf(fp, "PUSH R%d\n", i);
    fprintf(fp, "MOV R%d, %d\n", i, loc);
    fprintf(fp, "PUSH R%d\n", i);
    fprintf(fp, "PUSH R%d\n", i);
    fprintf(fp, "PUSH R%d\n", i);
    fprintf(fp, "CALL 0\n");
    fprintf(fp, "POP R%d\n", r);
    fprintf(fp, "POP R%d\n", i);
    fprintf(fp, "POP R%d\n", i);
    fprintf(fp, "POP R%d\n", i);
    fprintf(fp, "POP R%d\n", i);

    freeReg();

    for(int i = r-1; i >= 0; i--){
        fprintf(fp, "POP R%d\n", i);
    }

    return r;
}

RegIndex codeGenWrite(ASTNode* node, FILE* fp){
    int r = codeGenNODE(node->left, fp);

    for(int i = 0; i < r; i++){
        fprintf(fp, "PUSH R%d\n", i);
    }

    int i = getReg();

    fprintf(fp, "MOV R%d,\"Write\"\n", i);
    fprintf(fp, "PUSH R%d\n", i);
    fprintf(fp, "MOV R%d, -2\n", i);
    fprintf(fp, "PUSH R%d\n", i);
    fprintf(fp, "PUSH R%d\n", r);
    fprintf(fp, "PUSH R%d\n", i);
    fprintf(fp, "PUSH R%d\n", i);
    fprintf(fp, "CALL 0\n");
    fprintf(fp, "POP R%d\n", r);
    fprintf(fp, "POP R%d\n", i);
    fprintf(fp, "POP R%d\n", i);
    fprintf(fp, "POP R%d\n", i);
    fprintf(fp, "POP R%d\n", i);

    freeReg();

    for(int i = r-1; i >= 0; i--){
        fprintf(fp, "POP R%d\n", i);
    }

    return r;
}


int codeGenNODE(ASTNode* node, FILE* fp){
    switch(node->nodetype){
        case NODE_LEAF:
            if(node->varname == NULL)  
                return codeGenNUM(node, fp);
            else    
                return codeGenID(node, fp);

        case NODE_READ:
            return codeGenRead(node, fp);

        case NODE_WRITE:
            return codeGenWrite(node,fp);

        case NODE_IFELSE:
            return codeGenIfElse(node, fp);

        case NODE_WHILE:
            return codeGenIteration(node, fp);

        case NODE_DOWHILE:
            return codeGenIteration(node, fp);

        case NODE_REPEAT:
            return codeGenIteration(node, fp);

        case NODE_BREAK:
            return codeGenBreak(node, fp);

        case NODE_CONTINUE:
            return codeGenContinue(node, fp);

        default:
            return codeGenOP(node, fp);
    }
    return -1;
}


int codeGen(ASTNode *node){
    FILE *fp = fopen("./label_output.xsm", "w");     // output xsm file
    if(!fp){
        printf("Couldn't create output file\n");
        exit(1);
    }

    if(loopStack == NULL)
        loopStack = createStack();   // stack to keep track of nested loops


    codeGenHeader(fp);    // Header section
    codeGenNODE(node, fp);
    codeGenExit(fp);    // Exit system call

    if(loopStack) {
        freeStack(loopStack);
        loopStack = NULL;   // safety reset
    }
    
    fclose(fp);
    return 0;
}
