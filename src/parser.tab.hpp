/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

  #include "../include/ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 63 "src/parser.tab.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_TIMES = 258,                 /* T_TIMES  */
    T_DIVIDE = 259,                /* T_DIVIDE  */
    T_PLUS = 260,                  /* T_PLUS  */
    T_MINUS = 261,                 /* T_MINUS  */
    T_EXPONENT = 262,              /* T_EXPONENT  */
    T_EQUAL = 263,                 /* T_EQUAL  */
    T_LBRACKET = 264,              /* T_LBRACKET  */
    T_RBRACKET = 265,              /* T_RBRACKET  */
    T_LCURBRACKET = 266,           /* T_LCURBRACKET  */
    T_RCULBRACKET = 267,           /* T_RCULBRACKET  */
    T_SEMICOLON = 268,             /* T_SEMICOLON  */
    T_COMMA = 269,                 /* T_COMMA  */
    T_LSQBRACKET = 270,            /* T_LSQBRACKET  */
    T_RSQBRACKET = 271,            /* T_RSQBRACKET  */
    T_COLON = 272,                 /* T_COLON  */
    T_TILDE = 273,                 /* T_TILDE  */
    T_HASH = 274,                  /* T_HASH  */
    T_EXCLAMATIONMARK = 275,       /* T_EXCLAMATIONMARK  */
    T_QUESTIONMARK = 276,          /* T_QUESTIONMARK  */
    T_LOG = 277,                   /* T_LOG  */
    T_EXP = 278,                   /* T_EXP  */
    T_SQRT = 279,                  /* T_SQRT  */
    T_RETURN = 280,                /* T_RETURN  */
    T_IF = 281,                    /* T_IF  */
    T_WHILE = 282,                 /* T_WHILE  */
    T_FOR = 283,                   /* T_FOR  */
    T_BREAK = 284,                 /* T_BREAK  */
    T_NUMBER = 285,                /* T_NUMBER  */
    T_VALUE = 286,                 /* T_VALUE  */
    T_VARIABLE = 287,              /* T_VARIABLE  */
    T_TYPE = 288,                  /* T_TYPE  */
    FUNCTION_NAME = 289            /* FUNCTION_NAME  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "src/parser.y"

  const Expression *expr;
  double number;
  std::string *string;

#line 120 "src/parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
