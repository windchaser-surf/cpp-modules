#include "Cat.hpp"

Cat::Cat() : brain(new Brain){
	
	type = "Cat";
	std::cout << "Default constructor Cat called" << std::endl; 
}

Cat& Cat::operator=(const Cat& old) {

	std::cout << "Overload operator \"=\" Cat called" << std::endl;
	if (this != &old)
	{
		type = old.type; 
		*brain = *old.brain;
	}
	return (*this); 
}

Cat::Cat(const Cat &old) {

	type = old.type; 
	brain = new Brain(*old.brain);
	std::cout << "Copy constructor Cat called" << std::endl;
}

void	Cat::setBrain(std::string newIdea) {

	brain->setBrain(newIdea);
}

Brain* Cat::getBrain() const {

	return brain;
}

void	Cat::makeSound() const {

	std::cout << "miaow, miaow, miaow, miaow ...!" << std::endl;
}

Cat::~Cat() {

	delete brain;
	std::cout << "Deconstructor Cat called" << std::endl;
}
