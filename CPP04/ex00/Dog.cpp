#include "Dog.hpp"

Dog::Dog() {
	
	type = "Dog";
	std::cout << "Default constructor Dog called" << std::endl; 
}

Dog& Dog::operator=(const Dog& old) {

	std::cout << "Overload operator \"=\" Dog called" << std::endl;
	if (this != &old)
		this->type = old.type; 
	return (*this); 
}

Dog::Dog(const Dog &old) {

	std::cout << "Copy constructor Dog called" << std::endl;
	*this = old;
}

void Dog::makeSound() const {

	std::cout << "WoofWoof, WoofWoof ... !" << std::endl;	
}

Dog::~Dog() {

	std::cout << "Deconstructor Dog called" << std::endl;
}
