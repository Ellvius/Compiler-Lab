%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>
%}

%token LETTER DIGIT

%%
    start   : variable '\n' {printf("Valid variable\n"); exit(1)}
            ;

    variable    : LETTER rest
                ;

    rest    : LETTER rest
            | DIGIT rest
            | 
            ;
%%

int yylex(){
    char c;

    while((c=getchar())== ' ' || c == '\t')
        ;   // spin till there is a whitespace

    if(c==EOF) return 0;

    if(isalpha(c)) return LETTER;
    if(isdigit(c)) return DIGIT;
    return c;
}

int yyerror(const char *c){
    printf("Invalid variable\n", c);
    return 0;
}

int main(){
    yyparse();
    return 0;
}