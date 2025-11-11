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
    CLASS = 264,
    ENDCLASS = 265,
    READ = 266,
    WRITE = 267,
    INITIALIZE = 268,
    ALLOC = 269,
    FREE = 270,
    MAIN = 271,
    RETURN = 272,
    NEW = 273,
    DELETE = 274,
    SELF = 275,
    IF = 276,
    THEN = 277,
    ELSE = 278,
    ENDIF = 279,
    WHILE = 280,
    DO = 281,
    ENDWHILE = 282,
    REPEAT = 283,
    UNTIL = 284,
    BREAK = 285,
    CONTINUE = 286,
    PLUS = 287,
    MINUS = 288,
    STAR = 289,
    DIV = 290,
    MOD = 291,
    LT = 292,
    GT = 293,
    LE = 294,
    GE = 295,
    NE = 296,
    EQ = 297,
    AND = 298,
    OR = 299,
    NOT = 300,
    ASSGN = 301,
    EOS = 302,
    COMMA = 303,
    ADDR = 304,
    DOT = 305,
    INT = 306,
    STR = 307,
    NULL_T = 308,
    NUM = 309,
    STRING = 310,
    ID = 311
  };
#endif
/* Tokens.  */
#define START_BLOCK 258
#define END_BLOCK 259
#define DECL 260
#define ENDDECL 261
#define TYPE 262
#define ENDTYPE 263
#define CLASS 264
#define ENDCLASS 265
#define READ 266
#define WRITE 267
#define INITIALIZE 268
#define ALLOC 269
#define FREE 270
#define MAIN 271
#define RETURN 272
#define NEW 273
#define DELETE 274
#define SELF 275
#define IF 276
#define THEN 277
#define ELSE 278
#define ENDIF 279
#define WHILE 280
#define DO 281
#define ENDWHILE 282
#define REPEAT 283
#define UNTIL 284
#define BREAK 285
#define CONTINUE 286
#define PLUS 287
#define MINUS 288
#define STAR 289
#define DIV 290
#define MOD 291
#define LT 292
#define GT 293
#define LE 294
#define GE 295
#define NE 296
#define EQ 297
#define AND 298
#define OR 299
#define NOT 300
#define ASSGN 301
#define EOS 302
#define COMMA 303
#define ADDR 304
#define DOT 305
#define INT 306
#define STR 307
#define NULL_T 308
#define NUM 309
#define STRING 310
#define ID 311

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

#line 260 "y.tab.c"

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
typedef yytype_int16 yy_state_t;

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
#define YYLAST   679

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  326

#define YYUNDEFTOK  2
#define YYMAXUTOK   311


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
      59,    60,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    65,    69,    74,    77,    80,    81,    84,
      87,    88,    91,    92,    99,   100,   101,   111,   114,   115,
     118,   121,   124,   125,   128,   131,   132,   135,   138,   139,
     142,   143,   144,   149,   150,   153,   154,   157,   160,   161,
     164,   165,   166,   167,   172,   175,   176,   177,   180,   181,
     188,   189,   190,   202,   203,   207,   207,   236,   237,   240,
     241,   244,   247,   248,   251,   256,   260,   261,   262,   275,
     295,   296,   297,   300,   303,   304,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   322,   323,   326,
     327,   328,   331,   334,   337,   338,   339,   340,   341,   342,
     343,   346,   349,   352,   355,   358,   362,   365,   368,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   397,   398,   399,   400,   401,   404,   407,   408,   413,
     418,   421,   422,   423,   426,   427
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START_BLOCK", "END_BLOCK", "DECL",
  "ENDDECL", "TYPE", "ENDTYPE", "CLASS", "ENDCLASS", "READ", "WRITE",
  "INITIALIZE", "ALLOC", "FREE", "MAIN", "RETURN", "NEW", "DELETE", "SELF",
  "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT",
  "UNTIL", "BREAK", "CONTINUE", "PLUS", "MINUS", "STAR", "DIV", "MOD",
  "LT", "GT", "LE", "GE", "NE", "EQ", "AND", "OR", "NOT", "ASSGN", "EOS",
  "COMMA", "ADDR", "DOT", "INT", "STR", "NULL_T", "NUM", "STRING", "ID",
  "'{'", "'}'", "'('", "')'", "'['", "']'", "$accept", "Program",
  "TypeDefBlock", "TypeDefList", "TypeDef", "FieldDeclList", "FieldDecl",
  "Ftype", "CDeclBlock", "ClassDefList", "ClassDef", "Cname", "MemberList",
  "Member", "MethodDecl", "MDecl", "MethodDefns", "CType", "GDeclBlock",
  "GDeclList", "GDecl", "GidList", "Gid", "ParamList", "Param", "DType",
  "FDefBlock", "FDef", "$@1", "LDeclBlock", "LDecList", "LDecl", "LidList",
  "Lid", "PType", "MainBlock", "Body", "RetStmt", "SList", "Stmt",
  "IfStmt", "IterativeStmt", "InputStmt", "OutputStmt", "AsgStmt",
  "BreakStmt", "ContinueStmt", "InitializeStmt", "AllocStmt", "FreeStmt",
  "DeleteStmt", "NewStmt", "Expr", "Identifier", "Field", "FieldFunction",
  "ArgList", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   123,   125,    40,
      41,    91,    93
};
# endif

