#ifndef ast_functions_hpp
#define ast_functions_hpp

#include "ast_expression.hpp"

#include <cmath>

class Function
    : public Expression
{
private:
    ExpressionPtr arg;
protected:
    Function(ExpressionPtr _arg)
        : arg(_arg)
    {}
public:
    virtual ~Function()
    {
        delete arg;
    }

    virtual const char * getFunction() const =0;

    ExpressionPtr getArg() const
    { return arg; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<getFunction()<<"( ";
        arg->print(dst);
        dst<<" )";
    }

    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const override
    {
        // NOTE : This should be implemented by the inheriting function nodes, e.g. LogFunction
        double v = getArg()->evaluate(bindings); //traverse down args
        return v;

    }
};

class Statment
    : public Function
{
public:
    Statment(ExpressionPtr _arg)
        : Function(_arg)
    {}

};

class Return_Type
    : public Function
{
public:
    Return_Type(ExpressionPtr _arg)
        : Function(_arg)
    {}

};

class Function_name_Args
    : public Function
{
public:
    Function_name_Args(ExpressionPtr _arg)
        : Function(_arg)
    {}

};

class ExpFunction
    : public Function
{
public:
    ExpFunction(ExpressionPtr _arg)
        : Function(_arg)
    {}

    virtual const char *getFunction() const
    { return "exp"; }

    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const override
    { 
        double v = getArg()->evaluate(bindings); //traverse down args
        return exp(v);
    }
};

class SqrtFunction
    : public Function
{
public:
    SqrtFunction(ExpressionPtr _arg)
        : Function(_arg)
    {}

    virtual const char *getFunction() const
    { return "sqrt"; }

    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const override
    { 
        double v = getArg()->evaluate(bindings); //traverse down args
        return sqrt(v);
    }
};

#endif
