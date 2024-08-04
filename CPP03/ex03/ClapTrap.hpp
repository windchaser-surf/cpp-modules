/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:16:22 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/12 15:34:46 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string.h>
# include <iostream>

class ClapTrap {
	
	protected : 

		std::string _name;
		int 		_hitPoints;
		int 		_energyPoints;
		int 		_attackDamage; 

	public : 
	
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& old);
		ClapTrap &operator=(const ClapTrap& old);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		int		getHitPoints() const;
		int		getEnergyPoints() const; 
		int		getAttackDamage() const; 

};

#endif
