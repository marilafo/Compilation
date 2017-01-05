/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "grammar.y" /* yacc.c:339  */

#define _GNU_SOURCE
#include <stdio.h>
#include "identificateur.h"
#include "double_to_hex.c"
#include "code.c"
  
  
  //A enlever quand on aura les listes
  //int tab = 0;
  //int p = 0;

  char *code;
  
  extern int yylineno;
  int yylex ();
  int yyerror ();

    
  

#line 88 "grammar.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.tab.h".  */
#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANTI = 259,
    CONSTANTF = 260,
    INC_OP = 261,
    DEC_OP = 262,
    LE_OP = 263,
    GE_OP = 264,
    EQ_OP = 265,
    NE_OP = 266,
    SUB_ASSIGN = 267,
    MUL_ASSIGN = 268,
    ADD_ASSIGN = 269,
    DIV_ASSIGN = 270,
    SHL_ASSIGN = 271,
    SHR_ASSIGN = 272,
    REM_ASSIGN = 273,
    REM = 274,
    SHL = 275,
    SHR = 276,
    AND = 277,
    OR = 278,
    TYPE_NAME = 279,
    INT = 280,
    DOUBLE = 281,
    VOID = 282,
    IF = 283,
    ELSE = 284,
    DO = 285,
    WHILE = 286,
    RETURN = 287,
    FOR = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "grammar.y" /* yacc.c:355  */

  char *string;
  int n;
  double f;

  struct llist *list;
  
  struct expression *exp;
  struct generation *gen;

#line 173 "grammar.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 190 "grammar.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   298

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,    35,    38,    40,    36,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      41,    43,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    59,    62,    69,    72,    79,    82,    85,
      92,   103,   109,   115,   118,   134,   156,   159,   163,   171,
     174,   180,   183,   187,   191,   210,   215,   218,   221,   224,
     231,   234,   237,   244,   247,   250,   253,   256,   259,   262,
     269,   273,   280,   283,   286,   289,   292,   295,   298,   301,
     308,   330,   335,   343,   347,   351,   361,   384,   397,   401,
     404,   426,   451,   455,   463,   470,   473,   476,   479,   482,
     488,   505,   514,   518,   521,   528,   531,   538,   541,   548,
     551,   558,   561,   568,   572,   579,   582,   585,   588,   591,
     594,   597,   600,   603,   606,   613,   616,   623,   626,   633,
     637,   645,   648,   655
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANTI", "CONSTANTF",
  "INC_OP", "DEC_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "SUB_ASSIGN",
  "MUL_ASSIGN", "ADD_ASSIGN", "DIV_ASSIGN", "SHL_ASSIGN", "SHR_ASSIGN",
  "REM_ASSIGN", "REM", "SHL", "SHR", "AND", "OR", "TYPE_NAME", "INT",
  "DOUBLE", "VOID", "IF", "ELSE", "DO", "WHILE", "RETURN", "FOR", "'('",
  "')'", "','", "'-'", "'*'", "'/'", "'+'", "'<'", "'>'", "'='", "';'",
  "'{'", "'}'", "$accept", "conditional_expression",
  "logical_or_expression", "logical_and_expression", "shift_expression",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "comparison_expression", "expression",
  "assignment_operator", "declaration", "declarator_list", "type_name",
  "function_declarator", "declarator", "parameter_list",
  "parameter_declaration", "statement", "LB", "RB", "compound_statement",
  "compound_stat", "compound_dec", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "program", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    40,    41,    44,    45,    42,    47,
      43,    60,    62,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -44

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-44)))

