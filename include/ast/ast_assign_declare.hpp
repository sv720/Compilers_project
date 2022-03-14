#ifndef ast_assign_declare_hpp
#define ast_assign_declare_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ast_expression.hpp"
#include "ast_expressionlist.hpp"
#include "context.hpp"

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

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        // right->generateMIPS(dst, context, destReg); //ONLY used for variable declaration
        // dst<<"DEBUG : adding to map for "<<right->getId() << '\n';
        context.variables_map[right->getId()].offset = context.variables_map.size()*4+4;
        // dst<<"DEBUG : added to map "<< variables_map[right->getId()];
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

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        right->generateMIPS(dst, context, destReg); //li or lw but we need to access register number, through a function
        // dst<<" DEBUG : in variables_map for " << left->getId() << " " << variables_map[left->getId()] << '\n';
        dst<<"sw $";
        dst<<destReg;
        dst<<","<<(context.variables_map[left->getId()].offset)<<"($fp)"<<'\n'; //store output register of the calculations in  respective stack location
        left->generateMIPS(dst, context, destReg);
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

    std::string getId() const override
    { return id; }

    virtual void print(std::ostream &dst) const override
    {
        // dst<< "DEBUG DECALARATOR ";
        dst<<id;
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        //assigning the variable to an address
        // dst<<"DEBUG : function "<<id << '\n';
        // variables_map[id] = variables_map.size()*4+4;
        // dst<<"DEBUG : added to map "<< variables_map[id];
        dst<<id; //prints out labels (when we have a function definition) and gives variable name
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

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        if (middle == "="){
            right->generateMIPS(dst, context, destReg); //li or lw but we need to access register number, through a function
            // dst<<" DEBUG : in variables_map for " << left->getId() << " " << context.variables_map[left->getId()].reg<< '\n';
            dst<<"sw $";
            dst<<context.variables_map[left->getId()].reg;
            dst<<","<<(context.variables_map[left->getId()].offset)<<"($fp)"<<'\n'; //store output register of the calculations in  respective stack location
            left->generateMIPS(dst, context, destReg);
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