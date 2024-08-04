#ifndef WHATEVER_H
# define WHATEVER_H

#include <iostream>

template <typename T>
void swap(T &x, T &y)
{
    T tmp = x;
    x = y; 
    y = tmp;
}

template <typename T>
T min(T &x, T &y)
{
    if (x == y)
        return y;
    return x < y ? x : y;
}

template <typename T>
T max(T &x, T &y)
{
    return y >= x ? y : x;
}

#endif