#define YYTABLE_NINF -58

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      54,   -44,   -44,   -44,   -44,    -1,     5,   -44,   -44,   -44,
      -1,   -24,   -42,   -25,   -44,   -44,    69,    -1,   -44,   -44,
      63,   -44,     0,   260,   -44,   -15,     4,   -44,   -44,    31,
      33,    15,   172,    48,    68,    58,    10,   -44,   -44,   -44,
     -44,    16,    24,    95,   -44,   -44,   255,    10,    91,   -19,
     142,     7,   -44,    -1,   -44,   -44,   -44,    52,    52,   137,
     137,   -44,   -44,   -44,   -44,    56,    -1,    96,   -44,   -44,
     125,   -44,   -44,   207,   -44,   -44,    10,    75,    10,   -44,
      67,    80,    78,    10,    10,    10,    10,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,    10,   -44,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,   -44,   -15,
     -44,   -44,   -44,   -44,   -44,   -44,   -15,    77,    54,   -44,
     -44,   162,   -44,   103,    92,   112,   -44,   152,   122,   -44,
      24,   -44,   142,   -19,   -19,   -44,   -44,   -44,   -44,    91,
      91,    95,    95,    95,    95,    95,    95,   -44,   -44,    10,
     172,    10,   172,   222,   136,   187,   -44,   156,   160,   -44,
     172,   164,   229,   242,   157,   172,   171,   -44,   172,   172,
     183,   172,   184,   247,   -44,   -44,   -44,   -44,   172,   -44,
     172,   172,   185,   -44,   -44,   -44,   172,   -44
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    54,    55,    53,   102,     0,     0,    99,   101,    58,
       0,     0,     0,    51,     1,   100,     0,     0,    50,    70,
       0,   103,     0,     0,    59,    52,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    83,    71,
      41,     2,     3,    33,    16,    21,    26,     0,    30,     7,
       5,     0,    79,     0,    81,    72,    65,     0,     0,    77,
      75,    66,    69,    67,    68,    61,     0,     0,    62,    61,
       0,    17,    18,     0,    22,    23,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,    49,    43,    48,
      44,    46,    47,    45,    42,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    51,
      73,    74,    80,    78,    82,    76,    64,    60,     0,    60,
      14,     0,    19,     0,     0,     0,    98,     0,     0,    13,
       4,    26,     6,     8,     9,    40,    29,    27,    28,    32,
      31,    36,    37,    38,    39,    34,    35,    63,    15,     0,
       0,     0,     0,     0,     0,     0,    20,    85,     0,    95,
       0,     0,     0,     0,     0,     0,     0,    94,     0,     0,
       0,     0,     0,     0,    86,    96,    93,    92,     0,    90,
       0,     0,     0,    91,    89,    88,     0,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -44,   127,   -44,   140,   186,   -44,   -44,   -44,   -43,   -44,
      72,   102,   146,   -28,   -44,    17,   -44,     1,   -44,    12,
     214,   120,   -32,   -44,   150,   227,   181,   195,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   237,   -44
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    40,    41,    42,    43,    44,    45,   121,    46,    47,
      48,    49,    50,    51,    95,     4,    11,    53,    12,    13,
      67,    68,    54,    20,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     6,     7,     8
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,     5,     9,    19,    96,    14,    80,     5,    82,    22,
      71,    72,    17,    26,    27,    28,    29,    30,   100,    23,
      18,   101,    16,    66,    66,     1,     2,     3,   114,    25,
       1,     2,     3,    10,    74,    65,    75,    52,    73,    83,
     131,   131,   131,   131,    36,   122,    84,    37,   123,    76,
     125,   108,   131,   128,   136,   137,   138,   131,   131,   131,
     131,   131,   131,   131,   131,   109,    26,    27,    28,    29,
      30,    26,    27,    28,    29,    30,   112,    52,   116,     1,
       2,     3,    78,    26,    27,    28,    29,    30,     1,     2,
       3,    31,    81,    32,    33,    34,    35,    36,    39,   154,
      37,   -57,    36,    23,    24,    37,   124,    38,    19,    39,
      97,   126,    79,   129,    36,    85,    86,    37,   157,    66,
     159,   156,   -56,   158,   127,   161,   151,   164,   167,    98,
      99,   117,   118,   174,   170,   172,   176,   177,   150,   179,
      26,    27,    28,    29,    30,   182,   183,   152,   184,   185,
     102,   103,   104,   105,   187,    26,    27,    28,    29,    30,
     119,   118,     1,     2,     3,    31,   155,    32,    33,    34,
      35,    36,   139,   140,    37,    26,    27,    28,    29,    30,
     162,    38,    19,   106,   107,   165,    36,   133,   134,    37,
      26,    27,    28,    29,    30,   166,   153,   148,   149,   168,
      31,   173,    32,    33,    34,    35,    36,   110,   111,    37,
      26,    27,    28,    29,    30,   175,    38,    19,   178,   180,
     186,    36,   135,   130,    37,    26,    27,    28,    29,    30,
     132,   163,    26,    27,    28,    29,    30,    70,   147,    21,
     113,    36,   120,    15,    37,    26,    27,    28,    29,    30,
      26,    27,    28,    29,    30,   115,    36,   160,     0,    37,
       0,     0,     0,    36,   169,     0,    37,    87,    88,    89,
      90,    91,    92,    93,     0,     0,    36,   171,     0,    37,
       0,    36,   181,     0,    37,     1,     2,     3,   141,   142,
     143,   144,   145,   146,     0,    69,     0,     0,    94
};

