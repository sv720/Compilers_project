#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>
#include <vector>

class Variable
    : public Expression
{
private:
    std::string id;
public:
    Variable(const std::string &_id)
        : id(_id)
    {}

    const std::string getId() const
    { return id; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<id;
    }

    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const override
    {
        // TODO-B : Run bin/eval_expr with a variable binding to make sure you understand how this works.
        // If the binding does not exist, this will throw an error
        return bindings.at(id);
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

    const std::string getId() const
    { return id; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<id;
    }
    
};

class FunctionDeclarator
    : public Expression
{
private:
    ExpressionPtr id;
public:
    FunctionDeclarator(ExpressionPtr _id)
        : id(_id)
    {}

    ExpressionPtr getId() const
    { return id; }

    virtual void print(std::ostream &dst) const override
    {
        id->print(dst);
    }
    
};

class Number
    : public Expression
{
private:
    int value;
public:
    Number(int _value)
        : value(_value)
    {}

    int getValue() const
    { return value; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<value;
    }

};


//FUNCTION______________________________________
typedef std::vector<ExpressionPtr> ExpressionList;
typedef ExpressionList *ExpressionListPtr;

class Full_Function
    : public Expression
{
private:
    ExpressionPtr left;
    ExpressionPtr right;  
public:
    Full_Function(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }
    //no member functions yet

    virtual void print(std::ostream &dst) const override
    {
        dst<<"( ";
        left->print(dst);
        dst<<" ";
        right->print(dst);
        // for (ExpressionPtr e : *right) {
        //     e->print(dst);
        // }
        dst<<" )";
    }
};

class Function_Definition
    : public Expression
{
private:
    std::string left;
    ExpressionPtr right;  
public:
    Function_Definition(const std::string &_left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}

    const std::string getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }
    //no member functions yet

    virtual void print(std::ostream &dst) const override
    {
        dst<<left<<" ";
        right->print(dst);
    }
};

class Scope
    : public Expression
{
private:
    ExpressionListPtr right;  
public:
    Scope()
        
    {}

    Scope(ExpressionListPtr _right)
        : right(_right)
    {}

    ExpressionListPtr getRight() const
    { return right; }
    //no member functions yet

    virtual void print(std::ostream &dst) const override
    {
        dst<<"( ";
        for (ExpressionPtr e : *right) {
            e->print(dst);
        }
        dst<<" )";
    }
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
    
    virtual const char *getFunction() const
    { return "return"; }

    virtual void print(std::ostream &dst) const override
    {
        arg->print(dst);
    }

};


//________________________________________________

class Assign_Declare
    : public Expression
{
private:
    std::string left;
    ExpressionPtr right;  
public:
    Assign_Declare(std::string &_left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}

    virtual ~Assign_Declare()
    {
        delete right;
    }
    //no member functions yet
    const std::string getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        // std::cout << "DEBUG : printing in AssignDeclare left" <<std::endl;
        dst<<left<<" ";
        // std::cout << "DEBUG : printing in AssignDeclare right" <<std::endl;
        right->print(dst);
    }
};

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
    //no member functions yet
    const std::string getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<left<<" ";
        right->print(dst);
    }
};

//________________________________________________

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
    //no member functions yet
    virtual void print(std::ostream &dst) const override
    {   
        left->print(dst);
        dst<<"=";
        right->print(dst);
    }
};

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
};



#endif
