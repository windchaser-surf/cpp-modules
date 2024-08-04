/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:20:54 by felix             #+#    #+#             */
/*   Updated: 2024/02/04 13:29:41 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
    
}
//useless Constructor if I call my setName function!
/* Zombie::Zombie(std::string name) : name(name) {
    
    std::cout << name << " is created!" << std::endl; 
} */

Zombie::~Zombie (void) {

    std::cout << this->name << " is deleted" << std::endl; 
}

void    Zombie::announce(int N) {
    std::cout << "["<< N <<"]: " << this->name <<std::endl;
}

void    Zombie::setName(std::string name) {

    this->name = name;
}