#define YYPACT_NINF (-142)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      27,    54,    40,    81,    56,     1,  -142,  -142,    37,    59,
     134,   171,   200,  -142,  -142,  -142,  -142,  -142,    -2,  -142,
     -21,  -142,    -3,  -142,    85,    37,   142,   116,   171,  -142,
    -142,  -142,  -142,  -142,   140,  -142,   -20,  -142,  -142,   125,
       5,   101,  -142,  -142,  -142,   172,   171,   120,   126,  -142,
    -142,  -142,  -142,   141,   165,  -142,   219,   160,  -142,   -21,
    -142,  -142,   161,   219,   185,  -142,  -142,  -142,  -142,   -40,
    -142,   -18,   175,  -142,   243,   177,   -19,  -142,   219,  -142,
     182,  -142,   184,  -142,  -142,  -142,  -142,     9,  -142,   191,
     248,  -142,  -142,  -142,   204,    37,  -142,   206,    33,    37,
     266,   223,   224,   152,  -142,   234,  -142,   219,   -17,    16,
    -142,   110,   242,   248,  -142,  -142,  -142,    22,   245,  -142,
     117,  -142,  -142,  -142,  -142,   247,   251,   258,   259,   260,
     377,   264,   274,   269,   271,   325,   325,  -142,  -142,   278,
      67,   337,   229,  -142,   295,   296,   300,   302,   305,   307,
     311,   318,   319,   329,   331,   326,   128,  -142,   266,   335,
    -142,  -142,   -17,   -11,   377,   288,   324,   -10,   336,   377,
     -11,  -142,  -142,  -142,   121,   377,   619,  -142,   350,  -142,
      -9,   345,   377,   377,   349,   253,  -142,   347,   365,   377,
    -142,   400,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,    98,   353,   357,   358,  -142,  -142,
      24,   355,   493,  -142,  -142,    95,    31,   361,   480,  -142,
     367,   506,   377,   377,   377,   377,   377,   377,   377,   377,
     377,   377,   377,   377,   377,  -142,   371,   -29,    34,  -142,
     535,   548,   369,   370,  -142,  -142,   635,    60,   405,  -142,
     375,  -142,  -142,  -142,   635,  -142,  -142,   635,  -142,  -142,
     377,  -142,  -142,  -142,   377,  -142,   376,   404,  -142,   159,
     159,  -142,  -142,  -142,   356,   356,   356,   356,   522,   522,
     480,   436,   406,  -142,   442,   440,   377,   377,   377,  -142,
     123,   451,   418,   449,   377,   377,   377,   325,   325,   577,
     590,   635,   452,   377,   450,   448,   473,    86,   102,   115,
     205,   277,   440,  -142,  -142,   462,  -142,  -142,  -142,  -142,
     325,  -142,  -142,  -142,   301,  -142
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,    34,     0,     0,     8,     1,     0,     0,
      34,     0,     0,     5,     7,    50,    51,    52,     0,    36,
       0,    21,     0,    19,     0,     0,    50,     0,     0,    53,
       4,    14,    15,    16,     0,    11,     0,    33,    35,     0,
      44,     0,    39,    17,    18,     0,     0,     0,     0,    54,
       3,     9,    10,     0,     0,    43,    47,     0,    37,     0,
      23,     2,     0,    47,     0,    12,    66,    67,    68,     0,
      46,     0,     0,    38,     0,     0,     0,    13,     0,    40,
       0,    48,    42,    30,    31,    32,    22,     0,    26,     0,
      58,    55,    45,    49,     0,     0,    25,     0,     0,     0,
       0,     0,     0,     0,    29,     0,    24,    47,     0,     0,
      60,     0,     0,    58,    41,    20,    28,     0,     0,    65,
       0,    63,    57,    59,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   102,     0,
     136,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,     0,     0,
      64,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   128,   129,   136,     0,     0,   125,   126,   127,
       0,     0,     0,     0,     0,     0,   135,     0,     0,     0,
      71,     0,    74,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,    27,    62,
     136,     0,     0,   103,   104,     0,     0,     0,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,     0,     0,     0,   137,
       0,     0,     0,     0,   138,   131,   145,     0,     0,    70,
       0,    99,    98,   100,    94,    95,    97,    96,   140,    56,
       0,    92,    93,   105,     0,   106,   137,   138,   114,   109,
     110,   111,   112,   113,   119,   120,   121,   122,   123,   124,
     115,   116,   140,   107,     0,     0,     0,     0,     0,   132,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,   134,     0,     0,     0,     0,
       0,     0,    90,    91,   139,     0,   108,   141,   142,   143,
       0,    88,    89,   133,     0,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,  -142,  -142,   546,  -142,   518,  -142,  -142,  -142,
     543,  -142,  -142,  -142,  -142,   507,  -142,   509,   583,  -142,
     579,  -142,   539,   -44,   521,    10,   575,   -16,  -142,   488,
    -142,   494,  -142,   443,  -142,    23,   444,   464,  -130,  -141,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,   403,    72,  -142,
    -142,   399,  -127,  -111,  -109,  -142,   -89
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    34,    35,    36,    10,    22,
      23,    24,    74,    86,    87,    88,   103,    89,    11,    18,
      19,    41,    42,    69,    70,    27,    28,    29,   101,   100,
     109,   110,   120,   121,    71,    30,   112,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   253,   246,   177,   178,   179,   247
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     155,   192,   156,   176,    37,   184,   185,    43,    78,    13,
     132,   132,    49,    39,    53,    95,    80,   118,    20,    76,
      79,   187,   122,   139,   155,   155,   156,   156,    20,    78,
      49,   155,   264,   156,     1,    40,    54,   212,    81,   119,
       7,    91,   218,   192,   192,   210,   215,   237,   221,    15,
      16,    50,   211,    21,    17,   240,   241,     4,   216,   219,
      83,    84,   248,   117,    56,    85,    57,    15,    16,    61,
      78,   238,    17,   155,   155,   156,   156,   254,   257,   104,
     106,   206,   159,   188,   206,   260,     8,   116,    15,    16,
       9,   265,   107,    17,   283,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   288,   108,
       4,   127,   128,    12,   124,    21,   250,   187,   168,   108,
     289,   125,   126,   127,   128,   129,   188,   130,   189,   131,
     132,   133,   139,   292,   288,   134,   135,   293,   136,     8,
     137,   138,    45,   169,   139,   187,   317,   170,    58,    59,
     288,   171,   172,   173,   174,   263,   264,   175,    47,   299,
     300,   301,   318,   288,   161,   162,   140,   310,   311,   192,
     192,   220,    48,   302,   205,   319,   315,    60,   206,    62,
     188,    55,   189,   192,   303,    63,   155,   155,   156,   156,
     324,    31,    32,   224,   225,   226,    33,    64,    51,   155,
     155,   156,   156,    15,    16,   307,   308,   309,    17,   155,
     115,   156,    65,   155,    72,   156,   125,   126,   127,   128,
     129,    75,    26,    16,   131,   132,   133,    17,   320,   321,
     134,   135,    77,   136,    90,   137,   138,    82,    93,   139,
     125,   126,   127,   128,   129,    94,   130,    98,   131,   132,
     133,    31,    32,    99,   134,   135,    33,   136,   102,   137,
     138,   140,   105,   139,   125,   126,   127,   128,   129,   111,
      66,    67,   131,   132,   133,    68,   252,   255,   134,   135,
     113,   136,   243,   137,   138,   140,   114,   139,   125,   126,
     127,   128,   129,   107,    83,    84,   131,   132,   133,    85,
     157,   160,   134,   135,   322,   136,   163,   137,   138,   140,
     164,   139,   125,   126,   127,   128,   129,   165,   166,   167,
     131,   132,   133,   180,   181,   325,   134,   135,   182,   136,
     183,   137,   138,   140,   186,   139,   125,   126,   127,   128,
     129,   190,   193,   194,   131,   132,   133,   195,   213,   196,
     134,   135,   197,   136,   198,   137,   138,   140,   199,   139,
     125,   126,   127,   128,   129,   200,   201,   128,   131,   132,
     133,   250,   204,   168,   242,   135,   202,   136,   203,   137,
     138,   140,   208,   139,   214,   168,   217,   139,   222,   223,
     224,   225,   226,    -1,    -1,    -1,    -1,   168,   169,   139,
     236,   239,   170,   244,   249,   140,   171,   172,   173,   174,
     169,   139,   175,   258,   170,   261,   259,   266,   171,   172,
     173,   174,   169,   267,   175,   245,   170,   282,   286,   287,
     171,   172,   173,   174,   291,   294,   175,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   295,   297,   296,   298,   290,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     305,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   304,   314,   303,
     316,   306,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   302,   323,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,    14,    52,   262,   222,   223,   224,   225,   226,   227,
     228,   229,   230,    -1,    -1,    44,   268,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    25,    96,   284,    97,    38,    73,    92,
      46,   158,   207,   123,   256,   209,   191,   251,   285,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     0,     0,   312,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     313,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     0,     0,   235,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234
};

