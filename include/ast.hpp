#ifndef ast_hpp
#define ast_hpp

#include <vector>

#include "ast/ast_expression.hpp"
#include "ast/ast_expressionList.hpp"
#include "ast/ast_root.hpp"

#include "ast/ast_primitives.hpp"
#include "ast/ast_operators.hpp"
#include "ast/ast_unary.hpp"
#include "ast/ast_functions.hpp"
//My addition
#include "ast/ast_assign.hpp"

extern const Expression *parseAST(std::string filename);

// static int makeNameUnq=0;

// static std::string makeName(std::string base)
// {
//     return "_"+base+"_"+std::to_string(makeNameUnq++);
// }




// Functions to be used in parser for instantiation / concatenation
typedef std::vector<ExpressionPtr> ExpressionList;
typedef ExpressionList *ListPtr;

// Functions to be used in parser for instantiation / concatenation
inline ListPtr initialiseList(ExpressionPtr expr)
{
  ListPtr exprList = new ExpressionList(); // Potentially replace with Nodelist(NodePtr) constructor
  exprList->push_back(expr);
  return exprList;
}

inline ListPtr addToList(ListPtr exprList, ExpressionPtr expr)
{
  exprList->push_back(expr);
  return exprList;
}

#endif