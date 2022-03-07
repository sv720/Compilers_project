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

// Represents the value associated with any kind of AST node.
%union{
  const Expression *expr;
  ExprList *exprList;
  int number;
  double numberFloat;
  std::string *string;
  yytokentype token;
}

%token IDENTIFIER INT_LITERAL STRING_LITERAL SIZEOF
%token POINTER_OP INCREMENT_OP DECREMENT_OP LEFTSHIFT_OP RIGHTSHIFT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFTSHIFT_ASSIGN RIGHTSHIFT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER 
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%type <expr> cast_expression

%type <expr> primary_expression postfix_expression unary_expression
%type <expr> multiplicative_expression additive_expression shift_expression
%type <expr> relational_expression equality_expression and_expression
%type <expr> exclusive_or_expression inclusive_or_expression logical_and_expression
%type <expr> logical_or_expression conditional_expression assignment_expression
%type <expr> expression constant_expression

%type <expr> declaration init_declarator
// %type <expr> declaration_specifiers //string for now
%type <expr> struct_declaration
%type <expr> struct_declarator declarator
%type <expr> enum_specifier enumerator direct_declarator pointer

%type <expr> parameter_declaration type_name abstract_declarator direct_abstract_declarator
%type <expr> initializer statement labeled_statement compound_statement
%type <expr> expression_statement selection_statement iteration_statement
%type <expr> jump_statement external_declaration function_definition

%type <exprList> translation_unit struct_declaration_list argument_expression_list
%type <exprList> specifier_qualifier_list struct_declarator_list
%type <exprList> enumerator_list parameter_list init_declarator_list
%type <exprList> identifier_list initializer_list declaration_list statement_list

%type <number> INT_LITERAL // CHAR_LITERAL
// %type <numberFloat> FLOAT_LITERAL
%type <string> IDENTIFIER assignment_operator declaration_specifiers type_specifier


%start ROOT

%%

ROOT : external_declaration			{ g_root = $1; /*translation_unit*/ }

translation_unit
	: external_declaration     					{ $$ = initExprList($1); }               
	| translation_unit external_declaration   	{ $$ = appendToExprList($1, $2); }
	;

external_declaration
	: function_definition		{ $$ = $1; }
	| declaration				{ $$ = $1; }
	;

function_definition
	// : declaration_specifiers declarator compound_statement { $$ = new Full_Function(new Function_Definition(*$1, $2), $3); }
	: declaration_specifiers declarator '{' statement_list '}'		{ $$ = new Full_Function(new Function_Definition(*$1, $2), $4); }
	| declaration_specifiers declarator '{' declaration_list '}'	{ $$ = new Full_Function(new Function_Definition(*$1, $2), $4); }
	| declaration_specifiers declarator '{' declaration_list statement_list '}'	{;}
	| declaration_specifiers declarator '{' '}'						{$$ = new Full_Function(new Function_Definition(*$1, $2));}
	| declarator 
	;

declarator
	: pointer direct_declarator
	| direct_declarator				{ $$ = $1; }
	;

direct_declarator
	: IDENTIFIER										{ $$ = new Declarator(*$1);}
	| '(' declarator ')'								{ $$ = $2; }
	| direct_declarator '[' constant_expression ']'		{ ;}
	| direct_declarator '(' parameter_list ')'			{ ;}
	| direct_declarator '(' identifier_list ')'			{ ;}
	| direct_declarator '(' ')'							{ $$ = new FunctionDeclarator($1);;}
	;

/* from direct_declarator */
parameter_list
	: parameter_declaration						{ $$ = initExprList($1); } 
	| parameter_list ',' parameter_declaration	{ $$ = appendToExprList($1, $3); }
	;
	
parameter_declaration
	: declaration_specifiers declarator				{ $$ = new Declare(*$1, $2);}
	| declaration_specifiers abstract_declarator	{ $$ = new Declare(*$1, $2);}
	| declaration_specifiers
	;

/* from external_declaration */
declaration
	: declaration_specifiers ';'						{ ; }
	| declaration_specifiers init_declarator ';'	{ $$ = new Declare(*$1, $2);}
	;

/* from init_declarator & parameter_declaration*/
declaration_specifiers
	: type_specifier									{ $$ == $1; }
	| type_specifier declaration_specifiers
	| TYPEDEF
	| TYPEDEF declaration_specifiers
	;


/* from declaration */
init_declarator
	: declarator						{ $$ = $1; }
	| declarator '=' initializer		{ $$ = new InitDeclarator($1, $3); }
	;

/* from init_declarator */
initializer
	: assignment_expression			{ $$ = $1; }
	| '{' initializer_list '}'		{ ; /*list to expr, need a class for creating an exprPtr to list */}
	| '{' initializer_list ',' '}'	{ ; /* same */ }
	;

