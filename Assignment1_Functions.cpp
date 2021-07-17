#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Function that reads the input command
std::vector<std::string> readFile(std::string fileName)
{
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
std::vector<std::string> categorizeKeyWords(std::vector<std::string> list){
  const std::vector<std::string> keyWords{
      "int",  "float",  "bool",     "True",      "False",    "if", "else",
      "then", "endif",  "endelse",  "while",     "whileend", "do", "enddo",
      "for",  "endfor", "STDinput", "STDoutput", "and",      "or", "not"};
  std::vector<std::string> words;
  for(int i = 0; i < list.size(); i++ ){
    for(int j = 0; j < keyWords.size(); j++ ){
      if (list[i] == keyWords[j]){
        words.push_back(keyWords[j]);
      }
    }
  }
  return words;
}

std::vector<std::string> categorizeIdentifiers(std::vector<std::string> list);

std::vector<std::string> categorizeSeparators(std::vector<std::string> list){
  const std::vector<std::string> separators{"(", ")", "{", "}", "[", "]",
                                            ",", ".", ":", ";", "'"};
  std::vector<std::string> words;
  for(int i = 0; i < list.size(); i++ ){
    for(int j = 0; j < separators.size(); j++ ){
      if (list[i] == separators[j]){
        words.push_back(separators[j]);
      }
    }
  }
  return words;
}

std::vector<std::string> categorizeOperators(std::vector<std::string> list){
  const std::vector<std::string> operators{"*", "+", "-", "=",
                                           "/", ">", "<", "%"};
  std::vector<std::string> words;
  for(int i = 0; i < list.size(); i++ ){
    for(int j = 0; j < operators.size(); j++ ){
      if (list[i] == operators[j]){
        words.push_back(operators[j]);
      }
    }
  }
  return words;
}
