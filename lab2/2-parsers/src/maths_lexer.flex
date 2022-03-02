%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "maths_parser.tab.hpp"
%}

DIGIT         [0-9]
LETTER			  [a-zA-Z_]

%%

";"			        { return(';'); }
"{"		          { return('{'); }
"}"		          { return('}'); }

"("             { return('('); }
")"             { return(')'); }

"int"			      { return T_INT; }
"void"			    { return T_VOID; }

[0-9]+([.][0-9]*)? { yylval.number=strtod(yytext, 0); return T_NUMBER; }
{LETTER}({LETTER}|{DIGIT})*	  { yylval.string=new std::string(yytext); return IDENTIFIER; }



[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
