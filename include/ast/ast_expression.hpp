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
public:
    Expression(std::vector<ExpressionPtr> _branches);
    Expression();
    Expression(std::vector<ExpressionPtr> branches1, std::vector<ExpressionPtr> branches2); 


    virtual ~Expression()
    {}

    //! Tell and expression to print itself to the given stream
    virtual void print(std::ostream &dst) const =0;

    virtual ExpressionPtr getExpression(unsigned index) const;
    
};


#endif