static const yytype_int16 yycheck[] =
{
      32,     0,     3,    45,    47,     0,    34,     6,    36,    34,
       6,     7,    36,     3,     4,     5,     6,     7,    37,    34,
      44,    40,    10,    22,    23,    25,    26,    27,    60,    17,
      25,    26,    27,    34,     3,    35,     3,    20,    34,    23,
      83,    84,    85,    86,    34,    73,    22,    37,    76,    34,
      78,    44,    95,    81,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    53,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,    59,    60,    66,    25,
      26,    27,    34,     3,     4,     5,     6,     7,    25,    26,
      27,    28,    34,    30,    31,    32,    33,    34,    46,   127,
      37,    45,    34,    34,    35,    37,    31,    44,    45,    46,
      19,    44,    44,    35,    34,    20,    21,    37,   150,   118,
     152,   149,    45,   151,    44,   153,    34,   155,   160,    38,
      39,    35,    36,   165,   162,   163,   168,   169,    35,   171,
       3,     4,     5,     6,     7,   173,   178,    35,   180,   181,
       8,     9,    10,    11,   186,     3,     4,     5,     6,     7,
      35,    36,    25,    26,    27,    28,    44,    30,    31,    32,
      33,    34,   100,   101,    37,     3,     4,     5,     6,     7,
      44,    44,    45,    41,    42,    29,    34,    85,    86,    37,
       3,     4,     5,     6,     7,    35,    44,    35,    36,    35,
      28,    44,    30,    31,    32,    33,    34,    57,    58,    37,
       3,     4,     5,     6,     7,    44,    44,    45,    35,    35,
      35,    34,    95,    83,    37,     3,     4,     5,     6,     7,
      84,    44,     3,     4,     5,     6,     7,    23,   118,    12,
      59,    34,    35,     6,    37,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,    60,    34,    35,    -1,    37,
      -1,    -1,    -1,    34,    35,    -1,    37,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    34,    35,    -1,    37,
      -1,    34,    35,    -1,    37,    25,    26,    27,   102,   103,
     104,   105,   106,   107,    -1,    35,    -1,    -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    26,    27,    62,    64,    81,    82,    83,     3,
      34,    63,    65,    66,     0,    82,    66,    36,    44,    45,
      70,    72,    34,    34,    35,    66,     3,     4,     5,     6,
       7,    28,    30,    31,    32,    33,    34,    37,    44,    46,
      48,    49,    50,    51,    52,    53,    55,    56,    57,    58,
      59,    60,    62,    64,    69,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    35,    64,    67,    68,    35,
      67,     6,     7,    34,     3,     3,    34,    69,    34,    44,
      60,    34,    60,    23,    22,    20,    21,    12,    13,    14,
      15,    16,    17,    18,    43,    61,    55,    19,    38,    39,
      37,    40,     8,     9,    10,    11,    41,    42,    44,    66,
      71,    71,    62,    73,    69,    74,    66,    35,    36,    35,
      35,    54,    60,    60,    31,    60,    44,    44,    60,    35,
      50,    55,    59,    58,    58,    48,    55,    55,    55,    57,
      57,    51,    51,    51,    51,    51,    51,    68,    35,    36,
      35,    34,    35,    44,    60,    44,    60,    69,    60,    69,
      35,    60,    44,    44,    60,    29,    35,    69,    35,    35,
      60,    35,    60,    44,    69,    44,    69,    69,    35,    69,
      35,    35,    60,    69,    69,    69,    35,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    51,
      52,    52,    52,    52,    52,    52,    53,    53,    53,    54,
      54,    55,    55,    55,    55,    56,    57,    57,    57,    57,
      58,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    63,    63,    64,    64,    64,    65,    65,    66,    66,
      66,    66,    67,    67,    68,    69,    69,    69,    69,    69,
      70,    71,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    79,    79,    80,    80,    81,
      81,    82,    82,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     3,     1,     3,     3,
       1,     1,     1,     3,     3,     4,     1,     2,     2,     1,
       3,     1,     2,     2,     2,     1,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     4,     3,     1,     3,
       4,     3,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     3,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     5,     7,     9,     8,     8,
       7,     8,     7,     7,     6,     5,     7,     2,     3,     1,
       2,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 52 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = (yyvsp[0].gen);
 }
#line 1428 "grammar.c" /* yacc.c:1646  */
    break;

  case 3:
#line 59 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = (yyvsp[0].gen);
 }
#line 1436 "grammar.c" /* yacc.c:1646  */
    break;

  case 4:
#line 62 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), OR_OP, 0);
 }
#line 1444 "grammar.c" /* yacc.c:1646  */
    break;

  case 5:
#line 69 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = (yyvsp[0].gen);
 }
#line 1452 "grammar.c" /* yacc.c:1646  */
    break;

  case 6:
#line 72 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), AND_OP, 0);
 }
#line 1460 "grammar.c" /* yacc.c:1646  */
    break;

  case 7:
#line 79 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = (yyvsp[0].gen);
 }
#line 1468 "grammar.c" /* yacc.c:1646  */
    break;

  case 8:
#line 82 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), SHL_OP, 0);
 }
#line 1476 "grammar.c" /* yacc.c:1646  */
    break;

  case 9:
#line 85 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), SHR_OP, 0);
 }
#line 1484 "grammar.c" /* yacc.c:1646  */
    break;

  case 10:
#line 92 "grammar.y" /* yacc.c:1646  */
    {
  //printf("%s\n",$1);
  tmp = action_identifier((yyvsp[0].string));
  (yyval.gen) = malloc(sizeof(struct generation));
  (yyval.gen)->name = tmp->val;
  (yyval.gen)->t = tmp->t;
  (yyval.gen)->code = NULL;
  (yyval.gen)->last_id = (yyvsp[0].string);
  //asprintf(&($$->code), "%s", $$->name);
  //printf("%s", $$->name);      
 }
#line 1500 "grammar.c" /* yacc.c:1646  */
    break;

  case 11:
#line 103 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = malloc(sizeof(struct generation));
  (yyval.gen)->name = new_var();
  (yyval.gen)->t = INTEGER;
  asprintf(&((yyval.gen)->code),"%s = add i32 0, %d\n", (yyval.gen)->name, (yyvsp[0].n));
  }
#line 1511 "grammar.c" /* yacc.c:1646  */
    break;

  case 12:
#line 109 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = malloc(sizeof(struct generation));
  (yyval.gen)->name = new_var();
  (yyval.gen)->t = FLOATING;
  asprintf(&((yyval.gen)->code),"%s = fadd double %s, %s\n", (yyval.gen)->name, double_to_hex_str(0.0), double_to_hex_str((yyvsp[0].f)));
  }
#line 1522 "grammar.c" /* yacc.c:1646  */
    break;

  case 13:
#line 115 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = (yyvsp[-1].gen);
  }
#line 1530 "grammar.c" /* yacc.c:1646  */
    break;

  case 14:
#line 118 "grammar.y" /* yacc.c:1646  */
    {
  //printf("%s\n",$1);
  //printf("Contenu hash table\n");
  //g_hash_table_foreach(hash_array[0], print_hash, NULL);
  (yyval.gen) = malloc(sizeof(struct generation));
  tmp = map_with_name(new_func((yyvsp[-2].string)));
  //faire la vérif de type
  if(tmp == NULL){
    asprintf(&err, "Error: %s function not define", (yyvsp[-2].string));
    yyerror(err);
  }    
  (yyval.gen)->name = tmp->val;
  (yyval.gen)->t = tmp->t;
  (yyval.gen)->last_id = NULL;
  asprintf(&((yyval.gen)->code), "%s",call_function((yyval.gen)->name, tmp->val, "", tmp->t));
  }
#line 1551 "grammar.c" /* yacc.c:1646  */
    break;

  case 15:
#line 134 "grammar.y" /* yacc.c:1646  */
    {
  //printf("%s\n", $1);
  //printf("Contenu hash table\n");
  //g_hash_table_foreach(hash_array[0], print_hash, NULL);
  (yyval.gen) = malloc(sizeof(struct generation));
  printf("mapping %s\n", new_func((yyvsp[-3].string)));
  tmp = map_with_name(new_func((yyvsp[-3].string)));
  //faire la vérif de type
  if(tmp == NULL){
    asprintf(&err, "Error: %s function not define", (yyvsp[-3].string));
    yyerror(err);
  }
    
  (yyval.gen)->name = tmp->val;
  (yyval.gen)->t = tmp->t;
  (yyval.gen)->last_id = NULL;
  asprintf(&((yyval.gen)->code), "%s", call_function((yyval.gen)->name, tmp->val, (yyvsp[-1].string), tmp->t));
  }
#line 1574 "grammar.c" /* yacc.c:1646  */
    break;

  case 16:
#line 156 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = (yyvsp[0].gen);
 }
#line 1582 "grammar.c" /* yacc.c:1646  */
    break;

  case 17:
#line 159 "grammar.y" /* yacc.c:1646  */
    {
  //printf("%s\n", $1);
  (yyval.gen) = op_1((yyvsp[-1].string),ADD_OP);
 }
#line 1591 "grammar.c" /* yacc.c:1646  */
    break;

  case 18:
#line 163 "grammar.y" /* yacc.c:1646  */
    {
  //printf("%s\n", $1);
  (yyval.gen) = op_1((yyvsp[-1].string),SUB_OP);
 }
#line 1600 "grammar.c" /* yacc.c:1646  */
    break;

  case 19:
#line 171 "grammar.y" /* yacc.c:1646  */
    {
  asprintf(&(yyval.string),"%s",get_type((yyvsp[0].gen)->name, (yyvsp[0].gen)->t));
 }
#line 1608 "grammar.c" /* yacc.c:1646  */
    break;

  case 20:
#line 174 "grammar.y" /* yacc.c:1646  */
    {
  asprintf(&(yyval.string),"%s, %s",(yyvsp[-2].string), get_type((yyvsp[0].gen)->name, (yyvsp[0].gen)->t));
  }
#line 1616 "grammar.c" /* yacc.c:1646  */
    break;

  case 21:
#line 180 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = (yyvsp[0].gen);
 }
#line 1624 "grammar.c" /* yacc.c:1646  */
    break;

  case 22:
#line 183 "grammar.y" /* yacc.c:1646  */
    {
  printf("%s\n",(yyvsp[0].string));
  (yyval.gen) = op_1((yyvsp[0].string), ADD_OP);
 }
#line 1633 "grammar.c" /* yacc.c:1646  */
    break;

  case 23:
#line 187 "grammar.y" /* yacc.c:1646  */
    {
  printf("%s\n",(yyvsp[0].string));
  (yyval.gen) = op_1((yyvsp[0].string), SUB_OP);
 }
#line 1642 "grammar.c" /* yacc.c:1646  */
    break;

  case 24:
#line 191 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = malloc(sizeof(struct generation));
  (yyval.gen)->name = new_var();
  (yyval.gen)->t = (yyvsp[0].gen)->t;
  switch((yyval.gen)->t){
  case INTEGER :
    asprintf(&((yyval.gen)->code),"%s%s = sub i32 0, %s\n",(yyvsp[0].gen)->code, (yyval.gen)->name, (yyvsp[0].gen)->name);
    break;
  case FLOATING:
    asprintf(&((yyval.gen)->code),"%s%s = fsub double %s, %s\n",(yyvsp[0].gen)->code, (yyval.gen)->name, double_to_hex_str(0.0), (yyvsp[0].gen)->name);
    break;
  default:
    printf("Error l.278\n");
  }
 }