static const yytype_int16 yycheck[] =
{
     111,   142,   111,   130,     6,   135,   136,    10,    48,     8,
      20,    20,    28,    34,    34,     6,    34,    34,     8,    63,
      60,    50,     6,    34,   135,   136,   135,   136,    18,    48,
      46,   142,    61,   142,     7,    56,    56,   164,    56,    56,
       0,    60,   169,   184,   185,    56,    56,    56,   175,    51,
      52,    28,   163,    56,    56,   182,   183,    56,   167,   170,
      51,    52,   189,   107,    59,    56,    61,    51,    52,    46,
      48,   180,    56,   184,   185,   184,   185,   204,   205,    95,
      47,    50,    60,    59,    50,    61,     5,   103,    51,    52,
       9,    60,    59,    56,    60,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,    48,    99,
      56,    13,    14,    57,     4,    56,    18,    50,    20,   109,
      60,    11,    12,    13,    14,    15,    59,    17,    61,    19,
      20,    21,    34,   260,    48,    25,    26,   264,    28,     5,
      30,    31,    57,    45,    34,    50,    60,    49,    47,    48,
      48,    53,    54,    55,    56,    60,    61,    59,    16,   286,
     287,   288,    60,    48,    47,    48,    56,   297,   298,   310,
     311,    50,    56,    50,    46,    60,   303,     5,    50,    59,
      59,    56,    61,   324,    61,    59,   297,   298,   297,   298,
     320,    51,    52,    34,    35,    36,    56,    56,    58,   310,
     311,   310,   311,    51,    52,   294,   295,   296,    56,   320,
      58,   320,    47,   324,    54,   324,    11,    12,    13,    14,
      15,    60,    51,    52,    19,    20,    21,    56,    23,    24,
      25,    26,    47,    28,    57,    30,    31,    62,    56,    34,
      11,    12,    13,    14,    15,    61,    17,    56,    19,    20,
      21,    51,    52,     5,    25,    26,    56,    28,    54,    30,
      31,    56,    56,    34,    11,    12,    13,    14,    15,     3,
      51,    52,    19,    20,    21,    56,   204,   205,    25,    26,
      57,    28,    29,    30,    31,    56,    62,    34,    11,    12,
      13,    14,    15,    59,    51,    52,    19,    20,    21,    56,
      58,    56,    25,    26,    27,    28,    59,    30,    31,    56,
      59,    34,    11,    12,    13,    14,    15,    59,    59,    59,
      19,    20,    21,    59,    50,    24,    25,    26,    59,    28,
      59,    30,    31,    56,    56,    34,    11,    12,    13,    14,
      15,     4,    47,    47,    19,    20,    21,    47,    60,    47,
      25,    26,    47,    28,    47,    30,    31,    56,    47,    34,
      11,    12,    13,    14,    15,    47,    47,    14,    19,    20,
      21,    18,    46,    20,    25,    26,    47,    28,    47,    30,
      31,    56,    47,    34,    60,    20,    50,    34,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    20,    45,    34,
      50,    56,    49,    56,     4,    56,    53,    54,    55,    56,
      45,    34,    59,    56,    49,    60,    58,    56,    53,    54,
      55,    56,    45,    56,    59,    60,    49,    56,    59,    59,
      53,    54,    55,    56,    59,    59,    59,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    59,    22,    59,    26,    62,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      62,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    56,    56,    61,
      60,    62,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    50,    62,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     5,    34,    60,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    22,    60,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    10,    87,    60,    87,    18,    59,    78,
      25,   113,   158,   109,   205,   162,   142,   204,    60,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    64,    65,    56,    66,    67,     0,     5,     9,
      71,    81,    57,     8,    67,    51,    52,    56,    82,    83,
      88,    56,    72,    73,    74,    81,    51,    88,    89,    90,
      98,    51,    52,    56,    68,    69,    70,     6,    83,    34,
      56,    84,    85,    10,    73,    57,    89,    16,    56,    90,
      98,    58,    69,    34,    56,    56,    59,    61,    47,    48,
       5,    98,    59,    59,    56,    47,    51,    52,    56,    86,
      87,    97,    54,    85,    75,    60,    86,    47,    48,    60,
      34,    56,    62,    51,    52,    56,    76,    77,    78,    80,
      57,    60,    87,    56,    61,     6,    78,    80,    56,     5,
      92,    91,    54,    79,    90,    56,    47,    59,    88,    93,
      94,     3,    99,    57,    62,    58,    90,    86,    34,    56,
      95,    96,     6,    94,     4,    11,    12,    13,    14,    15,
      17,    19,    20,    21,    25,    26,    28,    30,    31,    34,
      56,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   116,   117,    58,    92,    60,
      56,    47,    48,    59,    59,    59,    59,    59,    20,    45,
      49,    53,    54,    55,    56,    59,   115,   116,   117,   118,
      59,    50,    59,    59,   101,   101,    56,    50,    59,    61,
       4,   100,   102,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    46,    46,    50,    99,    47,    96,
      56,   116,   115,    60,    60,    56,   117,    50,   115,   116,
      50,   115,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    47,    50,    56,   117,    56,
     115,   115,    25,    29,    56,    60,   115,   119,   115,     4,
      18,   110,   111,   114,   115,   111,   114,   115,    56,    58,
      61,    60,    60,    60,    61,    60,    56,    56,    60,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,    56,    60,    60,    60,    59,    59,    48,    60,
      62,    59,   115,   115,    59,    59,    59,    22,    26,   115,
     115,   115,    50,    61,    56,    62,    62,   119,   119,   119,
     101,   101,    60,    60,    56,   115,    60,    60,    60,    60,
      23,    24,    27,    62,   101,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    64,    64,    65,    65,    66,    66,    67,
      68,    68,    69,    69,    70,    70,    70,    71,    72,    72,
      73,    74,    75,    75,    76,    77,    77,    78,    79,    79,
      80,    80,    80,    81,    81,    82,    82,    83,    84,    84,
      85,    85,    85,    85,    85,    86,    86,    86,    87,    87,
      88,    88,    88,    89,    89,    91,    90,    92,    92,    93,
      93,    94,    95,    95,    96,    96,    97,    97,    97,    98,
      99,    99,    99,   100,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   103,   103,   104,
     104,   104,   105,   106,   107,   107,   107,   107,   107,   107,
     107,   108,   109,   110,   111,   112,   112,   113,   114,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   116,   116,   116,   116,   116,   116,   117,   117,   117,
     117,   118,   118,   118,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     3,     0,     2,     1,     4,
       2,     1,     3,     4,     1,     1,     1,     3,     2,     1,
       8,     1,     2,     0,     3,     2,     1,     6,     2,     1,
       1,     1,     1,     3,     0,     2,     1,     3,     3,     1,
       4,     7,     4,     2,     1,     3,     1,     0,     2,     3,
       1,     1,     1,     1,     2,     0,    10,     3,     0,     2,
       1,     3,     3,     1,     2,     1,     1,     1,     1,     8,
       4,     3,     2,     3,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     9,     7,     7,
       6,     6,     4,     4,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     3,     3,     4,     4,     4,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     7,     4,     2,     1,     3,     3,     6,
       3,     6,     6,     6,     3,     1
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
#line 61 "abstree.y"
                                                                        {

                                                                        }
#line 1734 "y.tab.c"
    break;

  case 3:
#line 65 "abstree.y"
                                                                {
                                                                    // printGST();
                                                                    // fprintf(stdout,"parsing successful!\n");
                                                                }
#line 1743 "y.tab.c"
    break;

  case 4:
#line 69 "abstree.y"
                                                                {
                                                                    // printGST();
                                                                }
#line 1751 "y.tab.c"
    break;

  case 5:
#line 74 "abstree.y"
                                                { 
                                                    // printTypeTable();
                                                }
#line 1759 "y.tab.c"
    break;

  case 9:
#line 84 "abstree.y"
                                                {TInstall((yyvsp[-3].idName), 1, Fhead); Fhead = NULL;}
#line 1765 "y.tab.c"
    break;

  case 12:
#line 91 "abstree.y"
                                        {FInstall((yyvsp[-1].idName), FieldType);}
#line 1771 "y.tab.c"
    break;

  case 13:
#line 92 "abstree.y"
                                        {
                                            struct TypeTable *ptrType = FieldType == TLookup("integer") ?
                                            TLookup("integer_ptr") : TLookup("string_ptr");
                                            FInstall((yyvsp[-1].idName), ptrType);
                                        }
#line 1781 "y.tab.c"
    break;

  case 14:
#line 99 "abstree.y"
                                    {FieldType = TLookup("integer"); (yyval.idType) = TLookup("integer");}
#line 1787 "y.tab.c"
    break;

  case 15:
#line 100 "abstree.y"
                                    {FieldType = TLookup("string"); (yyval.idType) = TLookup("string");}
#line 1793 "y.tab.c"
    break;

  case 16:
#line 101 "abstree.y"
                                    {
                                        FieldType = TLookup((yyvsp[0].idName)); 
                                        (yyval.idType) = TLookup((yyvsp[0].idName));
                                        if(FieldType == NULL){
                                            FieldType = TLookup("dummy");
                                        }
                                    }
#line 1805 "y.tab.c"
    break;

  case 40:
#line 164 "abstree.y"
                                            {GInstall((yyvsp[-3].idName), DeclType, -1, -1, -1, Phead);}
#line 1811 "y.tab.c"
    break;

  case 41:
#line 165 "abstree.y"
                                            {GInstall((yyvsp[-6].idName), DeclType, (yyvsp[-4].intVal)*(yyvsp[-1].intVal), (yyvsp[-4].intVal), (yyvsp[-1].intVal), NULL);}
#line 1817 "y.tab.c"
    break;

  case 42:
#line 166 "abstree.y"
                                            {GInstall((yyvsp[-3].idName), DeclType, (yyvsp[-1].intVal), (yyvsp[-1].intVal), -1, NULL);}
#line 1823 "y.tab.c"
    break;

  case 43:
#line 167 "abstree.y"
                                            {
                                                struct TypeTable *ptrType = DeclType == TLookup("integer") ?
                                                TLookup("integer_ptr") : TLookup("string_ptr"); 
                                                GInstall((yyvsp[0].idName), ptrType, DeclType->size, -1, -1, NULL);
                                            }
#line 1833 "y.tab.c"
    break;

  case 44:
#line 172 "abstree.y"
                                            {GInstall((yyvsp[0].idName), DeclType, DeclType->size, -1, -1, NULL);}
#line 1839 "y.tab.c"
    break;

  case 48:
#line 180 "abstree.y"
                                        {PInstall((yyvsp[0].idName), ParamType);}
#line 1845 "y.tab.c"
    break;

  case 49:
#line 181 "abstree.y"
                                        {
                                            struct TypeTable *ptrType = ParamType == TLookup("integer") ?
                                            TLookup("integer_ptr") : TLookup("string_ptr"); 
                                            PInstall((yyvsp[0].idName), ptrType);
                                        }
#line 1855 "y.tab.c"
    break;

  case 50:
#line 188 "abstree.y"
                                    {DeclType = TLookup("integer");(yyval.idType) = TLookup("integer");}
#line 1861 "y.tab.c"
    break;

  case 51:
#line 189 "abstree.y"
                                    {DeclType = TLookup("string");(yyval.idType) = TLookup("string");}
#line 1867 "y.tab.c"
    break;

  case 52:
#line 190 "abstree.y"
                                    {
                                        DeclType = TLookup((yyvsp[0].idName)); 
                                        if(DeclType == NULL){
                                            fprintf(stderr, "Type not declared: %s\n", (yyvsp[0].idName));
                                            exit(1);
                                        }
                                        (yyval.idType) = TLookup((yyvsp[0].idName));
                                    }
#line 1880 "y.tab.c"
    break;

  case 55:
#line 207 "abstree.y"
                                                 {
                                                    PInstallLST((yyvsp[-3].idName));    // Insert params to Local symbol Table
                                                    total_params = validateParams((yyvsp[-3].idName), Phead);  // check name equivalence of the parameters
                                                    freeParamList();    // Free the unwanted paramlist formed from the Fdef block, we will use the paramlist from GST
                                                }
#line 1890 "y.tab.c"
    break;

  case 56:
#line 212 "abstree.y"
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
                                                        addr++;
                                                        temp = temp->next;
                                                    }
                                                    // printLST($2);
                                                    // codeGenFunc($9, $2);
                                                    FreeLST();
                                                }
