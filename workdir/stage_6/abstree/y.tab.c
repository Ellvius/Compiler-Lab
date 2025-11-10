/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "abstree.y"

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


#line 88 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    START_BLOCK = 258,
    END_BLOCK = 259,
    DECL = 260,
    ENDDECL = 261,
    TYPE = 262,
    ENDTYPE = 263,
    READ = 264,
    WRITE = 265,
    INITIALIZE = 266,
    ALLOC = 267,
    FREE = 268,
    MAIN = 269,
    RETURN = 270,
    IF = 271,
    THEN = 272,
    ELSE = 273,
    ENDIF = 274,
    WHILE = 275,
    DO = 276,
    ENDWHILE = 277,
    REPEAT = 278,
    UNTIL = 279,
    BREAK = 280,
    CONTINUE = 281,
    PLUS = 282,
    MINUS = 283,
    STAR = 284,
    DIV = 285,
    MOD = 286,
    LT = 287,
    GT = 288,
    LE = 289,
    GE = 290,
    NE = 291,
    EQ = 292,
    AND = 293,
    OR = 294,
    NOT = 295,
    ASSGN = 296,
    EOS = 297,
    COMMA = 298,
    ADDR = 299,
    DOT = 300,
    INT = 301,
    STR = 302,
    NULL_T = 303,
    NUM = 304,
    STRING = 305,
    ID = 306
  };
#endif
/* Tokens.  */
#define START_BLOCK 258
#define END_BLOCK 259
#define DECL 260
#define ENDDECL 261
#define TYPE 262
#define ENDTYPE 263
#define READ 264
#define WRITE 265
#define INITIALIZE 266
#define ALLOC 267
#define FREE 268
#define MAIN 269
#define RETURN 270
#define IF 271
#define THEN 272
#define ELSE 273
#define ENDIF 274
#define WHILE 275
#define DO 276
#define ENDWHILE 277
#define REPEAT 278
#define UNTIL 279
#define BREAK 280
#define CONTINUE 281
#define PLUS 282
#define MINUS 283
#define STAR 284
#define DIV 285
#define MOD 286
#define LT 287
#define GT 288
#define LE 289
#define GE 290
#define NE 291
#define EQ 292
#define AND 293
#define OR 294
#define NOT 295
#define ASSGN 296
#define EOS 297
#define COMMA 298
#define ADDR 299
#define DOT 300
#define INT 301
#define STR 302
#define NULL_T 303
#define NUM 304
#define STRING 305
#define ID 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "abstree.y"

    struct ASTNode* node;
    struct TypeTable* idType;
    char* idName;
    int intVal;
    char* strVal;

#line 250 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   574

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  245

