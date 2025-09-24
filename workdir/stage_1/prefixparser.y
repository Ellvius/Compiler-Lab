%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "./exprtree/exprtree.h"

    extern FILE *yyin;

    int yylex(void);
    int yyerror(const char *s);

%}

%union{
    struct tnode *node;
}

%token PLUS MINUS MUL DIV
%token <node> NUM END
%type <node> E PRGM

%left PLUS MINUS
%left MUL DIV

%%

PRGM    :   E END           {
                                    $$ = $1;
                                    codeGen($1);
                                    exit(0);
                            }
        ;

E       :   PLUS E E        {$$ = makeOperatorNode('+',$2,$3);}
        |   MINUS E E       {$$ = makeOperatorNode('-',$2,$3);}
        |   MUL E E         {$$ = makeOperatorNode('*',$2,$3);}
        |   DIV E E         {$$ = makeOperatorNode('/',$2,$3);}
        |   '(' E ')'       {$$ = $2;}
        |   NUM             {$$ = $1;}
        ;

%%

int yyerror(char const *s){
    printf("yyerror %s\n",s);
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