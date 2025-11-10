%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "abstree.h"
    #include "../symboltable/symboltable.h"
    // #include "../codeGen/codeGen.h"

    extern FILE *yyin;
    struct TypeTable* DeclType = NULL;
    struct TypeTable* ParamType = NULL;
    struct TypeTable* FieldType = NULL;
    int total_params = 0;

    int yylex(void);
    int yyerror(const char *s);

%}

%union{
    struct ASTNode* node;
    struct TypeTable* idType;
    char* idName;
    int intVal;
    char* strVal;
}

%token START_BLOCK END_BLOCK DECL ENDDECL TYPE ENDTYPE
%token READ WRITE INITIALIZE ALLOC FREE MAIN RETURN
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE REPEAT UNTIL
%token BREAK CONTINUE
%token PLUS MINUS STAR DIV MOD
%token LT GT LE GE NE EQ AND OR NOT
%token ASSGN EOS COMMA ADDR DOT
%token INT STR NULL_T
%token <intVal> NUM
%token <strVal> STRING
%token <idName> ID
%type <idType> DType PType
%type <node> SList Stmt IfStmt IterativeStmt InputStmt OutputStmt AsgStmt Body
%type <node> BreakStmt ContinueStmt Expr Identifier ArgList RetStmt
%type <node> InitializeStmt AllocStmt FreeStmt Field

%left OR
%left AND
%right NOT ADDR
%left DOT

%right ASSGN
%nonassoc NE EQ
%nonassoc LT LE GT GE
%left PLUS MINUS
%left STAR DIV MOD

%%

/*----------------------------------------------------------------------------------------------------*/

Program     :   TypeDefBlock GDeclBlock FDefBlock MainBlock     {
                                                                    printGST();
                                                                    // fprintf(stdout,"parsing successful!\n");
                                                                }
            |   TypeDefBlock GDeclBlock MainBlock               {
                                                                    printGST();
                                                                }
            ;

TypeDefBlock    :   TYPE TypeDefList ENDTYPE    {  printTypeTable();}
                |
                ;

TypeDefList     :   TypeDefList TypeDef
                |   TypeDef
                ;

TypeDef         :   ID '{' FieldDeclList '}'    {TInstall($1, 1, Fhead); Fhead = NULL;}
                ;

FieldDeclList   :   FieldDeclList FieldDecl
                |   FieldDecl       
                ;

FieldDecl       :   DType ID EOS        {FInstall($2, DeclType);}
                |   DType STAR ID EOS   {
                                            struct TypeTable *ptrType = DeclType == TLookup("integer") ?
                                            TLookup("integer_ptr") : TLookup("string_ptr");
                                            FInstall($3, ptrType);
                                        }
                ;

DType       :   INT                 {DeclType = TLookup("integer"); $$ = TLookup("integer");}
            |   STR                 {DeclType = TLookup("string"); $$ = TLookup("string");}
            |   ID                  {
                                        DeclType = TLookup($1); 
                                        $$ = TLookup($1);
                                        if(DeclType == NULL){
                                            DeclType = TLookup("dummy");
                                        }
                                    }
            ;
/*----------------------------------------------------------------------------------------------------*/

GDeclBlock  :   DECL GDeclList ENDDECL   
            |           
            ;

GDeclList   :   GDeclList GDecl
            |   GDecl
            ;

GDecl       :   DType GidList EOS
            ;

GidList     :   GidList COMMA Gid
            |   Gid
            ;

Gid         :   ID '(' ParamList ')'        {GInstall($1, DeclType, -1, -1, -1, Phead);}
            |   ID '['NUM']' '['NUM']'      {GInstall($1, DeclType, $3*$6, $3, $6, NULL);}               
            |   ID '['NUM']'                {GInstall($1, DeclType, $3, $3, -1, NULL);}              
            |   STAR ID                     {
                                                struct TypeTable *ptrType = DeclType == TLookup("integer") ?
                                                TLookup("integer_ptr") : TLookup("string_ptr"); 
                                                GInstall($2, ptrType, DeclType->size, -1, -1, NULL);
                                            }              
            |   ID                          {GInstall($1, DeclType, DeclType->size, -1, -1, NULL);}       
            ;

ParamList   :   ParamList COMMA Param 
            |   Param
            | /*param can be empty*/
            ;

Param       :   PType ID                {PInstall($2, ParamType);}
            |   PType STAR ID           {
                                            struct TypeTable *ptrType = ParamType == TLookup("integer") ?
                                            TLookup("integer_ptr") : TLookup("string_ptr"); 
                                            PInstall($3, ptrType);
                                        }
            ;
            
/*----------------------------------------------------------------------------------------------------*/

FDefBlock   :   FDef 
            |   FDefBlock FDef
            ;