#define YYUNDEFTOK  2
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      54,    55,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    63,    66,    67,    70,    71,    74,    77,
      78,    81,    82,    89,    90,    91,   101,   102,   105,   106,
     109,   112,   113,   116,   117,   118,   119,   124,   127,   128,
     129,   132,   133,   142,   143,   147,   147,   176,   177,   180,
     181,   184,   187,   188,   191,   196,   200,   201,   207,   227,
     228,   229,   232,   235,   236,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   253,   254,   257,   258,   259,
     262,   265,   268,   269,   270,   271,   272,   275,   278,   281,
     284,   287,   291,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   319,   320,   321,   322,   323,   326,
     329,   334,   337,   338
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START_BLOCK", "END_BLOCK", "DECL",
  "ENDDECL", "TYPE", "ENDTYPE", "READ", "WRITE", "INITIALIZE", "ALLOC",
  "FREE", "MAIN", "RETURN", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "REPEAT", "UNTIL", "BREAK", "CONTINUE", "PLUS", "MINUS",
  "STAR", "DIV", "MOD", "LT", "GT", "LE", "GE", "NE", "EQ", "AND", "OR",
  "NOT", "ASSGN", "EOS", "COMMA", "ADDR", "DOT", "INT", "STR", "NULL_T",
  "NUM", "STRING", "ID", "'{'", "'}'", "'('", "')'", "'['", "']'",
  "$accept", "Program", "TypeDefBlock", "TypeDefList", "TypeDef",
  "FieldDeclList", "FieldDecl", "DType", "GDeclBlock", "GDeclList",
  "GDecl", "GidList", "Gid", "ParamList", "Param", "FDefBlock", "FDef",
  "$@1", "LDeclBlock", "LDecList", "LDecl", "LidList", "Lid", "PType",
  "MainBlock", "Body", "RetStmt", "SList", "Stmt", "IfStmt",
  "IterativeStmt", "InputStmt", "OutputStmt", "AsgStmt", "BreakStmt",
  "ContinueStmt", "InitializeStmt", "AllocStmt", "FreeStmt", "Expr",
  "Identifier", "Field", "ArgList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   123,   125,    40,    41,    91,    93
};
# endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,    -8,    56,    96,    21,    -4,   -99,   -99,    31,   102,
      31,   -99,   -99,   -99,   -99,   -99,   -20,     2,   -99,    92,
      81,   102,   -99,   -99,    41,   -99,   -14,    84,    39,    43,
     -99,   -99,   -99,    88,    89,   -99,   -99,   -99,   -99,    90,
     108,   -99,    68,   107,   -99,   -20,   104,    68,   121,   -99,
     -99,   -99,   -13,   -99,     7,   110,   -99,   116,    14,   -99,
      68,   -99,   122,   -99,   118,   171,   -99,   -99,   -99,   128,
      31,   175,   129,   125,    15,     8,   -99,    87,   134,   171,
     -99,   137,   -99,    75,   -99,   -99,   -99,   -99,   141,   142,
     144,   149,   151,   491,   154,   155,   290,   290,   -99,   -99,
     165,   -29,   215,   202,   -99,   178,   179,   182,   184,   187,
     188,   191,   197,   198,   200,   203,    35,   -99,   175,   -99,
     -99,    15,    17,   491,   192,   205,   201,   491,    17,   -99,
     -99,   -99,   491,   519,   -99,   216,   491,   491,   313,   225,
     -99,   212,   -16,   491,   -99,   239,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   135,   306,   213,
     217,   -99,    55,   210,   382,   -99,   -99,     5,    26,   411,
     -99,   395,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   -99,   424,   437,   219,   220,
     -99,   -99,   535,    20,   338,   -99,   -99,   -99,   535,   -99,
     535,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -19,   -19,
     -99,   -99,   -99,   495,   495,   495,   495,   453,   453,   411,
     369,   260,   262,   491,   491,   491,   -99,   228,   290,   290,
     466,   479,   535,   491,   181,   246,   262,   -99,   351,   290,
     -99,   -99,   -99,   269,   -99
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,    17,     0,     0,     7,     1,     0,     0,
       0,     4,     6,    13,    14,    15,     0,     0,    19,    13,
       0,     0,    33,     3,     0,    10,     0,     0,    27,     0,
      22,    16,    18,     0,     0,    34,     2,     8,     9,     0,
       0,    26,    30,     0,    20,     0,     0,    30,     0,    11,
      46,    47,     0,    29,     0,     0,    21,     0,     0,    12,
       0,    23,     0,    31,    25,    38,    35,    28,    32,     0,
       0,     0,     0,     0,     0,     0,    40,     0,     0,    38,
      24,     0,    45,     0,    43,    37,    39,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    78,
       0,   109,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,    44,
      41,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     101,   102,     0,     0,    99,   100,     0,     0,     0,     0,
     108,     0,     0,     0,    50,     0,    53,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,     0,     0,
       0,    42,   109,     0,     0,    79,    80,     0,     0,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,     0,     0,     0,     0,
     110,   104,   113,     0,     0,    49,    76,    75,    72,    73,
      74,   111,    36,    70,    71,    81,    82,    88,    83,    84,
      85,    86,    87,    93,    94,    95,    96,    97,    98,    89,
      90,     0,     0,     0,     0,     0,   105,   107,     0,     0,
       0,     0,   112,     0,     0,     0,    68,    69,     0,     0,
      66,    67,   106,     0,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   -99,   281,   -99,   263,    -3,   -99,   -99,
     274,   -99,   248,   249,   244,   -99,   284,   -99,   229,   -99,
     232,   -99,   193,   -99,   288,   194,   214,   -95,   -98,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   164,   -18,   -99,   -53,
     -77,   -74,   -99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    24,    25,    16,     9,    17,
      18,    29,    30,    52,    53,    21,    22,    72,    71,    75,
      76,    83,    84,    54,    23,    78,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   133,
     134,   135,   193
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     115,   138,   139,   116,    11,   146,    20,    26,    31,    27,
     174,   175,   176,   100,    85,    39,   141,     1,    20,   115,
     115,    26,   116,   116,   127,   142,   115,   143,   128,   116,
      60,    28,   129,   130,   131,   101,    62,    40,   132,   191,
     146,   146,    61,     4,    81,   163,   100,     4,    13,    14,
     141,   170,   168,    15,    13,    14,     7,    60,    63,    15,
     205,   115,   115,   225,   116,   116,    82,    74,   162,    66,
     164,   159,    74,    10,   169,   226,   158,    13,    14,   171,
     159,   206,    15,   186,   187,    44,    45,    13,    14,   192,
     194,    87,    15,    42,    37,    43,    88,    89,    90,    91,
      92,     8,    93,    94,   198,   200,    33,    95,    96,   142,
      97,   143,    98,    99,    50,    51,   100,   120,   121,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    34,   234,   235,    41,   146,   146,   101,   197,
     199,    48,    46,    47,   243,   146,    90,    91,    19,    14,
      49,   115,   115,    15,   116,   116,    55,   115,   115,    57,
     116,   116,   115,    59,   100,   116,   115,    64,    65,   116,
     230,   231,   232,    68,    69,   127,    70,    73,    77,   128,
     238,    79,    80,   129,   130,   131,   101,   117,   119,   132,
      88,    89,    90,    91,    92,   122,   123,    94,   124,   239,
     240,    95,    96,   125,    97,   126,    98,    99,   136,   137,
     100,    88,    89,    90,    91,    92,   140,    93,    94,   144,
     147,   148,    95,    96,   149,    97,   150,    98,    99,   151,
     152,   100,   101,   153,    88,    89,    90,    91,    92,   154,
     155,    94,   156,   195,   157,    95,    96,   165,    97,   189,
      98,    99,   167,   101,   100,    88,    89,    90,    91,    92,
     166,   159,    94,   190,   201,   203,    95,    96,   241,    97,
     202,    98,    99,   223,   224,   100,   101,   228,    88,    89,
      90,    91,    92,   229,   233,    94,    12,    38,   244,    95,
      96,    32,    97,    56,    98,    99,    58,   101,   100,    88,
      89,    90,    91,    92,    67,    35,    94,    86,   118,    36,
      95,    96,   160,    97,   161,    98,    99,   145,    91,   100,
     101,   196,    88,    89,    90,    91,    92,     0,     0,    94,
       0,     0,     0,   188,    96,   100,    97,     0,    98,    99,
       0,   101,   100,     0,     0,     0,   127,     0,     0,     0,
     128,     0,     0,     0,   129,   130,   131,   101,     0,     0,
     132,     0,     0,     0,   101,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,     0,     0,     0,     0,   227,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   242,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,     0,     0,   204,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,     0,
     207,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,     0,     0,   221,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,     0,   222,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,     0,
     100,   236,   172,   173,   174,   175,   176,    -1,    -1,    -1,
      -1,   127,     0,     0,   237,   128,     0,     0,     0,   129,
     130,   131,   101,     0,     0,   132,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,     0,
       0,   185,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184
};

