#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>
#include <vector>
#include "context.hpp"

class Expression;

typedef const Expression *ExpressionPtr;

class Expression
{
// protected:
//     std::vector<ExpressionPtr> list;
public:
    Expression()
    {}

    virtual ~Expression()
    {}


    //! Tell and expression to print itself to the given stream
    virtual void print(std::ostream &dst) const =0;
    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const =0;

    // virtual std::string getDeclarator() const {};

    virtual std::string getId() const //TODO: check if this is desirable
    {
        return "<NULL>";
    }
};

class EmptyExpr
    : public Expression
{
    public:
    EmptyExpr()
    {}

    virtual ~EmptyExpr()
    {}
    virtual void print(std::ostream &dst) const override
    {}
    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {}
};


#endif
