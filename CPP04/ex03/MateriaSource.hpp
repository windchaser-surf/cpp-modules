#ifndef MATERIALSOURCE_H
# define MATERIALSOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	
	private:
		AMateria* _materia[4];
	
	public: 
		MateriaSource();
		MateriaSource(const MateriaSource &old);
		MateriaSource& operator=(const MateriaSource &old);
		~MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