static const yytype_int16 yycheck[] =
{
      77,    96,    97,    77,     8,   103,     9,    10,     6,    29,
      29,    30,    31,    29,     6,    29,    45,     7,    21,    96,
      97,    24,    96,    97,    40,    54,   103,    56,    44,   103,
      43,    51,    48,    49,    50,    51,    29,    51,    54,    55,
     138,   139,    55,    51,    29,   122,    29,    51,    46,    47,
      45,   128,   126,    51,    46,    47,     0,    43,    51,    51,
      55,   138,   139,    43,   138,   139,    51,    70,    51,    55,
     123,    45,    75,    52,   127,    55,    41,    46,    47,   132,
      45,    55,    51,   136,   137,    42,    43,    46,    47,   142,
     143,     4,    51,    54,    53,    56,     9,    10,    11,    12,
      13,     5,    15,    16,   157,   158,    14,    20,    21,    54,
      23,    56,    25,    26,    46,    47,    29,    42,    43,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,    51,   228,   229,    51,   234,   235,    51,   157,
     158,    51,    54,    54,   239,   243,    11,    12,    46,    47,
      42,   228,   229,    51,   228,   229,    49,   234,   235,    55,
     234,   235,   239,    42,    29,   239,   243,    57,    52,   243,
     223,   224,   225,    51,    56,    40,     5,    49,     3,    44,
     233,    52,    57,    48,    49,    50,    51,    53,    51,    54,
       9,    10,    11,    12,    13,    54,    54,    16,    54,    18,
      19,    20,    21,    54,    23,    54,    25,    26,    54,    54,
      29,     9,    10,    11,    12,    13,    51,    15,    16,     4,
      42,    42,    20,    21,    42,    23,    42,    25,    26,    42,
      42,    29,    51,    42,     9,    10,    11,    12,    13,    42,
      42,    16,    42,     4,    41,    20,    21,    55,    23,    24,
      25,    26,    51,    51,    29,     9,    10,    11,    12,    13,
      55,    45,    16,    51,    51,    55,    20,    21,    22,    23,
      53,    25,    26,    54,    54,    29,    51,    17,     9,    10,
      11,    12,    13,    21,    56,    16,     5,    24,    19,    20,
      21,    17,    23,    45,    25,    26,    47,    51,    29,     9,
      10,    11,    12,    13,    60,    21,    16,    75,    79,    21,
      20,    21,   118,    23,   121,    25,    26,   103,    12,    29,
      51,   157,     9,    10,    11,    12,    13,    -1,    -1,    16,
      -1,    -1,    -1,    20,    21,    29,    23,    -1,    25,    26,
      -1,    51,    29,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    48,    49,    50,    51,    -1,    -1,
      54,    -1,    -1,    -1,    51,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    57,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    57,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    55,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      55,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    55,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    55,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      29,    55,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    40,    -1,    -1,    55,    44,    -1,    -1,    -1,    48,
      49,    50,    51,    -1,    -1,    54,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    59,    60,    51,    61,    62,     0,     5,    66,
      52,     8,    62,    46,    47,    51,    65,    67,    68,    46,
      65,    73,    74,    82,    63,    64,    65,    29,    51,    69,
      70,     6,    68,    14,    51,    74,    82,    53,    64,    29,
      51,    51,    54,    56,    42,    43,    54,    54,    51,    42,
      46,    47,    71,    72,    81,    49,    70,    55,    71,    42,
      43,    55,    29,    51,    57,    52,    55,    72,    51,    56,
       5,    76,    75,    49,    65,    77,    78,     3,    83,    52,
      57,    29,    51,    79,    80,     6,    78,     4,     9,    10,
      11,    12,    13,    15,    16,    20,    21,    23,    25,    26,
      29,    51,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    98,    99,    53,    76,    51,
      42,    43,    54,    54,    54,    54,    54,    40,    44,    48,
      49,    50,    54,    97,    98,    99,    54,    54,    85,    85,
      51,    45,    54,    56,     4,    84,    86,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    41,    41,    45,
      83,    80,    51,    98,    97,    55,    55,    51,    99,    97,
      98,    97,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    42,    97,    97,    20,    24,
      51,    55,    97,   100,    97,     4,    94,    95,    97,    95,
      97,    51,    53,    55,    55,    55,    55,    55,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    55,    55,    54,    54,    43,    55,    57,    17,    21,
      97,    97,    97,    56,    85,    85,    55,    55,    97,    18,
      19,    22,    57,    85,    19
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    61,    61,    62,    63,
      63,    64,    64,    65,    65,    65,    66,    66,    67,    67,
      68,    69,    69,    70,    70,    70,    70,    70,    71,    71,
      71,    72,    72,    73,    73,    75,    74,    76,    76,    77,
      77,    78,    79,    79,    80,    80,    81,    81,    82,    83,
      83,    83,    84,    85,    85,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    87,    87,    88,    88,    88,
      89,    90,    91,    91,    91,    91,    91,    92,    93,    94,
      95,    96,    96,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    98,    98,    98,    98,    98,    98,
      99,    99,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     0,     2,     1,     4,     2,
       1,     3,     4,     1,     1,     1,     3,     0,     2,     1,
       3,     3,     1,     4,     7,     4,     2,     1,     3,     1,
       0,     2,     3,     1,     2,     0,    10,     3,     0,     2,
       1,     3,     3,     1,     2,     1,     1,     1,     8,     4,
       3,     2,     3,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     9,     7,     7,     6,     6,
       4,     4,     3,     3,     3,     3,     3,     1,     1,     3,
       3,     4,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     3,     4,     7,     4,     2,     1,
       3,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 59 "abstree.y"
                                                                {
                                                                    printGST();
                                                                    // fprintf(stdout,"parsing successful!\n");
                                                                }
#line 1665 "y.tab.c"
    break;

  case 4:
#line 66 "abstree.y"
                                                {  printTypeTable();}
#line 1671 "y.tab.c"
    break;

  case 8:
#line 74 "abstree.y"
                                                {TInstall((yyvsp[-3].idName), -1, Fhead); Fhead = NULL;}
#line 1677 "y.tab.c"
    break;

  case 11:
#line 81 "abstree.y"
                                        {FInstall((yyvsp[-1].idName), DeclType);}
#line 1683 "y.tab.c"
    break;

  case 12:
#line 82 "abstree.y"
                                        {
                                            struct TypeTable *ptrType = DeclType == TLookup("integer") ?
                                            TLookup("integer_ptr") : TLookup("string_ptr");
                                            FInstall((yyvsp[-1].idName), ptrType);
                                        }
#line 1693 "y.tab.c"
    break;

  case 13:
#line 89 "abstree.y"
                                    {DeclType = TLookup("integer"); (yyval.idType) = TLookup("integer");}
#line 1699 "y.tab.c"
    break;

  case 14:
#line 90 "abstree.y"
                                    {DeclType = TLookup("string"); (yyval.idType) = TLookup("string");}
#line 1705 "y.tab.c"
    break;

  case 15:
#line 91 "abstree.y"
                                    {
                                        DeclType = TLookup((yyvsp[0].idName)); 
                                        (yyval.idType) = TLookup((yyvsp[0].idName));
                                        if(DeclType == NULL){
                                            DeclType = TLookup("dummy");
                                        }
                                    }
#line 1717 "y.tab.c"
    break;

  case 23:
#line 116 "abstree.y"
                                            {GInstall((yyvsp[-3].idName), DeclType, -1, -1, -1, Phead);}
#line 1723 "y.tab.c"
    break;

  case 24:
#line 117 "abstree.y"
                                            {GInstall((yyvsp[-6].idName), DeclType, (yyvsp[-4].intVal)*(yyvsp[-1].intVal), (yyvsp[-4].intVal), (yyvsp[-1].intVal), NULL);}
#line 1729 "y.tab.c"
    break;

  case 25:
#line 118 "abstree.y"
                                            {GInstall((yyvsp[-3].idName), DeclType, (yyvsp[-1].intVal), (yyvsp[-1].intVal), -1, NULL);}
#line 1735 "y.tab.c"
    break;

  case 26:
#line 119 "abstree.y"
                                            {
                                                struct TypeTable *ptrType = DeclType == TLookup("integer") ?
                                                TLookup("integer_ptr") : TLookup("string_ptr"); 
                                                GInstall((yyvsp[0].idName), ptrType, DeclType->size, -1, -1, NULL);
                                            }
#line 1745 "y.tab.c"
    break;

  case 27:
#line 124 "abstree.y"
                                            {GInstall((yyvsp[0].idName), DeclType, DeclType->size, -1, -1, NULL);}
#line 1751 "y.tab.c"
    break;

  case 31:
#line 132 "abstree.y"
                                        {PInstall((yyvsp[0].idName), ParamType);}
#line 1757 "y.tab.c"
    break;

  case 32:
#line 133 "abstree.y"
                                        {
                                            struct TypeTable *ptrType = ParamType == TLookup("integer") ?
                                            TLookup("integer_ptr") : TLookup("string_ptr"); 
                                            PInstall((yyvsp[0].idName), ptrType);
                                        }
#line 1767 "y.tab.c"
    break;

  case 35:
#line 147 "abstree.y"
                                                 {
                                                    PInstallLST((yyvsp[-3].idName));    // Insert params to Local symbol Table
                                                    total_params = validateParams((yyvsp[-3].idName), Phead);  // check name equivalence of the parameters
                                                    freeParamList();    // Free the unwanted paramlist formed from the Fdef block, we will use the paramlist from GST
                                                }
#line 1777 "y.tab.c"
    break;

  case 36:
#line 152 "abstree.y"
                                                {
                                                    if((yyvsp[-1].node)->right->type != (yyvsp[-9].idType)){
                                                        fprintf(stderr, "mismatch in return type: %s\n", (yyvsp[-8].idName));
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
                                                        addr+=temp->type->size;
                                                        temp = temp->next;
                                                    }
                                                    printLST((yyvsp[-8].idName));
                                                    // codeGenFunc($9, $2);
                                                    FreeLST();
                                                }
#line 1804 "y.tab.c"
    break;

  case 44:
#line 191 "abstree.y"
                                                {
                                                    struct TypeTable *ptrType = DeclType == TLookup("integer") ?
                                                    TLookup("integer_ptr") : TLookup("string_ptr"); 
                                                    LInstall((yyvsp[0].idName), ptrType);
                                                }
#line 1814 "y.tab.c"
    break;

  case 45:
#line 196 "abstree.y"
                                                {LInstall((yyvsp[0].idName), DeclType);}
#line 1820 "y.tab.c"
    break;

  case 46:
#line 200 "abstree.y"
                                                {ParamType = TLookup("integer");}
#line 1826 "y.tab.c"
    break;

  case 47:
#line 201 "abstree.y"
                                                {ParamType = TLookup("string");}
#line 1832 "y.tab.c"
    break;

  case 48:
#line 207 "abstree.y"
                                                           {
                                                                if((yyvsp[-1].node)->right->type != TLookup("integer")){
                                                                    fprintf(stderr, "mismatch in return type: %s\n", "main");
                                                                    exit(1);
                                                                }
                                                                Lsymbol *temp = Lhead;

                                                                int addr = 1;
                                                                while(temp != NULL){
                                                                    
                                                                    temp->binding = addr;
                                                                    addr+=temp->type->size;
                                                                    temp = temp->next;
                                                                }
                                                                printLST("main");
                                                                // codeGenMain($7);
                                                                FreeLST();
                                                            }
#line 1855 "y.tab.c"
    break;

  case 49:
#line 227 "abstree.y"
                                                            {(yyval.node) = makeConnNode((yyvsp[-2].node), (yyvsp[-1].node));}
#line 1861 "y.tab.c"
    break;

  case 50:
#line 228 "abstree.y"
                                                            {(yyval.node) = makeConnNode(NULL, (yyvsp[-1].node));}
#line 1867 "y.tab.c"
    break;

  case 51:
#line 229 "abstree.y"
                                                            {(yyval.node) = makeConnNode(NULL, NULL);}
#line 1873 "y.tab.c"
    break;

  case 52:
#line 232 "abstree.y"
                                        {(yyval.node) = makeRetNode((yyvsp[-1].node));}
#line 1879 "y.tab.c"
    break;

  case 53:
#line 235 "abstree.y"
                                        {(yyval.node) = makeConnNode((yyvsp[-1].node), (yyvsp[0].node));}
#line 1885 "y.tab.c"
    break;

  case 54:
#line 236 "abstree.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 1891 "y.tab.c"
    break;

  case 55:
#line 239 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1897 "y.tab.c"
    break;

  case 56:
#line 240 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1903 "y.tab.c"
    break;

  case 57:
#line 241 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1909 "y.tab.c"
    break;

  case 58:
#line 242 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1915 "y.tab.c"
    break;

  case 59:
#line 243 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1921 "y.tab.c"
    break;

  case 60:
#line 244 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1927 "y.tab.c"
    break;

  case 61:
#line 245 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1933 "y.tab.c"
    break;

  case 62:
#line 246 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1939 "y.tab.c"
    break;

  case 63:
#line 247 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1945 "y.tab.c"
    break;

  case 64:
#line 248 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1951 "y.tab.c"
    break;

  case 65:
#line 253 "abstree.y"
                                                                {(yyval.node) = makeIfElseNode((yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-1].node));}
