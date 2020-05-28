#include "automaton.hh"

Automaton::Automaton(int symbols, int states, int, std::vector<std::vector<char>> transitions)
  : nb_symbols_{symbols}, nb_states_{states}, transitions_{transitions} { }

std::string Automaton::toString() {
  std::string str{};
  for (auto i = transitions_.begin(); i != transitions_.end(); i++) {
    for (auto j = (*i).begin(); j != (*i).end(); j++) {
      str = str + " " + *j;
    }
    str = str + '\n';
  }
  return str;
}
