#ifndef ast_expressionlist_hpp
#define ast_expressionlist_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include "ast/ast_expression.hpp"

class ExpressionList;

typedef std::vector<ExpressionPtr> ExprList;
// typedef ExprList *ExprListPtr;
typedef ExpressionList *ExpressionListPtr;

class ExpressionList
    : public Expression
{
   
public:
    std::vector<ExpressionPtr> list;
    //TODO: think about making constructors protected (was causing issue - not too sure why)
    /*Personal reasoning:
        My understanding of what a protected function or data is that it is private from outside of the class
        or its children but public for itself or its children. Hence; I don't understand how we can consistently
        use protected constuctors in parser.y when these calls are not being made from withing a child of the class
        - for now left this classes constructors public as was causing issues when protected
        */
    //CONSTRUCTORS
    ExpressionList() 
    {   std::cout<<"DEBUG: create list CONSTRUCTOR" << std::endl;
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
        std::cout<<"DEBUG: add in_list ";
        // list.push_back(in_list[0]);
        for (int i =0; i < in_list->list.size(); i++)
        {
            std::cout<< in_list->list[i] << std::endl;
            list.push_back(in_list->list[i]);
        }
        std::cout<<"DEBUG: size of list after copying in_list = "<< list.size() << std::endl; 
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

        std::cout<<"DEBUG in print; list.size() = " << list.size() << std::endl;
        // for (ExpressionPtr i : list){
        //     std::cout << "DEBUG address of ExpressionPtr =" << i << std::endl;
        //     dst<<"( ";
        //     i->print(dst);
        //     dst<<" )";
        // }
    }
};


class Scope
    : public ExpressionList
{ 
public:
    // Does everything the same for constructor/destructor 
    using ExpressionList::ExpressionList;


    virtual void print(std::ostream &dst) const override
    {
        dst<<"( ";
        // for (int i = 0; i < list.size(); i++) {
        //     list[i]->print(dst);
        // }
        dst<<" )";
    }
};


#endif