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
        // dst<<"DECLARE : ";
        dst<<left<<" ";
        // dst<<"DECLARE: right:";
        right->print(dst);
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {

            dst << "addiu $sp,$sp,-4 \n"; //have a new variable so need to make some space on the stack 
            dst<< "sw $25,0($fp) \n"; //we move the old (out of function) frame pointer into the current fp value
            dst<< "sw $31,4($fp) \n"; //we store old_pc just above old_fp
            dst<< "move $fp,$sp"<< '\n'; // move frame pointer back to the bottom

            right->generateMIPS(dst, context, destReg);
        //}

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

    std::string getId() const override
    { return left->getId(); }

    virtual void print(std::ostream &dst) const override
    {   dst<<"INITDECLARATOR \n";
        left->print(dst);
        dst<<"=";
        right->print(dst);
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        variable v;
        v.size = 4; //only for int !!!
        v.reg = v.reg = context.allocate(context.current_function);
        if (v.reg == -1) v.reg = context.allocate(context.current_function);
        v.old_map_size = context.functions[context.current_function].variables_map.size() +1; //------------------------------
        context.functions[context.current_function].variables_map.insert({left->getId(), v});
        dst<<"#DEBUG InitDeclarator: adding to map at address " << left->getId() << " making map size = "<< context.functions[context.current_function].variables_map.size() <<'\n';


        right->generateMIPS(dst, context, destReg); //li or lw but we need to access register number, through a function
        //dst<<"#DEBUG : in variables_map for " << left->getId() << " " << context.functions[context.current_function].variables_map[left->getId()].offset << " " << v.offset << '\n';

        dst<<"sw $";
        dst<<destReg;
        dst<<",12($fp)"<<'\n'; //store output register of the calculations in  respective stack location
        // left->generateMIPS(dst, context, context.functions[context.current_function].variables_map[left->getId()].reg);

        context.regFile.freeReg(context.functions[context.current_function].variables_map[left->getId()].reg);
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
        dst<< "DECALARATOR :";
        dst<<id;
    }

    std::string found_in_f(Context &context, std::string id, std::string function) const {
        bool found_var = false;
        
        std::string found_in_function;
        for (int i = 0; i < context.functions[function].variables_map.size() && !found_var; i++) {
            if (context.functions[function].variables_map.find(id) !=  context.functions[function].variables_map.end()) {
                found_var = true;
                return function;
            }
        }
        if (context.functions[function].previous_function == function) {
            return "NOT_FOUND";
        } else {
            if (found_var == false) {
                return found_in_f(context, id, context.functions[function].previous_function);
            }
        }
        
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        //dst<< "#DEBUG : IN DECLARATOR \n";
        int found_enum_index = -1;
        for (int i = 0; i < context.enums.size(); i++) {
            if (context.enums[i].id == id) {
                found_enum_index = i;
            }
        }

        bool found_var = false;
        for (int i = 0; i < context.functions[context.current_function].variables_map.size() && !found_var; i++) {
            if (context.functions[context.current_function].variables_map.find(id) !=  context.functions[context.current_function].variables_map.end()) {
                found_var = true;
            }
        }

        if (found_enum_index != -1) {
            dst<<"#DEBUG ENUM call: "<<context.enums[found_enum_index].id<<" <-> "<<context.enums[found_enum_index].value<<'\n';
            dst<<"li $"<<destReg<<","<<context.enums[found_enum_index].value<<'\n';
        }
        else if ( found_in_f(context, id, context.current_function) != "NOT_FOUND" ) {
            std::string f = found_in_f(context, id, context.current_function);
            dst<<"#DEBUG Declarator: FOUND_VAR, adding to map at address" << id << " from function "<< f <<'\n';
            int curr_offset = 4*(context.functions[f].variables_map.size() - context.functions[f].variables_map[id].old_map_size) + 12;
            dst<<"lw $"<<destReg<<","; // need to set other register, depending on free
            dst<<curr_offset<<"($fp)"<<'\n'; //specific location in stack for the variable (to check in alive variables vector)
        
        } else {
        //     dst << "addiu $sp,$sp,-4 \n"; //have a new variable so need to make some space on the stack 
        //     dst<< "sw $25,0($fp) \n"; //we move the old (out of function) frame pointer into the current fp value
        //     dst<< "sw $31,4($fp) \n"; //we store old_pc just above old_fp
        //     dst<< "move $fp,$sp"<< '\n'; // move frame pointer back to the bottom
            
            variable v;
            v.reg = destReg;
            v.size = 4; //only for int !!!
            v.old_map_size = context.functions[context.current_function].variables_map.size() +1; //------------------------------
            context.functions[context.current_function].variables_map.insert({id, v});
            dst<<"#DEBUG Declarator: NOT_FOUND_VAR, adding to map at address" << id << " making map size = "<< context.functions[context.current_function].variables_map.size() <<'\n';

            int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[id].old_map_size) + 12;
            dst<<"sw $"<<context.functions[context.current_function].variables_map[id].reg<<",12($fp)"<<'\n';
            dst<<"#DEBUG: reg of argument="<<context.functions[context.current_function].variables_map[id].reg<< " "<< id <<'\n';
        }
        
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
    
    std::string getId() const{
        return left->getId();
    }

    virtual void print(std::ostream &dst) const override
    { 
        left->print(dst);
        dst<<" "<<middle<<" ";
        right->print(dst);
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        if (middle == "="){
            // variable v;
            // v.reg = context.allocate(context.current_function);
            // v.size = 4; //only for int !!!
            // if (v.reg == -1) v.reg = context.allocate(context.current_function);
            // v.old_map_size = context.functions[context.current_function].variables_map.size()+1; //------------------------------
            // context.functions[context.current_function].variables_map.insert({left->getId(), v});
            dst<<"#DEBUG AssignOperator: in variables_map for " << left->getId() << '\n';


             if (left->getNature() == "Variable_Indexed_Array"){
                dst<<"#DEBUG : Varaible_Indexed_Array__________________________________________________________________"<<'\n';
                //TODO : ADD CODE FOR REGISTER STYLE
                right->generateMIPS(dst, context, destReg); //li or lw but we need to access register number, through a function
                //dst<<"#DEBUG AssignOperator: after right->mips, in variables_map for " << left->getId() << " was " << context.functions[context.current_function].variables_map[left->getId()].old_map_size << ", now " << v.old_map_size << '\n';
                dst<<"#DEBUG AssignOperator: in variables_map for " << left->getId() << " was " << context.functions[context.current_function].variables_map[left->getId()].old_map_size << '\n';
                int regIndex = context.allocate(context.current_function_name);

                int regOffset = context.allocate(context.current_function_name);

                //dst<<"addi $"<<regOffset<<",$"<<regIndex<<",-"<<curr_offset<<'\n';
                dst<<"sub $"<<regOffset<<",$0,$"<<regOffset<<'\n';

                int regAddress = context.allocate(context.current_function_name);

                dst<<"add $"<<regAddress<<",$"<<regOffset<<",$fp"<<'\n';

                dst<<"sw $";
                dst<<destReg;
                dst<<",0($"<<regAddress<<")"<<'\n'; //store output register of the calculations in  respective stack location
                //left->generateMIPS(dst, context, context.functions[context.current_function].variables_map[left->getId()].reg);
            }else {
                dst<<"#DEBUG : OTHER__________________________________________________________________"<<'\n';
                right->generateMIPS(dst, context, destReg); //li or lw but we need to access register number, through a function
                //dst<<"#DEBUG AssignOperator: after right->mips, in variables_map for " << left->getId() << " was " << context.functions[context.current_function].variables_map[left->getId()].old_map_size << ", now " << v.old_map_size << '\n';
                int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[left->getId()].old_map_size) + 12;
                dst<<"sw $";
                dst<<destReg;
                dst<<","<<curr_offset<<"($fp)"<<'\n'; //store output register of the calculations in  respective stack location
                //left->generateMIPS(dst, context, context.functions[context.current_function].variables_map[left->getId()].reg);
            }
            // context.regFile.freeReg(context.functions[context.current_function].variables_map[left->getId()].reg);

        }else if (middle == "*="){
            int regLeft = context.allocate(context.current_function);
            int regRight = context.allocate(context.current_function);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight); 

            dst<<"mult $"<<regLeft<<", $"<<regRight<<'\n';
            dst<<"mflo $"<<regLeft<<'\n';

            int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[left->getId()].old_map_size) + 12;
            dst<<"sw $";
            dst<<regLeft;
            dst<<","<<curr_offset<<"($fp)"<<'\n'; //store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);

        }else if (middle == "/="){
            int regLeft = context.allocate(context.current_function);
            int regRight = context.allocate(context.current_function);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight); 

            dst<<"div $"<<regLeft<<", $"<<regRight<<'\n';
            dst<<"mflo $"<<regLeft<<'\n';

            int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[left->getId()].old_map_size) + 12;
            dst<<"sw $";
            dst<<regLeft;
            dst<<","<<curr_offset<<"($fp)"<<'\n'; //store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);

        }else if (middle == "%="){
            int regLeft = context.allocate(context.current_function);
            int regRight = context.allocate(context.current_function);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight); 

            dst<<"div $"<<regLeft<<", $"<<regRight<<'\n';
            dst<<"mfhi $"<<regLeft<<'\n';

            int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[left->getId()].old_map_size) + 12;
            dst<<"sw $";
            dst<<regLeft;
            dst<<","<<curr_offset<<"($fp)"<<'\n'; //store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);

        }else if (middle == "+="){
            int regLeft = context.allocate(context.current_function);
            int regRight = context.allocate(context.current_function);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight); 

            dst<<"addu $"<<regLeft<<", $"<<regLeft<<", $"<<regRight<<'\n';

            int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[left->getId()].old_map_size) + 12;
            dst<<"sw $";
            dst<<regLeft;
            dst<<","<<curr_offset<<"($fp)"<<'\n'; //store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);

        }else if (middle == "-="){
            int regLeft = context.allocate(context.current_function);
            int regRight = context.allocate(context.current_function);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight); 

            dst<<"subu $"<<regLeft<<", $"<<regLeft<<", $"<<regRight<<'\n';

            int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[left->getId()].old_map_size) + 12;
            dst<<"sw $";
            dst<<regLeft;
            dst<<","<<curr_offset<<"($fp)"<<'\n'; //store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);

        }else if (middle == "<<="){
            int regLeft = context.allocate(context.current_function);
            int regRight = context.allocate(context.current_function);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight); 

            dst<<"sllv $"<< regLeft << ",$"<<regLeft<<",$"<<regRight<<'\n';

            int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[left->getId()].old_map_size) + 12;
            dst<<"sw $";
            dst<<regLeft;
            dst<<","<<curr_offset<<"($fp)"<<'\n'; //store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);

        }else if (middle == ">>="){
            int regLeft = context.allocate(context.current_function);
            int regRight = context.allocate(context.current_function);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight); 

            dst<<"srlv $"<< regLeft << ",$"<<regLeft<<",$"<<regRight<<'\n';

            int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[left->getId()].old_map_size) + 12;
            dst<<"sw $";
            dst<<regLeft;
            dst<<","<<curr_offset<<"($fp)"<<'\n'; //store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);

        }else if (middle == "&="){
            int regLeft = context.allocate(context.current_function);
            int regRight = context.allocate(context.current_function);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight); 

            dst<<"and $"<< regLeft << ",$"<<regLeft<<",$"<<regRight<<'\n';

            int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[left->getId()].old_map_size) + 12;
            dst<<"sw $";
            dst<<regLeft;
            dst<<","<<curr_offset<<"($fp)"<<'\n'; //store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);

        }else if (middle == "^="){
            int regLeft = context.allocate(context.current_function);
            int regRight = context.allocate(context.current_function);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight); 

            dst<<"xor $"<< regLeft << ",$"<<regLeft<<",$"<<regRight<<'\n';

            int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[left->getId()].old_map_size) + 12;
            dst<<"sw $";
            dst<<regLeft;
            dst<<","<<curr_offset<<"($fp)"<<'\n'; //store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);

        }else{
            std::cerr<< "Error: operand for assignment not accepted" << std::endl;
        }
        
    }
};

#endif