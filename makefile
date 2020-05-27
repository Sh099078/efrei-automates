CXX = g++
CXXFLAGS = -std=c++2a -Wall -Wextra -Werror -g
VPATH = src
SRC = main.cc
EXE = a.out

.PHONY: all clean

all: $(EXE)

$(EXE) : $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(EXE) *.o

