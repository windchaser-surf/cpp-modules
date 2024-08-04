#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {

    private : 

        std::string _target;
        ShrubberyCreationForm();

    public :

        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& old);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& old);
        ~ShrubberyCreationForm();
        virtual void    execute(const Bureaucrat& executer) const;
        void            createFile() const;
        
        class FileNotOpened : public std::exception {

			const char* what() const throw();
		};
};

#endif
