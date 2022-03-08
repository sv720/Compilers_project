/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

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

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INT_LITERAL = 4,                /* INT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_SIZEOF = 6,                     /* SIZEOF  */
  YYSYMBOL_POINTER_OP = 7,                 /* POINTER_OP  */
  YYSYMBOL_INCREMENT_OP = 8,               /* INCREMENT_OP  */
  YYSYMBOL_DECREMENT_OP = 9,               /* DECREMENT_OP  */
  YYSYMBOL_LEFTSHIFT_OP = 10,              /* LEFTSHIFT_OP  */
  YYSYMBOL_RIGHTSHIFT_OP = 11,             /* RIGHTSHIFT_OP  */
  YYSYMBOL_LE_OP = 12,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 13,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 14,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 15,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 16,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 17,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 18,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 19,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 20,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 21,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 22,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFTSHIFT_ASSIGN = 23,          /* LEFTSHIFT_ASSIGN  */
  YYSYMBOL_RIGHTSHIFT_ASSIGN = 24,         /* RIGHTSHIFT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 25,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 26,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 27,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPE_NAME = 28,                 /* TYPE_NAME  */
  YYSYMBOL_TYPEDEF = 29,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 30,                    /* EXTERN  */
  YYSYMBOL_STATIC = 31,                    /* STATIC  */
  YYSYMBOL_AUTO = 32,                      /* AUTO  */
  YYSYMBOL_REGISTER = 33,                  /* REGISTER  */
  YYSYMBOL_CHAR = 34,                      /* CHAR  */
  YYSYMBOL_SHORT = 35,                     /* SHORT  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_LONG = 37,                      /* LONG  */
  YYSYMBOL_SIGNED = 38,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 39,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 40,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 41,                    /* DOUBLE  */
  YYSYMBOL_CONST = 42,                     /* CONST  */
  YYSYMBOL_VOLATILE = 43,                  /* VOLATILE  */
  YYSYMBOL_VOID = 44,                      /* VOID  */
  YYSYMBOL_STRUCT = 45,                    /* STRUCT  */
  YYSYMBOL_UNION = 46,                     /* UNION  */
  YYSYMBOL_ENUM = 47,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 48,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 49,                      /* CASE  */
  YYSYMBOL_DEFAULT = 50,                   /* DEFAULT  */
  YYSYMBOL_IF = 51,                        /* IF  */
  YYSYMBOL_ELSE = 52,                      /* ELSE  */
  YYSYMBOL_SWITCH = 53,                    /* SWITCH  */
  YYSYMBOL_WHILE = 54,                     /* WHILE  */
  YYSYMBOL_DO = 55,                        /* DO  */
  YYSYMBOL_FOR = 56,                       /* FOR  */
  YYSYMBOL_GOTO = 57,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 58,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 59,                     /* BREAK  */
  YYSYMBOL_RETURN = 60,                    /* RETURN  */
  YYSYMBOL_61_ = 61,                       /* '('  */
  YYSYMBOL_62_ = 62,                       /* ')'  */
  YYSYMBOL_63_ = 63,                       /* '['  */
  YYSYMBOL_64_ = 64,                       /* ']'  */
  YYSYMBOL_65_ = 65,                       /* ','  */
  YYSYMBOL_66_ = 66,                       /* ';'  */
  YYSYMBOL_67_ = 67,                       /* '='  */
  YYSYMBOL_68_ = 68,                       /* '{'  */
  YYSYMBOL_69_ = 69,                       /* '}'  */
  YYSYMBOL_70_ = 70,                       /* ':'  */
  YYSYMBOL_71_ = 71,                       /* '.'  */
  YYSYMBOL_72_ = 72,                       /* '-'  */
  YYSYMBOL_73_ = 73,                       /* '&'  */
  YYSYMBOL_74_ = 74,                       /* '*'  */
  YYSYMBOL_75_ = 75,                       /* '+'  */
  YYSYMBOL_76_ = 76,                       /* '~'  */
  YYSYMBOL_77_ = 77,                       /* '!'  */
  YYSYMBOL_78_ = 78,                       /* '/'  */
  YYSYMBOL_79_ = 79,                       /* '%'  */
  YYSYMBOL_80_ = 80,                       /* '<'  */
  YYSYMBOL_81_ = 81,                       /* '>'  */
  YYSYMBOL_82_ = 82,                       /* '^'  */
  YYSYMBOL_83_ = 83,                       /* '|'  */
  YYSYMBOL_84_ = 84,                       /* '?'  */
  YYSYMBOL_YYACCEPT = 85,                  /* $accept  */
  YYSYMBOL_ROOT = 86,                      /* ROOT  */
  YYSYMBOL_external_declaration = 87,      /* external_declaration  */
  YYSYMBOL_function_definition = 88,       /* function_definition  */
  YYSYMBOL_declarator = 89,                /* declarator  */
  YYSYMBOL_direct_declarator = 90,         /* direct_declarator  */
  YYSYMBOL_parameter_list = 91,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 92,     /* parameter_declaration  */
  YYSYMBOL_declaration = 93,               /* declaration  */
  YYSYMBOL_declaration_specifiers = 94,    /* declaration_specifiers  */
  YYSYMBOL_init_declarator = 95,           /* init_declarator  */
  YYSYMBOL_initializer = 96,               /* initializer  */
  YYSYMBOL_initializer_list = 97,          /* initializer_list  */
  YYSYMBOL_abstract_declarator = 98,       /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 99, /* direct_abstract_declarator  */
  YYSYMBOL_compound_statement = 100,       /* compound_statement  */
  YYSYMBOL_declaration_list = 101,         /* declaration_list  */
  YYSYMBOL_statement_list = 102,           /* statement_list  */
  YYSYMBOL_statement = 103,                /* statement  */
  YYSYMBOL_labeled_statement = 104,        /* labeled_statement  */
  YYSYMBOL_expression_statement = 105,     /* expression_statement  */
  YYSYMBOL_selection_statement = 106,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 107,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 108,           /* jump_statement  */
  YYSYMBOL_primary_expression = 109,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 110,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 111, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 112,         /* unary_expression  */
  YYSYMBOL_unary_operator = 113,           /* unary_operator  */
  YYSYMBOL_cast_expression = 114,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 115, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 116,      /* additive_expression  */
  YYSYMBOL_shift_expression = 117,         /* shift_expression  */
  YYSYMBOL_relational_expression = 118,    /* relational_expression  */
  YYSYMBOL_equality_expression = 119,      /* equality_expression  */
  YYSYMBOL_and_expression = 120,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 121,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 122,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 123,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 124,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 125,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 126,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 127,      /* assignment_operator  */
  YYSYMBOL_expression = 128,               /* expression  */
  YYSYMBOL_constant_expression = 129,      /* constant_expression  */
  YYSYMBOL_type_specifier = 130,           /* type_specifier  */
  YYSYMBOL_specifier_qualifier_list = 131, /* specifier_qualifier_list  */
  YYSYMBOL_enum_specifier = 132,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 133,          /* enumerator_list  */
  YYSYMBOL_enumerator = 134,               /* enumerator  */
  YYSYMBOL_type_qualifier = 135,           /* type_qualifier  */
  YYSYMBOL_pointer = 136,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 137,      /* type_qualifier_list  */
  YYSYMBOL_identifier_list = 138,          /* identifier_list  */
  YYSYMBOL_type_name = 139                 /* type_name  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INT_LITERAL", "STRING_LITERAL", "SIZEOF", "POINTER_OP", "INCREMENT_OP",
  "DECREMENT_OP", "LEFTSHIFT_OP", "RIGHTSHIFT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFTSHIFT_ASSIGN",
  "RIGHTSHIFT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['", "']'", "','", "';'",
  "'='", "'{'", "'}'", "':'", "'.'", "'-'", "'&'", "'*'", "'+'", "'~'",
  "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "$accept",
  "ROOT", "external_declaration", "function_definition", "declarator",
  "direct_declarator", "parameter_list", "parameter_declaration",
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
  "expression", "constant_expression", "type_specifier",
  "specifier_qualifier_list", "enum_specifier", "enumerator_list",
  "enumerator", "type_qualifier", "pointer", "type_qualifier_list",
  "identifier_list", "type_name", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
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
#endif

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
static const yytype_uint8 yydefgoto[] =
{
       0,    15,    16,    17,    28,    19,   177,    52,    20,    53,
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* ROOT: external_declaration  */
#line 75 "src/parser.y"
                                                { g_root = (yyvsp[0].expr); /*translation_unit*/ }
