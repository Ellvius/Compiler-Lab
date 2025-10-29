%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "../symboltable/symboltable.h"

    extern FILE *yyin;
    VarType currentType = TYPE_NONE;

    int yylex(void);
    int yyerror(const char *s);

%}

%union{
    int idType;
    char* idName;
    int intVal;
    char* strVal;
}

%token START_BLOCK END_BLOCK DECL ENDDECL READ WRITE MAIN RETURN
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE REPEAT UNTIL
%token BREAK CONTINUE
%token PLUS MINUS STAR DIV MOD
%token LT GT LE GE NE EQ AND OR NOT
%token ASSGN EOS COMMA ADDR
%token INT STR
%token <intVal> NUM
%token <strVal> STRING
%token <idName> ID
%type <idType> Type

%left OR
%left AND
%right NOT

%right ASSGN
%nonassoc NE EQ
%nonassoc LT LE GT GE
%left PLUS MINUS
%left STAR DIV MOD

%%

/*----------------------------------------------------------------------------------------------------*/

Program     :   GDeclBlock FDefBlock MainBlock      {
                                                        printGST();
                                                        fprintf(stdout,"parsing successful!\n");
                                                    }
            |   GDeclBlock MainBlock                {}
            |   MainBlock                           {}
            ;

GDeclBlock  :   DECL GDeclList ENDDECL              {}
            |   DECL ENDDECL
            ;

GDeclList   :   GDeclList GDecl
            |   GDecl
            ;

GDecl       :   Type GidList EOS
            ;

GidList     :   GidList COMMA Gid
            |   Gid
            ;

Gid         :   ID '(' ParamList ')'        {
                                                GInstall($1, currentType, -1, -1, -1, Phead);
                                            }
            |   ID '['NUM']' '['NUM']'      {
                                                GInstall($1, currentType, $3*$6, $3, $6, NULL);
                                            }               
            |   ID '['NUM']'                {
                                                GInstall($1, currentType, $3, $3, -1, NULL);
                                            }              
            |   STAR ID                     {
                                                VarType ptrType = currentType == TYPE_INT ?
                                                TYPE_INT_PTR : TYPE_STR_PTR; 
                                                GInstall($2, ptrType, 1, -1, -1, NULL);
                                            }              
            |   ID                          {
                                                GInstall($1, currentType, 1, -1, -1, NULL);
                                            }       
            ;
            
/*----------------------------------------------------------------------------------------------------*/

FDefBlock   :   FDefBlock FDef 
            |   FDef
            ;


FDef        :   Type ID '(' ParamList ')'       {
                                                    PInstallLST($2);    // Insert params to Local symbol Table
                                                    freeParamList();    // Free the unwanted paramlist formed from the Fdef block, we will use the paramlist from GST
                                                }
                '{' LDeclBlock Body '}'         {
                                                    printLST($2);
                                                    FreeLST();
                                                }
            ;

ParamList   :   ParamList COMMA Param 
            |   Param
            | /*param can be empty*/
            ;

Param       :   Type ID              {PInstall($2, currentType);}
            ;

/*----------------------------------------------------------------------------------------------------*/

LDeclBlock  : DECL LDecList ENDDECL         
            | DECL ENDDECL
            ;

LDecList    : LDecList LDecl 
            | LDecl
            ;

LDecl       : Type LidList EOS
            ;

LidList     : LidList COMMA Lid
            | Lid
            ;

Lid         :   STAR ID                         {
                                                    VarType ptrType = currentType == TYPE_INT ?
                                                    TYPE_INT_PTR : TYPE_STR_PTR; 
                                                    LInstall($2, ptrType);
                                                }        
            |   ID                              {
                                                    LInstall($1, currentType);
                                                }        
            ;


Type        :   INT                     {currentType = TYPE_INT; $$ = TYPE_INT;}
            |   STR                     {currentType = TYPE_STR; $$ = TYPE_STR;}
            ;

/*----------------------------------------------------------------------------------------------------*/

MainBlock   :   Type MAIN '('')' '{' LDeclBlock Body '}'    {
                                                                printLST("main");
                                                                FreeLST();
                                                            }
            ;

Body        :   START_BLOCK SList RetStmt END_BLOCK         
            |   START_BLOCK END_BLOCK                
            ;

RetStmt     :   RETURN Expr EOS
            ;

SList       :   SList Stmt              {}
            |   Stmt                    {}
            ;

Stmt        :   IfStmt                  {}
            |   IterativeStmt           {}
            |   InputStmt               {}
            |   OutputStmt              {}
            |   AsgStmt                 {}
            |   BreakStmt               {}
            |   ContinueStmt            {}
            ;

/*----------------------------------------------------------------------------------------------------*/

IfStmt      :   IF '(' Expr ')' THEN SList ELSE SList ENDIF EOS     {}
            |   IF '(' Expr ')' THEN SList ENDIF EOS                {}
            ;

IterativeStmt   :   WHILE '(' Expr ')' DO SList ENDWHILE EOS        {}
                |   DO SList WHILE '(' Expr ')' EOS                 {}
                |   REPEAT SList UNTIL '(' Expr ')' EOS             {}
                ;

InputStmt   :   READ '(' Identifier ')' EOS             {}
            ;

OutputStmt  :   WRITE '(' Expr ')' EOS                  {}
            ;

AsgStmt     :   Identifier ASSGN Expr EOS               {}
            |   Identifier ASSGN ADDR Identifier EOS    {}
            ;

BreakStmt   :   BREAK EOS               {}
            ;

ContinueStmt:   CONTINUE EOS            {}
            ;

/*----------------------------------------------------------------------------------------------------*/

Expr        :   Expr PLUS Expr          {}
            |   Expr MINUS Expr         {}
            |   Expr STAR Expr          {}
            |   Expr DIV Expr           {}
            |   Expr MOD Expr           {}
            |   '(' Expr ')'            {}
            |   Expr AND Expr           {}
            |   Expr OR Expr            {}
            |   NOT Expr                {}
            |   Expr LT Expr            {}
            |   Expr GT Expr            {}
            |   Expr LE Expr            {}
            |   Expr GE Expr            {}
            |   Expr NE Expr            {}
            |   Expr EQ Expr            {}
            |   Identifier              {}
            |   NUM                     {}
            |   STRING                  {}
            ;

Identifier  :   ID'('')'                    {}
            |   ID'(' ArgList ')'           {}
            |   ID '['Expr']' '['Expr']'    {}
            |   ID '['Expr']'               {}
            |   ID                          {}
            |   STAR ID                     {}
            ;

ArgList     :   ArgList COMMA Expr
            |   Expr
            ;

%%

int yyerror(const char *s){
    printf("yyerror %s\n",s);
    exit(1);
}


int main(int argc, char* argv[]){
    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            printf("Couldn't find the input file!\n");
            return 1;
        }
    }
    else {
        yyin = stdin;
    }
    
    yyparse();

    if(yyin != stdin) fclose(yyin);
    return 0;
}