#ifndef ast_assign_declare_hpp
#define ast_assign_declare_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ast_expression.hpp"
#include "ast_expressionlist.hpp"

class Declare
    : public Expression
{
private:
    std::string left;
    ExpressionPtr right;  
public:
    Declare(const std::string _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}

    virtual ~Declare()
    {
        delete right;
    }

    const std::string getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<left<<" ";
        right->print(dst);
    }

    virtual void generateMIPS(std::ostream &dst, std::map<std::string, int> &variables_map, std::map<int, bool> &live_variables) const override
    {

    }
};

//______________________DECLARATORS__________________________

class InitDeclarator
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;  

public:
    InitDeclarator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    
    ~InitDeclarator(){
        delete left;
        delete right;
    }

    virtual void print(std::ostream &dst) const override
    {   
        left->print(dst);
        dst<<"=";
        right->print(dst);
    }

    virtual void generateMIPS(std::ostream &dst, std::map<std::string, int> &variables_map, std::map<int, bool> &live_variables) const override
    {
        right->generateMIPS(dst, variables_map, live_variables);
        left->generateMIPS(dst, variables_map, live_variables);
    }
};

class Declarator
    : public Expression
{
private:
    std::string id;
public:
    Declarator(const std::string &_id)
        : id(_id)
    {}

    std::string getDeclarator() const override
    { return id; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<id;
    }

    virtual void generateMIPS(std::ostream &dst, std::map<std::string, int> &variables_map, std::map<int, bool> &live_variables) const override
    {
        //assigning the variable to an address
        variables_map[id] = variables_map.size()*4+4;
        dst<<id;
    }
    
};


//________________________________________________

class AssignOperator
    : public Expression
{
private:
    ExpressionPtr left;
    std::string middle;
    ExpressionPtr right;  

public:
    AssignOperator(ExpressionPtr _left, std::string _middle, ExpressionPtr _right)
        : left(_left)
        , middle(_middle)
        , right(_right)
    {}
    //no member functions yet
    virtual void print(std::ostream &dst) const override
    {   
        left->print(dst);
        dst<<" "<<middle<<" ";
        right->print(dst);
    }

    virtual void generateMIPS(std::ostream &dst, std::map<std::string, int> &variables_map, std::map<int, bool> &live_variables) const override
    {
        if (middle == "="){

            right->generateMIPS(dst, variables_map, live_variables); //li or lw but we need to access register number, through a function
            dst<<"sw $4";
            dst<<variables_map[left->getId()];
            dst<<"($fp)"<<'\n'; //store output register of the calculations in  respective stack location
            left->generateMIPS(dst, variables_map, live_variables);
        }else if (middle == "*="){

        }else if (middle == "/="){

        }else if (middle == "%="){

        }else if (middle == "+="){

        }else if (middle == "-="){

        }else if (middle == "<<="){

        }else if (middle == ">>="){

        }else if (middle == "&="){

        }else if (middle == "^="){

        }else if (middle == "!="){

        }else{
            std::cerr<< "Error: operand for assignment not accepted" << std::endl;
        }
        
    }
};

#endif