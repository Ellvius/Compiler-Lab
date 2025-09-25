%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "../exprtree/exprtree.h"
    #include "../codeGen/codeGen.h"

    extern FILE *yyin;

    int yylex(void);
    int yyerror(const char *s);

%}

%union{
    struct tnode *node;
}

%token START_BLOCK END_BLOCK READ WRITE 
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE
%token PLUS MINUS MUL DIV
%token LT GT LE GE NE EQ
%token ASSGN EOS
%token <node> NUM ID
%type <node> Expr Program Slist Stmt
%type <node> InputStmt OutputStmt AsgStmt IfStmt WhileStmt

%right ASSGN
%left PLUS MINUS
%left MUL DIV
%nonassoc LT LE GT GE
%nonassoc NE EQ

%%

Program     :   START_BLOCK Slist END_BLOCK EOS     {
                                                        $$ = $2;
                                                        // codeGen($2);
                                                        exit(0);
                                                    }
            |   START_BLOCK END_BLOCK EOS           {
                                                        fprintf(stdout, "Empty program\n");
                                                        exit(0);
                                                    }  
            ;

Slist       :   Slist Stmt              {$$ = makeOperatorNode(NODE_CONN, $1, $2);}
            |   Stmt                    {$$ = $1;}
            ;

Stmt        :   IfStmt                  {$$ = $1;}
            |   WhileStmt               {$$ = $1;}
            |   InputStmt               {$$ = $1;}
            |   OutputStmt              {$$ = $1;}
            |   AsgStmt                 {$$ = $1;}
            ;

IfStmt      :   IF '(' Expr ')' THEN Slist ELSE Slist ENDIF EOS     {$$ = makeIfElseNode($3, $6, $8);}
            |   IF '(' Expr ')' THEN Slist ENDIF EOS                {$$ = makeIfElseNode($3, $6, NULL);}
            ;

WhileStmt   :   WHILE '(' Expr ')' DO Slist ENDWHILE EOS            {$$ = makeWhileNode($3, $6);}
            ;

InputStmt   :   READ '(' ID ')' EOS     {$$ = makeOperatorNode(NODE_READ, $3, NULL);}
            ;

OutputStmt  :   WRITE '(' Expr ')' EOS  {$$ = makeOperatorNode(NODE_WRITE, $3, NULL);}
            ;

AsgStmt     :   ID ASSGN Expr EOS       {$$ = makeOperatorNode(NODE_ASSGN, $1, $3);}
            ;

Expr        :   Expr PLUS Expr          {$$ = makeOperatorNode(NODE_ADD, $1, $3);}
            |   Expr MINUS Expr         {$$ = makeOperatorNode(NODE_SUB, $1, $3);}
            |   Expr MUL Expr           {$$ = makeOperatorNode(NODE_MUL, $1, $3);}
            |   Expr DIV Expr           {$$ = makeOperatorNode(NODE_DIV, $1, $3);}
            |   '(' Expr ')'            {$$ = $2;}
            |   Expr LT Expr            {$$ = makeOperatorNode(NODE_LT, $1, $3);}
            |   Expr GT Expr            {$$ = makeOperatorNode(NODE_GT, $1, $3);}
            |   Expr LE Expr            {$$ = makeOperatorNode(NODE_LE, $1, $3);}
            |   Expr GE Expr            {$$ = makeOperatorNode(NODE_GE, $1, $3);}
            |   Expr NE Expr            {$$ = makeOperatorNode(NODE_NE, $1, $3);}
            |   Expr EQ Expr            {$$ = makeOperatorNode(NODE_EQ, $1, $3);}
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