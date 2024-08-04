#include "Brain.hpp"

Brain::Brain() {

	
	ideas = new(std::string[100]);
	for (int i = 0; i < 100; i++)
	{
		std::stringstream ss;
		ss << i + 1;
		ideas[i] = "idea " + ss.str();
	}
	std::cout << "Default constructor Brain called" << std::endl; 
}


Brain& Brain::operator=(const Brain& old) {

	std::cout << "Overload operator \"=\" Brain called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = old.ideas[i] + " copy ";
	}
	
	return (*this); 
}

Brain::Brain(const Brain &old) {

	std::cout << "Copy constructor Brain called" << std::endl;
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = old.ideas[i] + " copy ";
	}
}

std::string*	Brain::getIdeas() const {

	return (ideas);
}

void	Brain::setBrain(std::string newBrain) {

	
	for (int i = 0; i < 100; i++)
	{
		std::stringstream ss;
		ss << i + 1;
		ideas[i] = newBrain + ss.str();
	}
	
}


Brain::~Brain() {

	delete [] ideas;
	std::cout << "Deconstructor Brain called" << std::endl;
}
