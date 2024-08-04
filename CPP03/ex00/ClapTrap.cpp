/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:16:55 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/12 11:21:15 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
 
ClapTrap::ClapTrap() {
	
	std::cout << "Default constructor called!" << std::endl; 
	_hitPoints = 10;
	_energyPoints = 10; 
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {

	std::cout << "Overload constructor called" << std::endl;
	_hitPoints = 10;
    _energyPoints = 10; 
    _attackDamage = 0;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& old) {

	std::cout << "Copy operator called" << std::endl;
	if (this != &old)
	{
		_name = old._name; 
		_hitPoints = old._hitPoints; 
		_attackDamage = old._attackDamage;
		_energyPoints = old._energyPoints; 
		
	}
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap& old) {

	std::cout << "Copy constructor called" << std::endl;
	_name = old._name;
	_hitPoints = old._hitPoints; 
	_attackDamage = old._attackDamage;
	_energyPoints = old._energyPoints;
}

void	ClapTrap::attack(const std::string &target) {
	
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage" << std::endl; 
		_energyPoints--;	
	}
	else if (_energyPoints == 0 && _hitPoints == 0)
		std::cout << _name << " has not enough Energy Points and Hit Points!!!" << std::endl;
	else if (_energyPoints == 0)
		std::cout << _name << " has not enough Energy Points!!!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << _name << " has not enough HitPoints!!!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {

	if (_hitPoints > 0)
	{
		std::cout << _name << " take a Damage of " << amount << " points" << std::endl;
		while (amount > 0 && _hitPoints > 0)
		{
			_hitPoints--; 
			amount--;
		}
		if (_hitPoints == 0)
			std::cout << _name << " is died" << std::endl;
	}
	else
		std::cout << _name << " has no hit points left!!!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {

	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << _name << " repaired by amount of " << amount << " points" << std::endl; 
	}
	else if (_energyPoints == 0 && _hitPoints == 0)
		std::cout << _name << " cannot be repaired!!! (no energyPoints & hitPoints)" << std::endl;
	else if (_energyPoints == 0)
		std::cout << _name << " cannot be repaired!!! (no energyPoints)" << std::endl;
	else if (_hitPoints == 0)
		std::cout << _name << " cannot be repaired!!! (no hitPoints)" << std::endl;
}

int ClapTrap::getAttackDamage() const {

	return (_attackDamage);	
}

ClapTrap::~ClapTrap() {
	
	std::cout << "Deconstructor called" << std::endl; 
}
