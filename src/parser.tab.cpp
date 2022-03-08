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

#line 126 "src/parser.tab.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    INT_LITERAL = 259,
    STRING_LITERAL = 260,
    SIZEOF = 261,
    POINTER_OP = 262,
    INCREMENT_OP = 263,
    DECREMENT_OP = 264,
    LEFTSHIFT_OP = 265,
    RIGHTSHIFT_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    AND_OP = 271,
    OR_OP = 272,
    MUL_ASSIGN = 273,
    DIV_ASSIGN = 274,
    MOD_ASSIGN = 275,
    ADD_ASSIGN = 276,
    SUB_ASSIGN = 277,
    LEFTSHIFT_ASSIGN = 278,
    RIGHTSHIFT_ASSIGN = 279,
    AND_ASSIGN = 280,
    XOR_ASSIGN = 281,
    OR_ASSIGN = 282,
    TYPE_NAME = 283,
    TYPEDEF = 284,
    EXTERN = 285,
    STATIC = 286,
    AUTO = 287,
    REGISTER = 288,
    CHAR = 289,
    SHORT = 290,
    INT = 291,
    LONG = 292,
    SIGNED = 293,
    UNSIGNED = 294,
    FLOAT = 295,
    DOUBLE = 296,
    CONST = 297,
    VOLATILE = 298,
    VOID = 299,
    STRUCT = 300,
    UNION = 301,
    ENUM = 302,
    ELLIPSIS = 303,
    CASE = 304,
    DEFAULT = 305,
    IF = 306,
    ELSE = 307,
    SWITCH = 308,
    WHILE = 309,
    DO = 310,
    FOR = 311,
    GOTO = 312,
    CONTINUE = 313,
    BREAK = 314,
    RETURN = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "src/parser.y"

  const Expression *expr;
  ExprList *vectorList;
  ExpressionList *expressionList;
  int number;
  double numberFloat;
  std::string *string;
  yytokentype token;

#line 208 "src/parser.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */



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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   845

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  306

#define YYUNDEFTOK  2
#define YYMAXUTOK   315


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
       2,     2,     2,    77,     2,     2,     2,    79,    73,     2,
      61,    62,    74,    75,    65,    72,    71,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    70,    66,
      80,    67,    81,    84,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    82,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,    83,    69,    76,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    75,    75,    83,    84,    88,    93,    97,    98,   102,
     103,   104,   105,   106,   107,   112,   113,   117,   118,   119,
     124,   125,   130,   131,   132,   133,   139,   140,   145,   146,
     147,   151,   152,   156,   157,   158,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   175,   176,   177,   179,   186,
     187,   192,   193,   197,   198,   199,   200,   201,   202,   211,
     212,   213,   217,   218,   222,   223,   224,   228,   229,   230,
     231,   235,   236,   237,   238,   239,   245,   246,   249,   253,
     254,   255,   256,   257,   258,   259,   260,   264,   265,   269,
     270,   271,   272,   273,   274,   275,   279,   280,   281,   282,
     283,   284,   288,   289,   293,   294,   295,   296,   300,   301,
     302,   306,   307,   308,   312,   313,   314,   315,   316,   320,
     321,   322,   326,   327,   331,   332,   336,   337,   341,   342,
     346,   347,   351,   352,   356,   357,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   375,   376,   380,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   398,
     422,   423,   424,   425,   440,   441,   442,   446,   447,   451,
     452,   456,   457,   461,   462,   463,   464,   468,   469,   476,
     477,   481,   482
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INT_LITERAL",
  "STRING_LITERAL", "SIZEOF", "POINTER_OP", "INCREMENT_OP", "DECREMENT_OP",
  "LEFTSHIFT_OP", "RIGHTSHIFT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFTSHIFT_ASSIGN", "RIGHTSHIFT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPE_NAME", "TYPEDEF",
  "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR", "SHORT", "INT", "LONG",
  "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID",
  "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN",
  "'('", "')'", "'['", "']'", "','", "';'", "'='", "'{'", "'}'", "':'",
  "'.'", "'-'", "'&'", "'*'", "'+'", "'~'", "'!'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "$accept", "ROOT", "external_declaration",
  "function_definition", "declarator", "direct_declarator",
  "parameter_list", "parameter_declaration", "declaration",
  "declaration_specifiers", "init_declarator", "initializer",
  "initializer_list", "abstract_declarator", "direct_abstract_declarator",
  "compound_statement", "declaration_list", "statement_list", "statement",
  "labeled_statement", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "type_specifier", "specifier_qualifier_list",
  "enum_specifier", "enumerator_list", "enumerator", "type_qualifier",
  "pointer", "type_qualifier_list", "identifier_list", "type_name", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    40,    41,    91,    93,    44,    59,    61,   123,   125,
      58,    46,    45,    38,    42,    43,   126,    33,    47,    37,
      60,    62,    94,   124,    63
};
# endif

