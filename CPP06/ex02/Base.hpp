#ifndef BASE_H
# define BASE_H

#include <iostream>
#include <ctime>
#include <cstdlib>

class Base {

public: 

    virtual ~Base();
    virtual Base* generate();
    virtual void identify(Base* p);
    virtual void identify(Base& p);

    class ClassNotFound : public std::exception {

        const char* what() const throw();
    };

private:

};

#endif
