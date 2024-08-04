/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:33:11 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/06 10:31:29 by fwechsle         ###   ########.fr       */
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
	
	for (int i = 0; i < 4; i++)
	{
		if (level == all_levels[i])
			(this->*pointerToMemberFunction[i])();
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
