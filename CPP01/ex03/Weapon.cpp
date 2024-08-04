/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:20:59 by felix             #+#    #+#             */
/*   Updated: 2024/02/06 12:04:29 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
	
}

Weapon::Weapon(std::string type) {

	this->_type = type;
}

Weapon::~Weapon() {
	
}

std::string	Weapon::getType(void) const {
	
	return (this->_type);
}

void    Weapon::setType(std::string type) {

	this->_type = type;
}
