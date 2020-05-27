#include <iostream>

#include "read-automaton.hh"
#include "automaton.hh"

int main(void) {
  size_t auto_nb;
  while(std::cout << "Which automaton do you want to test ?\n" && std::cin >> auto_nb) {
    std::cout << "You chose the automaton " << auto_nb << "." << std::endl;
  }
  std::cout << "Leaving the program." << std::endl;
  return 0;
}
