#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter& old) {

	if (this == &old)
		return ;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& old) {

	if (this == &old)
		return (*this);
	return (*this);
}

static bool isDigit(const std::string& literal) {

	for (size_t i = 0; i < literal.length(); i++)
	{
		if (literal[0] == '-' && i == 0)
			i++;
		if (literal[i] < '0' || literal[i] > '9')
			return (false);
	}
	return (true);
}

static bool checkOctal(const std::string& literal) {

	if (literal[0] == '-' && literal.length() > 2 && literal[1] == '0')
		return (true);
	if (literal[0] == '0' && literal.length() > 1)
		return (true);
	return (false);
}

////////////////////////////checker Functions////////////////////////////

static bool checkChar(const std::string& literal) {

	if (literal.length() != 1)
		return (false);
	else if (literal[0] >= '0' && literal[0] <= '9')
		return (false);
	return (true);
}

static bool checkInt(const std::string& literal) {

	if (literal.length() > 11)
		return (false);
	if (checkOctal(literal))
		return (false);
	else if (!isDigit(literal))
		return (false);
	else if (strtol(literal.c_str(), NULL, 10) > 2147483647 || \
			strtol(literal.c_str(), NULL, 10)  < -2147483648)
		return (false);
	return (true);
}

static bool checkFloat(const std::string& literal) {
	
    bool dotFound = false;
    bool fFound = false;
	bool plusFound = false;
	bool minusFound = false;

	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
		return true;
    if (literal[literal.length() - 1] != 'f' || literal == ".f")
		return false;
	else 
		fFound = true;
	if (literal[0] == '-')
		minusFound = true;
	if (literal[0] == '+')
		plusFound = true;
	for (size_t i = 0; i < literal.length(); i++)
	{
		if ((minusFound || plusFound) && i == 0)
			i++;
		if (literal[i] == '.') {
			if (dotFound == true)
				return false;
			dotFound = true;
		}
		if (literal[i] == 'f' && i + 1 < literal.length())
			return false;
		if (literal[i] != 'f' && literal[i]  != '.' \
			&& !isdigit(literal[i]))
			return false;
	}
	if (dotFound)
		return true;
	return (false);
}

static bool checkDouble(const std::string& literal) {

    bool dotFound = false;
	bool plusFound = false;
	bool minusFound = false;

	if (literal == "+inf" || literal == "-inf" || literal == "nan")
		return true;
	if (literal[0] == '-')
		minusFound = true;
	if (literal[0] == '+')
		plusFound = true;
	for (size_t i = 0; i < literal.length(); i++)
	{
		if ((minusFound || plusFound) && i == 0)
			i++;
		if (literal[i] == '.') {
			if (dotFound == true)
				return false;
			dotFound = true;
		}
		if (literal[i]  != '.' \
			&& !isdigit(literal[i]))
			return false;
	}
	if (dotFound)
		return true;
	return false;
}

////////////////////////////print Functions////////////////////////////

static void printChar(char c, int check) {

	if (check < -128 || check > 127)
		std::cout << "char: " << "impossible" << std::endl;
	else if (c <= 32 || c >= 127)
		std::cout << "char: " << "Non displayable" << std::endl;
	else 
		std::cout << "char: " << c << std::endl;
}

static void printInt(int n, long check) {

	if (check > std::numeric_limits<int>::max() || check < std::numeric_limits<int>::min())
		std::cout << "int: " << "impossible" << std::endl;
	else if (std::isinf(check) || std::isnan(check))
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << n << std::endl;
}

static void printFloat(float f) {

	if (std::isnan(f))
		std::cout << "float: nanf" << std::endl; 
	else if (std::isinf(f)) {
		
		if (f > 0)
			std::cout << "float: inff" << std::endl;
		else 
			std::cout << "float: -inff" << std::endl;
	}
	else {
		if (fabs(f - roundf(f)) < 0.000001)	
			std::cout << std::fixed << std::setprecision(1) << "float: " << f  << 'f' << std::endl;
		else 
			std::cout << std::fixed <<"float: " << f << 'f' << std::endl;
	}
}

////////////////////////////convert from Functions////////////////////////////

static void convertFromChar(const std::string& literal) {

	char c = literal[0];
	printChar(c, 0);
	std::cout << "int: " << static_cast <int> (c) << std::endl;
	printFloat(static_cast <float> (c));
	std::cout << "double: " << static_cast <double> (c) << std::endl;
}

static void convertFromInt(const std::string& literal) {

	std::stringstream ss(literal);
	int n;
	
	ss >> n; 
	printChar(static_cast <char> (n), n);
	std::cout << "int: " << n << std::endl;
	printFloat(static_cast <float> (n));
	std::cout << "double: " << static_cast <double> (n) << std::endl;	

}

static void convertFromFloat(const std::string& literal) {

	double d = strtod(literal.c_str(), NULL);
	float f = static_cast <float> (d);

	printChar(static_cast <char> (f), f);
	printInt(static_cast <int> (f), f);
	printFloat(f);
	std::cout << "double: " << static_cast <double> (f) << std::endl;		
}

static void convertFromDouble(const std::string& literal) {

	double d = strtod(literal.c_str(), NULL);

	printChar(static_cast <char> (d), d);
	printInt(static_cast <int> (d), d);
	printFloat(static_cast <float> (d)); 
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {

	if (literal.empty())
		std::cout << "NOTHING" << std::endl;
	else if (checkChar(literal))
		convertFromChar(literal);
	else if (checkInt(literal))
		convertFromInt(literal);
	else if (checkFloat(literal))
		convertFromFloat(literal); 
	else if (checkDouble(literal))
		convertFromDouble(literal);
	else 
		std::cout << "NOTHING" << std::endl;
}

ScalarConverter::~ScalarConverter() {

}
