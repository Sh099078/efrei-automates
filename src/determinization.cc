#include "determinization.hh"

bool is_determinist(const Automaton& automaton) {
  //TODO add synchronization
  auto& transitions = automaton.transitions_;
  for (auto it = transitions.begin(); it != transitions.end(); it++) {
    for (auto jt = (*it).begin(); jt != (*it).end(); jt++) {
      //TODO change nb_symbols_ type to unsigned long int
      int nb_transitions = (*jt).size();
      if (0 < nb_transitions && nb_transitions < automaton.nb_symbols_)
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