#define YYPACT_NINF (-228)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     719,  -228,   798,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,    25,    14,   -21,    35,  -228,  -228,  -228,    33,
    -228,    13,   798,  -228,    59,  -228,   -28,    51,    28,  -228,
    -228,  -228,  -228,   -21,  -228,   738,   583,  -228,    66,    10,
    -228,    33,    51,    52,    70,  -228,  -228,  -228,  -228,  -228,
    -228,   -35,  -228,    17,    93,  -228,  -228,   627,   658,   658,
     524,   658,  -228,  -228,  -228,  -228,  -228,  -228,   153,  -228,
     583,  -228,   -23,    -9,    36,     2,   160,    22,    62,   100,
     138,     8,  -228,   103,   303,   209,  -228,  -228,    76,   583,
      51,  -228,  -228,   798,   677,   480,  -228,  -228,    64,    65,
    -228,   218,   524,  -228,   583,  -228,  -228,   363,  -228,  -228,
      94,   261,   -22,   261,   166,  -228,   238,  -228,  -228,   542,
     583,   251,  -228,   583,   583,   583,   583,   583,   583,   583,
     583,   583,   583,   583,   583,   583,   583,   583,   583,   583,
     583,   583,  -228,   303,  -228,  -228,   185,   583,   187,   200,
     210,   211,   463,   212,   271,   213,   214,   566,  -228,  -228,
    -228,    13,  -228,   284,   359,  -228,  -228,  -228,  -228,  -228,
    -228,    84,  -228,  -228,  -228,  -228,  -228,   126,   227,  -228,
     230,   464,   573,    64,  -228,   229,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,   583,  -228,   583,
    -228,   767,  -228,   102,  -228,   583,  -228,  -228,   128,  -228,
     140,  -228,  -228,  -228,  -228,   -23,   -23,    -9,    -9,    36,
      36,    36,    36,     2,     2,   160,    22,    62,   100,   138,
     -46,  -228,    82,   463,   206,   463,   583,   583,   583,   256,
     602,   248,  -228,  -228,  -228,   168,   249,  -228,  -228,   388,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,   135,  -228,   253,
    -228,  -228,  -228,  -228,  -228,   583,  -228,   583,   134,  -228,
    -228,   463,  -228,   136,   157,   158,   254,   602,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,   463,   463,
     463,   583,   620,   274,  -228,  -228,   164,   463,   165,   463,
     263,  -228,   463,  -228,  -228,  -228
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    24,   151,   152,   153,   154,   157,   158,   155,
     156,   150,     0,     0,   173,     0,     2,     3,     6,     8,
       4,     0,    22,   159,     0,    25,   166,     0,     0,   171,
     172,   177,   175,   174,     1,     0,     0,    20,    26,     0,
      23,     7,     0,   169,     0,   167,    10,   178,   176,   179,
      14,     0,    15,    19,     0,    76,    77,     0,     0,     0,
       0,     0,    96,    97,    98,   100,   101,    79,    89,   102,
       0,   104,   108,   111,   114,   119,   122,   124,   126,   128,
     130,   132,   149,     0,     0,     0,     5,    21,     0,     0,
       0,   164,    12,     0,     0,     0,    17,    18,    34,    33,
      13,     0,     0,    94,     0,    90,    91,   102,   134,   147,
       0,   161,   181,   163,     0,    93,     0,    85,    86,     0,
       0,     0,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,    27,    28,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    45,
      49,     0,    58,     0,     0,    51,    53,    54,    55,    56,
      57,     0,   165,   170,   168,    16,    41,     0,     0,    37,
       0,     0,     0,    35,   180,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   136,     0,    78,     0,
     160,     0,   182,    33,   162,     0,    84,    81,     0,    87,
       0,    83,   105,   106,   107,   110,   109,   112,   113,   117,
     118,   115,   116,   120,   121,   123,   125,   127,   129,   131,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,    74,     0,    26,    46,    50,     0,
      47,    52,    63,    42,    36,    38,    43,     0,    39,     0,
      95,   135,   148,   103,    82,     0,    80,     0,     0,    29,
      59,     0,    61,     0,     0,     0,     0,     0,    71,    75,
      48,    44,    40,    88,   133,    30,    32,    60,     0,     0,
       0,     0,     0,    64,    66,    67,     0,     0,     0,     0,
       0,    69,     0,    65,    68,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -228,  -228,  -228,  -228,     5,   -15,   -33,   234,   -78,     1,
    -228,  -139,  -228,   -43,   -87,   292,  -228,   169,  -103,  -228,
    -227,  -228,  -228,  -228,  -228,  -228,  -228,   -25,  -228,   -52,
     109,   111,    39,   117,   215,   199,   208,   216,   207,  -228,
     -30,   -76,  -228,   -60,   -58,    71,    68,  -228,   306,   259,
      15,    24,  -228,  -228,   252
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    28,    19,   177,    52,    20,    53,
      39,   144,   232,   178,    98,   162,   163,   164,   165,   166,
     167,   168,   169,   170,    67,    68,   208,   107,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
     108,   109,   197,   171,    83,    22,   112,    23,    44,    45,
     113,    24,    33,    54,   114
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     110,    21,    51,    25,   231,    18,    82,   160,   145,    41,
      97,    69,   183,   277,   130,   131,     1,     1,   122,   199,
       1,    29,    30,    40,   267,   140,    38,    92,    26,    31,
      93,   173,   103,   105,   106,    34,   115,   180,    32,   201,
      42,    95,   110,   209,   110,    69,   128,   129,    47,   239,
     292,   123,    14,    14,    43,   124,   125,    48,    96,    82,
     210,   251,     1,   126,    69,    82,   127,   145,     1,   202,
      69,   212,   213,   214,    13,    13,    87,    99,    94,    37,
      95,   230,   132,   133,    41,   248,   161,    14,    14,   234,
      46,    14,   141,    27,    35,   136,    36,   245,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,   183,    82,    99,    89,
      13,   261,    69,   262,   259,   181,    94,   182,    95,   286,
     270,   111,   272,    84,    85,    90,   203,    55,    56,    91,
      57,    90,    58,    59,   137,   172,   251,   268,   257,   199,
     252,   269,    82,   263,   139,   100,   198,    69,   101,   199,
     116,   117,   118,   201,   161,    95,   246,   142,   287,   219,
     220,   221,   222,   111,   134,   135,   273,   274,   275,   200,
      69,   204,   111,   138,   111,   293,   294,   295,   253,   283,
     264,    93,   145,   265,   301,    60,   303,   281,   288,   305,
      93,   199,   143,   285,   266,   199,    61,    62,    63,    64,
      65,    66,   146,    56,   119,    57,   120,    58,    59,   289,
     290,   184,   199,   199,   121,   203,   300,   302,   205,   199,
     199,   296,   298,   199,   279,   215,   216,   284,     2,   217,
     218,   206,    69,     3,     4,     5,     6,     7,     8,     9,
      10,   223,   224,    11,   211,   233,    12,   235,   147,   148,
     149,   236,   150,   151,   152,   153,   154,   155,   156,   157,
      60,   237,   238,   240,   241,   158,   271,    85,   159,   242,
     243,    61,    62,    63,    64,    65,    66,   146,    56,   254,
      57,   260,    58,    59,   255,     3,     4,     5,     6,     7,
       8,     9,    10,    29,    30,    11,    55,    56,    12,    57,
     276,    58,    59,     2,   278,   291,    84,   282,     3,     4,
       5,     6,     7,     8,     9,    10,   299,   175,    11,   304,
      86,    12,   249,   147,   148,   149,   226,   150,   151,   152,
     153,   154,   155,   156,   157,    60,   227,   229,    88,   174,
     158,   225,    85,   247,   185,   228,    61,    62,    63,    64,
      65,    66,   146,    56,    60,    57,     0,    58,    59,     0,
       0,   143,     0,     0,     0,    61,    62,    63,    64,    65,
      66,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   146,    56,     0,    57,     0,    58,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   147,   148,
     149,     0,   150,   151,   152,   153,   154,   155,   156,   157,
      60,     0,     0,     0,     0,   158,     0,    85,   250,     0,
     196,    61,    62,    63,    64,    65,    66,   147,   148,   149,
       0,   150,   151,   152,   153,   154,   155,   156,   157,    60,
       0,     0,     0,     0,   158,     0,    85,   280,     0,     0,
      61,    62,    63,    64,    65,    66,   146,    56,     0,    57,
       0,    58,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,     0,    57,     0,    58,    59,
       0,     0,     0,     2,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,     0,    11,     0,
       0,    12,   147,   148,   149,     0,   150,   151,   152,   153,
     154,   155,   156,   157,    60,     0,   256,    55,    56,   158,
      57,    85,    58,    59,     0,    61,    62,    63,    64,    65,
      66,    60,     0,     0,   179,    55,    56,     0,    57,     0,
      58,    59,    61,    62,    63,    64,    65,    66,     3,     4,
       5,     6,     7,     8,     9,    10,    29,    30,    11,    55,
      56,    12,    57,     0,    58,    59,    55,    56,     0,    57,
       0,    58,    59,     0,     0,    60,    55,    56,     0,    57,
       0,    58,    59,     0,     0,     0,    61,    62,    63,    64,
      65,    66,     0,    60,   207,    55,    56,     0,    57,     0,
      58,    59,     0,     0,    61,    62,    63,    64,    65,    66,
       0,     0,     0,    55,    56,     0,    57,    60,    58,    59,
      55,    56,   244,    57,    60,    58,    59,   258,    61,    62,
      63,    64,    65,    66,    60,    61,    62,    63,    64,    65,
      66,     0,     0,     0,     0,    61,    62,    63,    64,    65,
      66,    55,    56,    60,    57,     0,    58,    59,   158,     0,
       0,     0,     0,     0,    61,    62,    63,    64,    65,    66,
       1,    60,   297,     0,     0,     0,     0,     0,   102,     0,
       0,     0,    61,    62,    63,    64,    65,    66,     0,    61,
      62,    63,    64,    65,    66,     0,     2,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,   104,
       0,    11,     1,     0,    12,     0,     0,     0,     0,     0,
      61,    62,    63,    64,    65,    66,     0,     0,    94,   176,
      95,    49,     0,     0,     0,     0,     0,     0,     2,     0,
       0,    14,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,     0,    11,     0,     0,    12,     2,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      13,     0,    11,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,     2,     0,     0,     0,
      50,     3,     4,     5,     6,     7,     8,     9,    10,     0,
       0,    11,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,   201,   176,
      95,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    14,    11,     0,     0,    12
};

