#include "easyfind.hpp"
#include <vector>
#include <stack>
#include <ctime>
#include <list>

//test_case with std::vector 
void testCase(int findInt) {

	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	std::cout << std::endl;
	try {
		std::vector<int>::iterator it = easyfind(v, findInt);
		(void)it;
		std::cout << "Found \"" << findInt  << "\" in the vector" << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n------------------------------------\n" << std::endl;
}

//test_case with std::string
void testCase2(int findInt) {

	std::string str = "Hallo";
	
	try {
		std::string::const_iterator it2 = easyfind(str, findInt);
		(void)it2;
		std::cout << "Found \"" << static_cast<char> (findInt)  << "\" in string ";
		std::cout << str << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n------------------------------------\n" << std::endl;
}

//test_case with std::list;
void testCase3(int findInt) {
	
	std::list<int> list; 

	list.push_back(12);
	list.push_back(67);
	list.push_back(45);
	list.push_back(78);


	try {
		std::list<int>::iterator it2 = easyfind(list, findInt);
		(void)it2;
		std::cout << "Found \"" << findInt  << "\" in list" << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n------------------------------------\n" << std::endl;	
}


int main() 
{
	int find = 3;
	testCase(find);
	
	const int find2 = 'a';
	testCase2(find2);

	int find3 = 67; 
	testCase3(find3);

	return (0);
}
