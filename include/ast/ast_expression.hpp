#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>
#include <vector>

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
    virtual void generateMIPS(std::ostream &dst, std::map<std::string, int> &variables_map, std::map<int, bool> &live_variables) const =0;

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
    virtual void generateMIPS(std::ostream &dst, std::map<std::string, int> &variables_map, std::map<int, bool> &live_variables) const override
    {}
};


#endif
