#ifndef ERROR_H
#define ERROR_H

#include <exception>
#include <iostream>

class Invalid_argument : public std::exception
{
public:
    Invalid_argument(std::string const &descr) throw() : message(descr) {};
    virtual const char *what() const throw()
    {
        return message.c_str();
    }
private:
    std::string message;
};

class Unknow_adress : public std::exception
{
public:
    Unknow_adress(std::string const &descr) throw() : message(descr) {};
    virtual const char *what() const throw()
    {
        return message.c_str();
    }
private:
    std::string message;
};
#endif