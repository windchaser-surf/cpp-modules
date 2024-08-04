#include "MutantStack.hpp"
#include <list>
#include <vector>

//shows that pop set the end() 
void testMutant() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Stack top = " << mstack.top() << std::endl << std::endl;

    mstack.pop();

    std::cout << "Stack size = " << mstack.size() << std::endl << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(123);
    mstack.push(45);
    mstack.push(897);
    mstack.push(78);
    mstack.push(36);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    if (it == ite)
        std::cout << "Size of stack = 1" << std::endl << std::endl;
    else if (it != ite)
        std::cout << "Size of stack = " << mstack.size() << std::endl << std::endl;
    
    while (it != ite)
    {
    ite--;
    std::cout << "Mutant stack = " << *ite << std::endl;
    }
    
    std::stack<int> s(mstack);
    while (s.size() > 0) {

        std::cout << "Ori stack = " << s.top() << std::endl;
        s.pop();
    }
}

void testList() {

    std::list<int> lst; 

    lst.push_back(5);
    lst.push_back(17);

    std::cout << "list top = " << lst.back() << std::endl << std::endl;

    lst.pop_back();

    std::cout << "list size = " << lst.size() << std::endl << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(123);
    lst.push_back(45);
    lst.push_back(897);
    lst.push_back(78);
    lst.push_back(36);
    lst.push_back(0);


    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();

    ++it;
    --it;

    if (it == ite)
        std::cout << "Size of list = 1" << std::endl << std::endl;
    else if (it != ite)
        std::cout << "Size of list = " << lst.size() << std::endl << std::endl;
    
    while (it != ite)
    {
    ite--;
    std::cout << "List = " << *ite << std::endl;
    }
}

void testVec() {

    std::vector<int> vec; 

    vec.push_back(5);
    vec.push_back(17);

    std::cout << "Vector top = " << vec.back() << std::endl << std::endl;

    vec.pop_back();

    std::cout << "Vector size = " << vec.size() << std::endl << std::endl;

    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(737);
    vec.push_back(123);
    vec.push_back(45);
    vec.push_back(897);
    vec.push_back(78);
    vec.push_back(36);
    vec.push_back(0);


    std::vector<int>::iterator it = vec.begin();
    std::vector<int>::iterator ite = vec.end();

    ++it;
    --it;

    if (it == ite)
        std::cout << "Size of vector = 1" << std::endl << std::endl;
    else if (it != ite)
        std::cout << "Size of vector = " << vec.size() << std::endl << std::endl;
    
    while (it != ite)
    {
    ite--;
    std::cout << "Vector = " << *ite << std::endl;
    }
}

int main()
{
   	std::cout << "\n-------------Test Mutant-----------------\n" << std::endl;
    testMutant();
   	std::cout << "\n-------------Test List-----------------\n" << std::endl;
    testList();
   	std::cout << "\n-------------Test Vector-----------------\n" << std::endl;
    testVec();
    return 0;
}
