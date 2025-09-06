%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include <ctype.h>

    int maxLevel = 0;
%}

%union {
    int ival;   // integer values for nesting depth
}

%token IF ELSE THEN ID NUM RELOP
%type <ival> stmt cond var
%nonassoc RELOP
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%left '+'
%left '*'

%%

start   :   stmt '\n'                                   {
                                                            printf("\nMaximum nesting level = %d\n", maxLevel);
                                                            exit(0);
                                                        }
        ;

stmt    :   '(' stmt ')'                                { $$ = $2; }
        |   IF cond THEN stmt ELSE stmt                 {   
                                                            int depth = 1 + ($4 > $6 ? $4 : $6); // greater of the nested stmts
                                                            if(depth > maxLevel) maxLevel = depth;
                                                            $$ = depth;
                                                        }
        |   IF cond THEN stmt %prec LOWER_THAN_ELSE     {
                                                            int depth = 1 + $4;
                                                            if(depth > maxLevel) maxLevel = depth;
                                                            $$ = depth;
                                                        }
        |   var '+' var                                 { $$ = 0; }
        |   var '*' var                                 { $$ = 0; }
        ;

cond    :   var RELOP var                               { $$ = 0; }
        ;

var     :   ID                                          { $$ = 0; }
        |   NUM                                         { $$ = 0; }
        ;
            
%%

int yyerror(const char *s) {
    printf("Error: %s\n", s);
    return 0;
}

int yylex() {
    int c;

    // skip whiteline characters except newline
    while((c = getchar()) == ' ' || c == '\t');

    if(c == EOF) return 0;

    // single characters
    if(c == '\n' || c == '+' || c == '*' || c == '(' || c == ')')
        return c; 
        
    // relational operators
    if(c == '<' || c == '>' || c == '!' || c == '='){
        int next = getchar();
        if(next == '='){
            return RELOP;
        }
        else {
            ungetc(next, stdin);
            if(c == '>' || c == '<') return RELOP;
        }
    }

    // numbers
    if(isdigit(c)){
        int num = c - '0';
        while(isdigit(c = getchar())){
            num = num * 10 + (c - '0');
        }
        ungetc(c, stdin);
        return NUM;
    }

    // identifiers and keywords
    if(isalpha(c)){
        char buffer[100];
        int i = 0;
        buffer[i++] = c;

        while(isalnum(c = getchar())){
            buffer[i++] = c;
        }
        buffer[i] = '\0';
        ungetc(c, stdin);

        if(strcmp(buffer, "if") == 0) return IF;
        if(strcmp(buffer, "else") == 0) return ELSE;
        if(strcmp(buffer, "then") == 0) return THEN;

        return ID;
    }

    return c;
}

int main() {
    printf("Enter program:\n");
    yyparse();
    return 0;
}
