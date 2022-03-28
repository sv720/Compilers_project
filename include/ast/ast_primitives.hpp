#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include "ast/ast_expressionlist.hpp"
#include "context.hpp"

// class Variable
//     : public Expression
// {
// private:
//     std::string id;
// public:
//     Variable(const std::string &_id)
//         : id(_id)
//     {}

//     virtual std::string getId() const override
//     { return id; }

//     virtual void print(std::ostream &dst) const override
//     {
//         dst<<"VARAIBLE : ";
//         dst<<id;
//     }

//     virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
//     {
//         variable v;
//         v.reg = destReg;
//         v.old_map_size = context.functions[context.current_function].variables_map.size() +1; //------------------------------
//         context.functions[context.current_function].variables_map.insert({id, v});
//         dst<<"#DEBUG Declarator: adding to map at address" << id << " making map size = "<< context.functions[context.current_function].variables_map.size() <<'\n';

//         //TODO: check if valid
//         int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[id].old_map_size) + 12;
//         dst<<"lw $"<<destReg<<","; // need to set other register, depending on free
//         dst<<curr_offset<<"($fp)"<<'\n'; //specific location in stack for the variable (to check in alive variables vector) //S: Does this do anything? TODO : check if can remove
//     }
   
// };


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

class Float
    : public Expression
{
private:
    float value;
    int s; //sign
    int e; //exponent plus 1023 
    int f; //stores binary fration (with leading 1 implcit) e.g. 1.011=>011
public:
    Float()
    {
        if (value >= 0){
            s=0;
        }
        else { s=1; }
        
        e = (int) log10(value);
        f = (int) ((value/e)-1)*8388608; //should store the int value of 23 decimal points (large multiplier is 2^23 ; 23 is size of f field)
    }

    Float(float _value)
        : value(_value)
    {}


    virtual void print(std::ostream &dst) const override
    {
        dst<<"FLOAT VALUE = ";
        dst<<value;
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"li $"<<destReg<<","; // need to set other register
        dst<<value<<'\n'; 
    }
};

class Double
    : public Expression
{
private:
    double value;
public:
    Double()
    {}

    Double(int _value)
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


class Character
    : public Expression
{
private:
    std::string id;
    char c;

public:
    Character(const std::string &_id)
        : id(_id)
    {
        c = id[1];
    }

    std::string getId() const override
    {
        return id;
    }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"id = "<<id<< "and";
        dst<<"CHAR_LITERAL c = "<<c;
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"li $"<<destReg<<","; // need to set other register
        dst<<(int)c<<'\n'; 
    }


   // int getValue() const
    //{
     //   return int(c); //should return ASCII value of the character
    //}
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
        dst<<"#DEBUG: calling generateMIPS on arg is return \n";
        arg->generateMIPS(dst, context, 2);
        
        dst<<"j end_"<<context.current_function_name<<'\n';
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
        // dst<<".global "; //must be called after generating all mips so we know which function to add here
        // for (std::string f_name : context.functions_names) {
        //     dst<<f_name<<' ';
        // }
        // dst<<'\n';
        // dst<<".cprestore 8"<<'\n';
        arg->generateMIPS(dst, context, destReg);
    }

};



#endif