#line 1553 "src/parser.tab.cpp"
    break;

  case 3: /* external_declaration: function_definition  */
#line 83 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1559 "src/parser.tab.cpp"
    break;

  case 4: /* external_declaration: declaration  */
#line 84 "src/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1565 "src/parser.tab.cpp"
    break;

  case 5: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 88 "src/parser.y"
                                                               { (yyval.expr) = new Full_Function(new Function_Definition(*(yyvsp[-2].string), (yyvsp[-1].expr)), (yyvsp[0].expressionList)); }
#line 1571 "src/parser.tab.cpp"
    break;

  case 8: /* declarator: direct_declarator  */
#line 98 "src/parser.y"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1577 "src/parser.tab.cpp"
    break;

  case 9: /* direct_declarator: IDENTIFIER  */
#line 102 "src/parser.y"
                                                                                                { (yyval.expr) = new Declarator(*(yyvsp[0].string));}
#line 1583 "src/parser.tab.cpp"
    break;

  case 10: /* direct_declarator: '(' declarator ')'  */
#line 103 "src/parser.y"
                                                                                        { (yyval.expr) = (yyvsp[-1].expr); }
#line 1589 "src/parser.tab.cpp"
    break;

  case 11: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 104 "src/parser.y"
                                                                { ;}
#line 1595 "src/parser.tab.cpp"
    break;

  case 12: /* direct_declarator: direct_declarator '(' parameter_list ')'  */
