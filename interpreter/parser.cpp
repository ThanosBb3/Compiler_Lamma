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
#line 1 "parser.y" /* yacc.c:339  */

    #include <cstdio>
    #include <cstdlib>
    #include "AST_main.hpp"
    #include "type.hpp"
    #include "ast.hpp"
    #include "lexer.hpp"

    SymbolTable st;
    std::unordered_map<std::string, SymbolEntry*> globals;

#line 78 "parser.cpp" /* yacc.c:339  */

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
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_and = 258,
    T_array = 259,
    T_begin = 260,
    T_bool = 261,
    T_char = 262,
    T_delete = 263,
    T_dim = 264,
    T_do = 265,
    T_done = 266,
    T_downto = 267,
    T_else = 268,
    T_end = 269,
    T_false = 270,
    T_float = 271,
    T_for = 272,
    T_if = 273,
    T_in = 274,
    T_int = 275,
    T_let = 276,
    T_match = 277,
    T_mod = 278,
    T_mutable = 279,
    T_new = 280,
    T_not = 281,
    T_of = 282,
    T_rec = 283,
    T_ref = 284,
    T_then = 285,
    T_to = 286,
    T_true = 287,
    T_type = 288,
    T_unit = 289,
    T_while = 290,
    T_with = 291,
    T_arrow = 292,
    T_fplus = 293,
    T_fminus = 294,
    T_fmul = 295,
    T_fdiv = 296,
    T_land = 297,
    T_power = 298,
    T_lor = 299,
    T_diff = 300,
    T_leq = 301,
    T_geq = 302,
    T_eq = 303,
    T_neq = 304,
    T_def = 305,
    UNOP = 306,
    T_Id = 307,
    T_id = 308,
    T_integer = 309,
    T_real = 310,
    T_character = 311,
    T_string = 312
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 89 "parser.y" /* yacc.c:355  */

    int num;
    double flo;
    char *op;
    char *str;
    char *ch;
    char *id;

    Block *block;
    Let *let;
    Deflist *dlist;
    Def *def;
    Parlist *pplist;
    Exprlist *elist;
    Mytype *mytype;
    Tdeflist *ttlist;
    Tdef *tdef;
    Constrlist *cclist;
    Constr *constr;
    Typelist *typelist;
    Par *par;
    Type *type;
    Expr *expr;
    Valexprlist *vlist;
    Valexpr *valexpr;
    Clauselist *clauselist;
    Clause *clause;
    Pattern *pattern;


#line 207 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 224 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   977

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  230

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,     2,     2,     2,     2,     2,
      72,    73,    57,    55,    70,    56,     2,    58,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    69,    51,
      53,    52,    54,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    71,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    59,    63,    64,    65,
      66,    67,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   147,   147,   155,   156,   157,   164,   165,   169,   170,
     174,   175,   176,   177,   178,   179,   183,   184,   188,   189,
     193,   197,   198,   202,   206,   207,   211,   212,   216,   217,
     221,   222,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   241,   242,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   291,   292,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   311,   312,   317,   321,   322,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   340,   341,   345,
     346
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"and\"", "\"array\"", "\"begin\"",
  "\"bool\"", "\"char\"", "\"delete\"", "\"dim\"", "\"do\"", "\"done\"",
  "\"downto\"", "\"else\"", "\"end\"", "\"false\"", "\"float\"", "\"for\"",
  "\"if\"", "\"in\"", "\"int\"", "\"let\"", "\"match\"", "\"mod\"",
  "\"mutable\"", "\"new\"", "\"not\"", "\"of\"", "\"rec\"", "\"ref\"",
  "\"then\"", "\"to\"", "\"true\"", "\"type\"", "\"unit\"", "\"while\"",
  "\"with\"", "\"->\"", "\"+.\"", "\"-.\"", "\"*.\"", "\"/.\"", "\"&&\"",
  "\"**\"", "\"||\"", "\"<>\"", "\"<=\"", "\">=\"", "\"==\"", "\"!=\"",
  "\":=\"", "';'", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "UNOP",
  "'!'", "'['", "']'", "T_Id", "T_id", "T_integer", "T_real",
  "T_character", "T_string", "':'", "','", "'|'", "'('", "')'", "$accept",
  "program", "deflist", "letdef", "muldef", "def", "mulpar", "mulexpr",
  "typedef", "multdef", "tdef", "mulconstr", "constr", "multype", "par",
  "type", "muldim", "expr", "mulexpr2", "valexpr", "mulclause", "clause",
  "pattern", "pattern1", "pattern2", "mulpat", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    59,    61,    60,    62,    43,    45,    42,    47,   306,
      33,    91,    93,   307,   308,   309,   310,   311,   312,    58,
      44,   124,    40,    41
};
# endif

