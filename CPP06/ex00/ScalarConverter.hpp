#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <limits>


class ScalarConverter {

    private: 

        ScalarConverter();
        ScalarConverter(const ScalarConverter& old);
        ScalarConverter& operator=(const ScalarConverter& old);
        ~ScalarConverter();
    
    public: 

        static void convert(const std::string& literal);
};

#endif
