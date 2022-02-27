#ifndef ast_assign_hpp
#define ast_assign_hpp

// #include "ast_expression.hpp"

#include <string>
#include <iostream>
#include <typeinfo>


class Assign
    : public Expression
{
private:
    ExpressionPtr left;
    std::string middle;
    ExpressionPtr right;
protected:
    Assign(ExpressionPtr _left, ExpressionPtr _right, std::string _middle)
     : left(_left)
     , middle(_middle)
     , right(_right)
    {}
public:
    virtual ~Assign()
    {
        delete left;
        delete right;
    }

    ExpressionPtr getLeft() const
    { return left; }

    ExpressionPtr getRight() const
    { return right; }
    //the 2 above functions return the known values of right and left

    // virtual const char * getMiddle() const 
    // { return operator; } 

    //int a += b
    //int a += 5

    virtual void print(std::ostream &dst) const override
    {
        if( typeid(*right) == typeid(Number()) ){ //we are assigning from an immediate
            if (middle == "=="){ //ADDI LEFT RIGHT 0
                dst<<"ADDI ";
                left->print(dst);
                dst<<" ";
                right->print(dst);
                dst<<" 0";
            }
            else if (middle == "+="){ //ADDI LEFT LEFT RIGHT 
                dst<<"ADDI ";
                left->print(dst);
                dst<<" ";
                left->print(dst);
                dst<<" ";
                right->print(dst); 
            }
            else if (middle == "-="){ //SUBI LEFT LEFT RIGHT
                dst<<"SUBI ";
                left->print(dst);
                dst<<" ";
                left->print(dst);
                dst<<" ";
                right->print(dst); 
            }
            else if (middle == "*="){ //MULT LEFT RIGHT (right is immediate we will store in tmp reg)
                //NB there is no Immediate multiplication so need to assign to a register first

                dst<<"ADDI $t0 $zero ";
                right->print(dst);
                //stores immediate value  

                dst <<"\n";

                dst<<"MULT "; // MULT LEFT RIGHT $t0
                left->print(dst);
                dst<<" ";
                left->print(dst);
                dst<<" $t0"; //

                //TODO : implement MFHI and MFLO 
                //NB : MULT does not have a destination regiser operand - places values in fixed upper and lower
            }

            else if (middle == "/="){ //DIV LEFT RIGHT (right is immediate we will store in tmp reg)
                //NB there is no Immediate multiplication so need to assign to a register first

                dst<<"ADDI $t0 $zero ";
                right->print(dst);
                //stores immediate value 

                dst <<"\n";

                dst<<"DIV "; // MULT LEFT RIGHT $t0
                left->print(dst);
                dst<<" ";
                left->print(dst);
                dst<<" $t0"; //
                //NB : Similarly to MULT - quotient is stored in HI reg and remainder in LO

                dst << "\n";

                dst << "MFHI ";
                left->print(dst);
            }

            else if (middle == "%="){ //DIV LEFT RIGHT (right is immediate we will store in tmp reg)
                //NB there is no Immediate multiplication so need to assign to a register first

                dst<<"ADDI $t0 $zero ";
                right->print(dst);
                //stores immediate value 

                dst <<"\n";

                dst<<"DIV "; // MULT LEFT RIGHT $t0
                left->print(dst);
                dst<<" ";
                left->print(dst);
                dst<<" $t0"; //
                //NB : Similarly to MULT - quotient is stored in HI reg and remainder in LO

                dst << "\n";

                dst << "MFLO ";
                left->print(dst);
            }
        
        }
        else {//we are assigning from a variable /register

            if (middle == "=="){ //ADD LEFT RIGHT 0
                dst<<"ADD ";
                left->print(dst);
                dst<<" ";
                right->print(dst);
                dst<<" 0";
            }
            else if (middle == "+="){ //ADD LEFT LEFT RIGHT 
                dst<<"ADD";
                left->print(dst);
                dst<<" ";
                left->print(dst);
                dst<<" ";
                right->print(dst); 
            }
            else if (middle == "-="){ //SUB LEFT LEFT RIGHT
                dst<<"SUB ";
                left->print(dst);
                dst<<" ";
                left->print(dst);
                dst<<" ";
                right->print(dst); 
            }
            else if (middle == "*="){ //MULT LEFT RIGHT (right is immediate we will store in tmp reg)

                dst<<"MULT "; // MULT LEFT RIGHT
                left->print(dst);
                dst<<" ";
                right->print(dst);

                //TODO : Add Move from HI and MFL 
                
                //NB : MULT does not have a destination regiser operand - places values in fixed upper and lower
            }

            else if (middle == "/="){ //DIV LEFT RIGHT (right is immediate we will store in tmp reg)
                //NB there is no Immediate multiplication so need to assign to a register first

                dst<<"DIV "; // MULT LEFT RIGHT $t0
                left->print(dst);
                dst<<" ";
                right->print(dst);

                dst << "\n";

                dst << "MFHI ";
                left->print(dst);
    
                //NB : Similarly to MULT - quotient is stored in HI reg and remainder in LO
            }

            else if (middle == "%="){ //DIV LEFT RIGHT (right is immediate we will store in tmp reg)
                //NB there is no Immediate multiplication so need to assign to a register first

                dst<<"DIV "; // MULT LEFT RIGHT $t0
                left->print(dst);
                dst<<" ";
                right->print(dst);

                dst <<"\n";

                dst << "MFLO ";
                left->print(dst);
    
                //NB : Similarly to MULT - quotient is stored in HI reg and remainder in LO
            }
        
        }
        
       
    }
    // static int makeNameUnq=0;
};


#endif