#line 1957 "y.tab.c"
    break;

  case 66:
#line 254 "abstree.y"
                                                                {(yyval.node) = makeIfElseNode((yyvsp[-4].node), (yyvsp[-1].node), NULL);}
#line 1963 "y.tab.c"
    break;

  case 67:
#line 257 "abstree.y"
                                                                {(yyval.node) = makeIterationNode(NODE_WHILE, (yyvsp[-4].node), (yyvsp[-1].node));}
#line 1969 "y.tab.c"
    break;

  case 68:
#line 258 "abstree.y"
                                                                {(yyval.node) = makeIterationNode(NODE_DOWHILE, (yyvsp[-1].node), (yyvsp[-4].node));}
#line 1975 "y.tab.c"
    break;

  case 69:
#line 259 "abstree.y"
                                                                {(yyval.node) = makeIterationNode(NODE_REPEAT, (yyvsp[-1].node), (yyvsp[-4].node));}
#line 1981 "y.tab.c"
    break;

  case 70:
#line 262 "abstree.y"
                                                    {(yyval.node) = makeReadNode((yyvsp[-1].node));}
#line 1987 "y.tab.c"
    break;

  case 71:
#line 265 "abstree.y"
                                                    {(yyval.node) = makeWriteNode((yyvsp[-1].node));}
