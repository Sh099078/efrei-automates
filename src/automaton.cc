#include <algorithm>
#include <iterator>

#include "automaton.hh"

Automaton::Automaton(int symbols, int states, int nb_transitions,
   std::vector<int> entries, std::vector<int> exits,
   std::vector<std::vector<std::vector<int>>> transitions)
  : nb_symbols_{symbols}, nb_states_{states}, nb_transitions_{nb_transitions},
    entries_{entries}, exits_{exits}, transitions_{transitions} { }

Automaton::Automaton(int symbols) {
  nb_symbols_ = symbols;
  nb_states_ = 0;
  nb_transitions_ = 0;
  entries_ = std::vector<int>(0);
  exits_ = std::vector<int>(0);
  transitions_ = std::vector<std::vector<std::vector<int>>>(0);
}

Automaton::Automaton(const Automaton& automaton) {
  nb_symbols_ = automaton.nb_symbols_;
  nb_states_ = automaton.nb_states_;
  nb_transitions_ = automaton.nb_transitions_;
  entries_ = automaton.entries_;
  exits_ = automaton.exits_;
  transitions_ = automaton.transitions_;
}

int int_length(int i) {
  return std::to_string(i).length();
}

bool Automaton::addTransition(int begin, char symbol, int end) {
  if (begin != std::clamp(begin, 0, std::max(0, nb_states_ - 1))
      || symbol - 'a' != std::clamp(symbol - 'a', 0, nb_symbols_ - 1)
      || end != std::clamp(end, 0, std::max(0, nb_states_ - 1)))
    return false; // Index out of range
  auto& end_states = transitions_[begin][symbol - 'a'];
  auto pos = std::upper_bound(end_states.begin(), end_states.end(), end);
  if (pos == end_states.begin() || *std::prev(pos, 1) != end)
    transitions_[begin][symbol - 'a'].insert(pos, end);
  nb_transitions_++;
  return true;
}
bool Automaton::removeTransition(int begin, char symbol, int end) {
  auto& end_states = transitions_[begin][symbol - 'a'];
  auto pos = std::find(end_states.begin(), end_states.end(), end);
  if (!nb_transitions_ || pos == end_states.end())
    return false; // Transition doesn't exist
  end_states.erase(pos);
  nb_transitions_--;
  return true;
}

int Automaton::addState(bool initial, bool terminal) {
  nb_states_++;
  std::vector<std::vector<int>> new_state(nb_symbols_);
  for (auto it = new_state.begin(); it != new_state.end(); it++) {
    *it = std::vector<int>(0);
  }
  transitions_.push_back(new_state);
  if (initial)
    entries_.push_back(nb_states_ - 1);
  if (terminal)
    exits_.push_back(nb_states_ - 1);
  return nb_states_ - 1;
}

std::string Automaton::toString() {
  int padding = 8;
  int most_digits = int_length(std::max({nb_symbols_, nb_states_, 10}));
  std::string str{};
  str += std::string(padding, ' ');
  padding = 9;
  for (int i = 0; i < nb_symbols_; i++) {
    str.push_back('a' + i);
    str += std::string(padding, ' ');
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
      padding = 10;
      auto end_states = *j;
      std::string end;
      if (end_states.size() == 0)
        end = "  x  ";
      else {
        end += "{ ";
        for (auto it = end_states.begin(); it != end_states.end(); it++) {
          //Concatenate end states:
          end += std::to_string(*it) + " ";
        }
        end += '}';
      }
      str += end;
      str += std::string(padding - end.size(), ' ');
    }
    str = str + '\n';
  }
  return str;
}
