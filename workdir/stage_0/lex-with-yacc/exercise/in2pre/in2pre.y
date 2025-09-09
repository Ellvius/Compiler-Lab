%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    int yyerror();
    int yylex();
%}

%union {
    char* s;
}

%token <s> SYMBOL
%type <s> expr

%left '+'
%left '*'

%%

start   :   expr '\n'           {   
                                    printf("%s", $<s>1);
                                    printf("\nComplete\n");
                                    exit(0);
                                }
        ;

expr    :   expr '*' expr       {
                                    char *buf = malloc(strlen($<s>1) + strlen($<s>3) + 5);
                                    sprintf(buf, "* %s %s ", $<s>1, $<s>3);
                                    $<s>$ = buf;
                                    free($<s>1);
                                    free($<s>3);
                                }
        |   expr '+' expr       {
                                    char *buf = malloc(strlen($<s>1) + strlen($<s>3) + 5);
                                    sprintf(buf, "+ %s %s ", $<s>1, $<s>3);
                                    $<s>$ = buf;
                                    free($<s>1);
                                    free($<s>3);
                                }
        |   '(' expr ')'        {$<s>$ = $<s>2; }
        |   SYMBOL              {$<s>$ = $<s>1;}
        ;

%%

int yyerror(){
    printf("\nError\n");
}

int main(){
    yyparse();
    return 1;
}