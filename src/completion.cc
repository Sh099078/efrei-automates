#include "completion.hh"

bool is_complete(Automaton automaton) {
  auto& transitions = automaton.transitions_;
  for (auto it = transitions.begin(); it != transitions.end(); it++) {
    for (auto jt = (*it).begin(); jt != (*it).end(); jt++)
      if ((*jt).size() == 0)
        return false;
  }
  return true;
}

Automaton complete(Automaton) {
  return Automaton(0);
}
