%{
    #include <stdio.h>
    #include <string.h>
    #include "y.tab.h"
%}

characters      [a-zA-Z_]
number          [0-9]

%%

{characters}({characters}|{number})*    { yylval.string = strdup(yytext); return SYMBOL; }
"*"                                     { return '*'; }
"+"                                     { return '+'; }
"("                                     { return '('; }
")"                                     { return ')'; }
\n                                      { return '\n'; }
[ \t]                                   ;  
.                                       { return *yytext; }

%%

int yywrap(){
    return 1;
}