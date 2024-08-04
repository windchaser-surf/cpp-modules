#include "Bureaucrat.hpp"

#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void	validConstructor() {
	
	Bureaucrat *franz = NULL;
	std::cout << ANSI_COLOR_CYAN << "\n+++ Test case 1: valid Constructor and valid Decrement! +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 10);
		for (int i = 0; i < 5; i++)
		{
			franz->DecrementGrade(); 
			std::cout << *franz << std::endl;
		} 
	}
	catch (std::exception& e) {

		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}
	if (franz != NULL)
		delete franz; 
}	

void	exceptionDecrement() {

	Bureaucrat *franz = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 2: valid Constructor and invalid Decrement! +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 145);
		for (int i = 0; i < 10; i++)
		{
			franz->DecrementGrade(); 
			std::cout << *franz << std::endl;
		} 
	}
	catch (std::exception& e) {

		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}
	if (franz != NULL)
		delete franz; 	
}

void 	exceptionIncrement() {

	Bureaucrat *franz = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 3: valid Constructor and invalid Increment! +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 5);
		for (int i = 0; i < 10; i++)
		{
			franz->IncrementGrade(); 
			std::cout << *franz << std::endl;
		} 
	}
	catch (std::exception& e) {

		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}
	if (franz != NULL)
		delete franz;	
}

void	invalidConstructor() {

	Bureaucrat *franz = NULL;


	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 4: invalid Constructor and invalid Decrement+++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 151);
		for (int i = 0; i < 1; i++)
		{
			franz->DecrementGrade(); 
			std::cout << *franz << std::endl;
		} 
	}
	catch (std::exception& e) {

		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}
	if (franz != NULL)
		delete franz; 
}

void invalidConstructor2() {

	Bureaucrat *franz = NULL;


	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 5: invalid Constructor and invalid Decrement+++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", -5);
		for (int i = 0; i < 1; i++)
		{
			franz->DecrementGrade(); 
			std::cout << *franz << std::endl;
		} 
	}
	catch (std::exception& e) {

		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}
	if (franz != NULL)
		delete franz; 	
}

int main () {

	validConstructor();
	exceptionDecrement();
	exceptionIncrement();
	invalidConstructor();
	invalidConstructor2();


	return (0);
}
