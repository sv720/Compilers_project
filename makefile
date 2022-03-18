.PHONY: clean
  
CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include

all : bin/c_compiler

src/parser.tab.cpp : src/parser.y
	bison -v -d src/parser.y -o src/parser.tab.cpp

src/lexer.yy.cpp : src/lexer.flex src/parser.tab.hpp
	flex -o src/lexer.yy.cpp  src/lexer.flex

bin/c_compiler : src/c_compiler.o src/parser.tab.o src/lexer.yy.o src/parser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_compiler $^
	


clean :
	rm -f src/*.o
	rm -f bin/*
	rm -f src/*.tab.cpp
	rm -f src/*.yy.cpp
	rm -f -r test/err/
	rm -f -r test/working/
	rm -f -r test/objects/