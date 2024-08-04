#ifndef SPAN_H
# define SPAN_H

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

class Span
{
    public:

        Span(void);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        Span(unsigned int n);
        void addNumber(int n);
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void printVector() ;
        void addMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    private:

        std::vector<int> _vec;
        unsigned int _maxSize;
};

#endif // !SPAN_H