#line 105 "src/parser.y"
                                                                        { ;}
#line 1601 "src/parser.tab.cpp"
    break;

  case 13: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 106 "src/parser.y"
                                                                        { ;}
#line 1607 "src/parser.tab.cpp"
    break;

  case 14: /* direct_declarator: direct_declarator '(' ')'  */
#line 107 "src/parser.y"
                                                                                        { (yyval.expr) = new FunctionDeclarator((yyvsp[-2].expr));;}
#line 1613 "src/parser.tab.cpp"
    break;

  case 15: /* parameter_list: parameter_declaration  */
#line 112 "src/parser.y"
                                                                        {  (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 1619 "src/parser.tab.cpp"
    break;

  case 16: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 113 "src/parser.y"
                                                        { appendToExprList((yyvsp[-2].expressionList), (yyvsp[0].expr)); }
#line 1625 "src/parser.tab.cpp"
    break;

  case 17: /* parameter_declaration: declaration_specifiers declarator  */
#line 117 "src/parser.y"
                                                                        { (yyval.expr) = new Declare(*(yyvsp[-1].string), (yyvsp[0].expr));}
#line 1631 "src/parser.tab.cpp"
    break;

  case 18: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 118 "src/parser.y"
                                                        { (yyval.expr) = new Declare(*(yyvsp[-1].string), (yyvsp[0].expr));}
#line 1637 "src/parser.tab.cpp"
    break;

  case 20: /* declaration: declaration_specifiers ';'  */
#line 124 "src/parser.y"
                                                                                { ; }
#line 1643 "src/parser.tab.cpp"
    break;

  case 21: /* declaration: declaration_specifiers init_declarator ';'  */
#line 125 "src/parser.y"
                                                        { (yyval.expr) = new Declare(*(yyvsp[-2].string), (yyvsp[-1].expr));}
#line 1649 "src/parser.tab.cpp"
    break;

  case 22: /* declaration_specifiers: type_specifier  */
#line 130 "src/parser.y"
                                                                                                { (yyval.string) == (yyvsp[0].string); }
#line 1655 "src/parser.tab.cpp"
    break;

  case 26: /* init_declarator: declarator  */
#line 139 "src/parser.y"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1661 "src/parser.tab.cpp"
    break;

  case 27: /* init_declarator: declarator '=' initializer  */
#line 140 "src/parser.y"
                                                { (yyval.expr) = new InitDeclarator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1667 "src/parser.tab.cpp"
    break;

  case 28: /* initializer: assignment_expression  */
#line 145 "src/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1673 "src/parser.tab.cpp"
    break;

  case 29: /* initializer: '{' initializer_list '}'  */
#line 146 "src/parser.y"
                                                { ; /*list to expr, need a class for creating an exprPtr to list */}
#line 1679 "src/parser.tab.cpp"
    break;

  case 30: /* initializer: '{' initializer_list ',' '}'  */
#line 147 "src/parser.y"
                                        { ; /* same */ }
#line 1685 "src/parser.tab.cpp"
    break;

  case 31: /* initializer_list: initializer  */
#line 151 "src/parser.y"
                                                                {  (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 1691 "src/parser.tab.cpp"
    break;

  case 32: /* initializer_list: initializer_list ',' initializer  */
#line 152 "src/parser.y"
                                                { appendToExprList((yyvsp[-2].expressionList), (yyvsp[0].expr)); }
#line 1697 "src/parser.tab.cpp"
    break;

  case 36: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 162 "src/parser.y"
                                                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 1703 "src/parser.tab.cpp"
    break;

  case 37: /* direct_abstract_declarator: '[' ']'  */
#line 163 "src/parser.y"
                                                                                                                        { ; }
#line 1709 "src/parser.tab.cpp"
    break;

  case 38: /* direct_abstract_declarator: '[' constant_expression ']'  */
#line 164 "src/parser.y"
                                                                                                { ; }
#line 1715 "src/parser.tab.cpp"
    break;

  case 39: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 165 "src/parser.y"
                                                                                        { ; }
#line 1721 "src/parser.tab.cpp"
    break;

  case 40: /* direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'  */
#line 166 "src/parser.y"
                                                                        { ; }
#line 1727 "src/parser.tab.cpp"
    break;

  case 41: /* direct_abstract_declarator: '(' ')'  */
#line 167 "src/parser.y"
                                                                                                                        { ; }
#line 1733 "src/parser.tab.cpp"
    break;

  case 42: /* direct_abstract_declarator: '(' parameter_list ')'  */
#line 168 "src/parser.y"
                                                                                                        { ; }
#line 1739 "src/parser.tab.cpp"
    break;

  case 43: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 169 "src/parser.y"
                                                                                        { ; }
#line 1745 "src/parser.tab.cpp"
    break;

  case 44: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_list ')'  */
#line 170 "src/parser.y"
                                                                                { ; }
#line 1751 "src/parser.tab.cpp"
    break;

  case 45: /* compound_statement: '{' '}'  */
#line 175 "src/parser.y"
                                                                                                { (yyval.expressionList) = new ExpressionList();}
#line 1757 "src/parser.tab.cpp"
    break;

  case 46: /* compound_statement: '{' declaration_list '}'  */
#line 176 "src/parser.y"
                                                                                { (yyval.expressionList) = new ExpressionList((yyvsp[-1].expressionList)); }
#line 1763 "src/parser.tab.cpp"
    break;

  case 47: /* compound_statement: '{' statement_list '}'  */
#line 177 "src/parser.y"
                                                                                { (yyval.expressionList) = new ExpressionList((yyvsp[-1].expressionList)); }
#line 1769 "src/parser.tab.cpp"
    break;

  case 48: /* compound_statement: '{' declaration_list statement_list '}'  */
#line 179 "src/parser.y"
                                                                { (yyval.expressionList) = new ExpressionList(); appendToExprList((yyval.expressionList), (yyvsp[-2].expressionList)); appendToExprList((yyval.expressionList), (yyvsp[-1].expressionList)); }
#line 1775 "src/parser.tab.cpp"
    break;

  case 49: /* declaration_list: declaration  */
#line 186 "src/parser.y"
                                                        { (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 1781 "src/parser.tab.cpp"
    break;

  case 50: /* declaration_list: declaration_list declaration  */
#line 187 "src/parser.y"
                                        { appendToExprList((yyvsp[-1].expressionList), (yyvsp[0].expr)); }
#line 1787 "src/parser.tab.cpp"
    break;

  case 51: /* statement_list: statement  */
#line 192 "src/parser.y"
                                                        {  (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 1793 "src/parser.tab.cpp"
    break;

  case 52: /* statement_list: statement_list statement  */
#line 193 "src/parser.y"
                                        { appendToExprList((yyvsp[-1].expressionList), (yyvsp[0].expr)); }
#line 1799 "src/parser.tab.cpp"
    break;

  case 53: /* statement: labeled_statement  */
#line 197 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1805 "src/parser.tab.cpp"
    break;

  case 54: /* statement: expression_statement  */
#line 198 "src/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1811 "src/parser.tab.cpp"
    break;

  case 55: /* statement: selection_statement  */
#line 199 "src/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1817 "src/parser.tab.cpp"
    break;

  case 56: /* statement: iteration_statement  */
#line 200 "src/parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1823 "src/parser.tab.cpp"
    break;

  case 57: /* statement: jump_statement  */
#line 201 "src/parser.y"
                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1829 "src/parser.tab.cpp"
    break;

  case 58: /* statement: compound_statement  */
#line 202 "src/parser.y"
                                { (yyval.expr) = (yyvsp[0].expressionList); /*at the moment compound_statement is avoided so we can add its versions below*/}
#line 1835 "src/parser.tab.cpp"
    break;

  case 74: /* jump_statement: RETURN ';'  */
#line 238 "src/parser.y"
                                        { ; }
#line 1841 "src/parser.tab.cpp"
    break;

  case 75: /* jump_statement: RETURN expression ';'  */
#line 239 "src/parser.y"
                                { (yyval.expr) = new Return((yyvsp[-1].expr)); }
#line 1847 "src/parser.tab.cpp"
    break;

  case 76: /* primary_expression: IDENTIFIER  */
#line 245 "src/parser.y"
                                        { (yyval.expr) = new Variable( *(yyvsp[0].string) );}
#line 1853 "src/parser.tab.cpp"
    break;

  case 77: /* primary_expression: INT_LITERAL  */
#line 246 "src/parser.y"
                                        { (yyval.expr) = new Number( (yyvsp[0].number) );}
#line 1859 "src/parser.tab.cpp"
    break;

  case 78: /* primary_expression: '(' expression ')'  */
#line 249 "src/parser.y"
                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 1865 "src/parser.tab.cpp"
    break;

  case 79: /* postfix_expression: primary_expression  */
#line 253 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1871 "src/parser.tab.cpp"
    break;

  case 87: /* argument_expression_list: assignment_expression  */
#line 264 "src/parser.y"
                                                                                                { (yyval.expressionList) = initExprList((yyvsp[0].expr)); }
#line 1877 "src/parser.tab.cpp"
    break;

  case 88: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 265 "src/parser.y"
                                                                { appendToExprList((yyvsp[-2].expressionList), (yyvsp[0].expr)); }
#line 1883 "src/parser.tab.cpp"
    break;

  case 89: /* unary_expression: postfix_expression  */
#line 269 "src/parser.y"
                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1889 "src/parser.tab.cpp"
    break;

  case 93: /* unary_expression: '-' unary_expression  */
#line 273 "src/parser.y"
                                                        { (yyval.expr) = new NegOperator((yyvsp[0].expr)); }
#line 1895 "src/parser.tab.cpp"
    break;

  case 102: /* cast_expression: unary_expression  */
#line 288 "src/parser.y"
                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1901 "src/parser.tab.cpp"
    break;

  case 104: /* multiplicative_expression: cast_expression  */
#line 293 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1907 "src/parser.tab.cpp"
    break;

  case 105: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 294 "src/parser.y"
                                                                { (yyval.expr) = new MulOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1913 "src/parser.tab.cpp"
    break;

  case 106: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 295 "src/parser.y"
                                                                { (yyval.expr) = new DivOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1919 "src/parser.tab.cpp"
    break;

  case 107: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 296 "src/parser.y"
                                                                {;}
#line 1925 "src/parser.tab.cpp"
    break;

  case 108: /* additive_expression: multiplicative_expression  */
#line 300 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1931 "src/parser.tab.cpp"
    break;

  case 109: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 301 "src/parser.y"
                                                                        { (yyval.expr) = new AddOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1937 "src/parser.tab.cpp"
    break;

  case 110: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 302 "src/parser.y"
                                                                        { (yyval.expr) = new SubOperator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1943 "src/parser.tab.cpp"
    break;

  case 111: /* shift_expression: additive_expression  */
#line 306 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1949 "src/parser.tab.cpp"
    break;

  case 114: /* relational_expression: shift_expression  */
#line 312 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1955 "src/parser.tab.cpp"
    break;

  case 119: /* equality_expression: relational_expression  */
#line 320 "src/parser.y"
                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1961 "src/parser.tab.cpp"
    break;

  case 122: /* and_expression: equality_expression  */
#line 326 "src/parser.y"
                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1967 "src/parser.tab.cpp"
    break;

  case 124: /* exclusive_or_expression: and_expression  */
#line 331 "src/parser.y"
                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1973 "src/parser.tab.cpp"
    break;

  case 126: /* inclusive_or_expression: exclusive_or_expression  */
#line 336 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1979 "src/parser.tab.cpp"
    break;

  case 128: /* logical_and_expression: inclusive_or_expression  */
#line 341 "src/parser.y"
                                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1985 "src/parser.tab.cpp"
    break;

  case 130: /* logical_or_expression: logical_and_expression  */
#line 346 "src/parser.y"
                                                                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1991 "src/parser.tab.cpp"
    break;

  case 132: /* conditional_expression: logical_or_expression  */
#line 351 "src/parser.y"
                                                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1997 "src/parser.tab.cpp"
    break;

  case 134: /* assignment_expression: conditional_expression  */
#line 356 "src/parser.y"
                                     { (yyval.expr) = (yyvsp[0].expr); }
#line 2003 "src/parser.tab.cpp"
    break;

  case 135: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 357 "src/parser.y"
                                                                        { (yyval.expr) = new AssignOperator((yyvsp[-2].expr), *(yyvsp[-1].string), (yyvsp[0].expr));  }
#line 2009 "src/parser.tab.cpp"
    break;

  case 136: /* assignment_operator: '='  */
#line 361 "src/parser.y"
                             { (yyval.string) = new std::string("="); }
#line 2015 "src/parser.tab.cpp"
    break;

  case 137: /* assignment_operator: MUL_ASSIGN  */
#line 362 "src/parser.y"
                             { (yyval.string) = new std::string("*="); }
#line 2021 "src/parser.tab.cpp"
    break;

  case 138: /* assignment_operator: DIV_ASSIGN  */
#line 363 "src/parser.y"
                             { (yyval.string) = new std::string("/="); }
#line 2027 "src/parser.tab.cpp"
    break;

  case 139: /* assignment_operator: MOD_ASSIGN  */
#line 364 "src/parser.y"
                             { (yyval.string) = new std::string("%="); }
#line 2033 "src/parser.tab.cpp"
    break;

  case 140: /* assignment_operator: ADD_ASSIGN  */
#line 365 "src/parser.y"
                             { (yyval.string) = new std::string("+="); }
#line 2039 "src/parser.tab.cpp"
    break;

  case 141: /* assignment_operator: SUB_ASSIGN  */
#line 366 "src/parser.y"
                             { (yyval.string) = new std::string("-="); }
#line 2045 "src/parser.tab.cpp"
    break;

  case 142: /* assignment_operator: LEFTSHIFT_ASSIGN  */
#line 367 "src/parser.y"
                             { (yyval.string) = new std::string("<<="); }
#line 2051 "src/parser.tab.cpp"
    break;

  case 143: /* assignment_operator: RIGHTSHIFT_ASSIGN  */
#line 368 "src/parser.y"
                             { (yyval.string) = new std::string(">>="); }
#line 2057 "src/parser.tab.cpp"
    break;

  case 144: /* assignment_operator: AND_ASSIGN  */
#line 369 "src/parser.y"
                             { (yyval.string) = new std::string("&="); }
#line 2063 "src/parser.tab.cpp"
    break;

  case 145: /* assignment_operator: XOR_ASSIGN  */
#line 370 "src/parser.y"
                             { (yyval.string) = new std::string("^="); }
#line 2069 "src/parser.tab.cpp"
    break;

  case 146: /* assignment_operator: OR_ASSIGN  */
#line 371 "src/parser.y"
                             { (yyval.string) = new std::string("|="); }
#line 2075 "src/parser.tab.cpp"
    break;

  case 147: /* expression: assignment_expression  */
#line 375 "src/parser.y"
                                                                        {(yyval.expr) = (yyvsp[0].expr); /*{ $$ = initExprList($1); }*/}
#line 2081 "src/parser.tab.cpp"
    break;

  case 148: /* expression: expression ',' assignment_expression  */
#line 376 "src/parser.y"
                                                        { /* appendToExprList($1, $2); */ }
#line 2087 "src/parser.tab.cpp"
    break;

  case 150: /* type_specifier: VOID  */
#line 388 "src/parser.y"
                                { (yyval.string) = new std::string("void"); }
#line 2093 "src/parser.tab.cpp"
    break;

  case 153: /* type_specifier: INT  */
#line 391 "src/parser.y"
                                { (yyval.string) = new std::string("int"); }
#line 2099 "src/parser.tab.cpp"
    break;


#line 2103 "src/parser.tab.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
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
