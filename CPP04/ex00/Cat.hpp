#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"

class Cat : public Animal {

	private: 
	
	public: 

		Cat();
		Cat(const Cat& old);
		Cat &operator=(const Cat& old); 
		~Cat();
		void	makeSound() const;
};

#endif
