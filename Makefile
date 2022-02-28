CPPFLAGS += -std=c++17 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include -I src

OBJS = $(patsubst %.cpp,%.o,$(CPPFILES))

all: bin/c_compiler

src/parser.tab.cpp src/parser.tab.hpp: src/parser.y
	yacc -v -d src/parser.y -o src/parser.tab.cpp
	mkdir -p bin;

src/lexer.yy.cpp : src/lexer.flex src/parser.tab.hpp
	flex -o src/lexer.yy.cpp src/lexer.flex
	g++ -W -Wall -g -c src/lexer.yy.cpp -o src/lexer.yy.cpp

parser: src/parser.tab.cpp src/parser.tab.hpp

lexer : src/lexer.yy.cpp



bin/c_compiler : src/parser.tab.o src/lexer.yy.o $(OBJS)
	mkdir -p bin
	g++ $(CPPFLAGS) -c -o bin/c_compiler $^
	chmod u+x bin/c_compiler


	
clean :
	rm -f src/*.o
	rm -f bin/*
	# rm src/*.tab.cpp
	# rm src/*.yy.cpp
	rm -r test/working/*/*.s
	rm -r test/working/*/*.o

