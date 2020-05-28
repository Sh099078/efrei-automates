#include <fstream>

#include "read-automaton.hh"

//TODO Add safety and data integrity checks
Automaton readAutomaton(const char* pathname) {
  std::string garbage; // for unused lines in input files
  int symbols, states, nb_transitions, nb_entries, nb_exits;
  std::ifstream file(pathname);
  // Retrieving automaton metadata:
  file >> symbols >> states >> nb_entries >> nb_exits;
  std::vector<int> entries{ nb_entries };
  std::vector<int> exits{ nb_exits };
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
  std::vector<std::vector<char>> transitions(states);
  for (auto it = transitions.begin(); it != transitions.end(); it++) {
    *it = std::vector<char>(states);
    for (auto jt = (*it).begin(); jt != (*it).end(); jt++)
      *jt = '\0';
  }
  // Filling matrix with automaton transitions:
  int begin, end;
  char symbol;
  while (file >> begin >> end >> symbol) {
    transitions[begin][end] = symbol;
  }
  return Automaton { symbols, states, nb_transitions, entries, exits, transitions };
}
