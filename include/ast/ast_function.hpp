#ifndef ast_function_hpp
#define ast_function_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ast_expression.hpp"
#include "context.hpp"

//FUNCTION______________________________________

class Full_Function
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionListPtr right;  
public:
    Full_Function(ExpressionPtr _left, ExpressionListPtr _right)
        : left(_left)
        , right(_right)
    {}

    Full_Function(ExpressionPtr _left)
        : left(_left)
        , right(new ExpressionList())
    {}

    virtual ~Full_Function()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionListPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"( ";
        left->print(dst);
        dst<<" ";
        // right->print(dst);
        for (ExpressionPtr e : right->list) {
            e->print(dst);
        }
        dst<<" )";
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        left->generateMIPS(dst, context, destReg);

        right->generateMIPS(dst, context, destReg);

        dst<<"end_"<<context.current_function_name<<":"<<'\n';
        // dst<<"move $s0, $2"<<'\n';
        dst<<"move $sp,$fp"<<'\n';
        dst<<"lw $fp,4($sp)"<<'\n'; // check alive variables vector
        dst<<"move $sp,$25"<<'\n';
        dst<<"jr $31"<<'\n';
        dst<<"nop"<<'\n';
    }
};

class Function_Definition
    : public Expression
{
private:
    std::string type;
    ExpressionPtr label_args;  
public:
    Function_Definition(const std::string &_type, ExpressionPtr _label_args)
        : type(_type)
        , label_args(_label_args)
    {}

    virtual ~Function_Definition()
    {
        delete label_args;
    }

    const std::string getType() const
    { return type; }

    std::string getId() const
    { return label_args->getId(); }

    ExpressionPtr getLabel() const
    { return label_args; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<type<<" ";
        label_args->print(dst);
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        label_args->generateMIPS(dst, context, destReg);
    }
};

class FunctionDeclarator
    : public Expression
{
private:
    ExpressionPtr id;
    ExpressionListPtr arg;
public:

    FunctionDeclarator(ExpressionPtr _id)
        : id(_id)
        , arg(new ExpressionList())
    {}

    FunctionDeclarator(ExpressionPtr _id, ExpressionListPtr _arg)
        : id(_id)
        , arg(_arg)
    {}

    ~FunctionDeclarator(){
        delete id;
        delete arg;
    }

    std::string getId() const
    { return id->getId(); }

    ExpressionListPtr getArg() const
    { return arg; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"DEBUG id = ";
        id->print(dst);
        dst<<"end of check";
        arg->print(dst);
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        context.functions_names.push_back(id->getId());
        std::string function_label = context.makeLabel(id->getId());
        function f;
        f.previous_function = function_label;
        context.functions.insert({function_label, f});
        context.current_function = function_label;
        context.current_function_name = id->getId();
        // storing argument parameters in stack

        dst<<"#DEBUG Function Declarator: label "<<context.current_function<< " " << context.functions[context.current_function].previous_function<<'\n';

        dst<<context.current_function_name<<":"<<'\n';
        dst<<"addiu $sp,$sp,-12"<<'\n'; //now 12 to allow space for old pc
        dst<<"sw $fp,4($sp)"<<'\n';
        dst<<"sw $31,8($sp)"<<'\n'; // stores pc above old_pc
        dst<<"move $25,$fp"<< '\n'; //make a copy of old fp in register 25
        dst<<"move $fp,$sp"<<'\n';

        int start_reg = 4;

        if (arg->list.size() <= 4){
            for (int i = 0; i < arg->list.size(); i++){
                arg->list[i]->generateMIPS(dst, context, start_reg+i);
            }
        } else {
            for (int i = 0; i <= 3; i++){
                arg->list[i]->generateMIPS(dst, context, start_reg+i);
            }
            for (int i = 4; i < arg->list.size(); i++){
                int regParam = context.allocate(context.current_function);
                // variable v;
                // v.reg = context.allocate(context.current_function);
                // v.size = 4; //only for int !!!
                // if (v.reg == -1) v.reg = context.allocate(context.current_function);
                // v.old_map_size = context.functions[context.current_function].variables_map.size()+1; //------------------------------
                // context.functions[context.current_function].variables_map.insert({arg->list[i]->getId(), v});
                
                arg->list[i]->generateMIPS(dst, context, regParam);

                context.regFile.freeReg(regParam);
            }
        }
        

    }

};

