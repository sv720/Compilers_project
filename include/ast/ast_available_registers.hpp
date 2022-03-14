#ifndef ast_available_registers_hpp
#define ast_available_registers_hpp

#include <vector>
#include <map>

extern std::map<std::string, int> variables_map;  // key is variable id, store memory address offset (relative to frame pointer)

extern std::map<int, int> live_variables = {
    {0,-1}, // $0 = 0 [0]
    {1,-1}, // $at = [1]
    {2,-1}, {3,-1}, // $v0-$v1, return value => [2-3]
    {4,-1}, {5,-1}, {6,-1}, {7,-1}, // $a0-$a3, function arguments, just use them for that [4-7]
    {8,0}, {9,0}, {10,0}, {11,0}, {12,0}, {13,0}, {14,0}, {15,0}, // $t0-$t7, temporary registers [8-15]
    {16,-1}, {17,-1}, {18,-1}, {19,-1}, {20,-1}, {21,-1}, {22,-1}, {23,-1}, // $s0-$s7, values preserved across function calls [16-23]
    {24,0}, {25,0}, // $t8-$t9, more temporaries [24-25]
    {26,-1}, {27,-1}, // $k0-$k1, kernel registers [26-27]
    {28,-1}, // $gp, used for static global variables [28]
    {29,-1}, // $sp, stack pointer [29]
    {30,-1}, // $fp, frame pointer [30]
    {31,-1} // $ra, return address [31]
}; //maps register numbers to stack addresses (so we can check whether the register i used by a variable and which variable)

// extern std::map<int, bool> live_variables = {
//     {0,true}, // $0 = 0 [0]
//     {1,true}, // $at = [1]
//     {2,true}, {3,true}, // $v0-$v1, return value => [2-3]
//     {4,true}, {5,true}, {6,true}, {7,true}, // $a0-$a3, function arguments, just use them for that [4-7]
//     {8,false}, {9,false}, {10,false}, {11,false}, {12,false}, {13,false}, {14,false}, {15,false}, // $t0-$t7, temporary registers [8-15]
//     {16,true}, {17,true}, {18,true}, {19,true}, {20,true}, {21,true}, {22,true}, {23,true}, // $s0-$s7, values preserved across function calls [16-23]
//     {24,false}, {25,false}, // $t8-$t9, more temporaries [24-25]
//     {26,true}, {27,true}, // $k0-$k1, kernel registers [26-27]
//     {28,true}, // $gp, used for static global variables [28]
//     {29,true}, // $sp, stack pointer [29]
//     {30,true}, // $fp, frame pointer [30]
//     {31,true} // $ra, return address [31]
// }; //maps register numbers to bool live (1) or dead (0)

// Register Number	Conventional Name	    Usage
// $0	            $zero	                Hard-wired to 0
// $1	            $at	                    Reserved for pseudo-instructions
// $2 - $3	        $v0, $v1	            Return values from functions
// $4 - $7	        $a0 - $a3	            Arguments to functions - not preserved by subprograms
// $8 - $15	        $t0 - $t7	            Temporary data, not preserved by subprograms
// $16 - $23	    $s0 - $s7	            Saved registers, preserved by subprograms
// $24 - $25	    $t8 - $t9	            More temporary registers, not preserved by subprograms
// $26 - $27	    $k0 - $k1	            Reserved for kernel. Do not use.
// $28	            $gp	                    Global Area Pointer (base of global data segment)
// $29          	$sp	                    Stack Pointer
// $30	            $fp	                    Frame Pointer
// $31          	$ra	                    Return Address
// $f0 - $f3	    -	                    Floating point return values
// $f4 - $f10	    -	                    Temporary registers, not preserved by subprograms
// $f12 - $f14	    -	                    First two arguments to subprograms, not preserved by subprograms
// $f16 - $f18	    -	                    More temporary registers, not preserved by subprograms
// $f20 - $f31	    -	                    Saved registers, preserved by subprograms

class available_registers
{
protected:
    int currently_used; 
    bool registers_available;
public:

    
    available_registers() //constructor does nothing (and should never been used)
    {}
    
    void increment()
    {
        currently_used +=1; 
    }
    void decrement()
    {
        currently_used -=1; 
    }

    virtual bool has_registers_avaialble() =0;
};

class at_reg //total of: 1 ($1)
    : public available_registers
{
public: 

    at_reg() //CONSTRUCTOR
    {
        currently_used = 0; 
        registers_available = true;
    }
    virtual bool has_registers_avaialble()
    {
        if(currently_used>0){
            registers_available = false; 
            return false;
        }
        return true;
    }
};

class result_reg    // 2            ($2-3) 
    : public available_registers
{
public: 

    result_reg() //CONSTRUCTOR
    {
        currently_used = 0; 
        registers_available = true;
    }
    virtual bool has_registers_avaialble()
    {
        if(currently_used>1){
            registers_available = false; 
        }
    }
};

class argument_reg    // 4            ($4-7)
    : public available_registers
{
public: 

    argument_reg() //CONSTRUCTOR
    {
        currently_used = 0; 
        registers_available = true;
    }
    virtual bool has_registers_avaialble()
    {
        if(currently_used>3){
            registers_available = false; 
        }
    }
};

class temporary_reg     // 10           ($8-15 and $24-25)  
    : public available_registers
{
public: 

    temporary_reg() //CONSTRUCTOR
    {
        currently_used = 0; 
        registers_available = true;
    }
    virtual bool has_registers_avaialble()
    {
        if(currently_used>9){
            registers_available = false; 
        }
    }
};

class saved_reg     // 8            ($16-23)
    : public available_registers
{
public: 

    saved_reg() //CONSTRUCTOR
    {
        currently_used = 0; 
        registers_available = true;
    }
    virtual bool has_registers_avaialble()
    {
        if(currently_used>7){
            registers_available = false; 
        }
    }
};

class kernel_reg     // 2            ($26-27)
    : public available_registers
{
public: 

    kernel_reg() //CONSTRUCTOR
    {
        currently_used = 0; 
        registers_available = true;
    }
    virtual bool has_registers_avaialble()
    {
        if(currently_used>1){
            registers_available = false; 
        }
    }
};




#endif