#line 1662 "grammar.c" /* yacc.c:1646  */
    break;

  case 26:
#line 215 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = (yyvsp[0].gen);
 }
#line 1670 "grammar.c" /* yacc.c:1646  */
    break;

  case 27:
#line 218 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), MUL_OP, 0);
  }
#line 1678 "grammar.c" /* yacc.c:1646  */
    break;

  case 28:
#line 221 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), DIV_OP, 0);
  }
#line 1686 "grammar.c" /* yacc.c:1646  */
    break;

  case 29:
#line 224 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), REM_OP, 0);
 }
#line 1694 "grammar.c" /* yacc.c:1646  */
    break;

  case 30:
#line 231 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = (yyvsp[0].gen);
 }
#line 1702 "grammar.c" /* yacc.c:1646  */
    break;

  case 31:
#line 234 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), ADD_OP, 0);
  }
#line 1710 "grammar.c" /* yacc.c:1646  */
    break;

  case 32:
#line 237 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), SUB_OP, 0);
  }
#line 1718 "grammar.c" /* yacc.c:1646  */
    break;

  case 33:
#line 244 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = (yyvsp[0].gen);
 }
#line 1726 "grammar.c" /* yacc.c:1646  */
    break;

  case 34:
#line 247 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), L_COMP, 1);
  }
#line 1734 "grammar.c" /* yacc.c:1646  */
    break;

  case 35:
#line 250 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), G_COMP, 1);
  }
#line 1742 "grammar.c" /* yacc.c:1646  */
    break;

  case 36:
#line 253 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), LE_COMP, 1);
 }
#line 1750 "grammar.c" /* yacc.c:1646  */
    break;

  case 37:
#line 256 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), GE_COMP, 1);
 }
#line 1758 "grammar.c" /* yacc.c:1646  */
    break;

  case 38:
#line 259 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), EQ_COMP, 1);
 }
#line 1766 "grammar.c" /* yacc.c:1646  */
    break;

  case 39:
#line 262 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), NE_COMP, 1);
 }
#line 1774 "grammar.c" /* yacc.c:1646  */
    break;

  case 40:
#line 269 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = operation_expression((yyvsp[-2].gen), (yyvsp[0].gen), string_to_op_code((yyvsp[-1].string)), 0);
  asprintf(&((yyval.gen)->code), "%s%s",(yyval.gen)->code,store_value((yyvsp[0].gen)->name, (yyvsp[-2].gen)->name, (yyval.gen)->t)); 
 }
#line 1783 "grammar.c" /* yacc.c:1646  */
    break;

  case 41:
#line 273 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.gen) = (yyvsp[0].gen);
  }
#line 1791 "grammar.c" /* yacc.c:1646  */
    break;

  case 42:
#line 280 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "ass";
 }
#line 1799 "grammar.c" /* yacc.c:1646  */
    break;

  case 43:
#line 283 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "mul";
  }
#line 1807 "grammar.c" /* yacc.c:1646  */
    break;

  case 44:
#line 286 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "div";
  }
#line 1815 "grammar.c" /* yacc.c:1646  */
    break;

  case 45:
#line 289 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "rem";
  }
#line 1823 "grammar.c" /* yacc.c:1646  */
    break;

  case 46:
#line 292 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "shl";
  }
#line 1831 "grammar.c" /* yacc.c:1646  */
    break;

  case 47:
#line 295 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "shr";
  }
#line 1839 "grammar.c" /* yacc.c:1646  */
    break;

  case 48:
#line 298 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "add";
  }
#line 1847 "grammar.c" /* yacc.c:1646  */
    break;

  case 49:
#line 301 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "sub";
  }
#line 1855 "grammar.c" /* yacc.c:1646  */
    break;

  case 50:
#line 308 "grammar.y" /* yacc.c:1646  */
    {
  int length_l = length_llist((yyvsp[-1].list));
  
  int i = 0;
  struct expression *tmp;
  for(; i<length_l; i++){
    tmp = look_for((yyvsp[-1].list), i); 
    tmp->t = string_to_type((yyvsp[-2].string));
    tmp->level = level;
    if(g_hash_table_contains(hash_array[level], tmp->name))
      printf("Erreur : rédéclaration de la variable %s", tmp->name);
    else
      g_hash_table_insert(hash_array[level], tmp->name, tmp);
  }
  
 }
#line 1876 "grammar.c" /* yacc.c:1646  */
    break;

  case 51:
#line 330 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.list) = init_llist();
  add_llist((yyval.list), (yyvsp[0].exp));
 }
#line 1885 "grammar.c" /* yacc.c:1646  */
    break;

  case 52:
#line 335 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.list) = (yyvsp[-2].list);
  add_llist((yyval.list), (yyvsp[0].exp));
  }
#line 1894 "grammar.c" /* yacc.c:1646  */
    break;

  case 53:
#line 343 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "void";
  last_type = VOID_T;
 }
