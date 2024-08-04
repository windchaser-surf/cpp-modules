#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
		: AForm("Robotomy Request Form", 72, 45){
	
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& old) 
		: AForm("Robotomy Request Form", 72, 45){
		
	_target = old._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& old) {

	if (this != &old)
		_target = old._target; 
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executer) const {

	AForm::checkRequirements(executer);
	std::cout << "Drilllllllllllles deep, deeper, deepest!!! ;)" << std::endl;
	srand(time(0)); // check if fine!!  
	if (rand() % 2)
		std::cout << _target << " has been robotmized successfully" << std::endl;
	else 
		std::cerr << _target << " robotomy failed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}
