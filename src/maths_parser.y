%code requires{
  #include "ast.hpp"

  #include <cassert>

  #include <iostream>

  extern const Expression *g_root; // A way of getting the AST out

  // ! This is to fix problems when generating C++
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
%token T_INT T_VOID
%token T_IDENTIFIER T_RETURN
%token T_NUMBER T_VARIABLE

%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFTSHIFT_ASSIGN RIGHTSHIFT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN INC_OP DEC_OP LEFTSHIFT_OP RIGHTSHIFT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP PTR_OP

// ASSOCIATIVITY
%left T_TIMES T_DIVIDE
%left T_PLUS T_MINUS
// %nonassoc %left or %right

// declare non-terminals
%type <expr> TOPLEVEL LINE ASSIGN_DECLARE ASSIGN FUNCTION_NAME_ARGS T_RETURN 
%type <expr> STATEMENT_LINES STATEMENT MATHS_STATEMENT TERM UNARY FACTOR
%type <number> T_NUMBER
%type <string> T_VOID T_INT T_IDENTIFIER TYPE assignment_operator

%start ROOT

%%
ROOT : TOPLEVEL { g_root = $1; }

TOPLEVEL : TYPE FUNCTION_NAME_ARGS  '{' STATEMENT_LINES '}' { $$ = new Full_Function(new Function_Definition(*$1, $2), $4); /*has ast_operator */}
         ;

FUNCTION_NAME_ARGS : T_IDENTIFIER '(' ')' { $$ = new Variable( *$1 ); /* TODO : allow to pass argument */ }
                   ;

STATEMENT_LINES : LINE ';'                  { $$ = new ExpressionList($1); }
                | STATEMENT_LINES LINE ';'  { $$ = new ExpressionList($1, $2); }
                ;

LINE      : ASSIGN_DECLARE                  { $$ = new Statement($1); /* has ast_function */ }
          | T_RETURN STATEMENT              { $$ = new Return($2);}
          ;

STATEMENT : MATHS_STATEMENT         { $$ = $1; }
          // | CONDITIONAL_STATEMENT
          // | LOGIC_STATEMENT
          ;

ASSIGN_DECLARE : TYPE ASSIGN { $$ = new Assign_Declare(*$1, $2); /* has ast_operator */ } 
               ;

ASSIGN : T_IDENTIFIER assignment_operator STATEMENT { $$ = new AssignOperator(*$1, *$2, $3); /* has ast_operator */ }
       ;

assignment_operator
	: '='                { $$ = new std::string("="); }
	| MUL_ASSIGN         { $$ = new std::string("*="); }
	| DIV_ASSIGN         { $$ = new std::string("/="); }
	| MOD_ASSIGN         { $$ = new std::string("%="); }
	| ADD_ASSIGN         { $$ = new std::string("+="); }
	| SUB_ASSIGN         { $$ = new std::string("-="); }
	| LEFTSHIFT_ASSIGN   { $$ = new std::string("<<="); }
	| RIGHTSHIFT_ASSIGN  { $$ = new std::string(">>="); }
	| AND_ASSIGN         { $$ = new std::string("&="); }
	| XOR_ASSIGN         { $$ = new std::string("^="); }
	| OR_ASSIGN          { $$ = new std::string("|="); }
	;

TYPE : T_INT   { $$ = new std::string("int"); }
     | T_VOID  { $$ = new std::string("void"); }
     ;

MATHS_STATEMENT : MATHS_STATEMENT '+' TERM { $$ = new AddOperator($1, $3); } 
                | MATHS_STATEMENT '-' TERM { $$ = new SubOperator($1, $3); }
                | TERM           { $$ = $1; }

TERM : TERM '*' UNARY { $$ = new MulOperator($1, $3); }
      | TERM '/' UNARY { $$ = new DivOperator($1, $3); }
      | UNARY          { $$ = $1; }

UNARY : '-' FACTOR            { $$ = new NegOperator($2); }
      | FACTOR        { $$ = $1; }

FACTOR : T_IDENTIFIER     { $$ = new Variable( *$1 ); }
       | T_NUMBER   { $$ = new Number( $1 ); }
       | '(' MATHS_STATEMENT ')' { $$ = $2; } 

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