static const yytype_int16 yycheck[] =
{
      60,     0,    35,     2,   143,     0,    36,    85,    84,    24,
      53,    36,    99,   240,    12,    13,     3,     3,    70,    65,
       3,    42,    43,    22,    70,    17,    21,    62,     3,    14,
      65,    89,    57,    58,    59,     0,    61,    95,    14,    61,
      68,    63,   102,   119,   104,    70,    10,    11,    33,   152,
     277,    74,    74,    74,     3,    78,    79,    33,    53,    89,
     120,   164,     3,    72,    89,    95,    75,   143,     3,   112,
      95,   123,   124,   125,    61,    61,    66,    53,    61,    66,
      63,   141,    80,    81,    99,   163,    85,    74,    74,   147,
      62,    74,    84,    68,    61,    73,    63,   157,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   203,   147,    94,    67,
      61,   197,   147,   199,   182,    61,    61,    63,    63,   268,
     233,    60,   235,    67,    68,    65,   112,     3,     4,    69,
       6,    65,     8,     9,    82,    69,   249,    65,   181,    65,
      66,    69,   182,   205,    16,    62,    62,   182,    65,    65,
       7,     8,     9,    61,   163,    63,   161,    64,   271,   130,
     131,   132,   133,   102,    14,    15,   236,   237,   238,   111,
     205,   113,   111,    83,   113,   288,   289,   290,    62,   265,
      62,    65,   268,    65,   297,    61,   299,    62,    62,   302,
      65,    65,    68,    69,    64,    65,    72,    73,    74,    75,
      76,    77,     3,     4,    61,     6,    63,     8,     9,    62,
      62,     3,    65,    65,    71,   201,    62,    62,    62,    65,
      65,   291,   292,    65,    66,   126,   127,   267,    29,   128,
     129,     3,   267,    34,    35,    36,    37,    38,    39,    40,
      41,   134,   135,    44,     3,    70,    47,    70,    49,    50,
      51,    61,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    61,    61,    61,     3,    66,    70,    68,    69,    66,
      66,    72,    73,    74,    75,    76,    77,     3,     4,    62,
       6,    62,     8,     9,    64,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     3,     4,    47,     6,
      54,     8,     9,    29,    66,    61,    67,    64,    34,    35,
      36,    37,    38,    39,    40,    41,    52,    93,    44,    66,
      38,    47,   163,    49,    50,    51,   137,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   138,   140,    42,    90,
      66,   136,    68,    69,   102,   139,    72,    73,    74,    75,
      76,    77,     3,     4,    61,     6,    -1,     8,     9,    -1,
      -1,    68,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     3,     4,    -1,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    68,    69,    -1,
      67,    72,    73,    74,    75,    76,    77,    49,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    -1,    68,    69,    -1,    -1,
      72,    73,    74,    75,    76,    77,     3,     4,    -1,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,     6,    -1,     8,     9,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    44,    -1,
      -1,    47,    49,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    62,     3,     4,    66,
       6,    68,     8,     9,    -1,    72,    73,    74,    75,    76,
      77,    61,    -1,    -1,    64,     3,     4,    -1,     6,    -1,
       8,     9,    72,    73,    74,    75,    76,    77,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     3,
       4,    47,     6,    -1,     8,     9,     3,     4,    -1,     6,
      -1,     8,     9,    -1,    -1,    61,     3,     4,    -1,     6,
      -1,     8,     9,    -1,    -1,    -1,    72,    73,    74,    75,
      76,    77,    -1,    61,    62,     3,     4,    -1,     6,    -1,
       8,     9,    -1,    -1,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,     3,     4,    -1,     6,    61,     8,     9,
       3,     4,    66,     6,    61,     8,     9,    64,    72,    73,
      74,    75,    76,    77,    61,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,     3,     4,    61,     6,    -1,     8,     9,    66,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
       3,    61,    62,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    -1,    72,
      73,    74,    75,    76,    77,    -1,    29,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    61,
      -1,    44,     3,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    77,    -1,    -1,    61,    62,
      63,     3,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    74,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    44,    -1,    -1,    47,    29,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      61,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    29,    -1,    -1,    -1,
      62,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    61,    62,
      63,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    74,    44,    -1,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    29,    34,    35,    36,    37,    38,    39,    40,
      41,    44,    47,    61,    74,    86,    87,    88,    89,    90,
      93,    94,   130,   132,   136,    94,     3,    68,    89,    42,
      43,   135,   136,   137,     0,    61,    63,    66,    89,    95,
      94,    90,    68,     3,   133,   134,    62,   135,   136,     3,
      62,    91,    92,    94,   138,     3,     4,     6,     8,     9,
      61,    72,    73,    74,    75,    76,    77,   109,   110,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   129,    67,    68,   100,    66,   133,    67,
      65,    69,    62,    65,    61,    63,    89,    98,    99,   136,
      62,    65,    61,   112,    61,   112,   112,   112,   125,   126,
     128,   130,   131,   135,   139,   112,     7,     8,     9,    61,
      63,    71,   114,    74,    78,    79,    72,    75,    10,    11,
      12,    13,    80,    81,    14,    15,    73,    82,    83,    16,
      17,    84,    64,    68,    96,   126,     3,    49,    50,    51,
      53,    54,    55,    56,    57,    58,    59,    60,    66,    69,
      93,    94,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   128,    69,   129,   134,    92,    62,    91,    98,    64,
     129,    61,    63,    99,     3,   139,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    67,   127,    62,    65,
     131,    61,    98,   136,   131,    62,     3,    62,   111,   126,
     128,     3,   114,   114,   114,   115,   115,   116,   116,   117,
     117,   117,   117,   118,   118,   119,   120,   121,   122,   123,
     128,    96,    97,    70,   129,    70,    61,    61,    61,   103,
      61,     3,    66,    66,    66,   128,    89,    69,    93,   102,
      69,   103,    66,    62,    62,    64,    62,    91,    64,   129,
      62,   126,   126,   114,    62,    65,    64,    70,    65,    69,
     103,    70,   103,   128,   128,   128,    54,   105,    66,    66,
      69,    62,    64,   126,   125,    69,    96,   103,    62,    62,
      62,    61,   105,   103,   103,   103,   128,    62,   128,    52,
      62,   103,    62,   103,    66,   103
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    90,    90,    90,    90,    91,    91,    92,    92,    92,
      93,    93,    94,    94,    94,    94,    95,    95,    96,    96,
      96,    97,    97,    98,    98,    98,    99,    99,    99,    99,
      99,    99,    99,    99,    99,   100,   100,   100,   100,   101,
     101,   102,   102,   103,   103,   103,   103,   103,   103,   104,
     104,   104,   105,   105,   106,   106,   106,   107,   107,   107,
     107,   108,   108,   108,   108,   108,   109,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   113,   113,   113,   113,
     113,   113,   114,   114,   115,   115,   115,   115,   116,   116,
     116,   117,   117,   117,   118,   118,   118,   118,   118,   119,
     119,   119,   120,   120,   121,   121,   122,   122,   123,   123,
     124,   124,   125,   125,   126,   126,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   128,   128,   129,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     131,   131,   131,   131,   132,   132,   132,   133,   133,   134,
     134,   135,   135,   136,   136,   136,   136,   137,   137,   138,
     138,   139,   139
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     2,     1,     1,
       3,     4,     4,     4,     3,     1,     3,     2,     2,     1,
       2,     3,     1,     2,     1,     2,     1,     3,     1,     3,
       4,     1,     3,     1,     1,     2,     3,     2,     3,     3,
       4,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     1,     2,     5,     7,     5,     5,     7,     6,
       7,     3,     2,     2,     2,     3,     1,     1,     3,     1,
       4,     3,     4,     3,     3,     2,     2,     1,     3,     1,
       2,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     1,     4,     5,     2,     1,     3,     1,
       3,     1,     1,     1,     2,     2,     3,     1,     2,     1,
       3,     1,     2
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
#line 75 "src/parser.y"
                                                { g_root = (yyvsp[0].expr); /*translation_unit*/ }
#line 1734 "src/parser.tab.cpp"
    break;

  case 3:
#line 83 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1740 "src/parser.tab.cpp"
    break;

  case 4:
#line 84 "src/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1746 "src/parser.tab.cpp"
    break;

  case 5:
#line 88 "src/parser.y"
                                                               { (yyval.expr) = new Full_Function(new Function_Definition(*(yyvsp[-2].string), (yyvsp[-1].expr)), (yyvsp[0].expressionList)); }
#line 1752 "src/parser.tab.cpp"
    break;

  case 8:
#line 98 "src/parser.y"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1758 "src/parser.tab.cpp"
    break;

  case 9:
#line 102 "src/parser.y"
                                                                                                { (yyval.expr) = new Declarator(*(yyvsp[0].string));}
#line 1764 "src/parser.tab.cpp"
    break;

  case 10:
#line 103 "src/parser.y"
                                                                                        { (yyval.expr) = (yyvsp[-1].expr); }
#line 1770 "src/parser.tab.cpp"
    break;

  case 11:
#line 104 "src/parser.y"
                                                                { ;}
#line 1776 "src/parser.tab.cpp"
    break;

  case 12:
#line 105 "src/parser.y"
                                                                        { ;}
#line 1782 "src/parser.tab.cpp"
    break;

  case 13:
#line 106 "src/parser.y"
                                                                        { ;}
#line 1788 "src/parser.tab.cpp"
    break;

  case 14:
#line 107 "src/parser.y"
                                                                                        { (yyval.expr) = new FunctionDeclarator((yyvsp[-2].expr));;}
#line 1794 "src/parser.tab.cpp"
    break;

  case 15:
#line 112 "src/parser.y"
                                                                        {  (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 1800 "src/parser.tab.cpp"
    break;

  case 16:
#line 113 "src/parser.y"
                                                        { appendToExprList((yyvsp[-2].expressionList), (yyvsp[0].expr)); }
#line 1806 "src/parser.tab.cpp"
    break;

  case 17:
#line 117 "src/parser.y"
                                                                        { (yyval.expr) = new Declare(*(yyvsp[-1].string), (yyvsp[0].expr));}
#line 1812 "src/parser.tab.cpp"
    break;

  case 18:
#line 118 "src/parser.y"
                                                        { (yyval.expr) = new Declare(*(yyvsp[-1].string), (yyvsp[0].expr));}
#line 1818 "src/parser.tab.cpp"
    break;

  case 20:
#line 124 "src/parser.y"
                                                                                { ; }
#line 1824 "src/parser.tab.cpp"
    break;

  case 21:
#line 125 "src/parser.y"
                                                        { (yyval.expr) = new Declare(*(yyvsp[-2].string), (yyvsp[-1].expr));}
#line 1830 "src/parser.tab.cpp"
    break;

  case 22:
#line 130 "src/parser.y"
                                                                                                { (yyval.string) == (yyvsp[0].string); }
#line 1836 "src/parser.tab.cpp"
    break;

  case 26:
#line 139 "src/parser.y"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1842 "src/parser.tab.cpp"
    break;

  case 27:
#line 140 "src/parser.y"
                                                { (yyval.expr) = new InitDeclarator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1848 "src/parser.tab.cpp"
    break;

  case 28:
#line 145 "src/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1854 "src/parser.tab.cpp"
    break;

  case 29:
#line 146 "src/parser.y"
                                                { ; /*list to expr, need a class for creating an exprPtr to list */}
#line 1860 "src/parser.tab.cpp"
    break;

  case 30:
#line 147 "src/parser.y"
                                        { ; /* same */ }
#line 1866 "src/parser.tab.cpp"
    break;

  case 31:
#line 151 "src/parser.y"
                                                                {  (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 1872 "src/parser.tab.cpp"
    break;

  case 32:
#line 152 "src/parser.y"
                                                { appendToExprList((yyvsp[-2].expressionList), (yyvsp[0].expr)); }
#line 1878 "src/parser.tab.cpp"
    break;

  case 36:
#line 162 "src/parser.y"
                                                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 1884 "src/parser.tab.cpp"
    break;

  case 37:
#line 163 "src/parser.y"
                                                                                                                        { ; }
#line 1890 "src/parser.tab.cpp"
    break;

  case 38:
#line 164 "src/parser.y"
                                                                                                { ; }
#line 1896 "src/parser.tab.cpp"
    break;

  case 39:
#line 165 "src/parser.y"
                                                                                        { ; }
#line 1902 "src/parser.tab.cpp"
    break;

  case 40:
#line 166 "src/parser.y"
                                                                        { ; }
#line 1908 "src/parser.tab.cpp"
    break;

  case 41:
#line 167 "src/parser.y"
                                                                                                                        { ; }
#line 1914 "src/parser.tab.cpp"
    break;

  case 42:
#line 168 "src/parser.y"
                                                                                                        { ; }
#line 1920 "src/parser.tab.cpp"
    break;

  case 43:
#line 169 "src/parser.y"
                                                                                        { ; }
#line 1926 "src/parser.tab.cpp"
    break;

  case 44:
#line 170 "src/parser.y"
                                                                                { ; }
#line 1932 "src/parser.tab.cpp"
    break;

  case 45:
#line 175 "src/parser.y"
                                                                                                { (yyval.expressionList) = new ExpressionList();}
#line 1938 "src/parser.tab.cpp"
    break;

  case 46:
#line 176 "src/parser.y"
                                                                                { (yyval.expressionList) = new ExpressionList((yyvsp[-1].expressionList)); }
#line 1944 "src/parser.tab.cpp"
    break;

  case 47:
#line 177 "src/parser.y"
                                                                                { (yyval.expressionList) = new ExpressionList((yyvsp[-1].expressionList)); }
#line 1950 "src/parser.tab.cpp"
    break;

  case 48:
#line 179 "src/parser.y"
                                                                { (yyval.expressionList) = new ExpressionList(); appendToExprList((yyval.expressionList), (yyvsp[-2].expressionList)); appendToExprList((yyval.expressionList), (yyvsp[-1].expressionList)); }
#line 1956 "src/parser.tab.cpp"
    break;

  case 49:
#line 186 "src/parser.y"
                                                        { (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 1962 "src/parser.tab.cpp"
    break;

  case 50:
#line 187 "src/parser.y"
                                        { appendToExprList((yyvsp[-1].expressionList), (yyvsp[0].expr)); }
#line 1968 "src/parser.tab.cpp"
    break;

  case 51:
#line 192 "src/parser.y"
                                                        {  (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 1974 "src/parser.tab.cpp"
    break;

  case 52:
#line 193 "src/parser.y"
                                        { appendToExprList((yyvsp[-1].expressionList), (yyvsp[0].expr)); }
#line 1980 "src/parser.tab.cpp"
    break;

  case 53:
#line 197 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1986 "src/parser.tab.cpp"
    break;

  case 54:
#line 198 "src/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1992 "src/parser.tab.cpp"
    break;

  case 55:
#line 199 "src/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1998 "src/parser.tab.cpp"
    break;

  case 56:
#line 200 "src/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2004 "src/parser.tab.cpp"
    break;

  case 57:
#line 201 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2010 "src/parser.tab.cpp"
    break;

  case 58:
#line 202 "src/parser.y"
                                { (yyval.expr) = (yyvsp[0].expressionList); /*at the moment compound_statement is avoided so we can add its versions below*/}
#line 2016 "src/parser.tab.cpp"
    break;

  case 74:
#line 238 "src/parser.y"
                                        { ; }
#line 2022 "src/parser.tab.cpp"
    break;

  case 75:
#line 239 "src/parser.y"
                                { (yyval.expr) = new Return((yyvsp[-1].expr)); }
#line 2028 "src/parser.tab.cpp"
    break;

  case 76:
#line 245 "src/parser.y"
                                        { (yyval.expr) = new Variable( *(yyvsp[0].string) );}
#line 2034 "src/parser.tab.cpp"
    break;

  case 77:
#line 246 "src/parser.y"
                                        { (yyval.expr) = new Number( (yyvsp[0].number) );}
#line 2040 "src/parser.tab.cpp"
    break;

  case 78:
#line 249 "src/parser.y"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 2046 "src/parser.tab.cpp"
    break;

  case 79:
#line 253 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2052 "src/parser.tab.cpp"
    break;

  case 87:
#line 264 "src/parser.y"
                                                                                                { (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 2058 "src/parser.tab.cpp"
    break;

  case 88:
#line 265 "src/parser.y"
                                                                { appendToExprList((yyvsp[-2].expressionList), (yyvsp[0].expr)); }
#line 2064 "src/parser.tab.cpp"
    break;

  case 89:
#line 269 "src/parser.y"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2070 "src/parser.tab.cpp"
    break;

  case 93:
#line 273 "src/parser.y"
                                                        { (yyval.expr) = new NegOperator((yyvsp[0].expr)); }
#line 2076 "src/parser.tab.cpp"
    break;

  case 102:
#line 288 "src/parser.y"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2082 "src/parser.tab.cpp"
    break;

  case 104:
#line 293 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2088 "src/parser.tab.cpp"
    break;

  case 105:
#line 294 "src/parser.y"
                                                                { (yyval.expr) = new MulOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2094 "src/parser.tab.cpp"
    break;

  case 106:
#line 295 "src/parser.y"
                                                                { (yyval.expr) = new DivOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2100 "src/parser.tab.cpp"
    break;

  case 107:
#line 296 "src/parser.y"
                                                                {;}
#line 2106 "src/parser.tab.cpp"
    break;

  case 108:
#line 300 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2112 "src/parser.tab.cpp"
    break;

  case 109:
#line 301 "src/parser.y"
                                                                        { (yyval.expr) = new AddOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2118 "src/parser.tab.cpp"
    break;

  case 110:
#line 302 "src/parser.y"
                                                                        { (yyval.expr) = new SubOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2124 "src/parser.tab.cpp"
    break;

  case 111:
#line 306 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2130 "src/parser.tab.cpp"
    break;

  case 114:
#line 312 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2136 "src/parser.tab.cpp"
    break;

  case 119:
#line 320 "src/parser.y"
                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2142 "src/parser.tab.cpp"
    break;

  case 122:
#line 326 "src/parser.y"
                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2148 "src/parser.tab.cpp"
    break;

  case 124:
#line 331 "src/parser.y"
                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2154 "src/parser.tab.cpp"
    break;

  case 126:
#line 336 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2160 "src/parser.tab.cpp"
    break;

  case 128:
#line 341 "src/parser.y"
                                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2166 "src/parser.tab.cpp"
    break;

  case 130:
#line 346 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2172 "src/parser.tab.cpp"
    break;

  case 132:
#line 351 "src/parser.y"
                                                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2178 "src/parser.tab.cpp"
    break;

  case 134:
#line 356 "src/parser.y"
                                     { (yyval.expr) = (yyvsp[0].expr); }
#line 2184 "src/parser.tab.cpp"
    break;

  case 135:
#line 357 "src/parser.y"
                                                                        { (yyval.expr) = new AssignOperator((yyvsp[-2].expr), *(yyvsp[-1].string), (yyvsp[0].expr));  }
#line 2190 "src/parser.tab.cpp"
    break;

  case 136:
#line 361 "src/parser.y"
                             { (yyval.string) = new std::string("="); }
#line 2196 "src/parser.tab.cpp"
    break;

  case 137:
#line 362 "src/parser.y"
                             { (yyval.string) = new std::string("*="); }
#line 2202 "src/parser.tab.cpp"
    break;

  case 138:
#line 363 "src/parser.y"
                             { (yyval.string) = new std::string("/="); }
#line 2208 "src/parser.tab.cpp"
    break;

  case 139:
#line 364 "src/parser.y"
                             { (yyval.string) = new std::string("%="); }
#line 2214 "src/parser.tab.cpp"
    break;

  case 140:
#line 365 "src/parser.y"
                             { (yyval.string) = new std::string("+="); }
#line 2220 "src/parser.tab.cpp"
    break;

  case 141:
#line 366 "src/parser.y"
                             { (yyval.string) = new std::string("-="); }
#line 2226 "src/parser.tab.cpp"
    break;

  case 142:
#line 367 "src/parser.y"
                             { (yyval.string) = new std::string("<<="); }
#line 2232 "src/parser.tab.cpp"
    break;

  case 143:
#line 368 "src/parser.y"
                             { (yyval.string) = new std::string(">>="); }
#line 2238 "src/parser.tab.cpp"
    break;

  case 144:
#line 369 "src/parser.y"
                             { (yyval.string) = new std::string("&="); }
#line 2244 "src/parser.tab.cpp"
    break;

  case 145:
#line 370 "src/parser.y"
                             { (yyval.string) = new std::string("^="); }
#line 2250 "src/parser.tab.cpp"
    break;

  case 146:
#line 371 "src/parser.y"
                             { (yyval.string) = new std::string("|="); }
#line 2256 "src/parser.tab.cpp"
    break;

  case 147:
#line 375 "src/parser.y"
                                                                        {(yyval.expr) = (yyvsp[0].expr); /*{ $$ = initExprList($1); }*/}
#line 2262 "src/parser.tab.cpp"
    break;

  case 148:
#line 376 "src/parser.y"
                                                        { /* appendToExprList($1, $2); */ }
#line 2268 "src/parser.tab.cpp"
    break;

  case 150:
#line 388 "src/parser.y"
                                { (yyval.string) = new std::string("void"); }
#line 2274 "src/parser.tab.cpp"
    break;

  case 153:
#line 391 "src/parser.y"
                                { (yyval.string) = new std::string("int"); }
#line 2280 "src/parser.tab.cpp"
    break;


#line 2284 "src/parser.tab.cpp"

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
#line 490 "src/parser.y"


const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
