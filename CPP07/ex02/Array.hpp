#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>
#include <ctime>
#include <cstdlib>

template <class T>
class Array {

	private: 

		T *_array;
		size_t _n;

	public: 
	Array();
	Array(size_t n);
	Array(const Array<T>& old);
	Array& operator=(const Array<T>& old);
	~Array();

	T& operator[](unsigned int index);
	size_t size() const;

	class IndexTooHigh : public std::exception {
		const char* what() const throw();
	};
};

template <class T> 
Array<T>::Array() : _array(new T()), _n(0) {

}

template <class T>
Array<T>::Array(size_t n) {
	
	_n = n;
	_array = new T[n];
	for (size_t i = 0; i < n; i++)
	{
		_array[i] = T();
	}
}

template <class T> 
Array<T>::Array(const Array<T>& old) {

	_n = old._n;
	_array = new T[_n];
	for (size_t i = 0; i < _n; i++)
	{
		_array[i] = old._array[i];
	}
	
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& old) {

	if (this != &old){
		if (_array != NULL)
			delete _array;
		_n = old._n;
		_array = new T[_n];
		for (size_t i = 0; i < _n; i++)
		{
			_array[i] = old._array[i];
		}
	}
	return (*this);
}

template <class T>
const char* Array<T>::IndexTooHigh::what() const throw() {
	return ("Index is out of range!");
}

template <class T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _n)
		throw IndexTooHigh();
	return (_array[index]);
}

template <class T>
size_t Array<T>::size() const {

	return (_n);
}

template <class T>
Array<T>::~Array() {

	delete[] _array;
}

#endif // !ARRAY_H
