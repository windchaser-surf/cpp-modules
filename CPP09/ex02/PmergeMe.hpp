#ifndef PMERGEME_H
# define PMERGEME_H

#include <string>
#include <iostream>
#include <vector>
#include <limits>
#include <stdlib.h>
#include <deque>
#include <time.h>
#include <iomanip>
#include <math.h>

struct TimeStamp
{
    timespec startVec;
    timespec endVec;
    timespec startDe;
    timespec endDe;
};

struct Block {

    std::vector<int>::iterator begin; 
    std::vector<int>::iterator end;

    bool operator<(const Block& other) const;
    bool operator>(const Block&) const;
};

struct Block_d {

    std::deque<int>::iterator begin; 
    std::deque<int>::iterator end;

    bool operator<(const Block_d& other) const;
    bool operator>(const Block_d&) const;
};

long	Jacobsthal(size_t n);
void    PmergeMe(std::string str);


#endif // !PMERGEME_H
