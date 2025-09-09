%{
    #include<stdio.h>
    #include<stdlib.h>
    int yyerror();
    int yylex();
%}

%union {
    char* string;
}

%token <string> SYMBOL

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
        |   SYMBOL                {printf("%s", $<string>1);}
        ;

%%

int yyerror(){
    printf("\nError\n");
}

int main(){
    yyparse();
    return 1;
}