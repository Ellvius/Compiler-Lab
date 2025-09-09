%{
  #include "y.tab.h"
  #include<stdlib.h>
  #include<stdio.h>
%}

number  [0-9]+

%%

{number}    {
                yylval.ival = atoi(yytext);
                return DIGIT;
            }

.           {   return *yytext;}

\n          { return '\n'; }

%%

int yywrap() {
    return 1;
}
