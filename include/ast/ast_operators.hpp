#ifndef ast_operators_hpp
#define ast_operators_hpp

#include <string>
#include <iostream>
#include <cmath>
#include "context.hpp"

class Operator
    : public Expression
{
private:
    ExpressionPtr right;
protected:
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
        right->generateMIPS(dst, context, destReg);
        left->generateMIPS(dst, context, destReg);
        dst<<getOpInstruction()<<" $4,"; //destination register
        dst<<"$"<<context.variables_map[left->getId()].reg<<",";
        dst<<"$"<<context.variables_map[right->getId()].reg<<"\n";
    }
};


class AddOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "+"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    AddOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
    
};

class SubOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "-"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    SubOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
    
};


class MulOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "*"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    MulOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

};

class DivOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "/"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    DivOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class ModOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "%"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    ModOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

// SHIFTS -----------------------------------

class LeftShiftOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "<<"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    LeftShiftOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

};

class RightShiftOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return ">>"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    RightShiftOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

};

// COMPARISONS -----------------------------------

class SmallerOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "<"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    SmallerOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

};

class GreaterOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return ">"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    GreaterOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

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

};

class EQOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "=="; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    EQOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

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

};

// INCREMENT/DECREMENT -----------------------------------

class PostIncrementOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "post++"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    PostIncrementOperator(ExpressionPtr _left)
        : Operator(_left)
    {}

    virtual void print(std::ostream &dst) const override
    {
        dst<<"( ";
        left->print(dst);
        dst<<" ++";
        dst<<" )";
    }

};

class PostDecrementOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "post--"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    PostDecrementOperator(ExpressionPtr _left)
        : Operator(_left)
    {}

    virtual void print(std::ostream &dst) const override
    {
        dst<<"( ";
        left->print(dst);
        dst<<" --";
        dst<<" )";
    }

};

class PreIncrementOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "pre++"; }
    virtual const char *getOpInstruction() const override
    { return "addu"; }
public:
    PreIncrementOperator(ExpressionPtr _left)
        : Operator(_left)
    {}

    virtual void print(std::ostream &dst) const override
    {
        dst<<"( ";
        dst<<"++ ";
        left->print(dst);
        dst<<" )";
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

    virtual void print(std::ostream &dst) const override
    {
        dst<<"( ";
        dst<<"-- ";
        left->print(dst);
        dst<<" )";
    }

};


#endif
