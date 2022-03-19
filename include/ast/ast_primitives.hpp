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
        variable v;
        v.reg = destReg;
        v.old_map_size = context.variables_map.size() +1; //------------------------------
        context.variables_map.insert({id, v});
        dst<<"#DEBUG Declarator: adding to map at address" << id << " making map size = "<< context.variables_map.size() <<'\n';

        //TODO: check if valid
        int curr_offset = 4*(context.variables_map.size() - context.variables_map[id].old_map_size) + 8;
        dst<<"lw $"<<destReg<<","; // need to set other register, depending on free
        dst<<curr_offset<<"($fp)"<<'\n'; //specific location in stack for the variable (to check in alive variables vector)
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
        // dst<<"move $sp,$fp"<<'\n';
        // dst<<"lw $fp,4($sp)"<<'\n'; // check alive variables vector
        // dst<<"move $sp,$25"<<'\n';
        // dst<<"jr $31"<<'\n';
        // dst<<"nop"<<'\n';
        dst<<"j end_"<<context.current_function<<'\n';
        dst<<"nop"<<'\n';
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
        // dst<<".cprestore 8"<<'\n';
        arg->generateMIPS(dst, context, destReg);
    }

};



#endif
