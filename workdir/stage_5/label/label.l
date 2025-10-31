%{
    #include <stdio.h>
    #include <string.h>
    #include "label.h"
    
    int step = 0;
    int addr = 2040;
    FILE* label_file = NULL;
    FILE* output_file = NULL;

%}

label   _L[0-9]+
flabel  _F[0-9]+
main    _MAIN
exit    _EXIT

%%
{label}:\n      {
                    if(step == 0){
                        int len = yyleng - 2;
                        char* label = strndup(yytext, len);
                        createLabel(label, addr);
                    }
                }

{flabel}:\n     {
                    if(step == 0){
                        int len = yyleng - 2;
                        char* label = strndup(yytext, len);
                        createLabel(label, addr);
                    }
                }

{main}:\n       {
                    if(step == 0){
                        char* label = strdup("_MAIN");
                        createLabel(label, addr);
                    }
                }

{exit}:\n       {
                    if(step == 0){
                        char* label = strdup("_EXIT");
                        createLabel(label, addr);
                    }
                }

{label}         {
                    if(step == 1){
                        int address = getLabelAddr(yytext);
                        fprintf(output_file, "%d", address);
                    }
                }

{flabel}        {
                    if(step == 1){
                        int address = getLabelAddr(yytext);
                        fprintf(output_file, "%d", address);
                    }
                }

{main}          {
                    if(step == 1){
                        int address = getLabelAddr(yytext);
                        fprintf(output_file, "%d", address);
                    }
                }

{exit}          {
                    if(step == 1){
                        int address = getLabelAddr(yytext);
                        fprintf(output_file, "%d", address);
                    }
                }

(.)             {
                    if(step == 1){
                        fprintf(output_file, "%c", *yytext);
                    }
                }

\n              {
                    if(step == 0){
                        addr += 2;
                    }
                    else {
                        fprintf(output_file, "\n");
                    }
                }
%%

int yywrap(){
    if(step == 0){
        rewind(yyin);
        step = 1;
        return 0;
    }
    return 1;
}

int main(int argc, char* argv[]){
    label_file = fopen(argv[1], "r");
    output_file = fopen(argv[2], "w");

    if(label_file == NULL || output_file == NULL){
        printf("Error opening file: label/output\n");
        exit(1);
    }

    yyin = label_file;
    yylex();
    return 0;
}