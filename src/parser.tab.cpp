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
  #include <fstream>

  extern const Expression *g_root; // A way of getting the AST out
  extern FILE *yyin;
  // ! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 127 "src/parser.tab.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    INT_LITERAL = 259,
    CHAR_LITERAL = 260,
    SIZEOF = 261,
    FLOAT_LITERAL = 262,
    POINTER_OP = 263,
    INCREMENT_OP = 264,
    DECREMENT_OP = 265,
    LEFTSHIFT_OP = 266,
    RIGHTSHIFT_OP = 267,
    LE_OP = 268,
    GE_OP = 269,
    EQ_OP = 270,
    NE_OP = 271,
    AND_OP = 272,
    OR_OP = 273,
    MUL_ASSIGN = 274,
    DIV_ASSIGN = 275,
    MOD_ASSIGN = 276,
    ADD_ASSIGN = 277,
    SUB_ASSIGN = 278,
    LEFTSHIFT_ASSIGN = 279,
    RIGHTSHIFT_ASSIGN = 280,
    AND_ASSIGN = 281,
    XOR_ASSIGN = 282,
    OR_ASSIGN = 283,
    TYPE_NAME = 284,
    TYPEDEF = 285,
    EXTERN = 286,
    STATIC = 287,
    AUTO = 288,
    REGISTER = 289,
    CHAR = 290,
    SHORT = 291,
    INT = 292,
    LONG = 293,
    SIGNED = 294,
    UNSIGNED = 295,
    FLOAT = 296,
    DOUBLE = 297,
    CONST = 298,
    VOLATILE = 299,
    VOID = 300,
    STRUCT = 301,
    UNION = 302,
    ENUM = 303,
    ELLIPSIS = 304,
    CASE = 305,
    DEFAULT = 306,
    IF = 307,
    ELSE = 308,
    SWITCH = 309,
    WHILE = 310,
    DO = 311,
    FOR = 312,
    GOTO = 313,
    CONTINUE = 314,
    BREAK = 315,
    RETURN = 316,
    uminu = 317,
    NOELSE = 318
  };
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

#line 212 "src/parser.tab.cpp"

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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   939

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  188
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  313

#define YYUNDEFTOK  2
#define YYMAXUTOK   318


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
       2,     2,     2,    81,     2,     2,     2,    82,    79,     2,
      69,    70,    64,    62,    73,    63,    78,    65,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    77,    68,
      83,    74,    84,    87,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    71,     2,    72,    85,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,    86,    76,    80,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    90,    91,    95,    96,   100,   101,   102,
     103,   107,   108,   112,   113,   114,   115,   116,   117,   118,
     123,   124,   128,   129,   130,   134,   139,   140,   145,   146,
     147,   148,   154,   155,   160,   161,   162,   166,   167,   171,
     172,   173,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   190,   191,   192,   194,   201,   202,   207,   208,   212,
     213,   214,   215,   216,   217,   222,   223,   224,   228,   229,
     233,   234,   235,   239,   240,   241,   242,   246,   247,   248,
     249,   250,   256,   257,   258,   259,   260,   264,   265,   266,
     267,   268,   269,   270,   271,   275,   276,   280,   281,   282,
     283,   284,   285,   286,   290,   291,   292,   293,   294,   295,
     299,   300,   304,   305,   306,   307,   311,   312,   313,   317,
     318,   319,   323,   324,   325,   326,   327,   331,   332,   333,
     337,   338,   342,   343,   347,   348,   352,   353,   357,   358,
     362,   363,   367,   368,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   386,   387,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   429,   430,   431,   432,
     447,   448,   449,   453,   454,   458,   459,   463,   464,   468,
     469,   470,   471,   475,   476,   483,   484,   488,   489
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INT_LITERAL",
  "CHAR_LITERAL", "SIZEOF", "FLOAT_LITERAL", "POINTER_OP", "INCREMENT_OP",
  "DECREMENT_OP", "LEFTSHIFT_OP", "RIGHTSHIFT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFTSHIFT_ASSIGN",
  "RIGHTSHIFT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "'+'", "'-'", "'*'", "'/'", "uminu",
  "NOELSE", "';'", "'('", "')'", "'['", "']'", "','", "'='", "'{'", "'}'",
  "':'", "'.'", "'&'", "'~'", "'!'", "'%'", "'<'", "'>'", "'^'", "'|'",
  "'?'", "$accept", "ROOT", "translation_unit", "external_declaration",
  "function_definition", "declarator", "direct_declarator",
  "parameter_list", "parameter_declaration", "constant_expression",
  "declaration", "declaration_specifiers", "init_declarator",
  "initializer", "initializer_list", "abstract_declarator",
  "direct_abstract_declarator", "compound_statement", "declaration_list",
  "statement_list", "statement", "labeled_statement",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "type_specifier", "specifier_qualifier_list",
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
     315,   316,    43,    45,    42,    47,   317,   318,    59,    40,
      41,    91,    93,    44,    61,   123,   125,    58,    46,    38,
     126,    33,    37,    60,    62,    94,   124,    63
};
# endif

