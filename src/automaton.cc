#include <algorithm>

#include "automaton.hh"

Automaton::Automaton(int symbols, int states, int nb_transitions,
   std::vector<int> entries, std::vector<int> exits,
   std::vector<std::vector<int>> transitions)
  : nb_symbols_{symbols}, nb_states_{states}, nb_transitions_{nb_transitions},
    entries_{entries}, exits_{exits}, transitions_{transitions} { }

int int_length(int i) {
  return std::to_string(i).length();
}

std::string Automaton::toString() {
  int padding = 3;
  int most_digits = int_length(std::max({nb_symbols_, nb_states_, 10}));
  std::string str{};
  str += std::string(most_digits + padding, ' ');
  for (int i = 0; i < nb_symbols_; i++) {
    str.push_back('a' + i);
    str += std::string(most_digits, ' ');
  }
  str += '\n';
  for (auto i = transitions_.begin(); i != transitions_.end(); i++) {
    // Display E / S if the current state is an entry (resp. exit):
    padding = 3;
    int state = std::distance(transitions_.begin(), i);
    if (std::find(entries_.begin(), entries_.end(), state) != entries_.end()) {
      str += 'E';
      padding--;
    }
    if (std::find(exits_.begin(), exits_.end(), state) != exits_.end()) {
      if (padding == 2) {
        str += "/";
        padding--;
      }
      str += 'S';
      padding--;
    }
    str += std::string(padding, ' ');
    // Display the state transitions:
    for (auto j = (*i).begin(); j != (*i).end(); j++) {
      str += std::string(most_digits - int_length(*j) + 1, ' ') + std::to_string(*j);
    }
    str = str + '\n';
  }
  return str;
}
