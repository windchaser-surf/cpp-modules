#ifndef FORM_H
# define FORM_H

#include <iostream>
#include <string.h>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private: 

		std::string const	_name;
		bool				_signed;
		const int 			_signedGrade; 
		const int			_execGrade;
		Form();

	public:
		Form(std::string const _name, int const signedGrade, int const execGrade);
		Form(const Form& old);
		Form& operator=(const Form& old);
		~Form();
		const std::string&	getName() const; 
		bool				getSigned() const; 
		const int&			getSignedGrade() const; 
		const int&			getExecGrade() const; 
		void				beSigned(Bureaucrat& bureaucrat); 
		class GradeTooHighException : public std::exception {

			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {

			const char* what() const throw();
		}; 
};

std::ostream& operator<<(std::ostream& os, const Form& form);


#endif
