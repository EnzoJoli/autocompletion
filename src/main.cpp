#include <iostream>
#include "Complet.hpp"
#include "Error.hpp"

int main(int ac, char**av)
{
    try {
        complet bo;
        if (ac != 2)
            throw Invalid_argument("invalid argument");
        bo.run(av[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}