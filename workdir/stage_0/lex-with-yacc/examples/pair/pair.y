%{
    #include <stdio.h>
    #include <stdlib.h>
    int yyerror();
    int yylex(void);
%}

%union {
    int ival;
}

%token <ival> DIGIT
%type <ival> num

%%
start   :   pair '\n'         {printf("\nComplete\n"); exit(0);}
        ;

pair    :   num ',' num       { printf("pair(%d,%d)",$1,$3); }
        ;

num     :   DIGIT             { $$=$1; }
        ;
%%

int yyerror(){
    printf("\nError\n");
}

int main(){
    yyparse();
    return 0;
}
