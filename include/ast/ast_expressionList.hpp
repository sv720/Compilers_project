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
  ExpressionList(std::vector<ExpressionPtr> nodes);
  ExpressionList();

  // Destructor
  virtual ~ExpressionList();

  // Visualising
//   virtual void PrettyPrint(std::ostream &dst, std::string indent) const override;

  // Get stuff in list (codegen)
  virtual ExpressionListPtr getExpression(unsigned index) const override;
};

#endif