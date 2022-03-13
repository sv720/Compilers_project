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
    CHAR_LITERAL = 260,
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
    RETURN = 315,
    uminu = 316,
    NOELSE = 317
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "src/parser.y"

  const Expression *expr;
  ExpressionList *expressionList;
  int integer;
  double numberFloat;
  std::string *string;
  yytokentype token;

#line 209 "src/parser.tab.cpp"

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
#define YYLAST   921

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  185
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  309

#define YYUNDEFTOK  2
#define YYMAXUTOK   317


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
       2,     2,     2,    80,     2,     2,     2,    81,    78,     2,
      67,    68,    63,    61,    71,    62,    77,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    76,    72,
      82,    73,    83,    86,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,    85,    75,    79,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    86,    87,    91,    92,    96,    97,   101,
     102,   106,   107,   108,   109,   110,   111,   112,   117,   118,
     122,   123,   124,   128,   133,   134,   139,   140,   141,   142,
     148,   149,   154,   155,   156,   160,   161,   165,   166,   167,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   184,
     185,   186,   188,   195,   196,   201,   202,   206,   207,   208,
     209,   210,   211,   216,   217,   218,   222,   223,   227,   228,
     229,   233,   234,   235,   236,   240,   241,   242,   243,   244,
     250,   251,   254,   258,   259,   260,   261,   262,   263,   264,
     265,   269,   270,   274,   275,   276,   277,   278,   279,   280,
     284,   285,   286,   287,   288,   289,   293,   294,   298,   299,
     300,   301,   305,   306,   307,   311,   312,   313,   317,   318,
     319,   320,   321,   325,   326,   327,   331,   332,   336,   337,
     341,   342,   346,   347,   351,   352,   356,   357,   361,   362,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   380,   381,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   399,   423,   424,   425,   426,   441,   442,   443,
     447,   448,   452,   453,   457,   458,   462,   463,   464,   465,
     469,   470,   477,   478,   482,   483
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INT_LITERAL",
  "CHAR_LITERAL", "SIZEOF", "POINTER_OP", "INCREMENT_OP", "DECREMENT_OP",
  "LEFTSHIFT_OP", "RIGHTSHIFT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFTSHIFT_ASSIGN", "RIGHTSHIFT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPE_NAME", "TYPEDEF",
  "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR", "SHORT", "INT", "LONG",
  "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID",
  "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN",
  "'+'", "'-'", "'*'", "'/'", "uminu", "NOELSE", "'('", "')'", "'['",
  "']'", "','", "';'", "'='", "'{'", "'}'", "':'", "'.'", "'&'", "'~'",
  "'!'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "$accept", "ROOT",
  "translation_unit", "external_declaration", "function_definition",
  "declarator", "direct_declarator", "parameter_list",
  "parameter_declaration", "constant_expression", "declaration",
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
  "type_specifier", "specifier_qualifier_list", "enum_specifier",
  "enumerator_list", "enumerator", "type_qualifier", "pointer",
  "type_qualifier_list", "identifier_list", "type_name", YY_NULLPTR
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
     315,    43,    45,    42,    47,   316,   317,    40,    41,    91,
      93,    44,    59,    61,   123,   125,    58,    46,    38,   126,
      33,    37,    60,    62,    94,   124,    63
};
# endif

