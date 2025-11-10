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

#line 167 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
