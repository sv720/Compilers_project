#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ast/ast_expressionlist.hpp"
#include "context.hpp"

class Variable
    : public Expression
{
private:
    std::string id;
public:
    Variable(const std::string &_id)
        : id(_id)
    {}

    virtual std::string getId() const override
    { return id; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"VARAIBLE : ";
        dst<<id;
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        // we need to access register number, through a function so we realise how far down from fp the variable is
        dst<<"lw $"<<destReg<<","; // need to set other register, depending on free
        dst<<(4*(context.variables_map.size() - context.variables_map[id].old_map_size) + 8)<<"($fp)"<<'\n'; 
        //specific location in stack for the variable (to check in alive variables vector)
        // we add +8 as the old_fp is stored in the relative location of +4
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

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"li $"<<destReg<<","; // need to set other register
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
    
    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        arg->generateMIPS(dst, context, 2);
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

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<".global f"<<'\n';
        arg->generateMIPS(dst, context, destReg);
    }

};



#endif
