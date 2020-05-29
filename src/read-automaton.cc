#include <fstream>

#include "read-automaton.hh"

//TODO Add safety and data integrity checks
Automaton readAutomaton(const char* pathname) {
  std::string garbage; // for unused lines in input files
  int symbols, states, nb_transitions, nb_entries, nb_exits;
  std::ifstream file(pathname);
  // Retrieving automaton metadata:
  file >> symbols >> states >> nb_entries >> nb_exits;
  auto entries = std::vector<int>();
  auto exits = std::vector<int>();
  for (int i = 0; i < nb_entries ; i++) {
    int entry;
    file >> entry;
    entries.push_back(entry);
  }
  for (int i = 0; i < nb_exits; i++) {
    int exit;
    file >> exit;
    exits.push_back(exit);
  }
  file >> nb_transitions;
  // Building the bidimensionnal transitions matrix:
  std::vector<std::vector<std::vector<int>>> transitions(states);
  for (auto it = transitions.begin(); it != transitions.end(); it++) {
    *it = std::vector<std::vector<int>>(symbols);
    for (auto jt = (*it).begin(); jt != (*it).end(); jt++)
      *jt = std::vector<int>(0);
  }
  // Filling matrix with automaton transitions:
  int begin, end;
  char symbol;
  while (file >> begin >> end >> symbol) {
    auto& end_states = transitions[begin][symbol - 'a'];
    auto pos = std::upper_bound(end_states.begin(), end_states.end(), end);
    transitions[begin][symbol - 'a'].insert(pos, end);
  }
  return Automaton { symbols, states, nb_transitions, entries, exits, transitions };
}
