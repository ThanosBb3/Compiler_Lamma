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

%token T_constructorid 
%token T_id 
%token T_real 
%token T_integer 
%token T_characters 
%token T_string 

%left '+' '-'
%left '*' '/' '%'

%expect 1

%%

program:
    stmt_list
;

stmt_list:
    /* nothing */
|   stmt_list stmt
;

stmt:
    "let" T_id '=' expr
|   "for" expr "to" expr "do" stmt "done"
|   "for" expr "downto" expr "do" stmt "done"
|   "if" expr "then" stmt
|   "if" expr "then" stmt "else" stmt
|   "begin" stmt_list "end"
;

expr:
    T_id
|   T_integer
|   '(' expr ')'
|   expr '+' expr
|   expr '-' expr
|   expr '*' expr
|   expr '/' expr
|   expr '%' expr


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