#define YYPACT_NINF (-224)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     803,  -224,   125,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,     6,   -26,   104,    41,   803,  -224,  -224,  -224,
     -21,  -224,   114,   125,  -224,    48,  -224,    -7,    53,  -224,
    -224,  -224,  -224,   -26,     7,  -224,  -224,   763,   506,  -224,
      76,    15,  -224,   -21,    53,    47,    68,  -224,  -224,  -224,
    -224,  -224,  -224,    87,  -224,    75,   129,  -224,  -224,   658,
     679,   679,  -224,   278,  -224,   486,  -224,  -224,  -224,  -224,
      86,  -224,    56,  -224,   702,  -224,   -29,   118,   256,    -1,
     208,    51,    84,    55,   157,    -3,  -224,   128,   190,  -224,
    -224,    70,   702,    53,  -224,  -224,   125,   749,   528,  -224,
    -224,   187,    10,  -224,   198,   486,  -224,   702,  -224,  -224,
    -224,   801,  -224,  -224,   141,   867,    59,   867,   148,  -224,
     233,  -224,  -224,   548,   702,   239,  -224,   702,   702,   702,
     702,   702,   702,   702,   702,   702,   702,   702,   702,   702,
     702,   702,   702,   702,   702,   702,   128,  -224,  -224,   179,
     702,   185,   206,   218,   249,   424,   253,   276,   220,   260,
     571,  -224,  -224,  -224,   114,  -224,   268,   330,  -224,  -224,
    -224,  -224,  -224,  -224,   222,  -224,  -224,  -224,  -224,  -224,
     142,   269,  -224,   274,   853,   593,   187,  -224,   281,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
     702,  -224,   702,  -224,   817,  -224,   221,  -224,   702,  -224,
    -224,   143,  -224,   225,  -224,  -224,  -224,  -224,   -29,   -29,
     118,   118,   256,   256,   256,   256,    -1,    -1,   208,    51,
      84,    55,   157,   -31,  -224,   107,   424,   275,   424,   702,
     702,   702,   296,   614,   280,  -224,  -224,  -224,   227,   282,
    -224,  -224,   362,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
     149,  -224,   283,  -224,  -224,  -224,  -224,  -224,   702,  -224,
     702,   392,  -224,  -224,   424,  -224,   150,   167,   192,   287,
     614,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,   424,   424,   424,   702,   636,   307,  -224,  -224,   207,
     424,   212,   424,   288,  -224,   424,  -224,  -224,  -224
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,    28,   154,   155,   156,   157,   160,   161,   158,
     159,   153,     0,   176,     0,     0,     2,     3,     5,     8,
      10,     6,     0,    26,   162,     0,    29,   169,     0,   174,
     175,   180,   178,   177,     0,     1,     4,     0,     0,    24,
      30,     0,    27,     9,     0,   172,     0,   170,   181,   179,
      12,   182,    17,     0,    18,    22,     0,    80,    81,     0,
       0,     0,   102,   103,   101,     0,    14,   100,   104,   105,
       0,    83,    93,   106,     0,   108,   112,   115,   118,   123,
     126,   128,   130,   132,   134,   136,    23,     0,     0,     7,
      25,     0,     0,     0,   167,    15,     0,     0,     0,    20,
      21,    38,    37,    16,     0,     0,    98,     0,    94,    95,
      97,   106,   138,   151,     0,   164,   184,   166,     0,    13,
       0,    89,    90,     0,     0,     0,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    49,    53,     0,    62,     0,     0,    55,    57,
      58,    59,    60,    61,     0,   168,   173,   171,    19,    45,
       0,     0,    41,     0,     0,     0,    39,   183,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   140,
       0,    82,     0,   163,     0,   185,    37,   165,     0,    88,
      85,     0,    91,     0,    87,   109,   110,   111,   113,   114,
     116,   117,   121,   122,   119,   120,   124,   125,   127,   129,
     131,   133,   135,     0,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,    78,     0,    30,
      50,    54,     0,    51,    56,    67,    46,    40,    42,    47,
       0,    43,     0,    99,   139,   152,   107,    86,     0,    84,
       0,     0,    33,    63,     0,    65,     0,     0,     0,     0,
       0,    75,    79,    52,    48,    44,    92,   137,    34,    36,
      64,     0,     0,     0,     0,     0,    68,    70,    71,     0,
       0,     0,     0,     0,    73,     0,    69,    72,    74
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -224,  -224,  -224,   345,  -224,   -12,   -18,   -33,   266,   -39,
     -80,    26,  -224,  -141,  -224,   -40,   -96,   323,  -224,   201,
    -117,  -224,  -223,  -224,  -224,  -224,  -224,  -224,  -224,   -38,
    -224,   -55,   170,   178,  -104,   175,   224,   228,   230,   231,
     229,  -224,   -37,   -84,  -224,   -36,   -47,   174,  -224,   331,
     284,    14,    11,  -224,  -224,   271
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    18,    19,    20,   180,    54,    70,
      21,    55,    41,   147,   235,   181,   101,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    71,    72,   211,   111,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,   112,   113,   200,   174,    23,   116,    24,    46,
      47,   117,    25,    33,    56,   118
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    86,    34,   148,    53,   234,   186,    43,   163,    27,
      40,   134,   135,     1,   144,   100,    29,    30,   115,   126,
     280,   106,   108,   109,    32,   110,    22,    31,    26,   114,
     222,   223,   224,   225,   127,   128,    73,    13,   242,   212,
     202,    35,    22,    99,    49,   270,    37,    48,    38,    42,
     254,     1,   129,   176,    73,    86,    45,   295,   115,   183,
      73,    86,   148,   120,   121,   122,   102,    44,   115,   114,
     115,   114,   215,   216,   217,    50,   205,    97,     1,    98,
      28,   136,   137,   145,    43,    34,   251,    90,   213,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,     1,   102,   233,
     186,   237,    73,    86,   164,    14,   264,     1,   265,   273,
      92,   275,    13,   123,   248,   124,   204,   206,    98,   140,
     289,    57,    58,   125,    59,   254,    60,    61,    13,    93,
     142,    93,    97,    94,    98,   175,   262,    73,    86,    87,
      88,   260,   249,   266,     2,    95,   119,   290,    96,     3,
       4,     5,     6,     7,     8,     9,    10,    13,   141,    11,
      73,    14,    12,   143,   296,   297,   298,    13,   271,   130,
     131,    14,   272,   304,   286,   306,    39,   148,   308,    62,
      63,    64,   164,   149,    58,    65,    59,   103,    60,    61,
     104,   187,   146,   276,   277,   278,    67,    68,    69,   201,
     256,   267,   202,    96,   268,   206,   208,   284,   291,     2,
      96,   202,   138,   139,     3,     4,     5,     6,     7,     8,
       9,    10,    73,   287,    11,   292,   209,    12,   202,   150,
     151,   152,   214,   153,   154,   155,   156,   157,   158,   159,
     160,    62,    63,    64,   184,   236,   185,    65,   299,   301,
     293,   238,   161,   202,    88,   162,   132,   133,    67,    68,
      69,   149,    58,   239,    59,   303,    60,    61,   202,   244,
     305,    57,    58,   202,    59,   240,    60,    61,   204,   203,
      98,   207,   245,   202,   255,   269,   202,     2,   202,   282,
     218,   219,     3,     4,     5,     6,     7,     8,     9,    10,
     220,   221,    11,   226,   227,    12,   241,   150,   151,   152,
     243,   153,   154,   155,   156,   157,   158,   159,   160,    62,
      63,    64,   246,   149,    58,    65,    59,   257,    60,    61,
     161,    64,    88,   250,   258,   107,    67,    68,    69,   263,
     279,   274,   281,   285,   294,    87,    67,    68,    69,   302,
     307,    36,   178,    89,   228,   149,    58,   252,    59,   229,
      60,    61,   230,   232,   231,    91,   188,   177,     0,   150,
     151,   152,     0,   153,   154,   155,   156,   157,   158,   159,
     160,    62,    63,    64,     0,    57,    58,    65,    59,     0,
      60,    61,   161,     0,    88,   253,     0,     0,    67,    68,
      69,   150,   151,   152,     0,   153,   154,   155,   156,   157,
     158,   159,   160,    62,    63,    64,     0,   149,    58,    65,
      59,     0,    60,    61,   161,     0,    88,   283,     0,     0,
      67,    68,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,    63,    64,     0,     0,     0,    65,
       0,     0,     0,     0,     0,     0,   146,   288,     0,     0,
      67,    68,    69,   150,   151,   152,     0,   153,   154,   155,
     156,   157,   158,   159,   160,    62,    63,    64,     0,    57,
      58,    65,    59,     0,    60,    61,   161,     0,    88,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,    57,
      58,     0,    59,     0,    60,    61,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    29,    30,
      11,    57,    58,    12,    59,     0,    60,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    63,    64,
       0,    57,    58,    65,    59,     0,    60,    61,     0,     0,
       0,     0,     0,     0,    67,    68,    69,    62,    63,    64,
       0,     0,     0,    65,    57,    58,    66,    59,     0,    60,
      61,     0,     0,     0,    67,    68,    69,     0,     0,    62,
      63,    64,     0,     0,     0,    65,    57,    58,   182,    59,
       0,    60,    61,     0,     0,     0,    67,    68,    69,    62,
      63,    64,     0,     0,     0,    65,   210,    57,    58,     0,
      59,     0,    60,    61,     0,     0,    67,    68,    69,     0,
       0,     0,    62,    63,    64,     0,     0,     0,    65,    57,
      58,     0,    59,   247,    60,    61,     0,     0,     0,    67,
      68,    69,     0,     0,    62,    63,    64,     0,     0,     0,
      65,    57,    58,   261,    59,     0,    60,    61,     0,     0,
       0,    67,    68,    69,     0,    62,    63,    64,     0,     0,
       0,    65,    57,    58,     0,    59,   161,    60,    61,     0,
       0,     0,    67,    68,    69,     0,     0,    62,    63,    64,
       0,     0,     0,    65,   300,    57,    58,     0,    59,     0,
      60,    61,     0,     0,    67,    68,    69,     0,     0,    62,
      63,    64,     0,     0,     0,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,     0,
      62,    63,    64,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,    67,    68,    69,
       0,     0,     0,    62,    63,    64,    51,     0,     0,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
      67,    68,    69,     3,     4,     5,     6,     7,     8,     9,
      10,     0,     2,    11,     0,     0,    12,     3,     4,     5,
       6,     7,     8,     9,    10,     0,     1,    11,     0,     0,
      12,     0,    13,     0,     0,     0,    97,   179,    98,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,     0,
       0,    52,     2,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,     2,    11,     0,     0,
      12,     3,     4,     5,     6,     7,     8,     9,    10,     0,
       0,    11,     0,     0,    12,     0,    13,     0,     0,     0,
      14,     0,     0,     0,   199,     0,     0,     0,     0,     0,
      13,     0,     2,     0,   204,   179,    98,     3,     4,     5,
       6,     7,     8,     9,    10,     0,     0,    11,     0,     0,
      12,     3,     4,     5,     6,     7,     8,     9,    10,    29,
      30,    11,     0,     0,    12,     0,     0,     0,     0,     0,
       0,   259
};

