#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{

    std::cout << "\033[32m" << "Correct version with virtual makeSound()" << "\033[0m" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    std::cout << std::endl; 
    std::cout << "\033[32m" << "Incorrect Version without virtual" << "\033[0m" << std::endl << std::endl;
    
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();
    std::cout << wrongI->getType() << " " << std::endl;
    std::cout << wrongMeta->getType() << " " << std::endl;

    wrongI->makeSound(); //will output the cat sound!
    wrongMeta->makeSound();

    delete meta;
    delete j; 
    delete i;

    delete wrongI;
    delete wrongMeta;

    return 0;
}
