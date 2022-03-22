#ifndef ast_enums_hpp
#define ast_enums_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ast_expression.hpp"
#include "ast/ast_expressionlist.hpp"
#include "context.hpp"


//________________________________________________


class Enum
    : public Expression
{
private:
    ExpressionPtr id;
    ExpressionListPtr enumeration_list;
public:
    Enum(ExpressionPtr _id)
        : id(_id)
    {}

    Enum(ExpressionPtr _id, ExpressionListPtr _enumeration_list)
        : id(_id)
        , enumeration_list(_enumeration_list)
    {}

    Enum(ExpressionListPtr _enumeration_list)
        : enumeration_list(_enumeration_list)
    {}

    virtual std::string getId() const override
    { return id->getId(); }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"ENUM : ";
        dst<<id->getId()<<":";

        for (int i = 0; i < enumeration_list->list.size(); i++){
            enumeration_list->list[i]->print(dst);
            dst<<",";
        }
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        std::vector<enumeration> enums;

        for (int i = 0; i < enumeration_list->list.size(); i++){
            enumeration_list->list[i]->generateENUM(i, context);
        }
        for (int i = 0; i < enumeration_list->list.size(); i++)
            dst<<"#DEBUG ENUM: "<<context.enums[i].id<<" <-> "<<context.enums[i].value<<'\n';
        context.global_enums.insert({id->getId(), enums});

        // context.enums.clear();
    }
   
};

class AssignEnum
    : public Expression
{
private:
    std::string id;
    ExpressionPtr value;  

public:
    AssignEnum(std::string _left, ExpressionPtr _right)
        : id(_left)
        , value(_right)
    {}

    virtual void print(std::ostream &dst) const override
    { 
        dst<<id<<" = ";
        value->print(dst);
    }

    virtual void generateENUM(int counter, Context &context) const override
    { 
        enumeration en;
        en.id = id;
        en.value = value->getValue(); // will not work if the RHS is anything else just an Integer()
        context.enums.push_back(en);
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {    }
};


class EnumDeclarator
    : public Expression
{
private:
    std::string id;
public:
    EnumDeclarator(const std::string &_id)
        : id(_id)
    {}

    std::string getId() const override
    { return id; }

    virtual void print(std::ostream &dst) const override
    {
        dst<< "(ENUM DECALARATOR :";
        dst<<id<<")";
    }

    virtual void generateENUM(int counter, Context &context) const override
    {
        enumeration en;
        en.id = id;
        en.value = counter;
        context.enums.push_back(en);
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {    }
    
};

#endif