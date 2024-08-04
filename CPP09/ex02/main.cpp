#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	std::string str;

	if (argc < 2)
		return (std::cerr << "Error: invalid args!" << std::endl, 1);
	if (argc > 2)
		for (int i = 1; i < argc; i++)
		{
			str += argv[i];
			str += ' ';
		}
	else 
		str = argv[1];
	try
	{
		PmergeMe(str);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
