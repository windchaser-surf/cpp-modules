#include "Cat.hpp"

Cat::Cat() {
	
	type = "Cat";
	std::cout << "Default constructor Cat called" << std::endl; 
}

Cat& Cat::operator=(const Cat& old) {

	std::cout << "Overload operator \"=\" Cat called" << std::endl;
	if (this != &old)
		this->type = old.type;
	return (*this); 
}

Cat::Cat(const Cat &old) {

	std::cout << "Copy constructor Cat called" << std::endl;
	*this = old;
}

void	Cat::makeSound() const {

	std::cout << "miaow, miaow, miaow, miaow ...!" << std::endl;
}

Cat::~Cat() {

	std::cout << "Deconstructor Cat called" << std::endl;
}
