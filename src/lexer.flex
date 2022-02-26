%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}


%%
[*]             { return T_TIMES; }
[+]             { return T_PLUS; }
[/]             { return T_DIVIDE; }
[\^]            { return T_EXPONENT; }
[-]             { return T_MINUS; }

[\[]            { return T_LSQBRACKET; } //TBC
[\]]            { return T_RSQBRACKET; }
[{]             { return T_LCURBRACKET; }
[}]             { return T_RCULBRACKET; }
[;]             { return T_SEMICOLON; }
[:]             { return T_COLON; }
[~]             { return T_TILDE; }
[#]             { return T_HASH; }
[!]             { return T_EXCLAMATIONMARK; }
[?]             { return T_QUESTIONMARK; }


[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }

return          { return T_RETURN; }
while           { return T_WHILE; }
for             { return T_FOR; }
break           { return T_BREAK; }



[0-9]+([.][0-9]*)?  { yylval.number=strtod(yytext, 0); return T_NUMBER; }
[a-z]+              { yylval.string=new std::string(yytext); return T_VARIABLE; }

[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
