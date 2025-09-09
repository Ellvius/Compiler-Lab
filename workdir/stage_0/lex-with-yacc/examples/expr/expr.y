%{
    #include <stdio.h>
    int yyerror();
    int yylex();
%}

%union {
    int ival;
}

%token <ival> DIGIT
%type <ival> expr

%left '+'
%left '*'

%%

start   :   expr '\n'               { printf("Expression value = %d\n",$1);} 
        ;

expr    :   expr '+' expr           {$$ = $1 + $3;}
        |   expr '*' expr           {$$ = $1 * $3;}
        |   '(' expr ')'            {$$ = $2;}
        |   DIGIT                   {$$ = $1;}
        ;

%%

int yyerror(){
    printf("\nError\n");
}

int main(){
    yyparse();
    return 1;
}