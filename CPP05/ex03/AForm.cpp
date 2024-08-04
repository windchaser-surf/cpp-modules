#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signedGrade(42), _execGrade(42) {

}

AForm::AForm(std::string const name, int const signedGrade, int const execGrade) : _name(name), 
_signedGrade(signedGrade), _execGrade(execGrade) {
	
	if (_execGrade > 150)
		throw GradeTooLowException();
	if (_execGrade < 1)
		throw GradeTooLowException();
	if (_signedGrade > 150)
		throw GradeTooLowException();
	if (_signedGrade < 1)
		throw GradeTooLowException();
	_signed = false;
}

AForm::AForm(const AForm& old) :
	_name(old._name), _signed(old._signed), _signedGrade(old._signedGrade), _execGrade(old._execGrade) {

}

AForm& AForm::operator=(const AForm& old) {

	if (this != &old) {
		_signed = old._signed;

	}
	return *this;
}

const char* AForm::GradeTooHighException::what() const throw(){
	
	return " Grade is out of bounds (Too high!!)";
}

const char* AForm::GradeTooLowException::what() const throw(){
	
	return " Grade is out of bounds (Too low!!)";
}

const char* AForm::GradeNotSigned::what() const throw() {

	return "Unfortunately grade is not signed yet!!";
}

void    AForm::beSigned(Bureaucrat& bureaucrat) {

	if (bureaucrat.getGrade() > _signedGrade)
		throw GradeTooLowException();
	else 
		_signed = true;
}

int AForm::getExecGrade() const {

	return _execGrade;
}

bool AForm::getSigned() const {

	return _signed;
}

std::string AForm::getName() const {

	return _name;
}

int AForm::getSignedGrade() const {

	return _signedGrade;
}

void AForm::checkRequirements(const Bureaucrat& executer) const {

	if (getSigned() == false)
		throw GradeNotSigned();
	else if (executer.getGrade() > getExecGrade())
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {

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

AForm::~AForm() {

}
