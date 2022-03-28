#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ast/ast_expressionlist.hpp"
#include "context.hpp"

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
        c = id[1]; // not index 0????????
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
        dst<<"#DEBUG: calling generateMIPS on arg in return \n";
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

//________________________________________________

class SizeOf
    : public Expression
{
private:
    ExpressionPtr id;
public:
    SizeOf(ExpressionPtr _id)
        : id(_id)
    {}

    virtual void print(std::ostream &dst) const override
    {
        dst<<"sizeof: ";
        id->print(dst);
    }
    
    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#DEBUG: calling generateMIPS on arg is return \n";
        
        if (id->getId() == "int" || id->getId() == "char") {
            int reg = context.allocate(context.current_function);
            id->generateMIPS(dst, context, reg);
            dst<<"move $"<<destReg<<", $"<<reg<<'\n';
            context.regFile.freeReg(reg);
        } 
        else {
            dst<<"li $"<<destReg<<", "<<context.functions[id->found_in_f(context, id->getId(), context.current_function)].variables_map[id->getId()].size<<'\n';
        }
    }

};

//________________________________________________

class TypeSpecifier
    : public Expression
{
private:
    std::string id;
public:
    TypeSpecifier(std::string _id)
        : id(_id)
    {}

    std::string getId() const override
    {
        return id;
    }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"TypeSpecifier: "<<id;
    }
    
    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        // sizes of the types
        if (id == "int") {
            dst<<"li $"<<destReg<<", "<<4<<'\n';
        } else
        if (id == "unsigned int") {
            dst<<"li $"<<destReg<<", "<<4<<'\n';
        } else
        if (id == "char") {
            dst<<"li $"<<destReg<<", "<<1<<'\n';
        } else
        if (id == "double") {
            dst<<"li $"<<destReg<<", "<<8<<'\n';
        } else
        if (id == "float") {
            dst<<"li $"<<destReg<<", "<<4<<'\n';
        } 
        
    }

};

//________________________________________________

class ChangeType
    : public Expression
{
private:
    std::string new_type;
    ExpressionPtr id;
public:
    ChangeType(std::string _type, ExpressionPtr id)
        : new_type(_type)
        , id (id)
    {}

    std::string getId() const override
    {
        return id->getId();
    }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"ChangeType: "<<id;
    }
    
    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        context.functions[id->found_in_f(context, id->getId(), context.current_function)].variables_map[id->getId()].type = new_type;
        if (new_type == "int") {
            context.functions[id->found_in_f(context, id->getId(), context.current_function)].variables_map[id->getId()].size = 4;
        } else
        if (new_type == "char") {
            context.functions[id->found_in_f(context, id->getId(), context.current_function)].variables_map[id->getId()].size = 1;
        }
    }

};


#endif
