#ifndef INTERN_H
# define INTERN_H

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;
class PresidentialPardonForm;
class RobotomyRequestForm; 
class ShrubberyCreationForm;
 

class Intern {

    private: 

        AForm* _returnShrubberyCreationForm(const std::string& target);
        AForm* _returnRobotomyRequestForm(const std::string& target);
        AForm* _returnPresidentialPardonForm(const std::string& target);

    public:

        Intern();
        Intern(const Intern& old); 
        Intern& operator=(const Intern& old); 
        ~Intern();
        typedef AForm* (Intern::*FormCreator)(const std::string& target);
        AForm* makeForm(const std::string& name, const std::string& target);
        class FormNotFound : public std::exception {
            const char* what() const throw();
        };
};

#endif
