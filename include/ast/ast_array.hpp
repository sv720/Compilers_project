#ifndef ast_array_hpp
#define ast_array_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ast_expression.hpp"
#include "ast_expressionlist.hpp"
#include "context.hpp"

class ArrayDeclarator
    : public Expression
{
private:
    ExpressionPtr id;
    ExpressionPtr size;
public:
    ArrayDeclarator(ExpressionPtr _id, ExpressionPtr _size)
        : id(_id)
        , size(_size)
    {}

    ArrayDeclarator(ExpressionPtr _id)
        : id(_id)
        , size(new EmptyExpr())
    {}

    ~ArrayDeclarator(){
        delete id;
        delete size;
    }

    ExpressionPtr getSize() const
    { return size; }

    virtual std::string getNature(Context &context) const override
    { 
        return "ArrayDeclarator";
    }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"ARRAY: ";
        id->print(dst);
        dst<<"[";
        size->print(dst);
        dst<<"]";
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst << "#DEBUG: ARRAYDECLARATOR "<<'\n';
        dst << "#DEBUG: adding array to stack "<<'\n';
        int array_size = size->getValue();
        dst << "addiu $sp,$sp,-"<< (array_size)*4 <<" \n"; //have a new array so need to make some space on the stack : Scott : no -1 as need to free exactly number of words present
        //Scott: we want to keep old_fp and sp and bottom of allocated stack
        dst<< "move $fp,$sp"<< '\n'; // move frame pointer back to the bottom
        dst<< "sw $25,4($fp)"<< '\n'; //we move the old (out of function) frame pointer just above the new fp
        dst<< "sw $31,8($fp)" << '\n'; //we store old_pc just above old_fp
        
   
        //declare the array as a normal variable, declarator could have been used
        variable v;
        v.reg = destReg;
        v.size = 4;
        v.declared_in_function = context.current_function;
        v.old_map_size = context.functions[context.current_function].variables_map.size() + 1; //------------------------------

        context.current_array_label = id->getId();
        context.functions[context.current_function].variables_map.insert({id->getId(), v});
        
        for(int i = 1; i<array_size; i++){
            //dst<<"#DEBUG i = " << i <<'\n';
            std::string item_id = id->getId() + " " + std::to_string(i); 
            context.functions[context.current_function].variables_map.insert({item_id, v});

        }
        dst<<"#DEBUG ARRAYDeclarator: adding to map at address of ARRAY " << id->getId() << " making map size = "<< context.functions[context.current_function].variables_map.size() <<'\n';
    }
    
};

class ArrayInit
    : public Expression
{
protected:
    ExpressionPtr id;
    ExpressionListPtr elements;
public:
    ArrayInit(ExpressionPtr id, ExpressionListPtr _elements)
        : id(id)
        , elements(_elements)
    {}

    ~ArrayInit(){
        delete id;
        delete elements;
    }

    virtual void print(std::ostream &dst) const override
    {
        dst <<"array init";
        dst<<" {:";
        for (ExpressionPtr e : elements->list) {
            e->print(dst);
        }
        dst<<":} ";
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        //declare the array as a normal variable, declarator could have been used
        // variable v;
        // v.reg = destReg;
        // v.size = 4;
        // v.declared_in_function = context.current_function;
        // v.old_map_size = context.functions[context.current_function].variables_map.size() + 1; //------------------------------

        // context.current_array_label = id->getId();
        // context.functions[context.current_function].variables_map.insert({id->getId(), v});
        
        // for(int i = 1; i<elements->list.size(); i++){
        //     //dst<<"#DEBUG i = " << i <<'\n';
        //     std::string item_id = id->getId() + " " + std::to_string(i); 
        //     context.functions[context.current_function].variables_map.insert({item_id, v});

        // }

        dst << "#DEBUG: ARRAYINIT "<<'\n';
        // for ( int i = 0; i < elements->list.size(); i++ ) {
        //     // get the address of where we declared the array (label)

        //     int regElement = context.allocate(context.current_function);
        //     dst<<"#DEBUG : genrateMIPS ArrayINIT"<<'\n';
        //     elements->list[i]->generateMIPS(dst, context, regElement);

        //     //once we know the address, we can store the value stored in regElement into specific memory location
        //     // i*4 is the offset from the initial array label (only int)

        //     //would this be the address where we declare the start of the array????
        //     int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[context.current_array_label].old_map_size) + 12;
        //     dst<<"#DEBUG ARRAY INIT: adding element "<<elements->list[i] << " in array " << context.current_array_label<< '\n';
        //     dst<<"#DEBUG ARRAY offset = "<< curr_offset << " , element offset = "<< i*4 << '\n';
        //     dst<<"lw $"<<regElement<<","<<i*4+curr_offset<<"($fp)"<<'\n'; 
        // }
    }
    
};

