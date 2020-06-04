CXX = g++
CXXFLAGS = -std=c++2a -pedantic -Wall -Werror -Wextra -g
VPATH = src
INCLUDE = headers
SRC = main.cc automaton.cc read-automaton.cc completion.cc determinization.cc \
			word-recognition.cc complementarization.cc
EXE = a.out

.PHONY: all clean

all: $(EXE)

$(EXE) : $(SRC)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -o $@

test: $(EXE)
	./$<

debug: $(EXE)
	gdb ./$<

leaks: $(EXE)
	valgrind ./$<



clean:
	rm -rf $(EXE) *.o
