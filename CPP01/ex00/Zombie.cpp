/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:40:58 by felix             #+#    #+#             */
/*   Updated: 2024/02/06 10:12:28 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){

}

Zombie::Zombie (std::string name) : name(name) {
    
    //this->name = name; other syntax
    std::cout << name << " is created!" << std::endl;
}

Zombie::~Zombie (void) {
    
    std::cout << this->name << " is deleted" << std::endl;
}

void    Zombie::announce ( void ) {

    std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
