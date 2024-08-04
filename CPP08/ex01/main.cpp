#include "Span.hpp"
#include <ctime>

void	printGeneratedNumbers(std::vector<int> vec) 
{
	std::cout << "Print generated numbers" << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it <<  " ";
	}
	std::cout << std::endl;
}

std::vector<int> randomNumberGenerator(int min, int max, int nNumbers) 
{
    srand(static_cast<unsigned int>(time(0)));

    std::vector<int> vec;

    for (int i = 0; i < nNumbers; ++i) {
        vec.push_back(rand() % (max - min + 1) + min);
    }
	//printGeneratedNumbers(vec);
    return vec;	
}

void testSubject() {

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void testLargNumber() {

	Span sp(1000000);
	std::vector<int> vec = randomNumberGenerator(-8000000, 8000000 ,1000000);

	try {
		sp.addMultipleNumbers(vec.begin(), vec.end());
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "Shortest distance = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest distance = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void testSmallRange() {

	Span sp(100);
	std::vector<int> vec = randomNumberGenerator(-1000, 10000 ,100);

	try {
		sp.addMultipleNumbers(vec.begin(), vec.end());
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "Shortest distance = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest distance = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void throwShort() {

	Span sp(1);
	std::vector<int> vec = randomNumberGenerator(-1000, 1000 ,1);

	try {
		sp.addMultipleNumbers(vec.begin(), vec.end());
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "Shortest distance = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest distance = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void throwLong() {

	Span sp(1);
	std::vector<int> vec = randomNumberGenerator(-1000, 1000 ,1);

	try {
		sp.addMultipleNumbers(vec.begin(), vec.end());
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "Longest distance = " << sp.longestSpan() << std::endl;
		std::cout << "Shortest distance = " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void throwAdd() {

	Span sp(2);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "Longest distance = " << sp.longestSpan() << std::endl;
		std::cout << "Shortest distance = " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void throwAddMultiple() {

	Span sp(5);
	std::vector<int> vec = randomNumberGenerator(-1000, 1000 ,4);

	try {
		sp.addNumber(12);
		sp.addNumber(123);
		sp.addMultipleNumbers(vec.begin(), vec.end());
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Shortest distance = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest distance = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void	testCanonical() {

	Span sp(5);
	Span sp2;

	sp.addNumber(1);
	sp.addNumber(3);
	sp.addNumber(5);
	sp.addNumber(7);
	sp.addNumber(9);

	sp2 = sp;
	std::cout << "Print vector sp" << std::endl;
	sp.printVector();
	std::cout << "Print vector sp" << std::endl;
	sp2.printVector();
	try
	{
		sp.addNumber(12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	Span sp3(sp2);
	sp3.printVector();
}

int main() {

	std::cout << std::endl;
	testSubject();
	std::cout << "\n------------------------------\n" << std::endl;
	testLargNumber();
	std::cout << "\n------------------------------\n" << std::endl;
	testSmallRange();
	std::cout << "\n------------------------------\n" << std::endl;
	throwShort();
	std::cout << "\n------------------------------\n" << std::endl;
	throwLong();
	std::cout << "\n------------------------------\n" << std::endl;
	throwAdd();
	std::cout << "\n------------------------------\n" << std::endl;
	throwAddMultiple();
	std::cout << "\n------------------------------\n" << std::endl;
	testCanonical();

	return (0);
}