#line 1903 "grammar.c" /* yacc.c:1646  */
    break;

  case 54:
#line 347 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "int";
  last_type = INTEGER;
  }
#line 1912 "grammar.c" /* yacc.c:1646  */
    break;

  case 55:
#line 351 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "double";
  last_type = FLOATING;
  }
#line 1921 "grammar.c" /* yacc.c:1646  */
    break;

  case 56:
#line 361 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.exp) = (yyvsp[-3].exp);
  init_function((yyval.exp), new_func((yyval.exp)->name), last_type, (yyvsp[-1].list));
  if(!g_hash_table_contains(hash_array[level], new_func((yyvsp[-3].exp)->name)))
    g_hash_table_insert(hash_array[level], new_func((yyvsp[-3].exp)->name), (yyval.exp));
  //Sinon vérification de param
  int i = 0;
  for(; i < length_llist((yyvsp[-1].list)); ++i){
    tmp = look_for((yyvsp[-1].list), i);
    if(tmp->t != VOID_T){
      if(nb_occ((yyvsp[-1].list), tmp->name) != 1){
	asprintf(&err, "Error: param %s already initialize\n", tmp->name);
	yyerror(err);
      }
      if(!g_hash_table_contains(hash_array[level],new_param(tmp->name)))
	g_hash_table_insert(hash_array[level], new_param(tmp->name),tmp);
    }
    else{
      asprintf(&err,"Error:impossible to have void parameter :%s", tmp->name);
      yyerror(err);
    }
  }
 }
#line 1949 "grammar.c" /* yacc.c:1646  */
    break;

  case 57:
#line 384 "grammar.y" /* yacc.c:1646  */
    {
  if(!g_hash_table_contains(hash_array[level], new_func((yyvsp[-2].exp)->name)))
    g_hash_table_insert(hash_array[level], new_func((yyvsp[-2].exp)->name), (yyval.exp));
  //Sinon vérification de param
  (yyval.exp) = (yyvsp[-2].exp);
  init_function((yyval.exp),new_func((yyval.exp)->name), last_type, NULL);
  }
#line 1961 "grammar.c" /* yacc.c:1646  */
    break;

  case 58:
#line 397 "grammar.y" /* yacc.c:1646  */
    {
  //printf("%s\n",$1);
  (yyval.exp) = create_non_init_exp((yyvsp[0].string));
 }
#line 1970 "grammar.c" /* yacc.c:1646  */
    break;

  case 59:
#line 401 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.exp) = (yyvsp[-1].exp);
  }
#line 1978 "grammar.c" /* yacc.c:1646  */
    break;

  case 60:
#line 404 "grammar.y" /* yacc.c:1646  */
    {
    (yyval.exp) = (yyvsp[-3].exp);
    
    init_function((yyval.exp), new_func((yyval.exp)->name), last_type, (yyvsp[-1].list));
    if(!g_hash_table_contains(hash_array[level], new_func((yyvsp[-3].exp)->name)))
      g_hash_table_insert(hash_array[level], new_func((yyvsp[-3].exp)->name), (yyval.exp));
    //Sinon vérification de param
    int i = 0;
    for(; i < length_llist((yyvsp[-1].list)); ++i){
      tmp = look_for((yyvsp[-1].list), i);
      if(tmp->t != VOID_T){
	if(nb_occ((yyvsp[-1].list), tmp->name) != 1)
	  asprintf(&err, "Error: param %s already initialize\n", tmp->name);
	yyerror(err);
	if(!g_hash_table_contains(hash_array[level],new_param(tmp->name)))
	  g_hash_table_insert(hash_array[level], new_param(tmp->name),tmp);
      }
      else
	asprintf(&err,"Error:impossible to have void parameter :%s", tmp->name);
      yyerror(err);
    }
  }
#line 2005 "grammar.c" /* yacc.c:1646  */
    break;

  case 61:
#line 426 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.exp) = (yyvsp[-2].exp);
  init_function((yyval.exp), new_func((yyval.exp)->name), last_type, NULL);
  if(!g_hash_table_contains(hash_array[level], new_func((yyvsp[-2].exp)->name)))
    g_hash_table_insert(hash_array[level], new_func((yyvsp[-2].exp)->name), (yyval.exp));
  //Sinon vérification de param
  }
#line 2017 "grammar.c" /* yacc.c:1646  */
    break;

  case 62:
#line 451 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.list) = init_llist();
  add_llist((yyval.list), (yyvsp[0].exp));
 }
#line 2026 "grammar.c" /* yacc.c:1646  */
    break;

  case 63:
#line 455 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.list) = (yyvsp[-2].list);
  add_llist((yyval.list), (yyvsp[0].exp));
  }
#line 2035 "grammar.c" /* yacc.c:1646  */
    break;

  case 64:
#line 463 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.exp) = (yyvsp[0].exp);
 }
#line 2043 "grammar.c" /* yacc.c:1646  */
    break;

  case 65:
#line 470 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = (yyvsp[0].string);
 }
#line 2051 "grammar.c" /* yacc.c:1646  */
    break;

  case 66:
#line 473 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = (yyvsp[0].string);
  }
#line 2059 "grammar.c" /* yacc.c:1646  */
    break;

  case 67:
