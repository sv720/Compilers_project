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
        // context.in_loop_scope = true;
        // context.functions[context.current_function].fp_reg = context.allocate(context.current_function);

        

        condition->generateMIPS(dst, context, regA);
        // dst<<"move $"<<context.functions[context.current_function].fp_reg<<",$sp"<< '\n';
        dst<<WHILElabel<<":"<<'\n';
        
        dst<<"beq $"<<regA<<",$0,"<<endWhileLabel<<'\n';
        statement->generateMIPS(dst, context, destReg);
        condition->generateMIPS(dst, context, regA);
        dst<<"bne $"<<regA<<",$0,"<<WHILElabel<<'\n';

        dst<<endWhileLabel<<":"<<'\n';
        // dst<<"move $fp,$"<<context.functions[context.current_function].fp_reg<< '\n';
        // dst<<"move $sp,$"<<context.functions[context.current_function].fp_reg<<'\n';
        // dst<<"move $fp,$sp"<<'\n';
        // dst<<"sw $25,4($sp)"<<'\n';
        // dst<<"sw $31,8($sp)"<<'\n'; // stores pc above old_pc
        // context.regFile.freeReg(context.functions[context.current_function].fp_reg);
        // // context.functions.erase(context.current_function);
        // // context.functions[context.current_function].iteration_selection_statement = context.functions[context.functions[context.current_function].previous_function].iteration_selection_statement;
        // dst<<"#DEBUG exited SCOPE - "<<context.current_function;
        // context.current_function = context.functions[context.current_function].previous_function;
        // dst<<", now in "<<context.current_function<<'\n';
        
        context.regFile.freeReg(regA);
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
        int regA = context.allocate(context.current_function);
        int regCondition = context.allocate(context.current_function);
        int regStep = context.allocate(context.current_function);
        std::string FORlabel = context.makeLabel("FOR");
        std::string endForLabel = context.makeLabel("endFOR");
        // context.functions[context.current_function].iteration_selection_statement = true;
        // context.in_loop_scope = true;
        // context.functions[context.current_function].fp_reg = context.allocate(context.current_function);

        // dst<<"move $"<<context.functions[context.current_function].fp_reg<<",$sp"<< '\n';

        conditionInit->generateMIPS(dst, context, regStep);
        condition->generateMIPS(dst, context, regCondition);
        
        
        dst<<FORlabel<<":"<<'\n';
        
        dst<<"beq $"<<regCondition<<",$0,"<<endForLabel<<'\n';
        dst<<"nop"<<'\n';

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
            conditionStep->generateMIPS(dst, context, regStep);
            condition->generateMIPS(dst, context, regCondition); 
        }
        
        dst<<"bne $"<<regCondition<<",$0,"<<FORlabel<<'\n';

        // dst<<"move $fp,$"<<context.functions[context.current_function].fp_reg<< '\n';
        // dst<<"move $sp,$"<<context.functions[context.current_function].fp_reg<<'\n';
        // // int parent_map_size = context.functions[context.functions[context.current_function].previous_function].variables_map.size();
        // // dst<<"addiu $sp,$sp,"<< (4*(context.functions[context.current_function].variables_map.size() - parent_map_size))<<'\n';
        // // dst<<"move $fp,$sp"<<'\n';
        // dst<<"sw $25,4($sp)"<<'\n';
        // dst<<"sw $31,8($sp)"<<'\n'; // stores pc above old_pc
        // context.regFile.freeReg(context.functions[context.current_function].fp_reg);
        // // context.functions.erase(context.current_function);
        // // context.functions[context.current_function].iteration_selection_statement = context.functions[context.functions[context.current_function].previous_function].iteration_selection_statement;
        // dst<<"#DEBUG exited SCOPE - "<<context.current_function;
        // context.current_function = context.functions[context.current_function].previous_function;
        // dst<<", now in "<<context.current_function<<'\n';

        dst<<endForLabel<<":"<<'\n';

        // context.regFile.freeReg(regA);
        context.regFile.freeReg(regCondition);
        // context.regFile.freeReg(regStep);
    }
};


#endif