.PHONY: clean distclean default

CXX=c++
CXXFLAGS=-Wall -std=c++11 `llvm-config --cxxflags`
LDFLAGS=`llvm-config --ldflags --system-libs --libs all`

default: compiler

lexer.cpp: lexer.l
	flex -s -olexer.cpp lexer.l

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

lexer.o: lexer.cpp lexer.hpp parser.hpp ast.hpp symbol.hpp

parser.hpp parser.cpp: parser.y
	bison -dv -o parser.cpp parser.y

# Add your dependencies here, e.g.
parser.o: parser.cpp lexer.hpp ast.hpp symbol.hpp

compiler: lexer.o parser.o 
	$(CXX) $(CXXFLAGS) -o compiler lexer.o parser.o $(LDFLAGS)

clean:
	$(RM) lexer.cpp parser.cpp parser.hpp parser.output *.o

distclean: clean
	$(RM) compiler