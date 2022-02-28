#ifndef ast_globalSequence_hpp
#define ast_globalSequence_hpp

#include "ast/blockGrouping/ast_sequence.hpp"

// Holds everything declared in global scope

class GlobalSequence
  : public Sequence
{
public:
  using Sequence::Sequence;

  // Visualising
//   void PrettyPrint(std::ostream &dst, std::string indent) const override;

  // Codegen
//   void generateMIPS(std::ostream &dst, Context &context, int destReg) const override;
};

#endif