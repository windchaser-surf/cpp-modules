#include "BitcoinExchange.hpp"
//Muss raus am ende da ich nur map verwende!! 
#include <vector>

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_dataBase = other._dataBase; 
	_input = other._input;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other) {
		_dataBase = other._dataBase;
		_input = other._input;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

/////////////////////////basic checker functions//////////////////////////////

static bool basicCheckForSplitDatabase(std::string& line)
{
	if (line.find_first_not_of("-+0123456789,.") != std::string::npos)
		return (false);
	if (line.length() < 12)
		return (false);
	if (line.at(10) != ',')
		return (false);
	return (true);
}

static bool basicCheckForSplitInput(std::string& line)
{
	if (line.find_first_not_of("-+0123456789|. ") != std::string::npos)
		return (false);
	if (line.length() < 14)
		return (false);
	if (line.at(10) != ' ' || line.at(11) != '|' || line.at(12) != ' ')
		return (false);
	return (true);
}

static bool checkDouble(const std::string& rate) {

    bool dotFound = false;
	bool digitFound = false;
	bool negativFound = false;
	bool positvFound = false; 

	if (rate.at(0) == '-')
		negativFound = true;
	if (rate.at(0) == '+')
		positvFound = true;
	for (size_t i = 0; i < rate.length(); i++)
	{
		if ((positvFound || negativFound) && i == 0)
			continue;
		if (rate.at(i) == '.') {
			if (dotFound == true)
				return (std::cerr << "Error: not a number." << std::endl, false); //Not a number
			dotFound = true;
		}
		if (std::isdigit(rate.at(i)))
			digitFound = true;
		if (rate.at(i) != '.' && !isdigit(rate[i]))
			return (std::cerr << "Error: not a number." << std::endl, false); //Not a number
	}
	if (digitFound && negativFound)
		return (std::cerr << "Error: not a positive number." << std::endl, false); //negativ number!
	if (digitFound)
		return true;
	return (std::cerr << "Error: not a number." << std::endl, false);
}

static bool	checkValidRate(std::string& rate)
{
	if (rate.empty())
		return (std::cerr << "Error: empty rate!" << std::endl, false);
	else if (rate.find_first_not_of("-+0123456789.") != std::string::npos)
		return (std::cerr << "Error: not a number." << std::endl, false);
	else if (!checkDouble(rate))
		return (false);
	return (true);
}

static bool checkValidMonth (std::string date) 
{
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	int year = std::strtol (date.substr(0, 4).c_str(), NULL, 10);

	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	if (month == 2)
	{
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			return (day > 29 ? false : true);
		else 
			return (day > 28 ? false : true);
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return (day > 30 ? false : true);
	return (true); 
}

static float convertStringToFloat(std::string str) {

	return (static_cast <float> (strtod(str.c_str(), NULL)));
}


bool BitcoinExchange::getDataBase(std::string dataBase)
{
	std::fstream inputData;
	std::string line;

	inputData.open(dataBase.c_str());
	if (!inputData.is_open() || !inputData.good())
	{
		std::cerr << "Error: Database File not open" << std::endl;
		return (false);
	}
	std::getline(inputData, line);
	if (line != "date,exchange_rate")
		return (std::cerr << "Given format is not valid => \"date,exchange_rate\"" << std::endl, false);
	while (std::getline(inputData, line))
	{
		std::string date;
		std::string rate;
		if (!basicCheckForSplitDatabase(line))
			return (std::cerr << "Error: Invalid database! => " << line << '\n', false);
		date = line.substr(0, 10);
		rate = line.substr(11, line.length());
		if (!checkValidDate(date))
			return (false);
		if (!checkValidRate(rate))
			return (false);
		_dataBase.insert(std::make_pair(date, convertStringToFloat(rate)));
	}
	if (_dataBase.size() < 1)
		return (std::cerr << "Error: empty database!" << std::endl, false);
	return (true);
}

std::map<std::string, float>::iterator BitcoinExchange::getNextDate(std::string currDate)
{
	if (currDate < _dataBase.begin()->first) 
	{
		std::cerr << "Error: Date is too early!" << std::endl;
		return (_dataBase.end());
	}
	//get next date or equal date!
	std::map<std::string, float>::iterator nextDate = _dataBase.lower_bound(currDate);
	//to get the lower val!
	if (nextDate == _dataBase.end() || nextDate->first != currDate)
		nextDate--;
    return nextDate;
}

static bool checkValidAmount(float amount)
{
	if (amount < 0)
		return (std::cerr << "Error: not a positive number" << std::endl, false);
	if (amount > 1000)
		return (std::cerr << "Error: too large a number" << std::endl, false);
	return (true);
}

void BitcoinExchange::calcExchange(std::string date, std::string value)
{
	if (getNextDate(date) == _dataBase.end())
		return ;
	float amount = convertStringToFloat(value);
	if (!checkValidAmount(amount))
		return ;
	std::cout << date << " => " << value << " = " \
	<< getNextDate(date)->second * amount << std::endl;
}

static std::string getCurrentDate()
{
	std::string formatedDate;
    std::time_t t = std::time(0); // Get current time
    std::tm* now = std::localtime(&t);

	char buffer[11];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", now);

	formatedDate = static_cast <std::string> (buffer);
    return formatedDate;
}


bool BitcoinExchange::checkValidDate(std::string date)
{
	//check if date is valid!
	if (date.length() != 10)
		return (std::cerr << "Error: bad input => " << date << std::endl, false);
	if (date.find_first_not_of("-0123456789") != std::string::npos)
		return (std::cerr << "Error: bad input => " << date << std::endl, false);
	if (date.at(4) != '-' || date.at(7) != '-')
		return (std::cerr << "Error: bad input => " << date << std::endl, false);
	if (!checkValidMonth(date))
		return (std::cerr << "Error: bad input => " << date << std::endl, false);
	if (date > getCurrentDate())
		return (std::cerr << "Error: No exchange rate, date is in the future" << std::endl, false);
	return (true);
}

bool BitcoinExchange::getInput(std::string input)
{	
	std::fstream 	inputFile; 
	std::string		line;

	inputFile.open(input.c_str());
	if (!inputFile.is_open() || !inputFile.good())
	{
		std::cerr << "Error: "<< input << " couldn't be opened" << std::endl;
		return (1);
	}
	std::getline(inputFile, line);
	if (line != "date | value")
		return (std::cerr << "Given format is not valid => \"date | value\"" << std::endl, false);
	while (std::getline(inputFile, line))
	{
		std::string date;
		std::string val;

		if (!basicCheckForSplitInput(line))
		{
			std::cerr << "Error: bad input => " << line << '\n';
			continue;
		}
		date = line.substr(0, 10);
		val = line.substr(13, line.length());
		if (!checkValidDate(date))
			continue;
			//achtung hier darf es auch negative geben bzw. die müssen gecatcht werden! 
		if (!checkValidRate(val))
			continue;
		calcExchange(date, val);
	}

    return true;
}
