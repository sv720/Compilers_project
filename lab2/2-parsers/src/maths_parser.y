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
%type <expr> EXPR STATEMENT ASSIGN_DECLARE RETURN_TYPE ASSIGN FUNCTION_DEFINITION
%type <number> T_NUMBER
%type <string> T_VOID T_INT IDENTIFIER '{' '}' '(' ')' ';'

%start ROOT

%%

ROOT : EXPR { g_root = $1; }

EXPR : FUNCTION_DECLARATOR '(' ')' '{' STATEMENT '}' { $$ = new Full_Function($1, $5); //not sure what to do in AST function } 

FUNCTION_DEFINITION : RETURN_TYPE DECLARATOR { $$ = new Function_Definition($1, $2); //}

STATEMENT : ASSIGN_DECLARE ';' { $$ = new Statment($1); //has ast_function}

ASSIGN_DECLARE : RETURN_TYPE ASSIGN { $$ = new Assign_DeclareOperator($1, $2); //has ast_operator} 

ASSIGN : IDENTIFIER '=' T_NUMBER { $$ = new AssignOperator($1, $2); //has ast_operator}

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
