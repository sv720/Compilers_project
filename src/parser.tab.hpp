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

  #include "ast.hpp"

  #include <cassert>
  #include <iostream>
  #include <fstream>

  extern const Expression *g_root; // A way of getting the AST out
  extern FILE *yyin;
  // ! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 65 "src/parser.tab.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INT_LITERAL = 259,             /* INT_LITERAL  */
    CHAR_LITERAL = 260,            /* CHAR_LITERAL  */
    SIZEOF = 261,                  /* SIZEOF  */
    FLOAT_LITERAL = 262,           /* FLOAT_LITERAL  */
    POINTER_OP = 263,              /* POINTER_OP  */
    INCREMENT_OP = 264,            /* INCREMENT_OP  */
    DECREMENT_OP = 265,            /* DECREMENT_OP  */
    LEFTSHIFT_OP = 266,            /* LEFTSHIFT_OP  */
    RIGHTSHIFT_OP = 267,           /* RIGHTSHIFT_OP  */
    LE_OP = 268,                   /* LE_OP  */
    GE_OP = 269,                   /* GE_OP  */
    EQ_OP = 270,                   /* EQ_OP  */
    NE_OP = 271,                   /* NE_OP  */
    AND_OP = 272,                  /* AND_OP  */
    OR_OP = 273,                   /* OR_OP  */
    MUL_ASSIGN = 274,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 275,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 276,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 277,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 278,              /* SUB_ASSIGN  */
    LEFTSHIFT_ASSIGN = 279,        /* LEFTSHIFT_ASSIGN  */
    RIGHTSHIFT_ASSIGN = 280,       /* RIGHTSHIFT_ASSIGN  */
    AND_ASSIGN = 281,              /* AND_ASSIGN  */
    XOR_ASSIGN = 282,              /* XOR_ASSIGN  */
    OR_ASSIGN = 283,               /* OR_ASSIGN  */
    TYPE_NAME = 284,               /* TYPE_NAME  */
    TYPEDEF = 285,                 /* TYPEDEF  */
    EXTERN = 286,                  /* EXTERN  */
    STATIC = 287,                  /* STATIC  */
    AUTO = 288,                    /* AUTO  */
    REGISTER = 289,                /* REGISTER  */
    CHAR = 290,                    /* CHAR  */
    SHORT = 291,                   /* SHORT  */
    INT = 292,                     /* INT  */
    LONG = 293,                    /* LONG  */
    SIGNED = 294,                  /* SIGNED  */
    UNSIGNED = 295,                /* UNSIGNED  */
    FLOAT = 296,                   /* FLOAT  */
    DOUBLE = 297,                  /* DOUBLE  */
    CONST = 298,                   /* CONST  */
    VOLATILE = 299,                /* VOLATILE  */
    VOID = 300,                    /* VOID  */
    STRUCT = 301,                  /* STRUCT  */
    UNION = 302,                   /* UNION  */
    ENUM = 303,                    /* ENUM  */
    ELLIPSIS = 304,                /* ELLIPSIS  */
    CASE = 305,                    /* CASE  */
    DEFAULT = 306,                 /* DEFAULT  */
    IF = 307,                      /* IF  */
    ELSE = 308,                    /* ELSE  */
    SWITCH = 309,                  /* SWITCH  */
    WHILE = 310,                   /* WHILE  */
    DO = 311,                      /* DO  */
    FOR = 312,                     /* FOR  */
    GOTO = 313,                    /* GOTO  */
    CONTINUE = 314,                /* CONTINUE  */
    BREAK = 315,                   /* BREAK  */
    RETURN = 316,                  /* RETURN  */
    uminu = 317,                   /* uminu  */
    NOELSE = 318                   /* NOELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "src/parser.y"

  Expression *expr;
  ExpressionList *expressionList;
  int integer;
  float numberFloat;
  double numberDouble;
  std::string *string;
  yytokentype token;

#line 155 "src/parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
