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

    std::string getId() const override
    { return id->getId(); }

    virtual ExpressionPtr getSize() const override
    { return size; }

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
        dst << "addiu $sp,$sp,-"<< (array_size-1)*4 <<" \n"; //have a new array so need to make some space on the stack : Scott : agree about the -1 (can use the slot made available just before)
        //Scott: we want to keep old_fp and sp and bottom of allocated stack
        dst<< "move $fp,$sp"<< '\n'; // move frame pointer back to the bottom
        dst<< "sw $25,4($fp)"<< '\n'; //we move the old (out of function) frame pointer just above the new fp
        dst<< "sw $31,8($fp)" << '\n'; //we store old_pc just above old_fp
        
   

        //declare the array as a normal variable, declarator could have been used
        variable v;
        v.reg = destReg;
        v.size = array_size*4;
        v.old_map_size = context.functions[context.current_function].variables_map.size(); //------------------------------

        context.current_array_label = id->getId();
        context.functions[context.current_function].variables_map.insert({id->getId(), v});
        for(int i = 1; i<array_size; i++){
            //dst<<"#DEBUG i = " << i <<'\n';
            std::string item_id = id->getId() + std::to_string(i); 
            context.functions[context.current_function].variables_map.insert({item_id, v});

        }
        dst<<"#DEBUG ARRAYDeclarator: adding to map at address of ARRAY " << id->getId() << " making map size = "<< context.functions[context.current_function].variables_map.size() <<'\n';
/*
        //TODO: check if valid
        int curr_offset = 4*(context.functions[context.current_function].variables_map[id->getId()].old_map_size - context.functions[context.current_function].variables_map.size() ) + 12;
        dst<<"#DEBUG array declarator: curr_map_array: "<<context.functions[context.current_function].variables_map.size()<<'\n';
        dst<<"#DEBUG array declarator: old_map_size: "<<context.functions[context.current_function].variables_map[id->getId()].old_map_size<<'\n';
        dst<<"#DEBUG array declarator: curr_offset: "<<curr_offset<<'\n';
        dst<<"sw $";
        dst<<destReg;
        dst<<","<<curr_offset<<"($fp)"<<'\n';

        //Scott: Don't think we need to store anything here (in MIPS)?

        // context.regFile.freeReg(context.functions[context.current_function].variables_map[left->getId()].reg);

        */
    }
    
};

class ArrayInit
    : public Expression
{
private:
    ExpressionListPtr elements;
public:
    ArrayInit(ExpressionListPtr _elements)
        : elements(_elements)
    {}

    ~ArrayInit(){
        delete elements;
    }

    ExpressionListPtr getElements() const
    { return elements; }

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
        dst << "#DEBUG: ARRAYINIT "<<'\n';
        for ( int i = 0; i < elements->list.size(); i++ ) {
            // get the address of where we declared the array (label)

            int regElement = context.allocate(context.current_function_name);
            dst<<"#DEBUG : genrateMIPS ArrayINIT"<<'\n';
            elements->list[i]->generateMIPS(dst, context, regElement);

            //once we know the address, we can store the value stored in regElement into specific memory location
            // i*4 is the offset from the initial array label (only int)

            //would this be the address where we declare the start of the array????
            int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[context.current_array_label].old_map_size) + 12;
            dst<<"#DEBUG ARRAY INIT: adding element "<<elements->list[i] << " in array " << context.current_array_label<< '\n';
            dst<<"#DEBUG ARRAY offset = "<< curr_offset << " , element offset = "<< i*4 << '\n';
            dst<<"lw $"<<regElement<<","<<i*4+curr_offset<<"($fp)"<<'\n'; 
        }
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

    virtual std::string getNature() const override
    { 
        bool is_digit = true;
        for (char c : index->getId()){
            if(!isdigit(c)){
                is_digit = false;
            }
        }
        if(index->getId() == "<NULL>"){ //TODO : find a cleaner way of handling this
            is_digit = true;
        }
        if(!is_digit){
            return "Variable_Indexed_Array"; 
        }
        else{ return "Constant_Indexed_Array";}
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
        int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[id->getId()].old_map_size) + 12;
        int element_offset = index->getValue()*4;
        dst << "#DEBUG current map size = " << context.functions[context.current_function].variables_map.size() << '\n';
        dst << "#DEBUG old map size = " << context.functions[context.current_function].variables_map[id->getId()].old_map_size << '\n';
        dst<<"lw $"<<destReg<<","; // need to set other register, depending on free
        dst<<curr_offset-element_offset<<"($fp)"<<'\n'; //specific location in stack for the variable (to check in alive variables vector)
    }
    
};

#endif