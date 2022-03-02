%code requires{
  #include "ast.hpp"

  #include <cassert>

  #include <iostream>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}

// declare tokens
%token ';'
%token '{' '}'
%token T_INT T_VOID

%token T_LOG T_EXP T_SQRT
%token T_NUMBER T_VARIABLE

// declare non-terminals
%type <expr> EXPR STATEMENT ASSIGN_DECLARE RETURN_TYPE
%type <number> T_NUMBER
%type <string> T_VOID T_INT IDENTIFIER '{' '}' '(' ')' ';'

%start ROOT

%%

ROOT : EXPR { g_root = $1; }

EXPR : RETURN_TYPE DECLARATOR STATEMENT { $$ = new Function($1, $2, $3); //not sure what to do in AST function }  


ASSIGN_DECLARE : RETURN_TYPE IDENTIFIER '=' T_NUMBER { $$ = new Assign_Declare_Operator; //IDEM} 



TERM : TERM T_TIMES UNARY { $$ = new MulOperator($1, $3); }
  | TERM T_DIVIDE UNARY { $$ = new DivOperator($1, $3); }
  | UNARY          { $$ = $1; }


UNARY : T_MINUS FACTOR            { $$ = new NegOperator($2); }
  | FACTOR        { $$ = $1; }
  

FACTOR : T_VARIABLE { $$ = new Variable( *$1 ); }
       | T_NUMBER { $$ = new Number( $1 ); }
       | T_LBRACKET EXPR T_RBRACKET { $$ = $2; } 
       | T_LOG T_LBRACKET EXPR T_RBRACKET { $$ = new LogFunction($3); }
       | T_EXP T_LBRACKET EXPR T_RBRACKET { $$ = new ExpFunction($3); }
       | T_SQRT T_LBRACKET EXPR T_RBRACKET { $$ = new SqrtFunction($3); }
       | FACTOR T_EXPONENT UNARY { $$ = new ExpOperator($1, $3);}



RETURN_TYPE : T_INT { $$ = new std::string("int"); }
       | T_VOID { $$ = new std::string("void"); }
%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
