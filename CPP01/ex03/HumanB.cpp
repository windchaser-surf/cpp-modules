/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:15:58 by felix             #+#    #+#             */
/*   Updated: 2024/02/06 10:24:26 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

//Weapon type is not init directly => pointer
HumanB::HumanB(std::string name) {

    this->_name = name;
    this->_type = NULL;
}

HumanB::~HumanB () {
    
}

void HumanB::attack() {

    if (_type->getType().empty())
        std::cout << this->_name << " got no weapon..." << std::endl;
    else
        std::cout << this->_name << " attacks with their " << _type->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &type) {
    
    this->_type = &type;
}
