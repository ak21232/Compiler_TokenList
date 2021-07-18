#include "Assignment1_Functions.cpp"

const std::vector<std::string> identifiers{"null"};

std::vector<std::string> readFileLine(std::string fileName);

std::vector<std::string> removeComments(std::vector<std::string> wordListNoComments);

std::vector<std::string> removeSeparators(std::vector<std::string> wordListNoComments);

std::vector<std::string> categorizeSeparators(std::vector<std::string> list);

std::vector<std::string> categorizeOperators(std::vector<std::string> list);
