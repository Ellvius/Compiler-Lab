#include "codeGen.h"

static int regNum = 0;
static int symbolTable[20];

reg_index getReg(void){
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


void codeGenHeader(FILE* fp){
    fprintf(fp, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(fp, "MOV SP, %d\n", SP);
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


reg_index codeGenID(tnode* node, FILE* fp){
    char varname = *(node->varname);
    int loc = varname - 'a' + SP;

    int r = getReg();
    symbolTable[r] = loc;

    fprintf(fp, "MOV R%d, [%d]\n", r, loc);
    return r;
}


reg_index codeGenNUM(tnode *node, FILE* fp){
    int r = getReg();
    fprintf(fp, "MOV R%d, %d\n", r, node->val);
    return r;
}


reg_index codeGenOP(tnode *node, FILE* fp){
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


reg_index codeGenRead(tnode* node, FILE* fp){
    // left node has the var
    tnode* var = node->left;
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

    for(int i = r-1; i >= 0; i--){
        fprintf(fp, "POP R%d\n", i);
    }

    freeReg();
    return r;
}

reg_index codeGenWrite(tnode* node, FILE* fp){
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

    for(int i = r-1; i >= 0; i--){
        fprintf(fp, "POP R%d\n", i);
    }
    freeReg();
    return r;
}


int codeGenNODE(tnode* node, FILE* fp){
    switch(node->nodetype){
        case NODE_LEAF:
            if(node->vartype == TYPE_NONE)  
                return codeGenNUM(node, fp);
            else    
                return codeGenID(node, fp);

        case NODE_READ:
            return codeGenRead(node, fp);

        case NODE_WRITE:
            return codeGenWrite(node,fp);

        default:
            return codeGenOP(node, fp);
    }
    return -1;
}


int codeGen(tnode *node){
    FILE *fp = fopen("./output.xsm", "w");     // output xsm file
    if(!fp){
        printf("Couldn't create output file\n");
        exit(1);
    }

    codeGenHeader(fp);    // Header section
    codeGenNODE(node, fp);
    codeGenExit(fp);    // Exit system call

    fclose(fp);
    return 0;
}