#line 1993 "y.tab.c"
    break;

  case 72:
#line 268 "abstree.y"
                                                    {(yyval.node) = makeAssgnNode((yyvsp[-2].node), (yyvsp[0].node));}
#line 1999 "y.tab.c"
    break;

  case 73:
#line 269 "abstree.y"
                                                    {(yyval.node) = makeAssgnNode((yyvsp[-2].node), (yyvsp[0].node));}
#line 2005 "y.tab.c"
    break;

  case 74:
#line 270 "abstree.y"
                                                    {(yyval.node) = makeAssgnNode((yyvsp[-2].node), (yyvsp[0].node));}
#line 2011 "y.tab.c"
    break;

  case 75:
#line 271 "abstree.y"
                                                    {(yyval.node) = makeAssgnNode((yyvsp[-2].node), (yyvsp[0].node));}
#line 2017 "y.tab.c"
    break;

  case 76:
#line 272 "abstree.y"
                                                    {(yyval.node) = makeAssgnNode((yyvsp[-2].node), (yyvsp[0].node));}
#line 2023 "y.tab.c"
    break;

  case 77:
#line 275 "abstree.y"
                                        {(yyval.node) = makeBreakNode();}
#line 2029 "y.tab.c"
    break;

  case 78:
#line 278 "abstree.y"
                                        {(yyval.node) = makeContinueNode();}
