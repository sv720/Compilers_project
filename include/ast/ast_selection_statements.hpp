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
<<<<<<< HEAD
        
        int regA = context.allocate();
        condition->generateMIPS(dst, context, regA);
        dst<<"nop"<<'\n';
        std::string endIfLabel = context.makeLabel("L");
=======
        int regA = context.allocate();
        condition->generateMIPS(dst, context, regA);
        dst<<"nop"<<'\n';
        std::string endIfLabel = context.makeLabel("endIF");
>>>>>>> c2d88deee9140bc985f44f78d9c989b59aac66f3
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
        int regA = context.allocate();
        condition->generateMIPS(dst, context, regA);
        std::string ELSElabel = context.makeLabel("ELSE");
        dst<<"beq $"<<regA<<",$zero,"<<ELSElabel<<'\n';

        statement->generateMIPS(dst, context, destReg);
<<<<<<< HEAD
        std::string endIfLabel = context.makeLabel("L");
        dst<<"j "<<endIfLabel<<'\n';
        dst<<"nop"<<'\n';
=======
        std::string endIfLabel = context.makeLabel("endIFELSE");
        dst<<"j "<<endIfLabel<<'\n';
        // dst<<"nop"<<'\n';
>>>>>>> c2d88deee9140bc985f44f78d9c989b59aac66f3

        dst<<ELSElabel<<":"<<'\n';
        elseStatement->generateMIPS(dst, context, destReg);

        dst<<endIfLabel<<":"<<'\n';
<<<<<<< HEAD
=======


        context.regFile.freeReg(regA);
>>>>>>> c2d88deee9140bc985f44f78d9c989b59aac66f3
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

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {}
};

#endif