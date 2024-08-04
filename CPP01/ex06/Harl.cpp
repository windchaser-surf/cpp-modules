/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:33:11 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/05 13:26:46 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	
}

Harl::~Harl() {
	
}

void Harl::complain(std::string level) {
	
	void (Harl::*pointerToMemberFunction[4])() = {

		&Harl::debug,
		&Harl::info, 
		&Harl::warning,
		&Harl::error
	};

	std::string all_levels[4] = {
		"DEBUG",
		"INFO", 
		"WARNING",
		"ERROR"
	};
	int expression = 1;
	for (int i = 0; i < 4; i++)
	{
		if (level == all_levels[i])
			break;
		expression++;	
	}

	switch (expression)
	{
	case 1: //DEBUG
		(this->*pointerToMemberFunction[0])();	
	case 2: //INFO
		(this->*pointerToMemberFunction[1])();
	case 3: //WARNING
		(this->*pointerToMemberFunction[2])();
	case 4: //ERROR
		(this->*pointerToMemberFunction[3])();
		break;
	default:
		std::cout << "Sorry no matches for this case" << std::endl;
		break;
	}
}


void Harl::debug(void) {

	std::cout << "Now we are in DEBUG mode" << std::endl; 
}

void Harl::info(void) {

	std::cout << "Now we are in INFO mode" << std::endl; 
}

void Harl::warning(void) {
	
	std::cout << "Now we are in WARNING mode" << std::endl; 
}

void Harl::error(void) {

	std::cout << "Now we are in ERROR mode" << std::endl;
}
