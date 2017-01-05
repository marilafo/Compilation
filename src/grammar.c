/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "grammar.y"

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

    
  
/* Line 371 of yacc.c  */
#line 89 "grammar.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 39 "grammar.y"

  char *string;
  int n;
  double f;

  struct llist *list;
  
  struct expression *exp;
  struct generation *gen;


/* Line 387 of yacc.c  */
#line 177 "grammar.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 205 "grammar.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
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
/* YYNRULES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    13,    17,    19,    23,
      27,    29,    31,    33,    37,    41,    46,    48,    51,    54,
      56,    60,    62,    65,    68,    71,    73,    75,    79,    83,
      87,    89,    93,    97,    99,   103,   107,   111,   115,   119,
     123,   127,   129,   131,   133,   135,   137,   139,   141,   143,
     145,   149,   151,   155,   157,   159,   161,   166,   170,   172,
     176,   181,   185,   187,   191,   194,   196,   198,   200,   202,
     204,   206,   208,   211,   215,   219,   221,   224,   226,   229,
     231,   234,   236,   239,   241,   244,   250,   258,   268,   277,
     286,   294,   303,   311,   319,   326,   332,   340,   343,   347,
     349,   352,   354,   356
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      81,     0,    -1,    49,    -1,    50,    -1,    49,    23,    50,
      -1,    59,    -1,    50,    22,    59,    -1,    58,    -1,    51,
      20,    58,    -1,    51,    21,    58,    -1,     3,    -1,     4,
      -1,     5,    -1,    34,    60,    35,    -1,     3,    34,    35,
      -1,     3,    34,    54,    35,    -1,    52,    -1,     3,     6,
      -1,     3,     7,    -1,    60,    -1,    54,    36,    60,    -1,
      53,    -1,     6,     3,    -1,     7,     3,    -1,    56,    55,
      -1,    37,    -1,    55,    -1,    57,    38,    55,    -1,    57,
      39,    55,    -1,    57,    19,    55,    -1,    57,    -1,    58,
      40,    57,    -1,    58,    37,    57,    -1,    51,    -1,    59,
      41,    51,    -1,    59,    42,    51,    -1,    59,     8,    51,
      -1,    59,     9,    51,    -1,    59,    10,    51,    -1,    59,
      11,    51,    -1,    55,    61,    48,    -1,    48,    -1,    43,
      -1,    13,    -1,    15,    -1,    18,    -1,    16,    -1,    17,
      -1,    14,    -1,    12,    -1,    64,    63,    44,    -1,    66,
      -1,    63,    36,    66,    -1,    27,    -1,    25,    -1,    26,
      -1,    66,    34,    67,    35,    -1,    66,    34,    35,    -1,
       3,    -1,    34,    66,    35,    -1,    66,    34,    67,    35,
      -1,    66,    34,    35,    -1,    68,    -1,    67,    36,    68,
      -1,    64,    66,    -1,    72,    -1,    77,    -1,    79,    -1,
      80,    -1,    78,    -1,    45,    -1,    46,    -1,    70,    71,
      -1,    70,    73,    71,    -1,    70,    74,    71,    -1,    76,
      -1,    76,    74,    -1,    75,    -1,    75,    73,    -1,    62,
      -1,    75,    62,    -1,    69,    -1,    76,    69,    -1,    44,
      -1,    60,    44,    -1,    28,    34,    60,    35,    69,    -1,
      28,    34,    60,    35,    69,    29,    69,    -1,    33,    34,
      60,    44,    60,    44,    60,    35,    69,    -1,    33,    34,
      60,    44,    60,    44,    35,    69,    -1,    33,    34,    60,
      44,    44,    60,    35,    69,    -1,    33,    34,    60,    44,
      44,    35,    69,    -1,    33,    34,    44,    60,    44,    60,
      35,    69,    -1,    33,    34,    44,    60,    44,    35,    69,
      -1,    33,    34,    44,    44,    60,    35,    69,    -1,    33,
      34,    44,    44,    35,    69,    -1,    31,    34,    60,    35,
      69,    -1,    30,    69,    31,    34,    60,    35,    44,    -1,
      32,    44,    -1,    32,    60,    44,    -1,    82,    -1,    81,
      82,    -1,    83,    -1,    62,    -1,    64,    65,    72,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    59,    62,    71,    74,    84,    87,    93,
     103,   113,   119,   125,   128,   146,   170,   173,   180,   191,
     197,   206,   209,   216,   223,   242,   247,   250,   256,   262,
     272,   275,   281,   291,   294,   300,   306,   312,   318,   324,
     334,   342,   349,   352,   355,   358,   361,   364,   367,   370,
     377,   399,   404,   412,   416,   420,   430,   453,   466,   470,
     473,   495,   520,   524,   532,   541,   544,   547,   550,   553,
     559,   576,   585,   589,   592,   599,   602,   609,   612,   619,
     622,   629,   632,   639,   643,   650,   653,   656,   659,   662,
     665,   668,   671,   674,   677,   684,   687,   694,   700,   710,
     714,   722,   725,   732
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
  "function_definition", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    40,    41,    44,    45,    42,    47,
      43,    60,    62,    61,    59,   123,   125
};
# endif

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

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
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

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
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

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    40,    41,    42,    43,    44,    45,   121,    46,    47,
      48,    49,    50,    51,    95,     4,    11,    53,    12,    13,
      67,    68,    54,    20,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     6,     7,     8
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -44
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -44,   127,   -44,   140,   186,   -44,   -44,   -44,   -43,   -44,
      72,   102,   146,   -28,   -44,    17,   -44,     1,   -44,    12,
     214,   120,   -32,   -44,   150,   227,   181,   195,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   237,   -44
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -58
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

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-44)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

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

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 52 "grammar.y"
    {
  (yyval.gen) = (yyvsp[(1) - (1)].gen);
 }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 59 "grammar.y"
    {
  (yyval.gen) = (yyvsp[(1) - (1)].gen);
 }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 62 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), OR_OP, 0) != NULL)
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), OR_OP, 0);
  else yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 71 "grammar.y"
    {
  (yyval.gen) = (yyvsp[(1) - (1)].gen);
 }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 74 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), AND_OP, 0) != NULL)
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), AND_OP, 0);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 84 "grammar.y"
    {
  (yyval.gen) = (yyvsp[(1) - (1)].gen);
 }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 87 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), SHL_OP, 0) != NULL)
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), SHL_OP, 0);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 93 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), SHR_OP, 0) != NULL)
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), SHR_OP, 0);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 103 "grammar.y"
    {
  //printf("%s\n",$1);
  tmp = action_identifier((yyvsp[(1) - (1)].string));
  (yyval.gen) = malloc(sizeof(struct generation));
  (yyval.gen)->name = tmp->val;
  (yyval.gen)->t = tmp->t;
  (yyval.gen)->code = NULL;
  //asprintf(&($$->code), "%s", $$->name);
  //printf("%s", $$->name);      
 }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 113 "grammar.y"
    {
  (yyval.gen) = malloc(sizeof(struct generation));
  (yyval.gen)->name = new_var();
  (yyval.gen)->t = INTEGER;
  asprintf(&((yyval.gen)->code),"%s = add i32 0, %d\n", (yyval.gen)->name, (yyvsp[(1) - (1)].n));
  }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 119 "grammar.y"
    {
  (yyval.gen) = malloc(sizeof(struct generation));
  (yyval.gen)->name = new_var();
  (yyval.gen)->t = FLOATING;
  asprintf(&((yyval.gen)->code),"%s = fadd double %s, %s\n", (yyval.gen)->name, double_to_hex_str(0.0), double_to_hex_str((yyvsp[(1) - (1)].f)));
  }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 125 "grammar.y"
    {
  (yyval.gen) = (yyvsp[(2) - (3)].gen);
  }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 128 "grammar.y"
    {
  //printf("%s\n",$1);
  //printf("Contenu hash table\n");
  //g_hash_table_foreach(hash_array[0], print_hash, NULL);
  (yyval.gen) = malloc(sizeof(struct generation));
  tmp = map_with_name(new_func((yyvsp[(1) - (3)].string)));
  //faire la vérif de type
  if(tmp == NULL){
    asprintf(&err, "Error: %s function not define", (yyvsp[(1) - (3)].string));
    yyerror(err);
  }    
  (yyval.gen)->name = tmp->val;
  (yyval.gen)->t = tmp->t;
  if(call_function((yyval.gen)->name, tmp->val, "", tmp->t) != NULL)
    asprintf(&((yyval.gen)->code), "%s",call_function((yyval.gen)->name, tmp->val, "", tmp->t));
  else 
    yyerror("Type non pris en compte");
  }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 146 "grammar.y"
    {
  //printf("%s\n", $1);
  //printf("Contenu hash table\n");
  //g_hash_table_foreach(hash_array[0], print_hash, NULL);
  (yyval.gen) = malloc(sizeof(struct generation));
  //printf("mapping %s\n", new_func($1));
  tmp = map_with_name(new_func((yyvsp[(1) - (4)].string)));
  //faire la vérif de type
  if(tmp == NULL){
    asprintf(&err, "Error: %s function not define", (yyvsp[(1) - (4)].string));
    yyerror(err);
  }
    
  (yyval.gen)->name = tmp->val;
  (yyval.gen)->t = tmp->t;
  if(call_function((yyval.gen)->name, tmp->val, (yyvsp[(3) - (4)].string), tmp->t)==NULL)
    asprintf(&((yyval.gen)->code), "%s", call_function((yyval.gen)->name, tmp->val, (yyvsp[(3) - (4)].string), tmp->t));
  else
    yyerror("Type non pris en compte");
  }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 170 "grammar.y"
    {
  (yyval.gen) = (yyvsp[(1) - (1)].gen);
 }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 173 "grammar.y"
    {
  //printf("%s\n", $1);
  if(op_1((yyvsp[(1) - (2)].string),ADD_OP) != NULL)
    (yyval.gen) = op_1((yyvsp[(1) - (2)].string),ADD_OP);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 180 "grammar.y"
    {
  //printf("%s\n", $1);
  if(op_1((yyvsp[(1) - (2)].string),SUB_OP) != NULL)
    (yyval.gen) = op_1((yyvsp[(1) - (2)].string),SUB_OP);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 191 "grammar.y"
    {
  if(get_type((yyvsp[(1) - (1)].gen)->name, (yyvsp[(1) - (1)].gen)->t)!=NULL)
    asprintf(&(yyval.string),"%s",get_type((yyvsp[(1) - (1)].gen)->name, (yyvsp[(1) - (1)].gen)->t));
  else
    yyerror("Type non pris en compte");
 }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 197 "grammar.y"
    {
  if(get_type((yyvsp[(3) - (3)].gen)->name, (yyvsp[(3) - (3)].gen)->t)!=NULL)
    asprintf(&(yyval.string),"%s, %s",(yyvsp[(1) - (3)].string), get_type((yyvsp[(3) - (3)].gen)->name, (yyvsp[(3) - (3)].gen)->t));
  else 
    yyerror("Type non pris en compte");
  }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 206 "grammar.y"
    {
  (yyval.gen) = (yyvsp[(1) - (1)].gen);
 }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 209 "grammar.y"
    {
  //printf("%s\n",$2);
  if(op_1((yyvsp[(2) - (2)].string), ADD_OP) != NULL)
    (yyval.gen) = op_1((yyvsp[(2) - (2)].string), ADD_OP);
  else 
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 216 "grammar.y"
    {
  //printf("%s\n",$2);
  if(op_1((yyvsp[(2) - (2)].string), SUB_OP) != NULL)
    (yyval.gen) = op_1((yyvsp[(2) - (2)].string), SUB_OP);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 223 "grammar.y"
    {
  (yyval.gen) = malloc(sizeof(struct generation));
  (yyval.gen)->name = new_var();
  (yyval.gen)->t = (yyvsp[(2) - (2)].gen)->t;
  switch((yyval.gen)->t){
  case INTEGER :
    asprintf(&((yyval.gen)->code),"%s%s = sub i32 0, %s\n",(yyvsp[(2) - (2)].gen)->code, (yyval.gen)->name, (yyvsp[(2) - (2)].gen)->name);
    break;
  case FLOATING:
    asprintf(&((yyval.gen)->code),"%s%s = fsub double %s, %s\n",(yyvsp[(2) - (2)].gen)->code, (yyval.gen)->name, double_to_hex_str(0.0), (yyvsp[(2) - (2)].gen)->name);
    break;
  default:
    yyerror("Impossible de rendre négatif, type incompatible");
  }
 }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 247 "grammar.y"
    {
  (yyval.gen) = (yyvsp[(1) - (1)].gen);
 }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 250 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), MUL_OP, 0) != NULL)
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), MUL_OP, 0);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles test");
  }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 256 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), DIV_OP, 0) != NULL)
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), DIV_OP, 0);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
  }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 262 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), REM_OP, 0) != NULL)
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), REM_OP, 0);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
 }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 272 "grammar.y"
    {
  (yyval.gen) = (yyvsp[(1) - (1)].gen);
 }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 275 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), ADD_OP, 0) != NULL)
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), ADD_OP, 0);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
  }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 281 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), SUB_OP, 0) != NULL)
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), SUB_OP, 0);
  else 
    yyerror("Operation non prise en compte, Type et operation non compatibles");
  }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 291 "grammar.y"
    {
  (yyval.gen) = (yyvsp[(1) - (1)].gen);
 }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 294 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), L_COMP, 1) != NULL)
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), L_COMP, 1);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles");
  }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 300 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), G_COMP, 1) != NULL)
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), G_COMP, 1);
  else
  yyerror("Operation non prise en compte, Type et operation non compatibles");
  }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 306 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), LE_COMP, 1) != NULL)
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), LE_COMP, 1);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles"); 
 }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 312 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), GE_COMP, 1) != NULL)
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), GE_COMP, 1);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles"); 
 }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 318 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), EQ_COMP, 1) != NULL)
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), EQ_COMP, 1);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles"); 
 }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 324 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), NE_COMP, 1) != NULL)
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), NE_COMP, 1);
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles"); 
 }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 334 "grammar.y"
    {
  if(operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), string_to_op_code((yyvsp[(2) - (3)].string)), 0) != NULL){
    (yyval.gen) = operation_expression((yyvsp[(1) - (3)].gen), (yyvsp[(3) - (3)].gen), string_to_op_code((yyvsp[(2) - (3)].string)), 0);
    //asprintf(&($$->code), "%s%s",$$->code,store_value($3->name, $1->name, $$->t)); 
  }
  else
    yyerror("Operation non prise en compte, Type et operation non compatibles"); 
 }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 342 "grammar.y"
    {
  (yyval.gen) = (yyvsp[(1) - (1)].gen);
  }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 349 "grammar.y"
    {
  (yyval.string) = "ass";
 }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 352 "grammar.y"
    {
  (yyval.string) = "mul";
  }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 355 "grammar.y"
    {
  (yyval.string) = "div";
  }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 358 "grammar.y"
    {
  (yyval.string) = "rem";
  }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 361 "grammar.y"
    {
  (yyval.string) = "shl";
  }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 364 "grammar.y"
    {
  (yyval.string) = "shr";
  }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 367 "grammar.y"
    {
  (yyval.string) = "add";
  }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 370 "grammar.y"
    {
  (yyval.string) = "sub";
  }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 377 "grammar.y"
    {
  int length_l = length_llist((yyvsp[(2) - (3)].list));
  
  int i = 0;
  struct expression *tmp;
  for(; i<length_l; i++){
    tmp = look_for((yyvsp[(2) - (3)].list), i); 
    tmp->t = string_to_type((yyvsp[(1) - (3)].string));
    tmp->level = level;
    if(g_hash_table_contains(hash_array[level], tmp->name))
      yyerror(&err, "Redéclaration de la variable %s", tmp->name);
    else
      g_hash_table_insert(hash_array[level], tmp->name, tmp);
  }
  
 }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 399 "grammar.y"
    {
  (yyval.list) = init_llist();
  add_llist((yyval.list), (yyvsp[(1) - (1)].exp));
 }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 404 "grammar.y"
    {
  (yyval.list) = (yyvsp[(1) - (3)].list);
  add_llist((yyval.list), (yyvsp[(3) - (3)].exp));
  }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 412 "grammar.y"
    {
  (yyval.string) = "void";
  last_type = VOID_T;
 }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 416 "grammar.y"
    {
  (yyval.string) = "int";
  last_type = INTEGER;
  }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 420 "grammar.y"
    {
  (yyval.string) = "double";
  last_type = FLOATING;
  }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 430 "grammar.y"
    {
  (yyval.exp) = (yyvsp[(1) - (4)].exp);
  init_function((yyval.exp), new_func((yyval.exp)->name), last_type, (yyvsp[(3) - (4)].list));
  if(!g_hash_table_contains(hash_array[level], new_func((yyvsp[(1) - (4)].exp)->name)))
    g_hash_table_insert(hash_array[level], new_func((yyvsp[(1) - (4)].exp)->name), (yyval.exp));
  //Sinon vérification de param
  int i = 0;
  for(; i < length_llist((yyvsp[(3) - (4)].list)); ++i){
    tmp = look_for((yyvsp[(3) - (4)].list), i);
    if(tmp->t != VOID_T){
      if(nb_occ((yyvsp[(3) - (4)].list), tmp->name) != 1){
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
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 453 "grammar.y"
    {
  if(!g_hash_table_contains(hash_array[level], new_func((yyvsp[(1) - (3)].exp)->name)))
    g_hash_table_insert(hash_array[level], new_func((yyvsp[(1) - (3)].exp)->name), (yyval.exp));
  //Sinon vérification de param
  (yyval.exp) = (yyvsp[(1) - (3)].exp);
  init_function((yyval.exp),new_func((yyval.exp)->name), last_type, NULL);
  }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 466 "grammar.y"
    {
  //printf("%s\n",$1);
  (yyval.exp) = create_non_init_exp((yyvsp[(1) - (1)].string));
 }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 470 "grammar.y"
    {
  (yyval.exp) = (yyvsp[(2) - (3)].exp);
  }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 473 "grammar.y"
    {
    (yyval.exp) = (yyvsp[(1) - (4)].exp);
    
    init_function((yyval.exp), new_func((yyval.exp)->name), last_type, (yyvsp[(3) - (4)].list));
    if(!g_hash_table_contains(hash_array[level], new_func((yyvsp[(1) - (4)].exp)->name)))
      g_hash_table_insert(hash_array[level], new_func((yyvsp[(1) - (4)].exp)->name), (yyval.exp));
    //Sinon vérification de param
    int i = 0;
    for(; i < length_llist((yyvsp[(3) - (4)].list)); ++i){
      tmp = look_for((yyvsp[(3) - (4)].list), i);
      if(tmp->t != VOID_T){
	if(nb_occ((yyvsp[(3) - (4)].list), tmp->name) != 1)
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
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 495 "grammar.y"
    {
  (yyval.exp) = (yyvsp[(1) - (3)].exp);
  init_function((yyval.exp), new_func((yyval.exp)->name), last_type, NULL);
  if(!g_hash_table_contains(hash_array[level], new_func((yyvsp[(1) - (3)].exp)->name)))
    g_hash_table_insert(hash_array[level], new_func((yyvsp[(1) - (3)].exp)->name), (yyval.exp));
  //Sinon vérification de param
  }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 520 "grammar.y"
    {
  (yyval.list) = init_llist();
  add_llist((yyval.list), (yyvsp[(1) - (1)].exp));
 }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 524 "grammar.y"
    {
  (yyval.list) = (yyvsp[(1) - (3)].list);
  add_llist((yyval.list), (yyvsp[(3) - (3)].exp));
  }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 532 "grammar.y"
    {
  (yyval.exp) = (yyvsp[(2) - (2)].exp);
  init_exp((yyval.exp), new_param((yyval.exp)->name), string_to_type((yyvsp[(1) - (2)].string)), level);
  //printf("Dec : %s, %d, %s\n", $2->val, $2->t, $2->name);
 }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 541 "grammar.y"
    {
  (yyval.string) = (yyvsp[(1) - (1)].string);
 }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 544 "grammar.y"
    {
  (yyval.string) = (yyvsp[(1) - (1)].string);
  }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 547 "grammar.y"
    {
  (yyval.string) = (yyvsp[(1) - (1)].string);
  }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 550 "grammar.y"
    {
  (yyval.string) = (yyvsp[(1) - (1)].string);
  }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 553 "grammar.y"
    {
  (yyval.string) = (yyvsp[(1) - (1)].string);
  }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 559 "grammar.y"
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
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 576 "grammar.y"
    {
  g_hash_table_foreach(hash_array[level], value, NULL);
  
  level--;
 }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 585 "grammar.y"
    {
  (yyval.string) = NULL;
  
 }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 589 "grammar.y"
    {
  (yyval.string) = (yyvsp[(2) - (3)].string);
 }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 592 "grammar.y"
    {
  (yyval.string) = (yyvsp[(2) - (3)].string);
 }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 599 "grammar.y"
    {
  (yyval.string) = (yyvsp[(1) - (1)].string);
 }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 602 "grammar.y"
    {
  asprintf(&(yyval.string),"%s%s", (yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string));
 }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 609 "grammar.y"
    {
  (yyval.string) = (yyvsp[(1) - (1)].string);
 }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 612 "grammar.y"
    {
  asprintf(&(yyval.string), "%s%s", (yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string));
 }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 619 "grammar.y"
    {
  (yyval.string) = (yyvsp[(1) - (1)].string);
 }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 622 "grammar.y"
    {
  asprintf(&(yyval.string),"%s%s", (yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string));
 }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 629 "grammar.y"
    {
  (yyval.string) = (yyvsp[(1) - (1)].string);
 }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 632 "grammar.y"
    {
  asprintf(&(yyval.string),"%s%s", (yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string));
 }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 640 "grammar.y"
    {
  (yyval.string) = NULL;
}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 643 "grammar.y"
    {
  (yyval.string) = (yyvsp[(1) - (2)].gen)->code;
  }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 650 "grammar.y"
    {
  (yyval.string) = if_expression((yyvsp[(3) - (5)].gen)->name, (yyvsp[(3) - (5)].gen)->code, (yyvsp[(5) - (5)].string), NULL);
 }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 653 "grammar.y"
    {
  (yyval.string) = if_expression((yyvsp[(3) - (7)].gen)->name, (yyvsp[(3) - (7)].gen)->code, (yyvsp[(5) - (7)].string), (yyvsp[(7) - (7)].string));
  }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 656 "grammar.y"
    {
  (yyval.string) = for_expression((yyvsp[(3) - (9)].gen)->code, (yyvsp[(7) - (9)].gen)->code, (yyvsp[(5) - (9)].gen), (yyvsp[(9) - (9)].string));
  }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 659 "grammar.y"
    {
  (yyval.string) = for_expression((yyvsp[(3) - (8)].gen)->code, NULL, (yyvsp[(5) - (8)].gen), (yyvsp[(8) - (8)].string));
  }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 662 "grammar.y"
    {
  (yyval.string) = for_expression((yyvsp[(3) - (8)].gen)->code, (yyvsp[(6) - (8)].gen)->code, NULL, (yyvsp[(8) - (8)].string));
  }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 665 "grammar.y"
    {
  (yyval.string) = for_expression((yyvsp[(3) - (7)].gen)->code, NULL, NULL, (yyvsp[(7) - (7)].string));
  }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 668 "grammar.y"
    {
  (yyval.string) = for_expression(NULL, (yyvsp[(6) - (8)].gen)->code, (yyvsp[(4) - (8)].gen), (yyvsp[(8) - (8)].string));
  }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 671 "grammar.y"
    {
  (yyval.string) = for_expression(NULL, NULL, (yyvsp[(4) - (7)].gen), (yyvsp[(7) - (7)].string));
  }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 674 "grammar.y"
    {
  (yyval.string) = for_expression(NULL, (yyvsp[(5) - (7)].gen)->code, NULL, (yyvsp[(7) - (7)].string));
  }
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 677 "grammar.y"
    {
  (yyval.string) = for_expression(NULL, NULL, NULL, (yyvsp[(6) - (6)].string));
  }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 684 "grammar.y"
    {
  (yyval.string) = for_expression(NULL, (yyvsp[(3) - (5)].gen)->code, NULL, (yyvsp[(5) - (5)].string));
 }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 687 "grammar.y"
    {
  asprintf(&(yyval.string),"%s%s", (yyvsp[(2) - (7)].string),for_expression(NULL, (yyvsp[(5) - (7)].gen)->code, NULL, (yyvsp[(2) - (7)].string)));
 }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 694 "grammar.y"
    {
  if(return_expression(VOID_T, NULL) != NULL)
    (yyval.string) = return_expression(VOID_T, NULL);
  else
    yyerror("Type non pris en compte");
 }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 700 "grammar.y"
    {
  if(return_expression((yyvsp[(2) - (3)].gen)->t, (yyvsp[(2) - (3)].gen)->name) != NULL)
    (yyval.string) = return_expression((yyvsp[(2) - (3)].gen)->t, (yyvsp[(2) - (3)].gen)->name);
  else
    yyerror("Type non pris en compte");
 }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 710 "grammar.y"
    {
  (yyval.string) = (yyvsp[(1) - (1)].string);
  code = (yyval.string);
 }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 714 "grammar.y"
    {
  asprintf(&(yyval.string), "%s%s", (yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string));
  code = (yyval.string);
 }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 722 "grammar.y"
    {
  (yyval.string) = (yyvsp[(1) - (1)].string);
 }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 725 "grammar.y"
    {
  (yyval.string) = (yyvsp[(1) - (1)].string);
  }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 732 "grammar.y"
    {
  (yyvsp[(2) - (3)].exp)->t = string_to_type((yyvsp[(1) - (3)].string));
  (yyvsp[(2) - (3)].exp)->level = level;
  switch((yyvsp[(2) - (3)].exp)->t){
  case INTEGER:
    if(parameter_to_string((yyvsp[(2) - (3)].exp)) != NULL)
      asprintf(&(yyval.string),"define i32 %s(%s){\n", new_func((yyvsp[(2) - (3)].exp)->name), parameter_to_string((yyvsp[(2) - (3)].exp)));
    else
      yyerror("Type non pris en compte");
    break;
  case FLOATING:
    if(parameter_to_string((yyvsp[(2) - (3)].exp)) != NULL)
      asprintf(&(yyval.string),"define double %s(%s){\n", new_func((yyvsp[(2) - (3)].exp)->name), parameter_to_string((yyvsp[(2) - (3)].exp)));
    else
      yyerror("Type non pris en compte");
    break;
  case VOID_T:
    if(parameter_to_string((yyvsp[(2) - (3)].exp)) != NULL)
      asprintf(&(yyval.string),"define void %s(%s){\n", new_func((yyvsp[(2) - (3)].exp)->name), parameter_to_string((yyvsp[(2) - (3)].exp)));
    else
      yyerror("Type non pris en compte");
    break;
  default:
    yyerror("Type booléen ou non défini ne peuvent pas etre le type de retour d'une fonction");
    //printf("Error\n");
  }

  
  asprintf(&(yyval.string),"%s%s",(yyval.string), (yyvsp[(3) - (3)].string));  
  asprintf(&(yyval.string),"%s}\n",(yyval.string));


  
 }
    break;


/* Line 1792 of yacc.c  */
#line 2655 "grammar.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 768 "grammar.y"

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
