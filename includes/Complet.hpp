#ifndef AUTOCOMPLET_H
#define AUTOCOMPLET_H

#include <iostream>
#include <map>
#include "Parser.hpp"

typedef struct adress
{
    std::string city;
    std::string number;
    std::string adress;
    std::string street;
} adress_t;

class complet
{
    private:
        std::vector<char> character;
        std::vector<std::string> map;
        std::string input;
        parser parse;
        std::vector<adress_t> data;
        std::map<char, std::vector<std::string>> _city;
        std::map<char, adress_t> _final;
    public:
        complet();
        ~complet();
        std::vector<std::string> getCity();
        std::vector<std::string> getNumber();
        std::vector<std::string> getAdress();
        std::vector<std::string> getStreet();
    
        void fillCity(adress_t *buff, std::string adress);
        void fillNumber(adress_t *buff, std::vector<std::string> adress);
        void fillAdress(adress_t *buff, std::vector<std::string> adress);
        void fillStreet(adress_t *buff, std::vector<std::string> adress);
        void fillDatabase(std::string file);

        void PrintCity(void);
        void PrintFirst(std::vector<char> chra_list);
        void PrintFinal(std::string buffer, std::string inp, int start);
    
        void final(std::vector<adress_t> _adress);
        void firstPart();
        void secondPart();
        void end(std::string arg);
        void find(char c);
        void GetAbreviation(std::vector<std::string> arg);
        
        void setTolow(std::string &arg);
        void run(std::string filepath);
        void start(void);
};
#endif