#ifndef ast_available_registers_hpp
#define ast_available_registers_hpp

#include <vector>
#include <map>

extern std::map<std::string, int> variables_map;  // key is variable id, store memory address offset (relative to frame pointer)

extern std::map<int, bool> live_variables; //maps register numbers to bool live (1) or dead (0)

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