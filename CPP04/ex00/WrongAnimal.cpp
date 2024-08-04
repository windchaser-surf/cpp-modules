#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong random animal") {
	
	std::cout << "Default constructor WrongAnimal called" << std::endl; 
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& old) {

	std::cout << "Overload operator \"=\" WrongAnimal called" << std::endl;
	if (this != &old)
		*this = old; 
	return (*this); 
}

WrongAnimal::WrongAnimal(const WrongAnimal &old) {

	std::cout << "Copy constructor WrongAnimal called" << std::endl;
	*this = old;
}

std::string WrongAnimal::getType() const {

	return (this->type);
}

void	WrongAnimal::makeSound() const {

	std::cout << "Wrong random animals are doing random noices" << std::endl; 
}

WrongAnimal::~WrongAnimal() {

	std::cout << "Deconstructor WrongAnimal called" << std::endl;
}
