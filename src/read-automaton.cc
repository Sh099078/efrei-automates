#include <fstream>

#include "read-automaton.hh"

//TODO Implement or remove unsued lines from specs
//TODO Add safety and data integrity checks
//TODO Improve parsing not to bug on empty lines or incorrect token numbers
Automaton readAutomaton(const char* pathname) {
  std::string garbage; // for unused lines in input files
  int symbols, states, nb_transitions;
  std::ifstream file(pathname);
  // Retrieving automaton metadata:
  file >> symbols >> states >> garbage >> garbage >> nb_transitions;
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
  return Automaton { symbols, states, nb_transitions, transitions };
}
