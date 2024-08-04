#include "RPN.hpp"

static bool isOperator(const int& c)
{
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return (true);
	return (false);
}

static void calcOperator(std::stack<int>& stack, const int& c) {

	if (stack.size() < 2)
		throw std::runtime_error("Error: invalid format");

	long val2 = stack.top();
	stack.pop();
	long val1 = stack.top();
	stack.pop();
	long tmp = 0;

	if (c == '*')
		tmp = val1 * val2;
	else if (c == '/') {
		if (val2 == 0)
			throw std::runtime_error("Error: divided by 0!");
		tmp = val1 / val2;
	}
	else if (c == '+')
		tmp = val1 + val2;
	else if (c == '-')
		tmp = val1 - val2;
	if (tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min())
		throw std::runtime_error("Error: int overflow!");
	stack.push(tmp);
}

static void printStack(std::stack<int>& stack)
{
	if (stack.size() != 1)
		throw std::runtime_error("Error: Invalid format");
	std::cout << stack.top() << std::endl;
}

void calcRpn(std::string arg)
{
	std::stack<int> stack;

	if (arg.empty())
		throw std::runtime_error("Error: empty!");
	if (arg.find_first_not_of("-*+/0123456789 ") != std::string::npos)
		throw std::runtime_error("Error: Invalid character");
	for (size_t i = 0; i < arg.length(); i++)
	{
		if (isOperator(arg.at(i)))
		{
			calcOperator(stack, arg.at(i));
			if (i + 1 < arg.length() && arg.at(i + 1) != ' ')
				throw std::runtime_error("Error: invalid format!");
		}
		if (std::isdigit(arg.at(i)) && (i + 1 < arg.length() && arg.at(i + 1) != ' '))
			throw std::runtime_error("Error: invalid number!");
		else if (std::isdigit(arg.at(i)))
			stack.push(arg.at(i) - 48);
	}
	printStack(stack);
}
