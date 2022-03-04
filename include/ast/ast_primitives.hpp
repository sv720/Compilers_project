#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>

class Variable
    : public Expression
{
private:
    std::string id;
public:
    Variable(const std::string &_id)
        : id(_id)
    {}

    const std::string getId() const
    { return id; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<id;
    }

    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const override
    {
        // TODO-B : Run bin/eval_expr with a variable binding to make sure you understand how this works.
        // If the binding does not exist, this will throw an error
        return bindings.at(id);
    }    
};

class Number
    : public Expression
{
private:
    int value;
public:
    Number(int _value)
        : value(_value)
    {}

    int getValue() const
    { return value; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<value;
    }

    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const override
    {
        // TODO-A : Run bin/eval_expr with a numeric expression to make sure you understand how this works.
        return value;
    }
};


//FUNCTION______________________________________
class Function_Definition
    : public Expression
{
private:
    std::string left;
    ExpressionPtr right;  
public:
    Function_Definition(const std::string &_left, ExpressionPtr &_right)
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
//________________________________________________


class Return
    : public Expression
{
private:
    ExpressionPtr arg;
public:
    Return(ExpressionPtr _arg)
        : arg(_arg)
    {}
    
    virtual const char *getFunction() const
    { return "return"; }

    virtual void print(std::ostream &dst) const override
    {
        arg->print(dst);
    }

};


//________________________________________________

class Assign_Declare
    : public Expression
{
private:
    std::string left;
    ExpressionPtr right;  
public:
    Assign_Declare(std::string &_left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}

    virtual ~Assign_Declare()
    {
        delete right;
    }
    //no member functions yet
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

//________________________________________________

class AssignOperator
    : public Expression
{
private:
    std::string left;
    std::string middle;
    int right;  

public:
    AssignOperator(std::string _left, std::string _middle, int _right)
        : left(_left)
        , middle(_middle)
        , right(_right)
    {}
    //no member functions yet
    virtual void print(std::ostream &dst) const override
    {   
        dst<<left<<" "<<middle<<" "<<right;
    }
};

#endif
