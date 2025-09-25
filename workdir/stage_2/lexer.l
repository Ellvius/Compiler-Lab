%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "y.tab.h"
    #include "exprtree.h"
    int yyerror(const char *s);

    int val;
%}

%%

[0-9]+      {val = atoi(yytext); yylval.node = makeLeafNode(val, TYPE_NONE, NULL); return NUM;}
[a-z]       {yylval.node = makeLeafNode(0, TYPE_NUM, strdup(yytext)); return ID;}
"+"         {return PLUS;}
"-"         {return MINUS;}
"*"         {return MUL;}
"/"         {return DIV;}
"="         {return ASSGN;}
";"         {return EOS;}
"begin"     {return START_BLOCK;}
"end"       {return END_BLOCK;}
"read"      {return READ;}
"write"     {return WRITE;}
[ \t\n]     {}
[()]        {return *yytext;}
.           {yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
    return 1;
}