#line 1917 "y.tab.c"
    break;

  case 64:
#line 251 "abstree.y"
                                                {
                                                    struct TypeTable *ptrType = DeclType == TLookup("integer") ?
                                                    TLookup("integer_ptr") : TLookup("string_ptr"); 
                                                    LInstall((yyvsp[0].idName), ptrType);
                                                }
#line 1927 "y.tab.c"
    break;

  case 65:
#line 256 "abstree.y"
                                                {LInstall((yyvsp[0].idName), DeclType);}
#line 1933 "y.tab.c"
    break;

  case 66:
#line 260 "abstree.y"
                                    {ParamType = TLookup("integer");}
#line 1939 "y.tab.c"
    break;

  case 67:
#line 261 "abstree.y"
                                    {ParamType = TLookup("string");}
#line 1945 "y.tab.c"
    break;

  case 68:
#line 262 "abstree.y"
                                    {
                                        ParamType = TLookup((yyvsp[0].idName)); 
                                        if(ParamType == NULL){
                                            fprintf(stderr, "Type not declared: %s\n", (yyvsp[0].idName));
                                            exit(1);
                                        }
                                        (yyval.idType) = TLookup((yyvsp[0].idName));
                                    }
#line 1958 "y.tab.c"
    break;

  case 69:
#line 275 "abstree.y"
                                                           {
                                                                if((yyvsp[-1].node)->right->type != TLookup("integer")){
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
                                                                // printLST("main");
                                                                // codeGenMain($7);
                                                                FreeLST();
                                                            }
#line 1981 "y.tab.c"
    break;

  case 70:
#line 295 "abstree.y"
                                                            {(yyval.node) = makeConnNode((yyvsp[-2].node), (yyvsp[-1].node));}
#line 1987 "y.tab.c"
    break;

  case 71:
#line 296 "abstree.y"
                                                            {(yyval.node) = makeConnNode(NULL, (yyvsp[-1].node));}
#line 1993 "y.tab.c"
    break;

  case 72:
#line 297 "abstree.y"
                                                            {(yyval.node) = makeConnNode(NULL, NULL);}
#line 1999 "y.tab.c"
    break;

  case 73:
#line 300 "abstree.y"
                                        {(yyval.node) = makeRetNode((yyvsp[-1].node));}
#line 2005 "y.tab.c"
    break;

  case 74:
#line 303 "abstree.y"
                                        {(yyval.node) = makeConnNode((yyvsp[-1].node), (yyvsp[0].node));}
#line 2011 "y.tab.c"
    break;

  case 75:
#line 304 "abstree.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 2017 "y.tab.c"
    break;

  case 76:
#line 307 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2023 "y.tab.c"
    break;

  case 77:
#line 308 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2029 "y.tab.c"
    break;

  case 78:
#line 309 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2035 "y.tab.c"
    break;

  case 79:
#line 310 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2041 "y.tab.c"
    break;

  case 80:
#line 311 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2047 "y.tab.c"
    break;

  case 81:
#line 312 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2053 "y.tab.c"
    break;

  case 82:
#line 313 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2059 "y.tab.c"
    break;

  case 83:
#line 314 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2065 "y.tab.c"
    break;

  case 84:
#line 315 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2071 "y.tab.c"
    break;

  case 85:
#line 316 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2077 "y.tab.c"
    break;

  case 87:
#line 322 "abstree.y"
                                                                {(yyval.node) = makeIfElseNode((yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-1].node));}
