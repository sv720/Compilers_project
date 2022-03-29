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
        : left(_left), right(_right)
    {
    }

    virtual ~Declare()
    {
        delete right;
    }

    const std::string getLeft() const
    {
        return left;
    }

    ExpressionPtr getRight() const
    {
        return right;
    }

    virtual void print(std::ostream &dst) const override
    {
        // dst<<"DECLARE : ";
        dst << left << " ";
        // dst<<"DECLARE: right:";
        right->print(dst);
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        std::string type = left;
        
        right->generateMIPS(dst, context, destReg);

        for (int i = 0; i < context.typedefs.size(); i++) {
            if (context.typedefs.find(left) != context.typedefs.end()) {
                type = context.typedefs[left];
            }
        }

        if (right->getNature() != "ArrayDeclarator") {
            variable v;

            if ( (type == "int") || (type == "char") ){
                dst << "addiu $sp,$sp,-4 \n";  // have a new variable so need to make some space on the stack
                dst << "sw $25,0($fp) \n";     // we move the old (out of function) frame pointer into the current fp value
                dst << "sw $31,4($fp) \n";     // we store old_pc just above old_fp
                dst << "move $fp,$sp" << '\n'; // move frame pointer back to the bottom
                if (type == "int") {
                    v.size = 4; // only for int !!!
                    v.type = "int";
                }else if (type == "char") {
                    v.size = 1;
                    v.type = "char";
                }
            }
            else {
                dst << "addiu $sp,$sp,-4 \n";  // have a new variable so need to make some space on the stack
                dst << "sw $25,0($fp) \n";     // we move the old (out of function) frame pointer into the current fp value
                dst << "sw $31,4($fp) \n";     // we store old_pc just above old_fp
                dst << "move $fp,$sp" << '\n'; // move frame pointer back to the bottom
                v.size = 4;
            }
            
            
            v.declared_in_function = context.current_function;
            v.old_map_size = context.functions[context.current_function].variables_map.size() + 1; //------------------------------
            context.functions[context.current_function].variables_map.insert({right->getId(), v});
            dst << "#DEBUG Declarator: adding to map " << context.current_function << " at address: " << right->getId() << " making map size = " << context.functions[context.current_function].variables_map.size() << '\n';
        
            //  int curr_offset = 4 * (context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[right->getId()].old_map_size) + 12;
            dst << "sw $" << destReg << ",12($fp)" << '\n';
            dst << "#DEBUG: reg of argument=" << destReg << " " << right->getId() << '\n';
        }
        
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
        : left(_left), right(_right)
    {
    }

    ~InitDeclarator()
    {
        delete left;
        delete right;
    }

    std::string getId() const override
    {
        return left->getId();
    }

    virtual void print(std::ostream &dst) const override
    {
        dst << "INITDECLARATOR \n";
        left->print(dst);
        dst << "=";
        right->print(dst);
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        // variable v;
        // v.size = 4;                                                                            // only for int !!!
        // v.old_map_size = context.functions[context.current_function].variables_map.size() + 1; //------------------------------
        // v.declared_in_function = context.current_function;
        // context.functions[context.current_function].variables_map.insert({left->getId(), v});
        // dst << "#DEBUG InitDeclarator: adding to map " << context.current_function << " at address " << left->getId() << " making map size = " << context.functions[context.current_function].variables_map.size() << '\n';

        right->generateMIPS(dst, context, destReg); // li or lw but we need to access register number, through a function
        // dst<<"#DEBUG : in variables_map for " << left->getId() << " " << context.functions[context.current_function].variables_map[left->getId()].offset << " " << v.offset << '\n';
        
        // dst << "sw $";
        // dst << destReg;
        // dst << ",12($fp)" << '\n'; // store output register of the calculations in  respective stack location
        // left->generateMIPS(dst, context, context.functions[context.current_function].variables_map[left->getId()].reg);
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
    {
    }

    std::string getId() const override
    {
        return id;
    }

    virtual std::string found_in_f(Context &context, std::string id, std::string function) const override
    {
        bool found_var = false;

        std::string found_in_function;
        for (int i = 0; i < context.functions[function].variables_map.size() && !found_var; i++)
        {
            if (context.functions[function].variables_map.find(id) != context.functions[function].variables_map.end())
            {
                found_var = true;
                return function;
            }
        }
        if (context.functions[function].previous_function == function)
        {
            return "NOT_FOUND";
        }
        else
        {
            if (found_var == false)
            {
                return found_in_f(context, id, context.functions[function].previous_function);
            }
        }
    }

    virtual int maps_total_offsets(Context &context, std::string start_function, std::string end_function) const override
    {
        if (start_function == end_function) {
            return 0;
        }
        return context.functions[start_function].variables_map.size() + maps_total_offsets(context, context.functions[start_function].previous_function, end_function);
    }

    virtual void print(std::ostream &dst) const override
    {
        dst << "DECALARATOR :";
        dst << id;
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        // dst<< "#DEBUG : IN DECLARATOR \n";
        int found_enum_index = -1;
        for (int i = 0; i < context.enums.size(); i++)
        {
            if (context.enums[i].id == id)
            {
                found_enum_index = i;
            }
        }

        bool found_var = false;
        for (int i = 0; i < context.functions[context.current_function].variables_map.size() && !found_var; i++)
        {
            if (context.functions[context.current_function].variables_map.find(id) != context.functions[context.current_function].variables_map.end())
            {
                found_var = true;
            }
        }

        std::string f = found_in_f(context, id, context.current_function);

        if (found_enum_index != -1)
        {
            dst << "#DEBUG ENUM call: " << context.enums[found_enum_index].id << " <-> " << context.enums[found_enum_index].value << '\n';
            dst << "li $" << destReg << "," << context.enums[found_enum_index].value << '\n';
        }
        
        // else if (context.functions[context.current_function].variables_map[id].declared_in_function != context.current_function)
        // {
        //     if (found_var)
        //     {
        //         dst << "#DEBUG Declarator: FOUND_VAR, " << id << " from current function " << context.current_function << '\n';
        //         int curr_offset = 4 * (context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[id].old_map_size) + 12;
        //         dst << "lw $" << destReg << ",";       // need to set other register, depending on free
        //         dst << curr_offset << "($fp)" << '\n'; // specific location in stack for the variable (to check in alive variables vector)
        //     }
        //     else if (f != "NOT_FOUND")
        //     { // found in parent function
        //         dst << "#DEBUG Declarator: FOUND_VAR, " << id << " from function " << f << '\n';
        //         int maps_offsets = maps_total_offsets(context, context.current_function, f);
        //         int curr_offset = 4 * (context.functions[f].variables_map.size() - context.functions[f].variables_map[id].old_map_size) + 12 + 4 * maps_offsets;
        //         dst << "lw $" << destReg << ",";       // need to set other register, depending on free
        //         dst << curr_offset << "($fp)" << '\n'; // specific location in stack for the variable (to check in alive variables vector)
        //     }
        // }
        else
        // {
            if ( f != "NOT_FOUND" )
            {
                dst << "#DEBUG Declarator: NOT_FOUND_VAR, but found, " << id << " from function " << f << '\n';
                int maps_offsets = maps_total_offsets(context, context.current_function, f);
                dst<<"#DEBUG : maps_offsets: "<<maps_offsets<<" ; context.functions[f].variables_map.size(): "<<context.functions[f].variables_map.size()<<" ; context.functions[f].variables_map[id].old_map_size: "<<context.functions[f].variables_map[id].old_map_size<<'\n';
                int curr_offset = 4 * (context.functions[f].variables_map.size() - context.functions[f].variables_map[id].old_map_size) + 12 + 4 * maps_offsets;
                dst << "lw $" << destReg << ",";       // need to set other register, depending on free
                dst << curr_offset << "($fp)" << '\n'; // specific location in stack for the variable (to check in alive variables vector)
            }
            // else
            // {
            //     variable v;
            //     v.reg = destReg;
            //     v.size = 4; // only for int !!!
            //     v.declared_in_function = context.current_function;
            //     v.old_map_size = context.functions[context.current_function].variables_map.size() + 1; //------------------------------
            //     context.functions[context.current_function].variables_map.insert({id, v});
            //     dst << "#DEBUG Declarator: adding to map " << context.current_function << " at address: " << id << " making map size = " << context.functions[context.current_function].variables_map.size() << '\n';

            //     int curr_offset = 4 * (context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[id].old_map_size) + 12;
            //     dst << "sw $" << destReg << ",12($fp)" << '\n';
            //     dst << "#DEBUG: reg of argument=" << destReg << " " << id << '\n';
            // }
        }
    // }
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
        : left(_left), middle(_middle), right(_right)
    {
    }

    std::string getId() const
    {
        return left->getId();
    }

    virtual void print(std::ostream &dst) const override
    {
        left->print(dst);
        dst << " " << middle << " ";
        right->print(dst);
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        // check if variable exists in the function and if it has the same declared_in_scope
        int found_var_here = false;
        for (int i = 0; i < context.functions[context.current_function].variables_map.size() && !found_var_here; i++)
        {
            if (context.functions[context.current_function].variables_map.find(left->getId()) != context.functions[context.current_function].variables_map.end())
            {
                found_var_here = true;
            }
        }
        std::string f;

        if (found_var_here)
        {
            if (context.functions[context.current_function].variables_map[left->getId()].declared_in_function == context.current_function)
                f = context.current_function;
            else
                f = context.current_function;
        }
        else
        {
            f = left->found_in_f(context, left->getId(), context.current_function);
        }

        if (middle == "=")
        {
            dst << "#DEBUG AssignOperator: in variables_map for " << left->getId() << '\n';

            dst << "#DEBUG : left->getNature = " << left->getNature() << '\n';
            if (left->getNature() == "ArrayCall")
            {

                right->generateMIPS(dst, context, destReg); // li or lw but we need to access register number, through a function
                int regIndex = context.allocate(context.current_function);
                left->getSize()->generateMIPS(dst, context, regIndex); // call what is between brackets and store in index register

                // multiply regIndex by 4
                int regMultiplier4 = context.allocate(context.current_function_name);
                dst << "li $" << regMultiplier4 << ",4" << '\n';
                dst << "mult $" << regIndex << ",$" << regMultiplier4 << '\n';
                context.regFile.freeReg(regMultiplier4);

                dst << "mflo $" << regIndex << '\n';

                int regOffset = context.allocate(context.current_function);
                int curr_map_size = (context.functions[context.current_function].variables_map.size());
                dst << "#DEBUG : curr_map_size = " << curr_map_size;

                int old_map_size = (context.functions[context.current_function].variables_map[left->getId()].old_map_size);
                dst << "#DEBUG : old_map_size =" << old_map_size << '\n';

                int curr_offset = 4 * (curr_map_size - old_map_size) + 12;
                dst << "addi $" << regOffset << ",$" << regIndex << ",-" << curr_offset << '\n';
                dst << "sub $" << regOffset << ",$0,$" << regOffset << '\n';

                int regAddress = context.allocate(context.current_function);
                dst << "add $" << regAddress << ",$" << regOffset << ",$fp" << '\n';

                dst << "sw $";
                dst << destReg;
                dst << ",0($" << regAddress << ")" << '\n'; // store output register of the calculations in respective stack location

                context.regFile.freeReg(regAddress);
            }
            else
            {
                dst << "#DEBUG Assign operator: OTHER__________________________________________________________________" << '\n';
                right->generateMIPS(dst, context, destReg); // li or lw but we need to access register number, through a function
                int maps_offsets = left->maps_total_offsets(context, context.current_function, f);
                int curr_offset = 4 * (context.functions[f].variables_map.size() - context.functions[f].variables_map[left->getId()].old_map_size) + 12 + 4 * maps_offsets;                
                dst << "sw $";
                dst << destReg;
                dst << "," << curr_offset << "($fp)" << '\n'; // store output register of the calculations in  respective stack location
                // left->generateMIPS(dst, context, context.functions[f].variables_map[left->getId()].reg);
            }
            // context.regFile.freeReg(context.functions[f].variables_map[left->getId()].reg);
        }
        else if (middle == "*=")
        {
            int regLeft = context.allocate(f);
            int regRight = context.allocate(f);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight);

            dst << "mult $" << regLeft << ", $" << regRight << '\n';
            dst << "mflo $" << regLeft << '\n';

            int curr_offset = 4 * (context.functions[f].variables_map.size() - context.functions[f].variables_map[left->getId()].old_map_size) + 12;
            dst << "sw $";
            dst << regLeft;
            dst << "," << curr_offset << "($fp)" << '\n'; // store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);
        }
        else if (middle == "/=")
        {
            int regLeft = context.allocate(f);
            int regRight = context.allocate(f);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight);

            dst << "div $" << regLeft << ", $" << regRight << '\n';
            dst << "mflo $" << regLeft << '\n';

            int curr_offset = 4 * (context.functions[f].variables_map.size() - context.functions[f].variables_map[left->getId()].old_map_size) + 12;
            dst << "sw $";
            dst << regLeft;
            dst << "," << curr_offset << "($fp)" << '\n'; // store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);
        }
        else if (middle == "%=")
        {
            int regLeft = context.allocate(f);
            int regRight = context.allocate(f);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight);

            dst << "div $" << regLeft << ", $" << regRight << '\n';
            dst << "mfhi $" << regLeft << '\n';

            int curr_offset = 4 * (context.functions[f].variables_map.size() - context.functions[f].variables_map[left->getId()].old_map_size) + 12;
            dst << "sw $";
            dst << regLeft;
            dst << "," << curr_offset << "($fp)" << '\n'; // store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);
        }
        else if (middle == "+=")
        {
            int regLeft = context.allocate(f);
            int regRight = context.allocate(f);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight);

            dst << "addu $" << regLeft << ", $" << regLeft << ", $" << regRight << '\n';

            int curr_offset = 4 * (context.functions[f].variables_map.size() - context.functions[f].variables_map[left->getId()].old_map_size) + 12;
            dst << "sw $";
            dst << regLeft;
            dst << "," << curr_offset << "($fp)" << '\n'; // store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);
        }
        else if (middle == "-=")
        {
            int regLeft = context.allocate(f);
            int regRight = context.allocate(f);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight);

            dst << "subu $" << regLeft << ", $" << regLeft << ", $" << regRight << '\n';

            int curr_offset = 4 * (context.functions[f].variables_map.size() - context.functions[f].variables_map[left->getId()].old_map_size) + 12;
            dst << "sw $";
            dst << regLeft;
            dst << "," << curr_offset << "($fp)" << '\n'; // store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);
        }
        else if (middle == "<<=")
        {
            int regLeft = context.allocate(f);
            int regRight = context.allocate(f);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight);

            dst << "sllv $" << regLeft << ",$" << regLeft << ",$" << regRight << '\n';

            int curr_offset = 4 * (context.functions[f].variables_map.size() - context.functions[f].variables_map[left->getId()].old_map_size) + 12;
            dst << "sw $";
            dst << regLeft;
            dst << "," << curr_offset << "($fp)" << '\n'; // store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);
        }
        else if (middle == ">>=")
        {
            int regLeft = context.allocate(f);
            int regRight = context.allocate(f);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight);

            dst << "srlv $" << regLeft << ",$" << regLeft << ",$" << regRight << '\n';

            int curr_offset = 4 * (context.functions[f].variables_map.size() - context.functions[f].variables_map[left->getId()].old_map_size) + 12;
            dst << "sw $";
            dst << regLeft;
            dst << "," << curr_offset << "($fp)" << '\n'; // store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);
        }
        else if (middle == "&=")
        {
            int regLeft = context.allocate(f);
            int regRight = context.allocate(f);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight);

            dst << "and $" << regLeft << ",$" << regLeft << ",$" << regRight << '\n';

            int curr_offset = 4 * (context.functions[f].variables_map.size() - context.functions[f].variables_map[left->getId()].old_map_size) + 12;
            dst << "sw $";
            dst << regLeft;
            dst << "," << curr_offset << "($fp)" << '\n'; // store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);
        }
        else if (middle == "^=")
        {
            int regLeft = context.allocate(f);
            int regRight = context.allocate(f);

            left->generateMIPS(dst, context, regLeft);
            right->generateMIPS(dst, context, regRight);

            dst << "xor $" << regLeft << ",$" << regLeft << ",$" << regRight << '\n';

            int curr_offset = 4 * (context.functions[f].variables_map.size() - context.functions[f].variables_map[left->getId()].old_map_size) + 12;
            dst << "sw $";
            dst << regLeft;
            dst << "," << curr_offset << "($fp)" << '\n'; // store output register of the calculations in  respective stack location

            context.regFile.freeReg(regRight);
            context.regFile.freeReg(regLeft);
        }
        else
        {
            std::cerr << "Error: operand for assignment not accepted" << std::endl;
        }
    }
};

#endif