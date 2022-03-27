#ifndef ast_iteration_statements_hpp
#define ast_iteration_statements_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ast_expression.hpp"
#include "context.hpp"

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

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        int regA = context.allocate(context.current_function);
        std::string WHILElabel = context.makeLabel("WHILE");
        std::string endWhileLabel = context.makeLabel("endWHILE");
        context.functions[context.current_function].iteration_selection_statement = true;

        condition->generateMIPS(dst, context, regA);
        
        dst<<WHILElabel<<":"<<'\n';
        dst<<"beq $"<<regA<<",$0,"<<endWhileLabel<<'\n';
        dst<<"nop"<<'\n';
        statement->generateMIPS(dst, context, destReg);
        condition->generateMIPS(dst, context, regA);
        dst<<"bne $"<<regA<<",$0,"<<WHILElabel<<'\n';
        // dst<<"j "<<WHILElabel<<'\n';
        dst<<"nop"<<'\n';

        dst<<endWhileLabel<<":"<<'\n';
        
        context.regFile.freeReg(regA);

        dst<<"move $fp,$24"<< '\n';
        dst<<"move $sp,$24"<<'\n';
        dst<<"sw $25,4($sp)"<<'\n';
        dst<<"sw $31,8($sp)"<<'\n'; // stores pc above old_pc
        context.functions.erase(context.current_function);
        dst<<"#DEBUG exited SCOPE - "<<context.current_function;
        if(!context.functions.empty())    context.current_function = (--context.functions.end())->first;
        dst<<", now in "<<context.current_function<<'\n';

    }
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

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {

        dst<<"#DEBUG enter FOR SCOPE - "<<context.current_function<<'\n';

        int regA = context.allocate(context.current_function);
        int regCondition = context.allocate(context.current_function);
        int regStep = context.allocate(context.current_function);
        std::string FORlabel = context.makeLabel("FOR");
        std::string endForLabel = context.makeLabel("endFOR");
        context.functions[context.current_function].iteration_selection_statement = true;

        conditionInit->generateMIPS(dst, context, regStep);
        condition->generateMIPS(dst, context, regCondition);

        dst<<FORlabel<<":"<<'\n';
        
        dst<<"beq $"<<regCondition<<",$0,"<<endForLabel<<'\n';
        // dst<<"nop"<<'\n';
        dst<<"#DEBUG FOR step value: "<<conditionStep->getId()<<'\n';
        if (conditionStep->getId() == "pre++" || conditionStep->getId() == "pre--"){
            conditionStep->generateMIPS(dst, context, regStep);
            int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[conditionInit->getId()].old_map_size) + 12;
            dst<<"sw $";
            dst<<regStep;
            dst<<","<<curr_offset<<"($fp)"<<'\n';
            statement->generateMIPS(dst, context, destReg);
            condition->generateMIPS(dst, context, regCondition); 
        } else {
            statement->generateMIPS(dst, context, destReg);
            condition->generateMIPS(dst, context, regCondition); 
            conditionStep->generateMIPS(dst, context, regStep);
            // int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[conditionInit->getId()].old_map_size) + 12;
            // dst<<"sw $";
            // dst<<regStep;
            // dst<<","<<curr_offset<<"($fp)"<<'\n';
        }        
        
        dst<<"bne $"<<regCondition<<",$0,"<<FORlabel<<'\n';
        // dst<<"nop"<<'\n';

        dst<<endForLabel<<":"<<'\n';

        // context.regFile.freeReg(regA);
        context.regFile.freeReg(regCondition);
        // context.regFile.freeReg(regStep);

        dst<<"move $fp,$24"<< '\n';
        dst<<"move $sp,$24"<<'\n';
        dst<<"sw $25,4($sp)"<<'\n';
        dst<<"sw $31,8($sp)"<<'\n'; // stores pc above old_pc
        context.functions.erase(context.current_function);
        dst<<"#DEBUG exited SCOPE - "<<context.current_function;
        if(!context.functions.empty())    context.current_function = (--context.functions.end())->first;
        dst<<", now in "<<context.current_function<<'\n';
    }
};


#endif