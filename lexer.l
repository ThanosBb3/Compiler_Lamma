%{

#define T_eof 0
#define T_and 1001
#define T_array 1002
#define T_begin 1003
#define T_bool 1004
#define T_char 1005
#define T_delete 1006
#define T_dim 1007
#define T_do 1008
#define T_done 1009
#define T_downto 1010
#define T_else 1011
#define T_end 1012
#define T_false 1013
#define T_float 1014
#define T_for 1015
#define T_if 1016
#define T_in 1017
#define T_int 1018
#define T_let 1019
#define T_match 1020
#define T_mod 1021
#define T_mutable 1022
#define T_new 1023
#define T_not 1024
#define T_of 1025
#define T_rec 1026
#define T_ref 1027
#define T_then 1028
#define T_to 1029
#define T_true 1030
#define T_type 1031
#define T_unit 1032
#define T_while 1033
#define T_with 1034
#define T_constructorid 1035
#define T_id 1036
#define T_real 1037
#define T_integer 1038
#define T_characters 1039
#define T_string 1040

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

{LL}({LL}|{Ll}|{D}|_)* {return T_constructorid; }
{Ll}({LL}|{Ll}|{D}|_)* {return T_id; }
{D}+\.{D}+((e|E)(\-|\+)?{D}+)? { return T_real; }
{D}+ { return T_integer; }
\'([^\'\"\\\n\t\r\0\\\'\"]|\\n|\\t|\\r|\\0|\\\|\\\'|\\\"|\\x{hex}{hex})\' {return T_characters; }
\"([^\'\"\\\n\t\r\0\\\'\"]|\\n|\\t|\\r|\\0|\\\|\\\'|\\\"|\\x{hex}{hex})+\" { return T_string; }

"->"|"+."|"-."|"*."|"/."|"**"|"&&"|"||"|"<>"|"<="|">="|"=="|"!="|":=" {return yytext[0]+yytext[1]; }
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

int main() {
    int token;
    do {
        token = yylex();
        printf("token=%d, lexeme=\"%s\"\n", token, yytext);
    } while (token != T_eof);
}