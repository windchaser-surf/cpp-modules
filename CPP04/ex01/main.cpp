#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


void    testCaseOne() 
{
    //Main like in subjects!!! 
    Animal* animals[10];

    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            animals[i] = new Dog();
        else 
            animals[i] = new Cat();
    }

    for (int i = 0; i < 10; i++)
    {
        animals[i]->makeSound();
    }
    
    for (int i = 0; i < 10; i++)
    {
        delete animals[i];
    }
    
    std::cout << std::endl;
}

void    testCaseTwo() 
{
    //Check if it is a deepCopy!!!
    
    std::cout << "\n\n\033[32m" << "Before setBrain()" << "\033[0m" << std::endl << std::endl;

    Cat* cat1 = new Cat; 
    Cat cat2 = *cat1;
    Cat cat3;

    Brain* brain1; 
    Brain* brain2;
    Brain* brain3;

    brain1 = cat1->getBrain();
    brain2 = cat2.getBrain();

    cat3 = cat2;

    brain3 = cat3.getBrain();

    for (int i = 0; i < 100; i++)
        std::cout << brain1->getIdeas()[i] << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < 100; i++) 
        std::cout << brain2->getIdeas()[i] << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < 100; i++) 
        std::cout << brain3->getIdeas()[i] << std::endl; 
    std::cout << "---------------------------------------------" << std::endl;

    cat3.setBrain("cat3 Idea");
    cat1->setBrain("cat1 Idea");
    cat2.setBrain("cat2 Idea");

    std::cout << "\033[32m" << "After setBrain()" << "\033[0m" << std::endl << std::endl;
    
    brain1= cat1->getBrain();
    brain2 = cat2.getBrain();
    brain3 = cat3.getBrain();

    for (int i = 0; i < 100; i++)
        std::cout << brain1->getIdeas()[i] << std::endl;
    std::cout << "---------------------------------------------" << std::endl;    
    for (int i = 0; i < 100; i++) 
        std::cout << brain2->getIdeas()[i] << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < 100; i++) 
        std::cout << brain3->getIdeas()[i] << std::endl; 

    delete cat1;    
}

int main()
{

    testCaseOne();
    testCaseTwo();

    return 0;
}
