%{
    #include "y.tab.h"
    #include <stdio.h>
%}

%%

[0-9]+  {
          yylval.ival = atoi(yytext);
          return DIGIT;
        }
"+"     {return *yytext;}
"*"     {return *yytext;}
[()]    {return *yytext;}
[\n]    {return '\n';}

%%

int yywrap(){
    return 1;
}