#include "determinization.hh"

bool is_determinist(const Automaton& automaton) {
  //TODO add synchronization
  auto& transitions = automaton.transitions_;
  for (auto it = transitions.begin(); it != transitions.end(); it++) {
    for (auto jt = (*it).begin(); jt != (*it).end(); jt++) {
      if ((*jt).size() > 1)
        return false;
    }
  }
  return true;
}

Automaton determinize(const Automaton& automaton) {
  Automaton a_determinized = automaton;
  //TODO determinize a_determinized
  return a_determinized;
}