#define YYPACT_NINF -63

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -63,    27,     5,   -63,   -21,   -62,   -63,   -63,   -36,   -19,
     -63,    31,   -63,   -10,    41,   -63,   -28,    31,    86,   -19,
     -33,   -62,   187,   125,   187,   -63,   125,   -15,   -63,   -63,
      32,    -5,   -63,   -63,   187,   187,   -56,   -63,     4,   187,
     187,   125,   187,   -63,   187,   187,   187,   187,   187,   213,
     213,   200,   -63,   -63,   -63,   -63,   101,    48,     3,   785,
     -63,   -14,   -63,   -63,   -63,   -63,   -63,   -63,   125,    19,
     785,   -12,     1,   125,   -33,   677,   -63,   -63,    35,    50,
     713,   749,    19,   -63,   297,   -63,   -63,   -63,   -63,   -63,
      39,   -63,   213,   -63,   187,   213,   -63,   248,   187,    34,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   125,    56,   -23,   -63,   125,   187,   125,
     125,    19,   -63,   -63,   -63,   187,   187,    -3,   187,   -63,
      55,   -63,   785,   125,   785,    72,    14,    14,    72,    72,
     898,    72,   877,   919,   919,   919,   919,   919,   821,   849,
     919,   919,   919,    14,    14,    72,    72,    95,   -63,    58,
     -63,    19,   785,     2,    19,   586,   632,   -63,   -63,    68,
      69,    81,    83,   -63,   -63,   -63,   -63,   -63,    -3,   -13,
     -63,   100,   -63,   443,   -63,    19,   122,    94,   -63,   187,
     187,   187,   -63,   -63,   -63,   -63,   115,    79,   -63,    -3,
     187,   -63,   125,   -63,   346,   395,   785,   -63,   -63,   -63,
     -63,   -63,   785,    95,   187,   187,   491,   539,   -63,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     4,     5,     0,     0,
      16,     6,     8,     0,    20,    21,    12,     7,     0,     0,
       0,     0,     0,     0,     0,    30,     0,     0,    17,     9,
      26,    23,    24,    22,     0,     0,     0,    94,     0,     0,
       0,     0,     0,    93,     0,     0,     0,     0,     0,     0,
      98,    97,    89,    90,    91,    92,     0,     0,     0,    18,
      86,     0,    35,    34,    36,    33,    32,    37,     0,    13,
      10,     0,     0,     0,     0,     0,    78,    75,     0,     0,
       0,     0,    77,    71,     0,    69,    70,    67,    68,    98,
      97,   100,    73,    87,     0,    72,    95,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,     0,
      27,    28,    25,    79,    76,     0,     0,     0,     0,    88,
       0,    96,    74,     0,    19,    53,    47,    48,    50,    52,
      63,    54,    64,    56,    59,    60,    61,    62,    66,    65,
      55,    57,    58,    45,    46,    49,    51,    41,    43,     0,
      38,    40,    11,     0,    29,     0,    80,   114,   113,     0,
       0,     0,     0,   119,   115,   106,   109,   112,     0,     0,
     101,     0,   104,     0,    99,    15,     0,     0,    31,     0,
       0,     0,   110,   111,   107,   108,   105,     0,    85,     0,
       0,    82,     0,    44,     0,     0,    81,   118,   117,   120,
     116,   102,   103,    42,     0,     0,     0,     0,    84,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,   -63,   158,   153,   144,   -63,    78,   -63,   -63,
     162,   -63,   110,   -63,   -63,   -22,   -63,   -24,   140,    93,
     -63,   -16,     6,    -8,   -63,   -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    57,    11,    12,    18,    58,     7,    14,
      15,    31,    32,   130,    28,    69,   169,    59,    92,    60,
     189,   190,   191,   192,   219,   206
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,   208,    13,     8,    71,     8,   126,     9,    77,    78,
      75,    76,   177,   123,   127,    80,    81,   126,    83,    82,
      84,    85,    86,    87,    88,   127,     4,     3,    16,   178,
      30,   126,    97,    22,    19,   179,   180,   101,     5,   127,
     128,    23,    20,    10,    21,    10,   125,   124,   126,    72,
     170,   131,   181,   182,   104,   105,   127,   107,   209,    73,
     183,   184,   185,   186,   187,    99,    74,    98,    79,   188,
     129,   121,   122,   100,   142,   198,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   134,
      94,   167,   135,   143,   172,   171,    34,   173,   174,    35,
      36,   175,   176,   168,   193,   107,    37,   194,    38,    39,
     196,   195,     4,    40,   126,   100,    41,    42,   197,    61,
     177,    62,    63,    43,   202,   203,    44,   210,    24,    45,
      46,    64,    91,    93,    93,    65,   204,   178,   205,   212,
      25,   213,   220,   179,   180,    26,    47,    48,    27,    66,
       6,    49,    17,    29,    50,    51,    52,    53,    54,    55,
     181,   182,   140,    56,    96,   214,   215,   216,   217,   184,
     185,   186,   187,    33,   132,   139,   222,   188,   139,    67,
     223,    95,    34,   221,   207,    35,    36,    68,   218,     0,
     226,   227,    37,     0,    38,    39,     0,     0,     4,    40,
       0,     0,    41,    42,     0,    37,     0,     0,     0,    43,
       0,     0,    44,     0,     0,    45,    46,     0,    37,     0,
       0,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,    48,     0,    43,     0,    49,     0,     0,
      50,    51,    52,    53,    54,    55,     0,     0,     0,    56,
      49,    94,     0,    89,    90,    52,    53,    54,    55,     0,
       0,   101,    56,    49,     0,     0,    89,    90,    52,    53,
      54,    55,     0,     0,     0,    56,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   211,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   228,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     229,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   199,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
       0,     0,     0,     0,     0,     0,     0,   200,     0,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   133,     0,     0,     0,     0,     0,     0,     0,     0,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   101,     0,     0,     0,
       0,     0,     0,   136,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,   101,   116,   117,   118,   119,   120,   121,   122,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     101,   116,   117,   118,   119,   120,   121,   122,     0,     0,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   101,   109,   110,   111,   112,   113,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   102,   103,   104,   105,
       0,   107,   101,   109,   110,   111,   112,   113,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   102,   103,   104,
     105,     0,   107,     0,    -1,    -1,    -1,    -1,    -1,     0,
       0,    -1,    -1,    -1,   119,   120,   121,   122
};

