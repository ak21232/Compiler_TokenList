#include "Assignment1.hpp"
#include <iostream>
#include <vector>

// Please insert file name inot the readFileLine() function

int main() {
  std::vector<std::string> list = readFileLine("SampleInputFile-2021.txt");
  std::vector<std::string> words = removeComments(list);
  std::vector<std::string> identifiers = tokenRetrieval(words, "Identifiers");
  std::vector<std::string> operators = tokenRetrieval(words, "Operators");
  std::vector<std::string> separators = tokenRetrieval(words, "Separators");
  std::vector<std::string> keywords = tokenRetrieval(words, "KeyWords");

  for (int i = 0; i < identifiers.size(); i++) {
    std::cout << "Identifiers: " << identifiers[i] << '\n';
  }

  for (int i = 0; i < operators.size(); i++) {
    std::cout << "Operators: " << operators[i] << '\n';
  }

  for (int i = 0; i < separators.size(); i++) {
    std::cout << "Separators: " << separators[i] << '\n';
  }

  for (int i = 0; i < keywords.size(); i++) {
    std::cout << "KeyWords: " << keywords[i] << '\n';
  }

  return 0;
}
