#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_expression.hpp"
#include "ast/ast_primitives.hpp"
#include "ast/ast_operators.hpp"
#include "ast/ast_unary.hpp"
#include "ast/ast_functions.hpp"

extern const Expression *parseAST();

#endif

// #ifndef generic_ast_hpp
// #define generic_ast_hpp

// #include <string>
// #include <iostream>
// #include <memory>
// #include <initializer_list>
// #include <vector>
// #include <map>

// struct Tree;

// typedef std::shared_ptr<Tree> TreePtr;

// struct Tree
// {
//     Tree(std::string _type, std::string _value, const std::vector<TreePtr> &_branches)
//         : type(_type)
//         , value(_value)
//         , branches(_branches)
//     {}
    
//     Tree(std::string _type, std::string _value)
//         : type(_type)
//         , value(_value)
//     {}
    
//     template<class ...TArgs>
//     Tree(std::string _type, TArgs ...args)
//         : type(_type)
//         , branches{args...}
//     {}

//     std::string type;
//     std::string value;
//     std::vector<TreePtr> branches;
// };


// inline TreePtr Number(int32_t x)
// //{ return std::make_shared<Tree>("Number", std::to_string(x)); }
// { return std::make_shared<Tree>(std::to_string(x)); }

// inline TreePtr Variable(std::string id)
// //{ return std::make_shared<Tree>("Variable", id); }
// { return std::make_shared<Tree>(id); }

// inline TreePtr Input(std::string id)
// { return std::make_shared<Tree>("Input", id); }

// inline TreePtr Output(TreePtr expr)
// { return std::make_shared<Tree>("Output", expr); }


// inline TreePtr Add(TreePtr left, TreePtr right)
// { return std::make_shared<Tree>("Add", left, right); }

// inline TreePtr Sub(TreePtr left, TreePtr right)
// { return std::make_shared<Tree>("Sub", left, right); }

// inline TreePtr LessThan(TreePtr left, TreePtr right)
// { return std::make_shared<Tree>("LessThan", left, right); }


// inline TreePtr Seq(std::initializer_list<TreePtr> statements)
// { return std::make_shared<Tree>("Seq", statements); }

// inline TreePtr While(TreePtr cond, TreePtr stat)
// { return std::make_shared<Tree>("While", cond, stat ); }

// //inline TreePtr IfElse(TreePtr cond, TreePtr stat1, TreePtr stat2)
// //{ return std::make_shared<Tree>("IfElse", cond, stat1, stat2); }

// inline TreePtr If(TreePtr cond, TreePtr stat1)
// { return std::make_shared<Tree>("If", cond, stat1); }

// TreePtr Parse(
//     std::istream &src
// );

// void PrettyPrint(
//     std::ostream &dst,
//     TreePtr node,
//     std::string indent=""
// );

// void Compile(
//     TreePtr program
// );


// #endif