class ArrayCall
    : public Expression
{
private:
    ExpressionPtr id;
    ExpressionPtr index;
public:
    ArrayCall(ExpressionPtr _id, ExpressionPtr _index)
        : id(_id)
        , index(_index)
    {}

    ~ArrayCall(){
        delete id;
        delete index;
    }

    std::string getId() const override
    { return id->getId(); }

    virtual ExpressionPtr getSize() const override //not sure what this does
    { return index; }

    virtual std::string getNature(Context &context) const override
    { 
        return "ArrayCall";
    }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"index->getId() = "<< index->getId()<<'\n';
        id->print(dst);
        dst<<"[";
        index->print(dst);
        dst<<"]";
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        // x[a] == &x+a*4
        dst << "#DEBUG: ARRAYCALL "<<'\n';

        int regIndex = context.allocate(context.current_function);
        index->generateMIPS(dst, context, regIndex); // call what is between brackets and store in index register

        // multiply regIndex by 4
        int regMultiplier4 = context.allocate(context.current_function_name);
        dst << "li $" << regMultiplier4 << ",4" << '\n';
        dst << "mult $" << regIndex << ",$" << regMultiplier4 << '\n';
        // context.regFile.freeReg(regMultiplier4);

        dst << "mflo $" << regIndex << '\n';

        int regOffset = context.allocate(context.current_function);
        int curr_map_size = (context.functions[context.current_function].variables_map.size());
        dst << "#DEBUG : curr_map_size = " << curr_map_size;

        int old_map_size = (context.functions[context.current_function].variables_map[id->getId()].old_map_size);
        dst << "#DEBUG : old_map_size =" << old_map_size << '\n';

        int curr_offset = 4 * (curr_map_size - old_map_size) + 12;
        dst << "addi $" << regOffset << ",$" << regIndex << ",-" << curr_offset << '\n';
        dst << "sub $" << regOffset << ",$0,$" << regOffset << '\n';

        int regAddress = context.allocate(context.current_function);
        dst << "add $" << regAddress << ",$" << regOffset << ",$fp" << '\n';

        // id->generateMIPS(dst, context, destReg);
        // int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[id->getId()].old_map_size) + 12;
        // int element_offset = index->getValue()*4;
        // dst << "#DEBUG current map size = " << context.functions[context.current_function].variables_map.size() << '\n';
        // dst << "#DEBUG old map size = " << context.functions[context.current_function].variables_map[id->getId()].old_map_size << '\n';
        // dst<<"#DEBUG element_offset = "<<element_offset <<'\n';
        dst<<"lw $"<<destReg<<","; // need to set other register, depending on free
        dst<<"0($"<< regAddress <<")"<<'\n'; //specific location in stack for the variable (to check in alive variables vector)

        context.regFile.freeReg(regIndex);
        context.regFile.freeReg(regOffset);
        context.regFile.freeReg(regMultiplier4);
        context.regFile.freeReg(regAddress);

    }
    
};

#endif