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
    READ = 262,
    WRITE = 263,
    IF = 264,
    THEN = 265,
    ELSE = 266,
    ENDIF = 267,
    WHILE = 268,
    DO = 269,
    ENDWHILE = 270,
    REPEAT = 271,
    UNTIL = 272,
    BREAK = 273,
    CONTINUE = 274,
    PLUS = 275,
    MINUS = 276,
    MUL = 277,
    DIV = 278,
    MOD = 279,
    LT = 280,
    GT = 281,
    LE = 282,
    GE = 283,
    NE = 284,
    EQ = 285,
    ASSGN = 286,
    EOS = 287,
    COMMA = 288,
    INT = 289,
    STR = 290,
    NUM = 291,
    STRING = 292,
    ID = 293
  };
#endif
/* Tokens.  */
#define START_BLOCK 258
#define END_BLOCK 259
#define DECL 260
#define ENDDECL 261
#define READ 262
#define WRITE 263
#define IF 264
#define THEN 265
#define ELSE 266
#define ENDIF 267
#define WHILE 268
#define DO 269
#define ENDWHILE 270
#define REPEAT 271
#define UNTIL 272
#define BREAK 273
#define CONTINUE 274
#define PLUS 275
#define MINUS 276
#define MUL 277
#define DIV 278
#define MOD 279
#define LT 280
#define GT 281
#define LE 282
#define GE 283
#define NE 284
#define EQ 285
#define ASSGN 286
#define EOS 287
#define COMMA 288
#define INT 289
#define STR 290
#define NUM 291
#define STRING 292
#define ID 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

    struct ASTNode *node;
    struct Gsymbol *stEntry;
    int idType;
    char* idName;
    int intVal;
    char* strVal;

#line 142 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
