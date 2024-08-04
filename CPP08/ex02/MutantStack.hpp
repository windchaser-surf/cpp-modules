#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack <T>
{
    public:

        MutantStack(void);
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        typedef  typename std::stack <T>::container_type::iterator iterator;
        iterator begin();
        iterator end();

    private:

};

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) : std::stack<T>(other){
    
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& old) {

    if (this != &old)
        std::stack<T>::operator=(old);
    return (*this);
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin() {

    return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end() {

    return (this->c.end());
}

template <typename T>
MutantStack<T>::~MutantStack() {}

#endif // !MUTANTSTACK_H
