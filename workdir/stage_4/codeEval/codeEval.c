#include "codeEval.h"

static int memory[26];
static int breakFlag = 0;
static int continueFlag = 0;

void initializeMemory(void) {
    for(int i = 0; i < 26; i++) {
        memory[i] = 0;
    }
}

int evaluateCode(ASTNode* node){
    if(node == NULL) return 0;

    switch(node->nodetype){
        case NODE_LEAF:
            if(node->varname == NULL)  
                return node->val;
            else {
                char varname = *(node->varname);
                int idx = varname - 'a';
                return memory[idx];
            }

        case NODE_READ: {
            ASTNode* var = node->left;
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

        case NODE_IFELSE: {
            if(evaluateCode(node->left)){
                evaluateCode(node->middle);
            }
            else if(node->right != NULL){
                evaluateCode(node->right);
            }
            return 0;
        }

        case NODE_WHILE: {
            while(evaluateCode(node->left)){
                evaluateCode(node->right);
                if(breakFlag){ breakFlag = 0; break; }
                if(continueFlag){ continueFlag = 0; continue; }
            }
            return 0;
        }

        case NODE_DOWHILE: {
            do {
                evaluateCode(node->right);
                if(breakFlag){ breakFlag = 0; break; }
                if(continueFlag){ continueFlag = 0; continue; }
            } while(evaluateCode(node->left));
            return 0;
        }

        case NODE_REPEAT: {
            do {
                evaluateCode(node->right);
                if(breakFlag){ breakFlag = 0; break; }
                if(continueFlag){ continueFlag = 0; continue; }
            } while(!evaluateCode(node->left));
            return 0;
        }

        case NODE_BREAK:
            breakFlag = 1;
            return 0;

        case NODE_CONTINUE:
            continueFlag = 1;
            return 0;
            
        case NODE_CONN: {
            evaluateCode(node->left);
            if(breakFlag || continueFlag) return 0;  // propagate control flow
            evaluateCode(node->right);
            return 0;
        } 

        case NODE_ASSGN: {
            if(node->left->nodetype != NODE_LEAF || node->left->vartype == TYPE_NONE) {
                fprintf(stderr, "Error: Invalid assignment left-hand side\n");
                exit(1);
            }

            int val = evaluateCode(node->right);
            ASTNode* var = node->left;
            char varname = *(var->varname);
            int idx = varname - 'a';
            memory[idx] = val;
            return memory[idx];
        }

        case NODE_ADD : return evaluateCode(node->left) + evaluateCode(node->right);
        case NODE_SUB : return evaluateCode(node->left) - evaluateCode(node->right);
        case NODE_MUL : return evaluateCode(node->left) * evaluateCode(node->right);
        case NODE_DIV : {
            int i = evaluateCode(node->left);
            int j = evaluateCode(node->right);
            if(j == 0) {
                fprintf(stderr, "Error: Division by zero\n");
                exit(1);
            }
            return i / j;
        }

        case NODE_LT: return evaluateCode(node->left) < evaluateCode(node->right);
        case NODE_GT: return evaluateCode(node->left) > evaluateCode(node->right);
        case NODE_LE: return evaluateCode(node->left) <= evaluateCode(node->right);
        case NODE_GE: return evaluateCode(node->left) >= evaluateCode(node->right);
        case NODE_NE: return evaluateCode(node->left) != evaluateCode(node->right);
        case NODE_EQ: return evaluateCode(node->left) == evaluateCode(node->right);

        default:
            fprintf(stderr, "Error: Unknown operation node type %d\n", node->nodetype);
            exit(1);
    }
    return 0;
}

int evaluate(ASTNode *root) {
    initializeMemory();
    evaluateCode(root);
    printf("Program exited.\n");
    return 0;
}