initializer_list
	: initializer						{ $$ = initExprList($1); } 
	| initializer_list ',' initializer	{ $$ = appendToExprList($1, $3); }
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'						{ $$ = $2; }
	| '[' ']'													{ ; }
	| '[' constant_expression ']'								{ ; }
	| direct_abstract_declarator '[' ']'						{ ; }
	| direct_abstract_declarator '[' constant_expression ']'	{ ; }
	| '(' ')'													{ ; }
	| '(' parameter_list ')'									{ ; }
	| direct_abstract_declarator '(' ')'						{ ; }
	| direct_abstract_declarator '(' parameter_list ')'			{ ; }
	;

/* from function_definition */
compound_statement
	: '{' '}'										{ ;}
	| '{' statement_list '}'						{ ;}
	| '{' declaration_list '}'						{ ;}
	| '{' declaration_list statement_list '}'		{ ;}
	;

declaration_list
	: declaration					{ $$ = initExprList($1); } 
	| declaration_list declaration	{ $$ = appendToExprList($1, $2); }
	;

/* from compound_statement */
statement_list
	: statement					{ $$ = initExprList($1); } 
	| statement_list statement	{ $$ = appendToExprList($1, $2); }
	;

statement
	: labeled_statement		{ $$ = $1; }
	| expression_statement	{ $$ = $1; }
	| selection_statement	{ $$ = $1; }
	| iteration_statement	{ $$ = $1; }
	| jump_statement		{ $$ = $1; }
	// | compound_statement	{ $$ = $1; /*at the moment compound_statement is avoided so we can add its versions below*/} 
	| '{' '}'										{ ; /*same problem converting an ExprList into Expression*/}
	| '{' statement_list '}'						{ $$ = new Scope($2);}
	| '{' declaration_list '}'						{ $$ = new Scope($2);}
	| '{' declaration_list statement_list '}'		{ ;}
	;

/* from statement */
labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;
/* from statement */
expression_statement
	: ';'
	| expression ';'
	;
/* from statement */
selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	;
/* from statement */
iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;
/* from statement */
jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';' 			{ ; }
	| RETURN expression ';' { $$ = new Return($2); }
	;


/* new */
primary_expression
	: IDENTIFIER			{ $$ = new Variable( *$1 );}
	| INT_LITERAL			{ $$ = new Number( $1 );}
	// | FLOAT_LITERAL			{ ;}
	// | CHAR_LITERAL			{ ;}
	| '(' expression ')'	{ $$ = $2; }
	;

postfix_expression
	: primary_expression									{ $$ = $1; }
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression POINTER_OP IDENTIFIER
	| postfix_expression INCREMENT_OP
	| postfix_expression DECREMENT_OP
	;

argument_expression_list
	: assignment_expression									{ $$ = initExprList($1); } 
	| argument_expression_list ',' assignment_expression	{ $$ = appendToExprList($1, $3); }
	;

unary_expression
	: postfix_expression				{ $$ = $1; }
	| INCREMENT_OP unary_expression
	| DECREMENT_OP unary_expression
	| unary_operator cast_expression
	| '-' unary_expression				{ $$ = new NegOperator($2); }
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression					{ $$ = $1; }
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression									{ $$ = $1; }
	| multiplicative_expression '*' cast_expression		{ $$ = new MulOperator($1, $3); }
	| multiplicative_expression '/' cast_expression		{ $$ = new DivOperator($1, $3); }
	| multiplicative_expression '%' cast_expression		{;}
	;

additive_expression
	: multiplicative_expression								{ $$ = $1; }
	| additive_expression '+' multiplicative_expression		{ $$ = new AddOperator($1, $3); }
	| additive_expression '-' multiplicative_expression		{ $$ = new SubOperator($1, $3); }
	;

shift_expression
	: additive_expression									{ $$ = $1; }
	| shift_expression LEFTSHIFT_OP additive_expression
	| shift_expression RIGHTSHIFT_OP additive_expression
	;

relational_expression
	: shift_expression									{ $$ = $1; }
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression								{ $$ = $1; }
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression						{ $$ = $1; }
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression								{ $$ = $1; }
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression								{ $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression									{ $$ = $1; }
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression								{ $$ = $1; }
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression												{ $$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression     { $$ = $1; }   
	| unary_expression assignment_operator assignment_expression    { $$ = new AssignOperator($1, *$2, $3);  }
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

expression
	: assignment_expression						{$$ = $1; /*{ $$ = initExprList($1); }*/} 
	| expression ',' assignment_expression		{ /*$$ = appendToExprList($1, $2); */}
	;

constant_expression
	: conditional_expression
	;

//Start reading from hear up



type_specifier
	: VOID			{ $$ = new std::string("void"); }
	| CHAR
	| SHORT
	| INT			{ $$ = new std::string("int"); }
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	// | struct_specifier
	| enum_specifier
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST
	| VOLATILE
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;




identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;






%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}