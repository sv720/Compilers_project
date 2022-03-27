#ifndef ast_expressionlist_hpp
#define ast_expressionlist_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include "ast/ast_expression.hpp"
#include "context.hpp"

class ExpressionList;

typedef std::vector<ExpressionPtr> ExprList;
// typedef ExprList *ExprListPtr;
typedef ExpressionList *ExpressionListPtr;

class ExpressionList
    : public Expression
{
   
public:
    std::vector<ExpressionPtr> list;

    //CONSTRUCTORS
    ExpressionList() 
    {   //std::cout<<"DEBUG: create list CONSTRUCTOR" << std::endl;
        list = {}; }

    // ExpressionList(ExpressionPtr first_elem)
    // {
    //     std::cout<<"DEBUG: create list" << std::endl;std::vector<ExpressionPtr>
    //     list = {};
    //     std::cout<<"DEBUG: single input constructor" << std::endl;
    //     list.push_back(first_elem);
    //     std::cout<<"DEBUG: size of list after adding first_elem = "<< list.size() <<'\n'<< std::endl;
    // }

    ExpressionList(ExpressionListPtr in_list)
        : list (in_list->list)
    {
        //DEBUG PRINT OUTS
        // std::cout<<"DEBUG: add in_list ";
        // list.push_back(in_list[0]);
        // for (int i =0; i < in_list->list.size(); i++)
        // {
        //     std::cout<< in_list->list[i] << std::endl;
        //     // list.push_back(in_list->list[i]);
        // }
        // std::cout<<"DEBUG: size of list after copying in_list = "<< list.size() << std::endl; 
    }

    // ExpressionList( in_list, ExpressionPtr new_elem)
    // {
    //     std::cout<<"DEBUG: dual input constructor" << std::endl;
    //     std::cout<<"DEBUG: size of in_list in dual input constructor = " << in_list->getListVector().size() << std::endl; 
    //     for (int i = 0; i < in_list->getListVector().size(); i++)
    //     {
    //         list.push_back(in_list->getListVector()[i]);
    //     }
    //     list.push_back(new_elem);

    //     std::cout<<"DEBUG: list.size() " << list.size()<<'\n' << std::endl;

    // }



    virtual ~ExpressionList()
    {
        for (ExpressionPtr i : list){
            delete i;
        }
    }

    virtual void append(ExpressionPtr new_elem)
    {
       list.push_back(new_elem);
    }

    virtual std::vector<ExpressionPtr> getListVector()
    {
        return list;
    }

    virtual void print(std::ostream &dst) const override
    {

        //std::cout<<"DEBUG in print; list.size() = " << list.size() << std::endl;
        for (ExpressionPtr i : list){
            //std::cout << "DEBUG address of ExpressionPtr =" << i << std::endl;
            dst<<"( ";
            i->print(dst);
            dst<<" )";
        }
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        for (ExpressionPtr i : list){
            i->generateMIPS(dst, context, destReg);
        }
    }
};

class Scope
    : public ExpressionList
{
   
public:
    std::vector<ExpressionPtr> list;

    //CONSTRUCTORS
    Scope() 
    { list = {}; }

    Scope(ExpressionListPtr in_list)
        : list (in_list->list)
    {}

    virtual ~Scope()
    {
        for (ExpressionPtr i : list){
            delete i;
        }
    }

    virtual void append(ExpressionPtr new_elem)
    {
       list.push_back(new_elem);
    }

    virtual std::vector<ExpressionPtr> getListVector()
    {
        return list;
    }

    virtual void print(std::ostream &dst) const override
    {

        //std::cout<<"DEBUG in print; list.size() = " << list.size() << std::endl;
        for (ExpressionPtr i : list){
            //std::cout << "DEBUG address of ExpressionPtr =" << i << std::endl;
            dst<<"SCOPE( ";
            i->print(dst);
            dst<<" )";
        }
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        std::string top_function = context.current_function_name;
        function f = context.functions[context.current_function_name];
        context.functions.insert({context.makeLabel("Scope "+context.current_function_name), f});
        context.current_function_name = context.current_function_name;

        dst<<"#DEBUG enter SCOPE - "<<context.current_function_name<<'\n';
        dst<<"move $fp,$sp"<<'\n';
        dst<<"move $25,$sp"<< '\n'; //make a copy of old fp in register 25

        for (ExpressionPtr i : list){
            i->generateMIPS(dst, context, destReg);
        }

        context.functions.erase(context.current_function_name);
        context.current_function_name = top_function;
        dst<<"move $fp,$25"<<'\n';
        dst<<"move $sp,$fp"<<'\n';
        dst<<"#DEBUG exited SCOPE - "<<context.current_function_name<<'\n';
    }
};

#endif