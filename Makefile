CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I inc

all: lexer bin/compiler

parser: src/parser.y
	bison -v -d -Wcounterexamples src/parser.y -o src/parser.tab.o

lexer : src/lexer.flex src/parser.tab.hpp
	flex -o src/lexer.yy.cpp  src/lexer.flex
	g++ -W -Wall -g -c src/lexer.yy.cpp -o src/lexer.yy.cpp

bin/c_compiler : src/compiler.cpp src/parser.tab.cpp src/lexer.yy.cpp
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_compiler $^
	chmod u+x bin/c_compiler

# bin/compiler : src/compiler.cpp
# 	mkdir -p bin
# 	g++ $(CPPFLAGS) -o bin/compiler $^
# 	chmod u+x bin/compiler
	
clean :
	rm -f src/*.o
	rm -f bin/*
	# rm src/*.tab.cpp
	# rm src/*.yy.cpp
	rm -r test/working/*/*.s
	rm -r test/working/*/*.o

