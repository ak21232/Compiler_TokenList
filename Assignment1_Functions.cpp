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
        if (wordlist[i].at(j) != ' ' && wordlist[i].at(j) != '\t'){
          word += wordlist[i].at(j);
        }
      }
      wordListNoComments.push_back(word);
    }
  }
  return wordListNoComments;
}



std::vector<std::string> removeSeparators(std::vector<std::string> wordListNoComments){
  std::vector<std::string> wordListNoSep;
  std::vector<char> separatorsList;
  for(int i = 0; i < wordListNoComments.size(); i++){
    std::string word;
    for(int j = 0; j < wordListNoComments[i].length(); j++){
      if (wordListNoComments[i].at(j) != '(' && wordListNoComments[i].at(j) != ')' && wordListNoComments[i].at(j) != '{' && wordListNoComments[i].at(j) != '}' && wordListNoComments[i].at(j) != '[' && wordListNoComments[i].at(j) != ']' && wordListNoComments[i].at(j) != ',' && wordListNoComments[i].at(j) != '.' && wordListNoComments[i].at(j) != ';' && wordListNoComments[i].at(j) != ':' && wordListNoComments[i].at(j) != '\''  ){
        word += wordListNoComments[i].at(j);
      }
      else {
        separatorsList.push_back(wordListNoComments[i].at(j));
      }
    }
    wordListNoSep.push_back(word);
  }
  return wordListNoSep;
}

std::vector<std::string> removeOperators(std::vector<std::string> wordListNoSep){
  std::vector<std::string> wordListNoOps;
  std::vector<char> operatorsList;
  for(int i = 0; i < wordListNoSep.size(); i++){
    std::string word;
    for(int j = 0; j < wordListNoSep[i].length(); j++){
      if (wordListNoSep[i].at(j) != '+' && wordListNoSep[i].at(j) != '-' && wordListNoSep[i].at(j) != '=' && wordListNoSep[i].at(j) != '*' && wordListNoSep[i].at(j) != '/' && wordListNoSep[i].at(j) != '>' && wordListNoSep[i].at(j) != '<' && wordListNoSep[i].at(j) != '%' ){
        word += wordListNoSep[i].at(j);
      }
      else {
        operatorsList.push_back(wordListNoSep[i].at(j));
      }
    }
    wordListNoOps.push_back(word);
  }
  return wordListNoOps;
}

std::vector<std::string> getKeyWords(std::vector<std::string> wordListNoOps){
  std::vector<std::string> identifiers;
  std::vector<std::string> keywordList;
  for(int i = 0; i < wordListNoOps.size(); i++){
    std::string word;
    for(int j = 0; j < wordListNoOps[i].length(); j++){
      word += wordListNoOps[i].at(j);
      if (word == "int" || word == "float" || word == "bool" || word == "True" || word == "False" || word == "if" || word == "else" || word == "then" || word == "endif" || word == "endelse" || word == "while" || word == "whileend" || word == "do" || word == "enddo" || word == "for" || word == "endfor" || word == "STDinput" || word == "STDoutput" || word == "and" || word == "or"|| word == "not" ){
        keywordList.push_back(word);

      }
    }
  }
  return keywordList;
}

std::vector<std::string> removeSpace(std::vector<std::string> wordList){
  std::vector<std::string> identifiersList;
  std::vector<std::string> keywordList;
  std::vector<std::string> separatorsList;
  std::vector<std::string> operatorsList;
  for(int i = 0; i < wordList.size(); i++ ){
    std::string word;
    for(int j = 0; j < wordList[i].length(); j++){
      word += wordList[i].at(j);
      if (word == "int" || word == "float" || word == "bool" || word == "True" || word == "False" || word == "if" || word == "else" || word == "then" || word == "endif" || word == "endelse" || word == "while" || word == "whileend" || word == "do" || word == "enddo" || word == "for" || word == "endfor" || word == "STDinput" || word == "STDoutput" || word == "and" || word == "or"|| word == "not" ){
        keywordList.push_back(word);
        word.erase(0,word.at(j));
      }
      if(wordList[i].at(j) == '(' || wordList[i].at(j) == ')' || wordList[i].at(j) == '{' || wordList[i].at(j) == '}' || wordList[i].at(j) == '[' || wordList[i].at(j) == ']' || wordList[i].at(j) == ',' || wordList[i].at(j) == '.' || wordList[i].at(j) == ';' || wordList[i].at(j) == ':' || wordList[i].at(j) == '\''){
        std::string sep;
        sep += wordList[i].at(j);
        separatorsList.push_back(sep);
        word.erase(word.find(sep));
      }
      if (wordList[i].at(j) == '+' || wordList[i].at(j) == '-' || wordList[i].at(j) == '=' || wordList[i].at(j) == '*' || wordList[i].at(j) == '/' || wordList[i].at(j) == '>' || wordList[i].at(j) == '<' || wordList[i].at(j) == '%' ){
        std::string op;
        op += wordList[i].at(j);
        operatorsList.push_back(op);
        word.erase(word.find(op));
      }
    }
    identifiersList.push_back(word);
  }
  return identifiersList;
}
