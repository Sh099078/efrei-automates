CXX = g++
CXXFLAGS = -std=c++2a -pedantic -Wall -Wextra -g
VPATH = src
INCLUDE = headers
SRC = main.cc automaton.cc read-automaton.cc completion.cc determinization.cc \
			word-recognition.cc
EXE = a.out

.PHONY: all clean

all: $(EXE)

$(EXE) : $(SRC)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -o $@

clean:
	rm -rf $(EXE) *.o
