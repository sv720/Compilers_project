#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ast/ast_expressionlist.hpp"

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

    virtual void generateMIPS(std::ostream &dst, std::map<std::string, std::vector<int>> &variables_map, std::map<int, bool> &live_variables) const override
    {
        // we need to access register number, through a function so we realise how far down from fp the variable is
        dst<<"lw $2,"; // need to set other register, depending on free
        dst<<"8($fp)"<<'\n'; //specific location in stack for the variable (to check in alive variables vector)
        // dst<<id<<'\n'; //id is variable name, here we will need register assigned to that variable, a scan function in the vector of alive/used regs
    }
   
};


class Integer
    : public Expression
{
private:
    int value;
public:
    Integer()
    {}

    Integer(int _value)
        : value(_value)
    {}

    int getValue() const
    { return value; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<value;
    }

    virtual void generateMIPS(std::ostream &dst, std::map<std::string, std::vector<int>> &variables_map, std::map<int, bool> &live_variables) const override
    {
        dst<<"li $2,"; // need to set other register
        dst<<value<<'\n'; 
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

    virtual void print(std::ostream &dst) const override
    {
        dst<<"return ";
        arg->print(dst);
    }
    
    virtual void generateMIPS(std::ostream &dst, std::map<std::string, std::vector<int>> &variables_map, std::map<int, bool> &live_variables) const override
    {
        arg->generateMIPS(dst, variables_map, live_variables);
    }

};


//________________________________________________

class Root
    : public Expression
{
private:
    ExpressionListPtr arg;
public:
    Root(ExpressionListPtr _arg)
        : arg(_arg)
    {}

    virtual void print(std::ostream &dst) const override
    {
        arg->print(dst);
    }

    virtual void generateMIPS(std::ostream &dst, std::map<std::string, std::vector<int>> &variables_map, std::map<int, bool> &live_variables) const override
    {
        arg->generateMIPS(dst, variables_map, live_variables);
    }

};



#endif
