%{
    #include<stdio.h>
    #include<stdlib.h>
    int yyerror();
    int yylex();
%}

%union {
    char character;
}

%token <character> CHAR

%left '+'
%left '*'

%%

start   :   expr '\n'           {   printf("\nComplete\n");
                                    exit(0);
                                }
        ;

expr    :   expr '*' expr       {printf("*");}
        |   expr '+' expr       {printf("+");}
        |   '(' expr ')'        { }
        |   CHAR                {printf("%c", $<character>1);}
        ;

%%

int yyerror(){
    printf("\nError\n");
}

int main(){
    yyparse();
    return 1;
}