//--------------------------------------------------------------------------------

class Function_Call_Definition
    : public Expression
{
private:
    std::string type;
    ExpressionPtr label_args;  
public:
    Function_Call_Definition(const std::string &_type, ExpressionPtr _label_args)
        : type(_type)
        , label_args(_label_args)
    {}

    virtual ~Function_Call_Definition()
    {
        delete label_args;
    }

    const std::string getType() const
    { return type; }

    std::string getId() const
    { return label_args->getId(); }

    ExpressionPtr getLabel() const
    { return label_args; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<type<<" ";
        label_args->print(dst);
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        
        function f;
        std::string function_label = context.makeLabel(label_args->getId());
        context.functions.insert({function_label, f});
        // label_args->generateMIPS(dst, context, destReg);
        // //dst<<"end_"<<label_args->getId()<<":"<<'\n';
        // dst<<"move $sp,$fp"<<'\n';
        // dst<<"lw $fp,4($sp)"<<'\n'; // check alive variables vector ; Scott: not sure what this mean think we are just taking old fp and loading it into fp
        // dst<<"move $sp,$25"<<'\n';
        // //dst<<"move $fp, $sp"<<'\n'; //also resetting the frame pointer at end of function call
        // dst<<"jr $31"<<'\n'; //now we change the PC
        // dst<<"nop"<<'\n';
    }
};



class FunctionCall
    : public Expression
{
private:
    ExpressionPtr functionName;  
    ExpressionListPtr args;
public:
    FunctionCall(ExpressionPtr _functionName)
        : functionName(_functionName)
        , args(new ExpressionList())
    {}

    FunctionCall(ExpressionPtr _functionName, ExpressionListPtr _args)
        : functionName(_functionName)
        , args(_args)
    {}

    virtual ~FunctionCall()
    {
        delete functionName;
        delete args;
    }

    ExpressionPtr getFunctionName() const
    { return functionName; }

    ExpressionListPtr getArgs() const
    { return args; }

    virtual void print(std::ostream &dst) const override
    {
        functionName->print(dst);
        dst<<"(:";
        for (ExpressionPtr e : args->list) {
            e->print(dst);
        }
        dst<<":)";
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        int start_reg = 4;

        if (args->list.size() <= 4){
            for (int i = 0; i < args->list.size(); i++){
                args->list[i]->generateMIPS(dst, context, start_reg+i);
                // dst<<"move $s"<< i+1 <<", $"<<start_reg+i+1<<'\n';
            }
        } else {
            for (int i = 0; i <= 3; i++){
                args->list[i]->generateMIPS(dst, context, start_reg+i);
                // dst<<"move $s"<< i+1 <<", $"<<start_reg+i+1<<'\n';
            }
            int regParam = context.allocate(context.current_function);
            for (int i = 4; i < args->list.size(); i++){
                args->list[i]->generateMIPS(dst, context, regParam);
                // int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[args->list[i]->getId()].old_map_size) + 12;
                // dst<<"sw $"<<regParam<<","<<curr_offset<<"($fp)"<<'\n';
            }
            context.regFile.freeReg(regParam);
        }

        // dst<<"move $s0, $2"<<'\n';
        // dst<<"sw $31,8($sp)"<<'\n'; //we store old pc in memory NOT SURE IF NEEDED HERE (probably not)
        dst<<"jal "<<functionName->getId()<<'\n';
        // dst<<"nop"<<'\n';
        dst<<"lw $31,8($fp)"<<'\n';// get old_pc before jumping

        //UNCOMMENT TO TEST RECURSION
        // dst<<"add $2, $s0, $s2"<<'\n';
        
        dst<<"move $"<<destReg<<", $2"<<'\n';
        // dst<<"add $"<<destReg<<",$"<<destReg<<", $s1"<<'\n';
    }
};


#endif