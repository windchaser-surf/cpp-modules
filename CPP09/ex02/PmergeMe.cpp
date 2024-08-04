#include "PmergeMe.hpp"


//int g_compare = 0;
/////////////////////////////////////////////////////////
/////////////////////VECTOR//////////////////////////////
/////////////////////////////////////////////////////////

///////////////////////////STRUCT FUNCTIONS////////////////////////////////////

bool Block::operator<(const Block& other) const
{
	return *this->begin < *other.begin;
}

bool Block::operator>(const Block& other) const
{
	return *this->begin > *other.begin;
}

bool Block_d::operator<(const Block_d &other) const
{
    return *this->begin < *other.begin;
}

bool Block_d::operator>(const Block_d &other) const
{
    return *this->begin > *other.begin;
}
///////////////////////////CHECKER FUNCTIONS////////////////////////////////////

static void checkInput(std::string& str)
{
	if (str.empty())
		throw std::runtime_error("Error: Empty string");

	if (str.find_first_not_of("0123456789 ") != std::string::npos)
		throw std::runtime_error("Error: Invalid character");
}

template<typename Container>
void	checkSorted(Container checker)
{
	for (size_t i = 1; i < checker.size(); i++)
	{
		if (checker.at(i - 1) > checker.at(i)){
			std::cout <<"FUCK!!!!" << std::endl;
			std::cout << i << std::endl;
			return;
		}
	}
	//std::cout << "Congrates" << std::endl;
}

///////////////////////////CONVERSION FUNCTIONS////////////////////////////////////

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