static const yytype_int16 yycheck[] =
{
      24,    14,    64,    24,    26,    24,    29,    28,    64,    65,
      34,    35,    15,    27,    37,    39,    40,    29,    42,    41,
      44,    45,    46,    47,    48,    37,    21,     0,    64,    32,
      63,    29,    56,    61,     3,    38,    39,    23,    33,    37,
      52,    69,    52,    64,     3,    64,    68,    61,    29,    64,
      73,    73,    55,    56,    40,    41,    37,    43,    71,    27,
      63,    64,    65,    66,    67,    62,    71,    19,    64,    72,
      69,    57,    58,    70,    98,    73,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    64,
      61,   123,    52,    69,   128,   127,     5,   129,   130,     8,
       9,   135,   136,    57,   138,    43,    15,    62,    17,    18,
      62,   143,    21,    22,    29,    70,    25,    26,    70,     4,
      15,     6,     7,    32,    66,    66,    35,    37,    52,    38,
      39,    16,    49,    50,    51,    20,    65,    32,    65,    27,
      64,    57,    73,    38,    39,    69,    55,    56,    72,    34,
       2,    60,     9,    19,    63,    64,    65,    66,    67,    68,
      55,    56,    94,    72,    73,   199,   200,   201,    63,    64,
      65,    66,    67,    21,    74,    92,   210,    72,    95,    64,
     212,    51,     5,   209,   188,     8,     9,    72,   206,    -1,
     224,   225,    15,    -1,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    25,    26,    -1,    15,    -1,    -1,    -1,    32,
      -1,    -1,    35,    -1,    -1,    38,    39,    -1,    15,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    -1,    32,    -1,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    -1,    -1,    -1,    72,
      60,    61,    -1,    63,    64,    65,    66,    67,    68,    -1,
      -1,    23,    72,    60,    -1,    -1,    63,    64,    65,    66,
      67,    68,    -1,    -1,    -1,    72,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    23,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      23,    52,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    23,    45,    46,    47,    48,    49,    -1,    -1,    52,
      53,    54,    55,    56,    57,    58,    38,    39,    40,    41,
      -1,    43,    23,    45,    46,    47,    48,    49,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    38,    39,    40,
      41,    -1,    43,    -1,    45,    46,    47,    48,    49,    -1,
      -1,    52,    53,    54,    55,    56,    57,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,    76,     0,    21,    33,    77,    82,    24,    28,
      64,    78,    79,    64,    83,    84,    64,    78,    80,     3,
      52,     3,    61,    69,    52,    64,    69,    72,    88,    79,
      63,    85,    86,    84,     5,     8,     9,    15,    17,    18,
      22,    25,    26,    32,    35,    38,    39,    55,    56,    60,
      63,    64,    65,    66,    67,    68,    72,    77,    81,    91,
      93,     4,     6,     7,    16,    20,    34,    64,    72,    89,
      91,    89,    64,    27,    71,    91,    91,    64,    65,    64,
      91,    91,    89,    91,    91,    91,    91,    91,    91,    63,
      64,    93,    92,    93,    61,    92,    73,    91,    19,    62,
      70,    23,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    27,    61,    89,    29,    37,    52,    69,
      87,    89,    86,    14,    64,    52,    30,    36,    10,    93,
      81,    73,    91,    69,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    89,    57,    90,
      73,    89,    91,    89,    89,    91,    91,    15,    32,    38,
      39,    55,    56,    63,    64,    65,    66,    67,    72,    94,
      95,    96,    97,    91,    62,    89,    62,    70,    73,    12,
      31,    13,    66,    66,    65,    65,    99,    96,    14,    71,
      37,    11,    27,    57,    91,    91,    91,    63,    97,    98,
      73,    95,    91,    89,    10,    10,    91,    91,    11,    11
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    76,    77,    77,    78,    78,
      79,    79,    79,    79,    79,    79,    80,    80,    81,    81,
      82,    83,    83,    84,    85,    85,    86,    86,    87,    87,
      88,    88,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    90,    90,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    94,    94,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    98,    98,    99,
      99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     3,     1,     3,
       4,     6,     2,     4,     5,     7,     0,     2,     1,     3,
       2,     1,     3,     3,     1,     3,     1,     3,     1,     2,
       1,     5,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     3,     6,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     2,     2,     3,     2,     3,     2,     2,     3,
       4,     6,     5,     9,     9,     5,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     1,     4,
       2,     1,     3,     3,     1,     2,     1,     2,     2,     1,
       2,     2,     1,     1,     1,     1,     3,     1,     1,     0,
       2
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
#line 147 "parser.y" /* yacc.c:1646  */
    {
    (yyvsp[0].block)->sem();
    std::cout << "AST: " << *(yyvsp[0].block) << std::endl;
    //$1->run();
  }
#line 1619 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.block) = new Block(); }
#line 1625 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].block)->append((yyvsp[0].let)); (yyval.block) = (yyvsp[-1].block); }
#line 1631 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].block)->append((yyvsp[0].mytype)); (yyval.block) = (yyvsp[-1].block); }
#line 1637 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.let) = new Let(false,(yyvsp[0].dlist)); }
#line 1643 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.let) = new Let(true,(yyvsp[0].dlist)); }
#line 1649 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.dlist) = new Deflist(); (yyval.dlist)->append((yyvsp[0].def)); }
#line 1655 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].dlist)->append((yyvsp[0].def)); (yyval.dlist) = (yyvsp[-2].dlist); }
#line 1661 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.def) = new Def((yyvsp[-3].id), (yyvsp[-2].pplist), (yyvsp[0].expr)); }
#line 1667 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.def) = new Def((yyvsp[-5].id), (yyvsp[-4].pplist), (yyvsp[0].expr), (yyvsp[-2].type)); }
#line 1673 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.def) = new Def((yyvsp[0].id)); }
#line 1679 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.def) = new Def((yyvsp[-2].id), nullptr, nullptr, (yyvsp[0].type)); }
#line 1685 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.def) = new Def((yyvsp[-3].id), nullptr, nullptr, nullptr, (yyvsp[-1].elist)); }
#line 1691 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.def) = new Def((yyvsp[-5].id), nullptr, nullptr, (yyvsp[0].type), (yyvsp[-3].elist)); }
#line 1697 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.pplist) = new Parlist(); }
#line 1703 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].pplist)->append((yyvsp[0].par)); (yyval.pplist) = (yyvsp[-1].pplist); }
#line 1709 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.elist) = new Exprlist(); (yyval.elist)->append((yyvsp[0].expr)); }
#line 1715 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].elist)->append((yyvsp[0].expr)); (yyval.elist) = (yyvsp[-2].elist); }
#line 1721 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.mytype) = new Mytype((yyvsp[0].ttlist)); }
#line 1727 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.ttlist) = new Tdeflist(); (yyval.ttlist)->append((yyvsp[0].tdef)); }
#line 1733 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 198 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].ttlist)->append((yyvsp[0].tdef)); (yyval.ttlist) = (yyvsp[-2].ttlist); }
#line 1739 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.tdef) = new Tdef((yyvsp[-2].id), (yyvsp[0].cclist)); }
#line 1745 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.cclist) = new Constrlist(); (yyval.cclist)->append((yyvsp[0].constr)); }
#line 1751 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].cclist)->append((yyvsp[0].constr)); (yyval.cclist) = (yyvsp[-2].cclist); }
#line 1757 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.constr) = new Constr((yyvsp[0].id)); }
#line 1763 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.constr) = new Constr((yyvsp[-2].id), (yyvsp[0].typelist)); }
#line 1769 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 216 "parser.y" /* yacc.c:1646  */
    { (yyval.typelist) = new Typelist(); (yyval.typelist)->append((yyvsp[0].type)); }
#line 1775 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].typelist)->append((yyvsp[0].type)); (yyval.typelist) = (yyvsp[-1].typelist); }
#line 1781 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.par) = new Par((yyvsp[0].id)); }
#line 1787 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.par) = new Par((yyvsp[-3].id), (yyvsp[-1].type)); }
#line 1793 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Unit(); }
#line 1799 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Integer(); }
#line 1805 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 228 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Char(); }
#line 1811 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 229 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Boolean(); }
#line 1817 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Real(); }
#line 1823 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Typeid((yyvsp[0].id)); }
#line 1829 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 232 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 1835 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Tref((yyvsp[-1].type)); }
#line 1841 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Tfun((yyvsp[-2].type), (yyvsp[0].type)); }
#line 1847 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 235 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Array((yyvsp[0].type)); }
#line 1853 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Array((yyvsp[0].type), (yyvsp[-3].num)); }
#line 1859 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 241 "parser.y" /* yacc.c:1646  */
    { (yyval.num) = 1; }
#line 1865 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 242 "parser.y" /* yacc.c:1646  */
    { (yyval.num) = (yyvsp[-2].num) + 1; }
#line 1871 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 246 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1877 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 247 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1883 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1889 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1895 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 250 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1901 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 251 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1907 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 252 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1913 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 253 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1919 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 254 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1925 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 255 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1931 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 256 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1937 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 257 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1943 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 258 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1949 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 259 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1955 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1961 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1967 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 262 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1973 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 263 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1979 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1985 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1991 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 266 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 1997 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 267 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Binop((yyvsp[-2].expr), (yyvsp[-1].op), (yyvsp[0].expr)); }
#line 2003 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 268 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Unop((yyvsp[-1].op), (yyvsp[0].expr)); }
#line 2009 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 269 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Unop((yyvsp[-1].op), (yyvsp[0].expr)); }
#line 2015 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 270 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Unop((yyvsp[-1].op), (yyvsp[0].expr)); }
#line 2021 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 271 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Unop((yyvsp[-1].op), (yyvsp[0].expr)); }
#line 2027 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 272 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Unop((yyvsp[-1].op), (yyvsp[0].expr)); }
#line 2033 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 273 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Call((yyvsp[-1].id), (yyvsp[0].vlist)); }
#line 2039 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Call((yyvsp[-1].id), (yyvsp[0].vlist)); }
#line 2045 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Letin((yyvsp[-2].let), (yyvsp[0].expr)); }
#line 2051 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 276 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dim((yyvsp[0].id)); }
#line 2057 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 277 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Dim((yyvsp[0].id), (yyvsp[-1].num)); }
#line 2063 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 278 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new New((yyvsp[0].type)); }
#line 2069 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 279 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Delete((yyvsp[0].expr)); }
#line 2075 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 280 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 2081 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 281 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new If((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2087 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 282 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new If((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2093 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 283 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new While((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 2099 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 284 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For(false, (yyvsp[-7].id), (yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 2105 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 285 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new For(true, (yyvsp[-7].id), (yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 2111 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Match((yyvsp[-3].expr), (yyvsp[-1].clauselist)); }
#line 2117 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 287 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].valexpr); }
#line 2123 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 291 "parser.y" /* yacc.c:1646  */
    { (yyval.vlist) = new Valexprlist(); (yyval.vlist)->append((yyvsp[0].valexpr)); }
#line 2129 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 292 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].vlist)->append((yyvsp[0].valexpr)); (yyval.vlist) = (yyvsp[-1].vlist); }
#line 2135 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 296 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Constint((yyvsp[0].num), false); }
#line 2141 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 297 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Constreal((yyvsp[0].flo), false); }
#line 2147 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 298 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Constchar((yyvsp[0].ch)); }
#line 2153 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 299 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Conststr((yyvsp[0].str)); }
#line 2159 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 300 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Constbool(1); }
#line 2165 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 301 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Constbool(0); }
#line 2171 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 302 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Constunit(); }
#line 2177 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 303 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new BrackExp((yyvsp[-1].expr)); }
#line 2183 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 304 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Id(false, (yyvsp[0].id)); }
#line 2189 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 305 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Id(true, (yyvsp[0].id)); }
#line 2195 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Arrayitem((yyvsp[-3].id), (yyvsp[-1].elist)); }
#line 2201 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 307 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Deref((yyvsp[0].valexpr)); }
#line 2207 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 311 "parser.y" /* yacc.c:1646  */
    { (yyval.clauselist) = new Clauselist(); (yyval.clauselist)->append((yyvsp[0].clause)); }
#line 2213 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 312 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].clauselist)->append((yyvsp[0].clause)); (yyval.clauselist) = (yyvsp[-2].clauselist); }
#line 2219 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 317 "parser.y" /* yacc.c:1646  */
    { (yyval.clause) = new Clause((yyvsp[-2].pattern), (yyvsp[0].expr)); }
#line 2225 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 321 "parser.y" /* yacc.c:1646  */
    { (yyval.pattern) = new Pattern((yyvsp[0].valexpr), nullptr, nullptr); }
#line 2231 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 322 "parser.y" /* yacc.c:1646  */
    { (yyval.pattern) = new Pattern(nullptr, (yyvsp[-1].id), (yyvsp[0].vlist)); }
#line 2237 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 326 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Constint((yyvsp[0].num), false); }
#line 2243 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 327 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Constint((yyvsp[0].num), false); }
#line 2249 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 328 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Constint((yyvsp[0].num), true); }
#line 2255 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 329 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Constreal((yyvsp[0].flo), false); }
#line 2261 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 330 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Constreal((yyvsp[0].flo), false); }
#line 2267 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 331 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Constreal((yyvsp[0].flo), true); }
#line 2273 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 332 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Constchar((yyvsp[0].ch)); }
#line 2279 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 333 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Constbool(1); }
#line 2285 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 334 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Constbool(0); }
#line 2291 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 335 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Id(false, (yyvsp[0].id)); }
#line 2297 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 336 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new BrackPat((yyvsp[-1].pattern)); }
#line 2303 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 340 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = (yyvsp[0].valexpr);}
#line 2309 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 341 "parser.y" /* yacc.c:1646  */
    { (yyval.valexpr) = new Id(true, (yyvsp[0].id)); }
#line 2315 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 345 "parser.y" /* yacc.c:1646  */
    { (yyval.vlist) = new Valexprlist(); }
#line 2321 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 346 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].vlist)->append((yyvsp[0].valexpr)); (yyval.vlist) = (yyvsp[-1].vlist); }
#line 2327 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2331 "parser.cpp" /* yacc.c:1646  */
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
#line 350 "parser.y" /* yacc.c:1906  */


void yyerror(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

int main() {
    int result = yyparse();
    if (result == 0) printf("Success.\n");
    return result;
}
