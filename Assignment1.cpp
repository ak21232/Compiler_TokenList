#include <iostream>
#include <vector>
#include "Assignment1.hpp"

int main(){
  std::vector<std::string> list = readFile("SampleInputFile-2021.txt");
  std::vector<std::string> words = categorizeKeyWords(list);
  std::vector<std::string> separators = categorizeSeparators(list);
  std::vector<std::string> operators = categorizeOperators(list);
  for(int i = 0; i < list.size(); i++ ){
    std::cout << list[i] << '\n';
  }
  for(int i = 0; i < words.size(); i++ ){
    std::cout << "Words: "<< words[i] << '\n';
  }
  for(int i = 0; i < separators.size(); i++ ){
    std::cout << "Sep: "<<  separators[i] << '\n';
  }
  for(int i = 0; i < operators.size(); i++ ){
    std::cout << "Op: "<< operators[i] << '\n';
  }
  return 0;
}
