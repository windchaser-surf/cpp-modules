#include "Animal.hpp"

Animal::Animal() : type("Random animal") {
	
	std::cout << "Default constructor Animal called" << std::endl; 
}

Animal& Animal::operator=(const Animal& old) {

	std::cout << "Overload operator \"=\" Animal called" << std::endl;
	if (this != &old)
		*this = old; 
	return (*this); 
}

Animal::Animal(const Animal &old) {

	std::cout << "Copy constructor Animal called" << std::endl;
	*this = old;
}

std::string Animal::getType() const {

	return (this->type);
}

void	Animal::makeSound() const {

	std::cout << "Random animals are doing random noices" << std::endl; 
}

Animal::~Animal() {

	std::cout << "Deconstructor Animal called" << std::endl;
}