#line 476 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = (yyvsp[0].string);
  }
#line 2067 "grammar.c" /* yacc.c:1646  */
    break;

  case 68:
#line 479 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = (yyvsp[0].string);
  }
#line 2075 "grammar.c" /* yacc.c:1646  */
    break;

  case 69:
#line 482 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = (yyvsp[0].string);
  }
#line 2083 "grammar.c" /* yacc.c:1646  */
    break;

  case 70:
#line 488 "grammar.y" /* yacc.c:1646  */
    {
  level++;
  if(level >= max_hash){
    int i = max_hash;
    max_hash = max_hash * 2;
    hash_array = realloc(hash_array, max_hash);
    for(; i < max_hash ; ++i)
      hash_array[i] = NULL;
  }
  if(hash_array[level] != NULL)
    g_hash_table_remove_all(hash_array[level]);
  else
    hash_array[level] = g_hash_table_new(g_str_hash, g_str_equal);
 }
#line 2102 "grammar.c" /* yacc.c:1646  */
    break;

  case 71:
#line 505 "grammar.y" /* yacc.c:1646  */
    {
  g_hash_table_foreach(hash_array[level], value, NULL);
  
  level--;
 }
#line 2112 "grammar.c" /* yacc.c:1646  */
    break;

  case 72:
#line 514 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = NULL;
  
 }
#line 2121 "grammar.c" /* yacc.c:1646  */
    break;

  case 73:
#line 518 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = (yyvsp[-1].string);
 }
#line 2129 "grammar.c" /* yacc.c:1646  */
    break;

  case 74:
#line 521 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = (yyvsp[-1].string);
 }
#line 2137 "grammar.c" /* yacc.c:1646  */
    break;

  case 75:
#line 528 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = (yyvsp[0].string);
 }
#line 2145 "grammar.c" /* yacc.c:1646  */
    break;

  case 76:
#line 531 "grammar.y" /* yacc.c:1646  */
    {
  asprintf(&(yyval.string),"%s%s", (yyvsp[-1].string), (yyvsp[0].string));
 }
#line 2153 "grammar.c" /* yacc.c:1646  */
    break;

  case 77:
#line 538 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = (yyvsp[0].string);
 }
#line 2161 "grammar.c" /* yacc.c:1646  */
    break;

  case 78:
#line 541 "grammar.y" /* yacc.c:1646  */
    {
  asprintf(&(yyval.string), "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
 }
#line 2169 "grammar.c" /* yacc.c:1646  */
    break;

  case 79:
#line 548 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = (yyvsp[0].string);
 }
#line 2177 "grammar.c" /* yacc.c:1646  */
    break;

  case 80:
#line 551 "grammar.y" /* yacc.c:1646  */
    {
  asprintf(&(yyval.string),"%s%s", (yyvsp[-1].string), (yyvsp[0].string));
 }
#line 2185 "grammar.c" /* yacc.c:1646  */
    break;

  case 81:
#line 558 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = (yyvsp[0].string);
 }
#line 2193 "grammar.c" /* yacc.c:1646  */
    break;

  case 82:
#line 561 "grammar.y" /* yacc.c:1646  */
    {
  asprintf(&(yyval.string),"%s%s", (yyvsp[-1].string), (yyvsp[0].string));
 }
#line 2201 "grammar.c" /* yacc.c:1646  */
    break;

  case 83:
#line 569 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = NULL;
}
#line 2209 "grammar.c" /* yacc.c:1646  */
    break;

  case 84:
#line 572 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = (yyvsp[-1].gen)->code;
  }
#line 2217 "grammar.c" /* yacc.c:1646  */
    break;

  case 85:
#line 579 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = if_expression((yyvsp[-2].gen)->name, (yyvsp[-2].gen)->code, (yyvsp[0].string), NULL);
 }
#line 2225 "grammar.c" /* yacc.c:1646  */
    break;

  case 86:
#line 582 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = if_expression((yyvsp[-4].gen)->name, (yyvsp[-4].gen)->code, (yyvsp[-2].string), (yyvsp[0].string));
  }
#line 2233 "grammar.c" /* yacc.c:1646  */
    break;

  case 87:
#line 585 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = for_expression((yyvsp[-6].gen)->code, (yyvsp[-2].gen)->code, (yyvsp[-4].gen), (yyvsp[0].string));
  }
#line 2241 "grammar.c" /* yacc.c:1646  */
    break;

  case 88:
#line 588 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = for_expression((yyvsp[-5].gen)->code, NULL, (yyvsp[-3].gen), (yyvsp[0].string));
  }
#line 2249 "grammar.c" /* yacc.c:1646  */
    break;

  case 89:
#line 591 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = for_expression((yyvsp[-5].gen)->code, (yyvsp[-2].gen)->code, NULL, (yyvsp[0].string));
  }
#line 2257 "grammar.c" /* yacc.c:1646  */
    break;

  case 90:
#line 594 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = for_expression((yyvsp[-4].gen)->code, NULL, NULL, (yyvsp[0].string));
  }
#line 2265 "grammar.c" /* yacc.c:1646  */
    break;

  case 91:
