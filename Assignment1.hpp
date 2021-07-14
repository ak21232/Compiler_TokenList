#include "Assignment1_Functions.cpp"

const std::vector<std::string> keyWords{
    "int",  "float",  "bool",     "True",      "False",    "if", "else",
    "then", "endif",  "endelse",  "while",     "whileend", "do", "enddo",
    "for",  "endfor", "STDinput", "STDoutput", "and",      "or", "not"};

const std::vector<std::string> identifiers{"null"};

const std::vector<std::string> separators{"(", ")", "{", "}", "[", "]",
                                          ",", ".", ":", ";", "'"};

const std::vector<std::string> operators{"*", "+", "-", "=",
                                         "/", ">", "<", "%"};

std::vector<std::string> readFile(std::string fileName);

void categorizeLexemes();
