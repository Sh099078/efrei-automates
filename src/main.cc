#include <iostream>
#include <sstream>
#include <string>

#include "read-automaton.hh"
#include "automaton.hh"
#include "completion.hh"
#include "word-recognition.hh"
#include "complementarization.hh"

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
    std::cout << "Type words to recognize separated by whitespaces: ";
    std::string line;
    std::cin >> line;
    std::cout << "word '" << line << "' recognized : " << std::boolalpha
      << recognize_word(automaton, line) << std::endl;
    std::cout << "Is complete : " << std::boolalpha << is_complete(automaton) << std::endl;
    std::cout << "Completion : " << std::endl;
    Automaton a_complete = complete(automaton);
    //
    std::cout << '\n' << a_complete.toString() << '\n';
    std::cout << "Complementary automaton : " << std::endl;
    auto a_complementary = complementary(a_complete);
    std::cout << '\n' << a_complementary.toString() << '\n';
  }
  std::cout << "Leaving the program." << std::endl;
  return 0;
}
