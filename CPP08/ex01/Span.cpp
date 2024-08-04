#include "Span.hpp"

Span::Span() : _maxSize(0) {

}

Span::Span(unsigned int n) : _maxSize(n) {

}


//test me
Span::Span(const Span& old) {

	_maxSize = old._maxSize;
	_vec = old._vec;
}

Span& Span::operator=(const Span& old) {

	if (this != &old){

		_maxSize = old._maxSize;
		_vec = old._vec;
	}
	return (*this);
}


void Span::addNumber(int n) {

	if (_vec.size() == _maxSize)
		throw std::runtime_error("Vector has already max size!");
	_vec.push_back(n);
}



void Span::printVector() {

	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	
}

unsigned int Span::longestSpan() {

	if (_vec.size() < 2)
		throw std::runtime_error("Vector is too small for calc the span!");
	std::sort(_vec.begin(), _vec.end());
	return(_vec.back() - _vec.front());
}

unsigned int Span::shortestSpan() {

	if (_vec.size() < 2)
		throw std::runtime_error("Vector is too small for calc the span!");
	unsigned int shortestDistance = 0;	
	std::sort(_vec.begin(), _vec.end());
	shortestDistance = _vec.back() - _vec.front();
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end() - 1; ++it)
	{
		if (shortestDistance > (unsigned int)abs((*(it + 1) - *it)))
			shortestDistance = *(it + 1) - *it;
	}
	return (shortestDistance);
	
}

void Span::addMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {

	if (std::distance(begin, end) + _vec.size() > _maxSize)
		throw std::runtime_error("Vector is too big to Add");
	_vec.insert(_vec.end(), begin, end);
}

Span::~Span() {

}
