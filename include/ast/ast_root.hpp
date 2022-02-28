#ifndef ast_root_hpp
#define ast_root_hpp

#include "ast_expression.hpp"

// Top-level entity in our AST, holds the global scope

class Root
  : public Expression
{
public:
  // Constructor
  Root(ExpressionPtr globalSequence)
  {
    branches.push_back(globalSequence);
  }

  // Destructor
  virtual ~Root(){
    delete branches[0];
  }

  // Visualising
//   void PrettyPrint(std::ostream &dst, std::string indent) const override;

  // Codegen
//   void generateMIPS(std::ostream &dst, Context &context, int destReg) const override;
};

#endif