%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}

DIGIT			  [0-9]
LETTER			[a-zA-Z_]
H			      [a-fA-F0-9]
E			      [Ee][+-]?(D)+
FS			    (f|F|l|L)
IS			    (u|U|l|L)*

%%

";"			                { return(';'); }
("{"|"<%")		          { return('{'); }
("}"|"%>")		          { return('}'); }
","			                { return(','); }
":"			                { return(':'); }
"="			                { return('='); }
"("			                { return('('); }
")"			                { return(')'); }
("["|"<:")		          { return('['); }
("]"|":>")		          { return(']'); }
"."			                { return('.'); }
"&"			                { return('&'); }
"!"			                { return('!'); }
"~"			                { return('~'); }
"-"			                { return('-'); }
"+"			                { return('+'); }
"*"			                { return('*'); }
"/"			                { return('/'); }
"%"			                { return('%'); }
"<"			                { return('<'); }
">"			                { return('>'); }
"^"			                { return('^'); }
"|"			                { return('|'); }
"?"			                { return('?'); }

">>="			            { return(RIGHTSHIFT_ASSIGN); }
"<<="			            { return(LEFTSHIFT_ASSIGN); }
"+="			            { return(ADD_ASSIGN); }
"-="			            { return(SUB_ASSIGN); }
"*="			            { return(MUL_ASSIGN); }
"/="			            { return(DIV_ASSIGN); }
"%="			            { return(MOD_ASSIGN); }
"&="			            { return(AND_ASSIGN); }
"^="			            { return(XOR_ASSIGN); }
"|="			            { return(OR_ASSIGN); }
">>"			            { return(RIGHTSHIFT_OP); }
"<<"			            { return(LEFTSHIFT_OP); }
"++"			            { return(INCREMENT_OP); }
"--"			            { return(DECREMENT_OP); }
"->"			            { return(POINTER_OP); }
"&&"			            { return(AND_OP); }
"||"			            { return(OR_OP); }
"<="			            { return(LE_OP); }
">="			            { return(GE_OP); }
"=="			            { return(EQ_OP); }
"!="			            { return(NE_OP); }


"return"        { return(RETURN); }

"for"			      { return(FOR); }
"while"			    { return(WHILE); }
"if"			      { return(IF); }
"else"			    { return(ELSE); }
"switch"		    { return(SWITCH); }
"case"			    { return(CASE); }
"break"			    { return(BREAK); }
"continue"		  { return(CONTINUE); }
"default"		    { return(DEFAULT); }
"do"			      { return(DO); }

"int"			      { return(INT); }
"void"			    { return(VOID); }
"double"		    { return(DOUBLE); }
"char"			    { return(CHAR); }
"unsigned"		  { return(UNSIGNED); }
"float"			    { return(FLOAT); }
"enum"			    { return(ENUM); }

"sizeof"		    { return(SIZEOF); }
"struct"		    { return(STRUCT); }
"typedef"		    { return(TYPEDEF); }



[0-9]+                        { yylval.integer=strtod(yytext, 0); return INT_LITERAL; }
[0-9]+[0-9]*f?                { yylval.numberFloat=strtof(yytext, 0) ; return FLOAT_LITERAL;}
{LETTER}({LETTER}|{DIGIT})*	  { yylval.string=new std::string(yytext); return IDENTIFIER; }

'([^'\\\n]|\\.)'            { yylval.string=new std::string(yytext) ; return(CHAR_LITERAL);}
[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  // '(\\.|[^'\\])'          	    {yylval.integer=strtod(yytext, 0); return(CHAR_LITERAL); }
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
