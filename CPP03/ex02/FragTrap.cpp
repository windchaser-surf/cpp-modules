/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:57:40 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/12 11:03:06 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {

    _attackDamage = 30;
    _hitPoints = 100;
    _energyPoints = 100;
    std::cout << "Default constructor from FragTrap called" << std::endl; 
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){

    _attackDamage = 30;
    _hitPoints = 100;
    _energyPoints = 100;
    _name = name;
    std::cout << "Overloard constructor from FragTrap called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& old) {

    _attackDamage = old._attackDamage;
    _energyPoints = old._energyPoints;
    _hitPoints = old._hitPoints;
    _name = old._name;
}

FragTrap&   FragTrap::operator=(const FragTrap& old) {

    if (this != &old)
    {
        _attackDamage = old._attackDamage;
        _energyPoints = old._energyPoints;
        _hitPoints = old._hitPoints;
        _name = old._name;
    }
    return (*this);
}

void    FragTrap::highFivesGuys(void) {
    
    if (_energyPoints > 0 && _hitPoints > 0)
        std::cout << "Hey Guys give me High Five!!!" << std::endl;
    else
        std::cout << "I am not alive!!!" << std::endl;
}

FragTrap::~FragTrap() {
    
    std::cout << "Deconstructor from FragTrap called" << std::endl; 
}
