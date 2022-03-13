#ifndef ast_iteration_statements_hpp
#define ast_iteration_statements_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ast_expression.hpp"

// ITERATION STATEMENTS ______________________________________


class WhileLoop
    : public Expression
{
private:
    ExpressionPtr condition;
    ExpressionPtr statement;  
public:
    WhileLoop(ExpressionPtr _condition, ExpressionPtr _statement)
        : condition(_condition)
        , statement(_statement)
    {}

    virtual ~WhileLoop()
    {
        delete condition;
        delete statement;
    }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"WHILE (";
        condition->print(dst);
        dst<<") { ";
        statement->print(dst);
        dst<<" } ";
    }

    virtual void generateMIPS(std::ostream &dst, std::map<std::string, std::vector<int>> &variables_map, std::map<int, bool> &live_variables) const override
    {}
};

class ForLoop
    : public Expression
{
private:
    ExpressionPtr conditionInit;
    ExpressionPtr condition;
    ExpressionPtr conditionStep;
    ExpressionPtr statement;  
public:
    ForLoop(ExpressionPtr _conditionInit, ExpressionPtr _condition, ExpressionPtr _statement)
        : conditionInit(_conditionInit)
        , condition(_condition)
        , statement(_statement)
    {}

    ForLoop(ExpressionPtr _conditionInit, ExpressionPtr _condition, ExpressionPtr _conditionStep, ExpressionPtr _statement)
        : conditionInit(_conditionInit)
        , condition(_condition)
        , conditionStep(_conditionStep)
        , statement(_statement)
    {}

    virtual ~ForLoop()
    {
        delete conditionInit;
        delete condition;
        delete conditionStep;
        delete statement;
    }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"FOR (";
        conditionInit->print(dst);
        dst<<" ; ";
        condition->print(dst);
        dst<<" ; ";
        conditionStep->print(dst);
        dst<<" ) { ";
        statement->print(dst);
        dst<<" } ";
    }

    virtual void generateMIPS(std::ostream &dst, std::map<std::string, std::vector<int>> &variables_map, std::map<int, bool> &live_variables) const override
    {}
};


#endif