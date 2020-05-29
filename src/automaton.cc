#include <algorithm>

#include "automaton.hh"

Automaton::Automaton(int symbols, int states, int nb_transitions,
   std::vector<int> entries, std::vector<int> exits,
   std::vector<std::vector<int>> transitions)
  : nb_symbols_{symbols}, nb_states_{states}, nb_transitions_{nb_transitions},
    entries_{entries}, exits_{exits}, transitions_{transitions} { }

Automaton::Automaton(int symbols) {
  nb_symbols_ = symbols;
  entries_ = std::vector<int>();
  exits_ = std::vector<int>();
  nb_states_ = 0;
  nb_transitions_ = 0;
  transitions_ = std::vector<std::vector<int>>();
}

int int_length(int i) {
  return std::to_string(i).length();
}

bool Automaton::addTransition(int begin, char symbol, int end) {
  if (begin != std::clamp(begin, 0, std::max(0, nb_states_ - 1))
      || symbol - 'a' != std::clamp(symbol - 'a', 0, nb_symbols_ - 1)
      || end != std::clamp(end, 0, std::max(0, nb_states_ - 1)))
    return false; // Index out of range
  transitions_[begin][symbol - 'a'] = end;
  nb_transitions_++;
  return true;
}
bool Automaton::removeTransition(int begin, char symbol, int end) {
  if (!nb_transitions_ || transitions_[begin][symbol - 'a'] != end)
    return false; // Transition doesn't exist
  nb_transitions_--;
  return true;
}

int Automaton::addState(bool initial, bool terminal) {
  nb_states_++;
  std::vector<int> new_state(nb_symbols_);
  for (auto it = new_state.begin(); it != new_state.end(); it++)
    *it = -1;
  transitions_.push_back(new_state);
  if (initial)
    entries_.push_back(nb_states_ - 1);
  if (terminal)
    exits_.push_back(nb_states_ - 1);
  return nb_states_;
}

std::string Automaton::toString() {
  int padding = 6;
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
    padding = 4;
    int state = std::distance(transitions_.begin(), i);
    if (std::find(entries_.begin(), entries_.end(), state) != entries_.end()) {
      str += 'E';
      padding--;
    }
    if (std::find(exits_.begin(), exits_.end(), state) != exits_.end()) {
      if (padding == 3) {
        str += "/";
        padding--;
      }
      str += 'S';
      padding--;
    }
    str += std::string(padding, ' ');
    //Display the state number:
    int current_state = std::distance(transitions_.begin(), i);
    str += std::to_string(current_state);
    str += std::string(most_digits - int_length(current_state), ' ');
    // Display the state transitions:
    for (auto j = (*i).begin(); j != (*i).end(); j++) {
      str += std::string(most_digits - int_length(*j) + 1, ' ') + std::to_string(*j);
    }
    str = str + '\n';
  }
  return str;
}
