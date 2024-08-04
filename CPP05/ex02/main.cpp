#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void invalidSignShrubbery() {

	Bureaucrat *franz = NULL;
	AForm *shrubbery = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 1: invalid sign Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 3);
		shrubbery = new ShrubberyCreationForm("Shrubbbbby");
		if (shrubbery)
			std::cout << *shrubbery << std::endl;
		franz->executeForm(*shrubbery);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (shrubbery != NULL)
		delete shrubbery;
}

void invalidGradeSignShrubbery() {

	Bureaucrat *franz = NULL;
	AForm *shrubbery = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 2: invalid grade for sign Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 150);
		shrubbery = new ShrubberyCreationForm("Shrubbbbby");
		if (shrubbery)
			std::cout << *shrubbery << std::endl;
		franz->signForm(*shrubbery);
		franz->executeForm(*shrubbery);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (shrubbery != NULL)
		delete shrubbery;
}

void invalidGradeExecShrubbery() {

	Bureaucrat *franz = NULL;
	AForm *shrubbery = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 3: invalid grade for exec Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 140);
		shrubbery = new ShrubberyCreationForm("Shrubbbbby");

		if (shrubbery)
			std::cout << *shrubbery << std::endl;
		franz->signForm(*shrubbery);
		franz->executeForm(*shrubbery);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (shrubbery != NULL)
		delete shrubbery;
}

void validShrubbery() {

	Bureaucrat *franz = NULL;
	AForm *shrubbery = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 4: valid Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 137);
		shrubbery = new ShrubberyCreationForm("Shrubbbbby");
		if (shrubbery)		
			std::cout << *shrubbery << std::endl;
		franz->signForm(*shrubbery);
		franz->executeForm(*shrubbery);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (shrubbery != NULL)
		delete shrubbery;
}

void invalidSignRobotomy() {

	Bureaucrat *franz = NULL;
	AForm *robotomy = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 5: invalid sign Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 3);
		robotomy = new RobotomyRequestForm("Boston Dog");

		if (robotomy)
			std::cout << *robotomy << std::endl;
		franz->executeForm(*robotomy);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (robotomy != NULL)
		delete robotomy;
}

void invalidGradeSignRobotomy() {

	Bureaucrat *franz = NULL;
	AForm *robotomy = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 6: invalid grade for sign Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 74);
		robotomy = new RobotomyRequestForm("Boston Dog");
		if (robotomy)		
			std::cout << *robotomy << std::endl;
		franz->signForm(*robotomy);
		franz->executeForm(*robotomy);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (robotomy != NULL)
		delete robotomy;
}

void invalidGradeExecRobotomy() {

	Bureaucrat *franz = NULL;
	AForm *robotomy = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 7: invalid grade for exec Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 46);
		robotomy = new RobotomyRequestForm("Boston Dog");
		if (robotomy)		
			std::cout << *robotomy << std::endl;
		franz->signForm(*robotomy);
		franz->executeForm(*robotomy);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (robotomy != NULL)
		delete robotomy;
}

void validRobotomy() {

	Bureaucrat *franz = NULL;
	AForm *robotomy = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 8: valid Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 30);
		robotomy = new RobotomyRequestForm("Boston Dog");

		if (robotomy)		
			std::cout << *robotomy << std::endl;
		franz->signForm(*robotomy);
		franz->executeForm(*robotomy);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (robotomy != NULL)
		delete robotomy;
}

void invalidSignPresidential() {

	Bureaucrat *franz = NULL;
	AForm *presidential = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 9: invalid sign Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 3);
		presidential = new PresidentialPardonForm("Olaaaaaf");

		if (presidential)
			std::cout << *presidential << std::endl;
		franz->executeForm(*presidential);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (presidential != NULL)
		delete presidential;
}

void invalidGradeSignPresidential() {

	Bureaucrat *franz = NULL;
	AForm *presidential = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 10: invalid grade for sign Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 26);
		presidential = new PresidentialPardonForm("Olaaaaaf");

		if (presidential)		
			std::cout << *presidential << std::endl;
		franz->signForm(*presidential);
		franz->executeForm(*presidential);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (presidential != NULL)
		delete presidential;
}

void invalidGradeExecPresidential() {

	Bureaucrat *franz = NULL;
	AForm *presidential = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 11: invalid grade for exec Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 7);
		presidential = new PresidentialPardonForm("Olaaaaaf");

		if (presidential)		
			std::cout << *presidential << std::endl;
		franz->signForm(*presidential);
		franz->executeForm(*presidential);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (presidential != NULL)
		delete presidential;
}

void validPresidential() {

	Bureaucrat *franz = NULL;
	AForm *presidential = NULL;

	std::cout << ANSI_COLOR_CYAN << "\n\n+++ Test case 12: valid Form  +++\n" << ANSI_COLOR_RESET << std::endl;
	try {
		franz = new Bureaucrat("Franz", 2);
		presidential = new PresidentialPardonForm("Olaaaaaf");

		if (presidential)		
			std::cout << *presidential << std::endl;
		franz->signForm(*presidential);
		franz->executeForm(*presidential);
	}
	catch (std::exception& e){
		std::cerr << "Come on!!! Your Grade is not valid: " << e.what() << std::endl;
	}

	if (franz != NULL)
		delete franz;
	if (presidential != NULL)
		delete presidential;
}

int main () {

	invalidSignShrubbery();
	invalidGradeSignShrubbery();
	invalidGradeExecShrubbery();
	validShrubbery();

	invalidSignRobotomy();
	invalidGradeSignRobotomy();
	invalidGradeExecRobotomy();
	validRobotomy();

	invalidSignPresidential();
	invalidGradeSignPresidential();
	invalidGradeExecPresidential();
	validPresidential();

	return (0);

}
