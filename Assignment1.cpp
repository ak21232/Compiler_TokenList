#include <iostream>
#include <vector>
#include "Assignment1.hpp"

int main(){
  std::vector<std::string> list = readFileLine("SampleInputFile-2021.txt");
  std::vector<std::string> words = removeComments(list);
  std::vector<std::string> words2 = removeSeparators(words);
  for(int i = 0; i < list.size(); i++ ){
    std::cout << list[i] << '\n';
  }
  for(int i = 0; i < words2.size(); i++ ){
    std::cout << "Word: "<< words2[i] << '\n';
  }

  return 0;
}
