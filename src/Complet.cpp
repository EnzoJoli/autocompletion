#include "Complet.hpp"
#include <fstream>
#include <algorithm>
#include "Error.hpp"

complet::complet()
{
}

complet::~complet() {}

void complet::fillDatabase(std::string line)
{
    adress_t buff;
    std::vector<std::string>adress = clean_str(line, ",");

    if (adress.size() == 2) {
        if (parse.getNumber(clean_str(adress[0], " ")) == -1) {
            fillCity(&buff, adress[0]);
            fillNumber(&buff, clean_str(adress[1], " "));
            fillStreet(&buff,clean_str(adress[1], " "));
            fillAdress(&buff, clean_str(adress[1], " "));
        } else {
            fillCity(&buff, adress[1]);
            fillNumber(&buff,clean_str(adress[0], " "));
            fillStreet(&buff,clean_str(adress[0], " "));
            fillAdress(&buff, clean_str(adress[0], " "));
        }
    }
    data.emplace_back(buff);
}

void complet::GetAbreviation(std::vector<std::string> arg)
{
    std::vector<std::string> word;
    char c;
    std::string print = "";

    for (size_t i = 0; i < arg.size(); i++) {
        word = clean_str(arg[i], " ");
        for (size_t y = 0; y < word.size(); y++) {
            if (!word[y].empty()) {
                if (isupper(word[y].front())) {
                    c = (tolower(word[y].front()));
                } else c = (word[y].front());
                if (_city.find(c) == _city.end()) {
                    _city[c] = {word[y]};
                } else _city[c].push_back(word[y]);
            }
        }
    }
}

void complet::PrintCity(void)
{
    int max = 0;
    std::multimap<int, char> ret;

    for (auto &it : _city)
        ret.insert({it.second.size() , it.first});
    auto at = ++ret.rbegin();
    for (auto it = ret.rbegin(); it != ret.rend(); it++, at++, max++) {
        if (max == 5)
            break;
        if (it != ret.rbegin())
            std::cout << " ";
        if (at->first == it->first) {
            if (at->second < it->second)
                std::cout << "{" << at->second << "}";
            else std::cout << "{" << it->second << "}";
        } else std::cout << "{" << it->second << "}";
    }
    std::cout << std::endl;
}

void complet::end(std::string arg)
{
    for (unsigned long int i = 0; i < data.size(); i++) {
        if (data[i].city.find(arg) != std::string::npos)
            std::cout << "=> " << data[i].city << ", " << data[i].number << " " << data[i].street << " " << data[i].adress << std::endl;
    }
}

void complet::PrintFirst(std::vector<char> char_list)
{
    static int start = 0;
    int char_nb = 0;
    if (start > 0)
        std::cout << " ";
    if (char_list.empty())
        return;
    char buffer = char_list[0];
    for (unsigned long int i = 0; i < char_list.size(); i++) {
        if (buffer > char_list[i]) {
            buffer = char_list[i];
            char_nb = i;
        }
    }
    std::cout << "{" << input + char_list[char_nb] << "}";
    char_list.erase(char_list.begin() + char_nb);
    start++;
    PrintFirst(char_list);
}
void complet::firstPart()
{
    int b = 0;
    if (_city.find(tolower(input[0])) != _city.end()  || _city.find(tolower(input[0])) != _city.end()) {
        map = _city.at(tolower(input[0]));
    } else throw Unknow_adress("Unknow adress");
    if (map.size() > 1) {
        for (unsigned long int i = 0; i < map.size(); i++) {
            for (unsigned long int y = 0; y < map.size(); y++) {
                if (i != y && (b = map[i].compare(map[y])) > 0) {
                    map.erase(map.begin() + i);
                    if (std::find(character.begin(), character.end(), map[i][b]) == character.end())
                        character.emplace_back(map[i][b]);
                }
            }
        }
        PrintFirst(character);
        std::cout << std::endl;
    } else end(map[0]);
}

void complet::setTolow(std::string &arg)
{
    std::for_each(arg.begin(), arg.end(), [](char &d){
            d = tolower(d);
    });
}

void complet::PrintFinal(std::string buffer, std::string inp, int start)
{
    long unsigned int place = 0;

    if ((place = buffer.find(inp)) != std::string::npos) {
            for(;buffer[place] != ' ' && place < buffer.size(); place++)
                buffer[place] = toupper(buffer[place]);
    }
    std::cout << "{" << start << " : " << buffer << "}";
}

void complet::final(std::vector<adress_t> _adress)
{
    std::string inp = input;
    static int start = 1;

    if (_adress.empty()) {
        std::cout << std::endl;
        return;
    }
    setTolow(inp);
    if (start > 1)
        std::cout << " ";
    std::string buffer = _adress[0].city;
    setTolow(buffer);
    int buffer_nb = 0;
    for (unsigned long int i = 0; i < _adress.size(); i++) {
        if (buffer > _adress[i].city) {
            buffer = _adress[i].city;
            setTolow(buffer);
            buffer_nb = i; 
        }
    }
    PrintFinal(buffer, inp, start);
     _final[start + '0'] = _adress[buffer_nb];
    _adress.erase(_adress.begin() + buffer_nb);
    start++;
    final(_adress);
}

void complet::secondPart()
{
    long unsigned int place;
    std::vector<adress_t> ret;
    std::string buff;
    std::string inp = input;

    setTolow(inp);
    for (unsigned long int i = 0; i < data.size(); i++) {
        buff = data[i].city;
        setTolow(buff);
        if ((place = buff.find(inp)) != std::string::npos) {
            ret.push_back(data[i]);
        }
    }
    if (ret.size() == 1)
        end(ret[0].city);
    else final(ret);
}

void complet::find(char c)
{
    input += toupper(c);

    if (input.size() == 1) {
        firstPart();
    } else if (input.size() > 1) {
        if (!_final.empty() &&  _final.find(c) != _final.end()) {
            end(_final[c].city);
        }
        else if (_final.empty())
            secondPart();
    }
}

void complet::start(void)
{
    std::string buff;
    GetAbreviation(getCity());
    PrintCity();
    while(getline(std::cin, buff)) {
        if (buff == "ABORT")
            break;
        if (buff.size() > 1)
            throw Invalid_argument("unknow input");
        find(buff[0]);
    }
}

bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

void complet::run(std::string filepath) 
{
    std::string buff;
    std::ifstream file(filepath);

    if (!file.is_open())
        throw Invalid_argument("cant open filepath given");
    if (is_empty(file)) {
        throw Invalid_argument("");
        return;
    }
    while (getline(file, buff)) {
        if (parse.CheckLine(buff) == false)
            throw Invalid_argument("Bad input " + buff);
        fillDatabase(buff);
    }
    start();
}

