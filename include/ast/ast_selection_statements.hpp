#ifndef ast_selection_statements_hpp
#define ast_selection_statements_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ast_expression.hpp"
#include "context.hpp"

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

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        int regA = context.allocate(context.current_function);
        condition->generateMIPS(dst, context, regA);
        dst<<"nop"<<'\n';
        std::string endIfLabel = context.makeLabel("endIF");
        dst<<"beq $zero,$"<<regA<<","<<endIfLabel<<'\n';
        statement->generateMIPS(dst, context, destReg);

        dst<<endIfLabel<<":"<<'\n';
        // dst<<"nop"<<'\n';

        context.regFile.freeReg(regA);
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

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        int regA = context.allocate(context.current_function);
        condition->generateMIPS(dst, context, regA);
        std::string ELSElabel = context.makeLabel("ELSE");
        dst<<"beq $"<<regA<<",$zero,"<<ELSElabel<<'\n';

        
        statement->generateMIPS(dst, context, destReg);
        std::string endIfLabel = context.makeLabel("endIFELSE");
        dst<<"j "<<endIfLabel<<'\n';
        // dst<<"nop"<<'\n';

        dst<<ELSElabel<<":"<<'\n';
        elseStatement->generateMIPS(dst, context, destReg);

        dst<<endIfLabel<<":"<<'\n';


        context.regFile.freeReg(regA);
    }
};

class SwitchCase
    : public Expression
{
private:
    ExpressionPtr condition;
    ExpressionListPtr statement;  
public:
    SwitchCase(ExpressionPtr _condition, ExpressionListPtr _statement)
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

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        int conditionReg = context.allocate(context.current_function);

        int nb_cases = statement->getValue();
        std::vector<std::string> caseLabels;
        for (int i = 0; i < nb_cases; i++) {
            std::string switch_case_label = context.makeLabel("SWITCHCASE");
            caseLabels.push_back(switch_case_label);
        } 

        for (int i = 0; i < nb_cases; i++) {
            std::string switch_case_label = caseLabels[i];
            condition->generateMIPS(dst, context, conditionReg);
            dst<<"li $"<<destReg<<","<< i+1 <<'\n';
            dst<<"beq $"<<destReg<<",$"<<conditionReg<<", "<<  switch_case_label <<'\n';
            dst<<"nop"<<'\n';
        }
        context.regFile.freeReg(conditionReg);

        std::string ENDswitch_label = context.makeLabel("endSWITCH");
        dst<<"j "<<  ENDswitch_label <<'\n';
        dst<<"nop"<<'\n';

        for (int i = 0; i < nb_cases; i++) {
            dst<<caseLabels[i]<<":"<<'\n';
            statement->list[i]->generateMIPS(dst, context, destReg);
            dst<<"j "<<  ENDswitch_label <<'\n';
            dst<<"nop"<<'\n';
        }

        dst<<ENDswitch_label<<":"<<'\n';
    }
};

class Case
    : public Expression
{
private:
    ExpressionPtr expression;
    ExpressionPtr statement;    
public:

    Case(ExpressionPtr _condition, ExpressionPtr _statement)
        : expression(_condition)
        , statement(_statement)
    {}

    Case(ExpressionPtr _statement)
        : statement(_statement)
    {}

    virtual ~Case()
    {
        delete expression;
        delete statement;
    }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"SWITCH (";
        expression->print(dst);
        dst<<") { ";
        statement->print(dst);
        dst<<" } ";
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {        
        statement->generateMIPS(dst, context, destReg);

    }
};

#endif