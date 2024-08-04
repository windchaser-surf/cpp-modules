#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {

    private : 

        std::string _target;
        PresidentialPardonForm();

    public :

        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& old);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& old);
        ~PresidentialPardonForm();
        virtual void    execute(const Bureaucrat& executer) const;
};

#endif
