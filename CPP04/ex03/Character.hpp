#ifndef CHARACTER_H
# define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"

class AMateria;

class Character : public ICharacter {
	
	private:
		std::string _name;
		AMateria* _inventory[4];
	
	public: 
		Character();
		Character(std::string name);
		Character(const Character &old);
		Character& operator=(const Character &old);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria* getMemAdr(int idx);
		
};

#endif
