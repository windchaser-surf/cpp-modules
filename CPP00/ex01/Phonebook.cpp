/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:20:25 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/05 10:17:01 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() : capa(0){
	
}

Phonebook::~Phonebook() {
	
}

void Phonebook::addContact(){
	
	if (this->capa < 8)
	{
		this->Contacts[capa].setContact();
		capa += 1;
	}
	else 
	{
		this->Contacts[capa % 8].setContact();
		capa += 1;
	}
}

bool Phonebook::isNumber(std::string& str){
	
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
	
}

void Phonebook::printPhonebook(){
	
	std::string search_index;
	
	std::cout << std::endl << std::endl; 
	if (this->capa == 0)
	{
		std::cout << "Your current Phonebook is empty" << std::endl << std::endl; 
		return ;
	}
	else 
	{
		std::cout << "Current Contacts of your phonebook\n" << std::endl << std::endl;
		std::cout << std::setw(10) << "Index" << " | " << std::right;
		std::cout << std::setw(10) << "First name" << " | " << std::right;
		std::cout << std::setw(10) << "Last name" << " | " << std::right;
		std::cout << std::setw(10) << "Nickname" << std::right << std::endl << std::endl;
	}
	for (int i = 0; i < capa && i < 8; i++)
	{
		this->Contacts[i].printIndexContact(i);
		std::cout << std::endl;
		
	}
	std::cout << "Which contact do you wanna have? Please type the index: ";
	std::getline(std::cin, search_index);
	while (!std::cin.eof())
	{
		if (!search_index.empty() && isNumber(search_index) && \
			search_index.length() < 2)
		{
			int index = atoi(search_index.c_str());
			if (index <= this->capa && index > 0 && index <= 8)
			{
				this->Contacts[index - 1].printContact();
				break ;
			}
		}
		std::cout << "Please enter a valid index: ";
		std::getline(std::cin, search_index);
	}
}