static std::deque<int> strToDeque(std::string str)
{
	std::deque<int> vec;

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

std::vector<std::pair<Block, Block> > createPairedVec(std::vector<int>& input, int block)
{
	std::vector<std::pair<Block, Block> > vecPaired;
	Block block1;
	Block block2;
	size_t iterSize = input.size() / (block * 2);

	for (size_t i = 0; i < iterSize; i++)
	{
		block1.begin = input.begin() + i * block * 2;
		block1.end = block1.begin + block;
		block2.begin = block1.end;
		block2.end = block2.begin + block;
		vecPaired.push_back(std::make_pair(block1, block2));
	}
	if ((input.size() / block) % 2)
	{
		block2.begin = input.begin() + (iterSize * 2 * block);
		block2.end = block2.begin + block;
		block1.begin = input.end();
		block1.end = input.end();
		vecPaired.push_back(std::make_pair(block1, block2));
	}
	return (vecPaired);
}

std::deque<std::pair<Block_d, Block_d> > createPairedDeq(std::deque<int>& input, int block)
{
	std::deque<std::pair<Block_d, Block_d> > deqPaired;
	Block_d block1;
	Block_d block2;
	size_t iterSize = input.size() / (block * 2);

	for (size_t i = 0; i < iterSize; i++)
	{
		block1.begin = input.begin() + i * block * 2;
		block1.end = block1.begin + block;
		block2.begin = block1.end;
		block2.end = block2.begin + block;
		deqPaired.push_back(std::make_pair(block1, block2));
	}
	if ((input.size() / block) % 2)
	{
		block2.begin = input.begin() + (iterSize * 2 * block);
		block2.end = block2.begin + block;
		block1.begin = input.end();
		block1.end = input.end();
		deqPaired.push_back(std::make_pair(block1, block2));
	}
	return (deqPaired);
} 

///////////////////////////UTILS////////////////////////////////////

long	Jacobsthal(size_t n)
{
	return ((pow(2, n) - pow(-1, n)) / 3);
}

template<typename T>
void printContainer(T& container, size_t size)
{
	if (size <= 5)
		for (size_t i = 0; i < size; i++)
			std::cout << container.at(i) << " ";
	else
	{
		for (size_t i = 0; i < 4; i++)
		{
			std::cout << container.at(i) << " ";
		}
		std::cout << "[...]";
	}
	std::cout << "\n";
}

void printElapTime(timespec const& start, timespec const& end, size_t size, int container)
{
		if (container == 0)
			std::cout << "Time to process a range of " << size << " elements with std::vector<int>: ";
		else if (container == 1)
			std::cout << "Time to process a range of " << size << " elements with std::deque<int>: ";
		double elapsedTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;
		std::cout << elapsedTime;
		std::cout << " us" << std::endl;	
}

template <typename T>
void printResult(T& unsortCon, T& sortCon, TimeStamp& times)
{
		std::cout << "Before:	";
		printContainer(unsortCon, unsortCon.size());
		std::cout << "After:	";
		printContainer(sortCon, sortCon.size());
		printElapTime(times.startVec, times.endVec, unsortCon.size(), 0);
		printElapTime(times.startDe, times.endDe, unsortCon.size(), 1);

}

///////////////////////////SORT ALGORITHM////////////////////////////////////

void sortPairedVec(std::vector<std::pair<Block, Block> >& vecPaired, std::vector<int>& input)
{
	(void)input;
	for (size_t i = 0; i < vecPaired.size(); i++)
	{
		if (vecPaired.at(i).first.begin == input.end())
			continue;
		//g_compare++;
		if (vecPaired.at(i).first < vecPaired.at(i).second)
		{
			std::pair<Block, Block>& pair = vecPaired.at(i);
			for (size_t x = 0; x < (size_t)(pair.first.end - pair.first.begin); x++)
			{
				std::swap(*(pair.first.begin + x), *(pair.second.begin + x));
			}
		}
	}
}

void sortPairedDeq(std::deque<std::pair<Block_d, Block_d> >& deqPaired, std::deque<int>& input)
{
	// (void)input;
	for (size_t i = 0; i < deqPaired.size(); i++)
	{
		if (deqPaired.at(i).first.begin == input.end())
			continue;
		//pare++;
		if (deqPaired.at(i).first < deqPaired.at(i).second)
		{
			std::pair<Block_d, Block_d>& pair = deqPaired.at(i);
			for (size_t x = 0; x < (size_t)(pair.first.end - pair.first.begin); x++)
			{
				std::swap(*(pair.first.begin + x), *(pair.second.begin + x));
			}
		}
	}
}

template<typename Container>
int binarySearch(Container& main, int value, int index)
{
	int start = 0;
	int end = index;
	int mid = 0;
	bool isSmaller;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		//g_compare++;
		if (mid == (int)main.size())
			return (mid);
		isSmaller = value < *main.at(mid).begin;
		if (isSmaller)
			end = mid - 1;
		else
			start = mid + 1;
	}
	if (!isSmaller)
		mid++;
	return (mid);
}

template<typename Container>
void	insert(Container& input, Block block, Container start)
{
	Container save(block.begin, block.end);
	input.erase(block.begin, block.end);
	input.insert(start, save.begin(), save.end());	
}

void	insertion(std::vector<Block>& main, std::vector<Block>& pend, std::vector<int>& input)
{
	main.insert(main.begin(), pend.at(0));
	size_t block = main.at(0).end - main.at(0).begin;
	size_t n_insert = 3;
	size_t lower = 1;
	size_t added = 1;
	size_t jacob_n = Jacobsthal(n_insert);
	if (jacob_n >= pend.size()) 
			jacob_n = pend.size();
	while (lower < pend.size())
	{
		while (jacob_n > lower)
		{
			int index = binarySearch(main, *pend.at(jacob_n - 1).begin, (jacob_n - 1) + added - 1);
			main.insert(main.begin() + index, pend.at(jacob_n - 1));
			added++;
			jacob_n--;
		}
		lower = Jacobsthal(n_insert++);
		jacob_n = Jacobsthal(n_insert);
		if (jacob_n >= pend.size()) 
				jacob_n = pend.size();;
	}
	std::vector<int> newInput;
	for (size_t i = 0; i < main.size(); i++)
	{
		newInput.insert(newInput.end(), main.at(i).begin, main.at(i).end);
	}
	newInput.insert(newInput.end(), input.begin() + main.size() * block, input.end());

	input = newInput;
}

