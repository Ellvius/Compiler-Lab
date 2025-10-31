#include "codeGen.h"
#include "../symboltable/symboltable.h"

static int regNum = 0;
static int lnum = 0;
int header = 0;

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
    fprintf(fp, "MOV SP, %d\n", nextFreeAddr);
    fprintf(fp, "PUSH R0\n");
    fprintf(fp, "CALL _MAIN\n");
    fprintf(fp, "JMP _EXIT\n");
}


void codeGenExit(FILE* fp){
    fprintf(fp, "_EXIT:\n");
    fprintf(fp, "MOV R0,\"Exit\"\n");
    fprintf(fp, "PUSH R0\n");
    fprintf(fp, "PUSH R0\n");
    fprintf(fp, "PUSH R0\n");
    fprintf(fp, "PUSH R0\n");
    fprintf(fp, "PUSH R0\n");
    fprintf(fp, "CALL 0\n");
}


RegIndex codeGenID(ASTNode* node, FILE* fp){
    int r = getReg();

    if(node->Lentry != NULL){
        fprintf(fp, "MOV R%d, BP\n", r);
        fprintf(fp, "ADD R%d, %d\n", r, node->Lentry->binding);
        fprintf(fp, "MOV R%d, [R%d]\n", r, r);
    }
    else {
        fprintf(fp, "MOV R%d, [%d]\n", r, node->Gentry->binding);
    }
    return r;
}


RegIndex codeGenConst(ASTNode *node, FILE* fp){
    int r = getReg();
    
    switch(node->type){
        case TYPE_INT:
            fprintf(fp, "MOV R%d, %d\n", r, node->value->intVal);
            break;

        case TYPE_STR:
            fprintf(fp, "MOV R%d, \"%s\"\n", r, node->value->strVal);
            break;

        default:
            fprintf(stderr, "Undefined const type: %s\n", tokenToString(node->type));
            break;
    }
    return r;
}


RegIndex codeGenArray(ASTNode * node, FILE* fp){
    int i = getReg();
    int offsetRow = codeGenNODE(node->left, fp);

    if(node->right != NULL){
        int offsetCol = codeGenNODE(node->right, fp);

        fprintf(fp, "MUL R%d, %d\n", offsetRow, node->Gentry->rowsize);     // i*rowsize
        fprintf(fp, "ADD R%d, R%d\n", offsetRow, offsetCol);                // i*rowsize + j
        freeReg();      // free offsetCol
    }

    fprintf(fp, "ADD R%d, %d\n", offsetRow, node->Gentry->binding);
    fprintf(fp, "MOV R%d, [R%d]\n", i, offsetRow);
    freeReg();          // free offsetRow
    return i;
}


RegIndex codeGenAddress(ASTNode * node, FILE* fp){
    ASTNode* var = node->left;
    int address = getReg();

    if(var->Lentry != NULL){
        fprintf(fp, "MOV R%d, BP\n", address);
        fprintf(fp, "ADD R%d, %d\n", address, var->Lentry->binding);
    }
    else {
        fprintf(fp, "MOV R%d, %d\n", address, var->Gentry->binding);
    }

    return address;
}


RegIndex codeGenPtr(ASTNode * node, FILE* fp){
    ASTNode* ptr = node->left;
    int val = getReg();

    if(ptr->Lentry != NULL){
        fprintf(fp, "MOV R%d, BP\n", val);
        fprintf(fp, "ADD R%d, %d\n", val, ptr->Lentry->binding);
    }
    else {
        fprintf(fp, "MOV R%d, %d\n", val, ptr->Gentry->binding);
    }

    fprintf(fp, "MOV R%d, [R%d]\n", val, val);
    fprintf(fp, "MOV R%d, [R%d]\n", val, val);
    return val;
}


RegIndex codeGenRet(ASTNode* node, FILE* fp){
    int retVal = codeGenNODE(node->left, fp);

    int retAddr = getReg();
    fprintf(fp, "MOV R%d, BP\n", retAddr);
    fprintf(fp, "SUB R%d, 2\n", retAddr);                   // return addr space BP - 2
    fprintf(fp, "MOV [R%d], R%d\n", retAddr, retVal);
    freeReg();
    freeReg();

    fprintf(fp, "MOV SP, BP\n");
    fprintf(fp, "POP BP\n");
    fprintf(fp, "RET\n");
    
    return -1;
}


