%{
    #include <cstdio>
    #include <cstdlib>
    #include "lexer.hpp"
%}
    
%token T_and "and"
%token T_array "array"
%token T_begin "begin"
%token T_bool "bool"
%token T_char "char"
%token T_delete "delete"
%token T_dim "dim"
%token T_do "do"
%token T_done "done"
%token T_downto "downto"
%token T_else "else"
%token T_end "end"
%token T_false "false"
%token T_float "float"
%token T_for "for"
%token T_if "if"
%token T_in "in"
%token T_int "int"
%token T_let "let"
%token T_match "match"
%token T_mod "mod"
%token T_mutable "mutable"
%token T_new "new"
%token T_not "not"
%token T_of "of"
%token T_rec "rec"
%token T_ref "ref"
%token T_then "then"
%token T_to "to"
%token T_true "true"
%token T_type "type"
%token T_unit "unit"
%token T_while "while"
%token T_with "with"
%token T_arrow "->"
%token T_fplus "+."
%token T_fminus "-."
%token T_fmul "*."
%token T_fdiv "/."
%token T_land "&&"
%token T_power "**"
%token T_lor "||"
%token T_diff "<>"
%token T_leq "<="
%token T_geq ">="
%token T_eq "=="
%token T_neq "!="
%token T_def ":="


%nonassoc "in"
%left ';'
%nonassoc ":="
%left "||"
%left "&&"
%nonassoc '=' "<>" '<' '>' "<=" ">=" "==" "!=" 
%left '+' '-' "+." "-."
%left '*' '/' "*." "/." "mod"
%right "**"
%nonassoc UNOP "not" "delete"
%nonassoc '!'
%nonassoc '[' ']'
%nonassoc "new"



%token T_Id 
%token T_id 
%token T_integer
%token T_real 
%token T_character 
%token T_string 


%%

program:
    /* nothing */
|   program letdef 
|   program typedef
;

letdef:
    "let" def muldef       
|   "let" "rec" def muldef
;

muldef:
    /* nothing */
|   muldef "and" def
;

def:
    T_id mulpar '=' expr1
|   T_id mulpar ':' type '=' expr1
|   "mutable" T_id
|   "mutable" T_id ':' type
|   "mutable" T_id '[' expr1 mulexpr ']'
|   "mutable" T_id '[' expr1 mulexpr ']' ':' type
;

mulpar:
    /* nothing */
|   mulpar par
;

mulexpr:
    /* nothing */
|   mulexpr ',' expr1
;

typedef:
    "type" tdef multdef
;

multdef:
    /* nothing */
|   multdef "and" tdef
;

tdef:
    T_id '=' constr mulconstr
;

mulconstr:
    /* nothing */
|   mulconstr '|' constr
;

constr:
    T_Id
|   T_Id "of" type multype
;

multype:
    /* nothing */
|   multype type
;

par:
    T_id
|   '(' T_id ':' type ')'
;

type:
    type1
|   type "->" type1
;

type1:
    type2
|   type1 "ref"
;

type2:
    "unit"
|   "int"
|   "char"
|   "bool"
|   "float"
|   T_id
|   '(' type ')'
|   "array" "of" type2
|   "array" '[' '*' muldim ']' "of" type2
;


muldim:
    /* nothing */
|   muldim ',' '*'
;

expr1:
    expr3
|   T_id expr2 mulexpr2
|   T_Id expr2 mulexpr2
;

expr2:
    '(' letdef "in" expr1 ')'
|   expr
;

expr3:
    letdef "in" expr1
|   expr
;

expr:
    T_integer
|   T_real
|   T_character
|   T_string
|   "true"
|   "false"
|   '(' ')'
|   '(' expr1 ')'
|   T_id
|   T_Id
|   T_id '[' expr1 mulexpr ']'
|   '+' expr    %prec UNOP
|   '-' expr    %prec UNOP
|   "+." expr   %prec UNOP
|   "-." expr   %prec UNOP
|   '!' expr
|   "not" expr
|   expr '+' expr
|   expr '-' expr
|   expr "+." expr
|   expr "-." expr
|   expr '*' expr
|   expr "*." expr
|   expr '/' expr
|   expr "/." expr
|   expr "mod" expr
|   expr "**" expr
|   expr '=' expr
|   expr "<>" expr
|   expr '<' expr
|   expr '>' expr
|   expr "<=" expr
|   expr ">=" expr
|   expr "==" expr
|   expr "!=" expr
|   expr "&&" expr
|   expr "||" expr
|   expr ';' expr
|   expr ":=" expr 
|   "dim" T_id
|   "dim" T_integer T_id
|   "new" type
|   "delete" expr
|   "begin" expr1 "end"
|   "if" expr1 "then" expr1
|   "if" expr1 "then" expr1 "else" expr1
|   "while" expr1 "do" expr1 "done"
|   "for" T_id '=' expr1 "to" expr1 "do" expr1 "done"
|   "for" T_id '=' expr1 "downto" expr1 "do" expr1 "done"
|   "match" expr1 "with" clause mulclause "end"
;

mulexpr2:
    /* nothing */
|   mulexpr2 expr2
;

mulclause:
    /* nothing */
|   mulclause '|' clause
;


clause:
    pattern "->" expr1
;

pattern:
    pattern1
|   T_Id pattern1 mulpat
;

pattern1:
    T_integer
|   '+' T_integer %prec UNOP
|   '-' T_integer %prec UNOP
|   T_real
|   "+." T_real   %prec UNOP
|   "-." T_real   %prec UNOP
|   T_character
|   "true"
|   "false"
|   T_id
|   '(' pattern ')'
|   T_Id
;

mulpat:
    /* nothing */
|   mulpat pattern1
;


%%

void yyerror(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

int main() {
    int result = yyparse();
    if (result == 0) printf("Success.\n");
    return result;
}