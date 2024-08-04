/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:08:24 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/12 15:58:41 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {

    _attackDamage = 20;
    _hitPoints = 100;
    _energyPoints = 50;
    init_energyPoints = _energyPoints;
    std::cout << "Default constructor from ScavTrap called" << std::endl; 
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){

    _attackDamage = 20;
    _hitPoints = 100;
    _energyPoints = 50;
    init_energyPoints = _energyPoints;
    _name = name;
    std::cout << "Overloard constructor from ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& old) {

    _attackDamage = old._attackDamage;
    _energyPoints = old._energyPoints;
    _hitPoints = old._hitPoints;
    _name = old._name;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& old) {

    if (this != &old)
    {
        _attackDamage = old._attackDamage;
        _energyPoints = old._energyPoints;
        _hitPoints = old._hitPoints;
        _name = old._name;
    }
    return (*this);
}

void    ScavTrap::attack(const std::string& target) {

	if (getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << _name << " of ScavTrap attacks " << target << ", causing " << getAttackDamage() << " points of damage" << std::endl; 
		_energyPoints--;	
	}
	else if (_energyPoints == 0 && _hitPoints == 0)
		std::cout << _name << " has not enough Energy Points and Hit Points!!!" << std::endl;
	else if (_energyPoints == 0)
		std::cout << _name << " has not enough Energy Points!!!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << _name << " has not enough HitPoints!!!" << std::endl;
}

void ScavTrap::guardGate() {

    std::cout << _name << " is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap() {
    
    std::cout << "Deconstructor from ScavTrap called" << std::endl; 
}
