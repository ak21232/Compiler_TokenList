#include "Assignment1_Functions.cpp"

const std::vector<std::string> identifiers{"null"};

std::vector<std::string> readFile(std::string fileName);

std::vector<std::string> categorizeKeyWords(std::vector<std::string> list);

std::vector<std::string> categorizeIdentifiers(std::vector<std::string> list);

std::vector<std::string> categorizeSeparators(std::vector<std::string> list);

std::vector<std::string> categorizeOperators(std::vector<std::string> list);
