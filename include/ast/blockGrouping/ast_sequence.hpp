#ifndef ast_sequence_hpp
#define ast_sequence_hpp

#include "ast/ast_expression.hpp"


class Sequence;
typedef Sequence *SeqPtr;

class Sequence
  : public Expression
{
public:
    // Constructors
    Sequence()
    {}
    Sequence(ExpressionPtr in)
    {
        branches.push_back(in);
    }
    Sequence(std::vector<ExpressionPtr> _branches)
        : Expression(_branches)
    {}
    Sequence(std::vector<ExpressionPtr> decList, std::vector<ExpressionPtr> statList)
        : Expression(decList, statList)
    {}

    // Destructor
    ~Sequence(){
        for(int i = 0; i < branches.size(); i++){
            delete branches[i];
        }
    }

    // Visualising
    //   virtual void PrettyPrint(std::ostream &dst, std::string indent) const override;

    // Codegen helper
    //   virtual ExpressionPtr getNode(unsigned index) const;
};

#endif
