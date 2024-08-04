#ifndef ICE_H
# define ICE_H

#include <iostream>
#include <string.h>
#include "AMateria.hpp"

class Ice : public AMateria {

	public: 
		Ice();
		Ice(const Ice &old);
		Ice& operator=(const Ice &old);
		~Ice();
		AMateria* clone() const;
		void use(ICharacter& target);
		
};

#endif
