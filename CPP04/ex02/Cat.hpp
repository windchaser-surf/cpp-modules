#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

	private:

		Brain *brain;
		
	public: 

		Cat();
		Cat(const Cat& old);
		Cat &operator=(const Cat& old); 
		~Cat();
		void	setBrain(std::string newIdea);
		Brain* getBrain() const ;
		void	makeSound() const;
};

#endif
