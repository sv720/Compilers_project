Timeline:

### First meeting: 
- weekend after midterms (19-20Feb): decide on the plan to divide work, set meetings and use of trello, messaging apps or excel sheet for keeping track of progress

### 19 Feb 2022: Meeting 1:
-setting up git and adding the specification and requirements for the cw
-finding C89 documentation http://port70.net/~nsz/c/c89/c89-draft.html
-first look at testing codes and understand them
-decided on starting by having a basic fully working compiler (lexer, parser,code gen and vm) and then build up on it with more instructions
-will start working on lexer and parser
  
### 25-26 Feb 2022:
- useful links: https://www.lysator.liu.se/c/ANSI-C-grammar-y.html ; https://www.lysator.liu.se/c/ANSI-C-grammar-l.html
- our compiler only compiles the called function f(),g(),h() etc....main() is done by gcc ->check bashsscript or sth for this
- take the approach of lab 2 with ast files
- codegen only outpus/print out....so no need for ast to calculate will only call for code generation(cout)
- expect 40-50 ast files if we separate them fully
- lexer intensive approach is better
- all testing is in the testbench, the debugging needed is just printouts with pretty print

### 27-28 Feb 2022:
- working on parser and lexer as the grammar presented by C90
- start adding ast files and setting up 

https://github.com/TszwangKo/C_compiler
https://github.com/sts219/Odyssey_C_Compiler/blob/master/src/parser.y

### first week of march:
- after undertanding the OOP implementation of the ast files for the parser, and wrote a imple working parser for delaration, initialisation and maths operations in multiline
- applied our current process onto the official grammar 
- solved the problem of multi ExpressionPtr vectors converted in ExpressionListPtr for coumpound_statement

### 9-13 Mar 2022:
- resolved ast files for if,for,while, unary statements and solved some other small edge cases (dangling else probem and math associativity)
- working multiple functions in the c file and them calling each other (ast file), and arrays
- talked with TAs and understood the requirements needed for the output mips file and the requirements(regiter names, instructions) for the stack pointer and frame pointer
- introduce genrateMIPS function for all classes
- mips working for vars&function declarations, addu and subu (only int)

### 14 Mar 2022:
- implemented qeru-mips and bin/c_compiler personalised command to run and test the compiler
- discussed stack and frame pointers and implemented an acceptable approach

### 16 Mar 2022:
- mips working for local_var and integer (arithmetic, parameters, variable allocation to registers)

### 18 Mar 2022:
- relative stack/frame pointers implemented
- allocating temporary registers for operations and emtying them after use
- implemented while, if and for loops for generating mips

### 21 Mar 2022:
- Implementing storage of out of function pc values ($31) on stack to avoid loosing track when multiple function calls are present.
- Managing calls to internally and exteranly compiled/defined functions.

### 22 Mar 2022:
- implemented separate functions variable_map, to differentiate between each instance(looping) through the functions (for recursive calls) and differentiate the global wariable_map with the local ones (also for separating variables in scopes)

https://www.cs.tufts.edu/comp/140/lectures/Day_3/mips_summary.pdf //high level mips instr

- implemented enums which are calculated and kept track of by the compiler internally, no mips generated for it: so when reaching class declarator we heck if the id is of an enum, existent variable or we need to create a new variable for it
- flags are not added in the c_compiler.cpp file at the end of the output files (works)


### 23 Mar 2022
- arrays declaration solved, considering all array elements as variables in the map, but they are only saved on memory with a relative offset to its initial label
- working on arrays and their variable offsets for calling

### 25 Mar 2022
- all assignment operations completed (eg %= , /=) and written testcases for everyone of them

### 26 - 27 Mar 2022
- worked on 5 agruments function call, and passing internal testcase. have an assumption that our own stack/frame pointer methodology is conflicting the gcc one to get more than 4 parameters (so rest from stack of main function)
- have a draft of scopes, needs looking at how we reset the sp and fp after exiting the scope; when entering it we copy the parent scope/variables_map
- Wokring on arrays indexing but not fully understand why is not working, mips looks ok
- internal recursive function's mips looks perfectly fine but seg faults as godbolts'. Need more understanding
- tried debugging with gdb and taken some tutorials on how to work with it, installed specific qemu-user pachages for it. Need more work but interesting either way

### 28 Mar 2022
- scopes 90% implemented, some problems in arrays variable indexing
- arrays 90% implemented
- small tasks completed: sizeOf(), changing types of variables, simple switch case, adapted variables to be of more types (not just int)
- prepared for implementing floats and doubles


### 29 Mar 2022
- implemented typedef as a special vector in the context which keeps track of every type_id and specific type
- floats in progress (declaration and assignments however return of floats crashes)
- array initialisation of form a[] = {1,2,3,} is added in the grammar but not responding
- succesfully run function call (recursive), however it would break the external calls, hence we decided to pursue the external functions as they would be more impportant than recursions.