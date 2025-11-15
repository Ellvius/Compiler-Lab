/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    DOT = 304,
    NULL_T = 305,
    NUM = 306,
    STRING = 307,
    ID = 308
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
#define DOT 304
#define NULL_T 305
#define NUM 306
#define STRING 307
#define ID 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "abstree.y"

    struct ASTNode* node;
    char* idName;
    int intVal;
    char* strVal;

#line 170 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
