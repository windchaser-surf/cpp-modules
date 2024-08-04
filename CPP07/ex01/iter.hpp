#ifndef ITER_H
# define ITER_H

#include <iostream>

template <typename T>
void iter(T *x, size_t len, void (*func)(T &x))
{
	for (size_t i = 0; i < len; i++)
	{
		func(x[i]);
	}
}

template <typename T>
void iter(const T *x, size_t len, void (*func)(const T &x))
{
	for (size_t i = 0; i < len; i++)
	{
		func(x[i]);
	}
}

#endif // !ITER_H