FDef        :   DType ID '(' ParamList ')'       {
                                                    PInstallLST($2);    // Insert params to Local symbol Table
                                                    total_params = validateParams($2, Phead);  // check name equivalence of the parameters
                                                    freeParamList();    // Free the unwanted paramlist formed from the Fdef block, we will use the paramlist from GST
                                                }
                '{' LDeclBlock Body '}'         {
                                                    if($9->right->type != $1){
                                                        fprintf(stderr, "mismatch in return type: %s\n", $2);
                                                        exit(1);
                                                    }
                                                    Lsymbol *temp = Lhead;
                                                    for(int i = total_params; i > 0; i--){
                                                        temp->binding = 0-i-2;
                                                        temp = temp->next;
                                                    }

                                                    int addr = 1;
                                                    while(temp != NULL){
                                                        
                                                        temp->binding = addr;
                                                        addr++;
                                                        temp = temp->next;
                                                    }
                                                    printLST($2);
                                                    // codeGenFunc($9, $2);
                                                    FreeLST();
                                                }
            ;

LDeclBlock  : DECL LDecList ENDDECL         
            |
            ;

LDecList    : LDecList LDecl 
            | LDecl
            ;

LDecl       : DType LidList EOS
            ;

LidList     : LidList COMMA Lid
            | Lid
            ;

Lid         :   STAR ID                         {
                                                    struct TypeTable *ptrType = DeclType == TLookup("integer") ?
                                                    TLookup("integer_ptr") : TLookup("string_ptr"); 
                                                    LInstall($2, ptrType);
                                                }        
            |   ID                              {LInstall($1, DeclType);}        
            ;


PType       :   INT                 {ParamType = TLookup("integer");}
            |   STR                 {ParamType = TLookup("string");}
            |   ID                  {
                                        ParamType = TLookup($1); 
                                        $$ = TLookup($1);
                                        if(ParamType == NULL){
                                            ParamType = TLookup("dummy");
                                        }
                                    }
            ;


/*----------------------------------------------------------------------------------------------------*/

MainBlock   :   INT MAIN '('')' '{' LDeclBlock Body '}'    {
                                                                if($7->right->type != TLookup("integer")){
                                                                    fprintf(stderr, "mismatch in return type: %s\n", "main");
                                                                    exit(1);
                                                                }
                                                                Lsymbol *temp = Lhead;

                                                                int addr = 1;
                                                                while(temp != NULL){
                                                                    
                                                                    temp->binding = addr;
                                                                    addr++;
                                                                    temp = temp->next;
                                                                }
                                                                printLST("main");
                                                                // codeGenMain($7);
                                                                FreeLST();
                                                            }
            ;

Body        :   START_BLOCK SList RetStmt END_BLOCK         {$$ = makeConnNode($2, $3);}
            |   START_BLOCK RetStmt END_BLOCK               {$$ = makeConnNode(NULL, $2);}
            |   START_BLOCK END_BLOCK                       {$$ = makeConnNode(NULL, NULL);}
            ;

RetStmt     :   RETURN Expr EOS         {$$ = makeRetNode($2);}
            ;

SList       :   SList Stmt              {$$ = makeConnNode($1, $2);}
            |   Stmt                    {$$ = $1;}
            ;

Stmt        :   IfStmt EOS              {$$ = $1;}
            |   IterativeStmt EOS       {$$ = $1;}
            |   InputStmt EOS           {$$ = $1;}
            |   OutputStmt EOS          {$$ = $1;}
            |   AsgStmt EOS             {$$ = $1;}
            |   BreakStmt EOS           {$$ = $1;}
            |   ContinueStmt EOS        {$$ = $1;}
            |   InitializeStmt EOS      {$$ = $1;}
            |   AllocStmt EOS           {$$ = $1;}
            |   FreeStmt EOS            {$$ = $1;}
            ;

/*----------------------------------------------------------------------------------------------------*/

IfStmt      :   IF '(' Expr ')' THEN SList ELSE SList ENDIF     {$$ = makeIfElseNode($3, $6, $8);}
            |   IF '(' Expr ')' THEN SList ENDIF                {$$ = makeIfElseNode($3, $6, NULL);}
            ;

IterativeStmt   :   WHILE '(' Expr ')' DO SList ENDWHILE        {$$ = makeIterationNode(NODE_WHILE, $3, $6);}
                |   DO SList WHILE '(' Expr ')'                 {$$ = makeIterationNode(NODE_DOWHILE, $5, $2);}
                |   REPEAT SList UNTIL '(' Expr ')'             {$$ = makeIterationNode(NODE_REPEAT, $5, $2);}
                ;

InputStmt   :   READ '(' Identifier ')'             {$$ = makeReadNode($3);}
            ;

OutputStmt  :   WRITE '(' Expr ')'                  {$$ = makeWriteNode($3);}
            ;

