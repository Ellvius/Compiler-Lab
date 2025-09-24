%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "expr.h"

    extern FILE *yyin;

    int yylex(void);
    int yyerror(const char *s);

%}

%union{
    struct tnode *no;
}

%token PLUS
%token <no> NUM END
%type <no> expr program

%left PLUS

%%

program :   expr END            {
                                    $$ = $1;
                                    printf("Prefix: ");
                                    prefixForm($1);
                                    printf("\n");
                                    printf("Postfix: ");
                                    postfixForm($1);
                                    printf("\n");
                                    exit(0);
                                }
        ;

expr    :   expr PLUS expr      {$$ = makeOperatorNode('+',$1,$3);}
        |   '(' expr ')'        {$$ = $2;}
        |   NUM                 {$$ = $1;}
        ;

%%

int yyerror(char const *s){
    printf("yyerror %s",s);
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