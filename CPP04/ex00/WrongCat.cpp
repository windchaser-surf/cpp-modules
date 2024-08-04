#include "WrongCat.hpp"

WrongCat::WrongCat() {
	
	type = "WrongCat";
	std::cout << "Default constructor WrongCat called" << std::endl; 
}

WrongCat& WrongCat::operator=(const WrongCat& old) {

	std::cout << "Overload operator \"=\" WrongCat called" << std::endl;
	if (this != &old)
		this->type = old.type;
	return (*this); 
}

WrongCat::WrongCat(const WrongCat &old) {

	std::cout << "Copy constructor WrongCat called" << std::endl;
	*this = old;
}

void	WrongCat::makeSound() const {

	std::cout << "miaow, miaow, miaow, miaow ...!" << std::endl;
}

WrongCat::~WrongCat() {

	std::cout << "Deconstructor WrongCat called" << std::endl;
}
