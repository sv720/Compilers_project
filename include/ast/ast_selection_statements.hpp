#ifndef ast_selection_statements_hpp
#define ast_selection_statements_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ast_expression.hpp"

// SELECTION STATEMENTS ______________________________________

class If
    : public Expression
{
private:
    ExpressionPtr condition;
    ExpressionPtr statement;  
public:
    If(ExpressionPtr _condition, ExpressionPtr _statement)
        : condition(_condition)
        , statement(_statement)
    {}

    virtual ~If()
    {
        delete condition;
        delete statement;
    }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"IF (";
        condition->print(dst);
        dst<<") { ";
        statement->print(dst);
        dst<<" } ";
    }
};

class IfElse
    : public Expression
{
private:
    ExpressionPtr condition;
    ExpressionPtr statement;  
    ExpressionPtr elseStatement; 
public:
    IfElse(ExpressionPtr _condition, ExpressionPtr _statement, ExpressionPtr _elseStatement)
        : condition(_condition)
        , statement(_statement)
        , elseStatement(_elseStatement)
    {}

    virtual ~IfElse()
    {
        delete condition;
        delete statement;
        delete elseStatement;
    }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"IF (";
        condition->print(dst);
        dst<<") { ";
        statement->print(dst);
        dst<<" } ELSE {";
        elseStatement->print(dst);
        dst<<" } ";
    }
};

class SwitchCase
    : public Expression
{
private:
    ExpressionPtr condition;
    ExpressionPtr statement;  
public:
    SwitchCase(ExpressionPtr _condition, ExpressionPtr _statement)
        : condition(_condition)
        , statement(_statement)
    {}

    virtual ~SwitchCase()
    {
        delete condition;
        delete statement;
    }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"SWITCH (";
        condition->print(dst);
        dst<<") { ";
        statement->print(dst);
        dst<<" } ";
    }
};

#endif