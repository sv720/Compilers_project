#ifndef context_hpp
#define context_hpp

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <utility>

// Contains information related to where a variable exists in memory
struct variable;
// contains information related to size of arguments of a function
struct function;
// Represents current scope
struct stackFrame;
// Represents enumerations
struct enumeration;

// Regfile
struct registers
{
    int usedRegs[32] =
        {1,                      // $0 = 0 [0]
         1,                      // $at = no touch [1]
         1, 1,                   // $v0-$v1, return value => changed by function calls so not suitable to evaluate temporaries [2-3]
         1, 1, 1, 1,             // $a0-$a3, function arguments, just use them for that [4-7]
         0, 0, 0, 0, 0, 0, 0, 0, // $t0-$t7, temporary registers, do what you want [8-15]
         1, 1, 1, 1, 1, 1, 1, 1, // $s0-$s7, values preserved across function calls [16-23]
         0, 0,                   // $t8-$t9, more temporaries [24-25]
         1, 1,                   // $k0-$k1, kernel registers, no touchy [26-27]
         1,                      // $gp, used for static global variables (probs never use) [28]
         1,                      // $sp, stack pointer [29]
         1,                      // $fp, frame pointer [30]
         1};                     // $ra, return address [31]

    void useReg(int i) { usedRegs[i] = 1; };  // Register is now being used
    void freeReg(int i) { usedRegs[i] = 0; }; // Register is no longer being used
    int allocate(){
        for (int i = 2; i < 26; i++)
        {
            if (!usedRegs[i])
            {
                useReg(i);
                return i;
            }
        }
        return -1;
    }; // Returns empty register, -1 if no registers are available (Helper function for context)
};

// Supported types
// enum Specifier
// {
//     _int,
//     _void,
//     _unsigned, 
//     _char,     
//     _float,
//     _double,
//     _ptr
// };

struct variable
{
    unsigned int size;                     // How many bytes does the variable take up
    int old_map_size;                      // To calculate the new relative offset from the current fp
    int reg;                               // Keeps track of which register the variable is in (-1 := not stored in reg)
    std::string type = "int";
    // enum Specifier type = Specifier::_int; // keeps track of type, int by default (refactor this to enum if possible at some point)
};

struct function
{
    unsigned int size;                 // Total size of arguments
    std::vector<unsigned int> argSize; // Individual size of each argument
};

struct Context
{
    // Stack stuff
    std::vector<stackFrame> stack;
    std::map<std::string, variable> variables_map; // key is variable id, store memory address offset (relative to frame pointer)
    std::map<int, bool> live_variables; //maps register numbers to bool live (1) or dead (0)


    // Globals (pretty sure i should be using std::unordered_map for faster lookups but getting weird issues with the header)
    // std::map<std::string, enum Specifier> globals; // Just needs to track the names + types of globals
    std::map<std::string, function> functions;     // tracks the size of the arguments
    // std::map<std::string, enumeration> enums;      // Tracks enums globally


    // MIPS Register file
    registers regFile;
    // registers floatRegs = {{
    //     // Special floating point reg file
    //     1, 1,                              // $f0-1 used for return of floats/doubles
    //     0, 1,                              // $f2-3 available
    //     0, 1, 0, 1, 0, 1, 0, 1,            // $f4-$f11 temporaries, available
    //     0, 1, 0, 1,                        // $f12-$f15 used for arguments, stored in memory => available
    //     0, 1, 0, 1,                        // $f16-$f19 more temporaries, available
    //     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 // $f20-$f30 saved registers, preserved across fn calls
    // }};

    // Return a unique label for assembly code
    std::string makeLabel(std::string label){
        static int count = 0;
        return "_"+label+"_"+std::to_string(count++);
    };

    // bool isGlobal(std::string varName){
    //     auto it = globals.find(varName);
    //     return (it != globals.end());
    // }; // Use to check which map to use for variables
    // bool isEnum(std::string varName){
    //     auto it = enums.find(varName);
    //     return (it != enums.end());
    // };   // use to check which map to use for variables

