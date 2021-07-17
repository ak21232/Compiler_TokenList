#include <iostream>
#include <vector>
#include "Assignment1.hpp"

int main(){
  std::vector<std::string> list = readFileLine("SampleInputFile-2021.txt");
  std::vector<std::string> words = categorizeKeyWords(list);
  for(int i = 0; i < list.size(); i++ ){
    std::cout << list[i] << '\n';
  }
  for(int i = 0; i < words.size(); i++ ){
    std::cout << "Word: "<< words[i] << '\n';
  }

  return 0;
}
