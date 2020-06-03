#include "completion.hh"

bool is_complete(const Automaton& automaton) {
  auto& transitions = automaton.transitions_;
  for (auto it = transitions.begin(); it != transitions.end(); it++) {
    for (auto jt = (*it).begin(); jt != (*it).end(); jt++)
      if ((*jt).size() == 0)
        return false;
  }
  return true;
}

Automaton complete(const Automaton& original) {
  //TODO add synchronization and determinization
  Automaton automaton = original;
  if (is_complete(automaton))
    return automaton;
  int garbage_state = automaton.addState(false, false);
  auto& transitions = automaton.transitions_;
  for (auto it = transitions.begin(); it != transitions.end(); it++) {
    for (auto jt = (*it).begin(); jt != (*it).end(); jt++) {
      if ((*jt).size() == 0)
        (*jt).push_back(garbage_state);
    }
  }
  return automaton;
}
