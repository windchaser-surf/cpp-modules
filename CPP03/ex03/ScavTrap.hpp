/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:08:35 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/12 15:29:09 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

    protected :

        int init_energyPoints; 
        ScavTrap(void);    

    public : 

        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(const ScavTrap& old);
		ScavTrap &operator=(const ScavTrap& old);
        void    attack(const std::string &target);
        void    guardGate();
   
};

#endif
