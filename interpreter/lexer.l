%{
#include "lexer.hpp"
#include "parser.hpp"

#define T_eof 0


int nested=0, lines=1;

%}

LL [A-Z]
Ll [a-z]
D [0-9]
W [ \t\r]
hex [0-9a-f]

%x COMMENTS

%option noyywrap

%%

"and" { return T_and; }
"array" { return T_array; }
"begin" { return T_begin; }
"bool" { return T_bool; }
"char" { return T_char; }
"delete" { return T_delete; }
"dim" { return T_dim; }
"do" { return T_do; }
"done" { return T_done; }
"downto" { return T_downto; }
"else" { return T_else; }
"end" { return T_end; }
"false" {return T_false; }
"float" { return T_float; }
"for" { return T_for; }
"if" { return T_if; }
"in" { return T_in; }
"int" { return T_int; }
"let" {return T_let; }
"match" { return T_match; }
"mod" { return T_mod; }
"mutable" { return T_mutable; }
"new" { return T_new; }
"not" { return T_not; }
"of" {return T_of; }
"rec" { return T_rec; }
"ref" { return T_ref; }
"then" { return T_then; }
"to" { return T_to; }
"true" { return T_true; }
"type" {return T_type; }
"unit" { return T_unit; }
"while" { return T_while; }
"with" { return T_with; }

"->" { return T_arrow; }
"+." { return T_fplus; }
"-." { return T_fminus; }
"*." { return T_fmul; }
"/." { return T_fdiv; }
"&&" { return T_land; }
"**" { return T_power; }
"||" { return T_lor; }
"<>" { return T_diff; }
"<=" { return T_leq; }
">=" { return T_geq; }
"==" { return T_eq; }
"!=" { return T_neq; }
":=" { return T_def; }

{LL}({LL}|{Ll}|{D}|_)* {return T_Id; }
{Ll}({LL}|{Ll}|{D}|_)* {return T_id; }
{D}+\.{D}+((e|E)(\-|\+)?{D}+)? { return T_real; }
{D}+ { return T_integer; }
\'([^\'\"\\\n\t\r\0\\\'\"]|\\n|\\t|\\r|\\0|\\\\|\\\'|\\\"|\\x{hex}{hex})\' {return T_character; }
\"([^\'\"\\\n\t\r\0\\\'\"]|\\n|\\t|\\r|\\0|\\\\|\\\'|\\\"|\\x{hex}{hex})+\" { return T_string; }

[\=\|\+\-\*\/\!\;\<\>\(\)\[\]\,\:] { return yytext[0]; }

{W}+ { /* nothing */ }
"--".*\n { lines++; }
"--".* { /* nothing */ }
"\n" { lines++; }
"(*" { BEGIN(COMMENTS); nested++; }
<COMMENTS>"(*" { nested++;}
<COMMENTS>"*)" { nested--; if (nested == 0) BEGIN(INITIAL);}
<COMMENTS>"\n" { lines++; }
<COMMENTS>"*" { /* nothing */ }
<COMMENTS>"(" { /* nothing */ }
<COMMENTS>[^(*\n]+ { /* nothing */ }
<COMMENTS><<EOF>> { fprintf(stderr, "Error: EOF before comment-closing"); exit(1); }

. { fprintf(stderr, "illegal character '%c' (ASCII: '%d') at line '%d'\n", yytext[0], yytext[0], lines); exit(1); }


%%
/*
int main() {
    int token;
    do {
        token = yylex();
        printf("token=%d, lexeme=\"%s\"\n", token, yytext);
    } while (token != T_eof);
}

"->"|"+."|"-."|"*."|"/."|"&&"|"**"|"||"|"<>"|"<="|">="|"=="|"!="|":=" {return (yytext[0]*1000)+yytext[1]; }
*/