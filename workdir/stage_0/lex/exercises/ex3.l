%{
	#include <stdio.h>
	int cnt = 0;
%}

word A[a-zA-Z]+

%option noyywrap

%%
{word}      {   if(yyleng == 3){
                    // this prints only the word with length 3 and starting with A
                    printf("%s ", yytext);
                    cnt++;
                } 
            }
[\t\n]      { }    
.           { }
%%


int main(int argc, char *argv[]){
	if (argc > 1)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;

    yylex();
	yylex();
	printf("\nWords: %d\n", cnt);
	return 1;
}