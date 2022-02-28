#ifndef ast_declaration_hpp
#define ast_declaration_hpp

#include "ast_expression.hpp"
// #include "ast_identifier.hpp"

// Represents declarations as type (i.e. int) + what the declaration actually is, which could be a bunch of stuff

class Declaration
  : public Expression
{
public:
  // Constructors
  Declaration(ExpressionPtr type, ExpressionPtr id)
  {
    branches.push_back(type);
    branches.push_back(id);
  }
  // Declaration(ExpressionPtr type)
  //   : Declaration(type, new Identifier("<NULL>"))
  // {}

  // Destructor
  virtual ~Declaration()
  {
    delete branches[0];
    delete branches[1];
  }

  // Visualising
  // void PrettyPrint(std::ostream &dst, std::string indent) const override;

  // Codegen + helpers
  // void generateMIPS(std::ostream &dst, Context &context, int destReg) const override;

};

#endif