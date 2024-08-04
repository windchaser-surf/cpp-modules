#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {

}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {

	if (_grade > 150) {
		throw GradeTooLowException();
	}
	else if (_grade < 1) {
		throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& old) : _name(old._name), _grade(old._grade) {

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& old) {

	if (this != &old) {
		_grade = old._grade;
	}
	return *this;
}

void Bureaucrat::IncrementGrade() {

	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else 
		_grade--;
}

void Bureaucrat::DecrementGrade() {

	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else 
		_grade++;
}

int Bureaucrat::getGrade() const {

	return _grade;
}

std::string Bureaucrat::getName() const {

	return _name;
}

void	Bureaucrat::signForm(AForm& form) {

	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}	
	catch (std::exception& e) {
		std::cerr << _name << " can't signed " << form.getName(); 
		std::cerr << " , because" << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {

	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return os;
}

Bureaucrat::~Bureaucrat() {

}
