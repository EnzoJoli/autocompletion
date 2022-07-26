#include "Complet.hpp"
#include <fstream>
#include <algorithm>
#include "Error.hpp"

std::string clear_front(std::string line)
{
    size_t start = line.find_first_not_of(" \n\t");
    if (start == std::string::npos) {
        return line;
    } else return line.substr(start);
}

void complet::fillCity(adress_t *buff, std::string adress)
{
    std::string buffer = "";
    std::vector<std::string> city = clean_str(clear_front(adress), " ");
    for (long unsigned int i = 0; i < city.size(); i++) {
        buffer += " ";
        buffer += city[i];
    }
    buff->city = clear_front(buffer);
}

void complet::fillNumber(adress_t *buff, std::vector<std::string> adress)
{
    int index = parse.getNumber(adress);
    buff->number = adress[index];
}

void complet::fillStreet(adress_t *buff, std::vector<std::string> adress)
{
    int index = parse.getStreet(adress);
    buff->street = adress[index];
}

void complet::fillAdress(adress_t *buff, std::vector<std::string> adress)
{
    std::string buffer;
    adress.erase(adress.begin() + parse.getNumber(adress));
    adress.erase(adress.begin() + parse.getStreet(adress));
    for (long unsigned int i = 0; i < adress.size(); i++) {
        buffer += " ";
        buffer += adress[i];
    }
    buff->adress = clear_front(buffer);
}

std::vector<std::string> complet::getCity()
{
    std::vector<std::string> ret;
    for (long unsigned int i = 0; i < data.size(); i++) {
        ret.push_back(data[i].city);
    }
    return ret;
}

std::vector<std::string> complet::getNumber()
{
    std::vector<std::string> ret;
    for (long unsigned int i = 0; i < data.size(); i++) {
        ret.push_back(data[i].number);
    }
    return ret;
}

std::vector<std::string> complet::getAdress()
{
    std::vector<std::string> ret;
    for (long unsigned int i = 0; i < data.size(); i++) {
        ret.push_back(data[i].adress);
    }
    return ret;
}

std::vector<std::string> complet::getStreet()
{
    std::vector<std::string> ret;
    for (long unsigned int i = 0; i < data.size(); i++) {
        ret.push_back(data[i].street);
    }
    return ret;
}