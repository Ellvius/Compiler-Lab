%{
    #include <stdio.h>
    #include "y.tab.h"
%}

character    [a-zA-Z]

%%

{character}   { yylval.character = *yytext; return CHAR; }
"*"           { return '*'; }
"+"           { return '+'; }
"("           { return '('; }
")"           { return ')'; }
\n            { return '\n'; }
[ \t]         ;  
.             { return *yytext; }

%%

int yywrap(){
    return 1;
}