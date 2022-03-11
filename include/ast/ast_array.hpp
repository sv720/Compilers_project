#ifndef ast_array_hpp
#define ast_array_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ast_expression.hpp"
#include "ast_expressionlist.hpp"

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

    ExpressionPtr getId() const
    { return id; }

    ExpressionPtr getSize() const
    { return size; }

    virtual void print(std::ostream &dst) const override
    {
        id->print(dst);
        dst<<"[";
        size->print(dst);
        dst<<"]";
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
        dst<<" {:";
        for (ExpressionPtr e : elements->list) {
            e->print(dst);
        }
        dst<<":} ";
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

    ExpressionPtr getId() const
    { return id; }

    ExpressionPtr getSize() const
    { return index; }

    virtual void print(std::ostream &dst) const override
    {
        id->print(dst);
        dst<<"[";
        index->print(dst);
        dst<<"]";
    }
    
};

#endif