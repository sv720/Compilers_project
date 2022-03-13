#include "ast.hpp"
#include "../include/ast/ast_available_registers.hpp"

int main()
{
    const Expression *ast=parseAST();
    std::map<std::string, std::vector<int>> variables_map; // key is variable id, store memory address offset (relative to frame pointer)
    std::map<int, bool> live_variables; //maps register numbers to bool live (1) or dead (0)

    std::cout<<std::endl;
    std::cout<<"Intermediate Language:"<<std::endl;
    ast->print(std::cout);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"MIPS GENERATED:"<<std::endl;
    ast->generateMIPS(std::cout, variables_map, live_variables);
    std::cout<<std::endl;

    return 0;
}
