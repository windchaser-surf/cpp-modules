#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {

    private : 

        std::string _target;
        RobotomyRequestForm();

    public :

        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& old);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& old);
        ~RobotomyRequestForm();
        virtual void    execute(const Bureaucrat& executer) const;
};

#endif
