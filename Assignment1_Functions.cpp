#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Function that reads the code inputted
std::vector<std::string> readFileLine(std::string fileName)
{
  std::vector<std::string> wordList;
  std::fstream file;
  file.open(fileName);
  if (file.is_open()){
    std::string line;
    while (getline(file, line)){
      wordList.push_back(line);
    }
  }
  file.close();
  return wordList;
}

// Function that categorizes what is read from the input list
// into their respective lexeme type
std::vector<std::string> removeComments(std::vector<std::string> wordlist){
  std::vector<std::string> wordListNoComments;
  for(int i = 0; i < wordlist.size(); i++ ){
    if (wordlist[i].find("!") == std::string::npos){
      std::string word;
      for(int j = 0; j < wordlist[i].length(); j++){
        if (wordlist[i].at(j) != ' '){
          word += wordlist[i].at(j);
        }
      }
      wordListNoComments.push_back(word);
    }
  }
  return wordListNoComments;
}

std::vector<std::string> categorizeIdentifiers(std::vector<std::string> list);

std::vector<std::string> categorizeSeparators(std::vector<std::string> list){
  const std::vector<std::string> separators{"(", ")", "{", "}", "[", "]",
                                            ",", ".", ":", ";", "'"};
                                            // const std::vector<std::string> keyWords{
                                            //     "int",  "float",  "bool",     "True",      "False",    "if", "else",
                                            //     "then", "endif",  "endelse",  "while",     "whileend", "do", "enddo",
                                            //     "for",  "endfor", "STDinput", "STDoutput", "and",      "or", "not"};
                                            // const std::vector<std::string> separators{"(", ")", "{", "}", "[", "]",
                                            //                                               ",", ".", ":", ";", "'"};
  std::vector<std::string> words;
  for(int i = 0; i < list.size(); i++ ){
    for(int j = 0; j < separators.size(); j++ ){
      if (list[i].find(separators[j])){
        words.push_back(separators[j]);
        words.push_back(list[i].substr(0,list[i].size() -1));
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
