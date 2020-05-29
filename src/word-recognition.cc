#include <algorithm>

#include "word-recognition.hh"

bool recognize_word_rec(Automaton& automaton, std::string word,
    long unsigned int word_index, int curr_state) {
  auto& exits = automaton.exits_;
  if (word_index == word.length()) {
    return (std::find(exits.begin(), exits.end(), curr_state) != exits.end());
  }
  char symbol = word[word_index++];
  auto& next_states = automaton.transitions_[curr_state][symbol - 'a'];
  for (auto it = next_states.begin(); it != next_states.end(); it++) {
    if (recognize_word_rec(automaton, word, word_index, *it))
      return true;
  }
  return false;
}

bool recognize_word(Automaton& automaton, std::string word) {
  auto& entries = automaton.entries_;
 for (auto it = entries.begin(); it != entries.end(); it++) {
   if (recognize_word_rec(automaton, word, 0, *it)) {
     return true;
   }
 } 
 return false;
}
