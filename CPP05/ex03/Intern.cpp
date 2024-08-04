#include "Intern.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern& old) {

    if (this == &old)
        return ;
}

Intern& Intern::operator=(const Intern &old) {

    if (this == &old)
        return (*this);
    return (*this);
}

AForm* Intern::_returnShrubberyCreationForm(const std::string& target) {

    return (new ShrubberyCreationForm(target));
}

AForm* Intern::_returnRobotomyRequestForm(const std::string& target) {

    return (new RobotomyRequestForm(target));
}

AForm* Intern::_returnPresidentialPardonForm(const std::string& target) {

    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string &name, const std::string &target) {
    
    FormCreator formCreators[] = {

        &Intern::_returnShrubberyCreationForm,
        &Intern::_returnRobotomyRequestForm,
        &Intern::_returnPresidentialPardonForm
    };
    
    std::string formNames[] = {

        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (size_t i = 0; i < 3; i++)
    {
        if (name == formNames[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    throw FormNotFound();
    return (NULL);
}

const char* Intern::FormNotFound::what() const throw() {

    return ("Form not found!!");
}

Intern::~Intern() {

}
