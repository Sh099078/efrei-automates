#pragma once

#include <vector>
#include <string>

class Automaton {
  public:
    Automaton(int, int, int, std::vector<std::vector<char>>);
    std::string toString();
  private:
    int nb_symbols_;
    int nb_states_;
    int nb_transitions_;
    std::vector<std::vector<char>> transitions_;
};
