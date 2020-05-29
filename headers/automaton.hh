#pragma once

#include <vector>
#include <string>

class Automaton {
  public:
    Automaton(int, int, int, std::vector<int>, std::vector<int>,
        std::vector<std::vector<int>>);
    Automaton(int symbols);
    bool addTransition(int begin, char symbol, int end); //TODO
    bool removeTransition(int begin, char symbol, int end); //TODO
    int addState(bool, bool); //TODO
    std::string toString();
  private:
    int nb_symbols_;
    int nb_states_;
    int nb_transitions_;
    std::vector<int> entries_;
    std::vector<int> exits_;
    std::vector<std::vector<int>> transitions_;
};

// ascii(67) : g
// transitions_[3][67] : arrival state from begin state 3 after getting
// symbol (67 - 'a'). -1 if that transition doesn't exist.
