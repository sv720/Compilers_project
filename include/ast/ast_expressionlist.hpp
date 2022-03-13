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

    virtual void generateMIPS(std::ostream &dst, std::map<std::string, std::vector<int>> &variables_map, std::map<int, bool> &live_variables) const override
    {
        for (ExpressionPtr i : list){
            i->generateMIPS(dst, variables_map, live_variables);
        }
    }
};


#endif