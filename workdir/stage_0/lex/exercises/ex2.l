%{
	#include <stdio.h>
	int int_cnt = 0;
    int float_cnt = 0;
%}

int_num [0-9]+
float_num [0-9]+"."[0-9]+
line "\n"

%option noyywrap

%%
{int_num}   {int_cnt++;
             printf("%s ", yytext);}
{float_num} {float_cnt++;
             printf("%s ", yytext);}
.           { }
{line}      { }
%%


int main(int argc, char *argv[]){
    if (argc > 1)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;	yylex();
	printf("\nIntegers: %d\nFloats: %d\n", int_cnt, float_cnt);
	return 1;
}