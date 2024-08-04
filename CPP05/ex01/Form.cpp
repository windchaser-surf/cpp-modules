#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _signedGrade(42), _execGrade(42) {

}

Form::Form(std::string const name, int const signedGrade, int const execGrade) : _name(name), 
_signed(false), _signedGrade(signedGrade), _execGrade(execGrade) {
	
	if (_execGrade > 150)
		throw GradeTooLowException();
	if (_execGrade < 1)
		throw GradeTooHighException();
	if (_signedGrade > 150)
		throw GradeTooLowException();
	if (_signedGrade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& old) :
	_name(old._name), _signed(old._signed), _signedGrade(old._signedGrade), _execGrade(old._execGrade) {

}

Form& Form::operator=(const Form& old) {

	if (this != &old) {
		_signed = old._signed;
	}
	return *this;
}

const char* Form::GradeTooHighException::what() const throw(){
	
	return " Grade is out of bounds (Too high!!)";
}

const char* Form::GradeTooLowException::what() const throw(){
	
	return " Grade is out of bounds (Too low!!)";
}

void    Form::beSigned(Bureaucrat& bureaucrat) {

	if (bureaucrat.getGrade() > _signedGrade)
		throw GradeTooLowException();
	else 
		_signed = true;
}

const int& Form::getExecGrade() const {

	return _execGrade;
}

bool Form::getSigned() const {

	return _signed;
}

const std::string& Form::getName() const {

	return _name;
}

const int& Form::getSignedGrade() const {

	return _signedGrade;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {

	if (form.getSigned() == false) {
		os << form.getName() << " has the requirement to sign: " << form.getSignedGrade() << std::endl;
		os << "and the requirement to execute: " << form.getExecGrade() << "."<< std::endl; 
		os << "Is not signed yet!" << std::endl;	
	}
	else 
	{
		os << form.getName() << " has the requirement to sign: " << form.getSignedGrade() << std::endl;
		os << "and the requirement to execute: " << form.getExecGrade() << "."<< std::endl; ; 
		os << "Is already signed!" << std::endl;
	}
	return os;
}

Form::~Form() {

}
