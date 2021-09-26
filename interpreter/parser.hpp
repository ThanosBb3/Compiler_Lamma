/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 89 "parser.y" /* yacc.c:1909  */

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


#line 143 "parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
