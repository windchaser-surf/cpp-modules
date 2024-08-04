#include "Character.hpp"

Character::Character() : _name("default") {
    
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
    std::cout << "Default Constructor CHARACTER called" << std::endl;
}

Character::Character(std::string name) : _name(name) {
    
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
    std::cout << "Constructor CHARACTER called" << std::endl;
}

Character::Character(const Character &old) {
    
    this->_name = old._name;

        for (int i = 0; i < 4; i++) {
            if (old._inventory[i] != NULL) {
                this->_inventory[i] = old._inventory[i]->clone();
            }
            else
                this->_inventory[i] = NULL;
        }
    std::cout << "Copy Constructor CHARACTER called" << std::endl;
}

Character& Character::operator=(const Character &old) {
    
    if (this != &old) {

        this->_name = old._name;
        for (int i = 0; i < 4; i++) {
            if (this->_inventory[i] != NULL) {
                delete this->_inventory[i];
            }
            this->_inventory[i] = NULL;
            if (old._inventory[i] != NULL) {
                this->_inventory[i] = old._inventory[i]->clone();
            }
        }
    }
    std::cout << "Assignment Operator CHARACTER called" << std::endl;
    return *this;
} 

std::string const & Character::getName() const {
    
    return this->_name;
}

void Character::equip(AMateria* m) {
    
    if (m == NULL)
        return ;
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] == NULL) {
            this->_inventory[i] = m;
            std::cout << "AMateria " << i << " " << m->getType() << " equipped ";
            std::cout << _name << std::endl;
            break;
        }
        if (i == 3) {
            std::cout << "Inventory is full" << std::endl;
            delete m;
            return ;
        }
    }
}

void Character::unequip(int idx) {
    
    if (idx >= 0 && idx < 4) {
        this->_inventory[idx] = NULL;
        std::cout << "AMateria " << idx << " unequipped " << _name << std::endl;
    }
}



void Character::use(int idx, ICharacter& target) {
    
    if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL) {
        if (this->_inventory[idx] != NULL) {
            this->_inventory[idx]->use(target);
        }
    }
}

AMateria* Character::getMemAdr(int idx) {

    if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
        return (this->_inventory[idx]);
    else 
        return (NULL);
}

Character::~Character() {
    
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] != NULL) {
            delete this->_inventory[i];
            std::cout << "Deleted AMateria " << i << std::endl;
        }
    }
}
