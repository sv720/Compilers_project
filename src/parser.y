%code requires{
  #include "../include/ast.hpp"

  #include <cassert>

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

%token T_TIMES T_DIVIDE T_PLUS T_MINUS T_EXPONENT T_EQUAL
%token T_LBRACKET T_RBRACKET T_LCURBRACKET T_RCULBRACKET T_SEMICOLON T_COMMA
%token T_LSQBRACKET T_RSQBRACKET T_COLON T_TILDE T_HASH T_EXCLAMATIONMARK T_QUESTIONMARK
%token T_LOG T_EXP T_SQRT T_RETURN T_IF T_WHILE T_FOR T_BREAK
%token T_NUMBER T_VALUE T_VARIABLE T_TYPE FUNCTION_NAME

%type <expr> FUNCTION T_TYPE ARGUMENT LINES EXPR INITIALISE DEFINE OPERATIONS CONDITION FOR_CONDITION FOR_STEP EQUATION TERM UNARY FACTOR
%type <number> T_NUMBER T_VALUE
%type <string> T_VARIABLE T_LOG T_EXP T_SQRT FUNCTION_NAME

%start ROOT

%%

ROOT  : EQUATION          { g_root = $1; }
      // | ROOT FUNCTION

// FUNCTION    : T_TYPE FUNCTION_NAME T_LBRACKET          T_RBRACKET T_LCURBRACKET LINES T_RCULBRACKET
//             | T_TYPE FUNCTION_NAME T_LBRACKET ARGUMENT T_RBRACKET T_LCURBRACKET LINES T_RCULBRACKET 
//             | T_TYPE FUNCTION_NAME T_LBRACKET          T_RBRACKET T_SEMICOLON
//             | T_TYPE FUNCTION_NAME T_LBRACKET ARGUMENT T_RBRACKET T_SEMICOLON

// ARGUMENT    : INITIALISE
//             | INITIALISE T_COMMA ARGUMENT

// LINES       : EXPR T_SEMICOLON
//             | LINES EXPR T_SEMICOLON  //version 1 - agreed on

// EXPR        : INITIALISE
//             | DEFINE
//             | OPERATIONS
//             | T_RETURN EQUATION

// INITIALISE  : T_TYPE T_VARIABLE
// DEFINE      : T_TYPE T_VARIABLE T_EQUAL T_VALUE
//             | T_VARIABLE T_EQUAL EQUATION

// OPERATIONS  : T_IF    T_LBRACKET CONDITION T_RBRACKET T_LCURBRACKET LINES T_RCULBRACKET
//             | T_WHILE T_LBRACKET CONDITION T_RBRACKET T_LCURBRACKET LINES T_RCULBRACKET
//             | T_FOR T_LBRACKET FOR_CONDITION T_RBRACKET T_LCURBRACKET LINES T_RCULBRACKET

// CONDITION   : EQUATION T_EQUAL T_EQUAL EQUATION
// // <= >= < > comparisons tokens

// FOR_CONDITION : DEFINE T_SEMICOLON CONDITION T_SEMICOLON FOR_STEP

// FOR_STEP  : T_VARIABLE OPERATOR OPERATOR
//           | OPERATOR OPERATOR T_VARIABLE
//           | T_VARIABLE OPERATOR T_EQUAL

// OPERATOR  : T_PLUS
//             | T_MINUS
//             | T_TIMES
//             | T_DIVIDE
            

EQUATION  : EQUATION T_PLUS TERM             { $$ = new AddOperator( $1 , $3 );}
          | EQUATION T_MINUS TERM            { $$ = new SubOperator( $1 , $3 );}
          | TERM                             { $$ = $1; }

TERM : TERM T_TIMES UNARY           { $$ = new MulOperator( $1 , $3 );}
     | TERM T_DIVIDE UNARY          { $$ = new DivOperator( $1 , $3 );}
     | UNARY                        { $$ = $1; }

UNARY : T_MINUS FACTOR              { $$ = new NegOperator( $2 );}
      | FACTOR                      { $$ = $1; }

FACTOR : T_NUMBER                   { $$ = new Number( $1 );} 
       | T_VARIABLE                 { $$ = new Variable( *$1 );}

       | FACTOR T_EXPONENT UNARY    { $$ = new ExpOperator( $1 , $3 );}

//        | FUNCTION_NAME T_LBRACKET EQUATION T_RBRACKET       {   if (*$1 == "log")   {$$ = new LogFunction( $3 );}
//                                                             if (*$1 == "exp")   {$$ = new ExpFunction( $3 );}
//                                                             if (*$1 == "sqrt")  {$$ = new SqrtFunction( $3 );}
//                                                           }
       | T_LBRACKET EQUATION T_RBRACKET { $$ = $2; }


// FUNCTION_NAME : T_LOG   { $$ = new std::string("log"); }
//               | T_EXP   { $$ = new std::string("exp"); }
//               | T_SQRT  { $$ = new std::string("sqrt"); }

%%

const Expression *g_root;

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}