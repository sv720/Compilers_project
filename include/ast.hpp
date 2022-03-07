#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_expression.hpp"
#include "ast/ast_primitives.hpp"
#include "ast/ast_operators.hpp"
#include "ast/ast_unary.hpp"
#include "ast/ast_functions.hpp"
#include "ast/ast_expressionlist.hpp"
#include <vector>

extern const Expression *parseAST();

typedef std::vector<ExpressionPtr> ExprList;
typedef ExprList *ExprListPtr;

inline ExprListPtr initExprList(ExpressionPtr first_elem){
    ExprListPtr list = new ExprList();
    list->push_back(first_elem);
    return list;
}

inline ExprListPtr appendToExprList(ExprListPtr in_list, ExpressionPtr new_elem){
    in_list->push_back(new_elem);
    return in_list;
}

// inline ExpressionPtr initExprListPtr(ExprListPtr in_list){
//     ExpressionPtr listPtr;
//     listPtr = in_list;
//     return listPtr;
// }

#endif