void	insertion_d(std::deque<Block_d>& main, std::deque<Block_d>& pend, std::deque<int>& input)
{
	main.insert(main.begin(), pend.at(0));
	size_t block = main.at(0).end - main.at(0).begin;
	size_t n_insert = 3;
	size_t lower = 1;
	size_t added = 1;
	size_t jacob_n = Jacobsthal(n_insert);
	if (jacob_n >= pend.size()) 
			jacob_n = pend.size();
	while (lower < pend.size())
	{
		while (jacob_n > lower)
		{
			int index = binarySearch(main, *pend.at(jacob_n - 1).begin, (jacob_n - 1) + added - 1);
			main.insert(main.begin() + index, pend.at(jacob_n - 1));
			added++;
			jacob_n--;
		}
		lower = Jacobsthal(n_insert++);
		jacob_n = Jacobsthal(n_insert);
		if (jacob_n >= pend.size()) 
				jacob_n = pend.size();;
	}
	std::deque<int> newInput;
	for (size_t i = 0; i < main.size(); i++)
	{
		newInput.insert(newInput.end(), main.at(i).begin, main.at(i).end);
	}
	newInput.insert(newInput.end(), input.begin() + main.size() * block, input.end());

	input = newInput;
}

void FordJohnson(std::vector<int>& input, size_t steps)
{
	size_t block = 1 << steps;
	if (input.size() < (block * 2))
		return;

	std::vector<std::pair<Block, Block> > vecPaired = createPairedVec(input, block);
	sortPairedVec(vecPaired, input);
	FordJohnson(input, steps + 1);

	std::vector<Block> main;
	std::vector<Block> pend;

	block = 1 << (steps + 1);
	for (size_t i = 0; i < vecPaired.size(); i++)
	{
		if (vecPaired.at(i).first.begin != input.end())
			main.push_back((vecPaired.at(i).first));
		pend.push_back((vecPaired.at(i).second));

	}
	insertion(main, pend, input);
}

void FordJohnson_d(std::deque<int>& input, size_t steps)
{
	size_t block = 1 << steps;
	if (input.size() < (block * 2))
		return;

	std::deque<std::pair<Block_d, Block_d> > deqPaired = createPairedDeq(input, block);
	sortPairedDeq(deqPaired, input);
	FordJohnson_d(input, steps + 1);

	std::deque<Block_d> main;
	std::deque<Block_d> pend;

	block = 1 << (steps + 1);
	for (size_t i = 0; i < deqPaired.size(); i++)
	{
		if (deqPaired.at(i).first.begin != input.end())
			main.push_back((deqPaired.at(i).first));
		pend.push_back((deqPaired.at(i).second));

	}
	insertion_d(main, pend, input);
}


void PmergeMe(std::string str)
{
    TimeStamp times;
	std::vector<int> input;
	std::deque<int> input_d;
	std::vector<int> unsortVec;

	{
    clock_gettime(CLOCK_MONOTONIC, &times.startVec);
	input = strToVector(str);
	unsortVec = input;
	FordJohnson(input, 0);
	clock_gettime(CLOCK_MONOTONIC, &times.endVec);
	checkSorted(input);
	}
	//std::cout << g_compare << std::endl;
	//g_compare = 0;
	{
	    clock_gettime(CLOCK_MONOTONIC, &times.startDe);
		checkInput(str);
		input_d = strToDeque(str);
		FordJohnson_d(input_d, 0);
		clock_gettime(CLOCK_MONOTONIC, &times.endDe);
		checkSorted(input_d);
	}
	//std::cout << g_compare << std::endl;
	printResult(unsortVec, input, times);
}


