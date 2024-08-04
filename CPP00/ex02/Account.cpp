/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:53:30 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/03 15:29:05 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)  
{    
	_accountIndex = _nbAccounts; 
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";" ;
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";" ;
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts ( void )
{	
	return (_nbAccounts);
}

int Account::getTotalAmount( void )
{	
	return (_totalAmount);
}

int Account::getNbDeposits ( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{	
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp( void )
{
	time_t timer;
	time(&timer);

	tm *curr = localtime(&timer);
	std::cout << "[" << curr->tm_year + 1900 ;
	std::cout << std::setw(2) << std::setfill('0') << curr->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << curr->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << curr->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << curr->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << curr->tm_sec;
	std::cout << "] ";
}

void Account::displayAccountsInfos(void)
{	
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit (int deposit)
{	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";"; 
	this->_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal <= checkAmount())
	{
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}	
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
}

int Account::checkAmount ( void ) const 
{
	return (this->_amount);
}

void Account::displayStatus ( void ) const 
{	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

Account::Account(void) {
	
}
