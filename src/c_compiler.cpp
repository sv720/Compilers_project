#include "ast.hpp"
#include "../include/ast/ast_available_registers.hpp"

#include <fstream>

int main(int argc, char *argv[])
{
    if(argc < 5){
        std::cerr<<"ERROR accepted format: bin/c_compiler -S [source-file.c] -o [dest-file.s]"<<std::endl;
        return 1;
    }
    std::cout<< argv[2] << " <-> " << argv[4]<<std::endl;

    const Expression *ast=parseAST(argv[2]);
    Context context;

    std::ofstream ofs(argv[4], std::ofstream::out);
    std::cout<<std::endl;
    std::cout<<"Intermediate Language:"<<std::endl;
    ast->print(std::cout);
    std::cout<<std::endl;

    if(ofs.is_open()){
        
            std::cout<<std::endl;
            std::cout<<"MIPS GENERATED:"<<std::endl;
            ast->generateMIPS(ofs, context, 2);
            std::cout<<std::endl;

        ofs.close();
    }
    else{
        std::cerr << "Couldn't open output file: " << argv[4] << std::endl;
        exit(1);
    }



    return 0;
}
