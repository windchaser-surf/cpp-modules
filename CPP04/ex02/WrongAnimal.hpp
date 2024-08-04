#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <iostream>
#include <string.h>

class WrongAnimal {

    protected: 
		
		std::string type;

	public: 

		WrongAnimal();
		WrongAnimal(const WrongAnimal& old);
		WrongAnimal &operator=(const WrongAnimal& old); 
		virtual ~WrongAnimal();
		void makeSound() const;
		std::string	getType() const;

};

#endif
