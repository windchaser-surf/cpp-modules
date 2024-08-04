#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

	private: 

		Brain *brain;

	public: 

		Dog();
		Dog(const Dog& old);
		Dog &operator=(const Dog& old); 
		~Dog();
		Brain*	getBrain() const;
		void	setBrain(std::string newIdea);
		void	makeSound() const;
};

#endif
