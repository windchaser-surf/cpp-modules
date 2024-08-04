#include "RPN.hpp"

int main(int argc, char** argv) 
{
    if (argc != 2)
        return (std::cerr << "Error: invalid amount of arguments." << std::endl, 1);
    
    try {
        calcRpn(argv[1]);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl; 
        return (1);
    }
    return (0);    

}
