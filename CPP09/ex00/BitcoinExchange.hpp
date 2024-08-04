#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <ctime>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _dataBase;
		std::map<std::string, float> _input;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		typedef std::map<std::string, float>::iterator iterator;

		bool		getDataBase(std::string dataBase);
		iterator	getNextDate(std::string currDate);
		bool		getInput(std::string input);
		void		calcExchange(std::string date, std::string val);
		bool 		checkValidDate(std::string date);
};

#endif // !BITCOINEXCHANGE_H
