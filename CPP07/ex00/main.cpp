#include "whatever.hpp"

void swapTest() {

///////////////////////////Int swap(x, y))///////////////////////////

	int a = 5;
	int b = 3;

	std::cout << "\n\n+++ int swap(x, y) +++"<<std::endl << std::endl;
	swap(a, b);
	std::cout << "a = " << a << " | b = " << b << std::endl;
	swap(b, a);
	std::cout << "a = " << a << " | b = " << b << std::endl;

///////////////////////////String swap(x, y))///////////////////////////

	std::string stringA = "Guten"; 
	std::string stringB = "Morgen";

	std::cout << "\n\n+++ String swap(x, y) +++"<<std::endl << std::endl;
	swap(stringA, stringB);
	std::cout << "stringA = " << stringA << " | stringB = " << stringB << std::endl;
	swap(stringB, stringA);
	std::cout << "stringA = " << stringA << " | stringB = " << stringB << std::endl;
}

void minTest() {

///////////////////////////Int min(x, y)///////////////////////////

	int a = 3; 
	int b = 5;
	int c = -5;
	int d = 200;

	std::cout << "\n\n+++ int min(x, y) +++"<<std::endl << std::endl;
	std::cout << "min(3, 5)     =       " << min<int>(a, b) << std::endl;
	std::cout << "min(3, 3)     =       " << min<int>(a, a) << std::endl;
	std::cout << "min(-5, 3)    =       " << min<int>(c, a) << std::endl;
	std::cout << "min(3, 200)   =       " << min<int>(a, d) << std::endl;

///////////////////////////String min(x, y)///////////////////////////

	std::string a_string = "Hallo";
	std::string b_string = "Franz";
	std::string c_string = "Julia";
	std::string d_string = "Julian";

	std::cout << "\n\n+++ String min(x, y) +++"<<std::endl << std::endl;
	std::cout << "min(\"Hallo\", \"Franz\")     =       " << min<std::string>(a_string, b_string) << std::endl;
	std::cout << "min(\"Franz\", \"Hallo\")     =       " << min<std::string>(b_string, a_string) << std::endl;
	std::cout << "min(\"Julia\", \"Julian\")    =       " << min<std::string>(c_string, d_string) << std::endl;


///////////////////////////char min(x, y)///////////////////////////


	char a_char = 'H';
	char b_char = 'F';
	char c_char = 'J';

	std::cout << "\n\n+++ char min(x, y) +++"<<std::endl << std::endl;
	std::cout << "min(\"H\", \"F\")     =       " << min<char>(a_char, b_char) << std::endl;
	std::cout << "min(\"F\", \"H\")     =       " << min<char>(b_char, a_char) << std::endl;
	std::cout << "min(\"J\", \"J\")     =       " << min<char>(c_char, c_char) << std::endl;	
}


void maxTest() {
///////////////////////////Int max(x, y)///////////////////////////

	int a = 3; 
	int b = 5;
	int c = -5;
	int d = 200;

	std::cout << "\n\n+++ int max(x, y) +++"<<std::endl << std::endl;
	std::cout << "max(3, 5)     =       " << max<int>(a, b) << std::endl;
	std::cout << "max(3, 3)     =       " << max<int>(a, a) << std::endl;
	std::cout << "max(-5, 3)    =       " << max<int>(c, a) << std::endl;
	std::cout << "max(3, 200)   =       " << max<int>(a, d) << std::endl;

///////////////////////////String max(x, y)///////////////////////////

	std::string a_string = "Hallo";
	std::string b_string = "Franz";
	std::string c_string = "Julia";
	std::string d_string = "Julian";

	std::cout << "\n\n+++ String max(x, y) +++"<<std::endl << std::endl;
	std::cout << "max(\"Hallo\", \"Franz\")     =       " << max<std::string>(a_string, b_string) << std::endl;
	std::cout << "max(\"Franz\", \"Hallo\")     =       " << max<std::string>(b_string, a_string) << std::endl;
	std::cout << "max(\"Julia\", \"Julian\")    =       " << max<std::string>(c_string, d_string) << std::endl;


///////////////////////////char max(x, y)///////////////////////////


	char a_char = 'H';
	char b_char = 'F';
	char c_char = 'J';

	std::cout << "\n\n+++ char max(x, y) +++"<<std::endl << std::endl;
	std::cout << "max(\"H\", \"F\")     =       " << max<char>(a_char, b_char) << std::endl;
	std::cout << "max(\"F\", \"H\")     =       " << max<char>(b_char, a_char) << std::endl;
	std::cout << "max(\"J\", \"J\")     =       " << max<char>(c_char, c_char) << std::endl;
}


int main () {

	swapTest();
	minTest();
	maxTest();
	
	return (0);
}
