#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void createShrubby() {

	Bureaucrat *franz = NULL;
	AForm		*form = NULL;
	Intern		intern;

	std::cout << ANSI_COLOR_CYAN << "\n+++ Test case 1: create Shrubbery Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 6);
		
		form = intern.makeForm("shrubbery creation", "Shrubbbbby");
		franz->signForm(*form);
		franz->executeForm(*form);

	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete franz;
	delete form;
}

void createRobotomy() {

	Bureaucrat *franz = NULL;
	AForm		*form = NULL;
	Intern		intern;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 2: create Robotomy Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 6);
		
		form = intern.makeForm("robotomy request", "Boston Dog");
		franz->signForm(*form);
		franz->executeForm(*form);

	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete franz;
	delete form;
}

void createPresidential() {

	Bureaucrat *franz = NULL;
	AForm		*form = NULL;
	Intern		intern;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 3: create Presidential Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 5);
		
		form = intern.makeForm("presidential pardon", "Maaaagggus");
		franz->signForm(*form);
		franz->executeForm(*form);

	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete franz;
	delete form;
}

void invalidForm() {

	Bureaucrat *franz = NULL;
	AForm		*form = NULL;
	Intern		intern;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 4: invalid form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 5);
		
		form = intern.makeForm("Presidential Pardon Formm", "Maaaagggus");
		franz->signForm(*form);
		franz->executeForm(*form);

	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete franz;
	delete form;
}

int main () {

	createShrubby();
	createRobotomy();
	createPresidential();
	invalidForm();
	return (0);

}
