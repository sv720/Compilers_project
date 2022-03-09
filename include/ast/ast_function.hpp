#ifndef ast_function_hpp
#define ast_function_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ast_expression.hpp"

//FUNCTION______________________________________

class Full_Function
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionListPtr right;  
public:
    Full_Function(ExpressionPtr _left, ExpressionListPtr _right)
        : left(_left)
        , right(_right)
    {}

    Full_Function(ExpressionPtr _left)
        : left(_left)
    {}

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionListPtr getRight() const
    { return right; }
    //no member functions yet

    virtual void print(std::ostream &dst) const override
    {
        dst<<"( ";
        left->print(dst);
        dst<<" ";
        // right->print(dst);
        for (ExpressionPtr e : right->list) {
            e->print(dst);
        }
        dst<<" )";
    }
};

class Function_Definition
    : public Expression
{
private:
    std::string left;
    ExpressionPtr right;  
public:
    Function_Definition(const std::string &_left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}

    const std::string getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }
    //no member functions yet

    virtual void print(std::ostream &dst) const override
    {
        dst<<left<<" ";
        right->print(dst);
    }
};


#endif