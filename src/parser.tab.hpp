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

#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y"

  #include "ast.hpp"

  #include <cassert>

  #include <iostream>

  extern const Expression *g_root; // A way of getting the AST out

  // ! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 64 "src/parser.tab.hpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INT = 258,
    T_VOID = 259,
    T_IDENTIFIER = 260,
    T_RETURN = 261,
    T_NUMBER = 262,
    T_VARIABLE = 263,
    MUL_ASSIGN = 264,
    DIV_ASSIGN = 265,
    MOD_ASSIGN = 266,
    ADD_ASSIGN = 267,
    SUB_ASSIGN = 268,
    LEFTSHIFT_ASSIGN = 269,
    RIGHTSHIFT_ASSIGN = 270,
    AND_ASSIGN = 271,
    XOR_ASSIGN = 272,
    OR_ASSIGN = 273,
    INC_OP = 274,
    DEC_OP = 275,
    LEFTSHIFT_OP = 276,
    RIGHTSHIFT_OP = 277,
    LE_OP = 278,
    GE_OP = 279,
    EQ_OP = 280,
    NE_OP = 281,
    AND_OP = 282,
    OR_OP = 283,
    PTR_OP = 284,
    T_TIMES = 285,
    T_DIVIDE = 286,
    T_PLUS = 287,
    T_MINUS = 288
  };
#endif
/* Tokens.  */
#define T_INT 258
#define T_VOID 259
#define T_IDENTIFIER 260
#define T_RETURN 261
#define T_NUMBER 262
#define T_VARIABLE 263
#define MUL_ASSIGN 264
#define DIV_ASSIGN 265
#define MOD_ASSIGN 266
#define ADD_ASSIGN 267
#define SUB_ASSIGN 268
#define LEFTSHIFT_ASSIGN 269
#define RIGHTSHIFT_ASSIGN 270
#define AND_ASSIGN 271
#define XOR_ASSIGN 272
#define OR_ASSIGN 273
#define INC_OP 274
#define DEC_OP 275
#define LEFTSHIFT_OP 276
#define RIGHTSHIFT_OP 277
#define LE_OP 278
#define GE_OP 279
#define EQ_OP 280
#define NE_OP 281
#define AND_OP 282
#define OR_OP 283
#define PTR_OP 284
#define T_TIMES 285
#define T_DIVIDE 286
#define T_PLUS 287
#define T_MINUS 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "src/parser.y"

  const Expression *expr;
  ExpressionList *exprList;
  double number;
  std::string *string;

#line 148 "src/parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
