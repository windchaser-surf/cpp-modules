#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
/* 
    std::cout << "\033[32m" << "Correct version with virtual makeSound()" << "\033[0m" << std::endl;

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
    
    
    std::cout << std::endl; */


        //BESSERE MAIN NOCHMAL SCHREIBEN UND RUMSPIELEN SODASS ALLE TEST VISUELL SCHÖN DARGESTELLT WERDEN!!!! 



    std::cout << "\033[32m" << "Before setBrain()" << "\033[0m" << std::endl << std::endl;

    Cat* cat1 = new Cat; 
    Cat cat2 = *cat1;
    Cat cat3;
    Brain* brain1; 
    Brain* brain2;
    Brain* brain3;
    Brain* brainanimal;

    Animal* animal1 = new Cat();

    brain1 = cat1->getBrain();
    brain2 = cat2.getBrain();
    
    cat3 = cat2; 


    cat1->setBrain("NewIDEA1");

    std::cout << "\033[32m" << "After setBrain()" << "\033[0m" << std::endl << std::endl;
    
    brain1= cat1->getBrain();
    brain2 = cat2.getBrain();
    brain3 = cat3.getBrain();
    brainanimal = ((Cat *)animal1)->getBrain();


    for (int i = 0; i < 100; i++)
        std::cout << brain1->getIdeas()[i] << std::endl;
    for (int i = 0; i < 100; i++) 
        std::cout << brain2->getIdeas()[i] << std::endl;
    for (int i = 0; i < 100; i++) 
        std::cout << brain3->getIdeas()[i] << std::endl; 
    for (int i = 0; i < 100; i++) 
        std::cout << brainanimal->getIdeas()[i] << std::endl;

    delete cat1;
    delete animal1;
    return 0;
}
