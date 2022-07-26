#include "Parser.hpp"
#include "Error.hpp"
#include <vector>
#include <codecvt>
#include <locale>

parser::parser() : StreetType({"allée", "avenue", "boulevard", "chemin", "impasse", "place", "quai", "rue", "square"}) {}

parser::~parser() {}

std::vector<std::string> clean_str(std::string str, const char *separator)
{
    std::vector<std::string> ret;
    std::size_t buff, prev = 0;

    buff = str.find(separator);
    while (buff != std::string::npos) {
        ret.emplace_back(str.substr(prev, buff - prev));
        prev = buff + 1;
        buff = str.find(separator, prev);
    }
    ret.push_back(str.substr(prev, buff - prev));
    return ret;
}

bool parser::checkWord(std::string word)
{
    std::string exception = "éè-,'";
    for (long unsigned int y = 0; y < word.size(); y++)
            if ((word[y] < 'A' || word[y] > 'z')) {
                for (long unsigned int i = 0; i < exception.size(); i++)
                    if (word[y] == exception[i])
                        return true;
                return false;
            }
    return true;
}

int parser::getStreet(std::vector<std::string> adress)
{
    for (long unsigned int i = 0; i < adress.size(); i++)
        for (long unsigned int y = 0; y < StreetType.size(); y++)
            if (adress[i] == StreetType[y])
                return i;
    return -1;
}

int parser::getNumber(std::vector<std::string> adress)
{
    for (long unsigned int i = 0; i < adress.size(); i++) {
        if (atoi(adress[i].c_str()) != 0)
            return i;
    }
    return -1;
}

bool parser::CheckLine(std::string line)
{
    int index = -1;
    std::vector<std::string> adress = clean_str(line, " ");
    adress[0] = clean_str(adress[0], ",")[0];

    if (adress.size() < 4)
        return false;
    for (long unsigned int i = 0; i < adress.size(); i++) {
        index = getNumber(adress);
        if (index == -1 || (checkWord(adress[i]) == false && i != (long unsigned int)index))
            return false;
    }
    return true;
}