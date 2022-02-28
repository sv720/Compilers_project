#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>

#include <memory>

class Expression;

typedef const Expression *ExpressionPtr;

class Expression
{
protected:
    std::vector<ExpressionPtr> branches;
public:
    Expression(std::vector<ExpressionPtr> _branches)
        : branches(_branches)
    {}
    Expression()
        : Expression(std::vector<ExpressionPtr>{})
    {}

    Expression(std::vector<ExpressionPtr> branches1, std::vector<ExpressionPtr> branches2){
        branches = branches1;
        branches.insert(branches.end(), branches2.begin(), branches2.end());
    } 


    virtual ~Expression()
    {
        for (int i = 0; i < branches.size(); i++){
            delete branches[i];
        }
    }

    // Tell and expression to print itself to the given stream
    virtual void print(std::ostream &dst) const =0;

    virtual ExpressionPtr getExpression(unsigned index) const;
    // Used in codegen to check if a declaration is for a function
    virtual bool isFunction() const{
        return false;
    }

    virtual ExpressionPtr getNode(unsigned index) const{
    if(index < branches.size()){
        return branches[index];
    }
    return NULL;
    }
};


#endif