#line 597 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = for_expression(NULL, (yyvsp[-2].gen)->code, (yyvsp[-4].gen), (yyvsp[0].string));
  }
#line 2273 "grammar.c" /* yacc.c:1646  */
    break;

  case 92:
#line 600 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = for_expression(NULL, NULL, (yyvsp[-3].gen), (yyvsp[0].string));
  }
#line 2281 "grammar.c" /* yacc.c:1646  */
    break;

  case 93:
#line 603 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = for_expression(NULL, (yyvsp[-2].gen)->code, NULL, (yyvsp[0].string));
  }
#line 2289 "grammar.c" /* yacc.c:1646  */
    break;

  case 94:
#line 606 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = for_expression(NULL, NULL, NULL, (yyvsp[0].string));
  }
#line 2297 "grammar.c" /* yacc.c:1646  */
    break;

  case 95:
#line 613 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = for_expression(NULL, (yyvsp[-2].gen)->code, NULL, (yyvsp[0].string));
 }
#line 2305 "grammar.c" /* yacc.c:1646  */
    break;

  case 96:
#line 616 "grammar.y" /* yacc.c:1646  */
    {
  asprintf(&(yyval.string),"%s%s", (yyvsp[-5].string),for_expression(NULL, (yyvsp[-2].gen)->code, NULL, (yyvsp[-5].string)));
 }
#line 2313 "grammar.c" /* yacc.c:1646  */
    break;

  case 97:
#line 623 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = return_expression(VOID_T, NULL);
 }
#line 2321 "grammar.c" /* yacc.c:1646  */
    break;

  case 98:
#line 626 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = return_expression((yyvsp[-1].gen)->t, (yyvsp[-1].gen)->name);
 }
#line 2329 "grammar.c" /* yacc.c:1646  */
    break;

  case 99:
#line 633 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = (yyvsp[0].string);
  code = (yyval.string);
 }
#line 2338 "grammar.c" /* yacc.c:1646  */
    break;

  case 100:
#line 637 "grammar.y" /* yacc.c:1646  */
    {
  asprintf(&(yyval.string), "%s%s", (yyvsp[-1].string), (yyvsp[0].string));
  code = (yyval.string);
 }
#line 2347 "grammar.c" /* yacc.c:1646  */
    break;

  case 101:
#line 645 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = (yyvsp[0].string);
 }
#line 2355 "grammar.c" /* yacc.c:1646  */
    break;

  case 102:
#line 648 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = (yyvsp[0].string);
  }
#line 2363 "grammar.c" /* yacc.c:1646  */
    break;

  case 103:
#line 655 "grammar.y" /* yacc.c:1646  */
    {
  (yyvsp[-1].exp)->t = string_to_type((yyvsp[-2].string));
  (yyvsp[-1].exp)->level = level;
  switch((yyvsp[-1].exp)->t){
  case INTEGER:
    asprintf(&(yyval.string),"define i32 %s(%s){\n", new_func((yyvsp[-1].exp)->name), parameter_to_string((yyvsp[-1].exp)));
    break;
  case FLOATING:
    asprintf(&(yyval.string),"define double %s(%s){\n", new_func((yyvsp[-1].exp)->name), parameter_to_string((yyvsp[-1].exp)));
    break;
  case VOID_T:
    asprintf(&(yyval.string),"define void %s(%s){\n", new_func((yyvsp[-1].exp)->name), parameter_to_string((yyvsp[-1].exp)));
    break;
  default:
    printf("Error\n");
  }

  
  asprintf(&(yyval.string),"%s%s",(yyval.string), (yyvsp[0].string));  
  asprintf(&(yyval.string),"%s}\n",(yyval.string));


  
 }
#line 2392 "grammar.c" /* yacc.c:1646  */
    break;


#line 2396 "grammar.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 681 "grammar.y" /* yacc.c:1906  */

#include <stdio.h>
#include <string.h>

extern char yytext[];
extern int column;
extern int yylineno;
extern FILE *yyin;

char *file_name = NULL;

int yyerror (char *s) {
  fflush (stdout);
  fprintf (stderr, "%s:%d:%d: %s\n", file_name, yylineno, column, s);
  return 0;
}

int main (int argc, char *argv[]) {

  hash_array = calloc(max_hash, sizeof(GHashTable *));
  hash_array[level] = g_hash_table_new(g_str_hash, g_str_equal);
  int i = 1;
  for (; i < max_hash ; ++i)
    hash_array[i] = NULL;
  FILE *input = NULL;
  if (argc==2) {
    input = fopen (argv[1], "r");
    file_name = strdup (argv[1]);
    if (input) {
      yyin = input;
    }
    else {
      fprintf (stderr, "%s: Could not open %s\n", *argv, argv[1]);
      return 1;
    }
  }
  else {
    fprintf (stderr, "%s: error: no input file\n", *argv);
    return 1;
  }
  yyparse ();
  printf("%s\n", code);
  free (file_name);

  i = 0;
  for(; i < max_hash ; i++)
    if(hash_array[i] != NULL){
      g_hash_table_destroy(hash_array[i]);
    }
  free(hash_array);

  
  return 0;
}
