#include "Dog.hpp"

Dog::Dog() : brain(new Brain) {
	
	type = "Dog";
	std::cout << "Default constructor Dog called" << std::endl; 
}

Dog& Dog::operator=(const Dog& old) {

	std::cout << "Overload operator \"=\" Dog called" << std::endl;
	if (this != &old)
	{
		type = old.type;
		*brain = *old.brain;
	}
	return (*this); 
}

Dog::Dog(const Dog &old) {

	std::cout << "Copy constructor Dog called" << std::endl;
	type = old.type; 
	brain = new Brain(*old.brain);
}

void	Dog::setBrain(std::string newIdea) {

	brain->setBrain(newIdea);
}

Brain* Dog::getBrain() const {

	return brain;
}

void Dog::makeSound() const {

	std::cout << "WoofWoof, WoofWoof ... !" << std::endl;	
}

Dog::~Dog() {

	delete brain;
	std::cout << "Deconstructor Dog called" << std::endl;
}
