/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:09:54 by felix             #+#    #+#             */
/*   Updated: 2024/02/06 10:25:02 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//type from HumanA will directly init! => ref possible
HumanA::HumanA(std::string name, Weapon &type) : _type(type) {
    
    this->_name = name; 
}

HumanA::~HumanA() {
    
}

void    HumanA::attack() {

    if (this->_type.getType().empty())
        std::cout << this->_name << " got no weapon.." << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_type.getType() << std::endl;
}