#define YYPACT_NINF (-231)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     332,  -231,   457,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,    13,   -14,    66,    12,   332,  -231,  -231,  -231,
     247,  -231,   142,   457,   -48,   112,  -231,   -41,    44,  -231,
    -231,  -231,  -231,   -14,    -7,  -231,  -231,   252,   569,  -231,
      74,   -30,  -231,  -231,   247,    44,   -18,    97,  -231,  -231,
    -231,  -231,  -231,  -231,    77,  -231,    69,   113,  -231,  -231,
    -231,   736,  -231,   803,   803,  -231,    75,  -231,   526,  -231,
    -231,  -231,  -231,    55,  -231,     5,  -231,   816,  -231,    61,
       8,   222,    35,   223,    53,    73,    60,   155,   -10,  -231,
    -231,   593,   190,  -231,  -231,   140,   816,    44,  -231,  -231,
     457,   868,   607,  -231,  -231,   265,    65,  -231,   176,   526,
    -231,   816,  -231,  -231,  -231,   141,  -231,  -231,   144,   435,
     111,   435,   114,  -231,   189,  -231,  -231,   620,   816,   202,
    -231,   816,   816,   816,   816,   816,   816,   816,   816,   816,
     816,   816,   816,   816,   816,   816,   816,   816,   816,   816,
     593,  -231,  -231,   121,   816,   146,   174,   216,   227,   459,
     244,   253,   249,   272,   688,  -231,  -231,  -231,   142,  -231,
     269,   348,  -231,  -231,  -231,  -231,  -231,  -231,   -32,  -231,
    -231,  -231,  -231,  -231,   148,   286,  -231,   287,   817,   701,
     265,  -231,   290,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,   816,  -231,   816,  -231,   799,  -231,
     270,  -231,   816,  -231,  -231,   187,  -231,   195,  -231,  -231,
    -231,  -231,    61,    61,     8,     8,   222,   222,   222,   222,
      35,    35,   223,    53,    73,    60,   155,   -55,  -231,   188,
     459,   284,   459,   816,   816,   816,   308,   715,   296,  -231,
    -231,  -231,   -22,   291,  -231,  -231,   380,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,   207,  -231,   294,  -231,  -231,  -231,
    -231,  -231,   816,  -231,   816,   479,  -231,  -231,   459,  -231,
     211,   213,   225,   306,   715,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,   459,   459,   459,   816,   723,
     323,  -231,  -231,   230,   459,   242,   459,   310,  -231,   459,
    -231,  -231,  -231
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,    30,   158,   159,   160,   161,   164,   165,   162,
     163,   157,     0,   179,     0,     0,     2,     3,     5,    10,
      12,     6,     0,    28,     0,     0,    31,   172,     0,   177,
     178,   183,   181,   180,     0,     1,     4,     0,     0,    26,
       0,     0,    29,     9,    11,     0,   175,     0,   173,   184,
     182,    14,   185,    19,     0,    20,    24,     0,    82,    83,
      85,     0,    84,     0,     0,   106,   107,   105,     0,    16,
     104,   108,   109,     0,    87,    97,   110,     0,   112,   116,
     119,   122,   127,   130,   132,   134,   136,   138,   140,    25,
       8,     0,     0,     7,    27,     0,     0,     0,   170,    17,
       0,     0,     0,    22,    23,    40,    39,    18,     0,     0,
     102,     0,    98,    99,   101,   110,   142,   155,     0,   167,
     187,   169,     0,    15,     0,    93,    94,     0,     0,     0,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    51,    55,     0,    64,
       0,     0,    57,    59,    60,    61,    62,    63,     0,   171,
     176,   174,    21,    47,     0,     0,    43,     0,     0,     0,
      41,   186,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   144,     0,    86,     0,   166,     0,   188,
      39,   168,     0,    92,    89,     0,    95,     0,    91,   113,
     114,   115,   117,   118,   120,   121,   125,   126,   123,   124,
     128,   129,   131,   133,   135,   137,   139,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
      79,    80,     0,    32,    52,    56,     0,    53,    58,    69,
      48,    42,    44,    49,     0,    45,     0,   103,   143,   156,
     111,    90,     0,    88,     0,     0,    35,    65,     0,    67,
       0,     0,     0,     0,     0,    77,    81,    54,    50,    46,
      96,   141,    36,    38,    66,     0,     0,     0,     0,     0,
      70,    72,    73,     0,     0,     0,     0,     0,    75,     0,
      71,    74,    76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,  -231,  -231,   363,  -231,   -11,   -20,   -35,   281,   -65,
     -83,    19,  -231,  -146,  -231,   -29,   -96,   342,  -231,   218,
    -119,  -231,  -230,  -231,  -231,  -231,  -231,  -231,  -231,   -38,
    -231,   -71,   167,   206,    63,   204,   248,   246,   251,   266,
     245,  -231,   -37,   -84,  -231,   -36,   103,   -64,  -231,   349,
     298,    20,    11,  -231,  -231,   305
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    18,    19,    20,   184,    55,    73,
      21,    56,    41,   151,   239,   185,   105,   169,   170,   171,
     172,   173,   174,   175,   176,   177,    74,    75,   215,   115,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,   116,   117,   204,   178,    23,   120,    24,    47,
      48,   121,    25,    33,    57,   122
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,    89,    54,    34,   238,    44,   130,   152,   148,   167,
     190,    40,    35,   124,   125,   126,    27,   284,   206,    22,
      43,    26,   274,   110,    32,   112,   113,   104,   114,    29,
      30,   180,   118,    31,    45,    22,   259,   187,    94,    76,
     246,   206,    42,   216,    50,   103,   286,    46,   138,   139,
      13,   206,   258,    49,   299,   207,    96,   211,    76,    89,
     219,   220,   221,    51,    76,    89,   152,   106,     1,     1,
     134,   135,     1,   118,   127,   118,   128,   149,    58,    59,
      60,    61,    62,   129,    63,    64,    44,   255,    28,   241,
      34,   209,   217,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,   168,   106,   237,   190,     1,    76,    89,   140,   141,
     268,   277,   269,   279,   266,   131,   132,   123,   252,   293,
      13,   210,   144,    13,   101,    14,   102,   258,   101,    67,
     102,   270,    90,   133,   111,     1,   146,    99,    91,    92,
     100,    76,    89,   264,    70,    71,    72,   253,   145,   294,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
      97,   119,   147,    98,    76,    13,   300,   301,   302,   191,
     208,    14,   102,   107,   212,   308,   108,   310,   290,   168,
     312,   152,   213,   153,    59,    60,    61,    62,   240,    63,
      64,   226,   227,   228,   229,   218,    13,   280,   281,   282,
      39,    14,   119,    97,   205,   203,   179,   206,   260,   210,
       2,   100,   119,   242,   119,     3,     4,     5,     6,     7,
       8,     9,    10,   136,   137,    11,    76,   291,   142,   143,
     154,   155,   156,   243,   157,   158,   159,   160,   161,   162,
     163,   164,    65,    66,    67,    52,   248,   271,   165,    68,
     272,   275,   303,   305,   276,    92,   166,   273,   206,    70,
      71,    72,   153,    59,    60,    61,    62,   288,    63,    64,
     100,   295,     2,   296,   206,   244,   206,     3,     4,     5,
       6,     7,     8,     9,    10,   297,   245,    11,   206,     2,
     307,   222,   223,   206,     3,     4,     5,     6,     7,     8,
       9,    10,   309,   247,    11,   206,    37,   249,    38,   154,
     155,   156,    53,   157,   158,   159,   160,   161,   162,   163,
     164,    65,    66,    67,   188,     1,   189,   165,    68,   208,
     250,   102,   224,   225,    92,   254,   230,   231,    70,    71,
      72,   153,    59,    60,    61,    62,   261,    63,    64,   262,
     267,   278,     2,   283,   285,    91,   289,     3,     4,     5,
       6,     7,     8,     9,    10,   298,   306,    11,   311,    36,
      12,   182,    93,   153,    59,    60,    61,    62,   256,    63,
      64,   233,   232,   236,    95,   181,    13,   234,   154,   155,
     156,    14,   157,   158,   159,   160,   161,   162,   163,   164,
      65,    66,    67,   235,   192,     0,   165,    68,     0,     0,
       0,     0,     0,    92,   257,     0,     0,    70,    71,    72,
     154,   155,   156,     0,   157,   158,   159,   160,   161,   162,
     163,   164,    65,    66,    67,     0,     0,     0,   165,    68,
       0,     0,     0,     0,     0,    92,   287,     0,     0,    70,
      71,    72,   153,    59,    60,    61,    62,     0,    63,    64,
       3,     4,     5,     6,     7,     8,     9,    10,    29,    30,
      11,     0,    58,    59,    60,    61,    62,     2,    63,    64,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,    11,     0,     0,     0,     0,     0,     0,   154,
     155,   156,     0,   157,   158,   159,   160,   161,   162,   163,
     164,    65,    66,    67,     0,     0,     0,   165,    68,    58,
      59,    60,    61,    62,    92,    63,    64,     0,    70,    71,
      72,    65,    66,    67,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,   150,   292,     0,     0,    70,    71,
      72,     3,     4,     5,     6,     7,     8,     9,    10,    29,
      30,    11,    58,    59,    60,    61,    62,     0,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,     0,     0,     0,     0,    68,    58,    59,    60,    61,
      62,     0,    63,    64,     0,    70,    71,    72,     0,     0,
      58,    59,    60,    61,    62,     0,    63,    64,     0,     0,
       0,     0,     0,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,     0,     0,     0,     0,    68,     0,
       0,    69,     0,     0,     0,     0,     0,     0,    70,    71,
      72,     0,     0,     0,     0,    65,    66,    67,     0,     0,
       0,     0,    68,     0,     0,     0,     0,     0,   150,    65,
      66,    67,    70,    71,    72,     0,    68,     0,     0,   186,
       0,     0,    65,    66,    67,     0,    70,    71,    72,    68,
     214,    58,    59,    60,    61,    62,     0,    63,    64,    70,
      71,    72,     0,     0,    58,    59,    60,    61,    62,     0,
      63,    64,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,     0,    63,    64,    58,    59,    60,    61,
      62,     0,    63,    64,     0,     0,     0,     0,     0,    58,
      59,    60,    61,    62,     0,    63,    64,     0,     0,     0,
      65,    66,    67,     0,     0,     0,   251,    68,     0,     0,
       0,     0,     0,    65,    66,    67,     0,    70,    71,    72,
      68,     0,     0,   265,     0,     0,     0,    65,    66,    67,
      70,    71,    72,   165,    68,    65,    66,    67,     0,     0,
       0,     0,    68,   304,    70,    71,    72,     0,    65,    66,
      67,     0,    70,    71,    72,   109,    58,    59,    60,    61,
      62,     0,    63,    64,     0,    70,    71,    72,     0,    58,
      59,    60,    61,    62,     0,    63,    64,     0,     0,     2,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,     0,    11,     0,     0,     2,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,    11,    13,     0,    65,    66,    67,   208,   183,
     102,     1,   111,     0,     0,     0,     0,     0,    65,    66,
      67,     0,    70,    71,    72,    68,     0,   263,     0,     0,
       0,     0,     0,     0,     0,    70,    71,    72,     2,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,     0,     0,     0,     0,   101,   183,   102
};

