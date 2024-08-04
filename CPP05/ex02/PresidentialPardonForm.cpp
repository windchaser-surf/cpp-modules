#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
		: AForm("Presidential Pardon Form", 25, 5){
	
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& old) 
		: AForm("Presidential Pardon Form", 25, 5){
		
	_target = old._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& old) {

	if (this != &old)
		_target = old._target; 
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executer) const {

	AForm::checkRequirements(executer);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}
