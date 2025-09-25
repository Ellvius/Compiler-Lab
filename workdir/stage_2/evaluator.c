#include "evaluator.h"

static int memory[26];

void initializeMemory(void) {
    for(int i = 0; i < 26; i++) {
        memory[i] = 0;
    }
}

int evaluateOperation(tnode* node){
    int i = evaluateCode(node->left);
    int j = evaluateCode(node->right);

    switch(node->nodetype){
        case NODE_ADD : return i + j;
        case NODE_SUB : return i - j;
        case NODE_MUL : return i * j;
        case NODE_DIV : {
            if(j == 0) {
                fprintf(stderr, "Error: Division by zero\n");
                exit(1);
            }
            return i / j;
        }

        case NODE_ASSGN: {
            if(node->left->nodetype != NODE_LEAF || node->left->vartype == TYPE_NONE) {
                fprintf(stderr, "Error: Invalid assignment left-hand side\n");
                exit(1);
            }

            tnode* var = node->left;
            char varname = *(var->varname);
            int idx = varname - 'a';
            memory[idx] = j;
            return memory[idx];
        }

        case NODE_CONN: {
            return 0;
        }      
        
        default:
            fprintf(stderr, "Error: Unknown operation node type %d\n", node->nodetype);
            exit(1);
    }
}

int evaluateCode(tnode* node){
    if(node == NULL) return 0;

    switch(node->nodetype){
        case NODE_LEAF:
            if(node->vartype == TYPE_NONE)  
                return node->val;
            else {
                char varname = *(node->varname);
                int idx = varname - 'a';
                return memory[idx];
            }

        case NODE_READ: {
            if(node->left == NULL || node->left->nodetype != NODE_LEAF || 
                node->left->vartype == TYPE_NONE) {
                fprintf(stderr, "Error: Invalid read statement\n");
                exit(1);
            }

            tnode* var = node->left;
            char varname = *(var->varname);
            int idx = varname - 'a';
            scanf("%d", &memory[idx]);
            return 0;
        }

        case NODE_WRITE: {
            int val = evaluateCode(node->left);
            printf("%d\n", val);
            return 0;
        }

        default:
            return evaluateOperation(node);
    }
    return 0;
}

int evaluateAST(tnode *root) {
    initializeMemory();
    evaluateCode(root);
    printf("Program exited.\n");
}