#line 2083 "y.tab.c"
    break;

  case 88:
#line 323 "abstree.y"
                                                                {(yyval.node) = makeIfElseNode((yyvsp[-4].node), (yyvsp[-1].node), NULL);}
#line 2089 "y.tab.c"
    break;

  case 89:
#line 326 "abstree.y"
                                                                {(yyval.node) = makeIterationNode(NODE_WHILE, (yyvsp[-4].node), (yyvsp[-1].node));}
#line 2095 "y.tab.c"
    break;

  case 90:
#line 327 "abstree.y"
                                                                {(yyval.node) = makeIterationNode(NODE_DOWHILE, (yyvsp[-1].node), (yyvsp[-4].node));}
#line 2101 "y.tab.c"
    break;

  case 91:
#line 328 "abstree.y"
                                                                {(yyval.node) = makeIterationNode(NODE_REPEAT, (yyvsp[-1].node), (yyvsp[-4].node));}
#line 2107 "y.tab.c"
    break;

  case 92:
#line 331 "abstree.y"
                                                    {(yyval.node) = makeReadNode((yyvsp[-1].node));}
#line 2113 "y.tab.c"
    break;

  case 93:
#line 334 "abstree.y"
                                                    {(yyval.node) = makeWriteNode((yyvsp[-1].node));}
