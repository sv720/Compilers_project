#ifndef ast_operators_hpp
#define ast_operators_hpp

#include <string>
#include <iostream>
#include <cmath>
#include "context.hpp"

class Operator
    : public Expression
{    
protected:
    ExpressionPtr right; //why was this private? (assumed was accident)
    ExpressionPtr left;
    Operator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}
    Operator(ExpressionPtr _arg)
        : left(_arg)
    {}
public:
    virtual ~Operator()
    {
        delete left;
        delete right;
    }

    virtual const char *getOpcode() const =0;
    virtual const char *getOpInstruction() const =0;

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    std::string getId() const override {}

    virtual void print(std::ostream &dst) const override
    {
        dst<<"( ";
        left->print(dst);
        dst<<" ";
        dst<<getOpcode();
        dst<<" ";
        right->print(dst);
        dst<<" )";
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        // right->generateMIPS(dst, context, destReg);
        // left->generateMIPS(dst, context, destReg);
        // dst<<getOpInstruction()<<" $4,"; //destination register
        // dst<<"$"<<context.functions[context.current_function].variables_map[left->getId()].reg<<",";
        // dst<<"$"<<context.functions[context.current_function].variables_map[right->getId()].reg<<"\n";
    }
};


class AddOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "+"; }
    virtual const char *getOpInstruction() const override
    { return "add"; }
public:
    AddOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#AddOperator generateMIPS Called"<<'\n';
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB);
        dst<<"add $"<< destReg << ",$"<<regA<<",$"<<regB<<'\n';
        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }
    
};

class SubOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "-"; }
    virtual const char *getOpInstruction() const override
    { return "sub"; }
public:
    SubOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
    
    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#SubOperator generateMIPS Called"<<'\n';
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB); 
        dst<<"sub $"<< destReg << ",$"<<regA<<",$"<<regB<<'\n';
        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }
};


class MulOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "*"; }
    virtual const char *getOpInstruction() const override
    { return "mult"; }
public:
    MulOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#MulOperator generateMIPS Called"<<'\n';
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB); //TODO: why can't we access right here?
        dst<<"mult $"<<regA<<",$"<<regB<<'\n'; //remember: this goes in HI and LO registers
        dst<<"mflo $"<<destReg<<'\n'; //TBC : LO resutls goes into destReg (usually $2)
        dst<<"mfhi $"<<destReg+1<<'\n'; //TBC : HI result goes into destReg +1 (usually $3)
        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }

};

class DivOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "/"; }
    virtual const char *getOpInstruction() const override
    { return "div"; }
public:
    DivOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#DivOperator generateMIPS Called"<<'\n';
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB); //TODO: why can't we access right here?
        dst<<"div $"<<regA<<",$"<<regB<<'\n'; //remember: this goes in HI and LO registers
        dst<<"mflo $"<<destReg<<'\n'; //TBC : LO resutls goes into destReg (usually $2)
        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }
};

class ModOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "%"; }
    virtual const char *getOpInstruction() const override
    { return "mod"; }
public:
    ModOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#ModOperator generateMIPS Called"<<'\n';
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB); //TODO: why can't we access right here?
        dst<<"div $"<<regA<<",$"<<regB<<'\n'; //remember: this goes in HI and LO registers
        dst<<"mfhi $"<<destReg<<'\n'; //TBC : HI result goes into destReg +1 (usually $3)
        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }
};

// SHIFTS -----------------------------------

class LeftShiftOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "<<"; }
    virtual const char *getOpInstruction() const override
    { return "sllv"; }
public:
    LeftShiftOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#LeftShiftOperator generateMIPS Called"<<'\n';
        
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB);
        dst<<"sllv $"<< destReg << ",$"<<regA<<",$"<<regB<<'\n';
        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }

};

class RightShiftOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return ">>"; }
    virtual const char *getOpInstruction() const override
    { return "sra"; } //sra???
public:
    RightShiftOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#RightShiftOperator generateMIPS Called"<<'\n';
        
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB);
        dst<<"sra $"<< destReg << ",$"<<regA<<",$"<<regB<<'\n';
        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }

};

// COMPARISONS -----------------------------------

class SmallerOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "<"; }
    virtual const char *getOpInstruction() const override
    { return "L"; }
