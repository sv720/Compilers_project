#include "ast.hpp"

int main()
{
    const Expression *ast=parseAST();

    std::cout<<std::endl;
    std::cout<<"Intermediate Language:"<<std::endl;
    ast->print(std::cout);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"MIPS GENERATED:"<<std::endl;
    ast->generateMIPS(std::cout);
    std::cout<<std::endl;

    return 0;
}