#line 2119 "y.tab.c"
    break;

  case 94:
#line 337 "abstree.y"
                                                    {(yyval.node) = makeAssgnNode((yyvsp[-2].node), (yyvsp[0].node));}
#line 2125 "y.tab.c"
    break;

  case 95:
#line 338 "abstree.y"
                                                    {(yyval.node) = makeAssgnNode((yyvsp[-2].node), (yyvsp[0].node));}
#line 2131 "y.tab.c"
    break;

  case 96:
#line 339 "abstree.y"
                                                    {(yyval.node) = makeAssgnNode((yyvsp[-2].node), (yyvsp[0].node));}
#line 2137 "y.tab.c"
    break;

  case 98:
#line 341 "abstree.y"
                                                    {(yyval.node) = makeAssgnNode((yyvsp[-2].node), (yyvsp[0].node));}
#line 2143 "y.tab.c"
    break;

  case 99:
#line 342 "abstree.y"
                                                    {(yyval.node) = makeAssgnNode((yyvsp[-2].node), (yyvsp[0].node));}
#line 2149 "y.tab.c"
    break;

  case 101:
#line 346 "abstree.y"
                                        {(yyval.node) = makeBreakNode();}
#line 2155 "y.tab.c"
    break;

  case 102:
#line 349 "abstree.y"
                                        {(yyval.node) = makeContinueNode();}