#line 2035 "y.tab.c"
    break;

  case 79:
#line 281 "abstree.y"
                                        {(yyval.node) = makeInitNode();}
#line 2041 "y.tab.c"
    break;

  case 80:
#line 284 "abstree.y"
                                        {(yyval.node) = makeAllocNode();}
#line 2047 "y.tab.c"
    break;

  case 81:
#line 287 "abstree.y"
                                        {
                                            ASTNode* id = makeLeafNode(0, NULL, TLookup("dummy"), (yyvsp[-1].idName));
                                            (yyval.node) = makeFreeNode(id);
                                        }
#line 2056 "y.tab.c"
    break;

  case 82:
#line 291 "abstree.y"
                                        {(yyval.node) = makeFreeNode((yyvsp[-1].node));}
#line 2062 "y.tab.c"
    break;

  case 83:
#line 296 "abstree.y"
                                        {(yyval.node) = makeArithOPNode(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2068 "y.tab.c"
    break;

  case 84:
#line 297 "abstree.y"
                                        {(yyval.node) = makeArithOPNode(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2074 "y.tab.c"
    break;

  case 85:
#line 298 "abstree.y"
                                        {(yyval.node) = makeArithOPNode(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2080 "y.tab.c"
    break;

  case 86:
#line 299 "abstree.y"
                                        {(yyval.node) = makeArithOPNode(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2086 "y.tab.c"
    break;

  case 87:
#line 300 "abstree.y"
                                        {(yyval.node) = makeArithOPNode(NODE_MOD, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2092 "y.tab.c"
    break;

  case 88:
#line 301 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2098 "y.tab.c"
    break;

  case 89:
#line 302 "abstree.y"
                                        {(yyval.node) = makeLogicOPNode(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2104 "y.tab.c"
    break;

  case 90:
#line 303 "abstree.y"
                                        {(yyval.node) = makeLogicOPNode(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2110 "y.tab.c"
    break;

  case 91:
#line 304 "abstree.y"
                                        {(yyval.node) = makeLogicOPNode(NODE_NOT, (yyvsp[0].node), NULL);}
#line 2116 "y.tab.c"
    break;

  case 92:
#line 305 "abstree.y"
                                        {(yyval.node) = makeAddrNode((yyvsp[0].node));}
#line 2122 "y.tab.c"
    break;

  case 93:
#line 306 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_LT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2128 "y.tab.c"
    break;

  case 94:
#line 307 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_GT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2134 "y.tab.c"
    break;

  case 95:
#line 308 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_LE, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2140 "y.tab.c"
    break;

  case 96:
#line 309 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_GE, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2146 "y.tab.c"
    break;

  case 97:
#line 310 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_NE, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2152 "y.tab.c"
    break;

  case 98:
#line 311 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_EQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2158 "y.tab.c"
    break;

  case 99:
#line 312 "abstree.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 2164 "y.tab.c"
    break;

  case 100:
#line 313 "abstree.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 2170 "y.tab.c"
    break;

  case 101:
#line 314 "abstree.y"
                                        {(yyval.node) = makeLeafNode((yyvsp[0].intVal), NULL, TLookup("integer"), NULL);}
#line 2176 "y.tab.c"
    break;

  case 102:
#line 315 "abstree.y"
                                        {(yyval.node) = makeLeafNode(0, (yyvsp[0].strVal), TLookup("string"), NULL);}
#line 2182 "y.tab.c"
    break;

  case 103:
#line 316 "abstree.y"
                                        {(yyval.node) = makeNullNode();}
#line 2188 "y.tab.c"
    break;

  case 104:
#line 319 "abstree.y"
                                            {(yyval.node) = makeFuncNode((yyvsp[-2].idName), TLookup("dummy"), NULL);}
#line 2194 "y.tab.c"
    break;

  case 105:
#line 320 "abstree.y"
                                            {(yyval.node) = makeFuncNode((yyvsp[-3].idName), TLookup("dummy"), (yyvsp[-1].node));}
#line 2200 "y.tab.c"
    break;

  case 106:
#line 321 "abstree.y"
                                            {(yyval.node) = makeArrayNode((yyvsp[-6].idName), TLookup("dummy"), (yyvsp[-4].node), (yyvsp[-1].node));}
#line 2206 "y.tab.c"
    break;

  case 107:
#line 322 "abstree.y"
                                            {(yyval.node) = makeArrayNode((yyvsp[-3].idName), TLookup("dummy"), (yyvsp[-1].node), NULL);}
#line 2212 "y.tab.c"
    break;

  case 108:
#line 323 "abstree.y"
                                            {
                                                ASTNode *id = makeLeafNode(0, NULL, TLookup("dummy"), (yyvsp[0].idName));
                                                (yyval.node) = makePtrNode(id);}
#line 2220 "y.tab.c"
    break;

  case 109:
#line 326 "abstree.y"
                                            {(yyval.node) = makeLeafNode(0, NULL, TLookup("dummy"), (yyvsp[0].idName));}
#line 2226 "y.tab.c"
    break;

  case 110:
#line 329 "abstree.y"
                                            {
                                                ASTNode *id = makeLeafNode(0, NULL, TLookup("dummy"), (yyvsp[-2].idName));
                                                (yyval.node) = makeFieldNode(id, (yyvsp[0].idName));
                                                
                                            }
#line 2236 "y.tab.c"
    break;

  case 111:
#line 334 "abstree.y"
                                            {(yyval.node) = makeFieldNode((yyvsp[-2].node), (yyvsp[0].idName));}
#line 2242 "y.tab.c"
    break;

  case 112:
#line 337 "abstree.y"
                                            {(yyval.node) = makeArgNode((yyvsp[-2].node), (yyvsp[0].node));}
#line 2248 "y.tab.c"
    break;

  case 113:
#line 338 "abstree.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 2254 "y.tab.c"
    break;


#line 2258 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 341 "abstree.y"


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
