#ifndef context_hpp
#define context_hpp

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cassert>
#include <utility>

struct variable;
struct function;
struct enumeration;

struct registers
{
    int usedRegs[32] =
        {1,                      // $0  [0]
         1,                      // $at [1]
         1, 1,                   // $v0-$v1, return values [2-3]
         1, 1, 1, 1,             // $a0-$a3, function arguments [4-7]
         0, 0, 0, 0, 0, 0, 0, 0, // $t0-$t7, temporary registers, do what you want [8-15]
         1, 1, 1, 1, 1, 1, 1, 1, // $s0-$s7, values preserved across function calls [16-23] eg. f(int &a) where a is stored in these regs
         0, 1,                   // $t8-$t9, more temporaries [24-25], [25] used for old_fp
         1, 1,                   // $k0-$k1, kernel registers [26-27]
         1,                      // $gp, for static globals [28]
         1,                      // $sp, stack pointer [29]
         1,                      // $fp, frame pointer [30]
         1};                     // $ra, return address [31]

    void useReg(int i) { usedRegs[i] = 1; };  // Register is now being used
    void freeReg(int i) { usedRegs[i] = 0; }; // Register is no longer being used
    int allocate(){
        for (int i = 2; i < 25; i++) //was 26
        {
            if (!usedRegs[i])
            {
                useReg(i);
                return i;
            }
        }
        return -1;
    }; 
};

struct variable
{
    unsigned int size;                     
    int old_map_size;                      
    int reg;                               // not really used
    std::string type  = "int";
    std::string declared_in_function;
};

struct function
{
    unsigned int size;                 // Total size of arguments
    std::vector<unsigned int> argSize; // Individual size of each argument
    std::map<std::string, variable> variables_map; 
    int fp_reg = -1;
    std::string previous_function;
    bool iteration_selection_statement = false;
};

struct enumeration
{
    std::string id; // Name of enum element
    int value;      // Value associated with enum element
};

struct Context
{
    std::map<std::string, variable> global_variables_map; // key is variable id, store memory address offset (relative to frame pointer)

    std::map<std::string, std::vector<enumeration>> global_enums;      // Tracks enums globally with spefific enum label
    std::vector<enumeration> enums;                 // track all enums independent of their label

    std::map<std::string, std::string> typedefs;

    std::map<std::string, function> functions;     // tracks the size of the arguments
    std::string current_function;// previous_function;
    std::vector<std::string> functions_names;
    std::string current_function_name;
    std::string current_array_label;

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

    std::string makeLabel(std::string label){
        static int count = 0;
        return label+"_"+std::to_string(count++);
    };

    int allocate(std::string unique_label){
        // Allocates register
        int reg = regFile.allocate();
        if (reg != -1){
            return reg;
        }
        // If no registers are free, overwrites variable
        else{
            for(auto it = functions[unique_label].variables_map.begin(); it != functions[unique_label].variables_map.end(); it++){
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
        std::cerr << "Cannot free registers" << std::endl;
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

#endif