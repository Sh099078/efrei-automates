#include "automaton.hh"

Automaton::Automaton(int symbols, int states, int nb_transitions,
   std::vector<int> entries, std::vector<int> exits,
   std::vector<std::vector<char>> transitions)
  : nb_symbols_{symbols}, nb_states_{states}, nb_transitions_{nb_transitions},
    entries_{entries}, exits_{exits}, transitions_{transitions} { }

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
