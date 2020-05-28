#include "automaton.hh"

automaton::automaton(int symbols, int states, int, std::vector<std::vector<char>> transitions)
  : nb_symbols_{symbols}, nb_states_{states}, transitions_{transitions} { }
