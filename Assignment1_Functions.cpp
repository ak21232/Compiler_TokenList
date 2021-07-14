#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Function that reads the input command
std::vector<std::string> readFile(std::string fileName) {
  std::vector<std::string> wordList;
  std::string word;
  std::fstream file;
  file.open(fileName);
  while (file >> word) {
    wordList.push_back(word);
  }
  file.close();
  return wordList;
}

// Function that categorizes what is read from the input list
// into their respective lexeme type
void categorizeLexemes();
