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

    virtual std::string getId() const 
    {
        return "<NULL>";
    }
    
    virtual std::string getNature() const //Will be used to determine if we are assigning to an array or a variable 
    { return "<NULL>";  }

    virtual int getValue() const //for enums, as they are not considered in the mips generation, all of its assignments are done in compiler
    { return -1; }

    virtual ExpressionPtr getSize() const //for enums, as they are not considered in the mips generation, all of its assignments are done in compiler
    { return NULL; }

    virtual void generateENUM(int counter, Context &context) const
    { }
    
    virtual std::string found_in_f(Context &context, std::string id, std::string function) const 
    { return "<NULL>"; }
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
