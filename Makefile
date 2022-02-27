CPPFLAGS += -std=c++17 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I inc

all: lexer bin/compiler

parser: src/parser.y
	bison -v -d src/parser.y -o src/parser.tab.cpp

lexer : src/lexer.flex src/parser.tab.hpp
	flex -o src/lexer.yy.cpp  src/lexer.flex
	g++ src/lexer.yy.cpp -o src/lexer.yy.o 

bin/c_compiler : bin/compiler src/wrapper.sh
	cp src/wrapper.sh bin/c_compiler
	chmod u+x bin/c_compiler

bin/compiler : src/compiler.o lexer parser
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/compiler $^
	
clean :
	rm -f src/*.o
	rm -f bin/*
	rm src/*.tab.cpp
	rm src/*.yy.cpp
