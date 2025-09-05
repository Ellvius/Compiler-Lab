%{
    #include<stdio.h>
    int cnt = 0;
%}

LETTERS [a-zA-Z]+
DIGITS [0-9]+

%%
{LETTERS}({LETTERS}|{DIGITS})*  {   printf("%s ", yytext);
                                    cnt++;
                                }
.                               {}
%%

int main(int argc, char *argv[]){
    if(argc > 1)
        yyin = fopen(argv[1], "r");
    else 
        yyin = stdin;
    
    yylex();
    printf("\nTotal number of identifiers: %d\n", cnt);
    return 0;
}

int yywrap(){
    return 1;
}