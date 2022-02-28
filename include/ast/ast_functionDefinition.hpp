#ifndef ast_functionDefinition_hpp
#define ast_functionDefinition_hpp

#include "ast_expression.hpp"

// Represents a function as a declaration + {shit in here}, where the scope node contains the shit

class FunctionDefinition
  : public Expression
{
public:
    // Constructors
    FunctionDefinition(ExpressionPtr declaration, ExpressionPtr scope)
    {
        branches.push_back(declaration);
        branches.push_back(scope);
    }

    // Destructor
    virtual ~FunctionDefinition();

    // Visualising
    //   void PrettyPrint(std::ostream &dst, std::string indent) const override;

    // Codegen + helpers
    //   void generateMIPS(std::ostream &dst, Context &context, int destReg) const override;
    bool isFunction() const {
        return true;
    }
};

#endif
