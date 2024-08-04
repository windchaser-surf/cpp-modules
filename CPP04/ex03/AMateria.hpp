#ifndef AMATERIA_H
# define AMATERIA_H

#include <iostream>
#include <string.h>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {

    protected:

        std::string _type;

    public: 

        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria &old);
        AMateria& operator=(const AMateria &old);
        virtual ~AMateria();

        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
