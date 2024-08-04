#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <string.h>
#include <stdexcept>
#include "Form.hpp"

class Form; 

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
		void		signForm(Form& form);
		void        IncrementGrade(); 
		void        DecrementGrade();
		const std::string& getName() const; 
		int         getGrade() const;
		class GradeTooHighException : public std::exception {

			const char* what() const throw() {
				return ("Unfortunately, grade too high!!!");            }
		};
		class GradeTooLowException : public std::exception {

			const char* what() const throw() {
				return("Unfortunately, grade too low ;(");
			}
		};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

// " << " Operator implement!

#endif
