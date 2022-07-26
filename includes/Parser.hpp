#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>

class parser
{
    private:
        std::vector<std::string> StreetType;
    public:
    parser();
    ~parser();
    int getNumber(std::vector<std::string> adress);
    int getStreet(std::vector<std::string> adress);
    bool checkWord(std::string word);
    bool CheckLine(std::string line);
};

std::vector<std::string> clean_str(std::string str, const char *separator);
#endif