#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include "ast/ast_expressionlist.hpp"
#include "context.hpp"


typedef union {

        float f;
        struct
        {
            unsigned int f : 23;
            unsigned int e : 8;
            unsigned int s : 1;

        } ieee754;
    } myfloat;

// class Variable
//     : public Expression
// {
// private:
//     std::string id;
// public:
//     Variable(const std::string &_id)
//         : id(_id)
//     {}

//     virtual std::string getId() const override
//     { return id; }

//     virtual void print(std::ostream &dst) const override
//     {
//         dst<<"VARAIBLE : ";
//         dst<<id;
//     }

//     virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
//     {
//         variable v;
//         v.reg = destReg;
//         v.old_map_size = context.functions[context.current_function].variables_map.size() +1; //------------------------------
//         context.functions[context.current_function].variables_map.insert({id, v});
//         dst<<"#DEBUG Declarator: adding to map at address" << id << " making map size = "<< context.functions[context.current_function].variables_map.size() <<'\n';

//         //TODO: check if valid
//         int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - context.functions[context.current_function].variables_map[id].old_map_size) + 12;
//         dst<<"lw $"<<destReg<<","; // need to set other register, depending on free
//         dst<<curr_offset<<"($fp)"<<'\n'; //specific location in stack for the variable (to check in alive variables vector) //S: Does this do anything? TODO : check if can remove
//     }
   
// };


class Integer
    : public Expression
{
private:
    int value;
public:
    Integer()
    {}

    Integer(int _value)
        : value(_value)
    {}

    int getValue() const
    { return value; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<value;
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"li $"<<destReg<<","; // need to set other register
        dst<<value<<'\n'; 
    }
};

class Float
    : public Expression
{
private:
    float value;
    myfloat var; 
    unsigned int float_word;

public:
    Float()
    {    }

    Float(float _value)
        : value(_value)
    {
        var.f = value;

        float_word = (1&var.ieee754.s)*4294967296 + (255&var.ieee754.e)*8388608 + (8388607&var.ieee754.f);
        //float_word = var.ieee754.s<<32 + var.ieee754.e<<23 + var.ieee754.f;
    }


    virtual void print(std::ostream &dst) const override
    {
        dst<<"FLOAT VALUE = ";
        dst<<value;

        dst<<"s = "<< var.ieee754.s << "e = "<< var.ieee754.e << " manista = "<< var.ieee754.f <<'\n';
        dst<<"float_word = "<< float_word;
    }

    virtual std::string getNature(Context &context) const override
    {
        return "Float";
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {  
        if (destReg == -1){ //MEANS WE WANT TO RETURN so write to $f0
            dst<<"li $f0,"; // need to set other register
            dst<<(0xFFFF&float_word)<<'\n'; 

            dst<<"lui $f0,";
            dst<< (unsigned(0xFFFF0000&float_word))/65536<<'\n';

        } 
        else { //other times we use regular registers
            dst<<"li $"<<destReg<<","; // need to set other register
            dst<<(0xFFFF&float_word)<<'\n'; 

            dst<<"lui $"<<destReg<<",";
            dst<< (unsigned(0xFFFF0000&float_word))/65536<<'\n'; //TODO: check that here division is always unsigned division (used to do LSR)
        }     
        
    }
};

class Double
    : public Expression
{
private:
    double value;
public:
    Double()
    {}

    Double(int _value)
        : value(_value)
    {}

    int getValue() const
    { return value; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<value;
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"li $"<<destReg<<","; // need to set other register
        dst<<value<<'\n'; 
    }
};


class Character
    : public Expression
{
private:
    std::string id;
    char c;

public:
    Character(const std::string &_id)
        : id(_id)
    {
        c = id[1];
    }

    std::string getId() const override
    {
        return id;
    }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"id = "<<id<< "and";
        dst<<"CHAR_LITERAL c = "<<c;
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"li $"<<destReg<<","; // need to set other register
        dst<<(int)c<<'\n'; 
    }


   // int getValue() const
    //{
     //   return int(c); //should return ASCII value of the character
    //}
};


//________________________________________________


class Return
    : public Expression
{
private:
    ExpressionPtr arg;
public:
    Return(ExpressionPtr _arg)
        : arg(_arg)
    {}

    virtual void print(std::ostream &dst) const override
    {
        dst<<"return ";
        arg->print(dst);
    }
    
    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        //if (context.functions[context.current_function].variables_map.find(arg->getId()) != context.functions[context.current_function].variables_map.end())
        //{
          //dst <<"#DEBUG : found in map"<< '\n';
      //dst<<"#DEBUG : context.functions[context.current_function].variables_map.arg->getId()].type = "<<context.functions[context.current_function].variables_map[arg->getId()].type <<'\n';
        //}

        dst << "#DEBUG : arg->getNature(context) = " << arg->getNature(context)<< '\n';
        
        dst<<"#DEBUG: calling generateMIPS on arg is return \n";
        //if(context.functions[context.current_function].variables_map[arg->getId()].type == "float"){
        //    arg->generateMIPS(dst, context, -1);
        //}
        //else {
            arg->generateMIPS(dst, context, 2);
        //}
        
        
        dst<<"j end_"<<context.current_function_name<<'\n';
        dst<<"nop"<<'\n';
    }

};


//________________________________________________

class Root
    : public Expression
{
private:
    ExpressionListPtr arg;
public:
    Root(ExpressionListPtr _arg)
        : arg(_arg)
    {}

    virtual void print(std::ostream &dst) const override
    {
        arg->print(dst);
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        // dst<<".global "; //must be called after generating all mips so we know which function to add here
        // for (std::string f_name : context.functions_names) {
        //     dst<<f_name<<' ';
        // }
        // dst<<'\n';
        // dst<<".cprestore 8"<<'\n';
        arg->generateMIPS(dst, context, destReg);
    }

};



#endif
