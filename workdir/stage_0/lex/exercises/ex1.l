%{
	#include <stdio.h>
	int lines=0;
	int words=0;
	int chars=0;
%}

word [a-zA-Z]+
line "\n"

%option noyywrap

%%
{word}		{
			words+=1;
			chars+=yyleng;
            // use yyleng to find the number of characters
		}

{line}		{
			lines+=1;
		}
%%


int main(int argc, char *argv[]){
	if (argc > 1)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;
	yylex();
    if(words > 0 && lines == 0) lines++;
	printf("\nLines:%d\nWords:%d\nCharacters:%d\n",lines,words,chars);
	return 1;
}