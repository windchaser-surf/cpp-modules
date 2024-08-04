#include "ScalarConverter.hpp"

int main (int argc, char **argv) {

	if (argc != 2)
		return (std::cerr << "Number of arguments is not valid" << std::endl, 1);
	ScalarConverter::convert(argv[1]);
}
