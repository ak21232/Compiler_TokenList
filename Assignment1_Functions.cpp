#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Function that reads the code inputted
std::vector<std::string> readFileLine(std::string fileName) {
  std::vector<std::string> wordList;
  std::fstream file;
  file.open(fileName);
  if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
      wordList.push_back(line);
    }
  }
  file.close();
  return wordList;
}

// Function that categorizes what is read from the input list
// into their respective lexeme type
std::vector<std::string> removeComments(std::vector<std::string> wordlist) {
  std::vector<std::string> wordListNoComments;
  for (int i = 0; i < wordlist.size(); i++) {
    if (wordlist[i].find("!") == std::string::npos) {
      std::string word;
      std::istringstream iss(wordlist[i]);
      while (iss >> word) {
        wordListNoComments.push_back(word);
      }
    }
  }
  return wordListNoComments;
}


std::vector<std::string> tokenRetrieval(std::vector<std::string> wordList, std::string returnType) {
  std::vector<std::string> identifiersListInitial;
  std::vector<std::string> identifiersListFinal;
  std::vector<std::string> keywordList;
  std::vector<std::string> separatorsList;
  std::vector<std::string> operatorsList;
  for (int i = 0; i < wordList.size(); i++) {
    if (wordList[i] == "int" || wordList[i] == "float" ||
        wordList[i] == "bool" || wordList[i] == "True" ||
        wordList[i] == "False" || wordList[i] == "if" ||
        wordList[i] == "else" || wordList[i] == "then" ||
        wordList[i] == "endif" || wordList[i] == "endelse" ||
        wordList[i] == "while" || wordList[i] == "whileend" ||
        wordList[i] == "do" || wordList[i] == "enddo" || wordList[i] == "for" ||
        wordList[i] == "endfor" || wordList[i] == "STDinput" ||
        wordList[i] == "STDoutput" || wordList[i] == "and" ||
        wordList[i] == "or" || wordList[i] == "not") {
      keywordList.push_back(wordList[i]);
    } else if (wordList[i] == "(" || wordList[i] == ")" || wordList[i] == "{" ||
               wordList[i] == "}" || wordList[i] == "[" || wordList[i] == "]" ||
               wordList[i] == "," || wordList[i] == "." || wordList[i] == ";" ||
               wordList[i] == ":" || wordList[i] == "\'") {
      separatorsList.push_back(wordList[i]);
    } else if (wordList[i] == "+" || wordList[i] == "-" || wordList[i] == "=" ||
               wordList[i] == "*" || wordList[i] == "/" || wordList[i] == ">" ||
               wordList[i] == "<" || wordList[i] == "%") {
      operatorsList.push_back(wordList[i]);
    } else {
      identifiersListInitial.push_back(wordList[i]);
    }
  }
  for(int i = 0; i < identifiersListInitial.size(); i++){
    std::string word2;
    for (int j = 0; j < identifiersListInitial[i].length(); j++) {
      if (identifiersListInitial[i].at(j) != '(' &&
          identifiersListInitial[i].at(j) != ')' &&
          identifiersListInitial[i].at(j) != '{' &&
          identifiersListInitial[i].at(j) != '}' &&
          identifiersListInitial[i].at(j) != '[' &&
          identifiersListInitial[i].at(j) != ']' &&
          identifiersListInitial[i].at(j) != ',' &&
          identifiersListInitial[i].at(j) != '.' &&
          identifiersListInitial[i].at(j) != ';' &&
          identifiersListInitial[i].at(j) != ':' &&
          identifiersListInitial[i].at(j) != '\'' &&
          identifiersListInitial[i].at(j) != '+' &&
          identifiersListInitial[i].at(j) != '=' &&
          identifiersListInitial[i].at(j) != '-' &&
          identifiersListInitial[i].at(j) != '*' &&
          identifiersListInitial[i].at(j) != '/' &&
          identifiersListInitial[i].at(j) != '>' &&
          identifiersListInitial[i].at(j) != '<' &&
          identifiersListInitial[i].at(j) != '%') {
        word2 += identifiersListInitial[i].at(j);
      }
    }
    identifiersListFinal.push_back(word2);
  }
  if (returnType == "Identifiers"){
    return identifiersListFinal;
  }
  else if (returnType == "Operators"){
    return operatorsList;
  }
  else if (returnType == "Separators"){
    return separatorsList;
  }
  else if (returnType == "KeyWords"){
    return keywordList;
  }
  else{
    return wordList;
  }
}
