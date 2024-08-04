#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>
#include <string.h>
#include <sstream>

class Brain {

	private: 
		
		std::string* ideas;

	public: 

		Brain();
		Brain(const Brain& old);
		Brain &operator=(const Brain& old); 
		~Brain();
		void	setBrain(std::string newBrain);
		std::string* getIdeas() const;

};

#endif
