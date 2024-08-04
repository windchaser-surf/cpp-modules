#include "iter.hpp"

void testFunc(int &x)
{
    int y = 3; 
    std::cout << "3 + " << x << " = " << x + y << std::endl; 
}

void testFunc(float &x)
{
    float y = 3.5; 
    std::cout << "3.5 + " << x << " = " << x + y << std::endl; 
}

void testFunc(std::string &x)
{
    std::string y = "Hallo"; 
    std::cout  << y << " " << x << std::endl; 
}

void testFunc(const std::string &x)
{
    std::string y = "Hallo"; 
    std::cout  << y << " " << x << std::endl; 
}

class Animal {

    public: 
        std::string name;
        
};

class Dog : public Animal {

    public: 
        Dog() : Animal() {name = "Dog";};
};

class Cat : public Animal {

    public: 
        Cat() : Animal() {name = "Cat";};
};

class Monkey : public Animal {

    public: 
        Monkey() : Animal() {name = "Monkey";};
};

void testFunc(Animal &animals) {

    std::cout << "Hallo " << animals.name << std::endl; 
}

int main() {

    int array[] = {5, 4, 3, 2, 1};
    float array2[] = {5.5, 4.4, 3.3, 2.2, 1.1};
    std::string array3[] = {"Franz", "Josef", "Hubert", "Roswita", "Helga"};
    const std::string array4[] = {"Franz", "Josef", "Hubert", "Roswita", "Helga"};
    Animal animals[] = {Dog(), Cat(), Monkey()};

    iter(array, 5, testFunc);
    std::cout << std::endl;
    iter(array2, 5, testFunc);
    std::cout << std::endl;
    iter(array3, 5, testFunc);
    std::cout << std::endl;
    iter(array4, 5, testFunc);
    std::cout << std::endl;
    iter(animals, 3, testFunc);

    return (0);
}