public:
    SmallerOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#SmallerOperator generateMIPS Called"<<'\n';
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB);
        dst<<"slt $"<< destReg << ",$"<<regA<<",$"<<regB<<'\n'; //if left<right : set destReg to 1
        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }

};

class GreaterOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return ">"; }
    virtual const char *getOpInstruction() const override
    { return "G"; }
public:
    GreaterOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#GreaterOperator generateMIPS Called"<<'\n';
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB);
        dst<<"slt $"<< destReg << ",$"<<regB<<",$"<<regA<<'\n'; //if right<left : set destReg to 1
        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }

};

class LEOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "<="; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    LEOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
    
    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#LEOperator generateMIPS Called"<<'\n';
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB);
        dst<<"addi $"<<regA<<",$"<<regA<< ",-1"<< '\n'; //shift by -1 as a <= b equivalent to a-1 < b
        dst<<"slt $"<< destReg << ",$"<<regA<<",$"<<regB<<'\n'; //if right<left : set destReg to 1
        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }

};

class GEOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return ">="; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    GEOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#GEOperator generateMIPS Called"<<'\n';
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB);
        dst<<"addi $"<<regB<<",$"<<regB<< ",-1"<< '\n'; //shift by -1 as b <= a equivalent to b-1 < a
        dst<<"slt $"<< destReg << ",$"<<regB<<",$"<<regA<<'\n'; //if right<left : set destReg to 1
        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }

};

class EQOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "=="; }
    virtual const char *getOpInstruction() const override
    { return "equal"; }
public:
    EQOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#EQOperator generateMIPS Called"<<'\n';
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB);
        dst<<"seq $"<<destReg<<",$"<<regA<<",$"<<regB<<'\n'; 
        //if a number neither smaller neither greater to its pear, it must be equal
        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }
};

class NEOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "!="; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    NEOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
    
    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#NEOperator generateMIPS Called"<<'\n';
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB);
        dst<<"sne $"<<destReg<<",$"<<regA<<",$"<<regB<<'\n'; 
        //if either number is strictly greater than the other; they can't be equal
        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }


};

// BITWISE -----------------------------------

class ANDOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "&"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    ANDOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#ANDOperator generateMIPS Called"<<'\n';
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB);
        dst<<"and $"<< destReg<<",$"<<regA<<",$"<<regB<<'\n'; 

        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }


};

class XOROperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "^"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    XOROperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#XOROperator generateMIPS Called"<<'\n';
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB);
        dst<<"xor $"<< destReg<<",$"<<regA<<",$"<<regB<<'\n'; 

        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }

};

class OROperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "|"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    OROperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#OROperator generateMIPS Called"<<'\n';
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB);
        dst<<"or $"<< destReg<<",$"<<regA<<",$"<<regB<<'\n'; 

        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
    }

};

class OnesComplementOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "~"; }
    virtual const char *getOpInstruction() const override
    { return "1scomplement"; }
public:
    OnesComplementOperator(ExpressionPtr _left)
        : Operator(_left)
    {}

    virtual void print(std::ostream &dst) const override
    {
        dst<<" ~( ";
        left->print(dst);
        dst<<" )";
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#OnesComplementOperator generateMIPS Called"<<'\n';
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        dst<<"and $"<< destReg<<",$"<<regA<<", $"<<regA<<'\n';
        dst<<"not $"<< destReg<<'\n';

        context.regFile.freeReg(regA);
    }


};

// LOGICAL -----------------------------------

class LogicalANDOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "&&"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    LogicalANDOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB);
        int regC = context.allocate(context.current_function);
        int regD = context.allocate(context.current_function);

        dst<<"sne $"<< regC<<",$"<<regA<<",$0"<<'\n';
        dst<<"sne $"<< regD<<",$"<<regB<<",$0"<<'\n';
        dst<<"and $"<<destReg<<",$"<<regC<<",$"<<regD<<'\n';


        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
        context.regFile.freeReg(regC);
        context.regFile.freeReg(regD);
  
    }
};

class LogicalOROperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "||"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    LogicalOROperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        int regA = context.allocate(context.current_function);
        left->generateMIPS(dst, context, regA);
        int regB = context.allocate(context.current_function);
        right->generateMIPS(dst, context, regB);
        int regC = context.allocate(context.current_function);
        int regD = context.allocate(context.current_function);
    
        dst<<"sne $"<< regC<<",$"<<regA<<",$0"<<'\n';
        dst<<"sne $"<< regD<<",$"<<regB<<",$0"<<'\n';
        dst<<"or $"<<destReg<<",$"<<regC<<",$"<<regD<<'\n';


        context.regFile.freeReg(regA);
        context.regFile.freeReg(regB);
        context.regFile.freeReg(regC);
        context.regFile.freeReg(regD);
        
    }

};

class LogicalNOTOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "!"; }
    virtual const char *getOpInstruction() const override
    { return "not"; }
public:
    LogicalNOTOperator(ExpressionPtr _left)
        : Operator(_left)
    {}

    virtual void print(std::ostream &dst) const override
    {
        dst<<" !( ";
        left->print(dst);
        dst<<" )";
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#LogicalNOTOperator generateMIPS Called"<<'\n';
        left->generateMIPS(dst, context, destReg);
        dst<<"not $"<< destReg<<'\n';
        // dst<<"nor $"<< destReg<<", $"<<destReg<<", $"<<destReg<<'\n';
    }


};

// INCREMENT/DECREMENT -----------------------------------

class PostIncrementOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "post++"; }
    virtual const char *getOpInstruction() const override
    { return "add"; }
public:
    PostIncrementOperator(ExpressionPtr _left)
        : Operator(_left)
    {}

    std::string getId() const override
    { return "post++"; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"( ";
        left->print(dst);
        dst<<" ++";
        dst<<" )";
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#PostInrementOperator generateMIPS Called"<<'\n';
        left->generateMIPS(dst, context, destReg);

        int reg = context.allocate(context.current_function_name);
        dst<<"addi $"<< reg <<",$"<<destReg<<",1"<<'\n'; 
        int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - 
                        context.functions[context.current_function].variables_map[left->getId()].old_map_size) + 12;
        dst<<"sw $"<< reg <<","<<curr_offset<<"($fp)"<<'\n';

    }

};

class PostDecrementOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "post--"; }
    virtual const char *getOpInstruction() const override
    { return "add"; }
public:
    PostDecrementOperator(ExpressionPtr _left)
        : Operator(_left)
    {}

    std::string getId() const override
    { return "post--"; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"( ";
        left->print(dst);
        dst<<" --";
        dst<<" )";
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#PostDecrementOperator generateMIPS Called"<<'\n';
        left->generateMIPS(dst, context, destReg);

        int reg = context.allocate(context.current_function_name);
        dst<<"addi $"<< reg <<",$"<<destReg<<",-1"<<'\n'; 
        int curr_offset = 4*(context.functions[context.current_function].variables_map.size() - 
                        context.functions[context.current_function].variables_map[left->getId()].old_map_size) + 12;
        dst<<"sw $"<< reg <<","<<curr_offset<<"($fp)"<<'\n';
    }

};

class PreIncrementOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "pre++"; }
    virtual const char *getOpInstruction() const override
    { return "add"; }
public:
    PreIncrementOperator(ExpressionPtr _left)
        : Operator(_left)
    {}

    std::string getId() const override{
        return "pre++";
    }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"( ";
        dst<<"++ ";
        left->print(dst);
        dst<<" )";
    }
    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#PreIncrementOperator generateMIPS Called"<<'\n';
        left->generateMIPS(dst, context, destReg);
        dst<<"addi $"<< destReg<<",$"<<destReg<<",1"<<'\n'; 
    }

};

class PreDecrementOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "pre--"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    PreDecrementOperator(ExpressionPtr _left)
        : Operator(_left)
    {}

    std::string getId() const override{
        return "pre--";
    }

    virtual void print(std::ostream &dst) const override
    {
        dst<<"( ";
        dst<<"-- ";
        left->print(dst);
        dst<<" )";
    }

    virtual void generateMIPS(std::ostream &dst, Context &context, int destReg) const override
    {
        dst<<"#PreDecrementOperator generateMIPS Called"<<'\n';
        left->generateMIPS(dst, context, destReg);
        dst<<"addi $"<< destReg<<",$"<<destReg<<",-1"<<'\n'; 
    }

    

};


#endif
