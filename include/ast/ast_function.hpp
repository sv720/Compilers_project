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
        , right(new ExpressionList())
    {}

    virtual ~Full_Function()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionListPtr getRight() const
    { return right; }

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

    virtual ~Function_Definition()
    {
        delete right;
    }

    const std::string getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<left<<" ";
        right->print(dst);
    }
};

class FunctionDeclarator
    : public Expression
{
private:
    ExpressionPtr id;
    ExpressionListPtr arg;
public:
    FunctionDeclarator(ExpressionPtr _id)
        : id(_id)
        , arg(new ExpressionList())
    {}

    FunctionDeclarator(ExpressionPtr _id, ExpressionListPtr _arg)
        : id(_id)
        , arg(_arg)
    {}

    ~FunctionDeclarator(){
        delete id;
        delete arg;
    }

    ExpressionPtr getId() const
    { return id; }

    ExpressionListPtr getArg() const
    { return arg; }

    virtual void print(std::ostream &dst) const override
    {
        id->print(dst);
        arg->print(dst);
    }
    
};


class FunctionCall
    : public Expression
{
private:
    ExpressionPtr functionName;  
    ExpressionListPtr args;
public:
    FunctionCall(ExpressionPtr _functionName)
        : functionName(_functionName)
        , args(new ExpressionList())
    {}

    FunctionCall(ExpressionPtr _functionName, ExpressionListPtr _args)
        : functionName(_functionName)
        , args(_args)
    {}

    virtual ~FunctionCall()
    {
        delete functionName;
        delete args;
    }

    ExpressionPtr getFunctionName() const
    { return functionName; }

    ExpressionListPtr getArgs() const
    { return args; }

    virtual void print(std::ostream &dst) const override
    {
        functionName->print(dst);
        dst<<"(:";
        for (ExpressionPtr e : args->list) {
            e->print(dst);
        }
        dst<<":)";
    }
};


#endif