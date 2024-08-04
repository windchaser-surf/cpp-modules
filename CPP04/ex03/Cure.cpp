#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    
}

Cure::Cure(const Cure &old) {
 
    *this = old;
}


Cure &Cure::operator=(const Cure &old) {

    if (this != &old) {
        this->_type = old._type;
    }
    return *this;
}

AMateria* Cure::clone() const {
    
    return new Cure(*this);
}

void    Cure::use(ICharacter& target) {

    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 
}

Cure::~Cure() {
    
}
