%{

#include <stdio.h>
#include <stdlib.h>
// $1 means the position of the token in the production, here DIGIT is the 1st and only token in the production and hence $1 is used to refer to its attribute

%}

%token DIGIT
%left '+'
%left '*'

%%
start : expr '\n'  {printf("\nComplete\n");exit(1);}
 ;

expr:  expr '+' expr  {printf("+ ");}
 | expr '*' expr  {printf("* ");}
 | '(' expr ')'
 | DIGIT   {printf("%d ",$1);}
 ;

%%

yyerror()
{
 printf("Error");
}

yylex()
{
 int c;
 c = getchar();
 if(isdigit(c))
 {
  yylval = c - '0';
  return DIGIT;

 }
 return c;
}

main()
{
 yyparse();
 return 1;
}