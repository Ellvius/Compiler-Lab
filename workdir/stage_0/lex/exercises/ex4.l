%{
#include <stdio.h>
%}

SINGLE \/\/.*
MULTILINE \/\*([^*]|\*[^\/])*\*\/

%option noyywrap

%%

{SINGLE}             { printf("Single-line comment: %s\n", yytext); }
{MULTILINE}          { printf("Multi-line comment: %s\n", yytext);
                        // Multiline comment regex : everything except * and if * is there it should not be followed by / (explanation for the middle part of the regex)
                     }

[ \t\n]+               {}
.                      {}

%%

int main(int argc, char *argv[])
{
    if (argc > 1)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;

    yylex();
    return 0;
}
