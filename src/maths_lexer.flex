%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "maths_parser.tab.hpp"
%}

DIGIT         [0-9]
LETTER			  [a-zA-Z_]

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
"++"			            { return(INC_OP); }
"--"			            { return(DEC_OP); }
"->"			            { return(PTR_OP); }
"&&"			            { return(AND_OP); }
"||"			            { return(OR_OP); }
"<="			            { return(LE_OP); }
">="			            { return(GE_OP); }
"=="			            { return(EQ_OP); }
"!="			            { return(NE_OP); }


"return"        { return(T_RETURN); }

"int"			      { return T_INT; }
"void"			    { return T_VOID; }

[0-9]+                        { yylval.number=strtod(yytext, 0); return T_NUMBER; }
{LETTER}({LETTER}|{DIGIT})*	  { yylval.string=new std::string(yytext); return T_IDENTIFIER; }



[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