#line 2161 "y.tab.c"
    break;

  case 103:
#line 352 "abstree.y"
                                        {(yyval.node) = makeInitNode();}
#line 2167 "y.tab.c"
    break;

  case 104:
#line 355 "abstree.y"
                                        {(yyval.node) = makeAllocNode();}
#line 2173 "y.tab.c"
    break;

  case 105:
#line 358 "abstree.y"
                                        {
                                            ASTNode* id = makeLeafNode(0, NULL, TLookup("dummy"), (yyvsp[-1].idName));
                                            (yyval.node) = makeFreeNode(id);
                                        }
#line 2182 "y.tab.c"
    break;

  case 106:
#line 362 "abstree.y"
                                        {(yyval.node) = makeFreeNode((yyvsp[-1].node));}
#line 2188 "y.tab.c"
    break;

  case 107:
#line 365 "abstree.y"
                                            {(yyval.node) = NULL;}
#line 2194 "y.tab.c"
    break;

  case 109:
#line 373 "abstree.y"
                                        {(yyval.node) = makeArithOPNode(NODE_ADD, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2200 "y.tab.c"
    break;

  case 110:
#line 374 "abstree.y"
                                        {(yyval.node) = makeArithOPNode(NODE_SUB, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2206 "y.tab.c"
    break;

  case 111:
#line 375 "abstree.y"
                                        {(yyval.node) = makeArithOPNode(NODE_MUL, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2212 "y.tab.c"
    break;

  case 112:
#line 376 "abstree.y"
                                        {(yyval.node) = makeArithOPNode(NODE_DIV, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2218 "y.tab.c"
    break;

  case 113:
#line 377 "abstree.y"
                                        {(yyval.node) = makeArithOPNode(NODE_MOD, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2224 "y.tab.c"
    break;

  case 114:
#line 378 "abstree.y"
                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2230 "y.tab.c"
    break;

  case 115:
#line 379 "abstree.y"
                                        {(yyval.node) = makeLogicOPNode(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2236 "y.tab.c"
    break;

  case 116:
#line 380 "abstree.y"
                                        {(yyval.node) = makeLogicOPNode(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2242 "y.tab.c"
    break;

  case 117:
#line 381 "abstree.y"
                                        {(yyval.node) = makeLogicOPNode(NODE_NOT, (yyvsp[0].node), NULL);}
#line 2248 "y.tab.c"
    break;

  case 118:
#line 382 "abstree.y"
                                        {(yyval.node) = makeAddrNode((yyvsp[0].node));}
#line 2254 "y.tab.c"
    break;

  case 119:
#line 383 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_LT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2260 "y.tab.c"
    break;

  case 120:
#line 384 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_GT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2266 "y.tab.c"
    break;

  case 121:
#line 385 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_LE, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2272 "y.tab.c"
    break;

  case 122:
#line 386 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_GE, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2278 "y.tab.c"
    break;

  case 123:
#line 387 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_NE, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2284 "y.tab.c"
    break;

  case 124:
#line 388 "abstree.y"
                                        {(yyval.node) = makeRelOPNode(NODE_EQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2290 "y.tab.c"
    break;

  case 125:
#line 389 "abstree.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 2296 "y.tab.c"
    break;

  case 126:
#line 390 "abstree.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 2302 "y.tab.c"
    break;

  case 127:
#line 391 "abstree.y"
                                        {(yyval.node) = NULL;}
#line 2308 "y.tab.c"
    break;

  case 128:
#line 392 "abstree.y"
                                        {(yyval.node) = makeLeafNode((yyvsp[0].intVal), NULL, TLookup("integer"), NULL);}
#line 2314 "y.tab.c"
    break;

  case 129:
#line 393 "abstree.y"
                                        {(yyval.node) = makeLeafNode(0, (yyvsp[0].strVal), TLookup("string"), NULL);}
#line 2320 "y.tab.c"
    break;

  case 130:
#line 394 "abstree.y"
                                        {(yyval.node) = makeNullNode();}
#line 2326 "y.tab.c"
    break;

  case 131:
#line 397 "abstree.y"
                                            {(yyval.node) = makeFuncNode((yyvsp[-2].idName), TLookup("dummy"), NULL);}
#line 2332 "y.tab.c"
    break;

  case 132:
#line 398 "abstree.y"
                                            {(yyval.node) = makeFuncNode((yyvsp[-3].idName), TLookup("dummy"), (yyvsp[-1].node));}
#line 2338 "y.tab.c"
    break;

  case 133:
#line 399 "abstree.y"
                                            {(yyval.node) = makeArrayNode((yyvsp[-6].idName), TLookup("dummy"), (yyvsp[-4].node), (yyvsp[-1].node));}
#line 2344 "y.tab.c"
    break;

  case 134:
#line 400 "abstree.y"
                                            {(yyval.node) = makeArrayNode((yyvsp[-3].idName), TLookup("dummy"), (yyvsp[-1].node), NULL);}
#line 2350 "y.tab.c"
    break;

  case 135:
#line 401 "abstree.y"
                                            {
                                                ASTNode *id = makeLeafNode(0, NULL, TLookup("dummy"), (yyvsp[0].idName));
                                                (yyval.node) = makePtrNode(id);}
#line 2358 "y.tab.c"
    break;

  case 136:
#line 404 "abstree.y"
                                            {(yyval.node) = makeLeafNode(0, NULL, TLookup("dummy"), (yyvsp[0].idName));}
#line 2364 "y.tab.c"
    break;

  case 137:
#line 407 "abstree.y"
                                            {(yyval.node) = NULL;}
#line 2370 "y.tab.c"
    break;

  case 138:
#line 408 "abstree.y"
                                            {
                                                ASTNode *id = makeLeafNode(0, NULL, TLookup("dummy"), (yyvsp[-2].idName));
                                                (yyval.node) = makeFieldNode(id, (yyvsp[0].idName));
                                                // this will not occur inside a class
                                            }
#line 2380 "y.tab.c"
    break;

  case 139:
#line 413 "abstree.y"
                                            {
                                                ASTNode *id = makeArrayNode((yyvsp[-5].idName), TLookup("dummy"), (yyvsp[-3].node), NULL);
                                                (yyval.node) = makeFieldNode(id, (yyvsp[0].idName));
                                                
                                            }
#line 2390 "y.tab.c"
    break;

  case 140:
#line 418 "abstree.y"
                                            {(yyval.node) = makeFieldNode((yyvsp[-2].node), (yyvsp[0].idName));}
#line 2396 "y.tab.c"
    break;

  case 144:
#line 426 "abstree.y"
                                            {(yyval.node) = makeArgNode((yyvsp[-2].node), (yyvsp[0].node));}
#line 2402 "y.tab.c"
    break;

  case 145:
#line 427 "abstree.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 2408 "y.tab.c"
    break;


#line 2412 "y.tab.c"

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
#line 430 "abstree.y"


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
