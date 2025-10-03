%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "../exprtree/exprtree.h"
    #include "../evaluator/evaluator.h"

    extern FILE *yyin;

    int yylex(void);
    int yyerror(const char *s);

%}

%union{
    struct tnode *node;
}

%token START_BLOCK END_BLOCK READ WRITE 
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE REPEAT UNTIL
%token BREAK CONTINUE
%token PLUS MINUS MUL DIV
%token LT GT LE GE NE EQ
%token ASSGN EOS
%token <node> NUM ID
%type <node> Expr Program Slist Stmt
%type <node> InputStmt OutputStmt AsgStmt IfStmt IterativeStmt
%type <node> BreakStmt ContinueStmt

%right ASSGN
%nonassoc LT LE GT GE
%nonassoc NE EQ
%left PLUS MINUS
%left MUL DIV

%%

Program     :   START_BLOCK Slist END_BLOCK EOS     {
                                                        $$ = $2;
                                                        evaluate($2);
                                                        exit(0);
                                                    }
            |   START_BLOCK END_BLOCK EOS           {
                                                        fprintf(stdout, "Empty program\n");
                                                        exit(0);
                                                    }  
            ;

Slist       :   Slist Stmt              {$$ = makeConnNode($1, $2);}
            |   Stmt                    {$$ = $1;}
            ;

Stmt        :   IfStmt                  {$$ = $1;}
            |   IterativeStmt           {$$ = $1;}
            |   InputStmt               {$$ = $1;}
            |   OutputStmt              {$$ = $1;}
            |   AsgStmt                 {$$ = $1;}
            |   BreakStmt               {$$ = $1;}
            |   ContinueStmt            {$$ = $1;}
            ;

IfStmt      :   IF '(' Expr ')' THEN Slist ELSE Slist ENDIF EOS     {$$ = makeIfElseNode($3, $6, $8);}
            |   IF '(' Expr ')' THEN Slist ENDIF EOS                {$$ = makeIfElseNode($3, $6, NULL);}
            ;

IterativeStmt   :   WHILE '(' Expr ')' DO Slist ENDWHILE EOS        {$$ = makeIterationNode(NODE_WHILE, $3, $6);}
                |   DO Slist WHILE '(' Expr ')' EOS                 {$$ = makeIterationNode(NODE_DOWHILE, $5, $2);}
                |   REPEAT Slist UNTIL '(' Expr ')' EOS             {$$ = makeIterationNode(NODE_REPEAT, $5, $2);}
                ;

InputStmt   :   READ '(' ID ')' EOS     {$$ = makeReadNode($3);}
            ;

OutputStmt  :   WRITE '(' Expr ')' EOS  {$$ = makeWriteNode($3);}
            ;

AsgStmt     :   ID ASSGN Expr EOS       {$$ = makeAssgnNode($1, $3);}
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
            |   NUM                     {$$ = $1;}
            |   ID                      {$$ = $1;}
            ;

%%

int yyerror(char const *s){
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