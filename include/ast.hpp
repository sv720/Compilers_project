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

// typedef std::vector<ExpressionPtr> ExprList;
// typedef ExprList *ExprListPtr;

inline ExpressionListPtr initExprList(ExpressionPtr first_elem){
    ExpressionListPtr list = new ExpressionList();
    list->list.push_back(first_elem);
    std::cout<<"DEBUG: parser:initialise size list = "<< list->list.size() <<" with elem: " << first_elem<< std::endl;
    return list;
}

inline void appendToExprList(ExpressionListPtr &in_list, ExpressionPtr new_elem){
    in_list->list.push_back(new_elem);
    std::cout<<"DEBUG: parser:size list = "<< in_list->list.size() << " with elem: " << new_elem << std::endl;
    // return in_list;
}

// inline ExpressionPtr initExprListPtr(ExprListPtr in_list){
//     ExpressionPtr listPtr;
//     listPtr = in_list;
//     return listPtr;
// }

#endif
