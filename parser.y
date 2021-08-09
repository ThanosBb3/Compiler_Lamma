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

%token T_Id 
%token T_id 
%token T_integer
%token T_real 
%token T_character 
%token T_string 

%left '*' '/' "*." "/." "mod" '+' '-' "+." "-." '=' "<>" '>' '<' "<=" ">=" "==" "!=" "&&" "||" ';'

%right "**" 


%%

program:
    /* nothing */
|   letdef program 
|   typedef program    
;

letdef:
    "let" def muldef
|   "let" "rec" def muldef
;

muldef:
    /* nothing */
|   "and" def muldef
;

def:
    T_id mulpar "=" expr
|   T_id mulpar ":" type "=" expr
|   "mutable" T_id
|   "mutable" T_id ":" type
|   "mutable" T_id "[" expr mulexpr "]"
|   "mutable" T_id "[" expr mulexpr "]" ":" type
;

mulpar:
    /* nothing */
|   par mulpar
;

mulexpr:
    /* nothing */
|   "," expr mulexpr
;

typedef:
    "type" tdef multdef
;

multdef:
    /* nothing */
|   "and" tdef multdef
;

tdef:
    T_id "=" constr mulconstr
;

mulconstr:
    /* nothing */
|   "|" constr mulconstr
;

constr:
    T_Id
|   T_Id "of" type multype
;

multype:
    /* nothing */
|   type multype
;

par:
    T_id
|   "(" T_id ":" type ")"
;

type:
    "unit"
|   "int"
|   "char"
|   "bool"
|   "float"
|   "(" type ")"
|   type "->" type
|   type "ref"
|   "array" "of" type
|   "array" "[" "*" muldim "]" "of" type
|   T_id
;

muldim:
    /* nothing */
|   "," "*" muldim
;

expr:
    T_integer
|   T_real
|   T_character
|   T_string
|   "true"
|   "false"
|   "(" ")"
|   "(" expr ")"
|   unop expr
|   expr binop expr
|   T_id mulexpr2
|   T_Id mulexpr2
|   T_id "[" expr mulexpr "]"
|   "dim" T_id
|   "dim" T_integer T_id
|   "new" type
|   "delete" expr
|   letdef "in" expr
|   "begin" expr "end"
|   "if" expr "then" expr
|   "if" expr "then" expr "else" expr
|   "while" expr "do" expr "done"
|   "for" T_id "=" expr "to" expr "do" expr "done"
|   "for" T_id "=" expr "downto" expr "do" expr "done"
|   "match" expr "with" clause mulclause "end"
;

mulexpr2:
    /* nothing */
|   expr mulexpr2
;

mulclause:
    /* nothing */
|   "|" clause mulclause
;

unop:
    '+'
|   '-'
|   "+."
|   "-."
|   '!'
|   "not"
;

binop:
    '+'
|   '-'
|   '*'
|   '/'
|   "+."
|   "-."
|   "*."
|   "/."
|   "mod"
|   "**"
|   '='
|   "<>"
|   '<'
|   '>'
|   "<="
|   ">="
|   "=="
|   "!="
|   "&&"
|   "||"
|   ';'
|   ":="
;

clause:
    pattern "->" expr
;

pattern:
    T_integer
|   '+' T_integer
|   '-' T_integer
|   T_real
|   "+." T_real
|   "-." T_real
|   T_character
|   "true"
|   "false"
|   T_id
|   "(" pattern ")"
|   T_Id mulpat
;

mulpat:
    /* nothing */
|   pattern mulpat
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