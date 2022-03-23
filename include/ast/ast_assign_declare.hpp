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
        //if (right->getId() != "<NULL>"){ //don't want to add "<NULL> to map" BUT THIS IS NEEDED TO PASS MANY TESTCASES
            dst << "addiu $sp,$sp,-4 \n"; //have a new variable so need to make some space on the stack 
            dst<< "sw $25,0($fp) \n"; //we move the old (out of function) frame pointer into the current fp value
            dst<< "sw $31,4($fp) \n"; //we store old_pc just above old_fp
            dst<< "move $fp,$sp"<< '\n'; // move frame pointer back to the bottom

            variable v;
            v.reg = destReg; 
            v.size = 4; // only for int !!!
            v.old_map_size = context.functions[context.current_function].variables_map.size() +1 ; //------------------------------
            context.functions[context.current_function].variables_map.insert({right->getId(), v});
            dst<<"#DEBUG Declare: adding to map at address " << right->getId() << " making map size = "<< context.functions[context.current_function].variables_map.size() <<'\n';
            

            dst<<"sw $"<<context.functions[context.current_function].variables_map[right->getId()].reg<<",12($fp)"<<'\n';
            dst<<"#DEBUG: reg of argument="<<context.functions[context.current_function].variables_map[right->getId()].reg<< " "<< right->getId() <<'\n';
            right->generateMIPS(dst, context, context.functions[context.current_function].variables_map[right->getId()].reg);
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
        dst<<"#DEBUG InitDeclarator: adding to map at address " << right->getId() << " making map size = "<< context.functions[context.current_function].variables_map.size() <<'\n';


        right->generateMIPS(dst, context, destReg); //li or lw but we need to access register number, through a function
        //dst<<"#DEBUG : in variables_map for " << left->getId() << " " << context.functions[context.current_function].variables_map[left->getId()].offset << " " << v.offset << '\n';
        dst<<"sw $";
        dst<<destReg;
        dst<<",12($fp)"<<'\n'; //store output register of the calculations in  respective stack location
        left->generateMIPS(dst, context, context.functions[context.current_function].variables_map[left->getId()].reg);

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

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        //assigning the variable to an address
        // dst<<"DEBUG : function "<<id << '\n';
        // variables_map[id] = variables_map.size()*4+4;
        // dst<<"DEBUG : added to map "<< variables_map[id];
        //dst<< "#DEBUG : IN DECLARATOR \n";
        //dst<<id; //prints out labels (when we have a function definition) and gives variable name
        int found_enum_index = -1;
        for (int i = 0; i < context.enums.size(); i++) {
            if (context.enums[i].id == id) {
                found_enum_index = i;
            }
        }

        int found_var = false;
        for (int i = 0; i < context.functions[context.current_function].variables_map.size() && !found_var; i++) {
            if (context.functions[context.current_function].variables_map.find(id) !=  context.functions[context.current_function].variables_map.end()) {
                found_var = true;
            }
        }

        if (found_enum_index != -1) {
            dst<<"#DEBUG ENUM call: "<<context.enums[found_enum_index].id<<" <-> "<<context.enums[found_enum_index].value<<'\n';
            dst<<"li $"<<destReg<<","<<context.enums[found_enum_index].value<<'\n';
        }
        else if ( found_var ) {

            int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[id].old_map_size) + 12;
            dst<<"lw $"<<destReg<<","; // need to set other register, depending on free
            dst<<curr_offset<<"($fp)"<<'\n'; //specific location in stack for the variable (to check in alive variables vector)
            
        } else {
            variable v;
            v.reg = destReg;
            v.size = 4; //only for int !!!
            v.old_map_size = context.functions[context.current_function].variables_map.size() +1; //------------------------------
            context.functions[context.current_function].variables_map.insert({id, v});
            dst<<"#DEBUG Declarator: adding to map at address" << id << " making map size = "<< context.functions[context.current_function].variables_map.size() <<'\n';

            //TODO: check if valid
            int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[id].old_map_size) + 12;
            dst<<"lw $"<<destReg<<","; // need to set other register, depending on free
            dst<<curr_offset<<"($fp)"<<'\n'; //specific location in stack for the variable (to check in alive variables vector)
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
    //no member functions yet
    virtual void print(std::ostream &dst) const override
    { 
        left->print(dst);
        dst<<" "<<middle<<" ";
        right->print(dst);
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        if (middle == "="){
            variable v;
            v.reg = context.allocate(context.current_function);
            v.size = 4; //only for int !!!
            if (v.reg == -1) v.reg = context.allocate(context.current_function);
            v.old_map_size = context.functions[context.current_function].variables_map.size()+1; //------------------------------
            context.functions[context.current_function].variables_map.insert({left->getId(), v});
            dst<<"#DEBUG AssignOperator: in variables_map for " << left->getId() << " was " << context.functions[context.current_function].variables_map[left->getId()].old_map_size << ", now " << v.old_map_size << '\n';


            right->generateMIPS(dst, context, destReg); //li or lw but we need to access register number, through a function
            dst<<"#DEBUG AssignOperator: after right->mips, in variables_map for " << left->getId() << " was " << context.functions[context.current_function].variables_map[left->getId()].old_map_size << ", now " << v.old_map_size << '\n';
            int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[left->getId()].old_map_size) + 12;
            dst<<"sw $";
            dst<<destReg;
            dst<<","<<curr_offset<<"($fp)"<<'\n'; //store output register of the calculations in  respective stack location
            left->generateMIPS(dst, context, context.functions[context.current_function].variables_map[left->getId()].reg);

            context.regFile.freeReg(context.functions[context.current_function].variables_map[left->getId()].reg);

        }else if (middle == "*="){

        }else if (middle == "/="){

        }else if (middle == "%="){

        }else if (middle == "+="){

        }else if (middle == "-="){

        }else if (middle == "<<="){

        }else if (middle == ">>="){

        }else if (middle == "&="){

        }else if (middle == "^="){

        }else if (middle == "!="){

        }else{
            std::cerr<< "Error: operand for assignment not accepted" << std::endl;
        }
        
    }
};

#endif