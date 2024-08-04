#include "BitcoinExchange.hpp"

int main (int argc, char** argv) {

    (void)argc;
    (void)argv;

    if (argc != 2)
    {
        std::cerr << "The program needs a inputfile!" << std::endl;
        return (1);
    }
    BitcoinExchange data; 
    try {
        if(!data.getDataBase("data.csv"))
            return (1);
        if (!data.getInput(argv[1]))
            return (1);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
