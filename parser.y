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

%right "->"
%nonassoc "of"
%nonassoc "ref"

%token T_Id 
%token T_id 
%token T_integer
%token T_real 
%token T_character 
%token T_string 


%%

program:
    deflist
;

deflist:
    /* nothing */
|   deflist letdef 
|   deflist typedef
;

letdef:
    "let" muldef       
|   "let" "rec" muldef
;

muldef:
    def
|   muldef "and" def
;

def:
    T_id mulpar '=' expr
|   T_id mulpar ':' type '=' expr
|   "mutable" T_id
|   "mutable" T_id ':' type
|   "mutable" T_id '[' expr mulexpr ']'
|   "mutable" T_id '[' expr mulexpr ']' ':' type
;

mulpar:
    /* nothing */
|   mulpar par
;

mulexpr:
    /* nothing */
|   mulexpr ',' expr
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
    "unit"
|   "int"
|   "char"
|   "bool"
|   "float"
|   T_id
|   '(' type ')'
|   type "ref"
|   type "->" type
|   "array" "of" type
|   "array" '[' '*' muldim ']' "of" type
;


muldim:
    /* nothing */
|   muldim ',' '*'
;

expr:
    expr '+' expr
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
|   '+' expr    %prec UNOP
|   '-' expr    %prec UNOP
|   "+." expr   %prec UNOP
|   "-." expr   %prec UNOP
|   T_id mulexpr2
|   T_Id mulexpr2
|   letdef "in" expr
|   "dim" T_id
|   "dim" T_integer T_id
|   "new" type
|   "delete" expr
|   "begin" expr "end"
|   "if" expr "then" expr
|   "if" expr "then" expr "else" expr
|   "while" expr "do" expr "done"
|   "for" T_id '=' expr "to" expr "do" expr "done"
|   "for" T_id '=' expr "downto" expr "do" expr "done"
|   "match" expr "with" clause mulclause "end"
|   valexpr
;

mulexpr2:
    valexpr
|   mulexpr2 valexpr
;

valexpr:
    T_integer
|   T_real
|   T_character
|   T_string
|   "true"
|   "false"
|   '(' ')'
|   '(' expr ')'
|   T_id
|   T_Id
|   T_id '[' expr mulexpr ']'
|   '!' valexpr
|   "not" valexpr
;

mulclause:
    /* nothing */
|   mulclause '|' clause
;


clause:
    pattern "->" expr
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