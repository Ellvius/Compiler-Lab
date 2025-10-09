%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "../abstree/abstree.h"
    #include "../codeGen/codeGen.h"
    #include "../symboltable/symboltable.h"

    extern FILE *yyin;
    VarType currentType = TYPE_NONE;

    int yylex(void);
    int yyerror(const char *s);

%}

%union{
    struct ASTNode *node;
    struct Gsymbol *stEntry;
    int idType;
    char* idName;
    int intVal;
    char* strVal;
}

%token START_BLOCK END_BLOCK DECL ENDDECL READ WRITE 
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE REPEAT UNTIL
%token BREAK CONTINUE
%token PLUS MINUS MUL DIV
%token LT GT LE GE NE EQ
%token ASSGN EOS COMMA
%token INT STR
%token <intVal> NUM
%token <strVal> STRING
%token <idName> ID
%type <node> Expr Program Slist Stmt Code
%type <stEntry> VarList
%type <idType> Type
%type <node> InputStmt OutputStmt AsgStmt IfStmt IterativeStmt
%type <node> BreakStmt ContinueStmt

%right ASSGN
%nonassoc NE EQ
%nonassoc LT LE GT GE
%left PLUS MINUS
%left MUL DIV

%%

Program     :   Declarations Code                   {
                                                        $$ = $2;
                                                        printSymbolTable();
                                                        // codeGen($2);
                                                        exit(0);
                                                    }

Code        :   START_BLOCK Slist END_BLOCK         {
                                                        $$ = $2;
                                                    }
            |   START_BLOCK END_BLOCK               {
                                                        fprintf(stdout, "Empty program\n");
                                                        exit(0);
                                                    }  
            ;

Slist       :   Slist Stmt              {$$ = makeConnNode($1, $2);}
            |   Stmt                    {$$ = $1;}
            |   Declarations            {}
            ;

Stmt        :   IfStmt                  {$$ = $1;}
            |   IterativeStmt           {$$ = $1;}
            |   InputStmt               {$$ = $1;}
            |   OutputStmt              {$$ = $1;}
            |   AsgStmt                 {$$ = $1;}
            |   BreakStmt               {$$ = $1;}
            |   ContinueStmt            {$$ = $1;}
            ;

Declarations:   DECL DeclList ENDDECL   {}
            |   DECL ENDDECL            {}
            ;

DeclList    :   DeclList Decl           {}
            |   Decl                    {}
            ;

Decl        :   Type VarList EOS        {}
            ;

Type        :   INT                     {currentType = TYPE_INT; $$ = TYPE_INT;}
            |   STR                     {currentType = TYPE_STR; $$ = TYPE_STR;}
            ;

VarList     :   VarList COMMA ID                {GInstall($3, currentType, 1);}
            |   VarList COMMA ID '['NUM']'      {GInstall($3, currentType, $5);} 
            |   ID '['NUM']'                    {GInstall($1, currentType, $3);}
            |   ID                              {GInstall($1, currentType, 1);}
            ;

IfStmt      :   IF '(' Expr ')' THEN Slist ELSE Slist ENDIF EOS     {$$ = makeIfElseNode($3, $6, $8);}
            |   IF '(' Expr ')' THEN Slist ENDIF EOS                {$$ = makeIfElseNode($3, $6, NULL);}
            ;

IterativeStmt   :   WHILE '(' Expr ')' DO Slist ENDWHILE EOS        {$$ = makeIterationNode(NODE_WHILE, $3, $6);}
                |   DO Slist WHILE '(' Expr ')' EOS                 {$$ = makeIterationNode(NODE_DOWHILE, $5, $2);}
                |   REPEAT Slist UNTIL '(' Expr ')' EOS             {$$ = makeIterationNode(NODE_REPEAT, $5, $2);}
                ;

InputStmt   :   READ '(' ID ')' EOS                 {
                                                        ASTNode* id = makeLeafNode(0, NULL, TYPE_ID, $3);
                                                        $$ = makeReadNode(id);
                                                    }
            |   READ '(' ID '['Expr']' ')' EOS      {
                                                        ASTNode* id = makeLeafNode(0, NULL, TYPE_ID, $3);
                                                        $$ = makeReadNode(id);
                                                    }
            ;

OutputStmt  :   WRITE '(' Expr ')' EOS  {$$ = makeWriteNode($3);}
            ;

AsgStmt     :   ID ASSGN Expr EOS                   {
                                                        ASTNode* id = makeLeafNode(0, NULL, TYPE_ID, $1);
                                                        $$ = makeAssgnNode(id, $3);
                                                    }
            |   ID '['Expr']' ASSGN Expr EOS        {
                                                        ASTNode* id = makeLeafNode(0, NULL, TYPE_ID, $1);
                                                        $$ = makeAssgnNode(id, $3);
                                                    }
            ;

BreakStmt   :   BREAK EOS               {$$ = makeBreakNode();}
            ;

ContinueStmt:   CONTINUE EOS            {$$ = makeContinueNode();}
            ;

Expr        :   Expr PLUS Expr          {$$ = makeArithOPNode(NODE_ADD, $1, $3);}
            |   Expr MINUS Expr         {$$ = makeArithOPNode(NODE_SUB, $1, $3);}
            |   Expr MUL Expr           {$$ = makeArithOPNode(NODE_MUL, $1, $3);}
            |   Expr DIV Expr           {$$ = makeArithOPNode(NODE_DIV, $1, $3);}
            |   '(' Expr ')'            {$$ = $2;}
            |   Expr LT Expr            {$$ = makeRelOPNode(NODE_LT, $1, $3);}
            |   Expr GT Expr            {$$ = makeRelOPNode(NODE_GT, $1, $3);}
            |   Expr LE Expr            {$$ = makeRelOPNode(NODE_LE, $1, $3);}
            |   Expr GE Expr            {$$ = makeRelOPNode(NODE_GE, $1, $3);}
            |   Expr NE Expr            {$$ = makeRelOPNode(NODE_NE, $1, $3);}
            |   Expr EQ Expr            {$$ = makeRelOPNode(NODE_EQ, $1, $3);}
            |   NUM                     {$$ = makeLeafNode($1, NULL, TYPE_INT, NULL);}
            |   STRING                  {$$ = makeLeafNode(0, $1, TYPE_STR, NULL);}
            |   ID '['Expr']'           {$$ = makeArrayNode($1, TYPE_ID, $3);}
            |   ID                      {$$ = makeLeafNode(0, NULL, TYPE_ID, $1);}
            ;

%%

int yyerror(const char *s){
    printf("yyerror %s\n",s);
    exit(1);
}


int main(int argc, char* argv[]){
    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            printf("Couldn't find the input file!\n");
            return 1;
        }
    }
    else {
        yyin = stdin;
    }
    
    yyparse();

    if(yyin != stdin) fclose(yyin);
    return 0;
}