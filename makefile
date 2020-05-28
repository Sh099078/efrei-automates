CXX = g++
CXXFLAGS = -std=c++2a -Wall -Wextra -Werror -g
VPATH = src
INCLUDE = headers
SRC = main.cc
EXE = a.out

.PHONY: all clean

all: $(EXE)

$(EXE) : $(SRC)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -o $@

clean:
	rm -rf $(EXE) *.o