RegIndex codeGenFnCall(ASTNode* node, FILE* fp){
    int r = getReg();
    int val = -1;

    for(int i = 0; i < r; i++){
        fprintf(fp, "PUSH R%d\n", i);
    }

    regNum = 0;     // free all registers
    node = node->left;  // id node to separate fn(fn()) case

    ASTNode* args = node->arglist;

    while(args != NULL){
        val = codeGenNODE(args, fp);
        fprintf(fp, "PUSH R%d\n", val);     // pushing the arguments
        freeReg();
        args = args->arglist;
    }

    fprintf(fp, "PUSH R0\n");       // space for return value

    Gsymbol* Gtemp = GLookup(node->name);
    fprintf(fp, "CALL _F%d\n", Gtemp->flabel);

    fprintf(fp, "POP R%d\n", r);        // Store return value

    int dummy = getReg();
    args = node->arglist;
    while(args != NULL){
        fprintf(fp, "POP R%d\n", val);     // Discard arguments
        args = args->arglist;
    }
    freeReg();

    for(int i = r-1; i >= 0; i--){
        fprintf(fp, "POP R%d\n", i);        // Restore registers
    }

    regNum = r + 1;
    return r;
}


RegIndex codeGenLogicOP(ASTNode* node, FILE* fp){
    switch(node->nodetype){
        case NODE_AND: {
            int endLabel = getLabel();
            
            int i = codeGenNODE(node->left, fp);
            int r = getReg();
            fprintf(fp, "MOV R%d, 1\n", r);
            fprintf(fp, "JZ R%d, _L%d\n", i, endLabel);
            
            int j = codeGenNODE(node->right, fp);
            fprintf(fp, "MOV R%d, R%d\n", r, j);
            freeReg();

            fprintf(fp, "_L%d:\n", endLabel);
            fprintf(fp, "MUL R%d, R%d\n", i, r);
            freeReg();
    
            return i;
        }
    
        case NODE_OR:{
            int endLabel = getLabel();

            int i = codeGenNODE(node->left, fp);
            int r = getReg();
            fprintf(fp, "MOV R%d, 0\n", r);
            fprintf(fp, "JNZ R%d, _L%d\n", i, endLabel);

            int j = codeGenNODE(node->right, fp);
            fprintf(fp, "MOV R%d, R%d\n", r, j);
            freeReg();

            fprintf(fp, "_L%d:\n", endLabel);
            fprintf(fp, "ADD R%d, R%d\n", i, r);
            freeReg();

            return i;
        }
    
        case NODE_NOT:{
            int zeroLabel = getLabel();
            int endLabel = getLabel();
            int r = codeGenNODE(node->left, fp);

            fprintf(fp, "JZ R%d, _L%d\n", r, zeroLabel);

            fprintf(fp, "MOV R%d, 0\n", r);
            fprintf(fp, "JMP _L%d\n", endLabel);

            fprintf(fp, "_L%d:\n", zeroLabel);
            fprintf(fp, "MOV R%d, 1\n", r);

            fprintf(fp, "_L%d:\n", endLabel);

            return r;
        }
    }
}


