#ifndef EASYFIND_H
# define EASYFIND_H

#include <iostream>
#include <exception>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int& find) 
{
	typename T::iterator it = std::find(container.begin(), container.end(), find);
	if (it == container.end())
		throw std::runtime_error("Not found");
	return (it);
}

template <typename T>
typename T::const_iterator easyfind(const T& container, const int& find) 
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), find);
	if (it == container.end())
		throw std::runtime_error("Not found");
	return (it);
}

#endif // !EASYFIND_H
