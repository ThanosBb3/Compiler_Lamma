%{
#include "AST_main.hpp"
#include "type.hpp"
#include "ast.hpp"
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
"mod" {yylval.op = strdup(yytext); return T_mod; }
"mutable" { return T_mutable; }
"new" { return T_new; }
"not" {yylval.op = strdup(yytext); return T_not; }
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

"->" {yylval.op = strdup(yytext); return T_arrow; }
"+." {yylval.op = strdup(yytext); return T_fplus; }
"-." {yylval.op = strdup(yytext); return T_fminus; }
"*." {yylval.op = strdup(yytext); return T_fmul; }
"/." {yylval.op = strdup(yytext); return T_fdiv; }
"&&" {yylval.op = strdup(yytext); return T_land; }
"**" {yylval.op = strdup(yytext); return T_power; }
"||" {yylval.op = strdup(yytext); return T_lor; }
"<>" {yylval.op = strdup(yytext); return T_diff; }
"<=" {yylval.op = strdup(yytext); return T_leq; }
">=" {yylval.op = strdup(yytext); return T_geq; }
"==" {yylval.op = strdup(yytext); return T_eq; }
"!=" {yylval.op = strdup(yytext); return T_neq; }
":=" {yylval.op = strdup(yytext); return T_def; }

{LL}({LL}|{Ll}|{D}|_)* {yylval.id = strdup(yytext); return T_Id; }
{Ll}({LL}|{Ll}|{D}|_)* {yylval.id = strdup(yytext); return T_id; }
{D}+\.{D}+((e|E)(\-|\+)?{D}+)? {yylval.flo = std::stod(yytext); return T_real; }
{D}+ {yylval.num = std::stoi(yytext); return T_integer; }
\'([^\'\"\\\n\t\r\0\\\'\"]|\\n|\\t|\\r|\\0|\\\\|\\\'|\\\"|\\x{hex}{hex})\' {yylval.ch = strdup(yytext); return T_character; }
\"([^\'\"\\\n\t\r\0\\\'\"]|\\n|\\t|\\r|\\0|\\\\|\\\'|\\\"|\\x{hex}{hex})+\" {yylval.str = strdup(yytext); return T_string; }

[\=\|\+\-\*\/\!\;\<\>\[\]] {yylval.op = strdup(yytext); return yytext[0]; }

[\(\)\,\:] { return yytext[0]; }


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