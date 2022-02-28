#ifndef ast_nodeList_hpp
#define ast_nodeList_hpp

#include "ast_expression.hpp"

class ExpressionList;
typedef ExpressionList *ExpressionListPtr;

class ExpressionList
  : public Expression
{
public:
  // Constructors
  ExpressionList()
    : ExpressionList(std::vector<ExpressionPtr>{})
  {}
  ExpressionList(std::vector<ExpressionPtr> expressions){
    branches = expressions;
  }
  

  // Destructor
  virtual ~ExpressionList();

  // Visualising
//   virtual void PrettyPrint(std::ostream &dst, std::string indent) const override;

  // Get stuff in list (codegen)
  virtual ExpressionPtr getExpression(unsigned index) const{
    if(index < branches.size()){
      return branches[index];
    }
    else{
      return NULL;
    }
  }


};

#endif