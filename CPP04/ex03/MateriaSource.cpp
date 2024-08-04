#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    
    
    for (int i = 0; i < 4; i++) {
        this->_materia[i] = NULL;
    }
    std::cout << "Default Constructor MATERIASOURCE called" << std::endl;

}

MateriaSource::MateriaSource(const MateriaSource &old) {
    
    for (int i = 0; i < 4; i++) {
        if (old._materia[i] != NULL) {
            this->_materia[i] = old._materia[i]->clone();
        }
        else 
            this->_materia[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &old) {
    
    std::cout << "Copy Assignment operator MateriaSource called" << std::endl; 
    if (this != &old) {

        for (int i = 0; i < 4; i++) {
            if (this->_materia[i] != NULL) {
                delete this->_materia[i];
            }
            this->_materia[i] = NULL;
            if (old._materia[i] != NULL) {
                this->_materia[i] = old._materia[i]->clone();
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    
    for (int i = 0; i < 4; i++) {
        if (this->_materia[i] != NULL) {
            delete this->_materia[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    
    if (m == NULL)
        return ;    
    for (int i = 0; i < 4; i++) {
        if (this->_materia[i] == NULL) {
            this->_materia[i] = m;
            return;
        }
        if (i == 3){
            std::cout << "You can't learn new Materia's! <" << m->getType();
            std::cout << "> You're not as clever as you think!" << std::endl;  
            delete m;
            
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    
    for (int i = 0; i < 4; i++) {
        if (this->_materia[i] != NULL && this->_materia[i]->getType() == type) {
            return this->_materia[i]->clone();
        }
    }
    return NULL;
}

