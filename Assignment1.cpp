#include <iostream>
#include <vector>
#include "Assignment1.hpp"

int main(){
  std::vector<std::string> list = readFileLine("SampleInputFile-2021.txt");
  std::vector<std::string> words = removeComments(list);
  std::vector<std::string> words2 = removeSeparators(words);
  std::vector<std::string> words3 = removeOperators(words2);
  std::vector<std::string> words4 = getKeyWords(words3);
  std::vector<std::string> words5 = removeSpace(words);
  for(int i = 0; i < words.size(); i++ ){
    std::cout << "Word: "<< words[i] << '\n';
  }
  for(int i = 0; i < words2.size(); i++ ){
    std::cout << "Word1: "<< words2[i] << '\n';
  }
  for(int i = 0; i < words3.size(); i++ ){
    std::cout << "Word3: "<< words3[i] << '\n';
  }
  for(int i = 0; i < words4.size(); i++ ){
    std::cout << "Word4: "<< words4[i] << '\n';
  }
  for(int i = 0; i < words5.size(); i++ ){
    std::cout << "Word5: "<< words5[i] << '\n';
  }

  return 0;
}