RegIndex codeGenAssgn(ASTNode* node, FILE* fp){
    ASTNode* id = node->left;
    int expr = codeGenNODE(node->right, fp);

    if(id->nodetype == NODE_ARRAY){
        int offsetRow = codeGenNODE(id->left, fp);

        if(id->right != NULL){
            int offsetCol = codeGenNODE(id->right, fp);
    
            fprintf(fp, "MUL R%d, %d\n", offsetRow, id->Gentry->rowsize);     // i*rowsize
            fprintf(fp, "ADD R%d, R%d\n", offsetRow, offsetCol);                // i*rowsize + j
            freeReg();      // free offsetCol
        }

        fprintf(fp, "ADD R%d, %d\n", offsetRow, id->Gentry->binding);
        fprintf(fp, "MOV [R%d], R%d\n", offsetRow, expr);
        freeReg();
    } 
    else if(id->nodetype == NODE_PTR){
        ASTNode* ptr = id->left;

        int addr = getReg();
        if(ptr->Lentry != NULL){
            fprintf(fp, "MOV R%d, BP\n", addr);
            fprintf(fp, "ADD R%d, %d\n", addr, ptr->Lentry->binding);
        }
        else {
            fprintf(fp, "MOV R%d, %d\n", addr, ptr->Gentry->binding);
        }

        fprintf(fp, "MOV R%d, [R%d]\n", addr, addr);
        fprintf(fp, "MOV [R%d], R%d\n", addr, expr);
        freeReg();
    }
    else{
        int addr = getReg();
        if(id->Lentry != NULL){
            fprintf(fp, "MOV R%d, BP\n", addr);
            fprintf(fp, "ADD R%d, %d\n", addr, id->Lentry->binding);
            fprintf(fp, "MOV [R%d], R%d\n", addr, expr);
        }
        else {
            fprintf(fp, "MOV [%d], R%d\n", id->Gentry->binding, expr);
        }
        freeReg();
    }

    freeReg();
    return -1;
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

        case NODE_MOD: 
            fprintf(fp, "MOD R%d, R%d\n", i, j);
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
    ASTNode* id = node->left;
    int r = getReg();

    for(int i = 0; i < r; i++){
        fprintf(fp, "PUSH R%d\n", i);
    }

    int i = getReg();

    fprintf(fp, "MOV R%d,\"Read\"\n", i);
    fprintf(fp, "PUSH R%d\n", i);
    fprintf(fp, "MOV R%d, -1\n", i);
    fprintf(fp, "PUSH R%d\n", i);

    if(id->nodetype == NODE_ARRAY){
        int offsetRow = codeGenNODE(id->left, fp);

        if(id->right != NULL){
            int offsetCol = codeGenNODE(id->right, fp);
    
            fprintf(fp, "MUL R%d, %d\n", offsetRow, id->Gentry->rowsize);     // i*rowsize
            fprintf(fp, "ADD R%d, R%d\n", offsetRow, offsetCol);                // i*rowsize + j
            freeReg();      // free offsetCol
        }

        fprintf(fp, "ADD R%d, %d\n", offsetRow, id->Gentry->binding);
        fprintf(fp, "PUSH R%d\n", offsetRow);
        freeReg();
    }
    else {
        if(id->Lentry != NULL){
            fprintf(fp, "MOV R%d, BP\n", i);
            fprintf(fp, "ADD R%d, %d\n", i, id->Lentry->binding);
        }
        else {
            fprintf(fp, "MOV R%d, %d\n", i, id->Gentry->binding);
        }
        fprintf(fp, "PUSH R%d\n", i);
    }
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
            if(node->name == NULL)  
                return codeGenConst(node, fp);
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

        case NODE_ASSGN:
            return codeGenAssgn(node, fp);

        case NODE_ARRAY:
            return codeGenArray(node, fp);

        case NODE_ADDR:
            return codeGenAddress(node, fp);

        case NODE_PTR:
            return codeGenPtr(node, fp);

        case NODE_AND: 
        case NODE_OR:
        case NODE_NOT:
            return codeGenLogicOP(node, fp);

        case NODE_FUNC:
            return codeGenFnCall(node, fp);

        case NODE_RET:
            return codeGenRet(node, fp);

        default:
            return codeGenOP(node, fp);
    }
    return -1;
}


int codeGenFunc(ASTNode *node, char* fname){
    FILE *fp;

    if(!header){
        fp = fopen("./label_output.xsm", "w");     // output xsm file
        if(!fp){
            printf("Couldn't create output file\n");
            exit(1);
        }
        
        codeGenHeader(fp);    // Header section
        header = 1;
    }
    else {
        fp = fopen("./label_output.xsm", "a");
        if(!fp){
            printf("Couldn't open output file to append\n");
            exit(1);
        }
    }

    if(loopStack == NULL)
        loopStack = createStack();   // stack to keep track of nested loops

    Gsymbol* fn = GLookup(fname);

    fprintf(fp, "_F%d:\n", fn->flabel);
    fprintf(fp, "PUSH BP\n");
    fprintf(fp, "MOV BP, SP\n");

    Lsymbol* lst = Lhead;
    Paramstruct* params = fn->paramlist;
    while(params != NULL){
        lst = lst->next;
        params = params->next;
    }

    while(lst != NULL){
        fprintf(fp, "PUSH R0\n");
        lst = lst->next;
    }

    codeGenNODE(node, fp);

    if(loopStack) {
        freeStack(loopStack);
        loopStack = NULL;   // safety reset
    }
    
    fclose(fp);
    return 0;
}


int codeGenMain(ASTNode* node){
    FILE *fp;

    if(!header){
        fp = fopen("./label_output.xsm", "w");     // output xsm file
        if(!fp){
            printf("Couldn't create output file\n");
            exit(1);
        }
        
        codeGenHeader(fp);    // Header section
        header = 1;
    }
    else {
        fp = fopen("./label_output.xsm", "a");
        if(!fp){
            printf("Couldn't open output file to append\n");
            exit(1);
        }
    }

    if(loopStack == NULL)
        loopStack = createStack();   // stack to keep track of nested loops

    fprintf(fp, "_MAIN:\n");
    fprintf(fp, "PUSH BP\n");
    fprintf(fp, "MOV BP, SP\n");

    Lsymbol* temp = Lhead;
    while(temp != NULL){
        fprintf(fp, "PUSH R0\n");
        temp = temp->next;
    }

    codeGenNODE(node, fp);
    codeGenExit(fp);    // Exit system call

    if(loopStack) {
        freeStack(loopStack);
        loopStack = NULL;   // safety reset
    }
    
    fclose(fp);
    return 0;
}
