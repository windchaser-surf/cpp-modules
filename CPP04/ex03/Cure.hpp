#ifndef CURE_H
# define CURE_H

#include <iostream>
#include <string.h>
#include "AMateria.hpp"

class Cure : public AMateria {

	public: 
		Cure();
		Cure(const Cure &old);
		Cure& operator=(const Cure &old);
		~Cure();
		AMateria* clone() const;
		void use(ICharacter& target);
		
};

#endif
