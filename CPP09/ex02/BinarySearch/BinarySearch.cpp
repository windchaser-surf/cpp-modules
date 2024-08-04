#include <string>
#include <iostream>
#include <vector>
#include <limits>
#include <stdlib.h>
#include <deque>
#include <time.h>
#include <iomanip>

static std::vector<int> strToVector(std::string str)
{
	std::vector<int> vec;

	while (str.length() != 0)
	{
		if (str.at(0) == ' ')
		{
			str.erase(0, 1);
			continue;
		}
		size_t length = str.find(' ');
		if (length == std::string::npos)
			length = str.length();
		if (length > 10)
			throw std::runtime_error("Error: int overflow");
		long tmp = strtol(str.c_str(), NULL, 10);
		if (tmp > std::numeric_limits<int>::max())
			throw std::runtime_error("Error: int overflow");
		vec.push_back(static_cast <int> (tmp));
		str.erase(0, length);
	}
	return (vec);
}

void    printVector(std::vector<int> vec, int start, int end)
{
    for (std::vector<int>::iterator it = vec.begin() + start; it != vec.begin() + end + 1; it++)
    {
        std::cout << *it << std::endl;
    }
}

int binarySearch(std::vector<int> vec, int value, int index)
{
    int start = 0; 
    int end = index;
    if (end >= vec.size())
        end = vec.size() - 1;
    size_t mid = 0;
    while (start <= end)
    {
        printVector(vec, start, end);
        mid = start + (end - start) / 2;
        std::cout << " vec[" << mid << "] = " << vec.at(mid) << std::endl;
        std::cout << "mid = " << mid << std::endl;
        if (value < vec.at(mid))
        {
            end = mid - 1;

        }
        else
        {
            start = mid + 1;
        }
        std::cout << "start: vec[" << start << "] = " << vec.at(start)<<  std::endl;
        std::cout << "end: vec[" << end << "]" << vec.at(end) << std::endl;
        std::cout << "---------------------------------\n\n";
    }
    return (mid);
}


int main (int argc, char **argv)
{
    if (argc != 3)
        return (std::cout << "Error too less args!" << std::endl, 1);
    std::vector<int> vec;

    int value = atoi(argv[2]);
    vec = strToVector(argv[1]);
    int index = binarySearch(vec, value, vec.size() - 2);
    vec.insert(vec.begin() + index, value);

    std::cout << "Index = " << index << "\n" << std::endl;
    std::cout << "-----------FINISH---------------" << std::endl;
    printVector(vec, 0, vec.size() - 1);
 
    return (0);    
}
