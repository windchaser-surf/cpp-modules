#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    
}

Ice::Ice(const Ice &old) {
 
    *this = old;
}

Ice &Ice::operator=(const Ice &old) {

    if (this != &old) {
        this->_type = old._type;
    }
    return *this;
}

AMateria* Ice::clone() const {
    
    return new Ice(*this);
}

void    Ice::use(ICharacter& target) {

    std::cout << "* shoots an ice bolt at " << target.getName();
    std::cout << " *" << std::endl;
}

Ice::~Ice() {

}
