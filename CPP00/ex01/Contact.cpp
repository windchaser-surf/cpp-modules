/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:49:23 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/05 10:15:24 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : first_name(""), last_name(""), nick_name(""), \
				phone_number(""), darkest_secret("") {
					
}

Contact::~Contact(){
	
}

bool	isWhitespace(const std::string& str){

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!::isspace(str[i]))
			return (false);
	}
	return (true);
}

void Contact::setContactAttribute(std::string& attribute, const std::string& prompt) {
	
	while (!std::cin.eof() && (attribute.empty() || isWhitespace(attribute)))
	{
		std::cout << prompt;
		std::getline(std::cin, attribute); 
	}
}

void Contact::setContact() {
	
	std::cout << std::endl;
	*this = Contact(); //Reset Contact
	
	setContactAttribute(this->first_name, "First name: ");
	setContactAttribute(this->last_name, "Last name: ");
	setContactAttribute(this->nick_name, "Nickname: ");
	setContactAttribute(this->phone_number, "Phone number: ");
	setContactAttribute(this->darkest_secret, "Darkest Secret: ");

	std::cout << std::endl;
}

void Contact::printContact(){
	std::cout <<std::endl << "First name: "<< this->first_name <<"" << std::right <<std::endl;
	std::cout << "Last name: "<< this->last_name << ""<<std::endl;
	std::cout << "Nickname: "<< this->nick_name << ""<<std::endl;
	std::cout << "Phone number: "<< this->phone_number << ""<<std::endl;
	std::cout << "Darkest Secret: "<< this->darkest_secret << ""<< std::endl << std::endl;
	
}

std::string Contact::truncateContact(std::string str){
	
	if (str.length() > 10) 
	{	
		str = str.substr(0, 10);
		str[9] = '.';
		return (str);
	}
	else 
		return (str);
}

std::string Contact::replaceTabsWithSpaces(const std::string& str) {
    std::string result;

    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '\t') {
            result += "    ";
        } else {
            result += str[i];
        }
    }

    return result;
}


void Contact::printIndexContact(int index){
	
	std::cout << std::setw(8) << "["<< index + 1 <<"]" << " | " << std::right;
	std::cout << std::setw(10) <<truncateContact(replaceTabsWithSpaces(this->first_name)) << " | " << std::right;
	std::cout << std::setw(10) <<truncateContact(replaceTabsWithSpaces(this->last_name)) << " | " << std::right;
	std::cout << std::setw(10) << truncateContact(replaceTabsWithSpaces(this->nick_name))  << std::right << std::endl;
}
