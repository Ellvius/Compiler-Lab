%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "../parser/y.tab.h"
    #include "../exprtree/exprtree.h"
    int yyerror(const char *s);

    int val;
%}

%%

"begin"     { return START_BLOCK; }
"end"       { return END_BLOCK; }
"if"        { return IF; }
"then"      { return THEN; }
"else"      { return ELSE;}    
"endif"     { return ENDIF; }
"while"     { return WHILE; }
"do"        { return DO; }
"endwhile"  { return ENDWHILE; }

"<="        { return LE; }
">="        { return GE; }
"!="        { return NE; }
"=="        { return EQ; }
"<"         { return LT; }
">"         { return GT; }

[0-9]+      { val = atoi(yytext); yylval.node = makeLeafNode(val, TYPE_INT, NULL); return NUM;}
[a-z]       { yylval.node = makeLeafNode(0, TYPE_INT, strdup(yytext)); return ID;}

"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MUL; }
"/"         { return DIV; }
"="         { return ASSGN; }
";"         { return EOS; }
"read"      { return READ; }
"write"     { return WRITE; }

[ \t\n]     { }
[()]        { return *yytext; }
.           { yyerror("unknown character\n"); exit(1);}

%%

int yywrap(void) {
    return 1;
}