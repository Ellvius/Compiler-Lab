%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "../parser/y.tab.h"
    #include "../abstree/abstree.h"
    int yyerror(const char *s);

    int val;
%}

letter  [a-zA-Z]
digit   [0-9]

%%

"begin"     { return START_BLOCK; }
"end"       { return END_BLOCK; }
"decl"      { return DECL; }
"enddecl"   { return ENDDECL; }

"read"      { return READ; }
"write"     { return WRITE; }

"if"        { return IF; }
"then"      { return THEN; }
"else"      { return ELSE;}    
"endif"     { return ENDIF; }

"while"     { return WHILE; }
"do"        { return DO; }
"endwhile"  { return ENDWHILE; }
"repeat"    { return REPEAT; }
"until"     { return UNTIL; }
"break"     { return BREAK; }
"continue"  { return CONTINUE; }

"int"       { return INT; }
"str"       { return STR; }

"<="        { return LE; }
">="        { return GE; }
"!="        { return NE; }
"=="        { return EQ; }
"<"         { return LT; }
">"         { return GT; }

{digit}+                            { yylval.intVal = atoi(yytext); return NUM;}
{letter}({letter}|{digit})*         { yylval.idName = strdup(yytext); return ID;}

"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MUL; }
"/"         { return DIV; }
"="         { return ASSGN; }
";"         { return EOS; }
","         { return COMMA; }

[ \t\n]     { }
[()]        { return *yytext; }
.           { 
                yyerror("unknown character "); 
                fprintf(stdout, "%c\n", *yytext);
                exit(1);
            }

%%

int yywrap(void) {
    return 1;
}