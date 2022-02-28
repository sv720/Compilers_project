%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}

DIGIT         [0-9]
LETTER			  [a-zA-Z_]
HEX	          [a-fA-F0-9]
E			        [Ee][+-]?{D}+
FS			      (f|F|l|L)
IS			      (u|U|l|L)*


%%

";"			        { return(';'); }
("{"|"<%")		  { return('{'); }
("}"|"%>")		  { return('}'); }
","			        { return(','); }
":"			        { return(':'); }
"="			        { return('='); }
"("			        { return('('); }
")"			        { return(')'); }
("["|"<:")		  { return('['); }
("]"|":>")		  { return(']'); }
"."			        { return('.'); }
"&"			        { return('&'); }
"!"			        { return('!'); }
"~"			        { return('~'); }
"-"			        { return('-'); }
"+"			        { return('+'); }
"*"			        { return('*'); }
"/"			        { return('/'); }
"%"			        { return('%'); }
"<"			        { return('<'); }
">"			        { return('>'); }
"^"			        { return('^'); }
"|"			        { return('|'); }
"?"			        { return('?'); }
"#"             { return('#'); }
"..."			      { return(ELLIPSIS); } //never seen
">>="			      { return(RIGHTSHIFT_ASSIGN); } // RIGHT_ASSIGN
"<<="			      { return(LEFTSHIFT_ASSIGN); } // LEFT_ASSIGN
"+="			      { return(ADD_ASSIGN); }
"-="			      { return(SUB_ASSIGN); }
"*="			      { return(MUL_ASSIGN); }
"/="			      { return(DIV_ASSIGN); }
"%="			      { return(MOD_ASSIGN); }
"&="			      { return(AND_ASSIGN); }
"^="			      { return(XOR_ASSIGN); }
"|="			      { return(OR_ASSIGN); }
">>"			      { return(RIGHTSHIFT_OP); } // RIGHT_OP
"<<"			      { return(LEFTSHIFT_OP); } // LEFT_OP
"++"			      { return(INCREMENT_OP); } // INC_OP
"--"			      { return(DECREMENT_OP); } // DEC_OP
"->"			      { return(POINTER_OP); } //PTR_OP // TODO: how about *a and &a and (*a).x 
"&&"			      { return(AND_OP); }
"||"			      { return(OR_OP); }
"<="			      { return(LE_OP); }
">="			      { return(GE_OP); }
"=="			      { return(EQ_OP); }
"!="			      { return(NE_OP); }

"char"			      { return CHAR; }
"double"		      { return DOUBLE; }
"float"			      { return FLOAT; }
"int"			        { return INT; }
"long"			      { return LONG; }
"short"			      { return SHORT; }
"sizeof"		      { return SIZEOF; }
"signed"		      { return SIGNED; }
"unsigned"		    { return UNSIGNED; }
"const"			      { return CONST; }
"void"			      { return VOID; }
"static"		      { return STATIC; }
"struct"		      { return STRUCT; }
"enum"			      { return ENUM; }

"typedef"		      { return TYPEDEF; }
"return"          { return RETURN; }

"if"			        { return IF; }
"else"			      { return ELSE; }
"while"           { return WHILE; }
"for"             { return FOR; }
"switch"		      { return SWITCH; }
"case"			      { return CASE; }
"break"           { return BREAK; }
"continue"		    { return CONTINUE; }
"default"		      { return DEFAULT; }


{LETTER}({LETTER}|{DIGIT})*	  { yylval.string=new std::string(yytext); return IDENTIFIER; }
            
{DIGIT}+{IS}?         { yylval.number=(int)strtol(yytext, NULL, 0); return INT_LITERAL; }
0[xX]{HEX}+{IS}?      { yylval.number=(int)strtol(yytext, NULL, 0); return INT_LITERAL; }
0{DIGIT}+{IS}?        { yylval.number=(int)strtol(yytext, NULL, 0); return INT_LITERAL; }

{DIGIT}+{E}{FS}?                { yylval.numberFloat=strtod(yytext, NULL); return FLOAT_LITERAL; }
{DIGIT}*"."{DIGIT}+({E})?{FS}?  { yylval.numberFloat=strtod(yytext, NULL); return FLOAT_LITERAL; }
{DIGIT}+"."{DIGIT}*({E})?{FS}?  { yylval.numberFloat=strtod(yytext, NULL); return FLOAT_LITERAL; }

{LETTER}?\"(\\.|[^\\"])*\"	      { return(STRING_LITERAL); } /*TODO: L?\"(\\.|[^\\"])*\" */ // valid: a"s" or "\." or bbd"s0sd2l;;[;"

[ \t\v\n\f]+		{}

.               { /*INVALID characters*/
                  /*fprintf(stderr, "Invalid token\n"); exit(1);*/}

%%

// "/*"			            { comment(); }


void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
