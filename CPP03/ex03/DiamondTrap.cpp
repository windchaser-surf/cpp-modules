/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:27:33 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/12 15:45:45 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(){

	_hitPoints = FragTrap::init_hitPoints;
	_energyPoints =  ScavTrap::init_energyPoints;
	_attackDamage = FragTrap::init_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name){

	std::cout << "Overload constructor from DiamondTrap called" << std::endl;
	ClapTrap::_name += "_clap_name";
	_name = name;
	_hitPoints = FragTrap::init_hitPoints;
	_energyPoints =  ScavTrap::init_energyPoints;
	_attackDamage = FragTrap::init_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& old) {

	*this = old;
}

DiamondTrap&   DiamondTrap::operator=(const DiamondTrap& old) {

    if (this != &old)
    {
        _attackDamage = old._attackDamage;
		_energyPoints = old._energyPoints; 
		_hitPoints = old._hitPoints;
		_name = old._name;
    }
    return (*this);
}

void	DiamondTrap::whoAmI() {

    std::cout << "_name = " << _name << std::endl; 
    std::cout << "Clap_name = " << ClapTrap::_name << std::endl; 
}

DiamondTrap::~DiamondTrap() {

	std::cout << "Deconstructor from DiamondTrap called" << std::endl;
}
