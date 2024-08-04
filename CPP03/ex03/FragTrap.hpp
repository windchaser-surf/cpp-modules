/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:54:22 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/12 15:27:21 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap {

    protected: 

        int init_attackDamage;
        int init_hitPoints;
        FragTrap(void);

    public: 

        FragTrap(std::string name);
        ~FragTrap();
        FragTrap(const FragTrap& old);
		FragTrap &operator=(const FragTrap& old);
        void    highFivesGuys(void);
};

#endif
