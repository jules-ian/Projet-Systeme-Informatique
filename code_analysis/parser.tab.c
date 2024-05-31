/* A Bison parser, made by GNU Bison 3.8.2.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
//#include "st.c"
#include "at.c"
#include "ft.c"

FILE *asm_file;
char ADRname[40] = "@ADR";

#line 82 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tVOID = 3,                      /* tVOID  */
  YYSYMBOL_tINT = 4,                       /* tINT  */
  YYSYMBOL_tELSE = 5,                      /* tELSE  */
  YYSYMBOL_tWHILE = 6,                     /* tWHILE  */
  YYSYMBOL_tPRINT = 7,                     /* tPRINT  */
  YYSYMBOL_tRETURN = 8,                    /* tRETURN  */
  YYSYMBOL_tADD = 9,                       /* tADD  */
  YYSYMBOL_tSUB = 10,                      /* tSUB  */
  YYSYMBOL_tMUL = 11,                      /* tMUL  */
  YYSYMBOL_tDIV = 12,                      /* tDIV  */
  YYSYMBOL_tLT = 13,                       /* tLT  */
  YYSYMBOL_tGT = 14,                       /* tGT  */
  YYSYMBOL_tNE = 15,                       /* tNE  */
  YYSYMBOL_tEQ = 16,                       /* tEQ  */
  YYSYMBOL_tGE = 17,                       /* tGE  */
  YYSYMBOL_tLE = 18,                       /* tLE  */
  YYSYMBOL_tASSIGN = 19,                   /* tASSIGN  */
  YYSYMBOL_tAND = 20,                      /* tAND  */
  YYSYMBOL_tOR = 21,                       /* tOR  */
  YYSYMBOL_tNOT = 22,                      /* tNOT  */
  YYSYMBOL_tSEMI = 23,                     /* tSEMI  */
  YYSYMBOL_tCOMMA = 24,                    /* tCOMMA  */
  YYSYMBOL_tLPAR = 25,                     /* tLPAR  */
  YYSYMBOL_tRPAR = 26,                     /* tRPAR  */
  YYSYMBOL_tLBRACE = 27,                   /* tLBRACE  */
  YYSYMBOL_tRBRACE = 28,                   /* tRBRACE  */
  YYSYMBOL_tERROR = 29,                    /* tERROR  */
  YYSYMBOL_tID = 30,                       /* tID  */
  YYSYMBOL_tNB = 31,                       /* tNB  */
  YYSYMBOL_tIF = 32,                       /* tIF  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_Programme = 34,                 /* Programme  */
  YYSYMBOL_Fonc = 35,                      /* Fonc  */
  YYSYMBOL_36_1 = 36,                      /* $@1  */
  YYSYMBOL_37_2 = 37,                      /* $@2  */
  YYSYMBOL_PushAdr = 38,                   /* PushAdr  */
  YYSYMBOL_PushVal = 39,                   /* PushVal  */
  YYSYMBOL_IncrDepth = 40,                 /* IncrDepth  */
  YYSYMBOL_DecrDepth = 41,                 /* DecrDepth  */
  YYSYMBOL_Params = 42,                    /* Params  */
  YYSYMBOL_Param = 43,                     /* Param  */
  YYSYMBOL_Body = 44,                      /* Body  */
  YYSYMBOL_Instruction = 45,               /* Instruction  */
  YYSYMBOL_Affectation = 46,               /* Affectation  */
  YYSYMBOL_Expr = 47,                      /* Expr  */
  YYSYMBOL_Declaration = 48,               /* Declaration  */
  YYSYMBOL_49_3 = 49,                      /* $@3  */
  YYSYMBOL_MultiDeclaration = 50,          /* MultiDeclaration  */
  YYSYMBOL_51_4 = 51,                      /* $@4  */
  YYSYMBOL_While = 52,                     /* While  */
  YYSYMBOL_53_5 = 53,                      /* @5  */
  YYSYMBOL_54_6 = 54,                      /* @6  */
  YYSYMBOL_DebutIf = 55,                   /* DebutIf  */
  YYSYMBOL_56_7 = 56,                      /* @7  */
  YYSYMBOL_If = 57,                        /* If  */
  YYSYMBOL_58_8 = 58,                      /* @8  */
  YYSYMBOL_Cond = 59,                      /* Cond  */
  YYSYMBOL_Print = 60,                     /* Print  */
  YYSYMBOL_Return = 61                     /* Return  */
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
typedef yytype_uint8 yy_state_t;

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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   131

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    40,    40,    41,    45,    45,    46,    46,    49,    51,
      53,    55,    59,    60,    61,    66,    67,    72,    73,    76,
      77,    78,    79,    80,    86,    90,    91,    94,    95,    96,
      97,   104,   104,   105,   108,   108,   108,   108,   112,   112,
     112,   119,   119,   125,   126,   126,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   152,   155
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
  "\"end of file\"", "error", "\"invalid token\"", "tVOID", "tINT",
  "tELSE", "tWHILE", "tPRINT", "tRETURN", "tADD", "tSUB", "tMUL", "tDIV",
  "tLT", "tGT", "tNE", "tEQ", "tGE", "tLE", "tASSIGN", "tAND", "tOR",
  "tNOT", "tSEMI", "tCOMMA", "tLPAR", "tRPAR", "tLBRACE", "tRBRACE",
  "tERROR", "tID", "tNB", "tIF", "$accept", "Programme", "Fonc", "$@1",
  "$@2", "PushAdr", "PushVal", "IncrDepth", "DecrDepth", "Params", "Param",
  "Body", "Instruction", "Affectation", "Expr", "Declaration", "$@3",
  "MultiDeclaration", "$@4", "While", "@5", "@6", "DebutIf", "@7", "If",
  "@8", "Cond", "Print", "Return", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      44,   -23,   -21,    21,    44,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,    36,   -67,    49,    43,   -67,     4,    51,
     -67,    49,    45,    52,    61,    74,   -67,    73,   -67,    19,
     -67,    58,    78,    79,    86,    83,   -67,    19,   -67,   -67,
     -67,   101,   -67,   -67,    19,   -13,   -67,    80,    25,   -12,
      84,   -67,   -67,   105,   -67,    85,    91,   -12,    90,   -67,
     -67,    34,    25,    81,    92,   -67,    82,    25,   -67,    25,
       9,   -67,    93,    94,    25,    25,    25,    25,   -67,    72,
      25,    25,    25,    25,    25,    25,    25,    25,   -67,   -67,
     -67,    53,    95,    62,   -67,   -67,   -67,   -67,    47,    47,
     -67,   -67,    72,    72,    72,    72,    72,    72,    72,    72,
      97,    19,   -67,   -67,   -67,    25,    98,   -67,    99,   -67,
       3,   -67,    19,   -67,   -67,    19,   100,   -67,   102,   -67,
     -67,   -67,   -67
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     3,     6,     4,     1,     2,    10,
      10,     8,     8,     0,     9,    12,     0,    13,     0,     0,
      14,    12,    15,     0,     0,     0,    10,     0,    16,    17,
      10,     0,     0,     0,     0,     0,    11,    17,    19,    20,
      21,    43,    22,    23,    17,    34,    38,     0,     0,     0,
       0,    18,    44,     0,    31,     0,     0,     0,     0,    25,
      26,     0,     0,    46,     0,    11,     0,     0,    11,     0,
      34,    33,     0,     0,     0,     0,     0,     0,    24,    55,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     7,
      10,     0,     0,     0,    36,    35,    39,    56,    29,    30,
      27,    28,    47,    48,    49,    50,    51,    52,    53,    54,
       0,    17,    57,    11,    32,     0,     0,    10,     0,     5,
      34,    10,    17,    11,    37,    17,     0,    45,     0,    11,
      11,    42,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   116,   -67,   -67,   -67,   109,   -67,   -10,   -63,   108,
     106,   -36,   -67,   -67,   -45,   -67,   -67,   -66,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,    65,   -67,   -67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,    10,     9,    13,    16,    11,    50,    19,
      20,    36,    37,    38,    63,    39,    69,    56,   115,    40,
      57,   116,    41,   110,    42,    66,    64,    43,    68
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      12,    51,    89,    61,    95,    92,    54,     5,    53,     6,
      62,    55,    74,    75,    76,    77,    29,    79,    59,    60,
      44,     7,    91,    31,    93,    32,    33,    55,    94,    98,
      99,   100,   101,    55,    22,   102,   103,   104,   105,   106,
     107,   108,   109,    74,    75,    76,    77,     1,     2,    34,
     119,    35,    17,    18,   124,    59,    60,    78,    76,    77,
     127,    15,    74,    75,    76,    77,   131,   132,    21,    25,
     120,    74,    75,    76,    77,   118,   112,    23,    18,    26,
     111,    74,    75,    76,    77,   114,   126,    27,    45,   128,
      74,    75,    76,    77,    80,    81,    82,    83,    84,    85,
      30,    86,    87,    46,    47,    48,    52,   122,    49,    90,
      58,   125,    65,    67,    71,    70,    73,    97,    88,    96,
       8,    14,    72,   113,   117,   121,     0,   123,   129,    24,
     130,    28
};

