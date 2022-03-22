#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_expression.hpp"
#include "ast/ast_expressionlist.hpp"

#include "ast/ast_primitives.hpp"

#include "ast/ast_operators.hpp"
#include "ast/ast_unary.hpp"
#include "ast/ast_selection_statements.hpp"
#include "ast/ast_iteration_statements.hpp"

#include "ast/ast_function.hpp"
#include "ast/ast_array.hpp"
#include "ast/ast_enums.hpp"
#include "ast/ast_assign_declare.hpp"

// #include "ast/ast_available_registers.hpp"
#include "context.hpp"

#include <vector>

extern const Expression *parseAST(std::string input_file);


inline ExpressionListPtr initExprList(ExpressionPtr first_elem){
    ExpressionListPtr exprList = new ExpressionList();
    exprList->list.push_back(first_elem);
    // std::cout<<"DEBUG: parser:initialise size list = "<< exprList->list.size() <<" with elem: " << first_elem<< std::endl;
    return exprList;
}

inline void appendToExprList(ExpressionListPtr &in_exprList, ExpressionPtr new_elem){
    in_exprList->list.push_back(new_elem);
    // std::cout<<"DEBUG: parser:size list = "<< in_exprList->list.size() << " with elem: " << new_elem << std::endl;
    // return in_list;
}



#endif
