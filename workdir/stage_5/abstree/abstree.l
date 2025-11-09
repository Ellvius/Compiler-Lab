%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "y.tab.h"
    int yyerror(const char *s);
%}

digit           [0-9]
letter          [a-zA-Z]
identifier      {letter}({letter}|{digit})*
string          \"(\\.|[^\\\"])*\"
SINGLE \/\/.*
MULTILINE \/\*([^*]|\*[^\/])*\*\/

%%

"begin"     { return START_BLOCK; }
"end"       { return END_BLOCK; }
"decl"      { return DECL; }
"enddecl"   { return ENDDECL; }
"main"      { return MAIN; }
"return"    { return RETURN; }

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
"tuple"     { return TUPLE; }

"OR"        { return OR; }
"AND"       { return AND; }
"NOT"       { return NOT; }

"||"        { return OR; }
"&&"        { return AND; }
"!"         { return NOT; }

"<="        { return LE; }
">="        { return GE; }
"!="        { return NE; }
"=="        { return EQ; }
"<"         { return LT; }
">"         { return GT; }

{digit}+            { 
                        yylval.intVal = atoi(yytext); 
                        return NUM;
                    }

{identifier}        { 
                        yylval.idName = strdup(yytext); 
                        return ID;
                    }

{string}            {
                        size_t  len = strlen(yytext);
                        if(len < 2) {
                            yyerror("empty string literal");
                        }
                        yylval.strVal = strndup(yytext+1, len-2);
                        return STRING;
                    }

{SINGLE}            { }
{MULTILINE}         { }

"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return STAR; }
"/"         { return DIV; }
"%"         { return MOD; }
"="         { return ASSGN; }
";"         { return EOS; }
","         { return COMMA; }
"&"         { return ADDR; }
"."         { return DOT; }

[ \t\n]     { }
[()\[\]{}]        { return *yytext; }
.           { 
                fprintf(stderr, "Unknown character: %c\n", *yytext);
                exit(1);
            }

%%

int yywrap(void) {
    return 1;
}