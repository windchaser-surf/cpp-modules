#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {
	
	std::cout << "Default Constructor AMateria called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {

}

AMateria::AMateria(const AMateria &old) {
	
	*this = old;
}

AMateria& AMateria::operator=(const AMateria &old) {
	
	if (this != &old) {
		this->_type = old._type;
	}
	return *this;
}

std::string const & AMateria::getType() const {
	
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	
	std::cout << "Don't do this!" << target.getName() << std::endl;
}

AMateria::~AMateria() {}
