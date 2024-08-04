#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <string.h>
#include <stdexcept>

class Bureaucrat {

	private: 

		const std::string   _name; 
		int                 _grade;
		Bureaucrat(); 

	public: 

		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& old);
		Bureaucrat& operator=(const Bureaucrat& old);
		~Bureaucrat();
		void	IncrementGrade(); 
		void	DecrementGrade();
		const std::string&	getName() const; 
		int		getGrade() const; 
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