    // Used to manage scope within a function (i.e. block structures - ifElse, while, for)
    // void enterScope(){
    //     //std::cerr << "Entering scope" << std::endl; // Debugging
    //     assert(stack.size() > 0); // You should only enterScope within a function => at least 1 stackFrame
    //     stack.push_back(stack.back()); // Creates a copy of current scope (variables declared in function are available in sub-scope)
    // };
    // void exitScope(std::ostream &dst){
    //     // std::cerr << "Exiting scope" << std::endl; // Debugging
    //     //  Ensures changes to variable from previous scope are retained
    //     int oldScope = -(stack.end()[-2]).offset; // Any variable with an offset >= to this offset need to be stored
    //     for (auto it = stack.back().varBindings.begin(); it != stack.back().varBindings.end(); it++)
    //     {
    //         if (it->second.offset >= oldScope)
    //         {
    //             int reg = it->second.reg;
    //             // If variable is stored in a register write it back to offset to ensure it's preserved
    //             if (reg != -1)
    //             {
    //                 dst << "sw $" << reg << "," << it->second.offset << "($30)" << std::endl;
    //             }
    //         }
    //     }

    //     // Re-increments stack pointer to deallocate any variables no longer in scope
    //     int diff = stack.back().offset + oldScope; // oldScope is -ve
    //     // std::cerr << "Previous stack: " << std::endl << stack.end()[-2]; // Debugging
    //     // std::cerr << "Current stack: " << std::endl << stack.back(); // Debugging
    //     if (diff > 0)
    //     {
    //         dst << "addiu $29,$29," << diff << std::endl;
    //     }
    //     stack.pop_back(); // Leaves scope, re-enters previous scope
    //     // std::cerr << "Current stack == previous stack:" << std::endl << stack.back(); // Debugging
    //     //  Restores registers from previous scope
    //     for (auto it = stack.back().varBindings.begin(); it != stack.back().varBindings.end(); it++)
    //     {
    //         int reg = it->second.reg;
    //         if (reg != -1)
    //         {
    //             dst << "lw $" << reg << "," << it->second.offset << "($30)" << std::endl;
    //         }
    //     }
    // };

    // Use this method for allocation
    // If all registers are being used, this will clear a register and return it
    int allocate(){
        // Allocates register
        int reg = regFile.allocate();
        if (reg != -1)
        {
            return reg;
        }
        // If no registers are free, overwrites variable
        else
        {
            for(auto it = variables_map.begin(); it != variables_map.end(); it++){
            {
                reg = it->second.reg;
                if (reg != -1)
                {
                    regFile.freeReg(reg);
                    it->second.reg = -1;
                    return reg;
                }
            }
        }
        // Hopefully this never happens lmao
        std::cerr << "Unable to free any registers" << std::endl;
        exit(1);
        }
    };
    // int allocateFloat(){
    //     int reg = floatRegs.allocate();
    //     if (reg != -1)
    //     {
    //         return reg;
    //     }
    //     // Hopefully this never happens lmao
    //     std::cerr << "Unable to allocate any registers" << std::endl;
    //     exit(1);
    // };
};


// struct enumeration
// {
//     std::string id; // Name of enum
//     int value;      // Value associated with enum
// };

struct stackFrame
{
    std::map<std::string, variable> varBindings; // Tracks variables in scope
    unsigned int offset = 0;                     // Keeps track of size of frame to restore the stack pointer for blocks (i.e. while loops, if statements) -- MAKE SURE TO INCREMENT WHEN ALLOCATING VARIABLES
    // bool inFrame(std::string varName)
    // {
    //     auto it = varBindings.find(varName);
    //     return (it != varBindings.end());
    // };                                           // Error checking, probably not necessary
    std::string startLabel;                      // Used for continue statement (and case stuff for switch)
    std::string endLabel;                        // Used for break statement
    // enum Specifier returnType;                   // Used to track type being returned from function
};

// std::ostream &operator<<(std::ostream &dst, stackFrame frame){
//     dst << "Beginning of frame" << std::endl;
//     dst << "offset = " << frame.offset << std::endl;
//     // dst << "argSize = " << frame.argSize << std::endl;
//     dst << "varBindings:" << std::endl;
//     for(auto it = frame.varBindings.begin(); it != frame.varBindings.end(); it++){
//         dst << "  " << it->first << ": size = " << it->second.size << ", offset = " << it->second.offset << std::endl;
//     }
//     dst << "startlabel: " << frame.startLabel << std::endl;
//     dst << "endLabel: " << frame.endLabel << std::endl;
//     dst << "End of frame" << std::endl;
//     return dst;
// };


#endif