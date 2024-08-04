#ifndef AFORM_H
# define AFORM_H

#include <iostream>
#include <string.h>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private: 

		std::string const	_name;
		bool				_signed;
		const int 			_signedGrade; 
		const int			_execGrade;
		AForm();

	public:
		AForm(std::string const _name, int const signedGrade, int const execGrade);
		AForm(const AForm& old);
		AForm& operator=(const AForm& old);
		virtual ~AForm();
		std::string		getName() const; 
		bool			getSigned() const; 
		int				getSignedGrade() const; 
		int				getExecGrade() const; 
		void			beSigned(Bureaucrat& bureaucrat);
		void			checkRequirements(const Bureaucrat& executer) const;
		virtual void	execute(const Bureaucrat& executer) const = 0;
		class GradeTooHighException : public std::exception {

			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {

			const char* what() const throw();
		};
		class GradeNotSigned : public std::exception {

			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
