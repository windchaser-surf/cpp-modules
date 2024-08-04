#include "Bureaucrat.hpp"

#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void invalidBureaucrat() {

	Bureaucrat *franz = NULL;
	Form *fortyTwo = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n+++ Test case 1: invalid Constructor  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 0);
		fortyTwo = new Form("Acceptance condition", 151, 42);
		for (int i = 0; i < 120; i++)
		{
			franz->IncrementGrade();
		}
		
		franz->signForm(*fortyTwo);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (fortyTwo != NULL)
		delete fortyTwo;
}

void invalidForm() {

	Bureaucrat *franz = NULL;
	Form *fortyTwo = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 2: invalid Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 1);
		fortyTwo = new Form("Acceptance condition", 152, 42);
		if (fortyTwo)
			std::cout << *fortyTwo << std::endl;
		for (int i = 0; i < 5; i++)
		{
			franz->IncrementGrade();
		}
		
		franz->signForm(*fortyTwo);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (fortyTwo != NULL)
		delete fortyTwo;
}

void invalidSignForm() {

	Bureaucrat *franz = NULL;
	Form *fortyTwo = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 3: invalid sign Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 10);
		fortyTwo = new Form("Acceptance condition", 3, 42);
		
		if (fortyTwo)
			std::cout << *fortyTwo << std::endl;
		franz->signForm(*fortyTwo);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (fortyTwo != NULL)
		delete fortyTwo;	
}

void validSignForm() {

	Bureaucrat *franz = NULL;
	Form *fortyTwo = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 4: valid sign Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 3);
		fortyTwo = new Form("Acceptance condition", 3, 42);

		if (fortyTwo)
			std::cout << *fortyTwo << std::endl;
		franz->signForm(*fortyTwo);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (fortyTwo != NULL)
		delete fortyTwo;
}


int main () {

	invalidBureaucrat();
	invalidForm();
	invalidSignForm();
	validSignForm();

	return (0);
}