static const yytype_int16 yycheck[] =
{
      10,    37,    65,    48,    70,    68,    19,    30,    44,    30,
      22,    24,     9,    10,    11,    12,    26,    62,    30,    31,
      30,     0,    67,     4,    69,     6,     7,    24,    19,    74,
      75,    76,    77,    24,    30,    80,    81,    82,    83,    84,
      85,    86,    87,     9,    10,    11,    12,     3,     4,    30,
     113,    32,     3,     4,   120,    30,    31,    23,    11,    12,
     123,    25,     9,    10,    11,    12,   129,   130,    25,    24,
     115,     9,    10,    11,    12,   111,    23,    26,     4,    27,
      90,     9,    10,    11,    12,    23,   122,    26,    30,   125,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      27,    20,    21,    25,    25,    19,     5,   117,    25,    27,
      30,   121,    28,     8,    23,    30,    26,    23,    26,    26,
       4,    12,    57,    28,    27,    27,    -1,    28,    28,    21,
      28,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    34,    35,    30,    30,     0,    34,    37,
      36,    40,    40,    38,    38,    25,    39,     3,     4,    42,
      43,    25,    30,    26,    42,    24,    27,    26,    43,    40,
      27,     4,     6,     7,    30,    32,    44,    45,    46,    48,
      52,    55,    57,    60,    40,    30,    25,    25,    19,    25,
      41,    44,     5,    44,    19,    24,    50,    53,    30,    30,
      31,    47,    22,    47,    59,    28,    58,     8,    61,    49,
      30,    23,    59,    26,     9,    10,    11,    12,    23,    47,
      13,    14,    15,    16,    17,    18,    20,    21,    26,    41,
      27,    47,    41,    47,    19,    50,    26,    23,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      56,    40,    23,    28,    23,    51,    54,    27,    44,    41,
      47,    27,    40,    28,    50,    40,    44,    41,    44,    28,
      28,    41,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    34,    36,    35,    37,    35,    38,    39,
      40,    41,    42,    42,    42,    43,    43,    44,    44,    45,
      45,    45,    45,    45,    46,    47,    47,    47,    47,    47,
      47,    49,    48,    48,    50,    50,    51,    50,    53,    54,
      52,    56,    55,    57,    58,    57,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,    16,     0,    14,     0,     0,
       0,     0,     0,     1,     1,     2,     4,     0,     2,     1,
       1,     1,     1,     1,     4,     1,     1,     3,     3,     3,
       3,     0,     6,     4,     0,     3,     0,     6,     0,     0,
      11,     0,    10,     1,     0,     8,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     5,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 3: /* Programme: Fonc  */
#line 41 "parser.y"
         {add_instruction ("NOP",0, 0, 0);}
#line 1210 "parser.tab.c"
    break;

  case 4: /* $@1: %empty  */
#line 45 "parser.y"
               {function_table_push((yyvsp[0].s), at_top); (yyvsp[-1].nb) = atoi(pop_symbol().name);}
#line 1216 "parser.tab.c"
    break;

  case 5: /* Fonc: tINT tID $@1 IncrDepth PushAdr PushVal tLPAR Params tRPAR tLBRACE IncrDepth Body Return DecrDepth tRBRACE DecrDepth  */
#line 45 "parser.y"
                                                                                                                                                                                           {pop();  add_instruction("JMP", (yyvsp[-15].nb), 0, 0);pop();}
#line 1222 "parser.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 46 "parser.y"
               {function_table_push((yyvsp[0].s), at_top);}
#line 1228 "parser.tab.c"
    break;

  case 8: /* PushAdr: %empty  */
#line 49 "parser.y"
                 {push_ADR();}
#line 1234 "parser.tab.c"
    break;

  case 9: /* PushVal: %empty  */
#line 51 "parser.y"
                 {push_VAL();}
#line 1240 "parser.tab.c"
    break;

  case 10: /* IncrDepth: %empty  */
#line 53 "parser.y"
                    {incr_depth();}
#line 1246 "parser.tab.c"
    break;

  case 11: /* DecrDepth: %empty  */
#line 55 "parser.y"
                    {decr_depth();}
#line 1252 "parser.tab.c"
    break;

  case 15: /* Param: tINT tID  */
#line 66 "parser.y"
             {push((yyvsp[0].s));}
#line 1258 "parser.tab.c"
    break;

  case 16: /* Param: tINT tID tCOMMA Param  */
#line 67 "parser.y"
                          {push((yyvsp[-2].s));}
#line 1264 "parser.tab.c"
    break;

  case 24: /* Affectation: tID tASSIGN Expr tSEMI  */
#line 86 "parser.y"
                           { printf("Assignement de %d à %s\n", (yyvsp[-1].nb), (yyvsp[-3].s)); add_instruction ("COP",get_index((yyvsp[-3].s)), size()-1, 0); pop();}
#line 1270 "parser.tab.c"
    break;

  case 25: /* Expr: tID  */
#line 90 "parser.y"
        {push_tmp(); add_instruction ("COP",size()-1, get_index((yyvsp[0].s)), 0); }
#line 1276 "parser.tab.c"
    break;

  case 26: /* Expr: tNB  */
#line 91 "parser.y"
         {push_tmp(); add_instruction ("AFC",size()-1, (yyvsp[0].nb), 0);}
#line 1282 "parser.tab.c"
    break;

  case 27: /* Expr: Expr tMUL Expr  */
#line 94 "parser.y"
                   { add_instruction ("MUL",size()-2, size()-2, size()-1); pop();}
#line 1288 "parser.tab.c"
    break;

  case 28: /* Expr: Expr tDIV Expr  */
#line 95 "parser.y"
                   { add_instruction ("DIV",size()-2, size()-2, size()-1); pop();}
#line 1294 "parser.tab.c"
    break;

  case 29: /* Expr: Expr tADD Expr  */
#line 96 "parser.y"
                   { add_instruction ("ADD",size()-2, size()-2, size()-1); pop();}
#line 1300 "parser.tab.c"
    break;

  case 30: /* Expr: Expr tSUB Expr  */
#line 97 "parser.y"
                   { add_instruction ("SUB",size()-2, size()-2, size()-1); pop();}
#line 1306 "parser.tab.c"
    break;

  case 31: /* $@3: %empty  */
#line 104 "parser.y"
                     {push((yyvsp[-1].s));}
#line 1312 "parser.tab.c"
    break;

  case 32: /* Declaration: tINT tID tASSIGN $@3 Expr tSEMI  */
#line 104 "parser.y"
                                            {add_instruction("COP", get_index((yyvsp[-4].s)), size()-1, 0); pop();}
#line 1318 "parser.tab.c"
    break;

  case 33: /* Declaration: tINT tID MultiDeclaration tSEMI  */
#line 105 "parser.y"
                                      {;push((yyvsp[-2].s));}
#line 1324 "parser.tab.c"
    break;

  case 34: /* MultiDeclaration: %empty  */
#line 108 "parser.y"
                          {}
#line 1330 "parser.tab.c"
    break;

  case 35: /* MultiDeclaration: tCOMMA tID MultiDeclaration  */
#line 108 "parser.y"
                                                          {push((yyvsp[-1].s));}
#line 1336 "parser.tab.c"
    break;

  case 36: /* $@4: %empty  */
#line 108 "parser.y"
                                                                                           {push((yyvsp[-1].s));}
#line 1342 "parser.tab.c"
    break;

  case 37: /* MultiDeclaration: tCOMMA tID tASSIGN $@4 Expr MultiDeclaration  */
#line 108 "parser.y"
                                                                                                                             {add_instruction("COP", get_index((yyvsp[-4].s)), size()-1, 0); pop();}
#line 1348 "parser.tab.c"
    break;

  case 38: /* @5: %empty  */
#line 112 "parser.y"
               {(yyval.nb) = at_top;}
#line 1354 "parser.tab.c"
    break;

  case 39: /* @6: %empty  */
#line 112 "parser.y"
                                             {add_instruction("JMF", size()-1, -1, 0); pop(); (yyval.nb) = at_top - 1;}
#line 1360 "parser.tab.c"
    break;

  case 40: /* While: tWHILE tLPAR @5 Cond tRPAR @6 tLBRACE IncrDepth Body tRBRACE DecrDepth  */
#line 113 "parser.y"
                                           {add_instruction("JMP", (yyvsp[-8].nb), 0, 0); modify_jmf((yyvsp[-5].nb)); (yyval.nb) = (yyvsp[-5].nb);}
#line 1366 "parser.tab.c"
    break;

  case 41: /* @7: %empty  */
#line 119 "parser.y"
                         {add_instruction("JMF", size()-1, -1, 0); pop(); (yyval.nb) = at_top - 1;}
#line 1372 "parser.tab.c"
    break;

  case 42: /* DebutIf: tIF tLPAR Cond tRPAR @7 tLBRACE IncrDepth Body tRBRACE DecrDepth  */
#line 120 "parser.y"
                                             {modify_jmf((yyvsp[-5].nb)); (yyval.nb) = (yyvsp[-5].nb);}
#line 1378 "parser.tab.c"
    break;

  case 44: /* @8: %empty  */
#line 126 "parser.y"
                  {add_instruction("JMP", -1, 0, 0);modify_jmf((yyvsp[-1].nb));(yyval.nb) = at_top -1;}
#line 1384 "parser.tab.c"
    break;

  case 45: /* If: DebutIf tELSE @8 tLBRACE IncrDepth Body tRBRACE DecrDepth  */
#line 127 "parser.y"
                                             {modify_jmp((yyvsp[-5].nb));}
#line 1390 "parser.tab.c"
    break;

  case 46: /* Cond: Expr  */
#line 130 "parser.y"
            {(yyval.nb) = (yyvsp[0].nb);}
#line 1396 "parser.tab.c"
    break;

  case 47: /* Cond: Expr tLT Expr  */
#line 131 "parser.y"
                    {(yyval.nb) = (yyvsp[-2].nb) < (yyvsp[0].nb);  pop();}
#line 1402 "parser.tab.c"
    break;

  case 48: /* Cond: Expr tGT Expr  */
#line 132 "parser.y"
                    {(yyval.nb) = (yyvsp[-2].nb) > (yyvsp[0].nb);  pop();}
#line 1408 "parser.tab.c"
    break;

  case 49: /* Cond: Expr tNE Expr  */
#line 133 "parser.y"
                    {(yyval.nb) = (yyvsp[-2].nb) != (yyvsp[0].nb); pop();}
#line 1414 "parser.tab.c"
    break;

  case 50: /* Cond: Expr tEQ Expr  */
#line 134 "parser.y"
                    {(yyval.nb) = (yyvsp[-2].nb) == (yyvsp[0].nb); pop();}
#line 1420 "parser.tab.c"
    break;

  case 51: /* Cond: Expr tGE Expr  */
#line 135 "parser.y"
                    {(yyval.nb) = (yyvsp[-2].nb) >= (yyvsp[0].nb); pop();}
#line 1426 "parser.tab.c"
    break;

  case 52: /* Cond: Expr tLE Expr  */
#line 136 "parser.y"
                    {(yyval.nb) = (yyvsp[-2].nb) <= (yyvsp[0].nb); pop();}
#line 1432 "parser.tab.c"
    break;

  case 53: /* Cond: Expr tAND Expr  */
#line 137 "parser.y"
                    {(yyval.nb) = (yyvsp[-2].nb) && (yyvsp[0].nb); pop();}
#line 1438 "parser.tab.c"
    break;

  case 54: /* Cond: Expr tOR Expr  */
#line 138 "parser.y"
                    {(yyval.nb) = (yyvsp[-2].nb) || (yyvsp[0].nb); pop();}
#line 1444 "parser.tab.c"
    break;

  case 55: /* Cond: tNOT Expr  */
#line 139 "parser.y"
                    {(yyval.nb) = !(yyvsp[0].nb);      pop();}
#line 1450 "parser.tab.c"
    break;

  case 57: /* Return: tRETURN Expr tSEMI  */
#line 155 "parser.y"
                            {add_instruction ("COP",size()-1, get_index(ADRname), 0); pop(); add_instruction ("RET",0, 0, 0);}
#line 1456 "parser.tab.c"
    break;


#line 1460 "parser.tab.c"

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 164 "parser.y"



void yyerror(const char *msg) {
  fprintf(stderr, "error: %s\n", msg);
  exit(1);
} 


int main(void) {
  asm_file = fopen("assembly.asm", "w");
    
  
  if (asm_file == NULL) {
      printf("Unable to create file.\n");
      exit(1);
  }

  print_stack();
  yyparse();
  print_stack();

  to_asm_file(asm_file);

  fclose(asm_file);
}
