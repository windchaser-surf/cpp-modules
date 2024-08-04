/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:27:41 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/12 15:44:44 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap,  public FragTrap{

	private: 

		std::string _name;
		DiamondTrap(void); 
	
	public: 
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& old);
		DiamondTrap &operator=(const DiamondTrap& old);
		~DiamondTrap();
		void	whoAmI();
		using	ScavTrap::attack;
};

#endif