static const yytype_int16 yycheck[] =
{
      38,    38,    37,    14,   150,    25,    77,    91,    18,    92,
     106,    22,     0,     8,     9,    10,     3,   247,    73,     0,
      68,     2,    77,    61,    13,    63,    64,    56,    66,    43,
      44,    96,    68,    13,    75,    16,    68,   102,    68,    77,
     159,    73,    23,   127,    33,    56,    68,     3,    13,    14,
      64,    73,   171,    33,   284,   119,    74,   121,    96,    96,
     131,   132,   133,    70,   102,   102,   150,    56,     3,     3,
      62,    63,     3,   109,    69,   111,    71,    87,     3,     4,
       5,     6,     7,    78,     9,    10,   106,   170,    75,   154,
     101,   120,   128,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    92,   101,   149,   210,     3,   154,   154,    83,    84,
     204,   240,   206,   242,   189,    64,    65,    72,   164,   275,
      64,   120,    79,    64,    69,    69,    71,   256,    69,    64,
      71,   212,    68,    82,    69,     3,    86,    70,    74,    75,
      73,   189,   189,   188,    79,    80,    81,   168,    85,   278,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      73,    68,    17,    76,   212,    64,   295,   296,   297,     3,
      69,    69,    71,    70,    70,   304,    73,   306,   272,   170,
     309,   275,     3,     3,     4,     5,     6,     7,    77,     9,
      10,   138,   139,   140,   141,     3,    64,   243,   244,   245,
      68,    69,   109,    73,    70,    74,    76,    73,    70,   208,
      30,    73,   119,    77,   121,    35,    36,    37,    38,    39,
      40,    41,    42,    11,    12,    45,   274,   274,    15,    16,
      50,    51,    52,    69,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     3,     3,    70,    68,    69,
      73,    73,   298,   299,    76,    75,    76,    72,    73,    79,
      80,    81,     3,     4,     5,     6,     7,    70,     9,    10,
      73,    70,    30,    70,    73,    69,    73,    35,    36,    37,
      38,    39,    40,    41,    42,    70,    69,    45,    73,    30,
      70,   134,   135,    73,    35,    36,    37,    38,    39,    40,
      41,    42,    70,    69,    45,    73,    69,    68,    71,    50,
      51,    52,    70,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    69,     3,    71,    68,    69,    69,
      68,    71,   136,   137,    75,    76,   142,   143,    79,    80,
      81,     3,     4,     5,     6,     7,    70,     9,    10,    72,
      70,    77,    30,    55,    68,    74,    72,    35,    36,    37,
      38,    39,    40,    41,    42,    69,    53,    45,    68,    16,
      48,   100,    40,     3,     4,     5,     6,     7,   170,     9,
      10,   145,   144,   148,    45,    97,    64,   146,    50,    51,
      52,    69,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   147,   109,    -1,    68,    69,    -1,    -1,
      -1,    -1,    -1,    75,    76,    -1,    -1,    79,    80,    81,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    68,    69,
      -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    79,
      80,    81,     3,     4,     5,     6,     7,    -1,     9,    10,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,     3,     4,     5,     6,     7,    30,     9,    10,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    68,    69,     3,
       4,     5,     6,     7,    75,     9,    10,    -1,    79,    80,
      81,    62,    63,    64,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    79,    80,
      81,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     3,     4,     5,     6,     7,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    -1,    -1,    -1,    -1,    69,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    79,    80,    81,    -1,    -1,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,     9,
      10,    62,    63,    64,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,
      81,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    62,
      63,    64,    79,    80,    81,    -1,    69,    -1,    -1,    72,
      -1,    -1,    62,    63,    64,    -1,    79,    80,    81,    69,
      70,     3,     4,     5,     6,     7,    -1,     9,    10,    79,
      80,    81,    -1,    -1,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,     9,    10,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,     9,    10,    -1,    -1,    -1,
      62,    63,    64,    -1,    -1,    -1,    68,    69,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    -1,    79,    80,    81,
      69,    -1,    -1,    72,    -1,    -1,    -1,    62,    63,    64,
      79,    80,    81,    68,    69,    62,    63,    64,    -1,    -1,
      -1,    -1,    69,    70,    79,    80,    81,    -1,    62,    63,
      64,    -1,    79,    80,    81,    69,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    79,    80,    81,    -1,     3,
       4,     5,     6,     7,    -1,     9,    10,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    45,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    45,    64,    -1,    62,    63,    64,    69,    70,
      71,     3,    69,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    -1,    79,    80,    81,    69,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    30,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    69,    70,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    30,    35,    36,    37,    38,    39,    40,    41,
      42,    45,    48,    64,    69,    89,    90,    91,    92,    93,
      94,    98,    99,   134,   136,   140,    99,     3,    75,    43,
      44,   139,   140,   141,    93,     0,    91,    69,    71,    68,
      93,   100,    99,    68,    94,    75,     3,   137,   138,   139,
     140,    70,     3,    70,    95,    96,    99,   142,     3,     4,
       5,     6,     7,     9,    10,    62,    63,    64,    69,    72,
      79,    80,    81,    97,   114,   115,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      68,    74,    75,   105,    68,   137,    74,    73,    76,    70,
      73,    69,    71,    93,   103,   104,   140,    70,    73,    69,
     117,    69,   117,   117,   117,   117,   130,   131,   133,   134,
     135,   139,   143,    72,     8,     9,    10,    69,    71,    78,
     119,    64,    65,    82,    62,    63,    11,    12,    13,    14,
      83,    84,    15,    16,    79,    85,    86,    17,    18,    87,
      75,   101,   131,     3,    50,    51,    52,    54,    55,    56,
      57,    58,    59,    60,    61,    68,    76,    98,    99,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   133,    76,
      97,   138,    96,    70,    95,   103,    72,    97,    69,    71,
     104,     3,   143,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    74,   132,    70,    73,   135,    69,   103,
     140,   135,    70,     3,    70,   116,   131,   133,     3,   119,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   122,
     123,   123,   124,   125,   126,   127,   128,   133,   101,   102,
      77,    97,    77,    69,    69,    69,   108,    69,     3,    68,
      68,    68,   133,    93,    76,    98,   107,    76,   108,    68,
      70,    70,    72,    70,    95,    72,    97,    70,   131,   131,
     119,    70,    73,    72,    77,    73,    76,   108,    77,   108,
     133,   133,   133,    55,   110,    68,    68,    76,    70,    72,
     131,   130,    76,   101,   108,    70,    70,    70,    69,   110,
     108,   108,   108,   133,    70,   133,    53,    70,   108,    70,
     108,    68,   108
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    90,    90,    91,    91,    92,    92,    92,
      92,    93,    93,    94,    94,    94,    94,    94,    94,    94,
      95,    95,    96,    96,    96,    97,    98,    98,    99,    99,
      99,    99,   100,   100,   101,   101,   101,   102,   102,   103,
     103,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   105,   105,   105,   105,   106,   106,   107,   107,   108,
     108,   108,   108,   108,   108,   109,   109,   109,   110,   110,
     111,   111,   111,   112,   112,   112,   112,   113,   113,   113,
     113,   113,   114,   114,   114,   114,   114,   115,   115,   115,
     115,   115,   115,   115,   115,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   118,   118,   118,   118,   118,   118,
     119,   119,   120,   120,   120,   120,   121,   121,   121,   122,
     122,   122,   123,   123,   123,   123,   123,   124,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   131,   131,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   133,   133,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   135,   135,   135,   135,
     136,   136,   136,   137,   137,   138,   138,   139,   139,   140,
     140,   140,   140,   141,   141,   142,   142,   143,   143
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     3,     2,
       1,     2,     1,     1,     3,     4,     3,     4,     4,     3,
       1,     3,     2,     2,     1,     1,     2,     3,     1,     2,
       1,     2,     1,     3,     1,     3,     4,     1,     3,     1,
       1,     2,     3,     2,     3,     3,     4,     2,     3,     3,
       4,     2,     3,     3,     4,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     1,     2,
       5,     7,     5,     5,     7,     6,     7,     3,     2,     2,
       2,     3,     1,     1,     1,     1,     3,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     3,     1,     2,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       4,     5,     2,     1,     3,     1,     3,     1,     1,     1,
       2,     2,     3,     1,     2,     1,     3,     1,     2
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
#line 87 "src/parser.y"
                                        { g_root = new Root((yyvsp[0].expressionList)); /*external_declaration*/ }
#line 1760 "src/parser.tab.cpp"
    break;

  case 3:
#line 90 "src/parser.y"
                                                                        { (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 1766 "src/parser.tab.cpp"
    break;

  case 4:
#line 91 "src/parser.y"
                                                        { appendToExprList((yyvsp[-1].expressionList), (yyvsp[0].expr)); }
#line 1772 "src/parser.tab.cpp"
    break;

  case 5:
#line 95 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1778 "src/parser.tab.cpp"
    break;

  case 6:
#line 96 "src/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1784 "src/parser.tab.cpp"
    break;

  case 7:
#line 100 "src/parser.y"
                                                                { (yyval.expr) = new Full_Function(new Function_Definition(*(yyvsp[-2].string), (yyvsp[-1].expr)), (yyvsp[0].expressionList)); }
#line 1790 "src/parser.tab.cpp"
    break;

  case 8:
#line 101 "src/parser.y"
                                                                                        { (yyval.expr) = new Function_Call_Definition(*(yyvsp[-2].string), (yyvsp[-1].expr));}
#line 1796 "src/parser.tab.cpp"
    break;

  case 9:
#line 102 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 1802 "src/parser.tab.cpp"
    break;

  case 12:
#line 108 "src/parser.y"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1808 "src/parser.tab.cpp"
    break;

  case 13:
#line 112 "src/parser.y"
                                                                                                { (yyval.expr) = new Declarator(*(yyvsp[0].string));}
#line 1814 "src/parser.tab.cpp"
    break;

  case 14:
#line 113 "src/parser.y"
                                                                                        { (yyval.expr) = (yyvsp[-1].expr); }
#line 1820 "src/parser.tab.cpp"
    break;

  case 15:
#line 114 "src/parser.y"
                                                                { (yyval.expr) = new ArrayDeclarator((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1826 "src/parser.tab.cpp"
    break;

  case 16:
#line 115 "src/parser.y"
                                                                                        { (yyval.expr) = new ArrayDeclarator((yyvsp[-2].expr)); }
#line 1832 "src/parser.tab.cpp"
    break;

  case 17:
#line 116 "src/parser.y"
                                                                        { (yyval.expr) = new FunctionDeclarator((yyvsp[-3].expr), ((yyvsp[-1].expressionList)));}
#line 1838 "src/parser.tab.cpp"
    break;

  case 18:
#line 117 "src/parser.y"
                                                                        { (yyval.expr) = new FunctionDeclarator((yyvsp[-3].expr), ((yyvsp[-1].expressionList)));}
#line 1844 "src/parser.tab.cpp"
    break;

  case 19:
#line 118 "src/parser.y"
                                                                                        { (yyval.expr) = new FunctionDeclarator((yyvsp[-2].expr));}
#line 1850 "src/parser.tab.cpp"
    break;

  case 20:
#line 123 "src/parser.y"
                                                                        {  (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 1856 "src/parser.tab.cpp"
    break;

  case 21:
#line 124 "src/parser.y"
                                                        { appendToExprList((yyvsp[-2].expressionList), (yyvsp[0].expr)); }
#line 1862 "src/parser.tab.cpp"
    break;

  case 22:
#line 128 "src/parser.y"
                                                                        { (yyval.expr) = new Declare(*(yyvsp[-1].string), (yyvsp[0].expr));}
#line 1868 "src/parser.tab.cpp"
    break;

  case 23:
#line 129 "src/parser.y"
                                                        { (yyval.expr) = new Declare(*(yyvsp[-1].string), (yyvsp[0].expr));}
#line 1874 "src/parser.tab.cpp"
    break;

  case 25:
#line 134 "src/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1880 "src/parser.tab.cpp"
    break;

  case 26:
#line 139 "src/parser.y"
                                                                                { ; }
#line 1886 "src/parser.tab.cpp"
    break;

  case 27:
#line 140 "src/parser.y"
                                                        { (yyval.expr) = new Declare(*(yyvsp[-2].string), (yyvsp[-1].expr));}
#line 1892 "src/parser.tab.cpp"
    break;

  case 28:
#line 145 "src/parser.y"
                                                                                                { (yyval.string) == (yyvsp[0].string); }
#line 1898 "src/parser.tab.cpp"
    break;

  case 32:
#line 154 "src/parser.y"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1904 "src/parser.tab.cpp"
    break;

  case 33:
#line 155 "src/parser.y"
                                                { (yyval.expr) = new InitDeclarator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1910 "src/parser.tab.cpp"
    break;

  case 34:
#line 160 "src/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1916 "src/parser.tab.cpp"
    break;

  case 35:
#line 161 "src/parser.y"
                                                { (yyval.expr) = new ArrayInit((yyvsp[-1].expressionList)); }
#line 1922 "src/parser.tab.cpp"
    break;

  case 36:
#line 162 "src/parser.y"
                                        { (yyval.expr) = new ArrayInit((yyvsp[-2].expressionList)); }
#line 1928 "src/parser.tab.cpp"
    break;

  case 37:
#line 166 "src/parser.y"
                                                                {  (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 1934 "src/parser.tab.cpp"
    break;

  case 38:
#line 167 "src/parser.y"
                                                { appendToExprList((yyvsp[-2].expressionList), (yyvsp[0].expr)); }
#line 1940 "src/parser.tab.cpp"
    break;

  case 40:
#line 172 "src/parser.y"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1946 "src/parser.tab.cpp"
    break;

  case 42:
#line 177 "src/parser.y"
                                                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 1952 "src/parser.tab.cpp"
    break;

  case 43:
#line 178 "src/parser.y"
                                                                                                                        { ; }
#line 1958 "src/parser.tab.cpp"
    break;

  case 44:
#line 179 "src/parser.y"
                                                                                                { ; }
#line 1964 "src/parser.tab.cpp"
    break;

  case 45:
#line 180 "src/parser.y"
                                                                                        { (yyval.expr) = new ArrayDeclarator((yyvsp[-2].expr)); }
#line 1970 "src/parser.tab.cpp"
    break;

  case 46:
#line 181 "src/parser.y"
                                                                        { (yyval.expr) = new ArrayDeclarator((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1976 "src/parser.tab.cpp"
    break;

  case 47:
#line 182 "src/parser.y"
                                                                                                                        { ; }
#line 1982 "src/parser.tab.cpp"
    break;

  case 48:
#line 183 "src/parser.y"
                                                                                                        { ; }
#line 1988 "src/parser.tab.cpp"
    break;

  case 49:
#line 184 "src/parser.y"
                                                                                        { ; }
#line 1994 "src/parser.tab.cpp"
    break;

  case 50:
#line 185 "src/parser.y"
                                                                                { ; }
#line 2000 "src/parser.tab.cpp"
    break;

  case 51:
#line 190 "src/parser.y"
                                                                                                { (yyval.expressionList) = new ExpressionList();}
#line 2006 "src/parser.tab.cpp"
    break;

  case 52:
#line 191 "src/parser.y"
                                                                                { (yyval.expressionList) = new ExpressionList((yyvsp[-1].expressionList)); }
#line 2012 "src/parser.tab.cpp"
    break;

  case 53:
#line 192 "src/parser.y"
                                                                                { (yyval.expressionList) = new ExpressionList((yyvsp[-1].expressionList)); }
#line 2018 "src/parser.tab.cpp"
    break;

  case 54:
#line 194 "src/parser.y"
                                                                { (yyval.expressionList) = new ExpressionList(); appendToExprList((yyval.expressionList), (yyvsp[-2].expressionList)); appendToExprList((yyval.expressionList), (yyvsp[-1].expressionList)); }
#line 2024 "src/parser.tab.cpp"
    break;

  case 55:
#line 201 "src/parser.y"
                                                        { (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 2030 "src/parser.tab.cpp"
    break;

  case 56:
#line 202 "src/parser.y"
                                        { appendToExprList((yyvsp[-1].expressionList), (yyvsp[0].expr)); }
#line 2036 "src/parser.tab.cpp"
    break;

  case 57:
#line 207 "src/parser.y"
                                                        {  (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 2042 "src/parser.tab.cpp"
    break;

  case 58:
#line 208 "src/parser.y"
                                        { appendToExprList((yyvsp[-1].expressionList), (yyvsp[0].expr)); }
#line 2048 "src/parser.tab.cpp"
    break;

  case 59:
#line 212 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2054 "src/parser.tab.cpp"
    break;

  case 60:
#line 213 "src/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2060 "src/parser.tab.cpp"
    break;

  case 61:
#line 214 "src/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2066 "src/parser.tab.cpp"
    break;

  case 62:
#line 215 "src/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2072 "src/parser.tab.cpp"
    break;

  case 63:
#line 216 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2078 "src/parser.tab.cpp"
    break;

  case 64:
#line 217 "src/parser.y"
                                { /* $$ = $1; */ (yyval.expr) = new Scope((yyvsp[0].expressionList)); }
#line 2084 "src/parser.tab.cpp"
    break;

  case 68:
#line 228 "src/parser.y"
                                        { (yyval.expr) = new EmptyExpr(); }
#line 2090 "src/parser.tab.cpp"
    break;

  case 69:
#line 229 "src/parser.y"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 2096 "src/parser.tab.cpp"
    break;

  case 70:
#line 233 "src/parser.y"
                                                                { (yyval.expr) = new If((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2102 "src/parser.tab.cpp"
    break;

  case 71:
#line 234 "src/parser.y"
                                                                { (yyval.expr) = new IfElse((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); /* dangling else problem */ }
#line 2108 "src/parser.tab.cpp"
    break;

  case 72:
#line 235 "src/parser.y"
                                                                        { (yyval.expr) = new SwitchCase((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2114 "src/parser.tab.cpp"
    break;

  case 73:
#line 239 "src/parser.y"
                                                                                                                                { (yyval.expr) = new WhileLoop((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2120 "src/parser.tab.cpp"
    break;

  case 75:
#line 241 "src/parser.y"
                                                                                                        { (yyval.expr) = new ForLoop((yyvsp[-3].expr), (yyvsp[-2].expr), new EmptyExpr(), (yyvsp[0].expr)); }
#line 2126 "src/parser.tab.cpp"
    break;

  case 76:
#line 242 "src/parser.y"
                                                                                        { (yyval.expr) = new ForLoop((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); /* interior initialisation eg. int x=0, breakes the parser*/ }
#line 2132 "src/parser.tab.cpp"
    break;

  case 80:
#line 249 "src/parser.y"
                                        { (yyval.expr) = new Return(new Integer()); }
#line 2138 "src/parser.tab.cpp"
    break;

  case 81:
#line 250 "src/parser.y"
                                { (yyval.expr) = new Return((yyvsp[-1].expr)); }
#line 2144 "src/parser.tab.cpp"
    break;

  case 82:
#line 256 "src/parser.y"
                                        { (yyval.expr) = new Declarator( *(yyvsp[0].string) );}
#line 2150 "src/parser.tab.cpp"
    break;

  case 83:
#line 257 "src/parser.y"
                                        { (yyval.expr) = new Integer( (yyvsp[0].integer) );}
#line 2156 "src/parser.tab.cpp"
    break;

  case 84:
#line 258 "src/parser.y"
                                        { /*$$ = new Float( $1 );*/ }
#line 2162 "src/parser.tab.cpp"
    break;

  case 85:
#line 259 "src/parser.y"
                                        { (yyval.expr) = new Character( *(yyvsp[0].string) );}
#line 2168 "src/parser.tab.cpp"
    break;

  case 86:
#line 260 "src/parser.y"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 2174 "src/parser.tab.cpp"
    break;

  case 87:
#line 264 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2180 "src/parser.tab.cpp"
    break;

  case 88:
#line 265 "src/parser.y"
                                                                                { (yyval.expr) = new ArrayCall((yyvsp[-3].expr), (yyvsp[-1].expr));}
#line 2186 "src/parser.tab.cpp"
    break;

  case 89:
#line 266 "src/parser.y"
                                                                                        { (yyval.expr) = new FunctionCall((yyvsp[-2].expr));}
#line 2192 "src/parser.tab.cpp"
    break;

  case 90:
#line 267 "src/parser.y"
                                                                { (yyval.expr) = new FunctionCall((yyvsp[-3].expr), (yyvsp[-1].expressionList));}
#line 2198 "src/parser.tab.cpp"
    break;

  case 93:
#line 270 "src/parser.y"
                                                                                        { (yyval.expr) = new PostIncrementOperator((yyvsp[-1].expr));}
#line 2204 "src/parser.tab.cpp"
    break;

  case 94:
#line 271 "src/parser.y"
                                                                                        { (yyval.expr) = new PostDecrementOperator((yyvsp[-1].expr));}
#line 2210 "src/parser.tab.cpp"
    break;

  case 95:
#line 275 "src/parser.y"
                                                                                                { (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 2216 "src/parser.tab.cpp"
    break;

  case 96:
#line 276 "src/parser.y"
                                                                { appendToExprList((yyvsp[-2].expressionList), (yyvsp[0].expr)); }
#line 2222 "src/parser.tab.cpp"
    break;

  case 97:
#line 280 "src/parser.y"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2228 "src/parser.tab.cpp"
    break;

  case 98:
#line 281 "src/parser.y"
                                                { (yyval.expr) = new PreIncrementOperator((yyvsp[0].expr));}
#line 2234 "src/parser.tab.cpp"
    break;

  case 99:
#line 282 "src/parser.y"
                                                { (yyval.expr) = new PreDecrementOperator((yyvsp[0].expr));}
#line 2240 "src/parser.tab.cpp"
    break;

  case 100:
#line 283 "src/parser.y"
                                                { /* HOW */ }
#line 2246 "src/parser.tab.cpp"
    break;

  case 101:
#line 284 "src/parser.y"
                                                        { (yyval.expr) = new NegOperator((yyvsp[0].expr)); }
#line 2252 "src/parser.tab.cpp"
    break;

  case 104:
#line 290 "src/parser.y"
                        { /* pointer address */ }
#line 2258 "src/parser.tab.cpp"
    break;

  case 105:
#line 291 "src/parser.y"
                        { /* pointer value */ }
#line 2264 "src/parser.tab.cpp"
    break;

  case 106:
#line 292 "src/parser.y"
                        { /* same as $2 */ }
#line 2270 "src/parser.tab.cpp"
    break;

  case 107:
#line 293 "src/parser.y"
                        { /* neg */ }
#line 2276 "src/parser.tab.cpp"
    break;

  case 109:
#line 295 "src/parser.y"
                        { /* logic NOT */ }
#line 2282 "src/parser.tab.cpp"
    break;

  case 110:
#line 299 "src/parser.y"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2288 "src/parser.tab.cpp"
    break;

  case 112:
#line 304 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2294 "src/parser.tab.cpp"
    break;

  case 113:
#line 305 "src/parser.y"
                                                                { (yyval.expr) = new MulOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2300 "src/parser.tab.cpp"
    break;

  case 114:
#line 306 "src/parser.y"
                                                                { (yyval.expr) = new DivOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2306 "src/parser.tab.cpp"
    break;

  case 115:
#line 307 "src/parser.y"
                                                                { (yyval.expr) = new ModOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2312 "src/parser.tab.cpp"
    break;

  case 116:
#line 311 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2318 "src/parser.tab.cpp"
    break;

  case 117:
#line 312 "src/parser.y"
                                                                        { (yyval.expr) = new AddOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2324 "src/parser.tab.cpp"
    break;

  case 118:
#line 313 "src/parser.y"
                                                                        { (yyval.expr) = new SubOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2330 "src/parser.tab.cpp"
    break;

  case 119:
#line 317 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2336 "src/parser.tab.cpp"
    break;

  case 120:
#line 318 "src/parser.y"
                                                                        { (yyval.expr) = new LeftShiftOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2342 "src/parser.tab.cpp"
    break;

  case 121:
#line 319 "src/parser.y"
                                                                { (yyval.expr) = new RightShiftOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2348 "src/parser.tab.cpp"
    break;

  case 122:
#line 323 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2354 "src/parser.tab.cpp"
    break;

  case 123:
#line 324 "src/parser.y"
                                                                { (yyval.expr) = new SmallerOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2360 "src/parser.tab.cpp"
    break;

  case 124:
#line 325 "src/parser.y"
                                                                { (yyval.expr) = new GreaterOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2366 "src/parser.tab.cpp"
    break;

  case 125:
#line 326 "src/parser.y"
                                                                { (yyval.expr) = new LEOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2372 "src/parser.tab.cpp"
    break;

  case 126:
#line 327 "src/parser.y"
                                                                { (yyval.expr) = new GEOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2378 "src/parser.tab.cpp"
    break;

  case 127:
#line 331 "src/parser.y"
                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2384 "src/parser.tab.cpp"
    break;

  case 128:
#line 332 "src/parser.y"
                                                                { (yyval.expr) = new EQOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2390 "src/parser.tab.cpp"
    break;

  case 129:
#line 333 "src/parser.y"
                                                                { (yyval.expr) = new NEOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2396 "src/parser.tab.cpp"
    break;

  case 130:
#line 337 "src/parser.y"
                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2402 "src/parser.tab.cpp"
    break;

  case 131:
#line 338 "src/parser.y"
                                                        { (yyval.expr) = new ANDOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2408 "src/parser.tab.cpp"
    break;

  case 132:
#line 342 "src/parser.y"
                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2414 "src/parser.tab.cpp"
    break;

  case 133:
#line 343 "src/parser.y"
                                                        { (yyval.expr) = new XOROperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2420 "src/parser.tab.cpp"
    break;

  case 134:
#line 347 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2426 "src/parser.tab.cpp"
    break;

  case 135:
#line 348 "src/parser.y"
                                                                { (yyval.expr) = new OROperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2432 "src/parser.tab.cpp"
    break;

  case 136:
#line 352 "src/parser.y"
                                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2438 "src/parser.tab.cpp"
    break;

  case 137:
#line 353 "src/parser.y"
                                                                        { (yyval.expr) = new LogicalANDOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2444 "src/parser.tab.cpp"
    break;

  case 138:
#line 357 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2450 "src/parser.tab.cpp"
    break;

  case 139:
#line 358 "src/parser.y"
                                                                { (yyval.expr) = new LogicalOROperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2456 "src/parser.tab.cpp"
    break;

  case 140:
#line 362 "src/parser.y"
                                                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2462 "src/parser.tab.cpp"
    break;

  case 142:
#line 367 "src/parser.y"
                                     { (yyval.expr) = (yyvsp[0].expr); }
#line 2468 "src/parser.tab.cpp"
    break;

  case 143:
#line 368 "src/parser.y"
                                                                        { (yyval.expr) = new AssignOperator((yyvsp[-2].expr), *(yyvsp[-1].string), (yyvsp[0].expr));  }
#line 2474 "src/parser.tab.cpp"
    break;

  case 144:
#line 372 "src/parser.y"
                             { (yyval.string) = new std::string("="); }
#line 2480 "src/parser.tab.cpp"
    break;

  case 145:
#line 373 "src/parser.y"
                             { (yyval.string) = new std::string("*="); }
#line 2486 "src/parser.tab.cpp"
    break;

  case 146:
#line 374 "src/parser.y"
                             { (yyval.string) = new std::string("/="); }
#line 2492 "src/parser.tab.cpp"
    break;

  case 147:
#line 375 "src/parser.y"
                             { (yyval.string) = new std::string("%="); }
#line 2498 "src/parser.tab.cpp"
    break;

  case 148:
#line 376 "src/parser.y"
                             { (yyval.string) = new std::string("+="); }
#line 2504 "src/parser.tab.cpp"
    break;

  case 149:
#line 377 "src/parser.y"
                             { (yyval.string) = new std::string("-="); }
#line 2510 "src/parser.tab.cpp"
    break;

  case 150:
#line 378 "src/parser.y"
                             { (yyval.string) = new std::string("<<="); }
#line 2516 "src/parser.tab.cpp"
    break;

  case 151:
#line 379 "src/parser.y"
                             { (yyval.string) = new std::string(">>="); }
#line 2522 "src/parser.tab.cpp"
    break;

  case 152:
#line 380 "src/parser.y"
                             { (yyval.string) = new std::string("&="); }
#line 2528 "src/parser.tab.cpp"
    break;

  case 153:
#line 381 "src/parser.y"
                             { (yyval.string) = new std::string("^="); }
#line 2534 "src/parser.tab.cpp"
    break;

  case 154:
#line 382 "src/parser.y"
                             { (yyval.string) = new std::string("|="); }
#line 2540 "src/parser.tab.cpp"
    break;

  case 155:
#line 386 "src/parser.y"
                                                                        {(yyval.expr) = (yyvsp[0].expr); /*{ $$ = initExprList($1); }*/}
#line 2546 "src/parser.tab.cpp"
    break;

  case 156:
#line 387 "src/parser.y"
                                                        { /* appendToExprList($1, $2); */ }
#line 2552 "src/parser.tab.cpp"
    break;

  case 157:
#line 395 "src/parser.y"
                                { (yyval.string) = new std::string("void"); }
#line 2558 "src/parser.tab.cpp"
    break;

  case 158:
#line 396 "src/parser.y"
                                { (yyval.string) = new std::string("char"); }
#line 2564 "src/parser.tab.cpp"
    break;

  case 160:
#line 398 "src/parser.y"
                                { (yyval.string) = new std::string("int"); }
#line 2570 "src/parser.tab.cpp"
    break;

  case 162:
#line 400 "src/parser.y"
                                { (yyval.string) = new std::string("float");}
#line 2576 "src/parser.tab.cpp"
    break;

  case 170:
#line 447 "src/parser.y"
                                                                { (yyval.expr) = new Enum( (yyvsp[-1].expressionList) ); }
#line 2582 "src/parser.tab.cpp"
    break;

  case 171:
#line 448 "src/parser.y"
                                                        { (yyval.expr) = new Enum( new Declarator(*(yyvsp[-3].string)), (yyvsp[-1].expressionList) ); }
#line 2588 "src/parser.tab.cpp"
    break;

  case 172:
#line 449 "src/parser.y"
                                                                                { (yyval.expr) = new Enum( new Declarator(*(yyvsp[0].string)) ); }
#line 2594 "src/parser.tab.cpp"
    break;

  case 173:
#line 453 "src/parser.y"
                                                                { (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 2600 "src/parser.tab.cpp"
    break;

  case 174:
#line 454 "src/parser.y"
                                                { appendToExprList((yyvsp[-2].expressionList), (yyvsp[0].expr)); }
#line 2606 "src/parser.tab.cpp"
    break;

  case 175:
#line 458 "src/parser.y"
                                                                        { (yyval.expr) = new EnumDeclarator( *(yyvsp[0].string) ); }
#line 2612 "src/parser.tab.cpp"
    break;

  case 176:
#line 459 "src/parser.y"
                                                { (yyval.expr) = new AssignEnum( *(yyvsp[-2].string), (yyvsp[0].expr) );}
#line 2618 "src/parser.tab.cpp"
    break;


#line 2622 "src/parser.tab.cpp"

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
#line 497 "src/parser.y"


const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST(std::string input_file)
{
  yyin = fopen(input_file.c_str(), "r");
  if(yyin == NULL){
    std::cerr << "ERROR: Couldn't open input file: " << input_file << std::endl;
    exit(1);
  }

  g_root=0;
  yyparse();
  return g_root;
}
