Timeline:

First meeting: 
- weekend after midterms (19-20Feb): decide on the plan to divide work, set meetings and use of trello, messaging apps or excel sheet for keeping track of progress
19 Feb 2022: Meeting 1
	-setting up git and adding the specification and requirements for the cw
	-finding C89 documentation http://port70.net/~nsz/c/c89/c89-draft.html
	-first look at testing codes and understand them
	-decided on starting by having a basic fully working compiler (lexer, parser,code gen and vm) and then build up on it with more instructions
	-will start working on lexer and parser
  
25-26 Feb 2022:
	- useful links: https://www.lysator.liu.se/c/ANSI-C-grammar-y.html ; https://www.lysator.liu.se/c/ANSI-C-grammar-l.html
	- our compiler only compiles the called function f(),g(),h() etc....main() is done by gcc ->check bashsscript or sth for this
	- take the approach of lab 2 with ast files
	- codegen only outpus/print out....so no need for ast to calculate will only call for code generation(cout)
	- expect 40-50 ast files if we separate them fully
	- lexer intensive approach is better
	- all testing is in the testbench, the debugging needed is just printouts with pretty print

27-28 Feb 2022:
	- working on parser and lexer as the grammar presented by C90
	- start adding ast files and setting up 

https://github.com/TszwangKo/C_compiler
https://github.com/sts219/Odyssey_C_Compiler/blob/master/src/parser.y

first week of march:
  - after undertanding the OOP implementation of the ast files for the parser, and wrote a imple working parser for delaration, initialisation and maths operations in multiline
  - applied our current process onto the official grammar 
  - solved the problem of multi ExpressionPtr vectors converted in ExpressionListPtr for coumpound_statement