static const yytype_int16 yycheck[] =
{
      38,    38,    14,    87,    37,   146,   102,    25,    88,     3,
      22,    12,    13,     3,    17,    55,    42,    43,    65,    74,
     243,    59,    60,    61,    13,    63,     0,    13,     2,    65,
     134,   135,   136,   137,    63,    64,    74,    63,   155,   123,
      71,     0,    16,    55,    33,    76,    67,    33,    69,    23,
     167,     3,    81,    92,    92,    92,     3,   280,   105,    98,
      98,    98,   146,     7,     8,     9,    55,    74,   115,   105,
     117,   107,   127,   128,   129,    68,   116,    67,     3,    69,
      74,    82,    83,    86,   102,    97,   166,    72,   124,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     3,    97,   145,
     206,   150,   150,   150,    88,    67,   200,     3,   202,   236,
      73,   238,    63,    67,   160,    69,    67,   116,    69,    78,
     271,     3,     4,    77,     6,   252,     8,     9,    63,    71,
      85,    71,    67,    75,    69,    75,   185,   185,   185,    73,
      74,   184,   164,   208,    29,    68,    70,   274,    71,    34,
      35,    36,    37,    38,    39,    40,    41,    63,    84,    44,
     208,    67,    47,    16,   291,   292,   293,    63,    71,    61,
      62,    67,    75,   300,   268,   302,    72,   271,   305,    61,
      62,    63,   166,     3,     4,    67,     6,    68,     8,     9,
      71,     3,    74,   239,   240,   241,    78,    79,    80,    68,
      68,    68,    71,    71,    71,   204,    68,    68,    68,    29,
      71,    71,    14,    15,    34,    35,    36,    37,    38,    39,
      40,    41,   270,   270,    44,    68,     3,    47,    71,    49,
      50,    51,     3,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    67,    76,    69,    67,   294,   295,
      68,    76,    72,    71,    74,    75,    10,    11,    78,    79,
      80,     3,     4,    67,     6,    68,     8,     9,    71,     3,
      68,     3,     4,    71,     6,    67,     8,     9,    67,   115,
      69,   117,    72,    71,    72,    70,    71,    29,    71,    72,
     130,   131,    34,    35,    36,    37,    38,    39,    40,    41,
     132,   133,    44,   138,   139,    47,    67,    49,    50,    51,
      67,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    72,     3,     4,    67,     6,    68,     8,     9,
      72,    63,    74,    75,    70,    67,    78,    79,    80,    68,
      54,    76,    72,    70,    67,    73,    78,    79,    80,    52,
      72,    16,    96,    40,   140,     3,     4,   166,     6,   141,
       8,     9,   142,   144,   143,    44,   105,    93,    -1,    49,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,     3,     4,    67,     6,    -1,
       8,     9,    72,    -1,    74,    75,    -1,    -1,    78,    79,
      80,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,     3,     4,    67,
       6,    -1,     8,     9,    72,    -1,    74,    75,    -1,    -1,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      78,    79,    80,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,     3,
       4,    67,     6,    -1,     8,     9,    72,    -1,    74,    -1,
      -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,     3,
       4,    -1,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     3,     4,    47,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      -1,     3,     4,    67,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    61,    62,    63,
      -1,    -1,    -1,    67,     3,     4,    70,     6,    -1,     8,
       9,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    67,     3,     4,    70,     6,
      -1,     8,     9,    -1,    -1,    -1,    78,    79,    80,    61,
      62,    63,    -1,    -1,    -1,    67,    68,     3,     4,    -1,
       6,    -1,     8,     9,    -1,    -1,    78,    79,    80,    -1,
      -1,    -1,    61,    62,    63,    -1,    -1,    -1,    67,     3,
       4,    -1,     6,    72,     8,     9,    -1,    -1,    -1,    78,
      79,    80,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,
      67,     3,     4,    70,     6,    -1,     8,     9,    -1,    -1,
      -1,    78,    79,    80,    -1,    61,    62,    63,    -1,    -1,
      -1,    67,     3,     4,    -1,     6,    72,     8,     9,    -1,
      -1,    -1,    78,    79,    80,    -1,    -1,    61,    62,    63,
      -1,    -1,    -1,    67,    68,     3,     4,    -1,     6,    -1,
       8,     9,    -1,    -1,    78,    79,    80,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    -1,
      61,    62,    63,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    -1,    78,    79,    80,
      -1,    -1,    -1,    61,    62,    63,     3,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      78,    79,    80,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    29,    44,    -1,    -1,    47,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,     3,    44,    -1,    -1,
      47,    -1,    63,    -1,    -1,    -1,    67,    68,    69,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    68,    29,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    29,    44,    -1,    -1,
      47,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    44,    -1,    -1,    47,    -1,    63,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    29,    -1,    67,    68,    69,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    44,    -1,    -1,
      47,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    29,    34,    35,    36,    37,    38,    39,    40,
      41,    44,    47,    63,    67,    88,    89,    90,    91,    92,
      93,    97,    98,   133,   135,   139,    98,     3,    74,    42,
      43,   138,   139,   140,    92,     0,    90,    67,    69,    72,
      92,    99,    98,    93,    74,     3,   136,   137,   138,   139,
      68,     3,    68,    94,    95,    98,   141,     3,     4,     6,
       8,     9,    61,    62,    63,    67,    70,    78,    79,    80,
      96,   113,   114,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    73,    74,   104,
      72,   136,    73,    71,    75,    68,    71,    67,    69,    92,
     102,   103,   139,    68,    71,    67,   116,    67,   116,   116,
     116,   116,   129,   130,   132,   133,   134,   138,   142,    70,
       7,     8,     9,    67,    69,    77,   118,    63,    64,    81,
      61,    62,    10,    11,    12,    13,    82,    83,    14,    15,
      78,    84,    85,    16,    17,    86,    74,   100,   130,     3,
      49,    50,    51,    53,    54,    55,    56,    57,    58,    59,
      60,    72,    75,    97,    98,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   132,    75,    96,   137,    95,    68,
      94,   102,    70,    96,    67,    69,   103,     3,   142,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    73,
     131,    68,    71,   134,    67,   102,   139,   134,    68,     3,
      68,   115,   130,   132,     3,   118,   118,   118,   119,   119,
     120,   120,   121,   121,   121,   121,   122,   122,   123,   124,
     125,   126,   127,   132,   100,   101,    76,    96,    76,    67,
      67,    67,   107,    67,     3,    72,    72,    72,   132,    92,
      75,    97,   106,    75,   107,    72,    68,    68,    70,    68,
      94,    70,    96,    68,   130,   130,   118,    68,    71,    70,
      76,    71,    75,   107,    76,   107,   132,   132,   132,    54,
     109,    72,    72,    75,    68,    70,   130,   129,    75,   100,
     107,    68,    68,    68,    67,   109,   107,   107,   107,   132,
      68,   132,    52,    68,   107,    68,   107,    72,   107
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      95,    95,    95,    96,    97,    97,    98,    98,    98,    98,
      99,    99,   100,   100,   100,   101,   101,   102,   102,   102,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   104,
     104,   104,   104,   105,   105,   106,   106,   107,   107,   107,
     107,   107,   107,   108,   108,   108,   109,   109,   110,   110,
     110,   111,   111,   111,   111,   112,   112,   112,   112,   112,
     113,   113,   113,   114,   114,   114,   114,   114,   114,   114,
     114,   115,   115,   116,   116,   116,   116,   116,   116,   116,
     117,   117,   117,   117,   117,   117,   118,   118,   119,   119,
     119,   119,   120,   120,   120,   121,   121,   121,   122,   122,
     122,   122,   122,   123,   123,   123,   124,   124,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   132,   132,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   134,   134,   134,   134,   135,   135,   135,
     136,   136,   137,   137,   138,   138,   139,   139,   139,   139,
     140,   140,   141,   141,   142,   142
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     2,
       1,     1,     3,     4,     3,     4,     4,     3,     1,     3,
       2,     2,     1,     1,     2,     3,     1,     2,     1,     2,
       1,     3,     1,     3,     4,     1,     3,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     2,
       3,     3,     4,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     1,     2,     5,     7,
       5,     5,     7,     6,     7,     3,     2,     2,     2,     3,
       1,     1,     3,     1,     4,     3,     4,     3,     3,     2,
       2,     1,     3,     1,     2,     2,     2,     2,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     4,     5,     2,
       1,     3,     1,     3,     1,     1,     1,     2,     2,     3,
       1,     2,     1,     3,     1,     2
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
#line 83 "src/parser.y"
                                        { g_root = new Root((yyvsp[0].expressionList)); /*external_declaration*/ }
#line 1752 "src/parser.tab.cpp"
    break;

  case 3:
#line 86 "src/parser.y"
                                                                        { (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 1758 "src/parser.tab.cpp"
    break;

  case 4:
#line 87 "src/parser.y"
                                                        { appendToExprList((yyvsp[-1].expressionList), (yyvsp[0].expr)); }
#line 1764 "src/parser.tab.cpp"
    break;

  case 5:
#line 91 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1770 "src/parser.tab.cpp"
    break;

  case 6:
#line 92 "src/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1776 "src/parser.tab.cpp"
    break;

  case 7:
#line 96 "src/parser.y"
                                                               { (yyval.expr) = new Full_Function(new Function_Definition(*(yyvsp[-2].string), (yyvsp[-1].expr)), (yyvsp[0].expressionList)); }
#line 1782 "src/parser.tab.cpp"
    break;

  case 10:
#line 102 "src/parser.y"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1788 "src/parser.tab.cpp"
    break;

  case 11:
#line 106 "src/parser.y"
                                                                                                { (yyval.expr) = new Declarator(*(yyvsp[0].string));}
#line 1794 "src/parser.tab.cpp"
    break;

  case 12:
#line 107 "src/parser.y"
                                                                                        { (yyval.expr) = (yyvsp[-1].expr); }
#line 1800 "src/parser.tab.cpp"
    break;

  case 13:
#line 108 "src/parser.y"
                                                                { (yyval.expr) = new ArrayDeclarator((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1806 "src/parser.tab.cpp"
    break;

  case 14:
#line 109 "src/parser.y"
                                                                                        { (yyval.expr) = new ArrayDeclarator((yyvsp[-2].expr)); }
#line 1812 "src/parser.tab.cpp"
    break;

  case 15:
#line 110 "src/parser.y"
                                                                        { (yyval.expr) = new FunctionDeclarator((yyvsp[-3].expr), ((yyvsp[-1].expressionList)));}
#line 1818 "src/parser.tab.cpp"
    break;

  case 16:
#line 111 "src/parser.y"
                                                                        { (yyval.expr) = new FunctionDeclarator((yyvsp[-3].expr), ((yyvsp[-1].expressionList)));}
#line 1824 "src/parser.tab.cpp"
    break;

  case 17:
#line 112 "src/parser.y"
                                                                                        { (yyval.expr) = new FunctionDeclarator((yyvsp[-2].expr));}
#line 1830 "src/parser.tab.cpp"
    break;

  case 18:
#line 117 "src/parser.y"
                                                                        {  (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 1836 "src/parser.tab.cpp"
    break;

  case 19:
#line 118 "src/parser.y"
                                                        { appendToExprList((yyvsp[-2].expressionList), (yyvsp[0].expr)); }
#line 1842 "src/parser.tab.cpp"
    break;

  case 20:
#line 122 "src/parser.y"
                                                                        { (yyval.expr) = new Declare(*(yyvsp[-1].string), (yyvsp[0].expr));}
#line 1848 "src/parser.tab.cpp"
    break;

  case 21:
#line 123 "src/parser.y"
                                                        { (yyval.expr) = new Declare(*(yyvsp[-1].string), (yyvsp[0].expr));}
#line 1854 "src/parser.tab.cpp"
    break;

  case 23:
#line 128 "src/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1860 "src/parser.tab.cpp"
    break;

  case 24:
#line 133 "src/parser.y"
                                                                                { ; }
#line 1866 "src/parser.tab.cpp"
    break;

  case 25:
#line 134 "src/parser.y"
                                                        { (yyval.expr) = new Declare(*(yyvsp[-2].string), (yyvsp[-1].expr));}
#line 1872 "src/parser.tab.cpp"
    break;

  case 26:
#line 139 "src/parser.y"
                                                                                                { (yyval.string) == (yyvsp[0].string); }
#line 1878 "src/parser.tab.cpp"
    break;

  case 30:
#line 148 "src/parser.y"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1884 "src/parser.tab.cpp"
    break;

  case 31:
#line 149 "src/parser.y"
                                                { (yyval.expr) = new InitDeclarator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1890 "src/parser.tab.cpp"
    break;

  case 32:
#line 154 "src/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1896 "src/parser.tab.cpp"
    break;

  case 33:
#line 155 "src/parser.y"
                                                { (yyval.expr) = new ArrayInit((yyvsp[-1].expressionList)); }
#line 1902 "src/parser.tab.cpp"
    break;

  case 34:
#line 156 "src/parser.y"
                                        { (yyval.expr) = new ArrayInit((yyvsp[-2].expressionList)); }
#line 1908 "src/parser.tab.cpp"
    break;

  case 35:
#line 160 "src/parser.y"
                                                                {  (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 1914 "src/parser.tab.cpp"
    break;

  case 36:
#line 161 "src/parser.y"
                                                { appendToExprList((yyvsp[-2].expressionList), (yyvsp[0].expr)); }
#line 1920 "src/parser.tab.cpp"
    break;

  case 38:
#line 166 "src/parser.y"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1926 "src/parser.tab.cpp"
    break;

  case 40:
#line 171 "src/parser.y"
                                                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 1932 "src/parser.tab.cpp"
    break;

  case 41:
#line 172 "src/parser.y"
                                                                                                                        { ; }
#line 1938 "src/parser.tab.cpp"
    break;

  case 42:
#line 173 "src/parser.y"
                                                                                                { ; }
#line 1944 "src/parser.tab.cpp"
    break;

  case 43:
#line 174 "src/parser.y"
                                                                                        { (yyval.expr) = new ArrayDeclarator((yyvsp[-2].expr)); }
#line 1950 "src/parser.tab.cpp"
    break;

  case 44:
#line 175 "src/parser.y"
                                                                        { (yyval.expr) = new ArrayDeclarator((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1956 "src/parser.tab.cpp"
    break;

  case 45:
#line 176 "src/parser.y"
                                                                                                                        { ; }
#line 1962 "src/parser.tab.cpp"
    break;

  case 46:
#line 177 "src/parser.y"
                                                                                                        { ; }
#line 1968 "src/parser.tab.cpp"
    break;

  case 47:
#line 178 "src/parser.y"
                                                                                        { ; }
#line 1974 "src/parser.tab.cpp"
    break;

  case 48:
#line 179 "src/parser.y"
                                                                                { ; }
#line 1980 "src/parser.tab.cpp"
    break;

  case 49:
#line 184 "src/parser.y"
                                                                                                { (yyval.expressionList) = new ExpressionList();}
#line 1986 "src/parser.tab.cpp"
    break;

  case 50:
#line 185 "src/parser.y"
                                                                                { (yyval.expressionList) = new ExpressionList((yyvsp[-1].expressionList)); }
#line 1992 "src/parser.tab.cpp"
    break;

  case 51:
#line 186 "src/parser.y"
                                                                                { (yyval.expressionList) = new ExpressionList((yyvsp[-1].expressionList)); }
#line 1998 "src/parser.tab.cpp"
    break;

  case 52:
#line 188 "src/parser.y"
                                                                { (yyval.expressionList) = new ExpressionList(); appendToExprList((yyval.expressionList), (yyvsp[-2].expressionList)); appendToExprList((yyval.expressionList), (yyvsp[-1].expressionList)); }
#line 2004 "src/parser.tab.cpp"
    break;

  case 53:
#line 195 "src/parser.y"
                                                        { (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 2010 "src/parser.tab.cpp"
    break;

  case 54:
#line 196 "src/parser.y"
                                        { appendToExprList((yyvsp[-1].expressionList), (yyvsp[0].expr)); }
#line 2016 "src/parser.tab.cpp"
    break;

  case 55:
#line 201 "src/parser.y"
                                                        {  (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 2022 "src/parser.tab.cpp"
    break;

  case 56:
#line 202 "src/parser.y"
                                        { appendToExprList((yyvsp[-1].expressionList), (yyvsp[0].expr)); }
#line 2028 "src/parser.tab.cpp"
    break;

  case 57:
#line 206 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2034 "src/parser.tab.cpp"
    break;

  case 58:
#line 207 "src/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2040 "src/parser.tab.cpp"
    break;

  case 59:
#line 208 "src/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2046 "src/parser.tab.cpp"
    break;

  case 60:
#line 209 "src/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2052 "src/parser.tab.cpp"
    break;

  case 61:
#line 210 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2058 "src/parser.tab.cpp"
    break;

  case 62:
#line 211 "src/parser.y"
                                { (yyval.expr) = (yyvsp[0].expressionList); }
#line 2064 "src/parser.tab.cpp"
    break;

  case 66:
#line 222 "src/parser.y"
                                        { (yyval.expr) = new EmptyExpr(); }
#line 2070 "src/parser.tab.cpp"
    break;

  case 67:
#line 223 "src/parser.y"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 2076 "src/parser.tab.cpp"
    break;

  case 68:
#line 227 "src/parser.y"
                                                                { (yyval.expr) = new If((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2082 "src/parser.tab.cpp"
    break;

  case 69:
#line 228 "src/parser.y"
                                                                { (yyval.expr) = new IfElse((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); /* dangling else problem */ }
#line 2088 "src/parser.tab.cpp"
    break;

  case 70:
#line 229 "src/parser.y"
                                                                        { (yyval.expr) = new SwitchCase((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2094 "src/parser.tab.cpp"
    break;

  case 71:
#line 233 "src/parser.y"
                                                                                                                                { (yyval.expr) = new WhileLoop((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2100 "src/parser.tab.cpp"
    break;

  case 73:
#line 235 "src/parser.y"
                                                                                                        { (yyval.expr) = new ForLoop((yyvsp[-3].expr), (yyvsp[-2].expr), new EmptyExpr(), (yyvsp[0].expr)); }
#line 2106 "src/parser.tab.cpp"
    break;

  case 74:
#line 236 "src/parser.y"
                                                                                        { (yyval.expr) = new ForLoop((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); /* interior initialisation eg. int x=0, breakes the parser*/ }
#line 2112 "src/parser.tab.cpp"
    break;

  case 78:
#line 243 "src/parser.y"
                                        { (yyval.expr) = new Return(new Integer()); }
#line 2118 "src/parser.tab.cpp"
    break;

  case 79:
#line 244 "src/parser.y"
                                { (yyval.expr) = new Return((yyvsp[-1].expr)); }
#line 2124 "src/parser.tab.cpp"
    break;

  case 80:
#line 250 "src/parser.y"
                                        { (yyval.expr) = new Variable( *(yyvsp[0].string) );}
#line 2130 "src/parser.tab.cpp"
    break;

  case 81:
#line 251 "src/parser.y"
                                        { (yyval.expr) = new Integer( (yyvsp[0].integer) );}
#line 2136 "src/parser.tab.cpp"
    break;

  case 82:
#line 254 "src/parser.y"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 2142 "src/parser.tab.cpp"
    break;

  case 83:
#line 258 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2148 "src/parser.tab.cpp"
    break;

  case 84:
#line 259 "src/parser.y"
                                                                                { (yyval.expr) = new ArrayCall((yyvsp[-3].expr), (yyvsp[-1].expr));}
#line 2154 "src/parser.tab.cpp"
    break;

  case 85:
#line 260 "src/parser.y"
                                                                                        { (yyval.expr) = new FunctionCall((yyvsp[-2].expr));}
#line 2160 "src/parser.tab.cpp"
    break;

  case 86:
#line 261 "src/parser.y"
                                                                { (yyval.expr) = new FunctionCall((yyvsp[-3].expr), (yyvsp[-1].expressionList));}
#line 2166 "src/parser.tab.cpp"
    break;

  case 89:
#line 264 "src/parser.y"
                                                                                        { (yyval.expr) = new PostIncrementOperator((yyvsp[-1].expr));}
#line 2172 "src/parser.tab.cpp"
    break;

  case 90:
#line 265 "src/parser.y"
                                                                                        { (yyval.expr) = new PostDecrementOperator((yyvsp[-1].expr));}
#line 2178 "src/parser.tab.cpp"
    break;

  case 91:
#line 269 "src/parser.y"
                                                                                                { (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 2184 "src/parser.tab.cpp"
    break;

  case 92:
#line 270 "src/parser.y"
                                                                { appendToExprList((yyvsp[-2].expressionList), (yyvsp[0].expr)); }
#line 2190 "src/parser.tab.cpp"
    break;

  case 93:
#line 274 "src/parser.y"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2196 "src/parser.tab.cpp"
    break;

  case 94:
#line 275 "src/parser.y"
                                                { (yyval.expr) = new PreIncrementOperator((yyvsp[0].expr));}
#line 2202 "src/parser.tab.cpp"
    break;

  case 95:
#line 276 "src/parser.y"
                                                { (yyval.expr) = new PreDecrementOperator((yyvsp[0].expr));}
#line 2208 "src/parser.tab.cpp"
    break;

  case 96:
#line 277 "src/parser.y"
                                                { /* HOW */ }
#line 2214 "src/parser.tab.cpp"
    break;

  case 97:
#line 278 "src/parser.y"
                                                        { (yyval.expr) = new NegOperator((yyvsp[0].expr)); }
#line 2220 "src/parser.tab.cpp"
    break;

  case 100:
#line 284 "src/parser.y"
                        { /* pointer address */ }
#line 2226 "src/parser.tab.cpp"
    break;

  case 101:
#line 285 "src/parser.y"
                        { /* pointer value */ }
#line 2232 "src/parser.tab.cpp"
    break;

  case 102:
#line 286 "src/parser.y"
                        { /* same as $2 */ }
#line 2238 "src/parser.tab.cpp"
    break;

  case 103:
#line 287 "src/parser.y"
                        { /* neg */ }
#line 2244 "src/parser.tab.cpp"
    break;

  case 105:
#line 289 "src/parser.y"
                        { /* logic NOT */ }
#line 2250 "src/parser.tab.cpp"
    break;

  case 106:
#line 293 "src/parser.y"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2256 "src/parser.tab.cpp"
    break;

  case 108:
#line 298 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2262 "src/parser.tab.cpp"
    break;

  case 109:
#line 299 "src/parser.y"
                                                                { (yyval.expr) = new MulOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2268 "src/parser.tab.cpp"
    break;

  case 110:
#line 300 "src/parser.y"
                                                                { (yyval.expr) = new DivOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2274 "src/parser.tab.cpp"
    break;

  case 111:
#line 301 "src/parser.y"
                                                                { (yyval.expr) = new ModOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2280 "src/parser.tab.cpp"
    break;

  case 112:
#line 305 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2286 "src/parser.tab.cpp"
    break;

  case 113:
#line 306 "src/parser.y"
                                                                        { (yyval.expr) = new AddOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2292 "src/parser.tab.cpp"
    break;

  case 114:
#line 307 "src/parser.y"
                                                                        { (yyval.expr) = new SubOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2298 "src/parser.tab.cpp"
    break;

  case 115:
#line 311 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2304 "src/parser.tab.cpp"
    break;

  case 116:
#line 312 "src/parser.y"
                                                                        { (yyval.expr) = new LeftShiftOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2310 "src/parser.tab.cpp"
    break;

  case 117:
#line 313 "src/parser.y"
                                                                { (yyval.expr) = new RightShiftOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2316 "src/parser.tab.cpp"
    break;

  case 118:
#line 317 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2322 "src/parser.tab.cpp"
    break;

  case 119:
#line 318 "src/parser.y"
                                                                { (yyval.expr) = new SmallerOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2328 "src/parser.tab.cpp"
    break;

  case 120:
#line 319 "src/parser.y"
                                                                { (yyval.expr) = new GreaterOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2334 "src/parser.tab.cpp"
    break;

  case 121:
#line 320 "src/parser.y"
                                                                { (yyval.expr) = new LEOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2340 "src/parser.tab.cpp"
    break;

  case 122:
#line 321 "src/parser.y"
                                                                { (yyval.expr) = new GEOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2346 "src/parser.tab.cpp"
    break;

  case 123:
#line 325 "src/parser.y"
                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2352 "src/parser.tab.cpp"
    break;

  case 124:
#line 326 "src/parser.y"
                                                                { (yyval.expr) = new EQOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2358 "src/parser.tab.cpp"
    break;

  case 125:
#line 327 "src/parser.y"
                                                                { (yyval.expr) = new NEOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2364 "src/parser.tab.cpp"
    break;

  case 126:
#line 331 "src/parser.y"
                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2370 "src/parser.tab.cpp"
    break;

  case 127:
#line 332 "src/parser.y"
                                                        { (yyval.expr) = new ANDOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2376 "src/parser.tab.cpp"
    break;

  case 128:
#line 336 "src/parser.y"
                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2382 "src/parser.tab.cpp"
    break;

  case 129:
#line 337 "src/parser.y"
                                                        { (yyval.expr) = new XOROperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2388 "src/parser.tab.cpp"
    break;

  case 130:
#line 341 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2394 "src/parser.tab.cpp"
    break;

  case 131:
#line 342 "src/parser.y"
                                                                { (yyval.expr) = new OROperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2400 "src/parser.tab.cpp"
    break;

  case 132:
#line 346 "src/parser.y"
                                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2406 "src/parser.tab.cpp"
    break;

  case 133:
#line 347 "src/parser.y"
                                                                        { (yyval.expr) = new LogicalANDOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2412 "src/parser.tab.cpp"
    break;

  case 134:
#line 351 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 2418 "src/parser.tab.cpp"
    break;

  case 135:
#line 352 "src/parser.y"
                                                                { (yyval.expr) = new LogicalOROperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2424 "src/parser.tab.cpp"
    break;

  case 136:
#line 356 "src/parser.y"
                                                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2430 "src/parser.tab.cpp"
    break;

  case 138:
#line 361 "src/parser.y"
                                     { (yyval.expr) = (yyvsp[0].expr); }
#line 2436 "src/parser.tab.cpp"
    break;

  case 139:
#line 362 "src/parser.y"
                                                                        { (yyval.expr) = new AssignOperator((yyvsp[-2].expr), *(yyvsp[-1].string), (yyvsp[0].expr));  }
#line 2442 "src/parser.tab.cpp"
    break;

  case 140:
#line 366 "src/parser.y"
                             { (yyval.string) = new std::string("="); }
#line 2448 "src/parser.tab.cpp"
    break;

  case 141:
#line 367 "src/parser.y"
                             { (yyval.string) = new std::string("*="); }
#line 2454 "src/parser.tab.cpp"
    break;

  case 142:
#line 368 "src/parser.y"
                             { (yyval.string) = new std::string("/="); }
#line 2460 "src/parser.tab.cpp"
    break;

  case 143:
#line 369 "src/parser.y"
                             { (yyval.string) = new std::string("%="); }
#line 2466 "src/parser.tab.cpp"
    break;

  case 144:
#line 370 "src/parser.y"
                             { (yyval.string) = new std::string("+="); }
#line 2472 "src/parser.tab.cpp"
    break;

  case 145:
#line 371 "src/parser.y"
                             { (yyval.string) = new std::string("-="); }
#line 2478 "src/parser.tab.cpp"
    break;

  case 146:
#line 372 "src/parser.y"
                             { (yyval.string) = new std::string("<<="); }
#line 2484 "src/parser.tab.cpp"
    break;

  case 147:
#line 373 "src/parser.y"
                             { (yyval.string) = new std::string(">>="); }
#line 2490 "src/parser.tab.cpp"
    break;

  case 148:
#line 374 "src/parser.y"
                             { (yyval.string) = new std::string("&="); }
#line 2496 "src/parser.tab.cpp"
    break;

  case 149:
#line 375 "src/parser.y"
                             { (yyval.string) = new std::string("^="); }
#line 2502 "src/parser.tab.cpp"
    break;

  case 150:
#line 376 "src/parser.y"
                             { (yyval.string) = new std::string("|="); }
#line 2508 "src/parser.tab.cpp"
    break;

  case 151:
#line 380 "src/parser.y"
                                                                        {(yyval.expr) = (yyvsp[0].expr); /*{ $$ = initExprList($1); }*/}
#line 2514 "src/parser.tab.cpp"
    break;

  case 152:
#line 381 "src/parser.y"
                                                        { /* appendToExprList($1, $2); */ }
#line 2520 "src/parser.tab.cpp"
    break;

  case 153:
#line 389 "src/parser.y"
                                { (yyval.string) = new std::string("void"); }
#line 2526 "src/parser.tab.cpp"
    break;

  case 156:
#line 392 "src/parser.y"
                                { (yyval.string) = new std::string("int"); }
#line 2532 "src/parser.tab.cpp"
    break;


#line 2536 "src/parser.tab.cpp"

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
#line 491 "src/parser.y"


const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
