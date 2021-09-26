%{
    #include <cstdio>
    #include <cstdlib>
    #include "AST_main.hpp"
    #include "type.hpp"
    #include "ast.hpp"
    #include "lexer.hpp"

    SymbolTable st;
    std::unordered_map<char*, SymbolEntry*> globals;
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
%token<op> T_not "not"
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
%left<op> ';'
%nonassoc<op> ":="
%left<op> "||"
%left<op> "&&"
%nonassoc<op> '=' "<>" '<' '>' "<=" ">=" "==" "!=" 
%left<op> '+' '-' "+." "-."
%left<op> '*' '/' "*." "/." "mod"
%right<op> "**"
%nonassoc UNOP "not" "delete"
%nonassoc<op> '!'
%nonassoc<op> '[' ']'
%nonassoc "new"

%right<op> "->"
%nonassoc "of"
%nonassoc "ref"

%token<id> T_Id 
%token<id> T_id 
%token<num> T_integer
%token<flo> T_real 
%token<ch> T_character 
%token<str> T_string 

%union {
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

}

%type<block> deflist
%type<let> letdef
%type<dlist> muldef
%type<def> def
%type<pplist> mulpar
%type<elist> mulexpr
%type<mytype> typedef
%type<ttlist> multdef
%type<tdef> tdef
%type<cclist> mulconstr
%type<constr> constr
%type<typelist> multype
%type<par> par
%type<type> type
%type<num> muldim
%type<expr> expr
%type<vlist> mulexpr2 mulpat
%type<valexpr> valexpr pattern1
%type<clauselist> mulclause
%type<clause> clause
%type<pattern> pattern



%%

program:
    deflist {
    $1->sem();
    std::cout << "AST: " << *$1 << std::endl;
    //$1->run();
  }
;

deflist:
    /* nothing */    { $$ = new Block(); }
|   deflist letdef   { $1->append($2); $$ = $1; }
|   deflist typedef  { $1->append($2); $$ = $1; }
;




letdef:
    "let" muldef             { $$ = new Let(false,$2); } 
|   "let" "rec" muldef       { $$ = new Let(true,$3); }
;

muldef:
    def                 { $$ = new Deflist(); $$->append($1); }
|   muldef "and" def    { $1->append($3); $$ = $1; }
;

def:
    T_id mulpar '=' expr                                      { $$ = new Def($1, $2, $4); }
|   T_id mulpar ':' type '=' expr                             { $$ = new Def($1, $2, $6, $4); }
|   "mutable" T_id                                            { $$ = new Def($2); }
|   "mutable" T_id ':' type                                   { $$ = new Def($2, nullptr, nullptr, $4); }
|   "mutable" T_id '[' mulexpr ']'                            { $$ = new Def($2, nullptr, nullptr, nullptr, $4); }
|   "mutable" T_id '[' mulexpr ']' ':' type                   { $$ = new Def($2, nullptr, nullptr, $7, $4); }
;

mulpar:
    /* nothing */   { $$ = new Parlist(); }
|   mulpar par      { $1->append($2); $$ = $1; }
;

mulexpr:
    expr                    { $$ = new Exprlist(); $$->append($1); }
|   mulexpr ',' expr        { $1->append($3); $$ = $1; }
;

typedef:
    "type" multdef          { $$ = new Mytype($2); }
;

multdef:
    tdef                    { $$ = new Tdeflist(); $$->append($1); }
|   multdef "and" tdef      { $1->append($3); $$ = $1; }
;

tdef:
    T_id '=' mulconstr      { $$ = new Tdef($1, $3); }
;

mulconstr:
    constr                      { $$ = new Constrlist(); $$->append($1); }
|   mulconstr '|' constr        { $1->append($3); $$ = $1; }
;

constr:
    T_Id                        { $$ = new Constr($1); }
|   T_Id "of" multype           { $$ = new Constr($1, $3); }
;

multype:
    type                        { $$ = new Typelist(); $$->append($1); }
|   multype type                { $1->append($2); $$ = $1; }
;

par:
    T_id                        { $$ = new Par($1); }
|   '(' T_id ':' type ')'       { $$ = new Par($2, $4); }
;

type:
    "unit"                                      { $$ = new Unit(); }
|   "int"                                       { $$ = new Integer(); }
|   "char"                                      { $$ = new Char(); }
|   "bool"                                      { $$ = new Boolean(); }
|   "float"                                     { $$ = new Real(); }
|   T_id                                        { $$ = new Typeid($1); }
|   '(' type ')'                                { $$ = $2; }
|   type "ref"                                  { $$ = new Tref($1); }
|   type "->" type                              { $$ = new Tfun($1, $3); }
|   "array" "of" type                           { $$ = new Array($3); }
|   "array" '[' muldim ']' "of" type            { $$ = new Array($6, $3); }
;


muldim:
    '*'                     { $$ = 1; }
|   muldim ',' '*'          { $$ = $1 + 1; }
;

expr:
    expr '+' expr                                       { $$ = new Binop($1, $2, $3); }
|   expr '-' expr                                       { $$ = new Binop($1, $2, $3); }
|   expr "+." expr                                      { $$ = new Binop($1, $2, $3); }
|   expr "-." expr                                      { $$ = new Binop($1, $2, $3); }
|   expr '*' expr                                       { $$ = new Binop($1, $2, $3); }
|   expr "*." expr                                      { $$ = new Binop($1, $2, $3); }
|   expr '/' expr                                       { $$ = new Binop($1, $2, $3); }
|   expr "/." expr                                      { $$ = new Binop($1, $2, $3); }     
|   expr "mod" expr                                     { $$ = new Binop($1, $2, $3); }
|   expr "**" expr                                      { $$ = new Binop($1, $2, $3); }
|   expr '=' expr                                       { $$ = new Binop($1, $2, $3); }
|   expr "<>" expr                                      { $$ = new Binop($1, $2, $3); } 
|   expr '<' expr                                       { $$ = new Binop($1, $2, $3); }
|   expr '>' expr                                       { $$ = new Binop($1, $2, $3); }
|   expr "<=" expr                                      { $$ = new Binop($1, $2, $3); }
|   expr ">=" expr                                      { $$ = new Binop($1, $2, $3); }
|   expr "==" expr                                      { $$ = new Binop($1, $2, $3); }
|   expr "!=" expr                                      { $$ = new Binop($1, $2, $3); }
|   expr "&&" expr                                      { $$ = new Binop($1, $2, $3); }
|   expr "||" expr                                      { $$ = new Binop($1, $2, $3); }
|   expr ';' expr                                       { $$ = new Binop($1, $2, $3); }
|   expr ":=" expr                                      { $$ = new Binop($1, $2, $3); }
|   '+' expr    %prec UNOP                              { $$ = new Unop($1, $2); }
|   '-' expr    %prec UNOP                              { $$ = new Unop($1, $2); }
|   "+." expr   %prec UNOP                              { $$ = new Unop($1, $2); }
|   "-." expr   %prec UNOP                              { $$ = new Unop($1, $2); }
|   "not" expr                                          { $$ = new Unop($1, $2); }
|   T_id mulexpr2                                       { $$ = new Call($1, $2); }
|   T_Id mulexpr2                                       { $$ = new Call($1, $2); }
|   letdef "in" expr                                    { $$ = new Letin($1, $3); }
|   "dim" T_id                                          { $$ = new Dim($2); }
|   "dim" T_integer T_id                                { $$ = new Dim($3, $2); }
|   "new" type                                          { $$ = new New($2); }
|   "delete" expr                                       { $$ = new Delete($2); }
|   "begin" expr "end"                                  { $$ = $2; }
|   "if" expr "then" expr                               { $$ = new If($2, $4); }
|   "if" expr "then" expr "else" expr                   { $$ = new If($2, $4, $6); }
|   "while" expr "do" expr "done"                       { $$ = new While($2, $4); }
|   "for" T_id '=' expr "to" expr "do" expr "done"      { $$ = new For(false, $2, $4, $6, $8); }
|   "for" T_id '=' expr "downto" expr "do" expr "done"  { $$ = new For(true, $2, $4, $6, $8); }
|   "match" expr "with" mulclause "end"                 { $$ = new Match($2, $4); }
|   valexpr                                             { $$ = $1; }
;

mulexpr2:
    valexpr                                             { $$ = new Valexprlist(); $$->append($1); }
|   mulexpr2 valexpr                                    { $1->append($2); $$ = $1; }
;

valexpr:
    T_integer                                           { $$ = new Constint($1, false); }
|   T_real                                              { $$ = new Constreal($1, false); }
|   T_character                                         { $$ = new Constchar($1); }
|   T_string                                            { $$ = new Conststr($1); }
|   "true"                                              { $$ = new Constbool(1); }
|   "false"                                             { $$ = new Constbool(0); }
|   '(' ')'                                             { $$ = new Constunit(); }
|   '(' expr ')'                                        { $$ = new BrackExp($2); }
|   T_id                                                { $$ = new Id(false, $1); }
|   T_Id                                                { $$ = new Id(true, $1); }
|   T_id '[' mulexpr ']'                                { $$ = new Arrayitem($1, $3); }
|   '!' valexpr                                         { $$ = new Deref($2); }
;

mulclause:
    clause                                  { $$ = new Clauselist(); $$->append($1); }
|   mulclause '|' clause                    { $1->append($3); $$ = $1; }
;


clause:
    pattern "->" expr                       { $$ = new Clause($1, $3); }
;

pattern:
    pattern1                            { $$ = new Pattern($1, nullptr, nullptr); }                  
|   T_Id mulpat                         { $$ = new Pattern(nullptr, $1, $2); }
;

pattern1:
    T_integer                           { $$ = new Constint($1, false); }
|   '+' T_integer %prec UNOP            { $$ = new Constint($2, false); }
|   '-' T_integer %prec UNOP            { $$ = new Constint($2, true); }
|   T_real                              { $$ = new Constreal($1, false); }
|   "+." T_real   %prec UNOP            { $$ = new Constreal($2, false); }
|   "-." T_real   %prec UNOP            { $$ = new Constreal($2, true); }
|   T_character                         { $$ = new Constchar($1); }
|   "true"                              { $$ = new Constbool(1); }
|   "false"                             { $$ = new Constbool(0); }
|   T_id                                { $$ = new Id(false, $1); }
|   '(' pattern ')'                     { $$ = new BrackPat($2); }
|   T_Id                                { $$ = new Id(true, $1); }
;

mulpat:
    /* nothing */                       { $$ = new Valexprlist(); }
|   mulpat pattern1                     { $1->append($2); $$ = $1; }
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