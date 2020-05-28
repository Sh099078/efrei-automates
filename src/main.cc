#include <iostream>

#include "read-automaton.hh"
#include "automaton.hh"

#define TEAM_NB 24

int main(void) {
  size_t choice;
  while(std::cout << "Which automaton do you want to test ?\n" && std::cin >> choice) {
    std::cout << "You chose the automaton " << choice << "." << std::endl;
    std::string pathname = "tests/L3New-MpI-"
      + std::to_string(TEAM_NB) + "-"
      + std::to_string(choice) + ".txt";
    Automaton automaton = readAutomaton(pathname.c_str());
    //TODO Automaton processing
    std::cout << '\n' << automaton.toString() << '\n';
  }
  std::cout << "Leaving the program." << std::endl;
  return 0;
}
