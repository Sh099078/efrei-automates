#include "complementarization.hh"

#include <vector>

Automaton complementary(const Automaton& automaton) {
  //TODO add synchronization, completion and determinization
  Automaton a_complementary = automaton;
  auto& exits = a_complementary.exits_;
  std::vector<int> new_exits{};
  for (int state = 0; state < a_complementary.nb_states_; state++) {
    if (std::find(exits.begin(), exits.end(), state) == exits.end()) {
      new_exits.push_back(state);
    }
  }
  exits = new_exits;
  return a_complementary;
}