AsgStmt     :   Identifier ASSGN Expr               {$$ = makeAssgnNode($1, $3);}
            |   Field ASSGN AllocStmt               {$$ = makeAssgnNode($1, $3);}
            |   Field ASSGN Expr                    {$$ = makeAssgnNode($1, $3);}
            |   Identifier ASSGN AllocStmt          {$$ = makeAssgnNode($1, $3);}
            |   Identifier ASSGN InitializeStmt     {$$ = makeAssgnNode($1, $3);}
            ;

BreakStmt       :   BREAK               {$$ = makeBreakNode();}
                ;

ContinueStmt    :   CONTINUE            {$$ = makeContinueNode();}
                ;

InitializeStmt  :   INITIALIZE '(' ')'  {$$ = makeInitNode();}
                ;

AllocStmt       :   ALLOC '('')'        {$$ = makeAllocNode();}
                ;

FreeStmt        :   FREE '(' ID ')'     {
                                            ASTNode* id = makeLeafNode(0, NULL, TLookup("dummy"), $3);
                                            $$ = makeFreeNode(id);
                                        }
                |   FREE '(' Field ')'  {$$ = makeFreeNode($3);}
                ;

/*----------------------------------------------------------------------------------------------------*/

Expr        :   Expr PLUS Expr          {$$ = makeArithOPNode(NODE_ADD, $1, $3);}
            |   Expr MINUS Expr         {$$ = makeArithOPNode(NODE_SUB, $1, $3);}
            |   Expr STAR Expr          {$$ = makeArithOPNode(NODE_MUL, $1, $3);}
            |   Expr DIV Expr           {$$ = makeArithOPNode(NODE_DIV, $1, $3);}
            |   Expr MOD Expr           {$$ = makeArithOPNode(NODE_MOD, $1, $3);}
            |   '(' Expr ')'            {$$ = $2;}
            |   Expr AND Expr           {$$ = makeLogicOPNode(NODE_AND, $1, $3);}
            |   Expr OR Expr            {$$ = makeLogicOPNode(NODE_OR, $1, $3);}
            |   NOT Expr                {$$ = makeLogicOPNode(NODE_NOT, $2, NULL);}
            |   ADDR Identifier         {$$ = makeAddrNode($2);}
            |   Expr LT Expr            {$$ = makeRelOPNode(NODE_LT, $1, $3);}
            |   Expr GT Expr            {$$ = makeRelOPNode(NODE_GT, $1, $3);}
            |   Expr LE Expr            {$$ = makeRelOPNode(NODE_LE, $1, $3);}
            |   Expr GE Expr            {$$ = makeRelOPNode(NODE_GE, $1, $3);}
            |   Expr NE Expr            {$$ = makeRelOPNode(NODE_NE, $1, $3);}
            |   Expr EQ Expr            {$$ = makeRelOPNode(NODE_EQ, $1, $3);}
            |   Identifier              {$$ = $1;}
            |   Field                   {$$ = $1;}
            |   NUM                     {$$ = makeLeafNode($1, NULL, TLookup("integer"), NULL);}
            |   STRING                  {$$ = makeLeafNode(0, $1, TLookup("string"), NULL);}
            |   NULL_T                  {$$ = makeNullNode();}
            ;

Identifier  :   ID'('')'                    {$$ = makeFuncNode($1, TLookup("dummy"), NULL);}
            |   ID'(' ArgList ')'           {$$ = makeFuncNode($1, TLookup("dummy"), $3);}
            |   ID '['Expr']' '['Expr']'    {$$ = makeArrayNode($1, TLookup("dummy"), $3, $6);}
            |   ID '['Expr']'               {$$ = makeArrayNode($1, TLookup("dummy"), $3, NULL);}
            |   STAR ID                     {
                                                ASTNode *id = makeLeafNode(0, NULL, TLookup("dummy"), $2);
                                                $$ = makePtrNode(id);}
            |   ID                          {$$ = makeLeafNode(0, NULL, TLookup("dummy"), $1);}
            ;

Field       :   ID DOT ID                   {
                                                ASTNode *id = makeLeafNode(0, NULL, TLookup("dummy"), $1);
                                                $$ = makeFieldNode(id, $3);
                                                
                                            }
            |   Field DOT ID                {$$ = makeFieldNode($1, $3);}
            ;

ArgList     :   ArgList COMMA Expr          {$$ = makeArgNode($1, $3);}
            |   Expr                        {$$ = $1;}
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

    TInstall("integer", 1, NULL);
    TInstall("string", 1, NULL);
    TInstall("boolean", 1, NULL);
    TInstall("array_integer", 1, NULL);
    TInstall("array_string", 1, NULL);
    TInstall("integer_ptr", 1, NULL);
    TInstall("string_ptr", 1, NULL);
    TInstall("void", 0, NULL);
    TInstall("dummy", 0, NULL);
    
    yyparse();

    if(yyin != stdin) fclose(yyin);
    return 0;
}