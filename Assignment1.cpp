#include <iostream>
#include <vector>
#include "Assignment1.hpp"

int main(){
  std::vector<std::string> list = readFile("SampleInputFile-2021.txt");
  for(int i = 0; i < list.size(); i++ ){
    std::cout << list[i] << '\n';
  }
  for(int i = 0; i < keyWords.size(); i++ ){
    std::cout << keyWords[i] << '\n';
  }
  return 0;
}
